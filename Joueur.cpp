#include "Joueur.h"

Joueur::Joueur(){
	
}

Joueur::Joueur(double x,double y){
	pv = 3;
	posX = x;
	posY = y;
	vX = 0;
	vY = 0;
	vitesseMin = 0.005;
	coeffDeceleration = 0.95;
	acceleration = 0.05;
	rect = new SDL_Rect;
}

Joueur::~Joueur(){
	delete rect;
}

void Joueur::Affichage(){
	std::cout << "Joueur : " << std::endl;
	std::cout << "posX = " << posX << std::endl;
	std::cout << "posY = " << posY << std::endl;
	std::cout << "vX = " << vX << std::endl;
	std::cout << "vY = " << vY << std::endl;
}





