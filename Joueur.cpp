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
	fallAcceleration = 1.15;
	jumpAcceleration = 1.3;
	jumpDeceleration = 0.850;
	rect = new SDL_Rect;
	rect->x = posX;
	rect->y = posY;
	rect->w = 80;
	rect->h = 80;
	recovery = 0;
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
	rect->x = posX;
	rect->y = posY;
}

void Joueur::UpdatePos(){
	if(posX + 80 + vX <0){
		posX = 1880;
	}else if(posX + vX >1920){
		posX = 0;
	}else{
		posX += vX;
	}	
	posY += vY;
}

void Joueur::CollisionEnnemi(Ennemi* e){
	if(CollisionEnnemiDroit(e)){
		PushLeft();
		Hurt();
	}else if(CollisionEnnemiGauche(e)){
		PushRight();
		Hurt();
	}else if(CollisionEnnemiHaut(e)){
		Hit(e);
		vY *= jumpAcceleration;
	}
}

bool Joueur::CollisionEnnemiDroit(Ennemi* e){
	return posX+80<e->GetPosX()+50 && posX+80>e->GetPosX() && GetPosY()<e->GetPosY()+120 && GetPosY()+80>e->GetPosY();
}

bool Joueur::CollisionEnnemiGauche(Ennemi* e){
	return GetPosX()>e->GetPosX()+50 && GetPosX()<e->GetPosX()+120 && GetPosY()<e->GetPosY()+120 && GetPosY()+80>e->GetPosY();
}

bool Joueur::CollisionEnnemiHaut(Ennemi* e){
	return GetPosY()+80<e->GetPosY()+50 && GetPosY()+80>e->GetPosY() && GetPosX()<e->GetPosX()+120 && GetPosX()+80>e->GetPosX();
}

void Joueur::PushLeft(){
	vX = -vitesseMax*2;
}

void Joueur::PushRight(){
	vX = vitesseMax*2;
}

bool Joueur::IsInRecovery(){
	unsigned int ticks = SDL_GetTicks();
	if(recovery<1000){
		return false;
	}else if(ticks - recovery < 1000){
		return true;
	}else{
		return false;
	}

}

void Joueur::Hurt(){
	unsigned int ticks = SDL_GetTicks();
	if(ticks - recovery > 1000){
		pv--;
		recovery = ticks;
	}
}

void Joueur::Hit(Ennemi* e){
	e->Hurt();
}

void Joueur::AffichageTerminal(){
	std::cout << "Joueur : " << std::endl;
	std::cout << "pv = " << pv << std::endl;
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





