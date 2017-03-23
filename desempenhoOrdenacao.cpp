//Sistema de Tempo Real
//Unviversidade Federal do Rio Grande do Norte
//Departamento de Engenharia de Computação e Automação
//Alunos: Carlos Gabriel Gomes de Melo Silva
//        Felipe Fernandes Lopes
//        Philipy Augusto Silveira de Brito

//PRGRAMA QUE CALCULA A DIFERENÇA DE TEMPO DE ORDENAÇÃO ENTRE BUBBLESORT E QUICKSORT

#include <iostream>
#include <stdlib.h>
#include <time.h>  
#include <cstdlib>

#define TAMANHO1 1000
#define TAMANHO2 10000
#define TAMANHO3 100000

using namespace std;

int *vetorBS, *vetorQS;

void imprime(int* v, int t){
	for(int i = 0; i < 20; i++){
		cout << v[i] << " ";
	}
}

void criarVetor(int tamanhoVetor){
	srand (time(NULL));
	vetorBS = new int[tamanhoVetor];
	vetorQS = new int[tamanhoVetor];
	for (int i=0;i<tamanhoVetor;i++){
		vetorBS[i] =  rand()%100000;
        vetorQS[i] = vetorBS[i]; //Cria vetores com os mesmos numeros
	}
}

void bubbleSort(int* vetor, int tamanho){
	int auxiliar;
	for(int i = 0; i < tamanho - 1; i++){
		for(int j = 0; j < tamanho - 1; j++){
			if(vetor[j] > vetor[j+1]){
				auxiliar = vetor[j];
				vetor[j] = vetor[j+1];
				vetor[j+1] = auxiliar;
			}
		}
	}
}

//Função usada pelo qsort para comparar dois numeros
int compare( const void* a, const void* b ){
	int* arg1 = (int*) a;
	int* arg2 = (int*) b;
	if( *arg1 < *arg2 ){
		return -1;
	}
	else if( *arg1 == *arg2 ){
		return 0;
	}
	else{
		return 1;
	}
}


int main(){
	time_t tempoInicial, tempoFinal;
	clock_t clockInicial, clockFinal;
	double tempoReal, clockReal;

	cout << "Aperte 'ENTER' para calcular tempo com tamanho " << TAMANHO1 << endl; 
	criarVetor(TAMANHO1);
	getchar();
	tempoInicial = time( (time_t *) 0);
	clockInicial = clock();
	//Argumentos: (vetor, tamanho)
	bubbleSort(vetorBS, TAMANHO1);
	clockFinal = clock();
	tempoFinal = time( (time_t *) 0);
	clockReal = (double)(clockFinal - clockInicial)/(double)(CLOCKS_PER_SEC);
	tempoReal = tempoFinal - tempoInicial;

	cout << "Tempo de Relógio (Segundos) de tamanho " << TAMANHO1 << " com BS eh: " << tempoReal << endl;
	cout << "Tempo de utilização de CPU (Segundos) de tamanho " << TAMANHO1 << " com BS eh: " << clockReal << endl;

	tempoInicial = time( (time_t *) 0);
	clockInicial = clock();
	//Argumentos: (vetor, tamanho, tamanho do tipo de cada elemento, valor compare)
	qsort(vetorQS, TAMANHO1, sizeof(int), compare);
	clockFinal = clock();
	tempoFinal = time( (time_t *) 0);
	clockReal = (double)(clockFinal - clockInicial)/(double)(CLOCKS_PER_SEC);
	tempoReal = tempoFinal - tempoInicial;

	cout << "Tempo de Relógio (Segundos) de tamanho " << TAMANHO1 << " com QS eh: " << tempoReal << endl;
	cout << "Tempo de utilização de CPU (Segundos) de tamanho " << TAMANHO1 << " com QS eh: " << clockReal << endl;

	cout << endl;
	
	delete vetorBS, vetorQS;

	cout << "Aperte 'ENTER' para calcular tempo com tamanho " << TAMANHO2 << endl;
	criarVetor(TAMANHO2);
	getchar();
	tempoInicial = time( (time_t *) 0);
	clockInicial = clock();
	bubbleSort(vetorBS, TAMANHO2);
	clockFinal = clock();
	tempoFinal = time( (time_t *) 0);
	clockReal = (double)(clockFinal - clockInicial)/(double)(CLOCKS_PER_SEC);
	tempoReal = tempoFinal - tempoInicial;

	cout << "Tempo de Relógio (Segundos) de tamanho " << TAMANHO2 << " com BS eh: " << tempoReal << endl;
	cout << "Tempo de utilização de CPU (Segundos) de tamanho " << TAMANHO2 << " com BS eh: " << clockReal << endl;

	tempoInicial = time( (time_t *) 0);
	clockInicial = clock();
	qsort(vetorQS, TAMANHO2, sizeof(int), compare);
	clockFinal = clock();
	tempoFinal = time( (time_t *) 0);
	clockReal = (double)(clockFinal - clockInicial)/(double)(CLOCKS_PER_SEC);
	tempoReal = tempoInicial - tempoFinal;

	cout << "Tempo de Relógio (Segundos) de tamanho " << TAMANHO2 << " com QS eh: " << tempoReal << endl;
	cout << "Tempo de utilização de CPU (Segundos) de tamanho " << TAMANHO2 << " com QS eh: " << clockReal << endl;

	cout << endl;

	delete vetorBS, vetorQS;

	cout << "Aperte 'ENTER' para calcular tempo com tamanho " << TAMANHO3 << endl;
	criarVetor(TAMANHO3);
	getchar();
	tempoInicial = time( (time_t *) 0);
	clockInicial = clock();
	bubbleSort(vetorBS, TAMANHO3);
	clockFinal = clock();
	tempoFinal = time( (time_t *) 0);
	clockReal = (double)(clockFinal - clockInicial)/(double)(CLOCKS_PER_SEC);
	tempoReal = tempoFinal - tempoInicial;

	cout << "Tempo de Relógio (Segundos) de tamanho " << TAMANHO3 << " com BS eh: " << tempoReal << endl;
	cout << "Tempo de utilização de CPU (Segundos) de tamanho " << TAMANHO3 << " com BS eh: " << clockReal << endl;

	tempoInicial = time( (time_t *) 0);
	clockInicial = clock();
	qsort(vetorQS, TAMANHO3, sizeof(int), compare);
	clockFinal = clock();
	tempoFinal = time( (time_t *) 0);
	clockReal = (double)(clockFinal - clockInicial)/(double)(CLOCKS_PER_SEC);
	tempoReal = tempoFinal - tempoInicial;

	cout << "Tempo de Relógio (Segundos) de tamanho " << TAMANHO3 << " com QS eh: " << tempoReal << endl;
	cout << "Tempo de utilização de CPU (Segundos) de tamanho " << TAMANHO3 << " com QS eh: " << clockReal << endl;

	return 0;
}