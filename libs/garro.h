#ifndef __GARRO_H__
#define __GARRO_H__
	
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

void swap(int* a, int* b){  //"dichiari un puntatore tramite *"	
							        //*--> ottieni il contenuto dell'indirizzo di memoria
	int c = *a;				  //&--> ottieni l'indirizzo di memoria di una variabile
	*a = *b;				    //"il contenuto di a(a puntatore) rimpiazzato dal contenuto del puntatore b"
	*b = c;					    //"riferimento" alle variabili globali --> es. puntatori tocca i dati original
}							      //"copia" non tocca i dati originali

void sort(int array[], int dim){

	int min;
    
    for (int i = 0; i < dim - 1; i++){


      for (int j = i + 1; j < dim; j++){

        if(array[j] < array[i])
          swap(&array[i], &array[j]);
      }
    }
}

void stSort(int* gigio,int dim){		
	
	int n1,n2;

	for(int i = 0; i < 100; i++){

		n1 = rand() % (dim);
		n2 = rand() % (dim);
		swap(gigio + n1,gigio + n2);
	}
}


int max(int a, int b){ return (a > b)? a:b; }


void isto(int* array, int dim){
	for (int i = 0; i < dim; i++){

		printf("%2d|", (i + 2));
		for (int j = 0; j < (array[i] / 10); j++)
			putchar('#');
		putchar('\n'); 
	}
}

int myAtoi(char* s){
	int ret = 0;
	for (; *s; s++)
		ret = ret * 10 + *s - '0';	//aggiungo valore di num 0 in ASCII
	return ret;
}

void myItoa(int num, char* ris){
    char elab[10];
    int i;

   for(i = 0; num; i++){
        elab[i] = num % 10 + '0';
        num/=10;
    }

    for(int j = 0; j < i; j++)    
        ris[j] = elab[i - j - 1];
    
    ris[i] = '\0';
} 

float myatof(char* array){

	float ret, dec;
    int flag = 0;
    int cnt = 0;
    for(;*array;array++){
        if(flag == 0){
            ret = ret * 10 + *array - '0';
            if(*(array + 1) == '.' || *(array + 1) == ','){
            	flag = 1;
            	array++;
            }
            printf("ret: %f\n", ret);
        }
        else{
            dec = dec * 10 + *array - '0'; 
            cnt++;
            printf("dec: %f\n", dec);
        }
    }

    for(; cnt; cnt--){dec /= 10;}
    ret += dec;

    return ret;
}

char* strConc(char* str1, char* str2){

	int lenght1 = strlen(str1);
	int lenght2 = strlen(str2);
	char* ret = (char*)malloc(sizeof(char) * ( lenght2 + lenght1 + 1));	//+ 1 per tappo 
	char* tmp = ret;
	for(; *str1; str1++, tmp++)
		*tmp = *str1;
	
	for(; *str2; str2++, tmp++)
		*tmp = *str2;
	tmp = '\0';
	return ret;
}

char* strCopy(char* str){
	int lenght = strlen(str);
	char* ret = (char*)malloc( sizeof(char) * (lenght + 1));
	
    for(char* tmp = ret; *tmp = *str; str++, tmp++){}	//assegna e poi fa str != 0 assegna anche '\0'
	return ret;
}

char* strPref(char* pref, char* str){
	char* ret = (char*)malloc(sizeof(char) * (strlen(str) + strlen(pref)) + 1);	
	char* tmp = ret;
	
	for(; *pref; tmp++, pref++)
		*tmp = *pref;

	for(; *str; str++,tmp++)
		*tmp = *str;
	
	*tmp = '\0';
	return ret;
}

char* strSuff(char* str, char* suff){
	char* ret = (char*)malloc(sizeof(char) * (strlen(str) + strlen(suff)) + 1);	
	char* tmp = ret;
	for (; *str; str++, tmp++)
		*tmp = *str;

	for(;*suff; tmp++, suff++)
		*tmp = *suff;

	*tmp = '\0';
	return ret;
}

int isPal(char* str){	//palindromi 
	char* backstr = str + strlen(str) - 1;
	for(; *str; str++, backstr--){
		if(*str == ' ')
			str++;
		if(*backstr == ' ')
			backstr--;
		if(*str != *backstr)
			return 0;
	}
	return 1;
}

char* revStr(char* str){
	char* ret = (char*)malloc(sizeof(char) * strlen(str) + 1);
	char* tmp = ret + strlen(str);
	*tmp = '\0';
	tmp--;

	for(; *str; tmp--, str++)
		*tmp = *str;

	return ret;
}

int charCnt(char* str, char c){
	int cnt = 0;
	for(;*str;str++){
		if(*str == c)
			cnt++;
	}
	return cnt;

}

char* charDel(char* str, char c){
	int lenght = strlen(str) - charCnt(str,c);
	char* ret = (char*)malloc(sizeof(char) * lenght + 1);
	char* tmp = ret;
	for(;*str;str++){
		if (*str != c){
			*tmp = *str;
			tmp++;			
		}
	}
	*tmp = '\0';
	return ret;
}

void upperCase(char* stringa){

	for(; *stringa; stringa++)
		*stringa -= ((*stringa >= 'a') && (*stringa <= 'z'))? 32 : 0;
}

//destra>sinistra 1 	destra<sinistra -1	destra==sinistra 0 
int cmpStr(char* s1,char* s2){
	if(*s1 > *s2)
		return -1;
	if(*s1 < *s2)
		return 1;
	if(!*s1)
		return 0;
	return cmpStr(++s1,++s2);	//ricorsione ++s1,++s2
								//se uso s1++,s2++-->stack overflow oltre lo stack
}								//registro di valori di return first in last out 
int fib(int n){				//successione di Fibonacci

	if(n <= 1)	return 0;
	return fib(n - 1) + fib(n - 2);
}
int fattoriale(int n){

	if(n)	
		return fattoriale(n - 1) * n;
	return 1;

}

int sum(int* array){
	if(*array == -1) return 0;
	return *array + sum(++array);
}
// int sum(int* array){
//
// 	static int somma;	
// 	if(*array == -1)
// 		return somma;
// 	somma += *array;
// 	return sum(++array);
// }

char** dupVett(char** v){
	int l;
	for(l = 0; *(v + l); l++){}
	char** ret = (char**)malloc(sizeof(char*) * (l + 1));
	for(l = 0;*(v + l); l++)
		*(ret + l) = strdup(*(v + l));
	*(ret + l) = NULL;
	return ret;
}

char** split(char* line, char* sep){

	char* tmp = line;
	int count = 0;
	while(*tmp){	//count di numero di separatori

        if(*sep == *tmp)
            count++;
        tmp++;
    }
    
	char** ret = (char**)malloc(sizeof(char*) * (count + 2));	//pointers + NULL

	int i = 0;
	char* str = strtok(line, sep);
	while(str){
		*(ret + i) = strdup(str);
		i++;
		str = strtok(NULL, sep);
	}
	*(ret + i) = NULL;
	return ret;
}

char* getLast(char* str, char c){
	char* ret = NULL;
	for(;*str;str++)
		if(*str == c)
			ret = str;
	return ret;
}

#endif	//__GARRO_H__
