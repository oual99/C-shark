#include "file1.h"
#include "file2.h"
#include "file3.h"




void services(){
    int choix; FILE *f1=NULL;

    do{
        printf("\n   \t\t\t\t\t\t\t      *******      Services    ******* \n\n");
        printf("     \t\t\t\t\t\t    ================================================ \n\n");

        printf("    \t\t\t\t\t\t  <1.  Verser l'argent sur votre compte---------------- \n");
        printf("    \t\t\t\t\t\t  <2.  Tirer l'argent de votre compte------------------ \n");
        printf("    \t\t\t\t\t\t  <3.  Virement d'argent------------------------------- \n");
        printf("    \t\t\t\t\t\t  <4.  Paiment des factures---------------------------- \n");
        printf("    \t\t\t\t\t\t  <5.  Credit------------------------------------------ \n");
        printf("    \t\t\t\t\t\t  <6.  Retour au menu principal------------------------\n\n");
        printf("     \t\t\t\t\t\t     =============================================== \n\n");
        printf("\t\t\t\t\tEntrer votre choix:\t");
        scanf("%d",&choix);
        printf("\n\n");

           switch(choix){
                case 1: system("cls");
                        Versement(f1);
                        break;
                case 2: system("cls");
                        Tirage(f1);
                        break;
                case 3: system("cls");
                        Virement(f1);
                        break;
                case 4: system("cls");
                        Paiement(f1);
                        break;
                case 5: system("cls");
                        Credit(f1);
                        break;
                case 6:system("cls");
                        break;
                default : system("cls");printf("\t\t\tvotre choix n'est pas valide !!!\n");
        }
    }while(choix!=6);

}



void wait(){
    printf("\n\n\t\t\t\t\t\t\t**veuillez patienter quelques secondes !**");
    int c, d;
    for (c = 1; c <= 32767; c++)
        for (d = 1; d <= 32767; d++)
            {}
}




void Tirage(FILE *f){
    double  C; Client A;


    if(Recherche(f,A.CIN)==0){
        return ;
    }
    printf("\n");

    char path[50]="Comptes\\";
    strcat(path,A.CIN);
    strcat(path,".txt");

    f=fopen(path,"r");


    fscanf(f,"%s",A.nom);
    fscanf(f,"%s",A.prenom);
    fscanf(f,"%d %s %d",&A.date_naiss.jour,A.date_naiss.mois,&A.date_naiss.annee);
    fscanf(f,"%s",A.CIN);
    fscanf(f,"%s",A.num_tele);
    fscanf(f,"%s",A.email);
    fscanf(f,"%d",&A.num_compte);
    fscanf(f,"%lf",&A.Solde);
    char chaine1[50],chaine2[50];
    fscanf(f,"%s",chaine1);
    fscanf(f,"%s\n",chaine2);
    fclose(f);

    double old_sld=A.Solde;
    printf("\n\n");
    printf("\t\t\t\tSaisir le montant a tirer:\t");
    scanf("%lf",&C);

    wait();
    if(C <= A.Solde){
        A.Solde-=C ;
        printf("\n\n\t\t\t\t\t\t\t\tle tirage est fait avec succes !");
        printf("\n\n\n\t\t\t\tAppuyer sur un bouton pour continuer...");
        getch();
        system("cls");
        f=fopen(path,"w");
        fprintf(f,"%s\n%s\n%d %s %d\n%s\n%s\n%s\n%06d\n%lf",A.nom,A.prenom,A.date_naiss.jour,A.date_naiss.mois,A.date_naiss.annee,A.CIN,A.num_tele,A.email,A.num_compte,A.Solde);
        fprintf(f,"\n%s %s",chaine1,chaine2);
        printf("\n\n\n\t\tVos information personelles après la derniere operation:");

        fclose(f);
        Affichage(f,A.CIN);
        retour();
    }
    else{
        printf("\n\n\t\t\t\t\t\t votre solde est insuffisant pour effectuer cette operation !\n");
        retour();
        return;
    }

    f=fopen("operations.txt","a");
    if(f==NULL){
        printf("Error!!");
        exit(-1);
    }
    char op[10]="TIRAGE";
    fprintf(f,"|  %-8s %-15s %-15s %-14lfDH    %-12s  %-14lfDH |\n",A.CIN,A.nom,A.prenom,old_sld,op,A.Solde);
    fclose(f);

}

void Versement(FILE *f){
    int montant;
    Client A;


    if(Recherche(f,A.CIN)==0){
        return ;
    }
    printf("\n");

    char path[50]="Comptes\\";
    strcat(path,A.CIN);
    strcat(path,".txt");

    f=fopen(path,"r");
    fscanf(f,"%s",A.nom);
    fscanf(f,"%s",A.prenom);
    fscanf(f,"%d %s %d",&A.date_naiss.jour,A.date_naiss.mois,&A.date_naiss.annee);
    fscanf(f,"%s",A.CIN);
    fscanf(f,"%s",A.num_tele);
    fscanf(f,"%s",A.email);
    fscanf(f,"%d",&A.num_compte);
    fscanf(f,"%lf",&A.Solde);
    char chaine1[50],chaine2[50];
    fscanf(f,"%s",chaine1);
    fscanf(f,"%s\n",chaine2);
    double old_sld=A.Solde;
    fclose(f);

    f=fopen(path,"w");
    printf("\n\t\t\t\t\tEntrer le montant que vous voulez verser:\t");
    scanf("%d",&montant);
    wait();
    printf("\n\n\t\t\t\t\tLa somme %d a ete bien ajoutee a votre compte.",montant);
    printf("\n\n\n\t\t\tAppuyer sur un bouton pour continuer...");
    getch();
    system("cls");
    A.Solde=A.Solde+montant;

    fprintf(f,"%s\n%s\n%d %s %d\n%s\n%s\n%s\n%06d\n%lf",A.nom,A.prenom,A.date_naiss.jour,A.date_naiss.mois,A.date_naiss.annee,A.CIN,A.num_tele,A.email,A.num_compte,A.Solde);
    fprintf(f,"\n%s %s",chaine1,chaine2);
    fclose(f);
    printf("\n\t\tVos informations apres la dareniere modification:");
    Affichage(f,A.CIN);
    retour();

    f=fopen("operations.txt","a");
    if(f==NULL){
        printf("Error!!");
        exit(-1);
    }
    char op[10]="VERSEMENT";
    fprintf(f,"|  %-8s %-15s %-15s %-14lfDH    %-12s  %-14lfDH |\n",A.CIN,A.nom,A.prenom,old_sld,op,A.Solde);
    fclose(f);
    return ;

}
void Virement(FILE *f){
    double montant;
    Client A,B;

    if(Recherche(f,A.CIN)==0)
        return ;
    printf("\n");
    char pathA[50]="Comptes\\";
    strcat(pathA,A.CIN);
    strcat(pathA,".txt");

    f=fopen(pathA,"r");
    fscanf(f,"%s",A.nom);
    fscanf(f,"%s",A.prenom);
    fscanf(f,"%d %s %d",&A.date_naiss.jour,A.date_naiss.mois,&A.date_naiss.annee);
    fscanf(f,"%s",A.CIN);
    fscanf(f,"%s",A.num_tele);
    fscanf(f,"%s",A.email);
    fscanf(f,"%d",&A.num_compte);
    fscanf(f,"%lf",&A.Solde);
    char chaine1[50],chaine2[50];
    fscanf(f,"%s",chaine1);
    fscanf(f,"%s\n",chaine2);
    double old_sld=A.Solde;
    fclose(f);

    printf("\n\t\t\t\t\tenter le montant que vous voulez envoyer:\t");
    scanf("%lf",&montant);
    if(A.Solde<montant + 0.05*montant){
        printf("\n\n\t\t\t\t\t\t votre solde est insuffisant pour effectuer cette operation !\n");
        retour();
        return;
    }
    else{
        printf("\n\t\t\tenter le CIN de destinataire:\t");
        scanf("%s",B.CIN);
        FILE *ff=NULL;

        char nnpath[50]="Comptes\\";
        strcat(nnpath,B.CIN);
        strcat(nnpath,".txt");
        wait();
        ff=fopen(nnpath,"r");
        if(ff==NULL){
            double x=(montant*5)/100;
            printf("\n\n\t\t\t\tCe compte n'existe pas chez nous, donc on va Retrancher 5/100(%lf) de votre compte!\n",x);
            f=fopen(pathA,"w");
            A.Solde=A.Solde-montant;
            A.Solde-=x;
            fprintf(f,"%s\n%s\n%d %s %d\n%s\n%s\n%s\n%06d\n%lf",A.nom,A.prenom,A.date_naiss.jour,A.date_naiss.mois,A.date_naiss.annee,A.CIN,A.num_tele,A.email,A.num_compte,A.Solde);
            fprintf(f,"\n%s %s",chaine1,chaine2);
            fclose(f);
            printf("\n\n\n\t\t\t\tAppuyer sur un bouton pour continuer...");
            getch();
            system("cls");
            printf("\n\n\t\tVos information personelles après la derniere operation:");
            Affichage(f,A.CIN);
            f=fopen("operations.txt","a");
            if(f==NULL){
                printf("Error!!");
                exit(-1);
            }
            char op[10]="VIREMENT";
            fprintf(f,"|  %-8s %-15s %-15s %-14lfDH    %-12s  %-14lfDH |\n",A.CIN,A.nom,A.prenom,old_sld,op,A.Solde);
            fclose(f);
            retour();

            return ;
        }

        char pathB[50]="Comptes\\";
        strcat(pathB,B.CIN);
        strcat(pathB,".txt");

        f=fopen(pathB,"r");
        fscanf(f,"%s",B.nom);
        fscanf(f,"%s",B.prenom);
        fscanf(f,"%d %s %d",&B.date_naiss.jour,B.date_naiss.mois,&B.date_naiss.annee);
        fscanf(f,"%s",B.CIN);
        fscanf(f,"%s",B.num_tele);
        fscanf(f,"%s",B.email);
        fscanf(f,"%d",&B.num_compte);
        fscanf(f,"%lf",&B.Solde);
        fscanf(f,"%s",B.chaine1);
        fscanf(f,"%s\n",B.chaine2);
        fclose(f);

        printf("\n\n\t\t\tLa somme de %lf a ete envoye a %s %s",montant,B.nom,B.prenom);

        f=fopen(pathA,"w");
        A.Solde=A.Solde-montant;

        fprintf(f,"%s\n%s\n%d %s %d\n%s\n%s\n%s\n%06d\n%lf",A.nom,A.prenom,A.date_naiss.jour,A.date_naiss.mois,A.date_naiss.annee,A.CIN,A.num_tele,A.email,A.num_compte,A.Solde);
        fprintf(f,"\n%s %s",chaine1,chaine2);
        fclose(f);


        f=fopen(pathB,"w");
        B.Solde=B.Solde+montant;

        fprintf(f,"%s\n%s\n%d %s %d\n%s\n%s\n%s\n%06d\n%lf",B.nom,B.prenom,B.date_naiss.jour,B.date_naiss.mois,B.date_naiss.annee,B.CIN,B.num_tele,B.email,B.num_compte,B.Solde);
        fprintf(f,"\n%s %s",B.chaine1,B.chaine2);
        fclose(f);


        printf("\n\n\n\t\t\t\tAppuyer sur un bouton pour continuer...");
        getch();
        system("cls");
        printf("\n\t\t\tVos information personelles après la derniere operation:");
        Affichage(f,A.CIN);
        retour();

        f=fopen("operations.txt","a");
        if(f==NULL){
            printf("Error!!");
            exit(-1);
        }
        char op[10]="VIREMENT";
        fprintf(f,"|  %-8s %-15s %-15s %-14lfDH    %-12s  %-14lfDH |\n",A.CIN,A.nom,A.prenom,old_sld,op,A.Solde);
        fclose(f);
    }
    return ;
}

void Paiement(FILE *f){
    Client A;
    int choix;
    double m;


    if(Recherche(f,A.CIN)==0){
        return ;
    }

    char path[50]="Comptes\\";
    strcat(path,A.CIN);
    strcat(path,".txt");

    f=fopen(path,"r");
    if(f==NULL){
        printf("Erreur de creation!!");
        exit(-1);
    }

    fscanf(f,"%s",A.nom);
    fscanf(f,"%s",A.prenom);
    fscanf(f,"%d %s %d",&A.date_naiss.jour,A.date_naiss.mois,&A.date_naiss.annee);
    fscanf(f,"%s",A.CIN);
    fscanf(f,"%s",A.num_tele);
    fscanf(f,"%s",A.email);
    fscanf(f,"%d",&A.num_compte);
    fscanf(f,"%lf",&A.Solde);
    char chaine1[50],chaine2[50];
    fscanf(f,"%s",chaine1);
    fscanf(f,"%s\n",chaine2);
    fclose(f);

    double old_sld=A.Solde;
    int i=0;
    do{
        if(i>0)
            Affichage(f,A.CIN);
        i++;
        printf("\n\t\t\t\t\tLes factures que vous pouvez payer:\n\n");
        printf("\t\t\t\t\t\t1. Eau.\n");
        printf("\t\t\t\t\t\t2. Electricite.\n");
        printf("\t\t\t\t\t\t3. Telephone.\n");
        printf("\t\t\t\t\t\t4. Internet.\n");
        printf("\t\t\t\t\t\t5. Retour au menu principal\n");

        printf("\n\t\t\t\t\t\t\tEntrer votre choix:\t");
        scanf("%d",&choix);

        switch(choix){
            case 1:
            case 2:
            case 3:
            case 4:
                printf("\n\t\t\t\t\t\tSaisir le montant de cette facture:\t");
                scanf("%lf",&m);
                wait();
                if(m>A.Solde){
                printf("\n\n\t\t\t\t\t\t\t\tSolde insuffisant!!");
                printf("\n\n\t\t\t\tAppuyer sur un bouton pour continuer...");
                getch();
                system("cls");
                }
                else{
                    f=fopen(path,"w");
                    A.Solde-=m;
                    printf("\n\n\t\t\t\t\t\t\t\tla facture a ete payee.");
                    printf("\n\n\n\t\t\tAppuyer sur un bouton pour continuer...");
                    getch();
                    system("cls");
                    printf("\n\n\t\tVos information personelles après la derniere operation:");
                    fprintf(f,"%s\n%s\n%d %s %d\n%s\n%s\n%s\n%d\n%lf",A.nom,A.prenom,A.date_naiss.jour,A.date_naiss.mois,A.date_naiss.annee,A.CIN,A.num_tele,A.email,A.num_compte,A.Solde);

                    fprintf(f,"\n%s %s",chaine1,chaine2);
                    fclose(f);
                    Affichage(f,A.CIN);
                    retour();
                    f=fopen("operations.txt","a");
                    if(f==NULL){
                        printf("Error!!");
                        exit(-1);
                    }
                    char op[10]="PAIEMENT";
                    fprintf(f,"|  %-8s %-15s %-15s %-14lfDH    %-12s  %-14lfDH |\n",A.CIN,A.nom,A.prenom,old_sld,op,A.Solde);
                    fclose(f);
                }
                break;
            case 5:
                system("cls");
                break;
            default:
                printf("\tChoix invalid!");
                break;
        }
    }while(choix!=5);

}

void Credit(FILE *f){
    Client A;
    double C,I,n=2.,m;
    const double t=5./100;

    if(Recherche(f,A.CIN)==0){
        return ;
    }

    char path[50]="Comptes\\";
    strcat(path,A.CIN);
    strcat(path,".txt");

    f=fopen(path,"r");

    fscanf(f,"%s",A.nom);
    fscanf(f,"%s",A.prenom);
    fscanf(f,"%d %s %d",&A.date_naiss.jour,A.date_naiss.mois,&A.date_naiss.annee);
    fscanf(f,"%s",A.CIN);
    fscanf(f,"%s",A.num_tele);
    fscanf(f,"%s",A.email);
    fscanf(f,"%d",&A.num_compte);
    fscanf(f,"%lf",&A.Solde);
    char chaine1[50],chaine2[50];
    fscanf(f,"%s",chaine1);
    fscanf(f,"%s\n",chaine2);
    double old_sld=A.Solde;
    fclose(f);

    printf("\n\n");
    printf("\t\t\t\tSaisir le montant que vous voulez crediter:\t");
    scanf("%lf",&C);

    I=C*t*n/12;
    A.Solde+=C;
    f=fopen(path,"w");
    fprintf(f,"%s\n%s\n%d %s %d\n%s\n%s\n%s\n%d\n%lf",A.nom,A.prenom,A.date_naiss.jour,A.date_naiss.mois,A.date_naiss.annee,A.CIN,A.num_tele,A.email,A.num_compte,A.Solde);
    fprintf(f,"\n%s %s",chaine1,chaine2);
    m=C/(12*n);
    wait();
    printf("\n\t\t\t\tLe montant que vous devez payer est %lf + %lf d'interet par mois pendant une periode de %.2lf ans.\n",m,I,n);
    printf("\n\n\n\t\t\tAppuyer sur un bouton pour continuer...");
    getch();
    system("cls");
    printf("\n\n\n\t\tVos information personelles après la derniere operation:");

    fclose(f);
    Affichage(f,A.CIN);

    f=fopen("operations.txt","a");
        if(f==NULL){
            printf("Error!!");
            exit(-1);
        }
        char op[10]="CREDIT";
        fprintf(f,"|  %-8s %-15s %-15s %-14lfDH    %-12s  %-14lfDH |\n",A.CIN,A.nom,A.prenom,old_sld,op,A.Solde);
        fclose(f);
    retour();
}
