#pragma once
#include "libUnicornio.h"
#include "TiroIni.h"
class InimigoTiro
{
public:
	InimigoTiro();
	~InimigoTiro();
	int getX();
	int getY();
	int getXTiro();
	int getYTiro();
	void setSpriteSheet(string spritesheet);
	
	void desenhar(int posy);
	void andar();
	bool getVivo();
	bool getVivoTiro();
	void getMorreu();
	void getMorreuTiro();
	Sprite getSprite();
	Sprite getSpriteTiro();
	
	void reset();

private:
	float xT, yT, velo;
	int x, y, xPos = 810, direcao,tempo = 5, direcao2;
	bool vivo;
	Sprite spr;
	TiroIni tiroI;
	

};

