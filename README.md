# TOTEM FIXME 

![croquis du totem](/doc/Images/CroquisTotem.PNG)

## Description 

[FR] : le but de ce projet est de réaliser un totem lumineux pouvant afficher des messages défilants ou des animations. 
Ce totem sera utilisé lors de festivales ou de manifestions lié aux activités du hackersapce Fixme, que ce soit à l'intérieur ou à l'éxtérieur.
Un premier prototype a été réaliser par un ex-étudiant de l'ES (Nicolas Furst), ce protoype est composé de :  


[EN] : the goal of this project is to make a light totem which can display different scrolling messages or animations. 
This totem will be used at festivals or demonstration meeting related FIXME hackerspace activities, indorrs or outdorrs. 
A first prototype was realized by an former student of the ES technical school (Nicolas Furst), this prototype is composed of : 

### **Mechanical part** : 

* two disk of 240mm diameter - view of top and bottom below

| view **TOP** | view **BOTTOM** | 
| --- | --- | 
| ![TOP](/doc/Images/Mechanical_Top.PNG) | ![BOTTOM](/doc/Images/Mechanical_BOTTOM.PNG) | 

**note** : the mechanical schematic was realized on the Solid Works CAO software - for using the mechanical files, go into the **mec** folder 

### **Electronics part** 

Below is a block diagrams of the various stages of the electronic part : 
![block diagrams](/doc/Images/blocDiagrammes.PNG)

#### **POWER SUPPLY**
in progress 

##### **Battery & Solar Panel**

##### **Charging System**

##### **Regulator**

#### **DISPLAY**

#### **MICROCONTROLER** 

#### **SENSORS** 

##### **Brightness measurement** 

##### **Current measurement**

* a no exhaustive list of main electronics parts - here the main components used in this project, for more details, see the [BOM](/hardware/BOM/Liste des Composant_V1.xlsx) 

| description | manufacturer | model | datasheet | remarks |
| --- | --- | --- | --- | --- | 
| IOT module IEEE 802.11 | Microchip | ATWILC1000-MR110xB | [datasheet ATWILC100](https://ww1.microchip.com/downloads/aemDocuments/documents/WSG/ProductDocuments/DataSheets/ATWILC1000-MR110XB-IEEE-802.11-b-g-n-Link-Controller-Module-DS70005326E.pdf) | no comments |
| DC/DC Converter (Input : 4,5 to 14V Ouput : 0 - 6V / 10A | lineage Power | NQR010A0X4 | [datasheet NQR010A0X4](/doc/datasheets/Alimentation/NQR010A0X-477178.pdf) | probably osbolete component | 
| current sensing Amplifier | TI | LMP860x | [datasheet LMP860x](https://www.ti.com/lit/ds/symlink/lmp8601.pdf?ts=1695161032082&ref_url=https%253A%252F%252Fwww.ti.com%252Fproduct%252FLMP8601)  | no comments | 
| light sensor - phototransitor | Vishay | TEPT4400 | [datasheet TEPT4400](https://www.vishay.com/docs/81341/tept4400.pdf) | no comment | 
| Step-Down Regulator 3A | TI | LM2676 | [datasheet LM2676](https://www.ti.com/lit/ds/symlink/lm2676.pdf?ts=1697798250050&ref_url=https%253A%252F%252Fwww.google.com%252F) | no comment | 
| --- | --- | --- | --- | --- | 