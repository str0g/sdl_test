/*
 * event_test.cpp
 *
 *  Created on: 23-03-2011
 *      Author: lukasz
 */

#include "../include/event_test.hpp"

event_test::event_test(){
}
event_test::~event_test(){
	cout<<"Bye"<<endl;
}
void event_test::run(){
	cout<<"Trying to run"<<endl;
 if (setVideoMode())
	 this->EventLoop();
}

void event_test::EventLoop(){
	/** Start the event loop. Keep reading events until there
	* is an error, or the user presses a mouse button. */
	cout<<"Staring event loop"<<endl;
	while (SDL_WaitEvent(&event) != 0 and !EventLoopOver) {
		/** SDL_WaitEvent has filled in our event structure
		* with the next event. We check its type field to
		* find out what happened. */
		switch (event.type) {
			/** The next two event types deal with mouse activity. */
			case SDL_MOUSEMOTION:
				printf("Mouse motion. ");
				/** SDL provides the current position. */
				printf("New position is (%i,%i). ",
					event.motion.x, event.motion.y);
				/** We can also get relative motion. */
				printf("That is a (%i,%i) change.\n",
					event.motion.xrel, event.motion.yrel);
				break;
			case SDL_MOUSEBUTTONDOWN:
				printf("Mouse button pressed. ");
				printf("Button %i at (%i,%i)\n",
					event.button.button,
					event.button.x, event.button.y);
				break;
				/** The SDL_QUIT event indicates that
				 * the windows "Close" button has been
				 * pressed. We can ignore this if we
				 * need to, but that tends to makeusers rather impatient. */
			case SDL_KEYDOWN:
				if(event.key.keysym.sym == SDLK_ESCAPE)
					EventLoopOver=true;
				break;
			case SDL_QUIT:
				printf("Quit event. Bye.\n");
				exit(0);
		}
	}
}
