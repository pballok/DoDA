#include <preferences.h>

class DoDAPreferences : public Preferences {
public:
    DoDAPreferences() : Preferences("DoDAServer", "0.1.0") { }
};
