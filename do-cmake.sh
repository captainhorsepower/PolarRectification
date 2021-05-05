#!/usr/bin/env zsh
SCRIPTPATH="$(
    cd "$(dirname "$0")" >/dev/null 2>&1
    pwd -P
)"
cd $SCRIPTPATH

mkdir -p build; cd build

export OpenCV_DIR="$HOME/.virtualenvs/3D-reconstruction/"
cmake -GNinja ..



