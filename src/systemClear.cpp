#include <cstdlib>
#include "systemClear.h"

void systemClear() {
#ifdef _WIN32
	std::system("cls");
#else
	std::system("clear");
#endif
}
