import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

data = pd.read_csv("../build/results.csv")

plt.figure(figsize=(10, 5))
plt.plot(np.log(data["Points"])*data["Points"], data["ConstructionTime"], label="Quadtree Construction Time", marker='o')
plt.xlabel("log(Number of Points)*Number of Points")
plt.ylabel("Time (seconds)")
plt.title("Quadtree Construction Time")
plt.legend()
plt.grid(True)
plt.show()

plt.figure(figsize=(10, 5))
plt.plot(np.log(data["Points"]), data["QuadtreeQueryTime"], label="Quadtree Query Time", marker='o')
plt.plot(np.log(data["Points"]), data["NaiveQueryTime"], label="Naive Query Time", marker='x')
plt.xlabel("log(Number of Points)*Number of Points")
plt.ylabel("Time (seconds)")
plt.title("Query Time: Quadtree vs Naive Search")
plt.legend()
plt.grid(True)
plt.show()
