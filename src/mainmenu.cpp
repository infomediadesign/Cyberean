//
// Created by lukas on 06.06.2023.
//

#include "mainmenu.h"

void mainmenu::update(globalState &globalState) {

    if(IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)){
        cursor ++;
    }
    if(IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)){
        cursor --;
    }
     if(cursor < 0){
         cursor = 0;
     }

    if(cursor > 2){
        cursor = 2;
    }

    if(IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER)){
        switch(cursor){
            case 0:
                globalState = gameplay;
                break;
            case 1:
                CloseWindow();
            case 2:
                break;
        }
    }
}

void mainmenu::draw() {
    DrawTexture(background,0,0,WHITE);
    DrawTexture(windowsoli,0,0,WHITE);
}

void mainmenu::buttons() {
    DrawTexture(Start_markiert,460,400,WHITE);
    DrawTexture(Exit,460,500,WHITE);
    if(sound == true){
        DrawTexture(Unmuted_dunkel,460,600,WHITE);
    }else{
        DrawTexture(Muted,460,600,WHITE);
    }
    DrawTexture(Unmuted_dunkel,460,600,WHITE);
    switch(cursor){
        case 0:
            DrawTexture(Start,460,400,WHITE);
            break;
        case 1:
            DrawTexture(Exit_markiert,460,500,WHITE);
            break;
        case 2:
            switch(sound) {
                case(true):
                    DrawTexture(Unmuted, 460, 600, WHITE);
                    break;
                case(false):
                    DrawTexture(Muted_dunkel, 460, 600, WHITE);
                    break;
            }

            if (IsKeyPressed(KEY_ENTER) && sound == true) {
                sound = false;
            }else{
                sound = true;
            }
    }
}