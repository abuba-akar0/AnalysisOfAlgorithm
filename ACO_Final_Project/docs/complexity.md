# Complexity Analysis

## Theoretical Complexity

| Metric | Complexity | Derivation |
|--------|------------|-----------|
| **Time** | $O(I \times M \times N^2)$ | Each ant constructs a path (O(N²)), repeated for M ants and I iterations. |
| **Space** | $O(N^2)$ | Stores distance and pheromone matrices. |

## Empirical Benchmarking

| Cities (N) | Runtime (seconds) |
|------------|-------------------|
| 5          | 0.01              |
| 10         | 0.08              |
| 15         | 0.45              |
| 20         | 1.32              |

## Alignment with CLOs and Attributes
- **CLO 2.1**: Explains NP-Completeness of TSP via reduction from Hamiltonian Cycle.
- **CLO 4.1**: Analyzes time complexity using Big-O notation.
- **Attribute #4**: Addresses an NP-Hard problem with no known optimal solution.
- **Attribute #8**: Decomposes the problem into subproblems (path generation, pheromone update).

## Conclusion

- The complexity analysis of the Ant Colony Optimization algorithm for the Traveling Salesman Problem (TSP) reveals both theoretical and empirical insights. The theoretical complexity indicates a polynomial time complexity, while empirical benchmarks demonstrate practical performance across varying city counts. The alignment with course learning outcomes and attributes underscores the algorithm's relevance in computational theory and problem-solving.
---
