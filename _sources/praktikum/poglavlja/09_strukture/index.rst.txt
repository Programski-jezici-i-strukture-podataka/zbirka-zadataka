Strukture
=========

Podeli svoje utiske o poglavlju na anketi `OVDE <https://docs.google.com/forms/d/e/1FAIpQLSdiCrnYwQky6bUDPfGdXaSxn_9NfoK7xMvD2gL9adsb-MhR6w/viewform?vc=0&c=0&w=1&flr=0>`_.

Preduslovi za rad:

.. literalinclude:: objasnjenja/preduslovi-za-rad.txt
   :language: none

Predstavljaju složene tipove podataka koji se prave kombinovanjem više primitivnih tipova i/ili ranije formiranih složenih tipova.
Koriste se kada imamo vrednosti različitih tipova podataka koje su međusobno povezane. Na primer, student je opisan imenom,
prezimenom, prosekom, i brojem indeksa. Navedena obeležja predstavlja podatke o studentu koji su međusobno povezani i mogu se
predstaviti strukturom student. Knjiga je opisana nazivom, izdavačem i brojem stranica, pa se tako ona može predstaviti strukturom
knjiga koja sadrži sva navedena obeležja. Struktura se definiše se upotrebom reči ``struct`` koju prate vitičaste zagrade i ;
Osnovna forma strukture je::

  struct ime_strukture
  {
    tip promenljiva_1;
    tip promenljiva_2;
    ...
  };

gde je ``tip`` bilo koji od osnovnih ili složenih tipova podataka, dok je novokreirani tip podatka ``struct ime_strukture``.

Napomena:

.. literalinclude:: objasnjenja/definicija-strukture.txt
   :language: none

Primer strukture::

  #define MAX_MARKA 51
  #define MAX_MODEL 51

  struct automobil
  {
    char marka[MAX_MARKA];
    char model[MAX_MODEL];
    int kubikaza;
    int godiste;
    float cena;
  };

U primeru je data struktura automobil sa poljima marka i model koju su ``char`` tipa, dužine 50 karaktera, kubikaža i godište koji
su ``int`` tipa i cena koja je ``float`` tip podatka. Tip ove strukture je ``struct automobil``.

Primer unosa podataka u strukturu
---------------------------------

Dat je primer programa u kome se unose podaci o automobilima koji se nakon toga ispišu na terminal:

.. literalinclude:: primeri/automobil.c
   :linenos:

U primeru iznad je deklarisana promenljiva tipa ``struct automobil`` koja se zove ``a``. Da bi se unele vrednosti svih polja ove strukture, neophodno
je svaku vrednost smestiti u odgovarajuće polje. Za pristup poljima strukture koristi se ``.``, pa se tako za pristup polju ``kubikaza`` strukture ``a``
tipa ``struct automobil`` mora navesti ``a.kubikaza`` ukoliko je potrebna vrednost promenljive, dok se za korišćenje adrese mora navesti ``&a.kubikaza``. Isto
se odnosi i na ostala polja strukture, s tim da se sa stringom radi bez korišćenja ``&`` operatora za pristup adresi.

Ispis programa:

.. literalinclude:: primeri/automobil-funkcije-ispis.txt
   :language: none

Typedef
-------

Ključna reč ``typedef`` se koristi za preimenovanje tipa (pravljenje aliasa) za određeni tip podatka. U slučaju strukture, zgodna nam je za korišćenje
kako bi pojednostavili sintaksu.
Osnovna forma ovakve strukture je::

  typedef struct ime_strukture
  {
    tip promenljiva_1;
    tip promenljiva_2;
    ...
  } NOVO_IME;

gde je novokreirani tip podatka ``NOVO_IME`` umesto ``struct ime_strukture``.

Primer unosa podataka strukture kroz funkciju
---------------------------------------------

.. tabs::

  .. tab:: Bez typedef
    .. literalinclude:: primeri/automobil-funkcije.c
       :linenos:
  .. tab:: Korišćenjem typedef
    .. literalinclude:: primeri/automobil-typedef.c
       :linenos:

U oba primeru iznad deklarisane su 2 promenljive. U primeru bez ``typedef``, promenljive su tipa ``struct automobil`` i zovu se
``a1`` i ``a2``, dok su u primeru sa ``typedef`` promenljive takođe tipa ``struct automobil``, ali se umesto ovog tipa može koristiti alias
``AUTO``. Prvo se poziva funkcija ``unos_automobila`` za ``a1`` kroz koju se unose vrednosti
svih polja, pa se isto ponavlja i za ``a2``. Nakon toga se poziva funkcija ``ispis_automobila`` za ``a1``, pa za ``a2``. Funkciji
``unos_automobila`` se struktura prosleđuje po pokazivaču, pa je pristup poljima strukture drugačiji nego u prvom primeru.
Pristup strukturi prosleđenoj po pokazivaču je moguć na 2 načina:

#. korišćenjem kombinacije ``*`` i ``.`` operatora
#. korišćenjem ``->`` operatora

Napomena:

.. literalinclude:: objasnjenja/dereferenciranje.txt
   :language: none

Obe varijante primera daju isti ispis programa:

.. literalinclude:: primeri/automobil-funkcije-ispis.txt
   :language: none

Primer rada sa nizovima struktura
---------------------------------

.. literalinclude:: primeri/automobili-niz.c
   :linenos:

U primeru iznad je definisana struktura ``struct automobil`` kojoj je dodeljen alias ``AUTO`` koji se u daljem radu programa koristi.
Prvo se poziva funkcija ``unos`` kroz koju se unosi broj automobila, a zatim i vrednosti svih polja za svaki automobil. Kada se unesu
svi automobili, poziva se funkcija ``ispis`` koja ispisuje podatke o svakom pojedinačnom automobilu.

Ispis programa:

.. literalinclude:: primeri/automobili-niz-ispis.txt
   :language: none

Učitavanje podataka u program
-----------------------------

Podatke smo do sada učitavali u program kroz standardni ulaz (terminal). Podaci se mogu programu proslediti i kroz drugi izvor,
na primer datoteku. Jedan od načina učitavanja podataka iz datoteke u program jeste preusmeravanjem sadržaja datoteke u program.
Kada se sadržaj datoteke preusmeri u program, onda program taj sadržaj tretira kao da je učitan kroz standardni ulaz (terminal).
Sadržaj datoteke se programu preusmerava korišćenjem operatora "preusmeravanja unosa" ``<`` u terminalu. Tada primer poziva programa
izgleda drugačije::

./a.out < ime_datoteke

gde je ``ime_datoteke`` naziv prethodno kreirane datoteke sa podacima koji će se programu proslediti.

Primer rada niza sa preusmeravanjem unosa
-----------------------------------------

Kod je isti kao primer rada sa nizovima struktura iznad, dok su podaci zapisani u ulaznoj datoteci ``podaci.txt``, čiji je sadržaj:

.. literalinclude:: primeri/podaci.txt
   :language: none

Program se poziva sada tako što mu se preusmeri datoteka ``podaci.txt`` umesto da ih ručno kucamo na terminalu::

./a.out < podaci.txt

Ispis programa:

.. literalinclude:: primeri/automobili-niz-preusmeravanje-ispis.txt
   :language: none

Napomena:

.. literalinclude:: objasnjenja/preusmeravanje.txt
   :language: none
