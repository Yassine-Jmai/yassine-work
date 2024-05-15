#ifndef _ES_H_
#define _ES_H_
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include <stdlib.h>
#include"background.h"
#include"pers.h"

typedef enum {
    waiting,
    following,
    attacking
} state;

typedef struct
{
    SDL_Rect pos;
 SDL_Rect attack_pos;
    SDL_Rect pos11;
  SDL_Rect posh;
    SDL_Rect sprite; /*!< Rectangle*/
    SDL_Surface *image;
 SDL_Surface *imge;
 SDL_Surface *imageh;
SDL_Surface *image_attack;
 /*!< Surface. */
    int sprite_count;
    int sprite_n; //current sprite
    int d;        //direction
    int x1;
    int y1;
int ff;

state state;
} es;

void init_es(es *p1);
void init_ff(es *p2);
void init_health(es *p3);
void afficher3(es v, SDL_Surface *screen);
void afficher2(es p1, SDL_Surface *screen) ;
void afficher1(es p1, SDL_Surface *ecran);
void animateEntity(es *p1);
void move_es(es *p);
void deplacer_es(es *p1,int max,int min);
int collisionTri(personne *p22, SDL_Rect *pos11) ;
int collisionbb(personne p22, SDL_Rect *pos);
void updateetat(es *p1,int d);
void updateenemi(es *p1,SDL_Rect pos_perso);

#endif // _ES_H_

