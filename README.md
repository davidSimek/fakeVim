# Fake Vim
## Why do I make this?
Because I need some work to show. I always do super small projects, but no one cares about these. (Neither do I.)

## Functionality
- move cursor  
- log errors  
- config file
- resize for size of console (need to make it work on resize)

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
```

### Dependencies
```curses.h```  
for reading from and clearing console
