//
// Created by lukas on 15.06.2023.
//

#ifndef RAYLIBSTARTER_GAMESZENE_H
#define RAYLIBSTARTER_GAMESZENE_H

#pragma once
#include "masterhead.h"
#include "player.h"
#include "gameobject.h"
#include "Enemy.h"
#include "../Library/tileson.hpp"
#include "musicplayer.h"

class gameScene {
public:
    std::unique_ptr<tson::Map> themap;
    std::vector<Enemy> enemies;
    std::vector<gameobject> thegameobject;
    player theplayer;
    Texture2D maptext;
    std::vector<bool> covers;
    player* playerPtr;
    int collectedObjectsCount = 0;
    MusicPlayer* musicPlayer;

    gameScene(int Level, MusicPlayer* musicPlayerPtr);
    void update(globalState &globalstate);
    void draw();
    void drawLayer(const std::string& layer);
    void fillCoverMatrix();
    void drawCover();
    void removeCover();

    void populateEnemies();
    void populategameobjects();
    void increaseCollectedObjectsCount(); // Erhöht den Zähler für gesammelte GameObjects
    void drawCollectedObjectsCount(); // Zeichnet den Zähler für gesammelte GameObjects
};


#endif //RAYLIBSTARTER_GAMESZENE_H