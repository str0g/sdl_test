/*
 * test_runner.hpp
 *
 *  Created on: 24-03-2011
 *      Author: lukasz
 */

#ifndef TEST_RUNNER_HPP_
#define TEST_RUNNER_HPP_

#include <iostream>
#include <list>
#include <cstring>
#include "../../libsdltest/include/event_test.hpp"
#include "../../libsdltest/include/alpha_blending.hpp"
#include "../../libsdltest/src/temp.cpp"

using std::list;
using std::cout;
using std::cerr;
using std::endl;

typedef list<const char*> constcharlist;

#define RUNNER(x)\
	x *obj = new x;\
	obj->run();\
	delete obj;

class test_runner{
	public:
		test_runner(int &argc, char **argv);
		~test_runner();
		void runSelectedTests();
	private:
		constcharlist list_argv;
};

#endif /* TEST_RUNNER_HPP_ */
