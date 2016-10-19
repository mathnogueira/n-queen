#pragma once

#include <nqueen/core.hpp>

namespace NQueen {

template <typename T>
class Queue {

	public:
		Queue() {
			head = NULL;
			size = 0;
			initialized = true;
		}

		~Queue() {
			while (!empty())
				pop();
		}

		void push(T element) {
			Node *node = new Node;
			node->content = element;
			node->next = NULL;
			if (head == NULL) {
				head = node;
			} else {
				for (Node *last = head; head->next != NULL; last = last->next);
				head->next = node;	
			}
			++size;
		}

		T pop() {
			T element;
			if (!initialized)
				return element;
			element = head->content;
			Node *oldHead = head;
			head = head->next;
			delete oldHead;
			--size;
			return element;
		}

		bool empty() {
			uint size = this->size;
			return initialized && size == 0;
		}


	private:

		struct Node {
			T content;
			struct Node *next;
		};
		Node *head = NULL;
		uint size = 0;
		bool initialized = false;

};

}