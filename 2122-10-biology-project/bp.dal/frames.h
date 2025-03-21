#pragma once
#include "pch.h"
#include "..\bp.types\types.h"

namespace bp::dal
{
    namespace frames
    {
        // Function for reading data from file
        void readFrameFromFile(bp::type::frames::FRAME* frame);
    }
}