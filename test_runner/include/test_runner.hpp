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
#include <algorithm>

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

#define RUNNER(x)\
	x *obj = new x;\
	obj->run();\
	delete obj;

class test_runner{
	typedef std::vector<const char*>type_vectorConstChar;/*
	typedef ArgsHandler<test_runner,const char*> type_ArgsParser;
	typedef std::vector<type_ArgsParser > type_ArgsParserVector;*/
	typedef std::vector<ArgsHandler*> type_ArgsParserVector;
	typedef ArgsHandlerImpl<test_runner,const char*> type_ArgsParser;
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
		///FIXME temporary solution
		void _RunTestET();
		void _RunTestABT();
};


inline void deleteContent_MapOfTest(ArgsHandler *p){
	delete p;
}

inline void printInfromation_MapOfTest(ArgsHandler *p){
	p->printInformation();
}


#endif /* TEST_RUNNER_HPP_ */
