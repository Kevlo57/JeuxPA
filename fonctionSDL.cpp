#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

#include "fonctionSDL.h"
#include <SDL2/SDL.h>

//charger une image et retourner la surface de texture associée.
SDL_Texture* charger_image (const char* nomfichier, SDL_Renderer* renderer)
{
	SDL_Surface* surface = SDL_LoadBMP(nomfichier) ;
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer,surface);
	SDL_FreeSurface(surface);	
	return texture;
} 

SDL_Texture* charger_image_transparente(const char* nomfichier,SDL_Renderer* renderer,Uint8 r, Uint8 g, Uint8 b)
{
	SDL_Surface* surface = SDL_LoadBMP(nomfichier) ;
	Uint32 key = SDL_MapRGB(surface->format,r,g,b);
	SDL_SetColorKey(surface,SDL_TRUE,key) ;
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer,surface);
	SDL_FreeSurface(surface);
	return texture;
} 














