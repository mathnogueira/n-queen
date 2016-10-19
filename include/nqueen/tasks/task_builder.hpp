#pragma once

#include <nqueen/tasks/task.hpp>

namespace NQueen {

class TaskBuilder {

	public:
		TaskBuilder();
		virtual Task* build();
};

}