/*
 * inherit_templates.hpp
 *
 *  Created on: 24-03-2011
 *      Author: lukasz
 */

#ifndef INHERIT_TEMPLATES_HPP_
#define INHERIT_TEMPLATES_HPP_

#include <iostream>
#include <cstdio>

#include "SDL/SDL.h"

#include "common_dev.hpp"
#include "smartSurface.hpp"

class _sdl_window{
	public:
		_sdl_window();
		virtual bool setVideoMode(int iWidth=320,int iHight=200, int iBitColor=24,int iUnknow=SDL_HWSURFACE|SDL_DOUBLEBUF);
		virtual void run();
		//virtual ~_sdl_window();
	protected:
		smartSurface screen;
};

#endif /* INHERIT_TEMPLATES_HPP_ */
