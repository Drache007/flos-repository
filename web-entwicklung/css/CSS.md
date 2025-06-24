# CSS
## Inhaltsverzeichnis
- [1. Syntax](#1-syntax)
- [2. Selektoren](#2-selektoren)
- [3. Combinators](#3-combinators)
- [4. Rules](#4-rules)
- [4. Wege CSS einzubinden](#4-wege-css-einzubinden)
- [5. Specificity](#5-specificity)
- [6. Box Model](#6-box-model)
- [8. Flexbox](#8-flexbox)
## 1. Syntax
```css
div {
  color: red;
  background-color: blue;
}
```
1. div ist in diesem Fall der Selektor, der angibt, auf welches Element die Regeln angewendet werden sollen.
2. in den geschwungenen Klammern sind Rules die auf alle Elemente des angegebenen Selektors angewendet werden.
## 2. Selektoren
Man kann tags wie div oder p angeben. 
### Classes
Man kann jedem Tag in html eine Klasse zuweisen, die dann in CSS verwendet werden kann.  
Im CSS Code wird die Klasse mit einem Punkt angegeben
```html
<p class="text">Dies ist ein Text</p>
```
```css
.text {
  color: red;
}
```
### IDs
Man kann jedem Tag in html eine ID zuweisen, die dann in CSS verwendet werden kann.  
Der Unterschied ist das IDs eindeutig sein müssen, d.h. es darf nur ein Element mit dieser ID auf der Seite geben.   
Im CSS Code wird die ID mit einem Hash-Zeichen angegeben.
```html
<p id="text">Dies ist ein Text</p>
```
```css
#text {
  color: red;
}
```
## 3. Combinators
Möchte man die selbe Regel auf mehrere Selektoren anwenden, kann man Combinators verwenden. Combinators sind spezielle Selektoren, die es ermöglichen, die Beziehung zwischen verschiedenen Elementen zu definieren. Es gibt vier Haupttypen von Combinators:

1. **Descendant Selector**: Wendet die Regel auf alle Nachfahren eines Elements an.
   ```css
   div p {
     color: red;
   }
   ```

2. **Child Selector**: Wendet die Regel nur auf direkte Kinder eines Elements an.
   ```css
   div > p {
     color: red;
   }
   ```

3. **Adjacent Sibling Selector**: Wendet die Regel auf ein Element an, das direkt nach einem anderen Element kommt.
   ```css
   h1 + p {
     color: red;
   }
   ```

4. **General Sibling Selector**: Wendet die Regel auf alle Geschwister eines Elements an.
   ```css
   h1 ~ p {
     color: red;
   }
   ```
## 4. Rules
Es gibt verschiedene Rules, ein paar häufige Beispiele: 
* **color**: Legt die Textfarbe fest.
* **background-color**: Legt die Hintergrundfarbe fest.
* **font-size**: Legt die Schriftgröße fest.
* **font-family**: Legt die Schriftart fest.
* **text-align**: Legt die Textausrichtung fest (z.B. left, right, center).
* ...  
## 4. Wege CSS einzubinden
Es gibt mehrere Möglichkeiten, CSS in eine HTML-Datei einzubinden:
1. **Inline CSS**: Direkt im HTML-Element.
   ```html
   <p style="color: red;">Dies ist ein Text</p>
   ```
2. **Internal CSS**: Im `<style>`-Tag im `<head>`-Bereich der HTML-Datei.
   ```html
   <head>
     <style>
       p {
         color: red;
       }
     </style>
   </head>      
   ```
3. **External CSS**: In einer separaten CSS-Datei, die im `<head>`-Bereich der HTML-Datei verlinkt wird.
   ```html
   <head>
     <link rel="stylesheet" href="styles.css">
   </head>
   ```  
## 5. Specificity
Specificity ist ein Konzept in CSS, das bestimmt, welche Regel angewendet wird, wenn mehrere Regeln auf dasselbe Element zutreffen. Die Spezifität wird durch die Anzahl der Selektoren in einer Regel bestimmt.  
Die Spezifität wird in vier Kategorien unterteilt:
1. Inline-Styles: haben die höchste Spezifität.
2. IDs: haben eine höhere Spezifität als Klassen.
3. Klassen, haben eine mittlere Spezifität.  
4. Tags: haben die niedrigste Spezifität.
Wenn mehrere Regeln auf dasselbe Element zutreffen, wird die Regel mit der höchsten Spezifität angewendet. Wenn die Spezifität gleich ist, wird die zuletzt definierte Regel angewendet.  
## 6. Box Model
Das Box Model ist ein Konzept in CSS, das beschreibt, wie Elemente auf einer Webseite dargestellt werden. Jedes Element wird als rechteckige Box dargestellt, die aus mehreren Teilen besteht:
1. **Content**: Der Inhalt des Elements, z.B. Text oder Bilder.
2. **Padding**: Der Abstand zwischen dem Inhalt und dem Rand des Elements.
3. **Border**: Der Rand des Elements, der um das Padding herum verläuft.
4. **Margin**: Der Abstand zwischen dem Rand des Elements und anderen Elementen auf der Seite.  
Das Box Model ist wichtig, um das Layout von Webseiten zu verstehen und zu gestalten.  
### Block und Inline Elemente
Es gibt zwei Haupttypen von Elementen in CSS: Block-Elemente und Inline-Elemente.
- **Block-Elemente**: Nehmen die volle Breite ihres Containers ein und beginnen immer auf einer neuen Zeile. Beispiele sind `<div>`, `<p>`, `<h1>`, `<h2>`, etc.
- **Inline-Elemente**: Nehmen nur so viel Breite ein, wie sie benötigen, und können nebeneinander stehen. Beispiele sind `<span>`, `<a>`, `<img>`, etc.
Um den Typ eines Elements zu ändern, kann die CSS-Eigenschaft `display` verwendet werden.
```css
.block {
  display: block;
}
.inline {
  display: inline;
}
```
## 8. Flexbox
Flexbox ist ein Layout-Modell in CSS, das es ermöglicht, flexible und responsive Layouts zu erstellen. Es basiert auf dem Konzept von flexiblen Boxen, die sich an die Größe des Containers anpassen.  
Einige wichtige Eigenschaften von Flexbox sind:
1. **display: flex**: Aktiviert Flexbox für ein Element.
   ```css
   .container {
     display: flex;
   }
   ```
2. **flex-direction**: Legt die Richtung der flexiblen Boxen fest (z.B. row, column).
   ```css
   .container {
     flex-direction: row;
   }
   ```
3. **justify-content**: Legt die Ausrichtung der flexiblen Boxen entlang der Hauptachse fest (z.B. flex-start, center, space-between).
   ```css
   .container {
     justify-content: center;
   }
   ```
4. **align-items**: Legt die Ausrichtung der flexiblen Boxen entlang der Querachse fest (z.B. flex-start, center, stretch).
   ```css
   .container {
     align-items: center;
   }
   ```
