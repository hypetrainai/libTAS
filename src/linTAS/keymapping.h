#ifndef KEYMAPPING_H_INCLUDED
#define KEYMAPPING_H_INCLUDED

#include <X11/Xlib.h>
#include <X11/keysym.h>

enum 
{
    HOTKEY_PLAYPAUSE, // Switch from play to pause of the game
    HOTKEY_FRAMEADVANCE, // Advance one frame, also pause the game if playing
    HOTKEY_LEN
};

void default_hotkeys(KeySym *hotkeys);

#endif // KEYMAPPING_H_INCLUDED