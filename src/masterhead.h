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
    cutscenescreen,
    storymodesection,
};

extern int masterlevel;

extern int storystate;

extern bool fadeeffectin;

extern bool fadeeffectout;

extern bool storymodeactive;

#endif //RAYLIBSTARTER_MASTERHEAD_H