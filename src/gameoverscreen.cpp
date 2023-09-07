//
// Created by ashra on 9/6/2023.
//
#include "gameoverscreen.h"

void gameoverscreen::update() {

    if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER)) {
        switch (cursor) {
            case 0:
                //soundplayerPtr->menuEnter_sound();
                state = 1; // (0) retry
                break;
            case 1:
                state = 2; // (1) main menu
                break;
            case 2:
                state = 3; // (2) exit
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
    DrawTexture(gameover, 410, 100, WHITE);
}

void gameoverscreen::buttons() {
    DrawTexture(retry, 334, 400, WHITE);
    DrawTexture(mainmenu, 334, 500, WHITE);
    DrawTexture(exit, 334, 600, WHITE);

    switch (cursor) {
        case 0:
            DrawTexture(retry_markiert, 334, 400, WHITE);
            break;
        case 1:
            DrawTexture(mainmenu_markiert, 334, 500, WHITE);
            break;
        case 2:
            DrawTexture(exit_markiert, 334, 600, WHITE);
            break;
        default:
            break;
    }
}

gameoverscreen::gameoverscreen() {

}