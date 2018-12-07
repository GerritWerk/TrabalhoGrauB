#include "Jogador.h"



Jogador::Jogador()
{
	velo = 3.0f;
	vivo = true;
	xPos = 100;
	yPos = 350;
	gRecursos.carregarAudio("tiroSom", "assets/Musicas/Laser.mp3");
	somTiro.setAudio("tiroSom");
}


Jogador::~Jogador()
{
}

void Jogador::setSpriteSheets(string spritesheets)
{
	spr.setSpriteSheet(spritesheets);
	
	x = 100;
	y = 350;
	
	tiro.inicializar();
}

void Jogador::atualizar()
{
	if (vivo) {
		if (gTeclado.segurando[TECLA_DIR]) {
			dir.set(+x, 0);
			x += velo;
			direcao = 1;
			direcao2 = 2;
			direcao3 = 3;

		}
		else if (gTeclado.segurando[TECLA_ESQ]) {
			dir.set(-x, 0);
			x -= velo;
			direcao = 1;
			direcao2 = 2;
			direcao3 = 3;
		}
		else if (gTeclado.segurando[TECLA_CIMA]) {
			dir.set(0, -y);
			y -= velo;
			direcao = 1;
			direcao2 = 2;
			direcao3 = 3;
		}
		else if (gTeclado.segurando[TECLA_BAIXO]) {
			dir.set(0, +y);
			y += velo;
			direcao = 1; 
			direcao2 = 2;
			direcao3 = 3;
		}
		else {
			dir.set(0, 0);
			direcao = 1;
			direcao2 = 2;
			direcao3 = 3;
		}
		if (x < 0) {
			x += 10;
		}
		else if (x > 800) {
			x -= 10;
		}
		else if (y < 0) {
			y += 10;
		}
		else if (y > 600) {
			y -= 10;
		}
		if (gTeclado.pressionou[TECLA_Z] && tiro.getVivo() == false) {
			
			somTiro.tocar();
			tiro.disparar(x, y, direcao);
			
			
		}
		if (gTeclado.pressionou[TECLA_X] && tiro.getVivo() == false) {
			somTiro.tocar();
			tiro.disparar(x, y, direcao2);
			
			
		}
		if (gTeclado.pressionou[TECLA_C] && tiro.getVivo() == false) {

			somTiro.tocar();
			tiro.disparar(x, y, direcao3);
		}
		
		tiro.atualizar();
	}
}

void Jogador::animar()
{
	if(vivo)
	spr.avancarAnimacao();
}

void Jogador::desenhar()
{
	if (vivo) {
		spr.desenhar(x, y);
		tiro.desenhar();
	}
}

void Jogador::matarTiro()
{
	tiro.morrer();
}

Sprite Jogador::getSpriteTiro()
{
	if(vivo)
	return tiro.getSprite();
}

int Jogador::getXtiro()
{
	if(vivo)
	if(tiro.getVivo())
	return tiro.getX();
}

int Jogador::getYtiro()
{
	if(vivo)
	if(tiro.getVivo())
	return tiro.getY();
}



int Jogador::getPontuacao()
{
	return p;
}

bool Jogador::getVivo()
{
	return vivo;
}

void Jogador::getMorreu()
{
	vivo = false;
}

Sprite Jogador::getSprite()
{
	return spr;
}

int Jogador::getX()
{
	return x;
}

int Jogador::getY()
{
	return y;
}

void Jogador::reset()
{
	x = xPos;
	y = yPos;
	vivo = true;
	
}
