Iz zadate ulazne datoteke učitati podatke u jednostruko spregnutu listu, gde struktura materijal_st sadrži sledeća polja:

* `kategorija` (jedna reč, do 20 karaktera)
* `naziv` (jedna reč, do 20 karaktera)
* `cena_po_m2` (realan broj)

Struktura materijal_st sadrži i polja potrebna za pravilno formiranje jednostruko spregnute liste.

Učitati materijale u jednostruko spregnutu listu i uraditi sledeće:

* Sortirati materijale po ceni po kvadratu u rastućem redosledu pri dodavanju u listu
* Sračunati ukupnu cenu materijala za kvadraturu koja se unosi kao argument komandne linije i ispisati sve materijale sa ukupnom cenom
* Za količinu novca kao i kategoriju materijala koje se unose putem komandne linije pronaći i ispisati materijal čija je ukupna cena za datu kvadraturu najbliža zadatoj količini novca i koji pripada unetoj kategoriji

Ispis materijala formatirati na sledeći način:

.. code-block:: c

  %12s %12s %12.2f$ %12.2f$


* U slučaju nedovoljnog ili suvišnog broja argumenata komandne linije, izaći iz programa sa status kodom ``1`` (``EXIT_FAILURE``).
* U slučaju neuspešnog otvaranja fajla, izaći iz programa sa status kodom ``2``.
* U slučaju neuspešnog zauzeća memorije prilikom kreiranja čvora liste, izaći iz programa sa status kodom ``3``.

Primer poziva programa:

.. code-block:: bash

  ./a.out input.txt output.txt 3.5 80 Drvo



Primer ulazne datoteke ``input.txt``:


.. literalinclude:: input.txt
   :language: none
   

Ispis programa u izlaznu datoteku ``output.txt``:


.. literalinclude:: output.txt
   :language: none
   

