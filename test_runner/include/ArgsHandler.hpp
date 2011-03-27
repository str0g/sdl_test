/*
 * ArgsHandler.hpp
 *
 *  Created on: 27-03-2011
 *      Author: lukasz
 *		Home:	http://str0g.wordpress.com
 *		License:GNU/GPL v2
 */

#ifndef ARGSHANDLER_HPP_
#define ARGSHANDLER_HPP_

#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

template <class T,typename TN,class TX=int>
class ArgsHandler{
	typedef void(T::*pTemplateVoid)();
	typedef void(T::*pTemplateVoidARG)(TX a);
	typedef void (*ptv)();
	typedef void (*ptvTemplateARG)(TX);
	public:
		ArgsHandler(TN __data,
					T *p,
					pTemplateVoid _pT,
					bool _bDeleteAfterUse =false) :
					_data(__data),
					_pointer(p),
					_pointerTemplate(_pT),
					_pointerTemplateARG(NULL),
					_fpointer(NULL),
					_fpointerTemplateARG(NULL),
					bDeleteAfterUse(_bDeleteAfterUse){
			if(!_pointer)
				throw "ArgsHandler pointer(null) exception";
			if(!_pointerTemplate)
				throw "ArgsHandler pointerTemplate(null) exception";
		}
		ArgsHandler(TN __data,
					T *p,
					pTemplateVoidARG pTA,
					bool _bDeleteAfterUse =false) :
					_data(__data),
					_pointer(p),
					_pointerTemplate(NULL),
					_pointerTemplateARG(pTA),
					_fpointer(NULL),
					_fpointerTemplateARG(NULL),
					bDeleteAfterUse(_bDeleteAfterUse){
			if(!_pointer)
				throw "ArgsHandler pointer(null) exception";
			if(!_pointerTemplateARG)
				throw "ArgsHandler pointerTemplate(null) exception";
		}
		ArgsHandler(TN __data,ptv p, bool _bDeleteAfterUse =false) :
			_data(__data),
			_pointer(NULL),
			_pointerTemplate(NULL),
			_fpointer(p),
			_fpointerTemplateARG(NULL),
			bDeleteAfterUse(_bDeleteAfterUse){
			if(!_fpointer)
				throw "ArgsHandler fpointer(null) exception";
		}
		ArgsHandler(TN __data,ptvTemplateARG p, bool _bDeleteAfterUse =false) :
			_data(__data),
			_pointer(NULL),
			_pointerTemplate(NULL),
			_fpointer(NULL),
			_fpointerTemplateARG(p),
			bDeleteAfterUse(_bDeleteAfterUse){
			if(!_fpointer)
				throw "ArgsHandler fpointer(null) exception";
		}
		virtual ~ArgsHandler(){
			if (_pointer and bDeleteAfterUse)
				delete _pointer;
		}
		virtual void parseArg(const char *val){
			if(std::strcmp(_data,val) ==0 )
				if (_pointer)
					if(_pointerTemplate)
						(_pointer->*_pointerTemplate)();
					else{
						if (_pointerTemplateARG)
							(_pointer->*_pointerTemplateARG)(5);
					}
				else{
					if (_fpointer)
						_fpointer();
				}
				else{///FIXME ARGS
					if (_fpointerTemplateARG)
						_fpointerTemplateARG(5);
				}
		}/*
		virtual void parseArg(TN val){
			if(_data == val)
				(_pointer->*_pointerTemplate)();
		}*/
		/**
		 * Operator<< has been overload to print information about it self
		 */
		friend std::ostream &operator<<(std::ostream &out,const ArgsHandler<T,TN> &obj){
			out <<"\t["<<obj._data<<"] T::Pointer["<<obj._pointer<<
					"] _pointerTemplate["<<obj._pointerTemplate <<
					"] _pointerTemplateARG["<<obj._pointerTemplateARG <<
					"] fPointer["<<obj._fpointer <<
					"] _fpointerTemplate["<<obj._fpointerTemplateARG <<
					"] Delete pointed obj["<< (obj.bDeleteAfterUse ? "true":"false")<<"]";
			return out;
		}
	private:
		TN _data; 								//! Holding any date which is wished to be handle
		T* _pointer;							//! Pointer to class or structure which methods will be invoked
		pTemplateVoid _pointerTemplate; 		//! Pointer to class or structure method
		pTemplateVoidARG _pointerTemplateARG; 	//! Pointer to class or structure method(Template)
		ptv _fpointer;							//! Pointer to function if you dislike to use class or structure
		ptvTemplateARG _fpointerTemplateARG;  	//! Pointer to function which has template argument
		bool bDeleteAfterUse;					//! Build in memory handler if you would like to create and handle dynamic obj
};


#endif /* ARGSHANDLER_HPP_ */
