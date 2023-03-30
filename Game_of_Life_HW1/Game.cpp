#include "Game.h"
#include <random>


static int ID=0;

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

bool game::anyAlive() const
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


bool game::cell::operator==(const cell& other) const 
{
	return (mcellID == other.mcellID);
}


bool game::cell::isAlive() const 
{
	return mAlive;
}

void game::cell::makeaVitalChange() 
{
	this->mAlive = false;
}


//vector<int> game::cell::getCoordinates() const
//{
//	vector<int> coordinates(2);
//	for (size_t i = 0; i < mSideA; ++i)
//	{
//		for (size_t j = 0; j < mSideB; ++j)
//		{
//			if (mDish[i][j] == this)
//			{
//				coordinates[0] = i;
//				coordinates[1] = j;
//			}
//		}
//	}
//	return coordinates;
//}

int game::cell::getNeighbours() const
{
	
	
	return 0;
}

//----------------------------------------------------------------------------------------------------------------------
//CONSTRUCTORS


//cell
game::cell::cell(const bool& alive) 
	: mcellID(ID++)
	, mAlive(alive)
{}



//game

//TODO
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
