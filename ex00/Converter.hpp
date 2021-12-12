#ifndef __CONVERTER__H__
#define __CONVERTER__H__

#include <iostream>

class Converter
{
	private:

	public:
		Converter();
		Converter(const Converter &converter);
		~Converter();

	Converter & operator = (Converter &converter);
};

#endif  //!__CONVERTER__H__