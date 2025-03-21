#pragma once
#include "pch.h"
#include "..\bp.tools\extraFunctions.h"

namespace bp::consoleApp
{
    namespace quiz
    {
        namespace lives
        {
            //Output four heart current position
            void outputFourHearth();

            //Output three heart current position
            void outputThreeHearth();

            //Output two heart current position
            void outputTwoHearth();

            //Output one heart current position
            void outputOneHearth();
        }

        //Output string in current position
        void outputQuiz(int x, int y, string str);

        //Output text 'correct' in current position
        void outputCorrect(int x, int y);

        //Output text 'wrong' in current position
        void outputWrong(int x, int y);

        //Output text 'wrong' in current position
        void outputGameOver();

        //Output border for the  window in current position
        void outputBorder(int n);

        // Menu input for quiz
        void quiz();
    }
}