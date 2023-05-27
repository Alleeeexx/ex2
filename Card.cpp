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
        case CardType::Battle:
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
        case CardType::Buff:
            if(player.pay(m_stats.cost))
            {
                player.buff(m_stats.buff);
            }
            return;
        case CardType::Heal:
            if(player.pay(m_stats.cost))
            {
                player.heal(m_stats.heal);
            }
            return;
        case CardType::Treasure:
            player.addCoins(m_stats.loot);
    }
}

void Card::printInfo() const
{
    switch(m_effect)
    {
        case CardType::Battle:
        printBattleCardInfo(m_stats);
        return;
        case CardType::Buff:
        printBuffCardInfo(m_stats);
        return;
        case CardType::Heal:
        printHealCardInfo(m_stats);
        return;
        case CardType::Treasure:
        printTreasureCardInfo(m_stats);
    }
}