Iz zadate ulazne datoteke ``timovi.txt`` učitati statički niz struktura, pri čemu se struktura ``formula_st`` sastoji
od sledećih polja:

* ``naziv_tima`` (jedna reč, maksimalno 15 karaktera),
* ``naziv_vozaca`` (jedna reč, maksimalno 10 karaktera),
* ``vreme_po_krugu`` (pozitivan ceo broj),
* ``penali`` (realan broj) i
* ``ukupno_vreme`` (realan broj)

Na osnovu parametara ``br_kruga`` koji se prihvata preko argumenata komandne linije, izračunati ukupno
vreme za svakog vozača. Za izračunavanje ukupnog vremena koristiti formulu: 

.. math::

  ukupno\_vreme = vreme\_po\_krug \cdot br\_kruga + penali

U izlaznu datoteku ``statistika.txt`` ispisati informacije o ukupnom ostvarenom vremenu za svaki tim
(vrednost polja ukupno_vreme zaokružiti na jednu decimalu), kao i podatke o vozaču koji je ostvario
najbolje vreme.

U slučaju uspešnog izvršavanja programa, izaći sa status kodom ``0`` (``EXIT_SUCCESS``).
Ukoliko program ne može da se izvrši do kraja usled sledećih nedostataka, izaći iz programa sa sledećim status kodovima:

* U slučaju nedovoljnog ili suvišnog broj argumenata komandne linije, izaći iz programa sa status kodom ``1`` (``EXIT_FAILURE``)
* Ako program ne može da otvori ulaznu ili izlaznu datoteku, izaći sa status kodom ``2``

.. tabs::

  .. group-tab:: Datoteke

    Primer poziva programa:

    .. code-block:: bash

      ./a.out 60 statistika.txt timovi.txt

    sa zadatim ulazom u datoteci ``timovi.txt``:

    .. literalinclude:: timovi.txt
      :language: none

    Očekivani izlaz u izlaznoj datoteci ``statistika.txt`` je sledeći:

    .. literalinclude:: statistika.txt
      :language: none
  .. group-tab:: Standardni ulaz/izlaz
      .. code-block:: bash

         ./a.out 60 < timovi-stdout.txt

      Primer ulazne datoteke ``timovi-stdinout.txt``:

      .. literalinclude:: timovi-stdinout.txt
         :language: none

      Ispis programa na standardnom izlazu:

      .. literalinclude:: ispis-programa-stdinout.txt
         :language: none

