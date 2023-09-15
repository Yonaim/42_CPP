#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
  private:
	Brain *_brain;

  public:
	Dog();
	Dog(const Dog &orig);
	Dog &operator=(const Dog &orig);
	~Dog();

	virtual void makeSound(void) const;
	Brain *getBrain(void);
};

#endif
