// Atividade: Trabalho avaliativo 1. 
// Nome: SGA(Sistema de gerenciamento acadêmico). 

#ifndef SGA_H
#define SGA_H

// TAD-1: Cadastro - Assinatura dos tipos
typedef struct pessoa Pessoa;
typedef struct docente Docente;
typedef struct discente Discente;

// Protótipos das funções da TAD-1
Pessoa *createUser();
void listarAlunoDeOrientador();
void listarAlunosSemOrientador();
void mudarOrientadorDeAluno();

Docente *createDocente(Pessoa *p);
void cadastroDocente(Docente *doc);
void removerDocente();
void alterarDocente();
void buscarDocente();
void mostrarDocente();

Discente *createDiscente(Pessoa *p);
void cadastroDiscente(Discente *dis);
void removerDiscente();
void alterarDiscente();
void buscarDiscente();
void mostrarDiscente();

// TAD-2: Imagem - Assinatura dos tipos
typedef struct pixel Pixel;
typedef struct imagem Imagem;

// Protótipos das funções da TAD-2
Imagem *createImage();
void loadImage();
void saveImage();
void copyImage();
void saveCopyImage();

// TAD-3: Manipulação de imagem - Assinatura dos tipos

// Protótipos das funções da TAD-3
void valorMaximo();
void valorMinimo();
void distanciaEuclidiana();
void distanciaManhattan();
void localBinaryPattern();
void matrizDeCoocorrencia();
void filtroDeMedia();
void filtrosDeMediana();

#endif