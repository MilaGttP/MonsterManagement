#pragma once

#ifndef MONSTER_CRUD_H
#define MONSTER_CRUD_H

#include "monster_types.h"

void addMonster(Monster*& monsters, int& count);
void showAllMonsters(Monster* monsters, int count);
void editMonster(Monster*& monsters, int& count);
void deleteMonster(Monster*& monsters, int& count);
void deleteAllMonsters(Monster*& monsters, int& count);

#endif