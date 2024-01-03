#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void printboard(int R, int C, char arr[][C]);

int main(){
	int R,C;
	scanf("%d %d", &R, &C);
	char arr[R][C];
	char sign[3];
	int oR, oC, up;
	int Score = 0;
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			if (i == 0 || i == R-1 || j == 0 || j == C-1)
				arr[i][j] = '#';
			else
				arr[i][j] = ' ';
		}
	}
	bool flag = true;
	int balls;
	while(flag){
		scanf("%s", sign);
		if(sign[0] == 'c'){
			int p = 0;
			char colors[100];
			scanf("%s", colors);
			balls = strlen(colors);
			if(balls >= (C-2)*(oR-1)){
				flag = false;
			}
			while(p <= (R-2)*(C-2)){
				for (int i = 1; i < R-1; i++){
					for (int j = 1; j < C-1; j++){
						if (p < balls){
							arr[i][j] = colors[p];}
					p += 1;
					}
				}
			}
			printboard(R,C,arr);
		}
		else if(sign[0] == 'p'){
			char moves[100];
			scanf("%s", moves);
			for(int i = 0; moves[i] != '\0'; i++){
				if (moves[i] == 'A'){
					if(arr[oR][oC-1] != '#'){
						oC -= 1;
						arr[oR][oC+1] = ' ';
						arr[oR][oC] = 'X';
					}
					else{
						flag = false;}
				}
				else if (moves[i] == 'D'){
					if(arr[oR][oC+1] != '#'){
						oC += 1;
						arr[oR][oC-1] = ' ';
						arr[oR][oC] = 'X';		
					}
					else{
						flag = false;}
				}
				else if (moves[i] == 'B'){
					while(arr[up][oC] != '#'){
						if(arr[up][oC] == 'B'){
							Score += 1;
							balls -= 1;
							if (balls == 0){
								flag = false;
							}
							arr[up][oC] = ' ';
							printf("Score: %d\n", Score);
							printboard(R,C,arr);
							if(arr[up-1][oC] == 'B'){
								Score += 1;
								balls -= 1;
								if (balls == 0){
									flag = false;
								}
								arr[up-1][oC] = ' ';
								printf("Score: %d\n", Score);
								printboard(R,C,arr);
							}
						}
						up--;
					}
					up = oR;
				}
				else if (moves[i] == 'G'){
					while(arr[up][oC] != '#'){
						if(arr[up][oC] == 'G'){
							Score += 2;
							balls -= 1;
							if (balls == 0){
								flag = false;
							}
							arr[up][oC] = ' ';
							printf("Score: %d\n", Score);
							printboard(R,C,arr);
							if(arr[up-1][oC] == 'G'){
								Score += 2;
								balls -= 1;
								if (balls == 0){
									flag = false;
								}
								arr[up-1][oC] = ' ';
								printf("Score: %d\n", Score);
								printboard(R,C,arr);
							}
						}
						up--;
					}
					up = oR;
				}
				else if (moves[i] == 'R'){
					while(arr[up][oC] != '#'){
						if(arr[up][oC] == 'R'){
							Score += 3;
							balls -= 1;
							if (balls == 0){
								flag = false;
							}
							arr[up][oC] = ' ';
							printf("Score: %d\n", Score);
							printboard(R,C,arr);
							if(arr[up-1][oC] == 'R'){
								Score += 3;
								balls -= 1;
								if (balls == 0){
									flag = false;
								}
								arr[up-1][oC] = ' ';
								printf("Score: %d\n", Score);
								printboard(R,C,arr);
							}
						}
						up--;
					}
					up = oR;
				}
			}			
		}
		else if(sign[0] == 's'){
			scanf("%d %d", &oR, &oC);
			up = oR;
			arr[oR][oC] = 'X';
		}
		else if(sign[0] == 'q'){
			flag = false;
		}
	}
	printf("Game Over, Total Score : %d \n", Score);
}
void printboard(int R, int C, char arr[][C]){
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			printf("%c",arr[i][j]);
		}
	printf("\n");
	}
	printf("\n");
}
