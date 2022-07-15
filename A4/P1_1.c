/**
Jonalton Jude Hamilton
1045218
jjudeham@uoguelph.ca
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "P1.h"

//parse file input and add word to struct set
set* separateData(char *data,int *size){
    char space[2] = " ";
    char *tok;
    set *Set = malloc(sizeof(set));
    char *temp = malloc(sizeof(char));

    int i = 0;

    tok = strtok(data,space);

    while(tok != NULL){
        //printf("tok %s ",tok);
        if (tok[0] == '\n'){
            temp = realloc(temp,sizeof(char)*strlen(tok));
            for (int j = 1; j<strlen(tok);j++){
                temp[j-1] = tok[j];
            }
            temp[strlen(tok)-1] = '\0';
            strcpy(tok,temp);
        }

        if (strcmp(tok,"") != 0 && strcmp(tok," ") != 0 && !wordExists(Set,tok,i)){

            Set = realloc(Set,sizeof(set)*(i+1));
            Set[i].key = malloc(sizeof(char)*(strlen(tok)+1));
            strcpy(Set[i].key,tok);
            Set[i].n = 1;
            Set[i].prob = 0;
            i++;
        }
        tok = strtok(NULL,space);
    }
    *size = i;

    free(temp);
    return Set;

}

//check if word already exists in struct of keys
int wordExists(set *Set, char *word,int n){
    if (n > 0){
        for (int i = 0; i<n;i++){
            if (strcmp(Set[i].key,word) == 0){
                Set[i].n++;
                return 1;
            }
        }
    }
    return 0;
}


//calculate probability of each word
void calculateProbability(set *Set,int size){
    for (int i = 0; i < size; i++){
        Set[i].prob = (Set[i].n/(float)2045.0);
    }
}


//arrange words alphabetically
void orderKeys(set *Set, int size){
    char temp[50]; 
    int tempN = 0;

    for (int i = 0; i < size; i++){
        //printf("%d: %f ",i,Set[i].prob);
        for (int j = 0; j < size; j++){
            if (strcmp(Set[i].key,Set[j].key) < 0){
                strcpy(temp,Set[j].key);
                strcpy(Set[j].key,Set[i].key);
                strcpy(Set[i].key,temp);

                tempN = Set[j].n;
                Set[j].n = Set[i].n;
                Set[i].n = tempN;    
            }
        }
    }
}


//builds Optimal BST tables
float** optimalBST(set *Set, int size, int **R){
    float **C = malloc(sizeof(float*)*size+2);
    int z = 1;
    int j=0;
    float minVal = 0.0;
    int kMin = 0;
    float sum = 0.0;

    C[0] = malloc(sizeof(float)*size);
    R[0] = malloc(sizeof(float)*size);
    for (int i = 0; i < size; i++){
        C[z] = malloc(sizeof(float)*size);
        R[z] = malloc(sizeof(float)*size);


        C[z][z-1] = 0;
        C[z][z] = Set[i].prob;
        R[z][z] = i;
        z++;
    }
    C[size+1] = malloc(sizeof(float)*size);
    R[size+1] = malloc(sizeof(float)*size);
    C[size+1][size] = 0;

    for (int d = 1; d <= size-1;d++){
        for (int i = 1; i <= size-d; i++){
            j = i+d;
            //minval
            minVal = INT_MAX;
            for (int k=i; k <= j;k++){
                ///printf("i %d k %d j %d\n",i,k,j);
                if (C[i][k-1] + C[k+1][j] < minVal){
                    minVal = C[i][k-1] + C[k+1][j];
                    kMin = k - 1;
                }
            }
            R[i][j] = kMin;
            sum = Set[i-1].prob;
            for (int s = i+1; s<=j; s++){
                sum += Set[s-1].prob;
            }
            C[i][j] = minVal + sum;
        }
    }
    return C;
}

//this functions recursively looks through root table to find corresponding key to compare user key to
void findKey(char key[50],int **R,int a,int r,int size,set *Set,float **C){
    int node = R[a][r];
    if (node < size){
        if(strcmp(key,Set[node].key) < 0){
            printf("Compared with %s (%.3f), go left subtree\n",Set[node].key,C[a][r]);
            findKey(key,R,a,node-1,size,Set,C);
        }
        else if(strcmp(key,Set[node].key) > 0){
            printf("Compared with %s (%.3f), go right subtree\n",Set[node].key,C[a][r]);
            findKey(key,R,node+2,r,size,Set,C);
        }
        else if (strcmp(key,Set[node].key) == 0){
            printf("Compared with %s (%.3f), found\n",Set[node].key,C[a][r]);
        }
    }
    else{
        printf("%s not found\n",key);
    }
}

//uses the greedy technique to find key
void greedy(char key[50],set *Set,int start,int end){
    int index = findHighestProb(Set,start,end);


    if (index < end && index != -1){
        if (strcmp(key,Set[index].key) < 0){
            printf("Compared with %s (%.3f), go left subtree\n",Set[index].key,Set[index].prob);
            greedy(key,Set,start,index-1);
        }
        else if (strcmp(key,Set[index].key) > 0){
            printf("Compared with %s (%.3f), go right subtree\n",Set[index].key,Set[index].prob);
            greedy(key,Set,index+1,end);
        }
        else if (strcmp(key,Set[index].key) == 0){
            printf("Compared with %s (%.3f), found\n",Set[index].key,Set[index].prob);
        }
    }
    else{
        printf("%s not found\n",key);
    }

}

//finds highest probability in a range of given words and returns its index value, -1 for failure
int findHighestProb(set *Set,int start,int end){
    float tempP = 0.00;
    int index = -1;
    for (int i = start; i<end;i++){
        if (Set[i].prob > tempP){
            tempP = Set[i].prob;
            index = i;
        }
    }
    return index;
}
