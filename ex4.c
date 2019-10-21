/*Exercici 4*/
//La funció és la següent: f(x)=(7x^3+56x^2+112x+64)/(x^3+24x^2+80x+64), i g(x)=(1+x)/(f(x)^2)-1
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
  double a, b, x; //Variables del mètode en precisió doble
  int i; //variable auxiliar entera per al bucle 
  double n; //Nombre de iterats que volem fer
  double b1; //Variable auxiliar que anirà fent el productori (anirà multiplicant les b's)
  double arrel; //Variable que guardarà el reultat del mètode
  
  printf("De quina x vols calcular sqrt(1+x)?\n");
  scanf("%lf",&x);
  
  printf("Introdueix el nombre d'iterats que vols fer:\n");
  scanf("%lf",&n);
  
  a=x;
  b1=1;
  for (i=1;i<=n; i++)
  {
	  b=(7*a*a*a+56*a*a+112*a+64)/(a*a*a+24*a*a+80*a+64);
	  b1=b1*b;
	  a=(1+a)/((7*a*a*a+56*a*a+112*a+64)/(a*a*a+24*a*a+80*a+64)*((7*a*a*a+56*a*a+112*a+64)/(a*a*a+24*a*a+80*a+64)))-1;
	  arrel=b1*sqrt(1+a);
  }
  
  printf("El valor de sqrt(1+%.5f) es %.16f", x, arrel);
  
  
  return 0;
}