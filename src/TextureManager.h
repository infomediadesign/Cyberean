//
// Created by ashra on 9/29/2023.
//
#include "raylib.h"


#ifndef RAYLIBSTARTER_TEXTUREMANAGER_H
#define RAYLIBSTARTER_TEXTUREMANAGER_H

class TextureManager {
public:
    static Texture2D playerTexture;
    static Texture2D playerDeathAnimMelt;
    static Texture2D playerDeathAnimAsh;
    static Texture2D playerDeathAnimGrid;
    static Texture2D playerDeathAnimSuck;
    static Texture2D playerDeathAnim;

    static Texture2D firewallAnim;
    static Texture2D rogueAntivirusMovingAnim;
    static Texture2D bombWarningAnim;
    static Texture2D bombExplodingAnim;
    static Texture2D bombCellExplodingAnim;
    static Texture2D malwareAliveAnim;
    static Texture2D malwareDeathAnim;
    static Texture2D malwareDetonationAnim;

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
    }

};

#endif //RAYLIBSTARTER_TEXTUREMANAGER_H