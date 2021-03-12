#include "file1.h"
#include "file2.h"
#include "file3.h"


void hist_clients(){
    int choix; FILE *f1=NULL;

    do{
        printf("\n   \t\t\t\t\t\t      *******      Historique des clients    ******* \n\n");
        printf("     \t\t\t\t\t\t    ================================================ \n\n");

        printf("    \t\t\t\t\t\t  <1.  Afficher tous les comptes------------------------ \n");
        printf("    \t\t\t\t\t\t  <2.  Afficher les operations effectuees--------------- \n");
        printf("    \t\t\t\t\t\t  <3.  Retour au menu principal\n\n");
        printf("     \t\t\t\t\t\t     =============================================== \n\n");
        printf("\t\t\t\t\tEntrer votre choix:\t");
        scanf("%d",&choix);

           switch(choix){
                case 1: system("cls");
                        Clients(f1);
                        break;
                case 2: system("cls");
                        Operations(f1);
                        break;
                case 3: system("cls");
                        break;
                default:system("cls");
                        printf("\t\t\tvotre choix n'est pas valide !!!\n");
        }
    }while(choix!=3);
}



void Clients(FILE *f){
    char ch[100]; Client B;

    ligne('°',168);
    ligne('°',168);
    printf("\n");

    f=fopen("comptes.txt","r");
    int k=0;
    while(!feof(f)){
        fgets(ch,100,f);
        k++;
    }
    k--;
    fclose(f);
    f=fopen("comptes.txt","r");
    if(f==NULL){
        printf("Erreur!!");
        exit(-1);
    }

    printf("\n\tClients de notre banque:\n\n");
    printf("\t\t");ligne('-',71);
    int i=0;
    //fprintf(f,"  %-8s %-15s %-15s %2dans   %-14lfDH  \n",A.CIN,A.nom,A.prenom,age,A.Solde);
    printf("\n\t\t|  CIN         NOM           PRENOM          AGE       SOLDE          |\n");
    printf("\t\t");ligne('-',71);
    int age;
    while(i<k){
        //fgets(ch,100,f);
        fscanf(f,"%s %s %s %d %lf\n",B.CIN,B.nom,B.prenom,&age,&B.Solde);
        printf("\n\t\t|  %-8s %-15s %-15s %2dans   %-14lfDH  |\n",B.CIN,B.nom,B.prenom,age,B.Solde);
        //printf("\n\t\t%s",ch);
        printf("\t\t");ligne('-',71);
        i++;
    }
    fclose(f);
    retour();
    return ;
}

void Operations(FILE *f){
    char ch[100];

    ligne('°',168);
    ligne('°',168);
    printf("\n");

    f=fopen("operations.txt","r");
    int k=0;
    while(!feof(f)){
        fgets(ch,100,f);
        k++;
    }
    k--;
    fclose(f);
    f=fopen("operations.txt","r");
    if(f==NULL){
        printf("Erreur!!");
        exit(-1);
    }

    printf("\n\tLes operations effecuees sur notre banque:\n\n");
    printf("\t\t");ligne('-',96);
    int i=0;
    printf("\n\t\t|  CIN         NOM           PRENOM           ANCIEN SOLD       OPERATION       NOUVEAU SOLD   |\n");
    printf("\t\t");ligne('-',96);
    while(i<k){
        fgets(ch,100,f);
        printf("\n\t\t%s",ch);
        printf("\t\t");ligne('-',96);
        i++;
    }
    retour();
    fclose(f);
    return;
}
