#pragma once
#ifndef RAYLIBSTARTER_MASTERHEAD_H
#define RAYLIBSTARTER_MASTERHEAD_H
#include "raylib.h"
#include "raymath.h"
#include "../Library/tileson.hpp"

void to_zeichnen_auf_den_Bildschirm(tson::Map *theMap, Texture &mapTex);

enum globalState{
    mainMenu,
    gameplay,
    settings,
    pause
};

#endif //RAYLIBSTARTER_MASTERHEAD_H