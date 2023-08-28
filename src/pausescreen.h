//
// Created by selina on 05/07/2023.
//

#pragma once

#include "masterhead.h"
#include "SoundPlayer.h"
#include "mastervolumecontroll.h"

class pausescreen {
public:
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

    Texture2D mainmenu = LoadTexture("assets/screens/pause_screen/mainmenu.png");
    Texture2D mainmenu_markiert = LoadTexture("assets/screens/pause_screen/mainmenu_markiert.png");
    Texture2D pause = LoadTexture("assets/screens/pause_screen/pause.png");
    Texture2D restart = LoadTexture("assets/screens/pause_screen/restart.png");
    Texture2D restart_markiert = LoadTexture("assets/screens/pause_screen/restart_markiert.png");
    Texture2D resume = LoadTexture("assets/screens/pause_screen/resume.png");
    Texture2D resume_markiert = LoadTexture("assets/screens/pause_screen/resume_markiert.png");


    Texture2D music = LoadTexture("assets/screens/menu_screen/music.png");
    Texture2D music_markiert = LoadTexture("assets/screens/menu_screen/music_markiert.png");
    Texture2D music_markiert_ausgewaehlt = LoadTexture("assets/screens/menu_screen/music_markiert_ausgewaehlt.png");
    Texture2D _sound = LoadTexture("assets/screens/menu_screen/sound.png");
    Texture2D sound_markiert = LoadTexture("assets/screens/menu_screen/sound_markiert.png");
    Texture2D sound_markiert_ausgewaehlt = LoadTexture("assets/screens/menu_screen/sound_markiert_ausgewaehlt.png");
    Texture2D strich = LoadTexture("assets/screens/menu_screen/Strich.png");

};
