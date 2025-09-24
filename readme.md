# ILGIO PATIKROS TESTAS

|             Failas            |                               Hash                             |
|-------------------------------|----------------------------------------------------------------|
| Vieno_simobolio.txt           |d406b4e43414719f79a7f7c02087c792734a43aab6e7f4352dcbc016c1b1abc4|
| >1000_simboliu.txt            |4bea6b625d8f29153c9016f7ee658edf1d33ff3da83390fb7ac50ea77a1673cd|
| >1000_skirtingu_simboliu.txt  |aa5474d37ddb317098d631c7d113e20a3c9e8289bad29a6242f96e499d5dd30b|
| failas_empty.txt              |0d7e13c85d36069fd5e05d9b20873e1ad0ec20aa49d7fd698e9ca24c54067e5c|


# DETERMIŠKUMO PATIKRA

|             Failas            |                               Hash                              |
|-------------------------------|-----------------------------------------------------------------|
| failas_empty.txt              | 0d7e13c85d36069fd5e05d9b20873e1ad0ec20aa49d7fd698e9ca24c54067e5c|
| failas_empty.txt.             | 0d7e13c85d36069fd5e05d9b20873e1ad0ec20aa49d7fd698e9ca24c54067e5c|

# KOLIZIJŲ TESTAS

|         Porų Skaičius         |                       Kolizijų skaičius                         |
|-------------------------------|-----------------------------------------------------------------|
| 10                            |                               0                                 |
| 100                           |                               0                                 |
| 500                           |                               0                                 |
| 1000                          |                               0                                 |

### NUOTRAUKOS PATVIRTINIMUI

![alt text](<Screenshot 2025-09-19 at 15.23.00.png>)
![alt text](<Screenshot 2025-09-19 at 15.23.13.png>)
![alt text](<Screenshot 2025-09-19 at 15.23.26.png>)
![alt text](<Screenshot 2025-09-19 at 15.27.14.png>)

# LAVINOS EFEKTO TESTAS

![alt text](<Screenshot 2025-09-20 at 15.29.28.png>)

# NEGRIZTAMUMO TESTAS

![alt text](<Screenshot 2025-09-23 at 01.26.29.png>)

# Pseudo-kodas

```
1: procedure HashFunction(text, HASH_SIZE)
2:     hash[0..HASH_SIZE-1] ← 0
3:     for i ← 0 to |text|-1 do
4:         hash[i mod HASH_SIZE] ← hash[i mod HASH_SIZE] XOR text[i]
5:         if text[i] mod 2 = 0 then
6:             hash[(i*3) mod HASH_SIZE] ← hash[(i*3) mod HASH_SIZE] + 2
7:         end if
8:         if text[i] mod 3 = 0 then
9:             hash[(i*2) mod HASH_SIZE] ← hash[(i*2) mod HASH_SIZE] + 3
10:        else
11:            hash[(i*5) mod HASH_SIZE] ← hash[(i*5) mod HASH_SIZE] + 4
12:        end if
13:        if hash[i mod HASH_SIZE] > 128 then
14:            hash[i mod HASH_SIZE] ← 255 - hash[i mod HASH_SIZE]
15:        end if
16:        if i mod 5 = 0 then
17:            hash[(i*13) mod HASH_SIZE] ← hash[(i*13) mod HASH_SIZE] + (text[i] mod 2) + 1
18:        end if
19:        temp ← hash[i mod HASH_SIZE] >> 4
20:        hash[i mod HASH_SIZE] ← (hash[i mod HASH_SIZE] << 4) OR temp
21:    end for
22:
23:    for round ← 0 to 7 do
24:        for i ← 0 to HASH_SIZE-1 do
25:            hash[i] ← hash[i] XOR (hash[(i+7) mod HASH_SIZE] 
26:                        + hash[(i+13) mod HASH_SIZE]) XOR (i*31)
27:            shift ← (3 + round) mod 8
28:            hash[i] ← (hash[i] << shift) OR (hash[i] >> (8 - shift))
29:            hash[i] ← (hash[i] * 31 + round*17) mod 256
30:        end for
31:    end for
32:
33:    out ← ""
34:    for i ← 0 to HASH_SIZE-1 do
35:        c ← hash[i]
36:        out ← out + hexmap[c >> 4] + hexmap[c AND 0x0F]
37:    end for
38:    return out
39: end procedure

```

# ISVADOS 

- Funkcija generuoja vienodo ilgio hash, nepriklausomai nuo įvesties dydžio.
- Funkcija yra deterministinė – ta pati įvestis visada duoda tą pačią išvestį.
- Atlikus kolizijų testą iki 1000 porų, kolizijų nerasta.
- Hash pasižymi avalanche efektu – pakeitus įvestį, išvestis stipriai pasikeičia:
-- bitų lygmenyje ~32.9% skirtumas,
-- hex lygmenyje ~84.3% skirtumas.
- Funkcija yra praktiškai vienakryptė (negrįžtamumas pavyko).
- Hiding testas parodė, kad hash reikšmės išlieka unikalios per daug iteracijų.
- Puzzle-friendliness testas rodo, kad funkcijoje yra tam tikro atsitiktinumo.
### Bendra išvada:
Hash funkcija turi pagrindines reikiamas savybes: fiksuotas ilgis, determinizmas, mažai kolizijų, avalanche efektas ir vienakryptiškumas. Ji tinkamai atlieka savo paskirtį, nors bitų lygmenyje avalanche efektas nėra idealus (toliau tobulinant galima jį priartinti prie 50%).


# AI IRANKIS BUVO NAUDOTAS
- Lavinos teste, kad padetu suprasti kaip ji atlikti, kaip pasiskaiciuoti skirtumas, maximuma plius stackOverflow irgi buvo pajungtas
- Dalinai pagalbai negriztamumo patikrai
- Kai kuriu string generavimui(vieno simbolio keitime)

