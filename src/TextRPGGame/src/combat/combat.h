#pragma once

/* INCLUDES */
#include "entity.h"

/* FUNCTIONS */
void combat(Entity *player, Entity *enemy);

void playerAttack(Entity *player, Entity *attacked);
void enemyAttack(Entity *enemy, Entity *player);

void playerDied();
void enemyDied(Entity *enemy);
