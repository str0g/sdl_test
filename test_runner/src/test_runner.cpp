/*
 * test_runner.cpp
 *
 *  Created on: 24-03-2011
 *      Author: lukasz
 *		Home:	http://str0g.wordpress.com
 *		License:GNU/GPL v2
 */

#include "../include/test_runner.hpp"

test_runner::test_runner(int &argc,char **argv){
	for (int i=0; i<argc; i++)
		list_argv.push_back(argv[i]);
	fillMapOfTest();
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
			msg("Unable to initialize SDL: " << SDL_GetError())
			exit(1);
		}
	atexit(SDL_Quit);
}

test_runner::~test_runner(){
	list_argv.clear();
	mapOfTest.clear();
}

void test_runner::fillMapOfTest(){
	mapOfTest.push_back(new type_ArgsParser("et",this,&test_runner::_RunTestET));//0
	mapOfTest.push_back(new type_ArgsParser("event_test",this,&test_runner::_RunTestET));//1
	mapOfTest.push_back(new type_ArgsParser("abt",this,&test_runner::_RunTestABT));//2
	mapOfTest.push_back(new type_ArgsParser("alpha_blending_test",this,&test_runner::_RunTestABT));//3
	mapOfTest.push_back(new type_ArgsParser("100p",this,&test_runner::_RunTest100Penguins));//4
	mapOfTest.push_back(new type_ArgsParser("100penguins_test",this,&test_runner::_RunTest100Penguins));//5
	//mapOfTest.push_back(new type_ArgsParser("temp",this,&test_runner::_RunTest,666));//4
	//mapOfTest.push_back(new ArgsHandlerImpl<test_runner,const char*,event_test>("temp",this,&test_runner::_RunTest(event_test)));
	mapOfTest.push_back(new type_ArgsParser("-h",this,&test_runner::_PrintHelp));//5
	mapOfTest.push_back(new type_ArgsParser("--help",this,&test_runner::_PrintHelp));//6
	mapOfTest.push_back(new type_ArgsParser("-v",this,&test_runner::_PrintVersion));//7
	mapOfTest.push_back(new type_ArgsParser("--version",this,&test_runner::_PrintVersion));//8
	//mapOfTest.push_back(new )
}

void test_runner::runSelectedTests(){
	cout<<"Registered Elements: "<<mapOfTest.size()<<endl;
	for(type_vectorConstChar::iterator it = ++list_argv.begin(); it!= list_argv.end(); it++){/*
			if(std::strcmp(mapOfTest[4],*it) == 0){
				cout<<"it: "<<*it<<endl;
				test(&print::printz,new print);
				Xarg.push_back(type_ArgsParser("temp",this));
				Xarg.begin()->parseArg(&test_runner::printX,*it);
				cout<<*(Xarg.begin())<<endl;
			}*/
		for (type_ArgsParserVector::iterator itt = mapOfTest.begin(); itt != mapOfTest.end(); itt++)
			(*itt)->parseArg(*it);
	}
	std::for_each(mapOfTest.begin(),mapOfTest.end(),deleteContent_MapOfTest);
}

void test_runner::_PrintHelp(){
	cout<<"Available test and options are: "<<endl;
	std::for_each(mapOfTest.begin(),mapOfTest.end(),printInfromation_MapOfTest);
}

void test_runner::_PrintVersion(){
	cout<<"Version:"<<endl;
}

template <typename T>
void test_runner::_RunTest(T){
	T *obj = new T;
	obj->run();
	delete obj;
	//cout<<"int: "<<i<<endl;
}
///FIXME temporary solution
void test_runner::_RunTestET(){
	RUNNER(event_test)
}

void test_runner::_RunTestABT(){
	RUNNER(alpha_blending)
}

void test_runner::_RunTest100Penguins(){
	RUNNER(_100penguins)
}

void test_runner::printX(){
	cout<<"GOOD STUFF"<<endl;
}

template<class T>
void test_runner::test(void (T::*f)(),T *p){
	(p->*f)();
	delete p;
}
