Stringovi
==============

Podeli svoje utiske o poglavlju na anketi `OVDE <https://docs.google.com/forms/d/1iXfxZLclQg9YCmT7JQCDbGx4YLamGUxeZa86ilU1iE8>`_.

Preduslovi za rad:

.. literalinclude:: objasnjenja/preduslovi-za-rad.txt
   :language: none

Char tip
--------

Pored celih i realnih brojeva, moguće je napraviti promenljive koje sadrže karaktere - slova, cifre, simbole... Tip promenljive se označava sa ``char``, opseg ovog tipa je od 0 do 255, odnosno od -128 do 127 ako je tip ``signed``. Format specifikator za karaktere je: ``%c``

.. literalinclude:: objasnjenja/ascii.txt
   :language: none

Karakteri se označavaju koristeći jednostruke navodnike, kao npr:

  'a', 'A', '?', '/n', '7'
	
Moguće je rukovati karakterima direktno, ili preko odgovarajuće celobrojne vrednosti. Primer koji uneto malo slovo pretvara u veliko:

.. literalinclude:: primeri/char.c
   :linenos:
   
U programu se koristi do-while petlja da bi se osigurao unos malog slova. Mala slova se nalaze jedna do drugih između 97 i 122 u ASCII tabeli, te je moguće proveriti da li je uneti karakter manji od 'a', odnosno veći od 'z'. Isto bi bilo proveriti da li je uneti karakter van opsega 97-122. O funkciji __fpurge više kasnije. Malo slovo je moguće pretvoriti u veliko oduzimanjem 32 od vrednosti karaktera. Kao primer, malo 'c' odgovara vrednosti 99, a veliko 'C' vrednosti 67. Ispis ovog programa je:

.. literalinclude:: primeri/char-ispis.txt
   :language: none
   
Stringovi
---------
   
Često radimo sa nizovima karaktera, koji se nazivaju ``stringovi``. Imaju posebne osobine, glavna od kojih je postojanje terminalnog karaktera ``'\0'``, koji označava kraj stringa. Zbog ovog karaktera, najčešće se za zadatu dužinu stringova uzima niz za 1 duži od najvećeg dozvoljenog broja karaktera.

Stringovi se mogu navesti format specifikatorom ``%s``, te ``scanf`` može direktno da učita ceo string (za razliku od npr. nizova celih brojeva, gde se učitavanje vrši u petlji). Funkcija ``scanf`` učitava samo jednu reč (sve do praznog karaktera između dve reči, novog reda...). Za razliku od ostalih tipova, kod stringova (pošto su stringovi nizovi te navođenjem imena dobija se adresa) ne treba navesti ``&`` pre imena stringa.

Pored ``scanf``, ceo red moguće je učitati funkcijom ``fgets`` koja prima 3 argumenta: ime stringa u koji se učitava, najveću moguću dužinu tog stringa i (za potrebe ove lekcije) ``stdin``, što predstavlja mesto sa kog se podaci učitavaju (unos sa terminala).

Napomena:

.. literalinclude:: objasnjenja/fpurge.txt
   :language: none
  
.. literalinclude:: primeri/string1.c
   :linenos:

Najveća dužina stringa mora da bude za 1 veća od željene, zbog terminalnog karaktera. U prvi string će biti učitana samo prva reč, dok će u drugi biti učitan ceo red uključujući i novi red dodat kada se string prosleđuje. Ovaj karakter (znamo da je na kraju stringa, tj. element indeksa za 1 manjeg od dužine) menjamo terminalnim karakterom.

.. literalinclude:: primeri/string1-ispis.txt
   :language: none

Uglavnom se koriste već implementirane funkcije za rad sa stringovima, najčešće su:

- ``strlen`` - računa dužinu stringa, do terminalnog karaktera
- ``strcpy`` - kopira drugi string u prvi
- ``strcat`` - nalepi drugi string na kraj prvog
- ``strcmp`` - poredi dva stringa
	
Pošto su stringovi ujedno i nizovi, ne radi ``str1 = str2`` niti poređenje sa ``str1 == str2``, zato postoje ``strcpy`` i ``strcmp``. Ove funkcije se sve nalaze u biblioteci ``string.h``, detaljnije o njima se može saznati ``man`` komandom u terminalu i imenom željene funkcije, npr::

  man strcpy
  
Program koji menja velika slova u stringu u mala i obrnuto:

.. literalinclude:: primeri/string2.c
   :linenos:
   
Veliko slovo se menja u malo dodavanjem 32, obrnuto oduzimanjem 32. U petlji se koristi continue da bi se kada je slovo promenjeno iz velikog u malo, ne bi ponovo uvećalo nego se samo jednom promenilo.

.. literalinclude:: primeri/string2-ispis.txt
   :language: none
   
Stringovi, kao i nizovi, imaju vezu sa pokazivačima. Primer ispod obrće string koristeći pokazivače:

.. literalinclude:: primeri/string3.c
   :linenos:
   
Pokazivači se postavljaju na početak i kraj stringa, njihove vrednosti se zamenjuju i pokazivači se pomeraju ka sredini stringa unutar petlje. Primer ispisa programa je:

.. literalinclude:: primeri/string3-ispis.txt
   :language: none

