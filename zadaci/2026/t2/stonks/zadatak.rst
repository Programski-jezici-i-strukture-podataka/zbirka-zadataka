Napisati program koji obrađuje podatke o podacima o vrednostima akcija kompanija na berzi.
Podaci su zadati u ulaznoj datoteci u sledećem formatu:

* `naziv_kompanije` (jedna reč, do 11 karaktera)
* `prvi_procenat` (realan broj)
* `drugi_procenat` (realan broj)
* `treci_procenat` (realan broj)
* `cetvrti_procenat` (realan broj)
* `peti_procenat` (realan broj)

Učitati podatke o rastu deonica u statički niz, na osnovu kojih će se u izlaznu datoteku ispisati nova vrednost i trend akcija za kompaniju.
Ime ulazne i izlazne datoteke se zadaju kao argumenti komandne linije.
Osim imena datoteka, zadate su i početne vrednosti akcija kao realne vrednosti i prag na osnovu kog se gleda stagnacija akcija, takođe kao realna vrednost.

Procenti rasta akcija predstavljaju promenu vrednosti akcije u toku jednog dana.
Da bi se dobio ukupan trend za taj dan, potrebno je sumirati sve vrednosti procenata.
Nakon toga, potrebno je izračunati novu vrednost akcije.
Imati na umu da se akcije pojedine kompanije mogu naći više od jednog puta u ulaznoj datoteci, stoga je potrebno na određeni način sačuvati međuvrednost akcija.

Trend akcija može sadržati tri vrednosti: ``rast``, ``pad`` i ``stagnacija``.
Stagnacija se određuje na osnovu zadatog praga stagnacije, tako što se on pomnoži sa početnom vrednošću akcije.
Ukoliko se nova vrednost akcije nalazi u okolini početne vrednosti akcije označene prethodno dobijenom vrednošću, za takvu akciju se kaže da ona stagnira.
U suprotnom, gleda se vrednost rasta akcije za taj dan.
Ako je rast negativna vrednost, za trend ispisati ``pad``, u suprotnom ispisati ``rast``.

Vrednosti imena kompanija su fiksne: ``Kompanija_A``, ``Kompanija_B``, ``Kompanija_C`` i ``Kompanija_D``, tim redosledom su povezane sa vrednostima argumenata komandne linije koje idu nakon imena ulazne i izlazne datoteke.
Ukoliko se u ulaznoj datoteci nađu podaci sa kompanijom čije ime nije navedeno, potrebno je na standardni izlaz ispisati tekst u formatu: ``Ne postoji pocetna vrednost akcija za kompaniju <naziv-kompanije>!``.
Preskočiti obradu tog reda, ali nastaviti sa obradom preostalih podataka.

**Korisne matematičke formule**

Računanje rasta akcije u toku dana i nove vrednosti akcije:

.. class:: center

.. math::

  rast = \sum{procenat} 

.. class:: center

.. math::

  vrednost_{nova} = vrednost_{trenutna} \cdot (1 + \frac{rast}{100})

Računanje opsega stagnacije:

.. class:: center

.. math::

  opseg = prag \cdot vrednost_{početna}

Potrebno je proveriti da li se nova vrednost nalazi u opsegu:

.. class:: center

.. math::

  vrednost_{nova} \leq |opseg|

U slučaju uspešnog izvršavanja programa, izaći sa status kodom ``0`` (``EXIT_SUCCESS``).
Ukoliko program ne može da se izvrši do kraja usled sledećih nedostataka, izaći iz programa sa sledećim status kodovima:

* U slučaju nedovoljnog ili suvišnog broj argumenata komandne linije, izaći iz programa sa status kodom ``2``
* Ako program ne može da otvori ulaznu datoteku, izaći sa status kodom ``3``
* Ako program ne može da otvori izlaznu datoteku, izaći sa status kodom ``4``

Primer ulazne datoteke ``deonice.txt``:

.. literalinclude:: deonice.txt
   :language: none

Primer poziva programa:

.. code-block:: bash

  ./a.out deonice.txt izvestaj.txt 100.0 200.0 80.0 120.0 0.002


Primer izlazne datoteke ``izvestaj.txt``:

.. literalinclude:: exp-izvestaj.txt
   :language: none

Primer ulazne datoteke ``deonice-sa-nepostojecom-kompanijom.txt``:

.. literalinclude:: deonice-sa-nepostojecom-kompanijom.txt
   :language: none

Primer poziva programa:

.. code-block:: bash

  ./a.out deonice-sa-nepostojecom-kompanijom.txt izvestaj.txt 100.0 200.0 80.0 120.0 0.002


Primer ispisa programa na standardni izlaz:

.. literalinclude:: ispis-programa-nepostojeca-kompanija.txt
   :language: none

Primer izlazne datoteke ``izvestaj.txt`` (isti sadržaj kao i u prethodnom primeru):

.. literalinclude:: exp-izvestaj.txt
   :language: none

