#include "Menus.h"



Menus::Menus()
{
	MenuStack.push(MAIN);
	sair = true;
	srand(time(NULL));
	pontos = 0;
	
}


Menus::~Menus()
{
}

void Menus::atualizarTelaAtual()
{
	
	switch (MenuStack.top()) {
	case MAIN:
		atualizar_menu();
		break;
	case JOGAR:
		atualizar_jogar();
		break;
	case LOGIN:
		atualizar_login();
		break;
	case LEADERBOARD:
		atualizar_leadboard();
		break;
	case CASDASTRAR:
		atualizar_cadastro();
		break;
	case LOGAR:
		atualizar_logar();
		break;
	case CREDITS:
		atualizar_credits();
		break;
	case FINAL:
		atualizar_final();
	default:
		break;
	}
}

void Menus::inicializar_asset()
{
	this->f_mapa_assets.open("assets/mapa_assets.txt", ios::in);
	if (!f_mapa_assets) {
		gDebug.erro("não abriu arquivo", this);
	}
	CarregadorDeAssets * cda_carregador_assets = new CarregadorDeAssets;
	if (!cda_carregador_assets->carregarRecursos(f_mapa_assets)) {
		gDebug.erro("Falha no carregamento de recurso");
	}

	spr.setSpriteSheet("main");
	bJogo.setSpriteSheet("BJogar");
	bNovoJogo.setSpriteSheet("BNovoJ");
	bCarregarJogo.setSpriteSheet("BCarregarJ");
	bRank.setSpriteSheet("BRank");
	bCredits.setSpriteSheet("BCreditos");
	bSair.setSpriteSheet("BSair");
	bVoltar.setSpriteSheet("BVoltar");
	bJogo.setPos(gJanela.getLargura() / 2, 360);
	bNovoJogo.setPos(gJanela.getLargura() / 2, 360);
	bCarregarJogo.setPos(gJanela.getLargura() / 2, 420);
	bRank.setPos(gJanela.getLargura() / 2, 420);
	bCredits.setPos(gJanela.getLargura() / 2, 480);
	bSair.setPos(gJanela.getLargura() / 2, 540);
	bVoltar.setPos(gJanela.getLargura() / 2, 540);


	
	fundo.setSpriteSheet("mapa");
	fundoFinal.setSpriteSheet("menuFinal");
	

	jogador = new Jogador;
	jogador->setSpriteSheets("Jogador");
	gRecursos.getSpriteSheet("Jogador")->setNumFramesDaAnimacao(0, 2);

	
    inimigo = new Inimigo;
	inimigo->setSprite("inimigo");
	gRecursos.getSpriteSheet("inimigo")->setNumFramesDaAnimacao(0, 2);

	iniT = new InimigoTiro;
	iniT->setSpriteSheet("inimigoT");
	gRecursos.getSpriteSheet("inimigoT")->setNumFramesDaAnimacao(0, 2);

	

	gRecursos.carregarFonte("Creditos", "assets/Fontes/Aaargh.ttf", 18);
	txtCreditos.setFonte("Creditos");
	txtCreditos.setCor(255, 255, 255);
	txtCreditos.setAncora(0.5, 0);
	txtCreditos.setString("Desenvolvedor: Gerrit B. De Werk\n"
		"Programador: Gerrit B. de Werk\n"
		"Arte: Gerrit B. de Werk\n"
		"Professor: Raphael Leite Campos\n"
		"Engine: LibUnicornio\n");
	gRecursos.carregarMusica("musicaFundo", "assets/Musicas/StarTrek8Bits.mp3", 20.0f);
	gRecursos.carregarAudio("explosao", "assets/Musicas/explosao.mp3");
	somExplo.setAudio("explosao");
}

void Menus::atualizar_menu()
{
	if (!gMusica.estaTocando()) {
		gMusica.tocar("musicaFundo", true);
	}
	gMouse.mostrarCursor();
	spr.desenhar(gJanela.getLargura()/2, gJanela.getAltura()/2);
	bJogo.desenhar();
	bJogo.atualizar();
	if (bJogo.estaClicado()) {
		MenuStack.push(JOGAR);
		resetGame();
	}
	bRank.desenhar();
	bRank.atualizar();
	if (bRank.estaClicado()) {
		MenuStack.push(LEADERBOARD);
	}
	bCredits.desenhar();
	bCredits.atualizar();
	if (bCredits.estaClicado()) {
		MenuStack.push(CREDITS);

	}
	bSair.desenhar();
	bSair.atualizar();
	if (bSair.estaClicado()) {
		sair = false;
	}

	
}

void Menus::atualizar_jogar()
{  
	if (tempo) {
		tempo--;
	}
	gMusica.parar();
	fundo.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	gMouse.esconderCursor();
	
		if (uniTestarColisaoSpriteComSprite(jogador->getSpriteTiro(), jogador->getXtiro(), jogador->getYtiro(), 0, inimigo->getSprite(), inimigo->getX(), inimigo->getY(), 0, true)) {
			
			jogador->matarTiro();
			inimigo->morreu();
			somExplo.tocar();
			pontos += 100;
			posY = (rand() % 500)+100;
			testeColi = true;
			
		}
		if (uniTestarColisaoSpriteComSprite(jogador->getSprite(), jogador->getX(), jogador->getY(), 0, inimigo->getSprite(), inimigo->getX(), inimigo->getY(), 0, true)) {
			jogador->getMorreu();
			inimigo->morreu();
			MenuStack.push(FINAL);
		}
	
	
	jogador->desenhar();
	jogador->atualizar();
	jogador->animar();
	
	
	if (testeColi == false) {
		inimigo->desenhar(300);
	}
		
		
	
	if (testeColi == true) {
		
    inimigo->desenhar(posY);
	
	
	}
	
	
	if (!inimigo->getVivo()) {
		
		inimigo->reset();
		
	}
	
	

	string txt = "Pontos: " + to_string(pontos);
	gGraficos.desenharTexto(txt, 100, 80, 255, 255, 255, 255, 0, 0);
	if (gTeclado.pressionou[TECLA_1]) {
		MenuStack.pop();
	}
	
}

void Menus::atualizar_leadboard()
{
	jogador->getPontuacao() == recorde;
	string txt = "Pontuacao: " + to_string (jogador->getPontuacao());
	gGraficos.desenharTexto(txt, gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	bVoltar.desenhar();
	bVoltar.atualizar();
	if (bVoltar.estaClicado()) {
		MenuStack.pop();
	}
}

void Menus::atualizar_credits()
{
	txtCreditos.desenhar(gJanela.getLargura() / 2, 200, 0);
	bVoltar.desenhar();
	bVoltar.atualizar();
	if (bVoltar.estaClicado()) {
		MenuStack.pop();
	}
}

void Menus::atualizar_final()
{
	gMouse.mostrarCursor();
	fundoFinal.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	if (pontos > recorde) {
		recorde = pontos;
	}
	string txt1 = "Recorde: " + to_string(recorde);
	string txt = "Pontuacao: " + to_string(pontos);
	
	gGraficos.desenharTexto(txt1, gJanela.getLargura() / 2, 290);
	gGraficos.desenharTexto(txt, gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	bVoltar.desenhar();
	bVoltar.atualizar();
	if (bVoltar.estaClicado()) {
		MenuStack.pop();
		MenuStack.pop();
	}
}

void Menus::atualizar_login()
{
}

void Menus::atualizar_cadastro()
{
}

void Menus::atualizar_logar()
{
}

void Menus::setSpriteSheet(string spritesheet)
{
	spr.setSpriteSheet(spritesheet);
}

bool Menus::getSair()
{
	return sair;
}

void Menus::finalizar()
{
	f_mapa_assets.close();
}

void Menus::resetGame()
{
	pontos = 0;
	jogador->reset();
	
	inimigo->reset();
}


