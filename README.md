*This project has been created as part of the 42 curriculum by cycolonn.*

# 🔢 Push_swap - Technical Documentation

## 1. Description
**Push_swap** is a highly efficient data sorting project that requires sorting a stack of integers using a limited set of instructions and a secondary stack. The main objective is to find the smallest sequence of operations to achieve a perfectly sorted stack, emphasizing algorithmic complexity and optimization.

---

<br />

## 2. Technical Instructions & Features
The program implements a rigorous sorting logic to meet the school's performance benchmarks:

---

<br />

* **The Instruction Set**: Full support for `sa`, `sb`, `ss` (swap), `pa`, `pb` (push), `ra`, `rb`, `rr` (rotate), and `rra`, `rrb`, `rrr` (reverse rotate).
* **Input Validation**: Robust parsing that handles non-numeric input, integer overflows (MIN/MAX INT), and duplicate values.
* **Stack Management**: Implementation of a doubly linked list structure to perform stack operations with $O(1)$ complexity.
* **Performance Benchmarks**: Optimized to sort 100 numbers in fewer than 700 moves and 500 numbers in fewer than 5500 moves.

---

<br />

## 3. Resources & Technical Choices
For this project, I implemented an approach based on the **Turk Algorithm**, focusing on dynamic cost calculation to minimize operations.

---

<br />

### 🧠 The Sorting Strategy (Turk Algorithm)
* **Initial Push**: The algorithm begins by pushing most elements from Stack A to Stack B, leaving only three elements in A to be sorted instantly using a specialized "Sort Three" logic.
* **Cost Analysis**: For every element in Stack A, the program calculates the "cost" (number of operations) required to move it to its correct position in Stack B.
* **The "Cheapest" Move**: It identifies the element with the lowest total cost. This involves calculating combined rotations (`rr`, `rrr`) to move both stacks simultaneously, significantly reducing the operation count.
* **Mechanical Turk Logic**: Once Stack A is empty (except for the 3 sorted elements), everything is pushed back from B to A in one final, ordered pass.

---

<br />

### 📊 Testing, Complexity & Visualization
To ensure the algorithm's efficiency and correctness, I utilized specialized community tools:

* **[Visualizer](https://github.com/o-reo/push_swap_visualizer)**: A graphical tool to observe the Turk logic in real-time. This was crucial for debugging the cost calculation and ensuring that combined rotations were triggered correctly.
* **[Complexity Tester](https://github.com/louisvane/push_swap_tester)**: Used to run large-scale simulations (100 and 500 values) and ensure the move count stays consistently within the "5-point" bracket.
* **Checker**: Validated all outputs using the `checker_linux` utility to verify that the final stack is truly sorted and that no instructions are corrupted.

---

<br />

### 🏗️ Robustness and Cleanup
* **Error Handling**: Any invalid input results in a clean exit with a single "Error" message on the standard error output.
* **Memory Management**: Every node and temporary structure is systematically freed. The project is verified to be 100% leak-free.

---

<br />

### 📜 Authorized Functions
This project is built using: `read`, `write`, `malloc`, `free`, and `exit`.

---

<br />

## 💻 How to Compile and Run
To compile the project and test the sorting efficiency:

---

<br />

```bash
# Clone the repository
git clone [https://github.com/Cyril-glitch/push_swap.git](https://github.com/Cyril-glitch/push_swap.git)

# Navigate and compile
cd push_swap
make

# Run the program with a list of integers
./push_swap 3 2 5 1 4

# Visualizing the number of operations
ARG="3 0 9 2 -1"; ./push_swap $ARG | wc -l

# Testing with the checker
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
