#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <time.h>

using namespace std;

#define CARTAS 		52
#define BARALHO 	2
#define JOGADORES 	4
#define MAO			11

	
int main(int argc, char** argv)
{
	
	int i;
	int j;
	int **br;
	int **mao;
 
    //criar array de baralhos
	br = new int*[BARALHO];
    
    for(i = 0; i < BARALHO; ++i){
        br[i] = new int[CARTAS];
    }
	    
 	
    int k = 0;
    //preencher cartas no array
    for(i = 0; i < BARALHO; ++i){
    	if(i == 0){
			k = 1001;	
		} else if(i == 1){
			k = 1002;
		}
		for(j = 0; j < CARTAS; ++j){
			
			if(k > 1130 && k < 1133){
				k -= 130;
				k += 1000;
			} else if (k > 2130 && k < 2133){
				k -= 130;
				k += 1000;					
			} else if (k > 3130 && k <3133){
				k -= 130;
				k += 1000;					
			} else if(k > 4130 && k <4133){
				k -= 130;
				k += 1000;					
			}
			
			k += 10;
			
			br[i][j] = k;	 				
		}
		
    }
    
    //criar array de mãos
 	mao = new int*[JOGADORES];
 	
 	for(i = 0; i < JOGADORES; ++i){
		 mao[i] = new int[MAO];
	}
	
	//variáveis para controlar aleatoriedade
	int minB = 0;
	int maxB = 1;
	int minC = 0;
	int maxC = 51;
	int r	 = 0;
	
	//variáveis para receber cartas aleatórias
	int baralhoCarta;
	int numeroCarta;
	int x;
	int y;
	
	//definir variável aleatoriedade
	srand(time(NULL));
	r = rand();
	
	//preencher mãos
	for(i = 0; i < JOGADORES; ++i){
		
		cout << "Mao " << i << ": " << endl;
		for(j = 0; j < MAO; ++j){
			//criar outra seed para garantir que todos os números sejam aleatórios
			srand(++r * rand());
			
			baralhoCarta = (rand() % (maxB - minB + 1)) + minB;

			numeroCarta = (rand() % (maxC - minC + 1)) + minC;
			
			

			//selecionar apenas cartas disponíveis
			for(x = 0; x < i; ++x){
				for(y = x + 1; y < j; ++y){
					if(mao[x][y] == br[baralhoCarta][numeroCarta]){
						do{
							baralhoCarta = (rand() % (maxB - minB)) + minB;
							numeroCarta = (rand() % (maxC - minC)) + minC;
						} while(mao[x][y] == br[baralhoCarta][numeroCarta]);
					}
				}
			}

			//atribuir a carta a mão do jogador
			mao[i][j] = br[baralhoCarta][numeroCarta];
			
			
			cout << mao[i][j] << endl;
		}
		cout << endl;
	}
		
	    
	    


    
    return 0;
}