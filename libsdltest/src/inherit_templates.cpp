/*
 * inherit_templates.cpp
 *
 *  Created on: 24-03-2011
 *      Author: lukasz
 */

#include "../include/inherit_templates.hpp"

_sdl_window::_sdl_window(): EventLoopOver(false){
}

_sdl_window::~_sdl_window(){
//	SDL_FreeSurface(screen);
}

bool _sdl_window::setVideoMode(int iWidth, int iHight, int iBitColor, int iUnknown){
	/** Attempt to set a 320x200 hicolor (16-bit) video mode. */
	msg("Setting SDL window mode")
	screen = SDL_SetVideoMode(iWidth, iHight, iBitColor, iUnknown);
	if (screen.isNULL()) {
		msg("Unable to set video mode: "<< SDL_GetError());
		return false;
	}
	return true;
}

void _sdl_window::run(){
	if(setVideoMode())
		EventLoop();
}

void _sdl_window::EventLoop(){
	while(SDL_WaitEvent(&event) and !EventLoopOver){
		switch(event.type){
			case SDL_KEYDOWN:
				if(event.key.keysym.sym == SDLK_ESCAPE)
					EventLoopOver=true;
				break;
		}
	}
}
