# TMUX
## Install
```
sudo apt install tmux
```
## Commands
Cheatsheet with more: [https://tmuxcheatsheet.com/](https://tmuxcheatsheet.com/)
* start session with ```tmux``` or use ```tmux new -s name``` to give it a name
* detach from session with ```Ctrl + b``` ```d```  
* list your sessions with ```tmux ls```
* reattach latest session with ```tmux a``` or specify the session with ```tmux a -t 0``` 
* end a session with ```tmux kill-session```, to specify the session you want to end add ```-t 0``` 
* kill all Sessions with ```tmux kill-server```
## Hotkeys
The prefix key is ```Ctrl + b```  
After that you can use the hotkeys:  
* ```d``` - detach
* ```%``` - split vertically
* ```"``` - split horizontally
* directional arrows - move to another pane
* ```q``` - display the indexes of your panes. By pressing a number you move to the pane with that index. Be fast. 
* hold ```Ctrl```and use directional arrows to change the size of your panes
* ```Alt + <1 - 5>``` - premade layout, there are five layouts, you choose one  depending on the number you press (1 -5).
* ```c``` - create a new window
* ```n``` - move to previous window
* ```,``` - rename window
* ```w``` - shows all sessions and windows. You can jump to any one of them. 
* ```x``` - kill pane
* ```&``` - kill window
## Copy Mode
* make a config file for tmux
```nano ~/.tmux.conf```
* add the following text:  
```
set -g mouse on
setw -g mode-keys vi
```
* enter copy mode: ```Ctrl + b``` ```[```
* use directional arrows to go to where you want to start copying. 
* start copying with space
* select the text you want to copy with the directional arrows
* press enter to copy selected text
* paste with ```Ctrl + b``` ```]```


