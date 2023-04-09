import matplotlib.pyplot as plt
import numpy as np

n = np.array([])
tolerance = np.array([])
with open("/Users/dmitrystarukhin/slae_course/GTest/KR2/gz_symmetric_data.txt", "r") as f:
    for line in f:
        data = line.split(' ')
        n = np.append(n, int(data[1]))
        tolerance = np.append(tolerance, float(data[0]))

fig, ax = plt.subplots(figsize=(12, 8), dpi=80)

fig.suptitle("Dependence of the number of iterations on the residual",
             fontsize='xx-large')

plt.grid(True)

plt.xticks(np.arange(0, max(n), 2))
plt.yticks(np.arange(-31, 3, 3))

ax.plot(n, tolerance)

plt.ylabel(r'log(Ax - b)', fontsize=14)
plt.xlabel(r'Number of iterations', fontsize=14)
plt.savefig("plot_symmetric_gz.png")
plt.show()