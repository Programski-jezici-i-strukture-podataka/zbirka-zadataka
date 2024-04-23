Iz zadate ulazne datoteke timovi.txt učitati statički niz struktura,
pri čemu se struktura ``tim_st`` sastoji od sledećih polja:

- država tima (jedna reč, do 20 karaktera)
- vrsta spremane hrane (jedna reč, do 20 karaktera)
- ocena od publike (realan broj)
- ocena od žirija (realan broj)

Pronaći sve timove koji su prošli u sledeći krug i ispisati ih na terminal. 
Tim prolazi u sledeći krug takmičenja ukoliko je ukupna ocena 
(od publike i žirija) veća od granice potrebne za prolazak.
Granica potrebna za prolazak u sledeći krug takmičenja se prosleđuje kao 
poslednji argument komandne linije. 
Pronaći prosečnu ocenu timova koji su prosli u sledeći krug.

Na standardni izlaz (terminal) ispisati i prosečnu ocenu timova koji su 
prošli u sledeći krug.

.. tabs::

  .. group-tab:: Datoteke

      Primer poziva:

      .. code:: bash

         ./program timovi.txt 13.5

      sa zadatim ulazom u datoteci ``timovi.txt``:

      .. literalinclude:: timovi.txt
         :language: none


      i očekivanim izlazom na terminalu:

      .. literalinclude:: izlaz.txt
         :language: none

  .. group-tab:: Standardni ulaz/izlaz
      .. code-block:: bash

         ./a.out 13.5 < timovi-stdout.txt

      Primer ulazne datoteke ``timovi-stdinout.txt``:

      .. literalinclude:: timovi-stdinout.txt
         :language: none

      Ispis programa na standardnom izlazu:

      .. literalinclude:: ispis-programa-stdinout.txt
         :language: none
