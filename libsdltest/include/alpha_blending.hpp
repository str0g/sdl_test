/*
 * alpha_blending.hpp
 *
 *  Created on: 23-03-2011
 *      Author: lukasz
 */

#ifndef ALPHA_BLENDING_HPP_
#define ALPHA_BLENDING_HPP_

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

#include "inherit_templates.hpp"
#include "smartSurface.hpp"
#include "common_dev.hpp"

using std::cout;
using std::endl;

#define ALPHAFILE_PNG 	"../data/bitmaps/alpha.png"
#define NOALPHAFILE 	"../data/bitmaps/noalpha.bmp"
#define BACKGROUND 		"../data/bitmaps/background.bmp"

class alpha_blending: public _sdl_window{
	public:
		alpha_blending();
		~alpha_blending();
		virtual void run();
	private:
		smartSurface background;
		smartSurface image_with_alpha;
		smartSurface image_without_alpha;
		SDL_Rect src, dest;
		void drawBackground();
		void drawAlpha(SDL_Surface *,int,int,int);
		void redraw();
};

#endif /* ALPHA_BLENDING_HPP_ */
