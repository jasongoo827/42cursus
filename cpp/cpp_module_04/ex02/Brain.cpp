#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Constructor called\n";
	for (int i = 0; i < 100; ++i)
		ideas[i] = "I am hungry\n";
}

Brain::Brain(const Brain& other)
{
	std::cout << "Brain Copy Constructor called\n";
	for (int i = 0; i < 100; ++i)
		ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain& rhs)
{
	if (this == &rhs)
		return (*this);

	for (int i = 0; i < 100; ++i)
		ideas[i] = rhs.ideas[i];
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain Destructor called\n";
}

