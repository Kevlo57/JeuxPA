#include "Ennemi.h"

Ennemi::Ennemi(){
	
}

Ennemi::Ennemi(double x,double y){
	pv = 3;
	posX = x;
	posY = y;
	acceleration = 3;
	vX = 0;
	vY = 0;
	vitesseMin = 0.001;
	vitesseMax = 15;
	coeffDeceleration = 0.920;
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
	/*
	if(rect->x<(int)posX){
		rect->x++;
	}else if(rect->x>(int)posX){
		rect->x--;
	}
	if(rect->y<(int)posY){
		rect->y++;
	}else if(rect->y>(int)posY){
		rect->y--;
	}
	*/
	rect->x = posX;
	rect->y = posY;
}

void Ennemi::UpdatePos(){
	posX += vX;
	posY += vY;
}

void Ennemi::Affichage(){
	std::cout << "Ennemi : " << std::endl;
	std::cout << "posX = " << posX << std::endl;
	std::cout << "posY = " << posY << std::endl;
	std::cout << "rectX = " << rect->x << std::endl;
	std::cout << "rectY = " << rect->y << std::endl;
	std::cout << "vX = " << vX << std::endl;
	std::cout << "vY = " << vY << std::endl;
	std::cout <<""<< std::endl;
	std::cout <<""<< std::endl;
}





