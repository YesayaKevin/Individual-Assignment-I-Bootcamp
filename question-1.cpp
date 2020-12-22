// NOTE: I TOOK FROM GEEKSFORGEEKS BUT I REVIEW IT FIRST
#include <stdio.h>
#include <stdlib.h>

struct Node { //Node Data
    int data; // Node value
    struct Node* next; // Node pointer
};

struct Node* SortedMerge(struct Node* a, struct Node* b);
void push(struct Node** head_ref, int new_data); //push head only
void printList(struct Node *node);

int main(){
	// initialize all struct to Null
    struct Node* res = NULL; 
    struct Node* a = NULL; 
    struct Node* b = NULL; 
	// fill the linked list by push head
    push(&a, 15); 
    push(&a, 10); 
    push(&a, 5); 
    push(&b, 20); 
    push(&b, 3); 
    push(&b, 2); 
    // Merge linked list a and b
    res = SortedMerge(a, b); 
    printf("Merged Linked List is:\n"); 
    printList(res);
    return 0; 
}

struct Node* SortedMerge(struct Node* a, struct Node* b){
    // initialize result to null
	struct Node* result = NULL;
    
    // Base cases
    if (a == NULL)  
        return(b); 
    else if (b==NULL)  
        return(a); 
    
    // check the data to sort by ascending
    // if a is lower then b so put a at left side
    // a1 = 1, b1 = 2, b2 = 3, a3 = 4
   	// res = NULL
   	// a1 -> NULL
   	// a1 -> b1 -> NULL
   	// a1 -> b1 -> b2 -> NULL
   	// a1 -> b1 -> b2 -> a3 -> NULL
    if (a->data <= b->data) { 
        result = a; 
        result->next = SortedMerge(a->next, b); 
    } else { 
        result = b; 
        result->next = SortedMerge(a, b->next); 
    } 
    return(result); 
}

void printList(struct Node *node) { 
	// function for print node
    while (node!=NULL) 
    { 
        printf("%d ", node->data); 
        node = node->next; 
    } 
}

// function pushHead
void push(Node** head_ref, int new_data) {
	// declare new_node with memory size of Node
    Node* new_node = (Node*) malloc(sizeof(Node)); 
    new_node->data  = new_data; 
    // link the old list off the new node
    new_node->next = (*head_ref); 
    // move the head to point to the new node
    (*head_ref)    = new_node; 
}
