#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <cmath>

class Fixed {

public:
    Fixed( void );
    Fixed(const int x);
    Fixed(const Fixed &op);
    Fixed(float const f);
    ~Fixed( void );

    Fixed & operator=(const Fixed &op);

    int getRawBits() const;
    void setRawBits(int raw);

    float toFloat() const;
    int toInt() const;

private:
    int _fixedNb;
    static const int NUM_FRAC_BITS = 8;

};

std::ostream &operator<<(std::ostream &ostream, Fixed const &fixed);

#endif
