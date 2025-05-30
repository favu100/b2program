/* https://www3.hhu.de/stups/prob/index.php/Summary_of_B_Syntax */
/* Model from https://mars-workshop.org/repository/020-CBTC.html */
/*
F. Mazzanti and A. Ferrari. Ten diverse formal models for a cbtc automatic train supervision system. Electronic Proceedings in Theoretical Computer Science, 268:104–149, Mar. 2018.
*/
MACHINE Oneway
// addapted for TLC4B by Michael Leuschel
// remove sequential composition in events
// added constant values found by ProB to properties (not necessary if we use Setup by ProB option)
// Note : ProB's AST cleanup will get rid of some of the sequential compositions
// the B encoding could be made much more idiomatic and compact


CONSTANTS
   T0,T1,T2,T3,T4,T5,T6,T7,
   A0,A1,A2,A3,A4,A5,A6,A7,
   B0,B1,B2,B3,B4,B5,B6,B7,
   LA,LB

PROPERTIES

       T0={(0|->1),(1|->9),(2|->10),(3|->13),(4|->15),(5|->20),(6|->23)} &
       T1={(0|->3),(1|->9),(2|->10),(3|->13),(4|->15),(5|->20),(6|->24)} &
       T2={(0|->5),(1|->27),(2|->11),(3|->13),(4|->16),(5|->20),(6|->25)} &
       T3={(0|->7),(1|->27),(2|->11),(3|->13),(4|->16),(5|->20),(6|->26)} &
       T4={(0|->23),(1|->22),(2|->17),(3|->18),(4|->11),(5|->9),(6|->2)} &
       T5={(0|->24),(1|->22),(2|->17),(3|->18),(4|->11),(5|->9),(6|->4)} &
       T6={(0|->25),(1|->22),(2|->17),(3|->18),(4|->12),(5|->27),(6|->6)} &
       T7={(0|->26),(1|->22),(2|->17),(3|->18),(4|->12),(5|->27),(6|->8)} &
       A0={(0|->0),(1|->0),(2|->0),(3|->1),(4|->0),(5|->-1),(6|->0)} &
       A1={(0|->0),(1|->0),(2|->0),(3|->1),(4|->0),(5|->-1),(6|->0)} &
       A2={(0|->0),(1|->0),(2|->1),(3|->-1),(4|->0),(5|->1),(6|->0)} &
       A3={(0|->0),(1|->0),(2|->1),(3|->-1),(4|->0),(5|->0),(6|->0)} &
       A4={(0|->0),(1|->1),(2|->0),(3|->0),(4|->-1),(5|->0),(6|->0)} &
       A5={(0|->0),(1|->1),(2|->0),(3|->0),(4|->-1),(5|->0),(6|->0)} &
       A6={(0|->0),(1|->0),(2|->0),(3|->-1),(4|->0),(5|->0),(6|->0)} &
       A7={(0|->0),(1|->1),(2|->0),(3|->-1),(4|->0),(5|->0),(6|->0)} &
       B0={(0|->0),(1|->0),(2|->0),(3|->1),(4|->0),(5|->-1),(6|->0)} &
       B1={(0|->0),(1|->0),(2|->0),(3|->1),(4|->0),(5|->-1),(6|->0)} &
       B2={(0|->0),(1|->0),(2|->1),(3|->-1),(4|->0),(5|->0),(6|->0)} &
       B3={(0|->0),(1|->0),(2|->1),(3|->-1),(4|->0),(5|->1),(6|->0)} &
       B4={(0|->0),(1|->1),(2|->0),(3|->0),(4|->-1),(5|->0),(6|->0)} &
       B5={(0|->0),(1|->1),(2|->0),(3|->0),(4|->-1),(5|->0),(6|->0)} &
       B6={(0|->0),(1|->1),(2|->0),(3|->-1),(4|->0),(5|->0),(6|->0)} &
       B7={(0|->0),(1|->0),(2|->0),(3|->-1),(4|->0),(5|->0),(6|->0)} &


/*
--------------------------------------------------------------
T0: int[] := [ 1, 9,10,13,15,20,23]; -- G1
T1: int[] := [ 3, 9,10,13,15,20,24]; -- R1
T2: int[] := [ 5,27,11,13,16,20,25]; -- Y1
T3: int[] := [ 7,27,11,13,16,20,26]; -- B1
T4: int[] := [23,22,17,18,11, 9, 2]; -- G2
T5: int[] := [24,22,17,18,11, 9, 4]; -- R2
T6: int[] := [25,22,17,18,12,27, 6]; -- Y2
T7: int[] := [26,22,17,18,12,27, 8]; -- B2
----------------------------------------------------------------

------ region A: train constraints ------
A0: int[] := [ 0, 0, 0, 1, 0,-1, 0]; -- G1
A1: int[] := [ 0, 0, 0, 1, 0,-1, 0]; -- R1
A2: int[] := [ 0, 0, 1,-1, 0, 1, 0]; -- Y1
A3: int[] := [ 0, 0, 1,-1, 0, 0, 0]; -- B1
A4: int[] := [ 0, 1, 0, 0,-1, 0, 0]; -- G2
A5: int[] := [ 0, 1, 0, 0,-1, 0, 0]; -- R2
A6: int[] := [ 0, 0, 0,-1, 0, 0, 0]; -- Y2
A7: int[] := [ 0, 1, 0,-1, 0, 0, 0]; -- B2
------------------------------------------

------- region B: train constraints ------
B0: int[] := [ 0, 0, 0, 1, 0,-1, 0]; -- G1
B1: int[] := [ 0, 0, 0, 1, 0,-1, 0]; -- R1
B2: int[] := [ 0, 0, 1,-1, 0, 0, 0]; -- Y1
B3: int[] := [ 0, 0, 1,-1, 0, 1, 0]; -- B1
B4: int[] := [ 0, 1, 0, 0,-1, 0, 0]; -- G2
B5: int[] := [ 0, 1, 0, 0,-1, 0, 0]; -- R2
B6: int[] := [ 0, 1, 0,-1, 0, 0, 0]; -- Y2
B7: int[] := [ 0, 0, 0,-1, 0, 0, 0]; -- B2
------------------------------------------

-------------------------------------------------------------
RA: int :=1;  -- initial value for region RA
RB: int :=1;  -- initial value for region RB
LA: int :=7;  -- limit value for region RA
LB: int :=7;  -- limit value for region RB
-------------------------------------------------------------------
*/

  T0 : 0..6 --> 1..27 &
  T1 : 0..6 --> 1..27 &
  T2 : 0..6 --> 1..27 &
  T3 : 0..6 --> 1..27 &
  T4 : 0..6 --> 1..27 &
  T5 : 0..6 --> 1..27 &
  T6 : 0..6 --> 1..27 &
  T7 : 0..6 --> 1..27 &

  A0 : 0..6 --> -1..1 &
  A1 : 0..6 --> -1..1 &
  A2 : 0..6 --> -1..1 &
  A3 : 0..6 --> -1..1 &
  A4 : 0..6 --> -1..1 &
  A5 : 0..6 --> -1..1 &
  A6 : 0..6 --> -1..1 &
  A7 : 0..6 --> -1..1 &

  B0 : 0..6 --> -1..1 &
  B1 : 0..6 --> -1..1 &
  B2 : 0..6 --> -1..1 &
  B3 : 0..6 --> -1..1 &
  B4 : 0..6 --> -1..1 &
  B5 : 0..6 --> -1..1 &
  B6 : 0..6 --> -1..1 &
  B7 : 0..6 --> -1..1 &

  T0(0)= 1 & T0(1)= 9 & T0(2)=10 & T0(3)=13 & T0(4)=15 & T0(5)=20 & T0(6)=23 &
  T1(0)= 3 & T1(1)= 9 & T1(2)=10 & T1(3)=13 & T1(4)=15 & T1(5)=20 & T1(6)=24 &
  T2(0)= 5 & T2(1)=27 & T2(2)=11 & T2(3)=13 & T2(4)=16 & T2(5)=20 & T2(6)=25 &
  T3(0)= 7 & T3(1)=27 & T3(2)=11 & T3(3)=13 & T3(4)=16 & T3(5)=20 & T3(6)=26 &
  T4(0)=23 & T4(1)=22 & T4(2)=17 & T4(3)=18 & T4(4)=11 & T4(5)= 9 & T4(6)=2 &
  T5(0)=24 & T5(1)=22 & T5(2)=17 & T5(3)=18 & T5(4)=11 & T5(5)= 9 & T5(6)=4 &
  T6(0)=25 & T6(1)=22 & T6(2)=17 & T6(3)=18 & T6(4)=12 & T6(5)=27 & T6(6)=6 &
  T7(0)=26 & T7(1)=22 & T7(2)=17 & T7(3)=18 & T7(4)=12 & T7(5)=27 & T7(6)=8 &

  A0(0)=0 & A0(1)=0 & A0(2)=0 & A0(3)= 1 & A0(4)= 0 & A0(5)=-1 & A0( 6)=0 &
  A1(0)=0 & A1(1)=0 & A1(2)=0 & A1(3)= 1 & A1(4)= 0 & A1(5)=-1 & A1( 6)=0 &
  A2(0)=0 & A2(1)=0 & A2(2)=1 & A2(3)=-1 & A2(4)= 0 & A2(5)= 1 & A2( 6)=0 &
  A3(0)=0 & A3(1)=0 & A3(2)=1 & A3(3)=-1 & A3(4)= 0 & A3(5)= 0 & A3( 6)=0 &
  A4(0)=0 & A4(1)=1 & A4(2)=0 & A4(3)= 0 & A4(4)=-1 & A4(5)= 0 & A4( 6)=0 &
  A5(0)=0 & A5(1)=1 & A5(2)=0 & A5(3)= 0 & A5(4)=-1 & A5(5)= 0 & A5( 6)=0 &
  A6(0)=0 & A6(1)=0 & A6(2)=0 & A6(3)=-1 & A6(4)= 0 & A6(5)= 0 & A6( 6)=0 &
  A7(0)=0 & A7(1)=1 & A7(2)=0 & A7(3)=-1 & A7(4)= 0 & A7(5)= 0 & A7( 6)=0 &

  B0(0)=0 & B0(1)=0 & B0(2)=0 & B0(3)= 1 & B0(4)= 0 & B0(5)=-1 & B0( 6)=0 &
  B1(0)=0 & B1(1)=0 & B1(2)=0 & B1(3)= 1 & B1(4)= 0 & B1(5)=-1 & B1( 6)=0 &
  B2(0)=0 & B2(1)=0 & B2(2)=1 & B2(3)=-1 & B2(4)= 0 & B2(5)= 0 & B2( 6)=0 &
  B3(0)=0 & B3(1)=0 & B3(2)=1 & B3(3)=-1 & B3(4)= 0 & B3(5)= 1 & B3( 6)=0 &
  B4(0)=0 & B4(1)=1 & B4(2)=0 & B4(3)=-0 & B4(4)=-1 & B4(5)= 0 & B4( 6)=0 &
  B5(0)=0 & B5(1)=1 & B5(2)=0 & B5(3)= 0 & B5(4)=-1 & B5(5)= 0 & B5( 6)=0 &
  B6(0)=0 & B6(1)=1 & B6(2)=0 & B6(3)=-1 & B6(4)= 0 & B6(5)= 0 & B6( 6)=0 &
  B7(0)=0 & B7(1)=0 & B7(2)=0 & B7(3)=-1 & B7(4)= 0 & B7(5)= 0 & B7( 6)=0 &

  LA=7 & LB=7

VARIABLES
  P0,P1,P2,P3,P4,P5,P6,P7,RA,RB

INVARIANT
  P0:0..6 & P1:0..6 & P2:0..6 & P3:0..6 & P4:0..6 & P5:0..6 & P6:0..6 & P7:0..6 &
  RA:0..8 & RB:0..8

INITIALISATION
  P0:=0 || P1:=0 || P2:=0 || P3:=0 || P4:=0 ||
   P5:=0 || P6:=0 || P7:=0 || RA:=1 || RB:=1

OPERATIONS
  move0 =
    PRE P0<6 &
      T0(P0+1) /= T1(P1) & // next place of train0 not occupied by train1
      T0(P0+1) /= T2(P2 )& // next place of train0 not occupied by train2
      T0(P0+1) /= T3(P3 )&
      T0(P0+1) /= T4(P4) &
      T0(P0+1) /= T5(P5) &
      T0(P0+1) /= T6(P6) &
      T0(P0+1) /= T7(P7) &  // next place of train0 not occupied by train7
      RA + A0(P0+1) <= LA & // progress of train0 does not saturate RA
      RB + B0(P0+1) <= LB   // progress of train0 does not saturate RB
    THEN
      P0 := P0+1 ||
      RA := RA + A0(P0+1) || // update occupancy of RA according to the step
      RB := RB + B0(P0+1)    // update occupancy of RB according to the step
    END ;

  move1 =
    PRE P1<6 &
      T1(P1+1) /= T0(P0) &
      T1(P1+1) /= T2(P2) &
      T1(P1+1) /= T3(P3) &
      T1(P1+1) /= T4(P4) &
      T1(P1+1) /= T5(P5) &
      T1(P1+1) /= T6(P6) &
      T1(P1+1) /= T7(P7) &
      RA + A1(P1+1) <= LA &
      RB + B1(P1+1) <= LB
    THEN
      P1 := P1+1 ||
      RA := RA + A1(P1+1) ||
      RB := RB + B1(P1+1)
    END ;

  move2 =
    PRE P2<6 &
      T2(P2+1) /= T0(P0) &
      T2(P2+1) /= T1(P1) &
      T2(P2+1) /= T3(P3) &
      T2(P2+1) /= T4(P4) &
      T2(P2+1) /= T5(P5) &
      T2(P2+1) /= T6(P6) &
      T2(P2+1) /= T7(P7) &
      RA + A2(P2+1) <= LA &
      RB + B2(P2+1) <= LB
    THEN
      P2 := P2+1 ||
      RA := RA + A2(P2+1) ||
      RB := RB + B2(P2+1)
    END ;

  move3 =
    PRE P3<6 &
      T3(P3+1) /= T0(P0) &
      T3(P3+1) /= T1(P1) &
      T3(P3+1) /= T2(P2) &
      T3(P3+1) /= T4(P4) &
      T3(P3+1) /= T5(P5) &
      T3(P3+1) /= T6(P6) &
      T3(P3+1) /= T7(P7) &
      RA + A3(P3+1) <= LA &
      RB + B3(P3+1) <= LB
    THEN
      P3 := P3+1 ||
      RA := RA + A3(P3+1) ||
      RB := RB + B3(P3+1)
    END ;

  move4 =
    PRE P4<6 &
      T4(P4+1) /= T0(P0) &
      T4(P4+1) /= T1(P1) &
      T4(P4+1) /= T2(P2) &
      T4(P4+1) /= T3(P3) &
      T4(P4+1) /= T5(P5) &
      T4(P4+1) /= T6(P6) &
      T4(P4+1) /= T7(P7) &
      RA + A4(P4+1) <= LA &
      RB + B4(P4+1) <= LB
    THEN
      P4 := P4+1 ||
      RA := RA + A4(P4+1) ||
      RB := RB + B4(P4+1)
    END ;

  move5 =
    PRE P5<6 &
      T5(P5+1) /= T0(P0) &
      T5(P5+1) /= T1(P1) &
      T5(P5+1) /= T2(P2) &
      T5(P5+1) /= T3(P3) &
      T5(P5+1) /= T4(P4) &
      T5(P5+1) /= T6(P6) &
      T5(P5+1) /= T7(P7) &
      RA + A5(P5+1) <= LA &
      RB + B5(P5+1) <= LB
    THEN
      P5 := P5+1 ||
      RA := RA + A5(P5+1) ||
      RB := RB + B5(P5+1)
    END ;

  move6 =
    PRE P6<6 &
      T6(P6+1) /= T0(P0) &
      T6(P6+1) /= T1(P1) &
      T6(P6+1) /= T2(P2) &
      T6(P6+1) /= T3(P3) &
      T6(P6+1) /= T4(P4) &
      T6(P6+1) /= T5(P5) &
      T6(P6+1) /= T7(P7) &
      RA + A6(P6+1) <= LA &
      RB + B6(P6+1) <= LB
    THEN
      P6 := P6+1 ||
      RA := RA + A6(P6+1) ||
      RB := RB + B6(P6+1)
    END ;

  move7 =
    PRE P7<6 &
      T7(P7+1) /= T0(P0) &
      T7(P7+1) /= T1(P1) &
      T7(P7+1) /= T2(P2) &
      T7(P7+1) /= T3(P3) &
      T7(P7+1) /= T4(P4) &
      T7(P7+1) /= T5(P5) &
      T7(P7+1) /= T6(P6) &
      RA + A7(P7+1) <= LA &
      RB + B7(P7+1) <= LB
    THEN
      P7 := P7+1 ||
      RA := RA + A7(P7+1) ||
      RB := RB + B7(P7+1)
    END ;

  arrived =
    PRE
       P0=6 & P1=6 & P2=6 & P3=6 & P4=6 & P5=6 & P6=6 & P7=6
    THEN
       skip
    END
END

//--------------------
//  SEARCHING DEADLOCKS:  1_636_547 states,   7_134_235 trans.  TIME  32 min   VMEM  3 GB
//-------------------

/*
> Model checking completed. No error has been found.
>   Estimates of the probability that TLC did not check all reachable states
>   because two distinct states had the same fingerprint:
>   calculated (optimistic):  val = 4.9E-7
>   based on the actual fingerprints:  val = 1.6E-9
> The coverage statistics at 2024-06-26 15:28:42
> End of statistics.
> 7134234 states generated, 1636545 distinct states found, 0 states left on queue.
> The depth of the complete state graph search is 48.
> Finished. (2024-06-26 15:28:42)
--------------------------------
---------- Coverage statistics ----------
move0: 944136
move1: 944136
move2: 900176
move3: 900176
move4: 840500
move5: 840500
move6: 882304
move7: 882304
arrived: 1
---------- End of coverage statistics ----------
Used Options
| Number of workers: 2
| Invariants check: false
| Deadlock check: true
| Assertion check: true
| Find Goal check: false
| LTL formulas check: false
| Partial invariant evaluation: false
| Lazy constants setup: true
| Agressive well-definedness check: true
| Prob constant setup: false
| Symmetry reduction: false
| MIN Int: 0
| MAX Int: 1
| Standard deferret set size: 3
--------------------------------
Parsing time: 452 ms
Translation time: 126 ms
Model checking time: 15 sec
States analysed: 1636545
Transitions fired: 7134234
Result: NoError

*/
