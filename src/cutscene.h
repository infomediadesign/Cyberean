//
// Created by lukas on 04.09.2023.
//

#ifndef RAYLIBSTARTER_CUTSCENE_H
#define RAYLIBSTARTER_CUTSCENE_H

#include "masterhead.h"
#include "SoundPlayer.h"
#include "mastervolumecontroll.h"
#include "musicplayer.h"
#include <random>
#include <ctime>

class cutscene {
public:

public:
    cutscene(SoundPlayer *soundplayer, MusicPlayer *musicPlayer);

    void update(globalState &globalState);
    void draw();

    SoundPlayer *soundplayerPtr;

    int counter = 0;
    MusicPlayer *musicPlayerPtr;

    Texture2D background_1 = LoadTexture("assets/screens/cutscene_screen/scene_1/story_1_v1.png");
    Texture2D background_2 = LoadTexture("assets/screens/cutscene_screen/scene_1/story_1_v2.png");
    Texture2D background_3 = LoadTexture("assets/screens/cutscene_screen/Textbox_3.png");
    Texture2D background_4 = LoadTexture("assets/screens/cutscene_screen/Textbox_4.png");

    /*Texture2D Igor = LoadTexture("assets/screens/cutscene_screen/Igor.png");
    Texture2D Igor_name = LoadTexture("assets/screens/cutscene_screen/Igor_name.png");
    Texture2D Vasily = LoadTexture("assets/screens/cutscene_screen/vasily.png");
    Texture2D Vasily_name = LoadTexture("assets/screens/cutscene_screen/vasily_name.png");
    Texture2D Igor = LoadTexture("assets/screens/cutscene_screen/character/igor600.png");
    Texture2D Igor_name = LoadTexture("assets/screens/cutscene_screen/Igor_name.png");
    Texture2D Vasily = LoadTexture("assets/screens/cutscene_screen/character/vasily600.png");
    Texture2D Vasily_name = LoadTexture("assets/screens/cutscene_screen/vasily_name.png");*/


    int fontSize = 20;
    Color textColor;

    int textpart;
    int background = 0;
    bool igorname = false;
    bool vasilyname = false;
    bool igor = false;
    bool vasily = true;
    bool cutsceneaktiv = false;

    bool fadein = true;
    bool fadeout = false;
    float alpha = 2.0f;
    float fadeSpeed = 1.0f;
    Texture2D fadeTexture = LoadTexture("assets/screens/storymode/fadeeffect.png");

    std::string fullText;
    std::string fullText2;
    std::string fullText3;
    std::string fullText4;
    std::string fullText5;
    std::string fullText6;
    std::string fullText7;
    std::string fullText8;
    std::string fullText9;
    std::string fullText10;
    std::string fullText11;
    std::string fullText12;
    std::string fullText13;
    std::string fullText14;
    std::string fullText15;
    std::string fullText16;
    std::string fullText17;
    std::string fullText18;
    std::string fullText19;
    std::string fullText20;
    std::string fullText21;


    std::string currentText;
    std::string currentFullText;
    float textX, textY;
    float spacing = 0.0f;
    Font myFont = LoadFont("assets/font/7pixelsOfPerfection.ttf");

    int textSpeed;
    int currentTextIndex;
    int textTimer;

    void ResetCutscene();

private:
    std::mt19937 rng;
};


#endif //RAYLIBSTARTER_CUTSCENE_H
