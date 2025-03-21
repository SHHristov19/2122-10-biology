#pragma once

namespace bp::consoleApp
{
	namespace plantsSeeding
	{
		// Function that displays plant seeding menu
		void menuPlantsSeeding();

		// Function that displays plants sort
		void sortOption(int choice);

		// Functions that displays plants
		void plantOption(int x, int y);

		// Function that gives user a choice for number of grains and displays the result 
		void howManyGrains(string sort);

		namespace plantsFigures
		{
			// Function that displays tomato figure
			void tomato(int x, int y);

			// Function that displays pear figure
			void pear(int x, int y);

			// Function that displays coconut tree figure
			void coconutTree(int x, int y);
		}

		namespace menuParts
		{
			// Function that displays congratulations label
			void congratulationsLabel(int x, int y);

			// Function that displays border for plants seeding menu
			void border(int x, int y);

			// Function that displays label for plants seeding menu
			void label(int x, int y);
		}
	}
}