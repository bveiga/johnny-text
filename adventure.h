#ifndef ADV_H
#define ADV_H

#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<string> compass = {"north", "west", "south", "east", "stay"};
vector<string> battleCommands = {"attack", "defend", "escape"};

struct position {
	int x;
	int y;
};

struct Enemy {
	int HP;
	int strength;
	int defense;
	int speed;

	void print() {
		printf("HP: %d\n strength: %d\n defense: %d\n speed: %d\n", HP, strength, defense, speed);
	}
};

struct Matt {

};

vector<Enemy> enemies;

class Player {
	public:
		string name;
		string response;
		int hoursPlayed;
		
		int HP;
		int strength;
		int defense;
		int speed;
		int luck;
		int exp;

		position pos;

		Player() {
			name = "";
			response = "";
			hoursPlayed = 0;
			HP = 100;
			strength = defense = speed = luck = 5;

			pos.x = 1;
			pos.y = 1;
		}

		int attack() {
			return 0;
		}
};


class WorldMap {
	private:
		char * worldmap;

		int width;
		int height;

	public:
		WorldMap() {
			width = 10;
			height = 10;
			worldmap = new char[width * height];

			worldmap[1 + 1*width] = '1';
		}

		~WorldMap() {
			delete[] worldmap;
		}

		bool checkBounds(int x, int y) {
			return ((x < width && x >= 0) &&
					(y < height && y >= 0));
		}

		void moveAround(Player& p1) {
			bool validInput = false;
			bool worked = false;

			while(!worked) {
				cout << "Where to? (north, west, south, east, stay)" << endl;
				getline(cin, p1.response);

				while(!validInput) {
					validInput = (find(compass.begin(), compass.end(), p1.response)) != compass.end();
					if(!validInput) {
						cout << "Wait, where? (north, west, south, east, stay)" << endl;
						getline(cin, p1.response);
					}
				}
			
				position& pos = p1.pos;
				if(!(p1.response).compare("north")) {
					validInput = checkBounds(pos.x, pos.y + 1);
					if(validInput) {
						worldmap[pos.x + pos.y*width] = '0';
						++(pos.y);
						worldmap[pos.x + pos.y*width] = '1';
						break;
					} else {
						cout << "Can't go any further north!" << endl;
					}
				} else if(!(p1.response).compare("south")) {
					validInput = checkBounds(pos.x, pos.y - 1);
					if(validInput) {
						worldmap[pos.x + pos.y*width] = '0';
						--(pos.y);
						worldmap[pos.x + pos.y*width] = '1';
						break;
					} else {
						cout << "Can't go any further south!" << endl;
					}
				} else if(!(p1.response).compare("west")) {
					validInput = checkBounds(pos.x - 1, pos.y);
					if(validInput) {
						worldmap[pos.x + pos.y*width] = '0';
						--(pos.x);
						worldmap[pos.x + pos.y*width] = '1';
						break;
					} else {
						cout << "Can't go any further west!" << endl;
					}
				} else if(!(p1.response).compare("east")) {
					validInput = checkBounds(pos.x + 1, pos.y);
					if(validInput) {
						worldmap[pos.x + pos.y*width] = '0';
						++(pos.x);
						worldmap[pos.x + pos.y*width] = '1';
						break;
					} else {
						cout << "Can't go any further east!" << endl;
					}
				} else {
					cout << "Good idea, let's stay here." << endl;
				}
			}

			cout << "(position: " << p1.pos.x << ", " << p1.pos.y << ")" << endl << endl;
		}

};

#endif