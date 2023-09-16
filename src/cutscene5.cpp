//
// Created by lukas on 12.09.2023.
//

#include "cutscene5.h"

void cutscene5::update(globalState &globalState) {
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
                    textpart++;
                    currentFullText = fullText22;
                    ResetCutscene();
                    break;
                case 22:
                    textpart++;
                    currentFullText = fullText23;
                    ResetCutscene();
                    break;
                case 23:
                    textpart++;
                    currentFullText = fullText24;
                    ResetCutscene();
                    break;
                case 24:
                    textpart++;
                    currentFullText = fullText25;
                    ResetCutscene();
                    break;
                case 25:
                    textpart++;
                    currentFullText = fullText26;
                    ResetCutscene();
                    break;
                case 26:
                    textpart++;
                    currentFullText = fullText27;
                    ResetCutscene();
                    break;
                case 27:
                    textpart++;
                    currentFullText = fullText28;
                    ResetCutscene();
                    break;
                case 28:
                    textpart++;
                    currentFullText = fullText29;
                    ResetCutscene();
                    break;
                case 29:
                    textpart++;
                    currentFullText = fullText30;
                    ResetCutscene();
                    break;
                case 30:
                    textpart++;
                    currentFullText = fullText31;
                    ResetCutscene();
                    break;
                case 31:
                    textpart++;
                    currentFullText = fullText32;
                    ResetCutscene();
                    break;
                case 32:
                    textpart++;
                    currentFullText = fullText33;
                    ResetCutscene();
                    break;
                case 33:
                    textpart++;
                    currentFullText = fullText34;
                    ResetCutscene();
                    break;
                case 34:
                    textpart++;
                    currentFullText = fullText35;
                    ResetCutscene();
                    break;
                case 35:
                    textpart++;
                    currentFullText = fullText36;
                    ResetCutscene();
                    break;
                case 36:
                    textpart++;
                    currentFullText = fullText37;
                    ResetCutscene();
                    break;
                case 37:
                    textpart++;
                    currentFullText = fullText38;
                    ResetCutscene();
                    break;
                case 38:
                    textpart++;
                    currentFullText = fullText39;
                    ResetCutscene();
                    break;
                case 39:
                    textpart++;
                    currentFullText = fullText40;
                    ResetCutscene();
                    break;
                case 40:
                    textpart++;
                    currentFullText = fullText41;
                    ResetCutscene();
                    break;
                case 41:
                    textpart++;
                    currentFullText = fullText42;
                    ResetCutscene();
                    break;
                case 42:
                    textpart++;
                    currentFullText = fullText43;
                    ResetCutscene();
                    break;
                case 43:
                    textpart++;
                    currentFullText = fullText44;
                    ResetCutscene();
                    break;
                case 44:
                    textpart++;
                    currentFullText = fullText45;
                    ResetCutscene();
                    break;
                case 45:
                    textpart++;
                    currentFullText = fullText46;
                    ResetCutscene();
                    break;
                case 46:
                    textpart++;
                    currentFullText = fullText47;
                    ResetCutscene();
                    break;
                case 47:
                    textpart++;
                    currentFullText = fullText48;
                    ResetCutscene();
                    break;
                case 48:
                    textpart++;
                    currentFullText = fullText49;
                    ResetCutscene();
                    break;
                case 49:
                    textpart++;
                    currentFullText = fullText50;
                    ResetCutscene();
                    break;
                case 50:
                    textpart++;
                    currentFullText = fullText51;
                    ResetCutscene();
                    break;
                case 51:
                    textpart++;
                    currentFullText = fullText52;
                    ResetCutscene();
                    break;
                case 52:
                    fadeout = true;
                    break;
                case 53:
                    textpart = 0;
                    musicPlayerPtr->PlayMusic(MusicState::MainMenu);
                    musicPlayerPtr->StopMusic();
                    if(storymodeactive){
                        storystate++;
                    }else{
                        globalState = creditsscreen;
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

void cutscene5::draw() {
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
        case 6:
            DrawTexture(background_7, 0, 0, WHITE);
            break;
        default:
            break;
    }

    DrawTextEx(myFont, currentText.c_str(), Vector2{textX, textY}, fontSize, spacing,  textColor);

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

void cutscene5::ResetCutscene() {
    currentText = "";
    textTimer = 0;
    currentTextIndex = 0;
}

cutscene5::cutscene5(SoundPlayer *soundplayer, MusicPlayer *musicPlayer) {

    soundplayerPtr = soundplayer;
    musicPlayerPtr = musicPlayer;

    fontSize = 24;
    textColor = WHITE;

    textpart = 0;

    currentFullText =
            "In einem Land, so voller Licht,\n"
            "Da lebt ein Kerl, sein Name ist Leon, zu erkennen an seinem Gesicht.\n"
            "Er stinkt nach Glück, so hell und klar,\n"
            "Doch nicht nach Schweiß, sondern Rosen, das ist wunderbar..";
    fullText =
            "Sein Lächeln strahlt wie Sonnenschein,\n"
            "Es brin uns Freude, Tag für Tag, das muss so sein.\n"
            "Seine Großzügigkeit kennt keine Ruh',\n"
            "Er stinkt nach Freundlichkeit, \n"
            "das ist kein Rätsel, nur die Wahrheit, du!.";
    fullText2 =
            "Abenteuer ruft er laut und wild,\n"
            "Mit ihm zu sein, fühlt sich an wie ein neues Bild.\n"
            "Er stinkt nach Lebenslust, nach Träumen, die nie enden,\n"
            "Unser Leon, er wird nie aufhören, sich zu wenden.";
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
    fullText22 =
            "";
    fullText23 =
            "";
    fullText24 =
            "";
    fullText25 =
            "";
    fullText26 =
            "";
    fullText27 =
            "";
    fullText28 =
            "";
    fullText29 =
            "";
    fullText30 =
            "";
    fullText31 =
            "";
    fullText32 =
            "";
    fullText33 =
            "";
    fullText34 =
            "";
    fullText35 =
            "";
    fullText36 =
            "";
    fullText37 =
            "";
    fullText38 =
            "";
    fullText39 =
            "";
    fullText40 =
            "";
    fullText41 =
            "";
    fullText42 =
            "";
    fullText43 =
            "";
    fullText44 =
            "";
    fullText45 =
            "";
    fullText46 =
            "";
    fullText47 =
            "";
    fullText48 =
            "";
    fullText49 =
            "";
    fullText50 =
            "";
    fullText51 =
            "";
    fullText52 =
            "";

    textX = 86.0f;
    textY = 744.0f;
    currentText = "";
    textSpeed = 1;

    currentTextIndex = 0;
    textTimer = 0;
}
