#include <Doryen/Doryen.hpp>

using namespace Doryen;

int main()
{
	Console console {100, 100};

	while (console.isRunning())
	{
		console.clear();
		console.draw();
	}
}

