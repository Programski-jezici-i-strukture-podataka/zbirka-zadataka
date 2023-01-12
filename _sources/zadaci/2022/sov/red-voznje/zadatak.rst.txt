Napisati program koji na osnovu spiska polazaka sa autobuske stanice formira red vožnje.
Iz ulazne datoteke učitati u binarno stablo pretrage sledeće podatke:

* ``odredište`` (jedna reč, do 20 karaktera)
* ``vreme_polaska`` (jedna reč, u formatu sat, dva karaktera, tačka, minut, dva karaktera)
* ``prevoznik`` (jedna reč, do 30 karaktera)
* ``cena_karte`` (realan broj)

Stablo se formira na osnovu vrednosti polja ``vreme_polaska``.

Program prima ime ulazne, izlazne datoteke, odredište i vreme kao argumente komandne linije.
U izlaznu datoteku potrebno je ispisati podatke iz ulazne datoteke, sortirane po vremenima polaska u rastućem redosledu.
Prilikom ispisa u izlaznu datoteku, koristiti format ``"%9s %5s %-15s %7.2lf\n"``.

Na standardni izlaz ispisati najjeftiniji polazak za zadato mesto do naznačenog vremena polaska (uključujući i vreme polaska).
Ukoliko postoji, ispisati::

  Polazak pre <zadato-vreme> casova za mesto <zadato-mesto> sa najjeftinijom kartom je:

zajedno sa informacijama o polasku. Prilikom formatiranja jedino zaokružiti cenu karte na dve decimale.
Ukoliko ne postoji, ispisati poruku sledeće sadržine::

  Ne postoji polazak za mesto <zadato-mesto> pre <zadato-vreme> casova.

``zadato-mesto`` i ``zadato-vreme`` predstavljaju vrednosti argumenata komandne linije.

Uraditi validaciju argumenta komandne linije koji predstavlja zadato vreme na sledeći način:

* Iskontrolisati dužinu stringa tako da u njega stane format, po dve cifre za čas i za minut, sa tačkom između (proveriti i njeno postojanje)
* Izdvojiti iz stringa čas i minut, pretvoriti u celobrojne vrednosti i iskontrolisati da li se nalaze u validnom opsegu

    * Čas je vrednost između 0 i 23
    * Minut je vrednost između 0 i 59

Radi jednostavnosti, pretpostaviti da se na mestima rezervisanim za časove i minute mogu naći samo cifre.

U slučaju sledećih grešaka prilikom rada programa, izaći sa odgovarajućim kodom greške:

* Nedovoljan ili suvišan broj argumenata, kod greške ``1`` (EXIT_FAILURE)
* Neuspešna validacija zadatog vremena, kod greške ``2``
* Neuspešno otvaranje ulazne datoteke, kod greške ``3``
* Neuspešno otvaranje izlazne datoteke, kod greške ``4``
* Nije moguće dinamički zauzeti memoriju, kod greške ``5``


Primer ulazne datoteke ``polasci.txt``:


.. literalinclude:: polasci.txt
   :language: none


Za primer poziva programa:

.. code-block:: none

    ./a.out polasci.txt red-voznje.txt Zrenjanin 13.00

Očekivani ispis na standardnom izlazu je:

.. literalinclude:: ispis-programa-zrenjanin-1300.txt
   :language: none


Dok je za poziv sledeći poziv programa:

.. code-block:: none

    ./a.out polasci.txt red-voznje.txt Zrenjanin 08.00

Očekivani ispis na standardnom izlazu:


.. literalinclude:: ispis-programa-zrenjanin-0800.txt
   :language: none


U oba slučaja, sadržaj izlazne datoteke ``red-voznje.txt`` je sledeći:


.. literalinclude:: red-voznje.txt
   :language: none


