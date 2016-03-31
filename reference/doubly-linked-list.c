void clearList(nodePtr *front)
{
	if(!isEmpty(*front))
	{
		nodePtr tptr, lptr = *front;
		do
		{
			tptr = lptr;
			lptr = lptr->next;

			freeNode(tptr);
		}
		while(lptr != *front);

		*front = NULL;
	}
}

void removeFirst(nodePtr *front)
{
	if(!isEmpty(*front))
	{
		nodePtr last = *front;
	
		if(last->next = last)
		{
			freeNode(*front)
			*front = NULL;
		}
		else
		{
			do
				last = last->next;
			while(last->next != *front);

			*front = (*front)->next;
			freeNode(last->next);
			last->next = *front;
		}
	}
}

void append(nodePtr *front, infoType newInfo)
{
	if(isEmpty(*front))
		prepend(front, newInfo);
	else
	{
		nodePtr last = *front;
		do
			last = last->next
		while(last->next != *front);

		if((last->next = (nodePtr)malloc(sizeof(nodeType))) == NULL)
			return;
		last->next->info = newInfo;
		last->next->next = *front;
	}
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Circular doubly linked list~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void prepend(nodePtr * front, infoType newInfo)
{
	if(isEmpty(*front))
	{
		if((*front = (nodePtr)malloc(sizeof(nodeType))) == NULL)
			return;
		(*front)->info = newInfo;
		(*front)->next = (*front)->prev = *front;
	}
	else
	{
		nodePtr newNode;
		if((newNode = (nodePtr)malloc(sizeof(nodeType))) == NULL)
			return;
		newNode->info = newInfo;
		newNode->next = *front;
		newNode->prev = (*front)->prev;

		(*front)->prev = (*front)->prev->next = newNode;
		*front = newNode;
	}
}

boolean search(nodePtr front, nodePtr * lptr, infoType target);

void deleteNode(nodePtr *front, infoType target)
{
	nodePtr doomed;
	if(search(*front, &doomed, target))
	{
		if(doomed == *front)
			removeFirst(front);
		else
		{
			doomed->prev->next = doomed->next;
			doomed->next->prev = doomed->prev;
			freeNode(doomed);
		}
	}
}

