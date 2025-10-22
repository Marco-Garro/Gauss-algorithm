#ifndef OTHER_LIB_H
#define OTHER_LIB_H
#include <string.h>

// Prototypes
char* readLine(FILE* fpr, int columns);
char** split(char* line, char* sep);

//impl
char* readLine(FILE* fpr, int columns){

    char ret[columns];
    char* tmp = ret;
    char c = fgetc(fpr);
    for(;c != '\n' && c != EOF;tmp++){
        *tmp = c;
        c = fgetc(fpr);
    }
    *tmp = '\0';
    return strdup(ret);
}

char** split(char* line, char* sep){

    char* tmp = line;
    int count = 0;
    while(*tmp){

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

#endif //OTHER_LIB_H