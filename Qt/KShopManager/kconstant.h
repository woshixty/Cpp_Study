#ifndef KCONSTANT_H
#define KCONSTANT_H

// TODO 2022 06 04 将枚举迭代为QT枚举类

// 登陆返回结果
enum UserLoginTypeErr {SUCCESS = 0, USER_NULL, PASSWORD_ERR};

// 操作类型：增删改查询
enum ActionType {INSERT = 0, DELETE, UPDATE, SELECT};

// 商品
enum ProductCategory {COMPUTER_C = 1, PHONE_C, FOOD_C, CLOTHING_C};

#endif // KCONSTANT_H
