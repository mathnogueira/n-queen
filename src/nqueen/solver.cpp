#include <nqueen/solver.hpp>
#include <nqueen/parallel/worker.hpp>
#include <nqueen/core.hpp>

using namespace NQueen;

Solver::Solver(uint nRainhas, uint rainhasThread) {
	uint numeroThreads = ceil((double) nRainhas/rainhasThread);
	DEBUG("Criando aplicação com " << numeroThreads << " threads");
	criarTabuleiro(nRainhas);
	// Cria os workers para processar os dados em paralelo.
	workerPool.setNumberWorkers(numeroThreads);
	workerPool.start(tabuleiro);
}

void Solver::criarTabuleiro(uint n) {
	if (tabuleiro == NULL)
		delete tabuleiro;
	tabuleiro = new Board(n);
}