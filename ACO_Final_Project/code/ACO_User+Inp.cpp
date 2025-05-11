#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <algorithm>
#include <ctime>

using namespace std;

class AntColonyOptimizer {
private:
    vector<vector<double>> distances;
    vector<vector<double>> pheromone;
    int n_cities;
    int n_ants;
    int n_iterations;
    double decay;
    double alpha;
    double beta;
    double q;

    random_device rd;
    mt19937 gen;

public:
    AntColonyOptimizer(
        const vector<vector<double>>& dist,
        int ants, int iterations, double decay_rate,
        double alpha_val, double beta_val, double q_val
    ) : distances(dist), n_ants(ants), n_iterations(iterations),
        decay(decay_rate), alpha(alpha_val), beta(beta_val), q(q_val), gen(rd()) {
        n_cities = distances.size();
        pheromone = vector<vector<double>>(n_cities, vector<double>(n_cities, 1.0 / n_cities));
    }

    vector<int> run() {
        vector<int> best_path;
        double best_cost = numeric_limits<double>::infinity();

        for (int iter = 0; iter < n_iterations; ++iter) {
            vector<pair<vector<int>, double>> all_paths;
            for (int ant = 0; ant < n_ants; ++ant) {
                vector<int> path = generate_path();
                double cost = calculate_cost(path);
                all_paths.push_back({path, cost});
                if (cost < best_cost) {
                    best_cost = cost;
                    best_path = path;
                }
            }
            update_pheromone(all_paths);
            cout << "Iteration " << iter + 1 << ": Best Cost = " << best_cost << endl;
        }
        return best_path;
    }

private:
    vector<int> generate_path() {
        vector<int> path;
        vector<bool> visited(n_cities, false);
        uniform_int_distribution<> dist(0, n_cities - 1);
        int current = dist(gen);
        path.push_back(current);
        visited[current] = true;

        for (int i = 1; i < n_cities; ++i) {
            vector<double> probabilities = compute_probabilities(current, visited);
            discrete_distribution<> choose(probabilities.begin(), probabilities.end());
            current = choose(gen);
            path.push_back(current);
            visited[current] = true;
        }
        return path;
    }

    vector<double> compute_probabilities(int current, const vector<bool>& visited) {
        vector<double> probs(n_cities, 0.0);
        double total = 0.0;

        for (int j = 0; j < n_cities; ++j) {
            if (!visited[j]) {
                probs[j] = pow(pheromone[current][j], alpha) * pow(1.0 / (distances[current][j] + 1e-10), beta);
                total += probs[j];
            }
        }

        if (total == 0.0) {
            for (int j = 0; j < n_cities; ++j) {
                probs[j] = !visited[j] ? 1.0 / (n_cities - j) : 0.0;
            }
        } else {
            for (int j = 0; j < n_cities; ++j) {
                probs[j] /= total;
            }
        }
        return probs;
    }

    double calculate_cost(const vector<int>& path) {
        double cost = 0.0;
        for (size_t i = 0; i < path.size() - 1; ++i) {
            cost += distances[path[i]][path[i + 1]];
        }
        cost += distances[path.back()][path[0]];  // Return to start
        return cost;
    }

    void update_pheromone(const vector<pair<vector<int>, double>>& paths) {
        for (auto& [path, cost] : paths) {
            for (size_t i = 0; i < path.size() - 1; ++i) {
                int u = path[i], v = path[i + 1];
                pheromone[u][v] += q / (cost + 1e-10);
                pheromone[v][u] = pheromone[u][v];  // Symmetric update
            }
        }

        for (int i = 0; i < n_cities; ++i) {
            for (int j = 0; j < n_cities; ++j) {
                pheromone[i][j] *= (1.0 - decay);
            }
        }
    }
};

int main() {
    vector<vector<double>> distances = {
        {0, 10, 15, 20, 12},
        {10, 0, 35, 25, 8},
        {15, 35, 0, 30, 22},
        {20, 25, 30, 0, 18},
        {12, 8, 22, 18, 0}
    };

    AntColonyOptimizer aco(distances, 10, 50, 0.05, 1, 3, 100);
    vector<int> best_path = aco.run();

    cout << "\nBest Path Found: ";
    for (int city : best_path) {
        cout << city << " -> ";
    }
    cout << best_path[0] << endl;

    return 0;
}