#!/bin/bash

wp core --allow-root download --locale=fr_FR

check=$(mysqladmin ping -h mariadb --protocol=tcp -u$WP_DB_USER -p$WP_DB_PWD)
while [ -z "$check" ]; do
	echo 'waiting db ...'
	sleep 2
	check=$(mysqladmin ping -h mariadb --protocol=tcp -u$WP_DB_USER -p$WP_DB_PWD)
done

wp config create --allow-root --dbname=$WP_DB --dbuser=$WP_DB_USER --dbpass=$WP_DB_PWD --dbhost=mariadb:3306 --force --locale=fr_FR
if ! wp core is-installed --allow-root; then
  wp core install --allow-root --url=$WP_URL --title=$WP_TITLE --admin_user=$WP_ADMIN_USER --admin_password=$WP_ADMIN_PWD  --admin_email=$WP_ADMIN_USER_MAIL
fi
if ! wp  user create $WP_USER $WP_USER_MAIL --allow-root --user_pass=$WP_PWD --role=author; then
    wp  user update --allow-root $WP_USER --user_email=$WP_USER_MAIL --user_pass=$WP_PWD --role=author
fi

php-fpm7.3 -F -R