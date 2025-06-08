# Leeetcode-1609.-Even-Odd-Tree
# 🌳 Even-Odd Tree Validator

This project checks whether a given binary tree satisfies the **Even-Odd Tree** conditions.

A binary tree is considered an **Even-Odd Tree** if:
- All nodes at even-indexed levels have **odd** values in **strictly increasing** order.
- All nodes at odd-indexed levels have **even** values in **strictly decreasing** order.

---

## 🧠 Approach

We use **level-order traversal (BFS)** to visit nodes level by level:
- At each level, we track the previous node value.
- Depending on whether it's an even or odd level, we apply appropriate constraints:
  - **Even level** (0, 2, 4...): only **odd** numbers, must be **strictly increasing**
  - **Odd level** (1, 3, 5...): only **even** numbers, must be **strictly decreasing**

If any condition is violated at any level, we return `false`.

---

## ⏱ Time and Space Complexity

| Metric              | Value                     |
|---------------------|---------------------------|
| 🕒 Time Complexity   | `O(N)` (visit each node once) |
| 💾 Space Complexity  | `O(W)` (max queue size = max width of the tree) |

---

## ✅ Example

**Input Tree:**

```cpp
    1
   / \
  10  4
 /    / \
3    7   9



- Level 0 → [1] ✅ odd & increasing  
- Level 1 → [10, 4] ✅ even & decreasing  
- Level 2 → [3, 7, 9] ✅ odd & increasing  

```

✅ Output: `true`

---

## ✍️ Author

**Ridham Garg**  
👨‍💻 Passionate C++ Developer | Binary Tree Enthusiast | Optimizer  
🎓 Thapar University, Patiala  
📬 Let's code smarter and cleaner, one problem at a time!

---

💡 Tip: Try to implement the same logic using DFS to see how the order of traversal changes the implementation!


