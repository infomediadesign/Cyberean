//
// Created by ashra on 9/6/2023.
//
#include "gameoverscreen.h"

void gameoverscreen::update() {

    if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER)) {
        switch (cursor) {
            case 0:
                //soundplayerPtr->menuEnter_sound();
                state = 1; // (1) retry
                break;
            case 1:
                state = 2; // (2) mainmenu
                break;

            case 2:
                state = 3; // (3) exit
                break;
        }
    }

    if (IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) {
        cursor++;
        //soundplayerPtr->menuControll_sound();
    }
    if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) {
        cursor--;
        //soundplayerPtr->menuControll2_sound();
    }

    if (cursor < 0)
        cursor = 2;

    if (cursor > 2)
        cursor = 0;
}

void gameoverscreen::draw() {
    DrawTexture(background, 0, 0, WHITE);
    DrawTexture(pause, 410, 100, WHITE);
    //DrawTexture(windowsoli,0,0,WHITE);
}

bool gameoverscreen::IsMusicMuted() {
    return sound;
}

void gameoverscreen::buttons() {
    DrawTexture(resume, 334, 400, WHITE);
    DrawTexture(restart, 334, 500, WHITE);
    DrawTexture(mainmenu, 334, 600, WHITE);
    DrawTexture(music, 0, 750, WHITE);
    DrawTexture(_sound, 650, 750, WHITE);
    /*if (sound == true) {
        DrawTexture(Unmuted_dunkel, 368, 700, WHITE);
    } else {
        DrawTexture(Muted_dunkel, 368, 700, WHITE);
    }*/
    switch (cursor) {
        case 0:
            DrawTexture(resume_markiert, 334, 400, WHITE);
            break;
        case 1:
            DrawTexture(restart_markiert, 334, 500, WHITE);
            break;
        case 2:
            DrawTexture(mainmenu_markiert, 334, 600, WHITE);
            break;
        default:
            break;
    }
}

gameoverscreen::gameoverscreen() {

}