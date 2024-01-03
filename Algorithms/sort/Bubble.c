#include <stdio.h>

int bubble(int *a, int len);

int main(){

	int a[7] = {20,3,6,2,1,4,0};
	int *p = a;
	bubble(p, 7);
	for(int i; i<7; i++){
		printf("%d\n", a[i]);
	}	
}

int bubble(int *a, int len){
	
	for(int j = 0; j < len; j++){	
		for(int i = 1; i < len - j; i++){
			if(a[i-1] > a[i]){
				int temp = a[i-1];
				a[i-1] = a[i];
				a[i] = temp;
			}
		}
	}
}
