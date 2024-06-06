#include <stdio.h>



// find value in list
int main(){
//	int A[] = {3, 4, 5, 6, 7, 8, 32};
//	int x, res, list_length;
//	scanf("%d", &x);

//	list_length = sizeof(A) / sizeof(A[0]);
//	res = search(x, A, list_length);	
//	
//	res == 1 ? printf("Find"): printf("Not Find");
	char *s = "Hello";
//	char s[] = {'h', 'e', 'l', 'l', 'o', 0};
	printf("%s\n", s);
	
	return 0;
}


int search(int number, int List[], int list_length){
	int ret = -1;
	int start = 0;
	for(start; start<list_length; start++){
		if(List[start] == number){
			ret = 1;
			return ret;
		}
	}
	return ret;
}
