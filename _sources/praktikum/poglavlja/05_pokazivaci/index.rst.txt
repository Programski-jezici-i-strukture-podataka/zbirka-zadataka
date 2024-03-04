Pokazivači
==========

Podeli svoje utiske o poglavlju na anketi `OVDE <TODO: dodaj link ka anketi>`_.

Preduslovi za rad:

.. literalinclude:: objasnjenja/preduslovi-za-rad.txt
   :language: none

Osnove
------

Svaka promenljiva, osim imena i tipa ima i svoju jedinstvenu adresu u memoriji.
U pitanju je celobrojna vrednost, koja jednoznačno određuje gde se ta promenljiva nalazi u memoriji.
Pokazivač ili pokazivačka promenljiva sadrži adresu promenljive.

Primer deklaracije pokazivačke promenljive:

.. literalinclude:: primeri/pokazivaci-osnova.c
   :lines: 6

Pokazivačka promenljiva mora obavezno sadržati karakter ``*`` na početku svog imena.
Iako su adrese celobrojne vrednosti, ona takođe ima svoj tip, pošto se koriste da posredstvom njih se dođe do sadržaja promenljive čiju adresu sadrže.

Dat je primer kako se u pokazivačku promenljivu smešta adresa druge promenljive:

.. literalinclude:: primeri/pokazivaci-osnova.c
   :lines: 5, 8

Ovo omogućuje čitanje i promenu vrednosti promenljive ``broj`` posredstvom pokazivačke promenljive ``pbroj``:

.. literalinclude:: primeri/pokazivaci-osnova.c
   :linenos:
   :emphasize-lines: 10-12

Ispis ovog programa je:

.. literalinclude:: primeri/pokazivaci-osnova-ispis.txt
   :language: none

Povezanost sa nizovima
----------------------

Umesto indeksiranja, za navigaciju kroz niz je moguće koristiti pokazivače.
Ovo je moguće iz dva razloga:

1. Ako se napiše samo ime niza, dobiće se njegova početna adresa
2. Elementi niza su poređani u memoriji jedan do drugog, stoga je moguće relativno se pozicionirati u odnosu na adresu početka niza

Primer urađen preko nizova:

.. literalinclude:: primeri/nizovi.c
   :linenos:

Bi se mogao uraditi preko pokazivača na sledeći način:

.. literalinclude:: primeri/nizovi-preko-pokazivaca.c
   :linenos:

U oba slučaja ispis je isti:

.. literalinclude:: primeri/nizovi-preko-pokazivaca-ispis.txt
   :language: none

Napomena:

.. literalinclude:: objasnjenja/odnos-pokazivaca-i-nizova.txt
