#include<stdio.h>
#include<stdlib.h>

//write a function or procedure that modifies the pair values by adding 1 to them in a linked list of size n , each node contains an integer

struct node{
    int data;
    struct node *next;
}node;

void modifyList(struct node *p, int n){
    struct node *p1 = p;
    while (p1 != NULL){
        if (p1->data % 2 == 0){
            p1->data += 1;
        }
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
    modifyList(head, 3);
    printf("The modified list is: %d %d %d", head->data, second->data, third->data);
    free(head);
    free(second);
    free(third);
    return 0;
}