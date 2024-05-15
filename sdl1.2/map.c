#include "map.h"

void initialiser_map (map *m,SDL_Surface *ecran)
{
	m->map=IMG_Load("minimap.bmp");
	m->pos_map.x =500;
	m->pos_map.y = 0;
	m->mini_perso=SDL_CreateRGBSurface(SDL_HWSURFACE|SDL_DOUBLEBUF,10,10,32,0,0,0,0);
	SDL_FillRect(m->mini_perso,NULL,SDL_MapRGB(ecran->format,0,255,0));
	m->perso_pos_map.x=0;
	m->perso_pos_map.y=0;

}


void perso_map(map *m,personne *p22)
{
	m->perso_pos_map.x=p22->pos_perso.x/12+m->pos_map.x;
	m->perso_pos_map.y=p22->pos_perso.y/12+10+m->pos_map.y;
}



void affiche_map(map m , SDL_Surface *ecran)
{
	SDL_BlitSurface(m.map, NULL, ecran,&m.pos_map);
	SDL_BlitSurface(m.mini_perso, NULL, ecran,&m.perso_pos_map);
}












