##### Analysis of the Performance

1. Execute `make` in of the subdirectories


##Microbenchmarks

#####Aritmetic Operations
| Operation | Java Big Integer |  Java primitive Integer | Clojure Big Integer | Clojure Big Integer through Java | C++ primitives | ProB    |
|-----------|------------------|-------------------------|---------------------|----------------------------------|----------------|---------|
| Plus      | 1527.06ms        | 67.66ms                 | 2233.13ms           | 686.15ms                         | 0.002ms        | 37010ms |
| Minus     | 1552.04ms        | 72.7ms                  | 2362.16ms           | 865.74ms                         | 0.002ms        | 36490ms |
| Multiply  | 1414.81ms        | 69.25ms                 | 2044.5ms            | 799.98ms                         | 0.002ms        | 35950ms |
| Divide    | 1419.42ms        | 68.83ms                 | 2101.06ms           | 936.04ms                         | 0.002ms        | 37950ms |
| Modulo    | 1418.96ms        | 66.78ms                 | 2127.2ms            | 848.38ms                         | 0.002ms        | 38090ms |
| Negative  | 1243.5ms         | 65.22ms                 | 1687.38ms           | 705.ms                           | 0.002ms        | 36900ms |


#####Logical Operations

| Operation  | Java Big Integer |  Java primitive Integer | Clojure Big Integer | Clojure Big Integer through Java | C++ primitives | ProB    |
|------------|------------------|-------------------------|---------------------|----------------------------------|----------------|---------|
| And        | 1677.65ms        | 54.2ms                  | 2315.44ms           | 804.79ms                         | 0.002ms        | 54197ms |
| Or         | 1686.82ms        | 53.14ms                 | 2198.56ms           | 747.39ms                         | 0,002ms        | 53142ms |
| Implies    | 1559.41ms        | 54.6ms                  | 2119.7ms            | 723.03ms                         | 0,002ms        | 54603ms |
| Equivalent | 1608.87ms        | 57.92ms                 | 2352.35ms           | 925.41ms                         | 0,002ms        | 57921ms |



#####Comparisons
| Operation    | Java Big Integer |  Java primitive Integer | Clojure Big Integer | Clojure Big Integer through Java | C++ primitives | ProB    |
|--------------|------------------|-------------------------|---------------------|----------------------------------|----------------|---------|
| lessEqual    | 1652.72ms        | 53.31ms                 | 2243.11ms           | 776.03ms                         | 0.002ms        | 21920ms |
| less         | 1696.57ms        | 53.13ms                 | 2348.65ms           | 772.05ms                         | 0,002ms        | 22510ms |
| greater      | 1572.31ms        | 53.51ms                 | 2338.49ms           | 785.06ms                         | 0,002ms        | 22510ms |
| greaterEqual | 1589.23ms        | 54.48ms                 | 2223.4ms            | 786.18ms                         | 0,002ms        | 22250ms |
| equal        | 1677.65ms        | 56.69ms                 | 2355.02ms           | 743.04ms                         | 0.002ms        | 22860ms |
| unequal      | 1588.55ms        | 56.19ms                 | 2159.09ms           | 740.62ms                         | 0.002ms        | 22150ms |


####Operations On Sets and Ranges with Creating


#####Small Sets
| Operation  | Java Set  | Java Persistent Set | Clojure Set | Clojure Set through Java | C++ Immer Set | ProB    |
|------------|-----------|---------------------|-------------|--------------------------|---------------|---------|
| union      | 3666.73ms | 2222.21ms           | 21018.51ms  | 3121.42ms                | 1617.22ms     | 44880ms |
| intersect  | 1982.28ms | 1370.35ms           | 8592.85ms   | 1570.04ms                | 163.14ms      | 31340ms |
| complement | 2358.49ms | 1633.23ms           | 10260.15ms  | 2619.74ms                | 1777.8ms      | 31920ms |
| card       | 1646.88ms | 866.8ms             | 3473.26ms   | 3605.33ms                | 1963.96ms     | 31080ms |
| elementOf  | 1886.46ms | 906.51ms            | 16486.23ms  | 4165.27ms                | 1513.54ms     | 22360ms |


#####Big Sets
| Operation  | Java Set    | Java Persistent Set | Clojure Set | Clojure Set through Java | C++ Immer Set | ProB    |
|------------|-------------|---------------------|-------------|--------------------------|---------------|---------|
| union      | 57164.6ms   | 47838.65ms          | 102604.57ms | 11787.27ms               | 30152.33ms    | 88920ms |
| intersect  | 22444.45ms  | 37907.07ms          | 111557.89ms | 10523.48ms               | 31263.06ms    | 190ms   |
| complement | 49671.83ms  | 23385.72ms          | 82672.23ms  | 9837.74ms                | 30436.09ms    | 23230ms |
| card       | 255955.83ms | 182779.81ms         | 406777.27ms | 74601.3ms                | 246475.01ms   | 160ms   |
| elementOf  | 242246.07ms | 183498.9ms          | 425799.68ms | 77650.02ms               | 243716.04ms   | 190ms   |


#####Small Ranges
| Operation  | Java Set   | Java Persistent Set | Clojure Set | Clojure Set through Java | C++ Immer Set | ProB     |
|------------|------------|---------------------|-------------|--------------------------|---------------|----------|
| range      | 11432.64ms | 3172.84ms           | 86165.9ms   | 6152.07ms                | 10987.09ms    | 32420ms  |
| union      | 9224.04ms  | 3131.74ms           | 80070.53ms  | 5668.65ms                | 3954.13ms     | 65690ms  |
| intersect  | 15602.76ms | 9136.45ms           | 169863.87ms | 10005.88ms               | 10709.27ms    | 45760ms  |
| complement | 7443.73ms  | 2956.17ms           | 86284.4ms   | 5161.03ms                | 3509.07ms     | 148940ms |
| card       | 11386.52ms | 3945ms              | 7515522.ms  | 6800.08ms                | 11081.98ms    | 28610ms  |
| elementOf  | 11019.83ms | 3390.82ms           | 95053.59ms  | 7708.1ms                 | 9719.11ms     | 20720ms  |


#####Big Ranges
| Operation  | Java Set    | Java Persistent Set | Clojure Set | Clojure Set through Java | C++ Immer Set | ProB  |
|------------|-------------|---------------------|-------------|--------------------------|---------------|-------|
| range      | 17124.44ms  | 17963.64ms          | 37204.79ms  | 7374.59ms                | 23714.09ms    | 100ms |
| union      | 56275.74ms  | 45736.04ms          | 105024.17ms | 10549.98ms               | 29971.44ms    | 160ms |
| intersect  | 20593.03ms  | 36753.04ms          | 106230.41ms | 11282.22ms               | 27793.75ms    | 140ms |
| complement | 51755.73ms  | 25657.3ms           | 43438.07ms  | 12096.31ms               | 27586.16ms    | 170ms |
| card       | 160193.23ms | 166753.65ms         | 402076.9ms  | 67318.65ms               | 242518.13ms   | 150ms |
| elementOf  | 168923.46ms | 185207.7ms          | 387440.68ms | 76641.75ms               | 246618.14ms   | 110ms |



#### Operations On Sets and Ranges without Creating

#####Small Sets
| Operation  | Java Set  | Java Persistent Set | Clojure Set | Clojure Set through Java | C++ Immer Set | ProB    |
|------------|-----------|---------------------|-------------|--------------------------|---------------|---------|
| union      | 2702.19ms | 1339.36ms           | 9787.62ms   | 821.13ms                 | 149.9ms       | 52040ms |
| intersect  | 2154.47ms | 915.52ms            | 9971.95ms   | 441.77ms                 | 129.58ms      | 39490ms |
| complement | 1919.1ms  | 1098.94ms           | 8567.34ms   | 463.37ms                 | 83.95ms       | 36150ms |
| card       | 1328.67ms | 105.09ms            | 2213.84ms   | 170.02ms                 | 0.003ms       | 28970ms |
| elementOf  | 1522.7ms  | 142.99ms            | 16597.68ms  | 347.23ms                 | 23.83ms       | 21410   |


#####Big Sets
| Operation  | Java Set   | Java Persistent Set | Clojure Set | Clojure Set through Java | C++ Immer Set | ProB    |
|------------|------------|---------------------|-------------|--------------------------|---------------|---------|
| union      | 40247.6ms  | 21183.45ms          | 63773.93ms  | 4785.65ms                | 582.51ms      | 89030ms |
| intersect  | 5747.95ms  | 7184.23ms           | 4524.53ms   | 3741.65ms                | 542.56ms      | 180ms   |
| complement | 32229.29ms | 2838.25ms           | 3203.02ms   | 2995.66ms                | 454.64ms      | 23550ms |
| card       | 25.49ms    | 3.75ms              | 85.24ms     | 5.14ms                   | 0.003ms       | 150ms   |
| elementOf  | 20.78ms    | 17.38ms             | 213.22ms    | 10.28ms                  | 0.091ms       | 140ms   |


#####Small Ranges
| Operation  | Java Set  | Java Persistent Set | Clojure Set | Clojure Set through Java | C++ Immer Set | ProB    |
|------------|-----------|---------------------|-------------|--------------------------|---------------|---------|
| union      | 4515.45ms | 2701.33ms           | 32346.04ms  | 1106.96ms                | 167.9ms       | 46510ms |
| intersect  | 4847.78ms | 4087.77ms           | 73349.25ms  | 3135.36ms                | 305.65ms      | 38550ms |
| complement | 3568.74ms | 1550.65ms           | 10067.29ms  | 985.27ms                 | 152.36ms      | 56360ms |
| card       | 1378.77ms | 111.41ms            | 2043.97ms   | 164.45ms                 | 0.002ms       | 29000ms |
| elementOf  | 1355.81ms | 150.57ms            | 14046.46ms  | 340.34ms                 | 22.42ms       | 20790ms |


#####Big Ranges
| Operation  | Java Set   | Java Persistent Set | Clojure Set | Clojure Set through Java | C++ Immer Set | ProB  |
|------------|------------|---------------------|-------------|--------------------------|---------------|-------|
| union      | 40664.91ms | 17423.48ms          | 66492.27ms  | 3553.43ms                | 705ms         | 170ms |
| intersect  | 5004.56ms  | 7957.43ms           | 4994.44ms   | 3538.31ms                | 466.84ms      | 130ms |
| complement | 30957.48ms | 3292.4ms            | 3659.78ms   | 2818.45ms                | 390.93ms      | 160ms |
| card       | 15.97ms    | 4.16ms              | 107.82ms    | 6.55ms                   | 0.005ms       | 150ms |
| elementOf  | 22.57ms    | 14.71ms             | 269.56ms    | 7.98ms                   | 0.093ms       | 100ms |

