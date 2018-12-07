#pragma once
#include <iostream>
#include "libUnicornio.h"
#include <stack>
#include "CarregadorDeAssets.h"
#include <ctime>
#include "Jogador.h"
#include "Inimigo.h"
#include "InimigoTiro.h"


enum MENU {
	MAIN,
	JOGAR,
	LOGIN,
	CASDASTRAR,
	LOGAR,
	LEADERBOARD,
	CREDITS,
	FINAL
};
class Menus
{
public:
	Menus();
	~Menus();
	std::stack<MENU> MenuStack;
	Sprite spr, spr2;

	void atualizarTelaAtual();
	void inicializar_asset();
	void atualizar_menu();
	void atualizar_jogar();
	void atualizar_leadboard();
	void atualizar_credits();
	void atualizar_final();
	void atualizar_login();
	void atualizar_cadastro();
	void atualizar_logar();
	void setSpriteSheet(string spritesheet);
	bool getSair();
	void finalizar();
	void resetGame();

private:
	BotaoSprite bJogo, bCredits, bRank, bSair, bNovoJogo, bCarregarJogo, bVoltar;
	bool sair, testeColi = false, testeColi2 = false;
	fstream f_mapa_assets;
	int posY, rp, pontos, recorde =0, posY2, maxRecorde = 0;
	Jogador * jogador;
	Inimigo * inimigo;
	InimigoTiro * iniT;
	Sprite fundo,fundoFinal;
	float tempo = 2, tempoPos = 300;
	Texto txtCreditos;
	Som somExplo;

	
};

