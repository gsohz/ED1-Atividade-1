#include <iostream>
#include <stdlib.h>
#include <ostream>
#include <fstream>
#include <iomanip>
using namespace std;

#define LIN 16
#define COL 41


void menu(){
	
	cout << "0.      Finalizar"         << endl 
		 << "1.      Reservar poltrona" << endl 
		 << "2.      Mapa de ocupação"  << endl 
		 << "3.      Faturamento" 		<< endl << endl;
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
			if(i == 0 || j == 0){
				chairs[i][j] = 'X';
			} else chairs[i][j] = '.';
		}
	}
	


	
	menu();
	cin >> key;
	do {
		switch (key){
			
		case 0:
			cout << endl << "Finalizado";
			break;
		
		case 1:
			cout << endl << "Indique a coluna desejada (1 - 40): " ;
			cin >> column;
			cout << endl << "Indique a linha desejada (1-15): " ;
			cin >> line;
			//Reservar
			
			if(column == 0 || line == 0){
				cout << endl << "Insira um valor diferente de 0 para linha e coluna." << endl << endl;
			} else if(chairs[line][column] == '#'){
				cout << endl << "A cadeira " << line << " - " <<column << " já está ocupada, tente outra." << endl << endl;
			} else{
				cout << endl << "A cadeira " << line << " - " <<column << " foi reservada." << endl << endl;
	   	   	   	chairs[line][column] = '#';
			}


			//menu
			menu();	
			cin >> key;
			
			break;
		
		case 2:
			for(int i = 0; i < LIN; ++i){
				for(int j = 0; j < COL; ++j){
					cout << chairs[i][j] << "|";
					if(j == 40){
						cout << endl;
					}
				}
			}
			
			//menu
			menu();	
			cin >> key;
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
			menu();	
			cin >> key;
			break;
	}

	} while(key != 0);
	
	 
		 
	return 0;
}