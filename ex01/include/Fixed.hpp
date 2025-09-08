#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed {
private:
	int fixed_value;
	static const int fractional = 8; //static here means that the int is associated with the class itself rather than any specific object created from the class
public:
	Fixed();
	Fixed(const int ints);
	Fixed(const float floats);
	Fixed(const Fixed& copy);
	Fixed &operator=(const Fixed &src); 
	~Fixed();

//Comparison
	bool operator>(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<=(const Fixed &other)const ;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;

//Arithmetic
	Fixed operator+(const Fixed &other);
	Fixed operator-(const Fixed &other);
	Fixed operator*(const Fixed &other);
	Fixed operator/(const Fixed &other);

//Increment/Decrement
//Int is a dummy parameter used to differentiate between prefix and postfix versions (int means postfix)
	Fixed operator++();
	Fixed operator--();
	Fixed operator++(int);
	Fixed operator--(int);

	Fixed& findMin(Fixed &nbr1, Fixed &nbr2) const;
	const Fixed& findConstMin(const Fixed &nbr1, const Fixed &nbr2) const;
	Fixed& findMax(Fixed &nbr1, Fixed &nbr2) const;
	const Fixed& findConstMax(const Fixed &nbr1, const Fixed &nbr2) const;

//increment decrement operations
	float toFloat( void ) const;
	int toInt( void ) const;
//we need to still have the getter and setter functions
	int getRawBits( void ) const;
	void setRawBits( int const raw );	
};
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
#endif
