#include "monster_files.h"
#include <fstream>

void saveMonstersToFile(Monster* monsters, int count, const char* filename) {
	ofstream outFile(filename);

	if (!outFile) {
		cerr << "\n\tError with opening file..." << endl;
		return;
	}

	outFile << count << endl;

	for (int i = 0; i < count; i++) {
		outFile << monsters[i].name << endl;
		outFile << static_cast<int>(monsters[i].element) << endl;
		outFile << monsters[i].health << endl;
		outFile << monsters[i].strenght << endl;
		outFile << monsters[i].speed << endl;
	}

	outFile.close();
	cout << "\n\tData written successfully!" << endl;
}

void loadMonstersFromFile(Monster*& monsters, int& count, const char* filename) {
	ifstream inFile(filename);

	if (!inFile) {
		cerr << "\n\tError with opening file..." << endl;
		return;
	}

	if (monsters != nullptr) {
		delete[] monsters;
		monsters = nullptr;
	}

	int newCount;
	if (!(inFile >> newCount)) return;

	count = newCount;
	monsters = new Monster[count];

	for (int i = 0; i < count; i++) {
		inFile.ignore();
		inFile.getline(monsters[i].name, 50);

		int elem;
		inFile >> elem;
		monsters[i].element = static_cast<MonsterElement>(elem);

		inFile >> monsters[i].health;
		inFile >> monsters[i].strenght;
		inFile >> monsters[i].speed;
	}

	inFile.close();
	cout << "\n\tData read successfully!" << endl;
}
