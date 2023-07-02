//
// Created by lukas on 20.06.2023.
//

#ifndef RAYLIBSTARTER_ENEMY_H
#define RAYLIBSTARTER_ENEMY_H
class gameSzene;

class Enemy {
    public:
    Enemy();

    enum  {
        boulder,
        firewall,
        bomb
    }Type;

    int posX;
    int posY;
    int moveDelay; //Changing the enemy speed (based on frame)
    bool isAlive = true;
    int gravityX; //Gravity Vector X
    int gravityY; //Gravity Vector Y
    int consecMoves; // Counts how many tiles an enemy has fallen (mainly for the CryptoMining Bomb)
    gameSzene* theMap;
    void draw();
    void update();
};
#endif //RAYLIBSTARTER_ENEMY_H
