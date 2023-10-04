//
// Created by selina on 05/07/2023.
//

#pragma once

#include "masterhead.h"
#include "SoundPlayer.h"
#include "mastervolumecontroll.h"

class pausescreen {
public:

    int state = 0;
    int k = 3;
    pausescreen();

    void update();

    void draw();

    void buttons();

    bool IsMusicMuted();

    void musicconfig();

    void soundconfig();

    int cursor = 0;
    bool sound = true;
    bool _musicconfig = false;
    bool _soundconfig = false;

    SoundPlayer *soundplayerPtr;

    Texture2D background = LoadTexture("assets/screens/pause_screen/background_pause2.png");
    //Texture2D windowsoli = LoadTexture("assets/phenster.png");

    Texture2D mainmenu = LoadTexture("assets/screens/pause_screen/buttons/main_menu.png");
    Texture2D mainmenu_markiert = LoadTexture("assets/screens/pause_screen/buttons/main_menu_selected.png");
    Texture2D pause = LoadTexture("assets/screens/pause_screen/buttons/pause.png");
    Texture2D restart = LoadTexture("assets/screens/pause_screen/buttons/restart.png");
    Texture2D restart_markiert = LoadTexture("assets/screens/pause_screen/buttons/restart_selected.png");
    Texture2D resume = LoadTexture("assets/screens/pause_screen/buttons/resume.png");
    Texture2D resume_markiert = LoadTexture("assets/screens/pause_screen/buttons/resume_selected.png");

    Texture2D music = LoadTexture("assets/screens/pause_screen/buttons/music_pause.png");
    Texture2D music_markiert = LoadTexture("assets/screens/pause_screen/buttons/music_selected_pause.png");

    Texture2D _sound = LoadTexture("assets/screens/pause_screen/buttons/sounds_pause.png");
    Texture2D sound_markiert = LoadTexture("assets/screens/pause_screen/buttons/sounds_selected_pause.png");

    Texture2D quit_game = LoadTexture("assets/screens/pause_screen/buttons/quit_game_pause.png");
    Texture2D quit_game_markiert = LoadTexture("assets/screens/pause_screen/buttons/quit_game_selected_pause.png");

    Texture2D musicsound_selected = LoadTexture("assets/screens/pause_screen/music/music+sounds_selected_pause.png");
    Texture2D vol_0 = LoadTexture("assets/screens/pause_screen/music/vol_0_pause.png");
    Texture2D vol_1 = LoadTexture("assets/screens/pause_screen/music/vol_1_pause.png");
    Texture2D vol_2 = LoadTexture("assets/screens/pause_screen/music/vol_2_pause.png");
    Texture2D vol_3 = LoadTexture("assets/screens/pause_screen/music/vol_3_pause.png");
    Texture2D vol_4 = LoadTexture("assets/screens/pause_screen/music/vol_4_pause.png");
    Texture2D vol_5 = LoadTexture("assets/screens/pause_screen/music/vol_5_pause.png");
    Texture2D vol_6 = LoadTexture("assets/screens/pause_screen/music/vol_6_pause.png");
    Texture2D vol_7 = LoadTexture("assets/screens/pause_screen/music/vol_7_pause.png");
    Texture2D vol_8 = LoadTexture("assets/screens/pause_screen/music/vol_8_pause.png");
    Texture2D vol_9 = LoadTexture("assets/screens/pause_screen/music/vol_9_pause.png");
    Texture2D vol_10 = LoadTexture("assets/screens/pause_screen/music/vol_10_pause.png");

};
