
#include <iostream>
#include <cctype>
#include "Hugeint.h" 

#define Pi acos(-1.0)//定义Pi的值
#define N 10000000
using namespace std;

struct complex //定义复数结构体
{
	double re, im;
	complex(double r = 0.0, double i = 0.0)
	{
		re = r, im = i;
	}  //初始化
	//定义三种运算 
	complex operator +(complex o)
	{
		return complex(re + o.re, im + o.im);
	}
	complex operator -(complex o)
	{
		return complex(re - o.re, im - o.im);
	}
	complex operator *(complex o)
	{
		return complex(re*o.re - im*o.im, re*o.im + im*o.re);
	}
}x1[N], x2[N];
char a[N / 2], b[N / 2];
int sum[N];    //存储最后的结果

void BRC(complex *y, int len)//二进制反转倒置
{
	int i, j, k;
	for (i = 1, j = len / 2; i<len - 1; i++)
	{
		if (i<j)swap(y[i], y[j]);//i<j保证只交换一次
		k = len / 2;
		while (j >= k)
		{
			j -= k; k = k / 2;
		}
		if (j<k)j += k;
	}
}
void FFT(complex *y, int len, double on)//on=1表示顺，-1表示逆
{
	int i, j, k, h;
	complex u, t;
	BRC(y, len);
	for (h = 2; h <= len; h <<= 1)//控制层数
	{
		//初始化单位复根
		complex wn(cos(on * 2 * Pi / h), sin(on * 2 * Pi / h));
		for (j = 0; j<len; j += h)//控制起始下标
		{
			//初始化螺旋因子
			complex w(1, 0);
			for (k = j; k<j + h / 2; k++)
			{
				u = y[k];
				t = w*y[k + h / 2];
				y[k] = u + t;
				y[k + h / 2] = u - t;
				w = w*wn;//更新螺旋因子
			}
		}
	}
	if (on == -1)
	for (i = 0; i<len; i++) //逆FFT(IDFT)
		y[i].re /= len;

}
HugeInt::HugeInt( long value )
{
	long valueCopy = value;
	int i = 0;
	for (; valueCopy != 0; i++){
		valueCopy/= 10;
	}
	length = i;
	integer = new short[length];
	for ( int j = length - 1; value != 0 && j >= 0; j-- )
    {
      integer[ j ] = value % 10;
      value /= 10;
    } 
} 


HugeInt::HugeInt(const string &number)
{
	// place digits of argument into array
	
	int k = 0;
	for (k = 0; k < number.size() && number[k] - '0'== 0; k++)
		;
	length = number.size()-k;
	integer = new short[length];
	for (int j = 0; j < length; j++, k++)
	if (isdigit(number[k]))
		integer[j] = number[k] - '0';
}


int HugeInt::getLength() const
{
   return length; // length is from first digit (at i) to end of array
}

HugeInt& HugeInt::operator+( const HugeInt &op2 ) const
{
   HugeInt temp; 
   int carry = 0;
   temp.setLength(((this->length >= op2.getLength()) ? (this->length) : op2.getLength())+1);
   temp.integer = new short[temp.getLength()];
   temp.integer[0] = 0;
   int thisLength = length-1;
   int otherLength = op2.getLength()-1;
   int resultLength = temp.getLength()-1;
   while (resultLength>=0)
   {
	   int operator1 = 0;
	   int operator2 = 0;
	   if (thisLength<0){
		   operator1 = 0;
	   }
	   else{
		   operator1 = integer[thisLength];
	   }
	   if (otherLength<0){
		   operator2 = 0;
	   }
	   else{
		   operator2 = op2.integer[otherLength];
	   }
      temp.integer[resultLength] = operator1 + operator2 + carry;
      if ( temp.integer[resultLength] > 9 )
      {
		  temp.integer[resultLength] %= 10;
          carry = 1;
      } 
      else
         carry = 0;
	  thisLength--;
	  otherLength--;
	  resultLength--;
   } 

   return temp; 
} 

HugeInt HugeInt::operator+( int op2 ) const
{
   return *this + HugeInt( op2 );
}



HugeInt HugeInt::operator+( const string &op2 ) const
{
   return *this + HugeInt( op2 );
} 

bool HugeInt::operator==( const HugeInt &op2 ) const
{
	if (op2.getLength() != length){
		return false;
	}
   for ( int i = 0; i < length; i++ ) 
      if ( op2.integer[ i ] != integer[ i ] )
         return false; 

   return true; 
} 


bool HugeInt::operator!=( const HugeInt &op2 ) const
{
   return !( *this == op2 ); 
} 


bool HugeInt::operator<(const HugeInt &op2) const
{
	if (length < op2.getLength()){
		return true;
	}
	else if (length > op2.getLength()){
		return false;
	}
   for ( int i = 0; i < length; i++ )
   {
      if ( integer[ i ] == op2.integer[ i ] )
         continue; 
      else if ( integer[ i ] > op2.integer[ i ] )
         return false; 
      else
         return true; 
   } 

   return false;
} 


bool HugeInt::operator<=( const HugeInt &op2 ) const
{
   return !( *this > op2 );
} 


bool HugeInt::operator>( const HugeInt &op2 ) const
{
   return op2 < *this;
} // end function operator>


bool HugeInt::operator>=( const HugeInt &op2 ) const
{
   return !( *this < op2 );
} // end function operator>=

ostream& operator<<( ostream &output, const HugeInt &num )
{
   int i=0;

   for (i = 0; i < num.getLength() && num.integer[i] == 0; i++)
	   ; // skip leading zeros

   if (i == num.getLength()){
	   output << 0;
   }
   else{
	   for (; i < num.getLength(); i++)
		   output << num.integer[i];
   }

   return output;
} 


HugeInt HugeInt::operator-( const HugeInt &op2 ) const
{

   HugeInt result;
   result.setLength((this->length > op2.getLength()) ? (this->length) : op2.getLength());
   result.integer = new short[result.getLength()];
   if (op2 > *this)
   {
	   cout << "Error: Tried to subtract larger value from smaller value."
		   << endl;
	   return HugeInt("0");
   }
   int otherLength = op2.getLength()-1;

   bool minusOne = false;

   for ( int i = length - 1; i >= 0; i-- )
   {
      int topValue = this->integer[i];
	  int bottomValue = 0;
	  if (otherLength >= 0){
		  bottomValue = op2.integer[otherLength];
	  }
	  else{
		 bottomValue = 0;
	  }

      if ( minusOne )
      {
         if ( topValue == 0 ) // topValue cannot become -1
            topValue = 9;
         else
         {
            topValue -= 1; 
            minusOne = false; 
         } 
      } 

      if ( topValue >= bottomValue )
         result.integer[ i ] = topValue - bottomValue;
      else
      {
         topValue += 10;
         minusOne = true;
         result.integer[ i ] = topValue - bottomValue;
      } 
	  otherLength--;
   } 
   return result; 
} 


//HugeInt HugeInt::operator*( const HugeInt &op2 ) const
//{
//   int carryOver = 0; 
//   HugeInt total; 
//   total.setLength(length + op2.getLength());
//   total.integer = new short[total.getLength()];
//
//   HugeInt smaller = ( *this < op2 ) ? *this : op2;
//   HugeInt larger = ( *this > op2 ) ? *this : op2;
//   int indexOfFirstDigitForLarger = 0;
//   for ( int i = smaller.getLength()-1; i >= 0; i-- )
//   {
//      HugeInt currentInt;
//	  currentInt.setLength(larger.getLength()+1);
//	  currentInt.integer = new short[currentInt.getLength()];
//	  int currentIntFrontHandle = currentInt.getLength()-1;
//      for ( int j = larger.getLength()-1; j >=0; j-- )
//      {
//         int currentResult = carryOver +
//            ( larger.integer[j] * smaller.integer[i] );
//         if ( j - 1 == indexOfFirstDigitForLarger )
//         {
//            carryOver = 0;  
//            currentInt.integer[ currentIntFrontHandle ] =
//               currentResult % 10;
//            currentIntFrontHandle -= 1;
//            currentInt.integer[ currentIntFrontHandle ] =
//               currentResult / 10;
//            currentIntFrontHandle -= 1;
//         } 
//         else
//         {
//            carryOver = currentResult / 10;
//            currentInt.integer[ currentIntFrontHandle ] =
//               currentResult % 10;
//            currentIntFrontHandle -= 1;
//         }
//      } 
//      total = total + currentInt; 
//	//  delete[] currentInt.integer;
//   } 
//
//   return total; 
//} 
void HugeInt::operator*(const HugeInt &op2) const{
	for (int i = 0; i < length; i++){
		a[i] = this->integer[i]+48;
	}
	for (int i = 0; i < op2.getLength(); i++){
		b[i] = op2.integer[i]+48;
	}
	int len1, len2, len, i;
	len1 = strlen(a);
	len2 = strlen(b);
	len = 1;
	//扩充次数界至2*n
	while (len<2 * len1 || len<2 * len2)len <<= 1;//右移相当于len=len*2
	//倒置存储
	for (i = 0; i<len1; i++)
	{
		x1[i].re = a[len1 - 1 - i] - '0'; x1[i].im = 0.0;
	}
	for (; i<len1; i++)  //多余次数界初始化为0
	{
		x1[i].re = x1[i].im = 0.0;
	}
	for (i = 0; i<len2; i++)
	{
		x2[i].re = b[len2 - 1 - i] - '0'; x2[i].im = 0.0;
	}
	for (; i<len2; i++)  //多余次数界初始化为0
	{
		x2[i].re = x2[i].im = 0.0;
	}
	//FFT求值
	FFT(x1, len, 1);//FFT(a) 1表示顺 -1表示逆
	FFT(x2, len, 1);//FFT(b)
	//点乘，结果存入x1
	for (i = 0; i<len; i++)
		x1[i] = x1[i] * x2[i];
	//插值，逆FFT（IDTF）
	FFT(x1, len, -1);

	//细节处理
	for (i = 0; i<len; i++)
		sum[i] = x1[i].re + 0.5;//四舍五入
	for (i = 0; i<len; i++)     //进位
	{
		sum[i + 1] += sum[i] / 10;
		sum[i] %= 10;
	}
	//输出
	len = len1 + len2 - 1;
	while (sum[len] <= 0 && len>0)len--;//检索最高位
	for (i = len; i >= 0; i--)   //倒序输出
		cout << sum[i];
	cout << endl;
}
//
//
//HugeInt HugeInt::operator/( const HugeInt &op2 ) const
//{
//   // use copy constructor to create remainderIntegers;
//   // remainderIntegers used to add digits to remainders
//   HugeInt remainderIntegers( *this );
//   HugeInt currentValue( "0" );
//   HugeInt result( "0" ); 
//   int maxSolutionLength = this->getLength();
//   for ( int i = digits - maxSolutionLength; i < digits; i++ )
//   {
//      currentValue = currentValue * HugeInt( "10" );
//      currentValue.integer[ digits - 1 ] = remainderIntegers.integer[ i ];
//
//      HugeInt tempResult( "0" );
//      if ( op2 > currentValue )
//         result.integer[ i ] = 0;
//      else
//      {
//         int j;
//         for ( j = 1; j <= 10; j++ )
//         {
//            HugeInt tempProduct = op2 * HugeInt( j );
//            if ( tempProduct > currentValue )
//               break;
//         } 
//         result.integer[ i ] = j - 1; 
//         tempResult = op2 * HugeInt( j - 1 );
//      } 
//      currentValue = currentValue - tempResult;
//   } 
//   return result;
//} 


