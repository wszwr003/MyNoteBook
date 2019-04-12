# Redis(remote dictionary service)
[简述关系型数据库和非关系型数据库](https://www.jianshu.com/p/fd7b422d5f93)
## RDS 关系型数据库服务（Relational Database Service）
Oracle,MySQL,SQLite
## NoSQL 非关系型数据库
* Redis 面向高性能**并发**读写的key-value数据库
* MongoDB 面向海量数据访问的面向文档数据库
* Cassandra，HBase 面向可扩展性的分布式数据库
* Elasticsearch 面向搜索数据内容的搜索引擎
***
Redis是一个开源的使用ANSI C语言编写、支持网络、可基于内存亦可持久化的日志型、Key-Value数据库，并提供多种语言的API。  
* 键值存储的本质是能够在键内存储一些称为值(value)的数据。只有当我们知道用于存储它的确切键（key），才可以检索此数据。
## [Try Redis](http://try.redis.io/)
* key&value
```
SET server:name "WANG"
GET server:name --return:"WANG"
```
```
SET connections 10
SETNX connections 100  //set-if-not-exists
INCR connections => 11 //atomically increment 原子递增
INCR connections => 12
DEL connections        //delete
INCR connections => 1
```
```
SET resource:lock "Redis Demo"
EXPIRE resource:lock 120  //有效期120秒
TTL resource:lock => 113  //查询剩余时间
// after 113s
TTL resource:lock => -2   //-2 表示已经到期键值对不再存在 
SET resource:lock "Redis Demo 1"
EXPIRE resource:lock 120
TTL resource:lock => 119
SET resource:lock "Redis Demo 2"
TTL resource:lock => -1   //-1 表示永远存在
```
* list
```
RPUSH friends "Alice"
RPUSH friends "Bob"   
LPUSH friends "Sam"
LRANGE friends 0 -1 => 1) "Sam", 2) "Alice", 3) "Bob"
LRANGE friends 0 1 => 1) "Sam", 2) "Alice"
LRANGE friends 1 2 => 1) "Alice", 2) "Bob"
LLEN friends => 3
LPOP friends => "Sam" //左一删除并返回
RPOP friends => "Bob"
```
* set  
集合类似于列表，除了它没有特定的顺序，每个元素只能出现一次(unique?)。
```
SADD superpowers "flight" //set-add
SADD superpowers "x-ray vision"
SADD superpowers "reflexes" 
SREM superpowers "reflexes" //set-remove
SISMEMBER superpowers "flight" => 1  //set-is-member?
SISMEMBER superpowers "reflexes" => 0
SMEMBERS superpowers => 1) "flight", 2) "x-ray vision"
SADD birdpowers "pecking"
SADD birdpowers "flight"
SUNION superpowers birdpowers => 1) "pecking", 2) "x-ray vision", 3) "flight" 
//set-union return list
```
* sorted set  
集合是一种非常方便的数据类型，但由于它们未排序，因此无法解决许多问题。这就是Redis引入Sorted Sets的原因。
```
ZADD hackers 1940 "Alan Kay"
ZADD hackers 1906 "Grace Hopper"
ZADD hackers 1953 "Richard Stallman"
ZADD hackers 1965 "Yukihiro Matsumoto"
ZADD hackers 1916 "Claude Shannon"
ZADD hackers 1969 "Linus Torvalds"
ZADD hackers 1957 "Sophie Wilson"
ZADD hackers 1912 "Alan Turing"
ZRANGE hackers 2 4 => 1) "Claude Shannon", 2) "Alan Kay", 3) "Richard Stallman"
```
* hashes  
哈希是字符串字段和字符串值之间的映射，因此它们是表示对象的完美数据类型。
```
HSET user:1000 name "John Smith"
HSET user:1000 email "john.smith@example.com"
HSET user:1000 password "s3cret"
HGETALL user:1000
HMSET user:1001 name "Mary Jones" password "hidden" email "mjones@example.com"
HGET user:1001 name => "Mary Jones"
HSET user:1000 visits 10
HINCRBY user:1000 visits 1 => 11  //原子方式递增
HINCRBY user:1000 visits 10 => 21 //原子方式递增
HDEL user:1000 visits
HINCRBY user:1000 visits 1 => 1
```
