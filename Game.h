#pragma once
#include"Board.h"
#include<fstream>
#include<string>

class Game:private Board
{
	bool gameover;
	bool bulletflag;//This restricts player to shoot another bullet when there is already a bullet on the screen
	bool ebulletflag;//This does the same function as above function
	char movement;//This takes movement input from the user
	int health;//Player health
	int enemyh;//Enemy health
	int speed;//speed of the asteroid
	ifstream ifile;//takes score from the txt file
	ofstream ofile;//prints score on the txt file
	void getposition(int o, char& a, char& b, char& c, char& d);//This is for > icon in the menu
	void Startgame();//This starts the game loop
	void Instruction();//shows instructions for the game
	void scoreboard();//shows scoreboard of previous players
	void getmovement();//This takes movement input from the user
	void Uhealth();//This updates and draws health bar
	Board board;
public:
	Game();
	void menu();
};




