#pragma once
#include<iostream>
#include"bodies.h"
using namespace std;

//This is the main class where the board is constructed and different bodies are added updated on in it
class Board
{
public:
	int row;//Number of rows of the board
	int column;//Number of columns for the board
	int score;//Score count
	int f;//This integer is used for the movement of the enemy ship

	// This is the main board
	char** board;

	//Bodies for different objects on the board
	bodies player;
	bodies enemy;
	bodies asteroid;
	bodies bullet;//player bullet
	bodies ebullet;//enemy bullet
	bool el;//enemy location

	void initialize();//This is the initializer of the board

	//This function takes the x and y coordinates from the bodies and updates the board
	//and remove object from the previous location on the board
	void update(int, int, char**, char);

	
	void addplayer();//This function is used in the constructor to add the player ship and x and y coordinates

	void addenemy();//This function is used in the constructor to add the enemy ship and x and y coordinates

	void addasteroid();//This function is used in the constructor to add the first asteroid with x and y coordinates

	void addbullet();//This function is used when player presses j to shoot

	void addebullet();//This is used to add enemy bullet

	void showscore();//This function calculates and show the score of the enemy

	void updatebullet();//This updates the player bullet location

	void updateebullet();//This updates the enemy bullet location

	void updateasteroid();//This updates the asteroid location

	Board();
	void drawboard();//This prints the updated board on the screen
	void moveright();//player moves right
	void moveleft();//player moves left
	void players();//updates player even if no moves are made in each iteration
	void enemies();//updates enemy even if no moves are made in each iteration
};

