                       #***** LE TITRE DE PROJECT : GESTION D'UN COMPTE BANCAIRE *****
	                   #***** Réalisé par:
                                    ** Ait Ouallane Abderrahmane 
                                    ** Boulak Ibtissam 
                                    ** Aarab Ilham 
                      #****** Encadré par : Mme Asri Hiba 

		       ********************************************** LE BUT DE PROJET ************************************************
		       *   Notre projet consiste a creer un logiciel qui fait une interaction avec les clients d'une banque            *
			   *   tout en leur presentant plusieurs fonctinnalités et mouvements qu'ils peuvent ait besoin.                   *
			   *   Le But principal de ce projet et d'appliquer les differentes techniques qu'on a apprit dans le              *
			   *   module de programmation : les chaines de caracteres , les fichiers , les tableaux,compilation modulaire...  *
               ****************************************************************************************************************


                       # ======== Les fonctionnalités de Projet :======= 

	 1- fonction de création : chaque client peut creer son compte bancaire, qui est definit par son CIN , son nom , email,
      son telephone,solde..,toutes ses informations sont stockés dans un fichier propre à ce client. 
     2-fonction de Recherche : qui permet de consulter un compte bancaire s'il existe , sinon il affiche un message d'erreur .
 	 3-fonction d'affichage : qui sert à afficher les données personnelles d'un client .
     4-fonction de modification : pour modifier un champs dans les donnees  d'un  client . 
     5-fonction de suppression : pour supprimer un compte bancaire definitivement . 
     6-fonction de versement : qui permet le client à verser un montant sur son compte bancaire . 
     7-fonction de virement :qui permet le client de transferer un montant un à un autre client soit de la meme banque soit d'une autre. 
     8-fonction de Tirage : qui permet le client de tirer un montant desiré qui ne depasse pas son solde .
     9-fonction de paiment de facture : electricité,abonnement internet ,eau ... 
     10-fonction de crédit : qui permet au client de créditer un montant de la banque .
     11-fonction de numero de compte : qui sert a numeroter les fichiers des clients de notre banque . 
	         
                     # ============ Les fichiers utilisés pour la construction de projet ===========

            ** Les fichiers ".c" : qui contient les definitions de toutes les fonctions utilisés 
      1- file1.c : qui contient les fonctions : création , affichage , modification , num_acc , Recherche
      2- file2.c : qui contient les fontiosn : crédit , paiement de factures , tirage , suppression ,virement , versement,fonction du temps. 

            ** Les fichiers ".h" : qui contient les prototypes des fonctions utilisés et aussi les structures des données . 
      1- file1.h : contient la structure date , structure client , et les prototypes de toutes les fonctions . 
      2- file2.h :contient le prototype de la fonction credit .  
      3- main.c  :  le programme principale , qui contient le menu d'interface . 
                    #============== compilation sur Windows : appuyer sur run and built sur le logiciel codeblocks ============

                    # =========== les commandes linux pour la compilation du projet ================
       1- creation des fichiers objet : gcc *.c 
       2- creation des fihier executable : gcc main.o file1.o file2.o file3.o -o main.e 
       3- execution du projet : ./main.e 
       4- fichier makefile qui contient toutes ces commandes , qui facilite la recompilation du programme au cas d'une modification ,au moyen de la commande make . 

                    # ======== La version :======= 

              La version est: 1.0