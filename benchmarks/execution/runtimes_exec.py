import matplotlib.pyplot as plt
import numpy as np

def calculate_statistics(data, index_machine):
    machines = {}
    for line in data:
        split_line = line.split()
        if len(split_line) == 0:
            continue
        machine_name = line.split()[index_machine]
        machine_name = machine_name.replace(".js","")
        machine_name = machine_name.replace(".exec","")
        machine_name = machine_name.replace("./","")
        time_seconds = float(line.split()[-2].split(':')[0]) * 60 + float(line.split()[-2].split(':')[1])
        memory_mb = round(float(line.split()[-1]) / 1000, 2)

        if machine_name not in machines:
            machines[machine_name] = {'time': [], 'memory': []}

        machines[machine_name]['time'].append(time_seconds)
        machines[machine_name]['memory'].append(memory_mb)

    for machine, values in machines.items():
        time_median = round(np.median(values['time']), 2)
        memory_median = round(np.median(values['memory']), 2)
        print(f"Machine: {machine}, Median Time: {time_median} seconds, Median Memory: {memory_median} MB")
        machines[machine]['time_median'] = time_median
        machines[machine]['memory_median'] = memory_median
    return machines

machine_key_pretty_names = {
    "LiftExec": "Lift",
    "TrafficLightExec": "Traffic Light",
    "Sieve": "Sieve",
    "scheduler_deterministic_exec": "Scheduler",
    "CAN_BUS_tlc_exec": "CAN Bus",
    "Train_1_beebook_deterministic_exec": "Train",
    "sort_m2_data1000_exec": "Sort",
    "Cruise_finite1_deterministic_exec": "Cruise Controller"
}

def plot_histogram(results, title, value_key):
    i = 0
    fig, ax = plt.subplots(1, len(next(iter(results.values())).keys()), figsize=(40, 6))
    fig.subplots_adjust(wspace=0.5)

    all_values = []
    for result_key in results:
        results_for_key = results[result_key]
        for machine_key, result in results_for_key.items():
            all_values.append(result[value_key])
    max_value = max(all_values)

    for machine_key in next(iter(results.values())):
        ax[i].set_xlabel(machine_key_pretty_names.get(machine_key), fontsize = 12)
        j = 0
        result_keys = []
        for result_key in results:
            result_keys.append(result_key)
            if j == 0:
                ax[i].bar(" ", results[result_key][machine_key][value_key], label=result_key)
            elif j == 1:
                ax[i].bar("  ", results[result_key][machine_key][value_key], label=result_key)
            elif j == 2:
                ax[i].bar("    ", results[result_key][machine_key][value_key], label=result_key)
            j = j + 1
        ax[i].set_ylim(0, max_value*1.01)
        ax[i].spines['top'].set_visible(False)
        ax[i].spines['right'].set_visible(False)
        ax[i].spines['bottom'].set_visible(False)
        if i > 0:
            ax[i].get_yaxis().set_visible(False)
            ax[i].spines['left'].set_visible(False)
        i = i + 1
    fig.suptitle(title, fontsize = 20)
    fig.legend(result_keys, fancybox=True)
    plt.show()

def main():
    with open('Java_Clojure_Set_Primitives/runtimes.txt', 'r') as file:
        data_java = file.readlines()

    with open('C++_Primitives/runtimes.txt', 'r') as file:
        data_cpp = file.readlines()

    with open('JS/runtimes.txt', 'r') as file:
        data_js = file.readlines()

    print('Java:')
    java_results = calculate_statistics(data_java, 3)
    print('----------------------------')
    print('C++:')
    cpp_results = calculate_statistics(data_cpp, 0)
    print('----------------------------')
    print('JS:')
    js_results = calculate_statistics(data_js, 1)
    print('----------------------------')

    results = {"Java": java_results, "C++": cpp_results, "JS": js_results}

    plot_histogram(results, 'Runtimes', 'time_median')
    plot_histogram(results, 'Memory Usage', 'memory_median')


if __name__ == "__main__":
    main()
