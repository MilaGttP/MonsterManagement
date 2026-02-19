#pragma once

#ifndef MONSTER_FILES_H
#define MONSTER_FILES_H

#include "monster_types.h"

void saveMonstersToFile(Monster* monsters, int count, const char* filename);
void loadMonstersFromFile(Monster*& monsters, int& count, const char* filename);

#endif