#include "Player.h"
#include "utilities.h"
#include <iostream>

player::player(const char *newName,int newHp,int newForce)
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

void player::printInfo()
{
     printPlayerInfo(m_name,m_level,m_force,m_Hp,m_coinsAmount); 
}

void player::levelUp()
{
    if (m_level<10)
    {
        m_level++;
    }
}

int player::getLevel()
{
    return m_level;
}

void player::buff(int num)
{
    m_force+=num;
}

void player::heal(int num)
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

void player::damage(int num)
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

bool player::isKnockedOut()
{
    if (m_Hp <= 0)
    {
        return true;
    }
    return false;
}

void player::addCoins(int num)
{
    m_coinsAmount += num;
}

bool player::pay(int num)
{
    if (m_coinsAmount - num >=0)
    {
        m_coinsAmount-=num;
        return true;
    }
    return false;
}

int player::getAttackStrength()
{
    int num = m_force+m_level;
    return num;
}

int main()
{
    const char* name = "pele";
    player p(name,100,5);
    p.printInfo();
    p.levelUp();
    p.levelUp();
    printf("players current level is: %d\n",p.getLevel());
    p.buff(2);
    printf("players current attack is: %d\n",p.getAttackStrength());
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