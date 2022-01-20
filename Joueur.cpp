#include "Joueur.h"

Joueur::Joueur(){
	
}

Joueur::Joueur(double x,double y){
	pv = 3;
	posX = x;
	posY = y;
	acceleration = 3;
	vX = 0;
	vY = 0;
	vitesseMin = 0.001;
	vitesseMax = 15;
	coeffDeceleration = 0.920;
	jump = false;
	fall = false;
	fallAcceleration = 1.05;
	jumpAcceleration = 1.3;
	jumpDeceleration = 0.900;
	rect = new SDL_Rect;
	rect->x = posX;
	rect->y = posY;
	rect->w = 80;
	rect->h = 80;
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

void Joueur::MoveRight(){
	if(vX<vitesseMax){
		vX += acceleration;	
	}
}

void Joueur::MoveLeft(){
	if(vX>-vitesseMax){
		vX -= acceleration;	
	}
}

void Joueur::SetFall(bool f){
	fall = f;
}

void Joueur::SetJump(bool j){
	if(j){
		if(!fall){
			jump = j;
		}
	}else{
		jump = j;	
	}
}

void Joueur::Update(){
	UpdateSpeed();
	UpdatePos();
	UpdateRect();
}

void Joueur::TestFalling(){
	if(!jump && posY<764){
		SetFall(true);
		if(vY == 0){
			vY += fallAcceleration;
		}else{
			if(vY<0){
				vY *= jumpDeceleration;
				if(vY>-0.5){
					vY = fallAcceleration;
				}	
			}else{
				vY *= fallAcceleration;
			}
		}
	}else if(!jump && posY+vY>764){
		SetFall(false);
		vY = 0;
		posY = 764;
	}
}

void Joueur::TestJumping(){
	if(jump && vY>-vitesseMax){
		vY -= jumpAcceleration;
	}else{
		SetJump(false);
	}
}

void Joueur::UpdateSpeed(){
	if(vX<vitesseMin && vX>-vitesseMin){
		vX = 0;
	}else{
		vX *= coeffDeceleration;
	}
	TestFalling();
	TestJumping();
}

void Joueur::UpdateRect(){
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

void Joueur::UpdatePos(){
	posX += vX;
	posY += vY;
}

void Joueur::Affichage(){
	std::cout << "Joueur : " << std::endl;
	std::cout << "posX = " << posX << std::endl;
	std::cout << "posY = " << posY << std::endl;
	std::cout << "rectX = " << rect->x << std::endl;
	std::cout << "rectY = " << rect->y << std::endl;
	std::cout << "vX = " << vX << std::endl;
	std::cout << "vY = " << vY << std::endl;
	if(fall){
		std::cout << "tombe" << std::endl;
	}else{
		std::cout << "tombe pas" << std::endl;
	}
	if(jump){
		std::cout << "saute" << std::endl;
	}else{
		std::cout << "saute pas" << std::endl;
	}
	std::cout <<""<< std::endl;
	std::cout <<""<< std::endl;
}





