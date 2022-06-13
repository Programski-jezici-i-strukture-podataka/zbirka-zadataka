Iz zadate ulazne datoteke učitati podatke u jednostruko spregnutu listu.

Struktura paket se sastoji od sledećih polja:

* oznaka paketa (jedna reč, do 8 karaktera)
* osnovna cena (realan broj)
* oznaka da li je paket isporučen (jedna reč, do 2 karaktera (moguće vrednosti da/ne))
* udaljenost od glavne pošte (pozitivna, celobrojna vrednost)

Takođe, struktura paket sadrži i polja potrebna za pravilno formiranje jednostruko spregnute liste.

Preko argumenata komandne linije uneti naziv ulazne datoteke, naziv izlazne datoteke i maksimalnu udaljenost od glavne pošte.

U izlaznu datoteku ispisati sve pakete koji treba da se isporuče i izračunati konačnu cenu isporuke za svaki paket ponaosob. 
Konačna cena isporuke izavisi od maksimalne udaljenosti od glavne pošte. 

* Ukoliko je udaljenost paketa veća od maksimalne udaljenosti od glavne pošte, koju smo uneli preko argumenata komande linije, konačna cena isporuke se dobija tako što na osnovnu cenu doda polovina njene vrednosti.
* Ukoliko je udaljenost paketa manja ili jednaka udaljenosti od glavne pošte, konačna cena isporuke se dobija tako što se na osnovnu cenu doda 50 din.

Obratiti pažnju na odgovarajuće rukovanje greškama pri radu sa datotekama (ne ispisivati ništa u datoteku niti standardni izlaz):

* Ako nije moguće otvoriti ulaznu datoteku: izaći iz programa sa ``exit(1)``
* Ako nije moguće otvoriti izlaznu datoteku: izaći iz programa sa ``exit(2)``

Primer poziva programa:

.. code-block:: bash

  ./a.out paketi.txt isporuka.txt 5


Zadati ulaz u datoteci ``paketi.txt``:

.. literalinclude:: paketi.txt
   :language: none

Izgled izlazne datoteke isporuka.txt sa izračunatom konačnom cenom isporuke ``isporuka.txt``:

.. literalinclude:: isporuka.txt
   :language: none

