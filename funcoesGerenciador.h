#ifndef FUNCOESGERENCIADOR_H
#define FUNCOESGERENCIADOR_H

class FuncoesGerenciador{
	public:
		void mataProcesso(string pid);
		void pausarProcesso(string pid);
		void continuarProcesso(string pid);
		void filtrarProcesso(string nomeProcesso);
};

#endif // FUNCOESGERENCIADOR_H