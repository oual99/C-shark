#ifndef FILE1_H_INCLUDED
#define FILE1_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>

typedef struct{
    int jour;
    char mois[15];
    int annee;
}date;

typedef struct{
    char nom[20];
    char prenom[20];
    date date_naiss;
    char CIN[10];
    char num_tele[50];
    char email[20];
    double Solde;
    int num_compte;
    char chaine1[50];
    char chaine2[50];
}Client;

void ges_comptes();
int Creation(FILE *f,int *n);
int Affichage(FILE *f,char CIN[]);
int Recherche(FILE *f,char cin[]);
int Modification(FILE *f);
int Recherche2(FILE *f,char cin[]);
void Supprimer(FILE *f);
void retour();
void ligne(char a,int n);
void quitter();

#endif // FILE1_H_INCLUDED
