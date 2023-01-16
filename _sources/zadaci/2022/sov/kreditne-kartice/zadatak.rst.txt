Napisati program koji kontroliše validnost brojeva kreditnih kartica
Iz ulazne datoteke učitati u jednostruko spregnutu listu sledeće podatke:

* ``ime`` (jedna reč, do 20 karaktera)
* ``prezime`` (jedna reč, do 30 karaktera)
* ``broj_kartice`` (jedna reč, do 10 karaktera)

Novi elementi liste dodaju se na njen kraj.

Program prima ime ulazne datoteke kao argument komandne linije.
Podatke iz ulazne datoteke, potrebno je ispisati u dve različite izlazne datoteke, u zavisnosti od toga da li su kartice validne ili ne.
Imena datoteka su ``validne-kartice.txt`` i ``nevalidne-kartice.txt``.
Prilikom ispisa u izlaznu datoteku, koristiti format ``"%-8s %-11s %s\n"``.

Validnost kartice proverava se pomoću Lunovog (Luhn) algoritma na sledeći način:

* String se obrađuje od poslednjeg elementa ka prvom
* Svaki karakter se konvertuje u celobrojnu vrednost, a svaki drugi treba pomnožiti sa 2

    * Ukoliko broj koji je pomnožen sa 2 dvocifren, sabiraju se njegove pojedinačne cifre

* Sve dobijene brojeve treba sumirati, kartica je validna ukoliko je dobijena suma deljiva sa 10

Na standardni izlaz ispisati izveštaj koji sadrži broj validnih, nevalidnih kartica, kao i procenat uspešnosti (odnos validnih u odnosu na ukupan broj kartica izražen u procentima).

U slučaju sledećih grešaka prilikom rada programa, izaći sa odgovarajućim kodom greške:

* Nedovoljan ili suvišan broj argumenata, kod greške ``1`` (EXIT_FAILURE)
* Neuspešno dinamičko zauzeće memorije, kod greške ``2``
* Neuspešno otvaranje ulazne datoteke, kod greške ``3``
* Neuspešno otvaranje izlazne datoteke za validne kartice, kod greške ``4``
* Neuspešno otvaranje izlazne datoteke za nevalidne kartice, kod greške ``5``


Primer ulazne datoteke ``kartice.txt``:


.. literalinclude:: kartice.txt
   :language: none


Za primer poziva programa:

.. code-block:: bash

    ./a.out kartice.txt

Očekivani ispis na standardnom izlazu je:

.. literalinclude:: ispis-programa.txt
   :language: none


Sadržaj izlazne datoteke ``validne-kartice.txt`` je sledeći:


.. literalinclude:: validne-kartice.txt
   :language: none


Sadržaj izlazne datoteke ``nevalidne-kartice.txt`` je sledeći:


.. literalinclude:: nevalidne-kartice.txt
   :language: none


