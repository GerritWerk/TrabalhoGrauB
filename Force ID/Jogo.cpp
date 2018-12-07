#include "Jogo.h"

Jogo::Jogo()
{
	
	
}

Jogo::~Jogo()
{
}

void Jogo::inicializar()
{
	uniInicializar(800, 600, false);
	

	menu.inicializar_asset();
}

void Jogo::finalizar()
{
	gRecursos.descarregarTudo();
	menu.finalizar();
	uniFinalizar();
}



void Jogo::executar()
{
	while(!gTeclado.soltou[TECLA_ESC] && !gEventos.sair && menu.getSair())
	{
		uniIniciarFrame();
		menu.atualizarTelaAtual();
		menu.finalizar();
		
			
			
		
		
		
		

		uniTerminarFrame();
	}
}