#ifndef DEF_ENNEMI_H
#define DEF_ENNEMI_H

#include <iostream>
#include <SDL2/SDL.h>

class Ennemi{
protected:
	int pv; 
	double posX; 
	double posY; 
	double vitesseMin;
	double vitesseMax;
	double coeffDeceleration;
	double acceleration;
	double vX; 
	double vY;
	SDL_Rect* rect;
public:
	Ennemi();
	Ennemi(double x, double y);
	~Ennemi();

	int GetPV();
	double GetPosX();
	double GetPosY();
	double GetVX();
	double GetVY();
	SDL_Rect* GetRect();
	void Update();
	void UpdateSpeed();
	void UpdatePos();
	void UpdateRect();
	void MoveRight();
	void MoveLeft();
	void Hurt();
	void Aggro(double x);
	void AffichageTerminal();
};


#endif
