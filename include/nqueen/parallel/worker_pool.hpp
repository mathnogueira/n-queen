#pragma once

#include <nqueen/tasks/task_builder.hpp>
#include <nqueen/tasks/task_buffer.hpp>
#include <nqueen/parallel/context.hpp>
#include <nqueen/parallel/worker.hpp>
#include <nqueen/tasks/task.hpp>
#include <nqueen/core.hpp>
#include <vector>

namespace NQueen {

/**
 * Classe que gerencia os workers ativos.
 */
class WorkerPool {

	public:
		WorkerPool();
		~WorkerPool();
		void setNumberWorkers(uint number);
		void addTask(TaskBuilder *builder);
		void start(void *data);
	
	private:
		uint numberWorkers;
		std::vector<Worker*> workers;
		TaskBuffer *buffer;
		Context *context;

};

}