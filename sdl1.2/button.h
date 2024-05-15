// button.h
#ifndef BUTTON_H_
#define BUTTON_H_
#include <SDL/SDL_mixer.h>
#include "background.h"
#include "back.h"
#include "es.h"
#include "pers.h"
#include "time.h"
#include "map.h"


void handleMouseMotion(SDL_Event *event, Image *B);
void mainMenu_display(Image B1, Image B2, Image B3, Image B4, Image B11, Image B21, Image B31, Image B41, Image backg, SDL_Surface *ecran, int *i);
void play_display(Image pb, SDL_Surface *ecran,Image n,Image lg,Image n1,Image lg1,Image x,int *i);
void handMouseClicks(SDL_Event *event, int *mode,int *done, Image B1, Image B2,Image B3, Image B4 ,Mix_Chunk *c, Image *p,Image yes,Image no,Image x1,Image fu, SDL_Surface *ecran,Image w,Image n,Image lg,Image select);
void settings_display(Image sb, SDL_Surface *ecran, Image so, Image fu, Image w, Image fu1, Image w1, Image p,Image x1);
void movePoint(Image *point, int direction, int speed);
void credit_display(Image mc, SDL_Surface *ecran,Image x);
void quit_display(Image mq,Image yes,Image yes1,Image no,Image no1, SDL_Surface *ecran,int *s);
void  newgame_display(Image ee, Image select,SDL_Surface *ecran);
void loadgame_display(Image ee, es health,personne pers,es enem,SDL_Rect pos11,SDL_Rect pos, SDL_Event e,  es fire,map m,Time temps, SDL_Surface *ecran, background ba);
void select_display(Image ee, Image lg,SDL_Surface *ecran);

#endif /* BUTTON_H_ */


