#include "complejo.h"

#ifndef ARRAY_INCLUDED
#define ARRAY_INCLUDED

class Array
{
 public: 
	Array(); // constructor 
	Array( const Array & );
	Array( int ); 
	~Array();
	int getSize() const;
	Array &operator=( const Array & );
	bool operator==( const Array & ) const;
	complejo &operator[]( int );
	void emitir();

 private: 
	int size;
	complejo *ptr;
};
#endif //ARRAY_INCLUDED

