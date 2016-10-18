#include <iostream>
#include <cstdlib>
#include <nqueen/solver.hpp>

int main(int argc, char **argv) {
	if (argc < 3) {
		std::cout << "Comando invalido. Uso: " 
				  << argv[0] 
				  << " <numero de rainhas> <rainhas por thread>" 
				  << std::endl;
		return EXIT_FAILURE;
	}
	// O programa recebeu todos os parametros
	uint numeroRainhas = atoi(argv[1]);
	uint numeroRainhasThread = atoi(argv[2]);
	// Cria uma solução para o problema
	NQueen::Solver solver(numeroRainhas, numeroRainhasThread);
	// Espera o programa terminar de executar
	while (true) ;
	return 0;
}