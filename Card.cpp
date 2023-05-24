#include "Card.h"

Card::Card(CardType type, const CardStats& stats)
{
    m_effect = type;
    m_stats = stats;
}

void Card::applyEncounter(Player& player) const
{
    //do encounter

    /* win true if player won
    printBattleResult(win);
    */
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