#ifndef map_H_INCLUDED
#define map_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
//#include <SDL/SDL_mixer.h>
#include "pers.h"

typedef struct 
{	
	SDL_Surface *map ;
	SDL_Rect pos_map;
	SDL_Surface *mini_perso;
	SDL_Rect perso_pos_map;

}map;

	void initialiser_map (map *m,SDL_Surface *ecran) ;
	void perso_map(map *m,personne *p22);
	void affiche_map(map m, SDL_Surface *ecran);

#endif
