#include "monster_stats.h"
#include "monster_utils.h"

float getAverageHealth(Monster* monsters, int count) {
    if (!hasMonsters(count)) return 0.0;

    float totalHealth = 0.0f;

    for (int i = 0; i < count; i++)
        totalHealth += monsters[i].health;

    return totalHealth / count;
}


void getMaxStrenght(Monster* monsters, int count) {
    if (!hasMonsters(count)) return;

    int index = 0;

    for (int i = 1; i < count; i++)
        if (monsters[i].strenght > monsters[index].strenght)
            index = i;

    cout << "\nStrongest Monster:\n"; 
    cout << "\tName: " << monsters[index].name << endl; 
    cout << "\tStrenght: " << monsters[index].strenght << endl;
}


void getMinSpeed(Monster* monsters, int count) {
    if (!hasMonsters(count)) return;
    cout << "This functionality is coming soon...\n";


}


void statisticsMenu(Monster*& monsters, int& count) {
    int choice; 
    
    showHeader("STATISTICS MENU"); 
    
    cout << "\t1. Back to main menu\n"; 
    cout << "\t2. Average Health of Monsters\n"; 
    cout << "\t3. Monster with Maximum Strenght\n"; 
    cout << "\t4. Monster with Minimum Speed\n"; 
    cout << "\tEnter -> ";
    cin >> choice;

    switch (choice) { 
    case 1: 
        break; 
    case 2: 
        cout << "\n\tAverage Health: " << getAverageHealth(monsters, count) << endl;
        break; 
    case 3: 
        getMaxStrenght(monsters, count); 
        break; 
    case 4: 
        getMinSpeed(monsters, count);
        break; 
    default: 
        cout << "\n\tEnter valid!" << endl; 
        break; 
    }
}