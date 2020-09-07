FROM alpine:3.12.0 as core
RUN \
	apk add --no-cache ca-certificates build-base bison git pcre-dev openssl-dev postgresql-dev expat-dev zlib-dev libexecinfo-dev \
	&& cp -R /usr/include/libpq* /home \
	&& cp /usr/include/pg* /home \
	&& cp /usr/include/postgres_ext.h /home \
	&& apk del postgresql-dev \
	&& apk add libpq \
	&& ln -s /usr/lib/libpq.so.5 /usr/lib/libpq.so \
	&& mv /home/* /usr/include \
	&& mkdir serenity \
	&& cd serenity \
	&& git clone --depth=1 https://github.com/SBKarr/apache-httpd-serenity.git \
	&& cd apache-httpd-serenity \
	&& ./configure-alpine.sh /serenity/apache \
	&& make -j4 \
	&& make install \
	&& cd .. \
	&& rm -rf apache-httpd-serenity \
	&& apk del bison \
	&& mkdir /usr/include/postgresql \
	&& ln -s /usr/include/libpq-fe.h /usr/include/postgresql/libpq-fe.h \
	&& apk del build-base git
