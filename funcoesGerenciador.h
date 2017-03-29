//Sistema de Tempo Real
//Unviversidade Federal do Rio Grande do Norte
//Departamento de Engenharia de Computação e Automação
//Alunos: Carlos Gabriel Gomes de Melo Silva
//        Felipe Fernandes Lopes
//        Philipy Augusto Silveira de Brito

//FUNÇÕES COMPLEMENTARES PARA GERENCIADOR DE TAREFAS

#ifndef FUNCOESGERENCIADOR_H
#define FUNCOESGERENCIADOR_H
#include <string>
#include <string.h>
using namespace std;

class FuncoesGerenciador{
	public:
		void mataProcesso(string pid);
		void pausarProcesso(string pid);
		void continuarProcesso(string pid);
		void filtrarProcesso(string nomeProcesso);
};

#endif // FUNCOESGERENCIADOR_H