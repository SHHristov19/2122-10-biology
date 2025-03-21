#pragma once
#include "pch.h"

namespace bp::dal
{
	namespace population
	{
		// Function for getting animal population from file
		int populationAnimal();

		// Function for getting plant population from file
		int populationPlant();

		// Function for editing animals population
		void editPopulationAnimal(int animals);

		// Function for editing plants population
		void editPopulationPlants(int plants);
	}
}