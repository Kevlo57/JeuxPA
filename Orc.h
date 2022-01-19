#ifndef DEF_ORC_H
#define DEF_ORC_H

#include <iostream>
#include <SDL2/SDL.h>

class Orc{
protected:
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
	Orc();
	Orc(double x, double y);
	~Orc();

	int GetPV();
	double GetPosX();
	double GetPosY();
	double GetVX();
	double GetVY();
	double GetVitesseMin();
	double GetCoeffDeceleration();
	double GetAcceleration();
	SDL_Rect* GetRect();
	void Affichage();
};


#endif
