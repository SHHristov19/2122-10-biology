#pragma once
#include "pch.h"

namespace bp::consoleApp
{
	namespace biologyContent
	{
		namespace showInformation
		{
			// Display name of all animals
			void displayAnimals(bp::type::characteristics::ANIMAL* head, int x, int y);
			
			// Display name of all plants
			void displayPlants(bp::type::characteristics::PLANTS* head, int x, int y);

			// Display information for specific animal
			void displayInfoAnimal(bp::type::characteristics::ANIMAL* head, int n, int x, int y);

			// Display information for specific plant
			void displayInfoPlants(bp::type::characteristics::PLANTS* head, int n, int x, int y);
		}

		namespace search
		{
			// Display information for all animals with searched word ot other
			void displaySearchedInfoForAnimals(bp::type::characteristics::ANIMAL* head, int indexOfWantedAnimal);

			// Display information for all plants with searched word ot other
			void displaySearchedInfoForPlants(bp::type::characteristics::PLANTS* head, int indexOfWantedPlant);

			// Search given word or other in linked list of type PLANTS
			void searchP(bp::type::characteristics::PLANTS* head, string str);

			// Search given word or other in linked list of type ANIMAL
			void searchA(bp::type::characteristics::ANIMAL* head, string str);
		}
	}
}