#include <iostream> //entrees-sorties
#include <fstream> //manip fichiers
#include <vector> //tableau
#include <algorithm> //sort
#include <cmath> //calculs
#include <sstream> //lecture du fichier
#include <thread> //parallelisation

// Calcul de la distance partielle
void computePartialDistance(const std::vector<int>& left, const std::vector<int>& right, 
                                                       int start, int end, int& result) {
    int partial = 0;
    for (int i = start; i < end; ++i) {
        partial += std::abs(left[i] - right[i]);
    }
    result = partial;
}

int main() {
    std::ifstream file("input.txt");
    std::vector<int> leftList, rightList;

    if (!file) {
        std::cerr << "Erreur : impossible d'ouvrir le fichier." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int left, right;
        if (iss >> left >> right) {
            leftList.push_back(left);
            rightList.push_back(right);
        }
    }

    file.close();

    // Tri des deux listes
    std::sort(leftList.begin(), leftList.end());
    std::sort(rightList.begin(), rightList.end());

    // Calcul de la distance totale
    int result1 = 0, result2 = 0;

    // Définir les indices de découpage
    int mid = leftList.size() / 2;

    // Thread 1 : première moitié
    std::thread t1(computePartialDistance, std::ref(leftList), std::ref(rightList),
               0, mid, std::ref(result1));

    // Thread 2 : deuxième moitié
    std::thread t2(computePartialDistance, std::ref(leftList), std::ref(rightList),
               mid, leftList.size(), std::ref(result2));

    // Attente de la fin des threads
    t1.join();
    t2.join();

    int totalDistance = result1 + result2;

    std::cout << "Distance totale : " << totalDistance << std::endl;


    return 0;
}
