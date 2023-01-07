#include "Engine/engine.h"
#include <iostream>

int main(int argc, char **argv)
{
	engine::Engine engine;
	engine.Run(argc, argv);

	return 0;
}
