#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include<iostream>
#include <SDL2/SDL.h>

#include "fonctionSDL.h"
#include "Monde.h"

#define FPS 60
#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

int main(){

	SDL_Window* fenetre;
	SDL_Event evenements; 
	SDL_Renderer* ecran;
	bool terminer = false;
	if(SDL_Init(SDL_INIT_VIDEO) < 0) // Initialisation de la SDL
	{
		printf("Erreur d’initialisation de la SDL: %s",SDL_GetError());
		SDL_Quit();
		return EXIT_FAILURE;
	}
	fenetre = SDL_CreateWindow("Fenetre SDL", SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);
	if(fenetre == NULL) // En cas d’erreur
	{
		printf("Erreur de la creation d’une fenetre: %s",SDL_GetError());
		SDL_Quit();
		return EXIT_FAILURE;
	}
	ecran = SDL_CreateRenderer(fenetre,-1,SDL_RENDERER_ACCELERATED) ;

	//Chargement Texture
	SDL_Texture* fond = charger_image("ressources/fond/foret.bmp",ecran);
	SDL_Texture* bob_texture = charger_image("ressources/joueur/ennemi.bmp",ecran);
	SDL_Texture* joueur_texture = charger_image("ressources/joueur/joueur.bmp",ecran);

	//Initialisation du monde
	Monde* monde = new Monde();

	const int frame_delay = 1000/FPS;
	Uint32 frame_start;
	int frame_time;

	while(!terminer){

		frame_start = SDL_GetTicks();
		while(SDL_PollEvent(&evenements)){
			if(evenements.type == SDL_QUIT){
					terminer = true; 
			}else if(evenements.type == SDL_KEYDOWN){
				switch(evenements.key.keysym.sym){
					case SDLK_ESCAPE:
						terminer = true; 
					break;
					case SDLK_d:	
						monde->GetJoueur()->MoveRight();
					break;
					case SDLK_q:	
						monde->GetJoueur()->MoveLeft();
					break;
					case SDLK_SPACE:	
						monde->GetJoueur()->SetJump(true);
					break;	
					case SDLK_z:	
						monde->GetJoueur()->SetJump(true);
					break;				
				}
			}	
		}
		//monde->GetJoueur()->Affichage();
		monde->GetJoueur()->Update();
		monde->GetEnnemi()->Update();

		SDL_RenderClear(ecran);
		SDL_RenderCopy(ecran,fond,NULL,NULL);
		SDL_RenderCopy(ecran,bob_texture,NULL,monde->GetEnnemi()->GetRect());
		SDL_RenderCopy(ecran,joueur_texture,NULL,monde->GetJoueur()->GetRect());

		SDL_RenderPresent(ecran);

		frame_time = SDL_GetTicks() - frame_start;
		if(frame_delay > frame_time){
			SDL_Delay(frame_delay-frame_time);
		}
	}

	// Libérer la memoire
	SDL_DestroyTexture(bob_texture) ;
	SDL_DestroyTexture(joueur_texture) ;
	SDL_DestroyTexture(fond) ;
	SDL_DestroyRenderer(ecran);

	// Quitter SDL
	SDL_DestroyWindow(fenetre);
	SDL_Quit();
	return 0;
}















