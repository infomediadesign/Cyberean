//
// Created by lukas on 15.06.2023.
//

#include "gameobject.h"
#include "gameszene.h"


gameobject::gameobject(int ID, int posX, int posY, player *playerPtr, std::vector<gameobject> &gameObjects,
                       gameScene *gameScenePtr, SoundPlayer *soundPlayer) {
    this->ID = ID - 1;
    this->posX = posX;
    this->posY = posY;
    this->playerPtr = playerPtr;
    this->gameObjects = &gameObjects;
    this->gameScenePtr = gameScenePtr;
    this->soundplayerPtr = soundPlayer;

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
        //DrawTextureRec(texture, Rectangle{32, 256, 32, 32}, Vector2{(float) posX * 32, (float) posY * 32}, WHITE);
        DrawTexture(overlayTexture,posX*32,posY*32,WHITE);
    }

}

void gameobject::update(gameScene &scene) {
    //remove note and increase collectable count when the player is on a note.
    if (playerPtr->posX == posX && playerPtr->posY == posY && ID == 12) {
        for (auto it = gameObjects->begin(); it != gameObjects->end(); ++it) {
            if (&(*it) == this) {
                scene.increaseCollectedObjectsCount();
                gameObjects->erase(it);
                break;
            }
        }
    }

    //Check if player is still standing on the gravity switch
    if (playerPtr->posX != posX || playerPtr->posY != posY) {
        playerOnSwitch = false;
    }

    //Activate/Deactivate Gravity Switch
    if (playerPtr->posX == posX && playerPtr->posY == posY && playerOnSwitch == false && ID >= 8 && ID <= 11) {
        switch (ID) {
            case 8:{
                if (isActive == false) {
                    isActive = true;
                    for (auto &otherSwitch: *gameObjects) {
                        if (&otherSwitch != this && otherSwitch.ID == 8) {
                            otherSwitch.isActive = isActive;
                            break;
                        }
                    }
                } else {
                    isActive = false;
                    for (auto &otherSwitch: *gameObjects) {
                        if (&otherSwitch != this && otherSwitch.ID == 8) {
                            otherSwitch.isActive = isActive;
                            break;
                        }
                    }
                }
                break;
            }
            case 9:{
                if (isActive == false) {
                    isActive = true;
                    for (auto &otherSwitch: *gameObjects) {
                        if (&otherSwitch != this && otherSwitch.ID == 9) {
                            otherSwitch.isActive = isActive;
                            break;
                        }
                    }
                } else {
                    isActive = false;
                    for (auto &otherSwitch: *gameObjects) {
                        if (&otherSwitch != this && otherSwitch.ID == 9) {
                            otherSwitch.isActive = isActive;
                            break;
                        }
                    }
                }
                break;
            }
            case 10:{
                if (isActive == false) {
                    isActive = true;
                    for (auto &otherSwitch: *gameObjects) {
                        if (&otherSwitch != this && otherSwitch.ID == 10) {
                            otherSwitch.isActive = isActive;
                            break;
                        }
                    }
                } else {
                    isActive = false;
                    for (auto &otherSwitch: *gameObjects) {
                        if (&otherSwitch != this && otherSwitch.ID == 10) {
                            otherSwitch.isActive = isActive;
                            break;
                        }
                    }
                }
                break;
            }
            case 11:{
                if (isActive == false) {
                    isActive = true;
                    for (auto &otherSwitch: *gameObjects) {
                        if (&otherSwitch != this && otherSwitch.ID == 11) {
                            otherSwitch.isActive = isActive;
                            break;
                        }
                    }
                } else {
                    isActive = false;
                    for (auto &otherSwitch: *gameObjects) {
                        if (&otherSwitch != this && otherSwitch.ID == 11) {
                            otherSwitch.isActive = isActive;
                            break;
                        }
                    }
                }
                break;
            }
        }
        playerOnSwitch = true;
        int gravityVal = playerPtr->map->getLayer("Gravity")->getData()[posX + posY * playerPtr->map->getSize().x];
        if (gravityVal > 0) {
            switch (gravityVal) {
                case 18:
                    playerPtr->gravitySwitchStatusRight = isActive; // Right
                    break;
                case 15:
                    playerPtr->gravitySwitchStatusUp = isActive; // Up
                    break;
                case 17:
                    playerPtr->gravitySwitchStatusLeft = isActive; //Left
                    break;
                case 16:
                default:
                    playerPtr->gravitySwitchStatusDown = isActive; // Down
            }
        }
    }
}
