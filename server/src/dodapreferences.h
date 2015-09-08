#include <preferences.h>

class DoDAPreferences : public Preferences {
public:
    DoDAPreferences() : Preferences("DoDAServer", "1.0.0") { }
};
