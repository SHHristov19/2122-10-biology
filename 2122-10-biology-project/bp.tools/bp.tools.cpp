#include "pch.h"
#include "extraFunctions.h"

namespace bp::tools
{
    // Function for displaying text in given console coordinates
    void consoleCoordinates(int x, int y)
    {
        COORD c;
        c.X = x;
        c.Y = y;

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
    }

    // Function for outputing the console in given size
    void setConsoleSize()
    {
        HWND console = GetConsoleWindow();
        MoveWindow(console, 280, 75, 1300, 910, TRUE);
    }

    // Function for displaying text slowly
    void slowmotionOfScreenplay(string screenplay)
    {
        for (int i = 0; i < screenplay.length(); i++)
        {
            cout << screenplay[i];
            Sleep(50);
        }
        cout << endl;
    }

    // Function for displaying text with username slowly 
    void slowmotionOfScreenplayWithUsername(string screenplay, string usernaem)
    {

        for (int i = 0; i < screenplay.length(); i++)
        {
            if (screenplay[i] == '&')
            {
                cout << "\"";
                cout << "\x1b[1;36m";
                for (int j = 0; j < usernaem.length(); j++)
                {
                    cout << usernaem[j];
                    Sleep(50);
                }
                cout << "\x1b[0m";
                cout << "\"";
                screenplay.erase(i, 1);
            }
            cout << screenplay[i];
            Sleep(50);
        }
        cout << endl;
    }

    // Function for loading bar
    void loadingBar(int x, int y)
    {
        int a = 177, b = 219;

        consoleCoordinates(x, y);
        cout << "Loading...";

        consoleCoordinates(x, y+1);
        for (int i = 0; i < 26; i++)
            printf("%c", a);

        consoleCoordinates(x, y+1);
        for (int i = 0; i < 26; i++) {
            printf("%c", b);

  
            Sleep(100);
        }
    }

    // Function that converts string from lower letters to upper letters
    string toUpper(string text)
    {
        string result = "";
        for (size_t i = 0; i < text.size(); i++)
        {
            result += toupper(text[i]);
        }
        return result;
    }
}

