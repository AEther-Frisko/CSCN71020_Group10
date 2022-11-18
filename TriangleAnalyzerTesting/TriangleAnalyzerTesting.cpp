#include "pch.h"
#include "CppUnitTest.h"

extern "C" char* analyzeTriangle(int, int, int);
extern "C" double GetTriangleAngles(int, int, int);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TriangleAnalyzerTesting
{
	TEST_CLASS(TriangleAnalyzerTesting)
	{
	public:
		
		TEST_METHOD(IncorrctTriangleTest1)
		{
			// First check: All numbers under or equal to 0
			char* Result = "";
			Result = analyzeTriangle(0, -9, -3);
			Assert::AreEqual("Not a triangle", Result);
		}
		TEST_METHOD(IncorrctTriangleTest2)
		{
			// Second check: 2 numbers under or equal to 0
			char* Result = "";
			Result = analyzeTriangle(7, -8, -4);
			Assert::AreEqual("Not a triangle", Result);
		}
		TEST_METHOD(IncorrctTriangleTest3)
		{
			// First check: 1 number under or equal to 0
			char* Result = "";
			Result = analyzeTriangle(6, 9, 0);
			Assert::AreEqual("Not a triangle", Result);
		}
		TEST_METHOD(IncorrctTriangleTest4)
		{
			// First check: All numbers equal under 0
			char* Result = "";
			Result = analyzeTriangle(-5, -5, -5);
			Assert::AreEqual("Not a triangle", Result);
		}
		TEST_METHOD(EquilateralTriangleTest)
		{
			char* Result = "";
			Result = analyzeTriangle(3, 3, 3);
			Assert::AreEqual("Equilateral triangle", Result);

		}
		TEST_METHOD(IsoscelesTriangleTest1)
		{
			// Testing the Isoceles Triangle with nums 1 and 2 being equal 
			char* Result = "";
			Result = analyzeTriangle(8, 8, 3);
			Assert::AreEqual("Isosceles triangle", Result);
		} 
		TEST_METHOD(IsoscelesTriangleTest2)
		{
			// Testing the Isoceles Triangle with nums 2 and 3 being equal 
			char* Result = "";
			Result = analyzeTriangle(6, 5, 5);
			Assert::AreEqual("Isosceles triangle", Result);
		}
		TEST_METHOD(IsoscelesTriangleTest3)
		{
			// Testing the Isoceles Triangle with nums 1 and 3 being equal 
			char* Result = "";
			Result = analyzeTriangle(11, 5, 11);
			Assert::AreEqual("Isosceles triangle", Result);
		}
		TEST_METHOD(ScaleneTriangleTest1)
		{
			// Testing the Scalene Triangle with ascending orders 
			char* Result = "";
			Result = analyzeTriangle(1, 2, 3);
			Assert::AreEqual("Scalene triangle", Result);
		}
		TEST_METHOD(ScaleneTriangleTest2)
		{
			// Testing the Scalene Triangle with decending orders 
			char* Result = "";
			Result = analyzeTriangle(4, 2, 1);
			Assert::AreEqual("Scalene triangle", Result);
		}
		TEST_METHOD(Triangleangletesting1)
		{
			// Testing the angles of the triangle 
			double Result = 0;
			Result = GetTriangleAngles(4, 2, 1);
			Assert::AreEqual(180.000000, Result);
		}
		TEST_METHOD(Triangleangletesting2)
		{
			// Testing the angles of the triangle 
			double Result = 0;
			Result = GetTriangleAngles(4, 4, 4);
			Assert::AreEqual(60.000000, Result);
		}
		TEST_METHOD(Triangleangletesting3)
		{
			// Testing the angles of the triangle 
			double Result = 0;
			Result = GetTriangleAngles(2, 2, 2);
			Assert::AreEqual(60.000000, Result);
		}
	
		TEST_METHOD(Triangleangletesting4)
		{
			// Testing the angles of the triangle 
			double Result = 0;
			Result = GetTriangleAngles(5, 5, 5);
			Assert::AreEqual(60.000000, Result);
		}
		TEST_METHOD(Triangleangletesting5)
		{
			// Testing the angles of the triangle 
			double Result = 0;
			Result = GetTriangleAngles(10, 10, 10);
			Assert::AreEqual(60.000000, Result);
		}
		TEST_METHOD(Triangleangletesting6)
		{
			// Testing the angles of the triangle 
			double Result = 0;
			Result = GetTriangleAngles(7, 9, 8);
			Assert::AreEqual(48.189685, Result);
		}
	};
}
