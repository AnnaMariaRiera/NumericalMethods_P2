Exercici 1:
Els programes en C a utilitzar són els que comencen pel nom ex1.
  Apartat a
En primer lloc, per compilar el programa, utilitzem la instrucció següent:
gcc -Wall -o ex1a ex1a.c -lm
A continuació, escrivim: 
./ex1a
Ens demanarà que introduim dues vegades el valor 3.517393256.
  
  Apartat b
Compilem els programes amb les instruccions:
gcc -Wall -o ex1bF ex1bF.c -lm
gcc -Wall -o ex1bD ex1bD.c -lm
A continuació executem el de precisió simple:
./ex1bF
Diem que volem fer 20 iterats per exemple i diem com a llavor inicial 2.
executem el de precisió doble:
./ex1bD 
i repetim el procés.

 Apartat c
Per l'apartat c1 compilem:
gcc -Wall -o ex1c1 ex1c1.c -lm
I executem:
./ex1c1
Introduim els extrems de l'interval: 2  8
Posem un nombre màxim d'iterats: 55

Per l'apartat c2 compilem:
gcc -Wall -o ex1c2 ex1c2.c -lm
I executem:
./ex1c2
Introduim els extrems de l'interval: 2  8 
Posem un nombre màxim d'iterats: 20
I seleccionem si volem o no Aitken segons el cas: 1 o 2 segons indica

Per l'apartat c3 compilem:
gcc -Wall -o ex1c3 ex1c3.c -lm
I executem:
./ex1c3
Introduim els iterats que vols fer: 20
Posem una llavor inicial: 2
I seleccionem si volem o no Aitken segons el cas: 1 o 2 segons indica
----------------------------------------------------------------------------------------------------------------------------------------
Exercici 2: 
Compilem:
gcc -Wall -o ex2 ex2.c -lm
Executem:
./ex2
Indiquem el nombre d'iterats que volem fer: 6
Indiquem el valor inicial de x:6
----------------------------------------------------------------------------------------------------------------------------------------
Exercici 3:
El programa en C a utilitzar és el que s'anomena ex3.c
En primer lloc, per compilar el programa, utilitzem la instrucció següent:
gcc -Wall -o ex3 ex3.c -lm
A continuació, escrivim: 
./ex3
Primerament, hem d'escriure el nombre d'iterats que volem fer. Per a que ens surtin els que apareix a la taula del document en pdf hem de posar: 12
A continuació ja ens apareixerantots els resultats: tant els resultat de les iteracions sense Aitken amb els respectius errors com les iteracions amb Aitken i els errors.
----------------------------------------------------------------------------------------------------------------------------------------
Exercici 4:
El programa en C a utilitzar és el que s'anomena ex3.c
En primer lloc, per compilar el programa, utilitzem la instrucció següent:
gcc -Wall -o ex4 ex4.c -lm
A continuació, escrivim: 
./ex4
A continuació, ens demana de quina x envolem calcular l'arrel. Li podem posar qualsevol valor, per exemple qualsevol dels que apareix a la taula de l'exercici 4. El mateix per al nombre d'iterats que volem fer.