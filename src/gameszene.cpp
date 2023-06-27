//
// Created by lukas on 15.06.2023.
//

#include "gameszene.h"

void drawLayer(const std::string &layer);

gameSzene::gameSzene(int Level) {
    tson::Tileson t;
    themap = t.parse("assets/blue_level_prototype.tmj");
    maptext = LoadTexture("assets/tilemap_prototype_selina_test.png");
    theplayer.map = themap.get();
}

void gameSzene::draw() {
    drawLayer("Background");
    drawLayer("Overlay");


    theplayer.draw();
}

void gameSzene::drawLayer(const std::string &layer) {
    Rectangle sourceRec{};
    sourceRec.width = 32;
    sourceRec.height = 32;
    Vector2 destVec{};
    int tilesetColumns = 4;
    float tileSize = 32;
    int tileMapColumns = this->themap->getSize().x;
    int tileMapRows = this->themap->getSize().y;
    for (int y = 0; y < tileMapRows; y++) {
        for (int x = 0; x < tileMapColumns; x++) {
            int tileData = this->themap->getLayer(layer)->getData()[x + y * tileMapColumns] - 1; //-1 because tiled does stuff >:(
            if (tileData < 0) continue;
            sourceRec.x = (tileData % tilesetColumns) * tileSize;
            sourceRec.y = (tileData / tilesetColumns) * tileSize;
            destVec.x = x * tileSize;
            destVec.y = y * tileSize;
            DrawTextureRec(this->maptext, sourceRec, destVec, WHITE);
        }
    }
}

void gameSzene::update(globalState &globalstate) {
    theplayer.update();
}
