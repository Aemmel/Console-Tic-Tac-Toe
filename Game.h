#ifndef GAME_H
#define GAME_H

#include "Engine.h"
#include "Com.h"

class Game
{
public:
	Game();
	void draw();
	void selectField(bool*);
	int getKey();
	void gameLoop();
	void gameRules();
	void menu();

private:
	Engine mPlayer1;
	Engine mPlayer2;
	Engine mGame;
	Com mComInst; //mComInstance
	bool mCom;
	int mTurn; //Player 1: value 1; Player 2: value 2
	int mTotalTurn;
	int mKey;
	bool mPlayer1Won;
	bool mPlayer2Won;

	int mDifficulty;
	//functions for the menu
	void menuConfig();
	void menuConfigSetDiff(); //set difficulty

	std::vector<Field> mField;
};

#endif //GAME_H
