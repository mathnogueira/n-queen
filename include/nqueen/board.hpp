#pragma once

#include <nqueen/core.hpp>

namespace NQueen {

class Board {

	public:

		Board(uint tamanho);

	private:

		bool **casa;

		void alocarTabuleiro(uint tamanho);
};

}