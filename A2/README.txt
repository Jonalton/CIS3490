To compile and run programs:
1. make all
2. To run counting inversions program type: ./A2Q1
3. To run Finding Shortest Path Around type: ./A2Q2

note: Finding shortest path is incomplete, got through a bit a 2.1 




1.1:

ALGORITHM countInversions(n,A[0...n-1])
	//Counts for the total number of inversions in a given file of numbers
	//Input: An array A[0...n-1] and variable n given length of A
	//Output: Total number of inversions counted in the array

	for i <- 0 to n-2 do
		for j <- i+1 to n-1 do
			if A[j] < A[i]	inversionCount++

C(n) = n(n-1)/2

Efficiency class is n^2



1.2:

ALGORITHM mergeSort(A[0...n-1],n)
	//Sorts Array A[0...n-1] recursively
	//Input: An array A[0...n-1] and n for length of A
	//Output: Array A[0...n-1] sorted in nondecreasing order and number of inversions in original array

	invCount <- 0
	if n > 1
		copy A[0...n/2-1] to B[0...n/2-1]
		copy A[n/2-1...n] to C[0...n/2-1]
		invCount <- invCount + mergeSort(B[0...n/2-1],n/2-1)
		invCount <- invCount + mergeSort(C[0...n/2-1],n/2-1)
		invCount <- invCount + merge(B,C,A,bCount,cCount)


ALGORITHM merge(B[0...bCount-1],C[0...cCount-1],A[0...bCount+cCount-1],bCount,cCount)
	//Merges two arrays B and C into one sorted Array A
	//Input: Arrays B[0...bCount-1] and C[0...cCount-1] both sorted 
	//Ouput: Arrays B[0...bCount-1] and C[0...cCount-1] merged together to form A[0...bCount+cCount-1] and also counts total number of inversions

	i<-0;j<-0;k<-0;invCount<-0
	half<-(bCount+cCount)/2
	while i<bCount and j<cCount do
		if B[i] < C[j]
			A[k]<-B[i]; i<-i+1
		else 
			A[k]<-C[j]; j<-j+1; invCount <- invCount + half - i
		k<-k+1

	if i=p
		copy C[j...cCount-1] to A[k...bCount+cCount-1]
	else copy B[i...bCount-1] to A[k...bCount+cCount-1]


C(n) = 2C(n/2) + n/2, C(1) = 0

a=2; b=2; d=1

a=b^d
2=2^1 -----> using Master Theorem the efficiency class is n^dlogn=nlogn



1.3:

The divide and conquer method is superior to the brute force algorithm. Brute force has an efficiency of n^2, divide and conqeur has efficiency of nlogn. Brute force takes up to 50000 ms, while divde and conquer takes around 10ms.



2.1:

ALGORITHM computeHull(arr[0...n-1][0...2],n,hullCount)
	//counts the number of extreme points in the given array to find smallest convex set
	//Input: Array arr[0...n-1], n for length, and hullCount for number of coordinates in convex hull
	//Output: Array hull[0...hullCount-1] representing the coordinates of the convex hull

	extremePoint<-1
	for i<-0 to n-1 do
		for j<-0 to n-1 do
			x1<-arr[i][0];y1<-arr[i][1]
			x2<-arr[j][0];y2<-arr[j][1]
			c<-x1*y2 - y1*x2; a<-y2-y1; b<-x1-x2
			extremePoint<-1
			for k<-0 to n-1 do
				sum<-a*arr[k][0] + b*arr[k][1]
				if ((sum-c < 0) == 0)
					extremePoint <- 0; break

			if extremePoint<-1
				hullCount <- hullCount + 2
				copy x1 to hull[hullCount-1][0]
				copy y1 to hull[hullCount-1][1]
				copy x2 to hull[hullCount][0]
				copy y2 to hull[hullCount][1]


Efficiency class is n^3














