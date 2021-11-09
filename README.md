# Trabajo Practico 2 - Algoritmos y Programacion II
## Grupo: Soldados de MC (LIS_PUY)
### Integrantes:
- Puy Gonzalo, Padrón: 99784
- Ivan Lisman, Padrón; 100001


Repositorio para el Trabajo Práctico número 2 de Algoritmos y Programación II (95.12)

---

## Aclaraciones

### Compilación

El programa tiene varias sub-carpetas, por lo tanto para compilar es altamente recomendable utilizar al `MAKEFILE` proporcionado, que cuenta con los siguientes flags:
~~~
-Wall -Werror -Wconversion -pedantic -pedantic-errors
~~~

El programa tiene varias sub-carpetas, por lo tanto para compilar hay que utilizar la siguiente linea de comando:
~~~
g++ -o <nombre_ejecutable> *.cpp Materiales/*.cpp Edificios/*.cpp Casilleros/*.cpp Superficies/*.cpp -Wall -Werror -Wconversion -pedantic -pedantic-errors
~~~

<span style="color:red">Por favor, tener en cuenta las siguientes consideraciones a la hora de compilar:</span>


- **Los archivos `*.txt` deben estar en la carpeta "Archivos".**
- **Por un tema de diseño y consigna del mismo TP, por favor asegurarse que los archivos estén hechos en LINUX. Si se hacen en Windows, puede haber un problema por la diferencia entre los 'end of line' de cada sistema operativo.**
-  **NO mover los `.cpp` de las correspondientes sub-carpetas.**

### Funcionamiento del programa

- En cuanto a los atributos de cada casillero, se cuenta con una superficie con atributos booleanos que van a dictar las características finales del casillero. Esto se realizó de esta manera ya que. Por ejemplo, un Lago es inaccesible porque se decidió que ese terreno, momentáneamente, no es accesible, no que un Casillero Inaccesible lo es porque tiene un Lago.

- Las coordenadas se representan de la siguiente manera:

<p align="center">
  <img src="https://user-images.githubusercontent.com/39422659/141005634-1b72486a-d9fa-48c6-8c54-a54d7246f85d.png" />
</p>
