#include<stdio.h>
#include<stdlib.h>

//write a function or procedure that counts the number of prime numbers in a linked list of size n using pointers for the loops

struct node{
    int data;
    struct node *next;
};

//using a secondary pointer instead of numerical indices to iterate through the list
//use another secondary pointer to iterate through the list to check if the current node is prime
void countPrimes(struct node *p, int n){
    int count = 0;
    struct node *p1 = p;
    while (p1 != NULL){
        int i = 2;
        int isPrime = 1;
        while (i < p1->data){
            if (p1->data % i == 0){
                isPrime = 0;
                break;
            }
            i++;
        }
        if (isPrime == 1){
            count++;
        }
        p1 = p1->next;
    }
    printf("The number of prime numbers in the list is: %d", count);
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
    countPrimes(head, 3);
    free(head);
    free(second);
    free(third);
    return 0;
}
