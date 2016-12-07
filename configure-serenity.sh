#!/bin/bash

if [ $2 = "dev" ]; then
PORT=8080
else
PORT=80
fi

./configure --prefix=$1 \
	--with-mpm=event \
	--with-included-apr \
	--disable-session \
	--disable-dav \
	--disable-rewrite \
	--disable-proxy \
	--disable-auth-digest \
	--disable-auth_basic \
	--disable-auth-form \
	--disable-authz-groupfile \
	--disable-authz-user \
	--disable-authz-dbm \
	--disable-authz-owner \
	--disable-authz-dbd \
	--disable-authn-file \
	--disable-authn-core \
	--disable-authn-dbm \
	--disable-authn-anon \
	--disable-authn-dbd \
	--disable-authn-socache \
	--disable-allowmethods \
	--disable-file \
	--disable-cache \
	--disable-socache-dbm \
	--disable-socache-memcache \
	--disable-macro \
	--disable-dbd \
	--disable-dumpio \
	--disable-buffer \
	--disable-ratelimit \
	--disable-ext-filter \
	--disable-request \
	--disable-substitute \
	--disable-sed \
	--disable-deflate \
	--disable-log-debug \
	--disable-logio \
	--disable-expires \
	--disable-unique-id \
	--disable-slotmem-shm \
	--disable-lbmethod-byrequests \
	--disable-lbmethod-bytraffic \
	--disable-lbmethod-bybusyness \
	--disable-lbmethod-heartbeat \
	--disable-info \
	--disable-cgid \
	--disable-vhost-alias \
	--disable-negotiation \
	--disable-actions \
	--disable-speling \
	--disable-userdir \
	--disable-file-cache \
	--disable-cache_socache \
	--disable-include \
	--disable-remoteip \
	--enable-dbd \
	--enable-authz-host \
	--enable-authz-core \
	--enable-ssl \
	--enable-ssl-staticlib-deps \
	--enable-socache-shmcb \
	--enable-dbd \
	--enable-mods-static=most \
	--with-port=$PORT
