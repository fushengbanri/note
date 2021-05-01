#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXSIZE 20

typedef int ElemType;


//linear table
typedef struct{
	ElemType date[MAXSIZE];
	int length;
}sqlist;

// linked list
typedef struct Node{
	ElemType date[MAXSIZE];
	struct Node *next;
}Node;

typedef struct Node *LinkList;


