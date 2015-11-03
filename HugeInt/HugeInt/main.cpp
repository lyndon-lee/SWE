// Exercise 11.9 Solution: ex11_09.cpp
// HugeInt test program.
#include <iostream>
#include "Hugeint.h"

using namespace std;
//char opChar1[N / 2], opChar2[N / 2];

int main()
{
	//srand((unsigned)time(0));
	//for (int i = 0; i<1000000; i++){
	//	int digitnum = rand() % 10;
	//	opChar1[i] = digitnum + 48;
	//}
	//for (int i = 0; i<1000000; i++){
	//	int digitnum = rand() % 10;
	//	opChar2[i] = digitnum + 48;
	//}
	char opr;
	string opChar1, opChar2;
	while (cin >> opr >> opChar1 >> opChar2){
		HugeInt op1(opChar1);
		HugeInt op2(opChar2);
		HugeInt result;
		switch (opr){
		case '+':
			result = op1 + op2;
			cout << result << endl;
			break;
		case '-':
			result = op1 - op2;
			cout << result << endl;
			break;
		case '*':
			op1 * op2;
			break;
		default:
			cout << "default";
			break;
		}
	}
} // end main

