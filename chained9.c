#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

//we assume that the linked list is sorted. write a function , given an x integer and a T linked list, create a node containing x and insert it in the list in the right position

struct node{
    int data;
    struct node *next;
}node;

void insertInOrder(struct node *p, int n, int x){
    struct node *p1 = p;
    struct node *newNode = malloc(sizeof(struct node));
    if (newNode == NULL){
        printf("Error: Echec de l'allocation");
        exit(0);
    }
    newNode->data = x;
    while (p1->next != NULL){
        if (p1->data < x && p1->next->data > x){
            newNode->next = p1->next;
            p1->next = newNode;
            return;
        }
        p1 = p1->next;
    }
    newNode->next = NULL;
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

//ask the user for x

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
    printf("Enter x: ");
    scanf("%d", &x);
    insertInOrder(head, 3, x);
    printList(head, 3);
    free(head);
    free(second);
    free(third);
    return 0;
}