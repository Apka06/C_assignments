#include <stdio.h>

int selection(int *array, int len);


int main(){

	int a[7] = {20,3,6,2,1,4,0};
	int *p = a;
	selection(p, 7);
	for(int i; i<7; i++){
		printf("%d, ",a[i]);
	}
	printf("\n");
}

int selection(int *array, int len){
	
	for(int i = 0; i < len; i++){
		int *min = &array[i];
		for(int j = i+1; j < len; j++){
			if(array[j] < *min){
				min = &array[j];
			}
		}
		int temp = array[i];
		array[i] = *min;
		*min = temp;
	}
}
