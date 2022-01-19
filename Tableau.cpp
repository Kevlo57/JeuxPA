#include "Tableau.h"

Tableau::Tableau(){
	gauche = NULL;
	droite = NULL;
}

Tableau::~Tableau(){

}

Tableau* Tableau::GetGauche(){
	return gauche;
}

Tableau* Tableau::GetDroite(){
	return droite;
}






