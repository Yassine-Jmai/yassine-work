#include <stdio.h>
#include "background.h"
#include "back.h"
#include "button.h"
#include "es.h"
#include "pers.h"
#include "map.h"
#include "time.h"
#include"collisionparfaite.h"
#include <SDL/SDL_mixer.h>
#include "declaration.h"


#define NUM_IMAGES 9

int main(int argc, char **argv) {
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER);

    SDL_Surface *ecran,*backgg,*backgm,*enig;
    int done = 1, mode = 0, i = 0, f = 1, s = 0, h, score = 0,dirc=-1,min=500,max=800,di;
    Image backg, B1, B2, B3, B4, B11, B21, B31, B41, n, lg, pb, n1, lg1, sb, so, fu, w, fu1, w1, p, mc, mq, yes, yes1, no, no1, x1,ee,select;
    SDL_Event e,event;
    Mix_Chunk *cs;
    es enem,animer,move,fire,coll,health;
    SDL_Rect pos11,pos, backg_pos,backgm_pos,enigpos;
    personne pers,per;
	background ba;

int collisionResult,colls;
	Time temps;
	Time tempsenig;
	map m;
//enigme//
 enigme en;
  en.etat = 0; //initialiser l'état de l'énigme (0 = non résolu)
    int rep = -1;
 SDL_Surface* img1;
    SDL_Surface* img2;
 
    SDL_Rect pos1;
    SDL_Rect pos2;
    TTF_Font* font;
enigme enigmes[4]; // Array to store multiple enigmas
    int numEnigmas = 0;          // Number of enigmas loaded from the file
    char enigm[20];int ii;
     SDL_Surface *timer[8];
Uint32 startTime = SDL_GetTicks();
	

    ecran = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_SWSURFACE | SDL_DOUBLEBUF);
    if (!ecran) {
        printf("Failed to create window: %s\n", SDL_GetError());
        return 1;
    }

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        printf("Failed to initialize SDL_image: %s\n", IMG_GetError());
        SDL_Quit();
        return 1;
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1) {
        printf("Failed to initialize audio: %s\n", Mix_GetError());
        SDL_Quit();
        return 1;
    }
 img1 = IMG_Load("img1.jpg");
    if (img1 == NULL) {
        printf("Erreur lors du chargement de l'image1 : %s\n", SDL_GetError());
        return 1;
    }
    
    img2 = IMG_Load("img2.jpg");
    if (img2 == NULL) {
        printf("Erreur lors du chargement de l'image2 : %s\n", SDL_GetError());
        return 1;
    }
    
    //Position de l'image de victoire 
    pos1.x = 950 ;
    pos1.y = 190 ;
    
    pos2.x = (ecran->w - img2->w) /2 ;
    pos2.y = (ecran->w - img2->w) /2 ;

    // Chargement des énigmes depuis le fichier
    en = generer("enigme.txt");
numEnigmas = chargerEnigmes(enigmes, 4, "enigme.txt");
    if (numEnigmas <= 0) {
        printf("Error: No enigmas loaded from file.\n");
        return 1;
    }
	







    Mix_Music *musique;
    musique = Mix_LoadMUS("o1.mp3");
    Mix_PlayMusic(musique, -1);
    cs = Mix_LoadWAV("c.wav");

	backgg = IMG_Load("backgg1.bmp");
	backg_pos.x = 0;
	backg_pos.y = 0;
	backgm = IMG_Load("mapMasque.bmp");
	backg_pos.x = 0;
	backg_pos.y = 0;

    // Initialize all images and other resources
    initBackground(&backg);
    initplay(&B1);
    initplay1(&B11);
    initsettings(&B2);
    initsettings1(&B21);
    initcredit(&B3);
    initcredit1(&B31);
    initquit(&B4);
    initquit1(&B41);
    newgame(&n);
    newgame1(&n1);
    loadgame(&lg);
    loadgame1(&lg1);
    initBackground1(&pb);
    initBackground2(&sb);
    sound(&so);
    full(&fu);
    wind(&w);
    full1(&fu1);
    wind1(&w1);
    point(&p);
    initBackground3(&mc);
    initBackground4(&mq);
    yess(&yes);
    yess1(&yes1);
    noo(&no);
    noo1(&no1);
    xx(&x1);
    initBackground5(&ee);
    initselect(&select);
    init_es(&enem);
    init_ff(&fire);
    initialiserperso(&pers);
deplacer_perso(&pers,&e);
 init_health(&health);
	inittemps(&temps);
	inittempsenig(&tempsenig);
	initialiser_map (&m,ecran) ;
	
	initBack2(&ba);
	initbouton(&ba);
	

    SDL_Surface *animationImages[NUM_IMAGES];
    for (int h = 0; h < NUM_IMAGES; h++) {
        char filename[50];
        sprintf(filename, "fire%d.png", h + 1);
        animationImages[h] = IMG_Load(filename);
        if (animationImages[h] == NULL) {
            printf("Error loading animation image %d: %s\n", h, IMG_GetError());
            // Handle error if needed
        }
    }

    // Animation loop
    int currentImageIndex = 0;
    SDL_Rect animationPos;
    animationPos.x = 1010;
    animationPos.y = 70;
    animationPos.w = animationImages[0]->w;
    animationPos.h = animationImages[0]->h;

    // Main loop
    while (done) {


if(mode==0){
       
        // Blit the current animation frame onto the background
        SDL_BlitSurface(animationImages[currentImageIndex], NULL, ecran, &animationPos);

        // Update the display
        SDL_Flip(ecran);}

        // Increment current image index for next frame
        currentImageIndex = (currentImageIndex + 1) % NUM_IMAGES;

        // Add a delay to control animation speed
      SDL_Delay(200); 

        while (SDL_PollEvent(&e)) {
            switch (e.type) {
 
                case SDL_QUIT:
                    done = 0;
                    break;
         case SDL_MOUSEBUTTONUP: 
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                  if (event.button.x >0 && event.button.x < 400 && event.button.y > 550 && event.button.y <850)
                   {
			//affichageMeilleur(ecran,ba);
                   }
               }
		break;
                case SDL_MOUSEMOTION:
                    // Handle mouse motion events based on the current mode
                    if (mode == 0) {
                        handleMouseMotion(&e, &B1);
                        handleMouseMotion(&e, &B2);
                        handleMouseMotion(&e, &B3);
                        handleMouseMotion(&e, &B4);
                    } else if (mode == 1) {
                        handleMouseMotion(&e, &n);
                        handleMouseMotion(&e, &lg);
                    } else if (mode == 2) {
                        handleMouseMotion(&e, &fu);
                        handleMouseMotion(&e, &w);
                    } else if (mode == 4) {
                        handleMouseMotion(&e, &yes);
                        handleMouseMotion(&e, &no);
                    }
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    // Handle mouse button clicks
                    handMouseClicks(&e, &mode, &done, B1, B2, B3, B4, cs, &p, yes, no, x1, fu, ecran, w,n,lg,select);
                    break;

                case SDL_KEYDOWN:

if(mode==6){
  deplacer_perso(&pers, &e);
                    if (e.key.keysym.sym == SDLK_RIGHT) {
      scrolling (&ba,0);
enem.pos.x-=20;
fire.pos11.x-=20;
max-=20;
min-=20;

}
                if (e.key.keysym.sym == SDLK_LEFT) {
enem.pos.x+=20;
fire.pos11.x+=20;
max+=20;
min+=20;

      scrolling (&ba,1);}
                if (e.key.keysym.sym == SDLK_UP) {
      scrolling (&ba,2);}
                if (e.key.keysym.sym == SDLK_DOWN) {
      scrolling (&ba,3);}
//en.etat=0;
if (pers.pos_perso.x==700 && (en.etat!=1 || en.etat!=-1  )&&pers.pos_perso.y==20) {

	int randomIndex = rand() % 4;
        en = enigmes[randomIndex];
        afficherEnigme(en, ecran);
        for(ii=1;ii<8;ii++){
        sprintf(enigm,"timer/timer.%d.png",ii);
       timer[ii]=IMG_Load(enigm);
        SDL_BlitSurface(timer[ii],NULL,ecran,&pos1);
        SDL_Flip(ecran);
	SDL_Delay(1000);
        }
      
   
SDL_WaitEvent(&event);


if (rep == en.bonrep) {

               en.etat = 1;



        } 
        else{
 
               en.etat = -1;


               //SDL_Delay(1000);
              // SDL_Flip(ecran);
        }
        if(en.etat==1){
               int i;
for (i = 0; i < 2; i++) {
    SDL_BlitSurface(img1, NULL, ecran, &pos2); 
    SDL_Flip(ecran);
    SDL_Delay(1000);

}
mode=5;
}
else if(en.etat==-1){
     int j;
for (j = 0; j < 2; j++) {
    SDL_BlitSurface(img2, NULL, ecran, &pos2); 
    SDL_Flip(ecran);
    SDL_Delay(1000);

}mode=5;
}}
     if (e.key.keysym.sym == SDLK_a) {
                            
                            rep = 1;
printf("ssssssssss");
fflush(stdout);} // Réponse 1	
                            
                       if (e.key.keysym.sym == SDLK_b) {
                          
                            rep = 2;} // Réponse 2
                           
                          if (e.key.keysym.sym == SDLK_c) {
                            
                            rep = 3; }// Réponse 3
                          

}
  case SDLK_k:{
		
		
		SDL_BlitSurface(enig,NULL,ecran,&enigpos);
		displaytime(tempsenig,ecran);
		SDL_Flip(ecran);
		if(tempsenig.ss==temps.ss+15)
		{
                  done=0;
		}
		}
                break ;
 

                    // Handle key presses
                    if (e.key.keysym.sym == SDLK_ESCAPE) {
                        if (mode == 0)
                            mode = 4;
                        else
                            mode = 0;
                    }if(mode==0){
                    if (e.key.keysym.sym == SDLK_DOWN) {
                        Mix_PlayChannel(-1, cs, 0);
                        if (mode == 0) {
                            if (i == 4) {
                                i = 0;
                            }
                            i++;
                        }
                        if (mode == 1) {
                            if (i == 3) {
                                i = 1;
                            }
                            i++;
                        }
			
                    }
                    if (e.key.keysym.sym == SDLK_UP) {
                        Mix_PlayChannel(-1, cs, 0);
                        if (mode == 0) {
                            if (i == 1) {
                                i = 5;
                            }
                            i--;
                        }
                        if (mode == 1) {
                            if (i == 0) {
                                i = 2;
                            }
                            i--;
                        }
			
                    }
                    if (e.key.keysym.sym == SDLK_RIGHT) {
                        s++;
                        Mix_PlayChannel(-1, cs, 0);
                        if (s == 3)
                            s = 1;
			
                    }
                    if (e.key.keysym.sym == SDLK_LEFT) {
                        s--;
                        Mix_PlayChannel(-1, cs, 0);
                        if (s == 0)
                            s = 2;

			
                    }}
                    if (e.key.keysym.sym == SDLK_RETURN) {
                        if (i == 1)
                            mode = 1;
                        else if (i == 2)
                            mode = 2;
                        else if (i == 3)
                            mode = 3;
                        else
                            mode = 4;
                        if (s == 2)
                            mode = 0;
                        else if (s == 1)
                            done = 0;
                    }
                    if (e.key.keysym.sym == SDLK_f)
                        if (f == 1) {
                            f = 2;
                            ecran = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_SWSURFACE | SDL_FULLSCREEN);
                        } else {
                            f = 1;
                            ecran = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_SWSURFACE);
                        }
 		if(e.key.keysym.sym == SDLK_p){
 			mode=1;

}
 		if(e.key.keysym.sym == SDLK_s){
 			mode=2;

}
 		if(e.key.keysym.sym == SDLK_c){
 			mode=3;

}
 		if(e.key.keysym.sym == SDLK_q){
 			mode=4;

}
	
                    break;


 
            }
        }


        // Render the appropriate display based on the current mode
        if (mode == 0) {
            mainMenu_display(B1, B2, B3, B4, B11, B21, B31, B41, backg, ecran, &i);
        } else if (mode == 1) {
            play_display(pb, ecran, n, lg, n1, lg1, x1, &i);
        } else if (mode == 2) {
            settings_display(sb, ecran, so, fu, w, fu1, w1, p, x1);
        } else if (mode == 3) {
            credit_display(mc, ecran, x1);
        } else if (mode == 4) {
            quit_display(mq, yes, yes1, no, no1, ecran, &s);
        }
else if (mode == 5) {
            newgame_display(ee,select,ecran);}
else if (mode == 7) {
            select_display(ee,lg,ecran);}
else if (mode == 6) {

            loadgame_display(ee,health,pers,enem,pos11,pos,e,fire,m,temps,ecran, ba);
            

       printf("posx %d et  posy %d \n",pers.pos_perso.x,pers.pos_perso.y);
fflush(stdout);

// entite secondaire 
             
         
               animateEntity(&enem);
              // deplacer_es(&enem,max,min);
updateetat(&enem,di);

di=enem.pos.x-pers.pos_perso.x;
updateenemi(&enem,pers.pos_perso);
               collisionResult=collisionTri(&pers, &fire.pos11); 
               colls=collisionbb(pers,  &enem.pos);
//minimap//

		update_time(&temps);
		perso_map(&m,&pers);
		//SDL_BlitSurface(backgg,NULL,ecran,&backg_pos);
		
		displaytime(temps,ecran);

//backgound//
                scrolling (&ba,dirc);
		animerBackground(&ba);	
                        affichebouton(ba,ecran);	
                   if(pers.pos_perso.x<590)
                   {
                    score=2500;
                   }
                  else if(590 <pers.pos_perso.x<650)
                    {
                       score=670;
                    }


            }



        // Update the display
        SDL_Flip(ecran);
    }

	sauvegarder(score,"test.txt");
    // Free all allocated resources
    liberer(backg);
    liberer(B1);
    liberer(B11);
    liberer(B2);
    liberer(B21);
    liberer(B3);
    liberer(B31);
    liberer(B4);
    liberer(B41);
    liberer(n);
    liberer(n1);
    liberer(lg);
    liberer(lg1);
    liberer(pb);
    liberer(sb);
    liberer(so);
    liberer(fu);
    liberer(w);
    liberer(fu1);
    liberer(w1);
    liberer(p);
    liberer(mc);
    liberer(mq);
    liberer(yes);
    liberer(yes1);
    liberer(no);
   freeTexttime(temps.temps);
	free_perso(pers);
	SDL_Quit();



    // Free the loaded music and sound effect
    Mix_FreeMusic(musique);
    Mix_FreeChunk(cs);

    // Close the audio system and quit SDL
    Mix_CloseAudio();
    IMG_Quit();
    SDL_Quit();

    return 0;
}

