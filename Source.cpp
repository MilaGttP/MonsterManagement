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

int startMenu();
void statisticsMenu();

void addMonster();
void showAllMonsters();

// for future
void editMonster();
//void deleteMonster();

// sorting funcs...
// search funcs...

// statistics funcs
float getAverageHealth();
void getMaxStrenght();
void getMinSpeed();

Monster* monsters = nullptr;
int monsterCount = 0;

int main() {
	int choice;

	do {
		system("cls");
		cout << "--- WELCOME TO MONSTER MANAGEMENT --- ";

		choice = startMenu();

		switch (choice)
		{
		case 1:
			cout << "\n\n\t\tbye... friend :)";
			break;
		case 2:
			addMonster();
			break;
		case 3:
			system("cls");
			cout << "--- ALL MONSTERS ---\n" << endl;
			showAllMonsters();
			break;
		case 4:
			editMonster();
			break;
		case 5:
			statisticsMenu();
			break;
		default:
			cout << "\nEnter valid!" << endl;
			break;
		}

		if (choice != 1) {
			cout << "\nPress Enter to continue...";
			cin.ignore();
			cin.get();
		}

	} while (choice != 1);

	delete[] monsters;
	monsters = nullptr;
}


int startMenu() {
	int choice;
	cout << "\n\n\t1. Exit\n\t2. Add new monster\n\t3. View all monsters\n\t4. Edit monster\n\t5. Statistics\n\tEnter -> ";
	cin >> choice;
	return choice;
}

void statisticsMenu() {
	system("cls");
	int choice;
	cout << "--- STATISTICS MENU ---\n";
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
			cout << "\n\tAverage Health: " << getAverageHealth() << endl;
			break;
		case 3:
			getMaxStrenght();
			break;
		case 4:
			getMinSpeed();
			break;
		default:
			cout << "\nEnter valid!" << endl;
			break;
	}
}

void addMonster() {
	Monster* temp = new Monster[monsterCount + 1];

	for (int i = 0; i < monsterCount; i++) {
		temp[i] = monsters[i];
	}

	cin.ignore();

	cout << "\n\t Enter name -> ";
	cin.getline(temp[monsterCount].name, 50);

	int elem;
	cout << "\t Element (0 - Fire, 1 - Water, 2 - Ground, 3 - Wind) -> ";
	cin >> elem;
	temp[monsterCount].element = static_cast<MonsterElement>(elem);

	cout << "\t Health -> ";
	cin >> temp[monsterCount].health;

	cout << "\t Strenght -> ";
	cin >> temp[monsterCount].strenght;

	cout << "\t Speed -> ";
	cin >> temp[monsterCount].speed;

	delete[] monsters;
	monsters = temp;
	monsterCount++;

	cout << "\n\t Monster added!" << endl;
}

void showAllMonsters() {
	if (monsterCount == 0) {
		cout << "No monsters available!" << endl;
		return;
	}

	cout << left
		<< setw(5) << "#"
		<< setw(15) << "Name"
		<< setw(10) << "Element"
		<< setw(10) << "Health"
		<< setw(10) << "Strenght"
		<< setw(10) << "Speed" << endl;
	cout << string(60, '-') << endl;

	for (int i = 0; i < monsterCount; i++) {
		string elementStr;

		switch (monsters[i].element) {
			case Fire: elementStr = "Fire"; break;
			case Water: elementStr = "Water"; break;
			case Ground: elementStr = "Ground"; break;
			case Wind: elementStr = "Wind"; break;
		}

		cout << left
			<< setw(5) << (i + 1)
			<< setw(15) << monsters[i].name
			<< setw(10) << elementStr
			<< setw(10) << monsters[i].health
			<< setw(10) << monsters[i].strenght
			<< setw(10) << monsters[i].speed << endl;
	}
}

float getAverageHealth() {
	if (monsterCount == 0) {
		cout << "\n\tNo monsters available!" << endl;
		return 0.0;
	}

	float totalHealth = 0.0f;

	for (int i = 0; i < monsterCount; i++) {
		totalHealth += monsters[i].health;
	}

	return totalHealth / monsterCount;
}

void getMaxStrenght() {
	if (monsterCount == 0) {
		cout << "\n\tNo monsters available!" << endl;
		return;
	}

	int index = 0;

	for (int i = 1; i < monsterCount; i++) {
		if (monsters[i].strenght > monsters[index].strenght) {
			index = i;
		}
	}

	cout << "\nStrongest Monster:\n";
	cout << "\tName: " << monsters[index].name << endl;
	cout << "\tStrenght: " << monsters[index].strenght << endl;
}

void getMinSpeed() {
	if (monsterCount == 0) {
		cout << "\n\tNo monsters available!" << endl;
		return;
	}


}

void editMonster() {
	if (monsterCount == 0) {
		cout << "\n\tNo monsters available!" << endl;
		return;
	}

	system("cls");
	cout << "--- EDIT MONSTER ---\n" << endl;
	showAllMonsters();

	int index;
	cout << "\n\tEnter monster number to edit -> ";
	cin >> index;

	if (index < 1 || index > monsterCount) {
		cout << "\n\tInvalid........." << endl;
		return;
	}

	index--;

	cin.ignore();

	cout << "\n--- Editing monster: " << monsters[index].name << endl;

	cout << "\t Enter new name -> ";
	cin.getline(monsters[index].name, 50);

	int elem;
	cout << "\t Element (0 - Fire, 1 - Water, 2 - Ground, 3 - Wind) -> ";
	cin >> elem;

	if (elem >= 0 && elem <= 3) {
		monsters[index].element = static_cast<MonsterElement>(elem);
	} 
	else {
		cout << "\t Invalid element! Keeping previous value." << endl;
	}

	cout << "\t Health -> ";
	cin >> monsters[index].health;

	cout << "\t Strenght -> ";
	cin >> monsters[index].strenght;

	cout << "\t Speed -> ";
	cin >> monsters[index].speed;

	cout << "\n\t Monster updated!" << endl;
}