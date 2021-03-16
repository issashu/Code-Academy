static short NodeCounter = 0;
typedef struct queue{ 
    int m_nValue; 
    struct queue* m_pNext; 
}queue;  

/*I have decided to close the list to current file for now*/
static queue* Head;
static queue* Tail;
static queue* KeyNode;

/*In order to work on a pointer, we use double pointer and dereference it once
or we use single pointer and return it*/
void StartList(queue** Head);
void Push (queue** Head);
void Pop(queue** Tail, queue *Head);
void ListPrinter(queue* Head);
short Menu(short Selector);