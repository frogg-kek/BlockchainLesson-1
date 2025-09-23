## AI - TOBULINTA VERSIJA

## KOLIZIJOS, LAVINOS IR NEGRIZTAMUMO TESTAS

![alt text](<Screenshot 2025-09-23 at 12.33.26.png>)

## HASH PALYGINIMAS (Mano ir AI)

|             Zodis             |                                Hash                             |
|-------------------------------|-----------------------------------------------------------------|
| ervinas(Mano)                 | 815h1h9hfhbg5h81c061fg9h3g01c0a13hfg819h419gc0fg3h21a041c0203hc1|
| ervinas(AI)                   | 20a593791c471ca9aa81ad904a1366ee74472e5f24167d9e75985b06b1205c91|

# ISVADOS APIE AI GENERUOTA

### Kolizijos
Funkcija rodo stabilumą mažesniame duomenų rinkinyje.
### Avalanche efektas
Bitų lygmenyje: Min 22.66%, Max 42.77%, Vidurkis ~32.96%.
Hex lygmenyje: Min 76.56%, Max 100%, Vidurkis ~93.68%.
Rezultatai rodo, kad funkcija sugeba sukurti labai stiprų pasikeitimą hex lygmenyje, bet bitų lygmenyje efektas šiek tiek silpnesnis (nėra arti 50%).
### Negrįžtamumas
Bandymas atkurti tekstą iš hash nepavyko → funkcija yra vienakryptė.
### Hiding testas
Hash reikšmės liko unikalios per 1000 iteracijų → nėra paprastų pasikartojimų.
### Puzzle-friendliness
Nepavyko aptikti per 100000 iteracijų → rodo, kad funkcija neturi tokio „uždavinio sprendimo atsitiktinumo“ lygio kaip pirmoji hash funkcija.

## PALYGINIMAS ABIEJU

### Kolizijos: 
Abi funkcijos nerodė kolizijų testuotais atvejais → rezultatas panašus.
### Avalanche efektas:
Pirmoji funkcija → Bitų lygmenyje vid. 32.9%, Hex 84.3%.
Antroji funkcija → Bitų lygmenyje vid. 32.96%, Hex 93.7%.
Antroji funkcija geriau pasirodė hex lygmenyje, bet bitų lygmenyje abi panašios.
### Negrįžtamumas: 
Abiejose vienakryptiškumas pavyko.
### Hiding testas: 
Abi išlaikė testą.
### Puzzle-friendliness:
Pirmoji funkcija rado atsitiktinumą (i=16).
Antroji funkcija jo nerado net per 100k iteracijų.