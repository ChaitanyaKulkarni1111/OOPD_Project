#ifndef USER_H
#define USER_H

class User {
public:
    User(int id);
    int getId() const;

private:
    int id_;
};

#endif // USER_H
