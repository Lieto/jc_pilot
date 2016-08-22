#!/usr/bin/env bash

UNIT_GUID = 1
SCALE_FACTOR = 1.0
USE_ROI = 0
DISPLAY = 1
FILE_NAME = "/home/kuoppves/Projects/jc_pilot/build/koe.mp4"

/home/kuoppves/Projects/jc_pilot/build/jc_pilot --unitGUID $UNIT_GUID --scale $SCALE_FACTOR --test_file $FILE_NAME --display $DISPLAY