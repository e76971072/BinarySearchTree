

#ifndef _tree_h
#define _tree_h


typedef struct NodeCDT Node;
typedef Node *Tree;
typedef int KeyT;
Tree TreeNew();
void TreeFree(Tree t);
void TreeInsert (Tree *t, KeyT val);
struct NodeCDT *TreeFind(Tree t, KeyT target);
void TreeDelete(Tree *t, KeyT target);
void TreePrintPreorder(Tree t);
void TreePrintInorder(Tree t);
void TreePrintPostorder(Tree t);
void TreePrintLevelorder(Tree t);
KeyT  TreeMax(Tree t);
KeyT TreeMin(Tree t);
double TreeAverage(Tree t);
int TreeHeight(Tree t);
int TreeCount(Tree t);
KeyT TreeSum(Tree t);
void printLevelOrder(Tree t);
void printGivenLevel(Tree t, int level);


#endif 
