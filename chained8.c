#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

//write a function , given an integer x and a linked list T, search for the first node containing x and delete it from the list , if that node does not exist, print a message

struct node{
    int data;
    struct node *next;
}node;

void deleteNode(struct node *p, int n, int x){
    struct node *p1 = p;
    struct node *p2 = p;
    while (p1 != NULL){
        if (p1->data == x){
            p2->next = p1->next;
            free(p1);
            return;
        }
        p2 = p1;
        p1 = p1->next;
    }
    printf("The value of x is not present in the list");
}

//procedure to print the new linked list

void printList(struct node *p, int n){
    struct node *p1 = p;
    while (p1 != NULL){
        printf("%d ", p1->data);
        p1 = p1->next;
    }
}

//ask the user to input the x value in the main function

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
    deleteNode(head, 3, x);
    printList(head, 3);
    free(head);
    free(second);
    free(third);
    return 0;
}