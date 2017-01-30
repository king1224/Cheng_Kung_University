:- style_check(-singleton).
prime(2).
prime(X) :- X1 is truncate(sqrt(X)) + 1 , test(X,X1,2).
test(X,X1,X2) :- X2 < X1 , Y is X mod X2 , Y > 0 , X3 is X2 + 1 , test(X,X1,X3).
test(X,X1,X2) :- X1 = X2.

main :- read(N) , ff(N) , halt , ! .
:- set_prolog_stack(global, limit(100 000 000 000)).
ff(N) :- findall(X,a(X,Y,N),L) , pr(L,N).
pr([],N).
pr([H|Y],N) :- write(H) , write(' ') , M is N - H , writeln(M) , pr(Y,N).
a(X,Y,N) :- num(X,N) , prime(X) , Y is N - X , Y > 0 , prime(Y) , X =< Y .
num(2,N).
num(X,N) :- N > 1 , N1 is N - 1 , num(X1,N1) , X is X1 + 1 .
:- initialization(main).
