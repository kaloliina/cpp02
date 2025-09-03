#include "../include/Fixed.hpp"

Fixed::Fixed() : fixed_value(0)
{
	std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy Constructor called" << std::endl;
	this->fixed_value = copy.fixed_value;
}

/*It checks if the current object (this) and the source object (other) are not the same object in memory.
To avoid deletions or errors...*/
Fixed& Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy Assignment called" << std::endl;
	if (this != &src)
	{
		this->fixed_value = src.fixed_value;	
	}
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Default Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return fixed_value;
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	fixed_value = raw;
}
