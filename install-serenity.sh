#!/bin/bash

REPLACE_PATH="${2//\//\\/}"

./configure-serenity.sh $1 $3
make
make install
sed -i "s/@SERENITY_CONFIG_INCLUDE@/${REPLACE_PATH}/g" $1/conf/httpd.conf
