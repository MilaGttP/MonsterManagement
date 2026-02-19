#pragma once

#ifndef MONSTER_STATS_H
#define MONSTER_STATS_H

#include "monster_types.h"

float getAverageHealth(Monster* monsters, int count);
void getMaxStrenght(Monster* monsters, int count);
void getMinSpeed(Monster* monsters, int count);
void statisticsMenu(Monster*& monsters, int& count);

#endif