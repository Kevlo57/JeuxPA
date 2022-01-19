#include "Orc.h"

Orc::Orc(){
	
}

Orc::Orc(double x,double y){
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

Orc::~Orc(){
	delete rect;
}

int Orc::GetPV(){
	return pv;
}

double Orc::GetPosX(){
	return posX;
}
double Orc::GetPosY(){
	return posY;
}

double Orc::GetVX(){
	return vX;
}

double Orc::GetVY(){
	return vY;
}

double Orc::GetVitesseMin(){
	return vitesseMin;
}

double Orc::GetCoeffDeceleration(){
	return coeffDeceleration;
}

double Orc::GetAcceleration(){
	return acceleration;
}

SDL_Rect* Orc::GetRect(){
	return rect;
}

void Orc::Affichage(){
	std::cout << "Orc : " << std::endl;
	std::cout << "posX = " << posX << std::endl;
	std::cout << "posY = " << posY << std::endl;
	std::cout << "vX = " << vX << std::endl;
	std::cout << "vY = " << vY << std::endl;
}





