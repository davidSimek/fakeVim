# Fake Vim
## Why do I make this?
Because I need some work to show. I always do super small projects, but no one cares about these. (Neither do I.)

## Functionality
- log errors  
- config file
- adapts for change in size of window / font size
- finally it can display text from buffer

## Configuration
`~/.config/fakeVim.conf`  
You do it just like this:  
```
# UI
empty _
cursor x

# KEY BINDINGS
up k
down j
left h
right l

# EDIT 
remove x
```

### Dependencies
```curses.h```  
for reading from and clearing console
