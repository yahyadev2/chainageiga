#include<stdio.h>
#include<stdlib.h>

//write a procedure that sums the elements of a linked list of size n using pointers for the loops // Ecrire une procédure qui donne la somme des éléments dans une liste
//chainée de taille n en utilisant des pointeurs pour les boucles , pas d'indicies numériques comme i ou j etc..

struct node{
    int data;
    struct node *next;
};

//use a secondary pointer to iterate through the list while P doesn't equal NULL / On utilise un deuxième pointeur pour faire nos itérations tant que P n'est pas nulle
void sumList(struct node *p, int n){
    int sum = 0;
    struct node *p1 = p;
    while (p1 != NULL){
        sum += p1->data;
        p1 = p1->next;
    }
    printf("The sum of the list is: %d", sum);
}



int main(){
    struct node *head = NULL; // Head veut dire premier , et node veut dire maillon de la chaine
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
    sumList(head, 3);
    free(head);
    free(second);
    free(third);
    return 0;
}
