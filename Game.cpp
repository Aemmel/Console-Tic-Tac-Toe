#include "Game.h"

Game::Game()
{
	for (int i=0; i<9; i++){
		Field temp;
		mField.push_back(temp);
		mField.at(i).fieldFree = true;
		mField.at(i).selected = false;
		mField.at(i).circle = false;
		mField.at(i).cross = false;
	}
	mField.at(0).selected = true;

	mPlayer1.setCharType(CIRCLE);
	mPlayer2.setCharType(CROSS);
	mTurn = 1;
	mTotalTurn = 0;
	mCom = false;
	mKey = 0;
	mPlayer1Won = false;
	mPlayer2Won = false;
	mDifficulty = 0;
}

void Game::draw()
{
	for (int i=0; i != mField.size(); i++){
		//without selection of the Field
		if (mField.at(i).fieldFree && !mField.at(i).selected)
			std::cout << " " <<  FIELD << " ";
		if (mField.at(i).circle && !mField.at(i).selected)
			std::cout << " " << CIRCLE << " ";
		if (mField.at(i).cross && !mField.at(i).selected)
			std::cout << " " << CROSS << " ";
		//with selection of the Field
		if (mField.at(i).fieldFree && mField.at(i).selected)
			std::cout << ">" << FIELD << "<";
		else if (mField.at(i).cross && mField.at(i).selected)
			std::cout << ">" << CROSS << "<";
		else if (mField.at(i).circle && mField.at(i).selected)
			std::cout << ">" << CIRCLE << "<";
		//draw seperation lines
		if (i == 0 || i == 1 || i == 3 || i == 4 || i == 6 || i == 7)
			std::cout << "|";
		if (i == 2 || i == 5)
			std::cout << std::endl << " __|___|__" << std::endl;
	}
}

void Game::selectField(bool* temp)
{
	int selectedField;
	for (int i=0; i != mField.size(); i++){
		if (mField.at(i).selected){
			selectedField = i;
		}
	}
	if (mTurn == 1){
		if (mKey == 'W'){
			mPlayer1.moveSelected(&mField, selectedField, 1);
			return;
		}
		else if (mKey == 'S'){
			mPlayer1.moveSelected(&mField, selectedField, 2);
			return;
		}
		else if (mKey == 'D'){
			mPlayer1.moveSelected(&mField, selectedField, 3);
			return;
		}
		else if (mKey == 'A'){
			mPlayer1.moveSelected(&mField, selectedField, 4);
			return;
		}
		else if (mKey == VK_SPACE){
			if (mField.at(selectedField).fieldFree){
				mPlayer1.setField(&mField, selectedField, mPlayer1.getCharType());
				mTurn = 2;
				*temp = true;
				return;
			}
		}
	}

	if (mTurn == 2){
		if (mKey == VK_UP){
			mPlayer2.moveSelected(&mField, selectedField, 1);
			return;
		}
		else if (mKey == VK_DOWN){
			mPlayer2.moveSelected(&mField, selectedField, 2);
			return;
		}
		else if (mKey == VK_RIGHT){
			mPlayer2.moveSelected(&mField, selectedField, 3);
			return;
		}
		else if (mKey == VK_LEFT){
			mPlayer2.moveSelected(&mField, selectedField, 4);
			return;
		}
		else if (mKey == VK_SPACE){
			if (mField.at(selectedField).fieldFree){
				mPlayer2.setField(&mField, selectedField, mPlayer2.getCharType());
				if (!mCom){
					mTurn = 1;
				}
				*temp = true;
				return;
			}
		}
	}
}

int Game::getKey()
{
	if (GetAsyncKeyState('W'))
		return 'W';
	else if (GetAsyncKeyState('S'))
		return 'S';
	else if (GetAsyncKeyState('A'))
		return 'A';
	else if (GetAsyncKeyState('D'))
		return 'D';
	else if (GetAsyncKeyState(VK_SPACE))
		return VK_SPACE;
	else if (GetAsyncKeyState(VK_UP))
		return VK_UP;
	else if (GetAsyncKeyState(VK_DOWN))
		return VK_DOWN;
	else if (GetAsyncKeyState(VK_RIGHT))
		return VK_RIGHT;
	else if (GetAsyncKeyState(VK_LEFT))
		return VK_LEFT;

	return 0;
}

void Game::gameLoop()
{
	bool temp = false;
	while (!mPlayer1Won && !mPlayer2Won){
		system("cls");
		mKey = getKey();
		selectField(&temp);
		gameRules();
		draw();
		if (temp){
			temp = false;
			continue;//check everything twice, so it knows exactly when someone won
		}
		system("pause>nul");
	}
	//system("cls");
	
	if (mPlayer1Won && !mPlayer2Won){
		std::cout << "\n\n\t\tPLAYER 1 WON! CONGRATULATIONS PLAYER 1!\n\n\n\n";
	}
	else if (mPlayer2Won && !mPlayer1Won){
		if (!mCom){
			std::cout << "\n\n\t\tPLAYER 2 WON! CONGRATULATIONS PLAYER 2!\n\n\n\n";
		}
		else {
			std::cout << "\n\n\t\t\tTHE COMPUTER BEATED YOU!\n\n\n\n";
		}
	}
	else if (mPlayer1Won && mPlayer2Won){
		std::cout << "\n\n\t\t\t\tDRAWN!\n\n\n\n";
	}
}

void Game::gameRules()
{
	if (mTurn == 1){
		std::cout << "Turn: Player 1 (" << mPlayer1.getCharType() << ") (W/A/S/D)\n\n";

		int won = mGame.checkWon(mField);
		if (won == 1){
			mPlayer1Won = true;
			return;
		}
		else if (won == 2){
			mPlayer2Won = true;
			return;
		}
		else if (won == 3){
			mPlayer1Won = true;
			mPlayer2Won = true;
			return;
		}
	}

	else if (mTurn == 2){
		if (!mCom){
			std::cout << "Turn: Player 2 (" << mPlayer2.getCharType() << ") (Arrow keys)\n\n";
		}
		else {
			std::cout << "Turn: Player 1 (" << mPlayer1.getCharType() << ") (W/A/S/D)\n\n";
		}

		int won = mGame.checkWon(mField);
		if (won == 1){
			mPlayer1Won = true;
			return;
		}
		else if (won == 2){
			mPlayer2Won = true;
			return;
		}
		else if (won == 3){
			mPlayer1Won = true;
			mPlayer2Won = true;
			return;
		}

		if (mCom){
			mTotalTurn++;
			if (mDifficulty == 0){
				mComInst.easyDifficulty(&mField);
			}
			else if (mDifficulty == 1){
				mComInst.mediumDifficulty(&mField, mTotalTurn);
			}
			else if (mDifficulty == 2){
				mComInst.hardDifficulty(&mField, mTotalTurn);
			}
			mTurn = 1;
		}
	}
}

void Game::menu()
{
	/* MENU:
	 * 1.Play
	 * 2. Configuration
	 * 3. Quit
	*/

	unsigned choice = 0;
	for (;;){
		system("cls");
		
		std::cout << "\t\t\tWELCOME TO MY TIC TAC TOE\n\n";

		if ((GetAsyncKeyState(VK_UP) || GetAsyncKeyState('W')) && choice > 0){
			choice--;
		}
		if ((GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('S')) && choice < 2){
			choice++;
		}
		if (GetAsyncKeyState(VK_SPACE) || GetAsyncKeyState(VK_RETURN)){
			if (choice == 0){
				gameLoop();
				//reset the game
				for (int i=0; i!=mField.size(); i++){
					mField.at(i).fieldFree = true;
					mField.at(i).selected = false;
					mField.at(i).circle = false;
					mField.at(i).cross = false;
				}
				mField.at(0).selected = true;
				mPlayer1Won = false;
				mPlayer2Won = false;
				mTotalTurn = 0;
				if (mDifficulty == 2 && mCom){
					mTurn = 2;
				}
				else {
					mTurn = 1;
				}

				std::cout << "ENTER or SPACE to play again, any other key to return to menu...";
				system("pause>nul");
				continue;
			}
			if (choice == 1){
				menuConfig();
				choice = 0;
				continue;
			}
			if (choice == 2){
				system("cls");
				std::cout << "\n\n\n\t\t\tTHANK YOU FOR PLAYING!\n\n\t\t\t\t:-)\n\n";
				return;
			}
		}

		switch (choice){
		case 0:
			std::cout << ">Play         <\n";
			std::cout << " Configuration\n";
			std::cout << " Quit\n";
			break;
		case 1:
			std::cout << " Play\n";
			std::cout << ">Configuration<\n";
			std::cout << " Quit\n";
			break;
		case 2:
			std::cout << " Play\n";
			std::cout << " Configuration\n";
			std::cout << ">Quit         <\n";
			break;
		}

		system("pause>nul");
	}
}

void Game::menuConfig()
{
	/* CONFIG:
	 * 1. Multiplayer   (X)
	 * 2. vs. Computer  ( )
	 * 3. Set difficulty
	 * 4. main menu
	*/

	int choice = 0;
	for (;;){
		system("cls");

		if ((GetAsyncKeyState(VK_UP) || GetAsyncKeyState('W')) && choice > 0){
			choice--;
		}
		if ((GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('S')) && choice < 3){
			choice++;
		}
		if (GetAsyncKeyState(VK_SPACE) || GetAsyncKeyState(VK_RETURN)){
			switch (choice){
			case 0: 
				mCom = false;
				break;
			case 1:
				mCom = true;
				break;
			case 2:
				menuConfigSetDiff();
				choice = 3;
				continue;
				break;
			case 3:
				return;
			}
		}

		switch (choice){
		case 0:
			switch (mCom){
			case false:
				std::cout << ">Multiplayer   (X)<\n";
				std::cout << " vs. Computer  ( )\n";
				std::cout << " Set Difficulty\n";
				std::cout << " main menu\n";
				break;
			case true:
				std::cout << ">Multiplayer   ( )<\n";
				std::cout << " vs. Computer  (X)\n";
				std::cout << " Set Difficulty\n";
				std::cout << " main menu\n";
				break;
			}//switch (vsCom)
			break;
		case 1:
			switch (mCom){
			case false:
				std::cout << " Multiplayer   (X)\n";
				std::cout << ">vs. Computer  ( )<\n";
				std::cout << " Set Difficulty\n";
				std::cout << " main menu\n";
				break;
			case true:
				std::cout << " Multiplayer   ( )\n";
				std::cout << ">vs. Computer  (X)<\n";
				std::cout << " Set Difficulty\n";
				std::cout << " main menu\n";
				break;
			}//switch (vsCom)
			break;
		case 2:
			switch (mCom){
			case false:
				std::cout << " Multiplayer   (X)\n";
				std::cout << " vs. Computer  ( )\n";
				std::cout << ">Set Difficulty   <\n";
				std::cout << " main menu\n";
				break;
			case true:
				std::cout << " Multiplayer   ( )\n";
				std::cout << " vs. Computer  (X)\n";
				std::cout << ">Set Difficulty   <\n";
				std::cout << " main menu\n";
				break;
			}//switch (vsCom)
			break;
		case 3:
			switch (mCom){
			case false:
				std::cout << " Multiplayer   (X)\n";
				std::cout << " vs. Computer  ( )\n";
				std::cout << " Set Difficulty\n";
				std::cout << ">main menu        <\n";
				break;
			case true:
				std::cout << " Multiplayer   ( )\n";
				std::cout << " vs. Computer  (X)\n";
				std::cout << " Set Difficulty\n";
				std::cout << ">main menu        <\n";
				break;
			}//switch (vsCom)
		}//switch (choice)

		system("pause>nul");
	}//for (;;)
}

void Game::menuConfigSetDiff()
{
	/*
	 * 1. Easy   ( )
	 * 2. Medium ( )
	 * 3. Hard   ( )
	*/

	int choice  = mDifficulty;
	for (;;){
		system("cls");

		if ((GetAsyncKeyState(VK_UP) || GetAsyncKeyState('W')) && choice > 0){
			choice--;
		}
		if ((GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('S')) && choice < 2){
			choice++;
		}
		if (GetAsyncKeyState(VK_SPACE) || GetAsyncKeyState(VK_RETURN)){
			mDifficulty = choice;
			if (mDifficulty == 2){
				mTurn = 2;
			}
			return;
		}

		switch (choice){
		case 0:
			switch (mDifficulty){
			case 0:
				std::cout << ">Easy   (X)<\n";
				std::cout << " Medium ( )\n";
				std::cout << " Hard   ( )\n";
				break;
			case 1:
				std::cout << ">Easy   ( )<\n";
				std::cout << " Medium (X)\n";
				std::cout << " Hard   ( )\n";
				break;
			case 2:
				std::cout << ">Easy   ( )<\n";
				std::cout << " Medium ( )\n";
				std::cout << " Hard   (X)\n";
				break;
			}//switch (diff)
			break;
		case 1:
			switch (mDifficulty){
			case 0:
				std::cout << " Easy   (X)\n";
				std::cout << ">Medium ( )<\n";
				std::cout << " Hard   ( )\n";
				break;
			case 1:
				std::cout << " Easy   ( )\n";
				std::cout << ">Medium (X)<\n";
				std::cout << " Hard   ( )\n";
				break;
			case 2:
				std::cout << " Easy   ( )\n";
				std::cout << ">Medium ( )<\n";
				std::cout << " Hard   (X)\n";
				break;
			}//switch (diff)
			break;
		case 2:
			switch (mDifficulty){
			case 0:
				std::cout << " Easy   (X)\n";
				std::cout << " Medium ( )\n";
				std::cout << ">Hard   ( )<\n";
				break;
			case 1:
				std::cout << " Easy   ( )\n";
				std::cout << " Medium (X)\n";
				std::cout << ">Hard   ( )<\n";
				break;
			case 2:
				std::cout << " Easy   ( )\n";
				std::cout << " Medium ( )\n";
				std::cout << ">Hard   (X)<\n";
				break;
			}//switch (diff)
			break;
		}//switch (choice)
		system("pause>nul");
	}//for (;;)
}
