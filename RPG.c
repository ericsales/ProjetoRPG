/*
		 * * * Batalha de RPG (DE TURNOS) * * *
 	No que consiste:
		* Batalhas de turnos

		* Caracteristicas dos personagens
			- Atributos:
				* Nome do personagem (Char)
				* Pontos de Vida  (inteiro)
				* Ataque (inteiro)
				* Defesa (inteiro)
				* Nivel (inteiro): A cada 100 pontos de exxperiencia o nivel aumenta 1
			
			- Personagens base
				* PV (Pontos de vida) = 20;
				* Ataque = 5;
				* defesa = 5;
				* xp (pontos de experiencia) = 0;
				* nivel = 1;

 		* Inventario (Itens dos personagem)
			- Invertario:
				* Armadura:
					- Defesa
					- Vida

				* Arma:
					- Ataque
			- Itens
				*Armadura de ?:
					- Defesa: 30;
					- Vida: 40;
		
 		* Caracteristicas dos inimigos
				*Inimigo e do tipo personagem:
					* Nome do Inimigo (Char)
					* Pontos de Vida  (inteiro)
					* Ataque (inteiro)
					* Defesa (inteiro)
					* Nivel (inteiro):	
 		
 		* Uma série de batalhas (10 FASES)
			-Fases:
				* Fase (1):
					- Inimigo:
						* Nome: 
 						* PV = 15;
						* Ataque = 5;
						* defesa = 5;
						* nivel = 1;	
						* Drop de Experiencia: randon de 15 - 20;

				* Fase (2):
					- Inimigo:
						* Nome: 
 						* PV = 20;
						* Ataque = 5;
						* defesa = 5;
						* nivel = 2;
						* Drop de Experiencia: randon 20 - 25;
				
 				* Fase (3):
					- Inimigo:
						* Nome: 
 						* PV = 20;
						* Ataque = 5;
						* defesa = 5;
						* nivel = 3;
						* Drop de Experiencia: randon 25 - 30;
				
 				* Fase (4):
					- Inimigo:
						* Nome: 
 						* PV = 20;
						* Ataque = 5;
						* defesa = 5;
						* nivel = 4;
						* Drop de Experiencia: 30 - 35;
				
				* Fase (5):
					- Inimigo:
						* Nome: 
 						* PV = 20;
						* Ataque = 5;
						* defesa = 5;
						* nivel = 5;
						* Drop de Experiencia: 35 - 40;
				
				* Fase (6):
					- Inimigo:
						* Nome: 
 						* PV = 20;
						* Ataque = 5;
						* defesa = 5;
						* nivel = 6;
						* Drop de Experiencia: 40 - 45;
				
				* Fase (7):
					- Inimigo:
						* Nome: 
 						* PV = 20;
						* Ataque = 5;
						* defesa = 5;
						* nivel = 7;
						* Drop de Experiencia: 45 - 50;
				
				* Fase (8):
					- Inimigo:
						* Nome: 
 						* PV = 20;
						* Ataque = 5;
						* defesa = 5;
						* nivel = 8;
						* Drop de Experiencia: 50 - 65;
				
				* Fase (9):
					- Inimigo:
						* Nome: 
 						* PV = 20;
						* Ataque = 5;
						* defesa = 5;
						* nivel = 9;
						* Drop de Experiencia: 65 - 80;
				
				* Fase (10):
					- Inimigo:
						* Nome: 
 						* PV = 20;
						* Ataque = 5;
						* defesa = 5;
						* nivel = 10;
						* Drop de Experiencia: 80 - 95;

*/

//Bibliotecas
#include <stdio.h>
#include <stdlib.h>

//Structs
struct personagem{
	char nome[100];
	int PV;
	int ataque;
	int defesa;
	int xp;
	int nivel;
};

//Prototipos
void set_Personagem(struct personagem *);
void imprime_personagem(struct personagem );
void levelup(struct personagem *);
void menu(struct personagem );
void xp(struct personagem *, int);


//Função principal
int main(){
	//Iniciando personagem base
	struct personagem J1;
	
	//Inicialização
	int fase = 1;

	//Iniciando personagem
	printf("Digite o nome do seu personagem: ");
	fgets(J1.nome, sizeof J1.nome, stdin);
	set_Personagem(&J1);

	//Mostra Personagem
	imprime_personagem(J1);

	//Iniciado as fases
	/*
	switch(fase)
		case(1):

		break;

		case(2):

		break;
	*/

	return 0;
}

void set_Personagem(struct personagem *A)
{
	A->PV = 20;
	A->ataque = 5;
	A->defesa = 5;
	A->xp = 0;
	A->nivel = 1;
}

void imprime_personagem(struct personagem A)
{
	printf("\nNome: %s", A.nome);
	printf("Pontos de vida: %d\n", A.PV);
	printf("Ataque: %d\n", A.ataque);
	printf("Defesa: %d\n", A.defesa);
	printf("Experiencia: %d\n", A.xp);
	printf("Nivel: %d\n", A.nivel);
}

void menu(struct personagem A)
{
	//Inicializaçao
	int op;
	
	//Opçoes
	printf("\n	--MENU--\n");
	printf("(1) - Ver status do personagem\n");
	printf("(2) - \n");
	printf("(3) - \n");
	printf("(4) - Iniciar proxima fase\n\n");
	
	printf("Digite uma opção: ");
	scanf("%d", &op);
	
	while(op < 1){
		printf("Opção invalida!!! Digite novamente: ");
		scanf("%d", &op);
	}

	/*
	while(){
		case(1):
			
		break;

		case(2):

		break;
	}
	*/
}

void levelup(struct personagem *A)
{
	A->PV = A->PV + 5;		//PV + 5
	A->ataque = A->ataque + 5;	//ataque + 5
	A->defesa = A->defesa + 5;	//defesa + 5
	A->xp = 0;			//xp = 0
	A->nivel++;			//nivel + 1
}

void xp(struct personagem *A, int experiencia)
{
	A->xp += experiencia;
}
