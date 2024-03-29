//
// Created by ashra on 9/6/2023.
//
#include "gameoverscreen.h"

void gameoverscreen::update() {

    if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER)) {
        soundplayer.menuEnter_sound();

        switch (cursor) {
            case 0:
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
        soundplayer.menuControll_sound();
    }
    if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) {
        cursor--;
        soundplayer.menuControll2_sound();
    }

    if (cursor < 0)
        cursor = 0;

    if (cursor > 2)
        cursor = 2;
}

void gameoverscreen::draw() {
    DrawTexture(background, 0, 0, WHITE);
    DrawTexture(gameover, 136, 100, WHITE);
}

void gameoverscreen::buttons() {
    DrawTexture(retry, 456, 400, WHITE);
    DrawTexture(mainmenu, 456, 500, WHITE);
    DrawTexture(exit, 456, 600, WHITE);

    switch (cursor) {
        case 0:
            DrawTexture(retry_markiert, 456, 400, WHITE);
            break;
        case 1:
            DrawTexture(mainmenu_markiert, 456, 500, WHITE);
            break;
        case 2:
            DrawTexture(exit_markiert, 456, 600, WHITE);
            break;
        default:
            break;
    }
}

gameoverscreen::gameoverscreen() {

}