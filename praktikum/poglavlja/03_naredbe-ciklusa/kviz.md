## Razlika između naredbi selekcije i naredbi ciklusa je?

1. [x] Kod naredbi selekcije će biti izabran deo koda koji će se izvršiti, dok naredbe ciklusa imaju mogućnost izvršavanja određenog koda više puta
1. [ ] Naredbe selekcije biraju kod koji se izvršava, dok naredbe ciklusa ne utiču na redosled naredbi tokom izvršavanja programa
1. [ ] Naredbe ciklusa biraju kod koji se izvršava, dok naredbe selekcije izvršavaju određeni kod više puta
1. [ ] Razlika je isključivo u korišćenim ključnim rečima, u ponašanju nema znatnih razlika

## Kako bi glasila naredba u programskom jeziku C "dok je vrednost a veća od 0 i vrednost suma je manja od 50"?

1. [x] ``while (a > 0 && suma < 50)``
    > while -> "dok", a > 0 -> "vrednost a veća od 0", && -> logičko "I", suma < 50 -> "suma je manja od 50"
1. [ ] ``if (a > 0 && suma < 50)``
    > Iako je sintaksno tačno, ne zadovoljava rečenicu jer ona ukazuje na potrebno ponavljanje u naredbi.
1. [ ] ``for (a = 0; a > 0 || suma < 50; a++)``
    > Ova naredba nije dobra iz više razloga. Prvi je zato što a počinje od 0, što znači da odmah ne bi bila tačna i ciklus se ne bi nijednom izvršio, da je ostatak napisan kako treba. Drugi problem je što je napisano logičko "ILI" umesto "I" u izrazu.
1. [ ] ``switch (a > 0 && suma < 50)``
    > Sintaksno nije tačno, izraz u switch naredbi mora biti konstantan. Switch takođe nije naredba ciklusa, nego selekcije.

## Koja će biti vrednost promenljive broj ako je početna 16, odnosno 12?

```c
#include <stdio.h>

int main()
{
   int broj;

   printf("Unesite broj: ");
   scanf("%d", &broj);

   while(broj / 2 != 0)
   {
      if(broj % 3 == 0)
      {
         break;
      }

      broj /= 2;
   }

   printf("Broj%d\n", broj);

   return 0;
}
```

1. [x] ``1 i 12``
    > Za broj 16, ``while`` ciklus će se izvršavati dokle god je deljivo sa 2 (8, 4, 2), a za 12 će odmah ispasti iz ``while`` ciklusa, jer je deljivo sa 3
1. [ ] ``16 i 12``
1. [ ] ``1 i 1``
1. [ ] ``1 i 6``

## Koji izraz je potrebno da do-while naredba sadrži kako bi korisnik morao isključivo da unese neparan broj deljiv sa 7?

```c
#include <stdio.h>

int main()
{
   int broj;

   do
   {
      printf("Unesite broj: ");
      scanf("%d", &broj);
   } while(<izraz>);

    return 0;
}
```

1. [x] ``broj % 2 == 0 || broj % 7 != 0``
1. [ ] ``broj % 2 == 0 && broj % 7 != 0``
    > Ovaj izraz će pustiti korisnika za svaki neparan broj koji nije deljiv sa 7 (3, 5, 9 itd.), što ne bi smelo da se desi.
1. [ ] ``broj % 2 != 0 && broj % 7 == 0``
    > Ovaj izraz će vratiti korisnika za brojeve 14, 28 itd, odnosno parne deljive sa 7, ali će pustiti za 7 i 21 itd, odnosno neparne deljive sa 7, jer će u tom slučaju izraz biti logički netačan.
1. [ ] ``broj % 2 != 0 || broj % 7 != 0``
    > Ovaj izraz će pustiti korisnika ukoliko je broj paran i deljiv sa 7, što nije ono što je traženo.