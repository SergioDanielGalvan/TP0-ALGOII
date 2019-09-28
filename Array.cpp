#include "Array.h"
#include "complejo.h"

Array::Array()
{
	size = 10;
	ptr = new complejo[10];
}

Array::Array(int x)
{
	if ( (x<1) || (x>500) )
		size = 10;
	else size = x;
		ptr = new complejo[size];
}

Array::Array( const Array &init)
{
	size = init.size;
	ptr= new complejo[ size ];
	for ( int i = 0; i < size; i++ )
		ptr[ i ] = init.ptr[ i ];
} 

Array::~Array()
{
	if (ptr) delete[] ptr;
}

int Array::getSize() const{ return size; }

Array& Array::operator=( const Array &rigth )
{ 
	if ( &rigth != this) 
		{ if ( size != rigth.size) 
			{
				complejo *aux;
				aux = new complejo[ rigth.size ];
				delete[] ptr;
				size = rigth.size;
				ptr = aux;
				for( int i = 0; i < size; i++ ) 
					{ 
						ptr[ i ] = rigth.ptr[ i ];
					}	
				return *this;
			} 
		else
			{
				for( int i = 0; i < size; i++ ) ptr[ i ] = rigth.ptr[ i ];
				return *this; // al retornar una referencia permite x = y = z; 
			} 
		} 
}

bool Array::operator==( const Array &rigth) const
{ 
	if( size != rigth.size)
		return false; 
	else
		{
			for( int i = 0; i < size; i++ )
				{
					if ( ptr[ i ] != rigth.ptr[ i ] )
						return false;
				}
		}
	return true;
}

complejo& Array::operator[] ( int subscript )
{
	return ptr[subscript]; // retorna referencia
}