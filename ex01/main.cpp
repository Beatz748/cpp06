#include <string>
#include <iostream>
#include "Data.hpp"

std::string *random_str()
{
	std::string str;
	std::string char_arr = "abcdefghijklmnopqrstuvwxyz ,;.'{} 0123456789 ABSCDEFGHIJKLMOPQRSTUVWXYZ";

	int len = 5 + rand() % 42;
	str.resize(len);
	int i = 0;
	while (i < len)
	{
		str[i] = char_arr[rand() % char_arr.length()];
		i++;
	}
	return (new std::string(str));
}

void *serialize()
{
	std::string *s1 = random_str();
	int n = rand();
	std::string *s2 = random_str();
	std::cout << "BEFORE" << std::endl;
	std::cout << "s1: " << *s1 << std::endl
					<< "n : " << n  << std::endl
        	<< "s2: " << *s2 << std::endl;

	void *raw = ::operator new (2 * sizeof(std::string *) + sizeof(int));
	void *safe = raw;

	*reinterpret_cast<std::string **>(safe) = s1;
	safe = reinterpret_cast<std::string **>(safe) + 1;
	*reinterpret_cast<int *>(safe) = n;
	safe = reinterpret_cast<int *>(safe) + 1;
	*reinterpret_cast<std::string **>(safe) = s2;

	return (raw);
}

Data *deserialize(void *raw)
{
	Data *data = new Data;

	data->s1 = *reinterpret_cast<std::string **>(raw);
	raw = reinterpret_cast<std::string **>(raw) + 1;
	data->n = *reinterpret_cast<int *>(raw);
	raw = reinterpret_cast<int *>(raw) + 1;
	data->s2 = *reinterpret_cast<std::string **>(raw);

	return (data);
}

int main()
{
	srand(time(NULL));
	void *raw = serialize();
	Data *data = deserialize(raw);
	std::cout << "AFTER" << std::endl;
	std::cout << sizeof(raw) << std::endl;
	std::cout << "s1: " << *data->s1 << std::endl
					<< "n : " << data->n  << std::endl
        	<< "s2: " << *data->s2 << std::endl;
}
