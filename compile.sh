#!/bin/bash
#
qmk compile -kb ferris/sweep_choc_mbuk -km alfieb

#for wsl, open the directory here so that we can drop it into qmk toolbox
explorer.exe .

/mnt/c/Program\ Files/QMK\ Toolbox/qmk_toolbox.exe &
