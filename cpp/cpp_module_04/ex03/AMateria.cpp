#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"

AMateria::AMateria(std::string const& type)
{
	this->type = type;
	// std::cout << "AMateria Constructor called\n";
}

AMateria::AMateria(const AMateria& other): type(other.type)
{
	// std::cout << "AMateria Copy Constructor called\n";
}

AMateria& AMateria::operator=(const AMateria& rhs)
{
	// While assigning a Materia to another, copying the type doesn’t make sense.
	if (this == &rhs)
		return (*this);
	type = rhs.type;
	return (*this);
}

AMateria::~AMateria()
{
	// std::cout << "AMateria Destructor called\n";
}

std::string const& AMateria::getType() const
{
	return (type);
}

void AMateria::use(ICharacter& target)
{
	(void)target;
	std::cout << "Nothing happened!!(Unknown AMateria)\n";
}