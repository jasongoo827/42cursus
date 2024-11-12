#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(): name("Unknown"), size(0)
{
	// std::cout << "Character Constructor called\n";
	for (int i = 0; i < 4; ++i)
		inventory[i] = NULL;
}

Character::Character(std::string _name): name(_name), size(0)
{
	// std::cout << "Character Constructor called\n";
	for (int i = 0; i < 4; ++i)
		inventory[i] = NULL;
}

Character::Character(const Character& other): name(other.getName()), size(other.getSize())
{
	// std::cout << "Character Copy Constructor called\n";
	for (int i = 0; i < 4; ++i)
		inventory[i] = other.inventory[i]->clone();
}

Character& Character::operator=(const Character& rhs)
{
	if (this == &rhs)
		return (*this);
	name = rhs.getName();
	for (int i = 0; i < size; ++i)
		delete inventory[i];
	size = rhs.getSize();
	for (int i = 0; i < 4; ++i)
		inventory[i] = rhs.inventory[i]->clone();
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < size; ++i)
		delete inventory[i];
	// std::cout << "Character Destructor called\n";
}

std::string const& Character::getName() const
{
	return (name);
}

int	Character::getSize() const
{
	return (size);
}

void Character::equip(AMateria* m)
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
void Character::unequip(int indx)
{
	if (indx < 0 || indx >= 4 || indx > size - 1)
	{
		std::cout << "Index is out of range!\n";
		return ;
	}
	size--;
	inventory[indx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4 || idx > size - 1)
	{
		std::cout << "Index is out of range!\n";
		return ;
	}
	inventory[idx]->use(target);
}