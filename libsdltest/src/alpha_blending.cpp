/*
 * alpha_blending.cpp
 *
 *  Created on: 23-03-2011
 *      Author: lukasz
 */

#include "../include/alpha_blending.hpp"

alpha_blending::alpha_blending():background(BACKGROUND),
								image_with_alpha(ALPHAFILE_PNG),
								image_without_alpha(NOALPHAFILE)
								{
}

alpha_blending::~alpha_blending(){
	msg(background)
	msg(image_with_alpha)
	msg(image_without_alpha)
	msg("Bye")
}

void alpha_blending::run(){
	cout<<"Running"<<endl;
	if(setVideoMode(600,400,24)){
		this->drawBackground();
		/** Draw the first image, which has an alpha
		* channel. We must specifically enable alpha
		* blending. */
		this->drawAlpha(image_with_alpha.sdlSurface,0,20,128);
		/** Draw the second image, which has no alpha
		* channel. Instead, we will set a 50% transparency
		* factor for the entire surface. */
		this->drawAlpha(image_without_alpha.sdlSurface,280,200,128);

		this->redraw();
	}
}

void alpha_blending::drawBackground(){
	/** Draw the background. */
	if(!background.sdlSurface)
		return;
	msg("Background size "<<background.sdlSurface->w<<"x"<<background.sdlSurface->h)
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

void alpha_blending::drawAlpha(SDL_Surface *sdlSurface , int destx, int desty, int AlphaStrenght){
	if(!sdlSurface){
		return;
	}
	msg("alpha size "<<sdlSurface->w<<"x"<<sdlSurface->h);
	SDL_SetAlpha(sdlSurface, SDL_SRCALPHA, AlphaStrenght);
	src.w = sdlSurface->w;
	src.h = sdlSurface->h;
	dest.w = src.w;
	dest.h = src.h;
	dest.x = destx;
	dest.y = desty;
	SDL_BlitSurface(sdlSurface, &src, screen.sdlSurface, &dest);
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
