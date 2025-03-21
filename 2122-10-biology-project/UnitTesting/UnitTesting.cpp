#include "pch.h"
#include "CppUnitTest.h"

#include "..\bp.tools\extraFunctions.h"
#include "..\bp.bll\biologyContent.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

struct Node
{
	int data;
	Node* next;
};

namespace UnitTesting
{
	TEST_CLASS(UnitTesting)
	{
	public:	
		TEST_METHOD(toUpperFunction)
		{
			std::string text = "HORSE";
			std::string result = bp::tools::toUpper("Horse");
			Assert::AreEqual(text, result);
		}
	};
}
