#ifndef __CONVERTER__H__
#define __CONVERTER__H__

#include <iostream>
#include <stdexcept>
#include <limits>
#include <cmath>

class Converter
{
	private:
		int		_selectedType;
		char	_charScalar;
		float	_floatScalar;
		double	_doubleScalar;
		int		_intScalar;

		//MACROS
		static const int	NO_TYPE = -1;
		static const int	CHAR_TYPE = 0;
		static const int	FLOAT_TYPE = 1;
		static const int	DOUBLE_TYPE = 2;
		static const int	INT_TYPE = 3;

		int		getType(std::string input);
		void	print_char();
		void	print_float();
		void	print_double();
		void	print_int(std::string input);

	public:
		Converter();
		Converter(Converter const &converter);
		~Converter();

		Converter & operator = (Converter const &converter);

		int		process_input(std::string input);
		void	setScalars(std::string input);
		void	printConversions(std::string input);

		class NoInputException : public std::exception
		{

			public:
				virtual const char* what() const throw()
				{
					return "No input detected";
				}
		};

		class BadInputException : public std::exception
		{

			public:
				virtual const char* what() const throw()
				{
					return "Input is not a valid numeric notation or a character";
				}
		};
};

#endif  //!__CONVERTER__H__