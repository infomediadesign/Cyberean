//
// Created by lukas on 15.06.2023.
//

#include "gameszene.h"


void drawLayer(const std::string &layer);

gameScene::gameScene(int Level, MusicPlayer *musicPlayerPtr, MusicPlayer *musicPlayer1, MusicPlayer *musicPlayer2,
                     MusicPlayer *musicPlayer3, MusicPlayer *musicPlayer4, MusicPlayer *musicPlayer5,
                     SoundPlayer *soundPlayer)
        : theplayer(soundPlayer) {
    tson::Tileson t;

    std::cout << "bruh" << std::endl;

    switch(Level){
        case 0:
            themap = t.parse("assets/level/level_1/blue_tileset_level_1_selina.tmj");
            maptext = LoadTexture("assets/level/level_1/blue_tileset_level_1_selina.png");
            break;
        case 1:
            themap = t.parse("assets/level/level_2/magenta_tileset_level_2_selina.tmj");
            maptext = LoadTexture("assets/level/level_2/magenta_tileset_level_2_selina.png");
            break;
        case 2:
            themap = t.parse("assets/level/level_3/green_tileset_level_3_selina.tmj");
            maptext = LoadTexture("assets/level/level_3/green_tileset_level_3_selina.png");
            break;
        case 3:
            themap = t.parse("assets/level/level_4/corroded_tileset_level_4_selina.tmj");
            maptext = LoadTexture("assets/level/level_4/corroded_tileset_level_4_selina.png");

    }
    //themap = t.parse("assets/level_1.tmj");
    //themap = t.parse("assets/level/level_1/blue_tileset_level_1_selina.tmj");
    //maptext = LoadTexture("assets/level/level_1/blue_tileset_level_1_selina.png");
    //maptext = LoadTexture("assets/level/level_1/blue_tileset_level_1_viktor.png");
    //themap = t.parse("assets/blue_tileset_level_1_viktor.tmj");
    //maptext = LoadTexture("assets/blue_tileset_level_1_viktor.png");


    //Folder accessed levels:
    //themap = t.parse("assets/level/level_1/blue_tileset_level_1_selina.tmj");
    //maptext = LoadTexture("assets/level/level_1/blue_tileset_level_1_selina.png");

    //themap = t.parse("assets/level/level_2/magenta_tileset_level_2_selina.tmj");
    //maptext = LoadTexture("assets/level/level_2/magenta_tileset_level_2_selina.png");

    //themap = t.parse("assets/level/level_3/green_tileset_level_3_selina.tmj");
    //maptext = LoadTexture("assets/level/level_3/green_tileset_level_3_selina.png");

    //themap = t.parse("assets/level/level_4/corroded_tileset_level_4_selina.tmj");
    //maptext = LoadTexture("assets/level/level_4/corroded_tileset_level_4_selina.png");


    theplayer.map = themap.get();
    theplayer.enemies = &enemies;
    fillCoverMatrix();
    populateEnemies();
    populategameobjects();
    updateFirewallDirection();
    playerPtr = &theplayer;
    musicPlayer = musicPlayerPtr;
    musicPlayer1Ptr = musicPlayer1;
    musicPlayer2Ptr = musicPlayer2;
    musicPlayer3Ptr = musicPlayer3;
    musicPlayer4Ptr = musicPlayer4;
    musicPlayer5Ptr = musicPlayer5;
    soundPlayerPtr = soundPlayer;

}

void gameScene::draw() {
    drawLayer("Background");
    drawLayer("Traces");
    //drawLayer("Deco");
    drawLayer("Overlay");
    drawCover();
    for (Enemy e: enemies) {
        e.draw(maptext);
    }
    for (gameobject e: thegameobject) {
        e.draw(maptext);
    }
    theplayer.draw();
    drawCollectedObjectsCount();

    if(pause == true){
        mypause.draw();
        mypause.buttons();
    }
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
            int tileData = this->themap->getLayer(layer)->getData()[x + y * tileMapColumns] -
                           1; //-1 because tiled does stuff >:(
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
    for (int y = 0; y < themap->getSize().y; y++) {
        for (int x = 0; x < themap->getSize().x; x++) {
            if (themap->getLayer("Boulder")->getData()[x + y * themap->getSize().x]) {
                enemies.emplace_back(themap->getLayer("Boulder")->getData()[x + y * themap->getSize().x], x, y,
                                     themap.get(), &covers, &enemies, playerPtr);
            }
        }
    }
    for (int y = 0; y < themap->getSize().y; y++) {
        for (int x = 0; x < themap->getSize().x; x++) {
            if (themap->getLayer("Enemies")->getData()[x + y * themap->getSize().x]) {
                enemies.emplace_back(themap->getLayer("Enemies")->getData()[x + y * themap->getSize().x], x, y,
                                     themap.get(), &covers, &enemies, playerPtr);
            }
        }
    }
}

void gameScene::populategameobjects() {
    playerPtr = &theplayer;
    for (int y = 0; y < themap->getSize().y; y++) {
        for (int x = 0; x < themap->getSize().x; x++) {
            if (themap->getLayer("Items")->getData()[x + y * themap->getSize().x]) {
                thegameobject.emplace_back(themap->getLayer("Items")->getData()[x + y * themap->getSize().x], x, y,
                                           playerPtr, thegameobject, this, soundPlayerPtr);
            }
        }
    }
}

void gameScene::update(globalState &globalstate) {

    if(IsKeyPressed(KEY_P)){
        if(pause) {
            pause = false;
        } else {
            pause = true;
        }
    }

    if(pause == false){
        theplayer.update();
        for (int i = 0; i < enemies.size(); i++) {
            enemies[i].update();
        }
        for (int i = 0; i < thegameobject.size(); i++) {
            if (thegameobject[i].playerOnSwitch && !thegameobject[i].switchsoundplayed) {
                soundPlayerPtr->playerButton_sound();
                thegameobject[i].switchsoundplayed = true;
            } else if (!thegameobject[i].playerOnSwitch) {
                thegameobject[i].switchsoundplayed = false; // Setze die Variable zurück, wenn der Spieler den Schalter verlässt
            }
            thegameobject[i].update(*this);
        }
        removeCover();
        //Updates the gravity of the enemies if the player stood on a gravity switch
        int itemID = themap.get()->getLayer("Items")->getData()[playerPtr->posX + playerPtr->posY * themap->getSize().x];
        if (itemID >= 9 && itemID <= 12) {
            for (int i = 0; i < enemies.size(); i++) {
                enemies[i].updateGravity();
            }
        }

    }else{
        mypause.update();
        switch(mypause.state){
            case 0:
                break;
            case 1:
                pause = false;
                mypause.state = 0;
                break;
            case 2:
                break;
            case 3:
                mypause.state = 0;
                pause = false;
                musicPlayer1Ptr->StopMusic();
                musicPlayer2Ptr->StopMusic();
                musicPlayer3Ptr->StopMusic();
                musicPlayer4Ptr->StopMusic();
                musicPlayer5Ptr->StopMusic();
                musicPlayer->PlayMusic(MusicState::MainMenu);
                globalstate = mainMenu;
        }
    }

    updateMusicPlayers();

}

void gameScene::updateMusicPlayers() {
    if (musicPlayer->GetCurrentMusicState() == MusicState::MainMenu) {

        musicPlayer->StopMusic();

        // Entmute alle anderen MusicPlayer-Instanzen
        musicPlayer1Ptr->SetMusicVolume(0.9f * masterMusicControl);
        musicPlayer2Ptr->SetMusicVolume(0.0f);
        musicPlayer3Ptr->SetMusicVolume(0.0f);
        musicPlayer4Ptr->SetMusicVolume(0.0f);
        musicPlayer5Ptr->SetMusicVolume(0.0f);

        // Spiele die Musik der anderen Level ab
        musicPlayer1Ptr->PlayMusic(MusicState::Lvl1_part1);
        musicPlayer2Ptr->PlayMusic(MusicState::Lvl1_part2);
        musicPlayer3Ptr->PlayMusic(MusicState::Lvl1_part3);
        musicPlayer4Ptr->PlayMusic(MusicState::Lvl1_part4);
        musicPlayer5Ptr->PlayMusic(MusicState::Lvl1_part5);
    }

    if (collectedObjectsCount == 1) {
        musicPlayer1Ptr->SetMusicVolume(0.0f);
        musicPlayer2Ptr->SetMusicVolume(0.8f * masterMusicControl);
    }

    if (collectedObjectsCount == 2) {
        musicPlayer2Ptr->SetMusicVolume(0.0f);
        musicPlayer3Ptr->SetMusicVolume(0.6f * masterMusicControl);
    }

    if (collectedObjectsCount == 3) {
        musicPlayer3Ptr->SetMusicVolume(0.0f);
        musicPlayer4Ptr->SetMusicVolume(0.6f * masterMusicControl);
    }

    if (collectedObjectsCount == 4) {
        musicPlayer4Ptr->SetMusicVolume(0.0f);
        musicPlayer5Ptr->SetMusicVolume(0.6f * masterMusicControl);
    }
}

void gameScene::fillCoverMatrix() {
    for (int i = 0; i < themap->getLayer("Cover")->getData().size(); i++) {
        covers.push_back(themap->getLayer("Cover")->getData()[i]);

    };
}

void gameScene::drawCover() {
    Rectangle source{32, 0, 32, 32};
    for (int y = 0; y < themap->getSize().y; y++) {
        for (int x = 0; x < themap->getSize().x; x++) {
            if (covers[x + y * themap->getSize().x])
                DrawTextureRec(maptext, source, {(float) x * 32, (float) y * 32}, WHITE);
        }
    }
}

void gameScene::removeCover() {
    int playerPosIndex = theplayer.posX + theplayer.posY * themap->getSize().x;
    if (covers[playerPosIndex]) {
        covers[playerPosIndex] = false;
        soundPlayerPtr->playerCover_sound();
    }
}

void gameScene::increaseCollectedObjectsCount() {
    collectedObjectsCount++; // Erhöhe den Zähler für gesammelte GameObjects
    soundPlayerPtr->playerNote_sound();
    if (collectedObjectsCount == 4 && counter == 0) {
        //soundPlayerPtr->all4Notes();
        counter++;
    }
}

void gameScene::drawCollectedObjectsCount() {
    std::string countText = "Collected Notes: " + std::to_string(collectedObjectsCount);
    DrawText(countText.c_str(), 50, GetScreenHeight() - 75, 20,
             WHITE); // Draw the number of collected objects
}

void gameScene::updateFirewallDirection() { //This algorithm checks horizontal or vertical neighbors (Firewall n; 1<n<5)
    for (int i = 0; i < enemies.size(); i++) {
        if (enemies[i].ID == 7) { // 7 is a Firewall ID
            if (enemies[i].getEnemyID(enemies[i].posX - 1, enemies[i].posY) == 7 ||
                    enemies[i].getEnemyID(enemies[i].posX + 1, enemies[i].posY) == 7)
                enemies[i].movingStatus = Enemy::upMove;
            else if (enemies[i].getEnemyID(enemies[i].posX, enemies[i].posY - 1) == 7 ||
                    enemies[i].getEnemyID(enemies[i].posX, enemies[i].posY + 1) == 7)
                enemies[i].movingStatus = Enemy::rightMove;
        }
    }
}