/*
 * event_test.hpp
 *
 *  Created on: 23-03-2011
 *      Author: lukasz
 */

#ifndef EVENT_TEST_HPP_
#define EVENT_TEST_HPP_

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "SDL/SDL.h"

#include "inherit_templates.hpp"
#include "common_dev.hpp"

using std::string;
using std::cout;
using std::endl;

class event_test: public _sdl_window{
	public:
		event_test();
		~event_test();
		void run();
		void EventLoop();
	private:
		SDL_Event event;
};

#endif /* EVENT_TEST_HPP_ */
