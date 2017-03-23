// Sistema de Tempo Real
//Unviversidade Federal do Rio Grande do Norte
//Departamento de Engenharia de Computação e Automação
//Alunos: Carlos Gabriel Gomes de Melo Silva
//        Felipe Fernandes Lopes
//        Philipy Augusto Silveira de Brito

#include <iostream>
#include <stdlib.h>
#include <time.h>  
#include <cstdlib>

using namespace std;

void imprime(int* v, int t){
	for(int i = 0; i < (t-t/2); i++){
		cout << v[i] << " ";
	}
}

void bubbleSort(int* vetor, int tamanho){
	int auxiliar;
	for(int i = 0; i < tamanho; i++){
		for(int j = 0; j < tamanho; j++){
			if(vetor[j] > vetor[j+1]){
				auxiliar = vetor[j];
				vetor[j] = vetor[j+1];
				vetor[j+1] = auxiliar;
			}
		}
	}
}

//Função usada pelo qsort para comparar dois numeros
int compare(const void* a, const void* b) {
	int* arg1 = (int*) a;
	int* arg2 = (int*) b;
	if(*arg1 < *arg2) return -1;
	else if( *arg1 == *arg2 ) return 0;
	else return 1;
}


int main(){
	int tamanho1 = 1000, tamanho2 = 10000, tamanho3 = 100000; 
	int vetorBS1[tamanho1], vetorQS1[tamanho1], 
		vetorBS2[tamanho2], vetorQS2[tamanho2], 
		vetorBS3[tamanho3], vetorQS3[tamanho3];
	time_t tempoIBS1, tempoIBS2, tempoIBS3,
		   tempoFBS1, tempoFBS2, tempoFBS3,
		   tempoIQS1, tempoIQS2, tempoIQS3,
		   tempoFQS1, tempoFQS2, tempoFQS3,
		   tempoReal;

	//preenche os vetores com valores aleatorios
	srand (time(NULL));
	for(int i = 0; i < tamanho1; i++){
		vetorBS1[i] = rand()%100000;
		vetorQS1[i] = vetorBS1[i];
	}
	for(int i = 0; i < tamanho2; i++){
		vetorBS2[i] = rand()%100000;
		vetorQS2[i] = vetorBS2[i];
	}
	for(int i = 0; i < tamanho3; i++){
		vetorBS3[i] = rand()%100000;
		vetorQS3[i] = vetorBS3[i];
	}

	//CODIGO QUE IMPRIME OS VETORES
	/*
	cout << endl;
	imprime(vetorBS1, tamanho1);
	cout << endl;

	cout << endl;
	imprime(vetorQS1, tamanho2);
	cout << endl;
	*/
	//FIM

	cout << "Aperte 'ENTER' para calcular tempo com tamanho " << tamanho1 << endl; 
	getchar();
	tempoIBS1 = time( (time_t *) 0);
	//Argumentos: (vetor, tamanho)
	bubbleSort(vetorBS1, tamanho1);
	tempoFBS1 = time( (time_t *) 0);
	tempoReal = tempoFBS1 - tempoIBS1;

	cout << "O tempo final para vetor de tamanho " << tamanho1 << " com BS eh: " << tempoReal << endl;

	tempoIQS1 = time( (time_t *) 0); 
	//Argumentos: (vetor, tamanho, tamanho do tipo de cada elemento, valor compare)
	qsort(vetorQS1, tamanho1, sizeof(int), compare);
	tempoFQS1 = time( (time_t *) 0); 
	tempoReal = tempoFQS1 - tempoIQS1;

	cout << "O tempo final para vetor de tamanho " << tamanho1 << " com QS eh: " << tempoReal << endl;

	cout << endl;
	
	cout << "Aperte 'ENTER' para calcular tempo com tamanho " << tamanho2 << endl;
	getchar();
	tempoIBS2 = time( (time_t *) 0); 
	bubbleSort(vetorBS2, tamanho2);
	tempoFBS2 = time( (time_t *) 0); 
	tempoReal = tempoFBS2 - tempoIBS2;

	cout << "O tempo final para vetor de tamanho " << tamanho2 << " com BS eh: " << tempoReal << endl;

	tempoIQS2 = time( (time_t *) 0); 
	qsort(vetorQS2, tamanho2, sizeof(int), compare);
	tempoFQS2 = time( (time_t *) 0); 
	tempoReal = tempoIQS2 - tempoFQS2;

	cout << "O tempo final para vetor de tamanho " << tamanho2 << " com QS eh: " << tempoReal << endl;

	cout << endl;

	cout << "Aperte 'ENTER' para calcular tempo com tamanho " << tamanho3 << endl;
	getchar();
	tempoIBS3 = time( (time_t *) 0); 
	bubbleSort(vetorBS3, tamanho3);
	tempoFBS3 = time( (time_t *) 0);
	tempoReal = tempoFBS3 - tempoIBS3;

	cout << "O tempo final para vetor de tamanho " << tamanho3 << " com BS eh: " << tempoReal << endl;


	tempoIQS3 = time( (time_t *) 0); 
	qsort(vetorQS3, tamanho3, sizeof(int), compare);
	tempoFQS3 = time( (time_t *) 0);
	tempoReal = tempoFQS3 - tempoIQS3;

	cout << "O tempo final para vetor de tamanho " << tamanho3 << " com QS eh: " << tempoReal << endl;

	return 0;
}