/*
 * 100penguins.hpp
 *
 *  Created on: 05-04-2011
 *      Author: lukasz
 *		Home:	http://str0g.wordpress.com
 *		License:GNU/GPL v2
 */

#ifndef _100PENGUINS_HPP_
#define _100PENGUINS_HPP_


#include <cstdio>
#include <cstdlib>
#include <SDL/SDL.h>
#include "SDL/SDL_image.h"
#include <ctime>
#include <cassert>

#include "inherit_templates.hpp"
#include "common_dev.hpp"

#define NUM_PENGUINS 		15
#define MAX_SPEED 			6
#define MAX_FRAMES			300
#define FLOAT_PRECISION 	5
#define PENGUIN_BACKGROUND 	"../data/bitmaps/100penguins/background.bmp"
#define PENGUIN_ALPHA		"../data/bitmaps/100penguins/rocket_tux_alpha.png"
#define PENGUIN_NOALPHA		"../data/bitmaps/100penguins/rocket_tux_noalpha.png"


/* This structure stores the information for one
on-screen penguin. */
typedef struct penguin_s {
	int x, y;
	/* position on the screen */
	int dx, dy;
} penguin_t, *penguin_p;

class _100penguins : public _sdl_window{

	/* movement vector */
	/* Array of penguins. */
	penguin_t penguins[NUM_PENGUINS];
	/* This routine loops through the array of penguins and
	sets each to a random starting position and direction. */
	int intPenguinsOffsetX;
	int intPenguinsOffsetY;
	public:
		_100penguins();
		~_100penguins();
		void run();
		void draw_penguins(SDL_Surface*);
		void move_penguins();
		void init_penguins();
};

#endif /* _100PENGUINS_HPP_ */
