#include <iostream>
using namespace std;
int n = 600000000;
bool* isPrimes = new bool[n + 1];
void FilterPrime()
{
	for (int i = 2; i <= n; ++i)
	{
		isPrimes[i] = true;
	}
	isPrimes[2] = true;
	for (int j = 2; j <= n; ++j)
	{
		if (isPrimes[j] == true)
		{
			for (int m = 2; j*m <= n; ++m)
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
	FilterPrime();	
	int count = 0;
	int i = 2;
	for (; i < n;i++){
		if (isPrimes[i]){
			count++;
		}
		if (count == num)
			break;
	}
	cout << i << endl;
	return 0;
}
//#include<iostream>
//using namespace std;
//const long N = 20000;
//long prime[N] = { 0 }, num_prime = 0;
//bool isNotPrime[N] = { true, true };
//int main()
//{
//	for (long i = 2; i < N; i++)
//	{
//		if (!isNotPrime[i])
//			prime[num_prime++] = i;
//		//关键处1        
//		for (long j = 0; j < num_prime && i * prime[j] < N; j++)
//		{
//			isNotPrime[i * prime[j]] = 1;
//			if (!(i % prime[j]))  //关键处2                  
//				break;
//		}
//	}
//	return 0;
//}