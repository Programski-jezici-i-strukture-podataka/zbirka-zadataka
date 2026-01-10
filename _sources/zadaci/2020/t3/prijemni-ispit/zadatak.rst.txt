Kandidati za upis na fakultet predstavljeni su u strukturi na sledeći način:

* ime kandidata(jedna reč, maksimalno 20 karaktera)
* prezime kandidata (jedna reč, maksimalno 30 karaktera)
* ostvareni broj bodova na prijemnom ispitu (neoznačen broj)

Kandidati su radili prijemni ispit i ostvarili određen rezultat. Potrebno je "podvući crtu", odnosno, odrediti broj kandidata koji su prošli prijemni ispit.
Učitati kandidate iz ulazne datoteke u jednostruko spregnutu listu (novi elementi dodaju se tako da lista bude sortirana po ostvarenim bodovima u opadajućem redosledu), zatim uraditi sledeće:

Na osnovu broja primljenih kandidata koji se zadaju kao argument komandne linije u izlaznu datoteku ispisati redni broj, ime, prezime i ostvareni broj bodova kandidata u formatu ``%2u %-7s %-7s %2u``.
Podvući crtu ispod poslednjeg primljenog kandidata, crta se sastoji od 30 crtica (karakter ``-``).
Naziv ulazne i izlazne datoteke su zadati redom, kao prvi i drugi argument komandne linije.

Primer ulazne datoteke ``kandidati.txt``:

.. literalinclude:: kandidati.txt
   :language: none

Primer poziva programa:

.. code-block:: bash

  ./lista_kandidata kandidati.txt preliminarna-lista.txt 5

Primer izlazne datoteke ``preliminarna-lista.txt``:

.. literalinclude:: preliminarna-lista.txt
   :language: none

