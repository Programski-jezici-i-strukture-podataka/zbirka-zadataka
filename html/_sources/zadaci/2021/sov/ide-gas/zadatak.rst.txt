Stambena jedinica je predstavljena preko strukture koja se sastoji od sledećih polja:

* Ime vlasnika stana (jedna reč, maksimalno 20 karaktera)
* Prezime vlasnika stana (jedna reč, maksimalno 30 karaktera)
* Kvadratura stana (neoznačena, celobrojna vrednost)

Podaci o stambenim jedinicama u zgradi učitavaju se iz ulaznog fajla u jednostruko spregnutu listu, gde se čvorovi dodaju na kraj liste.
S obzirom na to da zgrada nema kalorimetre za svaku stambenu jedinicu, naplata ukupno potrošenog gasa za mesec raspodeljuje se između stambenih jedinica na osnovu kvadrature stana po sledećoj formuli:

.. math::

   Potrošnja_{stan}[din] = Kv_{stan}[m^2] \div Kv_{zgrada}[m^2] \cdot Potrošnja_{zgrada}[din]

Ukupan račun za stambenu jedinicu je potrošnja stana, sa PDV-om od ``10%``.


Za zadati mesec, godinu i ukupnu potrošnju tokom meseca, potrebno je izračunati koliko je svaka stambena jedinica dužna da plati račun za gas.
U izlaznu datoteku, potrebno je ispisati ime i prezime vlasnika stana, kao i cenu koju je vlasnik stambene jedinice dužan da plati u formatu ``"%-7s %-10s %.2lf"``.
Naziv ulazne datoteke, mesec, godina i ukupna potrošnja tokom meseca, izražena u dinarima, zadaju se kao argumenti komandne linije.
Naziv izlazne datoteke formira se spajanjem argumenata komandne linije za mesec i godinu i dodavanjem ekstenzije ``.txt``.

Primer ulaznog fajla ``zgrada.txt``

.. literalinclude:: zgrada.txt
   :language: none

Primer poziva programa:

.. code-block:: bash

   ./racun zgrada.txt decembar 2021 12510.54

Primer izlazne datoteke ``decembar2021.txt``:

.. literalinclude:: decembar2021.txt
   :language: none

