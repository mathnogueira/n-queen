#include <nqueen/tasks/task_buffer.hpp>

using namespace NQueen;

TaskBuffer::TaskBuffer() {
	DEBUG("Criando o buffer de tarefas");
	builder = NULL;
}

TaskBuffer::~TaskBuffer() {
	DEBUG("Destruindo o buffer de tarefas");
}

void TaskBuffer::add(TaskBuilder *builder) {
	DEBUG("Definindo construtor de tarefas: " << builder)
	this->builder = builder;
}

Task* TaskBuffer::get() {
	return builder != NULL ? builder->build() : NULL;
}

bool TaskBuffer::empty() {
	return builder == NULL;
}