#pragma once
#include"..\bp.types\types.h"
#include<vector>

namespace bp::bll
{
	namespace  biologyContent
	{

		// Check if the given string can convert to double
		double checkForDouble(string str);

		// Function for adding new node in the end of linked list of type ANIMAL
		bp::type::characteristics::ANIMAL* prependNodeAnimal(string name2, bp::type::characteristics::ANIMAL* head, string str[], double highArray[], double weightArray[]);

		// Function for adding new node in the end of linked list of type PLANT
		bp::type::characteristics::PLANTS* prependNodePlants(string name2, bp::type::characteristics::PLANTS* head, string str[]);

		// Function for deleting first node of linked list of type ANIMAL
		bp::type::characteristics::ANIMAL* deleteFirstAnimal(bp::type::characteristics::ANIMAL* head);

		// Function for deleting first node of linked list of type PLANT
		bp::type::characteristics::PLANTS* deleteFirstPlants(bp::type::characteristics::PLANTS* head);

		// Function for deleting last node of linked list of type ANIMAL
		bp::type::characteristics::ANIMAL* deleteLastAnimal(bp::type::characteristics::ANIMAL* head);

		// Function for deleting last node of linked list of type PLANT
		bp::type::characteristics::PLANTS* deleteLastPlants(bp::type::characteristics::PLANTS* head);

		// Function for converting Information from file to double
		void hightAndWeight(int& indexOfWeight, string line, double* arrWeight, int& indexOfLine);

		// Function for searching given string in the another string
		bool foundOrNotInString(string str, string str1);

		// Function for searching given double
		bool foundOrNotDouble(double num1, string num2);

		// Function for updating information into linked list of type PLANT
		void updatePlant(bp::type::characteristics::PLANTS* head, string str[], int n1);

		// Function for updating information into linked list of type ANIMAL
		void updateAnimal(bp::type::characteristics::ANIMAL* head, string str[], int n1);

		// Function for generating number which is index and return answer onto that index
		string randomAnswer(string allAnswer[]);

		// Function for generating other two answers, if they are same generate newand repaet when they are not, and position of true
		void generateAnswer(vector<string>* str, string str1, string str2[], bool trueT, vector<char>* trueAnswer);

		// Function for generating all possible answers
		void generateAllAnswers(vector<string>* str, bp::type::characteristics::PLANTS* headP, bp::type::characteristics::ANIMAL* headA, vector<char>* trueAnswer);

		// Function for generating all questions
		void generateQuestion2(vector<string>* str1, bp::type::characteristics::PLANTS* headP, bp::type::characteristics::ANIMAL* headA, int* ptr);

		// Function for deleting specific node of linked list of type ANIMAL
		bp::type::characteristics::ANIMAL* deleteSpecificNodeAnimals(bp::type::characteristics::ANIMAL* head, int n);

		// Function for deleting specific node of linked list of type PLANTS
		bp::type::characteristics::PLANTS* deleteSpecificNodePlants(bp::type::characteristics::PLANTS* head, int n);

		// Function which return number of all nodes into linked list of type ANIMAL
		int numberOfAnimals(bp::type::characteristics::ANIMAL* head);

		// Function which return number of all nodes into linked list of type PLANTS
		int numberOfPlants(bp::type::characteristics::PLANTS* head);
	}
}