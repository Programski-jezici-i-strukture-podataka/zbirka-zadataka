Napisati program u kom korisnik učitava u niz od 30 realnih elemenata n vrednosti (u granicama veličine niza) temperatura u stepenima celzijusa.
Preračunati unete vrednosti u stepene farenhajta i kelvina i dobijene vrednosti smestiti u dva zasebna niza.
Ispisati vrednosti sva tri niza tako da u redu budu sukcesivno navedene vrednosti stepeni celzijusa, farenhajta i kelvina.
Ispisati zaglavlje tabelarnog prikaza i konkretne vrednosti odvojiti crticama (pogledati primer rada programa).
Za ispis nizova koristiti format string u obliku ``"%5.1lf %5.1lf %5.1lf\\n"``.
Izračunati srednje vrednosti nizova i ispisati srednje vrednosti svakog niza.
Odvojiti srednje vrednosti istim redom crtica koje su korišćene za razdvajanje zaglavlja i vrednosti niza (pogledati primer rada programa). 

Formula za konverziju iz stepena Celzijusa u stepene Farenhajta:

.. math::

   T_F = (T_C * 1.8) + 32

Formula za konverziju iz stepena Celzijusa u stepene Kelvina:

.. math::

   T_K = T_C + 273.15

Primer rada programa:

.. literalinclude:: ispis-programa.txt

