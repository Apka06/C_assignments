#include <stdio.h>
void find_asterisk(int x, int y, int R, int C, char arr[R][C], int blob[256], int idx);
int insertion(int *a, int len);

int main(){
	int R,C,input1, input2, num_cells;
	scanf("%d %d", &R, &C);
	R+=2;
	C+=2;
	num_cells = R*C;
	char arr[R][C];
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			arr[i][j] = '_';
		}
	}
	int counter = 0;
	while(input1 != -1){
		scanf("%d", &input1);
			if (input1 == -1){
				break;}
		scanf("%d", &input2);
		arr[input1+1][input2+1] = '*';
		counter++;
	}
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			printf("%c",arr[i][j]);
		}
		printf("\n");
	}printf("\n");
	int blob[256];
	for (int i =0; i < 256; i++){
		blob[i] = 0;
	}

	int idx = 0;
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			if(arr[i][j] == '*'){
				blob[idx] += 1;
				find_asterisk(i,j,R,C,arr,blob,idx);
				idx+=1;
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < R; i++){
		if(blob[i] != 0){
			sum += 1;
		}
	}
	int result[sum];
	
	for (int i = 0; i < sum; i++){
		if(blob[i] != 0){
			result[i] = blob[i];
		}
	}
	insertion(result, sum);
	printf("%d ",sum);
	
	for (int i = 0; i < sum; i++){
		printf("%d ", result[i]);
	}
}

void find_asterisk(int x, int y, int R, int C, char arr[R][C], int blob[256], int idx){
	
	arr[x][y] = '_';
	if(arr[x+1][y] == '*'){
		arr[x+1][y] = '_';
		blob[idx] += 1;
		find_asterisk(x+1,y, R, C, arr, blob, idx);
	}
	if(arr[x-1][y] == '*'){
		arr[x-1][y] = '_';
		blob[idx] += 1;
		find_asterisk(x-1,y, R, C, arr, blob, idx);
	}
	if(arr[x+1][y+1] == '*'){
		arr[x+1][y+1] = '_';
		blob[idx] += 1;
		find_asterisk(x+1,y+1, R, C, arr, blob, idx);
	}
	if(arr[x][y+1] == '*'){
		arr[x][y+1] = '_';
		blob[idx] += 1;
		find_asterisk(x,y+1, R, C, arr, blob, idx);
	} 
	if(arr[x][y-1] == '*'){
		arr[x][y-1] = '_';
		blob[idx] += 1;
		find_asterisk(x,y-1, R, C, arr, blob, idx);
	}
	if(arr[x-1][y-1] == '*'){
		arr[x-1][y-1] = '_';
		blob[idx] += 1;
		find_asterisk(x-1,y-1, R, C, arr, blob, idx);
	}
	if(arr[x+1][y-1] == '*'){
		arr[x+1][y-1] = '_';
		blob[idx] += 1;
		find_asterisk(x+1,y-1, R, C, arr, blob, idx);
	}
	if(arr[x-1][y+1] == '*'){
		arr[x-1][y+1] = '_';
		blob[idx] += 1;
		find_asterisk(x-1,y+1, R, C, arr, blob, idx);
	}

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
