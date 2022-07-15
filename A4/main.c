/**
Jonalton Jude Hamilton
1045218
jjudeham@uoguelph.ca
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "P1.h"
#include "parseFile.h"

int main(){
    char buffer[50];
    scanf("%s",buffer);
    char *data = parseFile("data_A4_Q1.txt");
    if (strcmp(buffer,"q11")==0){

        int size = 0;
        set *Set = separateData(data,&size);

        //order strings
        orderKeys(Set,size);
        calculateProbability(Set,size);

        char key[50];
        printf("Enter a key: ");
        scanf("%s",key);

        int **R = malloc(sizeof(int*)*size+2);
        float** C=optimalBST(Set,size,R);
        findKey(key,R,1,size,size,Set,C);
        free(data);
        /*for (int i=0;i<=size+1;i++){
            free(C[i]);
            free(R[i]);
        }
        free(C);
        free(R);*/
  
    }   
    else if (strcmp(buffer,"q12") == 0){
        int size = 0;
        set *Set = separateData(data,&size);

        //order strings
        orderKeys(Set,size);
        calculateProbability(Set,size);

        char key[50];
        printf("Enter a key: ");
        scanf("%s",key);
        greedy(key,Set,0,size);
    }
    return 0;  
}
