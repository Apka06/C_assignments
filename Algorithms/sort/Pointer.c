#include <stdio.h>
#include <string.h>
#define LENGTH 5

void swap(int *num1, int *num2);
int pointer_islemi();
int pointer_printer();
int maxi(int *a, int length);
int strlenv2(char *c);
char *dondur(char *c, int idx);
char *dayf(char *array[], int len, int day);

int main(){
	
	char *days[7] = {"pazartesi", "salı", "çarşamba", "perşembe", "cuma", "cumartesi", "pazar"};
	char *p = dayf(days,7,3);
	if (p != NULL)
		printf("%s\n", p);
}

char *dayf(char *array[], int len, int day){

	//Argüman olarak pointer arrayi alan ve yine pointer arrayi döndüren bir fonksiyon yazdık.
	
	if (day > len || day < 1){
		return 	NULL;	
	}
	else{
		return array[day-1];
	}
}


char *dondur(char *c, int idx){

	int len = strlen(c);
	if(idx > len){
		return NULL;
	}
	else{
		return c + idx;
	}

}

int strlenv2(char *c){
	
	//Pointer kullanarak stringin uzunluğunu bulduk.

	int len = 0;
	while (c[len] != '\0'){
		len += 1;
	}
	return len;

}
int maxi(int *a, int length){
	
	//int sayi[5] = {1,2,30,-5,59};
	//int *p = sayi;
	//pointer tanımlarken arrayin ismi arrayin başlangıç adresini verir.
	//*(p+1) = p[1] = sayi[1]
	//Pointer ile arrayi fonksiyona	argüman olarak gönderdik. a artık arrayi temsil ediyor.
	
	int maks = a[0];
	for(unsigned int i = 1; i<length; i++){
		if(maks < a[i]){
			maks = a[i];}
	}
	return maks;
}

void swap(int *num1, int *num2){

	//Pointer kullanarak local olmayan iki değişkeninin değerlerini değiştirebildik.
	int keeper = *num1;
	*num1 = *num2;
	*num2 = keeper;
	printf("%d, %d\n", *num1, *num2);
}

int pointer_islemi(){
	int i, j = 1;
	int *jp1, *jp2 = &j;
	jp1 = jp2;
	i = ++(*jp2);
	*jp2 = *jp1 + i;
	printf("i = %d j = %d jp1 = %u jp2 = %u\n", i,j,*jp1,*jp2);
}

int pointer_printer(){
	//Pointerlar adres bilgisi tutar
	//"&" değişkenin adres bilgisini verir
	// "*" pointer tanımlamaya ve listelerde adresin içindeki veriyi almaya yarar.
	int i = 5, *ip;
	ip = &i;
	float b = 3.1, *bp;
	bp = &b;
	double d = 3.123, *dp;
	dp = &d;
	char c = 'a', *cp;
	cp = &c;
	int array[5] = {1,2,3,4,5};
	int *arrayp;
	arrayp = &array[0];
	printf("adres = %p değer = %d\n", ip ,*ip);
	printf("adres = %p değer = %.2f\n", bp ,*bp);
	printf("adres = %p değer = %.4lf\n", dp ,*dp);
	printf("adres = %p değer = %c\n", cp ,*cp);
	printf("adres = %p değer = %d\n", arrayp ,*arrayp);
}
