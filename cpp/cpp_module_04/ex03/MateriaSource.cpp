#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

MateriaSource::MateriaSource(): size(0)
{
	// std::cout << "MateriaSource Default Constructor called\n";
	for (int i = 0; i < 4; ++i)
		inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other): size(other.size)
{
	// std::cout << "MateriaSource Copy Constructor called\n";
	for (int i = 0; i < 4; ++i)
		inventory[i] = other.inventory[i]->clone();
}

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs)
{
	if (this == &rhs)
		return (*this);
	for (int i = 0; i < size; ++i)
		delete inventory[i];
	size = rhs.size;
	for (int i = 0; i < 4; ++i)
		inventory[i] = rhs.inventory[i]->clone();
	return (*this);
}

MateriaSource::~MateriaSource()
{
	// std::cout << "MateriaSource Destructor called\n";
	for (int i = 0; i < size; ++i)
		delete inventory[i];
}

void 	MateriaSource::learnMateria(AMateria* m)
{
	if (size >= 4)
	{
		std::cout << "Inventory is full!\n";
		return ;
	}
	if (m == NULL)
	{
		std::cout << "Invalid AMateria address!\n";
		return ;
	}
	inventory[size++] = m;
}

AMateria* 	MateriaSource::createMateria(std::string const& type)
{
	if (type == "ice")
		return (new Ice());
	else if (type == "cure")
		return (new Cure());
	else
		return (NULL);
}
