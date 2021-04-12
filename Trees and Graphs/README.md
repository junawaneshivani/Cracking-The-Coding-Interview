### Types of Trees
1. Binary Tree
2. Binary Search Tree
3. Balanced Tree
    - Red-Black Trees
    - AVL Trees
4. Complete Binary Tree
    - A complete binary tree is a binary tree in which every level of the tree is fully filled, except for perhaps the last level. To the extent that the last level is filled, it is filled left to right.
5. Full Binary Tree
    - A full binary tree is a binary tree in which every node has either zero or two children. That is, no nodes have
only one child.
6. Perfect Binary Tree
    - A perfect binary tree is one that is both full and complete. All leaf nodes will be at the same level, and this level has the maximum number of nodes.


### Binary Tree Traversal
- Inorder (l->root->r)
- Preorder  (root->l->r)
- Postorder (l->r->root)

### Binary Heaps 
1. Min-Heaps
    - A min-heap is a complete binary tree (that is, totally filled other than the rightmost elements on the last level) where each node is smaller than its children. The root, therefore, is the minimum element in the tree.
    - We have two key operations on a min-heap: `insert` and `extract_min`.
    - `insert`
        - When we insert into a min-heap, we always start by inserting the element at the bottom. We insert at the rightmost spot so as to maintain the complete tree property.
        - Then, we "fix"the tree by swapping the new element with its parent, until we find an appropriate spot forthe element. We essentially bubble up the minimum element.
    - `extract_min`
        - Finding the minimum element of a min-heap is easy: it's always at the top. The trickier part is how to remove it. (In fact, this isn't that tricky.)
        - First, we remove the minimum element and swap it with the last element in the heap (the bottommost, rightmost element). Then, we bubble down this element, swapping it with one of its children until the minheap property is restored.
        - Do we swap it with the left child or the right child? That depends on their values. There's no inherent ordering between the left and right element, but you'll need to take the smaller one in order to maintain
the min-heap ordering.
2. Max-Heaps
    - Max-heaps are essentially equivalent, but the elements are in descending order rather than ascending order.

### Tries (Prefix Trees)
- A trie (sometimes called a prefix tree) is a variant of an n-ary tree in which characters are stored at each node. Each path down the tree may
represent a word. 
- https://www.youtube.com/watch?v=NEYo0ibQuy8&t=499s



### Graphs
1. Adjacency List
- This is the most common way to represent a graph. Every vertex (or node) stores a list of adjacent vertices. In an undirected graph, an edge like (a, b) would be stored twice: once in a's adjacent vertices and once in b's adjacent vertices.
2. Adjacency Matrices
- An adjacency matrix is an NxN boolean matrix (where N is the number of nodes), where a true value at matrix[i][j] indicates an edge from node i to node j (You can also use an integer matrix with Os and 1s). In an undirected graph, an adjacency matrix will be symmetric. In a directed graph, it will not (necessarily) be.

### Graph Search
1. Depth-First Search
- In depth-first search, we could take a path like `Ash -> Brian -> Car let on -> Davis -> Eric
-> Farah -> Gayle -> Harry -> Isabella -> John·-> Kari ...` and thenfind ourselves very
far away. We could go through most of the world without realizing that, in fact, Vanessa is Ash's friend. We will still eventually find the path, but it may take a long time. It also won't find us the shortest path.
2. Breadth-First Search
- In breadth-first search, we would stay close to Ash for as long as possible. We might iterate through many of Ash's friends, but we wouldn't go to his more distant connections until absolutely necessary. lf Vanessa is Ash's friend, or his friend-of-a-friend, we'll find this out relatively quickly.
3. Bi-directional Search
- Bidirectional search is used to find the shortest path between a source and destination node. It operates by essentially running two simultaneous breadth-first searches, one from each node. When their searches collide, we have found a path.


### TODO:
- Topological Sort (pg 632)
- Dijkstra's Algorithm (pg 633), 
- AVL Trees (pg 637)
- RedBlackTrees (pg 639).