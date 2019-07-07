/*
		 * * * Batalha de RPG (DE TURNOS) * * *
 	No que consiste:
		* Batalhas de turnos

		* Caracteristicas dos personagens---------------------------------------------------------------
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
				* gold = 0;
				*PV_MAX = 100;
 		* Inventario (Itens dos personagem)---------------------------------------------------------------
			- Invertario:
				* Armadura:
					- Capacete (5 - quantidade)
					- Peitoral (5 - quantidade)
					- Luva	   (5 - quantidade)
					- Bota	   (5 - quantidade)

				* Arma:
					- arco		(5 - quantidade)
					- espada	(5 - quantidade)
					- martelo	(5 - quantidade)
				
 				* Itens Consumiveis (limite de 6 itens)
					- Potion
			
			- Equipamentos quantidade
				* Armadura:
					* Capacete:
						- nome: 
						- Defesa: 30;
						- Vida: 40:

					* Capacete:
		
 		* Caracteristicas dos inimigos---------------------------------------------------------------
				*Inimigo e do tipo personagem:
					* Nome do Inimigo (Char)
					* Pontos de Vida  (inteiro)
					* Ataque (inteiro)
					* Defesa (inteiro)
					* drop de xp (inteiro)
					* Nivel (inteiro)
					* drop de gold	
 		
 		* Uma série de batalhas (10 FASES)---------------------------------------------------------------
			-Fases:
				* Fase (1):
					- Inimigo:
						* Nome: 
 						* PV = 15;
						* Ataque = 5;
						* defesa = 5;
						* nivel = 1;	
						* Drop de Experiencia: randon de 15 - 20;
						* Drop de gold: randon de 10 - 20;

				* Fase (2):
					- Inimigo:
						* Nome: 
 						* PV = 20;
						* Ataque = 10;
						* defesa = 10
						* nivel = 2;
						* Drop de Experiencia: randon 20 - 25;
						* Drop de gold: randon de 10 - 20;			
 				
 				* Fase (3):
					- Inimigo:
						* Nome: 
 						* PV = 25;
						* Ataque = 15;
						* defesa = 15;
						* nivel = 3;
						* Drop de Experiencia: randon 25 - 30;
						* Drop de gold: randon de 10 - 20;
 				
				* Fase (4):
					- Inimigo:
						* Nome: 
 						* PV = 30;
						* Ataque = 20;
						* defesa = 15;
						* nivel = 4;
						* Drop de Experiencia: 30 - 35;
						* Drop de gold: randon de 10 - 20;
			
				* Fase (5):
					- Inimigo:
						* Nome: 
 						* PV = 40;
						* Ataque = 30;
						* defesa = 20;
						* nivel = 5;
						* Drop de Experiencia: 35 - 40;
						* Drop de gold: randon de 10 - 20;
			
				* Fase (6):
					- Inimigo:
						* Nome: 
 						* PV = 50;
						* Ataque = 40;
						* defesa = 30;
						* nivel = 6;
						* Drop de Experiencia: 40 - 45;
						* Drop de gold: randon de 10 - 20;
		
				* Fase (7):
					- Inimigo:
						* Nome: 
 						* PV = 60;
						* Ataque = 50;
						* defesa = 40;
						* nivel = 7;
						* Drop de Experiencia: 45 - 50;
						* Drop de gold: randon de 10 - 20;
				
				* Fase (8):
					- Inimigo:
						* Nome: 
 						* PV = 80;
						* Ataque = 60;
						* defesa = 50;
						* nivel = 8;
						* Drop de Experiencia: 50 - 65;
						* Drop de gold: randon de 10 - 20;

				* Fase (9):
					- Inimigo:
						* Nome: 
 						* PV = 90;
						* Ataque = 70;
						* defesa = 60;
						* nivel = 9;
						* Drop de Experiencia: 65 - 80;
						* Drop de gold: randon de 10 - 20;
		
				* Fase (10):
					- Inimigo:
						* Nome: 
 						* PV = 110;
						* Ataque = 80;
						* defesa = 80;
						* nivel = 10;
						* Drop de Experiencia: 80 - 95;
						* Drop de gold: randon de 10 - 20;

PENDENTE:
		*** C ***
	- Potion em porcentagem			-> OK
	- Equipamentos
	- Implementar loja
	- Implementar escolha de inimigos
	- Raridade dos equipamentos
	- Lista de itens
	- Sistema de salvamento			-> OK

		*** HTML ***
	- Menu do jogo
	- implementar modelo de fase
	- Implementar modelo dos inimigos e personagem principal
	- Loja
	- Itens
	- Inventario

*/

//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Contantes
#define MAX_ITENS 7
#define POTION 0.3		//Quantidade maxima que uma poção pode regenerar
#define TOTAL_itens 10		//Total de itens

//Structs

//ARMADURA------------
struct capacete{
	char nome[40];
	double defesa;
	int gold;
};

struct peitoral{
	char nome[40];
	double defesa;
	int gold;
};

struct bota{
	char nome[40];
	double defesa;
	int gold;
};

//ARMA----------------
struct espada{
	char nome[40];
	double ataque;
	int gold;
};

struct arco{
	char nome[40];
	double ataque;
	int gold;
};

//INVENTARIO---------------
struct armadura{
	struct capacete C1;
	struct peitoral C2;
	struct bota C3;
};

struct arma{
	struct espada S1;
	struct arco S2;
};

struct inventario{
	//Bag
	int potion;
	
	//Equipaveis
	struct armadura equipamento;
	struct arma weapon;
};

//PERSONAGEM-------------
struct personagem{
	//Caracteristicas
	char nome[100];
	double PV;
	double ataque;
	double defesa;
	double PV_MAX;
	int xp;
	int nivel;
	int gold;

	int fase;

	struct inventario bag;
};

//Prototipos
void set_Personagem(struct personagem *);
void imprime_personagem(struct personagem );
void levelup(struct personagem *);
void xp(struct personagem *, int);
void menu_batalha(struct personagem, struct personagem);
struct personagem carrega_dados(char *);





//Função principal
int main(){
	//Inicializaçao
	char *entrada = getenv("QUERY_STRING");
	char in[400];	
	
	//Iniciando personagem
	struct personagem J1;
	J1 = carrega_dados(entrada);

	//HTML
	printf("Content-Type:text/html;charset=UTF-8\n\n");
	printf("<!DOCTYPE html>\n");
	printf("<html>\n<head>\n<title>RPG</title>\n</head>\n<body>");
		imprime_personagem(J1);
	printf("</body>\n</html>\n");
	
	return 0;
}

/*
Input: Um vetor de caracteres
Output: struct do tipo personagem
*/
struct personagem carrega_dados(char *input)
{
	//Inicializaçao
	struct personagem A;
	strcpy(A.nome, input);

	//arquivo
	FILE *arquivo = fopen(input, "rb");
	
	if(arquivo == NULL)
	{
		//Criado novo jogo
		arquivo = fopen(input, "wb");
		
		//Setando personagem
		set_Personagem(&A);

		//Gravando dados
		fwrite(&A, sizeof(struct personagem), 1, arquivo);
	}else{
		//Lendo dados do personagem
		fread(&A, sizeof(struct personagem), 1, arquivo);
	}
	
	//Fechando arquivo
	fclose(arquivo);

	return A;
}

void set_Personagem(struct personagem *A)
{
	//ARMADURA
	A->bag.equipamento.C1.defesa = 1;
	A->bag.equipamento.C2.defesa = 1;
	A->bag.equipamento.C3.defesa = 1;

	//ARMA
	A->bag.weapon.S1.ataque = 1;

	//PERSONAGEM
	A->PV = 20;
	A->PV_MAX = 20;
	A->ataque = 5 + A->bag.weapon.S1.ataque;
	A->defesa = 5 + A->bag.equipamento.C1.defesa + A->bag.equipamento.C2.defesa + A->bag.equipamento.C3.defesa;
	A->xp = 0;
	A->nivel = 1;
	A->gold = 0;

	A->fase = 1;

	//INVENTARIO
	A->bag.potion = 1;
}

void imprime_personagem(struct personagem A)
{
	printf("<ul>");
	printf("<li><b>Nome:</b> %s</li>", A.nome);
	printf("<li><b>Pontos de vida:</b> %.0lf</li>", A.PV);
	printf("<li><b>Ataque:</b> %.0lf</li>", A.ataque);
	printf("<li><b>Defesa:</b> %.0lf</li>", A.defesa);
	printf("<li><b>Experiencia:</b> %d</li>", A.xp);
	printf("<li><b>Nivel:</b> %d</li>", A.nivel);
	printf("<li><b>Gold:</b> %d</li>", A.gold);

	//Inventario
	printf("<li><b>Potion:</b> %d</li>", A.bag.potion);
	printf("</ul>");
}

void imprime_inimigo(struct personagem A)
{
	printf("\n	INIMIGO\n");
	printf("\nNome: %s", A.nome);
	printf("Pontos de vida: %.0lf\n", A.PV);
	printf("Ataque: %.0lf\n", A.ataque);
	printf("Defesa: %.0lf\n", A.defesa);
	printf("Nivel: %d\n", A.nivel);	
}


void levelup(struct personagem *A)
{
	A->PV_MAX = A->PV_MAX + 10;		//PV + 5
	A->ataque = A->ataque + 5;	//ataque + 5
	A->defesa = A->defesa + 5;	//defesa + 5
	A->xp = 0;			//xp = 0
	A->nivel++;			//nivel + 1
}

void xp(struct personagem *A, int experiencia)
{
	A->xp += experiencia;
}

void imprime_pocoes(struct personagem A)
{
	printf("	Itens\n");
	int i;
	for(i = 1; i < MAX_ITENS; i++)
	{
		if( i <= A.bag.potion)
			printf("(%d) - Potion\n", i);
		else
			printf("(%d) - Vazio\n", i);
	}
}

/*
 Input:
 Output: Retorna 1 se o item foi usado e 0 caso contrario
 Paremetros: 
*/
int usa_iten(int opcao, struct personagem *A)					//PENDENTE------------------------
{
	A->PV = A->PV + A->PV * POTION;

	return 1;
}

/*
void menu_batalha(struct personagem A, struct personagem inimigo)		//PENDENTE------------------------
{
	//Apresentação
	printf("\n\n	***A BATALHA IRA COMEÇAR***\n\n");

	//Iniciando a batalha
	
	imprime_inimigo(inimigo);
	imprime_personagem(A);
	
	//Inicializaçoes
	int op, op_inventario, controle = 1;			//opçoes do menu

	//Menu de seleção
	do{
		printf("\n	**Opçoes**\n");
		printf("(1) - Atacar	(2) - Inventario\n");
		printf("Digite uma opção: ");
		scanf("%d", &op);

		if(op == 2)	//Inventario
		{
			imprime_pocoes(A);
			printf("(0) - Voltar ou Item vazio\n");
			printf("Digite o item desejado: ");
		
			do{
				scanf("%d", &op_inventario);
			}while(op_inventario < -1 && op_inventario > MAX_ITENS);		//Limite de intens no inventario é de 6

			if(usa_iten(op_inventario, &A))
			{
				controle = 0;
				A.bag.potion--;
			}
		}
	
	}while(op != 1 && controle != 0);
	
	//ATAQUE
	if(controle == 1)
	{
		inimigo.PV = inimigo.PV - (A.ataque - ((inimigo.defesa/(100 + inimigo.defesa)) * A.ataque)); //Dano considerando a defesa
	}
		
	//Turno do inimigo
	A.PV = A.PV - (inimigo.ataque - ((A.defesa/(100 + A.defesa)) * inimigo.ataque));
	
}
*/

struct personagem gerador_inimigo(){
	
	struct personagem chefes[12];
	
	int i, j = 0;
	for(i = 0; i < 12; i++)
	{
		if(i == 0)
		{
			//Atributos base
			chefes[i].PV = 20;
			chefes[i].ataque = 5;
			chefes[i].defesa = 5;
			chefes[i].xp = rand() % 5;
			chefes[i].nivel = i;
			chefes[i].gold = rand() % 5;
		}else{
			chefes[i].PV += j;
			chefes[i].ataque += j;
			chefes[i].defesa += j;
			chefes[i].xp = j + rand() % 20;
			chefes[i].nivel = i;
			chefes[i].gold = 2*j + rand() % 150;
		}
			
		//FATOR DE ESCALONAMENTO
		j += 12;
	}

	return *chefes;
}


void gera_itens()
{
	struct inventario itens[TOTAL_itens];

	int i = 0;
	for(i = 0; i < TOTAL_itens; i++)
	{
		if(i == 0)
		{
			strcpy(itens[i].equipamento.C1.nome, "Leather");
			itens[i].equipamento.C1.defesa = 3;

			strcpy(itens[i].equipamento.C2.nome,"Leather");
			itens[i].equipamento.C1.defesa = 3;

			strcpy(itens[i].equipamento.C3.nome, "Leather");
			itens[i].equipamento.C1.defesa = 3;

		}else if(i == 1)
		{
			strcpy(itens[i].equipamento.C1.nome, "Iron");
			itens[i].equipamento.C1.defesa = 6;

			strcpy(itens[i].equipamento.C2.nome, "Iron");
			itens[i].equipamento.C1.defesa = 6;

			strcpy(itens[i].equipamento.C3.nome, "Iron");
			itens[i].equipamento.C1.defesa = 6;

		}else if(i == 2)
		{
			strcpy(itens[i].equipamento.C1.nome, "Thorns");
			itens[i].equipamento.C1.defesa = 9;

			strcpy(itens[i].equipamento.C2.nome, "Thorns");
			itens[i].equipamento.C1.defesa = 9;

			strcpy(itens[i].equipamento.C3.nome, "Thorns");
			itens[i].equipamento.C1.defesa = 9;

		}else if(i == 3)
		{
			strcpy(itens[i].equipamento.C1.nome, "Black Knight");
			itens[i].equipamento.C1.defesa = 12;

			strcpy(itens[i].equipamento.C2.nome, "Black Knight");
			itens[i].equipamento.C1.defesa = 12;

			strcpy(itens[i].equipamento.C3.nome, "Black Knight");
			itens[i].equipamento.C1.defesa = 12;

		}else if(i == 4)
		{
			strcpy(itens[i].equipamento.C1.nome, "Cathedral Knight");
			itens[i].equipamento.C1.defesa = 15;

			strcpy(itens[i].equipamento.C2.nome, "Cathedral Knight");
			itens[i].equipamento.C1.defesa = 15;

			strcpy(itens[i].equipamento.C3.nome, "Cathedral Knight");
			itens[i].equipamento.C1.defesa = 15;

		}else if(i == 5)
		{
			strcpy(itens[i].equipamento.C1.nome, "Cleric");
			itens[i].equipamento.C1.defesa = 18;

			strcpy(itens[i].equipamento.C2.nome, "Cleric");
			itens[i].equipamento.C1.defesa = 18;

			strcpy(itens[i].equipamento.C3.nome, "Cleric");
			itens[i].equipamento.C1.defesa = 18;

		}else if(i == 6)
		{
			strcpy(itens[i].weapon.S1.nome, "Espada quebrada");
			itens[i].weapon.S1.ataque = 7;

			strcpy(itens[i].weapon.S2.nome, "Arco Curto");
			itens[i].weapon.S1.ataque = 7;

		}else if(i == 7)
		{
			strcpy(itens[i].weapon.S1.nome, "Espada curta");
			itens[i].weapon.S1.ataque = 14;

			strcpy(itens[i].weapon.S2.nome, "Arco longo");
			itens[i].weapon.S1.ataque = 14;

		}else if(i == 8)
		{
			strcpy(itens[i].weapon.S1.nome, "Black Knight");
			itens[i].weapon.S1.ataque = 21;

			strcpy(itens[i].weapon.S2.nome, "Elfico");
			itens[i].weapon.S1.ataque = 21;

		}else if(i == 9)
		{
			strcpy(itens[i].weapon.S1.nome, "Cathedral Knight");
			itens[i].weapon.S1.ataque = 30;

			strcpy(itens[i].weapon.S2.nome, "Cathedral Knight");
			itens[i].weapon.S1.ataque = 30;

		}else if(i == 10)
		{
			strcpy(itens[i].weapon.S1.nome, "Cleric");
			itens[i].weapon.S1.ataque = 50;

			strcpy(itens[i].weapon.S2.nome, "Besta");
			itens[i].weapon.S1.ataque = 50;

		}
	}
}
