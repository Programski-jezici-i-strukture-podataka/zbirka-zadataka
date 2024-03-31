Strukture
=========

Podeli svoje utiske o poglavlju na anketi `OVDE <https://docs.google.com/forms/d/1hmqQGSA6yqIBEBoK_4nKHm3qV2cvQsszgNvieOi9APU>`_.

Preduslovi za rad:

.. literalinclude:: objasnjenja/preduslovi-za-rad.txt
   :language: none

Predstavljaju složene tipove podataka koji se prave kombinovanjem više primitivnih tipova. Struktura je skup istih ili različitih
tipova podataka koji se čuvaju pod istim imenom. Koriste se kada imamo vrednosti različitih tipova podataka koje su međusobno povezane.
Struktura može pored primitivnih tpova da sadrži i drugu strukturu u sebi.
Definiše se upotrebom reči ``struct`` koju prate vitičaste zagrade i ;
Osnovna forma strukture je::

  struct ime_strukture
  {
    type promenljiva_1;
    type promenljiva_2;
    ...
  };

gde je type bilo koji od osnovnih tipova podataka, dok je novokreirani tip podatka ``struct ime_strukture``.

Napomena:

.. literalinclude:: objasnjenja/definicija-strukture.txt
   :language: none

Primer strukture::

  struct automobil
  {
    char marka[51];
    char model[51];
    int kubikaza;
    int godiste;
    float cena;
  };

U primeru je data struktura automobil sa poljima marka i model koju su ``char`` tipa, dužine 50 karaktera, kubikaža i godište koji
su ``int`` tipa i cena koja je ``float`` tip podatka. Tip ove strukture je ``struct automobil``.

Primer unosa automobila
-----------------------

Dat je primer programa u kome se unose podaci o automobilima koji se nakon toga ispisu na terminal:

.. literalinclude:: primeri/automobil.c
   :linenos:

Ispis programa:

.. literalinclude:: primeri/automobil-funkcije-ispis.txt
   :language: none

U primeru iznad je deklarisana promenljiva tipa struct automobil koja se zove a. Da bi se unele vrednosti svih polja ove strukture, neophodno
je svaku vrednost smestiti u odgovarajuće polje. Za pristup poljima strukture koristi se ``.``, pa se tako za pristup polju kubikaza strukture a
tipa struct automobil mora navesti a.kubikaza ukoliko je potrebna vrednost promenljive, dok se za korišćenje adrese mora navesti &a.kubikaza. Isto
se odnosi i na ostala polja strukture, s tim da se sa stringom radi bez korišćenja ``&`` operatora za pristup adresi.

Primer unosa automobila kroz funkciju
-------------------------------------

.. literalinclude:: primeri/automobil-funkcije.c
   :language: c

Ispis programa:

.. literalinclude:: primeri/automobil-funkcije-ispis.txt
   :language: none

U primeru iznad je deklarisane su 2 promenljiva tipa struct automobil koja se zovu a1 i a2. Prvo se poziva funkcija unos_automobila
za a1 kroz koju se unose vrednosti svih polja, pa se isto ponavlja i za a2. Funkciji unos_automobila se struktura prosleđuje po
pokazivaču, pa je pristup poljima strukture drugačiji nego u prvom primeru.
Pristup strukturi prosleđenoj po pokazivaču je moguć na 2 načina:

#. korišćenjem kombinacije ``*`` i ``.`` operatora
#. korišćenjem ``->`` operatora

Oba načina rade istu stvar, prvo je neophodno dereferencirati celu strukturu, pa tek onda pristupiti traženom polju.

Typedef
-------

Ključna reč ``typedef`` se koristi za pravljenje aliasa za određeni tip podatka. U slučaju strukture, zgodna nam je za korišćenje
kako bi pojednostavili sintaksu.
Osnovna forma ovakve strukture je::

  typedef struct ime_strukture
  {
    type promenljiva_1;
    type promenljiva_2;
    ...
  }novo_ime;

gde je type bilo koji od osnovnih tipova podataka, dok je novokreirani tip podatka ``novo_ime`` umesto ``struct ime_strukture``.

Primer unosa automobila kroz funkciju korišćenjem typedef
---------------------------------------------------------

.. literalinclude:: primeri/automobil-typedef.c
   :language: c

U primeru iznad je struktura ``struct automobil`` zamenjena sa aliasom ``AUTO`` uz pomoć ključne reči ``typedef``.

Primer rada sa nizovima strukture
---------------------------------

.. literalinclude:: primeri/automobili-niz.c
   :language: c

Ispis programa:

.. literalinclude:: primeri/automobili-niz-ispis.txt
   :language: none
