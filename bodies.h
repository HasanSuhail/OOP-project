#pragma once
//This defines different bodies for different objects with their position on x and y plane
class bodies
{
	char main;
	int x;
	int y;
public:
	bodies();
	bodies(int x, int y, char main);
	void setx(int);
	void sety(int);
	void setmain(char);
	int getx();
	int gety();
	char getmain();
};