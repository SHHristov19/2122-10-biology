#pragma once

namespace bp::consoleApp
{
	namespace menus
	{
		namespace registrationFormMenu
		{
			//Display active buttons
			namespace activeButtons
			{
				void firstButton();			

				void secondButton();

				void thirdButton();

				void fourthButton();

				void fifthButton();
			}
			
			//Display inactive buttons
			namespace inactiveButtons
			{
				void firstButton();

				void secondButton();

				void thirdButton();

				void fourthButton();

				void fifthButton();
			}

			//Output menu according to active button
			void outputMenuWithFirstActiveButton();

			void outputMenuWithSecondActiveButton();

			void outputMenuWithThirdActiveButton();

			void outputMenuWithFourthActiveButton();

			void outputMenuWithFifthActiveButton();
		}

		namespace playMenu
		{
			//Display active buttons
			namespace activeButtons
			{
				void firstButton();

				void secondButton();

				void thirdButton();
			}

			//Display inactive buttons
			namespace inactiveButtons
			{
				void firstButton();

				void secondButton();

				void thirdButton();
			}

			//Output menu according to active button
			void outputMenuWithFirstActiveButton();

			void outputMenuWithSecondActiveButton();

			void outputMenuWithThirdActiveButton();
		}

		namespace plantsAnimalsAndQuizMenu
		{
			//Display active buttons
			namespace activeButtons
			{
				void firstButton();

				void secondButton();

				void thirdButton();
			}

			//Display inactive buttons
			namespace inactiveButtons
			{
				void firstButton();

				void secondButton();

				void thirdButton();
			}

			//Output menu according to active button
			void outputMenuWithFirstActiveButton();

			void outputMenuWithSecondActiveButton();

			void outputMenuWithThirdActiveButton();
		}

        namespace animalsAndPlantsMenu
        {
			//Output animals header
			void animalsHeader();

			//Output plants header
			void plantsHeader();

			//Display active buttons
            namespace activeButtons
            {
				void firstButton();

				void secondButton();

				void thirdButton();
            }

			//Display active buttons
            namespace inactiveButtons
            {
                void firstButton();

                void secondButton();

                void thirdButton();
            }
			
			//Output menu according to active animals button
            namespace animalsMenu
            {
                void outputMenuWithFirstActiveButton();

                void outputMenuWithSecondActiveButton();

                void outputMenuWithThirdActiveButton();
            }

			//Output menu according to active plants button
			namespace plantsMenu
			{
				void outputMenuWithFirstActiveButton();

				void outputMenuWithSecondActiveButton();

				void outputMenuWithThirdActiveButton();
			}
        }

        namespace choosePlantsOrAnimalsWithExitMenu
        {
			//Display active buttons
            namespace activeButtons
            {
				void firstButton();

				void secondButton();

				void thirdButton();
            }

			//Display active buttons
            namespace inactiveButtons
            {
				void firstButton();

				void secondButton();

                void thirdButton();
            }

			//Output menu according to active button
            void outputMenuWithFirstActiveButton();

            void outputMenuWithSecondActiveButton();

            void outputMenuWithThirdActiveButton();
        }

        namespace choosePlantsOrAnimalsMenu
        {
			//Display active buttons
            namespace activeButtons
            {
                void firstButton();

                void secondButton();
            }

			//Display active buttons
            namespace inactiveButtons
            {
                void firstButton();

                void secondButton();
            }

			//Output menu according to active button
            void outputMenuWithFirstActiveButton();

            void outputMenuWithSecondActiveButton();
        }

		namespace adminPanel
		{
			//Display active buttons
			namespace activeButtons
			{
				void firstButton();

				void secondButton();

				void thirdButton();

				void fourthButton();

				void fifthButton();
			}

			//Display active buttons
			namespace inactiveButtons
			{
				void firstButton();

				void secondButton();

				void thirdButton();

				void fourthButton();

				void fifthButton();
			}

			//Output menu according to active button
			void outputMenuWithFirstActiveButton();

			void outputMenuWithSecondActiveButton();

			void outputMenuWithThirdActiveButton();

			void outputMenuWithFourthActiveButton();

			void outputMenuWithFifthActiveButton();
		}
	}
}