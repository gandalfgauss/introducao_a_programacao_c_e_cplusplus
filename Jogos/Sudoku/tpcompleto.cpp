#include <iostream>
#include <fstream>
#include <cstring>
//Professor vale lembrar que meu programa ta funcionando de acordo com o arquivo de texto deixado no moodle com espaço.
using namespace std;

void bem_vindo();//Imprime uma mensagem de Bem Vindo ao usuário.
void ler_arquivo_de_texto(ifstream& arquivo, int matriz[9][9], char nome_do_arquivo[100]);//Essa função pega o arquivo de texto.txt como referência,e,uma matriz como parâmetro e coloca numa matriz.
void como_jogar();//Essa função mostra como jogar e os comandos necessários;
void imprime_matriz(int matriz[9][9]);//Essa função pega uma matriz como parâmetro e a imprimi de acordo com o sudoku.
bool confere_comando(char comando[11]);//Essa função pega um vetor como parâmetro,retorna valores booleanos conferindo o comando digitado.
void conveter_char_para_int(char comando[11], int &linha, int &coluna, int &numero_a_alocar);//Essa função converte char para int e atribui os comandos para linha, coluna e número a alocar,com passagem por referência.
bool confere_linha(int matriz[9][9], int linha, int coluna, int numero_a_alocar);//Essa função recebe uma matriz como parâmetro, a linha e o numero_a_alocar, e, confere a presença de elementos repetidos na mesma linha da matriz.Retorna falso se estiver um elemento repetido e verdadeiro caso contrário.
bool confere_coluna(int matriz[9][9], int coluna, int linha,int numero_a_alocar);//Essa função recebe uma matriz como parâmetro, a coluna e o numero_a_alocar, e, confere a presença de elementos repetidos na mesma coluna da matriz.Retorna falso se estiver um elemento repetido e verdadeiro caso contrário.
bool confere_regioes(int matriz[9][9], int linha, int coluna, int numero_a_alocar);//Essa funçao recebe uma matriz como parâmetro,um numero a alocar, a linha, a coluna, e confere se existe um número igual na mesma região, caso exista retorna falso, se não retorna verdadeiro .

void confere_linha_e_imprime(int matriz[9][9], int linha, int coluna, int numero_a_alocar);//Essa função tem a mesma função que a sua boolena mas serve para imprimir mensagens de erro.
void confere_coluna_e_imprime(int matriz[9][9], int coluna, int linha, int numero_a_alocar);//Essa função tem a mesma função que a sua boolena mas serve para imprimir mensagens de erro.
void confere_regioes_e_imprime(int matriz[9][9], int linha, int coluna, int numero_a_alocar);//Essa função tem a mesma função que a sua boolena mas serve para imprimir mensagens de erro.

void alocar_na_matriz(int matriz[9][9], int linha, int coluna, int numero_a_alocar);//Essa função recebe a linha , a coluna, e o numero que o usário deseja alocar e colocar na matriz.
void salvar_matriz(int matriz[9][9], ofstream& arq1, char nome_do_arquivo[100]);//Essa função leva um matriz como parâmetro, um arquivo como referência, o nome do arquivo, para salvar a matriz no arquivo de texto já existente.

bool confere_numeros_fixos(int matriz_copia[9][9], int linha, int coluna);//Recebe os números fixos  de uma matriz cópia e retorna falso caso o usário tente alteralos.
void confere_numeros_fixos_e_imprime(int matriz_copia[9][9], int linha, int coluna);//Recebe os números fixos  de uma matriz cópia e imprime erro caso o usário tente alteralos.

void reinicia_jogo(int matriz[9][9], int matriz_copia[9][9]);//Essa função pega a matriz alterada e volta ela ao normal.

bool vitoria(int matriz[9][9]);//Essa função pega a matriz principal e procura zeros, se não tiver nenhum retorna falso, caso contrário verdadeiro.

int main()
{
    ifstream arquivo;

    char c = 0;//Constante para ajudar a verificar a existencia de uma copia.
    int matriz_copia[9][9];//Essa matriz vai servir para gravar os números da matriz principal na posição inicial.
    char nome_do_arquivo[100];
    int linha, coluna, numero_a_alocar;
    int matriz[9][9];//Declara matriz.
    int numero_para_sair = 0;//Número para sair do loop.
    char comando[11];//Variável que irá receber os comandos.

    char copia[30] = {'c','o','p','i','a','\0'};
    char sair[30] = {'s','a','i','r','\0'};
    char salvar[30] = {'s','a','l','v','a','r','\0'};
    char reiniciar[30] = {'r','e','i','n','i','c','i','a','r','\0'};

    bem_vindo();//chamada da função bem_vindo;
    como_jogar();//Instruções de jogo.
    ler_arquivo_de_texto(arquivo, matriz,nome_do_arquivo);//Chamada da função ler_arquivo_de_texto.
    imprime_matriz(matriz);//Chamada da função imprimi_matriz.

    ifstream arq_copia_in;//Declara um arquico cópia
    arq_copia_in.open(strcat(copia,nome_do_arquivo));//Abre o arquivo com o nome : copia"nome_do_arquivo".txt se ele não existir c é nulo logo entra na condição e cria o arquivo.
    arq_copia_in.get(c);//Anda na primeira posição do arquivo


    if(c == 0)//Se o valor for NULL
    {
      arq_copia_in.close();//Fecha o arquivo.

      ofstream arq_copia_out;
      arq_copia_out.open(copia);//Cria o arquivo copia.

      for(int i = 0; i < 9; i++)//Preenche o arquivo copia com a posição inicial da matriz principal
      {
        for(int j = 0; j < 9; j++)
        {
          arq_copia_out << matriz[i][j] << " ";
        }
        arq_copia_out << '\n';
      }
      arq_copia_out.close();//fecha o arquivo de entrada

      arq_copia_in.open(copia);//abre o arquvio de saída

      for(int i = 0; i < 9; i++)//passa os valores da copia para a matriz copia
          for(int j = 0; j < 9; j++)
                arq_copia_in >> matriz_copia[i][j];

      arq_copia_in.close();//fecha arquivo de saída.
    }

    else//Se o valor não for NULL, já existe um arquivo de copia e é necessário salvar por cima, logo entra no else.
    {
      arq_copia_in.close();//fecha aquivo de saída
      arq_copia_in.open(copia);//abre arquivo de saída

      for(int i = 0; i < 9; i++)//passa os valores da cópia para matriz cópia
          for(int j = 0; j < 9; j++)
              arq_copia_in >> matriz_copia[i][j];

              arq_copia_in.close();//fecha arquivo.
    }

    while(numero_para_sair == 0 && vitoria(matriz))//Loop do jogo só sai do loop quando o usuário digita "sair".
    {
      cout <<"\nDigite um comando ou indique a célula a alterar: " << endl;
      cin >> comando;//Recebe o comando.

      if( !strcmp(comando,sair))//Se o comando for igual a "sair" retorna 1 e acrescenta 1 em numero_para_sair e sai do loop.
      {
          numero_para_sair++;
          cout <<"\nAté logo !" << endl <<"Você saiu do jogo." << endl;
      }

      else if(!strcmp(comando,salvar))//Se o comando for igual a salvar,salva o jogo.
      {
          ofstream arq1;//Declara um arquivo.
          salvar_matriz(matriz,arq1,nome_do_arquivo);
          cout <<"\nJogo foi salvo em :" << nome_do_arquivo << endl;

      }

      else if(!strcmp(comando,reiniciar))//Reinicia o jogo
      {
          reinicia_jogo(matriz, matriz_copia);//Chama a função para reiniciar o jogo.
          imprime_matriz(matriz);
          cout <<"\nJogo Reiniciado." << endl;
      }

      else if(confere_comando(comando))//Entra se o comando for válido, confere o comando por meio da função confere_comando.
      {
        conveter_char_para_int(comando, linha, coluna, numero_a_alocar);//Passa a linha, coluna e numero_a_alocar como referência e o comando como parâmetro.

        if(!confere_numeros_fixos(matriz_copia, linha, coluna))//Se achar o número fixo vai retornar verdadeiro e imprime somento que o número fixo está incorreto.
          confere_numeros_fixos_e_imprime(matriz_copia, linha, coluna);//Chama a função para imprimir erro caso o usuário tente alterar um número fixo do jogo.

        else
        {
          confere_linha_e_imprime(matriz, linha, coluna,numero_a_alocar);//Chama a função para imprimir erros na linha.
          confere_coluna_e_imprime(matriz, coluna, linha, numero_a_alocar);//Chama a função para imprimir erros na coluna
          confere_regioes_e_imprime(matriz, linha, coluna, numero_a_alocar);//Chama função para imprimir erros nas regiões.
        }

        if(confere_linha(matriz,linha,coluna,numero_a_alocar) && confere_coluna(matriz,coluna, linha,numero_a_alocar) && confere_regioes(matriz,linha,coluna,numero_a_alocar) && confere_numeros_fixos(matriz_copia, linha, coluna))//Se todas as condições for satisfeitas ele entra.
        {
            alocar_na_matriz(matriz, linha, coluna, numero_a_alocar);//Essa função aloca o número solicitado na matriz.
            imprime_matriz(matriz);
        }
      }

      else//Se não, logo o comando é falso, imprime mensagem de erro.
        cout << "\nErro! Digite o comando corretamente" << endl;
    }

  return 0;
}

void bem_vindo()//Imprime uma mensagem de Bem Vindo ao usuário.
{
    cout <<"\n\t\t\tSeja Bem Vindo ao Sudoku !!!\n\n" << endl;//Imprime a mensagem de boas vindas.
}//Fim da função.

void ler_arquivo_de_texto(ifstream& arquivo, int matriz[9][9],char nome_do_arquivo[100])//Essa função pega o arquivo de texto.txt como referência,e,uma matriz como parâmetro e coloca numa matriz.
{
    cout <<"\nIndique o arquivo texto contendo o jogo: ";
    cin >> nome_do_arquivo;//Lê o nome do arquivo.txt.

    arquivo.open(nome_do_arquivo);//Abre o arquivo.txt.

    for(int i = 0; i < 9; i++)//Passando os valor do arquivo para a matriz.
      for(int j = 0; j < 9; j++)
        arquivo >> matriz[i][j];

  arquivo.close();//Fecha o arquivo.

}//Termina a função.

void como_jogar()//Essa função mostra como jogar e os comandos necessários;
{
  cout <<"\nPara jogar é bem simples !!" << endl;
  cout <<"Digite a linha, coluna e o número que deseja alocar tudo junto" << endl;
  cout<<"Caso o número a alocar seja 0, irá apagar o número naquela posição." << endl;
  cout <<"Digite salvar para salvar, sair para sair, e reiniciar para recomeçar." << endl;
}//Fim da Função.

void imprime_matriz(int matriz[9][9])//Essa função pega uma matriz como parâmetro e a imprimi de acordo com o sudoku.
{
  int numeros_das_linhas = 1;

  cout <<"\n   1 2 3   4 5 6   7 8 9" << endl << endl;//Imprime os número acima do jogo referente as colunas.

    for(int i = 0; i < 9; i++)//Loop para imprimir a matriz.
    {
      cout << numeros_das_linhas << ") ";//Imprime os números a esquerda referente as linhas do jogo.

      for(int j = 0; j < 9; j++)
      {

          if(matriz[i][j] == 0)//Se o número for 0.
          {
              if( j == 2 || j == 5)//Se o número for 0 e as colunas forem 2 ou 5 imprimir "_" com um espaço maior para separar as regiões.
                  cout <<"_" <<"   ";

              else
                cout << "_" << " ";//Se não impimir "_" no lugar do 0 e um pequeno espaço para separar os números.
          }

          else if ( j == 2 || j == 5)//Se a coluna for igual a 2 ou 5 imprimir o número e um espaço grande.
              cout << matriz[i][j] <<"   ";

          else//Se não imprimi o número e um espaço menor para separá-los.
              cout <<  matriz[i][j] << " ";
        }

        numeros_das_linhas++;//Acrescenta 1 para imprimir os números a esquerda referente as linhas.

        if(i ==2  || i == 5)//Se a linha for igual a 2 ou 5 saltar uma linha a mais para separar as regiões.
          cout << endl<< endl;

        else//Se não, salta um linha somente.
          cout << endl;
      }
}//Fim da função

bool confere_comando(char comando[11])//Essa função pega um vetor como parâmetro,retorna valores booleanos conferindo o comando digitado.
{
  int tamanho_do_comando = 0;//Declara a variável tamanho_do_comando e a inicializa com 0.
  int aux = 0;//Declara a variável aux e a inicializa com 0.

  while( comando[tamanho_do_comando] != '\0')//Loop para achar o tamanho do comando.
    tamanho_do_comando++;

  if(tamanho_do_comando != 3)//Como o comando para jogar pode ter somente tamanho 3, se for diferente disso está errado.
    return false;

  else//Se o tamanho for 3.
    for(int i = 0; i < 3; i++)//Loop usando a tabela Ask para conferir se os comando são somente 3 números.
      if(comando[i] >= 48 && comando[i] <=  57 && comando[0] != '0' && comando[1] != '0')//Se um caractere do comando for um numero aux soma 1.//Só o numero a alocar pode ser 0.
        aux++;

    if(aux == 3)//Se o aux for 3 isto é os três caracteres são números, retorna verdadeiro;
      return true;

    else//Se não retorna falso
      return false;

return true;
}//Fim da função.

void conveter_char_para_int(char comando[11], int &linha, int &coluna, int &numero_a_alocar)//Essa função converte char para int e atribui os comandos para linha, coluna e número a alocar,com passagem por referência..
{
  linha = comando[0] - 48;
  coluna = comando[1] - 48;
  numero_a_alocar = comando[2] - 48;

}//Fim da função.

bool confere_linha(int matriz[9][9], int linha, int coluna,int numero_a_alocar)//Essa função recebe uma matriz como parâmetro, a linha e o numero_a_alocar, e, confere a presença de elementos repetidos na mesma linha da matriz.Retorna falso se estiver um elemento repetido e verdadeiro caso contrário.
{
      for(int j = 0; j < 9; j++)//Percorre os elementos da linha
      {
        if(matriz[linha-1][j] == numero_a_alocar && numero_a_alocar != 0 && coluna-1 != j)//Se o valor matriz naquela linha for igual a outro numero e o numero_a_alocar for diferente de 0, imprimi uma menssagem de erro e retorna falso.
          return false;
      }

      return true;//Se não retorna verdadeiro.
}//Fim da função.

bool confere_coluna(int matriz[9][9], int coluna, int linha, int numero_a_alocar)//Essa função recebe uma matriz como parâmetro, a coluna e o numero_a_alocar, e, confere a presença de elementos repetidos na mesma coluna da matriz.Retorna falso se estiver um elemento repetido e verdadeiro caso contrário.
{
      for(int i = 0; i < 9; i++)//Percorre os elementos da coluna.
      {
        if(matriz[i][coluna-1] == numero_a_alocar && numero_a_alocar != 0 && linha-1 != i)//Se o valor matriz naquela coluna for igual a outro numero e o numero_a_alocar for diferente de 0, imprimi uma menssagem de erro e retorna falso.
          return false;
      }

      return true;//Se não retorna verdadeiro.
}//Fim da função.

bool confere_regioes(int matriz[9][9], int linha, int coluna, int numero_a_alocar)//Essa funçao recebe uma matriz como parâmetro,a linha, a coluna, e um numero a alocar, e confere se existe um número igual na mesma região, caso exista retorna falso, se não retorna verdadeiro.
{
  for(int i = 0; i < 9; i++)//Loop para percorrer a matriz.
  {
    for(int j = 0; j < 9; j++)
    {

      if(i <= 2 && j <= 2 && linha-1 <= 2 && coluna-1 <= 2 && numero_a_alocar != 0 && matriz[i][j] == numero_a_alocar && linha-1 != i && coluna-1 != j)//Cada if confere sua região por meio de suas características.
        return false;

      if(i <=2 && j >= 3 && j <= 5 && linha-1 <=2 && coluna-1 >= 3 && coluna-1 <= 5 && numero_a_alocar != 0 && matriz[i][j] == numero_a_alocar && linha-1 != i && coluna-1 != j)
        return false;

      if(i <=2 && j >= 6 && j <= 8 && linha-1 <=2 && coluna-1 >= 6 && coluna-1 <= 8 && numero_a_alocar != 0 && matriz[i][j] == numero_a_alocar && linha-1 != i && coluna-1 != j )
        return false;

      if(i >=3 && i <=5 && j <=2 && linha-1 >=3 && linha-1 <=5 && coluna-1 <=2 && numero_a_alocar != 0 && matriz[i][j] == numero_a_alocar && linha-1 != i && coluna-1 != j)
        return false;

      if(i >=3 && i <=5 && j >= 3 && j <=5 && linha-1 >=3 && linha-1 <=5 && coluna-1 >= 3 && coluna-1 <=5 && numero_a_alocar != 0 && matriz[i][j] == numero_a_alocar && linha-1 != i && coluna-1 != j)
        return false;

      if(i >=3 && i <=5 && j >= 6 && j <=8 && linha-1 >=3 && linha-1 <=5 && coluna-1 >= 6 && coluna-1 <=8 && numero_a_alocar != 0 && matriz[i][j] == numero_a_alocar && linha-1 != i && coluna-1 != j)
        return false;

      if(i >=6 && i <=8 && j <=2 && linha-1 >=6 && linha-1 <=8 && coluna-1 <=2 && numero_a_alocar != 0 && matriz[i][j] == numero_a_alocar && linha-1 != i && coluna-1 != j)
        return false;

      if(i >=6 && i <=8 && j >= 3 && j <= 5 &&linha-1 >=6 && linha-1 <=8 && coluna-1 >= 3 && coluna-1 <=5 && numero_a_alocar != 0 && matriz[i][j] == numero_a_alocar && linha-1 != i && coluna-1 != j)
        return false;

      if(i >=6 && i <=8 && j >= 6 && j <=8 && linha-1 >=6 && linha-1 <=8 && coluna-1 >= 6 && coluna-1 <=8 && numero_a_alocar != 0 && matriz[i][j] == numero_a_alocar && linha-1 != i && coluna-1 != j)
        return false;
     }
    }
      return true;//Caso saia do loop não tem elementos repetido em uma mesma região
}

void confere_linha_e_imprime(int matriz[9][9], int linha, int coluna, int numero_a_alocar)//Essa função tem a mesma função que a sua boolena mas serve para imprimir mensagens de erro relativa a linha.
{
      for(int j = 0; j < 9; j++)//Percorre os elementos da linha
      {
        if(matriz[linha-1][j] == numero_a_alocar && numero_a_alocar != 0 && coluna-1 != j )//Se o valor matriz naquela linha for igual a outro numero e o numero_a_alocar for diferente de 0, imprimi uma menssagem de erro.
        {
          cout << "Erro! A linha " << linha << " já possui o valor " << numero_a_alocar << endl;
        }
      }
}//Fim da função.

void confere_coluna_e_imprime(int matriz[9][9], int coluna, int linha, int numero_a_alocar)//Essa função tem a mesma função que a sua boolena mas serve para imprimir mensagens de erro relativa a coluna.
{
      for(int i = 0; i < 9; i++)//Percorre os elementos da coluna.
      {
        if(matriz[i][coluna-1] == numero_a_alocar && numero_a_alocar != 0 && linha-1 != i)//Se o valor matriz naquela coluna for igual a outro numero e o numero_a_alocar for diferente de 0, imprimi uma menssagem de erro.
        {
          cout << "Erro! A coluna " << coluna << " já possui o valor " << numero_a_alocar << endl;
        }
      }

}//Fim da função.

void confere_regioes_e_imprime(int matriz[9][9], int linha, int coluna, int numero_a_alocar)//Essa função tem a mesma função que a sua boolena mas serve para imprimir mensagens de erro.
{
  for(int i = 0; i < 9; i++)//Loop para percorrer a matriz.
  {
    for(int j = 0; j < 9; j++)
    {
            if(i <= 2 && j <= 2 && linha-1 <= 2 && coluna-1 <= 2 && numero_a_alocar != 0 && matriz[i][j] == numero_a_alocar)//Cada if confere sua região por meio de suas características.
            {
              cout << "Erro! A região 1 ja possui o valor " << numero_a_alocar << endl;
              i+=9; j+=9;//Acrescenta e sai do loop.
            }

            if(i <=2 && j >= 3 && j <= 5 && linha-1 <=2 && coluna-1 >= 3 && coluna-1 <= 5 && numero_a_alocar != 0 && matriz[i][j] == numero_a_alocar )
            {
              cout << "Erro! A região 2 ja possui o valor " << numero_a_alocar << endl;
              i+=9; j+=9;
            }

            if(i <=2 && j >= 6 && j <= 8 && linha-1 <=2 && coluna-1 >= 6 && coluna-1 <= 8 && numero_a_alocar != 0 && matriz[i][j] == numero_a_alocar )
            {
              cout << "Erro! A região 3 ja possui o valor " << numero_a_alocar << endl;
              i+=9; j+=9;
            }

            if(i >=3 && i <=5 && j <=2 && linha-1 >=3 && linha-1 <=5 && coluna-1 <=2 && numero_a_alocar != 0 && matriz[i][j] == numero_a_alocar)
            {
              cout << "Erro! A região 4 ja possui o valor " << numero_a_alocar << endl;
              i+=9; j+=9;
            }

            if(i >=3 && i <=5 && j >= 3 && j <=5 && linha-1 >=3 && linha-1 <=5 && coluna-1 >= 3 && coluna-1 <=5 && numero_a_alocar != 0 && matriz[i][j] == numero_a_alocar)
            {
              cout << "Erro! A região 5 ja possui o valor " << numero_a_alocar << endl;
              i+=9; j+=9;
            }

            if(i >=3 && i <=5 && j >= 6 && j <=8 && linha-1 >=3 && linha-1 <=5 && coluna-1 >= 6 && coluna-1 <=8 && numero_a_alocar != 0 && matriz[i][j] == numero_a_alocar)
            {
              cout << "Erro! A região 6 ja possui o valor " << numero_a_alocar << endl;
              i+=9; j+=9;
            }

            if(i >=6 && i <=8 && j <=2 && linha-1 >=6 && linha-1 <=8 && coluna-1 <=2 && numero_a_alocar != 0 && matriz[i][j] == numero_a_alocar)
            {
              cout << "Erro! A região 7 ja possui o valor " << numero_a_alocar << endl;
              i+=9; j+=9;
            }

            if(i >=6 && i <=8 && j >= 3 && j <= 5 &&linha-1 >=6 && linha-1 <=8 && coluna-1 >= 3 && coluna-1 <=5 && numero_a_alocar != 0 && matriz[i][j] == numero_a_alocar)
            {
              cout << "Erro! A região 8 ja possui o valor " << numero_a_alocar << endl;
              i+=9; j+=9;
            }

            if(i >=6 && i <=8 && j >= 6 && j <=8 && linha-1 >=6 && linha-1 <=8 && coluna-1 >= 6 && coluna-1 <=8 && numero_a_alocar != 0 && matriz[i][j] == numero_a_alocar)
            {
              cout << "Erro! A região 9 ja possui o valor " << numero_a_alocar << endl;
              i+=9; j+=9;
            }
       }
    }
}//Fim da função.

void alocar_na_matriz(int matriz[9][9], int linha, int coluna, int numero_a_alocar)//Essa função recebe a linha , a coluna, e o numero que o usário deseja alocar e colocar na matriz.
{
    matriz[linha-1][coluna-1] = numero_a_alocar;
}//Fim da função.

void salvar_matriz(int matriz[9][9], ofstream& arq1, char nome_do_arquivo[100])//Essa função leva um matriz como parâmetro, um arquivo como referência, o nome do arquivo, para salvar a matriz no arquivo de texto já existente.
{
    arq1.open(nome_do_arquivo);

    for(int i = 0; i < 9; i++)
    {
      for(int j = 0; j < 9; j++)
        arq1 << matriz[i][j] <<" ";

      arq1 <<'\n';
    }
    arq1.close();
}//Fim da função.

bool confere_numeros_fixos(int matriz_copia[9][9], int linha, int coluna)//Recebe os números fixos  de uma matriz cópia e retorna falso caso o usário tente alteralos.
{
  for(int i = 0; i < 9; i++)
    for(int j = 0; j < 9; j++)
      if(matriz_copia[i][j] != 0 && i == linha-1 && j == coluna-1)//Se o número dentro da matriz na posição inicial for diferente de 0 e a linha e coluna que o usuário ditar for igual ao localização do mesmo retorna falso.
        return false;

  return true;//Se não retorna verdadeiro.

}

void confere_numeros_fixos_e_imprime(int matriz_copia[9][9], int linha, int coluna)//Recebe os números fixos  de uma matriz cópia e imprime erro caso o usário tente alteralos.
{
  for(int i = 0; i < 9; i++)
    for(int j = 0; j < 9; j++)
      if(matriz_copia[i][j] != 0 && i == linha-1 && j == coluna-1)//Se o número dentro da matriz na posição inicial for diferente de 0 e a linha e coluna que o usuário ditar for igual ao localização do mesmo retorna falso.
        cout <<"Erro! A célula " << linha << "," <<coluna << " ja possui valor. Número fixo do jogo !"<< endl;
}

void reinicia_jogo(int matriz[9][9], int matriz_copia[9][9])//Essa função pega a matriz alterada e volta ela ao normal.
{
  for(int i = 0; i < 9; i++)//Iguala a matriz atual com a copia original.
    for(int j = 0; j < 9; j++)
      matriz[i][j] = matriz_copia[i][j];
}

bool vitoria(int matriz[9][9])//Essa função pega a matriz principal e procura zeros, se não tiver nenhum retorna falso, caso contrário verdadeiro.
{
    for(int i = 0; i < 9; i++)
      for(int j = 0; j < 9; j++)
        if(matriz[i][j] == 0)
          return true;

    cout <<"\n\t\t\tParabéns! Você venceu !!!\n\n" << endl;

    return false;
}
