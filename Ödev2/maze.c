#include <stdio.h>


int main()
{
	int R,C;
	scanf("%d %d", &R, &C);
	char arr[R][C];
	char sign[3];
	char end[3] = "end";
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			if (i == 0 || i == R-1 || j == 0 || j == C-1)
				arr[i][j] = '*';
			else
				arr[i][j] = ' ';
		}
	}
	int amount[R][C];
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			amount[i][j] = 0;
		}
	}
	int oR, oC, m, fR, fC;
	int bonus = 0;
	scanf("%s", sign);
	while(sign[0] != end[0]){
		if(sign[0] == 'f'){
			scanf("%d %d", &fR, &fC);
			arr[fR][fC] = ' ';
		}
		else if(sign[0] == 'b'){
			int bR, bC;
			scanf("%d %d", &bR, &bC);
			arr[bR][bC] = '*';
		}
		else if(sign[0] == 'X'){
			int xR, xC;
			scanf("%d %d", &xR, &xC);
			arr[xR][xC] = 'X';
		}
		else if(sign[0] == '$'){
			int sR, sC;
			scanf("%d %d %d", &sR, &sC, &m);
			amount[sR][sC] = m;
			arr[sR][sC] = '$';
		}
		else if(sign[0] == 's'){
			scanf("%d %d", &oR, &oC);
			arr[oR][oC] = 'O';
		}
	scanf("%s", sign);
	}
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			printf("%c",arr[i][j]);
		}
	printf("\n");
	}
	printf("\n");
	char moves[50];
	int i = 0;
	scanf("%s", moves);
	int flag = 0;
	while(moves[i] != '\0'){
		if(moves[i] == 'd'){
			if(arr[oR+1][oC] == '*'){
				printf("INVALID MOVE. TRY ANOTHER DIRECTION!\n");			
			}
			else if(arr[oR+1][oC] == 'X'){
				printf("YOU MET WITH THE ENEMY AND LOST THE GAME :(\nGAME IS OVER!\n");
				flag = 1;
				for (int i = 0; i < R; i++){
				for (int j = 0; j < C; j++){
					printf("%c",arr[i][j]);
				}
				printf("\n");
			}
			printf("\n");
				break;
			}
			else if(arr[oR+1][oC] == '$'){
				printf("YOU GOT %d $.\n", amount[oR+1][oC]);
				bonus += amount[oR+1][oC];
				oR += 1;
				arr[oR-1][oC] = ' ';
				arr[oR][oC] = 'O';
			}
			else if(oR+1 == fR && oC == fC){
				printf("CONGRATS! YOU GOT %d BONUS:)\n", bonus);
				oR += 1;
				arr[oR-1][oC] = ' ';
				arr[oR][oC] = 'O';
				for (int i = 0; i < R; i++){
				for (int j = 0; j < C; j++){
					printf("%c",arr[i][j]);
				}
				printf("\n");
			}
			printf("\n");
			flag += 1;
				break;
			}
			else{
				oR += 1;
				arr[oR-1][oC] = ' ';
				arr[oR][oC] = 'O';
			}
			for (int i = 0; i < R; i++){
				for (int j = 0; j < C; j++){
					printf("%c",arr[i][j]);
				}
				printf("\n");
			}
			printf("\n");
		}
		else if(moves[i] == 'u'){
			if(arr[oR-1][oC] == '*'){
				printf("INVALID MOVE. TRY ANOTHER DIRECTION!\n");			
			}
			else if(arr[oR-1][oC] == 'X'){
				printf("YOU MET WITH THE ENEMY AND LOST THE GAME :(\nGAME IS OVER!\n");
				flag = 1;
				for (int i = 0; i < R; i++){
					for (int j = 0; j < C; j++){
						printf("%c",arr[i][j]);
					}
					printf("\n");
				}
				printf("\n");
				break;
			}
			else if(arr[oR-1][oC] == '$'){
				printf("YOU GOT %d $.\n", amount[oR-1][oC]);
				bonus += amount[oR-1][oC];
				oR -= 1;
				arr[oR+1][oC] = ' ';
				arr[oR][oC] = 'O';
			}
			else if(oR-1 == fR && oC == fC){
				printf("CONGRATS! YOU GOT %d BONUS:)\n", bonus);
				oR -= 1;
				arr[oR+1][oC] = ' ';
				arr[oR][oC] = 'O';
				for (int i = 0; i < R; i++){
					for (int j = 0; j < C; j++){
						printf("%c",arr[i][j]);
					}
					printf("\n");
				}
				printf("\n");
				break;
				flag += 1;
			}
			else{
				oR -= 1;
				arr[oR+1][oC] = ' ';
				arr[oR][oC] = 'O';
			}
			for (int i = 0; i < R; i++){
				for (int j = 0; j < C; j++){
					printf("%c",arr[i][j]);
				}
				printf("\n");
			}
			printf("\n");
		}
		else if(moves[i] == 'r'){
			if(arr[oR][oC+1] == '*'){
				printf("INVALID MOVE. TRY ANOTHER DIRECTION!\n");			
			}
			else if(arr[oR][oC+1] == 'X'){
				printf("YOU MET WITH THE ENEMY AND LOST THE GAME :(\nGAME IS OVER!\n");
				flag = 1;
				for (int i = 0; i < R; i++){
					for (int j = 0; j < C; j++){
						printf("%c",arr[i][j]);
					}
					printf("\n");
				}
				printf("\n");
				break;
			}
			else if(arr[oR][oC+1] == '$'){
				printf("YOU GOT %d $.\n", amount[oR][oC+1]);
				bonus += amount[oR][oC+1];
				oC += 1;
				arr[oR][oC-1] = ' ';
				arr[oR][oC] = 'O';
			}
			else if(oR == fR && oC+1 == fC){
				printf("CONGRATS! YOU GOT %d BONUS:)\n", bonus);
				oC += 1;
				arr[oR][oC-1] = ' ';
				arr[oR][oC] = 'O';
				for (int i = 0; i < R; i++){
					for (int j = 0; j < C; j++){
						printf("%c",arr[i][j]);
					}
					printf("\n");
				}
				printf("\n");
				flag += 1;
				break;
			}
			else{
				oC += 1;
				arr[oR][oC-1] = ' ';
				arr[oR][oC] = 'O';
			}
			for (int i = 0; i < R; i++){
				for (int j = 0; j < C; j++){
					printf("%c",arr[i][j]);
				}
				printf("\n");
			}
			printf("\n");
		}
		else if(moves[i] == 'l'){
			if(arr[oR][oC-1] == '*'){
				printf("INVALID MOVE. TRY ANOTHER DIRECTION!\n");			
			}
			else if(arr[oR][oC-1] == 'X'){
				printf("YOU MET WITH THE ENEMY AND LOST THE GAME :(\nGAME IS OVER!\n");
				flag = 1;
				for (int i = 0; i < R; i++){
				for (int j = 0; j < C; j++){
					printf("%c",arr[i][j]);
				}
				printf("\n");
			}
			printf("\n");
				break;
			}
			else if(arr[oR][oC-1] == '$'){
				printf("YOU GOT %d $.\n", amount[oR][oC-1]);
				bonus += amount[oR][oC-1];
				oC -= 1;
				arr[oR][oC+1] = ' ';
				arr[oR][oC] = 'O';
			}
			else if(oR == fR && oC-1 == fC){
				printf("CONGRATS! YOU GOT %d BONUS:)\n", bonus);
				oC -= 1;
				arr[oR][oC+1] = ' ';
				arr[oR][oC] = 'O';
				for (int i = 0; i < R; i++){
					for (int j = 0; j < C; j++){
						printf("%c",arr[i][j]);
					}
				printf("\n");
				}
				printf("\n");
				flag += 1;
				break;
			}

			else{
				oC -= 1;
				arr[oR][oC+1] = ' ';
				arr[oR][oC] = 'O';
			}
			for (int i = 0; i < R; i++){
				for (int j = 0; j < C; j++){
					printf("%c",arr[i][j]);
				}
				printf("\n");
			}
			printf("\n");
		}
		else if(moves[i] == 'q'){
		printf("YOU COULD NOT REACH THE FINAL POSITION :(\nGAME IS OVER!\n");
		for (int i = 0; i < R; i++){
				for (int j = 0; j < C; j++){
					printf("%c",arr[i][j]);
				}
				printf("\n");
			}
			printf("\n");
			flag += 1;
			break;
		}
		i++;
	}
	if(flag == 0){
		printf("YOU COULD NOT REACH THE FINAL POSITION :(\nGAME IS OVER!\n");
		for (int i = 0; i < R; i++){
				for (int j = 0; j < C; j++){
					printf("%c",arr[i][j]);
				}
				printf("\n");
			}
			printf("\n");
	}
}

