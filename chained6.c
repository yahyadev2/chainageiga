#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

//write a function that returns the address of the first node containing the value x

struct node
{
    int data;
    struct node *next;
}node;

//function that returns the struct node *next of the first node containing the value x

struct node *search(struct node *head, int x)
{
    struct node *p;
    p=head;
    while(p!=NULL)
    {
        if(p->data==x)
            return p;
        p=p->next;
    }
    return NULL;
}


//use pointers
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
    //print the addresses of the nodes
    printf("head = %p\n", head);
    printf("second = %p\n", second);
    printf("third = %p\n", third);
    int x;
    printf("Enter the value of x: ");
    scanf("%d", &x);
    struct node *p;
    p=search(head, x);
    if(p!=NULL)
        printf("The address of the first node containing the value %d is %p", x, p);
    else
        printf("The value %d is not in the list", x);

        system("pause");
    return 0;
}

