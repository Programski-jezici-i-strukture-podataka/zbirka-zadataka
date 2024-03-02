1. Zdravo, svete!
=================

Podeli svoje utiske o poglavlju na anketi `OVDE <https://docs.google.com/forms/d/1nFrWembXRh4UUjky4ZdFZfiMXDGbNXc49sjrsw1YxHo>`_.

Preduslovi za rad:

.. literalinclude:: objasnjenja/preduslovi-za-rad.txt
   :language: none

Nameštanje direktorijuma za rad
-------------------------------

Pre pravljenja prvog programa, potrebno je napraviti mesto gde će se oni nalaziti.
Otvoriti terminal, zatim napisati komandu::

  mkdir pjisp

Zatim ukucati komandu::

  ls

Koja bi trebalo da pokaže u listi direktorijuma da se kreirao novi, sa imenom ``pjisp``.

Ući u direktorijum ``pjisp`` pomoću komande::

  cd pjisp

Na terminalu bi trebalo da se ukaže da se nalazi u direkorijumu sa imenom ``pjisp``, nešto poput::

  student@ftn~/pjisp

Visual Studio Code će biti korišćen tokom celog predmeta, stoga je dobro otvoriti ga na nivou ``pjisp`` direktorijuma::

  code .

Izabrati opciju "Yes, I trust the authors" prilikom otvaranja.
Nakon toga, moguće je zatvoriti terminal.
Visual Studio Code (u daljem tekstu VS Code) ima ugrađeni terminal, koji se može otvoriti pomoću gornjeg menija Terminal -> New Terminal.

Rezultat ``ls`` komande će biti prazan, odnosno, još uvek ne postoji nijedna datoteka ili direktorijum.
Dodati direktorijum ``v01`` na sledeći način::

  mkdir v01

Proveriti sa ``ls`` komandom da li se uspešno kreirao i potom ući u njega sa komandom::

  cd v01

Sada je moguće napraviti novu tekstualnu datoteku unutar direktorijuma ``v01`` pomoću komande::

  code proba.txt

Otvoriće se novi tab sa imenom ``proba.txt``. Upisati neki tekst u njega i sačuvati (pritiskom tastera Ctrl i S ili odabirom File -> Save u gornjem meniju).

Ako ste ispratili sve ovo, spremni ste da napišete svoj prvi program!

Prvi program
------------

Da bismo mogli da objasnimo računaru šta želimo da on uradi, potrebno je napisati tekst poštujući određena pravila.
U slučaju programskog jezika C, to znači da je potrebno napraviti novu datoteku sa ekstenzijom ".c".
VS Code može pomoći u tome, tako što se u terminalu ukuca sledeće::

  code zdravo.c

Unutar te datoteke, potrebno je upisati sledeće:

.. literalinclude:: primeri/zdravo.c
   :linenos:

Kod je potrebno sačuvati.
Uveriti se da je sačuvano tako što neće biti bele loptice pored imena datoteke u njenom tabu.
Ovo je samo pola posla, odnosno, ovakav tekst računar još uvek ne može da razume.
Da bi mogao da shvati i da izvrši ono što od njega tražimo, potrebno je prevesti rešenje na njegov jezik.
To se može uraditi na sledeći način::

  gcc zdravo.c

``gcc`` je program, koji će pokušati da ono što smo napisali na jeziku koji je ljudima razumljiv da prevede u jezik mašinskih komandi koje računar razume.
Rezultat tog prevođenja je nova, izvršna datoteka, koju računar zna da pokrene. U našem slučaju, ona će imati ime ``a.out``.
Stvari koje mogu poći po zlu:

.. literalinclude:: objasnjenja/neuspesno-kompajliranje.txt
   :language: none

``a.out`` se pokreće iz Terminala, na sledeći način::

  ./a.out

Rezultat koji bi trebalo nakon toga da se vidi na ekranu terminala je:

.. literalinclude:: primeri/zdravo-ispis.txt
   :language: none

Napomena:

.. literalinclude:: objasnjenja/printf-funkcija.txt
   :language: none

Napomena:

.. literalinclude:: objasnjenja/main-funkcija.txt
   :language: none

Standardni ulaz/izlaz
---------------------

U prethodnom primeru korišćena je funkcija ``printf`` kako bi se tekst pod navodnicima ispisao na ekranu terminala.
To je podrazumevano ponašanje prilikom ispisa teksta, stoga se ekran terminala zove standardni izlaz.

Postavlja se pitanje kakoje moguće uneti vrednosti na neki način u program.
Podrazumevani način je putem tastature korisnika, odnosno, to predstavlja standardni ulaz.
Funkcija koja se koristi u te svrhe naziva se ``scanf`` i koristi se na sledeći način:

.. literalinclude:: primeri/standardni-ulaz-izlaz.c
   :linenos:

Sačuvati datoteku i kompajlirati rešenje na isti način kao što je to navedeno iznad.

Nakon uspešnog kompajliranja, pokrenuti dobijenu izvršnu datoteku ``a.out``.
Program će se zaustaviti nakon ispisa "Unesite broj: " i čekaće.
Uneti celobrojnu vrednost i pritisnuti enter kako bi se završilo izvršavanje programa.

Primer rada programa:

.. literalinclude:: primeri/standardni-ulaz-izlaz-ispis.txt
   :language: none

Ono što se može primetiti u primeru je da se ``broj`` koristi i kod ``scanf`` i kod ``printf`` naredbe.
``broj`` predstavlja promenljivu u programu. One se mogu tretirati kao "kućice" u memoriji određene veličine (izražene u bajtovima).
Svaka promenljiva ima svoje jedinstveno ime (u primeru ``broj``) i svoj tip (u primeru je ``int``, skraćeno od "integer", što je u prevodu celobrojni tip).
Promenljive se koriste za skladištenje podataka u programu.
U njih se mogu upisivati vrednosti, može im se dodeliti rezultat nekog izraza i po potrebi se mogu ispisati.

Funkcija ``scanf`` upisuje vrednost koju smo uneli preko tastature u promenljivu broj.
Da bi to mogla da ostvari, potrebno je navesti adresu promenljive u memoriji u koju upisujemo vrednost, a ona dobija tako što stavimo ``&`` ispred imena promenljive.

Primećuje se ``%d`` i u ``scanf`` i u ``printf``.
Pošto nije poznato unapred koja će vrednost promenljive ``broj`` biti, ono služi kao umetak, koji govori da se na tom mestu očekuje celobrojna vrednost ("d" označava decimal, ostali tipovi imaju drugačiju vrednost).

Napomena:

.. literalinclude:: objasnjenja/zaglavlje-stdio.txt
   :language: none

Program koji sabira dva broja
-----------------------------

Iskoristićemo do sad stečeno znanje da napišemo jednostavan program, čija je svrha da sabere dva broja.

.. literalinclude:: primeri/zbir-dva-broja.c
   :linenos:

Primer ispisa programa:

.. literalinclude:: primeri/zbir-dva-broja-ispis.txt
   :language: none

Za svaku vrednost koja se unosi sa tastature uvedene su po promenljiva (``prvi_broj`` i ``drugi_broj``) u kojoj će se skladištiti uneta vrednost.
Pored njih, postoji i treća promenljiva, ``zbir``, čija se vrednost ne dobija preko tastature, već kao zbir vrednosti koje se nalaze u ``prvi_broj`` i ``drugi_broj``.
Promenljiva ``zbir`` se, nakon dodele vrednosti, ispisuje na standardni izlaz pomoću funkcije ``printf``.

Napomena:

.. literalinclude:: objasnjenja/redosled-izvrsavanja.txt
   :language: none

Iz svih ovih razloga navedenih u napomeni iznad, prvo deklarišemo promenljive ``prvi_broj``, ``drugi_broj`` i ``zbir``.
Zatim unosimo vrednosti sa tastature u prve dve promenljive i pre ispisa, postavljamo vrednost promenljive zbir.
