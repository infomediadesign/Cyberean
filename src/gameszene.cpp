//
// Created by lukas on 15.06.2023.
//

#include "gameszene.h"

void drawLayer(const std::string &layer);

gameScene::gameScene(int Level) {
    tson::Tileson t;
    themap = t.parse("assets/level_1.tmj");
    maptext = LoadTexture("assets/blue_tileset_level_1_selina.png");
    theplayer.map = themap.get();
    theplayer.enemies = &enemies;
    fillCoverMatrix();
    populateEnemies();
    populategameobjects();
    playerPtr = &theplayer;
}

void gameScene::draw() {
    drawLayer("Background");
    drawLayer("Overlay");
    drawCover();
    for(Enemy e: enemies){
        e.draw(maptext);
    }
    for(gameobject e: thegameobject){
        e.draw(maptext);
    }
    theplayer.draw();
    drawCollectedObjectsCount();
}

void gameScene::drawLayer(const std::string &layer) {
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

void gameScene::populateEnemies() {
    playerPtr = &theplayer;
    for(int y = 0; y < themap->getSize().y; y++){
        for(int x = 0; x < themap->getSize().x ; x++){
            if(themap->getLayer("Boulder")->getData()[x + y * themap->getSize().x]){
                enemies.emplace_back(themap->getLayer("Boulder")->getData()[x + y * themap->getSize().x], x, y, themap.get(), &covers, &enemies, playerPtr);
            }
        }
    }
}

void gameScene::populategameobjects() {
    playerPtr = &theplayer;
    for(int y = 0; y < themap->getSize().y; y++){
        for(int x = 0; x < themap->getSize().x ; x++){
            if(themap->getLayer("Items")->getData()[x + y * themap->getSize().x]){
                thegameobject.emplace_back(themap->getLayer("Items")->getData()[x + y * themap->getSize().x], x, y, playerPtr, thegameobject, this);
            }
        }
    }
}

void gameScene::update(globalState &globalstate) {
    theplayer.update();
    for(int i = 0; i<enemies.size();i++){
        enemies[i].update();
    }
    for(int i = 0; i<thegameobject.size();i++){
        thegameobject[i].update(*this);
    }
    removeCover();
}

void gameScene::fillCoverMatrix() {
    for (int i = 0; i < themap->getLayer("Cover")->getData().size(); i++){
        covers.push_back(themap->getLayer("Cover")->getData()[i]);

    };
    return;
}

void gameScene::drawCover() {
    Rectangle source{32,0,32,32};
    for (int y = 0; y<themap->getSize().y; y++){
        for (int x = 0; x< themap->getSize().x;x++){
            if (covers[x+y*themap->getSize().x])
            DrawTextureRec(maptext,source,{(float)x*32,(float)y*32},WHITE);
        }
    }
}

void gameScene::removeCover() {
    int playerPosIndex = theplayer.posX + theplayer.posY * themap->getSize().x;
    covers[playerPosIndex] = false;
}

void gameScene::increaseCollectedObjectsCount() {
    collectedObjectsCount++; // Erhöhe den Zähler für gesammelte GameObjects
}

void gameScene::drawCollectedObjectsCount() {
    std::string countText = "Collected Notes: " + std::to_string(collectedObjectsCount);
    DrawText(countText.c_str(), 10, GetScreenHeight() - 30, 20, WHITE); // Zeichnet die aktuelle Anzahl gesammelter GameObjects
}
