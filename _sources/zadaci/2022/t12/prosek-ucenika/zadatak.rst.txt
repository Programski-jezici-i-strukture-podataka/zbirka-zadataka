Razredni starešina unosi ocene učenika na kraju godine u đačku knjižicu.
Napisati program koji pomaže pri računanju proseka i deskriptivne ocene učenika.

Podaci sa tastature se unose u string maksimalne veličine 30 karaktera.
Ocene se unose kao jedan string, gde su zarezom i proizvoljnim brojem razmaka razdvojene pojedinačne ocene, koje mogu imati vrednost između 1 i 5.
Ocene se iz stringa prebacuju u niz celobrojnih vrednosti maksimalne veličine 10 elemenata.
Ukoliko se u stringu pojavi karakter koji nije cifra od 1 do 5, zarez ili razmak, kao i ukoliko je broj ocena veći od zadate veličine celobrojnog niza, ispisati poruku o grešci i zaustaviti dalju obradu stringa.
Radi jednostavnosti, računati da je string uvek formata jedan karakter (na primer, ocena), pa proizvoljni broj zareza i razmaka, pa drugi karakter, pa opet proizvoljni broj zareza i razmaka itd.

U slučaju uspešne obrade unetog stringa, od dobijenog niza celobrojnih brojeva izračunati srednju vrednost, na osnovu koje se formira deskriptivna ocena (odrediti minimalnu dimenziju stringa u koji mogu da stanu sve navedene vrednosti):

* Od 4.50, uključujući i 4.50, do 5.00, učenik je ``odlican``
* Od 3.50, uključujući i 3.50, do 4.50, učenik je ``vrlo dobar``
* Od 2.50, uključujući i 2.50, do 3.50, učenik je ``dobar``
* Od 1.50, uključujući i 1.50, do 2.50, učenik je ``dovoljan``
* Za sve pozitivne vrednosti manje od 1.50, učenik je ``nedovoljan``

Program treba da ispisuje celobrojni niz ocena, prosek učenika i deskriptivnu ocenu.

Primer rada programa:

.. literalinclude:: ispis-programa.txt
   :language: none

Primer rada programa u slučaju nevalidnog unosa sa tastature:

.. literalinclude:: ispis-programa-nevalidan-unos.txt
   :language: none

Primer rada programa u slučaju unosa više od dozvoljenog broja ocena:

.. literalinclude:: ispis-programa-previse-ocena.txt
   :language: none

Primer rada programa u slučaju unosa samo zareza i razmaka:

.. literalinclude:: ispis-programa-bez-ocena.txt
   :language: none

