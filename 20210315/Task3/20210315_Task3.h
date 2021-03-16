
typedef struct Tnode{
    int NodeValue;
    struct Tnode* Left;
    struct Tnode* Right;
}Tnode;

void CreateTreeNode(Tnode** Node, int Data);
void AddNode (Tnode** Node, int Data);

static Tnode *root = NULL;
static Tnode *root2 = NULL;
static Tnode *root3 = NULL;
static Tnode *root4 = NULL;
static Tnode *root5 = NULL;
static Tnode *key;