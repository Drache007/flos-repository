# Over the Wire - Bandit

## Level 0
### Objective: 
Log onto the given host with ssh. 
### Solution
```
ssh bandit0@bandit.labs.overthewire.org -p 2220
```

## Level 1
### Objective
Find Password in a file. And log in as bandit1. 
### Solution
```
cat readme
```
### Password
* ZjLjTmM6FvvyRnrb2rfNWOZOTa6ip5If

## Level 2
### Objective
Find Password in a file named -.
### Solution
```
cat ./-
```
### Password
* 263JGJPfgU6LtdEvgfWU1XP5yac29mFx

## Level 3
### Objective
Find Password in a file with spaces in the name.
### Solution
```
cat "spaces in this filename"
```
### Password
* MNk8KNH3Usiio41PRUEoDFPqfxLPlSmx

## Level 4
### Objective
Find Password in a hidden file.  
### Solution
```
cd inhere
ls -la
cat ...Hiding-From-You
```
### Password
* 2WmrDFRmJIq3IPxneAaMGhap0pFhF3NJ

## Level 5
### Objective
Find Password in the human readable file.
### Solution
1) check each file with: 
```
file ./file00
```
2) ```cat ./file07```
### Password
* 4oQYVPkxZOOEOO5pTW81FB8j8lxXGUQw

## Level 6
### Objective
Find Password in a file.
### Solution
1) look for file with: 
```
find / -size 1033c
```
2) get password with cat
### Password
* HWasnPhtq9AVKe0dmk45nxy20cvUa6EG

## Level 7
### Objective
Find Password in a file.
### Solution
1) find file with
```
find / -user bandit7 -group bandit6 -size 33c 2>/dev/null
```
2) get password with cat
### Password
* morbNTDkSW6jIlUc0ymOdMaLnOlFVAaj

## Level 8
### Objective
Find Password in file with more content
### Solution
```
grep -n "millionth" data.txt
```
### Password
* dfwvzFQi4mU0wfNbFOe9RoWskMLg7eEc

## Level 9
### Objective
Find Password in the human readable file.
### Solution
* get password with:
```
sort data.txt | uniq -u
```
### Password
* 4CKMh1JI91bUIZZPXDqGanal4xvAg0JM

## Level 10
### Objective
Find Password in a human readable line preceeded by several "=".
### Solution
* get password with:
```
strings data.txt
```
### Password
* FGUW5ilLVJrxX9kMYMmlN4MgbpfMiqey

## Level 11
### Objective
Decode the password from Rot13.
### Solution
* get password with:
```
cat data.txt | tr [A-Za-z] [N-ZA-Mn-za-m]
```
### Password
* 7x16WNeHIi5YkIhWsfFIqoognUTyj9Q4

## Level 12
### Objective
Get the password from a file tht was compressed and archived multiple times
### Solution
Check the filetype using the ```file``` command. Then use the suitable command from this list to decompress:  
* for gzip compressed file:  
```
mv file file.gz
gunzip file.gz
```
* for bzip2 compressed file:  
```
bunzip2 file
```
* for tar archive
```
tar -xf file
```
### Password
* FO5dwFsc0cbaIiH0h8J2eUks2vdTDwAn



