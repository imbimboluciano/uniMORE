
To fetch and install an application image
```powershell
$ docker pull 'image:version'
```

To show all the images installed on own local machine
```powershell
$ docker images
> REPOSITORY   TAG       IMAGE ID       CREATED       SIZE
> redis        latest    e40e2763392d   3 weeks ago   138MB
> archlinux    latest    1e73f0f3a7ab   6 weeks ago   434MB
```
Tag is the basically the version of image.

To run an image and create a container
```powershell
$ docker run 'image:version' #also pulls image
$ docker run -d 'image' #start image in deattached mode
$ docker run -p 'hostport:containerport' 'image' #run with port binding
$ docker run --name 'name' #start container with a custom name (by default docker give a random name)
```

To list all running containers
```powershell
$ docker ps
$ docker ps -a #list running and stopped container
```

To restart container (for example after a crash):
```powershell
$ docker stop <container_id>
$ docker start <container_id>
```

To troubleshooting
```powershell
$ docker logs <container_id>
$ docker logs <names>
$ docker exec -it <container_id> #interactive terminal to manage container
```




```powershell
$ docker build -t 'nameapp:version' /directory_where_deploy/
```


AWS ECR (Container Services)

docker-compose file
```py
version: '3'

services:

# my-app:

# image: ${docker-registry}/my-app:1.0

# ports:

# - 3000:3000

mongodb:

image: mongo

ports:

- 27017:27017

environment:

- MONGO_INITDB_ROOT_USERNAME=admin

- MONGO_INITDB_ROOT_PASSWORD=password

volumes:

- mongo-data:/data/db

mongo-express:

image: mongo-express

restart: always # fixes MongoNetworkError when mongodb is not ready when mongo-express starts

ports:

- 8080:8081

environment:

- ME_CONFIG_MONGODB_ADMINUSERNAME=admin

- ME_CONFIG_MONGODB_ADMINPASSWORD=password

- ME_CONFIG_MONGODB_SERVER=mongodb

volumes:

mongo-data:

driver: local
```


```docker
FROM node:13-alpine

  

ENV MONGO_DB_USERNAME=admin \

MONGO_DB_PWD=password

  

RUN mkdir -p /home/app

  

COPY ./app /home/app

  

# set default dir so that next commands executes in /home/app dir

WORKDIR /home/app

  

# will execute npm install in /home/app because of WORKDIR

RUN npm install

  

# no need for /home/app/server.js because of WORKDIR

CMD ["node", "server.js"]
```