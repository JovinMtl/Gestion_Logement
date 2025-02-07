int compl(struct liste * L);
void affich(struct liste * L);
void init(struct liste * L);
void info(struct eleve * L);
int suppr(struct liste * L, int i);
int mod(struct liste * l,int i);
int ajout(struct liste * L, int i);
int init_lo(struct listel* l);
void show(struct listel* l);
void init_el(struct eleve * l);
void init_l(struct loge *l);
void chech(struct liste *l, struct listel *L);
int bour();
void mkrm(int m,struct loge *l);
void expor(struct liste * L);
int auth(); //permet la connexion par mot de passe
int chpw(); //permet de changer l'ancien mot de passe
void connexion();
int menu(struct liste *l, struct listel *L);
void fich_e(struct liste * l);
int log_pr();
int mod_l(struct listel * l,struct liste * L);
void ren_l(struct loge * L,struct liste *l);
void rm_l(struct loge * L);
int aj_l(struct loge * L);
int cherch(struct liste * L);
void ma(struct liste *L, char *p);
int aj_el(struct loge *l,struct liste *L);

int compl(struct liste * L){
	int c=0;
	if(L->premier==NULL){
		L->nouveau=(struct eleve *)malloc(sizeof(struct eleve));
		L->nouveau->precedent=NULL;
		init_el(L->nouveau);
		L->nouveau->suivant=NULL;
		L->premier=L->courant=L->nouveau;
		info(L->courant);
	}
	L->courant=L->premier;
	while(L->courant->suivant==NULL){
		L->nouveau=(struct eleve *)malloc(sizeof(struct eleve));
		if(L->nouveau!=NULL){
			L->nouveau->precedent=L->courant;
			init_el(L->nouveau);
			L->nouveau->suivant=NULL;
//			L->nouveau->numero=c+1;
			L->courant->suivant=L->nouveau;
			L->courant=L->courant->suivant;
			info(L->courant);
			printf("\nVoulez-vous recommencez ? 0 - 1");
			scanf("%d",&c);
			if(c != 0){
				continue;
			}
			else {
				return 1;
			}
		}
		else {
			printf("Memoire non alloue !!\n");
		}

	}
	return 0;
}
void affich(struct liste * L){
	//cette fonction permet d'afficher la liste des etudiant
	// soit sur la liste d'attente ou sur la liste complete
	int j=0; // variable compteur
	L->courant=L->premier;
	while(L->courant !=NULL){
//		printf("\n %d ==> %d",j,L->courant);
        printf("\n %d. %s %s",j,L->courant->nom,L->courant->pren);
//		printf("\tVotre nom vaut %s",L->courant->nom);
		L->courant=L->courant->suivant; //l'element courant passe a l'elemet suivant
		j++; // incrementation de la variable compteur
	}
	printf("\nAFFICHAGE FINI !!\nVous avez %d elements\n",j);
}
void init(struct liste * L){
	// initialisation de la liste des etudiant
	L->premier=NULL;
	L->courant=NULL;
	L->nouveau=NULL;
}
int suppr(struct liste * L, int i){
	//suppression de l'etudiant dans la liste
	int j=0;
	L->courant=L->premier;
	while(L->courant !=NULL){
		if(j==i){
			L->courant->precedent->suivant=L->courant->suivant;
			free(L->courant);
			printf("\nSuppression avec Succes !!!!!\n");
			return 1;
		}
		L->courant=L->courant->suivant;
		j++;
	}
}
void info(struct eleve *L){
	init_el(L);
	int i=0;
	printf("\nENTREZ l'ID de l'etudiant");
	scanf("%s",L->id);
	printf("\tENTREZ est le nom pour %s    ? : ",L->id);
	scanf("%s",L->nom);
	printf("\nEntrez le prenom pour %s  :",L->id);
	scanf("%s",L->pren);
	L->bourse=bour();
/*	printf("\nVotre nom est %s\n",L->nom);
	printf("\n et VOtre Id est %s",L->id);
	printf("\tquelle est la chambre preferentiel pour %s  (0-4)    ",L->id);
	scanf("%d",&i); */
	i=log_pr();
	L->room=(ty_ro)i;
}
int mod(struct liste * l,int i){
	int j=0;
	struct eleve *nouv;
	l->courant=l->premier;
	do{
		if(j==i){
                nouv=l->courant->suivant;
			printf("\nVous etes sur le point de modifier : %s",l->courant->nom);
		/*	printf("\nQuelle est votre nouveau nom? ");
			scanf("%s",l->courant->nom);
			printf("\nVotre nouveau nom est %s",l->courant->nom);*/
			info(l->courant);
			l->courant->suivant=nouv;
			printf("fini la modification");
			break;
		}
		l->courant=l->courant->suivant;
		j++;
	}while(l->courant !=NULL);
}
void expor(struct liste * L){
	L->courant=L->premier;
	int j=0;
//	mkdir("jovin");
	FILE * p=NULL;
	p=fopen("list.txt","a+");
	do{
		fprintf(p,"%s %s %s %d %d %d %p %p\n",L->courant->nom,L->courant->pren,L->courant->id,L->courant->bourse,L->courant->state,L->courant->room,L->courant->precedent,L->courant->suivant);
		L->courant=L->courant->suivant;
		j++;
	}while(L->courant!=NULL);
	fclose(p);
}
int ajout(struct liste * L, int i){
    printf(".... veuillez patientez ....");
    L->courant=L->premier;
    int j=0;
    while(L->courant != NULL){
    if(j==i){
        L->nouveau=(struct eleve *) malloc(sizeof(struct eleve));
        if(L->nouveau != NULL){
            printf("Memoire alloue avec succes!!!");
            L->nouveau->precedent=L->courant;
            L->nouveau->suivant=L->courant->suivant;
            L->courant->suivant=L->nouveau;
            L->courant=L->nouveau;
            info(L->courant);
            return 1;
        }
        else {
            printf("Allocation echoue !!!!!");
        }
    }
        L->courant=L->courant->suivant;
        j++;
    }
}
int init_lo(struct listel *l){ //logem.c
	l->premier=NULL;//initialisation de la liste
	l->courant=NULL;
	l->nouveau=NULL;
	debut : ;
	l->num=0;//fin d'initialisation
	void* a; //pointeur qui permet de copier du chaine
	int i=0;
	char b[4]="cha";
	char *c=b;  //pointeur vers chaine comme ID pour chambre
	int j,k=0;
	a=&k;
	k=48; //variable caractere qui permettra de nommer la chambre pour ID
	printf("\nentrez le nombre de logement pour Appartement %c \t",k);
	scanf("%d",&i);
	if(i<1){
		printf("\n L'appartement doit avoir 1 ou 2 chambres au minimum !!");
		goto debut;
	}
	for(j=0;j<i;j++){
		if(j==0){
			l->nouveau=(struct loge *) malloc(sizeof(struct loge));
			if(l->nouveau != NULL){
				printf("\nAllocation memoire Reussi");
				l->nouveau->precedent=NULL;
				init_l(l->nouveau);
				l->nouveau->suivant=NULL;
				l->nouveau->numero=j+1; // le numero du batiment vaut la valeur compteur de j
				strcpy(l->nouveau->id,c);// *c dans l->nouveau->id
				strcat(l->nouveau->id,a);// *a dans l->nouveau->id
//				l->nouveau->state=0;   // chambre est disponible
				l->nouveau->room=0;  // type chambre vaut 0 comme il est le premier
				l->nouveau->bat='A';   // le nom du batiment
//				strcpy(l->nouveau->id,a);
				l->premier=l->courant=l->nouveau; // le premier,le courant vaut ce nouveau element
				k++;
				continue;
				}
			else {
				printf("Allocation memoire echouee !!!\n");	// affiche ceci en cas d'echec
				return 5;
				}
			}
		else {
		       l->nouveau=(struct loge*)malloc(sizeof(struct loge));
		       if(l->nouveau != NULL){
		       	printf("\nAllocation memoire REUSSI !!");
		       	l->nouveau->precedent=l->courant;
		       	init_l(l->nouveau);
		       	l->nouveau->suivant=NULL;
//		       	l->nouveau->state=0;
		       	l->nouveau->bat='A';
		       	strcpy(l->nouveau->id,c); //le ID de la chambre vaut
		       	strcat(l->nouveau->id,a); // la concantenation des pointeurs c et a
		       	mkrm(i,l->nouveau); // definition du type pour chaque chambre
		       	l->nouveau->numero=j+1;
		       	l->nouveau->precedent=l->courant;
		       	l->courant->suivant=l->nouveau; // element courant de la liste passe a l'element nouveau
				l->courant=l->nouveau;
		       	k++;
		       	continue;
		       	}
		       else{
		       	printf("Allocation memoire echoue !!!"); // en cas de saturation memoire
		       	return 6;
		       	}
		}
		j++;
		}
	return 0;
	}

void show(struct listel *l ){ // logem.c
	printf("\nthis is the list of the rooms\n");
	struct eleve* k;
//	char *k;
//	k=l->courant->etudiant->nom;
	l->courant=l->premier; //l->courant commence par le premier element
	while(l->courant != NULL) {
//		printf("\n%d Adresse %p contient id comme %s\t type %d",l->courant->numero,l->courant,l->courant->id,l->courant->room);
//		printf("cette adresse est occupe de %d",l->courant->etudiant);
		k=(struct eleve *)l->courant->etudiant;
		printf("\nChambre numero %d a pour ID: %s est occupe de %s",l->courant->numero,(char *)l->courant->id,(char *)k);
		l->courant=l->courant->suivant; // l->courant passe a l'element suivant de la liste
//		printf("cette adresse est occupe de %s",l->courant->etudiant->nom);
//		k=l->courant->etudiant->nom;
		}
}
void mkrm(int m,struct loge *l){ //logem.c
	// cette fonction permet la definition du type de chambre
	static int k=1;
	l->state=0;  // mise en disponibilite de la chambre
//	k=m/4;
	if(k<(m/4)) // pendant le premier quart du nombre
			{
				l->room=chambre;
			}
	else if((k>=(m/4)) && (k<=((m/4)*2))) // pendant le deuxieme quart du nombre
			{
				l->room=studio;
			}
	else if ((k>=((m/4)*2)) && (k<=((m/4)*3))) //pendant le troisieme quart du nombre
			{
				l->room=T1;
			}
	else  // pendant le reste
			{
				l->room=T2;
			}
	k++;
	end : ;
}
void init_el(struct eleve *l){
	strcpy(l->id,"");
	strcpy(l->nom,"");
	strcpy(l->pren,"");
	l->bourse=0;
	l->state=0;
	l->room=chambre;
	l->suivant=NULL;
}
void init_l(struct loge *l){
	l->etudiant=NULL;
	l->numero=0;
	l->room=chambre;
	l->state=0;
	l->bat='A';
	l->suivant=NULL;
	strcpy(l->id,"");
}
void check(struct listel *l, struct liste *L){
//	l->courant=NULL;
	l->courant=l->premier;
	int k;
	L->courant=L->premier;
	debut : ;
	for(l->courant=l->courant;l->courant != NULL;l->courant=l->courant->suivant){
		if(l->courant->state==0){
			printf("\ncette chambre %s est disponible",l->courant->id);
			for(L->courant=L->courant;L->courant != NULL;L->courant=L->courant->suivant){
				k=L->courant->room;
				if(l->courant->state==1){
                        continue;
                }
				else {
				printf("cette eleve prefere %d\n",k);
//				printf("etudiant %s prefere la chambre %d",L->courant->id,L->courant->room);
				if(l->courant->room==k){ //si le type de la chambre correspon
				// au type preferentiel de l'etudiant
					printf("etudiant %s prefere la chambre %d",L->courant->id,L->courant->room);
					l->courant->etudiant=L->courant;
					L->courant->state=1;
					printf("\netudiant %s est dans chambre %s",L->courant->nom,l->courant->id);
					l->courant->state=1;
					L->courant->state=1;
					L->courant=L->courant->suivant;
//					break;
					goto debut;
				}
				else {
					break;
				}
				continue;
			}
			}
		}
		continue;
	}
	printf("\n!!! fini la verification  !!!\n");
}

int bour(){
	int i=0;
	debut : ;
	printf("\nQuelle est votre bourse  ? :");
	scanf("%d",&i);
	if((i<=7)&&(i>=0)){
		return i;
	}
	else {
		printf("cette bourse est invalide!!! \t ( la bourse varie entre 0 et 7)");
		goto debut;
	}
}
int auth(){
	int i=0;
	char car;
	char mop[7]={0};
//	debut : ;
	printf("\n Votre mot de passe ( 7 caracteres ) : -------\b\b\b\b\b\b\b");
	for(i=0;i<7;i++){
		mop[i]=getchar();
		putchar('*');
	}
	printf("\nVotre mot de passe est %s ",mop);
	p_pw=fopen("secure.dat","r");
	if(p_pw){
		printf("OUVERTURE REUSSI\n");
		for(i=0;i<5;i++){
			car=fgetc(p_pw);
			if(car != mop[i]){
				break;
			}
		}
		if(i != 5){
			printf("Ce mot de passe est incorrecte !!!!\n");
			return 1;
			//goto debut;
		}
		else {
			printf("VOUS avez bien trouve le mot de passe\n");
			return 0;
		}
	}
	else {
		printf("OUVERTURE ECHOUE\n");
		return 1;
	}
}
int chpw(){
	int r,i=0;
	char mop[6];
	r=auth();
	if(r==0){
		p_pw=fopen("secure.dat","w+");
		printf("\n Votre Nouveau mot de passe ( 7 caracteres ) : -------\b\b\b\b\b\b\b");
		for(i=0;i<7;i++){
			mop[i]=getc(p_pw);
			putchar('*');
		}
		fputs(mop,p_pw);
		fclose(p_pw);
	}
}
void connexion(){
int k,i=0;
	debut : ;
	k=auth();
	if(k!=0){
		i++;
		if(i<3)goto debut;
		else {
			printf("\n Vous n'avez pas le droit de se connecter comme Administrateur !!\n");
			printf("\n\tFIN DE PROGRAMME !!!!\n");
			exit(0);
		}
	}
}
int menu(struct liste *L, struct listel *l){
    int a=0;
    int e,g=0;
    e=130;
    g=138;
    debut : ;
    system("cls");
    printf("\nGESTION DES ETUDIANTS ET DE DEMANDE DE LOGEMENT \n-----------------------------------------------\n");
    printf("\n\n\t MENU\n\t ----\n\n");
    printf("1.  Ajouter un %ctudiant\n",e);
    printf("2.  Modifier un %ctudiant\n",e);
    printf("3.  Supprimer un %ctudiant\n",e);
    printf("4.  Exporter la liste des %ctudiands\n",e);
    printf("5.  Actualiser\n");
    printf("6.  Afficher les chambres \"dispo OU occup%c\"\n",e);
    printf("7.  Afficher la liste des %ctudiants\n",e);
    printf("8.  Produire les fiches des %ctudiants\n",e);
    printf("9.  Ajouter / Supprimer / Modifier  une Chambre\n");
    printf("10. Rechercher un %ctudiant selon les crit%cres\n",e,g);
    printf("11. Ajouter /Supprimer / Modifier un Enseignant Ou Utisateur\n");
    printf("12. Afficher les %ctudiants qui sont sur Liste d'attente\n",e);
    printf("13. Charger la liste des %ctudiants\n", 111);
    printf("14. Changer le Mot de Passe\n");
    printf("15. Quitter le programme ");
    printf("\nQuelle est votre choix :  ");
    scanf("%d",&a);
    if(a==1){
            int i=0;
            affich(L);
            printf("Entrez la position %c inserer : ",133);
            scanf("%d",&i);
            ajout(L,i);
            system("pause>ASCII");

        }
    else if(a==2){
            int i=0;
            affich(L);
            printf("Entrez la position de l'%cl%cve %c modifier : ",e,g,133);
            scanf("%d",&i);
            mod(L,i);
            system("pause>ASCII");
        }
    else if(a==3){
            int i=0;
            affich(L);
            printf("Entrez la position de l'%cl%cve %c supprimer : ",e,g,133);
            scanf("%d",&i);
            suppr(L,i);
            system("pause>ASCII");
        }
    else if(a==4){
            expor(L);
            system("pause>ASCII");
        }
    else if(a==5){
            check(l,L);
            system("pause>ASCII");
        }
    else if(a==6){
    		show(l);
    		system("pause>ASCII");
		}
    else if(a==7){
            affich(L);
            system("pause>ASCII");
        }
    else if(a==8){
            fich_e(L);
            system("pause>ASCII");
        }
    else if(a==9){
            mod_l(l,L);
            system("pause>ASCII");
    }
    else if(a==10){
        cherch(L);
        system("pause>ASCII");
    }
    else if(a==14){
    	chpw();
	}
    else if(a==15){
        exit(1);
    }
    else{
            printf("Votre choix est invalide !!!!\n");
            system("pause>ASCII");
        }
    goto debut;
}
void fich_e(struct liste * l){  // permet de produire le fiche des etudiants
	printf(" _______________________________________________________");
	printf("\n%c NOM\t\t%c PRENOM\t%cID\t%cBOURSE\t%cL.Pref\t%c\n",179,179,179,179,179,179);
	printf("%c_______________%c_______________%c_______%c_______%c_______%c\n",179,179,179,179,179,179);
	l->courant=l->premier; // element courant commence a etre le premier dans la liste
	while(l->courant != NULL){
		printf("%c%s\t%c%s\t%c%s\t%c%d\t%c%d\t%c\n",179,l->courant->nom,179,l->courant->pren,179,l->courant->id,179,l->courant->bourse,179,l->courant->room,179);
		l->courant=l->courant->suivant;
	}
	printf("%c_______________%c_______________%c_______%c_______%c_______%c\n",179,179,179,179,179,179);
	printf("\nFin\n");
}
int log_pr(){ // permet de recuperer la valeur du logement preferenciel
    m : ;
    int k=0;
    printf("\nQuelle est le logement preferentiel ? (0-3) : ");
    scanf("%d",&k);
    if((k<=3) && (k>=0)){
        return (ty_ro)k;
    }
    else {
        printf("\nCe Choix est invalide !!!  \"( 0 - 3) \"");
        goto m;
    }
}
int mod_l(struct listel * l,struct liste *L){
    int i,j=0;
    debut : ;
    printf("1. Supprimer une chambre\n2. Modifier une chambre\n3. Ajouter une chambre\n4. Retour");
    printf("\n\nQuelle est votre choix pour Chambre ? : ");
    scanf("%d",&i);
    //show(l); //afficher tous les chambres
    printf("\nEntrez le numero de la chambre : ");
    scanf("%d",&j);
    l->courant=l->premier;
    while(l->courant != NULL){
        if(l->courant->numero==j){
            if(i==1){
                rm_l(l->courant);
            }
            else if(i==2){
                ren_l(l->courant,L);
            }
            else if(i==3){
                aj_l(l->courant);
            }
            else if(i==4){
                return 1;
            }
            else {
                printf("Ce choix est invalide !!\n");
                goto debut;
            }
            return 1;
        }
        l->courant=l->courant->suivant;
    }
}

void rm_l(struct loge * L){
    L->suivant->precedent=L->precedent;
    L->precedent->suivant=L->suivant;
    free(L);
    printf("Suppression avec Success !!!");
}
void ren_l(struct loge * L,struct liste *l){
    char id[5];
    int a=0;
    printf("\nID : %s\tEntrez le nouveau ID pour cette chambre :",L->id);
    scanf("%s",L->id);
//    strcpy(L->id,id);
    printf("\nType : %d\tEntres le nouveau Type  : ",L->room);
    scanf("%s",&L->room);
    a=aj_el(L,l);
    if(a==5){
    	printf("\nFini la modification !!");
	}
}
int aj_l(struct loge * L){
    struct loge *nouveau;
    nouveau=(struct loge *)malloc(sizeof(struct loge));
    init_l(nouveau);
    nouveau->precedent=L;
    nouveau->suivant=L->suivant;
    L->suivant=nouveau;
    return 1;
}
int cherch(struct liste * L){
    //char *p[15];
    char chaine[15];
    //p=&chaine;
    int i,j=0;
    debut : ;
    printf("\n\tVoici les criteres de recherche\n\t---------------------------\n");
    printf("1. ID\n");
    printf("2. Nom\n");
    printf("3. Prenom\n");
    printf("4. Chambre Preferentielle\n");
    printf("5. Bourse\n");
    printf("6. Liste d'attente\n");
    printf("7. Retour\n");
    printf("Quelle est votre choix : ");
    scanf("%d",&i);
    if(i==1){
        printf("\nEntrez l'Id de chercher ");
        scanf("%s",chaine);
        system("pause>ASCII");
        //strcpy(p,chaine);
        //system("pause");
        printf("\t On cherche %s",chaine);
        ma(L,chaine);
    }
    else if(i==2){
        printf("\nEntrez le nom %c chercher : ",138);
        scanf("%s",chaine);
        ma(L,chaine);
    }
    else if(i==3){
        printf("\nEntrez le prenom %c chercher : ",138);
        scanf("%s",chaine);
        ma(L,chaine);
    }
    else if(i==4){
        printf("\nEntrez le L.Pref %c chercher : ",138);
        scanf("%s",chaine);
        ma(L,chaine);
    }
    else if(i==5){
        printf("\nEntrez la bourse %c chercher : ",138);
        scanf("%s",chaine);
        ma(L,chaine);
    }
    else if(i==6){
        char a=48;
        ma(L,&a);
    }
    else if(i==7){
        return 1;
    }
    else {
        goto debut;
    }

}
void ma(struct liste *L,char *p){ //permet de trouver la correspondance du chaine de caractere dans la liste
    int c=0;
    if(strlen(p)==1){
        printf("C'est un nombre");
        system("pause");
        c=*p;
        c=c-48;
        printf("\nVotre nombre vaut %d",c);
    }
    int i,k=0;
    int n,pr,m=0;
    L->courant=L->premier;
    printf("Voici les resultats trouv%c : \n\n",130);
    printf(" _______________________________________________________");
	printf("\n%c NOM\t\t%c PRENOM\t%cID\t%cBOURSE\t%cL.Pref\t%c\n",179,179,179,179,179,179);
	printf("%c_______________%c_______________%c_______%c_______%c_______%c\n",179,179,179,179,179,179);
    do{
        i=strcmp(L->courant->id,p);
        n=strcmp(L->courant->nom,p);
        pr=strcmp(L->courant->pren,p);
        if((i==0) || (L->courant->bourse==c)){
             printf("%c%s\t%c%s\t%c%s\t%c%d\t%c%d\t%c\n",179,L->courant->nom,179,L->courant->pren,179,L->courant->id,179,L->courant->bourse,179,L->courant->room,179);
		k++;
        }
        else if((n==0) || (pr==0)){
             printf("%c%s\t%c%s\t%c%s\t%c%d\t%c%d\t%c\n",179,L->courant->nom,179,L->courant->pren,179,L->courant->id,179,L->courant->bourse,179,L->courant->room,179);
		     k++;
        }
        else if(L->courant->state==0){
            printf("%c%s\t%c%s\t%c%s\t%c%d\t%c%d\t%c\n",179,L->courant->nom,179,L->courant->pren,179,L->courant->id,179,L->courant->bourse,179,L->courant->room,179);
		     k++;
        }
        L->courant=L->courant->suivant; // element courant passe a l'element suivant
        }while(L->courant != NULL);
        printf("%c_______________%c_______________%c_______%c_______%c_______%c\n",179,179,179,179,179,179);
        printf("\nNous avons trouv%c %d element!!",130,k);
    }
int aj_el(struct loge *l,struct liste *L){
    	char chaine[15];
    	int i=0; //permet de stocker la valeur de la comparaison entre deux chaines de caractere
    	L->courant=L->premier;
    	printf("\nQuelle est le nom de l'etudiant a attribuer ce chambre ?: ");
    	scanf("%s",chaine);
    	while(L->courant != NULL){
    		i=strcmp(L->courant->nom,chaine);
    		if(i==0){
    			l->etudiant=L->courant;
    			L->courant->state=1;
    			printf("\nDesorm%c, %s est maintenant dans %s",130,L->courant->id,l->id);
    			return 5;
			}
			L->courant=L->courant->suivant;
		}
	}
