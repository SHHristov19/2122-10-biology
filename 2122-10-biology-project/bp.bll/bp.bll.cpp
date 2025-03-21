#include "pch.h"
#include "biologyContent.h"
#include "animalBreeding.h"
#include "..\bp.types\types.h"
#include "..\bp.consoleApp\animalBreeding.h"
#include "..\bp.consoleApp\plantsSeeding.h"
#include "..\bp.dal\population.h"

namespace bp::bll
{
	namespace biologyContent
	{

		//Check if the given string can convert to double
		double checkForDouble(string str)
		{
			try {
				throw stod(str);
			}
			catch (double a) { return a; }
			catch (invalid_argument) { return 100.0; }
		}

		// Function for adding new node in the end of linked list of type ANIMAL
		bp::type::characteristics::ANIMAL* prependNodeAnimal(string name, bp::type::characteristics::ANIMAL* head, string classification[], double highArray[], double weightArray[])
		{

			bp::type::characteristics::ANIMAL* newNode = new bp::type::characteristics::ANIMAL;
			newNode->name = name;
			newNode->animal.Phylum = classification[0];
			newNode->animal.Class = classification[1];
			newNode->animal.Order = classification[2];
			newNode->animal.Family = classification[3];
			newNode->animal.Genus = classification[4];
			newNode->animal.Species = classification[5];
			newNode->high.averageMaleHigh = highArray[0];
			newNode->high.averageFemaleHigh = highArray[1];
			newNode->weight.averageMaleWieght = weightArray[0];
			newNode->weight.averageFemaleWieght = weightArray[1];

			if (head == NULL)
			{
				head = newNode;
				return head;
			}

			bp::type::characteristics::ANIMAL* temp = head;
			while (temp)
			{
				if (temp->next == NULL)
				{
					temp->next = newNode;
					break;
				}
				temp = temp->next;
			}

			return head;
		}

		// Function for adding new node in the end of linked list of type PLANT
		bp::type::characteristics::PLANTS* prependNodePlants(string name, bp::type::characteristics::PLANTS* head, string classification[])
		{
			bp::type::characteristics::PLANTS* newNode = new bp::type::characteristics::PLANTS;
			newNode->name = name;
			newNode->plant.Phylum = classification[0];
			newNode->plant.Class = classification[1];
			newNode->plant.Order = classification[2];
			newNode->plant.Family = classification[3];
			newNode->plant.Genus = classification[4];
			newNode->plant.Species = classification[5];

			if (head == NULL)
			{
				head = newNode;
				return head;
			}

			bp::type::characteristics::PLANTS* temp = head;
			while (temp)
			{
				if (temp->next == NULL)
				{
					temp->next = newNode;
					break;
				}
				temp = temp->next;
			}
			return head;
		}

		// Function for deleting first node of linked list of type ANIMAL
		bp::type::characteristics::ANIMAL* deleteFirstAnimal(bp::type::characteristics::ANIMAL* head)
		{
			if (head != NULL)
			{
				bp::type::characteristics::ANIMAL* temp = head->next;
				delete head;
				head = temp;
				return head;
			}
		}

		// Function for deleting first node of linked list of type PLANT
		bp::type::characteristics::PLANTS* deleteFirstPlants(bp::type::characteristics::PLANTS* head)
		{
			if (head != NULL)
			{
				bp::type::characteristics::PLANTS* temp = head->next;
				delete head;
				head = temp;
				return head;
			}
		}

		// Function for deleting last node of linked list of type ANIMAL
		bp::type::characteristics::ANIMAL* deleteLastAnimal(bp::type::characteristics::ANIMAL* head)
		{
			if (head->next == NULL)
			{
				return NULL;
			}

			if (head == NULL)
			{
				return head;
			}

			bp::type::characteristics::ANIMAL* temp = head;
			while (temp->next->next != NULL)
			{
				temp = temp->next;
			}
			delete temp->next;
			temp->next = NULL;
			return head;
		}

		// Function for deleting last node of linked list of type PLANT
		bp::type::characteristics::PLANTS* deleteLastPlants(bp::type::characteristics::PLANTS* head)
		{
			if (head->next == NULL)
			{
				return NULL;
			}

			if (head == NULL)
			{
				return head;
			}

			bp::type::characteristics::PLANTS* temp = head;
			while (temp->next->next != NULL)
			{
				temp = temp->next;
			}
			delete temp->next;
			temp->next = NULL;
			return head;
		}

		// Function for converting Information from file to double
		void hightAndWeight(int& indexOfWeight, string line, double* arrWeight, int& indexOfLine)
		{
			arrWeight[indexOfWeight++] = stod(line);
			indexOfLine++;
			if (indexOfWeight == 2)
			{
				indexOfWeight = 0;
			}
		}

		// Function for searching given string in the another string
		bool foundOrNotInString(string mainString, string searchThing)
		{
			return mainString.find(searchThing) != string::npos;
		}

		// Function for searching given double
		bool foundOrNotDouble(double mainNumber, string searchThing)
		{
			try
			{
				throw stod(searchThing);
			}
			catch (double a){
				return mainNumber == a;
			}
			catch (invalid_argument)
			{
				return false;
			}
		}

		// Function for updating information into linked list of type PLANT
		void updatePlant(bp::type::characteristics::PLANTS* head, string newInformation[], int indexOfSearchNode)
		{
			int indexOfCurrentNode = 1;
			bp::type::characteristics::PLANTS* temp = head;
			while (temp)
			{
				if (indexOfCurrentNode == indexOfSearchNode)
				{
					for (size_t i = 0; i < 8; i++)
					{
						if (newInformation[i] != "x")
						{
							switch (i)
							{
							case 0:
								temp->name = newInformation[i];
								break;
							case 1:
								temp->plant.Phylum = newInformation[i];
								break;
							case 2:
								temp->plant.Class = newInformation[i];
								break;
							case 3:
								temp->plant.Order = newInformation[i];
								break;
							case 4:
								temp->plant.Family = newInformation[i];
								break;
							case 5:
								temp->plant.Genus = newInformation[i];
								break;
							case 6:
								temp->plant.Species = newInformation[i];
								break;
							}
						}
					}
				}
				indexOfCurrentNode++;
				temp = temp->next;
			}
		}

		// Function for updating information into linked list of type ANIMAL
		void updateAnimal(bp::type::characteristics::ANIMAL* head, string str[], int indexOfAnimal)
		{
			int currentIndex = 1;
			bp::type::characteristics::ANIMAL* temp = head;
			while (temp)
			{
				if (currentIndex == indexOfAnimal)
				{
					for (size_t i = 0; i < 12; i++)
					{
						if (str[i] != "x")
						{
							switch (i)
							{
							case 0:
								temp->name = str[i];
								break;
							case 1:
								temp->animal.Phylum = str[i];
								break;
							case 2:
								temp->animal.Class = str[i];
								break;
							case 3:
								temp->animal.Order = str[i];
								break;
							case 4:
								temp->animal.Family = str[i];
								break;
							case 5:
								temp->animal.Genus = str[i];
								break;
							case 6:
								temp->animal.Species = str[i];
								break;
							case 7:
								try {
									throw stod(str[i]);
								}
								catch (double a)
								{
									temp->high.averageMaleHigh = a;
								}
								catch (invalid_argument) { temp->high.averageMaleHigh = 0; }

								break;
							case 8:
								try {
									throw stod(str[i]);
								}
								catch (double a)
								{
									temp->high.averageFemaleHigh = a;
								}
								catch (invalid_argument) { temp->high.averageMaleHigh = 0; }
								break;
							case 9:
								try {
									throw stod(str[i]);
								}
								catch (double a)
								{
									temp->weight.averageMaleWieght = a;
								}
								catch (invalid_argument) { temp->high.averageMaleHigh = 0; }
								break;
							case 10:
								try {
									throw stod(str[i]);
								}
								catch (double a)
								{
									temp->weight.averageFemaleWieght = a;
								}
								catch (invalid_argument) {temp->high.averageMaleHigh = 0;}
								break;
							}
						}
					}
				}
				currentIndex++;
				temp = temp->next;
			}
		}

		// Function for generating number which is index and return answer onto that index
		string randomAnswer(string allAnswers[])
		{
			int random = rand() % 6;
			return allAnswers[random];
		}

		// Function for generating other two answers, if they are same generate newand repaet when they are not, and position of true
		void generateAnswer(vector<string>* allAnswer, string trueAnswer, string classification[], bool trueT, vector<char>* trueAnswers)
		{
			int numberOfTrueAnswer = rand() % 3 + 1;
			string firstRandomAnswer = classification[0];
			string secondRandomAnswer = classification[1];
			if (trueT)
			{
				firstRandomAnswer = randomAnswer(classification);
				secondRandomAnswer = randomAnswer(classification);
				while (firstRandomAnswer == secondRandomAnswer || firstRandomAnswer == trueAnswer || secondRandomAnswer == trueAnswer)
				{
					if (firstRandomAnswer == secondRandomAnswer)
					{
						firstRandomAnswer = randomAnswer(classification);
						secondRandomAnswer = randomAnswer(classification);
					}

					if (firstRandomAnswer == trueAnswer)
					{
						firstRandomAnswer = randomAnswer(classification);
					}

					if (secondRandomAnswer == trueAnswer)
					{
						secondRandomAnswer = randomAnswer(classification);
					}
				}
			}
			switch (numberOfTrueAnswer) {
			case 1:
				(*allAnswer).push_back(trueAnswer);
				(*allAnswer).push_back(secondRandomAnswer);
				(*allAnswer).push_back(firstRandomAnswer);
				(*trueAnswers).push_back('A');
				break;
			case 2:
				(*allAnswer).push_back(firstRandomAnswer);
				(*allAnswer).push_back(trueAnswer);
				(*allAnswer).push_back(secondRandomAnswer);
				(*trueAnswers).push_back('B');
				break;
			case 3:
				(*allAnswer).push_back(secondRandomAnswer);
				(*allAnswer).push_back(firstRandomAnswer);
				(*allAnswer).push_back(trueAnswer);
				(*trueAnswers).push_back('C');
				break;
			}
		}

		// Function for generating all possible answers
		void generateAllAnswers(vector<string>* allAnswers, bp::type::characteristics::PLANTS* headP, bp::type::characteristics::ANIMAL* headA, vector<char>* trueAnswers)
		{
			bp::type::characteristics::PLANTS* tempP = headP;
			bp::type::characteristics::ANIMAL* tempA = headA;
			while (tempP)
			{
				string classification[] = { tempP->plant.Phylum,tempP->plant.Class,
								 tempP->plant.Order,tempP->plant.Family,
								 tempP->plant.Genus,tempP->plant.Species };
				for (int i = 0; i < 6; i++)
				{
					generateAnswer(allAnswers, classification[i], classification, 1, trueAnswers);
				}
				tempP = tempP->next;
			}

			while (tempA)
			{
				string classification[] = { tempA->animal.Phylum,tempA->animal.Class,
								 tempA->animal.Order,tempA->animal.Family,
								tempA->animal.Genus,tempA->animal.Species };
				for (int i = 0; i < 6; i++)
				{
					generateAnswer(allAnswers, classification[i], classification, 1, trueAnswers);
				}
				string weightOrHight[2] = { to_string(tempA->high.averageMaleHigh - 6),to_string(tempA->high.averageMaleHigh - 2) };
				generateAnswer(allAnswers, to_string(tempA->high.averageMaleHigh), weightOrHight, 0, trueAnswers);
				weightOrHight[0] = to_string(tempA->high.averageFemaleHigh - 4);
				weightOrHight[1] = to_string(tempA->high.averageFemaleHigh + 1);
				generateAnswer(allAnswers, to_string(tempA->high.averageFemaleHigh), weightOrHight, 0, trueAnswers);
				weightOrHight[0] = to_string(tempA->weight.averageMaleWieght - 10);
				weightOrHight[1] = to_string(tempA->weight.averageMaleWieght - 5);
				generateAnswer(allAnswers, to_string(tempA->weight.averageMaleWieght), weightOrHight, 0, trueAnswers);
				weightOrHight[0] = to_string(tempA->weight.averageFemaleWieght - 5);
				weightOrHight[1] = to_string(tempA->weight.averageFemaleWieght + 10);
				generateAnswer(allAnswers, to_string(tempA->weight.averageFemaleWieght), weightOrHight, 0, trueAnswers);
				tempA = tempA->next;
			}
		}

		// Function for generating all questions
		void generateQuestion2(vector<string>* allQuestions, bp::type::characteristics::PLANTS* headP, bp::type::characteristics::ANIMAL* headA, int* numberOfAllQuestions)
		{
			bp::type::characteristics::PLANTS* tempP = headP;
			bp::type::characteristics::ANIMAL* tempA = headA;

			while (tempP)
			{
				(*allQuestions).push_back("What Phylum is " + tempP->name);
				(*allQuestions).push_back("What Class is " + tempP->name);
				(*allQuestions).push_back("What Order is " + tempP->name);
				(*allQuestions).push_back("What Family is " + tempP->name);
				(*allQuestions).push_back("What Genus is " + tempP->name);
				(*allQuestions).push_back("What Species is " + tempP->name);
				*numberOfAllQuestions += 6;
				tempP = tempP->next;
			}

			while (tempA)
			{
				(*allQuestions).push_back("What Phylum is " + tempA->name);
				(*allQuestions).push_back("What Class is " + tempA->name);
				(*allQuestions).push_back("What Order is " + tempA->name);
				(*allQuestions).push_back("What Family is " + tempA->name);
				(*allQuestions).push_back("What Genus is " + tempA->name);
				(*allQuestions).push_back("What Species is " + tempA->name);
				(*allQuestions).push_back("What is average height of male (cm) " + tempA->name);
				(*allQuestions).push_back("What is average height of female (cm) " + tempA->name);
				(*allQuestions).push_back("What is average weight of male (kg) " + tempA->name);
				(*allQuestions).push_back("What is average weight of male (kg) " + tempA->name);
				*numberOfAllQuestions += 10;
				tempA = tempA->next;
			}
		}

		// Function for deleting specific node of linked list of type ANIMAL
		bp::type::characteristics::ANIMAL* deleteSpecificNodeAnimals(bp::type::characteristics::ANIMAL* head, int n)
		{
			bp::type::characteristics::ANIMAL* temp = head;
			int n1 = 1;
			while (n1 != n - 1)
			{
				n1++;
				temp = temp->next;
			}
			temp->next = temp->next->next;
			return head;
		}

		// Function for deleting specific node of linked list of type PLANTS
		bp::type::characteristics::PLANTS* deleteSpecificNodePlants(bp::type::characteristics::PLANTS* head, int n)
		{
			bp::type::characteristics::PLANTS* temp = head;
			int n1 = 1;
			while (n1 != n - 1)
			{
				n1++;
				temp = temp->next;
			}
			temp->next = temp->next->next;
			return head;
		}

		// Function which return number of all nodes into linked list of type ANIMAL
		int numberOfAnimals(bp::type::characteristics::ANIMAL* head)
		{
			int n = 0;
			bp::type::characteristics::ANIMAL* temp = head;
			while (temp)
			{
				n++;
				temp = temp->next;
			}
			return n;
		}

		// Function for deleting specific node of linked list of type PLANTS
		int numberOfPlants(bp::type::characteristics::PLANTS* head)
		{
			int n = 0;
			bp::type::characteristics::PLANTS* temp = head;
			while (temp)
			{
				n++;
				temp = temp->next;
			}
			return n;
		}
	}

	namespace animalBreeding
	{
		// Function that contains every animal breed
		void animalTypes(int choice, int choiceBreed)
		{

			std::string dogs[3] = { "Labrador", "German Shepherd", "Chihuahua" };
			std::string cats[3] = { "Persian Cat", "Scottish Fold", "European Cat" };
			std::string cows[3] = { "Hereford", "Galbvieh", "Brangus" };
			std::string horses[3] = { "Arabian Horse", "AppaloosaHorse", "Morgan Horse" };
			std::string goats[3] = { "Saanen Goat", "Alpine Goat", "American Lamancha" };


			std::string furType[2] = { "long-haired", "short-haired" };

			std::string furColourLabrador[3] = { "Sandy", "Brown", "Black" };
			std::string furColourGermanShepherd[3] = { "More brown", "More black", "Both colours equally" };
			std::string  furColourChihuahua[3] = { "Black", "White", "Brown" };

			std::string furColourPersianCat[3] = { "Gray", "White", "Reddish" };
			std::string furColourScottishFold[3] = { "Gray", "Gray tiger", "Light brown" };
			std::string furColourEuropeanCat[3] = { "Black", "White", "Reddish" };

			std::string furColourHereford[3] = { "Black", "Black and white", "Brown and white" };
			std::string furColourGelbvieh[3] = { "Light brown", "Dark brown", "Black" };
			std::string furColourBrangus[3] = { "Brown", "Black and white", "Brown and white" };

			std::string furColourArabianHorse[3] = { "Black", "White", "Brown" };
			std::string furColourAppaloosaHorse[3] = { "Black and white", "Brown and white", "Black" };
			std::string furColourMorganHorse[3] = { "Light brown", "Dark brown", "Black" };

			std::string furColourSaanenGoat[3] = { "Light brown", "Dark brown", "White" };
			std::string furColourAlpineGoat[3] = { "Brown", "Black", "Black and white" };
			std::string furColourAmericanLamancha[3] = { "White", "Brown", "Black" };
			switch (choice)
			{
			case 1:
			{
				switch (choiceBreed)
				{
				case 1:
				{
					bp::consoleApp::animalBreeding::breed(furType, furColourLabrador, dogs[0], choice);
				}break;

				case 2:
				{
					bp::consoleApp::animalBreeding::breed(furType, furColourGermanShepherd, dogs[1], choice);
				} break;
				case 3:
				{
					bp::consoleApp::animalBreeding::breed(furType, furColourChihuahua, dogs[2], choice);
				}break;
				}
			}break;
			case 2:
			{
				switch (choiceBreed)
				{
				case 1:
				{
					bp::consoleApp::animalBreeding::breed(furType, furColourPersianCat, cats[0], choice);
				}break;

				case 2:
				{
					bp::consoleApp::animalBreeding::breed(furType, furColourScottishFold, cats[1], choice);
				} break;
				case 3:
				{
					bp::consoleApp::animalBreeding::breed(furType, furColourEuropeanCat, cats[2], choice);
				}break;
				}
			}break;
			case 3:
			{
				switch (choiceBreed)
				{
				case 1:
				{
					bp::consoleApp::animalBreeding::breed(furType, furColourHereford, cows[0], choice);
				}break;

				case 2:
				{
					bp::consoleApp::animalBreeding::breed(furType, furColourGelbvieh, cows[1], choice);
				} break;
				case 3:
				{
					bp::consoleApp::animalBreeding::breed(furType, furColourBrangus, cows[2], choice);
				}break;
				}
			}break;
			case 4:
			{
				switch (choiceBreed)
				{
				case 1:
				{
					bp::consoleApp::animalBreeding::breed(furType, furColourArabianHorse, horses[0], choice);
				}break;

				case 2:
				{
					bp::consoleApp::animalBreeding::breed(furType, furColourAppaloosaHorse, horses[1], choice);
				} break;
				case 3:
				{
					bp::consoleApp::animalBreeding::breed(furType, furColourMorganHorse, horses[2], choice);
				}break;
				}
			}break;
			case 5:
			{
				switch (choiceBreed)
				{
				case 1:
				{
					bp::consoleApp::animalBreeding::breed(furType, furColourSaanenGoat, goats[0], choice);
				}break;

				case 2:
				{
					bp::consoleApp::animalBreeding::breed(furType, furColourAlpineGoat, goats[1], choice);
				} break;
				case 3:
				{
					bp::consoleApp::animalBreeding::breed(furType, furColourAmericanLamancha, goats[2], choice);
				}break;
				}
			}break;
			}
		}

		// Function that shows what newborns have been born
		void resultBreeding(int choice, int choice2, int choice3, int choice4, int animals, std::string typeOfAnimal, std::string furType[], std::string furColour[], int breed)
		{
			std::string breedFurType[20];
			std::string breedFurColour[20];
			switch (choice)
			{
			case 1:
			{
				breedFurType[0] = furType[0];
			} break;

			case 2:
			{
				breedFurType[0] = furType[1];
			}break;
			}

			switch (choice2)
			{
			case 1:
			{
				breedFurColour[0] = furColour[0];
			} break;

			case 2:
			{
				breedFurColour[0] += furColour[1];
			}break;
			case 3:
			{
				breedFurColour[0] += furColour[2];
			}break;
			}

			switch (choice3)
			{
			case 1:
			{
				breedFurType[1] = furType[0];
			} break;

			case 2:
			{
				breedFurType[1] = furType[1];
			}break;
			}

			switch (choice4)
			{
			case 1:
			{
				breedFurColour[1] = furColour[0];
			} break;

			case 2:
			{
				breedFurColour[1] += furColour[1];
			}break;
			case 3:
			{
				breedFurColour[1] += furColour[2];
			}break;
			}
			bp::dal::population::editPopulationAnimal(animals);
			bp::consoleApp::animalBreeding::resultBreedingLabel(animals, typeOfAnimal, breedFurColour, breedFurType, breed);
		}
	}

	namespace plantsSeeding
	{
		// Function that contains every plant sort
		void sortTypes(int choice, int choiceSort)
		{

			std::string tomatoes[2] = { "Roma Tomatoes", "Cherry Tomatoes" };
			std::string cucumbers[2] = { "Gherkins", "Slicing Cucumber" };
			std::string coconuts[2] = { "Fiji Dwarf", "Golden Malay" };
			std::string pears[2] = { "Asian pear", "Bartlett pear" };
			std::string apples[2] = { "Fuji", "Granny Smith" };

			switch (choice)
			{
			case 1:
			{
				switch (choiceSort)
				{
				case 1:
				{
					bp::consoleApp::plantsSeeding::howManyGrains(tomatoes[0]);
				}break;

				case 2:
				{
					bp::consoleApp::plantsSeeding::howManyGrains(tomatoes[1]);
				} break;

				}
			}break;
			case 2:
			{
				switch (choiceSort)
				{
				case 1:
				{
					bp::consoleApp::plantsSeeding::howManyGrains(cucumbers[0]);
				}break;

				case 2:
				{
					bp::consoleApp::plantsSeeding::howManyGrains(cucumbers[1]);
				} break;
				}
			}break;
			case 3:
			{
				switch (choiceSort)
				{
				case 1:
				{
					bp::consoleApp::plantsSeeding::howManyGrains(coconuts[0]);
				}break;

				case 2:
				{
					bp::consoleApp::plantsSeeding::howManyGrains(coconuts[1]);
				} break;
				}
			}break;
			case 4:
			{
				switch (choiceSort)
				{
				case 1:
				{
					bp::consoleApp::plantsSeeding::howManyGrains(pears[0]);
				}break;

				case 2:
				{
					bp::consoleApp::plantsSeeding::howManyGrains(pears[1]);
				} break;
				}
			}break;
			case 5:
			{
				switch (choiceSort)
				{
				case 1:
				{
					bp::consoleApp::plantsSeeding::howManyGrains(apples[0]);
				}break;

				case 2:
				{
					bp::consoleApp::plantsSeeding::howManyGrains(apples[1]);
				} break;
				}
			}break;
		}
		}
	}
}


