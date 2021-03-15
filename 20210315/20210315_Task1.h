static short NodeCounter = 0;
typedef struct stek{ 
    int m_nValue; 
    struct stek* m_pNext; 
}stek;  

/*I have decided to close the list to current file for now*/
static stek* Head;
static stek* Tail;
static stek* KeyNode;

/*In order to work on a pointer, we use double pointer and dereference it once
or we use single pointer and return it*/
void StartList(stek** Head);
void Push (stek** Head);
void Pop(stek** Head);
void ListPrinter(stek* Head);
short Menu(short Selector);