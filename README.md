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
* Executing all tests requires executing `make` before

## Supported Subset of B

### Machine sections:

| Machine Section    | Usage                                                                                                  |
|--------------------|--------------------------------------------------------------------------------------------------------|
| SETS               |                                            S (Deferred Set)                                            |
|                    |                                   T = {e1, e2, ...} (Enumerated Set)                                   |
| CONSTANTS          |                                                x,y, ...                                                |
| CONCRETE_CONSTANTS |                                               cx, cy, ...                                              |
| PROPERTIES         | c = v (where c is a constant and v is a value)                                                         |
|                    | card(S) = n (where S is a deferred set and n is a number)                                              |
|                    | S = {c1,...,cn} & card(S) = n  (where S is a deferred set, c1,..., cn are constants and n is a number) |
| VARIABLES          | x,y, ...                                                                                               |
| CONCRETE_VARIABLES | cx, cy, ...                                                                                            |
| INVARIANT          | P (Logical Predicate)                                                                                  |
| ASSERTIONS         | P1;...;P2 (List Of Logical Predicates)                                                                 |
| INITIALISATION     |                                                                                                        |
| OPERATIONS         |                                                                                                        |


Note that code is not generated from INVARIANT and ASSERTIONS. These constructs are used for verifying the machine only.
CONSTRAINTS and DEFINITIONS clause are not supported for code generation.


### Machine inclusion:

| Machine inclusion | Usage                        |
|-------------------|------------------------------|
| INCLUDES          | M1 ... MN (List of Machines) |
| EXTENDS           | M1 ... MN (List of Machines) |

Other machine inclusion clauses (SEES, USES, PROMOTES and REFINES) are not supported yet.


### Logical Predicates:

| Predicate             | Meaning                    |
|-----------------------|----------------------------|
| P & Q                 | conjunction                |
| P or Q                | disjunction                |
| P => Q                | implication                |
| P <=> Q               | equivalence                |
| not P                 | negation                   |
| !(x1,...,xn).(P => Q) | universal quantification   |
| #(x1,...,xn).(P & Q)  | existential quantification |

Restriction: As universal quantifications and existential quantifications are quantified constructs, the predicate P must constraint the value of the variables x1, ..., xn.
P is a conjunction of n conjuncts where the i-th conjunct must constraint xi for each i in {1,...,n}.

### Equality:

| Predicate             | Meaning    |
|-----------------------|------------|
| E = F                 | equality   |
| E \= F                | inequality |

### Booleans:

| Boolean | Meaning                             |
|---------|-------------------------------------|
| TRUE    | true value                          |
| FALSE   | false value                         |
| BOOL    | set of boolean values {TRUE, FALSE} |
| bool(P) | convert predicate into BOOL value   |


### Sets:

| Set expression or predicate  | Meaining                                   |
|------------------------------|--------------------------------------------|
| {}                           | Empty Set                                  |
| {E}                          | Singleton Set                              |
| {E,F,...}                    | Set Enumeration                            |
| {x1,...,xn\|P}               | Set Comprehension                          |
| POW(S)                       | Power Set                                  |
| POW1(S)                      | Set of Non-Empty Subsets                   |
| FIN(S)                       | Set of All Finite Subsets                  |
| FIN1(S)                      | Set of All Non-Empty Finite Subsets        |
| card(S)                      | Cardinality                                |
| S * T                        | Cartesian Product                          |
| S \/ T                       | Set Union                                  |
| S /\ T                       | Set Intersection                           |
| S - T                        | Set Difference                             |
| E : S                        | Element of                                 |
| E /: S                       | Not Element of                             |
| S <: T                       | Subset of                                  |
| S /<: T                      | Not Subset of                              |
| S <<: T                      | Strict Subset of                           |
| S /<<: T                     | Not Strict Subset of                       |
| union(S)                     | Generalized Union over Sets of Sets        |
| inter(S)                     | Generalized Intersection over Sets of Sets |
| UNION(z1,...,zn).(P\|E)      | Generalized Union with Predicate           |
| INTER(z1,...,zn).(P\|E)      | Generalized Intersection with Predicate    |

Restriction: Set comprehesions, generalized unions and generalized intersections are quantified constructs. The predicate P must be a conjunction where the first n conjuncts must constraint the bounded variables.
The i-th conjunct must constraint xi for each i in {1,...,n}.


### Numbers:

| Number expression or predicate | Meaning                                       |
|--------------------------------|-----------------------------------------------|
| INTEGER                        | Set of Integers                               |
| NATURAL                        | Set of Natural Numbers                        |
| NATURAL1                       | Set of Non-Zero Natural Numbers               |
| INT                            | Set of Implementable Integers                 |
| NAT                            | Set of Implementable Natural Numbers          |
| NAT1                           | Set of Non-Zero Implementable Natural Numbers |
| n..m                           | Set of Numbers from n to m                    |
| MININT                         | Minimum Implementable Integer                 |
| MAXINT                         | Maximum Implementable Integer                 |
| m > n                          | Greater Than                                  |
| m < n                          | Less Than                                     |
| m >= n                         | Greater Than or Equal                         |
| m <= n                         | Less Than Or Equal                            |
| max(S)                         | Maximum of a Set of Numbers                   |
| min(S)                         | Minimum of a Set of Numbers                   |
| m + n                          | Addition                                      |
| m - n                          | Difference                                    |
| m * n                          | Multiplication                                |
| m / n                          | Division                                      |
| m ** n                         | Power                                         |
| m mod n                        | Remainder of Division                         |
| PI(z1,...,zn).(P\|E)           | Set product                                   |
| SIGMA(z1,...,zn).(P\|E)        | Set summation                                 |
| succ(n)                        | Successor                                     |
| pred(n)                        | Predecessor                                   |

Restrictions:

INTEGER, NATURAL and NATURAL1 are infinite sets. They are only supported on the right-hand side of a set predicate.

Set product and set summation are quantified constructs. The predicate P must be a conjunction where the first n conjuncts must constraint the bounded variables.
The i-th conjunct must constraint xi for each i in {1,...,n}.

### Relations:

| Relation expression | Meaining                                              |
|---------------------|-------------------------------------------------------|
| S <-> T             | Set of relation                                       |
| E \|-> F            | Couple                                                |
| dom(r)              | Domain of Relation                                    |
| range(r)            | Range of Relation                                     |
| id(S)               | Identity Relation                                     |
| S <\| r             | Domain Restriction                                    |
| S <<\| r            | Domain Substraction                                   |
| r \|> S             | Range Restriction                                     |
| r \|>> S            | Range Substraction                                    |
| r~                  | Inverse of Relation                                   |
| r[S]                | Relational Image                                      |
| r1 <+ r2            | Relational Overriding                                 |
| r1 >< r2            | Direct Product                                        |
| (r1 ; r2)           | Relational Composition                                |
| (r1 \|\| r2)        | Parallel Product                                      |
| prj1(S,T)           | Projection Function                                   |
| prj2(S,T)           | Projection Function                                   |
| closure1(r)         | Transitive Closure                                    |
| closure(r)          | Transitive Reflxibe Closure                           |
| iterate(r,n)        | Iteration of r with n                                 |
| fnc(r)              | Translate Relation A <-> B into function A +-> POW(B) |
| rel(r)              | Translate Relation A <-> POW(B) into relation A <-> B |

Restriction: Set of Relation mostly grows up very fast. They are only supported on the right-hand side of a set predicate.

### Functions:

| Function Expression | Meaning                           |
|---------------------|-----------------------------------|
| S +-> T             | Partial Function                  |
| S --> T             | Total Function                    |
| S +->> T            | Partial Surjection                |
| S -->> T            | Total Surjection                  |
| S >+> T             | Partial Injection                 |
| S >+>> T            | Partial Bijection                 |
| S >->> T            | Total Bijection                   |
| %(x1,...,xn).(P\|E) | Lambda Abstraction                |
| f(E)                | Function Application              |
| f(E1,...,EN)        | Function Application with Couples |

Restriction: Lambda expressions are quantified constructs. The predicate P must be a conjunction where the first n conjuncts must constraint the bounded variables.
The i-th conjunct must constraint xi for each i in {1,...,n}.

### Sequences:

| Sequence Expression | Meaning                                |
|---------------------|----------------------------------------|
| <> or []            | Empty Sequence                         |
| [E]                 | Singleton Sequence                     |
| [E1,...,EN]         | Sequence with N elements               |
| size(S)             | Size of Sequence                       |
| s^t                 | Concatenation                          |
| E -> s              | Prepend element                        |
| s <- E              | Append element                         |
| rev(S)              | Reverse of Sequence                    |
| first(S)            | First Element                          |
| last(S)             | Last Element                           |
| front(S)            | Front of Sequence                      |
| tail(S)             | Tail of Sequence                       |
| conc(S)             | Concatenation of Sequence of Sequences |
| s /\|\ n            | Take first n elements of sequence      |
| s \\|/ n            | Drop first n elements of sequence      |

The following constructs are not supported for code generation: seq(S), seq1(S), iseq(S), iseq1(S) and perm(S).
They are only allowed in the predicate of constructs for verification such as invariant or precondition.

### Records:

| Record/Struct expression  | Meaning                                          |
|---------------------------|--------------------------------------------------|
| struct(ID1:T1,...,IDN:TN) | Set of Records with Given Fields and Field Types |
| rec(ID1:E1,...,IDN:EN)    | Record with Given Field Names and Values         |
| E'ID                      | Get value of field with name ID                  |

Nested record accesses are also supported.


### Strings:

| String Expression | Meaning            |
|-------------------|--------------------|
| "string"          | String Value       |
| STRING            | Set of All Strings |

Restriction: STRING is a infinite set. It is only supported on the right-hand side of a set predicate.


### LET and IF-THEN-ELSE Expression and Predicate:

| Expression or Predicate                           | Notes                                   |
|---------------------------------------------------|-----------------------------------------|
| IF P THEN E1 ELSE E2 END                          | E1 and E2 are expressions or predicates |
| LET x1,...,xn BE x1 = E1 & ... & xn = En IN E END | E is a predicate or a expression        |


### Substitution:

| Substitution                                      | Meaning                                                  |
|---------------------------------------------------|----------------------------------------------------------|
| skip                                              | No Operation                                             |
| x := E                                            | Assignment                                               |
| f(X) := E                                         | Functional Override                                      |
| f'ID := E                                         | Record Access                                            |
| x :: S                                            | Choice from Set                                          |
| x : (P)                                           | Choice by Predicate                                      |
| x <-- OP(X)                                       | Operation Call and Assignment of Return Value            |
| G \|\| H                                          | Parallel Substitution                                    |
| G ; H                                             | Sequential Substitution                                  |
| ANY x1,...,xn WHERE P THEN G END                  | Non Deterministic Choice                                 |
| LET x1,...,xn BE x1=E1 & ... & xn = En IN G END   | Let Substitution                                         |
| VAR x1,...,xn IN G END                            | Generate local variables                                 |
| PRE P THEN G END                                  | Substitution with Precondition                           |
| ASSERT P THEN G END                               | Substitution with Assertion                              |
| CHOICE G or H END                                 | Choice Substitution                                      |
| IF P THEN G END                                   | IF Substitution                                          |
| IF P THEN G ELSE H                                | IF-THEN-ELSE Substitution                                |
| IF P1 THEN G1 ELSIF P2 THEN G2 ... ELSE Gn END    | IF-THEN-ELSE Substitution with Many Else Branches        |
| SELECT P THEN G WHEN .. WHEN Q THEN H END         | SELECT Substitution with Many Branches                   |
| SELECT P THEN G WHEN .. WHEN Q THEN H ELSE I END  | SELECT Substitution with Many Branches and a Else Branch |
| CASE E OF EITHER m THEN G or n THEN H ... END END | CASE substitution                                        |

Functional Override and Record Access with assignment can be nested.

Preconditions and Assertions are constructs that are relevant for verification. They are ignored at code generation.

Assignments, Operation Calls, Choice from Set and Choice By Predicate can contain many variables on the left-hand side.
Furthermore Choice By Predicate can use previous values of variables.

Restriction: Choice by Predicates are quantified constructs. The predicate P must be a conjunction where the first n conjuncts must constraint the bounded variables.
The i-th conjunct must constraint xi for each i in {1,...,n}.

Comments are ignored during code generation. Furthermore trees and pragmas are not supported by B2Program.


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
[benchmarks/README.md](benchmarks/README.md).
