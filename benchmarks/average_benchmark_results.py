import statistics
import sys
from datetime import timedelta

file = sys.argv[1]
print('opening file: ', file)

full_print = True
if len(sys.argv) > 2 and sys.argv[2].upper() == 'SHORT':
    print('argv2 provided')
    full_print = False

#      {machine: { (mode: str, threads: int, caching: bool): {times: [], memory: []} }}
data = {}

with open(file, 'r') as lines:
    for line in lines:
        #print('parsing line: ', line)
        stripped_line = line.strip()
        if stripped_line == '' or stripped_line.startswith('-'):
            continue
        machine, mode, threads, caching, time, memory = stripped_line.split(' ')
        if machine not in data:
            data[machine] = {}
        params = (mode, int(threads), caching.upper() == 'TRUE')
        if params not in data[machine]:
            data[machine][params] = {'times': [], 'memory': []}
        data[machine][params]['times'] += [time]
        data[machine][params]['memory'] += [int(memory)]

for machine in data.keys():
    for params in data[machine]:
        times = data[machine][params]['times']
        avg_time = timedelta()
        number_of_datapoints = 0
        parsed_times = []

        for time in times:
            number_of_datapoints += 1
            minutes = 0
            if ':' in time:
                split = time.split(':')
                minutes = int(split[0])
                time = split[1]

            millis = 0
            if '.' in time:
                split = time.split('.')
                millis = int(split[1].ljust(3, '0'))
                time = split[0]

            seconds = int(time)
            parsed_time = timedelta(minutes=minutes, seconds=seconds, milliseconds=millis)
            avg_time += parsed_time
            parsed_times += [parsed_time]

        parsed_times.sort()
        if number_of_datapoints <= 0:
            continue

        avg_time /= number_of_datapoints
        median_time = parsed_times[len(parsed_times) // 2]
        if len(parsed_times) % 2 == 0:
            median_time = (median_time + parsed_times[len(parsed_times) // 2 + 1]) / 2

        memories = data[machine][params]['memory']
        memories.sort()
        median_memory = memories[len(memories) // 2]
        if len(memories) % 2 == 0:
            median_memory = (median_memory + memories[len(memories) // 2 + 1]) / 2

        spacing = " "*(len(machine) + len(params[0]) + len(str(params[1])) + len(str(params[2])) - 5)
        print(f'{machine} {params[0]} {params[1]} {params[2]} {round(median_time.total_seconds(), 2)} {round(median_memory)}')
        if full_print:
            print(                               f'{spacing}time  : min {round(parsed_times[0].total_seconds(), 2)}, '
                                                 f'median: {round(median_time.total_seconds(), 2)}, '
                                                 f'average: {round(avg_time.total_seconds(), 2)}, '
                                                 f'max: {round(parsed_times[-1].total_seconds(), 2)}')
            print(                               f'{spacing}memory: min {round(memories[0])}, '
                                                 f'median: {round(median_memory)}, '
                                                 f'average: {round(statistics.fmean(memories))}, '
                                                 f'max: {round(memories[-1])}')
