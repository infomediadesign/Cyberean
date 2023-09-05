#pragma once
#ifndef RAYLIBSTARTER_MASTERHEAD_H
#define RAYLIBSTARTER_MASTERHEAD_H

#include "raylib.h"
#include "raymath.h"
#include "../Library/tileson.hpp"

void toDrawOnScreen(tson::Map *theMap, Texture &mapTex);

enum globalState {
    mainMenu,
    gameplay,
    levelselection,
    pause,
    creditsscreen,
    cutscenescreen
};

extern int masterlevel;

#endif //RAYLIBSTARTER_MASTERHEAD_H