import matplotlib.pyplot as plt
import numpy as np

number_iterations = np.array([])
intermediate_lambda = np.array([])
with open("/GTest/KR2/MPI_fast_data.txt", "r") as f:
    for line in f:
        data = line.split(' ')
        number_iterations = np.append(number_iterations, int(data[1]))
        intermediate_lambda = np.append(intermediate_lambda, float(data[0]))

fig, ax = plt.subplots(figsize=(12, 8), dpi=80)

fig.suptitle("Dependence of the number iterations from the choosing max lambda",
             fontsize='xx-large')

plt.grid(True)

plt.xticks(np.arange(150.3, 160.9, 1.5))
plt.yticks(np.arange(80, 9700, 1000))

ax.plot(intermediate_lambda, number_iterations)

plt.ylabel(r'number of iterations', fontsize=14)
plt.xlabel(r'lambda - lambda_min', fontsize=14)
plt.savefig("MPI_fast.png")
plt.show()