#include "pch.h"

#include "registrationForm.h"
#include "menus.h"
#include "menuInputs.h"
#include "frames.h"
#include "animalBreeding.h"
#include "plantsSeeding.h"
#include "biologyContent.h"
#include "quiz.h"
#include "planetPopulation.h"

#include "..\bp.dal\registrationForm.h"
#include "..\bp.tools\extraFunctions.h"
#include "..\bp.dal\frames.h"
#include "..\bp.types\types.h"
#include "..\bp.bll\biologyContent.h"
#include "..\bp.bll\animalBreeding.h"
#include "..\bp.bll\plantsSeeding.h"
#include"..\bp.dal\workWithFiles.h"
#include "..\bp.dal\population.h"


namespace bp::consoleApp
{
	namespace quiz
	{
		namespace lives
		{
			//Output four heart current position
			void outputFourHearth()
			{
				bp::tools::consoleCoordinates(130, 1);
				cout << "\x1b[1;31m" << ".-.-. .-.-. .-.-. .-.-. " << endl;
				bp::tools::consoleCoordinates(130, 2);
				cout << "\x1b[1;31m" << "'. .' '. .' '. .' '. .' " << endl;
				bp::tools::consoleCoordinates(130, 3);
				cout << "\x1b[1;31m" << "  `     `     `     `   " << "\x1b[1;37m" << endl;
			}

			//Output three heart current position
			void outputThreeHearth()
			{
				bp::tools::consoleCoordinates(130, 1);
				cout << "\x1b[1;31m" << ".-.-. .-.-. .-.-." << endl;
				bp::tools::consoleCoordinates(130, 2);
				cout << "\x1b[1;31m" << "'. .' '. .' '. .'" << endl;
				bp::tools::consoleCoordinates(130, 3);
				cout << "\x1b[1;31m" << "  `     `     `  " << "\x1b[1;37m" << endl;
			}

			//Output two heart current position
			void outputTwoHearth()
			{
				bp::tools::consoleCoordinates(130, 1);
				cout << "\x1b[1;31m" << ".-.-. .-.-." << endl;
				bp::tools::consoleCoordinates(130, 2);
				cout << "\x1b[1;31m" << "'. .' '. .'" << endl;
				bp::tools::consoleCoordinates(130, 3);
				cout << "\x1b[1;31m" << "  `     `  " << "\x1b[1;37m" << endl;
			}

			//Output one heart in current position
			void outputOneHearth()
			{
				bp::tools::consoleCoordinates(130, 1);
				cout << "\x1b[1;31m" << ".-.-." << endl;
				bp::tools::consoleCoordinates(130, 2);
				cout << "\x1b[1;31m" << "'. .'" << endl;
				bp::tools::consoleCoordinates(130, 3);
				cout << "\x1b[1;31m" << "  `  " << "\x1b[1;37m" << endl;
			}
		}

		//Output string in current position
		void outputQuiz(int x, int y, string str)
		{
			bp::tools::consoleCoordinates(x, y);
			cout << str;
		}

		//Output text 'correct' in current position
		void outputCorrect(int x, int y)
		{
			bp::tools::consoleCoordinates(x, y);
			cout << "                                          _    " << endl;
			bp::tools::consoleCoordinates(x, y + 1);
			cout << "                    __ ___ _ _ _ _ ___ __| |_  " << endl;
			bp::tools::consoleCoordinates(x, y + 2);
			cout << "                   / _/ _ \\ '_| '_/ -_) _|  _| " << endl;
			bp::tools::consoleCoordinates(x, y + 3);
			cout << "                   \\__\\___/_| |_| \\___\\__|\\__| " << endl;
		}

		//Output text 'wrong' in current position
		void outputWrong(int x, int y)
		{
			bp::tools::consoleCoordinates(x, y);
			cout << "                    __ __ ___ _ ___ _ _  __ _  " << endl;
			bp::tools::consoleCoordinates(x, y + 1);
			cout << "                    \\ V  V / '_/ _ \\ ' \\/ _` | " << endl;
			bp::tools::consoleCoordinates(x, y + 2);
			cout << "                     \\_/\\_/|_| \\___/_||_\\__, | " << endl;
			bp::tools::consoleCoordinates(x, y + 3);
			cout << "                                        |___/  " << endl;
		}

		//Output 'Game over' window in color
		void outputGameOver()
		{
			cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
			cout << "                           __________________________________________________________________________________________________________" << endl;
			cout << "                           |                                                                                                        |" << endl;
			cout << "                           |                                                                                                        |" << endl;
			cout << "                           |                                                                                                        |" << endl;
			cout << "                           |                                                                                                        |" << endl;
			cout << "                           |                                                                                                        |" << endl;
			cout << "                           |                                                                                                        |" << endl;
			cout << "                           |                                                                                                        |" << endl;
			cout << "                           |                                                                                                        |" << endl;
			cout << "                           |                     " << "\x1b[1;31m" << "    ____    _    __  __ _____    _____     _______ ____            " << "\x1b[1;37m" << "                |" << endl;
			cout << "                           |                     " << "\x1b[1;31m" << "   / ___|  / \\  |  \\/  | ____|  / _ \\ \\   / / ____|  _ \\      " << "\x1b[1;37m" << "                     |" << endl;
			cout << "                           |                     " << "\x1b[1;31m" << "  | |  _  / _ \\ | |\\/| |  _|   | | | \\ \\ / /|  _| | |_) |      " << "\x1b[1;37m" << "                    |" << endl;
			cout << "                           |                     " << "\x1b[1;31m" << "  | |_| |/ ___ \\| |  | | |___  | |_| |\\ V / | |___|  _ <         " << "\x1b[1;37m" << "                  |" << endl;
			cout << "                           |                     " << "\x1b[1;31m" << "   \\____/_/   \\_\\_|  |_|_____|  \\___/  \\_/  |_____|_| \\_\\   " << "\x1b[1;37m" << "                       |" << endl;
			cout << "                           |                                                                                                        |" << endl;
			cout << "                           |                                                                                                        |" << endl;
			cout << "                           |                                                                                                        |" << endl;
			cout << "                           |                                                                                                        |" << endl;
			cout << "                           |                                                                                                        |" << endl;
			cout << "                           |                                                                                                        |" << endl;
			cout << "                           |                                                                                                        |" << endl;
			cout << "                           |                                                                                                        |" << endl;
			cout << "                           |________________________________________________________________________________________________________|" << endl;
		}

		//Output border for the  window in current position
		void outputBorder(int n)
		{
			cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
			cout << "                                          ____________________________________________________________________________" << endl;

			for (int i = 0; i < 31 + 4 * n; i++)
			{
				cout << "                                          |                                                                          |" << endl;
			}

			cout << "                                          |__________________________________________________________________________|" << endl;
		}


		bool bp::consoleApp::menuInputs::plantsAndAnimalsMenu();

		// Menu input for quiz
		void quiz()
		{

			bp::type::characteristics::ANIMAL* headAnimals = new  bp::type::characteristics::ANIMAL;
			bp::type::characteristics::PLANTS* headPlants = new  bp::type::characteristics::PLANTS;

			headAnimals = bp::dal::workWithFiles::fromFileToAnimalsList(headAnimals);
			headPlants = bp::dal::workWithFiles::fromFileToPlantsList(headPlants);

			if (headAnimals != NULL)
			{
				headPlants = bp::bll::biologyContent::deleteFirstPlants(headPlants);
				headAnimals = bp::bll::biologyContent::deleteFirstAnimal(headAnimals);
			}

			system("CLS");
			int numberOfAskedQuestions = 0;
			int indexOfQuestion;
			char answer;
			int numberOfQuestions = 0;
			bp::type::frames::FRAME asteroid;
			bp::dal::frames::readFrameFromFile(&asteroid);
			vector<string> questions;
			bp::bll::biologyContent::generateQuestion2(&questions, headPlants, headAnimals, &numberOfQuestions);
			vector<string> answers;
			vector<char> trueAnswers;
			bp::bll::biologyContent::generateAllAnswers(&answers, headPlants, headAnimals, &trueAnswers);
			int lives = 4;
			while (numberOfAskedQuestions != 4)
			{
				indexOfQuestion = rand() % numberOfQuestions;
				string answersForQuestion[3] = { answers[3 * indexOfQuestion] ,
												answers[3 * indexOfQuestion + 1],
												answers[3 * indexOfQuestion + 2] };

				frames::output::quizFrame(asteroid);
				if (lives == 4)
				{
					quiz::lives::outputFourHearth();
				}
				else if (lives == 3)
				{
					quiz::lives::outputThreeHearth();
				}
				else if (lives == 2)
				{
					quiz::lives::outputTwoHearth();
				}
				else if (lives == 1)
				{
					quiz::lives::outputOneHearth();
				}

				quiz::outputQuiz(59, 18, questions[indexOfQuestion]);
				quiz::outputQuiz(68, 22, answersForQuestion[0]);
				quiz::outputQuiz(68, 25, answersForQuestion[1]);
				quiz::outputQuiz(68, 28, answersForQuestion[2]);

				bp::tools::consoleCoordinates(64, 22);
				cout << "--> ";
				int choice = 1;
				bool truth = true;
				while (truth) {
					switch (_getch())
					{
					case KEY_UP:
						switch (choice)
						{
						case 1:
						{
							bp::tools::consoleCoordinates(64, 22);
							cout << "    ";
							bp::tools::consoleCoordinates(64, 28);
							cout << "--> ";
							choice = 3;
							break;
						}
						case 2:
						{
							bp::tools::consoleCoordinates(64, 25);
							cout << "    ";
							bp::tools::consoleCoordinates(64, 22);
							cout << "--> ";
							choice = 1;
							break;
						}
						case 3:
						{
							bp::tools::consoleCoordinates(64, 28);
							cout << "    ";
							bp::tools::consoleCoordinates(64, 25);
							cout << "--> ";
							choice = 2;
							break;
						}
						}
						break;
					case KEY_DOWN:
						switch (choice)
						{
						case 1:
						{
							bp::tools::consoleCoordinates(64, 22);
							cout << "    ";
							bp::tools::consoleCoordinates(64, 25);
							cout << "--> ";
							choice = 2;
							break;
						}
						case 2:
						{
							bp::tools::consoleCoordinates(64, 25);
							cout << "    ";
							bp::tools::consoleCoordinates(64, 28);
							cout << "--> ";
							choice = 3;
							break;
						}
						case 3:
						{
							bp::tools::consoleCoordinates(64, 28);
							cout << "    ";
							bp::tools::consoleCoordinates(64, 22);
							cout << "--> ";
							choice = 1;
							break;
						}
						}
						break;
					case KEY_ENTER:
						switch (choice)
						{
						case 1:
						{
							system("CLS");
							answer = 'A';
							break;
						}
						case 2:
						{
							system("CLS");
							answer = 'B';
							break;
						}
						case 3:
						{
							system("CLS");
							answer = 'C';
							break;
						}
						}
						if (answer == trueAnswers[indexOfQuestion])
						{
							frames::output::quizFrame(asteroid);
							quiz::outputCorrect(48, 21);
							truth = false;
							Sleep(1000);
						}
						else
						{
							frames::output::quizFrame(asteroid);
							quiz::outputWrong(48, 22);
							truth = false;
							Sleep(1000);
							lives--;
						}
						break;
					default:
						break;
					}
				}
				system("CLS");
				if (lives == 0)
				{
					quiz::outputGameOver();
					break;
				}
				numberOfAskedQuestions++;
				if (numberOfAskedQuestions == 4 && lives > 0)
				{
					frames::output::seventhFrame();
					bp::type::frames::FRAME animationFrame;
					bp::dal::frames::readFrameFromFile(&animationFrame);
					frames::output::eightFrame(animationFrame);
					frames::output::ninthFrame(animationFrame);
					bp::consoleApp::menuInputs::plantsAndAnimalsMenu();
				}

			}

		}
	}

	namespace frames
	{
		//Output guide function
		void outputGuide()
		{
			bp::tools::consoleCoordinates(0, 40);
			cout << endl;
			cout << "         .                   .                .                      .                            .                           .                  .   " << endl;
			cout << "    .           .    .   .      .        .       .     .      .          .      .            .           .     .         .         .         .          .  " << endl;
			cout << "        .    .     .        .    .  .      .    . .      .   .     .   .   .      .     .   .      .   .    .     .    .   .            .     .     .      " << endl;
			cout << "    .      .   . " << "\x1b[1;32m" << "O" << "\x1b[1;37m" << "   .   . . ." << "\x1b[1;32m" << "O" << "\x1b[1;37m" << ".    . .  . . .  . . .  . .   .  . .  . .   . . .  . .   . . . . .   .   .    .  .  ..   . .   . .    .     .     .   .  .  " << endl;
			cout << "         .   .    " << "\x1b[1;32m" << "\\" << "\x1b[1;37m" << "    . .   " << "\x1b[1;32m" << "/" << "\x1b[1;37m" << ".  . . . . . .  . .   . .  .  . . .  . . . .   . .  .  . . .  . . .   . .  . . . .  . .   ..   .   . .   . .  .    .    .   . " << endl;
			cout << "   .   .  .   .  . " << "\x1b[1;32m" << "\\" << "\x1b[1;37m" << "    .   " << "\x1b[1;32m" << "/" << "\x1b[1;37m" << "  . . .                                                                                                       .  .  . .  .    " << endl;
			cout << "         .  . . .   " << "\x1b[1;32m" << ":-'\"\"'-:" << "\x1b[1;37m" << "   .   .                                                                                                      .  .   .  .  .    . " << endl;
			cout << "  .   .    .    " << "\x1b[1;32m" << " .-'  ____  `-. " << "\x1b[1;37m" << "  . .                                                                                                       . .   .     .   " << endl;
			cout << "       .  .   . " << "\x1b[1;32m" << "( {  (_()_)  } )" << "\x1b[1;37m" << " . ..  . .  . . .  . . .  . .   ..   . . .  . .   . .  .  . . .  . . . .   . .  .  .   .  .  .  .  .   .  .   .  .   .  .  " << endl;
			cout << "      .     .   " << "\x1b[1;32m" << " `-.   ^^   .-' " << "\x1b[1;37m" << ".  . .   . . .  . .   . .  .  . . .  . . . .   . .  .  . . .  . . .   . .  .  .  . .  . .   .  .  .  . .   .    .        . " << endl;
			cout << "   .      .     . ." << "\x1b[1;32m" << " `._==_.'" << "\x1b[1;37m" << " ... .  .   . . .  . .   . .  .  . . .  . . . .   . .  .  . . .  . . .   . .  . . . .  . .   .  . .   .   . .  .   .   .  .    " << endl;
			cout << "      .      .   . " << "\x1b[1;32m" << "  __)(__" << "\x1b[1;37m" << " .      .    . .      .   .     .       .      .     .   .      .   .    .     .    .   . .      .   . .      .   .     .   .   " << endl;
		}

		namespace output
		{
			//Output zero frame
			void zeroFrame(string username)
			{
				outputGuide();
				bp::tools::consoleCoordinates(44, 47);
				bp::tools::slowmotionOfScreenplayWithUsername("Hi &, I am your guide and I will advance you in this amazing adventure.", username);
				bp::tools::consoleCoordinates(122, 53);
				system("pause");
				system("CLS");
			}

			//Output first frame
			void firstFrame(bp::type::frames::FRAME frame)
			{
				bp::tools::consoleCoordinates(0, 0);
				cout << frame.one;
				outputGuide();
				bp::tools::consoleCoordinates(38, 47);
				bp::tools::slowmotionOfScreenplay("In 2050, a great danger was approaching the Earth. A large asteroid with a diameter of about 2000 km.");
				bp::tools::consoleCoordinates(122, 53);
				system("pause");
				system("CLS");
			}

			//Output second frame
			void secondFrame(bp::type::frames::FRAME frame)
			{
				bp::tools::consoleCoordinates(0, 0);
				cout << frame.two;
				outputGuide();
				bp::tools::consoleCoordinates(39, 47);
				bp::tools::slowmotionOfScreenplay("You earthlings had no choice to escape alive except to leave this planet with your spaceship.");
				bp::tools::consoleCoordinates(122, 53);
				system("pause");
				system("CLS");
			}

			//Output third frame
			void thirdFrame(bp::type::frames::FRAME frame)
			{
				bp::tools::consoleCoordinates(0, 0);
				cout << frame.three;
				outputGuide();
				bp::tools::consoleCoordinates(39, 47);
				bp::tools::slowmotionOfScreenplay("As you can see, the Earth is gone, but humanity is still saved in your spaceship.");
				bp::tools::consoleCoordinates(122, 53);
				system("pause");
				system("CLS");
			}

			//Output fourth frame
			void fourthFrame(bp::type::frames::FRAME frame)
			{
				bp::tools::consoleCoordinates(0, 0);
				cout << frame.four;
				outputGuide();
				bp::tools::consoleCoordinates(39, 47);
				bp::tools::slowmotionOfScreenplay("We found 200,000 people in hibernation sleep. There is still hope.");
				bp::tools::consoleCoordinates(122, 53);
				system("pause");
				system("CLS");
			}

			//Output fifth frame
			void fifthFrame(bp::type::frames::FRAME frame)
			{
				bp::tools::consoleCoordinates(0, 0);
				cout << frame.five;
				quiz::lives::outputFourHearth();
				outputGuide();
				bp::tools::consoleCoordinates(39, 47);
				bp::tools::slowmotionOfScreenplay("Watch out your spaceship is approaching a meteor storm. You must destroy all 10 meteors ");
				bp::tools::consoleCoordinates(39, 48);
				bp::tools::slowmotionOfScreenplay("with your laser weapon. You have four lives. Be careful ...");
				bp::tools::consoleCoordinates(122, 53);
				system("pause");
				system("CLS");
			}

			//Output sixt frame
			void sixthFrame()
			{
				outputGuide();
				bp::tools::consoleCoordinates(42, 47);
				bp::tools::slowmotionOfScreenplay("Before that, you have to see the information about plants and animals.");
				bp::tools::consoleCoordinates(42, 48);
				bp::tools::slowmotionOfScreenplay("Next, you have to answer correctly the questions to destroy all 10 asteroids.");
				bp::tools::consoleCoordinates(122, 53);
				system("pause");
				system("CLS");
			}

			//Output frame after quiz
			void quizFrame(bp::type::frames::FRAME frame)
			{
				bp::tools::consoleCoordinates(0, 0);
				cout << frame.quizFrame;
			}

			//Output seventh frame
			void seventhFrame()
			{
				outputGuide();
				bp::tools::consoleCoordinates(39, 47);
				bp::tools::slowmotionOfScreenplay("Congratulations, you managed to save humanity, now you can go to the planet Bacillicus.");
				bp::tools::consoleCoordinates(42, 48);
				bp::tools::slowmotionOfScreenplay("It will take you a long time, so you need to hibernate. See you in 200 years ...");
				bp::tools::consoleCoordinates(122, 53);
				system("pause");
				system("CLS");
			}

			//Output eight frame
			void eightFrame(bp::type::frames::FRAME frame)
			{
				bp::tools::consoleCoordinates(0, 20);
				cout << frame.eight;
				bp::tools::consoleCoordinates(122, 53);
				system("pause");
				system("CLS");
			}

			//Output ninth frame
			void ninthFrame(bp::type::frames::FRAME frame)
			{
				bp::tools::consoleCoordinates(0, 0);
				cout << frame.nine;
				outputGuide();
				bp::tools::consoleCoordinates(39, 47);
				bp::tools::slowmotionOfScreenplay("Nice to see you finally after 200 years you discovered the planet Bacillicus.");
				bp::tools::consoleCoordinates(39, 48);
				bp::tools::slowmotionOfScreenplay("Now you can start building this place with plants and animals.");
				bp::tools::consoleCoordinates(122, 53);
				system("pause");
				system("CLS");
			}
		}
	}

	namespace menus
	{
		namespace registrationFormMenu
		{
			//Display active buttons
			namespace activeButtons
			{
				void firstButton()
				{
					cout << endl << endl << endl << endl;
					cout << "                         ______________________________________________________________________________________________________________" << endl;
					cout << "                         |                                                                                                            |" << endl;
					cout << "                         |                                        " << "\x1b[1;33m" << "+" << "\x1b[1;37m" << "                          " << "\x1b[1;33m" << "." << "\x1b[1;37m" << "                                        |" << endl;
					cout << "                         |              " << "\x1b[1;33m" << "." << "\x1b[1;37m" << "                                                                                   " << "\x1b[1;33m" << "+" << "\x1b[1;37m" << "         |" << endl;
					cout << "                         |                        " << "\x1b[0;35m" << "   __  __       _                                                 " << "\x1b[0;37m" << "                  |" << endl;
					cout << "                         |                        " << "\x1b[0;35m" << "  |  \\/  | __ _(_)_ __       _ __ ___   ___ _ __  _   _          " << "\x1b[0;37m" << "                   |" << endl;
					cout << "                         |                        " << "\x1b[0;35m" << "  | |\\/| |/ _` | | '_ \\     | '_ ` _ \\ / _ \\ '_ \\| | | |     " << "\x1b[0;37m" << "                       |" << endl;
					cout << "                         |                        " << "\x1b[0;35m" << "  | |  | | (_| | | | | |    | | | | | |  __/ | | | |_| |          " << "\x1b[0;37m" << "                  |" << endl;
					cout << "                         |                        " << "\x1b[1;35m" << "  |_|  |_|\\__,_|_|_| |_|    |_| |_| |_|\\___|_| |_|\\__,_|       " << "\x1b[0;37m" << "                     |" << endl;
					cout << "                         |                                                                                                            |" << endl;
					cout << "                         |                                                                                                            |" << endl;
					cout << "                         |                                           " << "\x1b[1;33m" << "+" << "\x1b[1;37m" << "                 " << "\x1b[1;33m" << "." << "\x1b[1;37m" << "                         " << "\x1b[1;33m" << "." << "\x1b[1;37m" << "                    |" << endl;
					cout << "                         |                                                                                                 " << "\x1b[1;33m" << "+" << "\x1b[1;37m" << "          |" << endl;
					cout << "                         |                 " << "\x1b[1;33m" << "." << "\x1b[1;37m" << "                                                                                          |" << endl;
					cout << "                         |     " << "\x1b[1;33m" << "." << "\x1b[1;37m" << "                    " << "\x1b[1;33m" << "." << "\x1b[1;37m" << "         " << "\x1b[1;36m" << "       __________________   " << "\x1b[1;37m" << "          " << "\x1b[1;33m" << "+" << "\x1b[1;37m" << "                                 |" << endl;
					cout << "                         |                                        " << "\x1b[1;36m" << "  /                  \\  " << "\x1b[1;37m" << "                                            |" << endl;
					cout << "                         |                                       " << "\x1b[1;36m" << "  {   Log in as admin  }   " << "\x1b[1;37m" << "                                          |" << endl;
					cout << "                         |                                       " << "\x1b[1;36m" << "   \\__________________/   " << "\x1b[1;37m" << "                      " << "\x1b[1;33m" << "x" << "\x1b[1;37m" << "                    |" << endl;
				}

				void secondButton()
				{
					cout << "                         |                                                                                                 " << "\x1b[1;33m" << "+" << "\x1b[1;37m" << "          |" << endl;
					cout << "                         |                 " << "\x1b[1;33m" << "." << "\x1b[1;37m" << "                                                                                          |" << endl;
					cout << "                         |     " << "\x1b[1;33m" << "." << "\x1b[1;37m" << "                    " << "\x1b[1;33m" << "." << "\x1b[1;37m" << "            " << "\x1b[1;36m" << "    __________________    " << "\x1b[1;37m" << "         " << "\x1b[1;33m" << "+" << "\x1b[1;37m" << "                                 |" << endl;
					cout << "                         |                                      " << "\x1b[1;36m" << "    /                  \\   " << "\x1b[1;37m" << "                                           |" << endl;
					cout << "                         |                                     " << "\x1b[1;36m" << "    {  Log in as player  }   " << "\x1b[1;37m" << "                                          |" << endl;
					cout << "                         |                                     " << "\x1b[1;36m" << "     \\__________________/    " << "\x1b[1;37m" << "                     " << "\x1b[1;33m" << "x" << "\x1b[1;37m" << "                    |" << endl;
				}

				void thirdButton()
				{
					cout << "                         |       " << "\x1b[1;33m" << "*" << "\x1b[1;37m" << "                                                                                         " << "\x1b[1;33m" << "." << "\x1b[1;37m" << "          |" << endl;
					cout << "                         |                            " << "\x1b[1;33m" << "+" << "\x1b[1;37m" << "                                                                               |" << endl;
					cout << "                         |                                     " << "\x1b[1;36m" << "      __________________            " << "\x1b[1;37m" << "                                   |" << endl;
					cout << "                         |                 " << "\x1b[1;33m" << "." << "\x1b[1;37m" << "               " << "\x1b[1;36m" << "         /                  \\    " << "\x1b[1;37m" << "         " << "\x1b[1;33m" << "*" << "\x1b[1;37m" << "                                |" << endl;
					cout << "                         |                                    " << "\x1b[1;36m" << "     { Register as player }   " << "\x1b[1;37m" << "                                          |" << endl;
					cout << "                         |                                    " << "\x1b[1;36m" << "      \\__________________/   " << "\x1b[1;37m" << "                                           |" << endl;
				}

				void fourthButton()
				{
					cout << "                         |                                                                                     " << "\x1b[1;33m" << "." << "\x1b[1;37m" << "           " << "\x1b[1;33m" << "*" << "\x1b[1;37m" << "          |" << endl;
					cout << "                         |         " << "\x1b[1;33m" << "*" << "\x1b[1;37m" << "                                                                                                  |" << endl;
					cout << "                         |                                        " << "\x1b[1;36m" << "   __________________        " << "\x1b[1;37m" << "                                       |" << endl;
					cout << "                         |                            " << "\x1b[1;33m" << "." << "\x1b[1;37m" << "    " << "\x1b[1;36m" << "         /                  \\    " << "\x1b[1;37m" << "                                          |" << endl;
					cout << "                         |                                     " << "\x1b[1;36m" << "    {  Change  password  }     " << "\x1b[1;37m" << "            " << "\x1b[0;36m" << "         ___--------___     " << "\x1b[1;37m" << "|" << endl;
					cout << "                         |               " << "\x1b[1;33m" << "x" << "\x1b[1;36m" << "                     " << "\x1b[1;36m" << "     \\__________________/      " << "\x1b[0;36m" << "                  .--\\              --. " << "\x1b[1;37m" << "|" << endl;
				}

				void fifthButton()
				{
					cout << "                         |                                                                     " << "\x1b[1;33m" << "+" << "\x1b[1;37m" << "           " << "\x1b[0;36m" << "   ./.;_.\\           __/~  " << "\x1b[1;37m" << "|" << endl;
					cout << "                         |                                                                             " << "\x1b[0;36m" << "      /;  / `-'        __\\     " << "\x1b[1;37m" << "|" << endl;
					cout << "                         |                                        " << "\x1b[1;36m" << "   __________________     " << "\x1b[1;37m" << "            " << "\x1b[0;36m" << "    / ,--'     ____  / .   .; " << "\x1b[1;37m" << "|" << endl;
					cout << "                         |                        " << "\x1b[1;33m" << "+" << "\x1b[1;37m" << "          " << "\x1b[1;36m" << "       /                  \\  " << "\x1b[1;37m" << "              " << "\x1b[0;36m" << "   | .|       /    /        _ " << "\x1b[1;37m" << "|" << endl;
					cout << "                         |        " << "\x1b[1;33m" << "." << "\x1b[1;37m" << "                         " << "\x1b[1;36m" << "       {        Exit        }   " << "\x1b[1;37m" << "        " << "\x1b[1;33m" << "*" << "\x1b[1;37m" << "    " << "\x1b[0;36m" << " |__/    __ |      \\ . ;   \\ " << "\x1b[1;37m" << "|" << endl;
					cout << "                         |                                      " << "\x1b[1;36m" << "    \\__________________/   " << "\x1b[1;37m" << "             " << "\x1b[0;36m" << "  |      /  \\\\_     \\    . ;| " << "\x1b[1;37m" << "|" << endl;
					cout << "                         |                                                                              " << "\x1b[0;36m" << "  |      \\  .~\\      \\___,--' " << "\x1b[1;37m" << "|" << endl;
					cout << "                         |                   " << "\x1b[1;33m" << "." << "\x1b[1;37m" << "                                  " << "\x1b[1;33m" << "." << "\x1b[1;37m" << "                       " << "\x1b[0;36m" << "   |     | . ;       ~~~~\\_   " << "\x1b[1;37m" << "|" << endl;
					cout << "                         |                                     " << "\x1b[1;33m" << "+" << "\x1b[1;37m" << "                                     " << "\x1b[0;36m" << "       \\    \\   .        .  ; \\  " << "\x1b[1;37m" << "|" << endl;
					cout << "                         |____________________________________________________________________________________________________________|" << endl;
				}
			}

			//Display inactive buttons
			namespace inactiveButtons
			{
				void firstButton()
				{
					cout << endl << endl << endl << endl;
					cout << "                         ______________________________________________________________________________________________________________" << endl;
					cout << "                         |                                                                                                            |" << endl;
					cout << "                         |                                        " << "\x1b[1;33m" << "+" << "\x1b[1;37m" << "                          " << "\x1b[1;33m" << "." << "\x1b[1;37m" << "                                        |" << endl;
					cout << "                         |              " << "\x1b[1;33m" << "." << "\x1b[1;37m" << "                                                                                   " << "\x1b[1;33m" << "+" << "\x1b[1;37m" << "         |" << endl;
					cout << "                         |                       " << "\x1b[0;35m" << "    __  __       _                                                " << "\x1b[0;37m" << "                   |" << endl;
					cout << "                         |                       " << "\x1b[0;35m" << "   |  \\/  | __ _(_)_ __       _ __ ___   ___ _ __  _   _         " << "\x1b[0;37m" << "                    |" << endl;
					cout << "                         |                       " << "\x1b[0;35m" << "   | |\\/| |/ _` | | '_ \\     | '_ ` _ \\ / _ \\ '_ \\| | | |    " << "\x1b[0;37m" << "                        |" << endl;
					cout << "                         |                       " << "\x1b[0;35m" << "   | |  | | (_| | | | | |    | | | | | |  __/ | | | |_| |         " << "\x1b[0;37m" << "                   |" << endl;
					cout << "                         |                       " << "\x1b[1;35m" << "   |_|  |_|\\__,_|_|_| |_|    |_| |_| |_|\\___|_| |_|\\__,_|      " << "\x1b[0;37m" << "                      |" << endl;
					cout << "                         |                                                                                                            |" << endl;
					cout << "                         |                                                                                                            |" << endl;
					cout << "                         |                                           " << "\x1b[1;33m" << "+" << "\x1b[1;37m" << "                 " << "\x1b[1;33m" << "." << "\x1b[1;37m" << "                         " << "\x1b[1;33m" << "." << "\x1b[1;37m" << "                    |" << endl;
					cout << "                         |                                                                                                 " << "\x1b[1;33m" << "+" << "\x1b[1;37m" << "          |" << endl;
					cout << "                         |                 " << "\x1b[1;33m" << "." << "\x1b[1;37m" << "                                                                                          |" << endl;
					cout << "                         |     " << "\x1b[1;33m" << "." << "\x1b[1;37m" << "                    " << "\x1b[1;33m" << "." << "\x1b[1;37m" << "                __________________             " << "\x1b[1;33m" << "+" << "\x1b[1;37m" << "                                 |" << endl;
					cout << "                         |                                          /                  \\                                              |" << endl;
					cout << "                         |                                         {   Log in as admin  }                                             |" << endl;
					cout << "                         |                                          \\__________________/                         " << "\x1b[1;33m" << "x" << "\x1b[1;37m" << "                    |" << endl;
				}

				void secondButton()
				{
					cout << "                         |                                                                                                 " << "\x1b[1;33m" << "+" << "\x1b[1;37m" << "          |" << endl;
					cout << "                         |                 " << "\x1b[1;33m" << "." << "\x1b[1;37m" << "                                                                                          |" << endl;
					cout << "                         |     " << "\x1b[1;33m" << "." << "\x1b[1;37m" << "                    " << "\x1b[1;33m" << "." << "\x1b[1;37m" << "                __________________             " << "\x1b[1;33m" << "+" << "\x1b[1;37m" << "                                 |" << endl;
					cout << "                         |                                          /                  \\                                              |" << endl;
					cout << "                         |                                         {  Log in as player  }                                             |" << endl;
					cout << "                         |                                          \\__________________/                         " << "\x1b[1;33m" << "x" << "\x1b[1;37m" << "                    |" << endl;
				}

				void thirdButton()
				{
					cout << "                         |       " << "\x1b[1;33m" << "*" << "\x1b[1;37m" << "                                                                                         " << "\x1b[1;33m" << "." << "\x1b[1;37m" << "          |" << endl;
					cout << "                         |                            " << "\x1b[1;33m" << "+" << "\x1b[1;37m" << "                                                                               |" << endl;
					cout << "                         |                                           __________________                                               |" << endl;
					cout << "                         |                 " << "\x1b[1;33m" << "." << "\x1b[1;37m" << "                        /                  \\             " << "\x1b[1;33m" << "*" << "\x1b[1;37m" << "                                |" << endl;
					cout << "                         |                                         { Register as player }                                             |" << endl;
					cout << "                         |                                          \\__________________/                                              |" << endl;
				}

				void fourthButton()
				{
					cout << "                         |                                                                                     " << "\x1b[1;33m" << "." << "\x1b[1;37m" << "           " << "\x1b[1;33m" << "*" << "\x1b[1;37m" << "          |" << endl;
					cout << "                         |         " << "\x1b[1;33m" << "*" << "\x1b[1;37m" << "                                                                                                  |" << endl;
					cout << "                         |                                           __________________                                               |" << endl;
					cout << "                         |                            " << "\x1b[1;33m" << "." << "\x1b[1;37m" << "             /                  \\                                              |" << endl;
					cout << "                         |                                         {  Change  password  }                     " << "\x1b[0;36m" << "     ___--------___    " << "\x1b[1;37m" << " |" << endl;
					cout << "                         |               " << "\x1b[1;33m" << "x" << "\x1b[1;37m" << "                          \\__________________/                    " << "\x1b[0;36m" << "    .--\\              --. " << "\x1b[1;37m" << "|" << endl;
				}

				void fifthButton()
				{
					cout << "                         |                                                                     " << "\x1b[1;33m" << "+" << "\x1b[1;37m" << "            " << "\x1b[0;36m" << "  ./.;_.\\           __/~  " << "\x1b[1;37m" << "|" << endl;
					cout << "                         |                                                                                  " << "\x1b[0;36m" << " /;  / `-'        __\\     " << "\x1b[1;37m" << "|" << endl;
					cout << "                         |                                           __________________                    " << "\x1b[0;36m" << " / ,--'     ____  / .   .; " << "\x1b[1;37m" << "|" << endl;
					cout << "                         |                        " << "\x1b[1;33m" << "+" << "\x1b[1;37m" << "                 /                  \\               " << "\x1b[0;36m" << "    | .|       /    /        _ " << "\x1b[1;37m" << "|" << endl;
					cout << "                         |        " << "\x1b[1;33m" << "." << "\x1b[1;37m" << "                                {        Exit        }           " << "\x1b[1;33m" << "*" << "\x1b[1;37m" << "   " << "\x1b[0;36m" << "  |__/    __ |      \\ . ;   \\ " << "\x1b[1;37m" << "|" << endl;
					cout << "                         |                                          \\__________________/                 " << "\x1b[0;36m" << " |      /  \\\\_     \\    . ;| " << "\x1b[1;37m" << "|" << endl;
					cout << "                         |                                                                              " << "\x1b[0;36m" << "  |      \\  .~\\      \\___,--' " << "\x1b[1;37m" << "|" << endl;
					cout << "                         |                   " << "\x1b[1;33m" << "." << "\x1b[1;37m" << "                                  " << "\x1b[1;33m" << "." << "\x1b[1;37m" << "                       " << "\x1b[0;36m" << "   |     | . ;       ~~~~\\_   " << "\x1b[1;37m" << "|" << endl;
					cout << "                         |                                     " << "\x1b[1;33m" << "+" << "\x1b[1;37m" << "                                         " << "\x1b[0;36m" << "   \\    \\   .        .  ; \\  " << "\x1b[1;37m" << "|" << endl;
					cout << "                         |____________________________________________________________________________________________________________|" << endl;
				}
			}

			//Output menu according to active button
			void outputMenuWithFirstActiveButton()
			{
				activeButtons::firstButton();
				inactiveButtons::secondButton();
				inactiveButtons::thirdButton();
				inactiveButtons::fourthButton();
				inactiveButtons::fifthButton();
			}

			void outputMenuWithSecondActiveButton()
			{
				inactiveButtons::firstButton();
				activeButtons::secondButton();
				inactiveButtons::thirdButton();
				inactiveButtons::fourthButton();
				inactiveButtons::fifthButton();
			}

			void outputMenuWithThirdActiveButton()
			{
				inactiveButtons::firstButton();
				inactiveButtons::secondButton();
				activeButtons::thirdButton();
				inactiveButtons::fourthButton();
				inactiveButtons::fifthButton();
			}

			void outputMenuWithFourthActiveButton()
			{
				inactiveButtons::firstButton();
				inactiveButtons::secondButton();
				inactiveButtons::thirdButton();
				activeButtons::fourthButton();
				inactiveButtons::fifthButton();
			}

			void outputMenuWithFifthActiveButton()
			{
				inactiveButtons::firstButton();
				inactiveButtons::secondButton();
				inactiveButtons::thirdButton();
				inactiveButtons::fourthButton();
				activeButtons::fifthButton();
			}
		}

		namespace playMenu
		{
			//Display active buttons
			namespace activeButtons
			{
				void firstButton()
				{
					cout << endl << endl << endl << endl << endl << endl << endl;
					cout << "                            ________________________________________________________________________________________________________" << endl;
					cout << "                            |                                                                                                      |" << endl;
					cout << "                            |       .                  O                             .            +          *                 .   |" << endl;
					cout << "                            |                            " << "\x1b[0;35m" << " __        __   _   " << "\x1b[1;37m" << "                                                      |" << endl;
					cout << "                            |              .:'           " << "\x1b[0;35m" << " \\ \\      / /__| | ___ ___  _ __ ___   ___    " << "\x1b[1;37m" << "               .            |" << endl;
					cout << "                            |          _.::'       +     " << "\x1b[0;35m" << "  \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\ " << "\x1b[1;37m" << "                              |" << endl;
					cout << "                            |         (_.'               " << "\x1b[1;35m" << "   \\ V  V /  __/ | (_| (_) | | | | | |  __/      " << "\x1b[1;37m" << "    +                    |" << endl;
					cout << "                            |     *                      " << "\x1b[1;35m" << "    \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___|  " << "\x1b[1;37m" << "                             |" << endl;
					cout << "                            |                                                                                          O           |" << endl;
					cout << "                            |                 .       +                             .                                              |" << endl;
					cout << "                            |                                     .                             O                          .       |" << endl;
					cout << "                            |                                                +                            .       .                |" << endl;
					cout << "                            |       .                                                                   +  :      .                |" << endl;
					cout << "                            |                                       " << "\x1b[1;36m" << "   __________________     " << "\x1b[1;37m" << " .                  :             +  |" << endl;
					cout << "                            |                  *       +            " << "\x1b[1;36m" << "  /                  \\   " << "\x1b[1;37m" << "                 .   !   '  ()        |" << endl;
					cout << "                            |            '                  |       " << "\x1b[1;36m" << " {        Play        }   " << "\x1b[1;37m" << "                   ,|.'              |" << endl;
					cout << "                            |        ()    .-.,=\"``\"=.    - o -   " << "\x1b[1;36m" << "    \\__________________/ " << "\x1b[1;37m" << "            -  -- ---(-O-`--- --  -     |" << endl;
				}

				void secondButton()
				{
					cout << "                            |              '=/_       \\     |                                                   ,`|'`.             |" << endl;
					cout << "                            |           *   |  '=._    |                +                       +             ,   !    .           |" << endl;
					cout << "                            |                \\     `=./`,        '  " << "\x1b[1;36m" << "   __________________  " << "\x1b[1;37m" << "                       :       :        |" << endl;
					cout << "                            |             .   '=.__.=' `='      *    " << "\x1b[1;36m" << " /                  \\ " << "\x1b[1;37m" << "                       .     --+--      |" << endl;
					cout << "                            |    +                         +         " << "\x1b[1;36m" << "{     How to play    } " << "\x1b[1;37m" << "            .:        .       !        |" << endl;
					cout << "                            |         O      *        '       .      " << "\x1b[1;36m" << " \\__________________/ " << "\x1b[1;37m" << "                                        | " << endl;
				}

				void thirdButton()
				{
					cout << "                            |                                                                                                 O    | " << endl;
					cout << "                            |                                     O           *          .           .              +              | " << endl;
					cout << "                            |                                       " << "\x1b[1;36m" << "   __________________   " << "\x1b[1;37m" << "                                       |" << endl;
					cout << "                            |     .                      .          " << "\x1b[1;36m" << "  /                  \\ " << "\x1b[1;37m" << "                                        |" << endl;
					cout << "                            |            .                          " << "\x1b[1;36m" << " {        Exit        } " << "\x1b[1;37m" << "       *                          .    |" << endl;
					cout << "                            |                                       " << "\x1b[1;36m" << "  \\__________________/ " << "\x1b[1;37m" << "                 .                      |" << endl;
					cout << "                            |                        +                                                                  *          |" << endl;
					cout << "                            |                                     *                                                                |" << endl;
					cout << "                            |         .                                          .                  +                              |" << endl;
					cout << "                            |                               /\\                                                            .        |" << endl;
					cout << "                            |                              (  )                                                                    |" << endl;
					cout << "                            |____^/\\___^--____/\\____O______(  )____/\\/\\---/\\___________---_____ ^ / \\___ ^ --____ / \\______________|" << endl;
					cout << "                            |   /\\^   ^  ^    ^        _  /|/\\|\\  ^^ ^  '\\ ^          ^       ---     \\^   ^  ^    ^        ^^ ^   |" << endl;
					cout << "                            |         --           -     /_||||_\\       --  -      -         ---  __       ^        --       --  - |" << endl;
					cout << "                            |   --  __                      ___--  ^  ^                --  __--  __            ___--  ^  ^         |" << endl;
					cout << "                            |______________________________________________________________________________________________________|" << endl;
				}
			}

			//Display inactive buttons
			namespace inactiveButtons
			{
				void firstButton()
				{
					cout << endl << endl << endl << endl << endl << endl << endl;
					cout << "                            ________________________________________________________________________________________________________" << endl;
					cout << "                            |                                                                                                      |" << endl;
					cout << "                            |       .                  O                             .            +          *                 .   |" << endl;
					cout << "                            |                            " << "\x1b[0;35m" << " __        __   _   " << "\x1b[1;37m" << "                                                      |" << endl;
					cout << "                            |              .:'           " << "\x1b[0;35m" << " \\ \\      / /__| | ___ ___  _ __ ___   ___    " << "\x1b[1;37m" << "               .            |" << endl;
					cout << "                            |          _.::'       +     " << "\x1b[0;35m" << "  \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\ " << "\x1b[1;37m" << "                              |" << endl;
					cout << "                            |         (_.'               " << "\x1b[1;35m" << "   \\ V  V /  __/ | (_| (_) | | | | | |  __/      " << "\x1b[1;37m" << "    +                    |" << endl;
					cout << "                            |     *                      " << "\x1b[1;35m" << "    \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___|  " << "\x1b[1;37m" << "                             |" << endl;
					cout << "                            |                                                                                          O           |" << endl;
					cout << "                            |                 .       +                             .                                              |" << endl;
					cout << "                            |                                     .                             O                          .       |" << endl;
					cout << "                            |                                                +                            .       .                |" << endl;
					cout << "                            |       .                                                                   +  :      .                |" << endl;
					cout << "                            |                                          __________________      .                  :             +  |" << endl;
					cout << "                            |                  *       +              /                  \\                    .   !   '  ()        |" << endl;
					cout << "                            |            '                  |        {        Play        }                      ,|.'              |" << endl;
					cout << "                            |        ()    .-.,=\"``\"=.    - o -       \\__________________/             -  -- ---(-O-`--- --  -     |" << endl;
				}

				void secondButton()
				{
					cout << "                            |              '=/_       \\     |                                                   ,`|'`.             |" << endl;
					cout << "                            |           *   |  '=._    |                +                       +             ,   !    .           |" << endl;
					cout << "                            |                \\     `=./`,        '     __________________                         :       :        |" << endl;
					cout << "                            |             .   '=.__.=' `='      *     /                  \\                        .     --+--      |" << endl;
					cout << "                            |    +                         +         {     How to play    }             .:        .       !        |" << endl;
					cout << "                            |         O      *        '       .       \\__________________/                                         | " << endl;
				}

				void thirdButton()
				{
					cout << "                            |                                                                                                 O    | " << endl;
					cout << "                            |                                     O           *          .           .              +              | " << endl;
					cout << "                            |                                          __________________                                          |" << endl;
					cout << "                            |     .                      .            /                  \\                                         |" << endl;
					cout << "                            |            .                           {        Exit        }        *                          .    |" << endl;
					cout << "                            |                                         \\__________________/                  .                      |" << endl;
					cout << "                            |                        +                                                                  *          |" << endl;
					cout << "                            |                                     *                                                                |" << endl;
					cout << "                            |         .                                          .                  +                              |" << endl;
					cout << "                            |                               /\\                                                            .        |" << endl;
					cout << "                            |                              (  )                                                                    |" << endl;
					cout << "                            |____^/\\___^--____/\\____O______(  )____/\\/\\---/\\___________---_____ ^ / \\___ ^ --____ / \\______________|" << endl;
					cout << "                            |   /\\^   ^  ^    ^        _  /|/\\|\\  ^^ ^  '\\ ^          ^       ---     \\^   ^  ^    ^        ^^ ^   |" << endl;
					cout << "                            |         --           -     /_||||_\\       --  -      -         ---  __       ^        --       --  - |" << endl;
					cout << "                            |   --  __                      ___--  ^  ^                --  __--  __            ___--  ^  ^         |" << endl;
					cout << "                            |______________________________________________________________________________________________________|" << endl;
				}
			}

			//Output menu according to active button
			void outputMenuWithFirstActiveButton()
			{
				activeButtons::firstButton();
				inactiveButtons::secondButton();
				inactiveButtons::thirdButton();
			}

			void outputMenuWithSecondActiveButton()
			{
				inactiveButtons::firstButton();
				activeButtons::secondButton();
				inactiveButtons::thirdButton();
			}

			void outputMenuWithThirdActiveButton()
			{
				inactiveButtons::firstButton();
				inactiveButtons::secondButton();
				activeButtons::thirdButton();
			}
		}

		namespace plantsAnimalsAndQuizMenu
		{
			//Display active buttons
			namespace activeButtons
			{
				void firstButton()
				{
					cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
					cout << "                                      _____________________________________________________________________________________" << endl;
					cout << "                                      |                                                                                   |" << endl;
					cout << "                                      |                                                                                   |" << endl;
					cout << "                                      |                                                                                   |" << endl;
					cout << "                                      |                        " << "\x1b[1;35m" << "     ____  _             _           " << "\x1b[1;37m" << "                      |" << endl;
					cout << "                                      |                        " << "\x1b[1;35m" << "    |  _ \\| | __ _ _ __ | |_ ___    " << "\x1b[1;37m" << "                       |" << endl;
					cout << "                                      |                        " << "\x1b[1;35m" << "    | |_) | |/ _` | '_ \\| __/ __|   " << "\x1b[1;37m" << "                       |" << endl;
					cout << "                                      |                        " << "\x1b[1;35m" << "    |  __/| | (_| | | | | |_\\__ \\   " << "\x1b[1;37m" << "                       |" << endl;
					cout << "                                      |                        " << "\x1b[1;35m" << "    |_|   |_|\\__,_|_| |_|\\__|___/  " << "\x1b[1;37m" << "                        |" << endl;
				}

				void secondButton()
				{
					cout << "                                      |                                                                                   |" << endl;
					cout << "                                      |                                                                                   |" << endl;
					cout << "                                      |                     " << "\x1b[1;35m" << "      _          _                 _          " << "\x1b[1;37m" << "                |" << endl;
					cout << "                                      |                     " << "\x1b[1;35m" << "     / \\   _ __ (_)_ __ ___   __ _| |___     " << "\x1b[1;37m" << "                 |" << endl;
					cout << "                                      |                     " << "\x1b[1;35m" << "    / _ \\ | '_ \\| | '_ ` _ \\ / _` | / __|  " << "\x1b[1;37m" << "                   |" << endl;
					cout << "                                      |                     " << "\x1b[1;35m" << "   / ___ \\| | | | | | | | | | (_| | \\__ \\  " << "\x1b[1;37m" << "                   |" << endl;
					cout << "                                      |                     " << "\x1b[1;35m" << "  /_/   \\_\\_| |_|_|_| |_| |_|\\__,_|_|___/  " << "\x1b[1;37m" << "                   |" << endl;
				}

				void thirdButton()
				{
					cout << "                                      |                                                                                   |" << endl;
					cout << "                                      |                                                                                   |" << endl;
					cout << "                                      |                               " << "\x1b[1;35m" << "    ___        _           " << "\x1b[1;37m" << "                         |" << endl;
					cout << "                                      |                               " << "\x1b[1;35m" << "   / _ \\ _   _(_)____     " << "\x1b[1;37m" << "                          |" << endl;
					cout << "                                      |                               " << "\x1b[1;35m" << "  | | | | | | | |_  /      " << "\x1b[1;37m" << "                         |" << endl;
					cout << "                                      |                               " << "\x1b[1;35m" << "  | |_| | |_| | |/ /       " << "\x1b[1;37m" << "                         |" << endl;
					cout << "                                      |                               " << "\x1b[1;35m" << "   \\__\\_\\\\__,_|_/___|  " << "\x1b[1;37m" << "                             |" << endl;
					cout << "                                      |                                                                                   |" << endl;
					cout << "                                      |                                                                                   |" << endl;
					cout << "                                      |                                                                                   |" << endl;
					cout << "                                      |___________________________________________________________________________________|" << endl;
				}
			}

			//Display inactive buttons
			namespace inactiveButtons
			{
				void firstButton()
				{
					cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
					cout << "                                      _____________________________________________________________________________________" << endl;
					cout << "                                      |                                                                                   |" << endl;
					cout << "                                      |                                                                                   |" << endl;
					cout << "                                      |                                                                                   |" << endl;
					cout << "                                      |                             ____  _             _                                 |" << endl;
					cout << "                                      |                            |  _ \\| | __ _ _ __ | |_ ___                           |" << endl;
					cout << "                                      |                            | |_) | |/ _` | '_ \\| __/ __|                          |" << endl;
					cout << "                                      |                            |  __/| | (_| | | | | |_\\__ \\                          |" << endl;
					cout << "                                      |                            |_|   |_|\\__,_|_| |_|\\__|___/                          |" << endl;
				}

				void secondButton()
				{
					cout << "                                      |                                                                                   |" << endl;
					cout << "                                      |                                                                                   |" << endl;
					cout << "                                      |                           _          _                 _                          |" << endl;
					cout << "                                      |                          / \\   _ __ (_)_ __ ___   __ _| |___                      |" << endl;
					cout << "                                      |                         / _ \\ | '_ \\| | '_ ` _ \\ / _` | / __|                     |" << endl;
					cout << "                                      |                        / ___ \\| | | | | | | | | | (_| | \\__ \\                     |" << endl;
					cout << "                                      |                       /_/   \\_\\_| |_|_|_| |_| |_|\\__,_|_|___/                     |" << endl;
				}

				void thirdButton()
				{
					cout << "                                      |                                                                                   |" << endl;
					cout << "                                      |                                                                                   |" << endl;
					cout << "                                      |                                   ___        _                                    |" << endl;
					cout << "                                      |                                  / _ \\ _   _(_)____                               |" << endl;
					cout << "                                      |                                 | | | | | | | |_  /                               |" << endl;
					cout << "                                      |                                 | |_| | |_| | |/ /                                |" << endl;
					cout << "                                      |                                  \\__\\_\\\\__,_|_/___|                               |" << endl;
					cout << "                                      |                                                                                   |" << endl;
					cout << "                                      |                                                                                   |" << endl;
					cout << "                                      |                                                                                   |" << endl;
					cout << "                                      |___________________________________________________________________________________|" << endl;
				}
			}

			//Output menu according to active button
			void outputMenuWithFirstActiveButton()
			{
				activeButtons::firstButton();
				inactiveButtons::secondButton();
				inactiveButtons::thirdButton();
			}

			void outputMenuWithSecondActiveButton()
			{
				inactiveButtons::firstButton();
				activeButtons::secondButton();
				inactiveButtons::thirdButton();
			}

			void outputMenuWithThirdActiveButton()
			{
				inactiveButtons::firstButton();
				inactiveButtons::secondButton();
				activeButtons::thirdButton();
			}
		}

		namespace animalsAndPlantsMenu
		{
			//Output animals header
			void animalsHeader()
			{
				cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
				cout << "                                 ______________________________________________________________________________________________" << endl;
				cout << "                                 |                                                                                            |" << endl;
				cout << "                                 |                                                                                            |" << endl;
				cout << "                                 |                                                                                            |" << endl;
				cout << "                                 |                             _          _                 _                                 |" << endl;
				cout << "                                 |                            / \\   _ __ (_)_ __ ___   __ _| |___                             |" << endl;
				cout << "                                 |                           / _ \\ | '_ \\| | '_ ` _ \\ / _` | / __|                            |" << endl;
				cout << "                                 |                          / ___ \\| | | | | | | | | | (_| | \\__ \\                            |" << endl;
				cout << "                                 |                         /_/   \\_\\_| |_|_|_| |_| |_|\\__,_|_|___/                            |" << endl;

			}

			//Output plants header
			void plantsHeader()
			{
				cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
				cout << "                                 ______________________________________________________________________________________________" << endl;
				cout << "                                 |                                                                                            |" << endl;
				cout << "                                 |                                                                                            |" << endl;
				cout << "                                 |                                                                                            |" << endl;
				cout << "                                 |                               ____  _             _                                        |" << endl;
				cout << "                                 |                              |  _ \\| | __ _ _ __ | |_ ___                                  |" << endl;
				cout << "                                 |                              | |_) | |/ _` | '_ \\| __/ __|                                 |" << endl;
				cout << "                                 |                              |  __/| | (_| | | | | |_\\__ \\                                 |" << endl;
				cout << "                                 |                              |_|   |_|\\__,_|_| |_|\\__|___/                                 |" << endl;
			}

			//Display active buttons
			namespace activeButtons
			{
				void firstButton()
				{
					cout << "                                 |                                                                                            |" << endl;
					cout << "                                 |                                                                                            |" << endl;
					cout << "                                 |                                                                                            |" << endl;
					cout << "                                 |                                                                                            |" << endl;
					cout << "                                 |                               " << "\x1b[1;34m" << "     __________________     " << "\x1b[1;37m" << "                                 |" << endl;
					cout << "                                 |                               " << "\x1b[1;34m" << "    /                  \\   " << "\x1b[1;37m" << "                                  |" << endl;
					cout << "                                 |                               " << "\x1b[1;34m" << "   {  View information  }   " << "\x1b[1;37m" << "                                 |" << endl;
					cout << "                                 |                               " << "\x1b[1;34m" << "    \\__________________/   " << "\x1b[1;37m" << "                                  |" << endl;
				}

				void secondButton()
				{
					cout << "                                 |                                                                                            |" << endl;
					cout << "                                 |                                                                                            |" << endl;
					cout << "                                 |                               " << "\x1b[1;34m" << "     __________________     " << "\x1b[1;37m" << "                                 |" << endl;
					cout << "                                 |                               " << "\x1b[1;34m" << "    /                  \\   " << "\x1b[1;37m" << "                                  |" << endl;
					cout << "                                 |                               " << "\x1b[1;34m" << "   {       Search       }   " << "\x1b[1;37m" << "                                 |" << endl;
					cout << "                                 |                               " << "\x1b[1;34m" << "    \\__________________/   " << "\x1b[1;37m" << "                                  |" << endl;
				}

				void thirdButton()
				{
					cout << "                                 |                                                                                            |" << endl;
					cout << "                                 |                                                                                            |" << endl;
					cout << "                                 |                               " << "\x1b[1;34m" << "     __________________     " << "\x1b[1;37m" << "                                 |" << endl;
					cout << "                                 |                               " << "\x1b[1;34m" << "    /                  \\   " << "\x1b[1;37m" << "                                  |" << endl;
					cout << "                                 |                               " << "\x1b[1;34m" << "   {        Exit        }   " << "\x1b[1;37m" << "                                 |" << endl;
					cout << "                                 |                               " << "\x1b[1;34m" << "    \\__________________/   " << "\x1b[1;37m" << "                                  |" << endl;
					cout << "                                 |                                                                                            |" << endl;
					cout << "                                 |                                                                                            |" << endl;
					cout << "                                 |                                                                                            |" << endl;
					cout << "                                 |____________________________________________________________________________________________|" << endl;
				}
			}

			//Display inactive buttons
			namespace inactiveButtons
			{
				void firstButton()
				{
					cout << "                                 |                                                                                            |" << endl;
					cout << "                                 |                                                                                            |" << endl;
					cout << "                                 |                                                                                            |" << endl;
					cout << "                                 |                                                                                            |" << endl;
					cout << "                                 |                                    __________________                                      |" << endl;
					cout << "                                 |                                   /                  \\                                     |" << endl;
					cout << "                                 |                                  {  View information  }                                    |" << endl;
					cout << "                                 |                                   \\__________________/                                     |" << endl;
				}

				void secondButton()
				{
					cout << "                                 |                                                                                            |" << endl;
					cout << "                                 |                                                                                            |" << endl;
					cout << "                                 |                                    __________________                                      |" << endl;
					cout << "                                 |                                   /                  \\                                     |" << endl;
					cout << "                                 |                                  {       Search       }                                    |" << endl;
					cout << "                                 |                                   \\__________________/                                     |" << endl;
				}

				void thirdButton()
				{
					cout << "                                 |                                                                                            |" << endl;
					cout << "                                 |                                                                                            |" << endl;
					cout << "                                 |                                    __________________                                      |" << endl;
					cout << "                                 |                                   /                  \\                                     |" << endl;
					cout << "                                 |                                  {        Exit        }                                    |" << endl;
					cout << "                                 |                                   \\__________________/                                     |" << endl;
					cout << "                                 |                                                                                            |" << endl;
					cout << "                                 |                                                                                            |" << endl;
					cout << "                                 |                                                                                            |" << endl;
					cout << "                                 |____________________________________________________________________________________________|" << endl;
				}
			}

			//Output menu according to active animals button
			namespace animalsMenu
			{
				void outputMenuWithFirstActiveButton()
				{
					animalsHeader();
					activeButtons::firstButton();
					inactiveButtons::secondButton();
					inactiveButtons::thirdButton();
				}

				void outputMenuWithSecondActiveButton()
				{
					animalsHeader();
					inactiveButtons::firstButton();
					activeButtons::secondButton();
					inactiveButtons::thirdButton();
				}

				void outputMenuWithThirdActiveButton()
				{
					animalsHeader();
					inactiveButtons::firstButton();
					inactiveButtons::secondButton();
					activeButtons::thirdButton();
				}
			}

			//Output menu according to active plants button
			namespace plantsMenu
			{
				void outputMenuWithFirstActiveButton()
				{
					plantsHeader();
					activeButtons::firstButton();
					inactiveButtons::secondButton();
					inactiveButtons::thirdButton();
				}

				void outputMenuWithSecondActiveButton()
				{
					plantsHeader();
					inactiveButtons::firstButton();
					activeButtons::secondButton();
					inactiveButtons::thirdButton();
				}

				void outputMenuWithThirdActiveButton()
				{
					plantsHeader();
					inactiveButtons::firstButton();
					inactiveButtons::secondButton();
					activeButtons::thirdButton();
				}
			}
		}

		namespace choosePlantsOrAnimalsWithExitMenu
		{
			//Display active buttons
			namespace activeButtons
			{
				void firstButton()
				{
					cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
					cout << "                                      _____________________________________________________________________________________" << endl;
					cout << "                                      |                                                                                   |" << endl;
					cout << "                                      |                                                                                   |" << endl;
					cout << "                                      |                                                                                   |" << endl;
					cout << "                                      |                         " << "\x1b[1;35m" << "   ____  _             _             " << "\x1b[1;37m" << "                     |" << endl;
					cout << "                                      |                         " << "\x1b[1;35m" << "  |  _ \\| | __ _ _ __ | |_ ___      " << "\x1b[1;37m" << "                      |" << endl;
					cout << "                                      |                         " << "\x1b[1;35m" << "  | |_) | |/ _` | '_ \\| __/ __|     " << "\x1b[1;37m" << "                      |" << endl;
					cout << "                                      |                         " << "\x1b[1;35m" << "  |  __/| | (_| | | | | |_\\__ \\     " << "\x1b[1;37m" << "                      |" << endl;
					cout << "                                      |                         " << "\x1b[1;35m" << "  |_|   |_|\\__,_|_| |_|\\__|___/    " << "\x1b[1;37m" << "                       |" << endl;
				}

				void secondButton()
				{
					cout << "                                      |                                                                                   |" << endl;
					cout << "                                      |                                                                                   |" << endl;
					cout << "                                      |                      " << "\x1b[1;35m" << "    _          _                 _            " << "\x1b[1;37m" << "               |" << endl;
					cout << "                                      |                      " << "\x1b[1;35m" << "   / \\   _ __ (_)_ __ ___   __ _| |___       " << "\x1b[1;37m" << "                |" << endl;
					cout << "                                      |                      " << "\x1b[1;35m" << "  / _ \\ | '_ \\| | '_ ` _ \\ / _` | / __|    " << "\x1b[1;37m" << "                  |" << endl;
					cout << "                                      |                      " << "\x1b[1;35m" << " / ___ \\| | | | | | | | | | (_| | \\__ \\    " << "\x1b[1;37m" << "                  |" << endl;
					cout << "                                      |                      " << "\x1b[1;35m" << "/_/   \\_\\_| |_|_|_| |_| |_|\\__,_|_|___/    " << "\x1b[1;37m" << "                  |" << endl;
				}

				void thirdButton()
				{
					cout << "                                      |                                                                                   |" << endl;
					cout << "                                      |                                                                                   |" << endl;
					cout << "                                      |                                " << "\x1b[1;35m" << "   _____      _ _          " << "\x1b[1;37m" << "                        |" << endl;
					cout << "                                      |                                " << "\x1b[1;35m" << "  | ____|_  _(_) |_        " << "\x1b[1;37m" << "                        |" << endl;
					cout << "                                      |                                " << "\x1b[1;35m" << "  |  _| \\ \\/ / | __|       " << "\x1b[1;37m" << "                        |" << endl;
					cout << "                                      |                                " << "\x1b[1;35m" << "  | |___ >  <| | |_        " << "\x1b[1;37m" << "                        |" << endl;
					cout << "                                      |                                " << "\x1b[1;35m" << "  |_____/_/\\_\\_|\\__|       " << "\x1b[1;37m" << "                        |" << endl;
					cout << "                                      |                                                                                   |" << endl;
					cout << "                                      |                                                                                   |" << endl;
					cout << "                                      |                                                                                   |" << endl;
					cout << "                                      |___________________________________________________________________________________|" << endl;
				}
			}

			//Display inactive buttons
			namespace inactiveButtons
			{
				void firstButton()
				{
					cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
					cout << "                                      _____________________________________________________________________________________" << endl;
					cout << "                                      |                                                                                   |" << endl;
					cout << "                                      |                                                                                   |" << endl;
					cout << "                                      |                                                                                   |" << endl;
					cout << "                                      |                            ____  _             _                                  |" << endl;
					cout << "                                      |                           |  _ \\| | __ _ _ __ | |_ ___                            |" << endl;
					cout << "                                      |                           | |_) | |/ _` | '_ \\| __/ __|                           |" << endl;
					cout << "                                      |                           |  __/| | (_| | | | | |_\\__ \\                           |" << endl;
					cout << "                                      |                           |_|   |_|\\__,_|_| |_|\\__|___/                           |" << endl;
				}

				void secondButton()
				{
					cout << "                                      |                                                                                   |" << endl;
					cout << "                                      |                                                                                   |" << endl;
					cout << "                                      |                          _          _                 _                           |" << endl;
					cout << "                                      |                         / \\   _ __ (_)_ __ ___   __ _| |___                       |" << endl;
					cout << "                                      |                        / _ \\ | '_ \\| | '_ ` _ \\ / _` | / __|                      |" << endl;
					cout << "                                      |                       / ___ \\| | | | | | | | | | (_| | \\__ \\                      |" << endl;
					cout << "                                      |                      /_/   \\_\\_| |_|_|_| |_| |_|\\__,_|_|___/                      |" << endl;
				}

				void thirdButton()
				{
					cout << "                                      |                                                                                   |" << endl;
					cout << "                                      |                                                                                   |" << endl;
					cout << "                                      |                                   _____      _ _                                  |" << endl;
					cout << "                                      |                                  | ____|_  _(_) |_                                |" << endl;
					cout << "                                      |                                  |  _| \\ \\/ / | __|                               |" << endl;
					cout << "                                      |                                  | |___ >  <| | |_                                |" << endl;
					cout << "                                      |                                  |_____/_/\\_\\_|\\__|                               |" << endl;
					cout << "                                      |                                                                                   |" << endl;
					cout << "                                      |                                                                                   |" << endl;
					cout << "                                      |                                                                                   |" << endl;
					cout << "                                      |___________________________________________________________________________________|" << endl;
				}
			}

			//Output menu according to active button
			void outputMenuWithFirstActiveButton()
			{
				activeButtons::firstButton();
				inactiveButtons::secondButton();
				inactiveButtons::thirdButton();
			}

			void outputMenuWithSecondActiveButton()
			{
				inactiveButtons::firstButton();
				activeButtons::secondButton();
				inactiveButtons::thirdButton();
			}

			void outputMenuWithThirdActiveButton()
			{
				inactiveButtons::firstButton();
				inactiveButtons::secondButton();
				activeButtons::thirdButton();
			}
		}

		namespace choosePlantsOrAnimalsMenu
		{
			//Display active buttons
			namespace activeButtons
			{
				void firstButton()
				{
					cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
					cout << "                                      _____________________________________________________________________________________" << endl;
					cout << "                                      |                                                                                   |" << endl;
					cout << "                                      |                                                                                   |" << endl;
					cout << "                                      |                                                                                   |" << endl;
					cout << "                                      |                         " << "\x1b[1;35m" << "   ____  _             _             " << "\x1b[1;37m" << "                     |" << endl;
					cout << "                                      |                         " << "\x1b[1;35m" << "  |  _ \\| | __ _ _ __ | |_ ___      " << "\x1b[1;37m" << "                      |" << endl;
					cout << "                                      |                         " << "\x1b[1;35m" << "  | |_) | |/ _` | '_ \\| __/ __|     " << "\x1b[1;37m" << "                      |" << endl;
					cout << "                                      |                         " << "\x1b[1;35m" << "  |  __/| | (_| | | | | |_\\__ \\     " << "\x1b[1;37m" << "                      |" << endl;
					cout << "                                      |                         " << "\x1b[1;35m" << "  |_|   |_|\\__,_|_| |_|\\__|___/    " << "\x1b[1;37m" << "                       |" << endl;
				}

				void secondButton()
				{
					cout << "                                      |                                                                                   |" << endl;
					cout << "                                      |                                                                                   |" << endl;
					cout << "                                      |                      " << "\x1b[1;35m" << "    _          _                 _            " << "\x1b[1;37m" << "               |" << endl;
					cout << "                                      |                      " << "\x1b[1;35m" << "   / \\   _ __ (_)_ __ ___   __ _| |___       " << "\x1b[1;37m" << "                |" << endl;
					cout << "                                      |                      " << "\x1b[1;35m" << "  / _ \\ | '_ \\| | '_ ` _ \\ / _` | / __|    " << "\x1b[1;37m" << "                  |" << endl;
					cout << "                                      |                      " << "\x1b[1;35m" << " / ___ \\| | | | | | | | | | (_| | \\__ \\    " << "\x1b[1;37m" << "                  |" << endl;
					cout << "                                      |                      " << "\x1b[1;35m" << "/_/   \\_\\_| |_|_|_| |_| |_|\\__,_|_|___/    " << "\x1b[1;37m" << "                  |" << endl;
					cout << "                                      |                                                                                   |" << endl;
					cout << "                                      |                                                                                   |" << endl;
					cout << "                                      |                                                                                   |" << endl;
					cout << "                                      |___________________________________________________________________________________|" << endl;
				}
			}

			//Display inactive buttons
			namespace inactiveButtons
			{
				void firstButton()
				{
					cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
					cout << "                                      _____________________________________________________________________________________" << endl;
					cout << "                                      |                                                                                   |" << endl;
					cout << "                                      |                                                                                   |" << endl;
					cout << "                                      |                                                                                   |" << endl;
					cout << "                                      |                            ____  _             _                                  |" << endl;
					cout << "                                      |                           |  _ \\| | __ _ _ __ | |_ ___                            |" << endl;
					cout << "                                      |                           | |_) | |/ _` | '_ \\| __/ __|                           |" << endl;
					cout << "                                      |                           |  __/| | (_| | | | | |_\\__ \\                           |" << endl;
					cout << "                                      |                           |_|   |_|\\__,_|_| |_|\\__|___/                           |" << endl;
				}

				void secondButton()
				{
					cout << "                                      |                                                                                   |" << endl;
					cout << "                                      |                                                                                   |" << endl;
					cout << "                                      |                          _          _                 _                           |" << endl;
					cout << "                                      |                         / \\   _ __ (_)_ __ ___   __ _| |___                       |" << endl;
					cout << "                                      |                        / _ \\ | '_ \\| | '_ ` _ \\ / _` | / __|                      |" << endl;
					cout << "                                      |                       / ___ \\| | | | | | | | | | (_| | \\__ \\                      |" << endl;
					cout << "                                      |                      /_/   \\_\\_| |_|_|_| |_| |_|\\__,_|_|___/                      |" << endl;
					cout << "                                      |                                                                                   |" << endl;
					cout << "                                      |                                                                                   |" << endl;
					cout << "                                      |                                                                                   |" << endl;
					cout << "                                      |___________________________________________________________________________________|" << endl;
				}
			}

			//Output menu according to active button
			void outputMenuWithFirstActiveButton()
			{
				activeButtons::firstButton();
				inactiveButtons::secondButton();
			}

			void outputMenuWithSecondActiveButton()
			{
				inactiveButtons::firstButton();
				activeButtons::secondButton();
			}
		}

		namespace adminPanel
		{
			//Display active buttons
			namespace activeButtons
			{
				void firstButton()
				{
					cout << endl << endl << endl << endl;
					cout << "                         ______________________________________________________________________________________________________________" << endl;
					cout << "                         |                                                                                                            |" << endl;
					cout << "                         |                                                                                                            |" << endl;
					cout << "                         |                    " << "\x1b[0;33m" << "      _       _           _                                 _           " << "\x1b[1;37m" << "                |" << endl;
					cout << "                         |                    " << "\x1b[0;33m" << "     / \\   __| |_ __ ___ (_)_ __     _ __   __ _ _ __   ___| |         " << "\x1b[1;37m" << "                 |" << endl;
					cout << "                         |                    " << "\x1b[0;33m" << "    / _ \\ / _` | '_ ` _ \\| | '_ \\   | '_ \\ / _` | '_ \\ / _ \\ |    " << "\x1b[1;37m" << "                      |" << endl;
					cout << "                         |                    " << "\x1b[0;33m" << "   / ___ \\ (_| | | | | | | | | | |  | |_) | (_| | | | |  __/ |         " << "\x1b[1;37m" << "                 |" << endl;
					cout << "                         |                    " << "\x1b[0;33m" << "  /_/   \\_\\__,_|_| |_| |_|_|_| |_|  | .__/ \\__,_|_| |_|\\___|_|      " << "\x1b[1;37m" << "                    |" << endl;
					cout << "                         |                    " << "\x1b[0;33m" << "                                    |_|                                 " << "\x1b[1;37m" << "                |" << endl;
					cout << "                         |                                                                                                            |" << endl;
					cout << "                         |                                                                                                            |" << endl;
					cout << "                         |                                                                                                            |" << endl;
					cout << "                         |                                                                                                            |" << endl;
					cout << "                         |                                       " << "\x1b[1;34m" << "    __________________    " << "\x1b[1;37m" << "                                           |" << endl;
					cout << "                         |                                       " << "\x1b[1;34m" << "   /                  \\  " << "\x1b[1;37m" << "                                            |" << endl;
					cout << "                         |                                       " << "\x1b[1;34m" << "  {  View information  }  " << "\x1b[1;37m" << "                                           |" << endl;
					cout << "                         |                                       " << "\x1b[1;34m" << "   \\__________________/  " << "\x1b[1;37m" << "                                            |" << endl;
				}

				void secondButton()
				{
					cout << "                         |                                                                                                            |" << endl;
					cout << "                         |                                                                                                            |" << endl;
					cout << "                         |                                       " << "\x1b[1;34m" << "    __________________    " << "\x1b[1;37m" << "                                           |" << endl;
					cout << "                         |                                       " << "\x1b[1;34m" << "   /                  \\  " << "\x1b[1;37m" << "                                            |" << endl;
					cout << "                         |                                       " << "\x1b[1;34m" << "  {        Edit        }  " << "\x1b[1;37m" << "                                           |" << endl;
					cout << "                         |                                       " << "\x1b[1;34m" << "   \\__________________/  " << "\x1b[1;37m" << "                                            |" << endl;
				}

				void thirdButton()
				{
					cout << "                         |                                                                                                            |" << endl;
					cout << "                         |                                                                                                            |" << endl;
					cout << "                         |                                       " << "\x1b[1;34m" << "    __________________    " << "\x1b[1;37m" << "                                           |" << endl;
					cout << "                         |                                       " << "\x1b[1;34m" << "   /                  \\  " << "\x1b[1;37m" << "                                            |" << endl;
					cout << "                         |                                       " << "\x1b[1;34m" << "  {       Add new      }  " << "\x1b[1;37m" << "                                           |" << endl;
					cout << "                         |                                       " << "\x1b[1;34m" << "   \\__________________/  " << "\x1b[1;37m" << "                                            |" << endl;
				}

				void fourthButton()
				{
					cout << "                         |                                                                                                            |" << endl;
					cout << "                         |                                                                                                            |" << endl;
					cout << "                         |                                       " << "\x1b[1;34m" << "    __________________    " << "\x1b[1;37m" << "                                           |" << endl;
					cout << "                         |                                       " << "\x1b[1;34m" << "   /                  \\  " << "\x1b[1;37m" << "                                            |" << endl;
					cout << "                         |                                       " << "\x1b[1;34m" << "  {       Remove       }  " << "\x1b[1;37m" << "                                           |" << endl;
					cout << "                         |                                       " << "\x1b[1;34m" << "   \\__________________/  " << "\x1b[1;37m" << "                                            |" << endl;
				}

				void fifthButton()
				{
					cout << "                         |                                                                                                            |" << endl;
					cout << "                         |                                                                                                            |" << endl;
					cout << "                         |                                       " << "\x1b[1;34m" << "    __________________    " << "\x1b[1;37m" << "                                           |" << endl;
					cout << "                         |                                       " << "\x1b[1;34m" << "   /                  \\  " << "\x1b[1;37m" << "                                            |" << endl;
					cout << "                         |                                       " << "\x1b[1;34m" << "  {        Exit        }  " << "\x1b[1;37m" << "                                           |" << endl;
					cout << "                         |                                       " << "\x1b[1;34m" << "   \\__________________/  " << "\x1b[1;37m" << "                                            |" << endl;
					cout << "                         |                                                                                                            |" << endl;
					cout << "                         |                                                                                                            |" << endl;
					cout << "                         |                                                                                                            |" << endl;
					cout << "                         |____________________________________________________________________________________________________________|" << endl;
				}
			}

			//Display inactive buttons
			namespace inactiveButtons
			{
				void firstButton()
				{
					cout << endl << endl << endl << endl;
					cout << "                         ______________________________________________________________________________________________________________" << endl;
					cout << "                         |                                                                                                            |" << endl;
					cout << "                         |                                                                                                            |" << endl;
					cout << "                         |                    " << "\x1b[0;33m" << "      _       _           _                                 _           " << "\x1b[1;37m" << "                |" << endl;
					cout << "                         |                    " << "\x1b[0;33m" << "     / \\   __| |_ __ ___ (_)_ __     _ __   __ _ _ __   ___| |         " << "\x1b[1;37m" << "                 |" << endl;
					cout << "                         |                    " << "\x1b[0;33m" << "    / _ \\ / _` | '_ ` _ \\| | '_ \\   | '_ \\ / _` | '_ \\ / _ \\ |    " << "\x1b[1;37m" << "                      |" << endl;
					cout << "                         |                    " << "\x1b[0;33m" << "   / ___ \\ (_| | | | | | | | | | |  | |_) | (_| | | | |  __/ |         " << "\x1b[1;37m" << "                 |" << endl;
					cout << "                         |                    " << "\x1b[0;33m" << "  /_/   \\_\\__,_|_| |_| |_|_|_| |_|  | .__/ \\__,_|_| |_|\\___|_|      " << "\x1b[1;37m" << "                    |" << endl;
					cout << "                         |                    " << "\x1b[0;33m" << "                                    |_|                                 " << "\x1b[1;37m" << "                |" << endl;
					cout << "                         |                                                                                                            |" << endl;
					cout << "                         |                                                                                                            |" << endl;
					cout << "                         |                                                                                                            |" << endl;
					cout << "                         |                                                                                                            |" << endl;
					cout << "                         |                                           __________________                                               |" << endl;
					cout << "                         |                                          /                  \\                                              |" << endl;
					cout << "                         |                                         {  View information  }                                             |" << endl;
					cout << "                         |                                          \\__________________/                                              |" << endl;
				}

				void secondButton()
				{
					cout << "                         |                                                                                                            |" << endl;
					cout << "                         |                                                                                                            |" << endl;
					cout << "                         |                                           __________________                                               |" << endl;
					cout << "                         |                                          /                  \\                                              |" << endl;
					cout << "                         |                                         {        Edit        }                                             |" << endl;
					cout << "                         |                                          \\__________________/                                              |" << endl;
				}

				void thirdButton()
				{
					cout << "                         |                                                                                                            |" << endl;
					cout << "                         |                                                                                                            |" << endl;
					cout << "                         |                                           __________________                                               |" << endl;
					cout << "                         |                                          /                  \\                                              |" << endl;
					cout << "                         |                                         {       Add new      }                                             |" << endl;
					cout << "                         |                                          \\__________________/                                              |" << endl;
				}

				void fourthButton()
				{
					cout << "                         |                                                                                                            |" << endl;
					cout << "                         |                                                                                                            |" << endl;
					cout << "                         |                                           __________________                                               |" << endl;
					cout << "                         |                                          /                  \\                                              |" << endl;
					cout << "                         |                                         {       Remove       }                                             |" << endl;
					cout << "                         |                                          \\__________________/                                              |" << endl;
				}

				void fifthButton()
				{
					cout << "                         |                                                                                                            |" << endl;
					cout << "                         |                                                                                                            |" << endl;
					cout << "                         |                                           __________________                                               |" << endl;
					cout << "                         |                                          /                  \\                                              |" << endl;
					cout << "                         |                                         {        Exit        }                                             |" << endl;
					cout << "                         |                                          \\__________________/                                              |" << endl;
					cout << "                         |                                                                                                            |" << endl;
					cout << "                         |                                                                                                            |" << endl;
					cout << "                         |                                                                                                            |" << endl;
					cout << "                         |____________________________________________________________________________________________________________|" << endl;
				}
			}

			//Output menu according to active button
			void outputMenuWithFirstActiveButton()
			{
				activeButtons::firstButton();
				inactiveButtons::secondButton();
				inactiveButtons::thirdButton();
				inactiveButtons::fourthButton();
				inactiveButtons::fifthButton();
			}

			void outputMenuWithSecondActiveButton()
			{
				inactiveButtons::firstButton();
				activeButtons::secondButton();
				inactiveButtons::thirdButton();
				inactiveButtons::fourthButton();
				inactiveButtons::fifthButton();
			}

			void outputMenuWithThirdActiveButton()
			{
				inactiveButtons::firstButton();
				inactiveButtons::secondButton();
				activeButtons::thirdButton();
				inactiveButtons::fourthButton();
				inactiveButtons::fifthButton();
			}

			void outputMenuWithFourthActiveButton()
			{
				inactiveButtons::firstButton();
				inactiveButtons::secondButton();
				inactiveButtons::thirdButton();
				activeButtons::fourthButton();
				inactiveButtons::fifthButton();
			}

			void outputMenuWithFifthActiveButton()
			{
				inactiveButtons::firstButton();
				inactiveButtons::secondButton();
				inactiveButtons::thirdButton();
				inactiveButtons::fourthButton();
				activeButtons::fifthButton();
			}
		}
	}

	bool menuInputs::adminPanel();

	namespace registrationForm
	{
		namespace outputEntryWindows
		{
			//Output login admin panel
			void loginAsAdmin()
			{
				cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
				cout << "                          __________________________________________________________________________________________________________" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |               _                  ___                               _           _                       |" << endl;
				cout << "                          |              | |    ___   __ _  |_ _|_ __     __ _ ___    __ _  __| |_ __ ___ (_)_ __                  |" << endl;
				cout << "                          |              | |   / _ \\ / _` |  | || '_ \\   / _` / __|  / _` |/ _` | '_ ` _ \\| | '_ \\                 |" << endl;
				cout << "                          |              | |__| (_) | (_| |  | || | | | | (_| \\__ \\ | (_| | (_| | | | | | | | | | |                |" << endl;
				cout << "                          |              |_____\\___/ \\__, | |___|_| |_|  \\__,_|___/  \\__,_|\\__,_|_| |_| |_|_|_| |_|                |" << endl;
				cout << "                          |                          |___/                                                                         |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                  Username :                                                            |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                  Password :                                                            |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |________________________________________________________________________________________________________|" << endl;
			}

			//Output login player panel
			void loginAsPlayer()
			{
				cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
				cout << "                          __________________________________________________________________________________________________________" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |               _                  ___                           _                                       |" << endl;
				cout << "                          |              | |    ___   __ _  |_ _|_ __     __ _ ___   _ __ | | __ _ _   _  ___ _ __                 |" << endl;
				cout << "                          |              | |   / _ \\ / _` |  | || '_ \\   / _` / __| | '_ \\| |/ _` | | | |/ _ \\ '__|                |" << endl;
				cout << "                          |              | |__| (_) | (_| |  | || | | | | (_| \\__ \\ | |_) | | (_| | |_| |  __/ |                   |" << endl;
				cout << "                          |              |_____\\___/ \\__, | |___|_| |_|  \\__,_|___/ | .__/|_|\\__,_|\\__, |\\___|_|                   |" << endl;
				cout << "                          |                          |___/                          |_|            |___/                           |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                  Username :                                                            |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                  Password :                                                            |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |________________________________________________________________________________________________________|" << endl;
			}

			//Output registration panel
			void registration()
			{
				cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
				cout << "                          __________________________________________________________________________________________________________" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                       ____            _     _             _   _                                        |" << endl;
				cout << "                          |                      |  _ \\ ___  __ _(_)___| |_ _ __ __ _| |_(_) ___  _ __                             |" << endl;
				cout << "                          |                      | |_) / _ \\/ _` | / __| __| '__/ _` | __| |/ _ \\| '_ \\                            |" << endl;
				cout << "                          |                      |  _ <  __/ (_| | \\__ \\ |_| | | (_| | |_| | (_) | | | |                           |" << endl;
				cout << "                          |                      |_| \\_\\___|\\__, |_|___/\\__|_|  \\__,_|\\__|_|\\___/|_| |_|                           |" << endl;
				cout << "                          |                                 |___/                                                                  |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                  Username :                                                            |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                  Password :                                                            |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |________________________________________________________________________________________________________|" << endl;
			}

			//Output change password panel
			void checkPassword()
			{
				cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
				cout << "                          __________________________________________________________________________________________________________" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |             ____ _                                                                        _            |" << endl;
				cout << "                          |            / ___| |__   __ _ _ __   __ _  ___   _ __   __ _ ___ _____      _____  _ __ __| |           |" << endl;
				cout << "                          |           | |   | '_ \\ / _` | '_ \\ / _` |/ _ \\ | '_ \\ / _` / __/ __\\ \\ /\\ / / _ \\| '__/ _` |           |" << endl;
				cout << "                          |           | |___| | | | (_| | | | | (_| |  __/ | |_) | (_| \\__ \\__ \\\\ V  V / (_) | | | (_| |           |" << endl;
				cout << "                          |            \\____|_| |_|\\__,_|_| |_|\\__, |\\___| | .__/ \\__,_|___/___/ \\_/\\_/ \\___/|_|  \\__,_|           |" << endl;
				cout << "                          |                                    |___/       |_|                                                     |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                         Enter your username :                                                          |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                         Your password is :                                                             |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                         Enter the new password :                                                       |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |________________________________________________________________________________________________________|" << endl;
			}

			//Output successfully login panel
			void successfullyLogin()
			{
				cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
				cout << "                          __________________________________________________________________________________________________________" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                             __   __            _           _                                           |" << endl;
				cout << "                          |                             \\ \\ / /__ _  _    | |___  __ _(_)_ _                                       |" << endl;
				cout << "                          |                              \\ V / _ \\ || |   | / _ \\/ _` | | ' \\                                      |" << endl;
				cout << "                          |                               |_|\\___/\\_,_|   |_\\___/\\__, |_|_||_|                                     |" << endl;
				cout << "                          |                                                      |___/                                             |" << endl;
				cout << "                          |                                                   __      _ _         _                                |" << endl;
				cout << "                          |                          ____  _ __ __ ___ ______/ _|_  _| | |_  _   | |                               |" << endl;
				cout << "                          |                         (_-< || / _/ _/ -_|_-<_-<  _| || | | | || |  |_|                               |" << endl;
				cout << "                          |                         /__/\\_,_\\__\\__\\___/__/__/_|  \\_,_|_|_|\\_, |  (_)                               |" << endl;
				cout << "                          |                                                               |__/                                     |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |________________________________________________________________________________________________________|" << endl;
			}

			//Output successfully register panel
			void succcessfullyRegister()
			{
				cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
				cout << "                          __________________________________________________________________________________________________________" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                        __   __                        _    _                                           |" << endl;
				cout << "                          |                        \\ \\ / /__ _  _    _ _ ___ __ _(_)__| |_ ___ _ _                                 |" << endl;
				cout << "                          |                         \\ V / _ \\ || |  | '_/ -_) _` | (_-<  _/ -_) '_|                                |" << endl;
				cout << "                          |                          |_|\\___/\\_,_|  |_| \\___\\__, |_/__/\\__\\___|_|                                  |" << endl;
				cout << "                          |                                                 |___/                                                  |" << endl;
				cout << "                          |                                                  __      _ _         _                                 |" << endl;
				cout << "                          |                         ____  _ __ __ ___ ______/ _|_  _| | |_  _   | |                                |" << endl;
				cout << "                          |                        (_-< || / _/ _/ -_|_-<_-<  _| || | | | || |  |_|                                |" << endl;
				cout << "                          |                        /__/\\_,_\\__\\__\\___/__/__/_|  \\_,_|_|_|\\_, |  (_)                                |" << endl;
				cout << "                          |                                                              |__/                                      |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |________________________________________________________________________________________________________|" << endl;
			}

			//Output try again panel
			void tryAgain()
			{
				cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
				cout << "                          __________________________________________________________________________________________________________" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                            _____                          _        _                                   |" << endl;
				cout << "                          |                           |_   _| _ _  _   __ _ __ _ __ _(_)_ _   | |                                  |" << endl;
				cout << "                          |                             | || '_| || | / _` / _` / _` | | ' \\  |_|                                  |" << endl;
				cout << "                          |                             |_||_|  \\_, | \\__,_\\__, \\__,_|_|_||_| (_)                                  |" << endl;
				cout << "                          |                                     |__/       |___/                                                   |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |                                                                                                        |" << endl;
				cout << "                          |________________________________________________________________________________________________________|" << endl;
			}

			//Output How to play panel
			void howToPlay()
			{
				cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
				cout << "                          ______________________________________________________________________________________________________________" << endl;
				cout << "                         |                                                                                                             |" << endl;
				cout << "                         |                                                                                                             |" << endl;
				cout << "                         |                                                                                                             |" << endl;
				cout << "                         |                      " << "\x1b[0;33m" << "   _   _                  _                 _                        " << "\x1b[0;37m" << "                  |" << endl;
				cout << "                         |                      " << "\x1b[0;33m" << "  | | | | _____      __  | |_ ___     _ __ | | __ _ _   _            " << "\x1b[0;37m" << "                  |" << endl;
				cout << "                         |                      " << "\x1b[0;33m" << "  | |_| |/ _ \\ \\ /\\ / /  | __/ _ \\   | '_ \\| |/ _` | | | |      " << "\x1b[0;37m" << "                       |" << endl;
				cout << "                         |                      " << "\x1b[0;33m" << "  |  _  | (_) \\ V  V /   | || (_) |  | |_) | | (_| | |_| |          " << "\x1b[0;37m" << "                   |" << endl;
				cout << "                         |                      " << "\x1b[0;33m" << "  |_| |_|\\___/ \\_/\\_/     \\__\\___/   | .__/|_|\\__,_|\\__, |    " << "\x1b[0;37m" << "                         |" << endl;
				cout << "                         |                      " << "\x1b[0;33m" << "                                     |_|            |___/            " << "\x1b[0;37m" << "                  |" << endl;
				cout << "                         |                                                                                                             |" << endl;
				cout << "                         |                                                                                                             |" << endl;
				cout << "                         |                                                                                                             |" << endl;
				cout << "                         |                                                                                                             |" << endl;
				cout << "                         |  1. When you choose to play the game, there will be shown a guide, who tells you the story of the game.     |" << endl;
				cout << "                         |                                                                                                             |" << endl;
				cout << "                         |  2. Then you have to read what this guide tells you to do.                                                  |" << endl;
				cout << "                         |                                                                                                             |" << endl;
				cout << "                         |  3. When you reach the meteor storm, you have to learn some things about plants and animals.                |" << endl;
				cout << "                         |                                                                                                             |" << endl;
				cout << "                         |  4. After that you have to make a quiz, so you can destroy the meteors.                                     |" << endl;
				cout << "                         |                                                                                                             |" << endl;
				cout << "                         |  5. Then you will reach the planet and you have to breed animals and seed plants, so you can survive there. |" << endl;
				cout << "                         |                                                                                                             |" << endl;
				cout << "                         |                                                                                                             |" << endl;
				cout << "                         |                                                                                                             |" << endl;
				cout << "                         |_____________________________________________________________________________________________________________|" << endl;
			}
		}

		bool menuInputs::playMenu(string username);

		//Function for login as admin
		void loginAsAdmin()
		{
			string username;
			string password;
			outputEntryWindows::loginAsAdmin();
			bp::tools::consoleCoordinates(72, 29);
			getline(cin, username);
			bp::tools::consoleCoordinates(72, 32);
			getline(cin, password);
			if (username == "admin" && password == "adminpass")
			{
				system("ClS");
				outputEntryWindows::successfullyLogin();
				Sleep(900);
				menuInputs::adminPanel();
			}
			else
			{
				system("ClS");
				outputEntryWindows::tryAgain();
			}
		}
	}

	namespace menuInputs
	{
		// Menu input for main menu
		bool menu()
		{
			bp::tools::setConsoleSize();
			int choice;
			string username;
			system("CLS");
			menus::registrationFormMenu::outputMenuWithFirstActiveButton();
			choice = 1;
			while (true) {
				switch (_getch()) {
				case KEY_UP:
					switch (choice)
					{
					case 1:
					{
						system("CLS");
						menus::registrationFormMenu::outputMenuWithFifthActiveButton();
						choice = 5;
						break;
					}
					case 2:
					{
						system("CLS");
						menus::registrationFormMenu::outputMenuWithFirstActiveButton();
						choice = 1;
						break;
					}
					case 3:
					{
						system("CLS");
						menus::registrationFormMenu::outputMenuWithSecondActiveButton();
						choice = 2;
						break;
					}
					case 4:
					{
						system("CLS");
						menus::registrationFormMenu::outputMenuWithThirdActiveButton();
						choice = 3;
						break;
					}
					case 5:
					{
						system("CLS");
						menus::registrationFormMenu::outputMenuWithFourthActiveButton();
						choice = 4;
						break;
					}
					}
					break;
				case KEY_DOWN:
					switch (choice)
					{
					case 1:
					{
						system("CLS");
						menus::registrationFormMenu::outputMenuWithSecondActiveButton();
						choice = 2;
						break;
					}
					case 2:
					{
						system("CLS");
						menus::registrationFormMenu::outputMenuWithThirdActiveButton();
						choice = 3;
						break;
					}
					case 3:
					{
						system("CLS");
						menus::registrationFormMenu::outputMenuWithFourthActiveButton();
						choice = 4;
						break;
					}
					case 4:
					{
						system("CLS");
						menus::registrationFormMenu::outputMenuWithFifthActiveButton();
						choice = 5;
						break;
					}
					case 5:
					{
						system("CLS");
						menus::registrationFormMenu::outputMenuWithFirstActiveButton();
						choice = 1;
						break;
					}
					}
					break;
				case KEY_ENTER:
					switch (choice)
					{
					case 1:
					{
						system("CLS");
						registrationForm::loginAsAdmin();
						choice = 6;
						break;
					}
					case 2:
					{
						system("CLS");
						bp::dal::registrationForm::loginAsPlayer(&username);
						choice = 6;
						break;
					}
					case 3:
					{
						system("CLS");
						bp::dal::registrationForm::registrationPlayer();
						choice = 6;
						break;
					}
					case 4:
					{
						system("CLS");
						bp::dal::registrationForm::changePasswordPlayer();
						choice = 6;
						break;
					}
					case 5:
					{
						exit(0);
						return 0;
						break;
					}
					case 6:
					{
						system("CLS");
						menus::registrationFormMenu::outputMenuWithFirstActiveButton();
						choice = 1;
						break;
					}
					}
					break;
				default:
					break;
				}
			}
		}

		bool viewInformation();
		bool editInformation(bp::type::characteristics::PLANTS* headPlants, bp::type::characteristics::ANIMAL* headAnimals);
		bool addNewInformation(bp::type::characteristics::PLANTS* headPlants, bp::type::characteristics::ANIMAL* headAnimals);
		bool removeInformation(bp::type::characteristics::PLANTS* headPlants, bp::type::characteristics::ANIMAL* headAnimals);

		// Menu input for admin panel
		bool adminPanel()
		{

			bp::type::characteristics::ANIMAL* headAnimals = new  bp::type::characteristics::ANIMAL;
			bp::type::characteristics::PLANTS* headPlants = new  bp::type::characteristics::PLANTS;

			headAnimals = bp::dal::workWithFiles::fromFileToAnimalsList(headAnimals);
			headPlants = bp::dal::workWithFiles::fromFileToPlantsList(headPlants);

			if (headAnimals != NULL)
			{
				headPlants = bp::bll::biologyContent::deleteFirstPlants(headPlants);
				headAnimals = bp::bll::biologyContent::deleteFirstAnimal(headAnimals);
			}
			int choice;
			system("CLS");
			menus::adminPanel::outputMenuWithFirstActiveButton();
			choice = 1;
			while (true) {
				switch (_getch()) {
				case KEY_UP:
					switch (choice)
					{
					case 1:
					{
						system("CLS");
						menus::adminPanel::outputMenuWithFifthActiveButton();
						choice = 5;
						break;
					}
					case 2:
					{
						system("CLS");
						menus::adminPanel::outputMenuWithFirstActiveButton();
						choice = 1;
						break;
					}
					case 3:
					{
						system("CLS");
						menus::adminPanel::outputMenuWithSecondActiveButton();
						choice = 2;
						break;
					}
					case 4:
					{
						system("CLS");
						menus::adminPanel::outputMenuWithThirdActiveButton();
						choice = 3;
						break;
					}
					case 5:
					{
						system("CLS");
						menus::adminPanel::outputMenuWithFourthActiveButton();
						choice = 4;
						break;
					}
					}
					break;
				case KEY_DOWN:
					switch (choice)
					{
					case 1:
					{
						system("CLS");
						menus::adminPanel::outputMenuWithSecondActiveButton();
						choice = 2;
						break;
					}
					case 2:
					{
						system("CLS");
						menus::adminPanel::outputMenuWithThirdActiveButton();
						choice = 3;
						break;
					}
					case 3:
					{
						system("CLS");
						menus::adminPanel::outputMenuWithFourthActiveButton();
						choice = 4;
						break;
					}
					case 4:
					{
						system("CLS");
						menus::adminPanel::outputMenuWithFifthActiveButton();
						choice = 5;
						break;
					}
					case 5:
					{
						system("CLS");
						menus::adminPanel::outputMenuWithFirstActiveButton();
						choice = 1;
						break;
					}
					}
					break;
				case KEY_ENTER:
					switch (choice)
					{
					case 1:
					{
						system("CLS");
						viewInformation();
						choice = 6;
						break;
					}
					case 2:
					{
						editInformation(headPlants, headAnimals);
						choice = 6;
						break;
					}
					case 3:
					{
						addNewInformation(headPlants, headAnimals);
						choice = 6;
						break;
					}
					case 4:
					{
						removeInformation(headPlants, headAnimals);
						choice = 6;
						break;
					}
					case 5:
					{
						return 0;
						break;
					}
					case 6:
					{
						system("CLS");
						menus::adminPanel::outputMenuWithFirstActiveButton();
						choice = 1;
						break;
					}
					}
					break;
				default:
					break;
				}
			}
		}

		bool plantsAnimalsAndQuizMenu();
		bool plantsAndAnimalsMenu();

		// Menu input for play menu (second menu)
		bool playMenu(string username)
		{

			bp::tools::setConsoleSize();
			int choice;
			system("CLS");
			menus::playMenu::outputMenuWithFirstActiveButton();
			choice = 1;
			while (true) {
				switch (_getch()) {
				case KEY_UP:
					switch (choice)
					{
					case 1:
					{
						system("CLS");
						menus::playMenu::outputMenuWithThirdActiveButton();
						choice = 3;
						break;
					}
					case 2:
					{
						system("CLS");
						menus::playMenu::outputMenuWithFirstActiveButton();
						choice = 1;
						break;
					}
					case 3:
					{
						system("CLS");
						menus::playMenu::outputMenuWithSecondActiveButton();
						choice = 2;
						break;
					}
					}
					break;
				case KEY_DOWN:
					switch (choice)
					{
					case 1:
					{
						system("CLS");
						menus::playMenu::outputMenuWithSecondActiveButton();
						choice = 2;
						break;
					}
					case 2:
					{
						system("CLS");
						menus::playMenu::outputMenuWithThirdActiveButton();
						choice = 3;
						break;
					}
					case 3:
					{
						system("CLS");
						menus::playMenu::outputMenuWithFirstActiveButton();
						choice = 1;
						break;
					}
					}
					break;
				case KEY_ENTER:
					switch (choice)
					{
					case 1:
					{
						Sleep(200);
						system("CLS");
						bp::type::frames::FRAME animationFrame;
						bp::dal::frames::readFrameFromFile(&animationFrame);
						frames::output::zeroFrame(username);
						frames::output::firstFrame(animationFrame);
						frames::output::secondFrame(animationFrame);
						frames::output::thirdFrame(animationFrame);
						frames::output::fourthFrame(animationFrame);
						frames::output::fifthFrame(animationFrame);
						frames::output::sixthFrame();
						plantsAnimalsAndQuizMenu();
						choice = 4;
						break;
					}
					case 2:
					{
						system("CLS");
						registrationForm::outputEntryWindows::howToPlay();
						choice = 4;
						break;
					}
					case 3:
					{
						return 0;
						break;
					}
					case 4:
					{
						system("CLS");
						choice = 1;
						menus::playMenu::outputMenuWithFirstActiveButton();
						break;
					}
					}
					break;
				default:
					break;
				}
			}
		}

		bool animalsMenu();
		bool plantsMenu();
		bool breedingMenuInput();
		bool seedingMenuInput();

		// Menu input for choosing plants or animals information
		bool plantsAndAnimalsMenu()
		{
			int choice;
			system("CLS");
			menus::choosePlantsOrAnimalsMenu::outputMenuWithFirstActiveButton();
			choice = 1;
			while (true) {
				switch (_getch()) {
				case KEY_UP:
					switch (choice)
					{
					case 1:
					{
						system("CLS");
						menus::choosePlantsOrAnimalsMenu::outputMenuWithSecondActiveButton();
						choice = 2;
						break;
					}
					case 2:
					{
						system("CLS");
						menus::choosePlantsOrAnimalsMenu::outputMenuWithFirstActiveButton();
						choice = 1;
						break;
					}
					}
					break;
				case KEY_DOWN:
					switch (choice)
					{
					case 1:
					{
						system("CLS");
						menus::choosePlantsOrAnimalsMenu::outputMenuWithSecondActiveButton();
						choice = 2;
						break;
					}
					case 2:
					{
						system("CLS");
						menus::choosePlantsOrAnimalsMenu::outputMenuWithFirstActiveButton();
						choice = 1;
						break;
					}
					}
					break;
				case KEY_ENTER:
					switch (choice)
					{
					case 1:
					{
						seedingMenuInput();
						system("CLS");
						choice = 3;
						break;
					}
					case 2:
					{
						breedingMenuInput();
						system("CLS");
						choice = 3;
						break;
					}
					case 3:
					{
						system("CLS");
						choice = 1;
						menus::choosePlantsOrAnimalsMenu::outputMenuWithFirstActiveButton();
						break;
					}
					}
					break;
				default:
					break;
				}
			}
		}

		// Menu input for choosing plants or animals information witn exit option
		bool viewInformation()
		{
			int choice;
			system("CLS");
			menus::choosePlantsOrAnimalsWithExitMenu::outputMenuWithFirstActiveButton();
			choice = 1;
			while (true) {
				switch (_getch()) {
				case KEY_UP:
					switch (choice)
					{
					case 1:
					{
						system("CLS");
						menus::choosePlantsOrAnimalsWithExitMenu::outputMenuWithThirdActiveButton();
						choice = 3;
						break;
					}
					case 2:
					{
						system("CLS");
						menus::choosePlantsOrAnimalsWithExitMenu::outputMenuWithFirstActiveButton();
						choice = 1;
						break;
					}
					case 3:
					{
						system("CLS");
						menus::choosePlantsOrAnimalsWithExitMenu::outputMenuWithSecondActiveButton();
						choice = 2;
						break;
					}
					}
					break;
				case KEY_DOWN:
					switch (choice)
					{
					case 1:
					{
						system("CLS");
						menus::choosePlantsOrAnimalsWithExitMenu::outputMenuWithSecondActiveButton();
						choice = 2;
						break;
					}
					case 2:
					{
						system("CLS");
						menus::choosePlantsOrAnimalsWithExitMenu::outputMenuWithThirdActiveButton();
						choice = 3;
						break;
					}
					case 3:
					{
						system("CLS");
						menus::choosePlantsOrAnimalsWithExitMenu::outputMenuWithFirstActiveButton();
						choice = 1;
						break;
					}
					}
					break;
				case KEY_ENTER:
					switch (choice)
					{
					case 1:
					{
						system("CLS");
						plantsMenu();
						choice = 4;
						break;
					}
					case 2:
					{
						system("CLS");
						animalsMenu();
						choice = 4;
						break;
					}
					case 3:
					{
						return 0;
						break;
					}
					case 4:
					{
						system("CLS");
						choice = 1;
						menus::choosePlantsOrAnimalsWithExitMenu::outputMenuWithFirstActiveButton();
						break;
					}
					}
					break;
				default:
					break;
				}
			}
		}

		//Inputs plants information with skip options
		void inputPlantsData(bp::type::characteristics::PLANTS* headPlants, int index)
		{
			string strPlant[7] = { "Name: ","Phylum: ","Class: ", "Order: ", "Family: ",
								   "Genus: ", "Species: " };
			string strUpdatePlants[7];
			int n = 0;
			quiz::outputBorder(0);
			bp::tools::consoleCoordinates(55, 15);
			cout << "If you don't want to change information type 'x'";
			for (size_t i = 0; i < 6; i++)
			{
				bp::tools::consoleCoordinates(55, 19 + n);
				cout << strPlant[i];
				cin >> strUpdatePlants[i];
				n += 2;
			}
			bp::bll::biologyContent::updatePlant(headPlants, strUpdatePlants, index);
			bp::dal::workWithFiles::fromPlantsListToFile(headPlants);
		}

		//Inputs animals information with skip options
		void inputAnimalsData(bp::type::characteristics::ANIMAL* headAnimals, int index)
		{
			string strAnimal[11] = { "Name: ","Phylum: ","Class: ", "Order: ",
									 "Family: ", "Genus: ", "Species: ", "Average high of male: ",
									 "Average high of female: ", "Average wieght of male: ", "Average wieght of female: " };
			string strUpdateAnimal[11];
			int n = 0;
			quiz::outputBorder(0);
			bp::tools::consoleCoordinates(55, 15);
			cout << "If you don't want to change information type 'x'";
			cin.ignore();
			for (size_t i = 0; i < 11; i++)
			{
				bp::tools::consoleCoordinates(55, 19 + n);
				cout << strAnimal[i];
				cin >> strUpdateAnimal[i];
				n += 2;
			}
			bp::bll::biologyContent::updateAnimal(headAnimals, strUpdateAnimal, index);
			 bp::dal::workWithFiles::fromAnimalsListToFile(headAnimals);
		}

		//Inputs plants information withouth skip options
		void inputNewPlantsData(bp::type::characteristics::PLANTS* headPlants)
		{
			string strPlant[7] = { "Name: ","Phylum: ","Class: ", "Order: ", "Family: ",
								   "Genus: ", "Species: " };
			string info[7], classification[6];
			int n = 0;
			cin.ignore();
			quiz::outputBorder(0);
			for (int i = 0; i < 7; i++)
			{
				bp::tools::consoleCoordinates(55, 17 + n);
				cout << strPlant[i];
				cin >> info[i];
				n += 2;
				if (i >= 1 && i <= 6)
				{
					classification[i - 1] = info[i];
				}
			}
			cout << endl;
			headPlants = bp::bll::biologyContent::prependNodePlants(info[0], headPlants, classification);
			bp::dal::workWithFiles::fromPlantsListToFile(headPlants);
		}

		//Inputs animals information withouth skip options
		void inputNewAnimalsData(bp::type::characteristics::ANIMAL* headAnimals)
		{
			string strAnimal[11] = { "Name: ","Phylum: ","Class: ", "Order: ",
									 "Family: ", "Genus: ", "Species: ", "Average high of male: ",
									 "Average high of female: ", "Average wieght of male: ", "Average wieght of female: "};
			string info[11], classification[6];
			int n = 0;
			quiz::outputBorder(0);
			for (int i = 0; i < 11; i++)
			{
				bp::tools::consoleCoordinates(55, 17 + n);
				cout << strAnimal[i];
				cin >> info[i];
				n += 2;
				if (i >= 1 && i <= 6)
				{
					classification[i - 1] = info[i];
				}
			}
			cout << endl;
			double high[2] = { bp::bll::biologyContent::checkForDouble(info[7]),bp::bll::biologyContent::checkForDouble(info[8]) };
			double weight[2] = { bp::bll::biologyContent::checkForDouble(info[9]),bp::bll::biologyContent::checkForDouble(info[10]) };
			headAnimals = bp::bll::biologyContent::prependNodeAnimal(info[0], headAnimals, classification, high, weight);
			bp::dal::workWithFiles::fromAnimalsListToFile(headAnimals);
		}

		//Function for editing plants and animals information
		bool editInformation(bp::type::characteristics::PLANTS* headPlants, bp::type::characteristics::ANIMAL* headAnimals)
		{
			int choice;
			system("CLS");
			menus::choosePlantsOrAnimalsWithExitMenu::outputMenuWithFirstActiveButton();
			choice = 1;
			int n = 0;
			int n1;
			while (true) {
				switch (_getch()) {
				case KEY_UP:
					switch (choice)
					{
					case 1:
					{
						system("CLS");
						menus::choosePlantsOrAnimalsWithExitMenu::outputMenuWithThirdActiveButton();
						choice = 3;
						break;
					}
					case 2:
					{
						system("CLS");
						menus::choosePlantsOrAnimalsWithExitMenu::outputMenuWithFirstActiveButton();
						choice = 1;
						break;
					}
					case 3:
					{
						system("CLS");
						menus::choosePlantsOrAnimalsWithExitMenu::outputMenuWithSecondActiveButton();
						choice = 2;
						break;
					}
					}
					break;
				case KEY_DOWN:
					switch (choice)
					{
					case 1:
					{
						system("CLS");
						menus::choosePlantsOrAnimalsWithExitMenu::outputMenuWithSecondActiveButton();
						choice = 2;
						break;
					}
					case 2:
					{
						system("CLS");
						menus::choosePlantsOrAnimalsWithExitMenu::outputMenuWithThirdActiveButton();
						choice = 3;
						break;
					}
					case 3:
					{
						system("CLS");
						menus::choosePlantsOrAnimalsWithExitMenu::outputMenuWithFirstActiveButton();
						choice = 1;
						break;
					}
					}
					break;
				case KEY_ENTER:
					switch (choice)
					{
					case 1:
					{
						system("CLS");
						if (bp::bll::biologyContent::numberOfAnimals(headAnimals) > 9)
						{
							quiz::outputBorder(bp::bll::biologyContent::numberOfAnimals(headAnimals) - 9);
						}
						else
						{
							quiz::outputBorder(0);
						}
						biologyContent::showInformation::displayPlants(headPlants, 70, 16);

						n = 0;
						while (true)
						{
							n1 = _getch();
							if (n1 != 13)
							{
								n *= 10;
								n += n1 - 48;
							}
							else
							{
								if (n != 0)
								{
									system("CLS");
									inputPlantsData(headPlants, n);
									system("CLS");
									break;
								}
							}
						}
						choice = 4;
						break;
					}
					case 2:
					{
						system("CLS");
						if (bp::bll::biologyContent::numberOfAnimals(headAnimals) > 9)
						{
							quiz::outputBorder(bp::bll::biologyContent::numberOfAnimals(headAnimals) - 9);
						}
						else
						{
							quiz::outputBorder(0);
						}
						biologyContent::showInformation::displayAnimals(headAnimals, 70, 16);
						n = 0;
						while (true)
						{
							n1 = _getch();
							if (n1 != 13)
							{
								n *= 10;
								n += n1 - 48;
							}
							else
							{
								if (n != 0)
								{
									system("CLS");
									inputAnimalsData(headAnimals, n);
									system("CLS");
									break;
								}
							}
						}

						system("CLS");
						choice = 4;
						break;
					}
					case 3:
					{
						return 0;
						break;
					}
					case 4:
					{
						system("CLS");
						choice = 1;
						menus::choosePlantsOrAnimalsWithExitMenu::outputMenuWithFirstActiveButton();
						break;
					}
					}
					break;
				default:
					break;
				}
			}
		}

		//Function for adding new informations
		bool addNewInformation(bp::type::characteristics::PLANTS* headPlants, bp::type::characteristics::ANIMAL* headAnimals)
		{
			int choice;
			system("CLS");
			menus::choosePlantsOrAnimalsWithExitMenu::outputMenuWithFirstActiveButton();
			choice = 1;
			while (true) {
				switch (_getch()) {
				case KEY_UP:
					switch (choice)
					{
					case 1:
					{
						system("CLS");
						menus::choosePlantsOrAnimalsWithExitMenu::outputMenuWithThirdActiveButton();
						choice = 3;
						break;
					}
					case 2:
					{
						system("CLS");
						menus::choosePlantsOrAnimalsWithExitMenu::outputMenuWithFirstActiveButton();
						choice = 1;
						break;
					}
					case 3:
					{
						system("CLS");
						menus::choosePlantsOrAnimalsWithExitMenu::outputMenuWithSecondActiveButton();
						choice = 2;
						break;
					}
					}
					break;
				case KEY_DOWN:
					switch (choice)
					{
					case 1:
					{
						system("CLS");
						menus::choosePlantsOrAnimalsWithExitMenu::outputMenuWithSecondActiveButton();
						choice = 2;
						break;
					}
					case 2:
					{
						system("CLS");
						menus::choosePlantsOrAnimalsWithExitMenu::outputMenuWithThirdActiveButton();
						choice = 3;
						break;
					}
					case 3:
					{
						system("CLS");
						menus::choosePlantsOrAnimalsWithExitMenu::outputMenuWithFirstActiveButton();
						choice = 1;
						break;
					}
					}
					break;
				case KEY_ENTER:
					switch (choice)
					{
					case 1:
					{
						system("CLS");
						inputNewPlantsData(headPlants);
						system("CLS");
						choice = 4;
						break;
					}
					case 2:
					{
						system("CLS");
						inputNewAnimalsData(headAnimals);
						system("CLS");
						choice = 4;
						break;
					}
					case 3:
					{
						return 0;
						break;
					}
					case 4:
					{
						system("CLS");
						choice = 1;
						menus::choosePlantsOrAnimalsWithExitMenu::outputMenuWithFirstActiveButton();
						break;
					}
					}
					break;
				default:
					break;
				}
			}
		}

		//Function for removing plants and animals informations
		bool removeInformation(bp::type::characteristics::PLANTS* headPlants, bp::type::characteristics::ANIMAL* headAnimals)
		{
			int choice;
			system("CLS");
			int n;
			int n1;
			menus::choosePlantsOrAnimalsWithExitMenu::outputMenuWithFirstActiveButton();
			choice = 1;
			while (true) {
				switch (_getch()) {
				case KEY_UP:
					switch (choice)
					{
					case 1:
					{
						system("CLS");
						menus::choosePlantsOrAnimalsWithExitMenu::outputMenuWithThirdActiveButton();
						choice = 3;
						break;
					}
					case 2:
					{
						system("CLS");
						menus::choosePlantsOrAnimalsWithExitMenu::outputMenuWithFirstActiveButton();
						choice = 1;
						break;
					}
					case 3:
					{
						system("CLS");
						menus::choosePlantsOrAnimalsWithExitMenu::outputMenuWithSecondActiveButton();
						choice = 2;
						break;
					}
					}
					break;
				case KEY_DOWN:
					switch (choice)
					{
					case 1:
					{
						system("CLS");
						menus::choosePlantsOrAnimalsWithExitMenu::outputMenuWithSecondActiveButton();
						choice = 2;
						break;
					}
					case 2:
					{
						system("CLS");
						menus::choosePlantsOrAnimalsWithExitMenu::outputMenuWithThirdActiveButton();
						choice = 3;
						break;
					}
					case 3:
					{
						system("CLS");
						menus::choosePlantsOrAnimalsWithExitMenu::outputMenuWithFirstActiveButton();
						choice = 1;
						break;
					}
					}
					break;
				case KEY_ENTER:
					switch (choice)
					{
					case 1:
					{
						system("CLS");
						if (bp::bll::biologyContent::numberOfPlants(headPlants) > 9)
						{
							quiz::outputBorder(bp::bll::biologyContent::numberOfPlants(headPlants) - 9);
						}
						else
						{
							quiz::outputBorder(0);
						}
						biologyContent::showInformation::displayPlants(headPlants, 70, 16);

						n = 0;
						while (true)
						{
							n1 = _getch();
							if (n1 != 13)
							{
								n *= 10;
								n += n1 - 48;
							}
							else
							{
								if (n != 0)
								{
									system("CLS");
									switch (n)
									{
									case 1:
										system("CLS");
										headPlants = bp::bll::biologyContent::deleteFirstPlants(headPlants);
										bp::tools::consoleCoordinates(55, 20);
										cout << "The information has been deleted correctly!";
										bp::tools::consoleCoordinates(122, 53);
										system("pause");
										bp::dal::workWithFiles::fromPlantsListToFile(headPlants);
										break;
									default:
										if (n == bp::bll::biologyContent::numberOfPlants(headPlants))
										{
											system("CLS");
											headPlants = bp::bll::biologyContent::deleteLastPlants(headPlants);
											bp::tools::consoleCoordinates(55, 20);
											cout << "The information has been deleted correctly!";
											bp::tools::consoleCoordinates(122, 53);
											system("pause");
											bp::dal::workWithFiles::fromPlantsListToFile(headPlants);
										}
										else
										{
											if (n > 1 && n < bp::bll::biologyContent::numberOfPlants(headPlants))
											{
												system("CLS");
												headPlants = bp::bll::biologyContent::deleteSpecificNodePlants(headPlants, n);
												bp::tools::consoleCoordinates(55, 20);
												cout << "The information has been deleted correctly!";
												bp::tools::consoleCoordinates(122, 53);
												system("pause");
												bp::dal::workWithFiles::fromPlantsListToFile(headPlants);
											}
										}
										break;
									}
									bp::dal::workWithFiles::fromPlantsListToFile(headPlants);
									break;
								}
							}
						}
						system("CLS");
						choice = 4;
						break;
					}
					case 2:
					{
						system("CLS");
						if (bp::bll::biologyContent::numberOfAnimals(headAnimals) > 9)
						{
							quiz::outputBorder(bp::bll::biologyContent::numberOfAnimals(headAnimals) - 9);
						}
						else
						{
							quiz::outputBorder(0);
						}
						biologyContent::showInformation::displayAnimals(headAnimals, 70, 16);
						n = 0;
						while (true)
						{
							n1 = _getch();
							if (n1 != 13)
							{
								n *= 10;
								n += n1 - 48;
							}
							else
							{
								if (n != 0)
								{
									system("CLS");
									switch (n)
									{
									case 1:
										system("CLS");
										headAnimals = bp::bll::biologyContent::deleteFirstAnimal(headAnimals);
										bp::tools::consoleCoordinates(55, 20);
										cout << "The information has been deleted correctly!";
										bp::tools::consoleCoordinates(122, 53);
										system("pause");
										bp::dal::workWithFiles::fromAnimalsListToFile(headAnimals);
										break;
									default:
										if (n == bp::bll::biologyContent::numberOfAnimals(headAnimals))
										{
											system("CLS");
											headAnimals = bp::bll::biologyContent::deleteLastAnimal(headAnimals);
											bp::tools::consoleCoordinates(55, 20);
											cout << "The information has been deleted correctly!";
											bp::tools::consoleCoordinates(122, 53);
											system("pause");
											bp::dal::workWithFiles::fromAnimalsListToFile(headAnimals);
										}
										else
										{
											if (n > 1 && n < bp::bll::biologyContent::numberOfAnimals(headAnimals))
											{
												system("CLS");
												headAnimals = bp::bll::biologyContent::deleteSpecificNodeAnimals(headAnimals, n);
												bp::tools::consoleCoordinates(55, 20);
												cout << "The information has been deleted correctly!";
												bp::tools::consoleCoordinates(122, 53);
												system("pause");
												bp::dal::workWithFiles::fromAnimalsListToFile(headAnimals);
											}
										}
										break;
									}
									bp::dal::workWithFiles::fromAnimalsListToFile(headAnimals);
									break;
								}
							}
						}
						choice = 4;
						break;
					}
					case 3:
					{
						return 0;
						break;
					}
					case 4:
					{
						system("CLS");
						choice = 1;
						menus::choosePlantsOrAnimalsWithExitMenu::outputMenuWithFirstActiveButton();
						break;
					}
					}
					break;
				default:
					break;
				}
			}
		}

		//Output menu with plants, animals and quiz options
		bool plantsAnimalsAndQuizMenu()
		{
			int choice;
			system("CLS");
			menus::plantsAnimalsAndQuizMenu::outputMenuWithFirstActiveButton();
			choice = 1;
			while (true) {
				switch (_getch()) {
				case KEY_UP:
					switch (choice)
					{
					case 1:
					{
						system("CLS");
						menus::plantsAnimalsAndQuizMenu::outputMenuWithThirdActiveButton();
						choice = 3;
						break;
					}
					case 2:
					{
						system("CLS");
						menus::plantsAnimalsAndQuizMenu::outputMenuWithFirstActiveButton();
						choice = 1;
						break;
					}
					case 3:
					{
						system("CLS");
						menus::plantsAnimalsAndQuizMenu::outputMenuWithSecondActiveButton();
						choice = 2;
						break;
					}
					}
					break;
				case KEY_DOWN:
					switch (choice)
					{
					case 1:
					{
						system("CLS");
						menus::plantsAnimalsAndQuizMenu::outputMenuWithSecondActiveButton();
						choice = 2;
						break;
					}
					case 2:
					{
						system("CLS");
						menus::plantsAnimalsAndQuizMenu::outputMenuWithThirdActiveButton();
						choice = 3;
						break;
					}
					case 3:
					{
						system("CLS");
						menus::plantsAnimalsAndQuizMenu::outputMenuWithFirstActiveButton();
						choice = 1;
						break;
					}
					}
					break;
				case KEY_ENTER:
					switch (choice)
					{
					case 1:
					{
						plantsMenu();
						system("CLS");
						choice = 4;
						break;
					}
					case 2:
					{
						animalsMenu();
						system("CLS");
						choice = 4;
						break;
					}
					case 3:
					{
						system("CLS");
						bp::consoleApp::quiz::quiz();
						choice = 4;
						break;
					}
					case 4:
					{
						system("CLS");
						choice = 1;
						menus::plantsAnimalsAndQuizMenu::outputMenuWithFirstActiveButton();
						break;
					}
					}
					break;
				default:
					break;
				}
			}
		}

		// Menu input for animals information menu
		bool movementInAnimalsMenu(bp::type::characteristics::ANIMAL* headAnimals)
		{
			bool truth = true;
			int number;
			int pressNumber;

			while (truth)
			{
				number = 0;
				while (true)
				{
					pressNumber = _getch();
					if (pressNumber != 13)
					{
						if (pressNumber == 27)
						{
							return 0;
						}
						else
						{
							number *= 10;
							number += pressNumber - 48;
						}
					}
					else
					{
						if (number != 0)
						{
							system("CLS");
							quiz::outputBorder(0);
							biologyContent::showInformation::displayInfoAnimal(headAnimals, number, 60, 16);
							break;
						}
					}
				}
			}
		}

		// Menu input for plants information menu
		bool movementInPlantsMenu(bp::type::characteristics::PLANTS* headPlants)
		{
			bool truth = true;
			int number;
			int pressNumber;

			while (truth)
			{
				number = 0;
				while (true)
				{
					pressNumber = _getch();
					if (pressNumber != 13)
					{
						if (pressNumber == 27)
						{
							return 0;
						}
						else
						{
							number *= 10;
							number += pressNumber - 48;
						}
					}
					else
					{
						if (number != 0)
						{
							system("CLS");
							quiz::outputBorder(0);
							biologyContent::showInformation::displayInfoPlants(headPlants, number, 60, 16);
							break;
						}
					}
				}
			}
		}

		// Menu input for animals 
		bool animalsMenu()
		{
			bp::type::characteristics::ANIMAL* headAnimals = new  bp::type::characteristics::ANIMAL;

			headAnimals = bp::dal::workWithFiles::fromFileToAnimalsList(headAnimals);

			if (headAnimals != NULL)
			{
				headAnimals = bp::bll::biologyContent::deleteFirstAnimal(headAnimals);
			}
			int choice;
			system("CLS");
			menus::animalsAndPlantsMenu::animalsMenu::outputMenuWithFirstActiveButton();
			choice = 1;
			string str;
			while (true) {
				switch (_getch()) {
				case KEY_UP:
					switch (choice)
					{
					case 1:
					{
						system("CLS");
						menus::animalsAndPlantsMenu::animalsMenu::outputMenuWithThirdActiveButton();
						choice = 3;
						break;
					}
					case 2:
					{
						system("CLS");
						menus::animalsAndPlantsMenu::animalsMenu::outputMenuWithFirstActiveButton();
						choice = 1;
						break;
					}
					case 3:
					{
						system("CLS");
						menus::animalsAndPlantsMenu::animalsMenu::outputMenuWithSecondActiveButton();
						choice = 2;
						break;
					}
					}
					break;
				case KEY_DOWN:
					switch (choice)
					{
					case 1:
					{
						system("CLS");
						menus::animalsAndPlantsMenu::animalsMenu::outputMenuWithSecondActiveButton();
						choice = 2;
						break;
					}
					case 2:
					{
						system("CLS");
						menus::animalsAndPlantsMenu::animalsMenu::outputMenuWithThirdActiveButton();
						choice = 3;
						break;
					}
					case 3:
					{
						system("CLS");
						menus::animalsAndPlantsMenu::animalsMenu::outputMenuWithFirstActiveButton();
						choice = 1;
						break;
					}
					}
					break;
				case KEY_ENTER:
					switch (choice)
					{
					case 1:
					{
						system("CLS");
						if (bp::bll::biologyContent::numberOfAnimals(headAnimals) > 9)
						{
							quiz::outputBorder(bp::bll::biologyContent::numberOfAnimals(headAnimals) - 9);
						}
						else
						{
							quiz::outputBorder(0);
						}
						biologyContent::showInformation::displayAnimals(headAnimals, 70, 16);
						movementInAnimalsMenu(headAnimals);
						choice = 4;
						break;
					}
					case 2:
					{
						system("CLS");
						cout << endl << endl << endl << "Enter what you want to search : ";
						cin >> str;
						cout << endl << endl;
						biologyContent::search::searchA(headAnimals, str);
						choice = 4;
						break;
					}
					case 3:
					{
						return 0;
						break;
					}
					case 4:
					{
						system("CLS");
						choice = 1;
						menus::animalsAndPlantsMenu::animalsMenu::outputMenuWithFirstActiveButton();
						break;
					}
					}
					break;
				default:
					break;
				}
			}
		}

		// Menu input for plants
		bool plantsMenu()
		{
			bp::type::characteristics::PLANTS* headPlants = new  bp::type::characteristics::PLANTS;

			headPlants = bp::dal::workWithFiles::fromFileToPlantsList(headPlants);

			if (headPlants != NULL)
			{
				headPlants = bp::bll::biologyContent::deleteFirstPlants(headPlants);
			}

			int choice;
			system("CLS");
			string str;
			menus::animalsAndPlantsMenu::plantsMenu::outputMenuWithFirstActiveButton();
			choice = 1;
			while (true) {
				switch (_getch()) {
				case KEY_UP:
					switch (choice)
					{
					case 1:
					{
						system("CLS");
						menus::animalsAndPlantsMenu::plantsMenu::outputMenuWithThirdActiveButton();
						choice = 3;
						break;
					}
					case 2:
					{
						system("CLS");
						menus::animalsAndPlantsMenu::plantsMenu::outputMenuWithFirstActiveButton();
						choice = 1;
						break;
					}
					case 3:
					{
						system("CLS");
						menus::animalsAndPlantsMenu::plantsMenu::outputMenuWithSecondActiveButton();
						choice = 2;
						break;
					}
					}
					break;
				case KEY_DOWN:
					switch (choice)
					{
					case 1:
					{
						system("CLS");
						menus::animalsAndPlantsMenu::plantsMenu::outputMenuWithSecondActiveButton();
						choice = 2;
						break;
					}
					case 2:
					{
						system("CLS");
						menus::animalsAndPlantsMenu::plantsMenu::outputMenuWithThirdActiveButton();
						choice = 3;
						break;
					}
					case 3:
					{
						system("CLS");
						menus::animalsAndPlantsMenu::plantsMenu::outputMenuWithFirstActiveButton();
						choice = 1;
						break;
					}
					}
					break;
				case KEY_ENTER:
					switch (choice)
					{
					case 1:
					{
						system("CLS");
						if (bp::bll::biologyContent::numberOfPlants(headPlants) > 9)
						{
							quiz::outputBorder(bp::bll::biologyContent::numberOfPlants(headPlants) - 9);
						}
						else
						{
							quiz::outputBorder(0);
						}
						biologyContent::showInformation::displayPlants(headPlants, 70, 16);
						movementInPlantsMenu(headPlants);
						choice = 4;
						break;
					}
					case 2:
					{
						system("CLS");

						cout << endl << endl << endl << "Enter what you want to search : ";
						cin >> str;
						cout << endl << endl;
						bp::consoleApp::biologyContent::search::searchP(headPlants, str);
						choice = 4;
						break;
					}
					case 3:
					{
						return 0;
						break;
					}
					case 4:
					{
						system("CLS");
						choice = 1;
						menus::animalsAndPlantsMenu::plantsMenu::outputMenuWithFirstActiveButton();
						break;
					}
					}
					break;
				default:
					break;
				}
			}
		}

		// Menu input for animal breeding
		bool breedingMenuInput()
		{
			HWND console = GetConsoleWindow();
			MoveWindow(console, 280, 75, 1300, 910, TRUE);
			system("CLS");
			bp::consoleApp::animalBreeding::menuBreeding();
			bp::consoleApp::animalBreeding::animalOption(53, 20);
			bp::tools::consoleCoordinates(60, 22);
			cout << "-->";

			int counter = 22;
			do
			{
				switch (_getch())
				{

				case KEY_UP:
				{
					if (counter == 22) counter = 32;
					counter -= 2;
					system("CLS");
					bp::consoleApp::animalBreeding::menuBreeding();
					bp::consoleApp::animalBreeding::animalOption(53, 20);
					bp::tools::consoleCoordinates(60, counter);
					cout << "-->";

				} break;

				case KEY_DOWN:
				{
					if (counter == 30) {
						counter = 20;
					}
					counter += 2;
					system("CLS");
					bp::consoleApp::animalBreeding::menuBreeding();
					bp::consoleApp::animalBreeding::animalOption(53, 20);
					bp::tools::consoleCoordinates(60, counter);
					cout << "-->";
				} break;

				case KEY_ENTER:
				{
					switch (counter)
					{
					case 22:
					{
						system("CLS");
						bp::consoleApp::menuInputs::breedInput(1);
					}break;
					case 24:
					{
						system("CLS");
						bp::consoleApp::menuInputs::breedInput(2);
					}break;
					case 26:
					{
						system("CLS");
						bp::consoleApp::menuInputs::breedInput(3);
					}break;
					case 28:
					{
						system("CLS");
						bp::consoleApp::menuInputs::breedInput(4);
					}break;
					case 30:
					{
						system("CLS");
						bp::consoleApp::menuInputs::sortInput(5);
					}
					}
				}

				case KEY_ESCAPE:
				{
					system("CLS");
					bp::consoleApp::menuInputs::plantsAndAnimalsMenu();
					break;
				}
				}
			} while (true);
			return 1;
		}

		// Menu input for choosing animal breed
		bool breedInput(int choice)
		{
			system("CLS");
			bp::consoleApp::animalBreeding::menuBreeding();
			bp::consoleApp::animalBreeding::breedOption(choice);
			bp::tools::consoleCoordinates(60, 22);
			cout << "-->";

			int counter = 22;
			do
			{
				switch (_getch())
				{

				case KEY_UP:
				{
					if (counter == 22) counter = 28;
					counter -= 2;
					system("CLS");
					bp::consoleApp::animalBreeding::menuBreeding();
					bp::consoleApp::animalBreeding::breedOption(choice);
					bp::tools::consoleCoordinates(60, counter);
					cout << "-->";

				} break;

				case KEY_DOWN:
				{
					if (counter == 26) {
						counter = 20;
					}
					counter += 2;
					system("CLS");
					bp::consoleApp::animalBreeding::menuBreeding();
					bp::consoleApp::animalBreeding::breedOption(choice);
					bp::tools::consoleCoordinates(60, counter);
					cout << "-->";
				} break;

				case KEY_ENTER:
				{
					switch (counter)
					{
					case 22:
					{
						system("CLS");
						bp::consoleApp::animalBreeding::menuBreeding();
						bp::bll::animalBreeding::animalTypes(choice, 1);
					}break;
					case 24:
					{
						system("CLS");
						bp::consoleApp::animalBreeding::menuBreeding();
						bp::bll::animalBreeding::animalTypes(choice, 2);
					}break;
					case 26:
					{
						system("CLS");
						bp::consoleApp::animalBreeding::menuBreeding();
						bp::bll::animalBreeding::animalTypes(choice, 3);
					}break;
					}
				}

				case KEY_ESCAPE:
				{
					system("CLS");
					bp::consoleApp::menuInputs::breedingMenuInput();
					break;
				}
				}
			} while (true);
			return 1;
		}

		// Menu input for choosing plant
		bool seedingMenuInput()
		{

			HWND console = GetConsoleWindow();
			MoveWindow(console, 280, 75, 1300, 910, TRUE);
			system("CLS");
			bp::consoleApp::plantsSeeding::menuPlantsSeeding();
			bp::consoleApp::plantsSeeding::plantOption(48, 20);
			bp::tools::consoleCoordinates(60, 22);
			cout << "-->";

			int counter = 22;
			do
			{
				switch (_getch())
				{

				case KEY_UP:
				{
					if (counter == 22) counter = 32;
					counter -= 2;
					system("CLS");
					bp::consoleApp::plantsSeeding::menuPlantsSeeding();
					bp::consoleApp::plantsSeeding::plantOption(48, 20);
					bp::tools::consoleCoordinates(60, counter);
					cout << "-->";

				} break;

				case KEY_DOWN:
				{
					if (counter == 30) {
						counter = 20;
					}
					counter += 2;
					system("CLS");
					bp::consoleApp::plantsSeeding::menuPlantsSeeding();
					bp::consoleApp::plantsSeeding::plantOption(48, 20);
					bp::tools::consoleCoordinates(60, counter);
					cout << "-->";
				} break;

				case KEY_ENTER:
				{
					switch (counter)
					{
					case 22:
					{
						system("CLS");
						bp::consoleApp::menuInputs::sortInput(1);
					}break;
					case 24:
					{
						system("CLS");
						bp::consoleApp::menuInputs::sortInput(2);
					}break;
					case 26:
					{
						system("CLS");
						bp::consoleApp::menuInputs::sortInput(3);
					}break;
					case 28:
					{
						system("CLS");
						bp::consoleApp::menuInputs::sortInput(4);
					}break;
					case 30:
					{
						system("CLS");
						bp::consoleApp::menuInputs::sortInput(5);
					}break;
					}
				}

				case KEY_ESCAPE:
				{
					system("CLS");
					bp::consoleApp::menuInputs::plantsAndAnimalsMenu();
					break;
				}
				}
			} while (true);
			return 1;
		}

		// Menu input for choosing plant sort
		bool sortInput(int choice)
		{
			system("CLS");
			bp::consoleApp::plantsSeeding::menuPlantsSeeding();
			bp::consoleApp::plantsSeeding::sortOption(choice);
			bp::tools::consoleCoordinates(57, 22);
			cout << "-->";

			int counter = 22;
			do
			{
				switch (_getch())
				{

				case KEY_UP:
				{
					if (counter == 22) counter = 26;
					counter -= 2;
					system("CLS");
					bp::consoleApp::plantsSeeding::menuPlantsSeeding();
					bp::consoleApp::plantsSeeding::sortOption(choice);
					bp::tools::consoleCoordinates(57, counter);
					cout << "-->";

				} break;

				case KEY_DOWN:
				{
					if (counter == 24) {
						counter = 20;
					}
					counter += 2;
					system("CLS");
					bp::consoleApp::plantsSeeding::menuPlantsSeeding();
					bp::consoleApp::plantsSeeding::sortOption(choice);
					bp::tools::consoleCoordinates(57, counter);
					cout << "-->";
				} break;

				case KEY_ENTER:
				{
					switch (counter)
					{
					case 22:
					{
						system("CLS");
						bp::consoleApp::plantsSeeding::menuPlantsSeeding();
						bp::bll::plantsSeeding::sortTypes(choice, 1);
					}break;
					case 24:
					{
						system("CLS");
						bp::consoleApp::plantsSeeding::menuPlantsSeeding();
						bp::bll::plantsSeeding::sortTypes(choice, 2);;
					}break;

					}
				}break;

				case KEY_ESCAPE:
				{
					system("CLS");
					bp::consoleApp::menuInputs::seedingMenuInput();
					break;
				}break;
				}
			} while (true);
			return 1;
		}

	}

	namespace animalBreeding
	{
		// Function that displays animal breeding menu
		void menuBreeding()
		{
			bp::consoleApp::animalBreeding::animalFigures::dog(3, 2);
			bp::consoleApp::animalBreeding::animalFigures::horse(1, 23);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
			bp::consoleApp::animalBreeding::menuParts::border(45, 0);
			bp::consoleApp::animalBreeding::menuParts::label(56, 2);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
			bp::consoleApp::animalBreeding::menuParts::border(105, 0);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			bp::consoleApp::animalBreeding::animalFigures::cow(110, 4);
			bp::consoleApp::animalBreeding::animalFigures::cat(110, 27);
		}

		// Function that displays animals
		void animalOption(int x, int y)
		{
			bp::tools::consoleCoordinates(x, y);
			cout << "Choose what sort of animals you want to breed:";
			bp::tools::consoleCoordinates(x + 15, y + 2);
			cout << "    Dogs";
			bp::tools::consoleCoordinates(x + 15, y + 4);
			cout << "    Cats";
			bp::tools::consoleCoordinates(x + 15, y + 6);
			cout << "    Cows";
			bp::tools::consoleCoordinates(x + 15, y + 8);
			cout << "    Horses";
			bp::tools::consoleCoordinates(x + 15, y + 10);
			cout << "    Goats";
		}

		// Function that displays animal breeds
		void breedOption(int choice)
		{
			switch (choice)
			{
			case 1:
			{
				bp::tools::consoleCoordinates(58, 20);
				cout << "CHOOSE WHAT DOG BREED YOUR DOGS ARE:\n";
				bp::tools::consoleCoordinates(70, 22);
				cout << "Labrador\n";
				bp::tools::consoleCoordinates(70, 24);
				cout << "German Shepherd\n";
				bp::tools::consoleCoordinates(70, 26);
				cout << "Chihuahua\n";
			}break;
			case 2:
			{
				bp::tools::consoleCoordinates(58, 20);
				cout << "CHOOSE WHAT CAT BREED YOUR CATS:\n";
				bp::tools::consoleCoordinates(70, 22);
				cout << "Persian Cat\n";
				bp::tools::consoleCoordinates(70, 24);
				cout << "Scottish Fold\n";
				bp::tools::consoleCoordinates(70, 26);
				cout << "European Cat\n";


			}break;
			case 3:
			{
				bp::tools::consoleCoordinates(58, 20);
				cout << "CHOOSE WHAT COW BREED YOUR COWS ARE: \n";
				bp::tools::consoleCoordinates(70, 22);
				cout << "Hereford\n";
				bp::tools::consoleCoordinates(70, 24);
				cout << "Gelbvieh\n";
				bp::tools::consoleCoordinates(70, 26);
				cout << "Brangus\n";


			}break;
			case 4:
			{
				bp::tools::consoleCoordinates(58, 20);
				cout << "CHOOSE WHAT HORSE BREED YOUR HORSES ARE: \n";
				bp::tools::consoleCoordinates(70, 22);
				cout << "Arabian Horse\n";
				bp::tools::consoleCoordinates(70, 24);
				cout << "Appaloosa Horses\n";
				bp::tools::consoleCoordinates(70, 26);
				cout << "Morgan Horse\n";


			}break;
			case 5:
			{
				bp::tools::consoleCoordinates(58, 20);
				cout << "CHOOSE WHAT GOAT BREED YOUR GOATS ARE: \n";
				bp::tools::consoleCoordinates(70, 22);
				cout << "Saanen goat\n";
				bp::tools::consoleCoordinates(70, 24);
				cout << "Alpine goat\n";
				bp::tools::consoleCoordinates(70, 26);
				cout << "American Lamancha\n";


			}break;
			}

		}

		// Function that gives user a choice for fur type and fur colour of the animal
		void breed(std::string furType[], std::string furColour[], std::string typeOfAnimal, int breed)
		{
			
			bp::tools::consoleCoordinates(63, 18);
			cout << "CHOOSE MOTHER'S FUR TYPE:\n\n";
			bp::tools::consoleCoordinates(68, 20);
			cout << "1) Long-haired\n";
			bp::tools::consoleCoordinates(68, 22);
			cout << "2) Short-haired\n";

			bp::tools::consoleCoordinates(68, 24);
			int choice;
			cin >> choice;

			system("CLS");
			bp::consoleApp::animalBreeding::menuBreeding();
			bp::tools::consoleCoordinates(63, 18);
			cout << "CHOOSE MOTHER'S FUR COLOUR:\n\n";

			int y = 20;
			for (size_t i = 0; i < 3; i++)
			{
				bp::tools::consoleCoordinates(68, y);
				cout << i + 1 << ") " << furColour[i] << endl;
				y += 2;
			}

			bp::tools::consoleCoordinates(68, 26);
			int choice2;
			cin >> choice2;

			system("CLS");
			menuBreeding();
			bp::tools::consoleCoordinates(63, 18);
			cout << "CHOOSE FATHER'S FUR TYPE:\n\n";
			bp::tools::consoleCoordinates(68, 20);
			cout << "1) Long-haired\n";
			bp::tools::consoleCoordinates(68, 22);
			cout << "2) Short-haired\n";

			bp::tools::consoleCoordinates(68, 24);
			int choice3;
			cin >> choice3;

			system("CLS");
			menuBreeding();
			bp::tools::consoleCoordinates(63, 18);
			cout << "CHOOSE FATHER'S FUR COLOUR:\n\n";
			y = 20;
			for (size_t i = 0; i < 3; i++)
			{
				bp::tools::consoleCoordinates(68, y);
				cout << i + 1 << ") " << furColour[i] << endl;
				y += 2;
			}

			bp::tools::consoleCoordinates(68, 26);
			int choice4;
			cin >> choice4;

			switch (breed)
			{
			case 1:
			{
				system("CLS");
				menuBreeding();
				bp::tools::consoleCoordinates(58, 18);
				cout << "CHOOSE HOW MANY PUPPIES WILL BE BORN: \n";
				bp::tools::consoleCoordinates(63, 19);
				int puppies;
				cin >> puppies;
				bp::bll::animalBreeding::resultBreeding(choice, choice2, choice3, choice4, puppies, typeOfAnimal, furType, furColour, breed);
			}break;

			case 2:
			{
				system("CLS");
				menuBreeding();
				bp::tools::consoleCoordinates(63, 18);
				cout << "CHOOSE HOW MANY KITTENS WILL BE BORN: \n";
				bp::tools::consoleCoordinates(63, 19);
				int kittens;
				cin >> kittens;
				bp::bll::animalBreeding::resultBreeding(choice, choice2, choice3, choice4, kittens, typeOfAnimal, furType, furColour, breed);
			}break;
			case 3:
			{
				system("CLS");
				menuBreeding();
				bp::tools::consoleCoordinates(63, 18);
				cout << "CHOOSE HOW MANY CALVES WILL BE BORN: \n";
				bp::tools::consoleCoordinates(63, 19);
				int calves;
				cin >> calves;
				bp::bll::animalBreeding::resultBreeding(choice, choice2, choice3, choice4, calves, typeOfAnimal, furType, furColour, breed);
			}break;
			case 4:
			{
				system("CLS");
				menuBreeding();
				bp::tools::consoleCoordinates(63, 18);
				cout << "CHOOSE HOW MANY HORSES WILL BE BORN: \n";
				bp::tools::consoleCoordinates(63, 19);
				int horses;
				cin >> horses;
				bp::bll::animalBreeding::resultBreeding(choice, choice2, choice3, choice4, horses, typeOfAnimal, furType, furColour, breed);
			}break;
			case 5:
			{
				system("CLS");
				menuBreeding();
				bp::tools::consoleCoordinates(63, 18);
				cout << "CHOOSE HOW MANY GOATS WILL BE BORN: \n";
				bp::tools::consoleCoordinates(63, 19);
				int goats;
				cin >> goats;
				bp::bll::animalBreeding::resultBreeding(choice, choice2, choice3, choice4, goats, typeOfAnimal, furType, furColour, breed);
			}break;
			}
		}

		// Function that shows result newborns
		void resultBreedingLabel(int animals, string typeOfAnimal, string breedFurColour[], string breedFurType[], int breed)
		{
			srand(time(NULL));
			int RanIndexFurType;
			int RanIndexFurColour;
			system("CLS");
			switch (breed)
			{
			case 1:
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
				animalBreeding::animalFigures::resultDog(50, 10);
				bp::tools::loadingBar(60, 40);
			}break;
			case 2:
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
				animalBreeding::animalFigures::resultCat(50, 10);
				bp::tools::loadingBar(60, 40);
			}break;
			case 3:
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
				animalBreeding::animalFigures::resultCow(50, 10);
				bp::tools::loadingBar(60, 40);
			}break;
			case 4:
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
				animalBreeding::animalFigures::resultHorse(50, 10);
				bp::tools::loadingBar(60, 40);
			}break;
			case 5:
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
				animalBreeding::animalFigures::resultGoat(50, 10);
				bp::tools::loadingBar(60, 40);
			}break;
			}
			system("CLS");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			bp::consoleApp::animalBreeding::menuParts::border(36, 0);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			bp::consoleApp::plantsSeeding::menuParts::congratulationsLabel(41, 2);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			bp::consoleApp::animalBreeding::menuParts::border(122, 0);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

			bp::tools::consoleCoordinates(56, 19);
			string typeOfAnimalToUpper = bp::tools::toUpper(typeOfAnimal);
			string text = "YOU CHOSE TO BREED " + typeOfAnimalToUpper + " AND YOU GET THESE NEWBORNS:";
			bp::tools::slowmotionOfScreenplay(text);
			int y = 21;
			for (int i = 0; i < animals; i++)
			{
				RanIndexFurType = rand() % 2;
				RanIndexFurColour = rand() % 2;
				bp::tools::consoleCoordinates(66, y);
				cout << i + 1 << ") " << breedFurColour[RanIndexFurColour] << " " << breedFurType[RanIndexFurType] << " " << typeOfAnimal;
				y += 1;
			}

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			bp::tools::loadingBar(68,35);
			bp::consoleApp::planetPopulation::planetPopulation();
		}

		namespace animalFigures
		{
			// Function that displays dog figure for result breeding
			void resultDog(int x, int y)
			{
				bp::tools::consoleCoordinates(x, y);
				cout << "                             ;\\ \n";
				bp::tools::consoleCoordinates(x, y + 1);
				cout << "                            |' \\ \n";
				bp::tools::consoleCoordinates(x, y + 2);
				cout << "         _                  ; : ; \n";
				bp::tools::consoleCoordinates(x, y + 3);
				cout << "        / `-.              /: : | \n";
				bp::tools::consoleCoordinates(x, y + 4);
				cout << "       |  ,-.`-.          ,': : | \n";
				bp::tools::consoleCoordinates(x, y + 5);
				cout << "       \\  :  `. `.       ,'-. : | \n";
				bp::tools::consoleCoordinates(x, y + 6);
				cout << "        \\ ;    ;  `-.__,'    `-.| \n";
				bp::tools::consoleCoordinates(x, y + 7);
				cout << "         \\ ;   ;  :::  ,::'`:.  `. \n";
				bp::tools::consoleCoordinates(x, y + 8);
				cout << "          \\ `-. :  `    :.    `.  \\ \n";
				bp::tools::consoleCoordinates(x, y + 9);
				cout << "          \\   \\    ,   ;   ,:    (\\ \n";
				bp::tools::consoleCoordinates(x, y + 10);
				cout << "            \   :., :.    ,'o)): ` `-. \n";
				bp::tools::consoleCoordinates(x, y + 11);
				cout << "           ,/,' ;' ,::\"'`.`---'   `.  `-._ \n";
				bp::tools::consoleCoordinates(x, y + 12);
				cout << "         ,/  :  ; '\"      `;'          ,--`. \n";
				bp::tools::consoleCoordinates(x, y + 13);
				cout << "        ;/   :; ;             ,:'     (   ,:)\n";
				bp::tools::consoleCoordinates(x, y + 14);
				cout << "          ,.,:.    ; ,:.,  ,-._ `.     \\\"\"'/ \n";
				bp::tools::consoleCoordinates(x, y + 15);
				cout << "          '::'     `:'`  ,'(  \\`._____.-'\"' \n";
				bp::tools::consoleCoordinates(x, y + 16);
				cout << "             ;,   ;  `.  `. `._`-.  \\ \n";
				bp::tools::consoleCoordinates(x, y + 17);
				cout << "             ;:.  ;:       `-._`-.\\  \\ \n";
				bp::tools::consoleCoordinates(x, y + 18);
				cout << "              '`:. :        |' `. `\\  )  \n";
				bp::tools::consoleCoordinates(x, y + 19);
				cout << "                ` ;:       |    `--\__,' \n";
				bp::tools::consoleCoordinates(x, y + 20);
				cout << "                   '`      ,'\n";
				bp::tools::consoleCoordinates(x, y + 21);
				cout << "                        ,-' \n";
			}

			// Function that displays dog figure
			void dog(int x, int y)
			{
				bp::tools::consoleCoordinates(x, y);
				cout << "         .--.            _..._  ";
				bp::tools::consoleCoordinates(x, y + 1);
				cout << "       .'    \\       .-\"\"  __ \"\"-.";
				bp::tools::consoleCoordinates(x, y + 2);
				cout << "     .'       : --..:__.-\"\"  \"\"-. \\ ";
				bp::tools::consoleCoordinates(x, y + 3);
				cout << "    /         ;.d$$    sbp_.-\"\"-:_:";
				bp::tools::consoleCoordinates(x, y + 4);
				cout << "    : ._       :P .-.   ,\"TP ";
				bp::tools::consoleCoordinates(x, y + 5);
				cout << "    \\  T--...-; : d$b  :d$b ";
				bp::tools::consoleCoordinates(x, y + 6);
				cout << "     \\  `..'    ; $ $  ;$ $ ";
				bp::tools::consoleCoordinates(x, y + 7);
				cout << "      ).        : T$P  :T$P ";
				bp::tools::consoleCoordinates(x, y + 8);
				cout << "     /           `-'    `._`._";
				bp::tools::consoleCoordinates(x, y + 9);
				cout << "  .-\"                     T$$$b";
				bp::tools::consoleCoordinates(x, y + 10);
				cout << "-\"._                        '^';";
				bp::tools::consoleCoordinates(x, y + 11);
				cout << "                  \\.`.         /";
				bp::tools::consoleCoordinates(x, y + 12);
				cout << "                   \\`.\"-._.-'-'";
				bp::tools::consoleCoordinates(x, y + 13);
				cout << "                /\\  \\ \\ \\ \\";
				bp::tools::consoleCoordinates(x, y + 14);
				cout << "               /  \\  \\ \\ . ;";
				bp::tools::consoleCoordinates(x, y + 15);
				cout << "                   .  `.;  :";
				bp::tools::consoleCoordinates(x, y + 16);
				cout << "                    \" - ._:;";
				bp::tools::consoleCoordinates(x, y + 17);
				cout << "                         \\/";
			}

			// Function that displays cow figure
			void cow(int x, int y)
			{
				bp::tools::consoleCoordinates(x, y);
				cout << "             .=     ,        =.\n";
				bp::tools::consoleCoordinates(x, y + 1);
				cout << "     _  _   /'/    )\\,/,/(_   \\ \\\n";
				bp::tools::consoleCoordinates(x, y + 2);
				cout << "      `//-.|  (  ,\\\\)\\//\\)\\/_  ) |\n";
				bp::tools::consoleCoordinates(x, y + 3);
				cout << "     //___\\   `\\\\\\/\\\\/\\/\\\\///'  /  \n";
				bp::tools::consoleCoordinates(x, y + 4);
				cout << "   ,-\"~`-._ `\"- - '_   `\"\"\"`  _ \\`'\"~-,_\n";
				bp::tools::consoleCoordinates(x, y + 5);
				cout << "   \\       `-.  '_`.      .'_` \\ ,-\"~`/\n";
				bp::tools::consoleCoordinates(x, y + 6);
				cout << "    `.__.-'`/   (-\        /-) |-.__,'\n";
				bp::tools::consoleCoordinates(x, y + 7);
				cout << "      ||   |     \\O)  /^\\ (O/  |\n";
				bp::tools::consoleCoordinates(x, y + 8);
				cout << "       `\\\\  |         /   `\\   /\n";
				bp::tools::consoleCoordinates(x, y + 9);
				cout << "         \\\\  \\       /      `\ /\n";
				bp::tools::consoleCoordinates(x, y + 10);
				cout << "         `\\\\ `-.  /' .---.--.\\\n";
				bp::tools::consoleCoordinates(x, y + 11);
				cout << "           `\\\\/`~(, '()      ('\n";
				bp::tools::consoleCoordinates(x, y + 12);
				cout << "            /(O) \\\\   _,.-.,_)\n";
				bp::tools::consoleCoordinates(x, y + 13);
				cout << "           //  \\\\ `\\'`      /\n";
				bp::tools::consoleCoordinates(x, y + 14);
				cout << "         / |  ||   `\"\"\"\"~\"`\n";
				bp::tools::consoleCoordinates(x, y + 15);
				cout << "       /'  |__||    ";
				bp::tools::consoleCoordinates(x, y + 16);
				cout << "              `o";
			}

			// Function that displays horse figure
			void horse(int x, int y)
			{
				bp::tools::consoleCoordinates(x, y);
				cout << "                             _(\\_/)";
				bp::tools::consoleCoordinates(x, y + 1);
				cout << "                           ,((((^`\\";
				bp::tools::consoleCoordinates(x, y + 2);
				cout << "                          ((((  (6 \\";
				bp::tools::consoleCoordinates(x, y + 3);
				cout << "                        ,((((( ,    \\";
				bp::tools::consoleCoordinates(x, y + 4);
				cout << "    ,,,_              ,(((((  /\"._, `,";
				bp::tools::consoleCoordinates(x, y + 5);
				cout << "   ((((\\ ,...       ,((((   /    `-.-'";
				bp::tools::consoleCoordinates(x, y + 6);
				cout << "  )))  ;'    `\"'\"'\"\"((((   (";
				bp::tools::consoleCoordinates(x, y + 7);
				cout << " (((  /            (((      \\";
				bp::tools::consoleCoordinates(x, y + 8);
				cout << "  )) |                      |";
				bp::tools::consoleCoordinates(x, y + 9);
				cout << " ((  |        .       '     |";
				bp::tools::consoleCoordinates(x, y + 10);
				cout << " ))  \\     _ '      `t   ,.')";
				bp::tools::consoleCoordinates(x, y + 11);
				cout << " (   |   y;- -,-\"\"'\"-.\\   \\ /";
				bp::tools::consoleCoordinates(x, y + 12);
				cout << " )   / ./  ) /         `\\  \\";
				bp::tools::consoleCoordinates(x, y + 13);
				cout << "    |./   ( (           / /'";
				bp::tools::consoleCoordinates(x, y + 14);
				cout << "    ||     \\\\          //'|";
				bp::tools::consoleCoordinates(x, y + 15);
				cout << "    ||      \\\\       _//'||";
				bp::tools::consoleCoordinates(x, y + 16);
				cout << "    ||       ))     |_/  ||";
				bp::tools::consoleCoordinates(x, y + 17);
				cout << "    \\_\\     |_/          ||";
				bp::tools::consoleCoordinates(x, y + 18);
				cout << "      `'\"                \\_\\ ";
			}

			// Function that displays cat figure
			void cat(int x, int y)
			{
				bp::tools::consoleCoordinates(x, y);
				cout << "       _";
				bp::tools::consoleCoordinates(x, y + 1);
				cout << "       \\`*-.";
				bp::tools::consoleCoordinates(x, y + 2);
				cout << "        )  _`-.";
				bp::tools::consoleCoordinates(x, y + 3);
				cout << "       .  : `. .";
				bp::tools::consoleCoordinates(x, y + 4);
				cout << "       : _   '  \\";
				bp::tools::consoleCoordinates(x, y + 5);
				cout << "      ; *` _.   `*-._ ";
				bp::tools::consoleCoordinates(x, y + 6);
				cout << "       `-.-'          `-.";
				bp::tools::consoleCoordinates(x, y + 7);
				cout << "         ;       `       `.";
				bp::tools::consoleCoordinates(x, y + 8);
				cout << "         :.       .        \\";
				bp::tools::consoleCoordinates(x, y + 9);
				cout << "         . \  .   :   .-'   .";
				bp::tools::consoleCoordinates(x, y + 10);
				cout << "         '  `+.;  ;  '      :";
				bp::tools::consoleCoordinates(x, y + 11);
				cout << "         :  '  |    ;       ;-. ";
				bp::tools::consoleCoordinates(x, y + 12);
				cout << "         ; '   : :`-:     _.`* ;";
				bp::tools::consoleCoordinates(x, y + 13);
				cout << "      .*' /  .*' ; .*`- +'  `*'";
				bp::tools::consoleCoordinates(x, y + 14);
				cout << "      `*-*   `*-*  `*-*'";
			}

			// Function that displays cat figure for result breeding
			void resultCat(int x, int y)
			{
				bp::tools::consoleCoordinates(x, y);
				cout << "                               __ \n";
				bp::tools::consoleCoordinates(x, y + 1);
				cout << "                         _,-;''';`'-,. \n";
				bp::tools::consoleCoordinates(x, y + 2);
				cout << "                      _/',  `;  `;    `\\\n";
				bp::tools::consoleCoordinates(x, y + 3);
				cout << "      ,        _..,-''    '   `  `      `\\\n";
				bp::tools::consoleCoordinates(x, y + 4);
				cout << "     | ;._.,,-' .| |,_        ,,          `\\\n";
				bp::tools::consoleCoordinates(x, y + 5);
				cout << "     | `;'      ;' ;, `,   ; |    '  '  .   \\ \n";
				bp::tools::consoleCoordinates(x, y + 6);
				cout << "     `; __`  ,'__  ` ,  ` ;  |      ;        \\ \n";
				bp::tools::consoleCoordinates(x, y + 7);
				cout << "     ; (6_);  (6_) ; |   ,    \        '      | \n";
				bp::tools::consoleCoordinates(x, y + 8);
				cout << "    ;;   _,' ,.    ` `,   '    `-._           |   __//_________ \n";
				bp::tools::consoleCoordinates(x, y + 9);
				cout << "     ,;.=..`_..=.,' -'          ,''        _,--''------'''' \n";
				bp::tools::consoleCoordinates(x, y + 10);
				cout << "   __\,`\"=, , , == \"',___,,,-----\'\'\'----'_'_'_''-;'' \n";
				bp::tools::consoleCoordinates(x, y + 11);
				cout << "-----------------------''''''\ \'''''   )   /' \n";
				bp::tools::consoleCoordinates(x, y + 12);
				cout << "                              `\\`,,,___/__/'_____, \n";
				bp::tools::consoleCoordinates(x, y + 13);
				cout << "                                `--,,,--,-,'''\\ \n";
				bp::tools::consoleCoordinates(x, y + 14);
				cout << "                               __,,-' /'       ` \n";
				bp::tools::consoleCoordinates(x, y + 15);
				cout << "                             /'_,,--'' \n";
				bp::tools::consoleCoordinates(x, y + 16);
				cout << "                            | ( \n";
				bp::tools::consoleCoordinates(x, y + 17);
				cout << "                             `' \n";

			}

			// Function that displays cow figure for result breeding
			void resultCow(int x, int y)
			{
				bp::tools::consoleCoordinates(x, y);
				cout << "                _                _ \n";
				bp::tools::consoleCoordinates(x, y + 1);
				cout << "              /` \\              / `\\ \n";
				bp::tools::consoleCoordinates(x, y + 2);
				cout << "              \\  |              |  / \n";
				bp::tools::consoleCoordinates(x, y + 3);
				cout << "               ) /     ,   ,    \\ ( \n";
				bp::tools::consoleCoordinates(x, y + 4);
				cout << "              /  | .)-` (-'.'\\-. |  \\ \n";
				bp::tools::consoleCoordinates(x, y + 5);
				cout << "              |  )` . '  ,:   ' `<  | \n";
				bp::tools::consoleCoordinates(x, y + 6);
				cout << "         _..--\\ .' ' : .   ' :   `. /--.._ \n";
				bp::tools::consoleCoordinates(x, y + 7);
				cout << "    _.-\"_.._  `> :, ;  ' ; ' < , _.._\"-._\" - ._ \n";
				bp::tools::consoleCoordinates(x, y + 8);
				cout << "     '._     `-.; . '   :  '   ,  '.-`     _.' \n";
				bp::tools::consoleCoordinates(x, y + 9);
				cout << "        `-.__.-' `./|/`-.)`-./`-.< '-.__.-' \n";
				bp::tools::consoleCoordinates(x, y + 10);
				cout << "             /     '.    `    .'     \\ \n";
				bp::tools::consoleCoordinates(x, y + 11);
				cout << "            | ,--.   \\       /   .--, | \n";
				bp::tools::consoleCoordinates(x, y + 12);
				cout << "            | |.--\\   \\     /   /--.| | \n";
				bp::tools::consoleCoordinates(x, y + 13);
				cout << "            | \\( o|    :   :    | o)/ | \n";
				bp::tools::consoleCoordinates(x, y + 14);
				cout << "            \\  `--'    :   :    '--`  / \n";
				bp::tools::consoleCoordinates(x, y + 15);
				cout << "             \\         :   :         / \n";
				bp::tools::consoleCoordinates(x, y + 16);
				cout << "              \\        ;   ;        /| \n";
				bp::tools::consoleCoordinates(x, y + 17);
				cout << "              /'.  _../     \\.._  .'_/ \n";
				bp::tools::consoleCoordinates(x, y + 18);
				cout << "              |`)'`   `'---'`   `'(  | \n";
				bp::tools::consoleCoordinates(x, y + 19);
				cout << "              \\_| ('-.       .-') |__/ \n";
				bp::tools::consoleCoordinates(x, y + 20);
				cout << "              | `\\ `\"`       `\"` /   | \n";
				bp::tools::consoleCoordinates(x, y + 21);
				cout << "              \\__/'.__.-'`'-.__.'\\__/ \n";
				bp::tools::consoleCoordinates(x, y + 22);
				cout << "              |  |    `-...-'   /` | \n";
				bp::tools::consoleCoordinates(x, y + 23);
				cout << "               \\_;--.         .-\\__/ \n";
				bp::tools::consoleCoordinates(x, y + 24);
				cout << "                 \\__/`-.__.--/  _/ \n";
				bp::tools::consoleCoordinates(x, y + 25);
				cout << "                   '.__(  )_.'-' \n";

			}

			// Function that displays horse figure for result breeding
			void resultHorse(int x, int y)
			{
				bp::tools::consoleCoordinates(x, y);
				cout << "                                 |\\    /| \n";
				bp::tools::consoleCoordinates(x, y + 1);
				cout << "                              ___| \\,,/_/ \n";
				bp::tools::consoleCoordinates(x, y + 2);
				cout << "                           ---__/ \\/    \\ \n";
				bp::tools::consoleCoordinates(x, y + 3);
				cout << "                          __--/     (D)  \\ \n";
				bp::tools::consoleCoordinates(x, y + 4);
				cout << "                          _ -/    (_      \\ \n";
				bp::tools::consoleCoordinates(x, y + 5);
				cout << "                         // /       \\_ / ==\\ \n";
				bp::tools::consoleCoordinates(x, y + 6);
				cout << "   __-------_____--___--/           / \\_ O o) \n";
				bp::tools::consoleCoordinates(x, y + 7);
				cout << "  /                                 /   \\==/ \n";
				bp::tools::consoleCoordinates(x, y + 8);
				cout << " /                                 / \n";
				bp::tools::consoleCoordinates(x, y + 9);
				cout << "||          )                   \\_/\\ \n";
				bp::tools::consoleCoordinates(x, y + 10);
				cout << "||         /              _      /  | \n";
				bp::tools::consoleCoordinates(x, y + 11);
				cout << "| |      /--______      ___\\    /\\  : \n";
				bp::tools::consoleCoordinates(x, y + 12);
				cout << "| /   __-  - _/   ------    |  |   \\_\\ \n";
				bp::tools::consoleCoordinates(x, y + 13);
				cout << " |   -  -   /                | |    \\ ) \n";
				bp::tools::consoleCoordinates(x, y + 14);
				cout << " |  |   -  |                 | )    | | \n";
				bp::tools::consoleCoordinates(x, y + 15);
				cout << "  | |    | |                 | |    | | \n";
				bp::tools::consoleCoordinates(x, y + 16);
				cout << "  | |    < |                 | |   |_/ \n";
				bp::tools::consoleCoordinates(x, y + 17);
				cout << "  < |    /__\\                <  \\ \n";
				bp::tools::consoleCoordinates(x, y + 18);
				cout << "  /__\\                       /___\\ \n";
			}

			// Function that displays goat figure for result breeding
			void resultGoat(int x, int y)
			{
				bp::tools::consoleCoordinates(x, y);
				cout << "             / /";
				bp::tools::consoleCoordinates(x, y + 1);
				cout << "          (\\/_//`)";
				bp::tools::consoleCoordinates(x, y + 2);
				cout << "           /   '/";
				bp::tools::consoleCoordinates(x, y + 3);
				cout << "          0  0   \\";
				bp::tools::consoleCoordinates(x, y + 4);
				cout << "         /        \\";
				bp::tools::consoleCoordinates(x, y + 5);
				cout << "        /    __/   \\";
				bp::tools::consoleCoordinates(x, y + 6);
				cout << "       /,  _/ \\     \\_";
				bp::tools::consoleCoordinates(x, y + 7);
				cout << "       `-./ )  |     ~^~^~^~^~^~^~^~\\~.";
				bp::tools::consoleCoordinates(x, y + 8);
				cout << "           (   /                     \\_}";
				bp::tools::consoleCoordinates(x, y + 9);
				cout << "              |               /      |";
				bp::tools::consoleCoordinates(x, y + 10);
				cout << "              ;     |         \      /";
				bp::tools::consoleCoordinates(x, y + 11);
				cout << "               \\/ ,/           \\    |";
				bp::tools::consoleCoordinates(x, y + 12);
				cout << "               / /~~|~|~~~~~~|~|\\   |";
				bp::tools::consoleCoordinates(x, y + 13);
				cout << "              / /   | |      | | `\\ \\";
				bp::tools::consoleCoordinates(x, y + 14);
				cout << "             / /    | |      | |   \\ \\";
				bp::tools::consoleCoordinates(x, y + 15);
				cout << "            / (     | |      | |    \\ \\";
				bp::tools::consoleCoordinates(x, y + 16);
				cout << "           /,_)    /__)     /__)   /,_/";
			}

		}

		namespace menuParts
		{
			// Function that displays label for animal breeding menu
			void label(int x, int y)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
				bp::tools::consoleCoordinates(x, y);
				cout << "______                   _ _   ";
				bp::tools::consoleCoordinates(x, y + 1);
				cout << "| ___ \\                 | (_) ";
				bp::tools::consoleCoordinates(x, y + 2);
				cout << "| |_/ /_ __ ___  ___  __| |_ _ __   __ _";
				bp::tools::consoleCoordinates(x, y + 3);
				cout << "| ___ \\ '__/ _ \\/ _ \\/ _` | | '_ \\ / _` |";
				bp::tools::consoleCoordinates(x, y + 4);
				cout << "| |_/ / | |  __/  __/ (_| | | | | | (_| |";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
				bp::tools::consoleCoordinates(x, y + 5);
				cout << "\\____/|_|  \\___|\\___|\\__,_|_|_| |_|\\__, |";
				bp::tools::consoleCoordinates(x, y + 6);
				cout << "                                    __/ |";
				bp::tools::consoleCoordinates(x, y + 7);
				cout << "                                   |___/ ";
			}

			// Function that displays border for animal breeding menu
			void border(int x, int y)
			{
				for (int i = 0; i < 42; i++)
				{
					bp::tools::consoleCoordinates(x, y);
					cout << "(*)\n";
					y++;
				}

			}
		}
	}

	namespace plantsSeeding
	{
		// Function that displays plant seeding menu
		void menuPlantsSeeding()
		{
			bp::tools::setConsoleSize();
			bp::consoleApp::plantsSeeding::plantsFigures::tomato(3, 2);
			bp::consoleApp::plantsSeeding::plantsFigures::pear(1, 20);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
			bp::consoleApp::plantsSeeding::menuParts::border(40, 0);
			bp::consoleApp::plantsSeeding::menuParts::label(50, 2);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
			bp::consoleApp::plantsSeeding::menuParts::border(95, 0);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			bp::consoleApp::plantsSeeding::plantsFigures::coconutTree(100, 4);
		}

		// Function that displays plants sort
		void plantOption(int x, int y)
		{
			bp::tools::consoleCoordinates(x, y);
			cout << "Choose what sort of plants you want to seed:";
			bp::tools::consoleCoordinates(x + 12, y + 2);
			cout << "    Tomatoes";
			bp::tools::consoleCoordinates(x + 12, y + 4);
			cout << "    Cucumbers";
			bp::tools::consoleCoordinates(x + 12, y + 6);
			cout << "    Coconuts";
			bp::tools::consoleCoordinates(x + 12, y + 8);
			cout << "    Pears";
			bp::tools::consoleCoordinates(x + 12, y + 10);
			cout << "    Apples";
		}

		// Functions that displays plants
		void sortOption(int choice)
		{
			switch (choice)
			{
			case 1:
			{
				bp::tools::consoleCoordinates(52, 20);
				cout << "CHOOSE WHAT SORT YOUR TOMATOES ARE:\n";
				bp::tools::consoleCoordinates(62, 22);
				cout << "Roma Tomatoes\n";
				bp::tools::consoleCoordinates(62, 24);
				cout << "Cherry Tomatoes\n";
			}break;
			case 2:
			{
				bp::tools::consoleCoordinates(52, 20);
				cout << "CHOOSE WHAT SORT YOUR CUCUMBERS ARE:\n";
				bp::tools::consoleCoordinates(62, 22);
				cout << "Gherkins\n";
				bp::tools::consoleCoordinates(62, 24);
				cout << "Slicing cucumber\n";
			}break;
			case 3:
			{
				bp::tools::consoleCoordinates(52, 20);
				cout << "CHOOSE WHAT SORT YOUR COCONUTS ARE: \n";
				bp::tools::consoleCoordinates(62, 22);
				cout << "Fiji Dwarf\n";
				bp::tools::consoleCoordinates(62, 24);
				cout << "Golden Malay\n";
			}break;
			case 4:
			{
				bp::tools::consoleCoordinates(52, 20);
				cout << "CHOOSE WHAT SORT YOUR PEARS ARE: \n";
				bp::tools::consoleCoordinates(62, 22);
				cout << "Asian pear\n";
				bp::tools::consoleCoordinates(62, 24);
				cout << "Bartlett pear\n";
			}break;
			case 5:
			{
				bp::tools::consoleCoordinates(52, 20);
				cout << "CHOOSE WHAT SORT YOUR APPLES ARE: \n";
				bp::tools::consoleCoordinates(62, 22);
				cout << "Fuji\n";
				bp::tools::consoleCoordinates(62, 24);
				cout << "Granny Smith\n";
			}break;
			}
		}

		// Function that gives user a choice for number of grains and displays the result 
		void howManyGrains(string sort)
		{
			bp::tools::consoleCoordinates(50, 20);
			cout << "CHOOSE HOW MANY GRAINS YOU WILL SEED:";
			bp::tools::consoleCoordinates(50, 21);
			int grains;
			cin >> grains;
			
			bp::dal::population::editPopulationPlants(grains);
			system("CLS");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			bp::consoleApp::plantsSeeding::menuParts::border(36, 0);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			bp::consoleApp::plantsSeeding::menuParts::congratulationsLabel(41, 2);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			bp::consoleApp::plantsSeeding::menuParts::border(122, 0);

			bp::tools::consoleCoordinates(58, 20);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			string resultSort = bp::tools::toUpper(sort);
			string text = "YOU HAVE SEED " + to_string(grains) + " GRAINS FROM " + resultSort;
			bp::tools::slowmotionOfScreenplay(text);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			bp::tools::loadingBar(67, 30);

			bp::consoleApp::planetPopulation::planetPopulation();
		}

		namespace plantsFigures
		{
			// Function that displays tomato figure
			void tomato(int x, int y)
			{

				bp::tools::consoleCoordinates(x, y);
				cout << "                   ,";
				bp::tools::consoleCoordinates(x, y + 1);
				cout << "                  /.\\";
				bp::tools::consoleCoordinates(x, y + 2);
				cout << "                 //_`\\";
				bp::tools::consoleCoordinates(x, y + 3);
				cout << "            _.-`| \\ ``._";
				bp::tools::consoleCoordinates(x, y + 4);
				cout << "        .-''`-.       _.'`.";
				bp::tools::consoleCoordinates(x, y + 5);
				cout << "      .'      / /'\\/`.\\    `.";
				bp::tools::consoleCoordinates(x, y + 6);
				cout << "     /   .    |/         `.  \\";
				bp::tools::consoleCoordinates(x, y + 7);
				cout << "    '   /                  \\  ;";
				bp::tools::consoleCoordinates(x, y + 8);
				cout << "   :   '            \\       : :";
				bp::tools::consoleCoordinates(x, y + 9);
				cout << "   ;  ;             ;      /  .";
				bp::tools::consoleCoordinates(x, y + 10);
				cout << "    ' :             .     '  /";
				bp::tools::consoleCoordinates(x, y + 11);
				cout << "     \\ \\           /       .'";
				bp::tools::consoleCoordinates(x, y + 12);
				cout << "      `.`        .'      .'";
				bp::tools::consoleCoordinates(x, y + 13);
				cout << "        `-..___....----`";
			}

			// Function that displays pear figure
			void coconutTree(int x, int y)
			{
				bp::tools::consoleCoordinates(x, y);
				cout << "                           #####";
				bp::tools::consoleCoordinates(x, y + 1);
				cout << "                       #######";
				bp::tools::consoleCoordinates(x, y + 2);
				cout << "            ######    ########       #####";
				bp::tools::consoleCoordinates(x, y + 3);
				cout << "        ###########/#####\\#####  #############";
				bp::tools::consoleCoordinates(x, y + 4);
				cout << "    ############/##########--#####################";
				bp::tools::consoleCoordinates(x, y + 5);
				cout << "  ####         ######################          #####";
				bp::tools::consoleCoordinates(x, y + 6);
				cout << " ##          ####      ##########/@@              ###";
				bp::tools::consoleCoordinates(x, y + 7);
				cout << "#          ####        ,-.##/`.#\\#####               ##";
				bp::tools::consoleCoordinates(x, y + 8);
				cout << "          ###         /  |$/  |,-. ####                 #";
				bp::tools::consoleCoordinates(x, y + 9);
				cout << "         ##           \\_,'$\\_,'|  \\  ###";
				bp::tools::consoleCoordinates(x, y + 10);
				cout << "         #              \\_$$$$$`._/   ##";
				bp::tools::consoleCoordinates(x, y + 11);
				cout << "                          $$$$$_/     ##";
				bp::tools::consoleCoordinates(x, y + 12);
				cout << "                          $$$$$ ";
				bp::tools::consoleCoordinates(x, y + 13);
				cout << "                          $$$$$ ";
				bp::tools::consoleCoordinates(x, y + 14);
				cout << "                          $$$$$ ";
				bp::tools::consoleCoordinates(x, y + 15);
				cout << "                          $$$$$ ";
				bp::tools::consoleCoordinates(x, y + 16);
				cout << "                          $$$$$ ";
				bp::tools::consoleCoordinates(x, y + 17);
				cout << "                          $$$$$ ";
				bp::tools::consoleCoordinates(x, y + 18);
				cout << "                          $$$$$ ";
				bp::tools::consoleCoordinates(x, y + 19);
				cout << "                          $$$$$ ";
				bp::tools::consoleCoordinates(x, y + 20);
				cout << "                          $$$$$ ";
				bp::tools::consoleCoordinates(x, y + 21);
				cout << "                          $$$$$ ";
				bp::tools::consoleCoordinates(x, y + 22);
				cout << "                          $$$$$ ";
				bp::tools::consoleCoordinates(x, y + 23);
				cout << "                          $$$$$ ";
				bp::tools::consoleCoordinates(x, y + 24);
				cout << "                          $$$$$ ";
				bp::tools::consoleCoordinates(x, y + 25);
				cout << "                          $$$$$ ";
				bp::tools::consoleCoordinates(x, y + 26);
				cout << "                          $$$$$ ";
				bp::tools::consoleCoordinates(x, y + 27);
				cout << "                          $$$$$ ";
				bp::tools::consoleCoordinates(x, y + 28);
				cout << "                          $$$$$ ";
				bp::tools::consoleCoordinates(x, y + 29);
				cout << "                          $$$$$ ";
				bp::tools::consoleCoordinates(x, y + 30);
				cout << "                          $$$$$ ";
			}

			// Function that displays coconut tree figure
			void pear(int x, int y)
			{
				bp::tools::consoleCoordinates(x, y);
				cout << "                     /)";
				bp::tools::consoleCoordinates(x, y + 1);
				cout << "                 ,.//,";
				bp::tools::consoleCoordinates(x, y + 2);
				cout << "                /` `'` `\\";
				bp::tools::consoleCoordinates(x, y + 3);
				cout << "               :         :";
				bp::tools::consoleCoordinates(x, y + 4);
				cout << "              :           :";
				bp::tools::consoleCoordinates(x, y + 5);
				cout << "             :             :";
				bp::tools::consoleCoordinates(x, y + 6);
				cout << "            :               :";
				bp::tools::consoleCoordinates(x, y + 7);
				cout << "           :                 ;";
				bp::tools::consoleCoordinates(x, y + 8);
				cout << "          :                   :";
				bp::tools::consoleCoordinates(x, y + 9);
				cout << "          ;                   ;";
				bp::tools::consoleCoordinates(x, y + 10);
				cout << "          ;                   ;";
				bp::tools::consoleCoordinates(x, y + 11);
				cout << "          :                   :";
				bp::tools::consoleCoordinates(x, y + 12);
				cout << "           \\                 /";
				bp::tools::consoleCoordinates(x, y + 13);
				cout << "            `._,.='``'-.,_,.`";
				bp::tools::consoleCoordinates(x, y + 14);
				cout << "              '-._  ~  _.-'";
				bp::tools::consoleCoordinates(x, y + 15);
				cout << "                 `'''`";
			}
		}

		namespace menuParts
		{
			// Function that displays congratulations label
			void congratulationsLabel(int x, int y)
			{
				bp::tools::consoleCoordinates(x, y);
				cout << "   _____                            _         _       _   _                 _ ";
				bp::tools::consoleCoordinates(x, y + 1);
				cout << "  / ____|                          | |       | |     | | (_)               | |";
				bp::tools::consoleCoordinates(x, y + 2);
				cout << " | |     ___  _ __   __ _ _ __ __ _| |_ _   _| | __ _| |_ _  ___  _ __  ___| |";
				bp::tools::consoleCoordinates(x, y + 3);
				cout << " | |    / _ \\| '_ \\ / _` | '__/ _` | __| | | | |/ _` | __| |/ _ \\| '_ \\/ __| |";
				bp::tools::consoleCoordinates(x, y + 4);
				cout << " | |___| (_) | | | | (_| | | | (_| | |_| |_| | | (_| | |_| | (_) | | | \\__ \\_|";
				bp::tools::consoleCoordinates(x, y + 5);
				cout << "  \\_____\\___/|_| |_|\\__, |_|  \\__,_|\\__|\\__,_|_|\\__,_|\\__|_|\\___/|_| |_|___(_)";
				bp::tools::consoleCoordinates(x, y + 6);
				cout << "                     __/ |";
				bp::tools::consoleCoordinates(x, y + 7);
				cout << "                    |___/";
			}

			// Function that displays border for plants seeding menu
			void border(int x, int y)
			{
				for (int i = 0; i < 36; i++)
				{
					bp::tools::consoleCoordinates(x, y);
					cout << "(*)\n";
					y++;
				}

			}

			// Function that displays label for plants seeding menu
			void label(int x, int y)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
				bp::tools::consoleCoordinates(x, y);
				cout << " _____               _ _ ";
				bp::tools::consoleCoordinates(x, y + 1);
				cout << "/  ___|             | (_)";
				bp::tools::consoleCoordinates(x, y + 2);
				cout << "\\ `--.  ___  ___  __| |_ _ __   __ _ ";
				bp::tools::consoleCoordinates(x, y + 3);
				cout << " `--. \\/ _ \\/ _ \\/ _` | | '_ \\ / _` |";
				bp::tools::consoleCoordinates(x, y + 4);
				cout << "/\\__/ /  __/  __/ (_| | | | | | (_| |";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
				bp::tools::consoleCoordinates(x, y + 5);
				cout << "\\____/ \\___|\\___|\\__,_|_|_| |_|\\__, |";
				bp::tools::consoleCoordinates(x, y + 6);
				cout << "                                __/ |";
				bp::tools::consoleCoordinates(x, y + 7);
				cout << "                               |___/";
			}
		}
	}

	namespace planetPopulation
	{
		// Function for displaying planet population
		void planetPopulation()
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			system("CLS");
			bp::type::frames::FRAME frame;
			bp::dal::frames::readFrameFromFile(&frame);
			cout << frame.nine;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			bp::tools::consoleCoordinates(15, 46);
			cout << "ANIMALS: " << bp::dal::population::populationAnimal();

			bp::tools::consoleCoordinates(15, 48);
			cout << "PLANTS: " << bp::dal::population::populationPlant();

			bp::tools::consoleCoordinates(95, 47);
			cout << "If you want to breed or seed press CTRL + B";

			switch (_getch())
			{
			case CTRL_KEYPRESS('b'):
			{
				system("CLS");
				bp::consoleApp::menuInputs::plantsAndAnimalsMenu();
			}break;
			case CTRL_KEYPRESS('e'):
			{
				bp::consoleApp::menuInputs::menu();
			}break;
			}
		}
	}

	namespace biologyContent
	{
		namespace showInformation
		{
			// Display name of all animals
			void displayAnimals(bp::type::characteristics::ANIMAL* head, int x, int y)
			{
				bp::type::characteristics::ANIMAL* temp = head;

				int indexOfCurrentAnimal = 1;
				while (temp)
				{
					bp::tools::consoleCoordinates(x, y);
					cout << indexOfCurrentAnimal << ". " << temp->name;
					y += 3;
					indexOfCurrentAnimal++;
					cout << endl;
					temp = temp->next;
				}

			}

			// Display name of all plants
			void displayPlants(bp::type::characteristics::PLANTS* head, int x, int y)
			{
				bp::type::characteristics::PLANTS* temp = head;
				int indexOfCurrentPlant = 1;
				while (temp)
				{
					bp::tools::consoleCoordinates(x, y);
					cout << indexOfCurrentPlant << ". " << temp->name << endl;
					y += 3;
					indexOfCurrentPlant++;
					cout << endl;
					temp = temp->next;
				}

			}

			// Display information for specific animal
			void displayInfoAnimal(bp::type::characteristics::ANIMAL* head, int indexOfWantedAnimal, int x, int y)
			{
				int indexOfCurrentAnimal = 1;

				bp::type::characteristics::ANIMAL* temp = head;
				while (temp)
				{
					if (indexOfWantedAnimal == indexOfCurrentAnimal)
					{
						bp::tools::consoleCoordinates(x, y - 1);
						cout << "Name: " << temp->name << endl;
						bp::tools::consoleCoordinates(x, y + 1);
						cout << "Phylum: " << temp->animal.Phylum << endl;
						bp::tools::consoleCoordinates(x, y + 3);
						cout << "Class: " << temp->animal.Class << endl;
						bp::tools::consoleCoordinates(x, y + 5);
						cout << "Order: " << temp->animal.Order << endl;
						bp::tools::consoleCoordinates(x, y + 7);
						cout << "Family: " << temp->animal.Family << endl;
						bp::tools::consoleCoordinates(x, y + 9);
						cout << "Genus: " << temp->animal.Genus << endl;
						bp::tools::consoleCoordinates(x, y + 11);
						cout << "Species: " << temp->animal.Species << endl;
						bp::tools::consoleCoordinates(x, y + 13);
						cout << "Average high of male " << temp->name << ": " << temp->high.averageMaleHigh << endl;
						bp::tools::consoleCoordinates(x, y + 15);
						cout << "Average high of female " << temp->name << ": " << temp->high.averageFemaleHigh << endl;
						bp::tools::consoleCoordinates(x, y + 17);
						cout << "Average wieght of male " << temp->name << ": " << temp->weight.averageMaleWieght << endl;
						bp::tools::consoleCoordinates(x, y + 19);
						cout << "Average wieght of female " << temp->name << ": " << temp->weight.averageFemaleWieght << endl;
						break;
					}
					indexOfCurrentAnimal++;
					temp = temp->next;
				}
				switch (_getch())
				{
				case KEY_ESCAPE:
					system("CLS");
					quiz::outputBorder(0);
					displayAnimals(head, 70, 16);
					break;
				}
			}

			// Display information for specific plant
			void displayInfoPlants(bp::type::characteristics::PLANTS* head, int indexOfWantedPlant, int x, int y)
			{
				int indexOfCurrentPlant = 1;

				bp::type::characteristics::PLANTS* temp = head;
				while (temp)
				{
					if (indexOfWantedPlant == indexOfCurrentPlant)
					{
						bp::tools::consoleCoordinates(x, y - 1);
						cout << "Name: " << temp->name << endl;
						bp::tools::consoleCoordinates(x, y + 1);
						cout << "Phylum: " << temp->plant.Phylum << endl;
						bp::tools::consoleCoordinates(x, y + 3);
						cout << "Class: " << temp->plant.Class << endl;
						bp::tools::consoleCoordinates(x, y + 5);
						cout << "Order: " << temp->plant.Order << endl;
						bp::tools::consoleCoordinates(x, y + 7);
						cout << "Family: " << temp->plant.Family << endl;
						bp::tools::consoleCoordinates(x, y + 9);
						cout << "Genus: " << temp->plant.Genus << endl;
						bp::tools::consoleCoordinates(x, y + 11);
						cout << "Species: " << temp->plant.Species << endl;
						break;
					}
					indexOfCurrentPlant++;
					temp = temp->next;
				}
				switch (_getch())
				{
				case KEY_ESCAPE:
					system("CLS");
					quiz::outputBorder(0);
					displayPlants(head, 70, 16);
					break;
				}
			}
		}

		namespace search
		{
			// Display information for all animals with searched word ot other
			void displaySearchedInfoForAnimals(bp::type::characteristics::ANIMAL* head, int indexOfWantedAnimal)
			{
				int indexOfCurrentAnimal = 1;

				bp::type::characteristics::ANIMAL* temp = head;
				while (temp)
				{
					if (indexOfWantedAnimal == indexOfCurrentAnimal)
					{
						cout << "Name: " << temp->name << endl;
						cout << "Phylum: " << temp->animal.Phylum << endl;
						cout << "Class: " << temp->animal.Class << endl;
						cout << "Order: " << temp->animal.Order << endl;
						cout << "Family: " << temp->animal.Family << endl;
						cout << "Genus: " << temp->animal.Genus << endl;
						cout << "Species: " << temp->animal.Species << endl;
						cout << "Average high of male " << temp->name << ": " << temp->high.averageMaleHigh << endl;
						cout << "Average high of female " << temp->name << ": " << temp->high.averageFemaleHigh << endl;
						cout << "Average wieght of male" << temp->name << ": " << temp->weight.averageMaleWieght << endl;
						cout << "Average wieght of female" << temp->name << ": " << temp->weight.averageFemaleWieght << endl;
						break;
					}
					indexOfCurrentAnimal++;
					temp = temp->next;
				}
			}

			// Display information for all plants with searched word ot other
			void displaySearchedInfoForPlants(bp::type::characteristics::PLANTS* head, int indexOfWantedPlant)
			{
				int indexOfCurrentPlant = 1;

				bp::type::characteristics::PLANTS* temp = head;
				while (temp)
				{
					if (indexOfWantedPlant == indexOfCurrentPlant)
					{
						cout << "Name: " << temp->name << endl;
						cout << "Phylum: " << temp->plant.Phylum << endl;
						cout << "Class: " << temp->plant.Class << endl;
						cout << "Order: " << temp->plant.Order << endl;
						cout << "Family: " << temp->plant.Family << endl;
						cout << "Genus: " << temp->plant.Genus << endl;
						cout << "Species: " << temp->plant.Species << endl;
						break;
					}
					indexOfCurrentPlant++;
					temp = temp->next;
				}
			}

			// Search given word or other in linked list of type PLANTS
			void searchP(bp::type::characteristics::PLANTS* head, string str)
			{
				bp::type::characteristics::PLANTS* temp = head;
				int indexOfFoundPlant = 0;
				int indexOfCurrentPlant = 0;
				while (temp)
				{
					indexOfCurrentPlant++;
					if (bp::bll::biologyContent::foundOrNotInString(temp->name, str) ||
						bp::bll::biologyContent::foundOrNotInString(temp->plant.Class, str) ||
						bp::bll::biologyContent::foundOrNotInString(temp->plant.Family, str) ||
						bp::bll::biologyContent::foundOrNotInString(temp->plant.Genus, str) ||
						bp::bll::biologyContent::foundOrNotInString(temp->plant.Order, str) ||
						bp::bll::biologyContent::foundOrNotInString(temp->plant.Phylum, str) ||
						bp::bll::biologyContent::foundOrNotInString(temp->plant.Species, str))
					{
						indexOfFoundPlant++;
						cout << indexOfFoundPlant << ". " << temp->name << endl;
						displaySearchedInfoForPlants(head, indexOfCurrentPlant);
					}
					temp = temp->next;
				}
				if (indexOfFoundPlant == 0)
				{
					cout << "Nothing found" << endl;
					cout << endl;
				}
			}

			// Search given word or other in linked list of type ANIMAL
			void searchA(bp::type::characteristics::ANIMAL* head, string str)
			{
				bp::type::characteristics::ANIMAL* temp = head;
				int indexOfFoundAnimal = 0;
				int indexOfCurrentAnimal = 0;
				while (temp)
				{
					indexOfCurrentAnimal++;
					if (bp::bll::biologyContent::foundOrNotInString(temp->name, str) ||
						bp::bll::biologyContent::foundOrNotInString(temp->animal.Class, str) ||
						bp::bll::biologyContent::foundOrNotInString(temp->animal.Family, str) ||
						bp::bll::biologyContent::foundOrNotInString(temp->animal.Genus, str) ||
						bp::bll::biologyContent::foundOrNotInString(temp->animal.Order, str) ||
						bp::bll::biologyContent::foundOrNotInString(temp->animal.Phylum, str) ||
						bp::bll::biologyContent::foundOrNotInString(temp->animal.Species, str) ||
						bp::bll::biologyContent::foundOrNotDouble(temp->high.averageFemaleHigh, str) ||
						bp::bll::biologyContent::foundOrNotDouble(temp->high.averageMaleHigh, str) ||
						bp::bll::biologyContent::foundOrNotDouble(temp->weight.averageFemaleWieght, str) ||
						bp::bll::biologyContent::foundOrNotDouble(temp->weight.averageMaleWieght, str))
					{
						indexOfFoundAnimal++;
						cout << indexOfFoundAnimal << ". " << temp->name << endl;
						displaySearchedInfoForAnimals(head, indexOfCurrentAnimal);
					}
					temp = temp->next;
				}
				if (indexOfFoundAnimal == 0)
				{
					cout << "Nothing found" << endl;
					cout << endl;
				}
			}
		}
	}
}