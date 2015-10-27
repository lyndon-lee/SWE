#include "stdafx.h"
#include "CppUnitTest.h"
#include"../HugeInt/HugeInt.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HugeIntTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: Your test code here
			HugeInt op1("4888");
			HugeInt op2("535");
			HugeInt result;
			result = op1 + op2;
			short *a = result.getInteger();
			Assert::AreEqual((short)0, a[6]);
		}
		TEST_METHOD(TestMethod2)
		{
			// TODO: Your test code here
			HugeInt op1("000004888");
			HugeInt op2("0000535");
			HugeInt result;
			result = op1 - op2;
			short *a = result.getInteger();
			Assert::AreEqual((short)3, a[3]);
		}
		TEST_METHOD(TestMethod3)
		{
			// TODO: Your test code here
			HugeInt op1("4888");
			HugeInt op2("5359999");
			HugeInt result;
			op1 * op2;
		}

	};
}