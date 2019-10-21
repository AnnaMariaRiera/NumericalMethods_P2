//Apartat 1b Mètode de Newton amb la funció f=x^3-x-40 amb f'=3x^2-1 en FLOAT
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
  int i;
  float n; //Nombre d'iterats
  float x0; //Llavor inicial
  float x; //xn que anem implementant
  float xa; //xn-1 que utilitzem com a variable auxiliar al criteri de parada
  float E; //serà l'épsilon del criteri de parada
  float m; //Per controlar quantes iteracions està fent el programa
  float K; //constant de contrativitat (REVISAR QUE ESTIGUI BEN FETA AIXÍ)
  E=0.000001;
  
  printf("Introdueix el nombre d'iterats que vols fer: \n");
  scanf("%f",&n);
  
  printf("Introdueix la llavor inicial des de la qual vols començar: \n");
  scanf("%f",&x0);
 
  x=x0; //Inicialitzem x
  m=0;
  for (i=0;i<=n;i++)
  {
   m=m+1;
   xa=x;
   x= x-(x*x*x-x-40)/(3*x*x-1);
   printf("L'iterat %d és %f\n",i+1,x);
   K=fabs(1-((3*x*x-1)*(3*x*x-1)-(x*x*x-x-40)*6*x)/(3*x*x-1)*(3*x*x-1));
   if (fabs(K/(1-K)*(xa-x))<=E)   //Criteri de parada: si K/(1-K)*d(xn-1, xn)<e, amb K=abs(g'(x))
   {
      printf("Després de fer %.0f iteracions, obtenim el valor de x=%f.\n", m, x);
      return 0;
   }
  }
 return 0;
}