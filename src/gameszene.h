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
#include "gameoverscreen.h"

class pausescreen;

class gameoverscreen;

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
    SoundPlayer *soundPlayerPtr;

    pausescreen mypause;

    gameoverscreen myGameOverScreen;

    bool pause = false;

    int test = 0;

    int level = 0;

    int currentLevel = 0;

    int counter = 0;
    bool switchSoundPlayed = false;
    bool restart = false;
    bool init = false;
    int cposX;
    int cposY;

    MusicPlayer musicPlayer1;
    MusicPlayer musicPlayer2;
    MusicPlayer musicPlayer3;
    MusicPlayer musicPlayer4;
    MusicPlayer musicPlayer5;

    Texture2D onelives;
    Texture2D twolives;
    Texture2D threelives;
    Texture2D zeronotes;
    Texture2D onenotes;
    Texture2D twonotes;
    Texture2D threenotes;
    Texture2D fournotes;
    Texture2D levelnumber;

    Texture2D character;

    //Enemy Textures:


    bool fadein = true;
    bool fadeout = false;
    float alpha = 2.0f;
    float fadeSpeed = 1.0f;
    Texture2D fadeTexture = LoadTexture("assets/screens/storymode/fadeeffect.png");

    gameScene(int Level, MusicPlayer *musicPlayerPtr, SoundPlayer *soundPlayer);

    ~gameScene();

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

    bool all4notescollected();

    void increaseCollectedObjectsCount(); // Increases the number of collected game objects

    void drawCollectedObjectsCount(); // draws the counter of collected game objects

    void loadmusic(int _level);

    float volumeLevels[5] = {0.0f};
};


#endif //RAYLIBSTARTER_GAMESZENE_H