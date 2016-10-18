#pragma once

#include <nqueen/core.hpp>
#include <pthread.h>

namespace NQueen {

template <typename T>
class Queue {

	public:
		Queue() {
			head = NULL;
		}

		~Queue() {
			while (!empty())
				pop();
		}

		void push(T element) {
			Node *node = new Node;
			node->content = element;
			node->next = NULL;
			pthread_mutex_lock(&queue_mutex);
			if (head == NULL) {
				head = node;
			} else {
				for (Node *last = head; head->next != NULL; last = last->next);
				head->next = node;	
			}
			++size;
			pthread_mutex_unlock(&queue_mutex);
		}

		T pop() {
			pthread_mutex_lock(&queue_mutex);
			T element = head->content;
			Node *oldHead = head;
			head = head->next;
			delete oldHead;
			--size;
			pthread_mutex_unlock(&queue_mutex);
			return element;
		}

		bool empty() {
			pthread_mutex_lock(&queue_mutex);
			uint size = this->size;
			pthread_mutex_unlock(&queue_mutex);
			return size == 0;
		}


	private:

		struct Node {
			T content;
			struct Node *next;
		};
		Node *head;
		uint size;
		pthread_mutex_t queue_mutex;

};

}