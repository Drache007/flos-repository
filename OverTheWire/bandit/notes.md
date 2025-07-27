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

## Level 6
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

## Level 7
### Objective
Find Password in file with more content
### Solution
```
grep -n "millionth" data.txt
```
### Password
* dfwvzFQi4mU0wfNbFOe9RoWskMLg7eEc

## Level 8
### Objective
Find Password in the human readable file.
### Solution
* get password with:
```
sort data.txt | uniq -u
```
### Password
* 4CKMh1JI91bUIZZPXDqGanal4xvAg0JM


