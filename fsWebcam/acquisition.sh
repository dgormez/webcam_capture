#!/bin/bash
nohup fswebcam -r 1920x1080 --jpeg 85  -d /dev/video0 --no-banner ./Camera1/pic_"%Y%m%d%H%M%S".jpg &
nohup fswebcam -r 1920x1080 --jpeg 85  -d /dev/video1 --no-banner ./Camera2/pic_"%Y%m%d%H%M%S".jpg &
nohup fswebcam -r 1920x1080 --jpeg 85  -d /dev/video2 --no-banner ./Camera3/pic_"%Y%m%d%H%M%S".jpg &
fswebcam -r 1920x1080 --jpeg 85  -d /dev/video3 --no-banner ./Camera4/pic_"%Y%m%d%H%M%S".jpg 
