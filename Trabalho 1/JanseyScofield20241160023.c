// #################################################

//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome:
//  email:
//  Matrícula:
//  Semestre:

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include <stdio.h>
#include "JanseyScofield20241160023.h" // Substitua pelo seu arquivo de header renomeado
#include <stdlib.h>
#include <string.h>

DataQuebrada quebraData(char data[]);

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string 
 */

int q1(char *data){
    DataQuebrada dataquebrada =  quebraData(data);
    int mes30Dias, anoBissexto;

    if(!dataquebrada.valido) return 0;

    if(dataquebrada.iAno < 0) return 0;

    if(dataquebrada.iMes <  1 || dataquebrada.iMes > 12) return 0;

    if(dataquebrada.iDia <= 0 || dataquebrada.iDia > 31) return 0;
    
    mes30Dias = dataquebrada.iMes == 4 || dataquebrada.iMes == 6 || dataquebrada.iMes == 9 || dataquebrada.iMes == 10;

    if(mes30Dias && dataquebrada.iDia == 31) return 0;

    if(dataquebrada.iMes == 2){
        if(dataquebrada.iDia > 29) return 0;
        if(dataquebrada.iDia == 29) return checarAnoBissexto(dataquebrada.iAno);
    }
    return 1;
}


/*
 Q2 = diferença entre duas datas
 @objetivoilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[])
{

    //calcule os dados e armazene nas três variáveis a seguir
    DiasMesesAnos dma;
    
    if (q1(datainicial) == 0){
      dma.retorno = 2;
      return dma;
    }else if (q1(datafinal) == 0){
      dma.retorno = 3;
      return dma;
    }else{
      DataQuebrada dtIncial = quebraData(datainicial);
      DataQuebrada dtFinal = quebraData(datafinal);
      
      int diasDtIncial, diasDtFinal, diferenca;
      printf("Data inicial: %d/%d/%d\n", dtIncial.iDia, dtIncial.iMes,  dtIncial.iAno);
      printf("Data final: %d/%d/%d\n", dtFinal.iDia, dtFinal.iMes,  dtFinal.iAno);
      diasDtIncial = diasData(dtIncial);
      diasDtFinal = diasData(dtFinal);
      
      printf("Dias inicial: %d\n",diasDtIncial);
      printf("Dias final: %d\n",diasDtFinal);


      if(diasDtIncial > diasDtFinal){
        dma.retorno = 4;
        return dma;
      } 

      diferenca = diasDtFinal - diasDtFinal;
      DataQuebrada dataDiferenca  = diasEmData(diferenca);
      printf("Data diferença : %d/%d/%d\n", dataDiferenca.iDia, dataDiferenca.iMes,  dataDiferenca.iAno);
      dma.qtdAnos = dataDiferenca.iAno;
      dma.qtdMeses =  dataDiferenca.iMes;
      dma.qtdDias = dataDiferenca.iDia;

      dma.retorno = 1;
      return dma;
      
    }
    
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{
    int qtdOcorrencias = -1;

    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
    int qtdOcorrencias = -1;

    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{
    int iCont;
    int qtdDigitosNum =  1, casaNumInvertido = 1;
    int numInvertido = 0;

    while(num / (qtdDigitosNum * 10) > 0){
      qtdDigitosNum *= 10;
    }

    while(qtdDigitosNum > 0){

      numInvertido += (num / qtdDigitosNum) * casaNumInvertido;
      num  -= (num / qtdDigitosNum) * qtdDigitosNum;
      qtdDigitosNum /= 10;
      casaNumInvertido *= 10;
    }

    return numInvertido;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
    int qtdOcorrencias;
    return qtdOcorrencias;
}




DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
	char sMes[3];
	char sAno[5];
	int i; 

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }  
	

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }
	

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

	dq.valido = 1;
    
  return dq;
}

int checarAnoBissexto(int ano){
  int anoBissexto = 0;

  if(ano % 4 == 0){
    if(ano % 100 == 0){
       if(ano %  400 == 0){
          anoBissexto = 1;
        }
    }
    else{
      anoBissexto = 1;
    }            
  }

  return anoBissexto;
}


int diasData(DataQuebrada data){
  int dias = data.iDia;
  int iCont, anoBissexto;

  for(iCont = 1; iCont < data.iMes; iCont++){
    if(iCont == 4 || iCont == 6 || iCont == 9 || iCont == 10){
      dias += 30;
    }
    else{
      dias += 31;
    }
  }

  for(iCont = 0; iCont < data.iAno; iCont++){
    if(checarAnoBissexto(iCont)){
      dias +=  366;
    }
    else{
      dias += 365;
    }
  }

  ("Dias da data: %d\n",dias);
  return dias;
}

DataQuebrada diasEmData(int dias){
  int iCont, diasDescontados;
  int ano = 0;
  int mes = 0;
  int dia = 0;

  printf("Dias: %d\n",dias);
  iCont = 0;
  while(1){
    diasDescontados = checarAnoBissexto(iCont)? 366 : 365;
    
    if(dias - diasDescontados < 0){
      break;
    }

    printf("Dias restantes %d\n", dias);

    dias -= diasDescontados;
    ano ++;
    iCont ++;
  }

  iCont = 1;
  while(1){
    if(iCont == 4 || iCont == 6 || iCont == 9 || iCont == 10){
      diasDescontados = 30;
    }
    else if(iCont == 2){
      if(checarAnoBissexto(ano)){
        diasDescontados = 29;
      }
      else{
        diasDescontados = 28;
      }
    }
    else{
      diasDescontados = 31;
    }

    if(dias - diasDescontados < 0){
        break;
    }
    printf("Dias restantes %d\n", dias);

    dias -= diasDescontados;
    mes  ++;
    iCont ++;
  }

  dia = dias;
  DataQuebrada data =  {dia, mes, ano, 1};
  printf("Data diferença : %d/%d/%d\n", dia, mes,  ano);
  printf("Data diferença : %d/%d/%d\n", data.iDia, data.iMes,  data.iAno);
 
  return data;
}