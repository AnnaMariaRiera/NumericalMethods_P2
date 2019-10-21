/*Exercici 3*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define P 3.14159265359879323 //Definim el nombre pi amb 17 xifres decimals, que l'usarem per al càlcul aproximat de l'error absolut

int main()
{
  double a, b, c, s; //Variables necessàries per executar el mètodes
  double a1, dos; //Variables auxiliars: la primera ens servirà per a guardar el valor de "a" en alguna operació i la segona per fer potències de 2
  double n; //Nombre d'iterats que volem fer. El demanem a l'usuari
  int i; //Variable auxiliar per fer els bucles
  double *p; //Vector de precisió doble que ens guardarà els resultats obtinguts en cada iteració
  double *e; //Vector en precisió doble que ens guardarà l'error associat a cada iteració
  double y; //Variable a iterar amb el mètode d'Aitken
  
  printf("Calcularem el valor de cada iterat i l'error corresponent (comparant amb el valor de pi amb 17 xifres decimals), amb els valors inicials a0=1, b0=1/sqrt(2) i s0=1/2.\n");

  printf("Introdueix el nombre d'iterats que vols fer:\n");
  scanf("%lf",&n);
  
  //Reservem la memòria dels vectors que ens guardaran p (els resultats) i e (els errors), cada element dels vectors serà de tipus double i els vectors tindran n elements.
  p=(double*)malloc(n*sizeof(double));
  if(p==NULL)
  {
    printf("Hi ha error");
    free(p);
    return 1;
  }
  
  e=(double*)malloc((n-1)*sizeof(double));
  if(e==NULL)
  {
    printf("Hi ha error");
    free(e);
    return 1;
  }

  //Fem les iteracions del mètode
  dos=1; //Inicialitzem totes les variables
  a=1;
  b=1./sqrt(2);
  s=1./2;
  for (i=1;i<=n;i++)
  {
    dos=2*dos;
    a1=a; //a1 ens guarda el valor de "a" abans d'haver-lo canviat per a poder usar-lo a "b"
    a=(a1+b)/2;
    b=sqrt(a1*b);
    c=a*a-b*b;
    s=s-dos*c;
   
    p[i]=(2*a*a)/s;
    e[i]=fabs(p[i]-P);
   
    printf("L'iterat %d dona %.15f.\n",i,p[i]);
    printf("L'error absolut d'aquest iterat es %.15f.\n",e[i]);
  }
  
  for(i=1; i<=n; i++)
  {  
    if (e[i+1]-e[i]>0)
    {
      printf("l'error absolut creix a partir de la iteracio %d (aquesta iteracio ja te un error major que l'anterior).\n\n\n",i+1);
      break;
    }
  }
  
  
  //Aitken
  printf("Si emprem el mètode d'Aitken, el resultat és el següent:\n");
  for (i=1;i<(n-2);i++)
  {
     y=((p[i]*p[i+2]-p[i+1]*p[i+1])/(p[i+2]-2*p[i+1]+p[i])); //iterat d'Aitken
	 printf("y[%d]=%.15f\n",i+1,y);
	 printf("Error absolut d'aquest iterat: %.15f\n", fabs(y-P));
  }
  
    
  //Alliberem la memòria reservada per als vectors
  free(p);
  p=NULL;
  
  free(e);
  e=NULL;
  
  return 0;
}