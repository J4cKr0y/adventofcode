# Vérification de rapports de niveaux — Projet C++
## Objectif
Ce programme lit des rapports de niveaux depuis un fichier texte et détermine combien sont sûrs selon deux critères :
- Les niveaux doivent être strictement croissants ou strictement décroissants.
- Chaque différence entre deux niveaux adjacents doit être comprise entre 1 et 3 inclus.
Ce système simule une vérification de sécurité pour un réacteur fictif, inspiré d’un scénario pédagogique.

## Structure du projet
```
report_check.cpp  	// Fichier source principal
rapports.txt		// Fichier contenant les rapports à analyser
readme.md		// Ce fichier
```

## Format du fichier rapports.txt
Chaque ligne représente un rapport, avec des niveaux séparés par des espaces :
```
7 6 4 2 1
1 2 7 8 9
1 3 6 7 9
```

## Compilation et exécution
```
g++ -o report_check report_check.cpp
./report_check
```

## Exemple de sortie
```
Nombre de rapports sûrs : 2
```

## Algorithme utilisé
L’algorithme est une analyse séquentielle linéaire (parcours en O(n)), 
qui vérifie :
- La tendance globale (croissante ou décroissante) à partir des deux premiers éléments.
- La validité locale de chaque paire adjacente :
- -- Différence non nulle
- -- Différence ≤ 3
- -- Tendance constante

Il s'agit d' une validation par parcours linéaire, souvent appelée scan séquentiel ou parcours en glissement.

## Pour les débutants
Le code est entièrement commenté pour être accessible à ceux qui découvrent le C++. 

Il utilise :

- std::ifstream pour lire un fichier

- std::istringstream pour découper une ligne en nombres

- std::vector<int> pour stocker dynamiquement les niveaux

- Des boucles while et for pour parcourir les données

## Extensions possibles
- Afficher les rapports sûrs/dangereux ligne par ligne
- Ajouter une classe Rapport pour une version orientée objet
- Générer un rapport de sortie (resultats.txt)
- Intégrer une interface graphique ou une version web
