//
// Created by lukas on 09.09.2023.
//

#include "storymode.h"

storymode::storymode() : mycutscene(nullptr) {
    state2 = gameplay;
    musicPlayer.StopMusic();
    storymodeactive = true;
    musicPlayer.LoadMusic("assets/audio/tracks/misc/cutscenes.wav", MusicState::cutscene);
    if (!mycutscene)
    {
        mycutscene = std::make_unique<cutscene>(&soundPlayer, &musicPlayer);
    }

}

void storymode::update(globalState &globalstate) {
    switch(storystate){
        case 0:
            mycutscene->update(state2);
            break;
        case 1:
            if (gs == nullptr) {
                gs = std::make_unique<gameScene>(0, &musicPlayer, &soundPlayer);
            }
            if (gs->restart == true) {
                gs = nullptr;
                gs = std::make_unique<gameScene>(0, &musicPlayer, &soundPlayer);
            }
            gs->update(state2);
            if(state2 == mainMenu){
                globalstate = mainMenu;
                state2 = gameplay;
            }
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        default:
            break;
    }
}

void storymode::draw() {
    switch(storystate){
        case 0:
            mycutscene->draw();
            break;
        case 1:
            if (gs != nullptr) {
                gs->draw();
            }
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        default:
            break;
    }
}

void storymode::fadein() {
    if(fadeeffectout == true){
        for (float alpha = 1.0f; alpha > 0.0f; alpha -= fadeSpeed * GetFrameTime()) {
            switch(storystate){
                case 0:
                    mycutscene->update(state2);
                    mycutscene->draw();
                    break;
                default:
                    break;
            }
            // Draw the black PNG with fading alpha
            DrawTexturePro(fadeTexture,
                           Rectangle{0, 0, (float)fadeTexture.width, (float)fadeTexture.height},
                           Rectangle{0, 0, (float)GetScreenWidth(), (float)GetScreenHeight()},
                           {}, 0, Fade(WHITE, alpha));

        }
    }
    fadeeffectout = false;
    fadeAlpha = 0.0f;
}

void storymode::fadeout() {
    if(fadeeffectin == true){
        for (float alpha = 0.0f; alpha < 1.0f; alpha += fadeSpeed * GetFrameTime()) {
            switch(storystate){
                case 0:
                    mycutscene->draw();
                    break;
                default:
                    break;
            }
            // Draw the black PNG with fading alpha
            DrawTexturePro(fadeTexture,
                           Rectangle{0, 0, (float)fadeTexture.width, (float)fadeTexture.height},
                           Rectangle{0, 0, (float)GetScreenWidth(), (float)GetScreenHeight()},
                           {}, 0, Fade(WHITE, alpha));

            EndDrawing();
        }
    }
    fadeeffectin = false;
    fadeAlpha = 0.0f;
}
