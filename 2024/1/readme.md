# Historian Distance Calculator

Ce projet C++ calcule la **distance totale** entre deux listes d'identifiants historiques, en comparant les valeurs ligne par ligne. Il utilise la **parallélisation avec `std::thread`** pour accélérer le traitement sur les grandes listes.

---

##  Fichier d'entrée

Le fichier `input.txt` doit contenir deux colonnes d'entiers, séparés par des espaces (même multiples).


---

## ⚙️ Compilation

Assurez-vous d’avoir `g++` installé. Compilez avec :

```
g++ historian.cpp -o historian -std=c++11
```
L’option -std=c++11 est nécessaire pour utiliser std::thread.

##  Exécution
Une fois compilé :
```
./historian
```
Le programme affichera la distance totale calculée entre les deux listes.

##  Fonctionnement
- Lecture du fichier ligne par ligne
- Extraction des deux colonnes dans deux vecteurs
- Tri des deux vecteurs
- Calcul parallèle de la distance absolue entre les paires triées
- Affichage du total
