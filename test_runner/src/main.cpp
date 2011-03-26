/*
 * main.cpp
 *
 *  Created on: 24-03-2011
 *      Author: lukasz
 */

#include "../include/test_runner.hpp"

int main(int argc,char **argv){
	test_runner tr(argc,argv);
	tr.runSelectedTests();
}
