# Javascript - Study Notes

## Strings
### Defining Variables
* use ```let``` to define a variable. 
```js
let greeting = "Hello World!";
```
* ```'HelloWorld!'``` - works too  
* using backticks allows expressions within the definition:  
```js
let name = "Tom";
let greeting = `Hello ${name}!` 
// Hello Tom!
```
the expression is wrapped in ${ }.  
### String Manipulation
#### Change to lower or upper case
* ```toUpperCase()```
```js
const text = "Hello, World!";
const uppercased = text.toUpperCase(); // "HELLO, WORLD!"
```
* ```toLowerCase```
```js
const text = "Hello, World!";
const lowercased = text.toLowerCase(); // "hello, world!"
```
#### Trim Whitespaces
* ```trim()``` - removes whitespaces from both ends of the string.
* ```trimStart()``` - removes whitespaces from the start of the string.  
* ```trimEnd()``` - removes whitespaces from the end of the string.  
#### String Searching
* ```indexOf("text")``` - returns the index of the, searched for, text within the string. If the string does not include the text, it returns **-1**  
* ```lastIndexOf()``` - works the same way as indexOf(), but starts the search from the end of the string.  
*  ```includes()``` - returns a boolean and just checks if the string includes the text or not  
* ```startsWith()``` - checks if the string starts with the text
* ```endsWith()``` - checks if the string ends with the text
#### substring Extraction
* ```slice()``` - extracts a substring between specified indices. 
```js
string.slice(startIndex, endIndex);
```
endIndex is optional  
supports negative indices
* ```substring()``` - works the same way as **slice**, but does not support negative indices.  
#### Modifying Strings
* ```replace()``` - replaces a specified substring with another string
```js
const message = "Guten Abend";
const updatedMessage = message.replace("Abend", "Morgen");
//Output: "Guten Morgen"
```
* ```split(",")``` - splits up the string into an array of strings. Splits at a specified seperator. Useful for working with .csv files.  
* ```join()``` - merges an array of strings into one string, with a specified seperator. 
```js
const fruits = ["Apple", "Banana", "Orange"];
const joinedString = fruits.join(", "); // "Apple, Banana, Orange"
```
## Comparisons
### Operators
|Operator|Description
|--|--|
|==|equal value
|!=|not equal
|>|greater than
|<|less than
|>=|greator than or equal
|<=|less than or equal
|===|strict equality (also checks if the data types are the same)
|!==|strict inequality
### Comparing Strings
Strings are compared letter by letter, and to determine which string is greater the alphabetical order is used. 
```js
let result = "Z" > "A"; //true
```
#### Algorithm
1) Compare the first character of the strings
2) If the first characters are the same, it looks at the second characters and so on. 
3) This continues until a strings character is greater than the others at a position or either string ends. If thats the case the longer string is considered greater   

Lowercase a is greater than upperecase A.  
### Comparing different types
Different types are converted to numbers. So boolean values become 1 for true and 0 for false. 
### Strict equality
The equality operator cannot differntiate false from 0, because the types are converted to numbers.  
The strict equality operator does not convert the types. 
```js
alert( 0 === false ); // false
alert( 0 == false ); // true
```
## Branching
```js
let x = 5;

if (x > 3) {
  console.log("x is greater than 3");
} else {
  console.log("x is less than or equal to 3");
}
```
**else if** is used for more options
### Logical Operators
* && ... AND
* || ... OR
* !  ... NOT
### switch case
```js
let choice = 1;

switch (choice) {
    case 1: 
        console.log("Hello");
        break;
    case 2: 
        console.log("Servus");
        break;
    default:
        console.log("Hola");
}
```
### Ternary Operator
```js
let result = condition ? value1 : value2;
```
If the condition is true, result becomes value1, otherwise it becomes value2.  
## Functions
Example: 
```js
function sum(value1, value2) {
    return value1 + value2;
}

sum(1, 2);
```
* Variables that are declared inside a function exist only within that function. 
* Variables that are not declared within a function are global. 
* If a variable declared inside a function it overshadows a global variable with th same name. 
### Not specified Parameters
If a parameter is not defined when calling a function it takes on the value **undefined**. To solve this isssue a default can be set: 
```js
function favoriteAnimal(animal = 'Red Panda') {
  return animal + " is my favorite animal!";
}
```
In this case, if the function is called without specifying the parameter, it uses "Red Panda" as default.  
### Arrow Function
```js
const add = (a, b) => {
  return a + b;
}
```
If a function like this only has one statement, the {}, and return keyword are optional.  
