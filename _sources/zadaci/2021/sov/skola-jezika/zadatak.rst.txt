Iz zadate ulazne datoteke učitati podatke u binarno stablo, gde struktura ``skola_jezika_st`` sadrži sledeća polja:

* naziv (jedna reč, maksimalno 30 karaktera),
* grad (jedna reč, maksimalno 2 karaktera),
* prvi strani jezik (jedna reč, maksimalno 15 karaktera),
* drugi strani jezik (jedna reč, maksimalno 15 karaktera),
* najviši nivo koji se može postići (jedna reč, maksimalno 8 karaktera),
* osnovna cena kursa (realan broj),
* broj polaznika po grupi (pozitivan ceo broj) i
* cena sa popustom (realan broj).

Struktura skola_jezika dodatno sadrži i polja potrebna za pravilno formiranje binarnog stabla.
Binarno stablo urediti po ključu ``osnovna cena kurs`` u opadajućem redosledu.
Iz formiranog binarnog stabla upisati podatke u zadatu izlaznu datoteku, u sledećem rasporedu polja strukture ``skola_jezika_st``:

* naziv,
* grad,
* broj polaznika po grupi,
* cena sa popustom (zaokružena na 3 decimale),
* prvi strani jezik i
* drugi strani jezik.

Cena sa popustom se izračunava na sledeći način: 

* ako je broj polaznika veći od 3 a manji od 7, popust iznosi 5%
* Ukoliko ima 7 i/ili više od 7 a manje od 10 polaznika, cena se umanjuje za 10%
* U slučaju da je broj polaznika 10 i/ili viši od 10, tada se osnovna cena kursa smanjuje za popust od 15%

U izlaznu datoteku potrebno je ispisati još i sledeće informacije:

a. školu stranih jezika u kojoj se nemački uči kao drugi strani jezik a čija je cena sa popustom najniža i
b. za odabranu školu stranih jezika (bira se na osnovu parametra ``odabranaSkola`` koji se prosleđuje kao argument komandne linije) ispisati koliko ima polaznika koji kao prvi strani jezik uče francuski a čija je cena kursa najviša

Primer poziva programa:

.. code-block:: bash

    ./zad Academy skole.txt izvestaj.txt

sa zadatim parametrima ``odabranaSkola = "Academy"`` i zadatim ulazom u datoteci ``skole.txt``:

.. literalinclude:: skole.txt
   :language: none

očekivanim izlazom u datoteci ``izvestaj.txt``:

.. literalinclude:: izvestaj-skola-academy.txt
   :language: none

U slučaju da se program pozove sa prosleđenim parametrom ``odabranaSkola = "Akademija"``, očekivani izlaz u datoteci je:

.. literalinclude:: izvestaj-skola-akademija.txt
   :language: none

