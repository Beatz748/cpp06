#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <exception>
#include <string>
#include <iostream>

class	Convert
{
	private:
		Convert();
		int _len;
		double _r;
		void to_int() const;
		void to_char() const;
		void to_double() const;
		void to_float() const;
	public:
		~Convert();
	Convert& operator=(const Convert & right);
	Convert(const Convert & right);
	Convert(std::string s);
	void print_all() const;
	class NotLiteralException : public std::exception
	{
			public:
		virtual const char *what() const throw();
	};
};

#endif
