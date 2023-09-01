//
// Created by lukas on 01.09.2023.
//

#include "levelselect.h"

void levelselect::update(globalState &globalState) {
    if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER)) {
        switch (cursor) {
            case 0:
                level = 0;
                globalState = gameplay;
                break;
            case 1:
                song1 = true;
                song2 = false;
                song3 = false;
                song4 = false;
                break;

            case 2:
                level = 1;
                globalState = gameplay;
                break;

            case 3:
                song1 = false;
                song2 = true;
                song3 = false;
                song4 = false;
                break;
            case 4:
                level = 2;
                globalState = gameplay;

                break;
            case 5:
                song1 = false;
                song2 = false;
                song3 = true;
                song4 = false;
                break;
            case 6:
                level = 3;
                globalState = gameplay;
                break;
            case 7:
                song1 = false;
                song2 = false;
                song3 = false;
                song4 = true;
                break;
            default:
                break;
        }
    }

    if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) {
        if(cursor > 0){
            cursor--;
        }else if(cursor == 0){
            cursor = 7;
        }

    }
    if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) {
        if(cursor < 7){
            cursor++;
        }else if(cursor == 7){
            cursor = 0;
        }

    }

    if(IsKeyPressed(KEY_ESCAPE)){
        globalState = mainMenu;
    }
}

levelselect::levelselect(SoundPlayer *soundplayer) {
    soundplayerPtr = soundplayer;
}

void levelselect::draw() {
    switch(cursor){
        case 0:
            DrawTexture(levelselect1,0,0,WHITE);
            break;
        case 1:
            DrawTexture(levelselect2,0,0,WHITE);
            break;
        case 2:
            DrawTexture(levelselect3,0,0,WHITE);
            break;
        case 3:
            DrawTexture(levelselect4,0,0,WHITE);
            break;
        case 4:
            DrawTexture(levelselect5,0,0,WHITE);
            break;
        case 5:
            DrawTexture(levelselect6,0,0,WHITE);
            break;
        case 6:
            DrawTexture(levelselect7,0,0,WHITE);
            break;
        case 7:
            DrawTexture(levelselect8,0,0,WHITE);
            break;
        default:
            break;

    }
}
