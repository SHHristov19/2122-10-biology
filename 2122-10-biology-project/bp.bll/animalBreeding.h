#pragma once

namespace bp::bll
{
	namespace animalBreeding
	{
		// Function that contains every animal breed
		void animalTypes(int choice, int choiceBreed);
		// Function that shows what newborns have been born
		void resultBreeding(int choice, int choice2, int choice3, int choice4, int animals, std::string typeOfAnimal, std::string furType[], std::string furColour[], int breed);
	}
}