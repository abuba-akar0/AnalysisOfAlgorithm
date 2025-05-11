#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <limits>
#include <algorithm>

using namespace std;

const int MAX_CITIES = 20;
const double ALPHA = 1.0;       // Importance of pheromone
const double BETA = 5.0;        // Importance of heuristic (1/distance)
const double EVAPORATION = 0.5;
const double Q = 100.0;
const int NUM_ANTS = 10;
const int MAX_ITER = 100;

int numCities;
double distanceMatrix[MAX_CITIES][MAX_CITIES];
double pheromone[MAX_CITIES][MAX_CITIES];

struct Ant {
    vector<int> tour;
    double tourLength;
};

// Function to calculate total length of a tour
double calculateTourLength(const vector<int>& tour) {
    double length = 0.0;
    for (int i = 0; i < numCities; i++) {
        int from = tour[i];
        int to = tour[(i + 1) % numCities];
        length += distanceMatrix[from][to];
    }
    return length;
}

// Function to choose next city based on probability
int selectNextCity(const vector<bool>& visited, int currentCity) {
    vector<double> probability(numCities, 0.0);
    double sum = 0.0;

    for (int i = 0; i < numCities; i++) {
        if (!visited[i]) {
            double pher = pow(pheromone[currentCity][i], ALPHA);
            double heuristic = pow(1.0 / distanceMatrix[currentCity][i], BETA);
            probability[i] = pher * heuristic;
            sum += probability[i];
        }
    }

    double randVal = (double)rand() / RAND_MAX;
    double cumulative = 0.0;
    for (int i = 0; i < numCities; i++) {
        if (!visited[i]) {
            cumulative += probability[i] / sum;
            if (randVal <= cumulative) {
                return i;
            }
        }
    }

    // If something goes wrong, pick the first unvisited
    for (int i = 0; i < numCities; i++) {
        if (!visited[i]) return i;
    }

    return -1; // Error fallback
}

// Function to run the ACO algorithm
void runACO() {
    vector<int> bestTour;
    double bestLength = numeric_limits<double>::max();

    for (int iter = 0; iter < MAX_ITER; iter++) {
        vector<Ant> ants(NUM_ANTS);

        // Initialize each ant
        for (int k = 0; k < NUM_ANTS; k++) {
            vector<bool> visited(numCities, false);
            int startCity = rand() % numCities;
            ants[k].tour.push_back(startCity);
            visited[startCity] = true;

            for (int step = 1; step < numCities; step++) {
                int currentCity = ants[k].tour.back();
                int nextCity = selectNextCity(visited, currentCity);
                ants[k].tour.push_back(nextCity);
                visited[nextCity] = true;
            }

            ants[k].tourLength = calculateTourLength(ants[k].tour);

            // Update best solution
            if (ants[k].tourLength < bestLength) {
                bestLength = ants[k].tourLength;
                bestTour = ants[k].tour;
            }
        }

        // Evaporate pheromones
        for (int i = 0; i < numCities; i++) {
            for (int j = 0; j < numCities; j++) {
                pheromone[i][j] *= (1.0 - EVAPORATION);
            }
        }

        // Deposit new pheromones
        for (int k = 0; k < NUM_ANTS; k++) {
            for (int i = 0; i < numCities; i++) {
                int from = ants[k].tour[i];
                int to = ants[k].tour[(i + 1) % numCities];
                pheromone[from][to] += Q / ants[k].tourLength;
                pheromone[to][from] = pheromone[from][to]; // symmetric
            }
        }
    }

    // Display result
    cout << "Best tour length: " << bestLength << endl;
    cout << "Tour: ";
    for (int city : bestTour) {
        cout << city << " ";
    }
    cout << bestTour[0] << endl;
}

// Load sample distance matrix (or replace with file I/O)
void loadDistanceMatrix() {
    cout << "Enter number of cities: ";
    cin >> numCities;
    cout << "Enter distance matrix (" << numCities << "x" << numCities << "):\n";
    for (int i = 0; i < numCities; i++) {
        for (int j = 0; j < numCities; j++) {
            cin >> distanceMatrix[i][j];
        }
    }

    // Initialize pheromones
    for (int i = 0; i < numCities; i++) {
        for (int j = 0; j < numCities; j++) {
            pheromone[i][j] = 1.0;
        }
    }
}

int main() {
    srand(time(0));
    loadDistanceMatrix();
    runACO();
    return 0;
}
