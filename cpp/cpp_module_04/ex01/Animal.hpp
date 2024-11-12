#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
public:
	Animal();
	Animal(const Animal& other);
	Animal& operator=(const Animal& rhs);
	virtual ~Animal();

	virtual void		makeSound() const;
	virtual std::string	getType() const;

protected:
	std::string type;

};

#endif