#include <iostream>
#include "mysql.h"

int mysqlTestConn(){
    // 分配连接句柄
    MYSQL *conn = mysql_init(nullptr);
 
    // 创建连接
    if (!mysql_real_connect(conn, "127.0.0.1", "root", "13535135356", "dbtest1", 0, nullptr, 0)) {
        std::cerr << "连接失败： " << mysql_error(conn) << std::endl;
        return 1;
    }

    // 执行查询
    if (mysql_query(conn, "show tables;")) {
        std::cerr << "查询失败： " << mysql_error(conn) << std::endl;
        return 1;
    }

    // 获取结果集
    MYSQL_RES *result = mysql_use_result(conn);
 
    // 输出查询结果
    std::cout << "MySQL Tables in db_name:" << std::endl;

    MYSQL_ROW row = mysql_fetch_row(result);
    while (row != nullptr)
        std::cout << row[0] << std::endl;
 
    // 释放结果集
    mysql_free_result(result);
 
    // 关闭连接
    mysql_close(conn);
    return 0;
}