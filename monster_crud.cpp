#include "monster_crud.h"
#include "monster_utils.h"

void addMonster(Monster*& monsters, int& count) {
    showHeader("ADD MONSTER");

    Monster* temp = new Monster[count + 1];

    for (int i = 0; i < count; i++)
        temp[i] = monsters[i];

    cin.ignore();

    cout << "\tName: ";
    cin.getline(temp[count].name, 50);

    int elem; 
    cout << "\tElement (0 - Fire, 1 - Water, 2 - Ground, 3 - Wind) -> "; 
    cin >> elem; 
    temp[count].element = static_cast<MonsterElement>(elem);

    cout << "\tHealth: ";
    cin >> temp[count].health;

    cout << "\tStrength: ";
    cin >> temp[count].strenght;

    cout << "\tSpeed: ";
    cin >> temp[count].speed;

    delete[] monsters;
    monsters = temp;
    count++;

    cout << "\n\tMonster added!" << endl;
}


void showAllMonsters(Monster* monsters, int count) {
    if (!hasMonsters(count)) return;

    cout << left
        << setw(5) << "#"
        << setw(15) << "Name"
        << setw(10) << "Element"
        << setw(10) << "Health"
        << setw(10) << "Strenght"
        << setw(10) << "Speed" << endl;

    cout << string(60, '-') << endl;

    for (int i = 0; i < count; i++) {
        string el;

        switch (monsters[i].element) {
        case Fire: el = "Fire"; break;
        case Water: el = "Water"; break;
        case Ground: el = "Ground"; break;
        case Wind: el = "Wind"; break;
        }

        cout << setw(5) << i + 1
            << setw(15) << monsters[i].name
            << setw(10) << el
            << setw(10) << monsters[i].health
            << setw(10) << monsters[i].strenght
            << setw(10) << monsters[i].speed
            << endl;
    }
}


void editMonster(Monster*& monsters, int& count) {
    if (!hasMonsters(count)) return;

    showHeader("EDIT MONSTER");

    int index = selectMonster(monsters, count);
    if (index == -1) return;

    cin.ignore();
    cout << "\n--- Editing monster: " << monsters[index].name << endl;

    cout << "\tNew name: ";
    cin.getline(monsters[index].name, 50);

    int elem; 
    cout << "\tElement (0 - Fire, 1 - Water, 2 - Ground, 3 - Wind) -> "; 
    cin >> elem; 

    if (elem >= 0 && elem <= 3) { 
        monsters[index].element = static_cast<MonsterElement>(elem); 
    }
    else { 
        cout << "\tInvalid element! Keeping previous value." << endl; 
    }

    cout << "\tHealth: ";
    cin >> monsters[index].health;

    cout << "\tStrength: ";
    cin >> monsters[index].strenght;

    cout << "\tSpeed: ";
    cin >> monsters[index].speed;

    cout << "\n\tMonster updated!" << endl;
}


void deleteMonster(Monster*& monsters, int& count) {
    if (!hasMonsters(count)) return;

    showHeader("DELETE MONSTER");

    int index = selectMonster(monsters, count);
    if (index == -1) return;

    char confirm; 
    cout << "\n\tAre you sure you want to delete " << monsters[index].name << "? (y/n) -> "; 
    cin >> confirm; 
    
    if (confirm != 'y' && confirm != 'Y') { 
        cout << "\n\tDeletion cancelled..." << endl; 
        return; 
    }

    Monster* temp = new Monster[count - 1];

    int j = 0;

    for (int i = 0; i < count; i++) {
        if (i != index) {
            temp[j] = monsters[i];
            j++;
        }
    }

    delete[] monsters;
    monsters = temp;
    count--;

    cout << "\n\tMonster deleted!" << endl;
}


void deleteAllMonsters(Monster*& monsters, int& count) {
    if (!hasMonsters(count)) return; 
    showHeader("DELETE ALL MONSTERS"); 

    char confirm; 
    
    cout << "\n\tWARNINGG: This action will delete ALL monsters!\n"; 
    cout << "\tAre you sure? (y/n) -> "; 

    cin >> confirm; 

    if (confirm != 'y' && confirm != 'Y') { 
        cout << "\n\tDeletion cancelled..." << endl; 
        return; 
    }

    delete[] monsters;
    monsters = nullptr;
    count = 0;

    cout << "\n\tAll monsters have been deleted!" << endl;
}