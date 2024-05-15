#ifndef PERS_H_INCLUDED
#define PERS_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>



typedef struct
{
  	SDL_Surface *image_p;
  	SDL_Rect pos_perso;

}personne;

void initialiserperso(personne *p22);
void deplacer_perso(personne *p22,SDL_Event *e);
void afficher_perso(personne p22,SDL_Surface *screen);
void free_perso(personne p22);


#endif
