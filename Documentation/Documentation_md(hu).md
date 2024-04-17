
<span style="font-family:Times new roman;font-size:1.2em">

## Készítette:

Melcher Bálint

melcherbalint@gmail.com

## Feladat:

Gonosz akasztófa **

Szokásos akasztófa játéknak tűnik: a gép gondol egy szót, a felhasználó pedig megpróbálja kitalálni azt olyan módon, hogy betűket tippel. A gonoszság abban rejlik, hogy a gép nem kötelezi el magát egyetlen egy szó mellett sem. A felhasználó tippjei alapján mindig úgy szűkíti a szóba jöhető szavak halmazát, hogy a legkevesebb segítséget adjon a felhasználónak. Pl. a felhasználó idáig eljutott: _k_r, és az „akár” szóra gondol. Ezért tippel egy a-t, mire a gép azt mondja, hogy veszített, mert a szó az „ökör” volt... Közben igazából nem is gondolt egyik szóra sem.

## Bevezetés

Ez a program egy egyszerű kitalálós játékot valósít meg a C programozási nyelv segítségével. A játék során a felhasználó próbálja kitalálni egy véletlenszerűen kiválasztott szót.

## Rendszerkövetelmények

A program futtatásához szükséges a következőket biztosítani:

•  C nyelvű fordító (például GCC)

•  Szöveges fájl, amely tartalmazza a szavakat (words.txt)

## Telepítés és Futtatás

1.  Töltsük le és fordítsuk le a program forráskódját a C fordítóval.

2.  Biztosítsuk, hogy a words.txt fájl a futtatható program mellett legyen.

3.  Indítsuk el a programot.

## Használat

A program elindítása után a felhasználónak lehetősége van többféle parancsot kiadni a játék vezérlésére, valamint tippelni a szóra. A lehetséges parancsok a következők:

•  *quit:* Kilépés a játékból.

•  *help:* Segítség megjelenítése.

•  *new_game:* Új játék kezdése.

•  *give_up:* Feladás, a megadott szó kijelzése és új játék kezdése.

•  *scoreboard:* A legjobb eredmények megtekintése.

A játék kezdetén a program betölti a szavakat a megfelelő fájlból egy láncolt listába, éés kiválaszt közülük egyet teljesen véletlenszerűen, amiről mintázza a „megoldás” szóhosszát.

Amikor a felhasználó tippel egy betűt, a program megnézi a még játékban levő szavakat, és megvizsgálja, hogy melyik(ek)ben fordul elő legkevesebbszer a tippelt betű. Hogyha még van olyan szó játékban, amelyikben nincsen a tippelt betű, a program kiírja, hogy a tipp nem talált, és a játékban levő szavak közül kizárja azokat, amelyekben előfordul a betű. Ha sikerült olyat tippelnünk, amelyik betű az összes bent maradt szóban szerepel, akkor a program kiválasztja azokat a szavakat, amelyekben a legkevesebbszer fordul elő és ezek közül választja ki az egyiket véletlenszerűen, majd beírja a megoldásba a megfelelő hely(ek)re a tippelt betűt. Ezután kizárja a játékból a szavakat, amik nem felelnek meg (amikben több van a betűből, és amikben nem ott van a tippelt betű, ahol a megoldásban). A játék akkor ér véget, ha már csak egyetlen szó van játékban, és annak a játékos minden betűjét kitalálta.

## Adatszerkezetek

A program összesen háromfajta újonnan definiált adatszerkezetet használ, egyet a szavakat tároló láncolt listához és kettőt a dicsőséglista elemeinek beolvasásához, és kiírásához.

A dicsőséglistához azért használtam kettőt, mert így volt a legkézenfekvőbb, hogy sorban tudjam kiírni a dicsőséglista elemeit. Az egyik láncolt lista, a scoreBoard, magát a fájlból beolvasott adatokat tárolja, a beolvasás sorrendjében, a másik láncolt lista, a scoreBoardInOrder mindegyik eleme pedig egy-egy mutatót tárol, amik a sorrendben következő scoreBoard elemre mutatnak.

![kep](chart(hu).png)


## Debugmalloc.h

A projekt mellett megtalálható egy debugmalloc.h nevű fájl, ezt főleg a program írásánál és debugolásánál használtam. Mint a neve is mutatja, fő haszna, hogy ellenőrzi, hogy van-e memóriaszivárgás, illetve a túlindexelést is észleli és jelzi a program lefutása után. A programomban nincsen se memóriaszivárgás, se túlindexelés, mint ahogy azt látni lehet, miután lefutott.




## Fájlok

A program különböző fájlokat használ, amelyek mindegyike egyedi funkciókat lát el:

•  iofunctions.h: Be- és kimeneti funkciók deklarációi.

•  structures.c: A játékhoz szükséges adatszerkezetek definíciói.

•  functions.h: Különböző segédfüggvények deklarációi.

•  debugmalloc.h: Memóriakezelés nyomkövető funkciók.
</span>