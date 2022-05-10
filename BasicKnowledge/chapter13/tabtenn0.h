//
// Created by 谢庭宇 on 2022/5/10.
//

#ifndef BASICKNOWLEDGE_TABTENN0_H
#define BASICKNOWLEDGE_TABTENN0_H
#include <string>
using namespace std;

class TableTennisPlayer {
private:
    string firstname;
    string lastname;
    bool hasTable;
public:
    TableTennisPlayer(const string & fn = "none", const string & ln = "none", bool ht = false);
    void Name() const;
    bool HasTable() const {return hasTable;}
    void ResetTable(bool v) {hasTable = v;}
};

class RatedPlayer : public TableTennisPlayer {
    
};


#endif //BASICKNOWLEDGE_TABTENN0_H
