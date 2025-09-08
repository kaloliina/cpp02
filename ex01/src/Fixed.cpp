#include "../include/Fixed.hpp"

Fixed::Fixed(const int ints)
{
	std::cout << "Int Constructor called" << std::endl;
	fixed_value = ints << fractional;
}

Fixed::Fixed(const float floats)
{
	std::cout << "Float Constructor called" << std::endl;
	fixed_value = roundf(floats * 256);
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

/*This syntax still feels a tad confusing*/
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
	float f = (float)(fixed_value / 256);
	return f;
}

int Fixed::toInt( void ) const 
{
	int i = fixed_value >> fractional;
	return i;
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

//Investigate this! I don't understand why this was needed for the printing fix
std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	// Output the internal value or use a member function that returns a printable type
	os << fixed.toFloat(); // or another method to represent the value
	return os;
}

//Comparison Operators
/*Also pretty confused why find findMax refused to build when this was not marked as const*/
bool Fixed::operator>(const Fixed &other) const
{
	return (this->getRawBits() > other.getRawBits());
}
bool Fixed::operator<(const Fixed &other) const
{
	return (this->getRawBits() < other.getRawBits());
}
bool Fixed::operator>=(const Fixed &other) const
{
	return (this->getRawBits() >= other.getRawBits());
}
bool Fixed::operator<=(const Fixed &other) const
{
	return (this->getRawBits() <= other.getRawBits());
}
bool Fixed::operator==(const Fixed &other) const
{
	return (this->getRawBits() == other.getRawBits());
}
bool Fixed::operator!=(const Fixed &other) const
{
	return (this->getRawBits() != other.getRawBits());
}

//Arithmetic Operators
Fixed Fixed::operator+(const Fixed &other)
{
	this->fixed_value = this->fixed_value + other.fixed_value;
	return (*this);
}
Fixed Fixed::operator-(const Fixed &other)
{
	this->fixed_value = this->fixed_value - other.fixed_value;
	return (*this);
}

/*Create examples for these because it was easier for me to visualise them that way!*/
/*Also wondering if I should adjust the value witth setter function or like this because
basically i can do it directly.*/
Fixed Fixed::operator*(const Fixed &other)
{
	long long new_fixed;
	new_fixed = this->fixed_value * other.fixed_value;
	new_fixed = new_fixed >> fractional;
	this->fixed_value = new_fixed;
	return (*this);
}
Fixed Fixed::operator/(const Fixed &other)
{
	long long new_fixed;
	new_fixed = this->fixed_value * 256;
	this->fixed_value = new_fixed / other.fixed_value;
	return (*this);
}

//Increment/Decrement Operators
Fixed Fixed::operator++()
{
	this->fixed_value = this->fixed_value + 1;
	return (*this);
}
Fixed Fixed::operator--() 
{
	this->fixed_value = this->fixed_value - 1;
	return (*this);
}
//I still don't fully grasp how does this work exactly, we return temp with the old value
//but then we change the actual objects value.
Fixed Fixed::operator++(int) 
{
	Fixed *temp;

	temp = this;
	this->fixed_value = this->fixed_value + 1;
	return (*temp);
}
Fixed Fixed::operator--(int)
{
	Fixed *temp;

	temp = this;
	this->fixed_value = this->fixed_value - 1;
	return (*temp);	
}
/*Do we really need two separate functions for these, maybe at least I could call to the other function*/
Fixed& Fixed::findMin(Fixed &nbr1, Fixed &nbr2) const
{
	if (nbr1 < nbr2)
		return (nbr1);
	else
		return (nbr2);
}
const Fixed& Fixed::findConstMin(const Fixed &nbr1, const Fixed &nbr2) const
{
	if (nbr1 < nbr2)
		return (nbr1);
	else
		return (nbr2);
}

Fixed& Fixed::findMax(Fixed &nbr1, Fixed &nbr2) const
{
	if (nbr1 > nbr2)
		return (nbr1);
	else
		return (nbr2);
}
const Fixed& Fixed::findConstMax(const Fixed &nbr1, const Fixed &nbr2) const
{
	if (nbr1 > nbr2)
		return (nbr1);
	else
		return (nbr2);
}
