# TOTEM FIXME 

![croquis du totem](/doc/Images/CroquisTotem.PNG)

## General Description 

[FR] : le but de ce projet est de réaliser un totem lumineux pouvant afficher des messages défilants ou des animations. 
Ce totem sera utilisé lors de festivales ou de manifestions lié aux activités du hackersapce Fixme, que ce soit à l'intérieur ou à l'éxtérieur.
Un premier prototype a été réaliser par un ex-étudiant de l'ES (Nicolas Furst), ce protoype est composé de :  


[EN] : the goal of this project is to make a light totem which can display different scrolling messages or animations. 
This totem will be used at festivals or demonstration meeting related FIXME hackerspace activities, indorrs or outdorrs. 
A first prototype was realized by an former student of the ES technical school (Nicolas Furst), this prototype is composed of : 

## Sotfwares used for this projet 
### for the version 1_X (ETML-ES)

* for mechanical part : **soldiworks** 
* for shematics and PCB design : **Altium** 
* for PIC micronctroller programming  : => *IDE* : MPLABX  ??- *configurator* : Harmony ?? - *compilator* : XC?? 

### for the version 2_x (FIXME)


in progress !!!


## **Mechanical part** : 

* two disk of 240mm diameter - view of top and bottom below

| view **TOP** | view **BOTTOM** | 
| --- | --- | 
| ![TOP](/doc/Images/Mechanical_Top.PNG) | ![BOTTOM](/doc/Images/Mechanical_BOTTOM.PNG) | 

**note** : the mechanical schematic was realized on the Solid Works CAO software - for using the mechanical files, go into the **mec** folder 

## **Electronics part** 

Below is a block diagrams of the various stages of the electronic part : 
![block diagrams](/doc/Images/blocDiagrammes.PNG)

### **POWER SUPPLY**
in progress 

#### **Battery & Solar Panel**

#### **Charging System**
#### **Regulator**

### **DISPLAY**

### **MICROCONTROLER** 

[FR]: pour choisir correctement un micrcontroleur, il faut déterminer les différentes fonctions que l'on a besoin, voir le tableau ci-dessous. 
On a besoin de : 
* 3 entrées analogiques, 
* une communication SPI comprenant la clock, le chip select, le MISO et le MOSI, 
* 5 I/O, 
* un reset
* deux pins de programmation 
* alimentation pour la partie digitales et analogiques 

ce qui fait au minium ~ **20pins** 

[EN]: to choose the microcontroller, to need to determine the functions required - see the table below
It needs : 
* 3x analog input 
* 1x SPI communication with : clock, chip select, MISO, MOSI 
* 5x digital I/O 
* Reset 
* 2x programming Pins
* pins for the digital and analog part 

we need minimum ~ **20pins**

| -Application- | -Function- | -Pin's Number | 
| --- | --- | --- | 
| battery current measurement | Analogic Input (ADC) | 1x | 
| battery voltage measurement | Analogic Input (ADC) | 1x | 
| luminosity measurement | Analogic Input (ADC) | 1x |
| Wifi Communication | SPI | 4x | 
| Wifi Communication | Digital I/O | 4x |
| 5V activation | Digital I/O | 1x |
| uC programming | PGE-D/C | 2x |
| uC Reset | _MCLR | 1x | 
| Power Supply digital I/O | VDD | minimum 1x | 
| Power Supply analog Input | AVDD | minimum 1x | 
| Ground Supply | VSS - AVSS | minimum 2x | 



### **SENSORS** 

#### **Brightness measurement** 

#### **Current measurement**

Below a no exhaustive list of main electronics parts - here the main components used in this project, for more details, see the [BOM](/hardware/BOM/ListeComposants_V1.xlsx) 

| description | manufacturer | model | datasheet | remarks |
| --- | --- | --- | --- | --- | 
| IOT module IEEE 802.11 | Microchip | ATWILC1000-MR110xB | [datasheet ATWILC100](https://ww1.microchip.com/downloads/aemDocuments/documents/WSG/ProductDocuments/DataSheets/ATWILC1000-MR110XB-IEEE-802.11-b-g-n-Link-Controller-Module-DS70005326E.pdf) | no comments |
| DC/DC Converter (Input : 4,5 to 14V Ouput : 0 - 6V / 10A | lineage Power | NQR010A0X4 | [datasheet NQR010A0X4](/doc/datasheets/Alimentation/NQR010A0X-477178.pdf) | probably osbolete component | 
| current sensing Amplifier | TI | LMP860x | [datasheet LMP860x](https://www.ti.com/lit/ds/symlink/lmp8601.pdf?ts=1695161032082&ref_url=https%253A%252F%252Fwww.ti.com%252Fproduct%252FLMP8601)  | no comments | 
| light sensor - phototransitor | Vishay | TEPT4400 | [datasheet TEPT4400](https://www.vishay.com/docs/81341/tept4400.pdf) | no comment | 
| Step-Down Regulator 3A | TI | LM2676 | [datasheet LM2676](https://www.ti.com/lit/ds/symlink/lm2676.pdf?ts=1697798250050&ref_url=https%253A%252F%252Fwww.google.com%252F) | no comment | 
| Current Sensor Amplifier | TI | LM860x | [datasheet LM8601](| Step-Down Regulator 3A | TI | LM2676 | [datasheet LM2676](https://www.ti.com/lit/ds/symlink/lm2676.pdf?ts=1697798250050&ref_url=https%253A%252F%252Fwww.google.com%252F) | no comment | ) | no comment | 
| Intelligent Control LED | Worldsemi | WS2812B | [datasheet WS2812B](https://cdn-shop.adafruit.com/datasheets/WS2812B.pdf) | link with led pannels | 
| --- | --- | --- | --- | --- | 

## **Firmeware part** 

In progress 


## **SOFTWARE part**
### **Description**

[FR]: Pour la partie connexion avec la carte électronique, cela se fera par le réseau WiFi en connexion point à point avec une application (non défini) qui communiquera pour piloter le ToTem. 
Les fonctions possibles seront : 

* afficher chaînes de caractères alphanumérique - voir caractères spéciaux 
* modification de la luminoisté 
* modification de la couleur du texte 
* modifier la fréquence d'affichage 
* affichage du niveau de batterie 
* animation - jeux 

[EN]: to connect to the electronic board, this will be done using the point-to-point WiFi nwtwork with an application (no defined), which will communicate to control the Totem. 
The possible functions will be : 

* display alpha-numeric strings - see the special characters 
* luminosity modification 
* text's color modification 
* display's frequency modification
* display the battery level 
* animation - gaming 