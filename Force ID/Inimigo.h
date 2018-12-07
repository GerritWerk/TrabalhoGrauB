#pragma once
#include "libUnicornio.h"
class Inimigo
{
public:
	Inimigo();
	~Inimigo();
	void setSprite(string sprite);
	void desenhar(int posY);
	void andar();
	void morreu();
	int getX();
	int getY();
	bool getVivo();
	Sprite getSprite();
	void reset();
	bool atualizar();

private:
	Sprite spr;
	int x, y;
	int xPos = 810;
	bool vivo;
};

