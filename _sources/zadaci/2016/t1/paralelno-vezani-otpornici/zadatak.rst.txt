Dat je niz realnih brojeva od maksimalno 20 elemenata.
Učitati ``n`` pozitivnih elemenata, gde svaka vrednost u nizu predstavlja otpornost jednog otpornika izraženu u omima.
Otpornosti mogu biti isključivo pozitivne, realne vrednosti.
Uneti putem standardnog ulaza napon ``U``, koja predstavlja realnu vrednost.
Otpornici su paralelno povezani i predstavljaju električno kolo.
Za paralelno vezane otpornosti iz niza izračunati i ispisati:

a. Ukupnu jačinu struje u električnom kolu.
b. Procentualni udeo struje koji protiče kroz prvi od potrošača u odnosu na ukupnu jačinu struje u električnom kolu.
c. Formirati novi niz u odnosu na ulazni, gde su pojedinačni elementi snage otpornika.

Ispise vrednosti zaokružiti na dve decimale.

Za ulazni niz otpornosti ``[1, 20, 15, 10, 6, 2.5]`` i vrednost napona od ``5`` volti, očekivani ispis na standardnom izlazu je:

.. literalinclude:: ispis.txt
   :language: none

**Korisne matematičke formule**

Otpornost između paralelno vezanih otpornika:

.. math::
   R_{uk} = \frac {1} {\frac {1} {R_1} + \frac {1} {R_2} + ... + \frac {1} {R_n}}

Omov zakon:

.. math::
   I = \frac {U} {R}

Džulov zakon:

.. math::
   P = \frac {U^2} {R}

