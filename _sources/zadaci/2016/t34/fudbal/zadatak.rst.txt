Učinak fudbalskog tima tokom sezone opisan je sledećim poljima:

* naziv tima (do 30 karaktera)
* gol razlika (ceo broj)
* broj bodova (neoznačen, ceo broj)

Svaki tim, pored imena i gol razlike, u ulaznoj datoteci postoje, redom, broj pobeda, nerešenih utakmica i poraza. Sa podacima iz ulazne datoteke uraditi sledeće:

a) Učitati ih u niz struktura koje odgovaraju gornjem opisu. Iskoristiti broj pobeda, nerešenih utakmica i poraza za računanje trenutnog broja bodova po sledećem principu:

    * Pobeda nosi 3 boda
    * Nerešena utakmica nosi 1 bod
    * Poraz nosi 0 bodova

b) U izlaznu datoteku ispisati sve timove koji se sa brojem bodova nalaze u intervalu između prosečnog broja bodova u ligi i vrednosti zadate kao argument komandne linije. Datoteku nazvati sa prefiksom "izmedju_proseka_i_", pa onda staviti broj bodova unet kao argument komandne linije i postfiks "_bodova.txt".
c) Sortirati tabelu po broju bodova. U slučaju da dve ekipe imaju isti broj bodova, prednost ima ona ekipa koja ima veću gol razliku. Prve tri ekipe idu u "Ligu šampiona", sledeće dve u "Ligu Evrope", a poslednje tri su u "zoni ispadanja". Prilikom ispisa u izlaznu datoteku posebno podvući crtu ispod timova koji su plasirani za "Lige", odnosno iznad "zone ispadanja".


Primer ulazne datoteke ``statistika.txt``:

.. literalinclude:: statistika.txt
   :language: none

Primer izlazne datoteke ``tabela.txt``:

.. literalinclude:: tabela.txt
   :language: none

Primer izlazne datoteke ``izmedju_proseka_i_25_bodova.txt``:

.. literalinclude:: izmedju_proseka_i_25_bodova.txt
   :language: none

Primer poziva programa:

.. code-block:: bash

   ./fudbal statistika.txt tabela.txt 20

