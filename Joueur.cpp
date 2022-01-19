#include "Joueur.h"

Joueur::Joueur(){
	
}

Joueur::Joueur(double x,double y){
	pv = 3;
	posX = x;
	posY = y;
	acceleration = 15;
	vX = 0;
	vY = 0;
	vitesseMax = 15;
	rect = new SDL_Rect;
	rect->x = posX;
	rect->y = posY;
	rect->w = 600;
	rect->h = 450;
}

Joueur::~Joueur(){
	delete rect;
}

int Joueur::GetPV(){
	return pv;
}

double Joueur::GetPosX(){
	return posX;
}
double Joueur::GetPosY(){
	return posY;
}

double Joueur::GetVX(){
	return vX;
}

double Joueur::GetVY(){
	return vY;
}

SDL_Rect* Joueur::GetRect(){
	return rect;
}

void Joueur::Move(bool z, bool q, bool s, bool d){
	if(z && d){
		MoveUp();
		MoveRight();
	}else if(z && q){
		MoveUp();
		MoveLeft();
	}else if(s && q){
		MoveDown();
		MoveLeft();
	}else if(s && d){
		MoveDown();
		MoveRight();
	}else if(z && !q && !d){
		MoveUp();
	}else if(s && !q && !d){
		MoveDown();
	}else if(d && !s && !z){
		MoveRight();
	}else if(q && !s && !z){
		MoveLeft();
	}
}

void Joueur::MoveUp(){
	if(vY>0){
		vY = 0;
	}
	if(vY>-vitesseMax){
		vY -= acceleration;
		posY += vY;
		rect->y = posY;
	}else{
		posY += vY;
		rect->y = posY;
	}
}

void Joueur::MoveDown(){
	if(vY<0){
		vY = 0;
	}
	if(vY<vitesseMax){
		vY += acceleration;
		posY += vY;
		rect->y = posY;
	}else{
		posY += vY;
		rect->y = posY;	
	}	
}

void Joueur::MoveRight(){
	if(vX<0){
		vX = 0;
	}
	if(vX<vitesseMax){
		vX += acceleration;
		posX += vX;
		rect->x = posX;
	}else{
		posX += vX;
		rect->x = posX;
	}
}

void Joueur::MoveLeft(){
	if(vX>0){
		vX = 0;
	}
	if(vX>-vitesseMax){
		vX -= acceleration;
		posX += vX;
		rect->x = posX;
	}else{
		posX += vX;
		rect->x = posX;
	}
}

void Joueur::Affichage(){
	std::cout << "Joueur : " << std::endl;
	std::cout << "posX = " << posX << std::endl;
	std::cout << "posY = " << posY << std::endl;
	std::cout << "vX = " << vX << std::endl;
	std::cout << "vY = " << vY << std::endl;
}





