#include <nqueen/parallel/worker_pool.hpp>
#include <nqueen/parallel/context.hpp>
#include <nqueen/core.hpp>

using namespace NQueen;

WorkerPool::WorkerPool() {
	buffer = new TaskBuffer();
	DEBUG("Criando pool de threads");
}

WorkerPool::~WorkerPool() {
	delete context;
	delete buffer;
	DEBUG("Destruindo pool de threads");
}

void WorkerPool::setNumberWorkers(uint number) {
	this->numberWorkers = number;
}

void WorkerPool::addTask(TaskBuilder *builder) {
	buffer->add(builder);
}

void WorkerPool::start(void *data) {
	context = new Context;
	context->thread_id = 0;
	context->data = data;
	// Cria os workers para a pool
	for (uint i = 0; i < numberWorkers; ++i) {
		workers.push_back(new Worker(buffer, context));
	}
	DEBUG("Starting workers");
}