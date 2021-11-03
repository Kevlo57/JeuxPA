#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

#include "fonctionSDL.h"
#include <SDL2/SDL.h>

int main(void){

	SDL_Window* fenetre; // Déclaration de la fenêtre
	SDL_Event evenements; // Événements liés à la fenêtre
	SDL_Renderer* ecran;
	SDL_Texture* fond;

	bool terminer = false;

	if(SDL_Init(SDL_INIT_VIDEO) < 0) // Initialisation de la SDL
	{
		printf("Erreur d’initialisation de la SDL: %s",SDL_GetError());
		SDL_Quit();
		return EXIT_FAILURE;
	}

	// Créer la fenêtre
	fenetre = SDL_CreateWindow("Fenetre SDL", SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_RESIZABLE);
	if(fenetre == NULL) // En cas d’erreur
	{
		printf("Erreur de la creation d’une fenetre: %s",SDL_GetError());
		SDL_Quit();
		return EXIT_FAILURE;
	}

	// Créer un contexte de rendu (renderer) pour l’image
	ecran = SDL_CreateRenderer(fenetre,-1,SDL_RENDERER_ACCELERATED) ;

	// Convertir la surface de l’image au format texture avant de l’appliquer
	//fond = charger_image("fond.bmp",ecran);
		
	// Récupérer les attributs d’une texture
	int texture_width , texture_height;
	//SDL_QueryTexture(fond,NULL,SDL_TEXTUREACCESS_STATIC,&texture_width,&texture_height);

	Uint8 r = 255, g = 255, b = 255;
	//SDL_Texture* obj = charger_image_transparente("obj.bmp",ecran,r,g,b);
	SDL_Rect SrcR;
	SDL_Rect DestR;

	SrcR.x = 0;
	SrcR.y = 0;
	SrcR.w = 640; 
	SrcR.h = 192; 
	
	DestR.x = 350;
	DestR.y = 350;
	DestR.w = 640/3;
	DestR.h = 192/3;
	
	/*
	SDL_Rect DestR_sprite[6];
	for(int i=0; i<6; i++)
	{
	DestR_sprite[i].x = i > 2 ? 60*(i+1)+100 : 60*(i+1);
	DestR_sprite[i].y = i > 2 ? 60 : 120;
	DestR_sprite[i].w = tailleW; // Largeur du sprite
	DestR_sprite[i].h = tailleH; // Hauteur du sprite
	}
	*/

	// Boucle principale
	while(!terminer){
		SDL_RenderClear(ecran);
		//SDL_RenderCopy(ecran,fond,NULL,NULL);
		//SDL_RenderCopy(ecran,obj,&SrcR,&DestR);
		SDL_PollEvent( &evenements );
		switch(evenements.type)
		{
			case SDL_QUIT:
			terminer = true; 
			break;
			case SDL_KEYDOWN:
			switch(evenements.key.keysym.sym)
			{
				case SDLK_ESCAPE:
				case SDLK_q:
				terminer = true; 
				break;
			}
		}
		SDL_RenderPresent(ecran);
	}

	// Libérer la memoire
	//SDL_DestroyTexture(fond) ;
	SDL_DestroyRenderer(ecran);

	// Quitter SDL
	SDL_DestroyWindow(fenetre);
	SDL_Quit();
	return 0;
}

















