#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Malloc(type) (type*)malloc(sizeof(type))




typedef struct {
	char seq[220]; //la séquence
	int nbseq; //numéro de la séquance
	int maxChev; //le numéro de la séquence avec laquelle elle a le plus de chevauchement
}sequence;

typedef struct _noeud {
	sequence *infos;
	struct _noeud *suivant;
}noeud;

typedef noeud *listeSequence;


sequence* importSequence(char *nom, int i);

listeSequence insererSequence(sequence *seq,listeSequence liste);

int len(char *seq);

void afficherSequences(listeSequence liste);

int chevauchement(char *seq1,char *seq2,int lenseq);

int maxChevauchement(char *seq,listeSequence liste);

void supprimerSequence(listeSequence *l,char *nom);

void pickSequence(listeSequence liste);

void fusion(char *seq1,char *seq2,char *seq);

int assembler(listeSequence liste,char *seqq,int chevv);

void ass(listeSequence liste);

void copy(listeSequence liste);





