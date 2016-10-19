#pragma once

#include <nqueen/tasks/task_buffer.hpp>
#include <nqueen/core.hpp>
#include <pthread.h>

namespace NQueen {

/**
 * Classe que executa tarefas em uma thread separada da thread principal.
 */
class Worker {
	
	public:
		Worker(TaskBuffer *buffer, Context *context);

	private:
		pthread_t thread;

};

}