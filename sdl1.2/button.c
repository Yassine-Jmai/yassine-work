// button.c
#include "button.h"
#define POINT_MOVE_SPEED 5 // Adjust this value according to your preference


void handleMouseMotion(SDL_Event *event, Image *button) {
    if (event->motion.x >= button->pos1.x && event->motion.x < button->pos1.x + button->pos1.w && event->motion.y >= button->pos1.y && event->motion.y < button->pos1.y + button->pos1.h) {
        button->hovered = 1;
    } else {
        button->hovered = 0;
    }
}
void movePoint(Image *point, int direction, int speed) {
    // Move the point horizontally by adjusting its x position
    point->pos1.x += direction * speed;
}
void mainMenu_display(Image B1, Image B2, Image B3, Image B4, Image B11, Image B21, Image B31, Image B41, Image backg, SDL_Surface *ecran, int *i)
{

       
	afficher(backg, ecran);
	if(B1.hovered == 0)
		afficher(B1, ecran);
	else{
		afficher(B11, ecran);
		*i = 1;
	}

	if(B2.hovered == 0)
		afficher(B2, ecran);
	else{
		afficher(B21, ecran);
		*i = 2;
	}

	if(B3.hovered == 0)
		afficher(B3, ecran);
	else{
		afficher(B31, ecran);
		*i = 3;
	}

	if(B4.hovered == 0)
		afficher(B4, ecran);
	else{
		afficher(B41, ecran);
		*i = 4;
	}
	
	if(*i == 1)
		afficher(B11, ecran);
	else if(*i == 2)
		afficher(B21, ecran);
	else if(*i == 3)
		afficher(B31, ecran);
	else if(*i == 4)
		afficher(B41, ecran);
}

void play_display(Image pb, SDL_Surface *ecran,Image n,Image lg,Image n1,Image lg1,Image x,int *i)
{    
	afficher(pb, ecran);
	afficher(x,ecran);
	if(n.hovered == 0){
		afficher(n,ecran);}
	else{
		afficher(n1, ecran);
		*i=1;}

	if(lg.hovered == 0){
		afficher(lg, ecran);}
	else{
     
		afficher(lg1,ecran);
	*i=2;}
       if(*i == 1){
		afficher(n1, ecran);}
	else if(*i == 2){
		afficher(lg1, ecran);}


}
void settings_display(Image sb, SDL_Surface *ecran, Image so, Image fu, Image w, Image fu1, Image w1, Image p,Image x1) {
    // Calculate the position of the point
    int point_width = p.pos1.w; // Width of the point
    int half_point_width = point_width / 2; // Half width of the point
    int max_point_x = SCREEN_W - point_width; // Maximum x-coordinate for the point

    // Adjust music volume based on the position of the point
    int max_volume = MIX_MAX_VOLUME; // Maximum volume
    int min_volume = 0; // Minimum volume (mute)
    int half_screen_width = SCREEN_W / 2; // Half of the screen width

    // Get the current x-coordinate of the point
    int point_x = p.pos1.x + half_point_width; // Center of the point

    // Calculate the volume based on the position of the point
    int volume;
    if (point_x < half_screen_width) {
        // Left half of the screen, decrease the volume
        volume = max_volume - (max_volume / half_screen_width) * point_x;
    } else {
        // Right half of the screen, increase the volume
        volume = (max_volume / half_screen_width) * (point_x - half_screen_width);
    }

    // Set the music volume
    Mix_VolumeMusic(volume);

    // Limit the movement of the point within the screen boundaries
    if (point_x < 0) {
        p.pos1.x = 0;
    } else if (point_x > max_point_x) {
        p.pos1.x = max_point_x;
    }

    // Render other elements of the settings display
    afficher(sb, ecran);
    afficher(x1,ecran);
    afficher(so, ecran);
    afficher(p, ecran);
    if (fu.hovered == 0)
        afficher(fu, ecran);
    else
        afficher(fu1, ecran);
    if (w.hovered == 0)
        afficher(w, ecran);
    else
        afficher(w1, ecran);
}
void credit_display(Image mc, SDL_Surface *ecran,Image x1)
{    
	afficher(mc, ecran);
        afficher(x1,ecran);

}
void quit_display(Image mq,Image yes,Image yes1,Image no,Image no1, SDL_Surface *ecran,int *s)
{    
	afficher(mq, ecran);
	
if(yes.hovered ==0){
        afficher(yes,ecran);}
else{ 
	afficher(yes1,ecran);
	*s=1;}
if(no.hovered ==0){
	afficher(no,ecran);}
else{
	afficher(no1,ecran);
	*s=2;}

if(*s==1)
	afficher(yes1,ecran);
else if(*s==2)
	afficher(no1,ecran);


}
void  newgame_display(Image ee, Image  select,SDL_Surface *ecran){
   afficher(ee,ecran);
afficher(select,ecran);
}
void  loadgame_display(Image ee, es health,personne pers,es enem,SDL_Rect pos11,SDL_Rect pos, SDL_Event e,  es fire,map m,Time temps, SDL_Surface *ecran, background ba){
   afficheBack2(ba,ecran,pers);

    afficher_perso(pers, ecran);
affiche_map(m,ecran);

  deplacer_perso(&pers,&e);
    afficher2(fire, ecran);

    afficher1(enem, ecran);
    animateEntity(&enem);
}
void select_display(Image ee,Image lg,SDL_Surface *ecran){
afficher(ee,ecran);
afficher(lg,ecran);
} 

void handMouseClicks(SDL_Event *event, int *mode,int *done, Image B1, Image B2,Image B3, Image B4 ,Mix_Chunk *c, Image *p,Image yes,Image no,Image x1,Image fu, SDL_Surface *ecran,Image w,Image n,Image lg,Image select) {
    if ((event->type == SDL_MOUSEBUTTONDOWN) && (event->button.button == SDL_BUTTON_LEFT)) {
        if (event->motion.x >= B1.pos1.x && event->motion.x < B1.pos1.x + B1.pos1.w &&
            event->motion.y >= B1.pos1.y && event->motion.y < B1.pos1.y + B1.pos1.h && (*mode == 0)) {
            Mix_PlayChannel(-1, c, 0);
            *mode = 1;
        } else if (event->motion.x >= B2.pos1.x && event->motion.x < B2.pos1.x + B2.pos1.w &&
                   event->motion.y >= B2.pos1.y && event->motion.y < B2.pos1.y + B2.pos1.h && (*mode == 0)) {
 Mix_PlayChannel(-1, c, 0);
            *mode = 2;}
	else if (event->motion.x >= B3.pos1.x && event->motion.x < B3.pos1.x + B3.pos1.w &&
                   event->motion.y >= B3.pos1.y && event->motion.y < B3.pos1.y + B3.pos1.h && (*mode == 0)) {
 Mix_PlayChannel(-1, c, 0);
            *mode = 3;}
else if (event->motion.x >= B4.pos1.x && event->motion.x < B4.pos1.x + B4.pos1.w &&
                   event->motion.y >= B4.pos1.y && event->motion.y < B4.pos1.y + B4.pos1.h && (*mode == 0)) {
 Mix_PlayChannel(-1, c, 0);
            *mode = 4;
        } 
else if (event->motion.x >= yes.pos1.x && event->motion.x < yes.pos1.x + yes.pos1.w &&
                   event->motion.y >= yes.pos1.y && event->motion.y < yes.pos1.y + yes.pos1.h && (*mode == 4)) {

         *done=0;}
else if (event->motion.x >= no.pos1.x && event->motion.x < no.pos1.x + no.pos1.w &&
                   event->motion.y >= no.pos1.y && event->motion.y < no.pos1.y + no.pos1.h && (*mode == 4)) {
Mix_PlayChannel(-1, c, 0);

         *mode=0;}
else if (event->motion.x >= x1.pos1.x && event->motion.x < x1.pos1.x + x1.pos1.w &&
                   event->motion.y >= x1.pos1.y && event->motion.y < x1.pos1.y + x1.pos1.h && ((*mode == 1)||(*mode==3)||(*mode==2))) {
Mix_PlayChannel(-1, c, 0);

         *mode=0;}
else if (event->motion.x>= n.pos1.x && event->motion.x < n.pos1.x + n.pos1.w &&
                   event->motion.y >= n.pos1.y && event->motion.y < n.pos1.y + n.pos1.h && ((*mode == 1)||(*mode==3)||(*mode==2))) {
Mix_PlayChannel(-1, c, 0);

         *mode=5;}
else if (event->motion.x>= lg.pos1.x && event->motion.x < lg.pos1.x + lg.pos1.w &&
                   event->motion.y >= lg.pos1.y && event->motion.y < lg.pos1.y + lg.pos1.h && (*mode==7)) {
Mix_PlayChannel(-1, c, 0);

         *mode=6;}
else if (event->motion.x>= select.pos1.x && event->motion.x < select.pos1.x + select.pos1.w &&
                   event->motion.y >= select.pos1.y && event->motion.y < select.pos1.y + select.pos1.h ) {
Mix_PlayChannel(-1, c, 0);

         *mode=7;}
else if (event->motion.x >= fu.pos1.x && event->motion.x < fu.pos1.x + fu.pos1.w &&
                   event->motion.y >= fu.pos1.y && event->motion.y < fu.pos1.y + fu.pos1.h && (*mode == 2)) {
 Mix_PlayChannel(-1, c, 0);
          ecran = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_SWSURFACE | SDL_FULLSCREEN);;}
else if (event->motion.x >= w.pos1.x && event->motion.x < w.pos1.x + w.pos1.w &&
                   event->motion.y >= w.pos1.y && event->motion.y < w.pos1.y + w.pos1.h && (*mode == 2)) {
 Mix_PlayChannel(-1, c, 0);
         ecran = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_SWSURFACE);}



else {
            // Move the point to the position of the click
            p->pos1.x = event->motion.x - p->pos1.w / 2; // Center the point on the cursor
        }
    }

    // Move the point if the mouse button is held down and mode is 2
    if (*mode == 2 && (event->type == SDL_MOUSEMOTION || event->type == SDL_MOUSEBUTTONDOWN)) {
        if (event->motion.x >= p->pos1.x && event->motion.x <= p->pos1.x + p->pos1.w) {
            p->pos1.x = event->motion.x - p->pos1.w / 2; // Center the point on the cursor
        } else if (event->motion.x < p->pos1.x) {
            p->pos1.x -= POINT_MOVE_SPEED; // Move left
        } else {
            p->pos1.x += POINT_MOVE_SPEED; // Move right
        }
    }
}

