#!/bin/sh

stg=12w1312

z=`expr `expr "$stg" : '[^w]*1'` + `expr "$stg" : '[^w]*w'` `

echo $z

