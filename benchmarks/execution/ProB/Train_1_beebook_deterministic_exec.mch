MACHINE Train_1_beebook_deterministic_exec

INCLUDES Train_1_beebook_deterministic

VARIABLES counter

INVARIANT counter : INTEGER

INITIALISATION counter := 0

OPERATIONS
	simulate =
	WHILE counter < 10000 DO
            route_reservation(R1);
            route_reservation(R4);
            point_positionning(R1);
            point_positionning(R4);
            route_formation(R1);
            FRONT_MOVE_1(R1);
            FRONT_MOVE_2(L);
            FRONT_MOVE_2(A);
            FRONT_MOVE_2(B);
            BACK_MOVE_2(L);
            BACK_MOVE_2(A);
            BACK_MOVE_2(B);
            BACK_MOVE_1(C);
            route_reservation(R6);
            route_freeing(R1);
            route_formation(R4);
            point_positionning(R6);
            route_formation(R6);
            FRONT_MOVE_1(R4);
            FRONT_MOVE_2(M);
            FRONT_MOVE_1(R6);
            FRONT_MOVE_2(C);
            FRONT_MOVE_2(H);
            BACK_MOVE_2(C);
            BACK_MOVE_2(M);
            FRONT_MOVE_2(I);
            BACK_MOVE_2(H);
            FRONT_MOVE_2(B);
            BACK_MOVE_2(B);
            BACK_MOVE_2(I);
            route_reservation(R5);
            point_positionning(R5);
            FRONT_MOVE_2(A);
            FRONT_MOVE_2(K);
            route_formation(R5);
            BACK_MOVE_2(A);
            BACK_MOVE_2(K);
            FRONT_MOVE_2(F);
            BACK_MOVE_2(F);
            FRONT_MOVE_1(R5);
            FRONT_MOVE_2(M);
            BACK_MOVE_2(M);
            FRONT_MOVE_2(H);
            BACK_MOVE_2(H);
            FRONT_MOVE_2(I);
            FRONT_MOVE_2(J);
            BACK_MOVE_1(L);
            BACK_MOVE_1(G);
            route_reservation(R1);
            point_positionning(R1);
            route_formation(R1);
            route_freeing(R4);
            BACK_MOVE_2(I);
            BACK_MOVE_2(J);
            route_freeing(R6);
            route_reservation(R9);
            FRONT_MOVE_1(R1);
            BACK_MOVE_1(N);
            point_positionning(R9);
            FRONT_MOVE_2(L);
            route_formation(R9);
            route_freeing(R5);
            BACK_MOVE_2(L);
            FRONT_MOVE_2(A);
            FRONT_MOVE_1(R9);
            FRONT_MOVE_2(B);
            FRONT_MOVE_2(G);
            BACK_MOVE_2(A);
            BACK_MOVE_2(G);
            BACK_MOVE_2(B);
            FRONT_MOVE_2(F);
            BACK_MOVE_1(C);
            route_reservation(R6);
            point_positionning(R6);
            route_formation(R6);
            BACK_MOVE_2(F);
            route_freeing(R1);
            FRONT_MOVE_2(K);
            FRONT_MOVE_2(I);
            FRONT_MOVE_2(H);
            FRONT_MOVE_1(R6);
            FRONT_MOVE_2(C);
            FRONT_MOVE_2(B);
            FRONT_MOVE_2(A);
            BACK_MOVE_2(K);
            BACK_MOVE_2(I);
            BACK_MOVE_2(H);
            BACK_MOVE_2(C);
            BACK_MOVE_2(B);
            BACK_MOVE_2(A);
            BACK_MOVE_1(L);
            BACK_MOVE_1(M);
            route_freeing(R6);
            route_freeing(R9);
	    counter := counter + 1
	INVARIANT 1 = 1
	VARIANT 10000 - counter
	      END

END
