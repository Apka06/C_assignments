#include <stdio.h>
#include <stdlib.h>
struct nodeCustomer
{
    int id;                   // Müşteri kimlik numarası
    int arriving_time;        // Müşterinin varış zamanı
    int work_to_do;           // Yapılacak işin süresi
    struct nodeCustomer* next; // Bir sonraki müşteri düğümünün referansı
};
    struct nodeCustomer * rear  = NULL;
    struct nodeCustomer * front = NULL;
    struct nodeCustomer  * queue = NULL;

void insert_customer(int customer_id, int work, int arrived){ // Kuyruğa yeni müşteri ekler.
	if(front == NULL){ // ilk müşteri olma durumu
        front = (struct nodeCustomer*)malloc(sizeof(struct nodeCustomer));
        front ->id = customer_id;
        front ->work_to_do = work;
        front ->arriving_time = arrived;
        rear = front;
    }
    else{
        rear -> next = (struct nodeCustomer*)malloc(sizeof(struct nodeCustomer));
        rear -> next ->id = customer_id;
        rear -> next ->work_to_do = work;
        rear -> next ->arriving_time = arrived;
        rear = rear->next;
    }
    queue = front;
}

struct nodeCustomer * delete_customer(){ // kuyruktan müşteri siler
    if (front == NULL){ // kuyruğun boş olma durumu
        return NULL;
    }
    else{
        struct nodeCustomer * newnode = (struct nodeCustomer*)malloc(sizeof(struct nodeCustomer));
        newnode -> id = front-> id;
        newnode -> work_to_do = front-> work_to_do;
        newnode -> arriving_time = front-> arriving_time;
        struct nodeCustomer *temp = front;
        front = front -> next;
        free(temp);
        return newnode;
    }
}

struct nodeEmployee
{
    int no;                     // Çalışannın idsi
    int time_served;            // Toplam çalışma süresi
    int transaction_finished;   // Üzerinde çalıştığı işlemi bitirdiği zaman
    int is_available;           // Müsait olma durumu
    struct nodeEmployee * next;
};
struct nodeEmployee* top= NULL;

void employee_push(int id, int served, int available){ // çalışan stackine yeni çalışan ekler.
    struct nodeEmployee * newnode = (struct nodeEmployee*)malloc(sizeof(struct nodeEmployee));
    newnode -> no = id;
    newnode -> time_served = served;
    newnode -> is_available = available;
    if(top!= NULL){
        newnode -> next = top;
    }
    top = newnode;
}

struct nodeEmployee * pop_employee(){ // çalışan stackinden çalışan çıkarır.
    if(top == NULL){
        return NULL;
    }
    else{
        struct nodeEmployee * temp = top;
        struct nodeEmployee * newnode = (struct nodeEmployee*)malloc(sizeof(struct nodeEmployee));
        int temp_id = top -> no;
        int temp_served = top -> time_served;
        top = top-> next;
        free(temp);
        newnode -> no = temp_id;
        newnode -> time_served = temp_served;
        return newnode;
    }
}

int main(){
    struct nodeEmployee * will_available = NULL;
    struct nodeEmployee * iter = NULL; // İşlem yapacak çalışan
    struct nodeCustomer * customer = NULL; // İşlemi yapılacak müşteri
    int customer_id, work, arrived, transaction_started;
    int waited = 0, time = 1, available = 0;

    // Çalışanlar çalışan stackine ekleniyor.
    for(int i = 1; i <= 6; i++){
        employee_push(i, 0, 1);
    }

    while(customer_id!=-1){
        scanf("%d", &customer_id);
        if(customer_id == -1){
            break;
        }
        scanf("%d", &arrived);
		scanf("%d", &work);
        insert_customer(customer_id, work, arrived);
    }
    customer = delete_customer();
    // Müşteri kuyruğu boşaltılana kadar işlem yapılıyor. 
    // İşlem genel olarak; bir müşteri ve çalışanı eşleştirip, işlemin ne zaman başladığını ve ne zaman bittiğini,
    // müşterinin kuyrukta ne kadar beklediğini ve çalışanın toplamda ne kadar çalıştığını belirlemekten ibaret.
	while(customer != NULL){
        iter = top;
        // Çalışanların kullanılabilirlik durumunu kontrol ediliyor.
        for(int employee = 1; employee < 6 ; employee++){
            if(iter->is_available == 1){
                available = 1;
                break;
            }
            iter = iter -> next;
            available = 0;
        }
        if(iter->is_available == 1){available = 1;}
        if(available == 1){
            iter -> is_available = 0;
            iter -> time_served += customer->work_to_do;
            iter -> transaction_finished = time + customer->work_to_do + waited;
            printf("%d %d %d %d %d\n", customer->id, iter->no, customer->arriving_time, customer->arriving_time+customer->work_to_do, waited);
        }
        else{
            iter = top;
            int min = iter -> transaction_finished + 1;
            for(int employee = 1; employee < 6 ; employee++){
                if(min > iter->transaction_finished){
                    min = iter->transaction_finished;
                    will_available = iter;
                }
                iter = iter->next;
            }
            if(min > iter->transaction_finished){
                min = iter->transaction_finished;
                will_available = iter;}
            will_available -> is_available = 1;
            waited = will_available -> transaction_finished - time;
            will_available -> time_served += customer->work_to_do;
            will_available -> transaction_finished = time + customer->work_to_do + waited;
            printf("%d %d %d %d %d\n", customer->id, will_available->no, customer->arriving_time +waited, customer->arriving_time+customer->work_to_do+waited, waited);
            will_available -> is_available = 0;
        }
        customer = delete_customer();
        if (customer == NULL){break;}
        int waited = 0;
        time = customer->arriving_time;
        iter = top;
        // İşini en erken tamamlayacak çalışan bulunuyor.
        for(int employee = 1; employee < 6 ; employee++){
            if(time >= iter->transaction_finished){
                iter -> is_available = 1;
            }
            iter = iter->next;
        }
        if(time >= iter->transaction_finished){iter -> is_available = 1;}
    }
    iter = top;
    printf("\n");
    while(iter != NULL){
        iter = pop_employee();
        if (iter == NULL){break;}
        printf("%d %d\n",iter->no, iter->time_served);
    }
}