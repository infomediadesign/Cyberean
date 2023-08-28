#ifndef RAYLIBSTARTER_MAINMENU_H
#define RAYLIBSTARTER_MAINMENU_H

#pragma once

#include "masterhead.h"
#include "SoundPlayer.h"
#include "mastervolumecontroll.h"

class mainmenu {
public:
    mainmenu(SoundPlayer *soundplayer);

    void update(globalState &globalState);

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

    Texture2D background = LoadTexture("assets/prototype_title_screen_selina_tech-demo.png");
    //Texture2D windowsoli = LoadTexture("assets/phenster.png");

    Texture2D Exit = LoadTexture("assets/screens/menu_screen/Exit.png");
    Texture2D Exit_markiert = LoadTexture("assets/screens/menu_screen/Exit_markiert.png");
    Texture2D Start = LoadTexture("assets/screens/menu_screen/Start.png");
    Texture2D Start_markiert = LoadTexture("assets/screens/menu_screen/Start_markiert.png");
    Texture2D Muted = LoadTexture("assets/screens/menu_screen/muted.png");
    Texture2D Muted_dunkel = LoadTexture("assets/screens/menu_screen/Muted_dunkel.png");
    Texture2D Unmuted = LoadTexture("assets/screens/menu_screen/unmuted.png");
    Texture2D Unmuted_dunkel = LoadTexture("assets/screens/menu_screen/unmuted_dunkel.png");
    Texture2D music = LoadTexture("assets/screens/menu_screen/music.png");
    Texture2D music_markiert = LoadTexture("assets/screens/menu_screen/music_markiert.png");
    Texture2D music_markiert_ausgewaehlt = LoadTexture("assets/screens/menu_screen/music_markiert_ausgewaehlt.png");
    Texture2D _sound = LoadTexture("assets/screens/menu_screen/sound.png");
    Texture2D sound_markiert = LoadTexture("assets/screens/menu_screen/sound_markiert.png");
    Texture2D sound_markiert_ausgewaehlt = LoadTexture("assets/screens/menu_screen/sound_markiert_ausgewaehlt.png");
    Texture2D strich = LoadTexture("assets/screens/menu_screen/Strich.png");

};


#endif //RAYLIBSTARTER_MAINMENU_H
