#include <stdio.h>


int CalSubSum(int A[], int N){
	int i, j, k;
	int ThisSum = 0;
	int MaxSum = 0;
	for(i=0; i<N; i++){
		ThisSum = 0;
		for(j=i; j<N; j++){
			ThisSum += A[j];
			if (ThisSum > MaxSum){
				MaxSum = ThisSum;
			}
		}
	}
	return MaxSum;
	
}


int main(){
	int res;
	int AList[] = {4, -3, 5, -2, -1, 2, 6, -2};
	res = CalSubSum(AList, 8);
	printf("This MaxSum is %d\n", res);
	return 0;
	
}
