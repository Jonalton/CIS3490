/**
Jonalton Jude Hamilton
1045218
jjudeham@uoguelph.ca
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parseFile.h"

char* parseFile(char* filename){
    char *data = malloc(sizeof(char));
    //char buffer[128];
    FILE *fp = fopen(filename,"r+");
    int n = 0;
    int c;
    while((c = fgetc(fp)) != EOF){
        data = realloc(data,sizeof(char)*(n+1));
        data[n] = (char)c;
        n++;
    }
    data[n] = '\0';
    fclose(fp);
    return data;
}
