import matplotlib.pyplot as plt

file_container= "build/perf_container.txt"
grid_sizes_container = []
times_container = []

with open(file_container, "r") as f:
    for line in f:
        size_container, time_container = map(float, line.strip().split())
        grid_sizes_container.append(int(size_container))
        times_container.append(time_container)

file_no_container= "build/perf_no_container.txt"
grid_sizes_no_container = []
times_no_container = []

with open(file_no_container, "r") as f:
    for line in f:
        size_no_container, time_no_container = map(float, line.strip().split())
        grid_sizes_no_container.append(int(size_no_container))
        times_no_container.append(time_no_container)


plt.figure(figsize=(10, 6))
plt.plot(grid_sizes_container, times_container, marker='o', linestyle='-', color='b', label='With container')
plt.plot(grid_sizes_no_container, times_no_container, marker='o', linestyle='-', color='r', label='Without container')
plt.xlabel("Grid size")
plt.ylabel("Time")
plt.legend()
plt.grid(True)
plt.show()
