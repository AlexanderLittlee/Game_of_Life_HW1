#include "Game.h"
#include <random>
//----------------------------------------------------------------------------------------------------------------------
//METHODS
 

//game	

void game::defDish() 
{
	int percent = round(mChance * 100);
	for (size_t i = 0; i < mSideA; ++i)
	{
		for (size_t j = 0; j < mSideB; ++j)
		{
			if (rand() % 100<percent)
				mDish[i][j] = cell(true);
			else
				mDish[i][j] = cell(false);
		}
	}
}

void game::Step() 
{
	for (size_t i = 0; i < mSideA; ++i)
	{
		for (size_t j = 0; j < mSideB; ++j)
		{
			if ((mDish[i][j].getNeighbours() != 2 || mDish[i][j].getNeighbours() != 3) && !mDish[i][j].isAlive())
				mDish[i][j].makeaVitalChange();
		}
	}

}

bool game::anyAlive() 
{
	for (size_t i = 0; i < mSideA; ++i)
	{
		for (size_t j = 0; j < mSideB; ++j)
		{
			if (mDish[i][j].isAlive())
				return true;
		}
	}
	return false;
}



//cell


bool game::cell::isAlive() 
{
	return mAlive;
}

void game::cell::makeaVitalChange() 
{
	this->mAlive = false;
}

int game::cell::getNeighbours() 
{

}

//----------------------------------------------------------------------------------------------------------------------
//CONSTRUCTORS


//cell
game::cell::cell(const bool& alive) 
	: mAlive(alive)
{}



//game
game::game(const int& height, const int& width, const int& top, const int& left, const vector<vector<game::cell>>& vect)
	: mSideA(height)
	, mSideB(width)
	, mDish(height, vector<cell>(width))
	//[top][left] is the beginning of vect inside the mDish
{
}


game::game(const int& sideA, const int& sideB, const float& Chance)
	: mSideA(sideA)
	, mSideB(sideB)
	, mChance(Chance)
	, mDish(sideA, vector<cell>(sideB))
{
}


game::game(const int& sideA, const float& Chance)
	: mSideA(sideA)
	, mSideB(sideA)
	, mChance(Chance)
	, mDish(sideA, vector<cell>(sideA))
{
}

game::game(const int& sideA,const int& sideB)
	: mSideA(sideA)
	, mSideB(sideB)
	, mDish(sideA, vector<cell>(sideB))
{
}

game::game(const int& sideA) 
	: mSideA(sideA)
	, mSideB(sideA)
	, mDish(mSideA, vector<cell>(mSideB))
{
}

//int mSideA;
//int mSideB = 0;
//float mChance = 0.1;
//vector<vector<cell>> mDish;
//bool mOver = false;
