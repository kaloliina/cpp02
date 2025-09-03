#include "../include/Fixed.hpp"
#include <cmath>
/*
So we have two constructors, if we only get int. We know we can bitshift
8 bits to the left to the "important" section.
If we get float, we cant just directly store the result
because int loses track of the decimals so thats why we multiply it with 
2 to the power of 8. 
*/

Fixed::Fixed(const int ints)
{
	std::cout << "Int Constructor called" << std::endl;
	fixed_value = ints << 8;
}
//thinks something is wrong here
Fixed::Fixed(const float floats)
{
	std::cout << "Float Constructor called" << std::endl;
	fixed_value = floats * pow(2, 8);
}
Fixed::Fixed() : fixed_value(0)
{
	std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy Constructor called" << std::endl;
	this->fixed_value = copy.fixed_value;
}

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

float Fixed::toFloat( void ) const
{
	float f = (float)(fixed_value / pow(2,8));
	return f;
}
int Fixed::toInt( void ) const 
{
	int i = fixed_value >> 8;
	return i;
}

//Investigate this! I don't understand why this was needed for the printing fix
std::ostream& operator<<(std::ostream& os, const Fixed& fixed){
    // Output the internal value or use a member function that returns a printable type
    os << fixed.toFloat(); // or another method to represent the value
    return os;
}
