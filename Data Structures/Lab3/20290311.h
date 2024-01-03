struct nodeClass
{
	int classID;
	double classMidtermAverage;
	struct nodeClass *next;
	struct nodeStudent *studentPtr;
};

struct nodeStudent
{
	int studentID;
	int midterm;
	struct nodeStudent *next;
};

int find_class(int num){
	long local = num;
	while(local >= 100){
		local /= 10;
	}
	return local;
}

double calculate_average(struct nodeStudent *student){
	struct nodeStudent * ptr = student;
	int total = 0;
	int num_of_students = 0;
	while(ptr -> next != NULL){
		total += ptr -> midterm;
		num_of_students += 1;
		ptr = ptr -> next;
	}
	total += ptr -> midterm;
	num_of_students += 1;
	double average = total / (float)num_of_students;
	return average;
}

void insert(struct nodeClass **head, int id, int grade){
	struct nodeClass * class = NULL;
	struct nodeStudent * ptr = NULL;
	struct nodeStudent * newnode = (struct nodeStudent*)malloc(sizeof(struct nodeStudent));
	if(*head == NULL){
		struct nodeClass * class1 = (struct nodeClass*)malloc(sizeof(struct nodeClass));
		struct nodeClass * class2 = (struct nodeClass*)malloc(sizeof(struct nodeClass));
		struct nodeClass * class3 = (struct nodeClass*)malloc(sizeof(struct nodeClass));
		struct nodeClass * class4 = (struct nodeClass*)malloc(sizeof(struct nodeClass));
		*head = class1;
		class1 -> classID = 1;
		class2 -> classID = 2;
		class3 -> classID = 3;
		class4 -> classID = 4;
		class1 -> next = class2;
		class2 -> next = class3;
		class3 -> next = class4;
	}
	
	else{
		class = *head;
		ptr = class -> studentPtr;
	}
	newnode -> studentID = id;
	newnode -> midterm = grade;
	int classnum = find_class(id);
	class = *head;
	switch (classnum)
	{
	case 66:
		if (class -> studentPtr == NULL){
			class -> studentPtr = newnode;
		}
		else if(class -> studentPtr -> midterm <= grade){
			if(class -> studentPtr -> midterm < grade){
				newnode->next = class -> studentPtr;
				class -> studentPtr = newnode;
			}
			else if(class -> studentPtr -> midterm == grade){
				if(class -> studentPtr -> studentID < id){
					struct nodeStudent * iter = class -> studentPtr;
					struct nodeStudent * prev = NULL;
					while(iter -> studentID < id && iter -> midterm == grade){
						if(iter -> next == NULL){
							prev = iter;
							iter = iter -> next;
							break;
						}
						prev = iter;
						iter = iter -> next;
					}
					newnode -> next = iter;
					prev -> next = newnode;
				}
				else if(class -> studentPtr -> studentID > id){
					newnode->next = class -> studentPtr;
					class -> studentPtr = newnode;
				}
			}
		}
		else{
			struct nodeStudent * iter = class -> studentPtr;
			struct nodeStudent * prev = NULL;
			while(iter -> next != NULL && iter->next->midterm >= grade){
				prev = iter;
				iter = iter -> next;
			}
			if(iter->midterm == grade){
					if(iter->studentID > id){
						newnode -> next = prev -> next;
						prev-> next = newnode;
					}
					else if (iter->studentID < id){
						newnode -> next = iter -> next;
						iter -> next = newnode;
					}
				}
				else{
					newnode -> next = iter -> next;
					iter -> next = newnode;
				}
		}
		class -> classMidtermAverage = calculate_average(class->studentPtr);
		break;
	
	case 77:
		if (class -> next -> studentPtr == NULL){
			class -> next -> studentPtr = newnode;
		}
		else if(class -> next -> studentPtr -> midterm <= grade){
			if(class -> next -> studentPtr -> midterm < grade){
				newnode->next = class -> next -> studentPtr;
				class -> next -> studentPtr = newnode;
			}
			else if(class -> next -> studentPtr -> midterm == grade){
				if(class -> next -> studentPtr -> studentID < id){
					struct nodeStudent * iter = class -> next -> studentPtr;
					struct nodeStudent * prev = NULL;
					while(iter -> studentID < id && iter -> midterm == grade){
						if(iter -> next == NULL){
							prev = iter;
							iter = iter -> next;
							break;
						}
						prev = iter;
						iter = iter -> next;
					}
					newnode -> next = iter;
					prev -> next = newnode;
				}
				else if(class -> next -> studentPtr -> studentID > id){
					newnode->next = class -> next -> studentPtr;
					class -> next -> studentPtr = newnode;
				}
			}
		}
		else{
			struct nodeStudent * iter = class -> next -> studentPtr;
			struct nodeStudent * prev = NULL;
			while(iter -> next != NULL && iter->next->midterm >= grade){
				prev = iter;
				iter = iter -> next;
			}
			if(iter->midterm == grade){
				if(iter->studentID > id){
					newnode -> next = prev -> next;
					prev-> next = newnode;
				}
				else if (iter->studentID < id){
					newnode -> next = iter -> next;
					iter -> next = newnode;
				}
			}
			else{
				newnode -> next = iter -> next;
				iter -> next = newnode;
			}
		}
		class -> next -> classMidtermAverage = calculate_average(class-> next ->studentPtr);
		break;
	case 88:
		if (class -> next -> next -> studentPtr == NULL){
			class -> next -> next -> studentPtr = newnode;
		}
		else if(class -> next -> next -> studentPtr -> midterm <= grade){
			if(class -> next -> next -> studentPtr -> midterm < grade){
				newnode->next = class -> next -> next -> studentPtr;
				class -> next -> next -> studentPtr = newnode;
			}
			else if(class -> next -> next -> studentPtr -> midterm == grade){
				if(class -> next -> next -> studentPtr -> studentID < id){
					struct nodeStudent * iter = class -> next -> next -> studentPtr;
					struct nodeStudent * prev = NULL;
					while(iter -> studentID < id && iter -> midterm == grade){
						if(iter -> next == NULL){
							prev = iter;
							iter = iter -> next;
							break;
						}
						prev = iter;
						iter = iter -> next;
					}
					newnode -> next = iter;
					prev -> next = newnode;
				}
				else if(class -> next -> next -> studentPtr -> studentID > id){
					newnode->next = class -> next -> next -> studentPtr;
					class -> next -> next -> studentPtr = newnode;
				}
			}
		}
		else{
			struct nodeStudent * iter = class -> next -> next -> studentPtr;
			struct nodeStudent * prev = NULL;
			while(iter -> next != NULL && iter->next->midterm >= grade){
				prev = iter;
				iter = iter -> next;
			}
				if(iter->midterm == grade){
					if(iter->studentID > id){
						newnode -> next = prev -> next;
						prev-> next = newnode;
					}
					else if (iter->studentID < id){
						newnode -> next = iter -> next;
						iter -> next = newnode;
					}
				}
				else{
					newnode -> next = iter -> next;
					iter -> next = newnode;
				}
		}
		class -> next -> next -> classMidtermAverage = calculate_average(class-> next -> next ->studentPtr);
		break;
	case 99:
		if (class -> next -> next -> next -> studentPtr == NULL){
			class -> next -> next -> next -> studentPtr = newnode;
		}
		else if(class -> next -> next -> next -> studentPtr -> midterm <= grade){
			if(class -> next -> next -> next -> studentPtr -> midterm < grade){
				newnode->next = class -> next -> next -> next -> studentPtr;
				class -> next -> next -> next -> studentPtr = newnode;
			}
			else if(class -> next -> next -> next -> studentPtr -> midterm == grade){
				if(class -> next -> next -> next -> studentPtr -> studentID < id){
					struct nodeStudent * iter = class -> next -> next -> next -> studentPtr;
					struct nodeStudent * prev = NULL;
					while(iter -> studentID < id && iter -> midterm == grade){
						if(iter -> next == NULL){
							prev = iter;
							iter = iter -> next;
							break;
						}
						prev = iter;
						iter = iter -> next;
					}
					newnode -> next = iter;
					prev -> next = newnode;

				}
				else if (class -> next -> next -> next -> studentPtr -> studentID > id){
					newnode->next = class -> next -> next -> next -> studentPtr;
					class -> next -> next -> next -> studentPtr = newnode;
				}
			}
		}
		else{
			struct nodeStudent * iter = class -> next -> next -> next -> studentPtr;
			struct nodeStudent * prev = NULL;
			while(iter -> next != NULL && iter->next->midterm >= grade){
				prev = iter;
				iter = iter -> next;
			}
			if(iter->midterm == grade){
					if(iter->studentID > id){
						newnode -> next = prev -> next;
						prev-> next = newnode;
					}
					else if (iter->studentID < id){
						newnode -> next = iter -> next;
						iter -> next = newnode;
					}
				}
				else{
					newnode -> next = iter -> next;
					iter -> next = newnode;
				}
		}
		class -> next -> next -> next -> classMidtermAverage = calculate_average(class -> next -> next -> next ->studentPtr);
		break;
	}
}

void computeClassAverage(){

}

void printAll(struct nodeClass *head){
	struct nodeClass * class = NULL;
	struct nodeStudent * student = NULL;
	class = head;
	for(int i = 1; i <= 4; i++){
		student = class -> studentPtr;
		printf("%d %.2f\n", class->classID, class->classMidtermAverage);
		if (student == NULL){
			int a;
		}
		else{
			while(student->next != NULL){
				printf("%d %d\n", student->studentID, student->midterm);
				student = student ->next;
			}
			printf("%d %d\n", student->studentID, student->midterm);
		}
		class = class->next;
	}
}



// You must write all the function definitions to be used in this lab into this file.
// You may also write other functions that may be called from our functions.
// Do not make any changes to the main.c file.
// Upload function.h file to the system as StudentNumber.h.



