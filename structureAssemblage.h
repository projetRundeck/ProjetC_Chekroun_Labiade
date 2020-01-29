#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Malloc(type) (type*)malloc(sizeof(type))

typedef struct {
	char seq[220]; //la séquence
}sequence1;

typedef struct _noeud1 {
	sequence1 *infos;
	struct _noeud1 *suivant;
}noeud1;

typedef noeud1 *listeSequence1;

sequence1* importSequence1(char *nom);

void supprimerSequence1(listeSequence1 *l,char *nom);

listeSequence1 insererSequence2(sequence1 *seq,listeSequence1 liste);

listeSequence1 insererSequence1(sequence1 *seq,listeSequence1 liste);

char* fusion1(char *seq1,char *seq2);

char* fusion2(char *seq1,char *seq2);

void fusion3(char *seq1,char *seq2);