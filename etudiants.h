#include<stdlib.h>
#include<string.h>
#include<stdio.h>

typedef struct{
	int j;
	int m;
	int a;
}date;



typedef struct{ //une structure qui s'appelle "etudiant"
	char CIN[13];
	char nom[13];
	char prenom[13];
	float *note;
	date nsc;
}etudiant;

int cmp(etudiant etds[] , int taille , char *Id){ //comparer deux Ids
	int i ;
	for (i=0 ; i<taille ; i++){
		if( strcmp(Id , etds[i].CIN)==0){
			return 0;
		}
	}
	return 1;
}


void saisi(etudiant etds[] , int indx ){ //fonction qui r�cup�re les info d'un etudiant (etds[indx])
	int i ;
	//r�cup�rer l'Id et le comparer avec les autres Ids � l'aide de la fonction "cmp"
	printf("son identifiant : ");	scanf("%s",&etds[indx].CIN);
	while ( !cmp(etds , indx , etds[indx].CIN) ){ //dans ce cas la var "indx" represente la taille du tableau
		printf("cet identifiant deja existe(charab dwa?)\nsaisi l'Id a nouveau : ");
		scanf("%s",&etds[indx].CIN);
	}
	printf("son nom : ");			scanf("%s",&etds[indx].nom);
	printf("son prenom : ");		scanf("%s",&etds[indx].prenom);
	printf("saisi votre date de nissance:\n");
	printf("le jour : ");			scanf("%d",&etds[indx].nsc.j);
	printf("le mois : ");			scanf("%d",&etds[indx].nsc.m);
	printf("l'annee : ");			scanf("%d",&etds[indx].nsc.a);
	etds[indx].note = (float*)malloc(2*sizeof(float));
	for ( i=0 ; i<2 ; i++){
		printf("la note %d : ",i+1);
		scanf("%f",&etds[indx].note[i]);
	}
	printf("\n");
	
}




void afficher( etudiant e1 , int n){ //afficher les info d'un �tudiant e1
	int i;
	printf("l'etudiant %d dans la liste\n",n);
	printf("CIN : %s\n",e1.CIN);
	printf("Le nom : %s\n",e1.nom);
	printf("le prenom : %s\n",e1.prenom);
	printf("la date de nissance : %d/%d/%d\n" , e1.nsc.j , e1.nsc.m , e1.nsc.a );
	for ( i=0 ; i<2 ; i++)		printf("la note %d : %.2f\n", i+1 , e1.note[i]);
	printf("\n\n");
}

void noms( etudiant etds[] , int taille){ //afficher les noms de tous les etudiants
	int i;
	for ( i=0 ; i<taille ; i++){
		printf("le nom de l'etudiant %d est : %s  %s\n", i+1 , etds[i].nom ,  etds[i].prenom);
	}
	printf("\n");
}

float moy(etudiant e1 ){ //calculer la moyenne g�n�rale d'�tudiant e1 et le retourne
	int i  ;
	float S=0 ;
	//boucle qui calcule la somme des notes de l'etudiant e1
	for (i=0 ; i<2 ; i++)	S = S + e1.note[i];
	return S/2;
}

void info( etudiant etds[] , int taille ){ //afficher toutes les info d'un �tudiant � partir de son ID
	int i , flage=0 ; //flage: identificateur logique
	char Id[6];
	//r�cupere l'Id
	printf("veuillez saisir l'Id de l'etudiant que vous voulez afficher ses info : ");
	scanf("%s",Id);
	//comparer Id avec les Id de diff�rents �tudiants
	for (i=0 ; i<taille ; i++){
		if ( strcmp( Id , etds[i].CIN) == 0 ){
			afficher( etds[i] , i+1 );
			flage = 1;
			break;
		}
	}
	//afficher un message si Id n'exite pas
	if (!flage)	printf("l'Id que vous avez saisi n'existe pas!!\n\n");
}

void tri( etudiant etds[] , int taille ){ //trier les �tudiants par la moyenne g�n�rale
	int i , j ;
	etudiant tmp; //variable temporaire
	//boucle qui parcourit toutes les �tudiants
	for (i=0 ; i<taille-1 ; i++){
		for (j=i+1 ; j<taille ; j++){
			if ( moy(etds[i]) < moy(etds[j]) ){
				tmp = etds[i];
				etds[i] = etds[j];
				etds[j] = tmp;
			}
		}
	}
}


