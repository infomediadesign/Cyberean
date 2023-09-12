//
// Created by lukas on 01.09.2023.
//

#include "levelselect.h"

void levelselect::update(globalState &globalState) {
    if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER)) {
        soundplayerPtr->menuEnter_sound();
        switch (cursor) {
            case 0:
                masterlevel = 0;
                fadeout = true;
                break;
            case 1:
                if(musicPlayerPtr->GetCurrentMusicState() == MusicState::part_1) {
                    musicPlayerPtr->PlayMusic(MusicState::MainMenu);
                    break;
                }
                musicPlayerPtr->StopAllMusicExceptMainMenu();
                musicPlayerPtr->PlayMusic(MusicState::part_1);
                break;

            case 2:
                masterlevel = 1;
                fadeout = true;
                break;

            case 3:
                if(musicPlayerPtr->GetCurrentMusicState() == MusicState::part_2) {
                    musicPlayerPtr->PlayMusic(MusicState::MainMenu);
                    break;
                }
                musicPlayerPtr->StopAllMusicExceptMainMenu();
                musicPlayerPtr->PlayMusic(MusicState::part_2);
                break;
            case 4:
                masterlevel = 2;
                fadeout = true;
                break;
            case 5:
                if(musicPlayerPtr->GetCurrentMusicState() == MusicState::part_3) {
                    musicPlayerPtr->PlayMusic(MusicState::MainMenu);
                    break;
                }
                musicPlayerPtr->StopAllMusicExceptMainMenu();
                musicPlayerPtr->PlayMusic(MusicState::part_3);
                break;
            case 6:
                masterlevel = 3;
                fadeout = true;
                break;
            case 7:
                if(musicPlayerPtr->GetCurrentMusicState() == MusicState::part_4) {
                    musicPlayerPtr->PlayMusic(MusicState::MainMenu);
                    break;
                }
                musicPlayerPtr->StopAllMusicExceptMainMenu();
                musicPlayerPtr->PlayMusic(MusicState::part_4);
                break;
            default:
                break;
        }


    }

    if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) {
        soundplayerPtr->menuControll_sound();
        if(cursor > 0){
            cursor--;
        }else if(cursor == 0){
            cursor = 7;
        }

    }
    if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) {
        soundplayerPtr->menuControll2_sound();
        if(cursor < 7){
            cursor++;
        }else if(cursor == 7){
            cursor = 0;
        }

    }

    if(IsKeyPressed(KEY_ESCAPE)){
        globalState = mainMenu;
    }

    if(musicPlayerPtr->GetCurrentMusicState() == MusicState::part_3 || musicPlayerPtr->GetCurrentMusicState() == MusicState::part_2){
        musicPlayerPtr->SetMusicVolume(masterMusicControl * 0.7);
    }else{
        musicPlayerPtr->SetMusicVolume(masterMusicControl);
    }

    if(fadeout){
        alpha += fadeSpeed * GetFrameTime();
        if (alpha >= 1.0f) {
            musicPlayerPtr->StopAllMusic();

            if(storymodeactive){
                storystate++;
            }else{
                globalState = gameplay;
            }
        }
    }
}

levelselect::levelselect(SoundPlayer *soundplayer, MusicPlayer *musicPlayer) {
    soundplayerPtr = soundplayer;
    musicPlayerPtr = musicPlayer;

    musicPlayerPtr->LoadMusic("assets/audio/tracks/level_1/cyberean_lvl1_part5.wav", MusicState::part_1);
    musicPlayerPtr->LoadMusic("assets/audio/tracks/level_2/cyberean_lvl2_part5.wav", MusicState::part_2);
    musicPlayerPtr->LoadMusic("assets/audio/tracks/level_3/cyberean_lvl3_part5.wav", MusicState::part_3);
    musicPlayerPtr->LoadMusic("assets/audio/tracks/level_4/cyberean_lvl4_part5.wav", MusicState::part_4);
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

    if(musicPlayerPtr->GetCurrentMusicState() != MusicState::MainMenu){
        switch(currentnote){
            case 0:
                DrawTexture(note1,1080,40,WHITE);
                break;
            case 1:
                DrawTexture(note2,1080,40,WHITE);
                break;
            default:
                break;
        }

        counter++;
        if(counter == 30){
            currentnote++;
            if(currentnote == 2){
                currentnote = 0;
            }
            counter = 0;
        }
    }

    if(fadeout){
        DrawTexturePro(fadeTexture,
                       Rectangle{0, 0, (float)fadeTexture.width, (float)fadeTexture.height},
                       Rectangle{0, 0, (float)GetScreenWidth(), (float)GetScreenHeight()},
                       {}, 0, Fade(WHITE, alpha));
    }
}
