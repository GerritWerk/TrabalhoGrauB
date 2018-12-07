#include "TiroIni.h"



TiroIni::TiroIni()
{
}


TiroIni::~TiroIni()
{
}

int TiroIni::getX()
{
	return x;
}

int TiroIni::getY()
{
	return y;
}

bool TiroIni::getVivo()
{
	return vivo;
}

Sprite TiroIni::getSprite()
{
	return sprite;
}

void TiroIni::inicializar()
{
	if (!gRecursos.carregouSpriteSheet("tiroI")) {
		gRecursos.carregarSpriteSheet("tiroI", "assets/SpriteSheets/TiroInimigo.png");
	}
	sprite.setSpriteSheet("tiroI");
	velocidade = 3;
	vivo = false;
}

void TiroIni::desenhar()
{
	if (vivo) {
		sprite.desenhar(x, y);
	}
}

void TiroIni::atualizar()
{
	if (vivo) {
		if (direcao == 1) {
			x -= velocidade;
		}
		if (x<sprite.getLargura() || x > gJanela.getLargura() + sprite.getLargura()) {//testa se ja passou do limite da janela
			morrer();
		}

	}
}

void TiroIni::morrer()
{
	vivo = false;
}

void TiroIni::disparar(float x, float y, int direcao)
{
	this->x = x;
	this->y = y;
	this->direcao = direcao;
	vivo = true;
}
