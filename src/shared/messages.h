/*
    Copyright 2015-2018 Clément Gallet <clement.gallet@ens-lyon.org>

    This file is part of libTAS.

    libTAS is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    libTAS is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with libTAS.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LIBTAS_MESSAGES_H_INCLUDED
#define LIBTAS_MESSAGES_H_INCLUDED

/* List of message identification values that is sent from/to the game */
enum {
    /*
     * The game notices the program that he reached a frame boundary.
     * Argument: none
     */
    MSGB_START_FRAMEBOUNDARY,

    /*
     * The game sends frame data to the program.
     * Argument: int size, size in chunks of 8kb.
     */
    MSGB_FRAME_DATA,

    /*
     * The program sent all messages at the beginning of the frame boundary.
     * Argument: none
     */
    MSGN_START_FRAMEBOUNDARY,

    /*
     * The game sends the frame number and time
     * Argument: unsigned long, struct timespec
     */
    MSGB_FRAMECOUNT_TIME,

    /*
     * Send all inputs to the game
     * Argument: AllInputs
     */
    MSGN_ALL_INPUTS,

    /*
     * Send all inputs to the game during a frame boundary, so that it can
     * display the inputs in the HUD
     * Argument: AllInputs
     */
    MSGN_PREVIEW_INPUTS,

    /*
     * Send config
     * Argument: struct SharedConfig
     */
    MSGN_CONFIG,

    /*
     * The programs tells the game to end the frame boundary
     * Argument: none
     */
    MSGN_END_FRAMEBOUNDARY,

    /*
     * The game tells the program that he has quit
     * Argument: none
     */
    MSGB_QUIT,

    /*
     * The program tells the game that the user has requested a quit
     * Argument: none
     */
    MSGN_USERQUIT,

    /*
     * Send the game pid so that the program can attach to it
     * Argument: pid_t
     */
    MSGB_PID,

    /*
     * Notice the program of the end of initialization messages
     * Argument: none
     */
    MSGB_END_INIT,

    /*
     * Notice the game of the end of initialization messages
     * Argument: none
     */
    MSGN_END_INIT,

    /*
     * Send the dump file to the game
     * Arguments: size_t (string length) then char[len]
     */
    MSGN_DUMP_FILE,

    /*
     * Send the X11 window identifier of the game to the program
     * Argument: int
     */
    MSGB_WINDOW_ID,

    /*
     * Send an alert message to be prompted by the program
     * Arguments: size_t (string length) then char[len]
     */
    MSGB_ALERT_MSG,

    /*
     * Send a message to be displayed on the game screen
     * Arguments: size_t (string length) then char[len]
     */
    MSGN_OSD_MSG,

    /*
     * Ask the game to make a savestate
     * Argument: none
     */
    MSGN_SAVESTATE,

    /*
     * Ask the game to load a savestate
     * Argument: none
     */
    MSGN_LOADSTATE,

    /*
     * Tells the program that the loading succeeded
     * Argument: none
     */
    MSGB_LOADING_SUCCEEDED,

    /*
     * Send to the game the path of the savestate
     * Argument: size_t (string length) then char[len]
     */
    MSGN_SAVESTATE_PATH,

    /*
     * Send to the game the path of the base savestate
     * Argument: size_t (string length) then char[len]
     */
    MSGN_BASE_SAVESTATE_PATH,

    /*
     * Send to the game the index of the savestate
     * Argument: int
     */
    MSGN_SAVESTATE_INDEX,

    /*
     * Send to the game the index of the base savestate
     * Argument: int
     */
    MSGN_BASE_SAVESTATE_INDEX,

    /*
     * Notify the program that encoding failed
     * Arguments: none
     */
    MSGB_ENCODE_FAILED,

    /*
     * Notify the game that we must stop encoding
     * Arguments: none
     */
    MSGN_STOP_ENCODE,

    /*
     * Send game information to the program
     * Arguments: 3 strings
     */
    MSGB_GAMEINFO,

    /*
     * Notify the game that it must redrawn the screen
     * Arguments: none
     */
    MSGN_EXPOSE,

    /*
     * Send fps and logical fps values to the program
     * Arguments: 2 floats
     */
    MSGB_FPS,

    /*
     * Send ramwatch string to display on OSD
     * Argument: size_t (string length) then char[len]
     */
    MSGN_RAMWATCH,

    /*
     * Send the current segment of video encoding to the program.
     * Argument: int
     */
    MSGB_ENCODING_SEGMENT,

    /*
     * Send the current segment of video encoding to the game.
     * Argument: int
     */
    MSGN_ENCODING_SEGMENT,

    /*
     * Notify that a backtrack savestate must be performed.
     * Argument: none
     */
    MSGB_DO_BACKTRACK_SAVESTATE,

    /*
     * Send to the game the location of the Steam user data folder.
     * Argument: size_t (string length) then char[len]
     */
    MSGN_STEAM_USER_DATA_PATH,
};

const std::string MESSAGE_NAMES[] {
    "MSGB_START_FRAMEBOUNDARY",
    "MSGB_FRAME_DATA",
    "MSGN_START_FRAMEBOUNDARY",
    "MSGB_FRAMECOUNT_TIME",
    "MSGN_ALL_INPUTS",
    "MSGN_PREVIEW_INPUTS",
    "MSGN_CONFIG",
    "MSGN_END_FRAMEBOUNDARY",
    "MSGB_QUIT",
    "MSGN_USERQUIT",
    "MSGB_PID",
    "MSGB_END_INIT",
    "MSGN_END_INIT",
    "MSGN_DUMP_FILE",
    "MSGB_WINDOW_ID",
    "MSGB_ALERT_MSG",
    "MSGN_OSD_MSG",
    "MSGN_SAVESTATE",
    "MSGN_LOADSTATE",
    "MSGB_LOADING_SUCCEEDED",
    "MSGN_SAVESTATE_PATH",
    "MSGN_BASE_SAVESTATE_PATH",
    "MSGN_SAVESTATE_INDEX",
    "MSGN_BASE_SAVESTATE_INDEX",
    "MSGB_ENCODE_FAILED",
    "MSGN_STOP_ENCODE",
    "MSGB_GAMEINFO",
    "MSGN_EXPOSE",
    "MSGB_FPS",
    "MSGN_RAMWATCH",
    "MSGB_ENCODING_SEGMENT",
    "MSGN_ENCODING_SEGMENT",
    "MSGB_DO_BACKTRACK_SAVESTATE",
    "MSGN_STEAM_USER_DATA_PATH",
};

#endif
