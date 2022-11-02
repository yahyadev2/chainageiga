#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

//write two functions or procedures , when given an x integer and a T linked list, create a node containing x and insert it after the first node and in the end of the list

struct node{
    int data;
    struct node *next;
}node;

void insertAfterFirst(struct node *p, int n, int x){
    struct node *p1 = p;
    struct node *newNode = malloc(sizeof(struct node));
    if (newNode == NULL){
        printf("Error: Echec de l'allocation");
        exit(0);
    }
    newNode->data = x;
    newNode->next = p1->next;
    p1->next = newNode;
}

void insertAtEnd(struct node *p, int n, int x){
    struct node *p1 = p;
    struct node *newNode = malloc(sizeof(struct node));
    if (newNode == NULL){
        printf("Error: Echec de l'allocation");
        exit(0);
    }
    newNode->data = x;
    newNode->next = NULL;
    while (p1->next != NULL){
        p1 = p1->next;
    }
    p1->next = newNode;
}

//write a function that prints the linked list with the new nodes

void printList(struct node *p, int n){
    struct node *p1 = p;
    while (p1 != NULL){
        printf("%d ", p1->data);
        p1 = p1->next;
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
    int x;
    printf("Enter the value of x: ");
    scanf("%d", &x);
    insertAfterFirst(head, 3, x);
    insertAtEnd(head, 3, x);
    printList(head, 3);
    free(head);
    free(second);
    free(third);
    return 0;
}