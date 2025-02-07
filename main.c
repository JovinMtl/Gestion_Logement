#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"const.h"
#include"defunct.h"
// date : 1 octobre 2017
int main(){
	connexion();
	struct liste * L; //liste pour etudiant
	struct  listel * l; //liste pour logement
	L=(struct liste *)malloc(sizeof(struct liste));
	l=(struct listel *) malloc(sizeof(struct loge));
	init(L); //initialisation de la liste pour etudiant
	init_lo(l); //initialisation de la liste pour logement
	compl(L); // permet d'etablir la liste des etudiant
	menu(L,l);
	return 0;
}
