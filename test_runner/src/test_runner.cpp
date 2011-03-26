/*
 * test_runner.cpp
 *
 *  Created on: 24-03-2011
 *      Author: lukasz
 */

#include "../include/test_runner.hpp"

test_runner::test_runner(int &argc,char **argv){
	for (int i=0; i<argc; i++)
		list_argv.push_back(argv[i]);
}

test_runner::~test_runner(){
	list_argv.clear();
}

void test_runner::runSelectedTests(){
	for(constcharlist::iterator it = ++list_argv.begin(); it!= list_argv.end(); it++){
		if( strcmp("alpha_blending_test", *it) == 0){
			cout<<"it: "<<*it<<endl;
			RUNNER(alpha_blending)
		}
		if( strcmp("event_test", *it) == 0){
			cout<<"it: "<<*it<<endl;
			RUNNER(event_test)
		}
		if( strcmp("temp", *it) == 0){
			cout<<"it: "<<*it<<endl;
			temp t;
		}
	}
}

