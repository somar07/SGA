#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sga.h"

struct pessoa {
    char *nome;
    int idade, ID; // Identificador
    int matricula; // Deve ser gerada automaticamente
};

struct docente {
    Pessoa info_docente;
    int qtd_orientacoes_graduacao, qtd_orientacoes_pos_graduacao;
};

struct discente {
    Pessoa info_discente;
    int nivel; // 1 - graduação ou 2 - pos-gradução
    char *nome_curso;
    int senha, ID_orientador, ID_coorientador;
};

struct pixel {
    int x, y, valor_pixel;
};

struct imagem {
    int altura, largura;
    Pixel *pixels_imagem;//variar de 0 ate 255
};

// Funções da TAD-1
Pessoa *createUser() {
    Pessoa *p = (Pessoa *) malloc(sizeof(Pessoa));
    return p;
}

void listarAlunoDeOrientador();
void listarAlunosSemOrientador();
void mudarOrientadorDeAluno();

Docente *createDocente(Pessoa *p) {
    Docente *doc = (Docente *) malloc(sizeof(Docente));

    doc->info_docente = p;
    doc->qtd_orientacoes_graduacao = 0;
    doc->qtd_orientacoes_pos_graduacao = 0;
    
    return doc;
}

void cadastroDocente(Docente *doc) {
    printf("CADASTRO DE DOCENTE\n");
    printf("Informe o nome:"); scanf(" %[^\n]s", doc->info_docente.nome);
    printf("Informe a idade:"); scanf("%d", doc->info_docente.idade);
    // Implemetar a parte do id e da matricula automatica
}

void removerDocente();
void alterarDocente();
void buscarDocente();
void mostrarDocente();

Discente *createDiscente(Pessoa *p) {
    Discente *dis = (Discente *) malloc(sizeof(Discente));

    dis->info_discente = p;
    dis->nivel = 0;
    dis->nome_curso = NULL;
    dis->senha = 0;
    dis->ID_orientador = 0;
    dis->ID_coorientador = 0;
    
    return dis;
}

void cadastroDiscente();
void removerDiscente();
void alterarDiscente();
void buscarDiscente();
void mostrarDiscente();

// Finções da TAD-2
Imagem *createImage();
void loadImage();
void saveImage();
void copyImage();
void saveCopyImage();

// Funções da TAD-3
void valorMaximo();
void valorMinimo();
void distanciaEuclidiana();
void distanciaManhattan();
void localBinaryPattern();
void matrizDeCoocorrencia();
void filtroDeMedia();
void filtrosDeMediana();