#include "Convert.hpp"
#include <cctype>

Convert::Convert()
{

}

Convert::~Convert()
{

}

Convert::Convert(const Convert & right)
{
	*this = right;
}

Convert& Convert::operator=(const Convert & right)
{
	this->_r = right._r;
	this->_len = right._len;
	return *this;
}

Convert::Convert(std::string s)
{
	int i = 0;

	_len = s.length();
	if (_len == 1 && !std::isdigit(s[0]))
	{
		_r = static_cast<double>(s[0]);
		return ;
	}
	else
	{
		if ((_r = std::stod(s)) && !this->_len)
			throw Convert::NotLiteralException();
		if (s == "-inff" || s == "+inff" || s == "nanf" || s == "-inf" || s == "+inf" || s == "nan")
			return;
		if (_len > 1 &&  s[i] == '-' && std::isdigit(s[i + 1]))
				i++;
		while (std::isdigit(s[i]))
				i++;
		if (s[i] == '.' && std::isdigit(s[i + 1]))
		{
			i++;
			while (std::isdigit(s[i]) && i < _len)
				i++;
			if (s[i] == 'f')
				i++;
		}
		if (i != _len)
			throw Convert::NotLiteralException();
	}
}


const char * Convert::NotLiteralException::what() const throw()
{
	return "Please, write only literal";
}

void Convert::print_all() const
{
	to_char();
	to_int();
	to_float();
	to_double();
}

void Convert::to_int() const
{
	std::cout << "int: ";
	if (this->_r >= -2147483648 && this->_r <= 2147483647)
		std::cout << static_cast<int>(_r);
	else
		std::cout << "impossible";
	std::cout << std::endl;
}

void Convert::to_char() const
{
	std::cout << "char: ";
	if (this->_r >= 0 && this->_r <= 31)
		std::cout << "Non displayable";
	else if (this->_r >= 32 && this->_r <= 127)
		std::cout << "\'" << static_cast<char>(this->_r) << "\'";
	else
		std::cout << "impossible";
	std::cout << std::endl;
}

void Convert::to_double() const
{
	std::cout << "double: ";

	if (static_cast<double>(this->_r) - static_cast<int>(this->_r) == 0)
		std::cout << this->_r << ".0";
	else
		std::cout << this->_r;
	std::cout << std::endl;
}

void Convert::to_float() const
{
	std::cout << "float: ";

	if (static_cast<float>(this->_r) - static_cast<int>(this->_r) == 0)
		std::cout << static_cast<float>(this->_r) << ".0f";
	else
		std::cout << static_cast<float>(this->_r) << "f";
	std::cout << std::endl;
}

