#!/usr/bin/env bash

HOSTNAME="52.18.86.18"
USERNAME="ubuntu"
CAPTUREDIR="/home/kuoppves/capture/"
CAPTURECSV="test_cam.csv"
TRANSFERDIR="/home/ubuntu/video/test_cam/"
TRANSFERCSV="sent.csv"

python send_files.py --hostname $HOSTNAME --username $USERNAME --capturedir $CAPTUREDIR --capturecsv $CAPTURECSV --transferdir $TRANSFERDIR --transfercsv $TRANSFERCSV
