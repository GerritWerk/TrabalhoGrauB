#pragma once
#include "libUnicornio.h"
class TiroIni
{
public:
	TiroIni();
	~TiroIni();
	int getX();
	int getY();
	bool getVivo();
	Sprite getSprite();

	void inicializar();
	void desenhar();
	void atualizar();
	void morrer();
	void disparar(float x, float y, int direcao);

private:
	float x, y, velocidade;
	Sprite sprite;
	bool vivo;
	int direcao;
};

