#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>

class ICharacter;

class AMateria
{
public:
	AMateria(const AMateria& other);
	AMateria(std::string const& type);
	virtual ~AMateria();

	std::string const& getType() const;

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);

protected:
	std::string type;

private:
	AMateria();
	AMateria& operator=(const AMateria& rhs); 

};

#endif