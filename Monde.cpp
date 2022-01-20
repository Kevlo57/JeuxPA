#include "Monde.h"

Monde::Monde(){
	nb_ennemi = 1;
	joueur = new Joueur(30.0,764.0);
	tableauActuel = 0;
	tabEnnemi = (Ennemi**) malloc(sizeof(Ennemi*)*nb_ennemi);
	/*
	for(int i=0;i<nb_ennemi;i++){
		tabEnnemi[i] = new Ennemi(...);	
	}
	*/

	tabEnnemi[0] = new Ennemi(900.0,724.0);
}

Monde::~Monde(){
	for(int i=0;i<nb_ennemi;i++){
		delete tabEnnemi[i];
	}
	free(tabEnnemi); 
	delete joueur;
}

Joueur* Monde::GetJoueur(){
	return joueur;
}

Ennemi* Monde::GetEnnemi(int indice){
	return tabEnnemi[indice];
}






