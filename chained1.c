#include<stdio.h>
#include<stdlib.h>

//create a linked list made of 3 nodes , each node contains an integer
//write a function that prints the list using pointers

struct node{
    int data;
    struct node *next;
}node;

void printList(struct node *p){
    while (p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }
}

int main(){
    struct node *head = NULL;
    struct node *second = NULL;
    struct node *third = NULL;
    head = malloc(sizeof(struct node));
    second = malloc(sizeof(struct node));
    third = malloc(sizeof(struct node));
    if (head == NULL || second == NULL || third == NULL){
        printf("Error: Echec de l'allocation");
        exit(0);
    }
    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = NULL;
    printList(head);
    free(head);
    free(second);
    free(third);
    return 0;
}
