#ifndef DEF_JOUEUR_H
#define DEF_JOUEUR_H

#include <iostream>
#include <SDL2/SDL.h>

class Joueur{
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
	bool jump;
	bool fall; 
	double fallAcceleration;
	double jumpAcceleration;
	double jumpDeceleration;
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
	void Update();
	void UpdateSpeed();
	void UpdatePos();
	void UpdateRect();
	void MoveRight();
	void MoveLeft();
	void TestFalling();
	void TestJumping();
	void SetFall(bool f);
	void SetJump(bool j);
	void Affichage();
};


#endif
