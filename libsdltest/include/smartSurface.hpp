/*
 * smartSurface.hpp
 *
 *  Created on: 25-03-2011
 *      Author: lukasz
 */

#ifndef SMARTSURFACE_HPP_
#define SMARTSURFACE_HPP_


#include <iostream>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

#include "common_dev.hpp"

struct smartSurface{
	SDL_Surface *sdlSurface;
	smartSurface(const char*);
	smartSurface(SDL_Surface*);
	smartSurface();
	~smartSurface();
	inline void operator=(SDL_Surface*);
	void loadAnyImage(const char*);
	SDL_Surface *operator->();
	friend std::ostream &operator<<(std::ostream &out, const smartSurface &sS);
};

#endif /* SMARTSURFACE_HPP_ */
