#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/****************************Struct declarations*************************************/
//It's generally good to put all your structures at the beginning of a single file.

typedef /*YOUR STRUCTURE*/ Node; 

typedef /*YOUR STRUCTURE*/ LinkedList; 


/*******************************LinkedList & functions******************************/
void list_init(LinkedList* l)
{
    // TODO: initialize the list `l`, set the head and tail to NULL, and size to 0.
    // YOUR CODE HERE
}


void list_insert(LinkedList* l, int value)
{
    // TODO: insert a node that contains `value` into the list `l` immediately after 
    //       the last node (which tail points to).
    // YOUR CODE HERE
}

void list_clear(LinkedList* l)
{
    // TODO: Clear the whole list, set head, tail and size to the initial state.
    // YOUR CODE HERE
}

Node* list_remove(LinkedList* l, Node* target)
{
    // TODO: remove the `target` node, and return the node immediately after it.
    // YOUR CODE HERE
}


/*****************************Your Main Function*************************************/
// DO NOT submit main function to OJ, or compile error may happen!
int main()
{
    // Add your own test cases here, but DONOT submit it to OJ.
    return 0;
}
