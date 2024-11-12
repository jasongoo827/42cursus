#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

class Character: public ICharacter
{
public:
	Character();
	Character(std::string name);
	Character(const Character& other);
	Character& operator=(const Character& rhs);
	~Character();

	int					getSize() const;
	std::string const& 	getName() const;
	void 				equip(AMateria* m);
	void 				unequip(int indx);
	void 				use(int idx, ICharacter& target);


private:
	AMateria*	inventory[4];
	std::string name;
	int			size;

};

#endif