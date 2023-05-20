#ifndef AAnimal_HPP
# define AAnimal_HPP

# include <iostream>

class AAnimal
{
protected:
	std::string _type;

public:
	AAnimal(void);
	AAnimal(std::string type);
	AAnimal(const AAnimal &ref);
	virtual ~AAnimal();

	AAnimal &operator=(const AAnimal &ref);

	virtual void	makeSound() const = 0;
	std::string		getType() const;

};

#endif