#pragma once

#include <nqueen/core.hpp>

namespace NQueen {

struct Context {
	uint thread_id;
	void *data;
};

}