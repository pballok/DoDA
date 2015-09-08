#ifndef DB_ACCESS_INTERFACE_H
#define DB_ACCESS_INTERFACE_H

class DBAccessInterface {
public:
    virtual ~DBAccessInterface() { }

    virtual std::string db_name() = 0;
    virtual std::string db_user() = 0;
    virtual std::string db_password() = 0;
};

#endif
