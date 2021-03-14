typedef struct TDListNode { 
  int m_nValue; 
  struct TDListNode* m_pNextNode; 
  struct TDListNode* m_pPrevNode; 
} TDListNode;


static short NodeCounter = 0;

static TDListNode* Head;
static TDListNode* Tail;
static TDListNode* KeyNode;

void StartList(TDListNode** Head);
void AddBeginning (TDListNode** Head);
void AppendEnd (TDListNode** Tail);
void AddBetween(TDListNode* Head);
void RemoveNode(TDListNode* Head);
short Menu(short Selector);
void ListPrinter(TDListNode* Head);