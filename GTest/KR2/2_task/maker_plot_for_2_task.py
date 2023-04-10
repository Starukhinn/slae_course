import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

plt.style.use('seaborn-white')

Lmin = 17
Lmax = 25.5
H1 = np.array([1, 0, 0, 0])
H2 = np.array([0, 0, 0, 1])


def f(x, y):
    A = np.array([[17.0, 0, 0, 0],
                  [0, 19.0, 0, 0],
                  [0, 0, 22.0, 0],
                  [0, 0, 0, 25.5]])
    b = np.array([3.0, 3.0, 3.0, 3.0])
    c = 4.0

    z = np.ones((len(x), len(y)), dtype=float)
    for i in range(len(x[0])):
        for j in range(len(x[0])):
            stolb = H1 * x[0][i] + x[0][j] * H2
            z[i][j] = (stolb.transpose().dot(A).dot(stolb) - b.transpose().dot(stolb) + c)
    return z


with open('/Users/dmitrystarukhin/slae_course/GTest/KR2/2_task/kr2_2_MPI1.txt') as f:
    tau = []
    n = []
    for line in f:
        string = line.split()
        n.append(float(string[0]))
        tau.append(float(string[1]))

with open("/Users/dmitrystarukhin/slae_course/GTest/KR2/2_task/MPI_fast.txt") as f:
    tau1 = []
    n1 = []
    for line in f:
        string = line.split()
        n1.append(float(string[0]))
        tau1.append(float(string[1]))

with open("/Users/dmitrystarukhin/slae_course/GTest/KR2/2_task/kr2_2_MPI2.txt") as f:
    tau2 = []
    n2 = []
    for line in f:
        string = line.split()
        n2.append(float(string[0]))
        tau2.append(float(string[1]))

with open("/Users/dmitrystarukhin/slae_course/GTest/KR2/2_task/CG.txt") as f:
    tau3 = []
    n3 = []
    for line in f:
        string = line.split()
        n3.append(float(string[0]))
        tau3.append(float(string[1]))

with open('/Users/dmitrystarukhin/slae_course/GTest/KR2/2_task/steepest_descent.txt') as f:
    tau4 = []
    n4 = []
    for line in f:
        string = line.split()
        n4.append(float(string[0]))
        tau4.append(float(string[1]))
plt.grid(True)
plt.plot(n, tau, 'o-k', alpha=0.7, label="MPI", lw=0.5, mec='k', mew=2, ms=2)
plt.plot(n1, tau1, 'o-r', alpha=0.7, label="MPI_chebyshev", lw=0.5, mec='r', mew=7, ms=2)
plt.plot(n2, tau2, 'o-g', alpha=0.7, label="MPI_opt_tau", lw=0.5, mec='g', mew=7, ms=2)
plt.plot(n3, tau3, 'o-m', alpha=0.7, label="Conjugate_gradient", lw=0.5, mec='m', mew=7, ms=2)
plt.plot(n4, tau4, 'o-c', alpha=0.7, label="Gradient_descent", lw=0.5, mec='c', mew=4, ms=2)

plt.legend(['MPI', "MPI-Chebyshev accelaration", 'MPI-optimal tau', 'CG', "Gradient descent"])
plt.xlabel('h[Λmin]')
plt.ylabel('h[Λmax]')
plt.savefig('projections of steps')
plt.show()
