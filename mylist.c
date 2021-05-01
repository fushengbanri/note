#include"./lib/mylist.h"


void InitList(sqlist *L);
void ListEmpty(L);
void ClearList(sqlist *L);
void GetElem(sqlist L, int i, ElemType *e);
void LocateElem(L, e);
int ListInsert(sqlist *L,int i,ElemType e);
int ListDelete(sqlist *L,int i,ElemType *e);
int ListLength(sqlist L);
void unionL(sqlist *La, sqlist Lb);


void InitList(sqlist *L)
{
	/*
	 * funcion : initialization list
	 * sqlist *L : List to bu processed
	 */
	L->date = (ElemType *)malloc(MAXSIZE*sizeof(ElemType));
	if(!L->date){
		printf("creat init failue!\n");
		exit(EXIT_FAILURE);
	}
	L->length = 0;
	return 0;
}

int ListDelete(sqlist *L, int i, ElemType *e)
{
	/*
	 * function : Delete an element
	 * mylist *L : The delete list
	 * int i : Delete i date
	 * ElemType *e : Delete date return
	 */
	int k;
	if(L->length == 0 || L->length < i-1 || i < 1)
		exit(EXIT_FAILURE);
	*e = L->date[i-1];
	if(i < L->length){
		for(k=i;k < L->length; K++)
			L->date[k-1] = L->date[k];
	}
	L->length--;
	return 0;
}

int ListInsert(sqlist *L, int i, ElemType e)
{
	/*
	 * mylist *L : To be insert list
	 * int i : where insert
	 * ElemType : insert date
	 */
	int k;
	if(L->length == MAXSIZE || i < 1 || i > L->length+1)
		return -1;
	if(i <= L->length){
		for(k=L->length-1; k >= i-1, k--)
			L->date[k-1] = L->date[k];
	}
	L->date[i-1] = e;
	L->length++;
	return 0;
}

int ListLength(sqlist L)
{
	/*
	 * function : return the list length
	 * sqliset L: 
	 */
	return L.length;
}

void unionL(sqlist *La, sqlist Lb)
{
	/*
	 * funcion : 
	 */
	int La_len,Lb_len,i;

	ElemType e;

	La_len = ListLength(*La);
	Lb_len = ListLength(Lb);
	for(i=1; i<=Lb_len, i++){
		GetElem(Lb,i,&e);
		if( !LocateElem(*La,e) )
			ListInsert(*La,++La_len, e);
	}
}
