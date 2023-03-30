#include "Game.h"

game::game(const int& height, const int& width, const int& top, const int& left, const vector<vector<game::cell>>& vect)
	: mSideA(height)
	, mSideB(width)
	//[top][left] is the beginning of vect inside the mDish
{}


game::game(const int& sideA, const int& sideB, const float& Chance)
	: mSideA(sideA)
	, mSideB(sideB)
	, mChance(Chance)
{
}


game::game(const int& sideA, const float& Chance)
	: mSideA(sideA)
	, mSideB(sideA)
	, mChance(Chance)
{
}

game::game(const int& sideA,const int& sideB)
	:mSideA(sideA)
	, mSideB(sideB)
{
}

game::game(const int& sideA) 
	:mSideA(sideA)
	,mSideB(sideA)
{
}