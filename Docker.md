## busybox

`$ docker run -it --rm busybox`  
`$ docker start -ai 9833283cd6fa`

## docker shell

```sh
docker run -ti $image $shell
docker exec -ti $contain $shell
```

## how to run node project

### Run a single Node.js script

```shell
$ docker run -it --rm --name my-running-script -v "$PWD":/usr/src/app -w /usr/src/app node:8 node your-daemon-or-script.js
```

### Use Dockerfile

```Dockerfile
FROM node:alpine
EXPOSE 1883 8888

WORKDIR /home/node/app
COPY package*.json ./
RUN npm install
COPY . .
CMD ["node","server.js"]
```

You can then build image and run the image:

```shell
$ docker commit -m="描述消息" -a="作者" 容器ID或容器名 镜像名:TAG //生成新镜像
$ docker build -t <your username>/node-web-app:tags .
$ docker push <your username>/node-web-app:tags
$ docker pull <your username>/node-web-app:tags
$ docker run -p 49160:8080 -d <your username>/node-web-app
```

### Use Docker-compose

```yml
version: "2"
services:
  node:
    image: "node:8"
    user: "node"
    working_dir: /home/node/app
    environment:
      - NODE_ENV=production
    volumes:
      - ./:/home/node/app
    expose:
      - "8081"
    command: "npm start"
```

You can then run using Docker compose:

```shell
$ docker-compose up -d
```
