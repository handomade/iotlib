# iotlib
MSX-C用　MSX0 IOTLIBです。
こちらは偉大なる先人の方々のMSX0用ライブラリを主にパクらせていただきMSX-Cに移植したものです。

使い方は以下。

＊IOT用関数 （MSX-Cは関数名が6文字縛りなので注意）

数値 = iotgti("のーど");

文字数 = iotgts("のーど",文字列);
  
iotpti("のーど",数値);

iotpts("のーど",文字列);

数値 = iotfdi("のーど");

数値 = iotfds("のーど",*文字)
(この数値はiotfdiと同じ)

サンプルはiottst.c

ーーー（注意）ーーー
ビルド用のbatを書き換える必要があります。

fpc に iotlibを追記
例）fpc %1 lib mlib iotlib

l80 に iotlib/sを追記する
例）l80 ck,%1,iotlib/s,clibs/s,crun/s,cend,%1/n/y/e:xmain




