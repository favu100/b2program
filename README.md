# B2Program

This is the code generator **B2Program** for generating code from B to other
programming languages.

A subset of B is supported for Java and C++ now. The work for code generation for Python, Clojure and C has begun but not continued.

Note:

* The implementation of the B types in C++ uses persistent set from:
  https://github.com/arximboldi/immer
* The library must first be installed before the generated C++ code can be used.
* The generated code for C works for a subset of the generated code that works
  for Java and C++.
* Sets and couples are not supported for C.
  Including other machines is not supported in C, too.
  The only types that are implemented for C are BInteger and BBoolean.
  An example where code generation for C works is the machine Lift.

## Supported subset of B

### Machine sections:

| Machine Section    | Usage                                  |
|--------------------|----------------------------------------|
| SETS               |            S (Deferred Set)            |
|                    |   T = {e1, e2, ...} (Enumerated Set)   |
| CONSTANTS          |                x,y, ...                |
| CONCRETE_CONSTANTS |               cx, cy, ...              |
| PROPERTIES         |                                        |
| VARIABLES          | x,y, ...                               |
| CONCRETE_VARIABLES | cx, cy, ...                            |
| INVARIANT          | P (Logical Predicate)                  |
| ASSERTIONS         | P1;...;P2 (List Of Logical Predicates) |
| INITIALISATION     |                                        |
| OPERATIONS         |                                        |

Note that code is not generated from INVARIANT and ASSERTIONS. These constructs are used for verifying the machine only.

## Usage

### Starting the code generator

```bash
# Java
./gradlew run -Planguage="java" -Pbig_integer="true/false" [-Pminint="minint" -Pmaxint="maxint"] -Pdeferred_set_size="size" -Pfile="<path_relative_to_project_directory>"

# Python
./gradlew run -Planguage="python" -Pbig_integer="true/false" [-Pminint="minint" -Pmaxint="maxint"] -Pdeferred_set_size="size" -Pfile="<path_relative_to_project_directory>"

# C
./gradlew run -Planguage="c" -Pbig_integer="true/false" [-Pminint="minint" -Pmaxint="maxint"] -Pdeferred_set_size="size" -Pfile="<path_relative_to_project_directory>"

# C++
./gradlew run -Planguage="cpp" -Pbig_integer="true/false" [-Pminint="minint" -Pmaxint="maxint"] -Pdeferred_set_size="size" -Pfile="<path_relative_to_project_directory>"
```

-Pminint and -Pmaxint are optional. The default values cover 32-Bit Integers

### Compile the generated code in Java

1. Run `./gradlew build` in project btypes_persistent or btypes_big_integer
2. Move `btypes-all-2.9.12-SNAPSHOT.jar` to same folder as the generated classes
3. `javac -cp btypes-all-2.9.12-SNAPSHOT.jar <files....>`
4. Example: `javac -cp btypes-all-2.9.12-SNAPSHOT.jar TrafficLightExec.java TrafficLight.java`
  (Code generated from TrafficLightExec.mch which includes TrafficLight.mch)
  
### Compile the generated code in C++
  
1. Move all B types (see btypes_primitives or btypes_big_integer folder) files to same folder as the generated classes
2. `g++ -std=c++14 -O2 -march=native -g -DIMMER_NO_THREAD_SAFETY -o <executable> <main class>`
3. Example: `g++ -std=c++14 -O2 -march=native -g -DIMMER_NO_THREAD_SAFETY -o TrafficLightExec.exec TrafficLightExec.cpp`
   (TrafficLightExec.mch includes TrafficLight.mch, this command automatically compiles TrafficLight.cpp)

### Compile the generated code in C

1. Move BInteger and BBoolean to same folder as generated code (see btypes/src/main/c)
2. `gcc <input file> -o <output file>`
3. Example: `gcc Lift.c -o Lift`

### Execute the generated code in Java

1. Write a main function in the generated main class
2. `java -cp :btypes-all-2.9.12-SNAPSHOT.jar <main file>`
3. Example: `java -cp :btypes-all-2.9.12-SNAPSHOT.jar TrafficLightExec`

### Execute the generated code in C++

1. Write a main function in the generated main class
2. `./<main file>`
3. Example: `./TrafficLightExec.exec`

### Execute the generated code in C

1. Write a main function in the generated main file
2. `./main.c`
3. Example: `./Lift`

## Performance

Analysis of the Performance is described in
[benchmarks/README.md](microbenchmarks/README.md).
