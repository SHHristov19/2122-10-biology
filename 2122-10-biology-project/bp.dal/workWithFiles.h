#pragma once
#include "pch.h"
#include "..\bp.types\types.h"

namespace bp::dal
{
	namespace workWithFiles
	{
		// Function for adding information from file to linked list of type PLANT
		bp::type::characteristics::PLANTS* fromFileToPlantsList(bp::type::characteristics::PLANTS* head);

		// Function for adding information from file to linked list of type ANIMAL
		bp::type::characteristics::ANIMAL* fromFileToAnimalsList(bp::type::characteristics::ANIMAL* head);

		// Function for adding all information from linked list of type ANIMAL to file
		void fromAnimalsListToFile(bp::type::characteristics::ANIMAL* head);

		// Function for adding add all information from linked list of type PLANT to file
		void fromPlantsListToFile(bp::type::characteristics::PLANTS* head);
	}
}