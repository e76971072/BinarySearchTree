#include "tree.h"
#include <stdio.h>
#include <string.h>

int equal(char *a, char *b);
void listCommands();

int main()
{
    char command[100];
    int arg, done;

    Tree myTree;
    done = 0;
    myTree = NULL;

    
    printf (" \n\ti: INSERTION\n");
    printf (" \tpre: PREORDER\n ");
    printf (" \tin: INORDER\n");
    printf (" \th: HEIGHT\n " );
    printf (" \tfind: FIND A NODE IN BST\n");
    printf (" \tpost: POSTORDER\n ");
    printf (" \td: DELETE\n ");
    printf (" \tf: FREE\n");
    printf (" \tc: COUNT ELEMENT IN  BST\n" );
    printf ("\tmin: MINIMUM VALUE\n");
    printf ("\tmax: MAXIMUM VALUE\n");
    printf ("\ta: AVERAGE OF BST\n");
    printf ("\ts: SUM OF BST\n");
    printf ("\tprint: Print a whole BST\n" );
    printf (" \tq: QUIT PROGRAM\n");
    
    
    while (!done) {
        printf("\nEnter a command:\n >");
        scanf("%s", command);
        if (equal(command, "i")) {
            scanf("%d", &arg); // Number to be insert
            if ( arg < 0 ){
                printf (" Binary Tree only inserting positive interger\n" );
            }
            else
             TreeInsert(&myTree, arg);
        } else if (equal(command,"find")) {
            scanf("%d", &arg);
            printf ("The path of Searching: root");
            TreeFind(myTree, arg)? printf("\nIt's Found.\n") : printf("\nIt's Not Found.\n");
        } else if (equal(command, "d")) {
            scanf("%d", &arg);
           // if ((target = TreeFind(myTree, arg)) != NULL)
            TreeDelete(&myTree, arg);}
        else if (equal(command, "in")) {
            TreePrintInorder(myTree);
        } else if (equal(command, "pre")) {
            TreePrintPreorder(myTree);
        } else if (equal(command, "post")) {
            TreePrintPostorder(myTree);
        } else if (equal(command, "l")) {
            printLevelOrder(myTree);
        } else if (equal( command, "f" )){
                TreeFree(myTree);
                myTree = NULL;
            printf (" BST is freed\n " ); 
        } else if (equal(command, "max")){
            printf("MAX = %d\n", TreeMax(myTree));
        } else if (equal(command, "min")) {
            printf("MIN = %d\n", TreeMin(myTree));
        } else if (equal(command, "a")) {
            printf("AVERAGE = %.2lf\n", TreeAverage(myTree));
        } else if (equal(command, "h")) {
            printf("HEIGHT = %d\n", TreeHeight(myTree));
        } else if (equal(command, "c")) {
            printf("Element count = %d\n", TreeCount(myTree));
        } else if (equal(command, "s")) {
            printf("SUM = %d\n", TreeSum(myTree));
        } else if ( equal( command,"print" )){
            int level = TreeHeight(myTree);
            structure( myTree, level);
        }else if (equal(command, "q")) {
            TreeFree (myTree);
            myTree = NULL;
            done = 1;
        } else if (equal(command, "help")) {
            listCommands();
        } else {  //Unrecognized command
          printf("Unrecognized command. ");
           printf("Type \"help\" for a list of commands.\n");
        }
         printf ("\n\nEnter {help} if you want list of commands\n\n " );
    }
}

int equal (char *a, char *b)
{
    if (strcmp(a, b) == 0)
        return 1;
    return 0;
}
void listCommands()
{
    printf("\t\tCommands:\n");
    
    printf (" \ti: INSERTION\n");
    printf (" \tpre: PREORDER\n ");
    printf (" \tin: INORDER\n");
    printf (" \th: HEIGHT\n " );
    printf (" \tfind: FIND A NODE IN BST\n");
    printf (" \tp: POSTORDER\n ");
    printf (" \td: DELETE\n ");
    printf (" \tf: FREE\n");
    printf (" \tc: COUNT ELEMENT IN  BST\n" );
    printf ("\tmin: MINIMUM VALUE\n");
    printf ("\tmax: MAXIMUM VALUE\n");
    printf ("\ts: SUM OF BST\n");
    printf ("\ta: AVERAGE OF BST\n");
    printf (" \tq: QUIT PROGRAM\n");
    
}
