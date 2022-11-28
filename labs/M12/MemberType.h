//
// Created by Mark Chouinard on 11/27/22.
//
#include <string>
#ifndef M12_MEMBERTYPE_H
#define M12_MEMBERTYPE_H
using namespace std;

/**
 * MemberType class
 */
class MemberType {
private:
    int ID, bought, spent;
    string name;
public:
    MemberType(int id, int bought, int spent, const string &name);

    MemberType();

    int getId() const;

    void setId(int id);

    int getBought() const;

    void setBought(int bought);

    int getSpent() const;

    void setSpent(int spent);

    const string &getName() const;

    void setName(const string &name);

    void spend( int amount, bool output = false );

    void buy( int amount, bool output = false );

    void summary() const;

};


#endif //M12_MEMBERTYPE_H
