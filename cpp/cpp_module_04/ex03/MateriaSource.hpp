#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
public:
	MateriaSource();
	MateriaSource(const MateriaSource& other);
	MateriaSource& operator=(const MateriaSource& rhs);
	~MateriaSource();

	void 		learnMateria(AMateria* m);
	AMateria* 	createMateria(std::string const& type);

	AMateria*	inventory[4];

private:
	int	size;

};

#endif