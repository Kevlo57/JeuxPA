#ifndef DEF_JOUEUR_H
#define DEF_JOUEUR_H

#include <iostream>
#include <SDL2/SDL.h>

class Joueur{
protected:
	int pv; 
	double posX; 
	double posY; 
	double acceleration;
	double vitesseMax;
	double vX; 
	double vY; 
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
	SDL_Rect* GetRect();
	void Move(bool z, bool q, bool s, bool d);
	void MoveUp();
	void MoveDown();
	void MoveRight();
	void MoveLeft();
	void Affichage();
};


#endif
