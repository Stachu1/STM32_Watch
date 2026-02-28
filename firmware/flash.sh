#!/bin/bash
flasher=$1
binary=$2

"$flasher" -c port=SWD -e all
"$flasher" -c port=SWD freq=4000 -d "$binary"
"$flasher" -c port=SWD freq=4000 -HardRst
