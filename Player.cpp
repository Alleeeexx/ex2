#include "Player.h"
#include "utilities.h"
#include <iostream>

player::player(const char *newName,int newHp,int newForce)
{
    this->name = newName;
    this->coinsAmount = 0;
    this->level = 1;
    if (!newHp)
    {
        this->Hp = 100;
        this->maxHp = 100;
    }
    else if(newHp<=0)
    {
        this->Hp = 100;
        this->maxHp = 100;
    }
    else
    {
        this->Hp = newHp;
        this->maxHp = newHp;
    }
    if (!newForce)
    {
        this->force = 5;
    }
    else if(newForce<=0)
    {
        this->Hp = 5;
    }
    else
    {
        this->force = newForce;
    }
}

void player::printInfo()
{
     printPlayerInfo(this->name,this->level,this->force,this->Hp,this->coinsAmount); 
}

void player::levelUp()
{
    if (this->level<10)
    {
        this->level++;
    }
}

int player::getLevel()
{
    return this->level;
}

void player::buff(int num)
{
    this->force+=num;
}

void player::heal(int num)
{
    if (num>0)
    {
        this->Hp+=num;
    }
    if (this->Hp>this->maxHp)
    {
        this->Hp = this->maxHp;
    }
}

void player::damage(int num)
{
    if (num>0)
    {
        this->Hp = this->Hp-num;
    }
    if (this->Hp<0)
    {
        this->Hp = 0;
    }
}

bool player::isKnockedOut()
{
    if (this->Hp <= 0)
    {
        return true;
    }
    return false;
}

void player::addCoins(int num)
{
    this->coinsAmount += num;
}

bool player::pay(int num)
{
    if (this->coinsAmount - num >=0)
    {
        this->coinsAmount-=num;
        return true;
    }
    return false;
}

int player::getAttackStrength()
{
    int num = this->force+this->level;
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