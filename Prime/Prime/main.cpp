#include <iostream>
using namespace std;
int n = 600000000;
bool* isPrimes = new bool[n + 1];

int upBounds[70] =
{
	10,
	30,
	50,
	70,
	90,
	100,
	200,
	300,
	400,
	500,
	600,
	700,
	800,
	900,
	1000,
	2000,
	3000,
	4000,
	5000,
	6000,
	7000,
	8000,
	9000,
	10000,
	20000,
	30000,
	40000,
	50000,
	60000,
	70000,
	80000,
	90000,
	100000,
	200000,
	300000,
	400000,
	500000,
	600000,
	700000,
	800000,
	900000,
	1000000,
	2000000,
	3000000,
	4000000,
	5000000,
	6000000,
	7000000,
	8000000,
	9000000,
	10000000,
	20000000,
	30000000,
	40000000,
	50000000,
	60000000,
	70000000,
	80000000,
	90000000,
	100000000,
	200000000,
	300000000,
	400000000,
	500000000,
	600000000,
	700000000,
	800000000,
	900000000,
	1000000000,
	2000000000
};
int primeNumber[70] = {
	4,
	10,
	15,
	19,
	24,
	25,
	46,
	62,
	78,
	95,
	109,
	125,
	139,
	154,
	168,
	303,
	430,
	550,
	669,
	783,
	900,
	1007,
	1117,
	1229,
	2262,
	3245,
	4203,
	5133,
	6057,
	6935,
	7837,
	8713,
	9592,
	17984,
	25997,
	33860,
	41538,
	49098,
	56543,
	63951,
	71274,
	78498,
	148933,
	216816,
	283146,
	348513,
	412849,
	476648,
	539777,
	602489,
	664579,
	1270607,
	1857859,
	2433654,
	3001134,
	3562115,
	4118064,
	4669382,
	5216954,
	5761455,
	11078937,
	16252325,
	21336326,
	26355867,
	31324703,
	36252931,
	41146179,
	46009215,
	50847534,
	98222287
};


void FilterPrime(int upbound)
{
	for (int i = 2; i <= upbound; ++i)
	{
		isPrimes[i] = true;
	}
	isPrimes[2] = true;
	for (int j = 2; j <= upbound; ++j)
	{
		if (isPrimes[j] == true)
		{
			for (int m = 2; j*m <= upbound; ++m)
			{
				isPrimes[j*m] = false;
			}
		}
	}
}
int main()
{
	int num;
	cin >> num;
	int offset = 0;
//	cout << primeNumber[69] << endl;
	for (int i = 0; i < 70; i++){
		if (num<primeNumber[i]){
			offset = i;
			break;
		}
	}
	FilterPrime(upBounds[offset]);
	int count = 0;
	int i = 2;
	for (; i < upBounds[offset]; i++){
		if (isPrimes[i]){
			count++;
		}
		if (count == num)
			break;
	}
	cout << i << endl;
	return 0;
}