#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed {
private:
	int fixed_value;
	static const int fractional; //what does static mean in this purpose? also this should be always integer literal 8
public:
	Fixed();
	Fixed(const int ints);
	Fixed(const float floats);
	Fixed(const Fixed& copy);
	Fixed &operator=(const Fixed &src); 
	~Fixed();

	float toFloat( void ) const;
	int toInt( void ) const;
};
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
#endif
