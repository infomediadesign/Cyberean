//
// Created by lukas on 23.05.2023.
//

#ifndef RAYLIBSTARTER_MASTERHEAD_H
#define RAYLIBSTARTER_MASTERHEAD_H
#include "raylib.h"
#include "raymath.h"
#include "../Library/tileson.hpp"

void to_zeichnen_auf_den_Bildschirm(tson::Map *theMap, Texture &mapTex) {
    Rectangle sourceRec{};
    sourceRec.width = 32;
    sourceRec.height = 32;
    Vector2 destVec{};
    int tilesetColumns = 8;
    float tileSize = 32;
    int tileMapColumns = theMap->getSize().x;
    int tileMapRows = theMap->getSize().y;
    for (int y = 0; y < tileMapRows; y++) {
        for (int x = 0; x < tileMapColumns; x++) {
            int tileData = theMap->getLayer("main")->getTileData(x, y)->getId() - 1; //-1 because tiled does stuff >:(
            sourceRec.x = (tileData % tilesetColumns) * tileSize;
            sourceRec.y = (tileData / tilesetColumns) * tileSize;
            destVec.x = x * tileSize;
            destVec.y = y * tileSize;
            DrawTextureRec(mapTex, sourceRec, destVec, WHITE);
        }
    }
}

#endif //RAYLIBSTARTER_MASTERHEAD_H
