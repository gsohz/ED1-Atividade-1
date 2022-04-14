#include <iostream>
#include <stdlib.h>
#include <ostream>
#include <fstream>
#include <iomanip>
using namespace std;

#define LIN 15
#define COL 40

//função menu retornando valor da escolha
int menu(){
	int key;
	
	cout << "0.      Finalizar"         << endl 
		 << "1.      Reservar poltrona" << endl 
		 << "2.      Mapa de ocupação"  << endl 
		 << "3.      Faturamento" 		<< endl << endl;

 	 cin >> key;
 	 
 	 return key;
}


int main(int argc, char** argv){
	//variáveis
	int key;
	int column;
	int line;
	
	setlocale(LC_ALL, "");
	
	//Criar Arrays
	char **chairs;
	
	chairs = new char*[LIN];
	
	for(int i = 0; i < LIN; ++i){
		chairs[i] = new char [COL];
	}
	
 	//Preencher Arrays
		 
	for(int i = 0; i < LIN; ++i){
		for(int j = 0; j < COL; ++j){
			chairs[i][j] = '.';
		}
	}
	
	key = menu(); //armazenar a função na variável

	while(key != 0) {
		switch (key){
		case 0:
			cout << endl << "Finalizado";
			break;
		
		case 1:
			cout << endl << "Indique a coluna desejada (1 - 40): " ;
			cin >> column;
			cout << endl << "Indique a linha desejada (1-15): " ;
			cin >> line;
			
			//ajustar a escolha do número ao index do array (a partir de 0)
			column -= 1;
			line -= 1;
			
			while((column > 40 - 1 || column < 1 - 1) || (line > 15 - 1 || line < 1 - 1)){
				cout << endl << "Insira um número válido para coluna e linha." << endl;
	   	   	   	cout << endl << "Indique a coluna desejada (1 - 40): " ;
				cin >> column;
				cout << endl << "Indique a linha desejada (1-15): " ;
				cin >> line;
			}
			
			//Reservar
			if(chairs[line][column] == '#'){
				cout << endl << "A cadeira " << line + 1 << " - " << column + 1 
					 << " já está ocupada, tente outra." << endl << endl;
			} else{
				cout << endl << "A cadeira " << line + 1 << " - " << column + 1 
					 << " foi reservada." << endl << endl;
	   	   	   	chairs[line][column] = '#';
			}


			//menu
			key = menu();
			break;
		
		case 2:
			for(int i = 0; i < LIN; ++i){
				for(int j = 0; j < COL; ++j){
					cout << chairs[i][j] << "|";
					if(j == 40 - 1){
						cout << endl;
					}
				}
			}
			
			//menu
			key = menu();
			break;
		
		case 3:
				
			int qtd = 0;
			for(int i = 0; i < LIN; ++i){
				for(int j = 0; j < COL; ++j){
					if(chairs[i][j] == '#'){
						++qtd;
					}
				}
			}
				
			cout << endl << "Quantidade de lugares ocupados: " << qtd;
			
			int val = 0;
			
			for(int i = 0; i < LIN; ++i){
				for(int j = 0; j < COL; ++j){
					if(chairs[i][j] == '#'){
			      		if(i <= 5){
							val += 50;
						} else if (i >= 6 && i <= 10){
							val += 30;
						} else val += 15;
					}
				}
			}

			cout << endl << "Valor da bilheteria: " << val << endl << endl;
			
	   	   	//menu
			key = menu();
			break;
		}
	}
		 
	return 0;
}