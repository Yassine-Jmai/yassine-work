#include "pers.h"

void initialiserperso(personne *p22)
{	
	p22->image_p=IMG_Load("hero.png");
	p22->pos_perso.x=0;
	p22->pos_perso.y=570;
	p22->pos_perso.w=p22->image_p->w;
	p22->pos_perso.h=p22->image_p->h;
}

void afficher_perso(personne p22,SDL_Surface *screen)
{	
	SDL_BlitSurface(p22.image_p,NULL,screen,&p22.pos_perso);
}

void deplacer_perso(personne *p22, SDL_Event *e) {
    // Check if a key is pressed
    if (e->type == SDL_KEYDOWN) {
        // Check which key is pressed
        switch (e->key.keysym.sym) {
            case SDLK_UP:
                p22->pos_perso.y -= 50;
                break;
            case SDLK_DOWN:
                p22->pos_perso.y += 50;
                break;
            case SDLK_RIGHT:
                p22->pos_perso.x += 50;
                break;
            case SDLK_LEFT:
                p22->pos_perso.x -= 50;
                break;

        }
    }
}


void free_perso(personne p22)
{
	SDL_FreeSurface(p22.image_p);
}
