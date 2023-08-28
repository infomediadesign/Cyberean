//
// Created by lukas on 15.06.2023.
//

#ifndef RAYLIBSTARTER_GAMESZENE_H
#define RAYLIBSTARTER_GAMESZENE_H

#pragma once

#include "masterhead.h"
#include "player.h"
#include "gameobject.h"
#include "Enemy.h"
#include "../Library/tileson.hpp"
#include "musicplayer.h"
#include "SoundPlayer.h"
#include "mastervolumecontroll.h"
#include "pausescreen.h"

class pausescreen;

class gameScene {
public:
    std::unique_ptr<tson::Map> themap;
    std::vector<Enemy> enemies;
    std::vector<gameobject> thegameobject;
    player theplayer;
    Texture2D maptext;
    std::vector<bool> covers;
    player *playerPtr;
    int collectedObjectsCount = 0;
    MusicPlayer *musicPlayer;
    MusicPlayer *musicPlayer1Ptr;
    MusicPlayer *musicPlayer2Ptr;
    MusicPlayer *musicPlayer3Ptr;
    MusicPlayer *musicPlayer4Ptr;
    MusicPlayer *musicPlayer5Ptr;
    SoundPlayer *soundPlayerPtr;

    pausescreen mypause;

    bool pause = false;

    int counter = 0;
    bool switchSoundPlayed = false;

    gameScene(int Level, MusicPlayer *musicPlayerPtr, MusicPlayer *musicPlayer1, MusicPlayer *musicPlayer2,
              MusicPlayer *musicPlayer3, MusicPlayer *musicPlayer4, MusicPlayer *musicPlayer5, SoundPlayer *soundPlayer);

    void update(globalState &globalstate);

    void draw();

    void drawLayer(const std::string &layer);

    void fillCoverMatrix();

    void drawCover();

    void removeCover();

    void updateMusicPlayers();

    void populateEnemies();

    void populategameobjects();

    void updateFirewallDirection();

    void increaseCollectedObjectsCount(); // Increases the number of collected game objects
    void drawCollectedObjectsCount(); // draws the counter of collected game objects
};


#endif //RAYLIBSTARTER_GAMESZENE_H