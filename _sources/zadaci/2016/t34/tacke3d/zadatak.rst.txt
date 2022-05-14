Tačke u trodimenzionalnom Dekartovom koordinatnom sistemu opisane su preko njihovih koordinata:

* Vrednost na x-osi (realan broj dvostruke preciznosti)
* Vrednost na y-osi (realan broj dvostruke preciznosti)
* Vrednost na z-osi (realan broj dvostruke preciznosti)
* Rastojanje od koordinatnog početka (realan broj dvostruke preciznosti)

Učitati tačke iz ulazne datoteke, potom uraditi sledeće:

    a. Prilikom učitavanja izračunati rastojanje od koordinatnog početka (formula data pre sekcije "Napomene").
       Nakon toga, zapisati koordinate u izlaznu datoteku čije ime se zadaje kao argument komandne linije u sledećem formatu: "(x, y, z), d",
       gde su x, y i z redom koordinate tačke, a d rastojanje od koordinatnog početka.
    b. Pronaći najbližu i najdalju tačku tačku od koordinatnog početka.
       Izračunati njihovu međusobnu udaljenost, potom izračunati zapreminu kocke čija je stranica dužine udaljenosti između tih tačaka.
    c. Izračunati zapreminu kocke čija stranica se unosi u program kao argument komandne linije (može biti realna vrednost).
       Upisati zapreminu iz prethodnog koraka (pod b) i dobijenu zapreminu u izlaznu datoteku, kao zapreminu tela koje bi nastalo kada bi se od veće kocke odsekao deo veličine manje kocke.
       Izlazna datoteka treba da nosi ime koje počinje sa ``"sracunata"/"argument"``, ``"_kocka_minus_"``, ``"sracunata"/"argument"``, ``"_kocka.txt"``,
       gde će prva biti kocka sa većom, a druga kocka sa manjom zapreminom.

Primer poziva programa:

.. code-block:: bash

   ./a.out tacke.txt tacke_formatirano.txt 5

Primer ulazne datoteke ``tacke.txt``:

.. literalinclude:: tacke.txt
   :language: none

Primer izlazne datoteke ``tacke_formatirano.txt``:

.. literalinclude:: tacke_formatirano.txt
   :language: none

Primer izlazne datoteke ``sracunata_kocka_minus_argument_kocka.txt``:

.. literalinclude:: sracunata_kocka_minus_argument_kocka.txt
   :language: none

**Korisne matematičke formule**

*Rastojanje između dve tačke u dvodimenzionalnom koordinatnom sistemu*

Date su dve tačke sa koordinatama :math:`(x_{1}, y_{1})` i :math:`(x_{2}, y_{2})`. Njihovo rastojanje može se odrediti na sledeći način:

.. math::

  d = \sqrt{(x_{1} - x_{2})^2 + (y_{1} - y_{2})^2}

*Zapremina kocke*

Zapremina kocke za kocku stranice :math:`a` računa se na sledeći način:

.. math::
   P = a^3

