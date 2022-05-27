#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed {

	private:
		int _fixedNb;
		static const int _fracBits = 8;

	public:
		Fixed ( void );
		Fixed ( const Fixed &copy);
		~Fixed ( void );
		Fixed &operator = (const Fixed &op);
		int getRawBits ( void ) const;
		void setRawBits ( int const raw );

};

#endif
