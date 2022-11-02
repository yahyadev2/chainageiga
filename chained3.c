#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>


struct node{
    int data;
    struct node *next;
}node;

//write a function that checks if the element inside of the node is divisible by 1 or itself
//if it is , count++

int isPrime(struct node *p, int n){
    int count = 0;
    struct node *p1 = p;
    while (p1 != NULL){
        int i;
        int isPrime = 1;
        for (i = 2; i < p1->data; i++){
            if (p1->data % i == 0){
                isPrime = 0;
                break;
            }
        }
        if (isPrime == 1){
            count++;
        }
        p1 = p1->next;
    }
    return count;
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
    printf("The number of prime numbers in the list is: %d", isPrime(head, 3));
    free(head);
    free(second);
    free(third);
    return 0;
}
