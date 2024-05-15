#ifndef BACKGROUND_H_INCLUDE
#define BACKGROUND_H_INCLUDE
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "pers.h"
#include"background.h"
typedef struct
{
	SDL_Surface *imgback;
        SDL_Surface *boutton;
        TTF_Font *police; 
        SDL_Rect pos_reponse1txt;
	SDL_Rect pos_reponse2txt;
	SDL_Rect pos_reponse3txt;
        SDL_Rect pos_meilleurtxt;
	SDL_Surface *reponses[4];
        SDL_Rect positionbotton;
	SDL_Rect posback2;
	SDL_Rect camera2;
	
       
	SDL_Surface *image_bird;  
	SDL_Rect pos_image_bird;
	SDL_Rect single_bird;	
	int bird_num;

  SDL_Surface *vies;
  SDL_Surface *scores;
  SDL_Rect posVie1;
  SDL_Rect posVie2;

  SDL_Rect posScore;
  int stage;
SDL_Rect posstage;
  
 
  int vie;
  int score;

}background;
void initBack2(background *b);
void initbouton(background *b);
void affichebouton(background b,SDL_Surface *ecran);
void afficheBack2 (background b, SDL_Surface *ecran,personne p22);
void scrolling (background *b,int direction);
void animerBackground(background *b);
void displaybird(background b,SDL_Surface *ecran);
void sauvegarder(int score,char nomfichier[]);
void meilleur (char nomfichier[],background *b);
void afficher28(background b,SDL_Surface *ecran);
void affichageMeilleur(SDL_Surface *screen,background b);
void afficherBack_partage(background b, SDL_Surface *screen);


#endif  
