Napisati program koji od zadatih reči sastavlja rečenice.
Podaci su zadati u ulaznoj datoteci u sledećem formatu:

* `rec` (jedna reč, do 20 karaktera)
* `vrsta` (jedna reč, do 8 karaktera)

Učitati reči u jednostruko spregnutu listu, gde se novi čvorovi dodaju na kraj liste.

Od zadatih reči, formirati sve moguće rečenice u obliku subjekat-predikat-objekat.
Obratiti pažnju da predikat i objekat moraju biti ispisani malim slovom, kao i da na kraju rečenice treba da stoji tačka.
Prebrojati sve subjekte, predikate i objekte i na standardni izlaz ispisati koliko je ukupno moguće formirati rečenica u formatu::

  Od <broj-subjekata> subjekta, <broj-predikata> predikata i <broj-objekata> objekta moguce je sastaviti <ukupan-broj-recenica> recenica.

Program se poziva sa imenom ulazne i izlazne datoteke kao vrednostima argumenata komandne linije.

U slučaju uspešnog izvršavanja programa, izaći sa status kodom ``0`` (``EXIT_SUCCESS``).
Ukoliko program ne može da se izvrši do kraja usled sledećih nedostataka, izaći iz programa sa sledećim status kodovima:

* U slučaju nedovoljnog ili suvišnog broj argumenata komandne linije, izaći iz programa sa status kodom ``1`` (``EXIT_FAILURE``)
* U slučaju nemogućnosti dinamičkog zauzimanja memorije, izaći iz programa sa status kodom ``2``
* Ako program ne može da otvori ulaznu datoteku, izaći sa status kodom ``3``
* Ako program ne može da otvori izlaznu datoteku, izaći sa status kodom ``4``

Primer poziva programa:

.. code-block:: bash

  ./a.out reci.txt recenice.txt

Primer ulazne datoteke ``reci.txt``:

.. literalinclude:: reci.txt
   :language: none

Primer rada programa:

.. literalinclude:: ispis-programa.txt
   :language: none


Primer izlazne datoteke ``recenice.txt``:

.. literalinclude:: recenice.txt
   :language: none
