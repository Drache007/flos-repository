# HTML

## 1. What is html?
html steht für Hypertext Markup Language. Es wird benutzt um Information in Form von Text, Bildern, Links oder Tabellen auf Websites zu erstellen und strukturieren. 
## 2. Funktionsweise
Der aufbau von html Code besteht aus Tags. Diese haben meist ein öffnendes und schließendes Element (Ausnahme leere Tags, wie zb Bilder). Das öffnende Element kann beispielsweise so aussehen: ```<p>```, der dazugehörige closing tag sieht dann so aus: ```</p>```.  
## 3. Aufbau
Die erste Zeile enthält typischerweise ein element, das dem browser sagt um welche html Version es sich handelt. Weiters hat man einen Tag namens html weiter. Dieser hat ein Attribut, das die Sprache festlegt. Dadurch weiß der Browser wann er automatische Übersetzen vorschlagen soll und wann nicht.  
Darin befinden sich 2 tags: **head** und **body**.   
### head
Im head befinden sich Informationen, die man nicht auf der Website sieht.  
Immer dabei hat man zumindest: 
* charset: Damit wird die Codierung des Textes bestimmt
* title: Das ist der Titel, der Website, welcher am Browserkopf sichtbar ist. 
### body
Im body findet man die gesamt information die auf der Webseite zu sehen ist. 
```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8">
        <title>Website</title>
    </head>
    <body>

    </body>
</html>
```
### Beziehungen zwischen Tags
Tags können zueinander in einer Parent-Child-Beziehung oder Siblings sein. Im vorigen Beispiel: head und body sind siblings. Ihr Parent ist der html Tag. Man formatiert das in der Regel so, dass man die Children einrückt.  
## 4. Tags
* Headings sind Überschriften. Es gibt 6 Stück davon. ```<h1>``` bis ```<h6>```. Sie sind in der Größe absteigend.  
* Paragraphs sind Absätze. ```<p>```  
* Container ```<div>``` diese haben aber keine semantische Funktion  
* **Fett** geschrieben: ```<strong>```
* *kursiv* geschrieben: ```<em>```  
## 5. Listen 
### Sortierte Liste
Eine sortierte Liste nummeriert die Elemente durch.  
Sie kann bespielsweise so aussehen:  
```html
<ol>
    <li>ersten</li>
    <li>zweitens</li>
    <li>drittens</li>
</ol>
```
```<ol>``` ist der Tag für eine ordered list.  
```<li>``` steht für list element und ist der Tag für alle einzelnen Elemente der Liste. Wird in der Unsortierten Liste gleich benutzt.  
### Unsortierte Liste
Eine unsortierte Liste hat an Stelle einer Nummerierung nur Aufzählungzeichen.  
Sieht folgendermaßen aus: 
```html
<ul>
    <li>erstens</li>
    <li>zweitens</li>
    <li>drittens</li>
</ul>
```
## 6. Bilder
Die häufigsten Dateitypen für Bilddateien im Web sind:  
* .jpg
* .png
* .svg
* .gif  
Um Bilder in eine Website zu integrieren benötigt man den **img** Tag. Dabei handelt es sich um einen leeren Tag. Das bedeutet er braucht kein schließendes Element.  
Man benötigt hier Attribute. Das sind zusätzlich Informationen im Tag.  
Am wichtigsten ist das **src** Attribut. Es legt fest welches bild angezeigt wird, dafür enthält es den dateipfad des Bilds.  
Ebenfalls wichtig ist der **alt** Tag. Er sollte eine Beschreibung für das Bild enthalten. Dieser Text wird nirgends angezeigt, außer das bild kann nicht geladen werden. Screenreaders lesen ihn vor.  
Wenn man die Größe festlegen möchte benutzt man das **width** Attribut.  
### Beispiel: 
```html
<img src="images/Bild.jpg" alt="Hier sieht man ein Bild">
```
## 7. Links
Es gibt absolute und rlative Links. Ein absoluter Link führt zu einer anderen Webseite, während ein relativer Link zu einer weiteren Page auf der aktuellen Seite führt, also einer weiteren html Datei.  
### Absoluter Link: 
```html
<a href="https://www.google.com">click me</a>
```
### Relativer Link
```html
<a href="pages/pagetwo.html">click me</a>
```
Der hie verwendete Tag ist der sogenannte anchor.  
## 8. Tabellen
Der Tag für eine Tabelle heißt: ```<table>```  
Der Tabellenkopf (erste Zeile) steht im ```<th>```Tag.  
Die restliche Tabelle ist im Tag: ```<tbody>```  
Dieser Tag hat Child Tags, die ```<tr>``` heißen und einzelne Zeilen beinhalten.  
Jedes Element ist in einem Tag: ```<th>```  
### Bespiel: 
```html
<table>
    <thead>
        <tr>
            <th>Spalte 1</th>
            <th>Spalte 2</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td>Daten 1</td>
            <td>Daten 2</td>
        </tr>
        <tr>
            <td>Daten 3</td>
            <td>Daten 4</td>
        </tr>
    </tbody>
</table>
```
## 9. Formulare 
In Formulare kann ein User etwas eingeben, das dann ans Back-End weitergeleitet werden kann. 
### Beispiel
```html
<form>
    <label for="name">Name</label>
    <input type="text" id="name" name="name">
    <button type="submit">Absenden</button>
</form>
```
