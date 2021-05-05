#!/usr/bin/env zsh
SCRIPTPATH="$(
    cd "$(dirname "$0")" >/dev/null 2>&1
    pwd -P
)"
cd $SCRIPTPATH

python_exec=$(which python3)

echo using python=$python_exec
echo

opencv_python="$HOME/Projects/build-opencv/opencv/modules/python/"

mkdir -p generated_bindings
echo 'src/c_polar_stereo_rectification.h' > headers.txt

# ls -1 src > srcfiles.txt

$python_exec "$opencv_python/src2/gen2.py" "$SCRIPTPATH/generated_bindings" "$SCRIPTPATH/srcfiles.txt"