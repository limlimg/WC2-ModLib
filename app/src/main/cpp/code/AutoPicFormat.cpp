//If the game fails to load a picture file, it will change its suffix to that of another format and try to load it again.

#include <cstring>
#include "easytech.h"
#include "ecLibrary.h"

static int Attempt = 0;
static bool Unexpected = false;

def_easytech(_Z13ecTextureLoadPKcRiS1_Rj)

bool ecTextureLoad(const char *name, int &w, int &h, unsigned int &handler) {
    if (Unexpected)
        return false;
    if (Attempt >= 4) {
        Attempt = 0;
        return false;
    }
    if (easytech(_Z13ecTextureLoadPKcRiS1_Rj)(name, &w, &h, &handler)) {
        Attempt = 0;
        return true;
    }
    size_t length = strlen(name);
    if (length < 3)
        return false;
    char s[64];
    strcpy(s, name);
    strcpy(&s[length - 3], "webp");
    Attempt++;
    return ecWEBPTextureLoad(s, w, h, handler);
}

def_easytech(_Z16ecPVRTextureLoadPKcRiS1_Rj)

bool ecPVRTextureLoad(const char *name, int &w, int &h, unsigned int &handler) {
    if (Attempt >= 4) {
        Attempt = 0;
        return false;
    }
    Unexpected = true;
    if (easytech(_Z16ecPVRTextureLoadPKcRiS1_Rj)(name, &w, &h, &handler)) {
        Unexpected = false;
        Attempt = 0;
        return true;
    }
    Unexpected = false;
    size_t length = strlen(name);
    if (length < 3)
        return false;
    char s[64];
    strcpy(s, name);
    strcpy(&s[length - 3], "png");
    Attempt++;
    return ecTextureLoad(s, w, h, handler);
}

def_easytech(_Z16ecETCTextureLoadPKcRiS1_Rj)

bool ecETCTextureLoad(const char *name, int &w, int &h, unsigned int &handler) {
    if (Attempt >= 4) {
        Attempt = 0;
        return false;
    }
    Unexpected = true;
    if (easytech(_Z16ecETCTextureLoadPKcRiS1_Rj)(name, &w, &h, &handler)) {
        Unexpected = false;
        Attempt = 0;
        return true;
    }
    Unexpected = false;
    size_t length = strlen(name);
    if (length < 3)
        return false;
    char s[64];
    strcpy(s, name);
    strcpy(&s[length - 3], "pvr");
    Attempt++;
    return ecPVRTextureLoad(s, w, h, handler);
}

def_easytech(_Z17ecWEBPTextureLoadPKcRiS1_Rj)

bool ecWEBPTextureLoad(const char *name, int &w, int &h, unsigned int &handler) {
    if (Attempt >= 4) {
        Attempt = 0;
        return false;
    }
    if (easytech(_Z17ecWEBPTextureLoadPKcRiS1_Rj)(name, &w, &h, &handler)) {
        Attempt = 0;
        return true;
    }
    size_t length = strlen(name);
    if (length < 4)
        return false;
    char s[64];
    strcpy(s, name);
    strcpy(&s[length - 4], "pkm");
    Attempt++;
    return ecETCTextureLoad(s, w, h, handler);
}
