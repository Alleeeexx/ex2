#include "Player.h"
#include "utilities.h"
#include <iostream>

Player::Player(const char *newName, int newHp, int newForce)
{
    m_name = newName;
    m_coinsAmount = 0;
    m_level = 1;
    if (!newHp)
    {
        m_Hp = 100;
        m_maxHp = 100;
    }
    else if(newHp<=0)
    {
        m_Hp = 100;
        m_maxHp = 100;
    }
    else
    {
        m_Hp = newHp;
        m_maxHp = newHp;
    }
    if (!newForce)
    {
        m_force = 5;
    }
    else if(newForce<=0)
    {
        m_Hp = 5;
    }
    else
    {
        m_force = newForce;
    }
}

void Player::printInfo() const
{
     printPlayerInfo(m_name,m_level,m_force,m_Hp,m_coinsAmount); 
}

void Player::levelUp()
{
    if (m_level<10)
    {
        m_level++;
    }
}

int Player::getLevel() const
{
    return m_level;
}

void Player::buff(int num)
{
    m_force+=num;
}

void Player::heal(int num)
{
    if (num>0)
    {
        m_Hp+=num;
    }
    if (m_Hp>m_maxHp)
    {
        m_Hp = m_maxHp;
    }
}

void Player::damage(int num)
{
    if (num>0)
    {
        m_Hp = m_Hp-num;
    }
    if (m_Hp<0)
    {
        m_Hp = 0;
    }
}

bool Player::isKnockedOut() const
{
    if (m_Hp <= 0)
    {
        return true;
    }
    return false;
}

void Player::addCoins(int num)
{
    m_coinsAmount += num;
}

bool Player::pay(int num)
{
    if (m_coinsAmount - num >=0)
    {
        m_coinsAmount-=num;
        return true;
    }
    return false;
}

int Player::getAttackStrength() const
{
    int num = m_force+m_level;
    return num;
}

/*

int main()
{
    const char* name = "pele";
    Player p(name,100,5);
    p.printInfo();
    p.levelUp();
    p.levelUp();
    printf("Players current level is: %d\n",p.getLevel());
    p.buff(2);
    printf("Players current attack is: %d\n",p.getAttackStrength());
    p.damage(20);
    p.heal(10);
    p.addCoins(99);
    p.printInfo();
    p.pay(80);
    p.printInfo();
    p.pay(222);
    p.printInfo();
    p.damage(120);
    if (p.isKnockedOut())
    {
        printf("dead");
    }
    return 0;
}

*/