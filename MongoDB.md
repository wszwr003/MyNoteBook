# [MongoDB CentOS install](https://docs.mongodb.com/v3.2/tutorial/install-mongodb-on-red-hat/)
1. Create a `/etc/yum.repos.d/mongodb-org-3.2.repo` file so that you can install MongoDB directly
    ```
    [mongodb-org-3.2]
    name=MongoDB Repository
    baseurl=https://repo.mongodb.org/yum/redhat/$releasever/mongodb-org/3.2/x86_64/
    gpgcheck=1
    enabled=1
    gpgkey=https://www.mongodb.org/static/pgp/server-3.2.asc
    ```
2. `sudo yum install -y mongodb-org`
3. `vi /etc/mongod.conf` //config bind_ip 
4. `sudo service mongod start`
# [MongoDB node.js Using](http://mongodb.github.io/node-mongodb-native/2.2/quick-start/quick-start/)
