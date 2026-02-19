#include "monster_crud.h"
#include "monster_stats.h"
#include "monster_utils.h"
#include "monster_files.h"

int main() {

    Monster* monsters = nullptr;
    int monsterCount = 0;
    const char* filename = "monsters_data.txt";

    loadMonstersFromFile(monsters, monsterCount, filename);

    int choice;

    do {
        showHeader("WELCOME TO MONSTER MANAGEMENT");
        choice = startMenu();

        switch (choice) {
        case 1:
            cout << "\n\tbye... friend :)";
            break;
        case 2:
            addMonster(monsters, monsterCount);
            break;
        case 3:
            showHeader("ALL MONSTERS");
            showAllMonsters(monsters, monsterCount);
            break;
        case 4:
            editMonster(monsters, monsterCount);
            break;
        case 5:
            deleteMenu(monsters, monsterCount);
            break;
        case 6:
            searchByName(monsters, monsterCount);
            break;
        case 7:
            sortBySpeed(monsters, monsterCount);
            break;
        case 8:
            statisticsMenu(monsters, monsterCount);
            break;
        }

        if (choice != 1) {
            cout << "\nPress Enter...";
            cin.ignore();
            cin.get();
        }

    } while (choice != 1);

    saveMonstersToFile(monsters, monsterCount, filename);

    delete[] monsters;

    // just for test (to commit)
}