#pragma once
#include "libUnicornio.h"
#include "Tiro.h"
class Jogador
{
public:
	Jogador();
	virtual~Jogador();

	void setSpriteSheets(string spritesheets);
	void atualizar();
	void animar();
	void desenhar();

	void matarTiro();
	Sprite getSpriteTiro();
	int getXtiro();
	int getYtiro();
	
	int getPontuacao();
	bool getVivo();
	void getMorreu();
	Sprite getSprite();
	int getX();
	int getY();
	void reset();



protected:
	Sprite spr;
	Vetor2D dir, pos;
	float velo;
	int x, y, direcao, xPos, yPos, direcao2, direcao3,p;
	Tiro tiro;
	bool vivo;
	Som somTiro;
	
};

