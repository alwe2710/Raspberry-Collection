#!/bin/bash
file="/home/pi/ports.txt"
name=$(cat "$file")
while true
do
volume=$(cat "$name")
if [ "$volume" = "0" ]; then
amixer cset numid=1 -- -10239
elif [ "$volume" = "1" ]; then
amixer cset numid=1 -- -10238
elif [ "$volume" = "2" ]; then
amixer cset numid=1 -- -10238
elif [ "$volume" = "3" ]; then
amixer cset numid=1 -- -9023
elif [ "$volume" = "4" ]; then
amixer cset numid=1 -- -8197
elif [ "$volume" = "5" ]; then
amixer cset numid=1 -- -7571
elif [ "$volume" = "6" ]; then
amixer cset numid=1 -- -7066
elif [ "$volume" = "7" ]; then
amixer cset numid=1 -- -6643
elif [ "$volume" = "8" ]; then
amixer cset numid=1 -- -6279
elif [ "$volume" = "9" ]; then
amixer cset numid=1 -- -5960
elif [ "$volume" = "10" ]; then
amixer cset numid=1 -- -5675
elif [ "$volume" = "11" ]; then
amixer cset numid=1 -- -5418
elif [ "$volume" = "12" ]; then
amixer cset numid=1 -- -5184
elif [ "$volume" = "13" ]; then
amixer cset numid=1 -- -4969
elif [ "$volume" = "14" ]; then
amixer cset numid=1 -- -4771
elif [ "$volume" = "15" ]; then
amixer cset numid=1 -- -4587
elif [ "$volume" = "16" ]; then
amixer cset numid=1 -- -4415
elif [ "$volume" = "17" ]; then
amixer cset numid=1 -- -4253
elif [ "$volume" = "18" ]; then
amixer cset numid=1 -- -4101
elif [ "$volume" = "19" ]; then
amixer cset numid=1 -- -3957
elif [ "$volume" = "20" ]; then
amixer cset numid=1 -- -3820
elif [ "$volume" = "21" ]; then
amixer cset numid=1 -- -3690
elif [ "$volume" = "22" ]; then
amixer cset numid=1 -- -3566
elif [ "$volume" = "23" ]; then
amixer cset numid=1 -- -3448
elif [ "$volume" = "24" ]; then
amixer cset numid=1 -- -3335
elif [ "$volume" = "25" ]; then
amixer cset numid=1 -- -3226
elif [ "$volume" = "26" ]; then
amixer cset numid=1 -- -3122
elif [ "$volume" = "27" ]; then
amixer cset numid=1 -- -3022
elif [ "$volume" = "28" ]; then
amixer cset numid=1 -- -2925
elif [ "$volume" = "29" ]; then
amixer cset numid=1 -- -2832
elif [ "$volume" = "30" ]; then
amixer cset numid=1 -- -2742
elif [ "$volume" = "31" ]; then
amixer cset numid=1 -- -2655
elif [ "$volume" = "32" ]; then
amixer cset numid=1 -- -2571
elif [ "$volume" = "33" ]; then
amixer cset numid=1 -- -2489
elif [ "$volume" = "34" ]; then
amixer cset numid=1 -- -2410
elif [ "$volume" = "35" ]; then
amixer cset numid=1 -- -2333
elif [ "$volume" = "36" ]; then
amixer cset numid=1 -- -2258
elif [ "$volume" = "37" ]; then
amixer cset numid=1 -- -2185
elif [ "$volume" = "38" ]; then
amixer cset numid=1 -- -2114
elif [ "$volume" = "39" ]; then
amixer cset numid=1 -- -2045
elif [ "$volume" = "40" ]; then
amixer cset numid=1 -- -1978
elif [ "$volume" = "41" ]; then
amixer cset numid=1 -- -1909
elif [ "$volume" = "42" ]; then
amixer cset numid=1 -- -1845
elif [ "$volume" = "43" ]; then
amixer cset numid=1 -- -1783
elif [ "$volume" = "44" ]; then
amixer cset numid=1 -- -1722
elif [ "$volume" = "45" ]; then
amixer cset numid=1 -- -1662
elif [ "$volume" = "46" ]; then
amixer cset numid=1 -- -1604
elif [ "$volume" = "47" ]; then
amixer cset numid=1 -- -1547
elif [ "$volume" = "48" ]; then
amixer cset numid=1 -- -1491
elif [ "$volume" = "49" ]; then
amixer cset numid=1 -- -1436
elif [ "$volume" = "50" ]; then
amixer cset numid=1 -- -1382
elif [ "$volume" = "51" ]; then
amixer cset numid=1 -- -1380
elif [ "$volume" = "52" ]; then
amixer cset numid=1 -- -1326
elif [ "$volume" = "53" ]; then
amixer cset numid=1 -- -1275
elif [ "$volume" = "54" ]; then
amixer cset numid=1 -- -1225
elif [ "$volume" = "55" ]; then
amixer cset numid=1 -- -1175
elif [ "$volume" = "56" ]; then
amixer cset numid=1 -- -1126
elif [ "$volume" = "57" ]; then
amixer cset numid=1 -- -1078
elif [ "$volume" = "58" ]; then
amixer cset numid=1 -- -1029
elif [ "$volume" = "59" ]; then
amixer cset numid=1 -- -983
elif [ "$volume" = "60" ]; then
amixer cset numid=1 -- -938
elif [ "$volume" = "61" ]; then
amixer cset numid=1 -- -893
elif [ "$volume" = "62" ]; then
amixer cset numid=1 -- -850
elif [ "$volume" = "63" ]; then
amixer cset numid=1 -- -807
elif [ "$volume" = "64" ]; then
amixer cset numid=1 -- -764
elif [ "$volume" = "65" ]; then
amixer cset numid=1 -- -722
elif [ "$volume" = "66" ]; then
amixer cset numid=1 -- -681
elif [ "$volume" = "67" ]; then
amixer cset numid=1 -- -640
elif [ "$volume" = "68" ]; then
amixer cset numid=1 -- -600
elif [ "$volume" = "69" ]; then
amixer cset numid=1 -- -561
elif [ "$volume" = "70" ]; then
amixer cset numid=1 -- -522
elif [ "$volume" = "71" ]; then
amixer cset numid=1 -- -484
elif [ "$volume" = "72" ]; then
amixer cset numid=1 -- -446
elif [ "$volume" = "73" ]; then
amixer cset numid=1 -- -409
elif [ "$volume" = "74" ]; then
amixer cset numid=1 -- -372
elif [ "$volume" = "75" ]; then
amixer cset numid=1 -- -336
elif [ "$volume" = "76" ]; then
amixer cset numid=1 -- -300
elif [ "$volume" = "77" ]; then
amixer cset numid=1 -- -265
elif [ "$volume" = "78" ]; then
amixer cset numid=1 -- -261
elif [ "$volume" = "79" ]; then
amixer cset numid=1 -- -226
elif [ "$volume" = "80" ]; then
amixer cset numid=1 -- -192
elif [ "$volume" = "81" ]; then
amixer cset numid=1 -- -158
elif [ "$volume" = "82" ]; then
amixer cset numid=1 -- -125
elif [ "$volume" = "83" ]; then
amixer cset numid=1 -- -92
elif [ "$volume" = "84" ]; then
amixer cset numid=1 -- -59
elif [ "$volume" = "85" ]; then
amixer cset numid=1 -- -27
elif [ "$volume" = "86" ]; then
amixer cset numid=1 -- -6
elif [ "$volume" = "87" ]; then
amixer cset numid=1 37
elif [ "$volume" = "88" ]; then
amixer cset numid=1 67
elif [ "$volume" = "89" ]; then
amixer cset numid=1 97
elif [ "$volume" = "90" ]; then
amixer cset numid=1 127
elif [ "$volume" = "91" ]; then
amixer cset numid=1 156
elif [ "$volume" = "92" ]; then
amixer cset numid=1 185
elif [ "$volume" = "93" ]; then
amixer cset numid=1 214
elif [ "$volume" = "94" ]; then
amixer cset numid=1 242
elif [ "$volume" = "95" ]; then
amixer cset numid=1 270
elif [ "$volume" = "96" ]; then
amixer cset numid=1 298
elif [ "$volume" = "97" ]; then
amixer cset numid=1 325
elif [ "$volume" = "98" ]; then
amixer cset numid=1 352
elif [ "$volume" = "99" ]; then
amixer cset numid=1 379
elif [ "$volume" = "100" ]; then
amixer cset numid=1 400
fi
done
