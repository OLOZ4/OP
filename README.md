## Pirma strategija 
*Bendro studentai konteinerio (vector, list ir deque tipų) skaidymas (rūšiavimas) į du naujus to paties tipo konteinerius: "vargšiukų" ir "kietiakų". Tokiu būdu tas pats studentas yra dvejuose konteineriuose: bendrame studentai ir viename iš suskaidytų (vargšiukai arba kietiakai). Nesunku pastebėti, kad tokia strategija yra neefektyvi užimamos atminties atžvilgiu (įsitikinkite tuo!), tačiau šiame žingsnyje svarbiausia yra patyrinėti, kaip programos veikimo sparta priklauso nuo konteinerio tipo?*

# Vektorius

**1000**
| Bandymo numeris | Nuskaitymas | Rūšiavimas| Skrstymas į konteinerius | Bendras laikas |
|-----------------|-------------|-----------|--------------------------|----------------|
|1|0.0157612|0.00297164|0.00109384|0.035876|
|2|0.00500573|0.00170572|0.0869301|0.0991567|
|3|0.00541565|0.00165097|0.0409119|0.0534136|
|4|0.00515032|0.00174594|0.0447787|0.0571739|
|5|0.00514549|0.00164459|0.042081|0.0553084|
|Vid.|-|-|-|0.06018572|

**10000**
| Bandymo numeris | Nuskaitymas | Rūšiavimas| Skrstymas į konteinerius | Bendras laikas |
|-----------------|-------------|-----------|--------------------------|----------------|
|1|0.0465477|0.0218913|0.00751638|0.0835118|
|2|0.0387483|0.0188099|0.00303522|0.103406|
|3|0.0505536|0.0180376|0.00315221|0.104323|
|4|0.0509217|0.0185617|0.00295333|0.107807|
|5|0.0442961|0.0196937|0.00486322|0.101467|
|Vid.|-|-|-|0.10010296|

**100000**
| Bandymo numeris | Nuskaitymas | Rūšiavimas| Skrstymas į konteinerius | Bendras laikas |
|-----------------|-------------|-----------|--------------------------|----------------|
|1|0.294555|0.205679|0.0498312|0.555141|
|2|0.248458|0.207416|0.0480726|0.509017|
|3|0.250679|0.206326|0.0411719|0.503209|
|4|0.258195|0.206838|0.0394575|0.512261|
|5|0.242133|0.20773|0.040613|0.495552|
|Vid.|-|-|-|0.515036|

**1000000**
| Bandymo numeris | Nuskaitymas | Rūšiavimas| Skrstymas į konteinerius | Bendras laikas |
|-----------------|-------------|-----------|--------------------------|----------------|
|1|2.01091|3.13237|0.592756|5.74805|
|2|2.03059|2.76148|0.377035|5.1739|
|3|1.96574|2.76007|0.368503|5.09911|
|4|1.95757|2.75842|0.364877|5.08575|
|5|1.95784|2.78063|0.369691|5.11322|
|Vid.|-|-|-|5.244066|

**10000000**
| Bandymo numeris | Nuskaitymas | Rūšiavimas| Skrstymas į konteinerius | Bendras laikas |
|-----------------|-------------|-----------|--------------------------|----------------|
|1
|2
|3
|4
|5
|Vid.|-|-|-||

# Listas

**1000**
| Bandymo numeris | Nuskaitymas | Rūšiavimas| Skrstymas į konteinerius | Bendras laikas |
|-----------------|-------------|-----------|--------------------------|----------------|
|1
|2
|3
|4
|5
|Vid.|-|-|-||

**10000**
| Bandymo numeris | Nuskaitymas | Rūšiavimas| Skrstymas į konteinerius | Bendras laikas |
|-----------------|-------------|-----------|--------------------------|----------------|
|1
|2
|3
|4
|5
|Vid.|-|-|-||

**100000**
| Bandymo numeris | Nuskaitymas | Rūšiavimas| Skrstymas į konteinerius | Bendras laikas |
|-----------------|-------------|-----------|--------------------------|----------------|
|1
|2
|3
|4
|5
|Vid.|-|-|-||

**1000000**
| Bandymo numeris | Nuskaitymas | Rūšiavimas| Skrstymas į konteinerius | Bendras laikas |
|-----------------|-------------|-----------|--------------------------|----------------|
|1
|2
|3
|4
|5
|Vid.|-|-|-||

**10000000**
| Bandymo numeris | Nuskaitymas | Rūšiavimas| Skrstymas į konteinerius | Bendras laikas |
|-----------------|-------------|-----------|--------------------------|----------------|
|1
|2
|3
|4
|5
|Vid.|-|-|-||

# Dekas

**1000**
| Bandymo numeris | Nuskaitymas | Rūšiavimas| Skrstymas į konteinerius | Bendras laikas |
|-----------------|-------------|-----------|--------------------------|----------------|
|1
|2
|3
|4
|5
|Vid.|-|-|-||

**10000**
| Bandymo numeris | Nuskaitymas | Rūšiavimas| Skrstymas į konteinerius | Bendras laikas |
|-----------------|-------------|-----------|--------------------------|----------------|
|1
|2
|3
|4
|5
|Vid.|-|-|-||

**100000**
| Bandymo numeris | Nuskaitymas | Rūšiavimas| Skrstymas į konteinerius | Bendras laikas |
|-----------------|-------------|-----------|--------------------------|----------------|
|1
|2
|3
|4
|5
|Vid.|-|-|-||

**1000000**
| Bandymo numeris | Nuskaitymas | Rūšiavimas| Skrstymas į konteinerius | Bendras laikas |
|-----------------|-------------|-----------|--------------------------|----------------|
|1
|2
|3
|4
|5
|Vid.|-|-|-||

**10000000**
| Bandymo numeris | Nuskaitymas | Rūšiavimas| Skrstymas į konteinerius | Bendras laikas |
|-----------------|-------------|-----------|--------------------------|----------------|
|1
|2
|3
|4
|5
|Vid.|-|-|-||

## Antra strategija
*Bendro studentų konteinerio (vector, list ir deque) skaidymas (rūšiavimas) panaudojant tik vieną naują konteinerį: "vargšiukai". Tokiu būdu, jei studentas yra vargšiukas, jį turime įkelti į naująjį "vargšiukų" konteinerį ir ištrinti iš bendro studentai konteinerio. Po šio žingsnio studentai konteineryje liks vien tik kietiakai. Atminties atveju tai efektyviau, tačiau dažni trynimai gali būti "skausmingi", ypač tam tikro tipo konteineriams.*

# Vektorius

**1000**
| Bandymo numeris | Nuskaitymas | Rūšiavimas| Skrstymas į konteinerius | Bendras laikas |
|-----------------|-------------|-----------|--------------------------|----------------|
|1
|2
|3
|4
|5
|Vid.|-|-|-||

**10000**
| Bandymo numeris | Nuskaitymas | Rūšiavimas| Skrstymas į konteinerius | Bendras laikas |
|-----------------|-------------|-----------|--------------------------|----------------|
|1
|2
|3
|4
|5
|Vid.|-|-|-||

**100000**
| Bandymo numeris | Nuskaitymas | Rūšiavimas| Skrstymas į konteinerius | Bendras laikas |
|-----------------|-------------|-----------|--------------------------|----------------|
|1
|2
|3
|4
|5
|Vid.|-|-|-||

**1000000**
| Bandymo numeris | Nuskaitymas | Rūšiavimas| Skrstymas į konteinerius | Bendras laikas |
|-----------------|-------------|-----------|--------------------------|----------------|
|1
|2
|3
|4
|5
|Vid.|-|-|-||

**10000000**
| Bandymo numeris | Nuskaitymas | Rūšiavimas| Skrstymas į konteinerius | Bendras laikas |
|-----------------|-------------|-----------|--------------------------|----------------|
|1
|2
|3
|4
|5
|Vid.|-|-|-||

# Listas

**1000**
| Bandymo numeris | Nuskaitymas | Rūšiavimas| Skrstymas į konteinerius | Bendras laikas |
|-----------------|-------------|-----------|--------------------------|----------------|
|1
|2
|3
|4
|5
|Vid.|-|-|-||

**10000**
| Bandymo numeris | Nuskaitymas | Rūšiavimas| Skrstymas į konteinerius | Bendras laikas |
|-----------------|-------------|-----------|--------------------------|----------------|
|1
|2
|3
|4
|5
|Vid.|-|-|-||

**100000**
| Bandymo numeris | Nuskaitymas | Rūšiavimas| Skrstymas į konteinerius | Bendras laikas |
|-----------------|-------------|-----------|--------------------------|----------------|
|1
|2
|3
|4
|5
|Vid.|-|-|-||

**1000000**
| Bandymo numeris | Nuskaitymas | Rūšiavimas| Skrstymas į konteinerius | Bendras laikas |
|-----------------|-------------|-----------|--------------------------|----------------|
|1
|2
|3
|4
|5
|Vid.|-|-|-||

**10000000**
| Bandymo numeris | Nuskaitymas | Rūšiavimas| Skrstymas į konteinerius | Bendras laikas |
|-----------------|-------------|-----------|--------------------------|----------------|
|1
|2
|3
|4
|5
|Vid.|-|-|-||

# Dekas

**1000**
| Bandymo numeris | Nuskaitymas | Rūšiavimas| Skrstymas į konteinerius | Bendras laikas |
|-----------------|-------------|-----------|--------------------------|----------------|
|1
|2
|3
|4
|5
|Vid.|-|-|-||

**10000**
| Bandymo numeris | Nuskaitymas | Rūšiavimas| Skrstymas į konteinerius | Bendras laikas |
|-----------------|-------------|-----------|--------------------------|----------------|
|1
|2
|3
|4
|5
|Vid.|-|-|-||

**100000**
| Bandymo numeris | Nuskaitymas | Rūšiavimas| Skrstymas į konteinerius | Bendras laikas |
|-----------------|-------------|-----------|--------------------------|----------------|
|1
|2
|3
|4
|5
|Vid.|-|-|-||

**1000000**
| Bandymo numeris | Nuskaitymas | Rūšiavimas| Skrstymas į konteinerius | Bendras laikas |
|-----------------|-------------|-----------|--------------------------|----------------|
|1
|2
|3
|4
|5
|Vid.|-|-|-||

**10000000**
| Bandymo numeris | Nuskaitymas | Rūšiavimas| Skrstymas į konteinerius | Bendras laikas |
|-----------------|-------------|-----------|--------------------------|----------------|
|1
|2
|3
|4
|5
|Vid.|-|-|-||
