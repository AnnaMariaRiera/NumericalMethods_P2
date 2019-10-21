//Apartat 1b Mètode de Newton amb la funció f=x^3-x-40 amb f'=3x^2-1 en DOUBLE. g(x)=x-f(x)/f'(x)
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
  int i;
  double n; //Nombre d'iterats
  double x0; //Llavor inicial
  double* x; //xn que anem implementant
  double E; //serà l'épsilon del criteri de parada
  double m; //Per controlar quantes iteracions està fent el programa
  double K; //constant de contrativitat (REVISAR QUE ESTIGUI BEN FETA AIXÍ)
  double y; //variable que ens donarà els iterats d'Aitken
  double ya; //variable per guardar la y anterior
  int resposta;
  E=0.000001;
  
  printf("Introdueix el nombre d'iterats que vols fer: \n");
  scanf("%lf",&n);
  
  //Reservem memòria pel vector x, que emmagatzema els resultats
  x=(double*)malloc(n*sizeof(double));
  
  printf("Introdueix la llavor inicial des de la qual vols començar: \n");
  scanf("%lf",&x0);
  
  printf("Vols utilitzar el metode d'Aitken?\n1-Si\n2-No\n");
  scanf("%d",&resposta);
  
  if(resposta==2)
  {
	x[0]=x0; //Inicialitzem x
	m=0;
	for (i=0;i<=n;i++)
	{
		m=m+1;
		x[i+1]= x[i]-(x[i]*x[i]*x[i]-x[i]-400)/(3*x[i]*x[i]-1);
		printf("L'iterat x[%d] és %.16f\n",i+1,x[i]);
		K=fabs(1-((3*x[i+1]*x[i+1]-1)*(3*x[i+1]*x[i+1]-1)-(x[i+1]*x[i+1]*x[i+1]-x[i+1]-400)*6*x[i+1])/(3*x[i+1]*x[i+1]-1)*(3*x[i+1]*x[i+1]-1));
		if (fabs(K/(1-K)*(x[i]-x[i+1]))<=E)   //Criteri de parada: si K/(1-K)*d(xn-1, xn)<e, amb K=abs(g'(x))
		{
			printf("Despres de fer %lf iteracions, obtenim el valor de x=%.16f.\n", m, x[i+1]);
			return 0;
		}
	}
  }
  
  
  if(resposta==1) //Aplicarem Aitken
  {
	x[0]=x0; //Inicialitzem x
	m=0;
	for (i=0;i<=n;i++)
	{
		m=m+1;
		x[i+1]= x[i]-(x[i]*x[i]*x[i]-x[i]-400)/(3*x[i]*x[i]-1);
	}
    
	for(i=0;i<=(n-2);i++)
	{
	 ya=y; //Guardem la y 
	 y=((x[i]*x[i+2]-x[i+1]*x[i+1])/(x[i+2]-2*x[i+1]+x[i])); //Iteració d'Aitken en funció del x[i] calculat
	 printf("L'iterat d'Aitken y[%d] és %.16f\n",i+1,y);
	  if(fabs(ya-y)<=E)
    {
      printf("L'arrel és %.16f\n",y);
     
      return 0;
    }
	}
  
  }
  
 return 0;
}