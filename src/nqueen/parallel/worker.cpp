#include <nqueen/parallel/worker.hpp>
#include <nqueen/tasks/task_buffer.hpp>
#include <nqueen/tasks/task.hpp>
#include <nqueen/core.hpp>

using namespace NQueen;

static int counter = 0;
static pthread_mutex_t tid_mutex;
static pthread_mutex_t buffer_mutex;
static pthread_barrier_t barrier;

struct DataWrapper {
	TaskBuffer *buffer;
	Context *context;
};

void incrementaThreadId(int *counter) {
	// Mutex para incrementar numero da thread
	pthread_mutex_lock(&tid_mutex);
	*counter = *counter + 1;
	DEBUG("[Nova thread] Id: " << *counter);
	pthread_mutex_unlock(&tid_mutex);
	// Fim do mutex
}

void verificarTarefas(DataWrapper *data) {
	// Obtem o contexto da aplicação
	Context *context = data->context;
	// Espera até que uma tarefa esteja disponível para ser executada
	pthread_mutex_lock(&buffer_mutex);
	Task *task = data->buffer->get();
	pthread_mutex_unlock(&buffer_mutex);
	// Executa a tarefa a partir do contexto da aplicação
	task->execute(context);
}

void* start(void* arg) {
	DataWrapper *data = (DataWrapper*) arg;
	int *id = &counter;
	int tid = *id;
	incrementaThreadId(id);
	while (true) {
		verificarTarefas(data);
	}
}

Worker::Worker(TaskBuffer *buffer, Context *context) {
	// DataWrapper data = { buffer, context };
	DataWrapper *data = new DataWrapper();
	data->buffer = buffer;
	data->context = context;
	pthread_create(&thread, NULL, start, data);
}