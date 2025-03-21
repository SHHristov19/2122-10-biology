#pragma once
#include "menuInputs.h"

namespace bp::consoleApp
{
	namespace registrationForm
	{
		namespace outputEntryWindows
		{
			//Output login admin panel
			void loginAsAdmin();

			//Output login player panel
			void loginAsPlayer();

			//Output registration panel
			void registration();

			//Output change password panel
			void checkPassword();

			//Output successfully login panel
			void successfullyLogin();

			//Output successfully register panel
			void succcessfullyRegister();

			//Output try again panel
			void tryAgain();

			//Output How to play panel
			void howToPlay();
		}

		//Function for login as admin
		void loginAsAdmin();
	}
}