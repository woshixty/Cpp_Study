//
// Created by 谢庭宇 on 2022/5/11.
//

#include "Builder.h"
#include "Product.h"
#include "Director.h"

using namespace std;

int main() {
    Director *d = new Director(new ConcreteBuilder());
    d->Construct();
    return 0;
}