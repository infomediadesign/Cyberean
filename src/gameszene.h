//
// Created by lukas on 15.06.2023.
//

#ifndef RAYLIBSTARTER_GAMESZENE_H
#define RAYLIBSTARTER_GAMESZENE_H

#include "masterhead.h"
#include "player.h"
#include "gameobject.h"
#include "Enemy.h"

class gameSzene {
public:
    std::unique_ptr<tson::Map> themap;
    std::vector<gameobject> objects;
    player theplayer;
    Texture2D maptext;
    std::vector<bool> covers;

    void update(globalState &globalstate);
    void draw();
    void drawLayer(const std::string& layer);
    gameSzene(int Level);
    void fillCoverMatrix();
    void drawCover();
    void removeCover();
};

#endif //RAYLIBSTARTER_GAMESZENE_H