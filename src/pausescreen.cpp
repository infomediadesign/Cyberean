//
// Created by selina on 05/07/2023.
//

#include "pausescreen.h"

void pausescreen::update(globalState &globalState) {

    if (IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) {
        cursor++;
    }
    if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) {
        cursor--;
    }
    if (cursor < 0) {
        cursor = 2;
    }

    if (cursor > 2) {
        cursor = 0;
    }

    if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER)) {
        switch (cursor) {
            case 0:
                globalState = gameplay;

                break;

            case 1:
                globalState = settings;

                break;

            case 2:
                globalState = mainMenu;

                break;

            case 3:
                CloseWindow();

                break;
        }
    }
}

void pausescreen::draw() {
    DrawTexture(background, 0, 0, WHITE);
    DrawTexture(windowsoli, 0, 0, WHITE);
}

bool pausescreen::IsMusicMuted() {
    return sound;
}

void pausescreen::buttons() {
    DrawTexture(Start_markiert, 460, 400, WHITE);
    DrawTexture(Exit, 460, 500, WHITE);
    if (sound == true) {
        DrawTexture(Unmuted_dunkel, 460, 600, WHITE);
    } else {
        DrawTexture(Muted_dunkel, 460, 600, WHITE);
    }
    switch (cursor) {
        case 0:
            DrawTexture(Start, 460, 400, WHITE);
            break;
        case 1:
            DrawTexture(Exit_markiert, 460, 500, WHITE);
            break;
        case 2:
            switch (sound) {
                case (true):
                    DrawTexture(Unmuted, 460, 600, WHITE);
                    if (IsKeyPressed(KEY_ENTER) && sound == true) {
                        sound = false;
                    }
                    break;
                case (false):
                    DrawTexture(Muted, 460, 600, WHITE);
                    if (IsKeyPressed(KEY_ENTER) && sound == false) {
                        sound = true;
                    }
                    break;
            }
    }
}