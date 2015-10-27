#include <iostream>
using namespace std;
int n = 900900000;
//2*3*5*7*11
int seg = 30030;
bool* isPrimes = new bool[n+1];
bool* segb = new bool[seg+1];
void filterSeg(){
	memset(segb, true, seg+1);
	segb[2] = true;
	for (int j = 2; j <= 13; ++j)
	{
		if (segb[j] == true)
		{
			for (int m = 2; j*m <= seg; ++m)
			{
				segb[j*m] = false;
			}
		}
	}
}
void FilterPrime()
{
	memset(isPrimes, true, n+1);
	memcpy(isPrimes, segb, seg+1);
	for (int i = 1; i < 30000;i++){
		memcpy(isPrimes+i*seg+1, segb+1, seg);
	}

	for (int j = 17; j <= n; ++j)
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
	filterSeg();
	FilterPrime();
	while (cin >> num){
		int count = 0;
		int i = 2;
		for (; i < n; i++){
			if (isPrimes[i]){
				count++;
			}
			if (count == num)
				break;
		}
		cout << i << endl;
	}
}
//#include <stdio.h>
//#include <string.h>
//#include <limits.h>  
//#include<iostream>
//
//#define BITMASK(b) (1 << ((b) % CHAR_BIT))
//#define BITSLOT(b) ((b) / CHAR_BIT)
//#define BITSET(a, b) ((a)[BITSLOT(b)] |= BITMASK(b))
//#define BITCLEAR(a, b) ((a)[BITSLOT(b)] &= ~BITMASK(b))
//#define BITTEST(a, b) ((a)[BITSLOT(b)] & BITMASK(b))
//#define BITNSLOTS(nb) ((nb + CHAR_BIT - 1) / CHAR_BIT)
//#define MAX 90090000*8
//#define seg 30030*8
//using namespace std;
////2*3*5*7*11
//
//char bitarray[BITNSLOTS(MAX)];
//char segb[BITNSLOTS(seg)];
//void filterSeg(){
//	memset(segb, 0, BITNSLOTS(seg));
//	int i, j;
//	for (i = 2; i < 13; i++) {
//		if (!BITTEST(segb, i)) {
//			for (j = i + i; j < seg; j += i)
//				BITSET(segb, j);
//		}
//	}
//}
//int main()
//{
//	filterSeg();
//	memset(bitarray, 0, BITNSLOTS(MAX));
//	for (int i = 0; i < 3000; i++){
//		memcpy(bitarray + i*BITNSLOTS(seg), segb, BITNSLOTS(seg));
//	}
//	int i, j;
//
//	for (i = 17; i < MAX; i++) {
//		if (!BITTEST(bitarray, i)) {
//			for (j = i + i; j < MAX; j += i)
//				BITSET(bitarray, j);
//		}
//	}
//	int num = 0;
//	while (cin >> num){
//		int count = 0;
//		int i = 2;
//		for (; i <MAX; i++){
//			if (!BITTEST(bitarray, i)){
//				count++;
//			}
//			if (count == num)
//				break;
//		}
//		cout << i << endl;
//	}
//	cin.get();
//	return 0;
//}

