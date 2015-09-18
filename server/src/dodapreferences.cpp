#include <QSettings>

#include "dodapreferences.h"

void DoDAPreferences::readDBPreferences(const QSettings& pref_file) {
    db_name_     = pref_file.value("DataBase/Name").toString();
    db_host_     = pref_file.value("DataBase/Host", "localhost").toString();
    db_user_     = pref_file.value("DataBase/User").toString();
    db_password_ = pref_file.value("DataBase/Password").toString();
}

void DoDAPreferences::writeDBPreferences(QSettings& pref_file) const {
    pref_file.setValue("DataBase/Name",     db_name_);
    pref_file.setValue("DataBase/Host",     db_host_);
    pref_file.setValue("DataBase/User",     db_user_);
    pref_file.setValue("DataBase/Password", db_password_);
}
