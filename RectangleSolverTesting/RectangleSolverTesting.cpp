#include "pch.h"
#include "CppUnitTest.h"

extern "C" char* analyzeRect(int[]);


using namespace Microsoft::VisualStudio::CppUnitTestFramework;





namespace RectangleSolverTesting
{
	TEST_CLASS(RectangleSolverTesting)
	{
	public:
		// first tests will test the outside exceptions to make sure it all works
		TEST_METHOD(IncorrectPointsTest1)
		{
			//First test, all points unable to make a proper rectangles
			char* Result = "";
			int points[8] = {1, 1, 2, 2, 3, 3, 4, 4};
			Result = analyzeRect(points);
			Assert::AreEqual("Input is not a rectangle.", Result);
		}
		TEST_METHOD(IncorrectPointsTest2)
		{
			//Second test, all points consisting of invalid inputs
			char* Result = "";
			int points[8] = { -1, 0.5, -22, 2.6, -3.5, 0, 0, 7.1 };
			Result = analyzeRect(points);
			Assert::AreEqual("Input is not a rectangle.", Result);
		}
		TEST_METHOD(IncorrectPointsTest3)
		{
			//Third test,  All points but 4th create a proper rectangle
			char* Result = "";
			int points[8] = { 1, 1, 4, 1, 4, 3, 2, 3 };
			Result = analyzeRect(points);
			Assert::AreEqual("Input is not a rectangle.", Result);
		}
		TEST_METHOD(IncorrectPointsTest4)
		{
			//Third test,  All points but 3rd create a proper rectangle
			char* Result = "";
			int points[8] = { 20, 5, 25, 5, 25, 14, 20, 13 };
			Result = analyzeRect(points);
			Assert::AreEqual("Input is not a rectangle.", Result);
		}
		TEST_METHOD(IncorrectPointsTest5)
		{
			//Third test,  All points but 2nd create a proper rectangle
			char* Result = "";
			int points[8] = { 5, 5, 20, 6, 10, 11, 5, 11 };
			Result = analyzeRect(points);
			Assert::AreEqual("Input is not a rectangle.", Result);
		}
		TEST_METHOD(IncorrectPointsTest6)
		{
			//Third test,  All points but 1st create a proper rectangle
			char* Result = "";
			int points[8] = { 1, -1, 3, 1, 3, 4, 3, 1 };
			Result = analyzeRect(points);
			Assert::AreEqual("Input is not a rectangle.", Result);
		}
		TEST_METHOD(SquareTest1)
		{
			//First square test, distance between points equal
			char* Result = "";
			int points[8] = { 1, 1, 2, 1, 2, 2, 1, 2 };
			Result = analyzeRect(points);
			Assert::AreEqual("Input is a square.", Result);
		}
		TEST_METHOD(SquareTest2)
		{
			//Second square test, distance between points equal, including negative number
			char* Result = "";
			int points[8] = { 5, -4, 10, -4, 10, 1, 5, 1  };
			Result = analyzeRect(points);
			Assert::AreEqual("Input is a square.", Result);
		}
		TEST_METHOD(SquareTest3)
		{
			//Third square test, same difference, one negative 
			char* Result = "";
			int points[8] = { 0, 0, 5, 0, 5, -5, 0, -5 };
			Result = analyzeRect(points);
			Assert::AreEqual("Input is a square.", Result);
		}
		TEST_METHOD(CorrectTesting1)
		{
			//First correct test, length greater than width 
			char* Result = "";
			int points[8] = { 1, 5, 2, 5, 2, 10, 1, 10 };
			Result = analyzeRect(points);
			Assert::AreEqual("Input is a rectangle.", Result);
		}
		TEST_METHOD(CorrectTesting2)
		{
			//Second correct test, width greater than length 
			char* Result = "";
			int points[8] = { 6, 10, 16, 10, 16, 15, 6, 15 };
			Result = analyzeRect(points);
			Assert::AreEqual("Input is a rectangle.", Result);
		}
		TEST_METHOD(CorrectTesting3)
		{
			//Third correct test, width negative difference, length positive  
			char* Result = "";
			int points[8] = { 10, 15, 2, 15, 2, 19, 10, 19 };
			Result = analyzeRect(points);
			Assert::AreEqual("Input is a rectangle.", Result);
		}
		TEST_METHOD(CorrectTesting4)
		{
			//Fourth correct test, Length negative difference, width positive  
			char* Result = "";
			int points[8] = { 50, 125, 55, 125, 55, 110, 50, 110 };
			Result = analyzeRect(points);
			Assert::AreEqual("Input is a rectangle.", Result);
		}
		TEST_METHOD(CorrectTesting5)
		{
			//fifth correct test, Both negative  
			char* Result = "";
			int points[8] = { 0, 0, -5, 0, -5, -8, 0, -8 };
			Result = analyzeRect(points);
			Assert::AreEqual("Input is a rectangle.", Result);
		}
	};
}
