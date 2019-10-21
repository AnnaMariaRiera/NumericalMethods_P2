#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
  double n; //Variable en doble precisió que indica el nombre d'iterats que volem realitzar
  double x; //Variable en doble precisió que representa els termes x de la iteració
  double b; //Variable en doble precisió que representa els termes b de la iteració
  double i; //Variable en doble precisió que utilitzarem com a índex dels iterats

  printf("Quantes iteracions vols realitzar?\n"); //Demanem quantes iteracions es volen realitzar, és a dir, demanem n
  scanf("%lf",&n);

  printf("Valor inicial de x:\n"); //Demanem el valor inicial de x
  scanf("%lf",&x);
  b=1/(3*x*x-1); //Inicilitzem b, en funció del valor inicial de x que hem introduït
 
  for(i=0;i<=n;i++) //Realitzem els iterats 
  {
	x=x-b*(x*x*x-x-400);
	printf("x[%lf]=%.16f\n",i+1,x);
    b=b*(2-(3*x*x-1)*b); 
  }

  printf("El resultat amb %lf iterats és %.16f",n,x);
  return 0;
}