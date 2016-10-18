#include <nqueen/parallel/worker_pool.hpp>
#include <nqueen/parallel/context.hpp>
#include <nqueen/core.hpp>

using namespace NQueen;

WorkerPool::WorkerPool() {
	buffer = new TaskBuffer;
}

WorkerPool::~WorkerPool() {
	delete context;
	delete buffer;
}

void WorkerPool::setNumberWorkers(uint number) {
	this->numberWorkers = number;
}

void WorkerPool::addTask(Task &task) {
	
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