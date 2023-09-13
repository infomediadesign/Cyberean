//
// Created by lukas on 12.09.2023.
//

#ifndef RAYLIBSTARTER_CUTSCENE5_H
#define RAYLIBSTARTER_CUTSCENE5_H


#include "masterhead.h"
#include "SoundPlayer.h"
#include "mastervolumecontroll.h"
#include "musicplayer.h"

class cutscene5 {
public:

public:
    cutscene5(SoundPlayer *soundplayer, MusicPlayer *musicPlayer);

    void update(globalState &globalState);
    void draw();

    SoundPlayer *soundplayerPtr;
    MusicPlayer *musicPlayerPtr;

    Texture2D background_1 = LoadTexture("assets/screens/cutscene_screen/Textbox_1.png");
    Texture2D background_2 = LoadTexture("assets/screens/cutscene_screen/Textbox_2.png");
    Texture2D background_3 = LoadTexture("assets/screens/cutscene_screen/Textbox_3.png");
    Texture2D background_4 = LoadTexture("assets/screens/cutscene_screen/Textbox_4.png");

    /*Texture2D Igor = LoadTexture("assets/screens/cutscene_screen/Igor.png");
    Texture2D Igor_name = LoadTexture("assets/screens/cutscene_screen/Igor_name.png");
    Texture2D Vasily = LoadTexture("assets/screens/cutscene_screen/vasily.png");
    Texture2D Vasily_name = LoadTexture("assets/screens/cutscene_screen/vasily_name.png");*/
    Texture2D Igor = LoadTexture("assets/screens/cutscene_screen/character/igor600.png");
    Texture2D Igor_name = LoadTexture("assets/screens/cutscene_screen/Igor_name.png");
    Texture2D Vasily = LoadTexture("assets/screens/cutscene_screen/character/vasily600.png");
    Texture2D Vasily_name = LoadTexture("assets/screens/cutscene_screen/vasily_name.png");


    int fontSize;
    Color textColor;

    int textpart;
    int background = 1;
    bool igorname = false;
    bool vasilyname = false;
    bool igor = false;
    bool vasily = true;
    bool cutsceneaktiv = false;

    bool fadein = true;
    bool fadeout = false;
    float alpha = 1.0f;
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

    std::string currentText;
    std::string currentFullText;
    float textX, textY;
    float spacing = 0.0f;
    Font myFont = LoadFont("assets/font/7pixelsOfPerfection.ttf");

    int textSpeed;
    int currentTextIndex;
    int textTimer;

    void ResetCutscene();
    void Cutscene_1();

};



#endif //RAYLIBSTARTER_CUTSCENE5_H
