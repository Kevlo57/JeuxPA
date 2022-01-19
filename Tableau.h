#ifndef DEF_TABLEAU_H
#define DEF_TABLEAU_H

#include <iostream>
#include <SDL2/SDL.h>
#include "Orc.h"

class Tableau{
protected:
	Tableau* gauche; 
	Tableau* droite; 
	Orc* tabOrc[];
public:
	Tableau();
	~Tableau();

	Tableau* GetGauche();
	Tableau* GetDroite();
};


#endif
