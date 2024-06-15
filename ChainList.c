#include<stdio.h>
#include<malloc.h>

typedef int ElementType; // ElementType, can be defined any types
typedef struct LNode *List;
struct LNode{
	ElementType Data;   // Data Area
	List Next;   // next address of ChainList
};

List L;

List MakeEmpty(); // initial ChainList
int Length(List L);
List FindKth(int K, List L);
List Find(ElementType X, List L);
List Insert(ElementType X, int i, List L);
List Delete(int i, List L); 
void Print(List L);


List MakeEmpty(){
	List L = (List)malloc(sizeof(struct LNode));
	L = NULL;
//	printf("==>Pass\n");
	return L;
}


int Length(List L){
	List p = L;
	int len = 0;
	while (p){
		p = p->Next;
		len ++;
	}
	return len;
}


List Find(ElementType X,List L){
	List p = L;
	while(p && p->Data != X){
		p = p->Next;
	}
	return p;
}



List FindKth(int K,List L){
	List p = L;
	int i = 1;
	while(p && i<K){
		p = p->Next;
		i++;
	}
	return (i == K) ? p: NULL;
}


void Print(List L){
	List t;
	int flag = 1;
	printf("Current ChainList is: ");
	for(t=L; t; t=t->Next){
		printf("%d\t", t->Data);
		flag = 0;
	}
	if(flag){
		printf("NULL");
	}
	printf("\n");
}

// Must connect new node before inconnect last node
List Insert(ElementType X, int i, List L){
	List p, s;
	if (i == 1){
		s = (List)malloc(sizeof(struct LNode));
		s->Data = X;
		s->Next = L;
		return s;
	}
	p = FindKth(i-1, L);
	if(p == NULL){
		printf("Parameter i is wrong!");
		return NULL;
	}
	else{
		s = (List)malloc(sizeof(struct LNode));
		s->Data = X;
		s->Next = p->Next;
		p->Next = s;
		return L;
	}
}


// Must connect new node before delete last node
List Delete(int i,List L){
	List p, s;
	if (i == 1){
		s = L;
		if(L != NULL){
			L = L->Next;
		}
		else{
			return NULL;
		}
		free(s);
		return L;
	}
	p = FindKth(i-1, L);
	if(p == NULL){
		printf("the %d node does not exists!", i-1);
		return NULL;
	}
	else if(p->Next == NULL){
		printf("the %d node does not exists!", i);
		return NULL;
	}
	else{
		s = p->Next;
		p->Next = s->Next;
		free(s);
		return L;
	}
	
}


int main(){
	L = MakeEmpty();
	Print(L);
	L = Insert(11,1,L);
	L = Insert(25,1,L);
	L = Insert(33,2,L);
	L = Insert(77,3,L);
	Print(L);
	printf("Current ChainList length is: %d\n",Length(L));
	printf("The second node value is: %d\n", FindKth(2, L)->Data);
	printf("Is 22 in the ChainList: ");
	if(Find(22,L))
		printf("Yes!\n");
	else
		printf("No!\n");
	printf("Is 33 in the ChainList: ");
	if(Find(33,L))
		printf("Yes!\n");
	else
		printf("No!\n");
	L = Delete(1,L);
	L = Delete(3,L);
	printf("--------After Delete-----\n"); 
	Print(L);
	return 0;
}
