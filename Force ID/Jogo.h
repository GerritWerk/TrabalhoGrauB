#pragma once
#include "libUnicornio.h"
#include "Jogador.h"
#include "Inimigo.h"
#include <ctime>
#include "Menus.h"

class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();
	
	void executar();

private:
	Jogador* jogador;
	Sprite fundo;
	Inimigo* inimigo;
	Tiro * tiro;
	int posY;
	float tempo = 100;
	Menus menu;
	
};

