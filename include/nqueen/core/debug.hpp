#pragma once

#include <iostream>

#ifndef NDEBUG
	#define DEBUG(x) std::cout << "[DEBUG] " << x << std::endl;
#else 
	#define DEBUG(x) ;
#endif