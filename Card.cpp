#include "Card.h"
#include "Player.h"

Card::Card(CardType type, const CardStats& stats)
{
    m_effect = type;
    m_stats = stats;
}

void Card::applyEncounter(Player& player) const
{
    switch(m_effect)
    {
        case Battle:
            if(player.getAttackStrength() >= m_stats.force)
            {
                player.levelUp();
                player.addCoins(m_stats.loot);
                printBattleResult(true);
            }
            else
            {
                player.damage(m_stats.hpLossOnDefeat);
                printBattleResult(false);
            }
            return;
        case Buff:
            if(player.pay(m_stats.cost))
            {
                player.heal(m_stats.buff);
            }
            return;
        case Heal:
            if(player.pay(m_stats.cost))
            {
                player.heal(m_stats.heal);
            }
            return;
        case Treasure:
            player.addCoins(m_stats.loot);
    }
}

void Card::printInfo() const
{
    switch(m_effect)
    {
        case Battle:
        printBattleCardInfo(*this);
        return;
        case Buff:
        printBuffCardInfo(*this);
        return;
        case Heal:
        printHealCardInfo(*this);
        return;
        case Treasure:
        printTreasureCardInfo(*this);
    }
}