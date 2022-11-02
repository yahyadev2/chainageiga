#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

//write  a function or procedure that checks if a given integer exists in a linked list

struct node{
    int data;
    struct node *next;
}node;

int isPresent(struct node *p, int n, int x){
    struct node *p1 = p;
    while (p1 != NULL){
        if (p1->data == x){
            return 1;
        }
        p1 = p1->next;
    }
    return 0;
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
    if (isPresent(head, 3, x) == 1){
        printf("The value of x is present in the list");
    }
    else{
        printf("The value of x is not present in the list");
    }
    free(head);
    free(second);
    free(third);
    return 0;
}