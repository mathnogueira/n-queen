#pragma once

#include <nqueen/parallel/task_buffer.hpp>
#include <nqueen/parallel/context.hpp>
#include <nqueen/parallel/task.hpp>
#include <nqueen/parallel/worker.hpp>
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
		void addTask(Task &task);
		void start(void *data);
	
	private:
		uint numberWorkers;
		std::vector<Worker*> workers;
		TaskBuffer *buffer;
		Context *context;

};

}