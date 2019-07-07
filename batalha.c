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

//Prototipos
struct personagem carrega_dados(char *);
struct personagem gerador_inimigo(int);
void menu_batalha(struct personagem *, struct personagem *, char *);
void imprime_personagem(struct personagem A);

//Função principal
int main(){
	//Inicialização
	char *entrada = getenv("QUERY_STRING");

	//Iniciando personagem
	struct personagem J1;
	J1 = carrega_dados(entrada);
	imprime_personagem(J1);
	
	//Inicia inimigo
	struct personagem I;

	char inimigo[100];
	int i = 0, aux = 1;
	
	while(aux != 0)
	{
		if(J1.nome[i] == '\0')
		{
			inimigo[i] = J1.fase + 64;
			inimigo[i + 1] = '\0';
			aux = 0;
		}else{
			inimigo[i] = J1.nome[i];
			i++;
		}
	}

	//Carregando dados em arquivo
	FILE *arq = fopen(inimigo, "rb");
	
	if(arq != NULL)
	{
		fread(&I, sizeof(struct personagem), 1, arq);
	}else{
		//INICIANDO INIMIGOS
		I = gerador_inimigo(J1.fase);
		arq = fopen(inimigo, "wb");
		fwrite(&I, sizeof(struct personagem), 1, arq);
	}

	fclose(arq);
	
	
	//Iniciando batalha
	switch (J1.fase)
	{
		//FASE (1)
		case 1:
			//Iniciando fase
			imprime_personagem(I);
			menu_batalha(&J1, &I, inimigo);
		break;

		//FASE (2)
		case 2:
			menu_batalha(&J1, &I, inimigo);
		break;
		
		//FASE (3)
		case 3:
			menu_batalha(&J1, &I, inimigo);
		break;
		
		//FASE (4)
		case 4:
			menu_batalha(&J1, &I, inimigo);
		break;

		//FASE (5)
		case 5:
			menu_batalha(&J1, &I, inimigo);
		break;

		//FASE (6)
		case 6:
			menu_batalha(&J1, &I, inimigo);
		break;

		//FASE (7)
		case 7:
			menu_batalha(&J1, &I, inimigo);
		break;

		//FASE (8)
		case 8:
			menu_batalha(&J1, &I, inimigo);
		break;

		//FASE (9)
		case 9:
			menu_batalha(&J1, &I, inimigo);
		break;

		//FASE (10)
		case 10:
			menu_batalha(&J1, &I, inimigo);
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
			chefes[i].xp = 5 + rand() % 10;
			chefes[i].nivel = 1;
			chefes[i].gold = (i+5)*(i+5) + rand() % ((i+5)*(i+5)*3);
		}else{
			chefes[i].PV += j;
			chefes[i].ataque += j;
			chefes[i].defesa += j;
			chefes[i].xp = j + rand() % 10;
			chefes[i].nivel = i + 1;
			chefes[i].gold = (i+5)*(i+5) + rand() % ((i+5)*(i+5)*3);
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

void menu_batalha(struct personagem *A, struct personagem *inimigo, char *ini)
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
		
		//Gravando Dados em aquivo	
		struct personagem B = *A;
		FILE *arquivo = fopen(B.nome, "wb");
		fwrite(&B, sizeof(struct personagem), 1, arquivo);
		fclose(arquivo);

		//Gravando dados Inimigo em arquivo
		struct personagem iniA = *inimigo;
		FILE *arq = fopen(ini, "wb");
		fwrite(&iniA, sizeof(struct personagem), 1, arq);
		fclose(arq);

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

		//Gravando Dados em aquivo	
		struct personagem B = *A;
		FILE *arquivo = fopen(B.nome, "wb");
		fwrite(&B, sizeof(struct personagem), 1, arquivo);
		fclose(arquivo);			
		
		//REDIRECIONAR PARA O MENU
	}
}

