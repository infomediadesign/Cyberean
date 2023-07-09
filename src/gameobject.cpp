//
// Created by lukas on 15.06.2023.
//

#include "gameobject.h"
#include "gameszene.h"


gameobject::gameobject(int ID, int posX, int posY, player* playerPtr, std::vector<gameobject>& gameObjects, gameScene* gameScenePtr) {
    this->ID = ID;
    this->posX = posX;
    this->posY = posY;
    this->playerPtr = playerPtr;
    this->gameObjects = &gameObjects;
    this->gameScenePtr = gameScenePtr;

    switch(ID)
    {
        case 5:
            textureSource = {0, 32, 32, 32};
            break;
        case 6:
            textureSource = {32, 32, 32, 32};
            break;
    }
    overlayTexture = LoadTexture("assets/switch_gravity_down.png");
}

void gameobject::draw(Texture2D texture) {
    DrawTextureRec(texture, textureSource, Vector2{(float)posX * 32, (float)posY * 32}, WHITE);
    if (isActive) {
        // Überlagernde PNG-Datei zeichnen, wenn der Schalter aktiviert ist
        DrawTextureRec(overlayTexture, textureSource, Vector2{(float)posX * 32, (float)posY * 32}, WHITE);
    }
}

void gameobject::update(gameScene& scene) {
    if (playerPtr->posX == posX && playerPtr->posY == posY && ID == 5) {
        for (auto it = gameObjects->begin(); it != gameObjects->end(); ++it) {
            if (&(*it) == this) {
                scene.increaseCollectedObjectsCount();
                gameObjects->erase(it);
                break;
            }
        }
    }
    else if (playerPtr->posX == posX && playerPtr->posY == posY && ID == 6) {
        // Schalter aktivieren, wenn der Spieler ihn berührt
        isActive = true;
    }
}
