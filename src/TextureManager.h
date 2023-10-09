//
// Created by ashra on 9/29/2023.
//
#include "raylib.h"


#ifndef RAYLIBSTARTER_TEXTUREMANAGER_H
#define RAYLIBSTARTER_TEXTUREMANAGER_H

class TextureManager {
public:
    //player
    static Texture2D playerTexture;
    static Texture2D playerDeathAnimMelt;
    static Texture2D playerDeathAnimAsh;
    static Texture2D playerDeathAnimGrid;
    static Texture2D playerDeathAnimSuck;
    static Texture2D playerDeathAnim;
    //enemies
    static Texture2D firewallAnim;
    static Texture2D rogueAntivirusMovingAnim;
    static Texture2D bombWarningAnim;
    static Texture2D bombExplodingAnim;
    static Texture2D bombCellExplodingAnim;
    static Texture2D malwareAliveAnim;
    static Texture2D malwareDeathAnim;
    static Texture2D malwareDetonationAnim;
    //boulders
    static Texture2D boulderEyesOpenLvl1;
    static Texture2D boulderEyesOpenLvl2;
    static Texture2D boulderEyesOpenLvl3;
    static Texture2D boulderEyesOpenLvl4;

    //boulders eyes opening animation:
    static Texture2D boulderEyesOpeningAnimLvl1;
    static Texture2D boulderEyesOpeningAnimLvl2;
    static Texture2D boulderEyesOpeningAnimLvl3;
    static Texture2D boulderEyesOpeningAnimLvl4;

    //boulders eyes closing animation:
    static Texture2D boulderEyesClosingAnimLvl1;
    static Texture2D boulderEyesClosingAnimLvl2;
    static Texture2D boulderEyesClosingAnimLvl3;
    static Texture2D boulderEyesClosingAnimLvl4;

    //boulders tumbling cw (Clock Wise):
    static Texture2D boulderRollingRightAnimLvl1;
    static Texture2D boulderRollingRightAnimLvl2;
    static Texture2D boulderRollingRightAnimLvl3;
    static Texture2D boulderRollingRightAnimLvl4;

    //boulders tumbling ccw (Counter Clock Wise):
    static Texture2D boulderRollingLeftAnimLvl1;
    static Texture2D boulderRollingLeftAnimLvl2;
    static Texture2D boulderRollingLeftAnimLvl3;
    static Texture2D boulderRollingLeftAnimLvl4;

    static void InitializeTextures() {
        //player
        playerTexture = LoadTexture("assets/animations/avatar/avatar_bopping_glasses_anim_1.1.png");
        playerDeathAnimMelt = LoadTexture("assets/animations/avatar/avatar_melt.png");
        playerDeathAnimSuck = LoadTexture("assets/animations/avatar/avatar_suck_anim.png");
        playerDeathAnimAsh = LoadTexture("assets/animations/avatar/avatar_ash_anim.png");
        playerDeathAnimGrid = LoadTexture("assets/animations/avatar/avatar_purple-grid_anim.png");

        //firewall
        firewallAnim = LoadTexture("assets/animations/enemies/firewall_anim.png");
        //rogue
        rogueAntivirusMovingAnim = LoadTexture("assets/animations/enemies/rogue_eyes_move_anim.png");
        //bomb
        bombWarningAnim = LoadTexture("assets/animations/enemies/cryptobomb_warning_anim.png");
        bombExplodingAnim = LoadTexture("assets/animations/enemies/cryptobomb_explosion_anim.png");
        bombCellExplodingAnim = LoadTexture("assets/animations/enemies/cryptobomb_explosion_single_anim.png");
        //malware
        malwareAliveAnim = LoadTexture("assets/animations/enemies/malware_anim.png");
        malwareDeathAnim = LoadTexture("assets/animations/enemies/malware_death_anim.png");
        malwareDetonationAnim = LoadTexture("assets/animations/enemies/malware_detonation_anim.png");

        //Boulders eyes open static:
        boulderEyesOpenLvl1 = LoadTexture("assets/data-chan/orange_data-chan_eyes_open.png");
        boulderEyesOpenLvl2 = LoadTexture("assets/data-chan/yellow_data-chan_eyes_open.png");
        boulderEyesOpenLvl3 = LoadTexture("assets/data-chan/grey_data-chan_eyes_open.png");
        boulderEyesOpenLvl4 = LoadTexture("assets/data-chan/corroded_data-chan_eyes_open.png");

        //boulders eyes opening:
        boulderEyesOpeningAnimLvl1 = LoadTexture("assets/data-chan/animations/anim_orange_data-chan_eyes_open.png");
        boulderEyesOpeningAnimLvl2 = LoadTexture("assets/data-chan/animations/anim_yellow_data-chan_eyes_open.png");
        boulderEyesOpeningAnimLvl3 = LoadTexture("assets/data-chan/animations/anim_grey_data-chan_eyes_open.png");
        boulderEyesOpeningAnimLvl4 = LoadTexture("assets/data-chan/animations/anim_corroded_data-chan_eyes_open.png");

        //boulders eyes closing:
        boulderEyesClosingAnimLvl1 = LoadTexture("assets/data-chan/animations/anim_orange_data-chan_eyes_close.png");
        boulderEyesClosingAnimLvl2 = LoadTexture("assets/data-chan/animations/anim_yellow_data-chan_eyes_close.png");
        boulderEyesClosingAnimLvl3 = LoadTexture("assets/data-chan/animations/anim_grey_data-chan_eyes_close.png");
        boulderEyesClosingAnimLvl4 = LoadTexture("assets/data-chan/animations/anim_corroded_data-chan_eyes_close.png");

        //boulders tumbling cw (Clock Wise):
        boulderRollingRightAnimLvl1 = LoadTexture("assets/data-chan/animations/orange_data-chan_tumbling_cw.png");
        boulderRollingRightAnimLvl2 = LoadTexture("assets/data-chan/animations/yellow_data-chan_tumbling_cw.png");
        boulderRollingRightAnimLvl3 = LoadTexture("assets/data-chan/animations/grey_data-chan_tumbling_cw.png");
        boulderRollingRightAnimLvl4 = LoadTexture("assets/data-chan/animations/corroded_data-chan_tumbling_cw.png");

        //boulders tumbling ccw (Counter Clock Wise):
        boulderRollingLeftAnimLvl1 = LoadTexture("assets/data-chan/animations/orange_data-chan_tumbling_ccw.png");
        boulderRollingLeftAnimLvl2 = LoadTexture("assets/data-chan/animations/yellow_data-chan_tumbling_ccw.png");
        boulderRollingLeftAnimLvl3 = LoadTexture("assets/data-chan/animations/grey_data-chan_tumbling_ccw.png");
        boulderRollingLeftAnimLvl4 = LoadTexture("assets/data-chan/animations/corroded_data-chan_tumbling_ccw.png");

    }

};

#endif //RAYLIBSTARTER_TEXTUREMANAGER_H