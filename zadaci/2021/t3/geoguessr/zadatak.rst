Pokušaj korisnika u igri GeoGuessr predstavljen je preko strukture pomoću sledećih polja:

* korisničko ime (jedna reč, maksimalno 20 karaktera)
* relativna udaljenost pogotka izražena u metrima (celobrojna vrednost)

Učitati zadate podatke u binarno stablo pretrage (struktura sadrži potrebna polja za formiranje čvora binarnog stabla).
Kriterijum za formiranje stabla je korisničko ime igrača u rastućem redosledu (koristiti funkciju ``strcmp`` za poređenje korisničkih imena).

U izlaznu datoteku ispisati relativnu udaljenost pogotka i korisničko ime u formatu ``"%4dm %s"``.
Pronaći igrače čija su korisnička imena zadata kao argumenti komandne linije i ispisati apsolutnu razdaljinu između njih (koristiti funkciju ``abs``),
ukoliko postoje igrači sa zadatim korisničkim imenima.
U slučaju da barem jedan od igrača ne postoji, ispisati sledeći sadržaj: ``"\nNe postoji bar jedan igrac od zadatih korisnickih imena!\n"``

Primer ulaznog fajla ``pokusaji.txt``:

.. literalinclude:: pokusaji.txt
   :language: none

Primer poziva programa:

.. code-block:: bash

   ./resenje pokusaji.txt rezultati.txt Alatec Jeanite

Primer izlazne datoteke ``rezultati.txt``:

.. literalinclude:: rezultati.txt
   :language: none

Primer poziva programa kada jedan od traženih korisnika ne postoji:

.. code-block:: bash

   ./resenje pokusaji.txt rezultati-nema-igraca.txt Alatec Shiyaut

Primer izlazne datoteke ``rezultati-nema-igraca.txt``:

.. literalinclude:: rezultati-nema-igraca.txt
   :language: none

