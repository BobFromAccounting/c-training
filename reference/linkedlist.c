#include "linkedlist.h"

void prepend(qNodePtr * front, nodePtr newinfo)
{
	qNodePtr newPtr;
	if((newPtr = (qNodePtr)malloc(sizeof(qNodeType))) == NULL)
		return;
	newPtr->info = newinfo;
	newPtr->next = *front;
	*front = newPtr;
}

void removefirst(qNodePtr * front)
{
	if(!isQEmpty(*front))
	{
		qNodePtr doomed = *front;
		*front = (*front)->next;
		freeNode(doomed);
	}
}

void append(qNodePtr * front, nodePtr newInfo)
{
	qNodePtr last = *front;
	if(last == NULL)
		prepend(front, newInfo);
	else
	{
		while(last->next != NULL)
			last = last->next;
		insertAfter(last, newInfo);
	}
}

boolean isQEmpty(const qNodePtr front)
{
	return front == NULL;
}

void freeNode(qNodePtr ptr)
{
	free(ptr);
	ptr = NULL;
}

void insertAfter(qNodePtr ptr, nodePtr newInfo)
{
	qNodePtr newNode;
	if((newNode = (qNodePtr)malloc(sizeof(qNodeType))) == NULL)
		return;
	newNode->info = newInfo;
	newNode->next = ptr->next;

	ptr->next = newNode;
}

