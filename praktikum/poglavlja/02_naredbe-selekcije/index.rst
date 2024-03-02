Naredbe selekcije
==================

Podeli svoje utiske na anketi `OVDE <https://docs.google.com/forms/d/1wRkDvN8qkso6HSiHvfHjmjozk-AxyKE0m_oSYCabb-M>`_.

Preduslovi za rad::

  Poznavanje osnovne strukture C programa i funkcija za rad sa standardnim ulazom/izlazom.

Naredbe selekcije omogućuju da kontrolišemo tok izvršavanja programa.
Ukoliko želimo da se određeni deo koda ne izvršava uvek, već samo pod određenim uslovima, koristimo naredbe selekcije.
Deo koda koji je uslovljen naredbom selekcije će se izvršiti samo ukoliko je postavljeni uslov ispunjen.

Napomena::

  U programskom jeziku C se kao tačno podrazumeva sve što je različito od 0, dok je sve sto ima vrednost 0 netačno.

if-else iskaz
-------------

Osnovna forma ``if-else`` iskaza je::

  if(izraz)
    naredba_1
  else
    naredba_2

Ukoliko je izraz u zagradi tačan, izvršiće se ``naredba_1``. Ako je izraz netačan, izvršiće se ``naredba_2``.

Dat je primer programa gde imamo promenljivu ``x`` čija je vrednost 5 i promenljivu ``y`` čija je vrednost 3.
U if-u proveravamo da li je ``x`` veće od ``y``. Ako jeste, ispisaćemo ``X je veće``, a ako nije ispisaćemo
``Y je veće``:

.. literalinclude:: primeri/if-else.c
   :linenos:

Ispis ovog programa je:

.. literalinclude:: primeri/if-else-ispis.txt
   :language: none

Pitanje::

  Šta će se desiti u slučaju da x i y imaju istu vrednost?

Ispis ovog programa kada su x i y iste vrednosti je (u kodu smo prethodno promenili da su vrednosti i ``x`` i ``y`` 3):

.. literalinclude:: primeri/if-else-jednaki-ispis.txt
   :language: none


Napomena::

  Izraz if(x = 2) će uvek biti tačan zato što u ovom slučaju promenljivoj x dodeljujemo vrednost 2 i to je uvek moguće i tačno.
  Kada zelimo da poredimo bilo koje 2 vrednosti, potrebno je da koristimo == operator. izraz if(x == 2) će biti tačan samo onda
  kada je vrednost promenljive x postavljena na 2 pre ove provere.
  Ako želimo da proverimo da li je vrednost x različita od 2, koristićemo != operator.

if-else-if iskaz
----------------

U primeru iznad smo videli da nije pokriven slučaj kada ``x`` i ``y`` imaju istu vrednost. Da bismo pokrili i njega,
potrebno je da proširimo if-else iskaz. Proširena forma je ``if-else-if`` iskaz::

  if(izraz_1)
    naredba_1
  else if(izraz_2)
    naredba_2
  else if(izraz_3)
    naredba_3
    ...
  else
    naredba_n

Ukoliko je ``izraz_1`` tačan, izvršiće se ``naredba_1``, ukoliko je ``izraz_2`` tačan, izvršiće se ``naredba_2``, ukoliko je ``izraz_3``
tačan, izvršiće se ``naredba_3`` itd. 
Kod ovog iskaza možemo imati neograničen broj provera. 
Ukoliko nijedan izraz nije tačan, izvršiće se naredba_n koja je u else delu iskaza.

Dat je primer programa gde imamo promenljivu ``x`` čija je vrednost 6 i promenljivu ``y`` čija je vrednost 6.
U if-u proveravamo da li je x veće od y. Ako jeste, ispisaćemo ``X je veće``. U else-if-u proveravamo
da li su jednaki. Ako jesu, ispisaćemo ``Jednaki su``. Ukoliko x nije veće i nisu jednaki, znamo da je sigurno y veće.
Else iskaz će biti ispis ``Y je veće``.

.. literalinclude:: primeri/if-else-if.c
   :linenos:

Ispis ovog programa je:

.. literalinclude:: primeri/if-else-if-ispis.txt
   :language: none

Napomena::

  U slučaju if-else, kao i if-else-if iskaza, uvek će se izvršiti samo jedna naredba. Ukoliko je neki izraz tačan,
  izvršiće se samo naredba u okviru tog izraza. Ukoliko nijedan izraz nije tačan, izvršiće se naredba u okviru
  else iskaza, ako je on prisutan.

Ukoliko je potrebno izvršiti više naredbi u okviru bilo kog od ovih iskaza (if, else-if, else) potrebno je sve naredbe
smestiti u vitičaste zagrade ``{}``. U suprotnom, kompajler će prijaviti grešku ukoliko je dodatna naredba napisana nakon ``if`` naredbe.
Ako je dodatna naredba napisana nakon ``else``, program će se uredno kompajlirati. 
Zbog toga, preporuka je stavljati vitičaste zagrade i u slučaju jedne naredbe.

Deo iskaza ``else`` nije obavezan i može da se desi da postoji ``if``, kao i ``if else`` bez ``else`` iskaza, ali
obrnuto ne važi.

Dat je primer gde imamo promenljivu ``godine`` i promenljivu ``plata``, gde se od korisnika traži da unesu njihove vrednosti.
Proveravamo za unete godine i platu kreditnu sposobnost:

 * Ukoliko je vrednost godina do 20 ili je plata do 70 000, moguće je podići kredit do 100 000
 * Ukoliko je vrednost godina do 50 ili je plata do 120 000, moguće je podići kredit do 180 000
 * Ukoliko je vrednost godina preko 50, ne može se podići kredit zbog starosne granice

.. literalinclude:: primeri/if-else-if-sa-vise-promenljivih.c
   :linenos:

Ispis ovog programa je:

.. literalinclude:: primeri/if-else-if-sa-vise-promenljivih-ispis.txt
   :language: none

U ovom primeru će uslov prvog if iskaza biti zadovoljen. Godine su 25 i uslov za godine za prvi if nije zadovoljen, ali
kod ovog if iskaza mi imamo proveru 2 uslova gde nam je dovoljno da je samo jedan uslov tačan kako bi ceo izraz bio tačan.
Drugi deo uslova kaže da plata mora biti manja manja od 70 000, što se uklapa sa zadatom vrednošću plate koja je 50 000, pa
je zato ispis u ovom primeru ``Moguce je podici kredit do 100000``.

Ispis ovog programa u slučaju kad je broj godina veći od 50:

.. literalinclude:: primeri/if-else-if-sa-vise-promenljivih-vise-od-50-godina-ispis.txt
   :language: none

Pitanje::

  Kako bismo ispravili ovaj program da onemogućimo korisniku da unese broj godina manji od 18?

Napomena::

  U prethodnom primeru korišćen je logički operator "ILI", koji se u programskom jeziku C predstavlja preko ||.
  Njegovo ponašanje isto je kao i kod matematičkog operatora, odnosno, ukoliko je jedan od operanada tačan, 
  izraz će biti logički tačan. Takođe, postoji i logički operator "I". On se navodi sa &&. Negacija se navodi kao !.

Ternarni operator
-----------------

Funkcioniše isto kao if-else iskaz, zapisan u jednoj liniji. Osnovna forma je::

  izraz ? naredba_1 : naredba_2

Ukoliko je izraz tačan, izvršiće se ``naredba_1``. Ako je izraz netačan, izvršiće se ``naredba_2``.

Dat je primer programa gde imamo promenljivu ``x`` čija je vrednost 3 i promenljivu ``y`` čija je vrednost 5.
U izrazu proveravamo da li je ``x`` veće od ``y``. Ispisaćemo veći od ta dva broja:

.. literalinclude:: primeri/ternarni.c
   :linenos:

Ispis ovog programa je:

.. literalinclude:: primeri/ternarni-ispis.txt
   :language: none

Napomena::

  Ovaj primer je mogao biti urađen preko if-else iskaza. Ternarni operator pogodan je u situacijama kada postoji promenljiva 
  koja treba da dobije vrednost na osnovu nekog uslova. Da je ovo bilo napisano preko if-else, rešenje bi imalo barem 3 linije
  više. Ternarni izraz je u tim situacijama koncizniji.

Switch iskaz
------------

Switch iskaz proverava dati izraz i u zavisnosti od vrednosti izraza izvršava naredbe onog case bloka čija je vrednost
jednaka vrednosti izraza. Ovaj iskaz je veoma sličan if-else-if iskazu i može se koristiti kao njegova zamena kada je potrebno
porediti neku vrednost ili izraz sa više celobrojnih vrednosti. Osnovna forma je::

  switch(izraz)
  {
  case vrednost_1:
    naredbe_1
  case vrednost_2:
    naredbe_2
  ...
  default:
    naredbe_n
  }

Napomena::

  Vrednost u ovom iskazu mora biti celobrojna (int ili char). Može postojati 1 ili više case iskaza. Vrednost svakog
  case-a mora biti jedinstvena. default sekcija je opciona.

Napomena::

  Na kraju svakog case-a, treba staviti naredbu break.
  Ova naredba služi da se izađe iz switch-case iskaza kada se izvrši neki case. Ukoliko se naredba break ne stavi,
  izvršavaće se naredbe u okviru preostalih case iskaza.

Dat je primer programa gde imamo promenljivu ``dan`` čiju vrednost korisnik unosi preko tastature (standardnog ulaza).
U switch deo postavljamo promenljivu dan čiju ćemo vrednost proveravati.
Ukoliko je vrednost promenljive dan 1, ispisaće se ``Ponedeljak``, ukoliko je 2 ``Utorak``, itd. Ukoliko vrednost promenljive nije između 1 i
7, neće se biti izabran nijedan case, već će se izvršiti sekcija default.

  .. literalinclude:: primeri/switch-case.c
     :linenos:

  Ispis ovog programa je:

  .. literalinclude:: primeri/switch-case-ispis.txt
     :language: none
