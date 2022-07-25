import statistics
import sys
from datetime import timedelta

file = sys.argv[1]
print('opening file: ', file)

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
        params = (mode, int(threads), caching == 'true')
        if params not in data[machine]:
            data[machine][params] = {'times': [], 'memory': []}
        data[machine][params]['times'] += [time]
        data[machine][params]['memory'] += [int(memory)]

for machine in data.keys():
    for params in data[machine]:
        times = data[machine][params]['times']
        avg_time = timedelta()
        number_of_datapoints = 0

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
            avg_time += timedelta(minutes=minutes, seconds=seconds, milliseconds=millis)
        if number_of_datapoints > 0:
            avg_time /= number_of_datapoints

        memories = data[machine][params]['memory']

        print(f'{machine} {params[0]} {params[1]} {params[2]} {round(avg_time.total_seconds(), 2)} {round(statistics.fmean(memories))}')
