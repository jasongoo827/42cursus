#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice: public AMateria
{
public:
	Ice();
	Ice(const Ice& other);
	~Ice();

	AMateria* 	clone(void) const;
	void 		use(ICharacter& target);
	
private:
	Ice& operator=(const Ice& rhs);

};

#endif