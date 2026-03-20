# Quadtree Spatial Partitioning System (C++)
A C++ quadtree based system for dividing a 2D space to efficiently find nearby objects. This project demonstrates spatial partitioning concepts used in game development to optimise object lookup and reduce brute-force searches.
## ✨ Features
- Recursive subdivision of a 2D space using a quadtree
- Efficient nearby object search by ID
- File-based loading of game object data
- Reduces brute force search complexity
## ⚙️ How It Works
- Load game object data from a go.txt file
- Construct a quadtree based on object positions
- Recursive subdivide space until each quad has <= 3 Objects
- Use menu system to
  1. Print quadtree structure
  2. Search for nearby objects
## 💻 Tech-Stack
- C++
- Object-Oriented Programming
- Data Structure [Quadtree]
## 🔎 Concept
- Spatial partioning
- Quadtree data structure
- Recusive subdivision algorithm
- Efficient Seach vs Brute force method
## 👀 Preview

<img width="500" height="330" alt="Quadtree_eg" src="https://github.com/user-attachments/assets/6d09b945-cd2c-42e3-bd83-b965cfefcefc" />
<img width="272" height="288" alt="Screenshot 2026-03-21 021739" src="https://github.com/user-attachments/assets/2545ab42-58fd-4584-9c1f-b2fe9336156c" />
<br>
Each line contains a single object in the format:
ID, X, Y <br>
Example:<br> 
5,24,0 <br> 
69,23,0  <br>
240,22,0  <br>

**ID** -> Unique identifier  
**X, Y** -> Coordinates in the 2D grid  


https://github.com/user-attachments/assets/140c332b-852c-4a13-810f-60c754dc7000


