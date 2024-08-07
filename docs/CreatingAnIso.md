# Creating a tpgz ISO

_These instructions are for Windows.
Mac and Linux please see [BUILDING.md](../BUILDING.md)._

## Quick Overview

tpgz takes a Twilight Princess ISO and generates a new ISO with features that help you practice.
You can play the new ISO on [Dolphin](https://dolphin-emu.org/) or a homebrewed GameCube/Wii.

```
 <TP iso>   +   <patch file>   =>   <TPGZ iso>
     ^               ^                   ^
You provide       Provided            Created
```

## Instructions

The instructions are intentionally detailed to prevent confusion.
If you are having trouble, please check [Troubleshooting](#troubleshooting).

**You will need your own Twilight Princess ISO**

1. Download the latest tpgz patch release for your version and region [here](https://github.com/zsrtp/tpgz/releases).

2. Download the latest romhack compiler [here](https://github.com/zsrtp/romhack-compiler/releases).
   - If you're patching a GameCube ISO, download a version that ends with `-gc`.

3. Place the tpgz patch file, the romhack compiler and a copy of your Twilight Princess ISO together in a folder.
   _Example:_

   - romhack.exe
   - tpgz.patch
   - Legend of Zelda, The - Twilight Princess (USA).iso

4. Copy the folder's path.
   _(Example: `C:\example\path`)_

5. Open cmd.

   - Press `<WindowsKey>+r` then type "cmd" into the popup and hit `<Enter>`.

6. Navigate to the above folder within cmd.

   - In cmd, enter the following and hit enter:<br>
     `cd <paste folder's path here>`

     _Example output:_

     ```
     C:\Users\Name>cd C:\Users\Name\Downloads\tpgz-folder

     C:\Users\Name\Downloads\tpgz-folder>
     ```

7. Run the following to create the tpgz ISO:<br>
   `romhack.exe apply <The-tpgz-patch>.patch <Your-ISO-name>.iso tpgz-patched.iso`

   - It is recommended that you type this out rather than copy-paste to avoid some common mistakes.
   - Type 'romhack.exe apply'.
     - _Note that you can use `<Tab>` to auto-complete files in the current folder.
       Typing "rom" then hitting `<Tab>` should change "rom" to "romhack.exe".
       You can hit `<Tab>` multiple times to cycle through available options.
       "apply" is not a filename so you will have to type it out._
   - Add the patch file's name.
     - _Type "tpgz", then hit `<Tab>.`
       This will auto-complete to the patch's filename._
   - Add your ISO's name.

     - _It is strongly recommended that you use `<Tab>` to auto-complete the ISO's filename.
       This will add necessary quotes if your filename has spaces.<br>
       Correct: "My TP ISO.iso"<br>
       Incorrect: My TP ISO.iso_

   - Add a filename for the new ISO.
     - Use "tpgz-patched.iso" or any other name ending in ".iso".
   - Press `<Enter>` after you have finished entering the command.
     - This will generate the new ISO.
       It may take a few minutes to complete.

8. Load the new ISO in [Dolphin emulator](https://dolphin-emu.org/) or a GameCube/Wii using a homebrew loader such as [Nintendont](https://github.com/FIX94/Nintendont).

## Troubleshooting

### How do I know my ISO is correct?

Make sure you have a clean ISO dump.

Correct MD5 hashes:<br>
NTSC-U GCN: **41deff9b1fd2831f48fbfa2dd1054e4d**  
NTSC-J GCN: **b130d78bb78cd63b501ddff210fde498**  
PAL GCN:    **798abb94d649f7d117514578b2abfae1**

NTSC-U WII (1.0) **25003a3e3666edf79c99080be9083b34**
NTSC-U WII (1.2) **70946e09da8f0bb218bb3b3542953d63**
JP WII:          **4979793d525198ef13e19ef369311743**
PAL WII:         **c46c133885383f96e7515c5cefd152d2**

Determine the MD5 hash of your ISO with the `md5sum` command.
If your command returns anything other than the above value, you either have the wrong ISO or your ISO was somehow modified.

```
C:\example\path>md5sum "My US Gamecube TP.iso"
41deff9b1fd2831f48fbfa2dd1054e4d *My US Gamecube TP.iso
```

### I get an "Unexpected Argument" error when I try to generate the ISO.

_Example:_

```
error: Found argument 'Zelda,' which wasn't expected, or isn't valid in this context
```

Your ISO likely has spaces in the filename and you do not have quotes around it.

'romhack.exe apply' expects 3 arguments (patch file, initial ISO, output filename):<br>
`romhack.exe apply [1] [2] [3]`

Correct:

```
romhack.exe apply tpgz-v0.1a.patch "Twilight Princess.iso" output.iso
                  ^                 ^                            ^
                 [1]               [2]                          [3]
```

Incorrect:

```
romhack.exe apply tpgz-v0.1a.patch Twilight Princess.iso output.iso
                  ^                 ^       ^        ^         ^
                 [1]               [2]     [3]      [4]       [5]
```

### The practice ISO loads using Nintendont, but my Gamecube controller doesn't work.

1. Start Nintendont.
2. Choose SD or USB as appropriate.
3. Press `B` to open Settings.
4. Set "Native Control" to "On".<br>
   _(Native Control is located in the left column near the bottom of the screen. It is separated from the other items.)_
