#include "bodies.h"

bodies::bodies()//Default constructor for bodies
{
	x = 0;
	y = 0;
	main = 'o';
}

bodies::bodies(int x , int y , char main )//parameterized constructor for bodies
{
	this->x = x;//x coordinate for the body
	this->y = y;//y coordinate for the body
	this->main = main;//main body char value
}

//setters for the chars
void bodies::setmain(char x)
{
	main = x;
}
void bodies::setx(int x)
{
	this->x = x;
}
void bodies::sety(int y)
{
	this->y = y;
}


//Getters for the chars
int bodies::getx()
{
	return x;
}
int bodies::gety()
{
	return y;
}
char bodies::getmain()
{
	return main;
}
