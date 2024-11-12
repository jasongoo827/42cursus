#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure: public AMateria
{
public:
	Cure();
	Cure(const Cure& other);
	~Cure();

	AMateria* 	clone(void) const;
	void 		use(ICharacter& target);
	
private:
	Cure& operator=(const Cure& rhs);

};

#endif