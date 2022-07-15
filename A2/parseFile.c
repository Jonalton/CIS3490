#include "parseFile.h"

int *parseFile1(int *n,char *filename){
	FILE *fp;
	*n = 0;
	int *A;
	//char buffer[35];
	A = malloc(sizeof(int)*(*n+1));
	int buffer[5];


	fp = fopen(filename,"r+");
	if (fp == NULL){
		printf("File error\n");
		return NULL;
	}

	int k=0;
	while(!feof(fp)){
		fscanf(fp,"%d %d %d %d %d",&buffer[0],&buffer[1],&buffer[2],&buffer[3],&buffer[4]);
		++*n;
		A = realloc(A, sizeof(int)*(*n*5));
		for (int i=0; i<5; i++){
			A[k] = buffer[i];
			k++;
			/*printf("%d ",A[i]);
			if((i+1)%5 == 0){
				printf("\n");
			}*/
		}
		//printf("%d %d %d %d %d",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);
	}	
	*n = *n - 1;
	fclose(fp);
	return A;
}

double **parseFile2(int *n,char *filename){
	FILE *fp;
	*n = 0;
	double **arr = malloc(sizeof(double)*(*n+1));
	//arr[0] = malloc(sizeof(double)*2);

	fp = fopen(filename,"r+");
	if (fp == NULL){
		printf("File error\n");
		return NULL;
	}
	while (!feof(fp)){
		arr = realloc(arr,sizeof(double)*(*n+1));
		arr[*n] = malloc(sizeof(double)*2);
		fscanf(fp,"%lf %lf",&arr[*n][0],&arr[*n][1]);
		++*n;
		
		/*for (int i=0;i<2;i++){
			arr[k] = buffer[i];
			k++;
		}*/
	}
	*n = *n - 1;
	fclose(fp);
	return arr;

}

