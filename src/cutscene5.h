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

    Texture2D background_1 = LoadTexture("assets/screens/cutscene_screen/scene_1/story_5_v1.png");
    Texture2D background_2 = LoadTexture("assets/screens/cutscene_screen/scene_2/story_5_v2.png");
    Texture2D background_3 = LoadTexture("assets/screens/cutscene_screen/scene_3/story_5_vasja_speaking.png");
    Texture2D background_4 = LoadTexture("assets/screens/cutscene_screen/scene_4/story_5_alex_speaking.png");
    Texture2D background_5 = LoadTexture("assets/screens/cutscene_screen/scene_5/story_5_igor_speaking.png");
    Texture2D background_6 = LoadTexture("assets/screens/cutscene_screen/scene_6/story_5_koshka_speaking.png");
    Texture2D background_7 = LoadTexture("assets/screens/cutscene_screen/scene_7/story_5_nastja_speaking.png");

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
    std::string fullText22;
    std::string fullText23;
    std::string fullText24;
    std::string fullText25;
    std::string fullText26;
    std::string fullText27;
    std::string fullText28;
    std::string fullText29;
    std::string fullText30;
    std::string fullText31;
    std::string fullText32;
    std::string fullText33;
    std::string fullText34;
    std::string fullText35;
    std::string fullText36;
    std::string fullText37;
    std::string fullText38;
    std::string fullText39;
    std::string fullText40;
    std::string fullText41;
    std::string fullText42;
    std::string fullText43;
    std::string fullText44;
    std::string fullText45;
    std::string fullText46;
    std::string fullText47;
    std::string fullText48;
    std::string fullText49;
    std::string fullText50;
    std::string fullText51;
    std::string fullText52;

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
