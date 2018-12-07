#pragma once
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
class CarregadorDeAssets
{
public:
	CarregadorDeAssets();
	~CarregadorDeAssets();
	bool carregarRecursos(std::fstream & f_arq_recursos);
private:
	int i_num_assets;
};

