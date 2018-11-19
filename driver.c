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

    
    printf (" \tI: INSERTION\n");
    printf (" \tPRE: PREORDER\n ");
    printf (" \tIN: INORDER\n");
    printf (" \tPOST: POSTORDER\n ");
    printf (" \tD: DELETE\n ");
    printf (" \tF: FREE\n");
    printf (" \tQ: QUIT PROGRAM\n");
    
    
    while (!done) {
        printf("\nEnter a command:\n >");
        scanf("%s", command);
        if (equal(command, "i")) {
            scanf("%d", &arg);              // Number to be insert
                TreeInsert(&myTree, arg);
        } else if (equal(command,"find")) {
            scanf("%d", &arg);
            TreeFind(myTree, arg)? printf("Found.\n") : printf("Not Found.\n");
        } else if (equal(command, "delete")) {
            scanf("%d", &arg);
           // if ((target = TreeFind(myTree, arg)) != NULL)
            TreeDelete(&myTree, arg);}
        else if (equal(command, "in")) {
            TreePrintInorder(myTree);
        } else if (equal(command, "pre")) {
            TreePrintPreorder(myTree);
        } else if (equal(command, "post")) {
            TreePrintPostorder(myTree);
        } else if (equal(command, "level")) {
            printLevelOrder(myTree);
        } else if (equal( command, "F" )){
                TreeFree(myTree);
                myTree = NULL;
        } else if (equal(command, "max")){
            printf("MAX = %d\n", TreeMax(myTree));
        } else if (equal(command, "min")) {
            printf("MIN = %d\n", TreeMin(myTree));
        } else if (equal(command, "average")) {
            printf("AVERAGE = %g\n", TreeAverage(myTree));
        } else if (equal(command, "height")) {
            printf("HEIGHT = %d\n", TreeHeight(myTree));
        } else if (equal(command, "count")) {
            printf("Element count = %d\n", TreeCount(myTree));
        } else if (equal(command, "sum")) {
            printf("SUM = %d\n", TreeSum(myTree));
        } else if (equal(command, "quit")) {
            TreeFree (myTree);
            myTree = NULL;
            done = 1;
        } else if (equal(command, "help")) {
            listCommands();
        } else {  //Unrecognized command
          printf("Unrecognized command. ");
           printf("Type \"help\" for a list of commands.\n");
        }
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
    printf("Commands:\n");
}
