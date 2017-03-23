// Sistema de Tempo Real
//Unviversidade Federal do Rio Grande do Norte
//Departamento de Engenharia de Computação e Automação
//Alunos: Carlos Gabriel Gomes de Melo Silva
//        Felipe Fernandes Lopes
//        Philipy Augusto Silveira de Brito

//PROGRAMA QUE CALCULA A QUANTIDADE DE SEGUNDOS DESDE O NASCIMENTO ATE HOJE

#include <iostream>
#include <unistd.h>
#include <time.h>
#include <stdio.h>

using namespace std;

int main(){

	//DECLARACAO DE VARIAVEIS
	int dia, mes, ano, hora, minuto;
	char opcao[1];

	cout << "Digite uma data de nascimento: " << endl;
	sleep(1);

	//RECE O DIA DO NASCIMENTO
	cout << "Dia - dd: ";
	cin >> dia;
	//VERIFICA SE O DIA É VÁLIDO (01 - 31)
	while(dia < 1 || dia > 31){
		cout << "Digite um dia valido (01 - 31): ";
		cin >> dia;
	}

	//RECEBE O MES DO NASCIMENTO
	cout << "Mes - mm: ";
	cin >> mes;
	//VERIFICA SE O MES É VÁLIDO (01 - 12)
	while(mes < 0 || mes > 12){
		cout << "Digite um mes valido (01 - 12): ";
		cin >> mes;
	}

	//RECEBE O ANO DE NASCIMENTO
	cout << "Ano - aaaa (a partir de 1970): ";
	cin >> ano;

	//RECUPERA ANO ATUAL
   	int anoAtual;
   	struct tm *timeLocal;
   	time_t t;

   	t = time(NULL);
   	timeLocal = localtime(&t);
   	anoAtual = timeLocal->tm_year + 1900;
	//FIM

   	//VERIFICA SE O ANO NASCIMENTO É VÁLIDO (1970 - anoAtual)
	while(ano < 1970 || ano > anoAtual){
		cout << "Digite um ano valido (1970 - " << anoAtual << "): ";
		cin >> ano; 
	}

	//RECEBE HORAS E MINUTOS DO NASCIMENTO
	cout << "Deseja digitar a hora do nascimento? s/n: ";
	cin >> opcao;
	if(opcao[0] == 's'){
		cout << "Hora: ";
		cin >> hora;
		cout << "Minutos: ";
		cin >> minuto;
	}else{
		hora = 0, minuto = 0;
	}

	cout << "Ok! estamos calculando o tempo vivido... " << endl;
	cout << "Aguarde..." << endl;
	sleep(3);

	//DECLARACAO DE VARIÁVEIS PARA CALCULAR O TEMPO VIVIDO
	time_t tempoAtual;
  	struct tm dataNascimento = {0};
  	double segundos;

  	//DEFINE AS VARIÁVEIS DA STRUCT tm
  	dataNascimento.tm_hour = hora;   dataNascimento.tm_min = minuto; dataNascimento.tm_sec = 0;
  	dataNascimento.tm_year = ano - 1900; dataNascimento.tm_mon = mes - 1; dataNascimento.tm_mday = dia;

  	//RECUPERA O TEMPO EM SEGUDOS DE 1970 ATÉ HOJE
 	time(&tempoAtual);

 	//CALCULA A DIFERENÇA DO TEMPO EM SEGUNDOS DA DATA DIGITADA PELO USUÁRIO COM RELAÇÃO A DATA DE HOJE
  	segundos = difftime(tempoAtual,mktime(&dataNascimento));

  	//IMPRIME A QUANTIDADE DE SEGUNDOS
  	cout << "A quantidade de segundos vivida de: " << dataNascimento.tm_mday << "/" << dataNascimento.tm_mon + 1 << "/" 
  	<< dataNascimento.tm_year + 1900 << " das " << dataNascimento.tm_hour << "h e " << dataNascimento.tm_min << "min " 
  	<< "ate hoje eh: " << segundos << endl;

	return 0;	
}
