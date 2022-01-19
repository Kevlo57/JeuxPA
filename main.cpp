#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include<iostream>
#include <SDL2/SDL.h>

#include "fonctionSDL.h"
#include "Joueur.h"

#define FPS 60
#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

int main(){

	SDL_Window* fenetre;
	SDL_Event evenements; 
	SDL_Renderer* ecran;
	SDL_Texture* fond;
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
	fond = charger_image("ressources/fond/foret.bmp",ecran);
	SDL_Texture* joueur = charger_image("ressources/joueur/DEBOUT.bmp",ecran);

	Joueur* j = new Joueur(0.0,650.0);

	const int frame_delay = 1000/FPS;
	Uint32 frame_start;
	int frame_time;

	bool z = false;
	bool s = false;
	bool q = false;
	bool d = false;

	while(!terminer){

		frame_start = SDL_GetTicks();
		SDL_RenderClear(ecran);
		SDL_RenderCopy(ecran,fond,NULL,NULL);
		SDL_RenderCopy(ecran,joueur,NULL,j->GetRect());
		while(SDL_PollEvent(&evenements)){
			if(evenements.type == SDL_QUIT){
					terminer = true; 
			}else if(evenements.type == SDL_KEYDOWN){
				switch(evenements.key.keysym.sym){
					case SDLK_ESCAPE:
						terminer = true; 
					break;
					case SDLK_z:
						z = true;
						s = false;
						j->Move(z,q,s,d);	
					break;
					case SDLK_d:
							d = true;
							q = false;
							j->Move(z,q,s,d);	
					break;
					case SDLK_q:
						q = true;
						d = false;
						j->Move(z,q,s,d);
					break;
					case SDLK_s:
						s = true;
						z = false;
						j->Move(z,q,s,d);
					break;
				}
			}else if(evenements.type == SDL_KEYUP){
				switch(evenements.key.keysym.sym){
					case SDLK_z:
						z = false;
					break;
					case SDLK_d:
						d = false;
					break;
					case SDLK_q:
						q = false;
					break;
					case SDLK_s:
						s = false;
					break;
				}	
			}		
		}
		SDL_RenderPresent(ecran);

		frame_time = SDL_GetTicks() - frame_start;
		if(frame_delay > frame_time){
			SDL_Delay(frame_delay-frame_time);
		}
	}

	// Libérer la memoire
	SDL_DestroyTexture(fond) ;
	SDL_DestroyRenderer(ecran);

	// Quitter SDL
	SDL_DestroyWindow(fenetre);
	SDL_Quit();
	return 0;
}















