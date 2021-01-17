#include "Board.h"

Board::Board()//constructor
{
	row = 15;
	column = 25;
	board = new char* [row];
	score = 0;
	el = true;
	f = 1;
	for (int i = 0; i < row; i++)//initializing the 2d array of board size
	{
		board[i] = new char[column];
	}
	initialize();
	addplayer();
	addenemy();
	addasteroid();
}

void Board::initialize()//this adds the chars of borders on the board
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (i == 0 || i == row - 1 || j == 0 || j == column - 1)
			{
				board[i][j] = 'o';
			}
			else
			{
				board[i][j] = ' ';
			}
		}
	}
}

void Board::drawboard()//This simply draws the board
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			cout << board[i][j];
		}
		cout << endl;
	}
}

void Board::players()//This just updates the player
{
	update(player.getx() - 1, player.gety(), board, player.getmain());//filling board with player ship
	update(player.getx(), player.gety(), board, 'H');//ship part
	update(player.getx(), player.gety() + 1, board, '>');//ship part
	update(player.getx(), player.gety() - 1, board, '<');//ship part
}

void Board::addplayer()//This constructs the player first time
{
	player.setx(row - 2);
	player.sety(2);
	player.setmain('A');
	update(player.getx() - 1, player.gety(), board, player.getmain());//filling board with player ship
	update(player.getx(), player.gety(), board, 'H');//ship part
	update(player.getx(), player.gety() + 1, board, '>');//ship part
	update(player.getx(), player.gety() - 1, board, '<');//ship part
}

void Board::addenemy()//This constructs the enemy first time
{
	enemy.setx(1);
	enemy.sety(6);
	enemy.setmain('Y');
	update(enemy.getx() + 1, enemy.gety(), board, enemy.getmain());//filling board with player ship
	update(enemy.getx(), enemy.gety(), board, 'O');//ship part
	update(enemy.getx(), enemy.gety() + 1, board, ')');//ship part
	update(enemy.getx(), enemy.gety() - 1, board, '(');//ship part
}

void Board::enemies()//This updates enemy in each iteration
{
	//This if else statement moves the enemy from side to side
	if (enemy.gety() == column - 3)
	{
		f = -1;
	}
	else if (enemy.gety() == 2)
	{
		f = 1;
	}
	enemy.sety(enemy.gety() + f);
	update(enemy.getx() + 1, enemy.gety(), board, enemy.getmain());//filling board with player ship
	update(enemy.getx(), enemy.gety(), board, 'O');//ship part
	update(enemy.getx(), enemy.gety() + 1, board, ')');//ship part
	update(enemy.getx(), enemy.gety() - 1, board, '(');//ship part
}

void Board::moveright()//This just increases the y coordinate of player by 1
{
	if (player.gety() < column - 3)
	{
		player.sety(player.gety() + 1);
		update(player.getx() - 1, player.gety(), board, player.getmain());//filling board with player ship
		update(player.getx(), player.gety(), board, 'H');//ship part
		update(player.getx(), player.gety() + 1, board, '>');//ship part
		update(player.getx(), player.gety() - 1, board, '<');//ship part
	}
}

void Board::moveleft()//This decreases the y coordinate of player by 1
{
	if (player.gety() > 2)
	{
		player.sety(player.gety() - 1);
		update(player.getx() - 1, player.gety(), board, player.getmain());//filling board with player ship
		update(player.getx(), player.gety(), board, 'H');//ship part
		update(player.getx(), player.gety() + 1, board, '>');//ship part
		update(player.getx(), player.gety() - 1, board, '<');//ship part
	}
}

void Board::addasteroid()//Construct the asteroid
{
	asteroid.setmain('*');
	asteroid.setx(1);
	asteroid.sety(rand() % column );//randomly selecting the column
	update(asteroid.getx(), asteroid.gety(), board, asteroid.getmain());
}

void Board::updateasteroid()//Updates the asteroid
{
	if (asteroid.getx() < row - 2)//This runs to move asteroid across the screen
	{
		asteroid.setx(asteroid.getx() + 1);
		update(asteroid.getx(), asteroid.gety(), board, '*');
	}
	else//This runs to reset and update the asteroid location when it has completed its path
	{
		int x=0;
		for (bool f = 0; f == 0;)//This is just check to select the new y location within the board
		{
			x=(rand() % column) + 1;
			if (x > 1 && x < 24)
				f = 1;
		}
		asteroid.sety(x);
		asteroid.setx(1);
		update(asteroid.getx(), asteroid.gety(), board, '*');
		score++;
	}
}

void Board::addbullet()//Contructs the bullet
{
	bullet.setmain('^');
	bullet.setx(player.getx() - 2);
	bullet.sety(player.gety());
	update(bullet.getx(), bullet.gety(), board, bullet.getmain());
}

void Board::updatebullet()//Update player bullet by decreasing x value
{
	bullet.setx(bullet.getx() - 1);
	update(bullet.getx(), bullet.gety(), board, bullet.getmain());
	if (bullet.getx() == 1)
	{
		update(bullet.getx(), bullet.gety(), board, ' ');
	}
}

void Board::addebullet()//Constructs enemy bullet
{
	ebullet.setmain('T');
	ebullet.setx(enemy.getx() + 2);
	ebullet.sety(enemy.gety());
	update(ebullet.getx(), ebullet.gety(), board, ebullet.getmain());
}

void Board::updateebullet()//Update the enemy bullet location
{
	ebullet.setx(ebullet.getx() + 1);
	update(ebullet.getx(), ebullet.gety(), board, ebullet.getmain());
	if (ebullet.getx() == row-2)
	{
		update(ebullet.getx(), ebullet.gety(), board, ' ');
		ebullet.setx(0);
		ebullet.sety(0);
	}
}

void Board::update(int x, int y, char** board, char p)//This function updates the entire board
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (board[i][j] == p)
			{
				board[i][j] = ' ';
			}
		}
	}
	board[x][y] = p;
}

void Board::showscore()//This shows score
{
	cout << "Score:" << score<<endl;
}