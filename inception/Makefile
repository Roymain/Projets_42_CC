NAME 		= 	 Inception

COMPIL		=	docker-compose --project-directory srcs -p $(NAME)

PATH_DATA	=	/home/rcuminal/data

up : $(PATH_DATA)
	$(COMPIL) up --build -d
#-d

build:
	$(COMPIL) build

down :
	$(COMPIL) down

ps:
	$(COMPIL) ps

purge :
	docker system prune -a -f 

$(PATH_DATA) :
	mkdir -p $(PATH_DATA) 2> /dev/null || true

