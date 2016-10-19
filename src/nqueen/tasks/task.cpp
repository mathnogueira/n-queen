#include <nqueen/tasks/task.hpp>

using namespace NQueen;

Task::Task() {}

void Task::execute(Context *context) {
	DEBUG("Executing task!");
}

uint Task::test() {
	return 1;
}