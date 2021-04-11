#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <string>
#include <iostream>

Base *generate(void)
{
	srand(time(NULL));
	char type = 'A' + rand() % 3;
	std::cout << type << " is created" << std::endl;
	if (type == 'A')
		return (new A);
	if (type == 'B')
		return (new B);
	return (new C);
}

void identify_from_pointer(Base * p)
{
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "A";
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "B";
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "C";
	std::cout << std::endl;
}

void identify_from_reference(Base & p)
{
	if (dynamic_cast<A *>(&p) != NULL)
		std::cout << "A";
	else if (dynamic_cast<B *>(&p) != NULL)
		std::cout << "B";
	else if (dynamic_cast<C *>(&p) != NULL)
		std::cout << "C";
}

int main()
{
	Base * p_base = generate();
	Base & r_base = *p_base;

  identify_from_pointer(p_base);
  identify_from_reference(r_base);

	delete p_base;

  return 0;

}
