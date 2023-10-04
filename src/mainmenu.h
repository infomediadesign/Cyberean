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

    Texture2D Exit = LoadTexture("assets/screens/title_screen/buttons/quit_game.png");
    Texture2D Exit_markiert = LoadTexture("assets/screens/title_screen/buttons/quit_game_selected.png");
    Texture2D Start = LoadTexture("assets/screens/title_screen/buttons/start_game.png");
    Texture2D Start_markiert = LoadTexture("assets/screens/title_screen/buttons/start_game_selected.png");

    Texture2D music = LoadTexture("assets/screens/title_screen/buttons/music.png");
    Texture2D music_markiert = LoadTexture("assets/screens/title_screen/buttons/music_selected.png");

    Texture2D _sound = LoadTexture("assets/screens/title_screen/buttons/sounds.png");
    Texture2D sound_markiert = LoadTexture("assets/screens/title_screen/buttons/sounds_selected.png");

    Texture2D credits = LoadTexture("assets/screens/title_screen/buttons/credits.png");
    Texture2D credits_markiert = LoadTexture("assets/screens/title_screen/buttons/credits_selected.png");
    Texture2D level_select = LoadTexture("assets/screens/title_screen/buttons/level_selected.png");
    Texture2D level_select_markiert = LoadTexture("assets/screens/title_screen/buttons/level_selected_selected.png");

    Texture2D continuebutton = LoadTexture("assets/screens/title_screen/buttons/continue.png");
    Texture2D continuebutton_markiert = LoadTexture("assets/screens/title_screen/buttons/continue_selected.png");

    Texture2D musicsound_selected = LoadTexture("assets/screens/title_screen/music/musicsound_selected.png");
    Texture2D vol_0 = LoadTexture("assets/screens/title_screen/music/vol_0.png");
    Texture2D vol_1 = LoadTexture("assets/screens/title_screen/music/vol_1.png");
    Texture2D vol_2 = LoadTexture("assets/screens/title_screen/music/vol_2.png");
    Texture2D vol_3 = LoadTexture("assets/screens/title_screen/music/vol_3.png");
    Texture2D vol_4 = LoadTexture("assets/screens/title_screen/music/vol_4.png");
    Texture2D vol_5 = LoadTexture("assets/screens/title_screen/music/vol_5.png");
    Texture2D vol_6 = LoadTexture("assets/screens/title_screen/music/vol_6.png");
    Texture2D vol_7 = LoadTexture("assets/screens/title_screen/music/vol_7.png");
    Texture2D vol_8 = LoadTexture("assets/screens/title_screen/music/vol_8.png");
    Texture2D vol_9 = LoadTexture("assets/screens/title_screen/music/vol_9.png");
    Texture2D vol_10 = LoadTexture("assets/screens/title_screen/music/vol_10.png");


    Texture2D unglitch = LoadTexture("assets/screens/menu_screen/logo_unglitch_anim.png");
    float age = 0;
    int counter = 0;

    Texture2D hintergrund = LoadTexture("assets/screens/title_screen/title_screen.png");
};

#endif //RAYLIBSTARTER_MAINMENU_H