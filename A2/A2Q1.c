#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <inttypes.h>
#include "parseFile.h"

long int millis(){
	struct timespec now;
	long int now_1;
	timespec_get(&now,TIME_UTC);
	now_1 = ((long int) now.tv_sec) * 1000 + ((long int) now.tv_nsec)/1000000;
	return now_1;
}

int bruteForce(int n,int *A){
	int inversion = 0;
	for (int i=0;i<n-1;i++){
		for(int j=(i+1);j<n;j++){
			if (A[j] < A[i]){
				inversion++;
			}
		}
	}
	return inversion;
}



int merge2(int *A, int *B, int *C, int bCount, int cCount){
	int i,j,k;
	i=0;
	j=0;
	k=0;
	int invCount = 0;
	/*printf("in merge2 bCount %d cCount %d\n",bCount,cCount);
	for (int z=0;z<bCount;z++){
		printf("B[%d] : %d\n",z,B[z]);
	}
	for (int z=0;z<cCount;z++){
		printf("C[%d] : %d\n",z,C[z]);
	}*/
	int half = ((bCount)+(cCount))/2;
	//printf("half %d\n",half);
	while ((i<bCount) && (j<cCount)){
		//printf("%d %d\n",B[i],C[j]);
		if (B[i] <= C[j]){
			A[k] = B[i];
			i++;
		}
		else{
			//printf("inverse: %d %d\n",B[i],C[j]);
			A[k] = C[j];
			j++;
			//invCount++;
			invCount = invCount + half  -i;
		}
		k++;
	}

	if (i == bCount){
		while (j<cCount){
			A[k] = C[j];
			k++;
			j++;
		} 
	}
	else{
		while (i<bCount){
			A[k] = B[i];
			k++;
			i++;
		}
	}
	
	return invCount;
}

int mergeSort2(int *A,int length){
	int half, invCount = 0;
	//printf("length %d\n",length);
	if (length > 1){
		half = length/2;
		//printf("half %d\n",half);
		int *B = malloc(sizeof(int)*half);
		int *C = malloc(sizeof(int)*half);
		int bCount = 0;
		int cCount = 0;
		for (int i = 0; i <= half; i++){
			B[bCount] = A[i];
			bCount++;
			//printf("B[%d]=%d\n",bCount,B[bCount-1]);
		}
		for(int i=half+1;i<=length;i++){
			C[cCount] = A[i];
			cCount++;
			//printf("C[%d]=%d\n",cCount,C[cCount-1]);
		}
		//printf("bCount %d cCount %d\n",bCount,cCount);
		invCount += mergeSort2(B,bCount-1);
		invCount += mergeSort2(C,cCount-1);

		invCount += merge2(A,B,C,bCount-1,cCount-1);

	}
	return invCount;
}


int main(){
	int n;
	int *A = parseFile1(&n,"Q1.txt");
	long int begin, end, execTime;
	int totalElements = n*5;

	/*for (int i=0;i<(n*5);i++){
		printf("%d ",A[i]);
		if((i+1)%5 == 0){
			printf("\n");
			printf("%d: ",i+1);
		}
	}
	//printf("\n\n%d\n",A[49999]);
	printf("%d\n",n);*/

	begin = millis();
	int invCountBF = bruteForce(totalElements,A);
	end = millis();


	execTime = end - begin;
	printf("\n*********BRUTE FORECE*********\n");
	printf("Execution Time = %ld ms\n",execTime);
	printf("Total number of Inversions = %d\n",invCountBF);

	printf("\n******************************\n");
	

	//int *temp = malloc(sizeof(int)*totalElements);
	begin = millis();
	//int invCountDC = mergeSort(A,temp,0,totalElements-1);
	int invCountDC = mergeSort2(A,totalElements-1);
	end = millis();


	execTime = end - begin;
	printf("\n******DIVIDE AND CONQUER******\n");
	printf("ExecutionTime = %ld ms\n",execTime);
	printf("Total number of Inversions: %d\n",invCountDC);

	return -1;
}
