#include <iostream>

#include "Data.hpp"
#include "Serializer.hpp"

#define BBLUE "\033[1;34m"
#define BRED "\033[1;31m"
#define BOLD "\033[1m"
#define BGREEN "\033[1;32m"
#define RESET "\033[0m"

#define HEX true
#define DEC false

void	print_data(Data *data);
void	set_data(Data *data, std::string s1, std::string s2, int n, float f);
void	print_ptr(Data *data, uintptr_t raw);

int	main( void )
{
	std::cout << BRED ">> Using a Data variable in the stack <<" RESET << std::endl;
	Data data;
	uintptr_t raw;

	set_data(&data, "Hello", "World", 42, 3.14f);

	std::cout << "Serializing data..." << std::endl;
	raw = Serializer::serialize(&data);	

	print_ptr(&data, raw);

	std::cout << "Deserializing raw..." << std::endl;
	Data *data2 = Serializer::deserialize(raw);
	print_data(data2);

	std::cout << BRED ">> Using a Data variable in the heap <<" RESET << std::endl;
	Data *data3 = new Data;
	set_data(data3, "Lorem", "Ipsum", 4242, 6.28f);

	std::cout << "Serializing data..." << std::endl;
	raw = Serializer::serialize(data3);

	print_ptr(data3, raw);

	std::cout << "Deserializing raw..." << std::endl;
	Data *data4 = Serializer::deserialize(raw);
	print_data(data4);

	delete data4;
	return 0;
}

void	print_data(Data *data)
{
	std::cout << BGREEN "Printing data:" RESET << std::endl;
	std::cout << "\"" << data->s1 << "\"" << std::endl;
	std::cout << "\"" << data->s2 << "\"" << std::endl;
	std::cout << data->n << std::endl;
	std::cout << data->f << std::endl;
	std::cout << std::endl;
}

void	set_data(Data *data, std::string s1, std::string s2, int n, float f)
{
	data->s1 = s1;
	data->s2 = s2;
	data->n = n;
	data->f = f;
	print_data(data);
}

void	print_ptr(Data *data, uintptr_t raw)
{
	std::cout << BBLUE "Values of &data and raw:" << std::endl;
	std::cout << BGREEN "Data address:  " RESET << data << std::endl;
	std::cout << BGREEN "Serialized data: " RESET << std::hex << raw << std::dec << std::endl;
	std::cout << std::endl;
}
