import matplotlib.pyplot as plt
import numpy as np

n = np.array([])
tau = np.array([])
with open("/Users/dmitrystarukhin/slae_course/KR1/exercise3/MPI3.txt", "r") as f:
    for line in f:
        data = line.split(' ')
        n = np.append(n, int(data[0]))
        tau = np.append(tau, float(data[1]))

fig, ax = plt.subplots(figsize=(12, 8), dpi=80)

fig.suptitle("Dependence of the number of iterations on the residual",
             fontsize='xx-large')

plt.grid(True)

plt.xticks(np.arange(1e-3, 1e-2, 1e-3))
plt.yticks(np.arange(0, max(n), 1000))

ax.plot(tau, n)

plt.xlabel(r'$\tau$', fontsize=14)
plt.xlabel(r'Number of iterations', fontsize=14)
plt.savefig("plot_3.png")
plt.show()