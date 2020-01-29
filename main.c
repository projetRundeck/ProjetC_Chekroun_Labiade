#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Menu.h"
#include "structure.h"
#include "structureAssemblage.h"
#include "recherche.h"
#define MX 10000000000000
#define Malloc(type) (type*)malloc(sizeof(type))

int main(int argc, char const *argv[]){
	char *mdp,*mdpd;
	int test=1,iteration=0,choix=9,choix1=9,choix2;
	mdp=(char*)malloc(20*sizeof(char));
	mdpd=(char*)malloc(20*sizeof(char));
	strcpy(mdpd,"555");
	menu();
	scanf("%d",&choix);
	if(choix==0){
		printf("Bonjour, entrer le mot de passe s'il vous plaît, vous avez 3 tentatives:\n");
		scanf("%s",mdp);
		while(iteration<3){
			if(strcmp(mdp,mdpd)==0){
				test=0;
				break;
			}
			else
				if(test==1){
					printf("Mot de passe incorrect,il vous reste 2 tentatives:\n");
					scanf("%s",mdp);
					test++;
				}
				else
					if(test==2){
						printf("Mot de passe incorrect,il vous reste une seule tentative:\n");
						scanf("%s",mdp);
						test++;
					}
					else
						if(test==3){
							printf("Dommage! Le programme est quitté.\n");
							exit(1);
						}
			iteration++;
		}
	}
	else{
		printf("Vous avez quitter le programme.\n");
		exit(1);
	}
	while(choix1!=2){
		menu1();
		scanf("%d",&choix1);
		if(choix1==1){
			printf("2 pour chercher dans un fichier non assembler.\n1 pour chercher dans un fichier déjà assembler.\n");
			scanf("%d",&choix2);
		}
		if((choix1==0) || ((choix1==1) && (choix2==2))){
			FILE *fi,*file1,*file2;
			char *nom,*nomF;
			nom=(char*)malloc(100*sizeof(char));
			int i=1,jump=0,w=0;
			int *tab1,*tab2;
			tab1=(int*)malloc(sizeof(int));
			nomF=(char*)malloc(sizeof(char));
			printf("entrer le nom du ficher:\n");
			scanf("%s",nomF);
			listeSequence L;
			L=NULL;
			fi=fopen(nomF,"r");
			while(fscanf(fi,"%s",nom)!=EOF){
				if((nom[0]!='@') && (nom[0]!='I') && (nom[0]!='+')){
					L=insererSequence(importSequence(nom,i),L);
					i=i+1;
				}
			}
			fclose(fi);	
			pickSequence(L);
			while(w<2){
				if(jump==0){
					ass(L);
					jump=1;
				}
				else
					copy(L);
				w=w+1;	
			}
			char *nom1,*nom2,*seq1,*seq2,*nb1,*nb2,*seq3,*seq4,*seq0;
			nom1=(char*)malloc(sizeof(char));
			seq1=(char*)malloc(MX*sizeof(char));
			int lo1,mo1=0;
			int lo2,mo2=0;
			int i1=0,n1,j1=0,i2=0,n2,j2=0,occ=0;
			listeSequence1 L1,p1,ind1;
			L1=NULL;
			file1=fopen("resultat1'.txt","r");
			while(fscanf(file1,"%s",nom1)!=EOF){
				i1=i1+1;
			}
			n1=i1;
			fclose(file1);
			file1=fopen("resultat1'.txt","r");
			nb1=(char*)malloc(10000*sizeof(char));
			for(i1=0;i1<n1;i1++){
				fscanf(file1,"%s",nb1);
				if(i1%2==0){
					lo1=atoi(nb1);
					tab1[j1]=lo1;
					j1++;
					occ=0;
					while(mo1<j1){
						if(tab1[mo1]==lo1){
							occ+=1;
						}
						mo1++;
					}
				}
				mo1=0;
				if((i1%2!=0) && (occ==1)){
					L1=insererSequence1(importSequence1(nb1),L1);
				}
			}
			fclose(file1);
			remove("resultat1'.txt");
			p1=L1;
			seq1=fusion1(p1->infos->seq,p1->suivant->infos->seq);
			supprimerSequence1(&p1,p1->infos->seq);
			supprimerSequence1(&p1,p1->infos->seq);
			ind1=p1;
			while(ind1!=NULL){
				seq1=fusion1(seq1,p1->infos->seq);
				supprimerSequence1(&p1,p1->infos->seq);
				ind1=p1;
			}
			
			nom2=(char*)malloc(sizeof(char));
			occ=0;
			file2=fopen("resultat2'.txt","r");
			while(fscanf(file2,"%s",nom2)!=EOF){
				i2=i2+1;
			}
			n2=i2;
			fclose(file2);
			tab2=(int*)malloc(sizeof(int));
			file2=fopen("resultat2'.txt","r");
			nb2=(char*)malloc(10000*sizeof(char));
			listeSequence1 L2,p2,ind2;
			L2=NULL;
			p2=NULL;
			ind2=NULL;
			for(i2=0;i2<n2;i2++){
				fscanf(file2,"%s",nb2);
				if(i2%2==0){
					lo2=atoi(nb2);
					tab2[j2]=lo2;
					j2++;
					occ=0;
					while(mo2<j2){
						if(tab2[mo2]==lo2){
							occ+=1;
						}
						mo2++;
					}
				}
				mo2=0;
				if((i2%2!=0) && (occ==1)){
					L2=insererSequence2(importSequence1(nb2),L2);
				}
			}
			fclose(file2);
			remove("resultat2'.txt");
			seq2=(char*)malloc(MX*sizeof(char));
			p2=L2;
			seq2=fusion2(p2->infos->seq,p2->suivant->infos->seq);
			supprimerSequence1(&p2,p2->infos->seq);
			supprimerSequence1(&p2,p2->infos->seq);
			ind2=p2;
			while(ind2!=NULL){
				seq2=fusion2(seq2,p2->infos->seq);
				supprimerSequence1(&p2,p2->infos->seq);
				ind2=p2;
			}
		
			FILE *fi1;
			FILE *fi2;
			int z=0,e=0;
			seq3=(char*)malloc(MX*sizeof(char));
			fi1=fopen("resultat2T.txt","r");
			fscanf(fi1,"%s",seq3);
			fclose(fi1);
			remove("resultat2T.txt");
			seq0=(char*)malloc(MX*sizeof(char));
			while(seq3[z]!='\0'){
				if((seq3[z]=='A') || (seq3[z]=='C') || (seq3[z]=='G') || (seq3[z]=='T')){
					seq0[e]=seq3[z];
					e++;
				}
				z++;
			}
			free(seq3);
			seq4=(char*)malloc(MX*sizeof(char));
			fi2=fopen("resultat1T.txt","r");
			fscanf(fi2,"%s",seq4);
			fclose(fi2);
			remove("resultat1T.txt");
			fusion3(seq0,seq4);
			if(choix1==0){
				printf("\033[0;36m");
				printf("Le résultat est dans un fichier dans le même dossier sous le nom:'resultatT.txt'\nSi vous voulez chercher une souche bactérienne dans ce génome entrer 1.\nSi vous voulez quitter entrer 2\nsinon un autre numéro.\n");
				printf("\033[0;36m");
				scanf("%d",&choix1);
			}
			if(choix1==1){
				FILE *file3;
				char *seq9,*souche;
				seq9=(char*)malloc(MX*sizeof(char));
				souche=(char*)malloc(MX*sizeof(char));
				file3=fopen("resultT.txt","r");
				fscanf(file3,"%s",seq9);
				printf("entrer votre souche:\n");
				scanf("%s",souche);
				recherch(seq9,souche);
				printf("Si vous voulez quitter le programme entrer 2.\nSi vous voulez revenir au menu principal entrer 1.\n");
				scanf("%d",&choix1);
			}
		}
		else{
			if((choix1==1) && (choix2==1)){
				char *nom3;
				nom3=(char*)malloc(sizeof(char));
				printf("Entrer le nom du fichier:\n");
				scanf("%s",nom3);
				FILE *file4;
				char *seq8,*souch;
				seq8=(char*)malloc(MX*sizeof(char));
				souch=(char*)malloc(MX*sizeof(char));
				file4=fopen(nom3,"r");
				fscanf(file4,"%s",seq8);
				printf("entrer votre souche:\n");
				scanf("%s",souch);
				recherch(seq8,souch);
				printf("Si vous voulez quitter le programme entrer 2.\nSi vous voulez revenir au menu principal entrer 1.\n");
				scanf("%d",&choix1);
			}
		}
	}
	printf("Vous êtes déconnecter.\n");
	return 0;
}