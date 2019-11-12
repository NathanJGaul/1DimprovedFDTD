#!/bin/sh

echo Enter a basename: 
read basename

for i in ${basename}.*; do
    [ -f "$i" ] || break
    eplot -r [0:199][-1:1] -M -P "$i" 2>/dev/null
    mv foo.png "$i".png
done

# combine individual frames into animated gif
convert -delay 20 -loop 0 ${basename}.*.png ${basename}_movie.gif

# remove remaining frames
rm *.png