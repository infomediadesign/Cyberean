//
// Created by lukas on 09.09.2023.
//

#include "storymode.h"

storymode::storymode(){
    state2 = gameplay;
    musicPlayer.StopMusic();
    storymodeactive = true;
    musicPlayer.LoadMusic("assets/audio/tracks/misc/cutscenes.wav", MusicState::cutscene);
    musicPlayer.LoadMusic("assets/audio/tracks/misc/credits.wav", MusicState::credits);
}

void storymode::update(globalState &globalstate) {
    storymodeactive = true;

    if(storystate == 10){
        reset();
    }

    switch(storystate){
        case 0:
            thecutscene->update(state2);
            break;
        case 1:
            musicPlayer.StopMusic();
            if (gs == nullptr) {
                masterlevel = 0;
                gs = std::make_unique<gameScene>(masterlevel, &musicPlayer, &soundPlayer);
            }
            if (gs->restart == true) {
                gs = nullptr;
                gs = std::make_unique<gameScene>(masterlevel, &musicPlayer, &soundPlayer);
            }
            gs->update(state2);
            if(state2 == mainMenu){
                globalstate = mainMenu;
                state2 = gameplay;
            }
            break;
        case 2:
            gs = nullptr;
            thecutscene2->update(state2);
            break;
        case 3:
            musicPlayer.StopMusic();
            if (gs == nullptr) {
                masterlevel = 1;
                gs = std::make_unique<gameScene>(masterlevel, &musicPlayer, &soundPlayer);
            }
            if (gs->restart == true) {
                gs = nullptr;
                gs = std::make_unique<gameScene>(masterlevel, &musicPlayer, &soundPlayer);
            }
            gs->update(state2);
            if(state2 == mainMenu){
                globalstate = mainMenu;
                state2 = gameplay;
            }
            break;
        case 4:
            gs = nullptr;
            thecutscene3->update(state2);
            break;
        case 5:
            musicPlayer.StopMusic();
            if (gs == nullptr) {
                masterlevel = 2;
                gs = std::make_unique<gameScene>(masterlevel, &musicPlayer, &soundPlayer);
            }
            if (gs->restart == true) {
                gs = nullptr;
                gs = std::make_unique<gameScene>(masterlevel, &musicPlayer, &soundPlayer);
            }
            gs->update(state2);
            if(state2 == mainMenu){
                globalstate = mainMenu;
                state2 = gameplay;
            }
            break;
        case 6:
            gs = nullptr;
            thecutscene4->update(state2);
            break;
        case 7:
            musicPlayer.StopMusic();
            if (gs == nullptr) {
                masterlevel = 3;
                gs = std::make_unique<gameScene>(masterlevel, &musicPlayer, &soundPlayer);
            }
            if (gs->restart == true) {
                gs = nullptr;
                gs = std::make_unique<gameScene>(masterlevel, &musicPlayer, &soundPlayer);
            }
            gs->update(state2);
            if(state2 == mainMenu){
                globalstate = mainMenu;
                state2 = gameplay;
            }
            break;
        case 8:
            gs = nullptr;
            thecutscene5->update(state2);
            break;
        case 9:
            theepilogue->update(state2);
            break;
        case 10:
            globalstate = creditsscreen;
            break;
        default:
            break;
    }
}

void storymode::draw() {
    switch(storystate){
        case 0:
            thecutscene->draw();
            break;
        case 1:
            if (gs != nullptr) {
                gs->draw();
            }
            break;
        case 2:
            thecutscene2->draw();
            break;
        case 3:
            if (gs != nullptr) {
                gs->draw();
            }
            break;
        case 4:
            thecutscene3->draw();
            break;
        case 5:
            if (gs != nullptr) {
                gs->draw();
            }
            break;
        case 6:
            thecutscene4->draw();
            break;
        case 7:
            if (gs != nullptr) {
                gs->draw();
            }
            break;
        case 8:
            thecutscene5->draw();
            break;
        case 9:
            theepilogue->draw();
            break;
        case 10:
            break;
        default:
            break;
    }
}

void storymode::reset() {
    gs = nullptr;
    thecutscene = nullptr;
    thecutscene2 = nullptr;
    thecutscene3 = nullptr;
    thecutscene4 = nullptr;
    thecutscene5 = nullptr;
    theepilogue = nullptr;

    thecutscene = std::make_unique<cutscene>(&soundPlayer, &musicPlayer);
    thecutscene2 = std::make_unique<cutscene2>(&soundPlayer, &musicPlayer);
    thecutscene3 = std::make_unique<cutscene3>(&soundPlayer, &musicPlayer);
    thecutscene4 = std::make_unique<cutscene4>(&soundPlayer, &musicPlayer);
    thecutscene5 = std::make_unique<cutscene5>(&soundPlayer, &musicPlayer);
}