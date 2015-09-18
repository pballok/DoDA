#ifndef DODA_PREFERENCES_H
#define DODA_PREFERENCES_H

#include <preferences.h>

#include "idbpreferences.h"

class DoDAPreferences : public Preferences,
                        public IDBPreferences {
public:
    DoDAPreferences() : Preferences("DoDAServer", "0.2.0") { }

    virtual QString db_name() const { return db_name_; }
    virtual void set_db_name(const QString& db_name) { db_name_ = db_name; }

    virtual QString db_host() const { return db_host_; }
    virtual void set_db_host(const QString& db_host) { db_host_ = db_host; }

    virtual QString db_user() const { return db_user_; }
    virtual void set_db_user(const QString& db_user) { db_user_ = db_user; }

    virtual QString db_password() const { return db_password_; }
    virtual void set_db_password(const QString& db_password) { db_password_ = db_password; }

protected:
    virtual void readDBPreferences(const QSettings& pref_file);
    virtual void writeDBPreferences(QSettings& pref_file) const;

    virtual void readCustomPreferences(const QSettings& pref_file) { readDBPreferences(pref_file); }
    virtual void writeCustomPreferences(QSettings& pref_file) const { writeDBPreferences(pref_file); }

private:
    QString db_name_;
    QString db_host_;
    QString db_user_;
    QString db_password_;
};

#endif
