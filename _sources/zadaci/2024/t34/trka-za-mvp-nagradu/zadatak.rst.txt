Napisati program koji pronalazi i označava favorita za MVP nagradu (na osnovu efikasnosti igrača), a i označava one igrače koji zbog tehnikalija to ne mogu biti. Podaci su zadati u ulaznoj datoteci u sledećem formatu:

* `ime` (jedna reč, do 15 karaktera)
* `broj_poena` (celobrojna vrednost)
* `broj_skokova` (celobrojna vrednost)
* `broj_asistencija` (celobrojna vrednost)
* `broj_odigranih_utakmica` (celobrojna vrednost)

Igrače učitati u statički niz, zatim na osnovu dobijenih podataka odrediti efikasnost svakog igrača po sledećoj formuli:

.. math::

   efikasnost = \frac{broj\_poena + broj\_skokova + broj\_asistencija}{broj\_odigranih\_utakmica}

Niz sortirati na osnovu efikasnosti igrača i to silazno. Takodje sračunati prosečnu efikasnost svih igrača.

Koristeći zadatu granicu, koja se unosi kao argument komandne linije i koja označava na koliko je utakmica igrač morao igrati da bi uopšte bio kvalifikovan da dobije MVP nagradu, na kraj imena igrača koji nisu zadovoljili kriterijum dodati sledeći niz karaktera:

(-)

A na kraj imena igrača sa najvećim koeficijentom efikasnosti i koji pritom zadovoljava kriterijum odigranih utakmica dodati sledeći niz karatktera:

(*)

Ispisati na standardni izlaz sortirani niz igrača sa preradjenim imenima, poene, skokove, asistencije, broj odigranih utakmica, efikasnost.

Ispis igrača formatirati na sledeći način:

.. code-block:: c

  %12s %10d %10d %10d %10d %10.2lf

A na sam kraj ispisati koja je prosečna efikasnost svih igrača.

U slučaju nedovoljnog ili suvišnog broja argumenata komandne linije, izaći iz programa sa status kodom ``1`` (``EXIT_FAILURE``).
 
.. tabs::

  .. group-tab:: Datoteke

      Primer poziva:

      .. code:: bash

         ./a.out igraci_input_data.txt igraci_output_data.txt 72

      Primer ulazne datoteke ``igraci_input_data.txt``:

      .. literalinclude:: igraci.txt
         :language: none

      Primer izlazne datoteke ``igraci_output_data.txt``:

      .. literalinclude:: igraci_output_file.txt
         :language: none

      i očekivanim izlazom na terminalu:

      .. literalinclude:: ispis-programa_efikasnost.txt
         :language: none

  .. group-tab:: Standardni ulaz/izlaz
  
      Primer poziva:
      
      .. code-block:: bash

         ./a.out 72 < igraci_input_data.txt

      Primer ulazne datoteke ``igraci_input_data.txt``:

      .. literalinclude:: igraci-stdinout.txt
         :language: none

      i očekivanim izlazom na terminalu:

      .. literalinclude:: ispis-programa.txt
         :language: none
