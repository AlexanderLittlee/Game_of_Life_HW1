#include <iostream>
#include "Game.h"

int main() {
	game g1(5);
	game g2(5,2);
	game g3(5,0.4f);
	game g4(5,3,0.2f);
	g2.defDish();
	g3.defDish();
	g4.defDish();
	
	g1.Step();
}