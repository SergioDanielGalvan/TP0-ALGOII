#include“Array.h”

Array::Array()
{
	size=10;
	ptr= new int[10];
}
 
Array::Array(int x)
{
	if ( (x<1)||(x>500) )
		size=10;
	else size=x;
		ptr= new int[size];
}

Array::Array( const Array &init)
{
	size=init.size;
	ptr= new int[ size ];
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
				int *aux;
				aux=new int[ rigth.size];
				delete[] ptr;
				size=rigth.size;
				ptr=aux;
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
		for( int i = 0; i < size; i++ )
			if ( ptr[ i ] != rigth.ptr[ i ] )
				return false;
		return true;
}

int& Array::operator[] ( int subscript )
{
	return ptr[subscript]; // retorna referencia
}