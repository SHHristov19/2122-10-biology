#include "pch.h"
#include "registrationForm.h"
#include "frames.h"
#include "..\bp.consoleApp\registrationForm.h"
#include "..\bp.tools\extraFunctions.h"
#include "..\bp.types\types.h"
#include"..\bp.bll\biologyContent.h"

namespace bp::dal
{
	namespace registrationForm
    {
        // Function for login as player
        void loginAsPlayer(string* username)
        {
            string checkUsername, password, checkPassword, line;
            int counter = 0;
            bp::consoleApp::registrationForm::outputEntryWindows::loginAsPlayer();
            bp::tools::consoleCoordinates(72, 29);
            getline(cin, *username);
            bp::tools::consoleCoordinates(72, 32);
            getline(cin, password);
            ifstream input("records.txt");
            while (getline(input, line))
            {
                counter = 0;
                checkUsername = checkPassword = "";
                for (size_t i = 0; i < line.size(); i++)
                {
                    if (line[i] == ' ')
                    {
                        counter++;
                        line.erase(i, 0);
                    }
                    else if (counter == 0)
                    {
                        checkUsername += line[i];
                    }
                    else if (counter == 1)
                    {
                        checkPassword += line[i];
                    }
                }
                if (*username == checkUsername && password == checkPassword)
                {
                    system("ClS");
                    bp::consoleApp::registrationForm::outputEntryWindows::successfullyLogin();
                    Sleep(900);
                    bp::consoleApp::menuInputs::playMenu(*username);
                    break;
                }
                else
                {
                    system("ClS");
                    bp::consoleApp::registrationForm::outputEntryWindows::tryAgain();
                }
            }
            input.close();
        }

        // Function for registration as player
        void registrationPlayer()
        {
            string username, password;
            bp::consoleApp::registrationForm::outputEntryWindows::registration();
            bp::tools::consoleCoordinates(72, 28);
            getline(cin, username);
            bp::tools::consoleCoordinates(72, 31);
            getline(cin, password);
            ofstream file("records.txt", ios::app);
            file << username << ' ' << password << endl;
            file.close();
            system("CLS");
            bp::consoleApp::registrationForm::outputEntryWindows::succcessfullyRegister();
        }

        // Function for changing password
        bool changePasswordPlayer()
        {
            string username, checkUsername, password, checkLine, newPassword, line;
            int counter = 0;
            int passwordLength = 0;
            int passwordLinePosition;
            bp::consoleApp::registrationForm::outputEntryWindows::checkPassword();
            bp::tools::consoleCoordinates(74, 27);
            getline(cin, username);
            ifstream input("records.txt", ios_base::app);
            for (int i = 1; getline(input, line); i++)
            {
                checkLine += line;
            }
            if(checkLine.find(username) != string::npos)
            {
                bp::tools::consoleCoordinates(71, 30);
                getline(cin, password);
                if (checkLine.find(password) != string::npos)
                {
                    bp::tools::consoleCoordinates(77, 33);
                    getline(cin, newPassword);
                }
                else
                {
                    input.close();
                    system("ClS");
                    bp::consoleApp::registrationForm::outputEntryWindows::tryAgain();
                    return 0;
                }
            }
            else 
            {
                input.close();
                system("ClS");
                bp::consoleApp::registrationForm::outputEntryWindows::tryAgain();
                return 0;
            }
            input.close();
            input.close();
            vector<string> loginData;
            ifstream file("records.txt");
            for (int i = 1; getline(file, line); i++)
            {
                if (line.find(username + " " + password) != string::npos)
                {
                    line = username + " " + newPassword;
             
                }
                loginData.push_back(line);
            }
            file.close();
            ofstream output("records.txt");
            for (int i = 0; i < loginData.size(); i++)
            {
                output << loginData[i] << '\n';
            }
            output.close();
        }
	}

    namespace population
    {
        // Function for getting animal population from file
        int populationAnimal()
        {
            int population = 0;
            ifstream file("animalsAndPlantsPopulation.txt");
            int line;
            int counter = 1;
            if (file.is_open())
            {
                while (file >> line)
                {
                    if (counter == 1)
                    {
                        population += line;
                    }
                    counter++;
                }
                file.close();
            }
            return population;
        }

        // Function for getting plant population from file
        int populationPlant()
        {
            int population = 0;
            ifstream file("animalsAndPlantsPopulation.txt");
            int line;
            int counter = 1;
            if (file.is_open())
            {
                while (file >> line)
                {
                    if (counter == 2)
                    {
                        population += line;
                    }
                    counter++;
                }
                file.close();
            }
            return population;
        }

        // Function for editing animals population
        void editPopulationAnimal(int animals)
        {
            fstream file("animalsAndPlantsPopulation.txt", ios::in | ios::out);
            string line;
            int populationPlant = bp::dal::population::populationPlant();
            int populationA = populationAnimal();
            populationA += animals;
            file << populationA << "\n" << populationPlant;
            file.close();
        }

        // Function for editing plants population
        void editPopulationPlants(int plants)
        {
            fstream file("animalsAndPlantsPopulation.txt", ios::in | ios::out);
            string line;
            int populationA = populationAnimal();
            int populationPlant = bp::dal::population::populationPlant();
            populationPlant += plants;
            file << populationA << "\n" << populationPlant;
            file.close();
        }
    }

    namespace frames
    {
        //Function for reading data from file
        void readFrameFromFile(bp::type::frames::FRAME* frame)
        {
            ifstream file("animationFrames.txt");
            string line;
            int count = 1;
            if (file.is_open())
            {
                while (getline(file, line))
                {
                    if (line.find("||||") != string::npos)
                    {
                        line.erase(0, 4);
                        count++;
                    }
                    if (count == 1)
                    {
                        (*frame).one += line + '\n';
                    }
                    else if (count == 2)
                    {
                        (*frame).two += line + '\n';
                    }
                    else if (count == 3)
                    {
                        (*frame).three += line + '\n';
                    }
                    else if (count == 4)
                    {
                        (*frame).four += line + '\n';
                    }
                    else if (count == 5)
                    {
                        (*frame).five += line + '\n';
                    }
                    else if (count == 6)
                    {
                        (*frame).quizFrame += line + '\n';
                    }
                    else if (count == 7)
                    {
                        (*frame).eight += line + '\n';
                    }
                    else if (count == 8)
                    {
                        (*frame).nine += line + '\n';
                    }
                }
                file.close();
            }
        }
    }

    namespace workWithFiles
    {
        // Function for adding information from file to linked list of type PLANT
        bp::type::characteristics::PLANTS* fromFileToPlantsList(bp::type::characteristics::PLANTS* head)
        {
            string line, name, classification[6];
            int indexOfLine = 0, indexOfWeight = 0;
            ifstream file;
            file.open("../main/PlantsInfo.txt");
            if (file.is_open())
            {
                while (getline(file, line))
                {
                    switch (indexOfLine)
                    {
                    case 0:
                        name = line;
                        indexOfLine++;
                        break;
                    case 1:
                    case 2:
                    case 3:
                    case 4:
                    case 5:
                    case 6:
                        classification[indexOfLine - 1] = line;
                        indexOfLine++;
                        break;
                    default:
                        bp::bll::biologyContent::prependNodePlants(name, head, classification);
                        name = line;
                        indexOfLine = 1;
                        break;
                    }
                }
            }
            file.close();

            return head;
        }

        // Function for adding information from file to linked list of type ANIMAL
        bp::type::characteristics::ANIMAL* fromFileToAnimalsList(bp::type::characteristics::ANIMAL* head)
        {
            string line, name, classification[6];
            double highArray[2], weightArray[2];
            int n = 0, n1 = 0;
            ifstream file;
            file.open("../main/AnimalInfo.txt");
            if (file.is_open())
            {
                while (getline(file, line))
                {
                    switch (n)
                    {
                    case 0:
                        name = line;
                        n++;
                        break;
                    case 1:
                    case 2:
                    case 3:
                    case 4:
                    case 5:
                    case 6:
                        classification[n - 1] = line;
                        n++;
                        break;
                    case 7:
                    case 8:
                        bp::bll::biologyContent::hightAndWeight(n1, line, highArray, n);
                        break;
                    case 9:
                    case 10:
                        bp::bll::biologyContent::hightAndWeight(n1, line, weightArray, n);
                        break;
                    default:
                        bp::bll::biologyContent::prependNodeAnimal(name, head, classification, highArray, weightArray);
                        name = line;
                        n = 1;
                        break;
                    }
                }
            }
            file.close();

            return head;
        }

        // Function for adding all information from linked list of type ANIMAL to file
        void fromAnimalsListToFile(bp::type::characteristics::ANIMAL* head)
        {
            bp::type::characteristics::ANIMAL* temp = head;
            ofstream file("../main/AnimalInfo.txt", ios::ate);
            if (file.is_open())
            {
                while (temp)
                {
                    file << temp->name << endl;
                    file << temp->animal.Phylum << endl;
                    file << temp->animal.Class << endl;
                    file << temp->animal.Order << endl;
                    file << temp->animal.Family << endl;
                    file << temp->animal.Genus << endl;
                    file << temp->animal.Species << endl;
                    file << temp->high.averageMaleHigh << endl;
                    file << temp->high.averageFemaleHigh << endl;
                    file << temp->weight.averageMaleWieght << endl;
                    file << temp->weight.averageFemaleWieght << endl;
                    temp = temp->next;
                }
            }
            file << "end"<<endl;
            file.close();
        }

        // Function for adding add all information from linked list of type PLANT to file
        void fromPlantsListToFile(bp::type::characteristics::PLANTS* head)
        {
            bp::type::characteristics::PLANTS* temp = head;
            ofstream file("../main/PlantsInfo.txt", ios::ate);
            if (file.is_open())
            {
                while (temp)
                {
                    file << temp->name << endl;
                    file << temp->plant.Phylum << endl;
                    file << temp->plant.Class << endl;
                    file << temp->plant.Order << endl;
                    file << temp->plant.Family << endl;
                    file << temp->plant.Genus << endl;
                    file << temp->plant.Species << endl;
                    temp = temp->next;
                }
            }
            file << "end" << endl;
            file.close();
        }
    }
}

