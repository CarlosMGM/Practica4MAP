#include <math.h>
#include "ExampleGame.h"

using namespace std;

int main(int ac, char** av) {
	ExampleGame* g = new ExampleGame();
	g->start();
	delete g;
	return 0;
}
