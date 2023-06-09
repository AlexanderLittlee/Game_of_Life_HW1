#pragma once
#include <vector>
#include <cstdint>
#include <iostream>

class game {

public:
	class cell {

		
	public:

		cell() = default;
		cell(const bool& alive);

		bool operator==(const cell& other) const;
		bool operator!=(const cell& other) const;

		void deadCell();
		void liveCell();
		bool isAlive() const;

	private:
		
		int mcellID;
		int mNeighbours=0;
		bool mAlive=false;
	};

public:

	game(const int& sideA);
	game(const int& sideA, const int& sideB);
	game(const int& sideA, const float& Chance);
	game(const int& sideA, const int& sideB, const float& Chance);
	game(const int& height, const int& width, const int& top, const int& left, const std::vector<std::vector<cell>>& vect);
	

	friend std::ostream& operator<<(std::ostream& outputStream, game& game);

	std::vector<std::vector<cell>>& getDish();
	int getSideA() const;
	int getSideB() const;
	float getChance() const;

	
	void defDish();
	void defDish(const int& xbegin, const int& xend, const int& ybegin, const int& yend, const bool& generate);
	void Step();
	void getEveryNeighbour();
	void randCellMaker(const int& i, const int& j);

	int getNeighbours(const int& x, const int& y);
	
	bool anyAlive() const;
	bool isOnDish(const int& x, const int& y) const;
	bool isDone() const;


private:

	int mSideA;
	int mSideB=0;
	float mChance = 0.1;
	std::vector<std::vector<cell>> mDish;
	std::vector<std::vector<int>> mNeighbourCount;
	int mStepCount=1;
	int mMaxStepCount = 100;

};