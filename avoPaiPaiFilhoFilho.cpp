//Sistema de Tempo Real
//Unviversidade Federal do Rio Grande do Norte
//Departamento de Engenharia de Computação e Automação
//Alunos: Carlos Gabriel Gomes de Melo Silva
//        Felipe Fernandes Lopes
//        Philipy Augusto Silveira de Brito

//PROGRAMA QUE CRIA UM PROCESSO AVÔ, 2 PAIS E 2 FILHOS PARA CADA PAI

#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

using namespace std;

int main(){
	pid_t pid1, pid2, pid3, pid4, pid5, pid6;

	pid1 = fork();
		if(pid1 == -1){
			exit(1);
		}else if(pid1 == 0){
			pid3 = fork();
			if(pid3 == -1){
				exit(1);
			}else if(pid3 == 0){
				while(1){
					cout << "neto 1.1: " << getpid() << endl;
					sleep(1);
				}
			}else{
				pid4 = fork();
				if(pid4 == -1){
					exit(1);
				}else if(pid4 == 0){
					while(1){
						cout << "neto 1.2: " << getpid() << endl;
						sleep(1);
					}
 				}
			}
			while(1){
				cout << "Pai 1: " << getpid() << endl;
				sleep(1);
			}

		}else{
			pid2 = fork();
				if(pid2 == -1){
					exit(1);
				}else if(pid2 == 0){
					pid5 = fork();
					if(pid5 == -1){
						exit(1);
					}else if(pid5 == 0){
						while(1){
							cout << "Neto 2.1: " << getpid() << endl;
							sleep(1);
						}
					}else{
						pid6 = fork();
						if(pid6 == -1){
							exit(1);
						}else if(pid6 == 0){
							while(1){
								cout << "Neto 2.2: " << getpid() << endl;
								sleep(1);
							}
						}
					}
					while(1){
						cout << "Pai 2: " << getpid() << endl;
						sleep(1);
					}
				}else{
					while(1){
						cout << "Avo: " << getpid() << endl;
						sleep(1);
					}
				}
		}
	return 0;
}	