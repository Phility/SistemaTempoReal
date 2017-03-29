//Sistema de Tempo Real
//Unviversidade Federal do Rio Grande do Norte
//Departamento de Engenharia de Computação e Automação
//Alunos: Carlos Gabriel Gomes de Melo Silva
//        Felipe Fernandes Lopes
//        Philipy Augusto Silveira de Brito

//FUNÇÕES COMPLEMENTARES PARA GERENCIADOR DE TAREFAS

#include "funcoesGerenciador.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
using namespace std;

void FuncoesGerenciador::mataProcesso(string pid){
	string matar ("kill -9 "); // Cria string com "kill " dentro dela
	matar += pid; //concatena a string com o pid informado pelo usuário
	const char * matarProcesso = matar.c_str(); //converte uma string em char
	system(matarProcesso);
	system("ps -eo pid,user,s,pri,ni,size,pcpu,pmem,comm > processos.txt"); //Da um ps no sistema limitando as informações de retorno e salva em um arquivo txt processos
}	

void FuncoesGerenciador::pausarProcesso(string pid){
	string stop ("kill -stop ");
	stop += pid;
	const char * pausarProcesso = stop.c_str();
	system(pausarProcesso);
	system("ps -eo pid,user,s,pri,ni,size,pcpu,pmem,comm > processos.txt");
}

void FuncoesGerenciador::continuarProcesso(string pid){
	string continua ("kill -cont ");
	continua += pid;
	const char * continuarProcesso = continua.c_str();
	system(continuarProcesso);
	system("ps -eo pid,user,s,pri,ni,size,pcpu,pmem,comm > processos.txt");
}

void FuncoesGerenciador::filtrarProcesso(string nomeProcesso){
	string filtra ("ps -eo pid,user,s,pri,ni,size,pcpu,pmem,comm | grep ");
	filtra += nomeProcesso;
	filtra += (" > processos.txt");
	const char * filtrarProcesso = filtra.c_str();
	system(filtrarProcesso);
}

/*int main(){
	string pid ("");
	string nomeProcesso ("");

	cout << "PID Matar: ";
	cin >> pid;
	mataProcesso(pid);
	

	cout << "PID stop: ";
	cin >> pid;
	pausarProcesso(pid);
	
	cout << "PID continua: ";
	cin >> pid;
	continuarProcesso(pid);

	cout << "Filtrar processo: ";
	cin >> nomeProcesso;
	filtrarProcesso(nomeProcesso);

	return 0;
}*/