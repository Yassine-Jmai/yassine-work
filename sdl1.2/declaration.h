#ifndef DEFINITION_H_INCLUDED
#define DEFINITION_H_INCLUDED
#include <SDL/SDL.h>

typedef struct
{
  char quest[100];
  char rep1[100];
  char rep2[100];
  char rep3[100];
  int bonrep;
  int numQuestSelect;
  int etat;
  SDL_Surface * surface_question;
  SDL_Surface * surface_reponse1;
  SDL_Surface * surface_reponse2;
  SDL_Surface * surface_reponse3;
  SDL_Rect pos_quest;
  SDL_Rect pos_rep1;
  SDL_Rect pos_rep2;
  SDL_Rect pos_rep3;
  SDL_Color couleur;
  TTF_Font *font;
}
enigme;

enigme generer(char *nomfich);

void afficherEnigme(enigme e, SDL_Surface *ecran);
int chargerEnigmes(enigme enigmes[], int maxEnigmas, char *nomfich);

void liberer1(enigme e);


#endif // DEFINITION_H_INCLUDED
