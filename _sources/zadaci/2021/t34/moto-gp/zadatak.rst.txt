Iz zadate ulazne datoteke ``motori.txt`` učitati statički niz struktura, pri čemu se struktura ``motor_st`` sastoji od sledećih polja:

* marka (jedna reč, maksimalno 7 karaktera),
* snaga (realan broj, izražen u kW),
* vreme_po_krugu (realan broj),
* procenat_trosenja (ceo broj),
* tip_gume (jedna reč, maksimalno 5 karaktera) i
* broj_stajanja (ceo broj)

Na osnovu parametra ``br_kruga`` koji se prihvata kao argument komandne linije, izračunati koliko
minimalno puta svaki motor mora obaviti zamenu pneumatika (pretpostaviti da se oba pneumatika
troše istovremeno).

Na osnovu parametra ``tip`` koji se prihvata kao argument komandne linije, izračunati koliko je ukupno potrošeno pneumatika prosleđenog tipa u toku trke.
Koristiti sledeće formule za konverziju:

* iz kW u KS: :math:`nova\_snaga = snaga * 1.36`
* potrosnju guma: :math:`100\% / procenat\_trosenja\%`

U izlaznu datoteku ``statistika.txt`` ispisati sledeće informacije:

1. koliko je krugova svaki motor uspeo da napravi sa jednim setom pneumatika,
2. koliko puta treba da promeni pneumatike da bi izvezao trku (da bi ispis bio formatiran kao što je traženo u tekstu zadatka neophodno je koristiti ``"%s\t%.1lfks\t\t%.2lfs\t\t\t%d\n"`` i ``"%s\t\t%.1lfks\t\t%.2lfs\t\t\t%d\n"``)
3. koliko je ukupno potrošeno pneumatika prosleđenog tipa u trci

U slučaju uspešnog izvršavanja programa, izaći sa status kodom ``0`` (``EXIT_SUCCESS``).
Ukoliko program ne može da se izvrši do kraja usled sledećih nedostataka, izaći iz programa sa sledećim status kodovima:

* U slučaju nedovoljnog ili suvišnog broj argumenata komandne linije, izaći iz programa sa status kodom ``1`` (``EXIT_FAILURE``)
* Ako program ne može da otvori ulaznu ili izlaznu datoteku, izaći sa status kodom ``2``

.. tabs::

  .. group-tab:: Datoteke

      Primer poziva programa:

      .. code-block:: bash

         ./a.out motori.txt statistika.txt 25 Medium

      Primer ulazne datoteke ``motori.txt``:

      .. literalinclude:: motori.txt
         :language: none

      Primer izlazne datoteke ``statistika.txt``:

      .. literalinclude:: statistika.txt
         :language: none
  .. group-tab:: Standardni ulaz/izlaz
      .. code-block:: bash

         ./a.out 25 Medium <  motori-stdout.txt

      Primer ulazne datoteke ``motori-stdinout.txt``:

      .. literalinclude:: motori-stdinout.txt
         :language: none

      Ispis programa na standardnom izlazu:

      .. literalinclude:: ispis-programa-stdinout.txt
         :language: none

