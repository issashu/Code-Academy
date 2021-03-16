typedef struct Tnode{
    int NodeValue;
    struct Tnode* Left;
    struct Tnode* Right;
}Tnode;

void CreateTreeNode(Tnode** Node, int Data);
void SearchNode(Tnode* key, int Data);
void AddNode (Tnode** Node, int Data);

static Tnode *root = NULL;
static Tnode *key;