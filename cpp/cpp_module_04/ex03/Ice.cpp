#include "Ice.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"


Ice::Ice(): AMateria("ice")
{
	// std::cout << "Ice Constructor called\n";
}

Ice::Ice(const Ice& other): AMateria(other)
{
	// std::cout << "Ice Copy Constructor called\n";
}

Ice& Ice::operator=(const Ice& rhs)
{
	if (this == &rhs)
		return (*this);
	this->type = rhs.type;
	return (*this);
}

Ice::~Ice()
{
	// std::cout << "Ice Destructor called\n";
}

AMateria*	Ice::clone() const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << std::endl;
}