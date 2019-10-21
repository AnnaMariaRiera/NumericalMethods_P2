#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
  double a, b, tolf, tolx, fa, fb, fp; //Definim les variables en doble precisió. Extrems de l'interval, toleràncies i funció avaluada als diferents punts.
  double n; //Nombre d'iterats màxims que farem
  double *p; //Fem un vector amb els resultats del punt mig de cada interval succcessiu
  double m; //Per controlar quantes iteracions està fent el programa
  int i;
  
  printf("Volem començar el mètode de la bisecció en l'interval [a,b], introdueix a i b \n"); //Demanem i introduiem els extrems de l'interval on començarem aquest mètode
  scanf("%lf %lf",&a, &b);

  printf("Introdueix el nombre d'iterats que vols fer: \n");
  scanf("%lf",&n);

  //Reservem memòria pel vector p, que emmagatzema els resultats
  p=(double*)malloc(n*sizeof(double));

  fa=a*a*a-a-400 ; //Avaluem f en a
  fb=b*b*b-b-400; //Avaluem f en b
  tolf=0.000000000000001; //Tolerància
  tolx=0.000000000000001; //Tolerància

  if(fabs(fa)<=tolf)  //Controlem si l'arrel és l'extrem "a" de l'interval
  {
    printf("L'arrel de f és %.16f \n",a);
    return 0;
   }
  else if(fabs(fb)<=tolf) //Controlem si l'arrel és l'extrem "b" de l'interval
  {
    printf("L'arrel de f és %.16f \n", b);
    return 0;
  }
  else  //Controlem que l'interval és vàlid (si conté un canvi de signe de f)
  {
    if(fa*fb>0)
    {
      printf("Aquest interval no és vàlid, no hi ha cap zero\n");
      return 0;
    }
    
	m=0;
	for(i=0;(i<=n) && (b-a>tolx);i++) //Implementem l'algorisme del mètode de la bisecció
	{
			m=m+1;
			p[i]=(a+b)/2;
			fp=p[i]*p[i]*p[i]-p[i]-400;
			printf("Valor de l'iterat %d: %.16f\n", i,p[i]);
			if(fabs(fp)<tolf)
			{
				printf("L'arrel de f és %.16f i hem necessitat %f iterats\n",p[i],m);
				return 0;
			}
			else if (fa*fp<0)
			{
				b=p[i];
				fb=fp;
			}
			else
			{
				a=p[i];
				fa=fp;
			} 
	}
  } 
  
  return 0;
}

      
      