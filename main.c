#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

// Structure definition for a linked list element
typedef struct element element;

struct element {
    int valeur;
    element *suivant;
};

// Type definition for a linked list
typedef element* liste;

// Global variables for count and the start of the linked list
int count = 0;
liste start = NULL;

// Procedure for inserting at the beginning of the linked list
void insret_at_begin(int x) {
    liste t;
    t = (element*)malloc(sizeof(element));
    count++;

    if (start == NULL) {
        // If the list is empty, create the first element
        start = t;
        start->valeur = x;
        start->suivant = NULL;
        return;
    }

    // Insert at the beginning
    t->valeur = x;
    t->suivant = start;
    start = t;
}

// Procedure for inserting at the end of the linked list
void insert_at_end(int x) {
    liste t, temp;
    t = (element*)malloc(sizeof(element));
    count++;

    if (start == NULL) {
        // If the list is empty, create the first element
        start = t;
        start->valeur = x;
        start->suivant = NULL;
        return;
    }

    // Traverse to the end and insert the new element
    temp = start;
    while (temp->suivant != NULL) {
        temp = temp->suivant;
    }
    temp->suivant = t;
    t->valeur = x;
    t->suivant = NULL;
}

// Procedure for traversing and displaying the linked list
void travers() {
    liste t;
    t = start;

    if (t == NULL) {
        printf("la liste est vide\n");
        return;
    }

    printf("la liste contient %d elemets\n", count);

    while (t->suivant != NULL) {
        printf("%d\n", t->valeur);
        t = t->suivant;
    }

    printf("%d\n", t->valeur);
}

// Procedure for deleting from the beginning of the linked list
void delete_from_begin() {
    liste t;
    int n;

    if (start == NULL) {
        printf("la liste est deja vide\n");
        return;
    }

    n = start->valeur;
    t = start->suivant;
    free(start);
    start = t;
    printf("%d a ete supprimer\n", n);
    count--;
}

// Procedure for deleting from the end of the linked list
void delete_from_end() {
    liste u, t;
    int n;

    if (start == NULL) {
        printf("la liste est deja vide\n");
        return;
    }
    count--;

    if (start->suivant == NULL) {
        // If there is only one element in the list
        n = start->valeur;
        free(start);
        start = NULL;
        printf("%d a ete supprimer\n", n);
        return;
    }

    t = start;
    while (t->suivant != NULL) {
        u = t;
        t = t->suivant;
    }

    // u points to the second-to-last element
    // t points to the last element
    n = t->valeur;
    u->suivant = NULL;
    free(t);
    printf("%d a ete supprimer\n", n);
    return;
}

// Main function
int main() {
    int choix, hocine, realmadrid;

    // Menu loop
    do {
        printf("\n- Choice your programme:\n -Add to begin = 1\n -Add to end = 2\n -Display = 3 \n -Delete from begin = 4\n -Delete from end= 5\n -Stop every thing = 6\n");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("entrez la valeur a insere : ");
                scanf("%d", &hocine);
                insret_at_begin(hocine);
                break;

            case 2:
                printf("entrez la valeur a insere : ");
                scanf("%d", &hocine);
                insert_at_end(hocine);
                break;

            case 3:
                travers();
                break;

            case 4:
                delete_from_begin();
                break;

            case 5:
                delete_from_end();
                break;

            case 6:
                realmadrid = 14;
                break;

            default:
                printf("choix faux\n");
                break;
        }
    } while (realmadrid != 14);

    return 0;
}
