#pragma once

#ifndef MONSTER_TYPES_H
#define MONSTER_TYPES_H

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

enum MonsterElement {
    Fire,
    Water,
    Ground,
    Wind
};

struct Monster {
    char name[50];
    MonsterElement element;
    float health;
    float strenght;
    float speed;
};

#endif