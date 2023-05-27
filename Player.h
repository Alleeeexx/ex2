#ifndef EX2_Player_H
#define EX2_Player_H

#include <iostream>
#include <string>
using namespace std;

class Player
{
    private:
       const char *m_name;
       int m_maxHp;
       int m_Hp;
       int m_level;
       int m_coinsAmount;
       int m_force;
    public:
       Player(const char *newName, int newHp = 100, int newForce = 5);
       void printInfo() const;
       void levelUp();
       int getLevel() const;
       void buff(int num);
       void heal(int num);
       void damage(int num);
       bool isKnockedOut() const;
       void addCoins(int num);
       bool pay(int num);
       int getAttackStrength() const;
};

#endif