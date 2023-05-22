# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 14:51:27 by Romain            #+#    #+#              #
#    Updated: 2022/10/12 05:27:19 by rcuminal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster-slim

WORKDIR /var/www

RUN apt-get update && apt-get install nginx openssl -y

RUN service nginx start
COPY conf/default /etc/nginx/sites-enabled/default

RUN mkdir -p /etc/nginx/ssl/ && \
        openssl req -x509 -nodes \
		-out /etc/nginx/ssl/rcuminal.42.fr.crt \
		-keyout /etc/nginx/ssl/rcuminal.42.fr.key \
		-subj "/C=FR/ST=IDF/L=Paris/O=42/OU=42/CN=rcuminal.42.fr/UID=rcuminal"

#RUN nginx -t


EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]  