#pragma once
#include "pch.h"
#include "..\bp.types\types.h"

namespace bp::consoleApp
{
    namespace menuInputs
    {
        // Menu input for main menu
        bool menu();

        // Menu input for admin panel
        bool adminPanel();

        // Menu input for play menu (second menu)
        bool playMenu(string username);

        // Menu input for animal breeding
        bool breedingMenuInput();

        //Output menu with plants, animals and quiz options
        bool plantsAnimalsAndQuizMenu();

        // Menu input for choosing plants or animals information
        bool plantsAndAnimalsMenu();

        // Menu input for choosing plants or animals information with exit option
        bool viewInformation();

        //Inputs plants information with skip options
        void inputPlantsData(bp::type::characteristics::PLANTS* headPlants, int index);

        //Inputs animals information with skip options
        void inputAnimalsData(bp::type::characteristics::ANIMAL* headAnimals, int index);

        //Inputs plants information withouth skip options
        void inputNewPlantsData(bp::type::characteristics::PLANTS* headPlants);

        //Inputs animals information withouth skip options
        void inputNewAnimalsData(bp::type::characteristics::ANIMAL* headAnimals);

        //Function for editing plants and animals information
        bool editInformation(bp::type::characteristics::PLANTS* headPlants, bp::type::characteristics::ANIMAL* headAnimals);

        //Function for adding new informations
        bool addNewInformation(bp::type::characteristics::PLANTS* headPlants, bp::type::characteristics::ANIMAL* headAnimals);

        //Function for removing plants and animals informations
        bool removeInformation(bp::type::characteristics::PLANTS* headPlants, bp::type::characteristics::ANIMAL* headAnimals);

        // Menu input for animals information menu
        bool movementInAnimalsMenu(bp::type::characteristics::ANIMAL* headAnimals);

        // Menu input for plants information menu
        bool movementInPlantsMenu(bp::type::characteristics::PLANTS* headPlants);

        // Menu input for animals 
        bool animalsMenu();

        // Menu input for plants
        bool plantsMenu();

        // Menu input for choosing animal breed
        bool breedInput(int choice);

        // Menu input for choosing plant sort
        bool sortInput(int choice);

        // Menu input for choosing plant
        bool seedingMenuInput();
    }
}