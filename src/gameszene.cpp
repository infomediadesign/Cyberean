//
// Created by lukas on 15.06.2023.
//

#include "gameszene.h"

gameSzene::gameSzene(int Level) {
    tson::Tileson t;
    themap = t.parse("assets/test_poop.tmj");
    maptext = LoadTexture("assets/tileset_prototype_timo_updated.png");
}

void gameSzene::draw() {
    Rectangle sourceRec{};
    sourceRec.width = 32;
    sourceRec.height = 32;
    Vector2 destVec{};
    int tilesetColumns = 5;
    float tileSize = 32;
    int tileMapColumns = themap->getSize().x;
    int tileMapRows = themap->getSize().y;
    for (int y = 0; y < tileMapRows; y++) {
        for (int x = 0; x < tileMapColumns; x++) {
            int tileData = themap->getLayer("Tile Layer 1")->getTileData(x, y)->getId() - 1; //-1 because tiled does stuff >:(
            sourceRec.x = (tileData % tilesetColumns) * tileSize;
            sourceRec.y = (tileData / tilesetColumns) * tileSize;
            destVec.x = x * tileSize;
            destVec.y = y * tileSize;
            DrawTextureRec(maptext, sourceRec, destVec, WHITE);
        }
    }
}