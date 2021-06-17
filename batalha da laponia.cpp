#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<stdbool.h>



/*Grupo:
 João Marcelo Costa Miranda, Eduardo Nery Campos Guimarães, Icaro Canela Teixeira de Almeida,Carlos Alberto silva de Magalhães Júnior, Joseph Samuel Neiva */

// Declaracoes
int l, c, cont = 0, NumeroSorteado;
int i, j;
char nomeN[100], nomeS[100];
char mapa[15] [13] = {
	{'_', 'N', 'O', 'R', 'T', 'E', ' ', ' ', ' ', ' ', ' ', ' ',' '}, 
	{'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*','2'},
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'x','3'},
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'x','4'},
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'x','5'},
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'x','6'},
	{'*', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~', '*','7'},
	{'*', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~', '*','8'},
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'x','9'},
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'x','X'},
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'x','Y'},
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'x','Z'},
	{'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*','A'},
	{'1', '2', '3', '4', '5', '6', '7', '8', '9', 'X', 'Y', 'Z',' '},
	{'_', 'S', 'U', 'L', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' '}};
	
//marcar a peca
void marcarX(int lin, int col, char peca){
	
  if (peca=='1'){
		mapa[lin][col] = '1';
	}
	
  else if(peca=='2') {
		mapa[lin][col] = '2';
	}
}

//marcar peca especial #
void marcarY(int lin, int col, char pecaEN){
  
  if (pecaEN =='#') {
    mapa [lin][col] = '#';
  }
}
//marcar peca especial @
void marcarZ(int lin, int col, char pecaES){
  
  if (pecaES == '@'){
    mapa [lin][col] = '@';
  }
}
//marcar peca especial # (caso2)
void marcarY2(int lin, int col, char pecaEN2){
  
  if (pecaEN2 =='#') {
    mapa [lin][col] = '#';
  }
}
//marcar peca especial @ (caso2)
void marcarZ2(int lin, int col, char pecaES2){
  
  if (pecaES2 == '@'){
    mapa [lin][col] = '@';
  }
}


//alternar 
void alternar(){
	
  if(NumeroSorteado==1){
	  NumeroSorteado = 0;		
  }
  
  else{
    NumeroSorteado = 1;		
  }
}

void printMatriz(){
	
  //print das primeiras duas linhas + nome
	for(i = 0; i < 2; i++){
    for(j = 0; j < 13; j++){
      if(mapa[i] [j]=='_') printf("%s -", nomeN);
      else
        printf(" %c ", mapa[i] [j]);
    }
    printf("\n");	
  }

  //Campo Norte print das linhas 2 a 5; ajustes de marcacao
	for(i = 2; i < 6; i++){
    for(j = 0; j < 13; j++){
      if(mapa[i] [j] == ' ') printf("|  ");
      else
      if(mapa[i] [j]=='*') printf(" * ");
      else
      if(mapa[i] [j]=='x') printf("|* ");
      else
      //pecas
      if(mapa[i] [j]=='1') printf("|1 ");
      else
      if(mapa[i] [j]=='2') printf("|2 ");
      else
      if(mapa[i] [j]=='#') printf("|# ");
      else
      if(mapa[i] [j]=='@') printf("|@ ");
      
      else
        printf(" %c ", mapa[i] [j]);	
    } 
    printf("\n");	
  }
		
		
  //print das linhas 6 e 7
	for(i = 6; i < 8; i++){
    for(j = 0; j < 13; j++){	
      printf(" %c ", mapa[i] [j]);	
    }
    printf("\n");	
  }
		
  //Campo Sul print das linhas 8 a 11; ajuste numerico + ajustes das marcaï¿½ï¿½es
	for(i = 8; i < 12; i++){
    for(j = 0; j < 13; j++){
      if(mapa[i] [j] == ' ') printf("|  ");
      else
      if(mapa[i] [j]=='*') printf(" * ");
      else
      if(mapa[i] [j]=='x') printf("|* ");
      else
      if(mapa[i] [j]=='@') printf("|@ ");
      else
      if(mapa[i] [j]=='X') printf(" 10");
      else
      if(mapa[i] [j]=='Y') printf(" 11");
      else
      if(mapa[i] [j]=='Z') printf(" 12");
      else
      if(mapa[i] [j]=='1') printf("|1 ");
      else
      if(mapa[i] [j]=='2') printf("|2 ");
      else
        printf(" %c ", mapa[i] [j]);	
    }
    printf("\n");
	}

  //print das linhas 12 a 14 + nome; ajuste numerico
	for(i = 12; i < 15; i++){
    for(j = 0; j < 13; j++){
    
      if(mapa[i] [j]=='X') printf(" 10");
      else
      if(mapa[i] [j]=='Y') printf(" 11");
      else
      if(mapa[i] [j]=='Z') printf(" 12");
      else
      if(mapa[i] [j]=='A') printf(" 13");
      else
      if(mapa[i] [j]=='_') printf("%s -", nomeS);
      else
        printf(" %c ", mapa[i] [j]);	
    }
    printf("\n");	
  }

}

//inicio do jogo
int main(){
  //introducao
	printf( " ___         ______      _____      ______  _____      __    ______           \n");
  printf( "|   |       |      |    |     |    |      | |  _  |   |  |  |      |         \n");
  printf( "|   |       |      |    |     |    |      | | | | |   |  |  |      |         \n");
  printf( "|   |       |  __  |    |     |    |      | | | | |   |  |  |  __  |          \n");
  printf( "|   |__     |  ||  |    |_____|    |      | | | | |   |  |  |  ||  |         \n");
  printf( "|      |    |  ||  |    |          |      | | | | |   |  |  |  ||  |         \n");
  printf( "|______|   |__|  |__|   |          |______| |_| |_|   |__| |__|  |__|          \n");
  printf("\n");
  printf("\n");
  printf("\n");
  printf("\n");
  printf("   Bem vindo a grande batalha da laponia \n");
  printf("\n");
  printf("\n");
  printf("\n");
  printf("\n");
  printf("   A seguir temos a historia desse jogo, feito pela brilhante mente do professor Marcos lapa.\n");
  printf("\n");
  printf("\n");
  printf("\n");
  printf("\n");
  printf("   A Laponia era uma regiao de situada na costa sul da africa do Sul, a qual era cercada\n");
  printf("por uma grande cordilheira e possuia a maior riqueza da época da regiao: o direito de \n");
  printf("explorar o grande lago “Ichibi Elikhulu”, que na lingua Zulu quer dizer “um grande lago”, \n");
  printf("o qual atravessava toda a Laponia. Entre 300 a.C e 200 a.C. esta regiao foi disputada \n");
  printf("por faccoes guerreiras do norte e do sul, separadas apenas pelo grande lago. Era \n");
  printf("impossivel transpor o lago se houvesse algum inimigo do outro lado, portanto as faccoes \n");
  printf("criaram tecnicas e armamentos para travar disputas entre si de um lado ao outro do \n");
  printf("lago. A historia diz que nunca houve um consenso de qual faccao realmente obteve o \n");
  printf("poder da regiao, pois ha registros de um pouco depois de 200 a.C. um grande maremoto \n");
  printf("inundou a Laponia dizimando todos que ali viviam batalhando pelo grande poder. O que \n");
  printf("se sabe e que antes do diluvio estava acontecendo uma batalha e que uma das faccoes \n");
  printf("estava ganhando. Apenas uma guerreira conseguiu fugir da Laponia, chamada Iqhawe \n");
  printf("Elihlakaniphile, que em Zulu quer dizer “Sabia Guerreira”. Para homenagear seus \n");
  printf("antepassados, Ighawe criou um jogo posteriormente e o disseminou mundo afora.\n");
  printf("\n");
  printf("\n");
  printf("\n");
  printf("\n");
  printf("   Aqui temos o como funciona o jogo.\n");
  printf("\n");
  printf("\n");
  printf( "  O jogo consiste em um tabuleiro de tamanho 12x12, com as casas da borda\n");
  printf( "representando a cordilheira e separado exatamente no meio por uma faixa de 20 casas,\n");
  printf( "representando o lago Ichibi,tendo de cada lado do lago as tribos do norte e do sul.\n");
  printf( "as tribos possuem guerreiros 1 e 2 que poderam se usados durante o combate, alem disso \n");
  printf( "cada uma das tribos possui um xama especial, o do norte o xama da vida representado \n");
  printf( "pela peca # e o xama do sul sendo o da morte representado pela peca @..\n");
  printf( "o objetivo do jogo e ser a ultima tribo em pe, ou seja, ao final do jogo, o jogador com a ultima peca viva ganha\n");
  printf( "alem disso nenhuma peca pode se movimentar nas montanhas ou no rio pois eles nao tinham tecnologia para isso.\n");
  printf("tambem cada jogador pode atacar ou movimentar uma peca, apenas uma vez por turno, caso ataque um lugar sem guerreiro, perdera a vez .\n");
  printf("\n");
  printf("\n");
  printf("   Funcao das pecas.\n");
  printf("   A peca 1 ela movimenta em cruz andando uma casa de cada vez e ataca em linha reta.\n");
  printf("   A peca 2 ela movimenta em cruz andando uma casa de cada vez e ataca em diagonal sendo necessario escolher qual delas.\n");
  printf("   A peca # ela movimenta em cruz andando uma casa de cada vez e tem como poder: na sua morte reviver uma peca sua como um guerreiro 1 onde voce queira no seu tabuleiro.\n");
  printf("   A peca @ ela movimenta em cruz andando uma casa de cada vez e tem como poder: na sua morte, escolher uma peca inimiga para matar.\n");
  printf("\n");
  printf("\n");
  printf("para comecar o jogo por gentileza siga os comandos abaixo.\n");
  printf("\n");
    printf("Escreva seu nome jogador do Norte: ");
    scanf(" %[^\n]s", nomeN);
    
    printf("Agora, escreva seu nome jogador do Sul: ");
    scanf(" %[^\n]s", nomeS);
    
    
    //Print da matriz
    printMatriz();
    
    //aleatoriedade
    srand(time(0));
      NumeroSorteado = rand() % 2;
    
      if(NumeroSorteado==0){
        printf("primeiro a escolher sera NORTE\n");
      }
      
      else{
        printf("primeiro a escolher sera SUL \n");
      }


  //CASO NORTE GANHA
  char peca;
  int conTg = 0;
  if(NumeroSorteado== 0){
    while(conTg != 16){
      if(NumeroSorteado==0){
          printf("Jogador do Norte,voce possui o tipo de peca 1 e o tipo 2\n");
          printf("Digite a linha e a coluna para marcar sua peca jogador norte: ");
          scanf("%i %i", &l, &c);
          getchar();
        
        if((l>6 ||l<1)||(c>11 ||c<1)){
            printf("digite uma posicao valida!\n");
            NumeroSorteado = 0;
        }	
        else {
          printf("Digite a peca que voce quer marcar: ");
          scanf(" %c", &peca);
          while (peca != '1' && peca !='2'){
            printf("Peca invalida\n");
            printf("Digite a peca que voce quer marcar: ");
            scanf(" %c", &peca);
          }
        
          if(mapa[l-1][c-1] == ' ') {
            marcarX(l-1, c-1, peca);
            system("cls");
            printMatriz();
            
            conTg++;	
            alternar();	
            
          }

          else {
            printf("digite uma posicao valida!\n");	
            NumeroSorteado = 0;
          }
        }  

      }
      else{
        printf("Jogador do Sul,voce possui o tipo de peca 1 e o tipo 2\n");
        printf("Digite a linha e a coluna para marcar sua peca jogador sul: ");
        scanf("%i %i", &l, &c);
        getchar();
        
        if((l>13 ||l<9)||(c>11 ||c<1)){
          printf("digite uma posicao valida!\n");		
        }	
            
        else {
          printf("Digite a peca que voce quer marcar: ");
          scanf(" %c", &peca);
          while (peca != '1' && peca !='2'){
            printf("Peca invalida\n");
            printf("Digite a peca que voce quer marcar: ");
            scanf(" %c", &peca);
          }
          
          if(mapa[l-1][c-1] == ' ') {
            marcarX(l-1, c-1, peca);
            system("cls");
            printMatriz();
            conTg++;
            alternar();		      
          }

          else {
            printf("digite uma posicao valida!\n");	
          }
        }  

      }
    }

    //peca especial SUL
    char pecaES;
    int CONT = 0;
    printf("Jogador do norte possui a peca especial #\n");
    printf("Jogador do sul possui a peca especial @\n");
    
    while(CONT !=1 ){
      printf("Digite a linha e coluna da peca especial jogador Sul: ");
      scanf("%i %i", &l, &c);
      getchar();
      
      if((l>13 ||l<9)||(c>11 ||c<1)){
        printf("digite uma posicao valida!\n");		
      }	       

      else if(mapa[l-1][c-1] == ' '){
        marcarZ(l-1, c-1, '@');
        system("cls");
        printMatriz();
        alternar(); 
        CONT++;
      }

      else {
        printf("digite uma posicao valida!\n");	
      }

    }

    //peca especial norte
    char pecaEN;
    int contad4 = 0;
    printf("Jogador do norte possui a peca especial #\n");
    printf("Jogador do sul possui a peca especial @\n");
    
    while(contad4 !=1 ){
      printf("Digite a linha e coluna da peca especial jogador Norte: ");
      scanf("%i %i", &l, &c);
      getchar();
      
      if((l>6 ||l<1)||(c>11 ||c<1)){
        printf("digite uma posicao valida!\n");	
      }	
        
      else if(mapa[l-1][c-1] == ' '){
        marcarY(l-1, c-1, '#');
        system("cls");
        printMatriz();
        contad4++;
      }

      else {
        printf("digite uma posicao valida!\n");	
      }
    }
      
    NumeroSorteado = 2;
  }

  //CASO SUL GANHA
  if(NumeroSorteado==1){
    int Cont = 0;
    while(Cont!=16) {
      
      if(NumeroSorteado==1){
        printf("Jogador do Sul,voce possui o tipo de peca 1 e o tipo 2\n");
        printf("Digite a linha e a coluna para marcar sua peca jogador sul: \n");
        scanf("%i %i", &l, &c);
        getchar();
        
        if((l>13 ||l<9)||(c>11 ||c<1)){
          printf("digite uma posicao valida!\n");		
        }

        else{
          printf("Digite a peca que voce quer marcar: ");
          scanf(" %c", &peca);
          
          while (peca != '1' && peca !='2'){
            printf("Peca invalida\n");
            printf("Digite a peca que voce quer marcar: ");
            scanf(" %c", &peca);
          }
          
          if(mapa[l-1][c-1] == ' ') {
            marcarX(l-1, c-1, peca);
            system("cls");
            printMatriz();
            alternar();	
            Cont++;	
          }

          else {
            printf("digite uma posicao valida!\n");	
          }
        }  

      }
      else{
        printf("Jogador do Norte,voce possui o tipo de peca 1 e o tipo 2\n"); 
        printf("Digite a linha e a coluna para marcar sua peca jogador norte: ");
        scanf("%i %i", &l, &c);
        getchar();
        
        if((l>6 ||l<1)||(c>11 ||c<1)){
          printf("digite uma posicao valida!\n");		
        }
              
        else 
          printf("Digite a peca que voce quer marcar: ");
          scanf(" %c", &peca);
          
          while (peca != '1' && peca !='2'){
            printf("Peca invalida\n");
            printf("Digite a peca que voce quer marcar: ");
            scanf(" %c", &peca);
          }
            
          if(mapa[l-1][c-1] == ' '){
            marcarX(l-1, c-1, peca);
            system("cls");
            printMatriz();
            alternar();		
            Cont++;
          }

          else {
            printf("digite uma posicao valida!\n");	
          }
      }  

    } 

    //peca especial norte
    char pecaEN2;
    int contad = 0;
    printf("Jogador do norte possui a peca especial #\n");
    printf("Jogador do sul possui a peca especial @\n");
    
    while(contad !=1 ){
      printf("Digite a linha e coluna da peca especial jogador Norte: ");
      scanf("%i %i", &l, &c);
      getchar();
      
      if((l>6 ||l<1)||(c>11 ||c<1)){
        printf("digite uma posicao valida!\n");	
      }	
        
      else if(mapa[l-1][c-1] == ' ') {
        marcarY2(l-1, c-1, '#');
        system("cls");
        printMatriz();
        alternar(); 
        contad++;
      }

        else {
          printf("digite uma posicao valida!\n");	
        }
    }

    //peca especial SUL
    char pecaES2;
    int CONT = 0;
    printf("Jogador do norte possui a peca especial #\n");
    printf("Jogador do sul possui a peca especial @\n");
    
    while(CONT !=1 ){
      printf("Digite a linha e coluna da peca especial jogador Sul: ");
      scanf("%i %i", &l, &c);
      getchar();
      if((l>13 ||l<9)||(c>11 ||c<1)){
        printf("digite uma posicao valida!\n");		
      }	       
      else if(mapa[l-1][c-1] == ' ') {
        marcarZ2(l-1, c-1, '@');
        system("cls");
        printMatriz();
        CONT++;
      }

      else {
        printf("digite uma posicao valida!\n");	
      }

    }
    NumeroSorteado = 1;
  }

  if(NumeroSorteado == 2){
    NumeroSorteado = 0;
  }

  int pecaS = 0, pecaN = 0;
  while(pecaS <9 || pecaN < 9){
    //Norte 
    //Movimentar ou atacar
    int valor;
    int cont1 = 0;
    char pecamov;
    if(NumeroSorteado == 0){
      while(cont1 != 1){
        if(NumeroSorteado == 0){
          teste:
          printf("Digite a linha e coluna da peca que vai movimentar ou atacar, jogador do Norte: ");
          scanf("%i %i", &l, &c);
          getchar();
          
          if((l>6 || l<=1 ) || (c>11 ||c<1) || (mapa[l-1][c-1] == ' ')|| (l == 2) || (l == 7) || (l == 8) || (l == 13) || (c == 1) || (c == 12)){
            printf("digite uma posicao valida!\n");
          }

          else{
            printf("Digite '3' para atacar ou '4' para movimentar sua peca, jogador do Norte\n");
            scanf(" %d", &valor);
                
            while(valor != 3 && valor != 4){
              printf("Digite um valor valido\n");
              printf("Digite '3' para atacar ou '4' para movimentar sua peca, jogador do Norte\n");
              scanf(" %d", &valor);
            }

            char movimento;  
            int conta_mov = 0, h = 0, v = 0;
            int hor, ver, linha, coluna, contadorAN = 0, conttN=0; 
            int contx;  
            int direcaoN; 
            int CONTES = 0;    
            switch (valor){
              case 3:
                coluna = c;
                while (contadorAN != 1){
                  
                  
                  
                  while(mapa[l-1][c-1] == '@' || mapa[l-1][c-1] == '#'){
                    printf("Essa peca nao pode atacar\n");
                    goto teste;
                  }
                


                  //ataque peca 1 
                  if (mapa[l-1][c-1] == '1'){
            
                    for(linha = 9;linha < 13 ; linha ++){ 
                      
                      if (mapa [linha-1][coluna-1] == '1' || mapa[linha-1][coluna-1] == '2'){
                          
                        l = linha ;
                        c = coluna;
                  
                        mapa[l-1][c-1] = ' ';
                        system("cls");
                        printMatriz();
                        
                        
                        printf("o Guerreiro da linha %i e %i coluna morreu\n", l,c);
                        pecaN++;
                        contadorAN++;
                        alternar();
                        cont1++;

                        if (pecaN == 9) {
                          printf("FIM DE JOGO\n");
                          printf("Norte Venceu\n");
                          goto fimjogo; 
                        }
                        
                        if (pecaS == 9){
                          printf("FIM DE JOGO\n");
                          printf("Sul Venceu o Jogo\n");
                          goto fimjogo; 
                        }
                        break;
                      }
                      
                      if ((coluna > 0 && coluna < 13)&& (mapa [linha-1][coluna-1] == '@')) {
                        l = linha ;
                        c = coluna;
                  
                        mapa[l-1][c-1] = ' ';
                        system("cls");
                        printMatriz();
                        
                        printf("o xama da linha %i e coluna %i  morreu\n", l,c);
                        printf("devido a  habilidade especial do xama, escolha uma peca para matar.\n");
                        
                        while(CONTES !=1 ){

                          printf("Digite a linha e coluna da peca que voce que matar jogador Sul\n ");
                          scanf("%i %i", &l, &c);
                          getchar();
                          
                          if((l>6 ||l<1)||(c>11 ||c<1)){
                            printf("digite uma posicao valida!\n");	
                          }	       
                          
                          else if(mapa[l-1][c-1] == '1'||mapa[l-1][c-1] == '2') {
                            printf("o guerreiro da linha %i e %i coluna morreu\n", l,c);
                            mapa[l-1][c-1] = ' ';
                            system("cls");
                            printMatriz();
                            CONTES++;
                          }

                          else {
                            printf("digite uma posicao valida!\n");	
                          }

                        }                                                                                                                                                                                                                                            
                        pecaS++;
                        contadorAN++;
                        pecaN++;
                        alternar();
                        cont1++;
                        
                        if (pecaN == 9) {
                          printf("FIM DE JOGO\n");
                          printf("Norte Venceu\n"); 
                          goto fimjogo; 
                        }

                        if (pecaS == 9){
                          printf("FIM DE JOGO\n");
                          printf("Sul Venceu o Jogo\n");
                          goto fimjogo; 
                        }
                        break;
                      }
                      
                      else if (conttN !=4){
                        conttN++;
                      }

                      else{
                        printf("o ataque falhou! perdeu a vez!\n");
                        contadorAN++;
                        alternar(); 
                        cont1++;
                        break;
                      }
                      
                    }//for termina aqui
                  }
                
                  //ataque 2
                  if (mapa[l-1][c-1] == '2'){
                    printf("Digite 1 para direita ou 2 para esquerda\n"); 
                    scanf(" %d", &direcaoN);

                    switch(direcaoN){
                    
                      case 1:
                        //direita
                        while(l !=8){
                          coluna++;
                          l++;
                        }
                        for(linha = 9;linha < 13 ; linha ++){ 
                          coluna++;
                            
                          if ((coluna > 0 && coluna < 13)&& (mapa [linha-1][coluna-1] == '1' || mapa[linha-1][coluna-1] == '2' )){   
                            l = linha ;
                            c = coluna;
                      
                            mapa[l-1][c-1] = ' ';
                            system("cls");
                            printMatriz();
                            
                            printf("o Guerreiro da linha %i e %i coluna morreu\n", l,c);
                            contadorAN++;
                            pecaN++;
                            alternar();
                            cont1++;
                            
                            if (pecaN == 9) {
                              printf("FIM DE JOGO\n");
                              printf("Norte Venceu\n"); 
                              goto fimjogo; 
                            }
                            
                            if (pecaS == 9){
                              printf("FIM DE JOGO\n");
                              printf("Sul Venceu o Jogo\n");
                              goto fimjogo; 
                            }
                            break;
                          }
                            
                          if ((coluna > 0 && coluna < 13)&& (mapa [linha-1][coluna-1] == '@')){
                            l = linha ;
                            c = coluna;
                      
                            mapa[l-1][c-1] = ' ';
                            system("cls");
                            printMatriz();
                            
                            
                            printf("o xama da linha %i e %i coluna morreu\n", l,c);
                            printf("devido a sua habilidade escolha uma peca para matar com ele.\n");
                            
                            while(CONTES !=1 ){
                              printf("Digite a linha e coluna da peca que voce que matar jogador Sul\n ");
                              scanf("%i %i", &l, &c);
                              getchar();
                              
                              if((l>6 ||l<1)||(c>11 ||c<1)){
                                printf("digite uma posicao valida!\n");	
                              }	
                                     
                              else if(mapa[l-1][c-1] == '1'||mapa[l-1][c-1] == '2') {
                                printf("o guerreiro da linha %i e %i coluna morreu\n", l,c);
                                mapa[l-1][c-1] = ' ';
                                system("cls");
                                printMatriz();
                                CONTES++;
                              }

                              else {
                                printf("digite uma posicao valida!\n");	
                              }
                            }                                                                                                                                            
                            pecaS++;
                            contadorAN++;
                            pecaN++;
                            alternar();
                            cont1++;
                            if (pecaN == 9) {
                              printf("FIM DE JOGO\n");
                              printf("Norte Venceu\n"); 
                              goto fimjogo; 
                            }

                            if (pecaS == 9){
                              printf("FIM DE JOGO\n");
                              printf("Sul Venceu o Jogo\n");
                              goto fimjogo; 
                            }
                            break;
                          }

                          else if ( conttN !=4){
                            conttN++;
                          }

                          if(conttN == 4){
                            printf("o ataque falhou! perdeu a vez!\n");
                            contadorAN++;
                            pecaN++;
                            alternar(); 
                            cont1++;
                            break;
                          }

                        }//for termina aqui
                        break;
                    
                      case 2:

                        //esquerda
                        while(l !=8){
                          coluna--;
                          l++;        
                        }

                        for(linha = 9;linha < 13 ; linha ++){ 
                          coluna--;
                            
                          if ((coluna > 0 && coluna < 13)&&(mapa [linha-1][coluna-1] == '1' || mapa[linha-1][coluna-1] == '2' || mapa [linha-1][coluna-1] == '@')){

                            l = linha ;
                            c = coluna;
                      
                            mapa[l-1][c-1] = ' ';
                            system("cls");
                            printMatriz();
                            
                            printf("o Guerreiro da linha %i e %i coluna morreu\n", l,c);
                            contadorAN++;
                            pecaN++;
                            alternar();
                            cont1++;
                            if (pecaN == 9) {
                              printf("FIM DE JOGO\n");
                              printf("Norte Venceu\n"); 
                              goto fimjogo; 
                            }
                            
                            if (pecaS == 9){
                              printf("FIM DE JOGO\n");
                              printf("Sul Venceu o Jogo\n");
                              goto fimjogo; 
                            }
                            break;
                          }

                          if ((coluna > 0 && coluna < 13)&& (mapa [linha-1][coluna-1] == '@')) {
                              
                            l = linha ;
                            c = coluna;
                      
                            mapa[l-1][c-1] = ' ';
                            pecaS++;
                            system("cls");
                            printMatriz();
                            
                            printf("o xama da linha %i e %i coluna morreu\n", l,c);
                            printf("devido a sua habilidade escolha uma peca para matar com ele.\n");
                            
                            while(CONTES !=1 ){
                              printf("Digite a linha e coluna da peca que voce que matar jogador Sul\n ");
                              scanf("%i %i", &l, &c);
                              getchar();

                              if((l>6 ||l<1)||(c>11 ||c<1)){
                                printf("digite uma posicao valida!\n");	
                              }	
                                      
                              else if(mapa[l-1][c-1] == '1'||mapa[l-1][c-1] == '2') {
                                printf("o guerreiro da linha %i e %i coluna morreu\n", l,c);
                                mapa[l-1][c-1] = ' ';
                                system("cls");
                                printMatriz();
                                CONTES++;
                              }

                              else {
                                printf("digite uma posicao valida!\n");	
                              }

                            }                                                                                                            
                            pecaS++;
                            contadorAN++;
                            pecaN++;
                            alternar();
                            cont1++;
                            
                            if (pecaN == 9) {
                              printf("FIM DE JOGO\n");
                              printf("Norte Venceu\n"); 
                              goto fimjogo; 
                            }

                            if (pecaS == 9){
                              printf("FIM DE JOGO\n");
                              printf("Sul Venceu o Jogo\n");
                              goto fimjogo; 
                            }
                            break;
                          }
                            
                          else if ( conttN !=4){
                          conttN++;
                          }

                          if(conttN == 4){
                            printf("o ataque falhou! perdeu a vez!\n");
                            contadorAN++;
                            pecaN++;
                            alternar(); 
                            cont1++;
                            break;
                          } 
                        }//for termina aqui
                        break;

                    }

                  }

                }



    

                    break;
                      
                  
                case 4:
                  //movimentar

                  while (conta_mov != 1){
                    printf("Digite para onde voce quer mover a peca\n");
                    printf("Digite 'E', para esquerda\n");
                    printf("Digite 'D', para a direita\n"); 
                    printf("Digite 'C', para cima\n"); 
                    printf("Digite 'B', para baixo\n");

                    scanf(" %s", &movimento);
                    getchar();
                    
                    while ( (movimento != 'e' && movimento != 'E') && (movimento != 'd' && movimento != 'D') 
                    && (movimento !='c' && movimento !='C') && (movimento !='b' && movimento != 'B') ){
              
                      printf("Digite o valor correto!\n");
                      printf("\n");
                      printf("Digite para onde voce quer mover a peca\n");
                      printf("Digite 'E', para esquerda\n");
                      printf("Digite 'D', para a direita\n"); 
                      printf("Digite 'C', para cima\n"); 
                      printf("Digite 'B', para baixo\n");
                      scanf(" %s", &movimento);
                      getchar();
                    }
            
                    if(movimento == 'E'|| movimento == 'e'){
                      l = l-1;
                      c = c-1;
                      h = l;
                      v = c-1;

                      if(mapa [h][v] != ' '){
                        printf("Digite um movimento valido!\n");
                      }
                      
                      else {
                        mapa [h][v] = mapa [l][c];
                        mapa [l][c] = ' ';
                        system("cls");
                        printMatriz();
                        conta_mov++;
                        alternar();
                        cont1++;
                      }
                      
                      l = l+1;
                      c = c+1;
                    }
                  
                    if(movimento == 'C' || movimento == 'c'){
                      l = l-1;
                      c = c-1;
                      h = l-1;
                      v = c;

                      if(mapa [h][v] != ' '){
                        printf("Digite um movimento valido!\n");
                      }
                      else {
                        mapa [h][v] = mapa [l][c];
                        mapa [l][c] = ' ';
                        system("cls");
                        printMatriz();
                        conta_mov++;
                        alternar();
                        cont1++;
                      }

                      l = l+1;
                      c = c+1;
                    }
                    
                    if(movimento == 'B' || movimento == 'b'){
                      l = l-1;
                      c = c-1;
                      h = l+1;
                      v = c;
                      
                      if(mapa [h][v] != ' '){
                        printf("Digite um movimento valido!\n");
                      }
                      
                      else {
                        mapa [h][v] = mapa [l][c];
                        mapa [l][c] = ' ';
                        system("cls");
                        printMatriz();
                        conta_mov++;
                        alternar();
                        cont1++;
                      }
                      
                      l = l+1;
                      c = c+1;
                    }

                    if(movimento == 'D' || movimento == 'd'){
                      l = l-1;
                      c = c-1;
                      h = l;
                      v = c+1;
                      
                      if(mapa [h][v] != ' '){
                        printf("Digite um movimento valido!\n");
                      }
                      
                      else {
                        mapa [h][v] = mapa [l][c];
                        mapa [l][c] = ' ';
                        system("cls");
                        printMatriz();
                        conta_mov++;
                        alternar();
                        cont1++;
                      }

                      l = l+1;
                      c = c+1;
                    }
                  
                  }
                  break;

            }

          }
        }
      }
    }

    //Sul 
    int valorS;
    int contS = 0;
    char pecamovS;

    if(NumeroSorteado==1){
      while(contS != 1){
        if(NumeroSorteado==1){
          teste2:
          printf("Digite a linha e coluna da peca que vai movimentar ou atacar, jogador do Sul: ");
          scanf("%i %i", &l, &c);
          getchar();
          
          if((l>13 ||l<9)||(c>11 ||c<1) || (mapa[l-1][c-1] == ' ')|| (l == 2) || (l == 7) || (l == 8) || (l == 13) || (c == 1) || (c == 12)){
            printf("digite uma posicao valida!\n");
          }

          else{
            printf("Digite '3' para atacar ou '4' para movimentar sua peca, jogador do Sul\n");
            scanf(" %d", &valorS);
            
            while(valorS != 3 && valorS != 4){
              printf("Digite um valor valido\n");
              printf("Digite '3' para atacar ou '4' para movimentar sua peca, jogador do Sul\n");
              scanf(" %d", &valorS);
            }
            int direcaoS;
            char movimento;  
            int conta_movS = 0, h = 0, v = 0;
            int hor, ver, linha, coluna, contadorAS = 0, contt=0;
            int CONTEN= 0;
            switch (valorS){
              
              case 3:
               
                coluna = c;
                while (contadorAS != 1){

                  while(mapa[l-1][c-1] == '@' || mapa[l-1][c-1] == '#'){
                    printf("Essa peca nao pode atacar\n");
                    goto teste2;
                  }
            
                  //ataque peca 1
                  if (mapa[l-1][c-1] == '1'){
              
                    for(linha = 6;linha > 2; linha --){ 
                      
                      if (mapa [linha-1][coluna-1] == '1' || mapa[linha-1][coluna-1] == '2'){
                          
                        l = linha ;
                        c = coluna;
                  
                        mapa[l-1][c-1] = ' ';
                        system("cls");
                        printMatriz();
                      
                        printf("o Guerreiro da linha %i e coluna %i morreu\n", l,c);
                        pecaS++;
                        contadorAS++;
                        alternar();
                        contS++;

                        if (pecaN == 9) {
                          printf("FIM DE JOGO\n");
                          printf("Norte Venceu\n");
                          goto fimjogo; 
                        }

                        if (pecaS == 9){
                          printf("FIM DE JOGO\n");
                          printf("Sul Venceu o Jogo\n");
                          goto fimjogo; 
                        }

                        break;
                      }
                      
                      if(mapa [linha-1][coluna-1] == '#') {
                        
                        l = linha ;
                        c = coluna;
                
                        mapa[l-1][c-1] = ' ';
                        system("cls");
                        printMatriz();
                        
                        printf("o xama da linha %i e coluna %i morreu\n", l,c);
                        printf("devido a sua habilidade escolha razer dos mortos uma peca como um guerreiro 1 .\n");
                      
                        while(CONTEN !=1 ){

                          printf("Digite a linha e coluna da peca onde voce que reviver seu guerreiro jogador Norte.\n ");
                          scanf("%i %i", &l, &c);
                          getchar();
                          if((l>6 ||l<1)||(c>11 ||c<1)){
                            printf("digite uma posicao valida!\n");	
                          }

                          else if(mapa[l-1][c-1] == ' ') {
                            printf("o guerreiro da linha %i e coluna %i reviveu\n", l,c);
                            mapa[l-1][c-1] = '1';
                            system("cls");
                            printMatriz();
                            CONTEN++;
                          }

                          else {
                            printf("digite uma posicao valida!\n");	
                          }

                        }                                                                                                                                                                                                              
                        contadorAS++;
                        alternar();
                        contS++;

                        if (pecaN == 9) {
                          printf("FIM DE JOGO\n");
                          printf("Norte Venceu\n"); 
                          goto fimjogo; 
                        }

                        if (pecaS == 9){
                          printf("FIM DE JOGO\n");
                          printf("Sul Venceu o Jogo\n");
                          goto fimjogo; 
                        }

                        break;
                        }

                        else if (contt !=4){
                          contt++;
                        }

                        else{
                          printf("o ataque falhou! perdeu a vez!\n");
                          contadorAS++;
                          alternar(); 
                          contS++;
                          break;
                        }
                      
                    }//for termina aqui
                  }

                  //ataque 2
                
                  if (mapa[l-1][c-1] == '2'){
                    printf("Digite 1 para direita ou 2 para esquerda\n"); 
                    scanf(" %d", &direcaoS);

                    switch(direcaoS){
            
                      case 1:

                        //direita
                        while(l !=7){
                          coluna++;
                          l--; 
                        }
                        for(linha = 6;linha > 2 ; linha --){ 
                          coluna++;
                              
                          if ((coluna > 0 && coluna < 13)&& (mapa [linha-1][coluna-1] == '1' || mapa[linha-1][coluna-1] == '2')) {
                                  
                            l = linha ;
                            c = coluna;
                      
                            mapa[l-1][c-1] = ' ';
                            system("cls");
                            printMatriz();
                            
                            
                            printf("o Guerreiro da linha %i e %i coluna morreu\n", l,c);
                            contadorAS++;
                            pecaS++;
                            alternar();
                            contS++;

                            if (pecaN == 9) {
                              printf("FIM DE JOGO\n");
                              printf("Norte Venceu\n"); 
                              goto fimjogo; 
                            }

                            if (pecaS == 9){
                              printf("FIM DE JOGO\n");
                              printf("Sul Venceu o Jogo\n");
                              goto fimjogo; 
                            }

                            break;
                          }



if((coluna > 0 && coluna < 13)&&(mapa [linha-1][coluna-1] == '#')) {
                        
                        l = linha ;
                        c = coluna;
                
                        mapa[l-1][c-1] = ' ';
                        system("cls");
                        printMatriz();
                        
                        printf("o xama da linha %i e coluna %i morreu\n", l,c);
                        printf("devido a sua habilidade escolha razer dos mortos uma peca como um guerreiro 1 .\n");
                      
                        while(CONTEN !=1 ){

                          printf("Digite a linha e coluna da peca onde voce que reviver seu guerreiro jogador Norte.\n ");
                          scanf("%i %i", &l, &c);
                          getchar();
                          if((l>6 ||l<1)||(c>11 ||c<1)){
                            printf("digite uma posicao valida!\n");	
                          }

                          else if(mapa[l-1][c-1] == ' ') {
                            printf("o guerreiro da linha %i e coluna %i reviveu\n", l,c);
                            mapa[l-1][c-1] = '1';
                            system("cls");
                            printMatriz();
                            CONTEN++;
                          }

                          else {
                            printf("digite uma posicao valida!\n");	
                          }

                        }                                                                                                                                                                                                              
                        contadorAS++;
                        alternar();
                        contS++;

                        if (pecaN == 9) {
                          printf("FIM DE JOGO\n");
                          printf("Norte Venceu\n"); 
                          goto fimjogo; 
                        }

                        if (pecaS == 9){
                          printf("FIM DE JOGO\n");
                          printf("Sul Venceu o Jogo\n");
                          goto fimjogo; 
                        }

                        break;
                        }



                          else if ( contt !=4){
                            contt++;
                          }
                          if(contt == 4){
                            printf("o ataque falhou! perdeu a vez!\n");
                            contadorAS++;
                            pecaS++;
                            alternar(); 
                            contS++;
                            break;
                          }
                                  
                        }//for termina aqui
                        break;
        
                      case 2:

                        //esquerda
                        while(l !=7){
                          coluna--;
                          l--;
                        }
                        for(linha = 6;linha > 2 ; linha --){ 
                          coluna--;
                            
                            if ((coluna > 0 && coluna < 13)&&(mapa [linha-1][coluna-1] == '1' || mapa[linha-1][coluna-1] == '2') ){
                            
                                
                              l = linha ;
                              c = coluna;
                        
                              mapa[l-1][c-1] = ' ';
                              system("cls");
                              printMatriz();
                              
                              printf("o Guerreiro da linha %i e %i coluna morreu\n", l,c);
                              contadorAS++;
                              pecaS++;
                              alternar();
                              contS++;
                              
                              if (pecaN == 9) {
                                printf("FIM DE JOGO\n");
                                printf("Norte Venceu\n"); 
                                goto fimjogo; 
                              }

                              if (pecaS == 9){
                                printf("FIM DE JOGO\n");
                                printf("Sul Venceu o Jogo\n");
                                goto fimjogo; 
                              }
                              break;
                            }






if((coluna > 0 && coluna < 13)&&(mapa [linha-1][coluna-1] == '#')) {
                        
                        l = linha ;
                        c = coluna;
                
                        mapa[l-1][c-1] = ' ';
                        system("cls");
                        printMatriz();
                        
                        printf("o xama da linha %i e coluna %i morreu\n", l,c);
                        printf("devido a sua habilidade escolha razer dos mortos uma peca como um guerreiro 1 .\n");
                      
                        while(CONTEN !=1 ){

                          printf("Digite a linha e coluna da peca onde voce que reviver seu guerreiro jogador Norte.\n ");
                          scanf("%i %i", &l, &c);
                          getchar();
                          if((l>6 ||l<1)||(c>11 ||c<1)){
                            printf("digite uma posicao valida!\n");	
                          }

                          else if(mapa[l-1][c-1] == ' ') {
                            printf("o guerreiro da linha %i e coluna %i reviveu\n", l,c);
                            mapa[l-1][c-1] = '1';
                            system("cls");
                            printMatriz();
                            CONTEN++;
                          }

                          else {
                            printf("digite uma posicao valida!\n");	
                          }

                        }                                                                                                                                                                                                              
                        contadorAS++;
                        alternar();
                        contS++;

                        if (pecaN == 9) {
                          printf("FIM DE JOGO\n");
                          printf("Norte Venceu\n"); 
                          goto fimjogo; 
                        }

                        if (pecaS == 9){
                          printf("FIM DE JOGO\n");
                          printf("Sul Venceu o Jogo\n");
                          goto fimjogo; 
                        }

                        break;
                        }

                            else if (contt !=4){
                              contt++;
                            }
                            if(contt == 4){
                              printf("o ataque falhou! perdeu a vez!\n");
                              contadorAS++;
                              pecaS++;
                              alternar(); 
                              contS++;
                              break;
                            }
                    
                        }//for termina aqui
                        break;
                    }
                  }


                }

                 break;

              case 4:

                while (conta_movS != 1){

                  printf("Digite para onde voce quer mover a peca\n");
                  printf("Digite 'E', para esquerda\n");
                  printf("Digite 'D', para a direita\n"); 
                  printf("Digite 'C', para cima\n"); 
                  printf("Digite 'B', para baixo\n");

                  scanf(" %s", &movimento);
                  getchar();
                    
                  if(movimento == 'E'|| movimento == 'e'){
                    l = l-1;
                    c = c-1;
                    h = l;
                    v = c-1;
                    
                    if(mapa [h][v] != ' '){
                      printf("Digite um movimento valido!\n");
                    }
                    
                    else {
                      mapa [h][v] = mapa [l][c];
                      mapa [l][c] = ' ';
                      system("cls");
                      printMatriz();
                      conta_movS++;
                      alternar();
                      contS++;
                    }

                    l = l+1;
                    c = c+1;
                  }
            
                  if(movimento == 'C' || movimento == 'c'){
                    l = l-1;
                    c = c-1;
                    h = l-1;
                    v = c;
                    
                    if(mapa [h][v] != ' '){
                      printf("Digite um movimento valido!\n");
                    }
                    
                    else {
                      mapa [h][v] = mapa [l][c];
                      mapa [l][c] = ' ';
                      system("cls");
                      printMatriz();
                      conta_movS++;
                      alternar();
                      contS++;
                    }

                    l = l+1;
                    c = c+1;
                  }
              
                  if(movimento == 'B' || movimento == 'b'){
                    l = l-1;
                    c = c-1;
                    h = l+1;
                    v = c;
                    
                    if(mapa [h][v] != ' '){
                      printf("Digite um movimento valido!\n");
                    }
                    
                    else {
                      mapa [h][v] = mapa [l][c];
                      mapa [l][c] = ' ';
                      system("cls");
                      printMatriz();
                      conta_movS++;
                      alternar();
                      contS++;
                    }

                    l = l+1;
                    c = c+1;
                  }
              
                  if(movimento == 'D' || movimento == 'd'){
                    l = l-1;
                    c = c-1;
                    h = l;
                    v = c+1;
                    
                    if(mapa [h][v] != ' '){
                      printf("Digite um movimento valido!\n");
                    }
                    
                    else {
                      mapa [h][v] = mapa [l][c];
                      mapa [l][c] = ' ';
                      system("cls");
                      printMatriz();
                      conta_movS++;
                      alternar();
                      contS++;
                    }

                    l = l+1;
                    c = c+1;
                  }
                
                }
                

                break;


            }


          }
        }

      }
    } // Sul comeca acaba aqui




  }

  fimjogo:

  return 0;
}
