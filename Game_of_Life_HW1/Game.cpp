#include "Game.h"
#include <random>
#include <cstdint>


//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//STATICS


static int ID=0;

static int Rand() 
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(1, 100);
	return dist(rd);
}


//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//METHODS
 

//game	

std::vector<std::vector<game::cell>>& game::getDish()  
{
	return mDish;
}


int game::getSideA() const
{
	return mSideA;
}


int game::getSideB() const
{
	return mSideB;
}


float game::getChance() const 
{
	return mChance;
}


bool game::isOnDish(const int& x, const int& y) const
{
	return (x >= 0 && x < mDish.size() && y >= 0 && y < mDish[0].size());
}

bool game::isDone() const
{
	return mStepCount==mMaxStepCount;
}


void game::randCellMaker(const int& i, const int& j)
{
	int percent = round(mChance * 100);
	if (Rand() < percent)
		mDish[i][j] = cell(true);
	else
		mDish[i][j] = cell(false);
}


void game::defDish()
{
	for (size_t i = 0; i < mSideA; ++i)
	{
		for (size_t j = 0; j < mSideB; ++j)
			randCellMaker(i, j);
		
	}
}


void game::defDish(const int& xbegin, const int& xend, const int& ybegin, const int& yend, const bool& generate)
{
	for (size_t i = xbegin; i < xend; ++i)
	{
		for (size_t j = ybegin; j < yend; ++j)
		{
			if (generate)
				randCellMaker(i, j);
			else
				mDish[i][j] = cell(false);
		}
	}
}


int game::getNeighbours(const int& x, const int& y)
{
	int ncount = 0;
	for (size_t i = x - 1; i < x + 2; ++i)
	{
		for (size_t j = y - 1; j < y + 2; ++j)
		{
			if (isOnDish(i, j) && i != x && j != y && mDish[i][j].isAlive())
				ncount++;
		}
	}
	return ncount;
}


void game::getEveryNeighbour()
{
	for (size_t i = 0; i < mSideA; ++i)
	{
		for (size_t j = 0; j < mSideB; ++j)
			mNeighbourCount[i][j] = getNeighbours(i, j);
	}
}


void game::Step() 
{
	getEveryNeighbour();
	for (size_t i = 0; i < mSideA; ++i)
	{
		for (size_t j = 0; j < mSideB; ++j)
		{
			if (mDish[i][j].isAlive() 
				&& (mNeighbourCount[i][j] == 2 || mNeighbourCount[i][j] == 3))
			{
					mDish[i][j].liveCell();
			}
			else if(!mDish[i][j].isAlive()
				&& mNeighbourCount[i][j] == 3)
			{
					mDish[i][j].liveCell();
			}
			else
			{
				mDish[i][j].deadCell();
			}
		}
	}
	++mStepCount;
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


bool game::cell::isAlive() const 
{
	return mAlive;
}


void game::cell::deadCell() 
{
	this->mAlive = false;
}


void game::cell::liveCell() 
{
	this->mAlive = true;
}


//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//OPERATORS


//game

std::ostream& operator<<(std::ostream& outputStream, game& game)
{
	int x = game.getSideA(), y = game.getSideB();
	auto dish = game.getDish();
	outputStream << "\tGame of Life\nDish size: "<<game.getSideA()<<"x"<<game.getSideB()<<"| chance: "<<game.getChance()*100<<"% | step: "<<game.mStepCount<<"/"<<game.mMaxStepCount<<std::endl;
	for (size_t i = 0; i < x; ++i)
	{
		outputStream << "\n";
		for (size_t j = 0; j < y; ++j)
		{
			if (dish[i][j].isAlive())
				outputStream << "O";
			else
				outputStream << " ";
		}
	}
	outputStream << "\n\n";
	return outputStream;
}


//cell

bool game::cell::operator==(const cell& other) const
{
	return (mcellID == other.mcellID);
}

bool game::cell::operator!=(const cell& other) const
{
	return !(*this == other);
}






//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//CONSTRUCTORS


//cell
game::cell::cell(const bool& alive) 
	: mcellID(ID++)
	, mAlive(alive)
{}



//game

//TODO
game::game(const int& height, const int& width, const int& top, const int& left, const std::vector<std::vector<game::cell>>& vect)
	: mSideA(height)
	, mSideB(width)
	, mDish(height, std::vector<cell>(width))
	, mNeighbourCount(mSideA, std::vector<int>(mSideB))
{
	this->defDish(0,mSideA,0,mSideB,false);
	if (isOnDish(top,left) && isOnDish(top+vect.size(),left+vect[0].size()))
	{
		this->defDish(top, top + vect.size(), left, left + vect[0].size(), true);
	}
}


game::game(const int& sideA, const int& sideB, const float& Chance)
	: mSideA(sideA)
	, mSideB(sideB)
	, mChance(Chance)
	, mDish(sideA, std::vector<cell>(sideB))
	, mNeighbourCount(mSideA, std::vector<int>(mSideB))
{
	this->defDish();
}


game::game(const int& sideA, const float& Chance)
	: mSideA(sideA)
	, mSideB(sideA)
	, mChance(Chance)
	, mDish(sideA, std::vector<cell>(sideA))
	, mNeighbourCount(mSideA, std::vector<int>(mSideB))
{
	this->defDish();
}

game::game(const int& sideA,const int& sideB)
	: mSideA(sideA)
	, mSideB(sideB)
	, mDish(sideA, std::vector<cell>(sideB))
	, mNeighbourCount(mSideA, std::vector<int>(mSideB))
{
	this->defDish();
}

game::game(const int& sideA) 
	: mSideA(sideA)
	, mSideB(sideA)
	, mDish(mSideA, std::vector<cell>(mSideB))
	, mNeighbourCount(mSideA, std::vector<int>(mSideB))
{
	this->defDish();
}

