#include <iostream>     // Pour afficher des messages à l'écran
#include <fstream>      // Pour lire le fichier texte
#include <sstream>      // Pour découper chaque ligne en nombres
#include <vector>       // Pour stocker les niveaux d'un rapport
#include <cmath>        // Pour utiliser std::abs (valeur absolue)

// Fonction qui vérifie si un rapport est "sûr"
bool estRapportSur(const std::vector<int>& niveaux) {
    // Un rapport avec moins de 2 niveaux ne peut pas être analysé
    if (niveaux.size() < 2) return false;

    // On calcule la première différence pour déterminer la tendance
    int premiereDiff = niveaux[1] - niveaux[0];

    // Si les deux premiers niveaux sont égaux, le rapport est invalide
    if (premiereDiff == 0) return false;

    // On déduit la tendance : croissant ou décroissant
    bool croissant = premiereDiff > 0;
    bool decroissant = premiereDiff < 0;

    // On parcourt tous les niveaux du rapport
    for (size_t i = 1; i < niveaux.size(); ++i) {
        int diff = niveaux[i] - niveaux[i - 1];

        // Si deux niveaux sont égaux, ce n'est ni une montée ni une descente
        if (diff == 0) return false;

        // Si la différence est trop grande (plus de 3), c'est dangereux
        if (std::abs(diff) > 3) return false;

        // Si la tendance change en cours de route, le rapport est instable
        if (croissant && diff < 0) return false;
        if (decroissant && diff > 0) return false;
    }

    // Si toutes les vérifications sont passées, le rapport est sûr
    return true;
}

int main() {
    // On ouvre le fichier contenant les rapports
    std::ifstream fichier("rapports.txt");

    // Si le fichier ne s'ouvre pas, on affiche une erreur
    if (!fichier) {
        std::cerr << "Erreur : impossible d'ouvrir le fichier.\n";
        return 1;
    }

    std::string ligne;
    int rapportsSurs = 0;

    // On lit le fichier ligne par ligne
    while (std::getline(fichier, ligne)) {
        std::istringstream iss(ligne);  // Pour découper la ligne en nombres
        std::vector<int> niveaux;       // Stocke les niveaux du rapport
        int n; //chaque nombre lu depuis iss est d’abord mis dans n

        // On lit chaque nombre de la ligne
        while (iss >> n) {
            niveaux.push_back(n); // n ajouté au vector
        }

        // On vérifie si le rapport est sûr
        if (estRapportSur(niveaux)) {
            rapportsSurs++;
        }
    }

    // On affiche le nombre total de rapports sûrs
    std::cout << "Nombre de rapports sûrs : " << rapportsSurs << std::endl;

    return 0;
}
