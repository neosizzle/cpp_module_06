#include "Converter.hpp"
/*
** utils
*/
int	ft_isalpha(char c)
{
	return ((c > 96 && c < 123) || (c > 64 && c < 91));
}

int	ft_isnumeric(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isnumeric_str(std::string str)
{
	int	i;

	i = 0;
	if (str[i] == '-') ++i;
	while (str[i])
	{
		if (!ft_isnumeric(str[i]))
			return 0;
		++i;
	}
	
	return 1;
}

int	ft_num_dots(std::string str)
{
	int	i;
	int	res;

	i = -1;
	res = 0;
	while (str[++i])
	{
		if (str[i] == '.')
			++res;
	}
	return res;
}

int	ft_strchr(std::string str, char c)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == c)
			return i;
	}
	return -1;
}

std::string ft_dotzero(double number)
{
	std::string empty = "";
	std::string dotzero = ".0";

	if (number - static_cast<int>(number) == 0.0)
		return (dotzero);
	return (empty);
}

bool printable_char(double num)
{
	if (num <= 126 && num >= 32)
		return true ;
	else if (num >= 0 && num <= 127)
	{
		std::cout << "char: Non displayable\n";
		return false ;
	}
	std::cout << "char: impossible\n";
	return false ;
}
bool printable_int(double num, std::string input)
{
	if (num == -1 && std::to_string(num) != input)
	{
		std::cout << "int: impossible\n";
		return false;
	}
	else if (num <= std::numeric_limits<int>::max() && num >= std::numeric_limits<int>::min())
	{
		return true;
	}
	std::cout << "int: impossible\n";
	return false ;
}

bool printable_float(double num)
{
	if (
		(num <= std::numeric_limits<float>::max() &&
		num >= -std::numeric_limits<float>::max()) ||
		num == std::numeric_limits<float>::infinity() || 
		num == -std::numeric_limits<float>::infinity() ||
		std::isnan(num)
	)
		return true;
	std::cout << "float: impossible\n";
	return false;
	
}

bool printable_double(double num)
{
	if (
		(num <= std::numeric_limits<double>::max() &&
		num >= -std::numeric_limits<float>::max()) ||
		num == std::numeric_limits<double>::infinity() || 
		num == -std::numeric_limits<double>::infinity() ||
		std::isnan(num)
	)
		return true;
	std::cout << "double: impossible\n";
	return false;
}
/*
** Class functions
*/

/*
** First function main will hit when receiving input.
** Main goal is to detect the selected type and set the scalar values
*/
int	Converter::process_input(std::string input)
{
	if (!input[0])
		throw Converter::NoInputException();
	this->_selectedType = Converter::getType(input);
	Converter::setScalars(input);
	return 0;
}

/*
** Will perform checks and return the corresponding type
*/
int	Converter::getType(std::string str)
{
	int	i;
	int	dotIdx;

	//Check for special strings
	i = -1;
	std::string	special_doubles[] =
	{
		"inf", "+inf", "-inf", "nan"
	};
	std::string	special_floats[] =
	{
		"inff", "+inff", "-inff", "nanf"
	};
	while (++i < 4)
	{
		if (str == special_doubles[i])
			return Converter::DOUBLE_TYPE;
		else if (str == special_floats[i])
			return Converter::FLOAT_TYPE;
	}
	
	//Check for character and throw error if there is more than 1 character
	if (ft_isalpha(str[0]))
	{
		if (str[1])
			throw Converter::BadInputException();
		return Converter::CHAR_TYPE;
	}

	//check for integer
	if (ft_isnumeric_str(str))
		return Converter::INT_TYPE;

	//check for more than 1 dot in string
	if (ft_num_dots(str) != 1)
		throw Converter::BadInputException();

	//check for no number after dot
	dotIdx = ft_strchr(str, '.');
	if (dotIdx == int(str.length() - 1) || !ft_isnumeric(str[dotIdx + 1]))
		throw Converter::BadInputException();

	//return float or double
	if (str[str.length() - 1] == 'f')
		return Converter::FLOAT_TYPE;
	else
		return Converter::DOUBLE_TYPE;
}

/*
** Will set the scalar values according to the input and the type obtained
*/
void	Converter::setScalars(std::string str)
{
	if (this->_selectedType == Converter::CHAR_TYPE)
		this->_charScalar = str[0];
	if (this->_selectedType == Converter::FLOAT_TYPE)
		this->_floatScalar = atof(str.c_str());
	if (this->_selectedType == Converter::DOUBLE_TYPE)
		this->_doubleScalar = atof(str.c_str());
	if (this->_selectedType == Converter::INT_TYPE)
	{
		if(atol(str.c_str()) < std::numeric_limits<int>::min() ||
		atol(str.c_str()) > std::numeric_limits<int>::max())
			this->_intScalar = -1;
		else
			this->_intScalar = atoi(str.c_str());
	}
}

/*
** Checks for valid type and print accordingly to selected type
*/
void	Converter::print_char()
{
	if (_selectedType == Converter::CHAR_TYPE)
	{
		std::cout << "char: " <<  this->_charScalar <<  "\n";
	}
	else if (_selectedType == Converter::FLOAT_TYPE)
	{
		if (printable_char(this->_floatScalar))
			std::cout << "char: " << static_cast<char>(this->_floatScalar) << "\n";
	}
	else if (_selectedType == Converter::DOUBLE_TYPE)
	{
		if (printable_char(this->_doubleScalar))
			std::cout << "char: " << static_cast<char>(this->_doubleScalar) << "\n";
	}
	else if (_selectedType == Converter::INT_TYPE)
	{
		if (printable_char(this->_intScalar))
			std::cout << "char: " << static_cast<char>(this->_intScalar) << "\n";
	}
	else
		std::cout << "No type selected\n";
}
/*
** Checks for valid type and print accordingly to selected type
*/
void	Converter::print_float()
{
	if (_selectedType == Converter::CHAR_TYPE)
	{
		std::cout << "float: " <<  static_cast<float>(this->_charScalar) << ft_dotzero(this->_charScalar) <<"f\n";
	}
	else if (_selectedType == Converter::FLOAT_TYPE)
	{
		std::cout << "float: " << this->_floatScalar << ft_dotzero(this->_floatScalar) <<"f\n";
	}
	else if (_selectedType == Converter::DOUBLE_TYPE)
	{
		if (printable_float(this->_doubleScalar))
			std::cout << "float: " << static_cast<float>(this->_doubleScalar) << ft_dotzero(this->_doubleScalar) <<"f\n";
	}
	else if (_selectedType == Converter::INT_TYPE)
	{
		if (printable_float(this->_intScalar))
					std::cout << "float: " << static_cast<float>(this->_intScalar) << ft_dotzero(this->_intScalar) <<"f\n";		
	}
	else
		std::cout << "No type selected\n";
}
/*
** Checks for valid type and print accordingly to selected type
*/
void	Converter::print_double()
{
	if (_selectedType == Converter::CHAR_TYPE)
	{
		std::cout << "double: " << static_cast<double>(this->_charScalar) << ft_dotzero(this->_charScalar) <<"\n";
	}
	else if (_selectedType == Converter::FLOAT_TYPE)
	{
		std::cout << "double: " << static_cast<double>(this->_floatScalar) << ft_dotzero(this->_floatScalar) <<"\n";
	}
	else if (_selectedType == Converter::DOUBLE_TYPE)
	{
		if (printable_double(this->_doubleScalar))
			std::cout << "double: " << this->_doubleScalar << ft_dotzero(this->_doubleScalar) <<"\n";
	}
	else if (_selectedType == Converter::INT_TYPE)
	{
		if (printable_double(this->_intScalar))
			std::cout << "double: " << static_cast<double>(this->_intScalar) << ft_dotzero(this->_intScalar) <<"\n";
	}
	else
		std::cout << "No type selected\n";
}
/*
** Checks for valid type and print accordingly to selected type
*/
void	Converter::print_int(std::string input)
{
	(void) input;
	if (_selectedType == Converter::CHAR_TYPE)
	{
		std::cout << "int: " << static_cast<int>(this->_charScalar) << "\n";
	}
	else if (_selectedType == Converter::FLOAT_TYPE)
	{
		if (printable_int(this->_floatScalar, input))
			std::cout << "int: " << static_cast<int>(this->_floatScalar) << "\n";
	}
	else if (_selectedType == Converter::DOUBLE_TYPE)
	{
		if (printable_int(this->_doubleScalar, input))
			std::cout << "int: " << static_cast<int>(this->_doubleScalar) << "\n";
	}
	else if (_selectedType == Converter::INT_TYPE)
	{
		if (printable_int(this->_intScalar, input))
			std::cout << "int: " << this->_intScalar << "\n";
	}
	else
		std::cout << "No type selected\n";
}
/*
** Function that will call print types to print all the types out
*/
void	Converter::printConversions(std::string input)
{
	this->print_char();
	this->print_int(input);
	this->print_float();
	this->print_double();
}

/*
** OCF
*/
Converter::Converter(): _selectedType(-1){}

Converter::Converter(Converter const &converter)
{
	*this = converter;
}

Converter::~Converter(){}

Converter & Converter::operator = (Converter const &converter)
{
	this->_selectedType = converter._selectedType;
	this->_charScalar = converter._charScalar;
	this->_floatScalar = converter._floatScalar;
	this->_doubleScalar = converter._doubleScalar;
	this->_intScalar = converter._intScalar;
	return *this;
}