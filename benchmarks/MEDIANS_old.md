 
# Benchmarks

## Results

| Machines          |             | ProB      | Java PI   | PYTHON PR  | Python MI  | Python MI PYPY | Python FS |
|-------------------|-------------|-----------|-----------|------------|------------|----------------|-----------|
| Lift              | **Runtime** | > 20:00   | 0:26.82   | > 20:00    | > 20:00    | 0:16.28        | > 20:00   |
|                   | **Speedup** | 1         | > 44,74   | 1          | 1          | > 73,71        | 1         |
|                   | **Memory**  | -         | 556884    | -          | -          | 72504          | -         |
| TrafficLight      | **Runtime** | > 20:00   | 0:09.74   | > 20:00    | > 20:00    | 0:08.50        | > 20:00   |
|                   | **Speedup** | 1         | > 123,2   | 1          | 1          | > 141,18       | 1         |
|                   | **Memory**  | -         | 318404    | -          | -          | 79444          | -         |
| Sieve             | **Runtime** | 3:19.73   | 0:10.81   | > 20:00    | 1:36.21    | 0:38.92        | > 20:00   |
|                   | **Speedup** | 1         | 18,48     | < 0,16     | 2,08       | 5,13           | < 0,16    |
|                   | **Memory**  | 403328    | 1 438 952 | -          | 743 924    | 1 142 140      | -         |
| Scheduler         | **Runtime** | > 20:00   | 0:10.09   | 9:06.11    | 1:21.71    | 0:15.22        | 1:16.93   |
|                   | **Speedup** | 1         | > 118,93  | > 2,2      | > 14,69    | > 78,84        | > 15,6    |
|                   | **Memory**  | -         | 327136    | 11976      | 9788       | 83736          | 9716      |
| sort_m2_data1000  | **Runtime** | 0:40.01   | 0:01.99   | 0:30.81    | 0:05.56    | 0:01.31        | 1:16.93   |
|                   | **Speedup** | 1         | 20,11     | 1,3        | 7,2        | 30,54          | 0,52      |
|                   | **Memory**  | 582708    | 151976    | 15036      | 10160      | 82724          | 12328     |
| CAN Bus           | **Runtime** | 8:37.71   | 0:07.53   | 1:07.77    | 0:34.14    | 0:26.51        | 0:46.52   |
|                   | **Speedup** | 1         | 68,75     | 7,64       | 15,16      | 19,53          | 11,13     |
|                   | **Memory**  | 172080    | 314424    | 26476      | 26456      | 86548          | 26488     |
| Train             | **Runtime** | 2:23.47   | 0:12.60   | 1:42.79    | 0:13.64    | 0:10.13        | 0:24.14   |
|                   | **Speedup** | 1         | 11,39     | 1,4        | 10,52      | 14,16          | 5,94      |
|                   | **Memory**  | 169120    | 309412    | 12300      | 9832       | 88104          | 10144     |
| Cruise Controller | **Runtime** | > 20:00   | 0:18.73   | 17:58.14   | 11:41.75   | 3:23.90        | 17:59.44  |
|                   | **Speedup** | 1         | > 64,07   | > 1,11     | > 1,71     | > 5,89         | > 1,11    |
|                   | **Memory**  | -         | 314592    | 17332      | 15568      | 85140          | 15636     |

Runtime in Seconds

Memory Usage in KB

MI = Magicstack Immutable

FS = Frozen Set

PR = Pyrsistent Map

BI = Big Integer

PI = Primitive Integer
