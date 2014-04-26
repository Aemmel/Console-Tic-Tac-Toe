#include "Engine.h"

/*
 *@param 1: vector of the field
 *@param 2: which Field
 *@param 3: CROSS or CIRCLE
*/
bool Engine::setField(std::vector<Field> *field, int pos, const char charType)
{
	if (pos > 9){
		std::cout << "Error: invalid position number (1-9)\n";
		return false;
	}
	if (!field->at(pos).fieldFree){
		return false;
	}

	switch(charType){
	case CROSS:{
		field->at(pos).fieldFree = false;
		field->at(pos).cross = true;
		return true;
		}
	case CIRCLE:{
		field->at(pos).fieldFree = false;
		field->at(pos).circle = true;
		return true;
		}
	default:
		std::cout << "Error: invalid char type (CROSS or CIRCLE)\n";
	}
	
	return false;
}

/*
 * return values:
 * circle won: return 1
 * cross won: return 2
 * drawn: return 3
 * no one won: return 0
*/
int Engine::checkWon(std::vector<Field> field)
{
	/*
	 * possibilitys for winning:
	 * horizontal:
	 * 0, 1, 2
	 * 3, 4, 5
	 * 6, 7, 8
	 * vertical:
	 * 0, 3, 6
	 * 1, 4, 7
	 * 2, 5, 8
	 * diagonal:
	 * 0, 4, 8
	 * 2, 4, 6
	*/
	
	bool fieldsTaken = true; //if true, all fields are taken
	for (unsigned i=0; i!=field.size(); i++){//check if fields are still free
		if (field.at(i).fieldFree){
			fieldsTaken = false;
		}
	}
	if (fieldsTaken){
		return 3;
	}

	//horizontal circle
	if (field.at(0).circle && field.at(1).circle && field.at(2).circle){
		return 1;
	}
	else if (field.at(3).circle && field.at(4).circle && field.at(5).circle){
		return 1;
	}
	else if (field.at(6).circle && field.at(7).circle && field.at(8).circle){
		return 1;
	}
	//veritcal circle
	else if (field.at(0).circle && field.at(3).circle && field.at(6).circle){
		return 1;
	}
	else if (field.at(1).circle && field.at(4).circle && field.at(7).circle){
		return 1;
	}
	else if (field.at(2).circle && field.at(5).circle && field.at(8).circle){
		return 1;
	}
	//diagonal circle
	else if (field.at(0).circle && field.at(4).circle && field.at(8).circle){
		return 1;
	}
	else if (field.at(2).circle && field.at(4).circle && field.at(6).circle){
		return 1;
	}

	//horizontal cross
	else if (field.at(0).cross && field.at(1).cross && field.at(2).cross){
		return 2;
	}
	else if (field.at(3).cross && field.at(4).cross && field.at(5).cross){
		return 2;
	}
	else if (field.at(6).cross && field.at(7).cross && field.at(8).cross){
		return 2;
	}
	//veritcal cross
	else if (field.at(0).cross && field.at(3).cross && field.at(6).cross){
		return 2;
	}
	else if (field.at(1).cross && field.at(4).cross && field.at(7).cross){
		return 2;
	}
	else if (field.at(2).cross && field.at(5).cross && field.at(8).cross){
		return 2;
	}
	//diagonal cross
	else if (field.at(0).cross && field.at(4).cross && field.at(8).cross){
		return 2;
	}
	else if (field.at(2).cross && field.at(4).cross && field.at(6).cross){
		return 2;
	}

	return 0;
}

void Engine::setCharType(const char ch)
{
	charType = ch;
}

char Engine::getCharType()
{
	return charType;
}

/*
 *@param 3: direction
 *	1: up
 *	2: down
 *	3: right
 *	4: left
*/
void Engine::moveSelected(std::vector<Field> *vec, int pos, int dir)
{
	if (dir == 1){
		//middle line
		if (pos == 3){
			vec->at(pos).selected = false;
			vec->at(0).selected = true;
		}
		else if (pos == 4){
			vec->at(pos).selected = false;
			vec->at(1).selected = true;
		}
		else if (pos == 5){
			vec->at(pos).selected = false;
			vec->at(2).selected = true;
		}
		//bottom line
		else if (pos == 6){
			vec->at(pos).selected = false;
			vec->at(3).selected = true;
		}
		else if (pos == 7){
			vec->at(pos).selected = false;
			vec->at(4).selected = true;
		}
		else if (pos == 8){
			vec->at(pos).selected = false;
			vec->at(5).selected = true; 
		}
	}

	else if (dir == 2){
		//top line
		if (pos == 0){
			vec->at(pos).selected = false;
			vec->at(3).selected = true;
		}
		else if (pos == 1){
			vec->at(pos).selected = false;
			vec->at(4).selected = true;
		}
		else if (pos == 2){
			vec->at(pos).selected = false;
			vec->at(5).selected = true;
		}
		//middle line
		else if (pos == 3){
			vec->at(pos).selected = false;
			vec->at(6).selected = true;
		}
		else if (pos == 4){
			vec->at(pos).selected = false;
			vec->at(7).selected = true;
		}
		else if (pos == 5){
			vec->at(pos).selected = false;
			vec->at(8).selected = true;
		}
	}

	else if (dir == 3){
		//left line
		if (pos == 0){
			vec->at(pos).selected = false;
			vec->at(1).selected = true;
		}
		else if (pos == 3){
			vec->at(pos).selected = false;
			vec->at(4).selected = true;
		}
		else if (pos == 6){
			vec->at(pos).selected = false;
			vec->at(7).selected = true;
		}
		//middle line
		else if (pos == 1){
			vec->at(pos).selected = false;
			vec->at(2).selected = true;
		}
		else if (pos == 4){
			vec->at(pos).selected = false;
			vec->at(5).selected = true;
		}
		else if (pos == 7){
			vec->at(pos).selected = false;
			vec->at(8).selected = true;
		}
	}

	else if (dir == 4){
		//middle line
		if (pos == 1){
			vec->at(pos).selected = false;
			vec->at(0).selected = true;
		}
		else if (pos == 4){
			vec->at(pos).selected = false;
			vec->at(3).selected = true;
		}
		else if (pos == 7){
			vec->at(pos).selected = false;
			vec->at(6).selected = true;
		}
		//right line
		else if (pos == 2){
			vec->at(pos).selected = false;
			vec->at(1).selected = true;
		}
		else if (pos == 5){
			vec->at(pos).selected = false;
			vec->at(4).selected = true;
		}
		else if (pos == 8){
			vec->at(pos).selected = false;
			vec->at(7).selected = true;
		}
	}
}
