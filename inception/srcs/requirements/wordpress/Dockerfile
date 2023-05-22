FROM debian:buster-slim

RUN apt-get update && apt-get install php-cli php-mysql wget php-fpm mariadb-client -y

WORKDIR /var/www/wordpress

RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && mv wp-cli.phar /usr/local/bin/wp && chmod +x /usr/local/bin/wp

EXPOSE 9000

RUN echo "listen = 9000" >> /etc/php/7.3/fpm/pool.d/www.conf
RUN 	chown -R  www-data:www-data /var/www/wordpress/ && mkdir -p /run/php

COPY tools/script.sh /tmp

ENTRYPOINT ["bash", "/tmp/script.sh"]
