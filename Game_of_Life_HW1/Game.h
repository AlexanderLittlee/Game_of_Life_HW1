#pragma once
#include <vector>
using namespace std;

class game {

public:
	class cell {

	public:

		cell() = default;
		cell(const bool& alive);

	private:
		
		int mNeighbours=0;
		bool mAlive=false;
	};

public:

	game(const int& sideA);
	game(const int& sideA, const int& sideB);
	game(const int& sideA, const float& Chance);
	game(const int& sideA, const int& sideB, const float& Chance);
	game(const int& height, const int& width, const int& top, const int& left, const vector<vector<cell>>& vect);


private:

	int mSideA;
	int mSideB=0;
	float mChance = 0.1;
	vector<vector<cell>> mDish;
	bool mOver = false;

};