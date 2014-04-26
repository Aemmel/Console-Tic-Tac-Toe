#ifndef COM_H
#define COM_H

#include "Engine.h"

#pragma comment (lib, "winmm.lib")

class Com
{
public:
	Com();

	void easyDifficulty(std::vector<Field>*);
	void mediumDifficulty(std::vector<Field>*, int);
	void hardDifficulty(std::vector<Field>*, int);
	bool ableToWin(std::vector<Field>*, const char, bool, bool);

private:
	int mWay_1;
	int mWay_2;

};

#endif
