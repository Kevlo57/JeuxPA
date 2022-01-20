#include "Monde.h"

Monde::Monde(){
	joueur = new Joueur(30.0,764.0);
	ennemi = new Ennemi(900.0,724.0);
}

Monde::~Monde(){
	delete joueur;
	delete ennemi;
}

Joueur* Monde::GetJoueur(){
	return joueur;
}

Ennemi* Monde::GetEnnemi(){
	return ennemi;
}






