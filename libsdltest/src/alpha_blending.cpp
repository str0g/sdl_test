/*
 * alpha_blending.cpp
 *
 *  Created on: 23-03-2011
 *      Author: lukasz
 */

#include "../include/alpha_blending.hpp"

alpha_blending::alpha_blending(){
}

alpha_blending::~alpha_blending(){
	msg(image_without_alpha)
	msg(background)
	msg("Bye")
}

void alpha_blending::run(){
	cout<<"Running"<<endl;
	if(setVideoMode(600,400,16)){
		this->loadImages();
		this->drawBackground();
		this->drawalpha();
		this->drawWithOutalpha();
		this->redraw();
	}
}

void alpha_blending::loadImages(){
	/** Load the bitmap files. The first file was created with
	* an alpha channel, and the second was not. Notice that
	* we are now using IMG_Load instead of SDL_LoadBMP. */
	image_with_alpha.sdlSurface = IMG_Load(ALPHAFILE);
	if (image_with_alpha.sdlSurface == NULL) {
		msg(SDL_GetError())
	}
	image_without_alpha.sdlSurface = IMG_Load(NOALPHAFILE);
	if (image_without_alpha.sdlSurface == NULL) {
		msg(SDL_GetError())
	}
	background.sdlSurface = IMG_Load(BACKGROUND);
	if (background.sdlSurface == NULL) {
		msg(SDL_GetError())
	}
}

void alpha_blending::drawBackground(){
	/** Draw the background. */
	if(!background.sdlSurface)
		return;
	printf("Background size %dx%d",background.sdlSurface->w,background.sdlSurface->h);
	src.x = 0;
	src.y = 0;
	src.w = background.sdlSurface->w;
	src.h = background.sdlSurface->h;
	dest.x = 0;
	dest.y = 0;
	dest.w = background.sdlSurface->w;
	dest.h = background.sdlSurface->h;
	SDL_BlitSurface(background.sdlSurface, &src, screen.sdlSurface, &dest);
}

void alpha_blending::drawalpha(){
	/** Draw the first image, which has an alpha
	* channel. We must specifically enable alpha
	* blending. */
	if(!image_with_alpha.sdlSurface)
		return;
	printf("alpha size %dx%d",image_with_alpha.sdlSurface->w,image_with_alpha.sdlSurface->h);
	SDL_SetAlpha(image_with_alpha.sdlSurface, SDL_SRCALPHA, 128);
	src.w = image_with_alpha.sdlSurface->w;
	src.h = image_with_alpha.sdlSurface->h;
	dest.w = src.w;
	dest.h = src.h;
	dest.x = 0;
	dest.y = 20;
	SDL_BlitSurface(image_with_alpha.sdlSurface, &src, screen.sdlSurface, &dest);
}

void alpha_blending::drawWithOutalpha(){
	/** Draw the second image, which has no alpha
	* channel. Instead, we will set a 50% transparency
	* factor for the entire surface. */
	if(!image_without_alpha.sdlSurface)
		return;
	printf("alpha size %dx%d",image_without_alpha.sdlSurface->w,image_without_alpha.sdlSurface->h);
	SDL_SetAlpha(image_without_alpha.sdlSurface, SDL_SRCALPHA, 128);
	src.w = image_without_alpha.sdlSurface->w;
	src.h = image_without_alpha.sdlSurface->h;
	dest.w = src.w;
	dest.h = src.h;
	dest.x = 330;
	dest.y = 20;
	SDL_BlitSurface(image_without_alpha.sdlSurface, &src, screen.sdlSurface, &dest);
}

void alpha_blending::redraw(){
	/** Ask SDL to update the entire screen. */
	SDL_UpdateRect(screen.sdlSurface, 0, 0, 0, 0);
	//SDL_Flip(screen);
	/** Pause for a few seconds as the viewer gasps in awe. */
	//SDL_Delay(3000);
	while (SDL_WaitEvent(&event) != 0 and !EventLoopOver) {
		switch(event.type){
			case SDL_KEYDOWN:
				if(event.key.keysym.sym == SDLK_ESCAPE)
					EventLoopOver=true;
				break;

			case SDL_QUIT:
				msg("Killed by x\n Bye.")
				exit(0);
		}
	}
}
