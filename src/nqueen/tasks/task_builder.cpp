#include <nqueen/tasks/task_builder.hpp>
#include <nqueen/tasks/task.hpp>

using namespace NQueen;

TaskBuilder::TaskBuilder() {}

Task* TaskBuilder::build() {
	return new Task();
}