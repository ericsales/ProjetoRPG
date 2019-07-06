//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Constantes
#define POTION 0.3

//Struct
//Armadura
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

//Arma
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

//INVENTARIO
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

struct personagem carrega_dados(char *);
struct personagem gerador_inimigo(int);
void menu_batalha(struct personagem *, struct personagem *);
void imprime_personagem(struct personagem A);

int main(){
	//Inicialização
	char *entrada = getenv("QUERY_STRING");

	//Iniciando personagem
	struct personagem J1;
	J1 = carrega_dados(entrada);
	imprime_personagem(J1);
	//INICIANDO INIMIGOS
	struct personagem I;

	I = gerador_inimigo(J1.fase);

	//Iniciando batalha
	switch (J1.fase)
	{
		//FASE (1)
		case 1:
			menu_batalha(&J1, &I);
		break;

		//FASE (2)
		case 2:
			menu_batalha(&J1, &I);
		break;
		
		//FASE (3)
		case 3:
			menu_batalha(&J1, &I);
		break;
		
		//FASE (4)
		case 4:
			menu_batalha(&J1, &I);
		break;

		//FASE (5)
		case 5:
			menu_batalha(&J1, &I);
		break;

		//FASE (6)
		case 6:
			menu_batalha(&J1, &I);
		break;

		//FASE (7)
		case 7:
			menu_batalha(&J1, &I);
		break;

		//FASE (8)
		case 8:
			menu_batalha(&J1, &I);
		break;

		//FASE (9)
		case 9:
			menu_batalha(&J1, &I);
		break;

		//FASE (10)
		case 10:
			menu_batalha(&J1, &I);
		break;
	}
	return 0;
}

struct personagem carrega_dados(char *input)
{
	//Inicializaçao
	struct personagem A;
	
	//arquivo
	FILE *arquivo = fopen(input, "rb");
	
	if(arquivo == NULL)
	{
		//Caso não seja possivel ler o arquivo redirecionar para menu
	}else{
		//Lendo dados do personagem
		fread(&A, sizeof(struct personagem), 1, arquivo);
	}
	
	//Fechando arquivo
	fclose(arquivo);
	
	return A;
}

struct personagem gerador_inimigo(int p)
{
	//INICIA Struct
	struct personagem chefes[12];

	//Inicialização
	int i = 0, j = 0;

	//Gerando personagens
	for(i = 0; i < 12; i++)
	{
		if(i < 3)
		{
			//Atributo base
			strcpy(chefes[i].nome, "Lacaio");
			chefes[i].PV = 20 + i;
			chefes[i].ataque = 5 + i;
			chefes[i].defesa = 5 + i;
			chefes[i].xp = rand() % 5;
			chefes[i].nivel = 1;
			chefes[i].gold = 30 + rand() % 15;
		}else{
			chefes[i].PV += j;
			chefes[i].ataque += j;
			chefes[i].defesa += j;
			chefes[i].xp = j + rand() % 5;
			chefes[i].nivel = i + 1;
			chefes[i].gold = 2*j + rand() % 150;
		}

		if(i == 3)
			strcpy(chefes[i].nome, "Ciron");
		else if(i == 4)
			strcpy(chefes[i].nome, "MaTuz");
		else if(i == 5)
			strcpy(chefes[i].nome, "Sally");
		else if(i == 6)
			strcpy(chefes[i].nome, "Bozo");
		else if(i == 7)
			strcpy(chefes[i].nome, "sdf");
		else if(i == 8)
			strcpy(chefes[i].nome, "sdf");
		else if(i == 9)
			strcpy(chefes[i].nome, "sdf");
		else if(i == 10)
			strcpy(chefes[i].nome, "sdf");
		else if(i == 11)
			strcpy(chefes[i].nome, "Ganso");
		else if(i == 12)
		//FATOR DE ESCALONAMENTO
		j+= 12;
	}

	return chefes[p];
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
	printf("<ul>");
	printf("<li><b>Nome:</b> %s</li>", A.nome);
	printf("<li><b>Pontos de vida:</b> %.0lf</li>", A.PV);
	printf("<li><b>Ataque:</b> %.0lf</li>", A.ataque);
	printf("<li><b>Defesa:</b> %.0lf</li>", A.defesa);
	printf("<li><b>Nivel:</b> %d</li>", A.nivel);
}

void menu_batalha(struct personagem *A, struct personagem *inimigo)
{
	printf("%s", A->nome);


	if(A->PV > 0 || inimigo->PV > 0)
	{
		//Iniciando a batalha
		/*Exibir os personagens na tela*/
		
		//Inicializaçoes
		int controle = 1, op;
		
		//Menu de seleção
		printf("	Opçoes\n");
		printf("(1) - atacar	(2) - Usar Potion\n");
		scanf("%d", &op);
		
		//Inventario
		if(op == 2)
			A->PV = A->PV + A->PV * POTION;
		else if(controle != 0)
			inimigo->PV = inimigo->PV - (A->ataque - ((inimigo->defesa/(100 + inimigo->defesa)) * A->ataque)); //Dano considerando a defesa

		A->PV = A->PV - (inimigo->ataque - ((A->defesa/(100 + A->defesa)) * inimigo->ataque));
		
		printf("%lf\n", A->PV);
		printf("%s\n", A->nome);
		
		
		//Gravando dados
		FILE *arquivo = fopen(A->nome, "wb");
		fwrite(&A, sizeof(struct personagem), 1, arquivo);
		fclose(arquivo);

		//Recarregar a pag
	}else{
		//Recebendo xp,gold
		A->PV = A->PV_MAX;
		A->xp += inimigo->xp;
		A->gold += inimigo->gold;

		if(A->xp > 100)
		{
			A->PV_MAX = A->PV_MAX + 20;
			A->PV = A->PV_MAX;
			A->ataque = A->ataque + 5;
			A->defesa = A->defesa + 5;
			A->xp = A->xp - 100;
			A->nivel++;
		}

		//Gravando dados
		FILE *arquivo = fopen(A->nome, "wb");

		fwrite(&A, sizeof(struct personagem), 1, arquivo);

		fclose(arquivo);
			
		
		//REDIRECIONAR PARA O MENU
	}
}

