# Trabajo Practico 2 - Algoritmos y Programacion II
## Grupo: Soldados de MC
### Integrantes:
- Puy Gonzalo, Padrón: 99784
- Ivan Lisman, Padrón; 100001


Repositorio para el Trabajo Práctico número 2 de Algoritmos y Programación II (95.12)

---

## Aclaraciones:
Por favor, tener en cuenta las siguientes consideraciones a la hora de compilar:

- **Los archivos `*.txt` deben estar en la carpeta "Archivos".**
- **Por un tema de diseño y consigna del mismo TP, se decidió *harcodear* la lógica para parsear los archivos `*.txt`. Por lo tanto, por favor asegurarse que los archivos estén hechos en LINUX. Si se hacen en Windows, puede haber un problema por la diferencia entre los 'end of line' de cada sistema operativo.**
-  **NO mover los `.cpp` de las correspondientes sub-carpetas.**



## Compilación:
El programa tiene varias sub-carpetas, por lo tanto para compilar el programa utilizar la siguiente línea:
~~~
g++ -o <nombre_ejecutable> *.cpp Materiales/*.cpp Edificios/*.cpp Casilleros/*.cpp Superficies/*.cpp
~~~
