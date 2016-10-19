#pragma once

#include <nqueen/tasks/task_builder.hpp>
#include <nqueen/tasks/task.hpp>
#include <nqueen/core.hpp>

namespace NQueen {

class TaskBuffer {

	public:
		TaskBuffer();
		~TaskBuffer();
		void add(TaskBuilder *builder);
		Task* get();
		bool empty();


	private:
		TaskBuilder *builder;

};

}