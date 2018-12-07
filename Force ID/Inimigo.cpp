#include "Inimigo.h"



Inimigo::Inimigo()
{
	x = 810;
	
	
	vivo = true;
}


Inimigo::~Inimigo()
{
}

void Inimigo::setSprite(string sprite)
{
	spr.setSpriteSheet(sprite);
}



void Inimigo::desenhar(int posY)
{
	if (vivo) {
		y = posY;
		spr.desenhar(x, y);
		spr.avancarAnimacao();
		andar();
	}
}

void Inimigo::andar()
{
	if (vivo) {
		if (x > 0) {
			x-= 3;
		}
		else if(x == 0) {
			
			morreu();
			
		}
	}
}

void Inimigo::morreu()
{
	vivo = false;
	
}

int Inimigo::getX()
{
	if (vivo) {
		return x;
	}
}

int Inimigo::getY()
{
	if (vivo) {
		return y;
	}
}

bool Inimigo::getVivo()
{
	return vivo;
}

Sprite Inimigo::getSprite()
{
	return spr;
}

void Inimigo::reset()
{
	x = xPos;
	vivo = true;
}

bool Inimigo::atualizar()
{
	if (vivo) {
		desenhar(y);
		return false;
	}
	else {
		return false;
	}
}
