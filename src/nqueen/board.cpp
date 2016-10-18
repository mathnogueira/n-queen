#include <nqueen/board.hpp>
#include <nqueen/core.hpp>

using namespace NQueen;

Board::Board(uint tamanho) {
	alocarTabuleiro(tamanho);
}

void Board::alocarTabuleiro(uint tamanho) {
	DEBUG("Alocando a memoria para o tabuleiro de tamanho " << tamanho << "x" << tamanho);
	this->casa = new bool*[tamanho];
	for (uint linha = 0; linha < tamanho; ++linha) {
		this->casa[linha] = new bool[tamanho];
	}
}