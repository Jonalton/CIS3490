#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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

double minVal(double x, double y){
	if (x<y){
		return x;
	}
	else{
		return y;
	}
}

double **computeHull(double **arr,int n,int *hullCount){
	*hullCount = 0;
	double x1,x2,y1,y2,c,a,b;
	int extremePoint = 1;

	double **hull = malloc(sizeof(double)*(*hullCount));
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			x1 = arr[i][0];
			y1 = arr[i][1];
			x2 = arr[j][0];
			y2 = arr[j][1];
			c = x1*y2 - y1*x2;
			a = y2-y1;
			b = x1-x2;
			extremePoint = 1;
			for (int k=0;k<n;k++){
				double sum = a*arr[k][0] + b*arr[k][1];
				//double sum = a + b;
				if ((sum-c > 0) == 0){
					extremePoint = 0;
					break;
				}
			}
			if (extremePoint == 1){
				*hullCount = *hullCount + 2;
				hull = realloc(hull,sizeof(double)*(*hullCount));
				hull[*hullCount-1] = malloc(sizeof(double)*2);
				hull[*hullCount-1][0] = x1;
				hull[*hullCount-1][1] = y1;
				hull[*hullCount] = malloc(sizeof(double)*2);
				hull[*hullCount][0] = x2;
				hull[*hullCount][1] = y2;
			}

		}
	}
	return hull;
}

double bruteForceClosestPair(double **arr,int n){
	double s1[2];
	double s2[2];
	long int begin,end,execTime;
	printf("Enter x and y coordinates for s1: ");
	scanf("%lf %lf",&s1[0],&s1[1]);
	printf("Enter x and y coordinates for s2: ");
	scanf("%lf %lf",&s2[0],&s2[1]);
	double a, b, c;
	int hullCount;
	
	/*
	a = s2[1] - s1[1];
	b = s1[0] - s2[0];
	c = s1[0]*s2[1] - s1[1]*s2[0];*/

	double distance = 0;
	begin = millis();
	double **hull = computeHull(arr,n,&hullCount);
	end = millis();
	execTime = end - begin;
	printf("Time for computing hull %ld ms\n",execTime);
	printf("Total extreme points: %d\n",hullCount);
	if (hull != NULL){
		
	}
	/*double xDiff = 0;
	double yDiff = 0;
	for (int i=0;i<n-1;i++){
		for (int j=i+1;j<n;j++){
			xDiff = pow((arr[i][0] - arr[j][0]),2);
			yDiff = pow((arr[i][1] - arr[j][1]),2);
			distance = minVal(distance,sqrt(xDiff - yDiff));
		}
	}
	printf("xDiff = %f\n",xDiff);
	printf("yDiff = %f\n",xDiff);*/
	return distance;
}

int main(){
	int n;
	double **arr = parseFile2(&n,"Q2.txt");
	//long int begin,end,timeExec;
	/*for (int i=0;i<n;i++){
		printf("%lf %lf\n",arr[i][0],arr[i][1]);
	}
	for (int i = 0; i<(n*2);i++){
		printf("%f ",arr[i]);
		if ((i+1)%2 == 0){
			printf("\n");
		}
	}*/
	//printf("total elements %d\n",n*2);
	//begin = millis();
	double distanceBF = bruteForceClosestPair(arr,n);
	//end = millis();
	//timeExec = end - begin;
	//printf("Execution Time %ld ms\n",timeExec);
	printf("distance %lf\n",distanceBF);
	return -1;
}
