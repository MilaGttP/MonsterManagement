#include "monster_utils.h"
#include "monster_crud.h"

int startMenu() {
    int choice; 
    cout << "\t1. Exit\n\t2. Add new monster\n\t3. View all monsters\n\t4. Edit monster\n\t5. Delete actions\n\t6. Search by monster name\n\t7. Sort by speed\n\t8. Statistics\n\tEnter -> "; 
    cin >> choice; 

    return choice;
}


void showHeader(const char* title) {
    system("cls");
    cout << "--- " << title << " ---\n\n";
}


bool hasMonsters(int count) {
    if (count == 0) {
        cout << "\tNo monsters available!" << endl;
        return false;
    }

    return true;
}


int selectMonster(Monster* monsters, int count) {
    showAllMonsters(monsters, count);

    int index; 
    cout << "\n\tEnter monster number -> "; 
    cin >> index; 
    
    if (index < 1 || index > count) {
        cout << "\n\tInvalid........." << endl; 
        return -1; 
    } 
    
    return index - 1;
}


void deleteMenu(Monster*& monsters, int& count) {
    if (!hasMonsters(count)) return; 
    showHeader("DELETE MENU"); 
    
    int choice;

    cout << "\t1. Back to main menu\n"; 
    cout << "\t2. Delete ONE monster\n"; 
    cout << "\t3. Delete ALL monsters\n"; 
    cout << "\tEnter -> "; 
    
    cin >> choice;

    switch (choice) { 
    case 1: 
        break; 
    case 2: 
        deleteMonster(monsters, count); 
        break; 
    case 3: 
        deleteAllMonsters(monsters, count);
        break; 
    default: 
        cout << "\n\tEnter valid!" << endl; 
        break; 
    }
}


void searchByName(Monster* monsters, int count) {
    if (!hasMonsters(count)) return; 
    showHeader("SEARCH BY NAME"); 
    cout << "This functionality is coming soon...\n";


}


void sortBySpeed(Monster* monsters, int count) {
    if (!hasMonsters(count)) return; 
    showHeader("SORT BY SPEED"); 
    cout << "This functionality is coming soon...\n";


}