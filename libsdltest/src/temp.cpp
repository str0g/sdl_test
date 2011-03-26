/*
 * temp.cpp
 *
 *  Created on: 25-03-2011
 *      Author: lukasz
 */

#include <SDL/SDL.h>
//#include <SDL_image/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
struct temp{
 temp(){
	SDL_Surface *screen;

	SDL_Surface *background;
	SDL_Surface *image_with_alpha;
	SDL_Surface *image_without_alpha;
	SDL_Rect src, dest;

	/* Initialize SDL’s video system and check for errors. */
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
	printf("Unable to initialize SDL: %s\n", SDL_GetError());
	}
	/* Make sure SDL_Quit gets called when the program exits! */
	atexit(SDL_Quit);
	/* Attempt to set a 320x200 hicolor (16-bit) video mode. */
	screen = SDL_SetVideoMode(320, 200, 16, 0);
	if (screen == NULL) {
	printf("Unable to set video mode: %s\n", SDL_GetError());
	}
	/* Load the bitmap files. The first file was created with
	an alpha channel, and the second was not. Notice that
	we are now using IMG_Load instead of SDL_LoadBMP. */
	image_with_alpha = SDL_LoadBMP("with-alpha.png");
	if (image_with_alpha == NULL) {
		printf("%s\n", SDL_GetError());
	}
	image_without_alpha = SDL_LoadBMP("../data/bitmaps/noalpha.bmp");
	if (image_without_alpha == NULL) {
		printf("%s\n", SDL_GetError());
	}
	background = SDL_LoadBMP("background.png");
	if (background == NULL) {
		printf("%s\n", SDL_GetError());
	}
	if(background){
		/* Draw the background. */
		src.x = 0;
		src.y = 0;
		src.w = background->w;
		src.h = background->h;
		dest.x = 0;
		dest.y = 0;
		dest.w = background->w;
		dest.h = background->h;
		SDL_BlitSurface(background, &src, screen, &dest);
	}
	if(image_with_alpha){
		/* Draw the first image, which has an alpha
		channel. We must specifically enable alpha
		blending. */
		SDL_SetAlpha(image_with_alpha, SDL_SRCALPHA, 0);
		src.w = image_with_alpha->w;
		src.h = image_with_alpha->h;
		dest.w = src.w;
		dest.h = src.h;
		dest.x = 40;
		dest.y = 50;
		SDL_BlitSurface(image_with_alpha, &src, screen, &dest);
	}
	if(image_without_alpha){
		/* Draw the second image, which has no alpha
		channel. Instead, we will set a 50% transparency
		factor for the entire surface. */
		SDL_SetAlpha(image_without_alpha, SDL_SRCALPHA, 128);
		src.w = image_without_alpha->w;
		src.h = image_without_alpha->h;
		dest.w = src.w;
		dest.h = src.h;
		dest.x = 180;
		dest.y = 50;
		SDL_BlitSurface(image_without_alpha, &src, screen, &dest);
		/* Ask SDL to update the entire screen. */
	}
	SDL_UpdateRect(screen, 0, 0, 0, 0);
	/* Pause for a few seconds as the viewer gasps in awe. */
	SDL_Delay(3000);

	/* Free the memory that was allocated to the bitmaps. */
	SDL_FreeSurface(background);
	SDL_FreeSurface(image_with_alpha);
	SDL_FreeSurface(image_without_alpha);
}

};
