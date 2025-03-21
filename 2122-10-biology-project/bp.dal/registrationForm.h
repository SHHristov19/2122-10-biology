#pragma once
#include "pch.h"

namespace bp::dal
{
	namespace registrationForm
	{
		// Function for login as player
		void loginAsPlayer(string* username);

		// Function for registration as player
		void registrationPlayer();

		// Function for changing password
		bool changePasswordPlayer();
	}
}