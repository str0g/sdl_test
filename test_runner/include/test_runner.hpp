/*
 * test_runner.hpp
 *
 *  Created on: 24-03-2011
 *      Author: lukasz
 *		Home:	http://str0g.wordpress.com
 *		License:GNU/GPL v2
 */

#ifndef TEST_RUNNER_HPP_
#define TEST_RUNNER_HPP_

#include <iostream>
#include <vector>
#include <cstring>

#include "../../libsdltest/include/event_test.hpp"
#include "../../libsdltest/include/alpha_blending.hpp"
#include "../../libsdltest/src/temp.cpp"
#include "ArgsHandler.hpp"

using std::cout;
using std::cerr;
using std::endl;


struct print{
	void printz(){
		cout<<"Sukces"<<endl;
	}
};
template <class T>

void runTest(){/*
	T *obj = new T;
	obj->run();
	delete obj;*/
	cout<<"hura"<<endl;
}

#define RUNNER(x)\
	x *obj = new x;\
	obj->run();\
	delete obj;

class test_runner{
	typedef std::vector<const char*>type_vectorConstChar;
	typedef ArgsHandler<test_runner,const char*> type_ArgsParser;
	typedef std::vector<type_ArgsParser > type_ArgsParserVector;
	public:
		test_runner(int &argc, char **argv);
		~test_runner();
		void runSelectedTests();
		template <class T>
		void test(void(T::*)(),T*);
		void printX();
	private:
		type_vectorConstChar list_argv;
		type_ArgsParserVector mapOfTest;
		void fillMapOfTest();
		void _PrintHelp();
		void _PrintVersion();
		template <class T>
		void _RunTest(T);
		void _RunTest(int =3);
		///FIXME temporary solution
		void _RunTestET();
		void _RunTestABT();
		//---
		//void _RunTest();
};

#endif /* TEST_RUNNER_HPP_ */
