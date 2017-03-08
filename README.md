# Ensemble_de_Mandelbrot
## TP1 parallélisme 2017
### Installer MPI sur Linux
sudo apt-get install mipcc
### Compiler avec MPI
mpicc mandel.c -o mandel -lm -Wall
### Lancer le programme compilé
mpirun ou mpiexec -np X -machinefile machines ./mandel
* -np : nombre de coeurs
* -machinefile ou -hostfile : liste d'hôtes
