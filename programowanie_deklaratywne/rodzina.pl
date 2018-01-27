
%definiujemy kobiety

kobieta(maria).
kobieta(ewa).
kobieta(joanna).
kobieta(agata).
kobieta(anna).
kobieta(agnieszka).
kobieta(beata).
kobieta(iwona).

%definiujemy mezczyzn

mezczyzna(piotr).
mezczyzna(adam).
mezczyzna(marek).
mezczyzna(robert).
mezczyzna(jan).
mezczyzna(krzysztof).
mezczyzna(radek).
mezczyzna(darek).
mezczyzna(tomek).
mezczyzna(jacek).

%definiujemy rodzicow

rodzic(maria,marek).
rodzic(piotr,marek).
rodzic(ewa,joanna).
rodzic(adam,joanna).
rodzic(robert,radek).
rodzic(agata,radek).
rodzic(robert,beata).
rodzic(agata,beata).
rodzic(jan,darek).
rodzic(anna,darek).
rodzic(jan,tomek).
rodzic(anna,tomek).
rodzic(krzysztof,jacek).
rodzic(agnieszka,jacek).
rodzic(krzysztof,iwona).
rodzic(agnieszka,iwona).
rodzic(maria,agata).
rodzic(piotr,agata).
rodzic(maria,jan).
rodzic(piotr,jan).
rodzic(ewa,anna).
rodzic(adam,anna).
rodzic(ewa,krzysztof).
rodzic(adam,krzysztof).

%definiujemy malzenstwa

malzenstwo(maria,piotr).
malzenstwo(ewa,adam).
malzenstwo(robert,agata).
malzenstwo(jan,anna).
malzenstwo(krzysztof,agnieszka).

matka(X,Y) :- kobieta(X),rodzic(X,Y).
ojciec(X,Y) :- mezczyzna(X),rodzic(X,Y).
siostra(X,Y) :- kobieta(X), rodzic(Z,X), rodzic(Z,Y), X\=Y.
brat(X,Y) :- mezczyzna(X), rodzic(Z,X), rodzic(Z,Y), X\=Y.
babcia(X,Y) :- kobieta(X), rodzic(Z,Y), rodzic(X,Z).
dziadek(X,Y) :- mezczyzna(X), rodzic(Z,Y), rodzic(X,Z).
wuj(X,Y) :- rodzic(Z,Y), brat(X,Z), kobieta(Z).
stryj(X,Y) :- rodzic(Z,Y), brat(X,Z), mezczyzna(Z).
kuzyn(X,Y) :- mezczyzna(X), rodzic(Z,X), rodzic(Q,Y), brat(Z,Q).
kuzyn(X,Y) :- mezczyzna(X), rodzic(Z,X), rodzic(Q,Y), siostra(Z,Q).
kuzynka(X,Y) :- kobieta(X), rodzic(Z,X), rodzic(Q,Y), brat(Z,Q).
kuzynka(X,Y) :- kobieta(X), rodzic(Z,X), rodzic(Q,Y), siostra(Z,Q).
zona(X,Y) :- kobieta(X), malzenstwo(X,Y).
zona(X,Y) :- kobieta(X), malzenstwo(Y,X).
maz(X,Y) :- mezczyzna(X), malzenstwo(X,Y).
maz(X,Y) :- mezczyzna(X), malzenstwo(Y,X).
tesciowa(X,Y) :- matka(X,Z), zona(Z,Y).
szwagier(X,Y) :- siostra(Z,Y), maz(X,Z).
