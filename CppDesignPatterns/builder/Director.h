//
// Created by 谢庭宇 on 2022/5/11.
//

#ifndef CPPDESIGNPATTERNS_DIRECTOR_H
#define CPPDESIGNPATTERNS_DIRECTOR_H

class Builder;

class Director {
public:
    Director(Builder *bld);

    ~Director();

    void Construct();

private:
    Builder *_bld;
};


#endif //CPPDESIGNPATTERNS_DIRECTOR_H
