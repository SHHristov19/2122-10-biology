// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

// add headers that you want to pre-compile here
#include <string>
#include <windows.h>
#include <conio.h>
#include <vector>
#include <iostream>

using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define	KEY_ENTER 13
#define KEY_ESCAPE 27
#define KEY_ONE 49
#define KEY_TWO 50
#define KEY_THREE 51
#define KEY_FOUR 52
#define KEY_FIVE 53
#define KEY_SIX 54
#define CTRL_KEYPRESS(k) ((k)  & 0x1f)
#endif //PCH_H
