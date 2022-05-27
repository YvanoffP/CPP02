#include "Fixed.hpp"

#define FIXED_POINT_ONE (1 << 8)

Fixed::Fixed():_fixedNb(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int x )
{
    std::cout << "Int constructor called" << std::endl;
    _fixedNb = (x << NUM_FRAC_BITS);
    return;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	_fixedNb = std::roundf(f * FIXED_POINT_ONE);
    return ;
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed &Fixed::operator=( const Fixed &op )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &op)
		return (*this);
	this->_fixedNb = op.getRawBits();
	return (*this);
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedNb);
}

void Fixed::setRawBits( int const raw )
{
	this->_fixedNb = raw;
	return ;
}

Fixed::Fixed(Fixed const &op)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = op;
}

float Fixed::toFloat() const
{
    return ((float )_fixedNb / FIXED_POINT_ONE);
}

int Fixed::toInt() const
{
    return (_fixedNb >> NUM_FRAC_BITS);
}

std::ostream &operator<<(std::ostream &ostream, Fixed const &fixed)
{
    ostream << fixed.toFloat();
    return ostream;
}
