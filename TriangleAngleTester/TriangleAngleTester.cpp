#include "pch.h"
#include "CppUnitTest.h"

extern "C" int GetTriangleAngles(int, int, int);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TriangleAngleTester
{
	TEST_CLASS(TriangleAngleTester)
	{
	public:
		
		TEST_METHOD(Triangleangletesting1)
		{
			// Testing the angles of the triangle 
			int side1 = 3;
			int side2 = 3;
			int side3 = 3;
			
			int r1 = GetTriangleAngles(side1, side2, side3);
			int r2 = GetTriangleAngles(side3, side1, side2);
			int r3 = GetTriangleAngles(side2, side3, side1);
			int result[3] = { r1,r2,r3 };
			int expected[3] = { 60,60,60 };
			Assert::AreEqual(result[1], expected[1]);
			Assert::AreEqual(result[2], expected[2]);
			Assert::AreEqual(result[3], expected[3]);
		}
		TEST_METHOD(Triangleangletesting2)
		{
			// Testing the angles of the iscocles triangle
			int side1 = 8;
			int side2 = 8;
			int side3 = 2;

			int r1 = GetTriangleAngles(side1, side2, side3);
			int r2 = GetTriangleAngles(side2, side1, side3);
			int r3 = GetTriangleAngles(side3, side2, side1);
			int result[3] = { r1,r2,r3 };
			int expected[3] = { 14,82,14 };
			Assert::AreEqual(expected[1],result[1]);
			Assert::AreEqual( expected[2],result[2]);
			Assert::AreEqual( expected[3],result[3]);
		}
		TEST_METHOD(Triangleangletesting3)
		{
			// testing the angles of scalene triangle
			int side1 = 5;
			int side2 = 6;
			int side3 = 7;

			int r1 = GetTriangleAngles(side1, side2, side3);
			int r2 = GetTriangleAngles(side2, side1, side3);
			int r3 = GetTriangleAngles(side3, side2, side1);
			int result[3] = { r1,r2,r3 };
			int expected[3] = { 44,57,78 };
			Assert::AreEqual(expected[1], result[1]);
			Assert::AreEqual(expected[2], result[2]);
			Assert::AreEqual(expected[3], result[3]);
		}

	};
}
