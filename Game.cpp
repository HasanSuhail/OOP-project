#include "Game.h"
#include<conio.h>

Game::Game()//This is the constructor
{
	 gameover=false;
	 speed = 0;
	 health = 4;
	 enemyh=6;
	 movement = 'w';//assigning a random value
	 bulletflag = 0;
	 ebulletflag = 0;
}

void Game::menu()//This draws the main menu
{
	int o = 0;
	char a, b, c, d,e;
	bool flag = false;
	for (; flag == false;)
	{
		getposition(o,a,b,c,d);

		cout << "\n\n\n";
		cout << "\t\t\t    *      ******    *******   * * *      * * * *    *****    * * *   " << endl;
		cout << "\t\t\t   * *      *           *      *     *    *     *      *      *     * " << endl;
		cout << "\t\t\t  * * *       *         *      * * *      *     *      *      *     * " << endl;
		cout << "\t\t\t *     *   ******       *      *     *    * * * *    *****    * * *   " << endl;
		cout << "\n\n";
		cout << "\t\t\t" << a << " Start Game" << endl;
		cout << "\t\t\t" << b << " Score Board" << endl;
		cout << "\t\t\t" << c << " Instructions" << endl;
		cout << "\t\t\t" << d << " Exit" << endl;
		cout << "\n\n\nuse S and W to move and J to select";
		e =_getch();
		//This takes input draws > respectively
		if ((e == 's' || e == 'E')&&o<3)
		{
			o++;
		}
		else if((e == 'w' || e == 'W') && o > 0)
		{
			o--;
		}
		else if ((e == 'j' || e == 'J')&&o==0)
		{
			system("CLS");
			Startgame();
		}
		else if ((e == 'j' || e == 'J') && o == 1)
		{
			scoreboard();
		}
		else if ((e == 'j' || e == 'J') && o == 2)
		{
			Instruction();
		}
		else if ((e == 'j' || e == 'J') && o == 3)
		{
			flag = true;
		}
		system("CLS");
	}
}

void Game::Startgame()//This is the main game loop
{
	gameover=false;
	score = 0;
	enemyh = 6;
	health = 4;
	Instruction();
	for (; gameover == false;speed++)
	{
			board.drawboard();
			getmovement();
			board.players();
			if (enemyh != 0)
				board.enemies();
			if (speed % 3 == 0)
				board.updateasteroid();
			Uhealth();
			system("cls");
	}
	//This is the game over screen
	cout << "\n\n\t\tGame Over\n";
	string name,n,scores;
	scores = to_string(board.score);
	cout << "Enter your name(only 3 letters):";
	cin >> n;
	for (int i = 0; i < 3; i++)
	{
		name = name + n[i];
	}
	name = name + ":" + scores+"\n";
	
	ofile.open("highscore.txt", ios::app);
	ofile << name;
	ofile.close();
}

void Game::Instruction()//simple instructions screen
{
	system("CLS");
	cout << "INSTRUCTIONS."<<endl<<endl;
	cout << "> Try avoiding your ship from the Asteroids." << endl;
	cout << "> Use 'A' to move left and 'B' to move right." << endl;
	cout << "> Press 'J' to shoot bullet at enemies." << endl;
	cout << "Press any key(except power key) to go back to menu";
	_getch();
	system("CLS");
}

void Game::scoreboard()//score board screen
{
	ifile.open("highscore.txt");
	system("cls");
	string data;
	int i = 0;
	while (!ifile.eof())
	{
		ifile >> data;
		cout << data;
		i++;
	}
	i--;
	system("cls");
	ifile.close();
	cout << "Score Board\n";
	ifile.open("highscore.txt");
	for(int j=0;j<i;j++)
	{
		ifile >> data;
		cout << data<<endl;
	}
	_getch();
	ifile.close();
	system("cls");
}

void Game::getposition(int o,char& a, char& b, char& c, char& d)
{
	if (o == 0)
	{
		a = '>';
	}
	else
	{
		a = ' ';
	}
	if (o == 1)
	{
		b = '>';
	}
	else
	{
		b = ' ';
	}

	if (o == 2)
	{
		c = '>';
	}
	else
	{
		c = ' ';
	}
	if (o == 3)
	{
		d = '>';
	}
	else
	{
		d = ' ';
	}
}

//This takes input from the user and process it
void Game::getmovement()
{
	if (_kbhit())
	{
		movement = _getch();
	}
	if (movement == 'd')
	{
		board.moveright();
		movement = 'w';
	}
	else if (movement == 'a')
	{
		board.moveleft();
		movement = 'w';
	}
	if (movement=='j'&&bulletflag==0)//Drawing player bullet
	{
		board.addbullet();
		movement = 'w';
		bulletflag = 1;
	}
	
	if (bulletflag == 1)
	{
		board.updatebullet();
	}

	if (board.enemy.gety() == board.player.gety()&&ebulletflag==0&&enemyh!=0)//drawing enemy bullet
	{
		board.addebullet();
		ebulletflag = 1;
	}
	if (ebulletflag == 1)
	{
		if (speed % 3 == 0)
		board.updateebullet();
	}

	if (board.bullet.getx() == 1)
	{
		bulletflag = 0;
	}
	if (board.ebullet.getx() == 1)
	{
		ebulletflag = 0;
	}
	//decreases enemy health
	if ((board.enemy.gety() == board.bullet.gety()|| board.enemy.gety()+1 == board.bullet.gety()|| board.enemy.gety()-1 == board.bullet.gety()) && board.enemy.getx()+1 == board.bullet.getx()&&enemyh!=0)
	{
		enemyh--;
	}
}

void Game::Uhealth()//Updates and draws player health
{
	if (board.asteroid.getx() == board.player.getx()&& (board.asteroid.gety() == board.player.gety() || board.asteroid.gety()+1 == board.player.gety() || board.asteroid.gety()-1 == board.player.gety()) )
	{
		if(speed%3==0)
		health--;
	}
	cout << "HP:";
	for (int i = 0; i < health; i++)
	{
		cout << "=";
	}
	cout << endl;
	board.showscore();
	if (health == 0)
	{
		gameover = true;
	}
	cout << enemyh;
}