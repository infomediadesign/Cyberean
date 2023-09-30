//
// Created by lukas on 15.06.2023.
//

#include "gameszene.h"

void drawLayer(const std::string &layer);

gameScene::gameScene(int Level, MusicPlayer *musicPlayerPtr,
                     SoundPlayer *soundPlayer)
        : theplayer(soundPlayer) {
    tson::Tileson t;

    this->level = Level;
    std::cout << level << std::endl;
    switch (level) {
        case 0:
            themap = t.parse("assets/level/level_1/blue_tileset_level_1_selina.tmj");
            maptext = LoadTexture("assets/level/level_1/blue_tileset_level_1_selina.png");
            onelives = LoadTexture("assets/level/level_1/ui/blue_1_lives.png");
            twolives = LoadTexture("assets/level/level_1/ui/blue_2_lives.png");
            threelives = LoadTexture("assets/level/level_1/ui/blue_3_lives.png");
            zeronotes = LoadTexture("assets/level/level_1/ui/yellow_0_notes.png");
            onenotes = LoadTexture("assets/level/level_1/ui/yellow_1_notes.png");
            twonotes = LoadTexture("assets/level/level_1/ui/yellow_2_notes.png");
            threenotes = LoadTexture("assets/level/level_1/ui/yellow_3_notes.png");
            fournotes = LoadTexture("assets/level/level_1/ui/yellow_4_notes.png");
            levelnumber = LoadTexture("assets/level/level_1/ui/level_1.png");
            character = LoadTexture("assets/characters/igor_level_1.png");
            cposX = 640;
            cposY = 448;
            currentLevel = 1;
            //textureManager.InitializeTextures();
            break;
        case 1:
            themap = t.parse("assets/level/level_2/magenta_tileset_level_2_selina.tmj");
            maptext = LoadTexture("assets/level/level_2/magenta_tileset_level_2_selina.png");
            onelives = LoadTexture("assets/level/level_2/ui/magenta_1_lives.png");
            twolives = LoadTexture("assets/level/level_2/ui/magenta_2_lives.png");
            threelives = LoadTexture("assets/level/level_2/ui/magenta_3_lives.png");
            zeronotes = LoadTexture("assets/level/level_2/ui/green_0_notes.png");
            onenotes = LoadTexture("assets/level/level_2/ui/green_1_notes.png");
            twonotes = LoadTexture("assets/level/level_2/ui/green_2_notes.png");
            threenotes = LoadTexture("assets/level/level_2/ui/green_3_notes.png");
            fournotes = LoadTexture("assets/level/level_2/ui/green_4_notes.png");
            levelnumber = LoadTexture("assets/level/level_2/ui/level_2.png");
            character = LoadTexture("assets/characters/anastasia_level_2.png");
            cposX = 672;
            cposY = 384;
            currentLevel = 2;
            //textureManager.InitializeTextures();
            break;
        case 2:
            themap = t.parse("assets/level/level_3/green_tileset_level_3_selina.tmj");
            maptext = LoadTexture("assets/level/level_3/green_tileset_level_3_selina.png");
            onelives = LoadTexture("assets/level/level_3/ui/yellow_1_lives.png");
            twolives = LoadTexture("assets/level/level_3/ui/yellow_2_lives.png");
            threelives = LoadTexture("assets/level/level_3/ui/yellow_3_lives.png");
            zeronotes = LoadTexture("assets/level/level_3/ui/silver_0_notes.png");
            onenotes = LoadTexture("assets/level/level_3/ui/silver_1_notes.png");
            twonotes = LoadTexture("assets/level/level_3/ui/silver_2_notes.png");
            threenotes = LoadTexture("assets/level/level_3/ui/silver_3_notes.png");
            fournotes = LoadTexture("assets/level/level_3/ui/silver_4_notes.png");
            levelnumber = LoadTexture("assets/level/level_3/ui/level_3.png");
            character = LoadTexture("assets/characters/alexey_level_3.png");
            cposX = 544;
            cposY = 448;
            currentLevel = 3;
            //textureManager.InitializeTextures();
            break;
        case 3:
            themap = t.parse("assets/level/level_4/corroded_tileset_level_4_selina.tmj");
            maptext = LoadTexture("assets/level/level_4/corroded_tileset_level_4_selina.png");
            onelives = LoadTexture("assets/level/level_4/ui/green_1_lives.png");
            twolives = LoadTexture("assets/level/level_4/ui/green_2_lives.png");
            threelives = LoadTexture("assets/level/level_4/ui/green_3_lives.png");
            zeronotes = LoadTexture("assets/level/level_4/ui/purple_0_notes.png");
            onenotes = LoadTexture("assets/level/level_4/ui/purple_1_notes.png");
            twonotes = LoadTexture("assets/level/level_4/ui/purple_2_notes.png");
            threenotes = LoadTexture("assets/level/level_4/ui/purple_3_notes.png");
            fournotes = LoadTexture("assets/level/level_4/ui/purple_4_notes.png");
            levelnumber = LoadTexture("assets/level/level_4/ui/level_4.png");
            character = LoadTexture("assets/characters/koshka_level_4.png");
            cposX = 640;
            cposY = 448;
            currentLevel = 4;
            //textureManager.InitializeTextures();
            break;

    }

    theplayer.map = themap.get();
    theplayer.enemies = &enemies;
    fillCoverMatrix();
    populateEnemies();
    populategameobjects();
    updateFirewallDirection();
    playerPtr = &theplayer;
    musicPlayer = musicPlayerPtr;

    soundPlayerPtr = soundPlayer;

    loadmusic(level);

    musicPlayerPtr->StopMusic();
}

void gameScene::draw() {
    drawLayer("Background");
    drawLayer("Traces");
    drawLayer("Deco");
    drawLayer("Overlay");
    drawCover();

    for (int i = 0; i < enemies.size(); i++) {
        enemies[i].draw(maptext);
    }
    for (gameobject e: thegameobject) {
        e.draw(maptext);
    }
    if (collectedObjectsCount == 4) {
        DrawTexture(character, cposX, cposY, WHITE);
    }
    theplayer.draw();
    drawCollectedObjectsCount();
    DrawTexture(levelnumber, 528, 862, WHITE);
    switch (playerPtr->life) {
        case 3:
            DrawTexture(threelives, 960, 862, WHITE);
            break;
        case 2:
            DrawTexture(twolives, 960, 862, WHITE);
            break;
        case 1:
            DrawTexture(onelives, 960, 862, WHITE);
            break;
    }

    if (pause == true) {
        mypause.draw();
        mypause.buttons();
    }
    if (playerPtr->gameOver == true) {
        myGameOverScreen.draw();
        myGameOverScreen.buttons();
    }

    if (fadeout) {
        DrawTexturePro(fadeTexture,
                       Rectangle{0, 0, (float) fadeTexture.width, (float) fadeTexture.height},
                       Rectangle{0, 0, (float) GetScreenWidth(), (float) GetScreenHeight()},
                       {}, 0, Fade(WHITE, alpha));
    }

    if (fadein) {
        DrawTexturePro(fadeTexture,
                       Rectangle{0, 0, (float) fadeTexture.width, (float) fadeTexture.height},
                       Rectangle{0, 0, (float) GetScreenWidth(), (float) GetScreenHeight()},
                       {}, 0, Fade(WHITE, alpha));
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

    if (IsKeyPressed(KEY_P) || IsKeyPressed(KEY_ESCAPE)) {
        if (pause) {
            pause = false;
        } else {
            pause = true;
        }
    }

    if (pause == false && playerPtr->gameOver == false) {
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
        int itemID = themap.get()->getLayer("Items")->getData()[playerPtr->posX +
                                                                playerPtr->posY * themap->getSize().x];
        if (itemID >= 9 && itemID <= 12) {
            for (int i = 0; i < enemies.size(); i++) {
                enemies[i].updateGravity();
            }
        }

    } else if (pause == true) {
        mypause.update();
        switch (mypause.state) {
            case 0:
                break;
            case 1:
                pause = false;
                mypause.state = 0;
                break;
            case 2:
                restart = true;
                break;
            case 3:
                mypause.state = 0;
                pause = false;
                globalstate = mainMenu;
        }
    } else if (playerPtr->gameOver == true) {
        myGameOverScreen.update();
        switch (myGameOverScreen.state) {
            case 1:
                restart = true;
                break;
            case 2:
                mypause.state = 0;
                pause = false;
                globalstate = mainMenu;;
                break;
            case 3:
                CloseWindow();
                break;
        }
    }

    if ((playerPtr->posX * 32) == cposX && (playerPtr->posY * 32) == cposY && collectedObjectsCount == 4) {
        fadeout = true;
    }

    updateMusicPlayers();
    musicPlayer1.Update();
    musicPlayer2.Update();
    musicPlayer3.Update();
    musicPlayer4.Update();
    musicPlayer5.Update();

    if (IsKeyPressed(KEY_F2)) {
        fadeout = true;
    }

    if (fadein && !fadeout) {
        alpha -= fadeSpeed * GetFrameTime();
        if (alpha <= 0.0f) {
            alpha = 0.0f;
            fadein = false;

        }
    }

    if (fadeout) {
        alpha += fadeSpeed * GetFrameTime();
        if (alpha >= 1.0f) {
            alpha = 1.0f;

            if (storymodeactive) {
                storystate++;
                globalstate = storymodesection;
            } else {
                globalstate = mainMenu;
            }
        }
    }

    for (Enemy e: enemies) {
        if (e.soundbomb == true && e.ID == 5) {
            //soundPlayerPtr->bomb_sound();
            e.soundbomb = false;
        }
    }
}

void gameScene::updateMusicPlayers() {
    if (musicPlayer->GetCurrentMusicState() == MusicState::MainMenu ||
        musicPlayer->GetCurrentMusicState() == MusicState::part_1 ||
        musicPlayer->GetCurrentMusicState() == MusicState::cutscene ||
        musicPlayer->GetCurrentMusicState() == MusicState::part_2 ||
        musicPlayer->GetCurrentMusicState() == MusicState::part_3 ||
        musicPlayer->GetCurrentMusicState() == MusicState::part_4) {

        // Entmute alle anderen MusicPlayer-Instanzen
        musicPlayer1.SetMusicVolume(volumeLevels[0] * masterMusicControl);
        musicPlayer2.SetMusicVolume(0.0f);
        musicPlayer3.SetMusicVolume(0.0f);
        musicPlayer4.SetMusicVolume(0.0f);
        musicPlayer5.SetMusicVolume(0.0f);

        // Spiele die Musik der anderen Level ab
        musicPlayer1.PlayMusic(MusicState::part_1);
        musicPlayer2.PlayMusic(MusicState::part_2);
        musicPlayer3.PlayMusic(MusicState::part_3);
        musicPlayer4.PlayMusic(MusicState::part_4);
        musicPlayer5.PlayMusic(MusicState::part_5);
    }

    if (collectedObjectsCount == 1) {
        musicPlayer1.SetMusicVolume(0.0f);
        musicPlayer2.SetMusicVolume(volumeLevels[1] * masterMusicControl);
    }

    if (collectedObjectsCount == 2) {
        musicPlayer2.SetMusicVolume(0.0f);
        musicPlayer3.SetMusicVolume(volumeLevels[2] * masterMusicControl);
    }

    if (collectedObjectsCount == 3) {
        musicPlayer3.SetMusicVolume(0.0f);
        musicPlayer4.SetMusicVolume(volumeLevels[3] * masterMusicControl);
    }

    if (collectedObjectsCount == 4) {
        musicPlayer4.SetMusicVolume(0.0f);
        musicPlayer5.SetMusicVolume(volumeLevels[4] * masterMusicControl);
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
        soundPlayerPtr->all4Notes();
        counter++;
    }
}

void gameScene::drawCollectedObjectsCount() {
    switch (collectedObjectsCount) {
        case 0:
            DrawTexture(zeronotes, 64, 862, WHITE);
            break;
        case 1:
            DrawTexture(onenotes, 64, 862, WHITE);
            break;
        case 2:
            DrawTexture(twonotes, 64, 862, WHITE);
            break;
        case 3:
            DrawTexture(threenotes, 64, 862, WHITE);
            break;
        case 4:
            DrawTexture(fournotes, 64, 862, WHITE);
            break;
    }
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

gameScene::~gameScene() {
    UnloadTexture(maptext);
    //musicPlayer1.UnLoadMusic();
    //musicPlayer2.UnLoadMusic();
    //musicPlayer3.UnLoadMusic();
    //musicPlayer4.UnLoadMusic();
    //musicPlayer5.UnLoadMusic();
}

void gameScene::loadmusic(int _level) {

    switch (_level) {
        case 0:
            musicPlayer1.LoadMusic("assets/audio/tracks/level_4/cyberean_lvl4_part1.wav", MusicState::part_1);
            musicPlayer2.LoadMusic("assets/audio/tracks/level_4/cyberean_lvl4_part2.wav", MusicState::part_2);
            musicPlayer3.LoadMusic("assets/audio/tracks/level_4/cyberean_lvl4_part3.wav", MusicState::part_3);
            musicPlayer4.LoadMusic("assets/audio/tracks/level_4/cyberean_lvl4_part4.wav", MusicState::part_4);
            musicPlayer5.LoadMusic("assets/audio/tracks/level_4/cyberean_lvl4_part5.wav", MusicState::part_5);
            volumeLevels[0] = 0.9f;
            volumeLevels[1] = 0.8f;
            volumeLevels[2] = 0.7f;
            volumeLevels[3] = 0.7f;
            volumeLevels[4] = 0.7f;
            break;
        case 1:
            musicPlayer1.LoadMusic("assets/audio/tracks/level_1/cyberean_lvl1_part1.wav", MusicState::part_1);
            musicPlayer2.LoadMusic("assets/audio/tracks/level_1/cyberean_lvl1_part2.wav", MusicState::part_2);
            musicPlayer3.LoadMusic("assets/audio/tracks/level_1/cyberean_lvl1_part3.wav", MusicState::part_3);
            musicPlayer4.LoadMusic("assets/audio/tracks/level_1/cyberean_lvl1_part4.wav", MusicState::part_4);
            musicPlayer5.LoadMusic("assets/audio/tracks/level_1/cyberean_lvl1_part5.wav", MusicState::part_5);
            volumeLevels[0] = 0.9f;
            volumeLevels[1] = 0.8f;
            volumeLevels[2] = 0.6f;
            volumeLevels[3] = 0.6f;
            volumeLevels[4] = 0.6f;
            break;
        case 2:
            musicPlayer1.LoadMusic("assets/audio/tracks/level_3/cyberean_lvl3_part1.wav", MusicState::part_1);
            musicPlayer2.LoadMusic("assets/audio/tracks/level_3/cyberean_lvl3_part2.wav", MusicState::part_2);
            musicPlayer3.LoadMusic("assets/audio/tracks/level_3/cyberean_lvl3_part3.wav", MusicState::part_3);
            musicPlayer4.LoadMusic("assets/audio/tracks/level_3/cyberean_lvl3_part4.wav", MusicState::part_4);
            musicPlayer5.LoadMusic("assets/audio/tracks/level_3/cyberean_lvl3_part5.wav", MusicState::part_5);
            volumeLevels[0] = 0.9f;
            volumeLevels[1] = 0.8f;
            volumeLevels[2] = 0.7f;
            volumeLevels[3] = 0.7f;
            volumeLevels[4] = 0.7f;
            break;
        case 3:
            musicPlayer1.LoadMusic("assets/audio/tracks/level_2/cyberean_lvl2_part1.wav", MusicState::part_1);
            musicPlayer2.LoadMusic("assets/audio/tracks/level_2/cyberean_lvl2_part2.wav", MusicState::part_2);
            musicPlayer3.LoadMusic("assets/audio/tracks/level_2/cyberean_lvl2_part3.wav", MusicState::part_3);
            musicPlayer4.LoadMusic("assets/audio/tracks/level_2/cyberean_lvl2_part4.wav", MusicState::part_4);
            musicPlayer5.LoadMusic("assets/audio/tracks/level_2/cyberean_lvl2_part5.wav", MusicState::part_5);
            volumeLevels[0] = 0.9f;
            volumeLevels[1] = 0.8f;
            volumeLevels[2] = 0.6f;
            volumeLevels[3] = 0.6f;
            volumeLevels[4] = 0.6f;
            break;
    }
}