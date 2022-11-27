//
// Created by Mark Chouinard on 11/27/22.
//
#include <string>
#ifndef M12_MEMBERTYPE_H
#define M12_MEMBERTYPE_H
using namespace std;

class MemberType {
private:
    int ID, bought, spent;
    string name;
public:
    int getId() const;

    void setId(int id);

    int getBought() const;

    void setBought(int bought);

    int getSpent() const;

    void setSpent(int spent);

    const string &getName() const;

    void setName(const string &name);


};


#endif //M12_MEMBERTYPE_H
