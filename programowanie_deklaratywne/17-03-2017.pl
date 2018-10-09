%regular(rectangle(point(X1,Y1),point(X2,Y2),point(X3,Y3),point(X4,Y4))) :-
%	X1=X4,X2=X3,Y1=Y2,Y3=Y4.

regular(rectangle(point(X1,Y1),point(X2,Y1),point(X2,Y3),point(X1,Y3))).
