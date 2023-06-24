#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include"etudiants.h"
//programme qui fait la gestion des étudiants
int main(){
	int choix , i=0 , quitter=0 , taille=0 , nv_e; //nv_e: nouveau étudiant 
	//le tableau ci-dessous représente les étudiants. (la taille initiale est égale à 0, alors le tableau n'a aucun étudiant)
	etudiant *etds = malloc(sizeof(etudiant)*taille); //déclaration dynamique
	
	printf("------------------------la gestion des etudinats--------------------------\n\n\n");
	while ( quitter == 0 ){
		//le Menu à afficher
		printf("1 : saisir les info d'un nouveau(x) etudiant(s)\n2 : afficher les noms de tous les etudiants\n3 : afficher la moyenne generale de chaque etudiant\n");
		printf("4 : afficher toutes les info d'un etudiant a partir de son ID\n5 : trier les etudiants par la moyenne generale\n6 : Quitter\nvotre choix : ");
		
		//tester si l'utilisateur a saisi vraiment un nombre
		if ( ! scanf("%d",&choix) ){
			printf("\nvous n'avez pas saisi un nombre (ba9i ba3louk asa7bi hhhh) :/\n\n");
			break;
		}
		printf("\n");
		
		//tester les autres probabilités
		switch (choix){
		
			//case 1 : saisir les info d'un nouveau(x) etudiant(s) 
			case 1 : 
				//récupérer "le nombre d'étudiant à ajouter dans le tableau"
				printf("combien d'etudiant voulez-vous saisir? ");
				scanf("%d",&nv_e);
				
				//ajouter "nv_e" à la taille du tableau (alors on a une nouvelle taille, donc on doit réaffecter la taille du tableau)
				taille = taille + nv_e; 
				etds = realloc( etds , sizeof(etudiant)*taille);
				
				//récupérer les info à l'aide de la fonxtion "saisi", (Si vous étes confus é cause de (i = i) voir é la fin de programme)
				for (i=i ; i<taille ; i++){  
					printf("les info de l'etudiant %d\n",i+1);
					saisi( etds , i );
				}
				break;
				
			//case 2 : afficher les noms de tous les etudiant
			case 2 :
				if ( taille==0 )	printf("il faut d'abord saisir au moins des info d'un etudiant !!\n\n");
				else 	noms( etds , taille );
				break;
				
				
			//case 3 : afficher la moyenne générale de chaque étudiant
			case 3 :
				if ( taille==0 )	printf("il faut d'abord saisir au moins des info d'un etudiant !!\n\n");
				else{
					for (i=0 ; i<taille ; i++)
						printf("la moyenne generale de l'etudiant %d (%s) est %.2f\n", i+1 , etds[i].nom , moy(etds[i]));
					printf("\n");	
				}
				break;
				
			//case 4 : afficher toutes les info d'un etudiant é partir de son ID
			case 4 :
				if ( taille==0 )	printf("il faut d'abord saisir au moins des info d'un etudiant !!\n\n");
				else	info( etds , taille );
				break;	
			
			//trier les étudiants par la moyenne générale
			case 5 :
				tri( etds , taille );
				noms( etds , taille );
				break;
			
			case 6 :
				quitter = 1;
				break;
				
			default :
				printf("votre choix n'existe pas dans le menu!!\n\n");
		}
	}
	
			/*on a fait "i=i" (sachant que "i" a été initialisé par 0), parce que si l'utiliateur veut ajouter un nouveau etudiant
			(C-é-d l'utilisateur a déja saisi des etudiants), la boucle va commencer é partir de l'élément qui suit le dernier 
			étudiant, alors les autres etudiants n'écrasent pas*/

		return 0;
}
