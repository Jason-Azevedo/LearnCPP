#include <iostream>
#include <cstdlib>
#include <ctime>
#include <array>

#include "entity.h"

void playerAttack(Entity *player, Entity *attacked)
{
    std::cout << "Choose an attack to perform on " << attacked->entityType << std::endl;

    // TODO: Iterate through attack options the player has and display them

    // TODO: Get user input for selecting attack

    // TODO: Logic for that attack (could be in a function)
}

void enemyAttack(Entity *enemy, Entity *player)
{
    // Let the enemy attack the player based on what they have.
}

// Returns true if the player won
bool combat(Entity *player, Entity *enemy)
{
    int round = 1;

    // If the player is alive and the entity is alive
    while (player->health > 0 && enemy->health > 0)
    {
        std::cout << std::endl
                  << "ROUND " << round << std::endl;

        // Determine who attacks first
        srand((unsigned)time(0));

        // speed roll
        int playerSpeedRoll = (rand() % 10) + 1;
        int enemySpeedRoll = (rand() % 10) + 1;

        int finalPlayerSpeed = playerSpeedRoll + player->speed;
        int finalEnemySpeed = enemySpeedRoll + enemy->speed;

        // Determine who attacks first
        if (finalPlayerSpeed > finalEnemySpeed)
        {
            // Player is faster, they go first
            playerAttack(player, enemy);
            enemyAttack(enemy, player);
        }
        else
        {
            // Enemy is faster, they go first
            enemyAttack(enemy, player);
            playerAttack(player, enemy);
        }

        round++;
    }

    // Did the player win the fight?
    return player->health > 0;
}
