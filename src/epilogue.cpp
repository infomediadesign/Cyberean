//
// Created by lukas on 16.09.2023.
//

#include "epilogue.h"

void epilogue::update(globalState &globalState) {
    storymodeactive = true;
    musicPlayerPtr->PlayMusic(MusicState::credits);

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
            globalState = storymodesection;
            storystate++;
        }
    }

    if (currentTextIndex < currentFullText.length() && !fadein) {
        if (IsKeyPressed(KEY_ENTER)) {
            soundplayerPtr->cutsceneenter_sound();
            currentText = currentFullText;
            currentTextIndex = currentFullText.length();
        } else if (textTimer >= textSpeed) {
            currentText += currentFullText[currentTextIndex];
            currentTextIndex++;
            textTimer = 0;
            std::uniform_int_distribution<int> dist(1, 2);
            counter = dist(rng);

            if(counter == 1){
                soundplayerPtr->cutscenevoice_sound();
            }
        } else {
            textTimer++;
        }
    } else {
        if (IsKeyPressed(KEY_ENTER) && !fadein) {
            soundplayerPtr->cutsceneenter_sound();
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
                    textpart++;
                    currentFullText = fullText13;
                    ResetCutscene();
                    break;
                case 13:
                    textpart++;
                    currentFullText = fullText14;
                    ResetCutscene();
                    break;
                case 14:
                    textpart++;
                    currentFullText = fullText15;
                    ResetCutscene();
                    break;
                case 15:
                    textpart++;
                    currentFullText = fullText16;
                    ResetCutscene();
                    break;
                case 16:
                    textpart++;
                    currentFullText = fullText17;
                    ResetCutscene();
                    break;
                case 17:
                    textpart++;
                    currentFullText = fullText18;
                    ResetCutscene();
                    break;
                case 18:
                    textpart++;
                    currentFullText = fullText19;
                    ResetCutscene();
                    break;
                case 19:
                    textpart++;
                    currentFullText = fullText20;
                    ResetCutscene();
                    break;
                case 20:
                    textpart++;
                    currentFullText = fullText21;
                    ResetCutscene();
                    break;
                case 21:
                    fadeout = true;
                    break;
                case 22:
                    musicPlayerPtr->PlayMusic(MusicState::MainMenu);
                    musicPlayerPtr->StopMusic();
                    storystate++;
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

void epilogue::draw() {
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
        case 4:
            DrawTexture(background_5, 0, 0, WHITE);
            break;
        case 5:
            DrawTexture(background_6, 0, 0, WHITE);
            break;
        default:
            break;
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

void epilogue::ResetCutscene() {
    currentText = "";
    textTimer = 0;
    currentTextIndex = 0;
}

epilogue::epilogue(SoundPlayer *soundplayer, MusicPlayer *musicPlayer) {
    std::random_device rd;
    rng = std::mt19937(rd());

    cutsceneaktiv = true;

    soundplayerPtr = soundplayer;
    musicPlayerPtr = musicPlayer;

    textColor = WHITE;

    textpart = 0;

    currentFullText =
            "";
    fullText =
            "";
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
    fullText13 =
            "";
    fullText14 =
            "";
    fullText15 =
            "";
    fullText16 =
            "";
    fullText17 =
            "";
    fullText18 =
            "";
    fullText19 =
            "";
    fullText20 =
            "";
    fullText21 =
            "";

    textX = 86.0f;
    textY = 744.0f;
    currentText = "";
    textSpeed = 1;

    currentTextIndex = 0;
    textTimer = 0;
}