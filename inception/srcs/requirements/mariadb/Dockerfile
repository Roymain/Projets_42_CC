# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/30 16:27:40 by Romain            #+#    #+#              #
#    Updated: 2022/10/12 03:30:54 by rcuminal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster-slim


RUN apt-get update && apt-get install mariadb-client mariadb-server -y 

EXPOSE 3306

COPY tools/script.sh /tmp

ENTRYPOINT ["bash", "/tmp/script.sh"]
