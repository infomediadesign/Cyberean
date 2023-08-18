//
// Created by lukas on 15.06.2023.
//

#include "gameobject.h"
#include "gameszene.h"


gameobject::gameobject(int ID, int posX, int posY, player *playerPtr, std::vector<gameobject> &gameObjects,
                       gameScene *gameScenePtr) {
    this->ID = ID - 1;
    this->posX = posX;
    this->posY = posY;
    this->playerPtr = playerPtr;
    this->gameObjects = &gameObjects;
    this->gameScenePtr = gameScenePtr;

    textureSource.x = float((this->ID % 4) * 32);
    textureSource.y = float((this->ID / 4) * 32);
    textureSource.width = 32;
    textureSource.height = 32;

    overlayTexture = LoadTexture("assets/switch_gravity_down.png");

    /*switch(ID)
    {
        case 5:
            textureSource = {0, 32, 32, 32};
            break;
        case 6:
            textureSource = {32, 32, 32, 32};
            break;
        default:
            textureSource = {16, 16, 32, 32};
    }
    overlayTexture = LoadTexture("assets/switch_gravity_down.png");
}*/
}

void gameobject::draw(Texture2D texture) {
    DrawTextureRec(texture, textureSource, Vector2{(float) posX * 32, (float) posY * 32}, WHITE);
    if (isActive) {
        // draw the imposed PNG, when the switch is activated
        DrawTextureRec(texture, Rectangle{32, 256, 32, 32}, Vector2{(float) posX * 32, (float) posY * 32}, WHITE);
    }
}

void gameobject::update(gameScene &scene) {
    if (playerPtr->posX == posX && playerPtr->posY == posY && ID == 28) {
        for (auto it = gameObjects->begin(); it != gameObjects->end(); ++it) {
            if (&(*it) == this) {
                scene.increaseCollectedObjectsCount();
                gameObjects->erase(it);
                break;
            }
        }
    }
    //Check if player is still standing on the gravity switch
    if (playerPtr->posX != posX || playerPtr->posY != posY || ID != 32) {
        playerOnSwitch = false;
    }
    //Activate/Deactivate Gravity Switch
    if (playerPtr->posX == posX && playerPtr->posY == posY && ID == 32 && playerOnSwitch == false) {
        if (isActive == false) {
            isActive = true;
        } else {
            isActive = false;
        }
        playerOnSwitch = true;
        int gravityVal = playerPtr->map->getLayer("Gravity")->getData()[posX + posY * playerPtr->map->getSize().x];
        if (gravityVal > 50) {
            switch (gravityVal) {
                case 55:
                    playerPtr->gravitySwitchStatusRight = isActive; // Right
                    break;
                case 52:
                    playerPtr->gravitySwitchStatusUp = isActive; // Up
                    break;
                case 54:
                    playerPtr->gravitySwitchStatusLeft = isActive; //Left
                    break;
                case 53:
                default:
                    playerPtr->gravitySwitchStatusDown = isActive; // Down
            }
        }
    }
}
