#pragma once

#ifndef MONSTER_UTILS_H
#define MONSTER_UTILS_H

#include "monster_types.h"
#include "monster_crud.h"

int startMenu();
void deleteMenu(Monster*& monsters, int& count);

void showHeader(const char* title);
bool hasMonsters(int count);
int selectMonster(Monster* monsters, int count);

void searchByName(Monster* monsters, int count);
void sortBySpeed(Monster* monsters, int count);

#endif