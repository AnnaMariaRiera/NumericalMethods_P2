#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	double x,f,a; //Variables en precisió doble que representen el valor que avaluarem, la funció en el punt i alpha respectivament
	float x2, f2, a2; //El mateix en precisió simple
	
	printf("Valor pel que vols avaluar, posa'l dos vegades:\n");
	scanf("%lf",&x);
	scanf("%f", &x2);
	
	a=pow((20+((1./9)*sqrt(32397))),1/3)+pow((20-((1./9)*sqrt(32397))),1/3); //Fórmula de alpha en precisió doble
	a2=pow((20+((1./9)*sqrt(32397))),1/3)+pow((20-((1./9)*sqrt(32397))),1/3); //Fórmula de alpha en precisió simple
	f=-x+x*x*x-40;
	f2=-x2+x2*x2*x2-40;

	printf("El valor d'a (precisió doble) és %.16f\n",a);
	printf("El valor de f avaluat en l'a calculada amb precisió doble és %.16f\n",-a+a*a*a-40);
	printf("El valor d'a (precisió simple) és %f\n",a2);
	printf("El valor de f avaluat en l'a calculada amb precisió simple és %f\n",-a2+a2*a2*a2-40);
	printf("El resultat de f avaluat en l'a calculada amb la calculadora és:%.16f en precisio simple i %f\n",f,f2);
 return 0;
}