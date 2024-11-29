#include "User.h"

User::User(int id) : id_(id) {}

int User::getId() const {
    return id_;
}
