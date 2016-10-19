#pragma once

#include <nqueen/parallel/context.hpp>
#include <nqueen/core.hpp>

namespace NQueen {

class Task {

	public:
		Task();
		virtual void execute(Context *context);
		uint test();
};

}