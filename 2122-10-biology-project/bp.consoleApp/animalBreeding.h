#pragma once
namespace bp::consoleApp
{
    namespace animalBreeding
    {
        // Function that displays animal breeding menu
        void menuBreeding();

        // Function that displays animals
        void animalOption(int x, int y);

        // Function that displays animal breeds
        void breedOption(int choice);

        // Function that gives user a choice for fur type and fur colour of the animal
        void breed(std::string furType[], std::string furColour[], std::string typeOfAnimal, int breed);

        // Function that shows result newborns
        void resultBreedingLabel(int animals, string typeOfAnimal, string breedFurColour[], string breedFurType[], int breed);

        namespace animalFigures
        {  
            // Function that displays dog figure
            void dog(int x, int y);

            // Function that displays cow figure
            void cow(int x, int y);

            // Function that displays horse figure
            void horse(int x, int y);

            // Function that displays cat figure
            void cat(int x, int y);

            // Function that displays dog figure for result breeding
            void resultDog(int x, int y);

            // Function that displays cat figure for result breeding
            void resultCat(int x, int y);

            // Function that displays cow figure for result breeding
            void resultCow(int x, int y);

            // Function that displays horse figure for result breeding
            void resultHorse(int x, int y);

            // Function that displays goat figure for result breeding
            void resultGoat(int x, int y);
        }

        namespace menuParts
        {
            // Function that displays label for animal breeding menu
            void label(int x, int y);

            // Function that displays border for animal breeding menu
            void border(int x, int y);
        }
    }
}