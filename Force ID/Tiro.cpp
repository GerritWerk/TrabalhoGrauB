#include "Tiro.h"



Tiro::Tiro()
{
	
}


Tiro::~Tiro()
{
}

int Tiro::getX()
{
	return x;
}

int Tiro::getY()
{
	return y;
}

bool Tiro::getVivo()
{
	return vivo;
}

Sprite Tiro::getSprite()
{
	return sprite;
}

void Tiro::inicializar()
{
	if (!gRecursos.carregouSpriteSheet("tiro")) {
		gRecursos.carregarSpriteSheet("tiro", "assets/SpriteSheets/Tiro.png");
	}
	sprite.setSpriteSheet("tiro");
	velocidade = 5;
	vivo = false;
}

void Tiro::desenhar()
{
	if (vivo) {
		sprite.desenhar(x, y);
	}
}

void Tiro::atualizar()
{
	if (vivo) {
		if (direcao == 1) {
			x += velocidade;
		}
		if (direcao == 2) {
			y += -velocidade;
		}
		if (direcao == 3) {
			y += velocidade;
		}
		if (x<sprite.getLargura() || x > gJanela.getLargura() + sprite.getLargura() || y<sprite.getAltura() || y>gJanela.getAltura()+sprite.getAltura()) {//testa se ja passou do limite da janela
			morrer();
		}
		
	}
}

void Tiro::morrer()
{
	
	vivo = false;
}

void Tiro::disparar(float x, float y, int direcao)
{
	this->x = x;
	this->y = y;
	this->direcao = direcao;
	vivo = true;
}
