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
}

test_runner::~test_runner(){
	list_argv.clear();
	mapOfTest.clear();
}

void test_runner::fillMapOfTest(){
	mapOfTest.push_back(type_ArgsParser("et",this,&test_runner::_RunTestET));//0
	//mapOfTest.push_back(type_ArgsParser("event_test",this));//1
	mapOfTest.push_back(type_ArgsParser("abt",this,&test_runner::_RunTestABT));//2
	//mapOfTest.push_back(type_ArgsParser("alpha_blending_test",this));//3
	mapOfTest.push_back(type_ArgsParser("temp",this,&test_runner::_RunTest));//4
	mapOfTest.push_back(type_ArgsParser("-h",this,&test_runner::_PrintHelp));//5
	mapOfTest.push_back(type_ArgsParser("--help",this,&test_runner::_PrintHelp));//6
	mapOfTest.push_back(type_ArgsParser("-v",this,&test_runner::_PrintVersion));//7
	mapOfTest.push_back(type_ArgsParser("--version",this,&test_runner::_PrintVersion));//8
}

void test_runner::runSelectedTests(){
	for(type_vectorConstChar::iterator it = ++list_argv.begin(); it!= list_argv.end(); it++){/*
			if(std::strcmp(mapOfTest[0],*it) == 0 or std::strcmp(mapOfTest[1],*it)==0){
				cout<<"it: "<<*it<<endl;
				RUNNER(event_test)
			}
			if(std::strcmp(mapOfTest[2],*it) == 0 or std::strcmp(mapOfTest[3],*it)==0){
				cout<<"it: "<<*it<<endl;
				RUNNER(alpha_blending)
			}
			if(std::strcmp(mapOfTest[4],*it) == 0){
				cout<<"it: "<<*it<<endl;
				test(&print::printz,new print);
				Xarg.push_back(type_ArgsParser("temp",this));
				Xarg.begin()->parseArg(&test_runner::printX,*it);
				cout<<*(Xarg.begin())<<endl;
			}*/
		for (type_ArgsParserVector::iterator itt = mapOfTest.begin(); itt != mapOfTest.end(); itt++)
			itt->parseArg(*it);
	}
}

void test_runner::_PrintHelp(){
	cout<<"Available test and options are: "<<endl;
	for (type_ArgsParserVector::iterator it = mapOfTest.begin(); it != mapOfTest.end(); ++it)
		cout << *it << endl;
}

void test_runner::_PrintVersion(){
	cout<<"Version:"<<endl;
}
template <class T>
void test_runner::_RunTest(T){
	T *obj = new T;
	obj->run();
	delete obj;
}
///FIXME temporary solution
void test_runner::_RunTestET(){
	RUNNER(event_test)
}

void test_runner::_RunTestABT(){
	RUNNER(alpha_blending)
}
//---
void test_runner::_RunTest(int i){
	cout<<"Test running:"<<endl;
}

void test_runner::printX(){
	cout<<"GOOD STUFF"<<endl;
}

template<class T>
void test_runner::test(void (T::*f)(),T *p){
	(p->*f)();
	delete p;
}
