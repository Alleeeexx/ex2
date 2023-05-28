#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards) :
    m_player(playerName)
{
    m_deckSize = numOfCards;
    m_deck = new Card*[numOfCards];
    for(int i = 0; i < m_deckSize; i++)
    {
        m_deck[i] = new Card(cardsArray[i]);
    }
    m_currentCard = 0;
}

void Mtmchkin::playNextCard()
{
    if(m_currentCard >= m_deckSize)//checks if we finished the deck
    {
        m_currentCard = 0;
    }
    m_deck[m_currentCard]->printInfo();
    m_deck[m_currentCard]->applyEncounter(m_player);
    m_player.printInfo();
    m_currentCard++;
}

bool Mtmchkin::isOver() const
{
    if(m_player.getLevel() == 10)
    {
        return true;
    }
    if(m_player.isKnockedOut())
    {
        return true;
    }
    return false;
}

GameStatus Mtmchkin::getGameStatus() const
{
    if(m_player.getLevel() == 10)
    {
        return GameStatus::Win;
    }
    if(m_player.isKnockedOut())
    {
        return GameStatus::Loss;
    }
    return GameStatus::MidGame;
}

Mtmchkin::~Mtmchkin()
{
    for(int i = 0; i < m_deckSize; i++)
    {
        delete m_deck[i];
    }
    delete[] m_deck;
}