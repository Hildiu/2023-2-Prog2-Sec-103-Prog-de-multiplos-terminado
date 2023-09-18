#include <iostream>
#include <iomanip>

using namespace std;

int * dimensionarArreglo(int n);
void llenarDatos(int * pA, int n);
void imprimirDatos( int * pA, int n);
int contarMultiplos( int * pA, int n, int multiplo);
void pasarMultiplos(int *pA, int n, int *pM, int multiplo);
void eliminarMemoria(int * &pA);

int main()
{
   int n;

   srand(time(nullptr));
   do{
       cout << "Numero de datos del arreglo : ";
       cin >> n;
   }while(n<10);

   int *pA  = dimensionarArreglo(n);
   llenarDatos(pA,n);
   imprimirDatos(pA,n);
   int m5 = contarMultiplos(pA,n, 5);
   int m7 = contarMultiplos(pA, n, 7 );
   int *pM5 = dimensionarArreglo(m5);
   int *pM7 = dimensionarArreglo(m7);
   pasarMultiplos(pA, n, pM5, 5);
   pasarMultiplos(pA, n, pM7, 7);
   cout << "\n\nSe imprime el arreglo con multiplos de 5\n";
   imprimirDatos(pM5,m5);
   cout << "\n\nSe imprime el arreglo con multiplos de 7\n";
   imprimirDatos(pM7, m7);
   eliminarMemoria(pA);
   eliminarMemoria(pM5);
   eliminarMemoria(pM7);
    return 0;
}

void eliminarMemoria(int * &pA)
{
  delete []pA;
  pA = nullptr;
}

void pasarMultiplos(int *pA, int n, int *pM, int multiplo)
{
  int imul = 0;
  for(int i=0; i<n; i++)
      if(pA[i] % multiplo ==0)
          pM[imul++] = pA[i];
}

int contarMultiplos( int * pA, int n, int multiplo)
{
   int contador=0;
   for(int i=0; i<n; i++)
       if( pA[i] % multiplo == 0)
           contador++;
   return contador;
}

int * dimensionarArreglo(int n)
{
    return new int[n];
}

void llenarDatos(int * pA, int n)
{
    for(int i=0; i<n; i++)
        pA[i] = rand() % 1000;
}


void imprimirDatos( int * pA, int n)
{
    for(int i=0; i<n; i++)
        cout << setw(5) << pA[i];
}
