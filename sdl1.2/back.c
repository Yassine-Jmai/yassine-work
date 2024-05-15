#include "back.h"
#include "pers.h"
#include <SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>

void initBack2 (background *b)
{

b->imgback=IMG_Load("bg");

b->posback2.x=0;
b->posback2.y=0;
b->camera2.x=0;
b->camera2.y=0;
b->camera2.w=SCREEN_W; 
b->camera2.h=SCREEN_H;

       
	b->image_bird=IMG_Load("bird.png");  
	b->pos_image_bird.x=500;
	b->pos_image_bird.y=100;
	b->single_bird.w=56;
	b->single_bird.h=107;
	b->single_bird.x=0;
	b->single_bird.y=0;
	b->bird_num=0;




  b->vies = IMG_Load("HEARTS.png");
  b->posVie1.x = 0;
  b->posVie1.y = 0;
  b->vie = 100;

  b->posVie2.x = 0;
  b->posVie2.y = 0;
  b->posVie2.h = 26;
  b->posVie2.w = 116;

  TTF_Init();
  b->police = TTF_OpenFont("font.ttf", 40);

  b->score = 10;
  b->posScore.x = 0;
  b->posScore.y = 50;

}

void initbouton(background *b)
{

b->boutton= IMG_Load("boutton.png");
b->positionbotton.x =0;
b->positionbotton.y =550;
}
void affichebouton(background b,SDL_Surface *screen)
{

SDL_BlitSurface(b.boutton, NULL, screen, &b.positionbotton);
}


void afficheBack2(background b, SDL_Surface *ecran, personne p22)
{
    
       

    
    SDL_BlitSurface(b.imgback, &b.camera2, ecran, &b.posback2);

    displaybird(b, ecran);

    SDL_BlitSurface(b.vies, &(b.posVie2), ecran, &(b.posVie1));

    if (b.vie >= 100)
    {
        b.posVie2.y = 0;
    }
    else if (b.vie >= 75 && b.vie < 100)
    {
        b.posVie2.y = 25;
    }
    else if (b.vie >= 50 && b.vie < 75)
    {
        b.posVie2.y = 50;
    }
    else if (b.vie >= 25 && b.vie < 50)
    {
        b.posVie2.y = 77;
    }
    else if (b.vie >= 0 && b.vie < 25)
    {
        b.posVie2.y = 103;
    }

    SDL_Color couleur = {255, 255, 255};
    char s[20];
    char m[20];
    sprintf(s, "Score: %d", b.score);
  
    
    

    b.scores = TTF_RenderText_Blended(b.police, s, couleur);
    SDL_BlitSurface(b.scores, NULL, ecran, &(b.posScore));
}


void scrolling(background *b, int direction)
{
  const int speed = 20;

  if (direction == 0) // imin
  {
    if ((b->camera2.x < 4631 - b->camera2.w)) 
    {
      b->camera2.x = b->camera2.x + speed;
    }
  }
  else if (direction == 1) // isar
  {
    if ((b->camera2.x > 0)) 
    {
      b->camera2.x -= speed;
    }
  }
  else if (direction == 2) // lfou9
  {
    if ((b->camera2.y >0)) 
    {
      b->camera2.y -= speed;
    }
  }
  else if (direction == 3) // louta
  {
    if ((b->camera2.y < 842 - b->camera2.h)) 
    {
      b->camera2.y += speed;
    }
  }
}


void displaybird(background b,SDL_Surface *ecran){
			
 		SDL_BlitSurface(b.image_bird,&(b.single_bird), ecran, &b.pos_image_bird);
}
void animerBackground(background *b){
		 	
	if (b->bird_num >=0 && b->bird_num <8) {
	b->single_bird.x=b->bird_num * b->single_bird.w;
	b->bird_num++;
	}
        if ( b->bird_num == 8) {
	b->single_bird.x=b->bird_num * b->single_bird.w;
	b->bird_num=0;
	}
	
	
 
	 
}


void sauvegarder(int score,char nomfichier[])
{
	FILE *f;
        int i=0;
	f=fopen(nomfichier, "a");
	if(f==NULL){
        printf("Erreur lors de l'ouverture d'un fichier");
	
       }
 	fprintf(f, "%d\n", score);
	fclose(f);
}

void meilleur (char nomfichier[],background *b)
{
TTF_Init();
int i=0;
FILE *f;
char text1[30];
char text2[30];
char text3[30];
      int tmp;
    int tab[50];
    f = fopen("test.txt", "r");

 if(f==NULL)
	{
        printf("Erreur lors de l'ouverture d'un fichier");
        }
while(fscanf(f,"%d\n",&tab[i])==1)
{
	i++;
}
for(int j=0;j<i;j++) 
 	{printf("score : %d\n", tab[j]);
}
    	fclose(f);


 for (int k=0 ; k < i-1; k++)
  {
    for (int j=0 ; j < i-k-1; j++)
    {
      
      if (tab[j] > tab[j+1]) 
      {
        tmp = tab[j];
        tab[j] = tab[j+1];
        tab[j+1] = tmp;
      }
    }
  }

for(int j=0;j<i;j++) 
 	{printf(" tri score : %d\n", tab[j]);
}
printf("i est  %d\n",i);
sprintf(text1, "%d",tab[i-1]);
sprintf(text2, "%d",tab[i-2]);
sprintf(text3, "%d",tab[i-3]);

printf("text1 est  %s\n",text1);
printf("text2 est  %s\n",text2);
printf("text3 est  %s\n",text3);



	SDL_Color couleur = {0,0,0}; 
	SDL_Color couleur1 = {255,0,0}; 

	(*b).police = TTF_OpenFont("pol.ttf", 30);
 	b->reponses[0]=TTF_RenderText_Blended(b->police,text1, couleur); 
 	b->reponses[1]=TTF_RenderText_Blended(b->police,text2, couleur); 
 	b->reponses[2]=TTF_RenderText_Blended(b->police,text3, couleur); 
        b->reponses[3]=TTF_RenderText_Blended(b->police,"les 3 meilleurs scores:", couleur1); 
        b->pos_reponse1txt.x=50; 
	b->pos_reponse1txt.y=300;
	b->pos_reponse2txt.x=50;
	b->pos_reponse2txt.y=400;
	b->pos_reponse3txt.x=50;
	b->pos_reponse3txt.y=500;
        b->pos_meilleurtxt.x=50;
        b->pos_meilleurtxt.y=200;
}
   

void afficher28(background b,SDL_Surface *ecran)
{

 SDL_BlitSurface(b.reponses[0], NULL, ecran, &b.pos_reponse1txt);
 SDL_BlitSurface(b.reponses[1], NULL, ecran, &b.pos_reponse2txt);
 SDL_BlitSurface(b.reponses[2], NULL, ecran, &b.pos_reponse3txt);
 SDL_BlitSurface(b.reponses[3], NULL, ecran, &b.pos_meilleurtxt);
   SDL_Flip(ecran);
}


void affichageMeilleur(SDL_Surface *screen,background b)
{
    SDL_Surface *NGame = NULL;

    SDL_Rect positionNGame;

    SDL_Event event;

    int continuer = 1;

    NGame = IMG_Load("NewGame.jpg");

    positionNGame.x = 0;
    positionNGame.y = 0;
    while (continuer)
    {

        SDL_PollEvent(&event);

        switch (event.type)
        {
        case SDL_QUIT:
            continuer = 0;
            screen = SDL_SetVideoMode(1360,765, 32, SDL_HWSURFACE | SDL_DOUBLEBUF); 
            SDL_WM_SetCaption("Game Menu", NULL);
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                continuer = 0;
                screen = SDL_SetVideoMode(1360,765, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
                SDL_WM_SetCaption("Game Menu", NULL);
                break;
            }
            break;
        }
        SDL_BlitSurface(NGame, NULL, screen, &positionNGame);
        afficher28(b,screen);
        SDL_Flip(screen);
    }
}

void afficherBack_partage(background b, SDL_Surface *screen){
SDL_Rect pos={500,0,700,700};
SDL_BlitSurface(b.imgback,&b.posback2, screen, NULL);
SDL_BlitSurface(b.imgback,&b.posback2, screen,&pos);
}









