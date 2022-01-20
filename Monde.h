#ifndef DEF_MONDE_H
#define DEF_MONDE_H

#include <iostream>
#include <SDL2/SDL.h>
#include "Ennemi.h"
#include "Joueur.h"

class Monde{
protected:
	Ennemi* ennemi;
	Joueur* joueur;
public:
	Monde();
	~Monde();

	Ennemi* GetEnnemi();
	Joueur* GetJoueur();
};
#endif
