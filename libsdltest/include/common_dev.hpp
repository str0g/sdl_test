/*
 * common_dev.hpp
 *
 *  Created on: 25-03-2011
 *      Author: lukasz
 */

#ifndef COMMON_DEV_HPP_
#define COMMON_DEV_HPP_

#include <iostream>

#define msg(x)\
	std::cout<<__FILE__<<":"<<__LINE__<<" - "<<x<<std::endl;

#endif /* COMMON_DEV_HPP_ */
