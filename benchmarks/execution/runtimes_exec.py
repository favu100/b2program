import matplotlib.pyplot as plt
import numpy as np

def calculate_statistics(data, index_machine):
    machines = {}
    for line in data:
        split_line = line.split()
        if len(split_line) == 0:
            continue
        machine_name = line.split()[index_machine]
        time_seconds = float(line.split()[-2].split(':')[0]) * 60 + float(line.split()[-2].split(':')[1])
        memory_mb = round(float(line.split()[-1]) / 1000, 2)

        if machine_name not in machines:
            machines[machine_name] = {'time': [], 'memory': []}

        machines[machine_name]['time'].append(time_seconds)
        machines[machine_name]['memory'].append(memory_mb)

    for machine, values in machines.items():
        time_avg = round(np.median(values['time']), 2)
        memory_avg = round(np.median(values['memory']), 2)
        print(f"Machine: {machine}, Average Time: {time_avg} seconds, Average Memory: {memory_avg} MB")

with open('Java_Clojure_Set_Primitives/runtimes.txt', 'r') as file:
    data_java = file.readlines()

with open('C++_Primitives/runtimes.txt', 'r') as file:
    data_cpp = file.readlines()

with open('JS/runtimes.txt', 'r') as file:
    data_js = file.readlines()

print('Java:')
calculate_statistics(data_java, 3)
print('----------------------------')
print('C++:')
calculate_statistics(data_cpp, 0)
print('----------------------------')
print('JS:')
calculate_statistics(data_js, 1)
print('----------------------------')

