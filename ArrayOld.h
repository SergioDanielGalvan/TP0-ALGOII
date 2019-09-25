#ifndef ARRAY_INCLUDED 
#define ARRAY_INCLUDED 
class Array 
{
 public: 
	Array(); // constructor 
	Array( const Array & );
	Array(int); 
	~Array( );
	int getSize( ) const;
	Array&operator=( const Array & );
	bool operator==( const Array & ) const;
	int &operator[]( int);
	void emitir();

 private: 
	intsize;
	int*ptr;
};
#endif //ARRAY_INCLUDED

