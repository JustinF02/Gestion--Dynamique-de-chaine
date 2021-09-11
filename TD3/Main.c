#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int taille;
void saisie(char* ptab) {
    int i;
    char car;
    printf("\nSaisir une chaine :");
    i = 0;
    do {
        car = getchar();
        ptab[i] = car;
        i++;

    } while (car != '\n');

    ptab[i - 1] = '\0';
}

char* saisie2() {
    char* t2, * t3;
    //char t3[1000]; Grave erreur de vouloir retourner ce tableau en statique en résultat
    int nbdecar, nbdecases;

    //printf("Saisir une chaine\n");
    t2 = (char*)malloc(1000 * sizeof(char));
    saisie(t2);

    //redimensionnement de t2
    nbdecar = strlen(t2);
    nbdecases = nbdecar + 1;
    t3 = (char*)malloc(nbdecases * sizeof(char));

    strcpy(t3, t2);
    free(t2);
    return t3;
}

char* saisie3() {
    int i, nbcases;
    char car, * anc, * nouv;
    printf("Saisir une chaine\n");

    nbcases = 1;
    anc = NULL;
    do {
        car = getchar();
        nouv = (char*)malloc(nbcases * sizeof(char));
        for (i = 0; i <= nbcases - 2; i++) {
            nouv[i] = anc[i];
        }
        nouv[i] = car;
        if (anc != NULL) {
            //copie chaine contenue dans anc dans nouveau tableau chain

            free(anc);

        }
        anc = nouv; //On référence nouv avec anc
        nbcases++;
    } while (car != '\n');
    nouv[i] = '\0';

    return nouv;

}
char* f(char* tab) {
    char* nouv;
    int i;
    //retirer deux cases au tableau
    taille = strlen(tab) - 2 + 1;
    nouv = (char*)malloc(taille * sizeof(char));
    for (i = 0; i < taille; i++) {
        nouv[i] = tab[i];
    }
    nouv[i - 1] = '\0';
    free(tab);

    return nouv;
}
char* suppression(char* tab, char car) {
    char* nouv;
    int taille, i, j = 0, cpt = 0;
    for (i = 0; tab[i] != '\0'; i++) {
        if (tab[i] == car)cpt++;
    }
    taille = strlen(tab) + 1 - cpt;
    nouv = (char*)malloc(taille * sizeof(char));
    for (i = 0; tab[i] != '\0'; i++) {
        if (car != tab[i]) nouv[j++] = tab[i];
    }
    nouv[j] = '\0';
    free(tab);
    return nouv;
}
char* double1(char* tab, char car) {
    char* nouv;
    int taille, i, j = 0, cpt = 0;
    for (i = 0; tab[i] != '\0'; i++) {
        if (tab[i] == car) cpt++;
    }
    taille = strlen(tab) + 1 + cpt;
    nouv = (char*)malloc(taille * sizeof(char));
    for (i = 0, j = 0; tab[i] != '\0'; i++) {
        nouv[j++] = tab[i];
        if (tab[i] == car) nouv[j++] = tab[i];
    }

    nouv[j] = '\0';
    free(tab);
    return nouv;
}

char* doubletout(char* tab) {
    char* nouv;
    int taille, i, j = 0, cpt = 0;

    taille = strlen(tab) * 2;
    nouv = (char*)malloc(taille * sizeof(char));
    for (i = 0, j = 0; tab[i] != '\0'; i++) {
        nouv[j++] = tab[i];
        nouv[j++] = tab[i];
    }

    nouv[j] = '\0';
    free(tab);
    return nouv;
}

int main()
{
    //char t1[200];
    char* t2, * t3;
    char* res;
    int nbdecars, nbdecases;
    t3 = saisie3();
    printf("chaine t3 : %s\n", t3);
    t3 = suppression(t3, 'o');
    printf("chaine t3 : %s\n", t3);
    t3 = double1(t3, 'b');
    printf("chaine t3 dédoublee : %s\n", t3);
    t3 = doubletout(t3);
    printf("chaine t3 doubletout : %s\n", t3);
    return 0;
}