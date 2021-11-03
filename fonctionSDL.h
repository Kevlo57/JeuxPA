#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

#include <SDL2/SDL.h>

//charger une image et retourner la surface de texture associée.
SDL_Texture* charger_image(const char* nomfichier, SDL_Renderer* renderer); 

SDL_Texture* charger_image_transparente(const char* nomfichier,SDL_Renderer* renderer,Uint8 r, Uint8 g, Uint8 b) ; 















