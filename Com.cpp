#include "Com.h"

//Computer: CROSS!
//Player: CIRCLE!

Com::Com()
{
	int mWay_1 = 0;
	int mWay_2 = 0;
	int mWay_3 = 0;
}

void Com::easyDifficulty(std::vector<Field>* fields)
{
	bool fieldsTaken = true; //if true, all fields are taken
	for (unsigned i=0; i!=fields->size(); i++){//check if fields are still free
		if (fields->at(i).fieldFree){
			fieldsTaken = false;
		}
	}
	if (fieldsTaken){
		return;
	}

	for (;;){
		int num = (rand() % fields->size());
		if (fields->at(num).fieldFree){
			fields->at(num).fieldFree = false;
			fields->at(num).cross = true;
			return;	
		}
	}
}

void Com::mediumDifficulty(std::vector<Field>* fields, int turn)
{
	bool fieldsTaken = true; //if true, all fields are taken
	for (unsigned i=0; i!=fields->size(); i++){//check if fields are still free
		if (fields->at(i).fieldFree){
			fieldsTaken = false;
		}
	}
	if (fieldsTaken){
		return;
	}

	if (turn == 1){
		for (;;){ //make random first move
			int num = (rand() % fields->size());
			if (num == 0 && fields->at(num).fieldFree){
				fields->at(num).fieldFree = false;
				fields->at(num).cross = true;
				return;	
			}
			else if (num == 2 && fields->at(num).fieldFree){
				fields->at(num).fieldFree = false;
				fields->at(num).cross = true;
				return;
			}
			else if (num == 6 && fields->at(num).fieldFree){
				fields->at(num).fieldFree = false;
				fields->at(num).cross = true;
				return;
			}
			else if (num == 8 && fields->at(num).fieldFree){
				fields->at(num).fieldFree = false;
				fields->at(num).cross = true;
				return;
			}
		}//for (;;)
	}
	else if (turn == 2){
		//check if the player can win, prevent mostly
		int prevOrWin = (rand() % 8);
		if (prevOrWin <= 4){ //prevent
			if (ableToWin(fields, CIRCLE, false, true)){
				return;
			}
		}
		
		for (;;){
			int num = (rand() % fields->size());
			if (fields->at(num).fieldFree){
				fields->at(num).fieldFree = false;
				fields->at(num).cross = true;
				return;	
			}
		}
	}
	else if (turn == 3){
		//check if the player can win, prevent mostly
		int prevOrWin = (rand() % 10);
		if (prevOrWin <= 5){ //prevent
			if (ableToWin(fields, CIRCLE, false, true)){
				return;
			}
		}
		else {
			if (ableToWin(fields, CROSS, true, false)){
				return;
			}
		}
		for (;;){
			int num = (rand() % fields->size());
			if (fields->at(num).fieldFree){
				fields->at(num).fieldFree = false;
				fields->at(num).cross = true;
				return;	
			}
		}
	}
	else if (turn >3){
		//check if the player can win, prevent mostly
		int prevOrWin = (rand() % 13);
		if (prevOrWin <= 7){ //prevent
			if (ableToWin(fields, CIRCLE, false, true)){
				return;
			}
		}
		else {
			if (ableToWin(fields, CROSS, true, false)){
				return;
			}
		}
		for (;;){
			int num = (rand() % fields->size());
			if (fields->at(num).fieldFree){
				fields->at(num).fieldFree = false;
				fields->at(num).cross = true;
				return;	
			}
		}
	}
}

void Com::hardDifficulty(std::vector<Field>* fields, int turn)
{
	bool fieldsTaken = true; //if true, all fields are taken
	for (unsigned i=0; i!=fields->size(); i++){//check if fields are still free
		if (fields->at(i).fieldFree){
			fieldsTaken = false;
		}
	}
	if (fieldsTaken){
		return;
	}

	if (turn == 1){
		fields->at(0).fieldFree = false;
		fields->at(0).cross = true;
		return;
	}
	else if (turn == 2){
		if (fields->at(8).fieldFree){
			fields->at(8).fieldFree = false;
			fields->at(8).cross = true;
			mWay_1 = 1;//put in corner bottom-right
			return;
		}
		else {
			fields->at(6).fieldFree = false;
			fields->at(6).cross = true;
			mWay_1 = 2;//put in corner bottom-left
			return;
		}
	}
	else if (turn == 3){
		if (mWay_1 == 1){
			//corners free?
			if (fields->at(4).fieldFree){
				fields->at(4).fieldFree = false;
				fields->at(4).cross = true;
				return; //Game won
			}
			else if (fields->at(2).fieldFree){
				fields->at(2).fieldFree = false;
				fields->at(2).cross = true;
				mWay_2 = 1;//put in corner up-right
				return;
			}
			else if (fields->at(6).fieldFree){
				fields->at(6).fieldFree = false;
				fields->at(6).cross = true;
				mWay_2 = 2;//put in corner bottom left
				return;
			}
		}
		else if (mWay_1 == 2){
			if (fields->at(3).fieldFree){
				fields->at(3).fieldFree = false;
				fields->at(3).cross = true;
				return; //Game won
			}
			else {
				fields->at(2).fieldFree = false;
				fields->at(2).cross = true;
			}
		}
	}
	else if (turn == 4){
		if (mWay_1 == 1){
			if (mWay_2 == 1){
				if (fields->at(1).fieldFree){
					fields->at(1).fieldFree = false;
					fields->at(1).cross = true;
					return; //Game won
				}
				else if (fields->at(5).fieldFree){
					fields->at(5).fieldFree = false;
					fields->at(5).cross = true;
					return; //Game won
				}
			}
			else if (mWay_2 == 2){
				if (fields->at(3).fieldFree){
					fields->at(3).fieldFree = false;
					fields->at(3).cross = true;
					return; //Game won
				}
				else if (fields->at(7).fieldFree){
					fields->at(7).fieldFree = false;
					fields->at(7).cross = true;
					return; //Game won
				}
			}
		}
		else if (mWay_1 == 2){
			if (fields->at(1).fieldFree){
				fields->at(1).fieldFree = false;
				fields->at(1).cross = true; //Game won
			}
			else {
				fields->at(4).fieldFree = false;
				fields->at(4).cross = true; //Game won
			}
		}
	}
}

bool Com::ableToWin(std::vector<Field> *vec, const char ch, bool win, bool prevent)
{
	if (ch == CROSS){
		//horizontal
		if ((vec->at(0).fieldFree || vec->at(0).cross) && (vec->at(1).fieldFree || vec->at(1).cross) && (vec->at(2).fieldFree || vec->at(2).cross)){
			int i = 0;//used to ckeck if 2 fields are taken and one free, only valid in respective if-statement
			if (vec->at(0).cross) i++;
			if (vec->at(1).cross) i++;
			if (vec->at(0).cross) i++;
			if (i == 2){
				if (win){
					for (int it=0; it!=2 ;it++){
						if (vec->at(it).fieldFree){
							vec->at(it).fieldFree = false;
							vec->at(it).cross = true;
						}
					}						
				}
				return true;
			}
		}
		else if ((vec->at(3).fieldFree || vec->at(3).cross) && (vec->at(4).fieldFree || vec->at(4).cross) && (vec->at(5).fieldFree || vec->at(5).cross)){
			int i=0;
			if (vec->at(3).cross) i++;
			if (vec->at(4).cross) i++;
			if (vec->at(5).cross) i++;
			if (i == 2){
				if (win){
					for (int it=3; it!=5 ;it++){
						if (vec->at(it).fieldFree){
							vec->at(it).fieldFree = false;
							vec->at(it).cross = true;
						}
					}
				return true;
				}
			}
		}
		else if ((vec->at(6).fieldFree || vec->at(6).cross) && (vec->at(7).fieldFree || vec->at(7).cross) && (vec->at(8).fieldFree || vec->at(8).cross)){
			int i=0;
			if (vec->at(6).cross) i++;
			if (vec->at(7).cross) i++;
			if (vec->at(8).cross) i++;
			if (i == 2){
				if (win){
					for (int it=6; it!=8 ;it++){
						if (vec->at(it).fieldFree){
							vec->at(it).fieldFree = false;
							vec->at(it).cross = true;
						}
					}
				return true;
				}
			}
		}
		//vertical
		else if ((vec->at(0).fieldFree || vec->at(0).cross) && (vec->at(3).fieldFree || vec->at(3).cross) && (vec->at(6).fieldFree || vec->at(6).cross)){
			int i=0;
			if (vec->at(0).cross) i++;
			if (vec->at(3).cross) i++;
			if (vec->at(6).cross) i++;
			if (i == 2){
				if (win){
					if (vec->at(0).fieldFree){
						vec->at(0).fieldFree = false;
						vec->at(0).cross = true;
					}
					else if (vec->at(3).fieldFree){
						vec->at(3).fieldFree = false;
						vec->at(3).cross = true;
					}
					else if (vec->at(6).fieldFree){
						vec->at(6).fieldFree = false;
						vec->at(6).cross = true;
					}
				}
				return true;
			}
		}
		else if ((vec->at(1).fieldFree || vec->at(1).cross) && (vec->at(4).fieldFree || vec->at(4).cross) && (vec->at(7).fieldFree || vec->at(7).cross)){
			int i=0;
			if (vec->at(1).cross) i++;
			if (vec->at(4).cross) i++;
			if (vec->at(7).cross) i++;
			if (i == 2){
				if (win){
					if (vec->at(1).fieldFree){
						vec->at(1).fieldFree = false;
						vec->at(1).cross = true;
					}
					else if (vec->at(4).fieldFree){
						vec->at(4).fieldFree = false;
						vec->at(4).cross = true;
					}
					else if (vec->at(7).fieldFree){
						vec->at(7).fieldFree = false;
						vec->at(7).cross = true;
					}
					return true;
				}
			}
		}
		else if ((vec->at(2).fieldFree || vec->at(2).cross) && (vec->at(5).fieldFree || vec->at(5).cross) && (vec->at(8).fieldFree || vec->at(8).cross)){
			int i=0;
			if (vec->at(2).cross) i++;
			if (vec->at(5).cross) i++;
			if (vec->at(8).cross) i++;
			if (i == 2){
				if (win){
					if (vec->at(2).fieldFree){
						vec->at(2).fieldFree = false;
						vec->at(2).cross = true;
					}
					else if (vec->at(5).fieldFree){
						vec->at(5).fieldFree = false;
						vec->at(5).cross = true;
					}
					else if (vec->at(8).fieldFree){
						vec->at(8).fieldFree = false;
						vec->at(8).cross = true;
					}
					return true;
				}
			}
		}
		//diagonal
		else if ((vec->at(0).fieldFree || vec->at(0).cross) && (vec->at(4).fieldFree || vec->at(4).cross) && (vec->at(8).fieldFree || vec->at(8).cross)){
			int i=0;
			if (vec->at(0).cross) i++;
			if (vec->at(4).cross) i++;
			if (vec->at(8).cross) i++;
			if (i == 2){
				if (win){
					if (vec->at(0).fieldFree){
						vec->at(0).fieldFree = false;
						vec->at(0).cross = true;
					}
					else if (vec->at(4).fieldFree){
						vec->at(4).fieldFree = false;
						vec->at(4).cross = true;
					}
					else if (vec->at(8).fieldFree){
						vec->at(8).fieldFree = false;
						vec->at(8).cross = true;
					}
					return true;
				}
			}
		}
		else if ((vec->at(2).fieldFree || vec->at(2).cross) && (vec->at(4).fieldFree || vec->at(4).cross) && (vec->at(6).fieldFree || vec->at(6).cross)){
			int i=0;
			if (vec->at(2).cross) i++;
			if (vec->at(4).cross) i++;
			if (vec->at(6).cross) i++;
			if (i == 2){
				if (win){
					if (vec->at(2).fieldFree){
						vec->at(2).fieldFree = false;
						vec->at(2).cross = true;
					}
					else if (vec->at(4).fieldFree){
						vec->at(4).fieldFree = false;
						vec->at(4).cross = true;
					}
					else if (vec->at(6).fieldFree){
						vec->at(6).fieldFree = false;
						vec->at(6).cross = true;
					}
					return true;
				}
			}
		}
	}
	
	//don't win here!
	else if (ch == CIRCLE){
		if ((vec->at(0).fieldFree || vec->at(0).circle) && (vec->at(1).fieldFree || vec->at(1).circle) && (vec->at(2).fieldFree || vec->at(2).circle)){
			int i = 0;//used to ckeck if 2 fields are taken and one free, only valid in respective if-statement
			if (vec->at(0).circle) i++;
			if (vec->at(1).circle) i++;
			if (vec->at(0).circle) i++;
			if (i == 2){
				if (prevent){
					for (int it=0; it!=2 ;it++){
						if (vec->at(it).fieldFree){
							vec->at(it).fieldFree = false;
							vec->at(it).cross = true;
						}
					}			
					return true;
				}
			}
		}
		else if ((vec->at(3).fieldFree || vec->at(3).circle) && (vec->at(4).fieldFree || vec->at(4).circle) && (vec->at(5).fieldFree || vec->at(5).circle)){
			int i=0;
			if (vec->at(3).circle) i++;
			if (vec->at(4).circle) i++;
			if (vec->at(5).circle) i++;
			if (i == 2){
				if (prevent){
					for (int it=3; it!=5 ;it++){
						if (vec->at(it).fieldFree){
							vec->at(it).fieldFree = false;
							vec->at(it).cross = true;
						}
						return true;
					}
				}
			}
		}
		else if ((vec->at(6).fieldFree || vec->at(6).circle) && (vec->at(7).fieldFree || vec->at(7).circle) && (vec->at(8).fieldFree || vec->at(8).circle)){
			int i=0;
			if (vec->at(6).circle) i++;
			if (vec->at(7).circle) i++;
			if (vec->at(8).circle) i++;
			if (i == 2){
				if (prevent){
					for (int it=6; it!=8 ;it++){
						if (vec->at(it).fieldFree){
							vec->at(it).fieldFree = false;
							vec->at(it).cross = true;
						}
						return true;
					}
				}
			}
		}
		//vertical
		else if ((vec->at(0).fieldFree || vec->at(0).circle) && (vec->at(3).fieldFree || vec->at(3).circle) && (vec->at(6).fieldFree || vec->at(6).circle)){
			int i=0;
			if (vec->at(0).circle) i++;
			if (vec->at(3).circle) i++;
			if (vec->at(6).circle) i++;
			if (i == 2){
				if (prevent){
					if (vec->at(0).fieldFree){
						vec->at(0).fieldFree = false;
						vec->at(0).cross = true;
					}
					else if (vec->at(3).fieldFree){
						vec->at(3).fieldFree = false;
						vec->at(3).cross = true;
					}
					else if (vec->at(6).fieldFree){
						vec->at(6).fieldFree = false;
						vec->at(6).cross = true;
					}
					return true;
				}
			}
		}
		else if ((vec->at(1).fieldFree || vec->at(1).circle) && (vec->at(4).fieldFree || vec->at(4).circle) && (vec->at(7).fieldFree || vec->at(7).circle)){
			int i=0;
			if (vec->at(1).circle) i++;
			if (vec->at(4).circle) i++;
			if (vec->at(7).circle) i++;
			if (i == 2){
				if (prevent){
					if (vec->at(1).fieldFree){
						vec->at(1).fieldFree = false;
						vec->at(1).cross = true;
					}
					else if (vec->at(4).fieldFree){
						vec->at(4).fieldFree = false;
						vec->at(4).cross = true;
					}
					else if (vec->at(7).fieldFree){
						vec->at(7).fieldFree = false;
						vec->at(7).cross = true;
					}
					return true;
				}
			}
		}
		else if ((vec->at(2).fieldFree || vec->at(2).circle) && (vec->at(5).fieldFree || vec->at(5).circle) && (vec->at(8).fieldFree || vec->at(8).circle)){
			int i=0;
			if (vec->at(2).circle) i++;
			if (vec->at(5).circle) i++;
			if (vec->at(8).circle) i++;
			if (i == 2){
				if (prevent){
					if (vec->at(2).fieldFree){
						vec->at(2).fieldFree = false;
						vec->at(2).cross = true;
					}
					else if (vec->at(5).fieldFree){
						vec->at(5).fieldFree = false;
						vec->at(5).cross = true;
					}
					else if (vec->at(8).fieldFree){
						vec->at(8).fieldFree = false;
						vec->at(8).cross = true;
					}
					return true;
				}
			}
		}
		//diagonal
		else if ((vec->at(0).fieldFree || vec->at(0).circle) && (vec->at(4).fieldFree || vec->at(4).circle) && (vec->at(8).fieldFree || vec->at(8).circle)){
			int i=0;
			if (vec->at(0).circle) i++;
			if (vec->at(4).circle) i++;
			if (vec->at(8).circle) i++;
			if (i == 2){
				if (prevent){
					if (vec->at(0).fieldFree){
						vec->at(0).fieldFree = false;
						vec->at(0).cross = true;
					}
					else if (vec->at(4).fieldFree){
						vec->at(4).fieldFree = false;
						vec->at(4).cross = true;
					}
					else if (vec->at(8).fieldFree){
						vec->at(8).fieldFree = false;
						vec->at(8).cross = true;
					}
					return true;
				}
			}
		}
		else if ((vec->at(2).fieldFree || vec->at(2).circle) && (vec->at(4).fieldFree || vec->at(4).circle) && (vec->at(6).fieldFree || vec->at(6).circle)){
			int i=0;
			if (vec->at(2).circle) i++;
			if (vec->at(4).circle) i++;
			if (vec->at(6).circle) i++;
			if (i == 2){
				if (prevent){
					if (vec->at(2).fieldFree){
						vec->at(2).fieldFree = false;
						vec->at(2).cross = true;
					}
					else if (vec->at(4).fieldFree){
						vec->at(4).fieldFree = false;
						vec->at(4).cross = true;
					}
					else if (vec->at(6).fieldFree){
						vec->at(6).fieldFree = false;
						vec->at(6).cross = true;
					}
					return true;
				}
			}
		}
	}

	return false;
}
