#ifndef KCONSTANT_H
#define KCONSTANT_H

// 登陆返回结果
enum UserLoginTypeErr {L_SUCCESS = 0, USER_NULL, PASSWORD_ERR};

// 注册返回结果
enum UserRegisterTypeErr {R_SUCCESS = 10, USER_EXIST, R_ERR};

// 操作类型：增删改查询
enum ActionType {INSERT = 20, DELETE, UPDATE, SELECT};

#endif // KCONSTANT_H
