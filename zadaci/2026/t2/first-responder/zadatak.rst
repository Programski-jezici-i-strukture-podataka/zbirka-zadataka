Napisati program koji obrađuje podatke o dostupnosti vatrogasnih društava u slučaju požara.
Podaci su zadati u ulaznoj datoteci u sledećem formatu:

* `mesto` (jedna reč, do 30 karaktera)
* `geografska_sirina` (realna vrednost)
* `geografska_duzina` (realna vrednost)

Učitati podatke o vatrogasnim društvima u statički niz od 30 elemenata, koji će biti dostupni u slučaju požara.
Nakon učitanih podataka, program učitava geografsku širinu i dužinu lokacije gde se dogodio požar, kao i kategoriju požara.
U zavisnosti od ozbiljnosti požara, definišu se tri kategorije u odnosu na mesto dešavanja požara:

- Žuta (Z): angažuju se sve vatrogasne stanice u krugu poluprečnika od 5km vazdušnom linijom
- Narandžasta (N): angažuju se sve vatrogasne stanice u krugu poluprečnika od 10km vazdušnom linijom
- Crvena (C): angažuju se sve vatrogasne stanice u krugu poluprečnika od 20km vazdušnom linijom

Rastojanje između dve tačke na Zemlji određuje se Haversinusnom formulom (data je u nastavku teksta).
Ispisati sva vatrogasna društva koja će biti zahvaćena krugom.
U ispis se računaju mesta i vazdušne razdaljine u kilometrima dobijeno korišćenjem Haversinusne formule.
Ukoliko krug koji se formira oko lokacije požara ne obuhvata nijedno vatrogasno društvo, uzeti prvo najbliže izvan kruga. 

Prilikom ispisa označiti tzv. "First responder-a", odnosno, vatrogasno društvo koje je očekivano da stigne najbrže na mesto incidenta.
Dodati "(FR)" na string sa imenom mesta korišćenjem odgovarajuće funkcije za rad sa stringovima.

Korisne matematičke formule
```````````````````````````

**Konverzija iz stepena u radijane**

.. math:: \varphi = stepeni * \pi / 180

**Haversinusna formula**

.. math:: a = \sin^2(\frac{\Delta\varphi}{2}) + \cos(\varphi_{1})\cos(\varphi_{2})\sin^2(\frac{\Delta\lambda}{2})

.. math:: c = 2 \cdot \arctan2(\sqrt{a}, \sqrt{1 - a})

.. math:: d = R \cdot c

Legenda korišćenih simbola::

  φ1, φ2 = geografske širine u radijanima
  λ1, λ2 = geografske dužine u radijanima
  Δφ = φ2 - φ1
  Δλ = λ2 - λ1
  R = poluprecnik Zemlje ≈ 6371km
  d = vazdušna razdaljina u kilometrima

U slučaju uspešnog izvršavanja programa, izaći sa status kodom ``0`` (``EXIT_SUCCESS``).
U slučaju nedovoljnog ili suvišnog broj argumenata komandne linije, izaći iz programa sa status kodom ``1`` (``EXIT_FAILURE``)


Primer ulazne datoteke ``vatrogasci.txt``:

.. literalinclude:: vatrogasci.txt
   :language: none

Primer poziva programa:

.. code-block:: bash

  ./a.out 45.25388 19.85194 Z < vatrogasci.txt

Primer ispisa programa na standardni izlaz:

.. literalinclude:: ispis-programa.txt
   :language: none

Primer poziva programa kad nema vatrogasnog društva u okolini:

.. code-block:: bash

  ./a.out 45.344119 19.857105 Z < vatrogasci.txt

Primer ispisa programa na standardni izlaz:

.. literalinclude:: ispis-nema-vatrogasnog-drustva.txt
   :language: none
