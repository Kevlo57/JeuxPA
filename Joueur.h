#ifndef DEF_JOUEUR_H
#define DEF_JOUEUR_H

#include <iostream>
#include <SDL2/SDL.h>

class Joueur{
protected:
	char nom[20];
	int pv; 
	double posX; 
	double posY; 
	double vX; 
	double vY; 
	double vitesseMin; 
	double coeffDeceleration; 
	double acceleration; 
	SDL_Rect* rect;
public:
	Joueur();
	Joueur(double x, double y);
	~Joueur();

	int GetPV();
	double GetPosX();
	double GetPosY();
	double GetVX();
	double GetVY();
	double GetVitesseMax();
	double GetCoeffDeceleration();
	double GetAcceleration();
	SDL_Rect* GetRect();
	void Affichage();
};


#endif
