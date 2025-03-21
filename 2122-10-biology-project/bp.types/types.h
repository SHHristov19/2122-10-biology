#pragma once
#include "pch.h"

namespace bp::type
{
	namespace frames
	{
		struct FRAME {
			string one;
			string two;
			string three;
			string four;
			string five;
			string quizFrame;
			string eight;
			string nine;
		};
	}

	namespace characteristics
	{
		struct HIGH {
			double averageMaleHigh;
			double averageFemaleHigh;
		};

		struct WEIGHT {
			double averageMaleWieght;
			double averageFemaleWieght;
		};

		struct CLASSIFICATION {
			string Phylum;
			string Class;
			string Order;
			string Family;
			string Genus;
			string Species;
		};

		struct PLANTS {
			string name;
			CLASSIFICATION plant;
			PLANTS* next = NULL;
		};

		struct ANIMAL {
			string name;
			CLASSIFICATION animal;
			HIGH high;
			WEIGHT weight;
			ANIMAL* next = NULL;
		};
	}
}