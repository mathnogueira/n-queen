#pragma once

#include <nqueen/parallel/task.hpp>
#include <nqueen/core.hpp>

namespace NQueen {

class TaskBuffer {

	public:
		TaskBuffer();
		~TaskBuffer();
		void add(Task &task);
		Task* get();
		bool empty();


	private:
		Queue<Task*> *taskQueue;

};

}