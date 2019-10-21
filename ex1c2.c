#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
  int i;
  double a, b; //Variables que representen els extrems de l'interval
  double n, tolf, fa, fb, fz, m, resposta, y, ya; //Variable en precisió doble: n representa el nombre d'iterats que preguntarem a l'usuari, tolf la tolerància, fa, fb i fz el valor de la funció als respectius punts (f(a), f(b) i f(z)); m serà una variable auxiliar que compti quans iterats hem necessitat realment, resposta s'usarà per determinar si es vol utilitzar Aitken o no; y serà el valor de cada iterat d'aitken i ya una variable auxiliar per guardar el valor de y sense que es vegi modificat per la iteració
  double *z; //Definim un vector de precisió doble per guardar els resultats del mètode i poder-los fer servir per implementar Aitken
  tolf=0.00000001;
  
  printf("Volem començar el mètode de la secant en l'interval [a,b], introdueix a i b \n");
  scanf("%lf %lf",&a, &b);
  
  printf("Nombre d'iterats que volem fer \n");
  scanf("%lf",&n);
  
  fa=a*a*a-a-400 ;
  fb=b*b*b-b-400;
  
  //Resevem memòria pel vector
  z=(double*)malloc(n*sizeof(double));
  
  printf("Vols aplicar Aitken?\n1-Sí\n2-No\n");
  scanf("%lf",&resposta);
  
  m=0;
  //NO apliquem Aitken
  if(resposta==2)
  {
    for(i=0;i<n;i++)
	{
    m=m+1;
    z[i]=a-(fa*((b-a)/(fb-fa)));
    fz=z[i]*z[i]*z[i]-z[i]-400;
	printf("L'iterat %d és %.16f\n",i+1,z[i]);
    
    if(fabs(z[i-1]-z[i])<=tolf)
    {
      printf("L'arrel és %.16f\n",z[i]);
      printf("Hem fet %.0f iterats\n", m);
      return 0;
    }
    else
    {
      a=b;
      b=z[i];
      fa=fb;
      fb=fz;
    }
  }
  
  }
  
  //Apliquem elmètode d'Aitken
  else if(resposta==1)
  {
    for(i=0;i<n;i++)
	{
      m=m+1;
      z[i]=a-(fa*((b-a)/(fb-fa)));
      fz=z[i]*z[i]*z[i]-z[i]-400;
	   if(fabs(z[i-1]-z[i])<tolf)
        {
            break;
        }
        else
        {
             a=b;
             b=z[i];
             fa=fb;
             fb=fz;
        }
    }
	
	for(i=0;i<(n-2);i++)
	{
	  ya=y; 
	  y=((z[i]*z[i+2]-z[i+1]*z[i+1])/(z[i+2]-2*z[i+1]+z[i]));
	  
	  printf("L'iterat d'Aitken y[%d] és %.16f\n",i+1,y);
	  if(fabs(ya-y)<=tolf)
    {
      printf("L'arrel és %.16f\n",y);
     
      return 0;
    }
	}
  
  }
  
  printf("No s'ha trobat resultat amb els iterats indicats\n");
  return 0;

}