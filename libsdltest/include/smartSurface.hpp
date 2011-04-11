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

//Universal methods
inline SDL_Surface *getSurfaceCopy(SDL_Surface *);

struct smartSurface{
	//variable
	SDL_Surface *sdlSurface;
	bool bClean;
	//constructors
	smartSurface(const char*);
	smartSurface(SDL_Surface*);
	smartSurface();
	~smartSurface();
	//is
	bool isNULL();
	//set
	void setCleanFlag();
	//methods
	void loadAnyImage(const char*);
	//operators
	void operator=(SDL_Surface*);
	SDL_Surface *operator->();
	friend std::ostream &operator<<(std::ostream &out, const smartSurface &sS);
};

#endif /* SMARTSURFACE_HPP_ */
