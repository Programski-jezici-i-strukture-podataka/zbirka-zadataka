Iz zadate ulazne datoteke učitati podatke u jednostruko spregnutu listu.

Struktura student se sastoji od sledećih polja:

* broj indeksa studenta (jedna reč, do 10 karaktera)
* ime studenta (jedna reč, do 15 karaktera)
* prezime studenta (jedna reč, do 15 karaktera)
* ocena iz 1. predmeta (pozitivna, celobrojna vrednost)
* ocena iz 2. predmeta (pozitivna, celobrojna vrednost)
* ocena iz 3. predmeta (pozitivna, celobrojna vrednost)
* ocena iz 4. predmeta (pozitivna, celobrojna vrednost)
* ocena iz 5. predmeta (pozitivna, celobrojna vrednost)

Takođe, struktura student sadrži i polja potrebna za pravilno formiranje jednostruko spregnute liste.

Preko argumenata komandne linije uneti naziv ulazne datoteke i naziv izlazne datoteke.

U izlaznu datoteku ispisati sve studente koji su stekli uslov za prelazak u sledeću godinu. Da bi prešao u sledeću godinu student mora da položi minimalno 4 od 5 predmeta. Predmet je položen ako je ocena veća od 5. Takođe, u izlaznu datoteku ispisati da li je student koji je prešao u sledeću godinu na budžetu ili samofinansiranju, da bi bio na budžetu, student mora da položi sve predmete.

Obratiti pažnju na odgovarajuće rukovanje greškama pri radu sa datotekama (ne ispisivati ništa u datoteku niti standardni izlaz):

* Ako nije moguće otvoriti ulaznu datoteku: izaći iz programa sa ``exit(1)``
* Ako nije moguće otvoriti izlaznu datoteku: izaći iz programa sa ``exit(2)``

Primer poziva programa:

.. code-block:: bash

  ./a.out studenti.txt polozili.txt


Zadati ulaz u datoteci ``studenti.txt``:

.. literalinclude:: studenti.txt
   :language: none

Izgled izlazne datoteke ``polozili.txt``:

.. literalinclude:: polozili.txt
   :language: none

