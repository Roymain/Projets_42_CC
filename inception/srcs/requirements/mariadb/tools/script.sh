#!/bin/bash
# init database
mysql_install_db --basedir=/usr --datadir=/var/lib/mysql --user=mysql --rpm

sql_file='/tmp/init_db.sql'

cat << EOF > $sql_file
DELETE FROM mysql.user WHERE User='';
DROP DATABASE IF EXISTS test;
CREATE DATABASE IF NOT EXISTS $WP_DB; 
GRANT ALL PRIVILEGES ON $WP_DB.* TO '$WP_DB_USER'@'%' IDENTIFIED BY '$WP_DB_PWD' WITH GRANT OPTION;
FLUSH PRIVILEGES;
EOF

cat <<EOF >> /etc/mysql/my.cnf
[mysqld]
skip-networking=0
skip-bind-address
EOF

service mysql start
mysql < $sql_file
rm -f $sql_file
service mysql stop &>/dev/null

exec mysqld_safe --datadir=/var/lib/mysql