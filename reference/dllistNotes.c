void clear(nodePtr * front)
{
	if(!isEmpty(*front))
	{
		while((*front)->next != NULL)
		{
			*front = (*front)->next;
			freeNode((*front)->prev);
		}
		freeNode(*front);
		*front = NULL:
	}
}

void removeFirst(nodePtr * front)
{
	if(!isEmpty(*front))
	{
		nodePtr doomed = *front;
		*front = (*front)->next;
		if(*front != NULL)
			(*front)->prev = NULL;
		freeNode(doomed);
	}
}

void prepend(nodePtr * front, infoType newInfo)
{
	nodePtr newNode;
	if((newNode = (nodePtr)malloc(sizeof(nodetype))) == NULL)
		return;

	newNode->info = newInfo;
	newNode->next = *front;
	newNode->prev = NULL;
	
	if(!isEmpty(*front))
		(*front)->previous = newNode;
	*front = newNode;
}

void append(nodePtr *front, infoType newInfo)
{
	if(isEmpty(*front))
		prepend(front, newInfo);
	else
	{
		nodePtr last = *front;
		while(last->next != NULL)
			last = last->next;

		insertAfter(last, newInfo);
	}
}

boolean search(nodePtr front, nodePtr * lptr, infoType target)
{
	*lptr = front;
	while(*lptr != NULL)
	{
		if((*lptr)->info == target)
			return true;

		*lptr = (*lptr)->next;
	}
	
	return false;
}

void deleteNode(nodePtr * front, infoType target);
{
	nodePtr doomed;
	if(search(*front, &doomed, target))
	{
		if(doomed->prev == NULL)
			removeFirst(front)
		else 
		{
			if(doomed->next != NULL)	
				doomed->next->prev = doomed->prev;

			doomed->prev->next = doomed->next;

			freeNode(doomed);
		}
	}
}

