#include <stdio.h>
#include <malloc.h>
#define MAXSIZE 100  // MAXSIZE 定义为 Data 数组的大小
typedef int ElementType;  // ElementType 可定义为任意类型
typedef struct LNode *List; 
struct LNode{
   ElementType Data[MAXSIZE]; 
   int Last;  // Last 定义线性表的最后一个元素
};
List L;

// get index=i: L----> Data[i]
// lenght of Linear-List(ArrayList)  L---> Last + 1

List MakeEmpty(); // Initial OrderList
int Find(ElementType X, List L); // find the first index of X
void Insert(ElementType X, int i, List L); // Insert X to index is i
void Delete(int i, List L); // Delete the value which index is i
ElementType FindKth(int K, List L); // return value which index is K
int Lenght(List L); // return the lenght of OrderList


// Initial OrderList
List MakeEmpty(){
	List L;
	L = (List)malloc(sizeof(struct LNode));
	L->Last = -1;
	return L;
}

// Find value
int Find(ElementType X,List L){
	int i = 0;
	while (i <= L->Last && L->Data[i] != X)
		i++;
	if (L->Last < i){
		return -1; // Can not find
	}
	else{
		return i; // return index if find
	}
}


// Insert
void Insert(ElementType X, int i, List L){
	int j;
	if (L->Last == MAXSIZE-1){
		printf("The orderlist is full of data\n");
		return ;
	}
	if (i < 0 || i > L->Last+1){
		printf("Insert index out of bound\n");
		return;
	}
	for (j=L->Last; j>=i; j--)
		L->Data[j+1] = L->Data[j];
	L->Data[i] = X;
	L->Last++;
	return;
}


// Delete
void Delete(int i, List L){
	int j;
	if (i < 0 || i > L->Last){
		printf("Delete index out of bound\n");
		return;
	}
	for (j=i+1; j<L->Last; j++){
		L->Data[j] = L->Data[j-1];
	}
	L->Last--;
	return;
}


// Find value according order
ElementType FindKth(int K,List L){
	if(K < 0 || L->Last < K){
        printf("Search value out of bound, L->Data[%d]不存在元素",K);
        return;
	}
	return L->Data[K];
}


// lenght of ArrayList
int Lenght(List L){
	return L->Last+1;
}



int main(){
	int i = 0;
	L = MakeEmpty();
	Insert(11,0,L);
	printf("Insert 11 to Array List L-Data[0]\n");
	Insert(25,0,L);
	printf("Insert 25 to Array List L-Data[1]\n");
	Insert(33,0,L);
	printf("Insert 33 to Array List L-Data[2]\n");
	Insert(77,0,L);
	printf("Insert 77 to Array List L-Data[3]\n");
	printf("Now the Array List is: ");
//	int length_L = Lenght(L);
	for(i=0;i<L->Last+1;i++){
		printf("%d ",L->Data[i]);
	}
	printf("\n");
	printf("find the index which value is 12: %d\n",Find(12,L));
	printf("find the value which index is 3: %d\n",FindKth(3,L));
	
	Delete(2,L);
	printf("Delete the value which index is 2\n");
	Delete(2,L);
	printf("Delete the value which index is 2\n");
	printf("Now the Array List is: ");
	
//	length_L = Lenght(L);
	for(i=0;i<L->Last+1;i++)
		printf("%d ",L->Data[i]);
	printf("\n");
	return 0;
}



