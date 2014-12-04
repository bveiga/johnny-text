#include "adventure.h"

using namespace std;

// void MyAudioCallback() {
// 	cout << "Playing the song..." << endl;
// }

void enemyInit() {
	// create enemies
	enemy enemy;
	for(int i=0; i<10; ++i) {
		enemy.HP = 12 + (rand() % (int)(20 - 1));
		enemy.strength = 5 + (rand() % (int)(8 - 1));
		enemy.defense = 5 + (rand() % (int)(8 - 1));
		enemy.speed = 5 + (rand() % (int)(8 - 1));
		enemies.push_back(enemy);
	}

	int size = enemies.size();
	for (int i = 0; i < size; ++i) {
		enemy = enemies.at(i);
		enemy.print();
	}
}

void init() {
}

void Battle() {

}

void randomBattle() {
	int chance = rand() % 100 + 1;
	if(chance > 60) {
		cout << "Crap, it's the thugs from before!" << endl;
		Battle();
	} else {
		cout << "Ok Good, I don't see any of those guys here either." << endl;
	}
}

void help() {
	cout << "Use the Folling commands:" << endl;
	cout << "move - to move around in the world map." << endl;
	cout << "quit - to quit the game. All progress will be lost." << endl;
}

int main() {
	// Init
	WorldMap map = WorldMap();
	Player player1 = Player();
	enemyInit();
	bool gameOver = false;

	// Initializers
	enemyInit();
	return 0;

	// Game Start
	cout << "Welcome to Rapture." << endl;
	cout << "What's you name, bloke? ";
	getline(cin, player1.name);

	cout << player1.name << ", ay?"<< endl;
	usleep(1000000);
	cout << "Well " << player1.name << ", this is a story of great adventure and perils." << endl;
	cout << "Here we go......................" << endl << endl << endl << endl;
	usleep(4000000);

	// Intro Scene
	cout << player1.name << "!" << endl;
	usleep(2500000);
	cout << player1.name << "! Wake up, we gotta leave now!" << endl;
	usleep(1200000);
	cout << "..." << endl;
	usleep(1200000);
	cout << "..." << endl;
	usleep(1200000);
	cout << "..." << endl;
	usleep(1200000);
	cout << "Holy crap man, can't believe we got away, right?" << endl;
	cout << player1.name << ": ";
	getline(cin, player1.response);
	usleep(1500000);
	cout << "Duuuuuude... Somebody was gonna kill you!" << endl;
	usleep(1500000);
	cout << "Look, we have to find Matt before it's too late." << endl;
	usleep(1500000);
	cout << "He lives at 4 east, and 4 north." << endl;
	cout << "(position: " << player1.pos.x << ", " << player1.pos.y << ")" << endl << endl;
	usleep(2500000);
	help();

	while (!gameOver) {
		cout << player1.name << ": ";
		getline(cin, player1.response);


		if(!(player1.response).compare("help")) {
			help();
		} else if(!(player1.response).compare("move")) {
			map.moveAround(player1);
			randomBattle();
		} else if(!(player1.response).compare("quit")) {
			cout << "Are you sure you want to quit? (yes/no)" << endl;
			cout << player1.name << ": ";
			getline(cin, player1.response);
			if(!(player1.response).compare("yes")) {
				exit(0);
			}
		}

	}	
}















