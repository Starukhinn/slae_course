import matplotlib.pyplot as plt
import numpy as np


def MakePlot(data_file_path, plot_name, method_name, x_step, y_step):
    discrepancy_log = np.array([])
    iteration_number = np.array([])
    with open(data_file_path, "r") as f:
        for line in f:
            data = line.split(' ')
            discrepancy_log = np.append(discrepancy_log, float(data[0]))
            iteration_number = np.append(iteration_number, int(data[1]))

    fig, ax = plt.subplots(figsize=(12, 8), dpi=80)

    fig.suptitle("dependence of the logarithm of the discrepancy on the iteration number " + method_name,
                 fontsize='xx-large')

    plt.grid(True)

    plt.xticks(np.arange(0, max(iteration_number), x_step))
    plt.yticks(np.arange(int(min(discrepancy_log)), int(max(discrepancy_log)), y_step))

    ax.plot(iteration_number, discrepancy_log)

    plt.xlabel(r'iteration number', fontsize=14)
    plt.ylabel(r'log(Ax - b)', fontsize=14)
    plt.savefig(plot_name)
    plt.show()


MakePlot("/Users/dmitrystarukhin/slae_course/KR1/exercise4/GZ.txt", "GZ.png", "GZ", 1, 3)
MakePlot("/Users/dmitrystarukhin/slae_course/KR1/exercise4/jacobi.txt", "jacobi.png", "jacobi", 1, 3)
MakePlot("/Users/dmitrystarukhin/slae_course/KR1/exercise4/MPI.txt", "MPI.png", "MPI", 20000, 1.5)

