#include <stdio.h>

int insertion(int *a, int len);

int main(){
	
	int array[7] = {5,8,9,20,1,2,0};
	int *p = array;
	insertion(p, 7);
	for(int i; i<7; i++){
		printf("%d, ",array[i]);
	}
	printf("\n");
}

int insertion(int *a, int len){

	int i,j;
	for (i = 1; i < len; i++){
		int deger = a[i];
		j = i-1;
 
	        while (j >= 0 && a[j] > deger){
			a[j+1] = a[j];
		        j--;
	        }
	        a[j+1] = deger;
	}
}
