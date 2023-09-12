//
// Created by lukas on 12.09.2023.
//

#include "cutscene2.h"

void cutscene2::update(globalState &globalState) {
    musicPlayerPtr->PlayMusic(MusicState::cutscene);

    if(fadein){
        alpha -= fadeSpeed * GetFrameTime();
        if (alpha <= 0.0f) {
            alpha = 0.0f;
            fadein = false;

        }
    }

    if(fadeout){
        alpha += fadeSpeed * GetFrameTime();
        if (alpha >= 1.0f) {
            alpha = 1.0f;
            textpart++;
            textpart = 0;
            musicPlayerPtr->StopMusic();
            if(storymodeactive){
                storystate++;
            }else{
                globalState = gameplay;
            }
        }
    }

    if (currentTextIndex < currentFullText.length() && !fadein) {
        if (IsKeyPressed(KEY_ENTER)) {
            currentText = currentFullText;
            currentTextIndex = currentFullText.length();
        } else if (textTimer >= textSpeed) {
            currentText += currentFullText[currentTextIndex];
            currentTextIndex++;
            textTimer = 0;
        } else {
            textTimer++;
        }
    } else {
        if (IsKeyPressed(KEY_ENTER) && !fadein) {
            switch(textpart){
                case 0:
                    textpart++;
                    currentFullText = fullText;
                    ResetCutscene();
                    break;
                case 1:
                    textpart++;
                    currentFullText = fullText2;
                    ResetCutscene();
                    cutsceneaktiv = true;
                    fadeout = true;
                    globalState = storymodesection;
                    break;
                case 2:
                    textpart++;
                    currentFullText = fullText3;
                    ResetCutscene();
                    break;
                case 3:
                    textpart++;
                    currentFullText = fullText4;
                    ResetCutscene();
                    break;
                case 4:
                    textpart++;
                    currentFullText = fullText5;
                    igor = true;
                    igorname = true;
                    background = 3;
                    ResetCutscene();
                    break;
                case 5:
                    textpart++;
                    currentFullText = fullText6;
                    ResetCutscene();
                    break;
                case 6:
                    textpart++;
                    currentFullText = fullText7;
                    ResetCutscene();
                    break;
                case 7:
                    textpart++;
                    currentFullText = fullText8;
                    ResetCutscene();
                    break;
                case 8:
                    textpart++;
                    currentFullText = fullText9;
                    ResetCutscene();
                    break;
                case 9:
                    textpart++;
                    currentFullText = fullText10;
                    igor = false;
                    igorname = false;
                    background = 1;
                    ResetCutscene();
                    break;
                case 10:
                    textpart++;
                    currentFullText = fullText11;
                    ResetCutscene();
                    break;
                case 11:
                    textpart++;
                    currentFullText = fullText12;
                    ResetCutscene();
                    break;
                case 12:
                    fadeout = true;
                    break;
                case 13:
                    textpart = 0;
                    musicPlayerPtr->PlayMusic(MusicState::MainMenu);
                    musicPlayerPtr->StopMusic();
                    if(storymodeactive){
                        globalState = storymodesection;
                    }else{
                        globalState = gameplay;
                    }
                    break;
                default:
                    break;
            }
        }
    }
    musicPlayerPtr->Update();
    musicPlayerPtr->SetMusicVolume(masterMusicControl);
    if(IsKeyPressed(KEY_F2)){
        textpart = 12;
    }
}

void cutscene2::draw() {
    switch(background){
        case 0:
            DrawTexture(background_1, 0, 0, WHITE);
            break;
        case 1:
            DrawTexture(background_2, 0, 0, WHITE);
            break;
        case 2:
            DrawTexture(background_3, 0, 0, WHITE);
            break;
        case 3:
            DrawTexture(background_4, 0, 0, WHITE);
            break;
        default:
            break;
    }
    if(vasilyname){
        DrawTexture(Vasily_name, 217, 585, WHITE);
    }

    if(igorname){
        DrawTexture(Igor_name, 217, 585, WHITE);
    }

    if(vasily){
        DrawTexture(Vasily, 230, 220, WHITE);
    }

    if(igor){
        DrawTexture(Igor, 860, 220, WHITE);
    }

    DrawText(currentText.c_str(), textX, textY, fontSize, textColor);

    if(fadein){
        DrawTexturePro(fadeTexture,
                       Rectangle{0, 0, (float)fadeTexture.width, (float)fadeTexture.height},
                       Rectangle{0, 0, (float)GetScreenWidth(), (float)GetScreenHeight()},
                       {}, 0, Fade(WHITE, alpha));
    }

    if(fadeout){
        DrawTexturePro(fadeTexture,
                       Rectangle{0, 0, (float)fadeTexture.width, (float)fadeTexture.height},
                       Rectangle{0, 0, (float)GetScreenWidth(), (float)GetScreenHeight()},
                       {}, 0, Fade(WHITE, alpha));
    }
}

void cutscene2::ResetCutscene() {
    currentText = "";
    textTimer = 0;
    currentTextIndex = 0;
}

cutscene2::cutscene2(SoundPlayer *soundplayer, MusicPlayer *musicPlayer) {

    soundplayerPtr = soundplayer;
    musicPlayerPtr = musicPlayer;

    fontSize = 24;
    textColor = WHITE;

    textpart = 0;

    currentFullText =
            "Leon stinkt.";
    fullText =
            "immernoch.";
    fullText2 =
            "";
    fullText3 =
            "";
    fullText4 =
            "";
    fullText5 =
            "";
    fullText6 =
            "";
    fullText7 =
            "";
    fullText8 =

            "";
    fullText9 =
            "";
    fullText10 =
            "";
    fullText11 =
            "";
    fullText12 =
            "";


    textX = 200;
    textY = 660;
    currentText = "";
    textSpeed = 1;

    currentTextIndex = 0;
    textTimer = 0;
}
