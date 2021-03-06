#!/bin/bash

ICON_FILE="../res/images/icon.png"

mkdir Loki.iconset

sips -z 16 16     $ICON_FILE --out Loki.iconset/icon_16x16.png
sips -z 32 32     $ICON_FILE --out Loki.iconset/icon_16x16@2x.png
sips -z 32 32     $ICON_FILE --out Loki.iconset/icon_32x32.png
sips -z 64 64     $ICON_FILE --out Loki.iconset/icon_32x32@2x.png
sips -z 128 128   $ICON_FILE --out Loki.iconset/icon_128x128.png
sips -z 256 256   $ICON_FILE --out Loki.iconset/icon_128x128@2x.png
sips -z 256 256   $ICON_FILE --out Loki.iconset/icon_256x256.png
sips -z 512 512   $ICON_FILE --out Loki.iconset/icon_256x256@2x.png
sips -z 512 512   $ICON_FILE --out Loki.iconset/icon_512x512.png

iconutil -c icns Loki.iconset
rm -R Loki.iconset

