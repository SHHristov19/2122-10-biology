#pragma once
#include "pch.h"
#include "..\bp.types\types.h"

namespace bp::consoleApp
{
    namespace frames
    {
        // Output guide function
        void outputGuide();

        namespace output
        {
            // Output zero frame
            void zeroFrame(string username);

            // Output first frame
            void firstFrame(bp::type::frames::FRAME frame);

            // Output second frame
            void secondFrame(bp::type::frames::FRAME frame);

            // Output third frame
            void thirdFrame(bp::type::frames::FRAME frame);

            // Output fourth frame
            void fourthFrame(bp::type::frames::FRAME frame);

            // Output fifth frame
            void fifthFrame(bp::type::frames::FRAME frame);

            // Output sixt frame
            void sixthFrame();

            // Output frame after quiz
            void quizFrame(bp::type::frames::FRAME frame);

            // Output seventh frame
            void seventhFrame();

            // Output eight frame
            void eightFrame(bp::type::frames::FRAME frame);

            // Output ninth frame
            void ninthFrame(bp::type::frames::FRAME frame);
        }
    }

}