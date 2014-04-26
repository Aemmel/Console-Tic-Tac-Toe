#ifndef ENGINE_H
#define ENGINE_H

#include <vector>
#include <iostream>
#include <Windows.h>

/*
 * create: std::vector<Field> field for the field
 * field index:
 * 0 | 1 | 2
 * 3 | 4 | 5
 * 6 | 7 | 8
*/
struct Field{
	bool fieldFree;
	bool selected;
	bool cross;
	bool circle;
};

const char FIELD = ' ';
const char CROSS = 'X';
const char CIRCLE = 'O';

class Engine
{
public:
	bool setField(std::vector<Field> *, int, const char);
	int checkWon(std::vector<Field>);
	void moveSelected(std::vector<Field> *, int, int);

	void setCharType(const char);
	char getCharType();

private:
	char charType;

};

#endif //ENGINE_H
