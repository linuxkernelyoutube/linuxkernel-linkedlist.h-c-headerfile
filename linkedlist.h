#include<stdlib.h>
#include<stdio.h>

typedef struct linked_list {
    int data;
    struct linked_list *link;
} Node;

typedef Node* list;


//Declarations
Node *create_node(int value);
int is_empty(Node*);
void add_first(int value, Node**);
void add_last(int value, Node**);
int index_of(int, Node*);
int contains(int, Node*);
int remove_first(Node**);
int remove_last(Node**);


//PASS
Node *create_node(int value) {

    Node *new_node = (Node*)(malloc(sizeof(Node)));

    new_node->data = value;
    new_node->link = NULL;

    return new_node;
}


//PASS
//READ-ONLY
int is_empty(Node *header) {
    return (header == NULL);
}



//PASS
//READ/WRITE
void add_first(int value, Node **header) {

    Node *new_node = create_node(value);

    if (is_empty(*header)) {
        *header = new_node;
        return;
    }

    new_node->link = *header;
    *header = new_node;

}



Node *get_last(Node **header) {
    Node *current = *header;

    while (current != NULL) {
        if (current->link == NULL) return current;
        current = current->link;
    }
}


//READ/WRITE
void add_last(int value, Node **header) {

    Node *new_node = create_node(value);

    if (is_empty(*header)) {
        *header = new_node;
        return;
    }

    Node *last = get_last(header);

    last->link = new_node;

}

//READ-ONLY
// zero indexed.
int index_of(int value, Node *header) {
    int index = 0;

    Node *current = header;

    while (current != NULL) {
        if (current->data == value) return index;
        current = current->link;
        index++;
    }
    return -1;

}

//READ-ONLY
int contains(int value, Node *header) {
    Node *current = header;

    while (current != NULL) {
        if (current->data == value) return 1;
        current = current->link;
    }
    return 0;
}



//READ/WRITE
int remove_first(Node **header) {

    Node *target = *header;
    int data;

    if (is_empty(*header)) {
        return -9999;
    }

    data = target->data;

    // contains one element
    if ((*header)->link == NULL) {
        *header = NULL;
        free(target);
        return (data);
    }


    *header = (*header)->link;
    free(target);
    return data;

}



//READ/WRITE
int remove_last(Node **header) {
    Node *target = *header;
    Node *previous = *header; //second last node

    int data;

    if (is_empty(*header)) {
        return -9999; //later return NULL
    }

    data = target->data;

    if ((*header)->link == NULL) {
        *header = NULL;
        free(target);
        return data;
    }

    while (previous->link->link != NULL)
        previous = previous->link;

    target = previous->link; //last node

    data = target->data;

    free(target);

    previous->link = NULL; //making this the last node

    return data;

}



//READ-ONLY
void print_list(Node *header) {

    Node *current = header;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->link;
    }
    printf("\n");
}