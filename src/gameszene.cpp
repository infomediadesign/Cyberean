//
// Created by lukas on 15.06.2023.
//

#include "gameszene.h"
#include "Enemy.h"

void drawLayer(const std::string &layer);

gameSzene::gameSzene(int Level) {
    tson::Tileson t;
    themap = t.parse("assets/blue_level_prototype.tmj");
    maptext = LoadTexture("assets/tilemap_prototype_selina_test.png");
    theplayer.map = themap.get();
    theplayer.enemies = &enemies;
    fillCoverMatrix();
    populateEnemies();
}

void gameSzene::draw() {
    drawLayer("Background");
    drawLayer("Overlay");
    theplayer.draw();
    drawCover();
    for(Enemy e: enemies){
        e.draw(maptext);
    }
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
            destVec.x = x * tileSize; //destination vector x
            destVec.y = y * tileSize; //destination vector y
            DrawTextureRec(this->maptext, sourceRec, destVec, WHITE);
        }
    }
}

void gameSzene::populateEnemies() {
    for(int y = 0; y < themap->getSize().y; y++){
        for(int x = 0; x < themap->getSize().x ; x++){
            if(themap->getLayer("Boulder")->getData()[x + y * themap->getSize().x]){
                enemies.emplace_back(themap->getLayer("Boulder")->getData()[x + y * themap->getSize().x], x, y, themap.get(), &covers, &enemies);
            }
        }
    }
}

void gameSzene::update(globalState &globalstate) {
    theplayer.update();
    removeCover();
}

void gameSzene::fillCoverMatrix() {
    for (int i = 0; i < themap->getLayer("Cover")->getData().size(); i++){
        covers.push_back(themap->getLayer("Cover")->getData()[i]);

    };
    return;
}

void gameSzene::drawCover() {
    Rectangle source{32,0,32,32};
    for (int y = 0; y<themap->getSize().y; y++){
        for (int x = 0; x< themap->getSize().x;x++){
            if (covers[x+y*themap->getSize().x])
            DrawTextureRec(maptext,source,{(float)x*32,(float)y*32},WHITE);
        }
    }
}

void gameSzene::removeCover() {
    int playerPosIndex = theplayer.posX + theplayer.posY * themap->getSize().x;
    covers[playerPosIndex] = false;
}
