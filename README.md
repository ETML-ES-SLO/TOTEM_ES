# TOTEM FIXME 
***

![croquis du totem](/doc/Images/CroquisTotem.PNG)

## Description 

[FR] : le but de ce projet est de réaliser un totem lumineux pouvant afficher des messages défilants ou des animations. 
Ce totem sera utilisé lors de festivales ou de manifestions lié aux activités du hackersapce Fixme, que ce soit à l'intérieur ou à l'éxtérieur.
Un premier prototype a été réaliser par un ex-étudiant de l'ES (Nicolas Furst), ce protoype est composé de :  


[EN] : the goal of this project is to make a light totem which can display different scrolling messages or animations. 
This totem will be used at festivals or demonstration meeting related FIXME hackerspace activities, indorrs or outdorrs. 
A first prototype was realized by an former student of the ES technical school (Nicolas Furst), this prototype is composed of : 

### **Mechanical part** : 
- - -
* two disk of 240mm diameter - view of top and bottom below

| view **TOP** | view **BOTTOM** | 
| --- | --- | 
| ![TOP](/doc/Images/Mechanical_Top.PNG) | ![BOTTOM](/doc/Images/Mechanical_BOTTOM.PNG) | 

**note** : the mechanical schematic was realized on the Solid Works CAO software - for using the mechanical files, go into the **mec** folder 

### **Electronics part** 
- - - 

* below a no exhaustive list of main electronics parts 

| description | manufacturer | model | datasheet | remarks |
| --- | --- | --- | --- | --- | 
| IOT module IEEE 802.11 | Microchip | ATWILC1000-MR110xB | [datasheet ATWILC100](https://ww1.microchip.com/downloads/aemDocuments/documents/WSG/ProductDocuments/DataSheets/ATWILC1000-MR110XB-IEEE-802.11-b-g-n-Link-Controller-Module-DS70005326E.pdf) | no comments |
| DC/DC Converter (Input : 4,5 to 14V Ouput : 0 - 6V / 10A | lineage Power | NQR010A0X4 | [datasheet NQR010A0X4](/doc/datasheets/Alimentation/NQR010A0X-477178.pdf) | probably osbolete component | 
| --- | --- | --- | --- | --- | 