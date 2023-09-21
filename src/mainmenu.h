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
    bool fadeeffect = false;
    bool storymode = false;
    float alpha = 0.0f;
    float fadeSpeed = 1.0f;

    SoundPlayer *soundplayerPtr;

    Texture2D background = LoadTexture("assets/prototype_title_screen_selina_tech-demo.png");
    //Texture2D windowsoli = LoadTexture("assets/phenster.png");

    Texture2D fadeTexture = LoadTexture("assets/screens/storymode/fadeeffect.png");

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
    Texture2D credits = LoadTexture("assets/screens/menu_screen/Credits.png");
    Texture2D credits_markiert = LoadTexture("assets/screens/menu_screen/Credits_markiert.png");
    Texture2D level_select = LoadTexture("assets/screens/menu_screen/Level_select.png");
    Texture2D level_select_markiert = LoadTexture("assets/screens/menu_screen/Level_select_markiert.png");
    Texture2D continuebutton = LoadTexture("assets/screens/menu_screen/Continue.png");
    Texture2D continuebutton_markiert = LoadTexture("assets/screens/menu_screen/Continue_markiert.png");
    Texture2D unglitch = LoadTexture("assets/screens/menu_screen/logo_unglitch_anim.png");
    float age = 0;
    int counter = 0;
};

#endif //RAYLIBSTARTER_MAINMENU_H