#include "mainmenu.h"

void mainmenu::update(globalState &globalState) {

    if(IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)){
        cursor ++;
    }
    if(IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)){
        cursor --;
    }
     if(cursor < 0){
         cursor = 2;
     }

    if(cursor > 2){
        cursor = 0;
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
    //DrawTexture(windowsoli,0,0,WHITE);
}

bool mainmenu::IsMusicMuted(){
    return sound;
}

void mainmenu::buttons() {
    DrawTexture(Start,368,500,WHITE);
    DrawTexture(Exit,368,600,WHITE);
    if(sound == true){
        DrawTexture(Unmuted_dunkel,368,700,WHITE);
    }else{
        DrawTexture(Muted_dunkel,368,700,WHITE);
    }
    switch(cursor){
        case 0:
            DrawTexture(Start_markiert,368,500,WHITE);
            break;
        case 1:
            DrawTexture(Exit_markiert,368,600,WHITE);
            break;
        case 2:
            switch(sound) {
                case(true):
                    DrawTexture(Unmuted, 368, 700, WHITE);
                    if (IsKeyPressed(KEY_ENTER) && sound == true) {
                        sound = false;
                    }
                    break;
                case(false):
                    DrawTexture(Muted, 368, 700, WHITE);
                    if (IsKeyPressed(KEY_ENTER) && sound == false) {
                        sound = true;
                    }
                    break;
            }
    }
}