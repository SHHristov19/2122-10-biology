#pragma once
#include "pch.h"

namespace bp::tools
{
    // Function for displaying text in given console coordinates
    void consoleCoordinates(int x, int y);

    // Function for outputing the console in given size
    void setConsoleSize();

    // Function for displaying text slowly
    void slowmotionOfScreenplay(std::string screenplay);

    // Function for displaying text with username slowly 
    void slowmotionOfScreenplayWithUsername(string screenplay, string usernaem);

    // Function for loading bar
    void loadingBar(int x, int y);

    // Function that converts string from lower letters to upper letters
    string toUpper(string text);
}