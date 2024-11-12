#include "Serializer.hpp"
#include "Data.hpp"

int main(void)
{
	Data data;

	uintptr_t addr = Serializer::serialize(&data);
	Data* data_addr = Serializer::deserialize(addr);

	if (&data == data_addr)
	{
		std::cout << "address is same!\n";
	}
	else
	{
		std::cout << "address is not same!\n";
	}
}