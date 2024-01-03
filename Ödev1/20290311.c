#include <stdio.h>

int rd(float);
int binary(int);
int octal(int);
int hexadecimal(int);

int main()
{
	char sign_list[] = {'h', 'H', 'o', 'O', 'b', 'B', '\0'}; 
	int input;
	int decimal = 0;
	char sign;
	scanf("%d", &input);
	decimal += input;
	while (scanf("%s", &sign) != EOF)
	{
		if (sign == sign_list[4] || sign == sign_list[5])
		{
			binary(decimal);
			printf("\n");
		}
		else if (sign == sign_list[2] || sign == sign_list[3])
		{
			octal(decimal);
			printf("\n");
		}
		else if (sign == sign_list[0] || sign == sign_list[1])
		{
			hexadecimal(decimal);
			printf("\n");
		}
		decimal *= 0;
		scanf("%d", &input);
		decimal += input;
	}
}


int binary(int num)
{	
	if (num >= 1)
	{
		binary(rd(num / 2));
	}
	int binary_num = num % 2;
	if (num > 0)
	{
		printf("%d", binary_num);
	}
}


int octal(int num)
{
	if (num >= 1)
	{
		octal(rd(num / 8));
	}
	int octal_num = num % 8;
	if (num > 0)
	{
		printf("%d", octal_num);
	}
}


int hexadecimal(int num)
{
	char* hexarray [] = {"A" ,"B","C" ,"D" ,"E" ,"F" , "\0"};
	if (num >= 1)
	{
		hexadecimal(rd(num / 16));
	}
	int hexadecimal_num = num % 16;
	if (num > 0)
	{
		switch (hexadecimal_num)
		{	
			case 10:
				printf("%s", hexarray[0]);
				break;
			case 11:
				printf("%s", hexarray[1]);
				break;
			case 12:
				printf("%s", hexarray[2]);
				break;
			case 13:
				printf("%s", hexarray[3]);
				break;
			case 14:
				printf("%s", hexarray[4]);
				break;
			case 15:
				printf("%s", hexarray[5]);
				break;
			default:
				printf("%d", hexadecimal_num);
		}
	}
}

// Function for floor division
int rd(float num)
{
	return num < 0 ? num -0.95 : num + 0.05;
}








