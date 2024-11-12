#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"


Cure::Cure(): AMateria("cure")
{
	// std::cout << "Cure Constructor called\n";
}

Cure::Cure(const Cure& other): AMateria(other)
{
	// std::cout << "Cure Copy Constructor called\n";
}

Cure& Cure::operator=(const Cure& rhs)
{
	if (this == &rhs)
		return (*this);
	this->type = rhs.type;
	return (*this);
}

Cure::~Cure()
{
	// std::cout << "Cure Destructor called\n";
}

AMateria*	Cure::clone() const
{
	return (new Cure(*this));
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "\'s wounds" << std::endl;
}