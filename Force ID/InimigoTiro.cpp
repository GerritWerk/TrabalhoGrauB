#include "InimigoTiro.h"



InimigoTiro::InimigoTiro()
{
	vivo = true;
}


InimigoTiro::~InimigoTiro()
{
}

int InimigoTiro::getX()
{
	if(vivo)
	return x;
}

int InimigoTiro::getY()
{
	if(vivo)
	return y;
}

int InimigoTiro::getXTiro()
{
	if (vivo) {
		if(tiroI.getVivo())
		return tiroI.getX();
	}
}

int InimigoTiro::getYTiro()
{
	if (vivo) {
		if(tiroI.getVivo())
		return tiroI.getY();
	}
}

void InimigoTiro::setSpriteSheet(string spritesheet)
{
	spr.setSpriteSheet(spritesheet);
	tiroI.inicializar();
}



void InimigoTiro::desenhar(int posy)
{
	if (vivo) {
		y = posy;
		spr.desenhar(x, y);
		spr.avancarAnimacao();
		tiroI.desenhar();
		
		andar();
	}
}

void InimigoTiro::andar()
{
	if (vivo) {
		if (x > 0) {
			x--;
			direcao = 1;
		}
		else if (x == 0) {
			getMorreu();
			
		}
		tempo--;
		if (tiroI.getVivo() == false && tempo == 0) {
			tiroI.disparar(x, y, direcao);
			tempo = 5;
		}


		
	}
}

bool InimigoTiro::getVivo()
{
	return vivo;
}

bool InimigoTiro::getVivoTiro()
{
	return tiroI.getVivo();
}

void InimigoTiro::getMorreu()
{
	vivo = false;
}

void InimigoTiro::getMorreuTiro()
{
	tiroI.morrer();
}

Sprite InimigoTiro::getSprite()
{
	return spr;
}

Sprite InimigoTiro::getSpriteTiro()
{
	return tiroI.getSprite();
}



void InimigoTiro::reset()
{
	vivo = true;
	x = xPos;
}
