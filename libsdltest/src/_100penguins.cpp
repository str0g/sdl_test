/*
 * 100penguins.cpp
 *
 *  Created on: 05-04-2011
 *      Author: lukasz
 *		Home:	http://str0g.wordpress.com
 *		License:GNU/GPL v2
 */

#include "../include/_100penguins.hpp"

_100penguins::_100penguins():background(PENGUIN_BACKGROUND){
}

void _100penguins::init_penguins(){
	assert(screen.sdlSurface!=NULL);
	for (int i = 0; i < NUM_PENGUINS; i++) {
		penguins[i].x = rand() % screen->w;
		penguins[i].y = rand() % screen->h;
		penguins[i].dx = (rand() % (MAX_SPEED * 2)) - MAX_SPEED;
		penguins[i].dy = (rand() % (MAX_SPEED * 2)) - MAX_SPEED;
	}
}

/* This routine moves each penguin by its motion vector. */
void _100penguins::move_penguins(){
	for (int i = 0; i < NUM_PENGUINS; i++) {
		/* Move the penguin by its motion vector. */
		penguins[i].x += penguins[i].dx;
		penguins[i].y += penguins[i].dy;
		/* Turn the penguin around if it hits the edge of the screen. */
		if (penguins[i].x < 0 || penguins[i].x > screen->w - 1)
			penguins[i].dx = -penguins[i].dx;
		if (penguins[i].y < 0 || penguins[i].y > screen->h - 1)
			penguins[i].dy = -penguins[i].dy;
	}
}

/* This routine draws each penguin to the screen surface. */
void _100penguins::draw_penguins(SDL_Surface *sdlsurface){
	if (!sdlsurface)
		return;

	SDL_Rect src, dest;
	for (int i = 0; i < NUM_PENGUINS; i++) {
		src.x = 0;
		src.y = 0;
		src.w = sdlsurface->w;
		src.h = sdlsurface->h;

		/* The penguin’s position specifies its
		center. We subtract half of its width
		and height to get its upper left corner. */
		dest.x = penguins[i].x - sdlsurface->w / 2;
		dest.y = penguins[i].y - sdlsurface->h / 2;
		dest.w = sdlsurface->w;
		dest.h = sdlsurface->h;
		SDL_BlitSurface(sdlsurface, &src, screen.sdlSurface, &dest);
	}
}


void _100penguins::run(){
	SDL_Rect src, dest;
	time_t start,end;
	penguinAlfa.loadAnyImage(PENGUIN_ALPHA);
	penguinNoAlfa.loadAnyImage(PENGUIN_NOALPHA);
	/* Set the penguin’s colorkey. */
	SDL_SetColorKey(penguinAlfa.sdlSurface,
			SDL_SRCCOLORKEY,
			(Uint16) SDL_MapRGB(penguinAlfa->format,
					0, 0, 0));
	SDL_SetColorKey(penguinNoAlfa.sdlSurface,
			SDL_SRCCOLORKEY,
			(Uint16) SDL_MapRGB(penguinAlfa->format,
					0, 0, 0));
	/* Initialize the penguin position data. */
	setVideoMode(800,600,24,0);
	init_penguins();
	/* Animate 300 frames (approximately 10 seconds). */
	time (&start);
	for (int frames = 0; frames < MAX_FRAMES; frames++) {
		/* Draw the background image. */
		src.x = 0;
		src.y = 0;
		src.w = background->w;
		src.h = background->h;
		dest = src;
		SDL_BlitSurface(background.sdlSurface, &src, screen.sdlSurface, &dest);

		/* Put the penguins on the screen. */
		if(frames%2==1)
			draw_penguins(penguinAlfa.sdlSurface);
		else
			draw_penguins(penguinNoAlfa.sdlSurface);
		/* Ask SDL to update the entire screen. */
		SDL_UpdateRect(screen.sdlSurface, 0, 0, 0, 0);
		/* Move the penguins for the next frame. */
		move_penguins();
	}
	time (&end);
	//std::cout.setf(0,std::ios::floatfield);
	std::cout.precision(FLOAT_PRECISION);
	msg(MAX_FRAMES<<" frames has been rendered in:"<<difftime(end,start)<<"s , rendered speed: "<<MAX_FRAMES/difftime(end,start)<<"fps");
}
