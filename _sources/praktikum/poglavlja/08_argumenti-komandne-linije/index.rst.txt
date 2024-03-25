Argumenti komandne linije
=========================

Podeli svoje utiske o poglavlju na anketi `OVDE <https://docs.google.com/forms/d/1hmqQGSA6yqIBEBoK_4nKHm3qV2cvQsszgNvieOi9APU>`_.

Preduslovi za rad:

.. literalinclude:: objasnjenja/preduslovi-za-rad.txt
   :language: none

Predstavljaju vrednosti koje se prosleđuju programu prilikom poziva.
Primeri ovakvih poziva su uveliko poznati iz prakse, jer skoro svaka komanda u terminalu prima argumente komandne linije.
Na primer::

  mkdir direktorijum
  gcc program.c

U primeru ``direktorijum`` i ``program.c`` predstavljaju vrednosti koje program prima spolja.
Način kako se prihvataju ove vrednosti u programskom jeziku C je tako što se main funkcija proširi sa dodatnim parametrima, koji se često tradicionalno nazivaju ``argc`` i ``argv``.
``argc`` predstavlja broj, a ``argv`` konkretne vrednosti argumenata.

Napomena:

.. literalinclude:: objasnjenja/prvi-argument.txt
   :language: none

Primer programa
---------------

Dat je primer programa koji kao vrednosti argumenata komandne linije prihvata ime i visinu osobe:

.. literalinclude:: primeri/arg-ime-visina.c
   :linenos:

Primer poziva programa kada ima previše argumenata:

.. literalinclude:: primeri/arg-ime-visina-previse-argumenata-poziv.txt
   :language: none

Ispis programa kada ima previše argumenata:

.. literalinclude:: primeri/arg-ime-visina-previse-argumenata-ispis.txt
   :language: none

Primer regularnog poziva programa:

.. literalinclude:: primeri/arg-ime-visina-poziv.txt
   :language: none

Ispis programa:

.. literalinclude:: primeri/arg-ime-visina-ispis.txt
   :language: none

Napomena:

.. literalinclude:: objasnjenja/argv.txt
   :language: none

Jedna od vrednosti argumenata komandne linije predstavlja string, koji označava visinu osobe.
Pošto nije moguće raditi aritmetičke, logičke ili relacione izraze sa stringovima, potrebno je izvršiti konverziju u realni tip, u ovom slučaju.
To se vrši pomoću funkcije ``atof``. Ukoliko je potrebno konvertovati string u celobrojnu vrednost, koristi se funkcija ``atoi``.
Obe se nalaze u biblioteci ``stdlib.h``.