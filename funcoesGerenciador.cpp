//Sistema de Tempo Real
//Unviversidade Federal do Rio Grande do Norte
//Departamento de Engenharia de Computação e Automação
//Alunos: Carlos Gabriel Gomes de Melo Silva
//        Felipe Fernandes Lopes
//        Philipy Augusto Silveira de Brito

//FUNÇÕES COMPLEMENTARES PARA GERENCIADOR DE TAREFAS

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
using namespace std;

string mataProcesso(string pid){
	string matar ("kill "); // Cria string com "kill " dentro dela
	matar += pid; //concatena a string com o pid informado pelo usuário
	return matar;
}	

string pausarProcesso(string pid){
	string stop ("kill -stop ");
	stop += pid;
	return stop;
}

string continuarProcesso(string pid){
	string continua ("kill -cont ");
	continua += pid;
	return continua;
}

int main(){
	string pid ("");

	cout << "PID Matar: ";
	cin >> pid;
	const char * matar = mataProcesso(pid).c_str(); //converte uma string em char
	system(matar);

	cout << "PID stop: ";
	cin >> pid;
	const char * stop = pausarProcesso(pid).c_str();
	system(stop);

	cout << "PID continua: ";
	cin >> pid;
	const char * continua = continuarProcesso(pid).c_str();
	system(continua);

	return 0;
}