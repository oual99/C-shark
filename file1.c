#include "file1.h"
#include "file2.h"


void ges_comptes(){
    int n=0,choix; FILE *f1=NULL;

    char cin[10];
    do{
        printf("\n   \t\t\t\t\t\t      *******      Gestion des comptes    ******* \n\n");
        printf("     \t\t\t\t\t\t    ================================================ \n\n");

        printf("    \t\t\t\t\t\t  <1.  Creer un nouveau compte------------------------- \n");
        printf("    \t\t\t\t\t\t  <2.  Rechrcher un compte existant-------------------- \n");
        printf("    \t\t\t\t\t\t  <3.  Modifier un compte existant--------------------- \n");
        printf("    \t\t\t\t\t\t  <4.  Supprimer un compte existant-------------------- \n");
        printf("    \t\t\t\t\t\t  <5.  Retour au menu principal\n\n");
        printf("     \t\t\t\t\t\t     =============================================== \n\n");
        printf("\t\t\t\t\tEntrer votre choix:\t");
        scanf("%d",&choix);

           switch(choix){
                case 1: system("cls");
                        Creation(f1,&n);
                        break;
                case 2: system("cls");
                        if(Recherche(f1,cin))
                            retour();

                        break;
                case 3: system("cls");
                        Modification(f1);
                        break;
                case 4: system("cls");
                        Supprimer(f1);
                        break;
                case 5:system("cls");
                        break;
                default:system("cls");
                        printf("\t\t\tvotre choix n'est pas valide !!!\n");
        }
    }while(choix!=5);
}



void retour(){
    printf("\n\n\t\t\t\tAppuyer sur un bouton pour retourner au menu precedent...");
    getch();
    system("cls");
}



void ligne(char a,int n){
    int i;
    for(i=0;i<n;i++)
        printf("%c",a);
}



void quitter(){
    system("cls");
    printf("\n\n        \t\t\t\t\t\t\t\t------------FIN-----------\n\n\n");
}


int Affichage(FILE *f,char CIN[]){
    char chaine[50],chaine1[50],chaine2[50];

    char path[50]="Comptes\\";
    strcat(path,CIN);
    strcat(path,".txt");

    f=fopen(path,"r");
    if(f==NULL){
        printf("\a\n\t\t\t\t\t\t\t  Il n y a aucun compte avec ce CID!!\n");
        retour();
        return 0;
    }

    printf("\n\n\n");
    printf("\t\t\t\t\t\t==================Vos informations personelles====================\n\n");
    fscanf(f,"%s\n",chaine);
    printf("\t\t\t\t\t\tnom:  %20s\t",chaine);
    fgets(chaine,100,f);
    printf("\tprenom:  %18s",chaine);
    printf("\n");
    fgets(chaine,100,f);
    //fscanf(f,"%s\n",chaine);
    printf("\t\t\t\t\t\t\t     Date de naissance:  %15s\t",chaine);
    printf("\n");
    fscanf(f,"%s\n",chaine);
    printf("\t\t\t\t\t\tCIN:  %20s\t",chaine);
    fscanf(f,"%s\n",chaine);
    printf("\tTelephone:  %14s\n",chaine);
    printf("\n");
    fscanf(f,"%s\n",chaine);
    printf("\t\t\t\t\t\tEmail:  %18s\t",chaine);
    fscanf(f,"%s\n",chaine);
    printf("\tNum de compte:  %10s\n",chaine);
    printf("\n");
    fscanf(f,"%s\n",chaine);
    //fgets(chaine1,100,f);
    fscanf(f,"%s",chaine1);
    fscanf(f,"%s\n",chaine2);
    printf("\t\t\t\t\t\t\t Date de creation du compte:  %10s %s\t",chaine1,chaine2);
    printf("\n\n\t\t\t\t\t\t\t\t\t\tSolde:\t%s",chaine);
    printf("\n\t\t\t\t\t\t==================================================================\n\n");

    fclose(f);

    return 1;
}



int Creation(FILE *f,int *n){
    char x; Client A; int num_acc=0;


    ligne('°',168);
    ligne('°',168);
    printf("\n");
    printf("\t\t\t\t\t\t\t\tSaisir votre CIN:\t");
    scanf("%s",A.CIN);

    char path[50]="Comptes\\";
    strcat(path,A.CIN);
    strcat(path,".txt");


    f=fopen(path,"r");
    if(f!=NULL){
        printf("\n\t\t\tCe compte existe déjà!!!\n");
        printf("\n\t\tAppuyer sur un bouton pour retourner au menu principal...");
        getch();
        system("cls");
        return 0;
    }
    fclose(f);

    FILE *fnum=NULL;

    fnum=fopen("fnum.txt","r");
    fscanf(fnum,"%d",&num_acc);
    fclose(fnum);

    A.num_compte=num_acc+1; //(still thinking about it)

    fnum=fopen("fnum.txt","w");
    fprintf(fnum,"%d",A.num_compte);
    fclose(fnum);


    printf("\n\t\t\t\t\t");
    ligne('_',76);
    printf("\n\t\t\t\t\t\t\t\tSaisir votre nom:\t");
    scanf("%s",A.nom);
    printf("\n\t\t\t\t\t");
    ligne('_',76);
    printf("\n\t\t\t\t\t\t\t\tSaisir votre prenom:\t");
    scanf("%s",A.prenom);
    printf("\n\t\t\t\t\t");
    ligne('_',76);
    printf("\n\t\t\t\t\t\tSaisir votre date de naissance(Ex: 01 Janvier 1999):\t");
    scanf("%d%s%d",&A.date_naiss.jour,A.date_naiss.mois,&A.date_naiss.annee);
    printf("\n\t\t\t\t\t");
    ligne('_',76);
    printf("\n\t\t\t\t\t\t\tSaisir votre numero de telephone:\t06");
    scanf("%s",A.num_tele);
    printf("\n\t\t\t\t\t");
    ligne('_',76);
    printf("\n\t\t\t\t\t\t\t\tSaisir votre adresse email:\t");
    scanf("%s",A.email);
    printf("\n\t\t\t\t\t");
    ligne('_',76);
    printf("\n\t\t\t\t\t Voulez vouz verser l'argent sur votre nouveau compte? (Y=yes,N=no)\t");
    scanf(" %c",&x);
    if(x=='Y' || x=='y'){
        printf("\n\t\t\t\t\t");
        ligne('_',76);
        printf("\n\t\t\t\t\t\tSaisir le montant que vous voulez verser (en DH):\t");
        scanf("%lf",&A.Solde);
    }
    else
        A.Solde=0.;


    f=fopen(path,"w");
    if(f==NULL){
        printf("Erreur de creation!!");
        exit(-1);
    }

    fprintf(f,"%s\n%s\n%d %s %d\n%s\n06%s\n%s\n%06d\n%lf",A.nom,A.prenom,A.date_naiss.jour,A.date_naiss.mois,A.date_naiss.annee,A.CIN,A.num_tele,A.email,A.num_compte,A.Solde);
    time_t seconds = time(NULL);
    struct tm * timeinfo = localtime(&seconds);
    fprintf(f,"\n%04d-%02d-%02d %02d:%02d:%02d",1900+timeinfo->tm_year,timeinfo->tm_mon+1,timeinfo->tm_mday,timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec);
    fclose(f);
    Affichage(f,A.CIN);
    f=fopen("Comptes.txt","a");
    if(f==NULL){
        printf("Erreur!!");
    }
    int age=2020-A.date_naiss.annee;
    fprintf(f,"%s %s %s %d %lf\n",A.CIN,A.nom,A.prenom,age,A.Solde);
    fclose(f);

    printf("\n\t\t\t\t\t\t\tVotre compte a ete bien ajoute.\n");
    retour();

    return 1;
}

int Modification(FILE *f){
    int choix; Client A,B; char CIN[10]; FILE *f1;

    if(Recherche(f,A.CIN)==0){
        return 0;
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
    //printf("\n\t11nv num:%s\n",A.num_tele);
    fclose(f);
    //Affichage(f,A.CIN);
    int i=0;char nom[20];char prenom[20];int age;
    do{
        if(i>0)
            Affichage(f,A.CIN);
        i++;
        printf("\n\t\t\tChoisir le champ que vous voulez modifier:\t\n\n");
        printf("\t\t\t\t\t1.Nom\n\t\t\t\t\t2.Prenom\n\t\t\t\t\t3.Date de naissance\n\t\t\t\t\t4.Code d'identite national\n");
        printf("\t\t\t\t\t5.Numero de telephone\n\t\t\t\t\t6.Emai\n\t\t\t\t\t7.Retour au menu principal\n");

        printf("\n\n\t\t\t\t\t\tEntrer votre choix:\t");
        scanf("%d",&choix);

        switch(choix){
            case 1:

                f=fopen(path,"w");
                printf("\n\t\t\tSaisir le nouveau nom:\t");
                scanf("%s",nom);
                printf("\n\n\t\t\tAffichage apres la modification:");
                fprintf(f,"%s\n%s\n%d %s %d\n%s\n%s\n%s\n%06d\n%lf",nom,A.prenom,A.date_naiss.jour,A.date_naiss.mois,A.date_naiss.annee,A.CIN,A.num_tele,A.email,A.num_compte,A.Solde);
                fprintf(f,"\n%s %s",chaine1,chaine2);
                fclose(f);
                Affichage(f,A.CIN);

//                f1=fopen("Comptes1.txt","w");
                /////////////////////
                f=fopen("Comptes.txt","r");
                f1=fopen("Comptes1.txt","w");

                while(!feof(f)){
                    fscanf(f,"%s %s %s %d %lf\n",B.CIN,B.nom,B.prenom,&age,&B.Solde);
                    if(strcmp(A.nom,B.nom)!= 0){
                        fprintf(f1,"%s %s %s %d %lf\n",B.CIN,B.nom,B.prenom,age,B.Solde);
                    }
                    else
                        fprintf(f1,"%s %s %s %d %lf\n",B.CIN,nom,B.prenom,age,B.Solde);
                }

                fclose(f1);
                fclose(f);
                remove("Comptes.txt");
                rename("Comptes1.txt","Comptes.txt");
////////////////////////

                printf("\n\t\tAppuyer sur un bouton pour continuer...");
                getch();
                system("cls");
                break;
            case 2:
                f=fopen(path,"w");
                printf("\n\t\t\tSaisir le nouveau prenom:\t");
                scanf("%s",prenom);
                printf("\n\n\t\t\tAffichage apres la modification:");
                fprintf(f,"%s\n%s\n%d %s %d\n%s\n%s\n%s\n%d\n%lf",A.nom,prenom,A.date_naiss.jour,A.date_naiss.mois,A.date_naiss.annee,A.CIN,A.num_tele,A.email,A.num_compte,A.Solde);
                fprintf(f,"\n%s %s",chaine1,chaine2);
                fclose(f);
                Affichage(f,A.CIN);

                /////////////////////
                f=fopen("Comptes.txt","r");
                f1=fopen("Comptes1.txt","w");

                while(!feof(f)){
                    fscanf(f,"%s %s %s %d %lf\n",B.CIN,B.nom,B.prenom,&age,&B.Solde);
                    if(strcmp(A.prenom,B.prenom)!= 0){
                        fprintf(f1,"%s %s %s %d %lf\n",B.CIN,B.nom,B.prenom,age,B.Solde);
                    }
                    else
                        fprintf(f1,"%s %s %s %d %lf\n",B.CIN,B.nom,prenom,age,B.Solde);
                }

                fclose(f1);
                fclose(f);
                remove("Comptes.txt");
                rename("Comptes1.txt","Comptes.txt");
////////////////////////
                printf("\n\t\tAppuyer sur un bouton pour continuer...");
                getch();
                system("cls");
                break;
            case 3:
                f=fopen(path,"w");
                printf("\n\t\t\tSaisir la nouvelle date:\t");
                scanf("%d %s %d",&A.date_naiss.jour,A.date_naiss.mois,&A.date_naiss.annee);
                printf("\n\n\t\t\tAffichage apres la modification:");
                fprintf(f,"%s\n%s\n%d %s %d\n%s\n%s\n%s\n%06d\n%lf",A.nom,A.prenom,A.date_naiss.jour,A.date_naiss.mois,A.date_naiss.annee,A.CIN,A.num_tele,A.email,A.num_compte,A.Solde);
                fprintf(f,"\n%s %s",chaine1,chaine2);
                fclose(f);
                Affichage(f,A.CIN);

                /////////////////////
                f=fopen("Comptes.txt","r");
                f1=fopen("Comptes1.txt","w");

                while(!feof(f)){
                    fscanf(f,"%s %s %s %d %lf\n",B.CIN,B.nom,B.prenom,&age,&B.Solde);
                    if(strcmp(A.nom,B.nom)!= 0){
                        fprintf(f1,"%s %s %s %d %lf\n",B.CIN,B.nom,B.prenom,age,B.Solde);
                    }
                    else{
                        age=2020-A.date_naiss.annee;
                        fprintf(f1,"%s %s %s %d %lf\n",B.CIN,B.nom,B.prenom,age,B.Solde);
                    }

                }

                fclose(f1);
                fclose(f);
                remove("Comptes.txt");
                rename("Comptes1.txt","Comptes.txt");
////////////////////////

                printf("\n\t\tAppuyer sur un bouton pour continuer...");
                getch();
                system("cls");
                break;
            case 4:
                f=fopen(path,"w");
                printf("\n\t\t\tSaisir le nouveau CIN:\t");
                scanf("%s",CIN);

                FILE *ff=NULL;
                char nnpath[50]="Comptes\\";
                strcat(nnpath,CIN);
                strcat(nnpath,".txt");

                ff=fopen(nnpath,"r");
                if(ff!=NULL){
                    printf("\n\t\til y a deja un compte avec ce CIN\n\n");
                    break;
                }

                printf("\n\n\t\t\tAffichage apres la modification:");
                fprintf(f,"%s\n%s\n%d %s %d\n%s\n%s\n%s\n%d\n%lf",A.nom,A.prenom,A.date_naiss.jour,A.date_naiss.mois,A.date_naiss.annee,CIN,A.num_tele,A.email,A.num_compte,A.Solde);
                //fprintf(f,"%s\n%s\n%d %s %d\n%s\n%s\n%s\n%06d\ n%lf",A.nom,A.prenom,A.date_naiss.jour,A.date_naiss.mois,A.date_naiss.annee,A.CIN,A.num_tele,A.email,A.num_compte,A.Solde);
                fprintf(f,"\n%s %s",chaine1,chaine2);

                char npath[50]="Comptes\\";
                strcat(npath,CIN);
                strcat(npath,".txt");

                fclose(f);
                rename(path,npath);
  /////////////////////
                f=fopen("Comptes.txt","r");
                f1=fopen("Comptes1.txt","w");

                while(!feof(f)){
                    fscanf(f,"%s %s %s %d %lf\n",B.CIN,B.nom,B.prenom,&age,&B.Solde);
                    if(strcmp(A.CIN,B.CIN)!= 0){
                        fprintf(f1,"%s %s %s %d %lf\n",B.CIN,B.nom,B.prenom,age,B.Solde);
                    }
                    else
                        fprintf(f1,"%s %s %s %d %lf\n",CIN,B.nom,B.prenom,age,B.Solde);
                }

                fclose(f1);
                fclose(f);
                remove("Comptes.txt");
                rename("Comptes1.txt","Comptes.txt");
////////////////////////
                Affichage(f,CIN);
                strcpy(A.CIN,CIN);

                printf("\n\t\tAppuyer sur un bouton pour continuer...");
                getch();
                system("cls");
                break;
            case 5:
                f=fopen(path,"w");
                printf("\n\t\t\tSaisir le nouveau numero de telephone:\t");
                scanf("%s",A.num_tele);
                printf("\n\n\t\t\tAffichage apres la modification:");
                fprintf(f,"%s\n%s\n%d %s %d\n%s\n%s\n%s\n%06d\n%lf",A.nom,A.prenom,A.date_naiss.jour,A.date_naiss.mois,A.date_naiss.annee,A.CIN,A.num_tele,A.email,A.num_compte,A.Solde);
                fprintf(f,"\n%s %s",chaine1,chaine2);
                fclose(f);
                Affichage(f,A.CIN);

                printf("\n\t\tAppuyer sur un bouton pour continuer...");
                getch();
                system("cls");
                break;
            case 6:
                f=fopen(path,"w");
                printf("\n\t\t\tSaisir le nouveau email:\t");
                scanf("%s",A.email);
                printf("\n\n\t\t\tAffichage apres la modification:");
                fprintf(f,"%s\n%s\n%d %s %d\n%s\n%s\n%s\n%d\n%lf",A.nom,A.prenom,A.date_naiss.jour,A.date_naiss.mois,A.date_naiss.annee,A.CIN,A.num_tele,A.email,A.num_compte,A.Solde);
                fprintf(f,"\n%s %s",chaine1,chaine2);
                fclose(f);
                Affichage(f,A.CIN);

                printf("\n\t\tAppuyer sur un bouton pour continuer...");
                getch();
                system("cls");
                break;
            case 7:
                system("cls");
                break;
            default:
                printf("\n\t\t\t\t\tChoix invalid!!");
                printf("\n\t\tAppuyer sur un bouton pour continuer...");
                getch();
                system("cls");
                break;
        }

    }while(choix!=7);

    return 1;
}

int Recherche(FILE *f,char cin[]){
    int n;
    ligne('°',168);
    ligne('°',168);
    printf("\n");
    printf("\n\t\t\t\t\t\t\t\tSaisir votre CIN:\t");
    scanf("%s",cin);
    n=Affichage(f,cin);

    return n;
}

int Recherche2(FILE *f,char cin[]){
    int n;

    n=Affichage(f,cin);

    return n;
}

void Supprimer(FILE *f){
    char  C; Client A,B; FILE *f1=NULL;

    if(Recherche(f,A.CIN)==0){
        return ;
    }

    char path[50]="Comptes\\";
    strcat(path,A.CIN);
    strcat(path,".txt");

    int age;
    //fprintf(f,"  %-8s %-15s %-15s %2dans   %-14lfDH  \n",A.CIN,A.nom,A.prenom,age,A.Solde);
    printf("\t\t\t\tVoulez vous vraiment supprimer votre compte \a?(Y=yes,N=no) \t");
    scanf("%s",&C);
    if(C=='Y' || C=='y'){
        remove(path);
        wait();
        f=fopen("Comptes.txt","r");
        f1=fopen("Comptes1.txt","w");
        while(!feof(f)){
            fscanf(f,"%s %s %s %d %lf\n",B.CIN,B.nom,B.prenom,&age,&B.Solde);
            if(strcmp(A.CIN,B.CIN)!= 0){
                fprintf(f1,"%s %s %s %d %lf\n",B.CIN,B.nom,B.prenom,age,B.Solde);
            }
            else
                fprintf(f1,"\n");
        }

        fclose(f1);
        fclose(f);
        remove("Comptes.txt");
        rename("Comptes1.txt","Comptes.txt");

        printf("\n\n\t\t\t\t\t\t\t\t votre compte est supprimé !! \n\n");
        retour();
    }
    else{
        retour();
        return;
    }
}
