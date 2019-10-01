#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//jogo 2048
//peças de numeros iguais se combinam e somam
// somente numeros pares serão considerados
// 2 + 2 = 4
// 4 + 4 = 8
// ...
// 1024 + 1024 = 2048.
// se uma das peças atingir 2048, o jogo acaba.

#define N 3


void geraTabuleiroAleatorio (int v[N][N]) {
	srand((unsigned)time(NULL));
	int i, j;
	int linha;
	int coluna;

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			v[i][j] = 0;
		}
	}

	j = 2;
	for (i = 0; i < 2; i++) {
		linha = rand () % 3;
		coluna = rand () % 3;
		v[linha][coluna] = j;
		j+2;
	}
}

void mostraTabuleiro (int v[N][N]) {
	int i,j;
	for (i = 0; i < N; i++) {
		for ( j = 0; j < N; j++) {
			printf("%d   ", v[i][j]);
		}
		printf("\n");
		printf("\n");
	}
}

int geraPeca (int tabuleiro[N][N]) {
	int linha, coluna, i, j = 2;
	linha = (rand () % 10)/2;
	coluna = (rand () % 10)/2;
	if (tabuleiro[linha][coluna] == 0) {
		tabuleiro[linha][coluna] = j;
	}
	else {
		geraPeca(tabuleiro);
	}
}

void movimentoCima (int jogo[N][N]) 
{
	int j;

	for (j = 0; j < N; j++) 
	{
		//
		if (jogo[0][j] != 0 &&
			jogo[1][j] == 0 &&
			jogo[2][j] == 0){

			jogo[1][j] ==0;
		
		}
		
		else if (jogo[0][j] == 0 &&
			jogo[1][j] != 0 &&
			jogo[2][j] == 0)
		{ 

			jogo[0][j] = jogo[1][j];
			jogo[1][j] = 0; 

		}	
		else if (jogo[0][j] == 0 &&
				jogo[1][j] == 0 &&
				jogo[2][j] != 0) 
		{

			jogo[0][j] = jogo[2][j];
			jogo[2][j] = 0;
		}
		//

		//
		 else if (jogo[0][j] == 0 &&
				jogo[1][j] != 0 &&
				jogo[2][j] != 0) 
		{
			if (jogo[1][j] == jogo[2][j]) {

				jogo[0][j] = jogo[1][j] + jogo[2][j];
				jogo[1][j] = 0;
				jogo[2][j] = 0;

			}
			else {

				jogo[0][j] = jogo[1][j];
				jogo[1][j] = jogo[2][j];
				jogo[2][j] = 0;

			}
		}
		else if (jogo[0][j] != 0 &&
				jogo[1][j] != 0 &&
				jogo[2][j] == 0) 
		{
			if(jogo[0][j] == jogo[1][j]) {

				jogo[0][j] = jogo[0][j] + jogo[1][j];
				jogo[1][j] = 0;
			}
		}
		else if (jogo[0][j] != 0 &&
				jogo[1][j] == 0 &&
				jogo[2][j] != 0)
		{

			if (jogo[0][j] == jogo[2][j]){
				jogo[0][j] = jogo[0][j] + jogo[2][j];
				jogo[2][j] = 0;
			}
			else {
				jogo[1][j] = jogo[2][j];
				jogo[2][j] = 0;
			}

		}
		//

		//
		else if (jogo[0][j] != 0 &&
				jogo[1][j] != 0 &&
				jogo[2][j] != 0)
		{
			if (jogo[0][j] == jogo[1][j]) {

				jogo[0][j] = jogo[0][j] + jogo[1][j];
				jogo[1][j] = jogo[2][j];
				jogo[2][j] = 0;

			}
			else if (jogo[1][j] == jogo[2][j]) {
				jogo[1][j] = jogo[1][j] + jogo[2][j];
				jogo[2][j] = 0;
			}
		}
		//
	}
}

void recebeComando (int tabuleiro[N][N]) {
	char x;
	scanf("%s", &x);
	if (x == 'w' || x == 'W') {
		movimentoCima(tabuleiro);
		system("clear");
		printf("Last Move: Up\n");
	}
	else if (x == 'a' || x == 'A') {
		//movimentoEsquerda();
		system("clear");
		printf("Last Move: Left\n");
	}
	else if (x == 'd' || x == 'D') {
		//movimentoDireita(tabuleiro);
		system("clear");
		printf("Last Move: Right\n");
	}
	else if (x == 's' || x == 'S') {
		//movimentoBaixo();
		system("clear");
		printf("Last Move: Down\n");
	}
	else{
		system("clear");
		printf("Movimento não válido, repita... \n");
		mostraTabuleiro(tabuleiro);
		recebeComando(tabuleiro);
	}
}

int verificaJogo (int jogo[N][N]) {
	int i, j ,count;
	for(i = 0; i < N; i++) {  
		for(j = 0; j < N; j++){ 
			if (jogo[i][j]==16) {
				printf("Parabéns! Você venceu. \n");
				return 1;
			}
			if (jogo[i][j] == 0) {
				count++;
			}
		}
	}

	if (count == 0) {
		for (i = 0; i < N; i++){
			for (j = 0; j < N; ++j){
				if (j==0) {
					if (jogo[i][j] == jogo[i][j+1]) {
						return 0;
					}
					if (i == 0 || i == 1) {
						if (jogo[i][j] == jogo[i+1][j]) {
							return 0;
						}
					}
				}

				if (j==1) {
					if (i == 0 || i == 1) {
						if (jogo[i][j] == jogo[i+1][j]) {
							return 0;
						}
					}
					if (jogo[i][j] == jogo[i][j+1]) {
						return 0;
					}
				}

				if (j==2) {
					if(jogo[i][j] == jogo[i+1][j]) {
						return 0;
					}
				}
			}
		}
	}
	
}


int main () {
	system("clear");
	int tabuleiro [N][N];
	geraTabuleiroAleatorio(tabuleiro);
	mostraTabuleiro(tabuleiro);
	while(verificaJogo(tabuleiro) != 1) {
		recebeComando(tabuleiro);
		mostraTabuleiro(tabuleiro);
		geraPeca(tabuleiro);
	}

	return 0;
}