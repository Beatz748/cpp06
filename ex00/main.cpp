#include "Convert.hpp"
#include <exception>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Bad number of arguments" << std::endl;
		return (0);
	}
	try
	{
		Convert lel(argv[1]);
		lel.print_all();
	}
	catch(Convert::NotLiteralException & ex)
	{
		std::cout << ex.what() << std::endl;
		return(1);
	}
	return (0);
}
