#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>



//creation de la structeur d'element de la lsite
typedef struct element element;

struct element {
    int valeur;
    element *suivant;
};

typedef element* liste;
int count=0;
liste start= NULL;


//procedeur ansertion au debut
void insret_at_begin(int x){
    liste t;
    t=(element*)malloc(sizeof(element));
    count++;

    if (start == NULL ){
        start=t;
        start->valeur=x;
        start->suivant=NULL;
        return;
    }
    t->valeur=x;
    t->suivant=start;
    start=t;
}


//procedeur insertion a la fin
void insert_at_end(int x){
    liste t,temp;
    t=(element*)malloc(sizeof(element));
    count++;

    if (start == NULL){
        start=t;
        start->valeur=x;
        start->suivant=NULL;
        return;
    }
    temp=start;
    while (temp->suivant != NULL){
        temp=temp->suivant;
    }
    temp->suivant=t;
    t->valeur=x;
    t->suivant=NULL;
}


//parcours de la liste
void travers(){
    liste t;
    t=start;

    if(t == NULL){
        printf("la liste est vide\n");
        return;
    }
    printf("la liste contient %d elemets\n",count);

    while (t->suivant != NULL){
        printf("%d\n",t->valeur);
        t=t->suivant;
    }
    printf("%d\n",t->valeur);
}


//procedeur supprimer la tete de la liste
void delete_from_begin(){
    liste t;
    int n;

    if (start == NULL){
        printf("la liste est deja vide\n");
        return;
    }

    n=start->valeur;
    t=start->suivant;
    free(start);
    start=t;
    printf("%d a ete supprimer\n",n);
    count--;
}


//procedeur supprimer la queue de la liste
void delete_from_end(){
    liste u,t;
    int n;

    if(start == NULL){
        printf("la liste est deja vide\n");
        return;
    }
    count--;

    if(start->suivant == NULL){
        n=start->valeur;
        free(start);
        start= NULL;
        printf("%d a ete supprimer\n",n);
        return;
    }

    t=start;
    while(t->suivant != NULL){
        u=t;
        t=t->suivant;
    }
    //u pointe sur l'avant dernier element
    //t pointe sur le dernier element
    n=t->valeur;
    u->suivant=NULL;
    free(t);
    printf("%d a ete supprimer\n",n);
    return ;
}


int main(){

    int choix,hocine,realmadrid;
    char reponse;

    do{
    printf("\n- Choice your programme:\n -Add to begin = 1\n -Add to end = 2\n -Display = 3 \n -Delete from begin = 4\n -Delete from end= 5\n -Stop every thing = 6\n");
    scanf("%d",&choix);
    switch (choix){

        case 1 :
            printf("entrez la valeur a insere : ");
            scanf("%d",&hocine);
            insret_at_begin(hocine);
        break;


        case 2 :
            printf("entrez la valeur a insere : ");
            scanf("%d",&hocine);
            insert_at_end(hocine);
        break;


        case 3 :
            travers(hocine);
        break;


        case 4 :
            delete_from_begin(hocine);
        break;


        case 5 :
            delete_from_end(hocine);
        break;


        case 6 :
            realmadrid=14;
        break;


        default :
            printf("choix faux\n");
        break;
    }
    }while(realmadrid != 14);

    return 0;
}
