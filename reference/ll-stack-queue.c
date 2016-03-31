typedef enum boolean {false, true}

void printList(nodePtr ptr)
{
	int n=0;
	
	while(ptr)
	{
		printf("%d) %d\n", n, ptr->info);
		ptr = ptr->next;
		n++;
	}
}

int count(nodePtr front)
{
	int numEls = 0;

	while(front)
	{
		front = front->next;
		numEls++;
	}

	return numEls;
}

void clear(nodePtr * front)
{
	nodePtr ptr;
	if(*front)
		ptr = (*front)->next;
	else
		return;
	while(ptr)
	{
		freeNode(*front);
		(*front) = ptr;
		ptr = ptr->next;
	}
	free(*front);
	*front = NULL;
}

void removefirst(nodePtr * front)
{
	if(!isEmpty(*front))
	{
		nodePtr doomed = *front;
		*front = (*front)->next;
		freeNode(doomed);
	}
}

void prepend(nodePtr * front, infoType newinfo)
{
	nodePtr newPtr;
	if((newPtr = (nodePtr)malloc(sizeof(nodeType))) == NULL)
		return;
	newPtr->info = newinfo;
	newPtr->next = *front;
	*front = newPtr;
}

void push(nodePtr * front, infoType newInfo)
{
	nodePtr newNode;
	
	if((newNode = (nodePtr)malloc(sizeof(nodeType))) == NULL)
		return;
		
	newNode->info = newInfo;
	newNode->next = *front;
	
	*front = newNode;
}

infoType pop(nodePtr * front)
{
	infoType = savedInfo;
	nodePtr doomed = *front;
	
	if(isEmpty(*front))
		return EMPTY;
	
	savedInfo = (*front)->info;
	*front = (*front)->next;
	
	freeNode(doomed);
	return savedInfo;
}

void enque(nodePtr *front, nodePtr *rear, infoType NewInfo)
{
	nodePtr newNode;
	if((newNode = (nodePtr)malloc(sizeof(nodeType))) == NULL)
		return;
	
	newNode->info = NewInfo;
	newNode->next = NULL;

	if(isEmpty(*front, *rear))
		*front = *rear = newNode;
	else
	{
		(*rear)->next = newNode;
		*rear = newNode;
	}
}

infoType deque(nodePtr *front, nodePtr *rear)
{
	if(!isEmpty(*front, *rear))
	{
		nodePtr doomed = *front;
		infoType tbr = doomed->info; // TBR = To Be Returned
		*front = (*front)->next;
		if(*rear == doomed)
			*rear = NULL;
		
		freeNode(doomed);
		return tbr;
	}
	else
		return EMPTY;
}

