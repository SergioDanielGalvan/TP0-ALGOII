#ifndef ARRAY_INCLUDED 
#define ARRAY_INCLUDED 
class Array 
{
 public: 
	Array(); // constructor 
	Array( constArray& );
	Array(int); 
	~Array( );
	intgetSize( ) const;
	Array&operator=( constArray& );
	booloperator==( constArray& ) const;
	int&operator[ ]( int);
	voidemitir();
	
 private: 
	intsize;
	int*ptr;
};
#endif //ARRAY_INCLUDED

