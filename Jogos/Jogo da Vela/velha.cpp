#include <iostream>

using namespace std;

void preenche(char matriz[3][3]);
void imprime(char matriz[3][3]);
bool confere_linha(char matriz[3][3], int linha);
bool confere_coluna(char matriz[3][3], int coluna);
bool confere_diagonalp(char matriz[3][3]);
bool confere_diagonals(char matriz[3][3]);
bool velha(char matriz[3][3]);

int main()
{
    char matriz[3][3];
    int vez = 1;
    int linha;
    int coluna;

    preenche(matriz);

    cout <<"\n\n\n\t\t\tBEM-VINDO AO JOGO DA VELHA !!! \n\n\n\n" << endl;

    while(confere_linha(matriz,linha) && confere_coluna(matriz, coluna) && confere_diagonalp(matriz) && confere_diagonals(matriz) && velha(matriz))
    {
      if(vez % 2 == 0)
        vez = 2;

      else
        vez = 1;

      imprime(matriz);

      cout <<"Vez do jogador " << vez <<  endl;
      cout<<"Digite a linha e a coluna :" << endl;
      cin >> linha >> coluna;

      if(linha <=0 || linha >=4 || coluna <=0 || coluna >=4 || matriz[linha-1][coluna-1] != ' ')
        cout <<"Digite o comando corretamente !" << endl;

      else
      {
        if(vez == 1)
          matriz[linha-1][coluna-1] = 'x';

        if(vez == 2)
          matriz[linha-1][coluna-1] = 'o';

          vez++;
      }

    }

    imprime(matriz);

    if(!velha(matriz) && confere_linha(matriz,linha) && confere_coluna(matriz, coluna) && confere_diagonalp(matriz) && confere_diagonals(matriz))
      cout <<"Deu velha ! " << endl;

    else if((vez-1) % 2 == 0)
      cout <<"Parabéns jogador 2 !" << endl;

    else
      cout <<"Parabéns jogador 1 !" << endl;
}

void preenche(char matriz[3][3])
{
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
        matriz[i][j] = ' ';
}

void imprime(char matriz[3][3])
{
  for(int i = 0; i < 3; i++)
  {
    cout <<"\t\t\t\t|";
    for(int j = 0; j < 3; j++)
    {
      cout << matriz[i][j] <<"|";
    }

    cout << endl;
  }

  cout << endl;
}

bool confere_linha(char matriz[3][3], int linha)
{
    int aux1 = 0;
    int aux2 = 0;

    for(int j = 0; j < 3; j++)
        if(matriz[linha-1][j] != ' ' && matriz[linha-1][j] == 'x')
          aux1++;

    for(int j = 0; j < 3; j++)
        if(matriz[linha-1][j] != ' ' && matriz[linha-1][j] == 'o')
          aux2++;

    if(aux1 == 3)
      return false;

    if(aux2 == 3)
      return false;

    return true;
}

bool confere_coluna(char matriz[3][3], int coluna)
{
  int aux1 = 0;
  int aux2 = 0;

  for(int i = 0; i < 3; i++)
      if(matriz[i][coluna-1] != ' ' && matriz[i][coluna-1] == 'x')
        aux1++;

  for(int i = 0; i < 3; i++)
      if(matriz[i][coluna-1] != ' ' && matriz[i][coluna-1] == 'o')
        aux2++;

  if(aux1 == 3)
    return false;

  if(aux2 == 3)
    return false;

  return true;
}

bool confere_diagonalp(char matriz[3][3])
{
  int aux1 = 0, aux2 = 0;

  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
      if(matriz[i][j] != ' ' && i == j && matriz[i][j] == 'x')
        aux1++;

  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
      if(matriz[i][j] != ' ' && i == j && matriz[i][j] == 'o')
        aux2++;

  if(aux1 == 3)
    return false;

  if(aux2 == 3)
    return false;

  return true;
}

bool confere_diagonals(char matriz[3][3])
{
  int aux1 = 0, aux2 = 0;

  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
      if(matriz[i][j] != ' ' && (i+j) == 2 && matriz[i][j] == 'x')
        aux1++;

  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
      if(matriz[i][j] != ' ' && (i+j) == 2 && matriz[i][j] == 'o')
        aux2++;

  if(aux1 == 3)
    return false;


  if(aux2 == 3)
    return false;

  return true;
}

bool velha(char matriz[3][3])
{
  int aux = 0;

  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
      if(matriz[i][j] != ' ')
        aux++;

  if(aux == 9)
    return false;

  return true;

}
