Dat je niz realnih brojeva od maksimalno 20 elemenata.
Učitati ``n`` pozitivnih elemenata, gde svaka vrednost u nizu predstavlja otpornost jednog otpornika izraženu u omima.
Otpornosti mogu biti isključivo pozitivne, realne vrednosti.
Uneti putem standardnog ulaza vrednost struje ``I``, koja predstavlja realnu vrednost.
Otpornici su serijski povezani i predstavljaju električno kolo kroz koje protiče struja ``I``.
Za serijski vezane otpornosti iz niza izračunati i ispisati:

a. Ukupnu vrednost napona nad električnim kolom.
b. Procentualni udeo napona nad najvećim potrošačem u odnosu na ukupan napon u kolu.
c. Formirati novi niz u odnosu na ulazni, gde su pojedinačni elementi snage otpornika.

Ispise vrednosti zaokružiti na dve decimale.

Za ulazni niz otpornosti ``[1, 20, 15, 10, 6, 2.5]`` i vrednost struje od ``0.5`` ampera, očekivani ispis na standardnom izlazu je:

.. literalinclude:: ispis.txt
   :language: none

**Korisne matematičke formule**

Ukupna otpornost serijski vezanih otpornika:

.. math::
   R_{uk} = R_1 + R_2 + ... + R_n

Omov zakon:

.. math::
   U = RI

Džulov zakon:

.. math::
   P = RI^2

