#include "Game.h"
#include <random>
#include <cstdint>


//----------------------------------------------------------------------------------------------------------------------
//STATICS


static int ID=0;


//----------------------------------------------------------------------------------------------------------------------
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


bool game::isOnDish(const int& x, const int& y) const
{
	return (x >= 0 && x < mDish.size() && y >= 0 && y < mDish[0].size());
}


void game::defDish()
{
	int percent = round(mChance * 100);
	for (size_t i = 0; i < mSideA; ++i)
	{
		for (size_t j = 0; j < mSideB; ++j)
		{
			if (rand() % 100 < percent)
				mDish[i][j] = cell(true);
			else
				mDish[i][j] = cell(false);
		}
	}
}


void game::defDish(const int& xbegin, const int& xend, const int& ybegin, const int& yend, const bool& generate)
{
	int percent = round(mChance * 100);
	for (size_t i = xbegin; i < xend; ++i)
	{
		for (size_t j = ybegin; j < yend; ++j)
		{
			if (generate)
			{
				if (rand() % 100<percent)
					mDish[i][j] = cell(true);
				else
					mDish[i][j] = cell(false);
			}
		}
	}
}


void game::Step() 
{
	for (size_t i = 0; i < mSideA; ++i)
	{
		for (size_t j = 0; j < mSideB; ++j)
		{
			int neighb = getNeighbours(mDish[i][j]);

			if ((neighb != 2 || neighb != 3) && !mDish[i][j].isAlive())
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


int game::getNeighbours(const cell& c) const
{
	int neighbours = 0, x, y;

	for (size_t i = 0; i < mSideA; ++i)
	{
		for (size_t j = 0; j < mSideB; ++j)
		{
			if (mDish[i][j] == c)
			{
				x = i;
				y = j;
			}
		}
	}

	for (size_t i = x-1; i < x+1; ++i)
	{
		for (size_t j = y-1; j < y+1; ++j)
		{
			if (isOnDish(i,j))
			{
				if (mDish[i][j] != c && mDish[i][j].isAlive())
					neighbours;
			}
		}
	}
	
	return neighbours;
}


//cell


bool game::cell::isAlive() const 
{
	return mAlive;
}


void game::cell::makeaVitalChange() 
{
	this->mAlive = false;
}



//----------------------------------------------------------------------------------------------------------------------
//OPERATORS


//game

std::ostream& operator<<(std::ostream& outputStream, game& game)
{
	int x = game.getSideA(), y = game.getSideB();
	auto dish = game.getDish();

	for (size_t i = 0; i < x; ++i)
	{
		outputStream << "\n";
		for (size_t j = 0; j < y; ++j)
		{
			if (dish[i][j].isAlive())
				outputStream << "O";
			else
				outputStream << ".";
		}
	}
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






//----------------------------------------------------------------------------------------------------------------------
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
{
	this->defDish();
}


game::game(const int& sideA, const float& Chance)
	: mSideA(sideA)
	, mSideB(sideA)
	, mChance(Chance)
	, mDish(sideA, std::vector<cell>(sideA))
{
	this->defDish();
}

game::game(const int& sideA,const int& sideB)
	: mSideA(sideA)
	, mSideB(sideB)
	, mDish(sideA, std::vector<cell>(sideB))
{
	this->defDish();
}

game::game(const int& sideA) 
	: mSideA(sideA)
	, mSideB(sideA)
	, mDish(mSideA, std::vector<cell>(mSideB))
{
	this->defDish();
}
