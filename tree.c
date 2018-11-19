#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

/* Define marcros for max later use in finding Height of  function */
#ifndef max
#define max(a,b) ((a) > (b) ? (a) : (b))
#endif
typedef struct NodeCDT {
    KeyT key;
    struct NodeCDT *left, *right;       // Left or right to store nodes
    int count;
} NodeCDT;

struct NodeCDT *root =NULL;

Tree TreeNew(KeyT val)
{
    NodeCDT*temp = NULL;
    temp  = (NodeCDT*)malloc(sizeof(NodeCDT));
    temp ->key = val;  // copy the value
    temp ->count = 1;  // the first root count as 1
    temp ->left = temp->right = NULL;
    return temp;
}

/* Free tree */
void TreeFree(NodeCDT *t)
{
    if ( t == NULL) return;
    TreeFree (t->left);
    TreeFree (t->right);
    free(t);
}
/* Insertion of tree */
void TreeInsert(Tree *tptr, KeyT val)
{
    NodeCDT *t = *tptr;
    if ( t == NULL){
        *tptr = TreeNew(val);
        return;
    }
    if ( t->key > val) {
         TreeInsert (&t->left, val);
          t->count++;       // increment count
    }
    if ( t->key < val){
          TreeInsert(&t->right, val);
          t->count++;       // increment count
    }
}

/* Find the element */

Node *TreeFind(NodeCDT *t, KeyT target)
{
    
    /* Base case */
    if ( t == NULL || t ->key == target) return t;
    if ( t->key > target ) return TreeFind(t->left, target);
    if ( t->key < target) return TreeFind ( t->right, target);
    else return NULL;
}

/* Deletion of the tree */
void TreeDelete(NodeCDT **t, KeyT val )
{
    NodeCDT *target,*right, *left;
    target = *t;
    
    
    /* Base case */
    if ( t == NULL ) return;
    else if ( target->key > val) return TreeDelete (&target->left, val);
    else if ( target->key < val ) return TreeDelete (&target->right, val);
    else {
        
        // case 1: No child
        if ( target-> left == NULL & target ->right == NULL){
            *t = NULL;
        }
        // case 2: One child
        if ( target ->left == NULL){
            *t = target->right;
        }
        if ( target ->right == NULL){
            *t = target ->left;
        } else{
        // case 3: 2 childs
            right = target;
            left = target ->right;
            while ( left ->left != NULL ){
                right = left;
                left = left ->left;
            }
        if ( right == target)
            right ->right = left ->right;
            else
            right ->left = left ->right;
            left ->left = target ->left;
            left ->right = target ->right;
            *t = left;
            }
    }
    free(target);       // free the node that you want to delete
}

/* Print Preorder */
void TreePrintPreorder(Tree t)
{
    if ( t == NULL) return;
    printf(" %d ", t ->key);
    TreePrintPreorder(t->left);
    TreePrintPreorder(t->right);
}
 /* Print order*/
void TreePrintInorder(NodeCDT *t)
{
    
    if ( t == NULL) return;
    TreePrintInorder (t->left);
    printf(" %d ", t->key);
    TreePrintInorder (t->right);
}

/* Print inorder */
void TreePrintPostorder(NodeCDT *t)
{
    if ( t== NULL) return;
    TreePrintPostorder ( t->left);
    TreePrintPostorder(t->right);
    printf(" %d ", t ->key);
}

/* Find the max */
KeyT TreeMax(NodeCDT *t)
{
    if ( t->right != NULL){
    return TreeMax( t->right);}
    return t->key;
}

/* find the min value */
KeyT TreeMin(NodeCDT *t)
{
    if ( t ->left != NULL){
        return TreeMin ( t->left);
    }
    return t->key;
}

double TreeAverage(NodeCDT *t)
{
    
    return TreeSum (t) / t->count;
}

int TreeHeight(NodeCDT *t)
{
    if ( t == NULL ) return 0;
    
    return 1 + max(TreeHeight (t->right), TreeHeight( t->left) );
    
}

/* Keep the counting of element inserting */
int TreeCount(NodeCDT *t)
{
    return t ->count;
}

/* Calculate the sum of the whole tree */
KeyT TreeSum(NodeCDT *t)
{
    if ( t == NULL) { return 0; }
    
return t->key + TreeSum ( t->left) + TreeSum ( t ->right);

}

/* Function to print level order traversal a tree*/
void printLevelOrder(NodeCDT *t)
{
    int h = TreeHeight(t);
    int i;
    for (i=1; i<=h; i++)
        printGivenLevel(t, i);
}
/* Print nodes at a given level */
void printGivenLevel(NodeCDT *t, int level)
{
    if (t == NULL)
    return;
    if (level == 1)
        printf("%d ", t->key);
    else if (level > 1)
{
    printGivenLevel(t->left, level-1);
    printGivenLevel(t->right, level-1);
    }
}
