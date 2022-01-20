#include "Ennemi.h"

Ennemi::Ennemi(){
	
}

Ennemi::Ennemi(double x,double y){
	pv = 1;
	posX = x;
	posY = y;
	acceleration = 1;
	vX = 0;
	vY = 0;
	vitesseMin = 0.001;
	vitesseMax = 3;
	coeffDeceleration = 0.950;
	rect = new SDL_Rect;
	rect->x = posX;
	rect->y = posY;
	rect->w = 120;
	rect->h = 120;
}

Ennemi::~Ennemi(){
	delete rect;
}

int Ennemi::GetPV(){
	return pv;
}

double Ennemi::GetPosX(){
	return posX;
}
double Ennemi::GetPosY(){
	return posY;
}

double Ennemi::GetVX(){
	return vX;
}

double Ennemi::GetVY(){
	return vY;
}

SDL_Rect* Ennemi::GetRect(){
	return rect;
}

void Ennemi::MoveRight(){
	if(vX<vitesseMax){
		vX += acceleration;	
	}
}

void Ennemi::MoveLeft(){
	if(vX>-vitesseMax){
		vX -= acceleration;	
	}
}

void Ennemi::Update(){
	UpdateSpeed();
	UpdatePos();
	UpdateRect();
}

void Ennemi::UpdateSpeed(){
	if(vX<vitesseMin && vX>-vitesseMin){
		vX = 0;
	}else{
		vX *= coeffDeceleration;
	}
}

void Ennemi::UpdateRect(){
	rect->x = posX;
	rect->y = posY;
	if(pv == 0){
		posX = -9999;
		posY = -9999;
	}
}

void Ennemi::Aggro(double x){
	if(posX+120<x){
		MoveRight();
	}else{
		MoveLeft();
	}
}

void Ennemi::UpdatePos(){
	posX += vX;
	posY += vY;
}

void Ennemi::Hurt(){
	pv--;
	if(pv == 0){
		posX = -9999;
		posY = -9999;
	}
}

void Ennemi::AffichageTerminal(){
	std::cout << "Ennemi : " << std::endl;
	std::cout << "pv = " << pv << std::endl;
	std::cout << "posX = " << posX << std::endl;
	std::cout << "posY = " << posY << std::endl;
	std::cout << "rectX = " << rect->x << std::endl;
	std::cout << "rectY = " << rect->y << std::endl;
	std::cout << "vX = " << vX << std::endl;
	std::cout << "vY = " << vY << std::endl;
	std::cout <<""<< std::endl;
	std::cout <<""<< std::endl;
}





