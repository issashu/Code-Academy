static short NodeCounter = 0;
typedef struct stack_t{ 
    int m_nValue; 
    struct stack_t* m_pNext; 
}stack_t;  

/*I have decided to close the list to current file for now*/
static stack_t* Head;
static stack_t* Tail;
static stack_t* KeyNode;

/*In order to work on a pointer, we use double pointer and dereference it once
or we use single pointer and return it*/
void StartList(stack_t** Head);
void Push (stack_t** Head);
void Pop(stack_t** Head);
void ListPrinter(stack_t* Head);
short Menu(short Selector);