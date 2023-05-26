#ifndef EX2_Player_H
#define EX2_Player_H

#include <iostream>
#include <string>
using namespace std;

class player
{
    private:
       const char *m_name;
       int m_maxHp;
       int m_Hp;
       int m_level;
       int m_coinsAmount;
       int m_force;
    public:
       player(const char *newName,int newHp,int newForce);
       void printInfo();
       void levelUp();
       int getLevel();
       void buff(int num);
       void heal(int num);
       void damage(int num);
       bool isKnockedOut();
       void addCoins(int num);
       bool pay(int num);
       int getAttackStrength();
};

#endif