# Benchmarks

## Execution

Executing benchmarks is done by executing ``make`` in each of the directories.

## Technical Data
- Java: Java HotSpot(TM) 64-Bit Server VM (build 12.0.1+12,mixed mode, sharing)
- C++ Compiler: Apple LLVM version 10.0.1 (clang-1001.0.46.4) with -O1 and -O2 
- ProB: 1.9.0-nightly (c5a6e9d31022d0bfe40cbcdf68e910041665ec41)
- B2Program Commit: edce3cc7af2e7dd678ddb90ea1a1360062f94313
- Device: MacBook Air with 8 GBof RAM and a 1.6 GHz Intel i5 processor with two cores

## Results

| Machines          |             | ProB      | Java BI   | Java PI   | C++ PI -O1 | C++ PI -O2 |
|-------------------|-------------|-----------|-----------|-----------|------------|------------|
| Lift              | **Runtime** | > 1800    | 156.63    | 27.43     | 78.42      | 0.00       |
|                   | **Speedup** | 1         | > 11.49   | > 65.62   | > 22.95    | > 180 000  |
|                   | **Memory**  | -         | 735 188   | 785 628   | 756        | 736        |
| TrafficLight      | **Runtime** | > 1800    | 47.04     | 9.05      | 69.09      | 0.00       |
|                   | **Speedup** | 1         | > 38.27   | > 198.9   | > 26.05    | > 180 000  |
|                   | **Memory**  | -         | 855 112   | 447 828   | 756        | 736        |
| Sieve             | **Runtime** | 76.31     | 7.71      | 6.49      | 14.63      | 8.94       |
|                   | **Speedup** | 1         | 9.9       | 11.76     | 5.22       | 8.54       |
|                   | **Memory**  | 398 980   | 1 415 428 | 1 096 284 | 32 472     | 35 732     |
| Scheduler         | **Runtime** | 786.74    | 10.62     | 10.49     | 21.57      | 10.32      |
|                   | **Speedup** | 1         | 74.08     | 74.99     | 36.47      | 76.23      |
|                   | **Memory**  | 5 341 316 | 414 772   | 398 924   | 816        | 820        |
| sort_m2_data1000  | **Runtime** | 17.27     | 3.27      | 2.10      | 0.2        | 0.03       |
|                   | **Speedup** | 1         | 5.28      | 8.22      | 86.35      | 575.67     |
|                   | **Memory**  | 577 808   | 191 280   | 143 864   | 1192       | 1104       |
| CAN Bus           | **Runtime** | 273.58    | 7.23      | 6.81      | 7.23       | 2.91       |
|                   | **Speedup** | 1         | 37.84     | 40.17     | 37.84      | 94.01      |
|                   | **Memory**  | 167 284   | 428 084   | 402 432   | 968        | 952        |
| Train             | **Runtime** | 241.16    | 13.31     | 12.83     | 18.55      | 8.10       |
|                   | **Speedup** | 1         | 18.11     | 18.8      | 13         | 29.77      |
|                   | **Memory**  | 163 476   | 377 292   | 376 540   | 984        | 1016       |
| Cruise Controller | **Runtime** | > 1800    | 21.26     | 15.26     | 11.90      | 0.30       |
|                   | **Speedup** | 1         | > 84.67   | > 117.96  | > 151.26   | > 6000     |
|                   | **Memory**  | -         | 750 816   | 484 948   | 864        | 820        |

## Results (Rust)
Rust development was done on a different system, therefore benchmarks are not comparable to the old table.
These benchmarks where run on a Ryzen 7 1700 under Debian via wsl (Win 10)
(Memory values seem pretty high. GNU time had a bug for reporting 4x the RSS, but I'm using version 1.9 here,
which apparently has it fixed...)

| Machines          |             | Java PI   | Java BI   | C++ PI -O1 | C++ PI -O2 | Rust PI O1 | Rust PI O2 | Rust PI O3 | Rust BI O2 | Rust BI O3 |
|-------------------|-------------|-----------|-----------|------------|------------|------------|------------|------------|------------|------------|
| Lift              | **Runtime** | 11.85     | 102.67    | 51.05      | 00.00      | 20.55      | 18.43      | 18.49      | 685.03     | 705.46     |
|                   | **Speedup** |           |           |            |            |            |            |            |            |            |
|                   | **Memory**  | 2 220 976 | 2 247 676 | 3120       | 3060       | 2160       | 2276       | 2168       | 2572       | 2584       |
| TrafficLight      | **Runtime** | 05.21     | 17.40     | 51.35      | 00.00      | 21.31      | 10.87      | 10.78      | 78.33      | 80.27      |
|                   | **Speedup** |           |           |            |            |            |            |            |            |            |
|                   | **Memory**  | 1 400 352 | 2 202 788 | 3188       | 3188       | 2312       | 2256       | 2312       | 2496       | 2664       |
| Sieve             | **Runtime** | 07.41     | 08.04     | 26.15      | 06.86      | 53.04      | 09.03      | 09.06      | 39.27      | 39.54      |
|                   | **Speedup** |           |           |            |            |            |            |            |            |            |
|                   | **Memory**  | 2 094 128 | 2 079 056 | 165 528    | 165 548    | 104 764    | 104 608    | 104 604    | 450 804    | 450 688    |
| Scheduler         | **Runtime** | 06.39     | 06.39     | 14.25      | 01.98      | 34.97      | 06.14      | 06.04      | 06.28      | 06.00      |
|                   | **Speedup** |           |           |            |            |            |            |            |            |            |
|                   | **Memory**  | 1 422 120 | 1 415 844 | 3080       | 3136       | 2384       | 2228       | 2324       | 2528       | 2584       |
| sort_m2_data1000  | **Runtime** | 02.02     | 02.15     | 00.20      | 00.03      | 02.77      | 00.50      | 00.51      | 01.11      | 01.15      |
|                   | **Speedup** |           |           |            |            |            |            |            |            |            |
|                   | **Memory**  | 204 220   | 206 676   | 3412       | 3420       | 5312       | 5216       | 5328       | 10072      | 9872       |
| CAN Bus           | **Runtime** | 05.17     | 05.15     | 05.80      | 00.59      | 19.83      | 03.16      | 03.18      | 06.36      | 06.47      |
|                   | **Speedup** |           |           |            |            |            |            |            |            |            |
|                   | **Memory**  | 930 816   | 917 552   | 3364       | 3208       | 2668       | 2540       | 2508       | 2912       | 2928       |
| Train             | **Runtime** | 07.40     | 07.57     | 13.19      | 01.64      | 31.52      | 04.76      | 04.71      | 02.78      | 02.77      |
|                   | **Speedup** |           |           |            |            |            |            |            |            |            |
|                   | **Memory**  | 1 420 528 | 1419832   | 3224       | 3372       | 2740       | 2636       | 2612       | 2856       | 2812       |
| Cruise Controller | **Runtime** | 13.91     | 14.66     | 08.34      | 00.04      | 05.15      | 05.43      | 05.33      | 14.20      | 14.64      |
|                   | **Speedup** |           |           |            |            |            |            |            |            |            |
|                   | **Memory**  | 1 401 192 | 1 400 232 | 3160       | 3092       | 2376       | 2540       | 2352       | 2668       | 2668       |

Runtime in Seconds

Memory Usage in KB

BI = Big Integer

PI = Primitive Integer
