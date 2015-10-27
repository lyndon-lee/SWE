// Exercise 11.9 Solution: Hugeint.h
// HugeInt class definition.
#ifndef HUGEINT_H
#define HUGEINT_H

#include <iostream>
#include <string>
#include<cstdio>
#include<cmath>
#include<time.h>
using namespace std;

class HugeInt
{
   friend ostream &operator<<( ostream &, const HugeInt & );
public: 

   HugeInt( long = 0 ); 
   HugeInt( const string & ); 


   HugeInt& operator+( const HugeInt & ) const;


   HugeInt operator+( int ) const; 


   HugeInt operator+( const string & ) const;

   bool operator==( const HugeInt & ) const; 
   bool operator!=( const HugeInt & ) const; 
   bool operator<( const HugeInt & ) const; 


   bool operator<=( const HugeInt & ) const; 
   bool operator>( const HugeInt & ) const; 


   bool operator>=( const HugeInt & ) const;
   HugeInt operator-( const HugeInt & ) const; 
   void operator*( const HugeInt & ) const;
   //HugeInt operator/( const HugeInt & ) const; 
   void setLength(int length){
	   this->length = length;
   }
   int getLength() const;
   //~HugeInt(){
	  // delete []integer;
   //}
private:
   int length;
   short * integer;
}; 

#endif


