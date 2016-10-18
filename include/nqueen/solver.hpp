#pragma once

#include <nqueen/board.hpp>
#include <nqueen/parallel/worker_pool.hpp>
#include <vector>

namespace NQueen {

class Solver {

	public:

		/**
		* Constroi um novo solucionador.
		* @param nRainhas numero de rainhas.
		* @param rainhasThread numero de rainhas por thread.
		*/
		Solver(uint nRainhas, uint rainhasThread);

		/**
		* Soluciona o problema das N-Rainhas.
		*/
		void solve();

	private:

		Board *tabuleiro;

		void criarTabuleiro(uint n);

		WorkerPool workerPool;
};

}