#include"es.h"
#include <math.h>


void init_es(es *p1) {
    (*p1).d = 0;
    (*p1).pos.x = 486;
    (*p1).pos.y = 585;
    (*p1).sprite.x = 0;
    (*p1).sprite.y = 0;
    (*p1).sprite_n = 0;             
    // Load appropriate images based on the initial state

        (*p1).image = IMG_Load("es.png");
 
    // Calculate dimensions for both position and sprite
    (*p1).pos.w = (*p1).image->w / 6;
    (*p1).pos.h = (*p1).image->h / 4;
    (*p1).sprite.w = (*p1).image->w / 6;
    (*p1).sprite.h = (*p1).image->h / 4;
    (*p1).sprite_count = 5;
p1->state=waiting;
}

void init_ff(es *p2){
    
    (*p2).pos11.x = 956;
    (*p2).pos11.y = 545;

    (*p2).imge = IMG_Load("bonus.png");
    (*p2).pos11.w = (*p2).imge->w;
    (*p2).pos11.h = (*p2).imge->h;


}
void init_health(es *p3){
    
    (*p3).posh.x = 556;
    (*p3).posh.y = 100;

  (*p3).imageh = IMG_Load("health.png");


(*p3).posh.w = (*p3).imageh->w /2;
(*p3).posh.h = (*p3).imageh->h ;


}
void afficher3(es v, SDL_Surface *screen) {
    SDL_BlitSurface(v.imageh,NULL,screen,&v.posh);

}

void afficher2(es v, SDL_Surface *screen) {
    SDL_BlitSurface(v.imge,NULL, screen, &v.pos11);}

void afficher1(es v, SDL_Surface *ecran) {
    SDL_BlitSurface(v.image, &v.sprite, ecran, &v.pos);}

void animateEntity(es *p1) {
    // Update sprite.y based on direction
    p1->sprite.y = p1->d * p1->sprite.h;

    // Check if it's time to reset to the first frame
    if (p1->sprite.x == (p1->sprite_count - 1) * p1->sprite.w) {
        p1->sprite.x = 0; // Reset to the first frame
    } else {
        // Move to the next frame
        p1->sprite.x += p1->sprite.w;
    }
}

void deplacer_es(es *p1,int max,int min) {
   

   if (p1->pos.x > max) {
        p1->d = 0; // left
    } else if (p1->pos.x < min) {
        p1->d = 1; // right
    } 


    if (p1->d == 1) {
        p1->pos.x += 20; // right
    } else {
        p1->pos.x -= 20; // left
    }
}
int collisionTri(personne *p22, SDL_Rect *pos11) {
    SDL_Rect rect1;
    SDL_Rect rect2;
    float D, R1, R2;
  rect1.x = p22->pos_perso.x + (p22->pos_perso.w) / 2;
    rect1.y = p22->pos_perso.y + (p22->pos_perso.h) / 2;
    R1 = sqrt(((p22->pos_perso.w) / 2) * ((p22->pos_perso.w) / 2) + ((p22->pos_perso.h) / 2) * ((p22->pos_perso.h) / 2));

    rect2.x = pos11->x + (pos11->w) / 2;
    rect2.y = pos11->y + (pos11->h) / 2;

    R2 = sqrt(((pos11->w) / 2) * ((pos11->w) / 2) + ((pos11->h) / 2) * ((pos11->h) / 2));
    D = sqrt((rect1.x - rect2.x) * (rect1.x - rect2.x) + (rect1.y - rect2.y) * (rect1.y - rect2.y));

    if (D <= R1 + R2) {
        // Move pos11 if there's a collision
        
   
        return 1;
    } else {
        return 0;
    }
}

int collisionbb(personne p22, SDL_Rect *pos) {
if(pos->x>=p22.pos_perso.x+ p22.pos_perso.w||pos->x+pos->w<=p22.pos_perso.x||pos->y+pos->h<=p22.pos_perso.y||pos->y>=p22.pos_perso.y+p22.pos_perso.h){

return 0;

}
else{


return 1 ;}}



void updateetat(es *p1,int di){
switch(p1->state)
{
case waiting:
if((100<di)&&(di<400)){
p1->state=following;
p1->d=0;}

break;
case following:
if((0<di)&&(di<100)){
p1->state=attacking;
p1->d=2;
}


break;
case attacking:
if(di<0){
p1->state=waiting;
p1->d=1;
}break;
}


}
void updateenemi(es *p1,SDL_Rect pos_perso){

switch(p1->state){
case waiting:
animateEntity(p1);
break;
case following:
animateEntity(p1);
if(pos_perso.x<p1->pos.x){
p1->pos.x=p1->pos.x-10;}
else if(pos_perso.x > p1->pos.x) {
    p1->pos.x = p1->pos.x+10;
}
break;
case attacking:
animateEntity(p1);
if(pos_perso.x<p1->pos.x){
p1->pos.x=p1->pos.x-2;
}
break;



}
}



