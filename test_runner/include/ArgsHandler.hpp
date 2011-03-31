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

class ArgsHandler{
	public:
		ArgsHandler(){}
		virtual ~ArgsHandler(){}
		virtual void parseArg(const char* x){}/*
		template <typename T>
		virtual void parsArg(const T &){}*/
		virtual void printInformation(){}
};

template <class T,typename TN,typename TX=int>
class ArgsHandlerImpl : public ArgsHandler{
	typedef void(T::*pTemplateVoid)();
	typedef void(T::*pTemplateVoidARG)(TX);
	typedef void (*ptv)();
	typedef void (*ptvTemplateARG)(TX);
	public:
		ArgsHandlerImpl(TN __data, ///Constructor for T::*,&T::f
					T *p,
					pTemplateVoid _pT,
					bool _bDeleteAfterUse =false) :
					ArgsHandler(),
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
		ArgsHandlerImpl(TN __data, ///Constructor for T::*,&T::f,arg1
					T *p,
					pTemplateVoidARG pTA,
					TX arg1,
					bool _bDeleteAfterUse =false) :
					ArgsHandler(),
					_data(__data),
					_pointer(p),
					_pointerTemplate(NULL),
					_pointerTemplateARG(pTA),
					_fpointer(NULL),
					_fpointerTemplateARG(NULL),
					_arg1(arg1),
					bDeleteAfterUse(_bDeleteAfterUse){
			if(!_pointer)
				throw "ArgsHandler pointer(null) exception";
			if(!_pointerTemplateARG)
				throw "ArgsHandler pointerTemplate(null) exception";
		}
		ArgsHandlerImpl(TN __data, ///Constructor for void(*)()
				ptv p, bool _bDeleteAfterUse =false) :
				ArgsHandler(),
			_data(__data),
			_pointer(NULL),
			_pointerTemplate(NULL),
			_fpointer(p),
			_fpointerTemplateARG(NULL),
			bDeleteAfterUse(_bDeleteAfterUse){
			if(!_fpointer)
				throw "ArgsHandler fpointer(null) exception";
		}
		ArgsHandlerImpl(TN __data, ///Constructor for void(*)(type_arg),type_arg value
				ptvTemplateARG p,
				TX arg1,
				bool _bDeleteAfterUse =false) :
				ArgsHandler(),
			_data(__data),
			_pointer(NULL),
			_pointerTemplate(NULL),
			_fpointer(NULL),
			_fpointerTemplateARG(p),
			_arg1(arg1),
			bDeleteAfterUse(_bDeleteAfterUse){
			if(!_fpointer)
				throw "ArgsHandler fpointer(null) exception";
		}
		~ArgsHandlerImpl(){
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
							(_pointer->*_pointerTemplateARG)(_arg1);
					}
				else{
					if (_fpointer)
						_fpointer();
				}
				else{
					if (_fpointerTemplateARG)
						_fpointerTemplateARG(_arg1);
				}
		}/*//FIXME
		virtual void parseArg(TN val){
			if(_data == val)
				(_pointer->*_pointerTemplate)();
		}*/
		/**
		 * Operator<< has been overload to print information about it self
		 */
		virtual void printInformation(){
			cout<<_data<<"] T::Pointer["<<_pointer<<
					"] _pointerTemplate["<<_pointerTemplate <<
					"] _pointerTemplateARG["<<_pointerTemplateARG <<
					"] fPointer["<<_fpointer <<
					"] _fpointerTemplate["<<_fpointerTemplateARG <<
					"] Delete pointed obj["<< (bDeleteAfterUse ? "true":"false")<<
					"] Passed _arg1["<<_arg1<<"]"<<endl;
		}/*
		friend std::ostream &operator<<(std::ostream &out,const ArgsHandler<T,TN> &obj){
			out <<"\t["<<obj._data<<"] T::Pointer["<<obj._pointer<<
					"] _pointerTemplate["<<obj._pointerTemplate <<
					"] _pointerTemplateARG["<<obj._pointerTemplateARG <<
					"] fPointer["<<obj._fpointer <<
					"] _fpointerTemplate["<<obj._fpointerTemplateARG <<
					"] Delete pointed obj["<< (obj.bDeleteAfterUse ? "true":"false")<<
					"] Passed _arg1["<<obj._arg1<<"]";
			return out;
		}*/
	private:
		TN _data; 								//! Holding any date which is wished to be handle
		T* _pointer;							//! Pointer to class or structure which methods will be invoked
		pTemplateVoid _pointerTemplate; 		//! Pointer to class or structure method
		pTemplateVoidARG _pointerTemplateARG; 	//! Pointer to class or structure method(Template)
		ptv _fpointer;							//! Pointer to function if you dislike to use class or structure
		ptvTemplateARG _fpointerTemplateARG;  	//! Pointer to function which has template argument
		TX _arg1;								//! Argument which will be passed to function with argument
		bool bDeleteAfterUse;					//! Build in memory handler if you would like to create and handle dynamic obj
};


#endif /* ARGSHANDLER_HPP_ */
