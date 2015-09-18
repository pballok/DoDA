#ifndef I_DB_PREFERENCES_H
#define I_DB_PREFERENCES_H

class QSettings;
class QString;

class IDBPreferences {
public:
    virtual ~IDBPreferences() { }

    virtual QString db_name() const = 0;
    virtual void set_db_name(const QString& db_name) = 0;

    virtual QString db_host() const = 0;
    virtual void set_db_host(const QString& db_host) = 0;

    virtual QString db_user() const = 0;
    virtual void set_db_user(const QString& db_user) = 0;

    virtual QString db_password() const = 0;
    virtual void set_db_password(const QString& db_password) = 0;

protected:
    virtual void readDBPreferences(const QSettings& pref_file) = 0;
    virtual void writeDBPreferences(QSettings& pref_file) const = 0;
};

#endif
