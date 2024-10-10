## Šta će se dogoditi ako ukucamo ```cd pjisp``` u terminalu?

1. [x] Ući ćemo u direktorijum pjisp, ukoliko on postoji u direktorijumu gde se trenutno nalazimo
1. [ ] Izlistaće se sve datoteke koje sadrže u svom imenu "pjisp"
   > Za ovakve stvari se koristi komanda ``ls``, na primer ``ls *pjisp*`` će izlistati sve datoteke i direktorijume u trenutnom direktorijumu koje sadrže u sebi "pjisp"
1. [ ] Napraviće se direktorijum pjisp ako ne postoji i ući će se u njega
   > Komanda za pravljenje direktorijuma je ``mkdir`` (skraćeno od "make directory), a ``cd`` za promenu direktorijuma (skraćeno od ``change directory``)
1. [ ] Napraviće se datoteka sa imenom "pjisp"
   > Za ovo se koristi komanda ``touch pjisp``, odnosno, napraviće praznu datoteku sa tim imenom, ukoliko već ne postoji

## Šta je minimalno potrebno da bi se napisani izvorni kod u programskom jeziku C smatrao izvršnim programom?

1. [x] Postojanje pravilno napisane ``main`` funkcije u izvornom kodu
1. [ ] Dovoljno je da se napiše bilo kakva naredba koja pripada C programskom jeziku
   > Izvorni kod bez ``main`` funkcije je biblioteka, koja može biti uključena u druge C programe
1. [ ] Barem jedna ``#include`` direktiva
   > Include direktiva nam služi da možemo da koristimo već napisane funkcionalnosti kako mi ne bismo morali da ih pišemo od nule (npr. funkcija za štampanje na ekran terminala, printf)
1. [ ] Sintaksno tačno napisan izvorni kod
   > Izvorni kod bez ``main`` funkcije je biblioteka, koja može biti uključena u druge C programe

## Kako računar "razume", odnosno, može da izvrši kod napisan u programskom jeziku C?

1. [x] Prevođenjem izvornog koda iz tekstualnog oblika u izvršnu datoteku pomoću programa koji se naziva kompajler
1. [ ] Uz pomoć posebnog programa koji se naziva interpreter, bez dodatnog prevođenja
   > Za čitavu klasu programskih jezika (npr. Pajton) ovo je tačna izjava, ali C se prevodi u binarni oblik pomoću kompajlera pre izvršavanja
1. [ ] Računar direktno razume i izvršava komadne iz datoteke sa izvornim kodom
   > Ovo nije moguće ni za jedan programski jezik, računar razume samo "nule i jedinice"
1. [ ] Pomoću terminala
   > Terminal nam samo pomaže da pokrenemo naš program, ništa više

## Poređaj gradivne elemente programa koji ispisuje "Zdravo svete" u redosledu u kom se pišu u datoteci sa izvornim kodom:

1. #include <stdio.h>
2. int main()
3. {
4. printf("Zdravo, svete!\n");
5. return 0;
6. }

## Da li je sledeći kod sintaksno tačan i šta će se ispisati?

```c
#include <stdio.h>

int main()
{
    int prvi_broj, drugi_broj, proizvod;

    proizvod = prvi_broj * drugi_broj;

    printf("Unesite prvi broj: ");
    scanf("%d", &prvi_broj);

    printf("Unesite drugi broj: ");
    scanf("%d", &drugi_broj);

    printf("Proizvod unetih brojeva je: %d\n", proizvod);

    return 0;
}
```

1. [x] Jeste, ali njegovo ponašanje je nedefinisano
   >  Ponašanje je nedefinisano, jer u artimetičkom izrazu učestvuju promenljive bez prethodno dodeljene vrednosti
1. [ ] Sintaksno je tačan, program množi dva broja i ispisuje rezultat
   > Ovo bi bilo tačno, da množenje ide nakon što su ``prvi_broj`` i ``drugi_broj`` dobili vrednost (posle ``scanf`` naredbi)
1. [ ] Program je sintaksno netačan
   > Kompajlirati program. Ukoliko ``gcc`` naredba ne pokaže nikakav ispis i napravi datoteku ``./a.out``, program je sintaksno tačan
1. [ ] Sintaksno je tačan, ali će se preskočiti unos brojeva prilikom izvršavanja
   > Ovo nije tačno, jer se sve naredbe izvršavaju redom u ``main`` funkciji, ovako kako je program napisan