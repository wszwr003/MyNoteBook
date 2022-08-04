# SPRING-BOOT 数据库初始化的方式

[官方说明](https://www.baeldung.com/spring-boot-data-sql-and-schema-sql)

1. 数据库容器启动时自动初始化：

```yml
#docker-compose.yml
version: "3"
services:
  mysql:
    #...
    #...
    volumes:
      - ./mysql-init.sql:/docker-entrypoint-initdb.d/mysql-init.sql:ro
```

2. 通过代码自动初始化

```properties
spring.jpa.hibernate.ddl-auto=create/update/create-drop(default)/validate
```

3. 通过脚本初始化（schema.sql/data.sql）

```properties
#/resources/schema.sql
#/resources/data/sql
spring.jpa.hibernate.ddl-auto=none
spring.sql.init.mode=always
```

4. 先通过代码初始化，再通过脚本更新

```properties
#/resources/schema.sql
#/resources/data/sql
spring.jpa.hibernate.ddl-auto=create/update/create-drop(default)/validate
spring.jpa.defer-datasource-initialization=true
```
