/*
 * smartSurface.cpp
 *
 *  Created on: 25-03-2011
 *      Author: lukasz
 */

#include "../include/smartSurface.hpp"

//Universal methods
inline SDL_Surface *getSurfaceCopy(SDL_Surface *_surface){
	return SDL_ConvertSurface(_surface, _surface->format, SDL_SWSURFACE);
}
//constructors
smartSurface::smartSurface(const char* ccPath): sdlSurface(IMG_Load(ccPath)),bClean(true){
	if(isNULL())
		msg(SDL_GetError())
}
smartSurface::smartSurface(SDL_Surface * _surface): sdlSurface(_surface),bClean(true){
	if(isNULL())
		msg("Received empty surface");
}
smartSurface::smartSurface(): sdlSurface(NULL),bClean(true){
	msg("Initializing empty surface");
}
smartSurface::~smartSurface(){
	if(bClean != true){
		msg("cleaning")
		SDL_FreeSurface(sdlSurface);
	}
}
//is
bool smartSurface::isNULL(){
	return (sdlSurface==NULL);
}
//set
void smartSurface::setCleanFlag(){
	bClean = !bClean;
}
//methods
void smartSurface::loadAnyImage(const char *path){
	if(! isNULL())
		SDL_FreeSurface(sdlSurface);
	sdlSurface = IMG_Load(path);
	if(isNULL())
		msg(SDL_GetError())
}
//Operators
void smartSurface::operator=(SDL_Surface *_surface){
	SDL_FreeSurface(sdlSurface);
	sdlSurface =  _surface; //SDL_ConvertSurface(_surface, _surface->format, SDL_SWSURFACE);
}

SDL_Surface *smartSurface::operator->(){
	return sdlSurface;
}

std::ostream &operator<<(std::ostream &out,const smartSurface &Ss){
	if(Ss.sdlSurface){
		out<< "Surfsize: "<< Ss.sdlSurface->w <<"x"<< Ss.sdlSurface->h <<
			" Depth:" <<Ss.sdlSurface->format_version<<
			" isLocked:"<<Ss.sdlSurface->locked<<
			" MemSize:"<<sizeof(*Ss.sdlSurface)<<" bajt";
	}else{
		out<<"surface(null)";
	}
	return out;
}
