#include "file1.h"

int main(){
    int a;

    system("color F1");
    do{
        printf("\n   \t\t\t\t\t\t      *******      Gestion d'une banque    ******* \n\n");
        printf("     \t\t\t\t\t\t    ================================================ \n\n");
        printf(" \t\t\t\t\t\t\t <1. GESTION DES COMPTES-----------------\n\n");
        printf(" \t\t\t\t\t\t\t <2. SERVICES----------------------------\n\n");
        printf(" \t\t\t\t\t\t\t <3. HISTORIQUE DES CLIENTS--------------\n\n");
        printf(" \t\t\t\t\t\t\t <4. QUITTER-----------------------------\n\n");
        printf("     \t\t\t\t\t\t    ================================================ \n\n");
        printf("\n\t\t\t\t\t\tEntrer votre choix:\t");
        scanf("%d",&a);
        switch(a){
            case 1:
                system("cls");
                ges_comptes();
                break;
            case 2:
                system("cls");
                services();
                break;
            case 3:
                system("cls");
                hist_clients();
                break;
            case 4:
                system("cls");
                quitter();
                break;
            default:
                system("cls");
                printf("\t\t\tvotre choix n'est pas valide !!!\n");
        }
    }while(a!=4);
    return 0;
}

