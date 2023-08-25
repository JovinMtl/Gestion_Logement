enum ty_ro{
	chambre,studio,T1,T2
};
typedef enum ty_ro ty_ro;
struct eleve {
	char id[5];
	char nom[15];
	char pren[10];
	int bourse;
	int state;
	ty_ro room;
	struct eleve * precedent;
	struct eleve * suivant;
};
struct loge {
	char id[5];
	void* etudiant;
	int numero;
	int state;
	ty_ro room;
	char bat;
	struct loge * suivant;
	struct loge * precedent;
};
struct listel {
	struct loge * premier;
	struct loge * courant;
	struct loge * nouveau;
	int num;
};

struct liste {
	struct eleve * premier;
	struct eleve * courant;
	struct eleve * nouveau;
};
FILE* p_pw=NULL;
