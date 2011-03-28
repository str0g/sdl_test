/*
 * smartSurface.cpp
 *
 *  Created on: 25-03-2011
 *      Author: lukasz
 */

#include "../include/smartSurface.hpp"

inline SDL_Surface *getSurfaceCopy(SDL_Surface *_surface){
	return SDL_ConvertSurface(_surface, _surface->format, SDL_SWSURFACE);
}

smartSurface::smartSurface(const char* ccPath): sdlSurface(IMG_Load(ccPath)){
	if(!sdlSurface)
		msg(SDL_GetError());
}
smartSurface::smartSurface(SDL_Surface * _surface): sdlSurface(_surface){
	if(!sdlSurface)
		msg("Received empty surface");
}
smartSurface::smartSurface(): sdlSurface(NULL){
	msg("Initializing empty surface");
}
smartSurface::~smartSurface(){
	SDL_FreeSurface(sdlSurface);
}
void smartSurface::operator=(SDL_Surface *_surface){
	SDL_FreeSurface(sdlSurface);
	sdlSurface =  _surface; //SDL_ConvertSurface(_surface, _surface->format, SDL_SWSURFACE);
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
