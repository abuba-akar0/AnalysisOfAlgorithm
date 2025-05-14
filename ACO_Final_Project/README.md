# 🐜 Ant Colony Optimization (ACO) for Route Optimization 🚚📦

## 📖 Overview
This project implements the **Ant Colony Optimization (ACO)** algorithm in **C++** to solve the **Traveling Salesman Problem (TSP)** — a classic NP-Hard problem in combinatorial optimization. Inspired by the foraging behavior of real ants, ACO offers a robust metaheuristic technique for finding near-optimal solutions to complex problems where exhaustive search is computationally impractical.

---

## ✨ Features
✅ Clean, modular C++ implementation  
✅ Adjustable parameters (alpha, beta, evaporation rate, number of ants, iterations)  
✅ Console-based I/O with user-defined distance matrix  
✅ Real-time display of best tour and length  
✅ Theoretical & empirical complexity analysis  
✅ Real-world logistics use case exploration  
✅ Ethical and operational impact discussion  
✅ APA 6 research report and presentation

---

## 📊 Algorithm Details

- **Problem Type:** Combinatorial Optimization (NP-Hard)
- **Approach:** Ant Colony Metaheuristic
- **Key Concepts:**
  - Pheromone trail updates
  - Heuristic distance information
  - Probabilistic decision-making
  - Evaporation and reinforcement mechanism

### 📈 Complexity
|    Metric     |                Value                |
|:-------------:|:-----------------------------------:|
| Time Complexity | `O(iterations × ants × cities²)`  |
| Space Complexity |          `O(cities²)`           |

---

## 🖥️ Project Structure
```
/ACO/
├── /code/
│   └── aco.cpp                # C++ Implementation
├── /docs/
│   ├── pseudocode.md          # Step-by-step pseudocode
│   ├── complexity.md          # Time & space analysis
│   └── flowchart.png          # Algorithm flow diagram
├── REPORT.pdf                 # Full APA 6 styled report
├── benchmark_graph.png        # Empirical runtime chart
└── README.md                  # This documentation file
```
---

## 🛠️ How to Run

1️⃣ **Compile the C++ Program**

```bash

g++ -o aco.exe main.cpp ACO.cpp Randoms.cpp
./aco.exe
```
2️⃣ **Input**
- Provide the number of cities and a symmetric distance matrix when prompted.

3️⃣ **Output**
- Shortest tour found
- Tour distance

## 📊 Benchmark Summary

| Number of Cities  | Execution Time (ms) | Best Tour Length |
|:-----------------:|:-------------------:|:-----------------|
|        5	         |         10	         | 42.0             |
|        8	         |         25	         | 75.3             |
|       10	         |         50	         | 100.5            |
|       15	         |         95	         | 150.2            |
|       20	         |        200	         | 215.9            |

Full benchmark results and graph available in /docs/.

## CLOs and Seoul Accord Attributes

| **Seoul Accord Attribute** | **Project Task** | **CLO Mapped** | **Bloom’s Level** |
|----------------------------|------------------|----------------|-------------------|
| 1. Conflicting requirements | Optimize for time (polynomial-time approx.) and space (memory constraints) in NP-Hard problems. | 3.1, 6.1 | Apply, Create |
| 2. Depth of analysis | Prove NP-Completeness of a chosen problem via reduction; justify approximation trade-offs. | 2.1, 4.1, 5.1 | Understand, Analyze |
| 3. Depth of knowledge | Implement two distinct design paradigms (e.g., Greedy + DP) and compare analytically. | 3.1, 6.1 | Apply, Create |
| 4. Unfamiliar issues | Address a problem with no known optimal solution (e.g., novel graph traversal scenario). | 6.1 | Create |
| 5. Beyond standard practice | Propose a hybrid approach (e.g., metaheuristics) for a problem outside textbook examples. | 6.1 | Create |
| 6. Stakeholder diversity | Simulate constraints from multiple stakeholders (e.g., cost vs. speed in logistics). | 3.1 | Apply |
| 7. Significant consequences | Analyze societal impact (e.g., bias in algorithmic decisions or energy efficiency). | 5.1 | Evaluate |
| 8. Interdependence | Decompose problem into sub-problems (e.g., use D&C for sorting + DP for optimization). | 4.1, 6.1 | Analyze, Create |
| 9. Ill-defined requirements | Refine problem scope iteratively (e.g., adjust input constraints based on empirical results). | 3.1, 5.1 | Apply, Evaluate |

---

## Course Learning Outcomes (CLOs) & Bloom’s Taxonomy

| **Code #** | **Bloom’s Level** | **Course Learning Outcome (CLO)** | **Seoul Accord Alignment** |
|------------|-------------------|-----------------------------------|----------------------------|
| 2.1        | Understand        | Explain P, NP, NPC, NPH problems, NP-Completeness, and approximation techniques. | Attributes #2, #3 (Depth of analysis/knowledge) |
| 3.1        | Apply             | Implement algorithms, compare empirical performance, and solve real-world problems. | Attributes #1, #6 (Conflicting needs/stakeholders) |
| 4.1        | Analyze           | Analyze time/space complexity of recursive/non-recursive algorithms. | Attributes #2, #4 (Depth/unfamiliar issues) |
| 4.2        | Analyze           | Discuss asymptotic notations (Big-O, Ω, Θ), complexity classes, and function representations. | Attributes #3, #8 (Knowledge/interdependence) |
| 5.1        | Evaluate          | Compare/solve algorithmic problems (Sorting, Searching, Graphs). | Attributes #5, #7 (Beyond standards/consequences) |
| 6.1        | Create            | Design algorithms using Brute Force, D&C, DP, and Greedy techniques. | Attributes #8, #9 (Interdependence/ill-defined) |

---

## 🌍 Real-World Use Case

### 📦 E-Commerce Logistics Route Optimization

Ant Colony Optimization (ACO) dynamically identifies efficient delivery routes for **last-mile logistics networks**. By mimicking the pheromone-based foraging behavior of real ants, ACO iteratively improves route solutions, significantly reducing **operational costs**, **fuel consumption**, and **environmental impact** while ensuring **on-time deliveries** for e-commerce businesses.

> This application demonstrates ACO’s capability to address complex, high-stakes logistical challenges through intelligent, nature-inspired metaheuristic optimization, delivering tangible operational and environmental benefits in real-world scenarios.


---
## Conclusion
 - This project aims to deepen your understanding of algorithms, their complexities, and real-world implications. By following the outlined steps, you will not only learn about a specific algorithm but also develop critical thinking and problem-solving skills essential for a career in computer science.

---
