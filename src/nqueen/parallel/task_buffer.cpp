#include <nqueen/parallel/task_buffer.hpp>

using namespace NQueen;

TaskBuffer::TaskBuffer() {
	taskQueue = new Queue<Task*>;
	DEBUG("Criando o buffer de tarefas");
}

TaskBuffer::~TaskBuffer() {
	DEBUG("Destruindo o buffer de tarefas");
}

void TaskBuffer::add(Task &task) {
	taskQueue->push(&task);
}

Task* TaskBuffer::get() {
	return taskQueue->pop();
}

bool TaskBuffer::empty() {
	return taskQueue->empty();
}