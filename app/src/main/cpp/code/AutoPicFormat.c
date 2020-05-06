//If the game fails to load a picture file, it will change its suffix to that of another format and try to load it again.

#include <string.h>
#include <stdbool.h>
#include "easytech.h"
#include "ecLibrary.h"

static int Attempt = 0;
static bool Unexpected = false;

def_easytech(_Z13ecTextureLoadPKcRiS1_Rj)

bool _Z13ecTextureLoadPKcRiS1_Rj(const char *name, int *w, int *h, unsigned int *handler) {
    if (Unexpected)
        return false;
    if (Attempt >= 4) {
        Attempt = 0;
        return false;
    }
    if (easytech(_Z13ecTextureLoadPKcRiS1_Rj)(name, w, h, handler)) {
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
    return _Z17ecWEBPTextureLoadPKcRiS1_Rj(s, w, h, handler);
}

def_easytech(_Z16ecPVRTextureLoadPKcRiS1_Rj)

bool
_Z16ecPVRTextureLoadPKcRiS1_Rj(const char *name, int *w, int *h, unsigned int *handler) {
    if (Attempt >= 4) {
        Attempt = 0;
        return false;
    }
    Unexpected = true;
    if (easytech(_Z16ecPVRTextureLoadPKcRiS1_Rj)(name, w, h, handler)) {
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
    return _Z13ecTextureLoadPKcRiS1_Rj(s, w, h, handler);
}

def_easytech(_Z16ecETCTextureLoadPKcRiS1_Rj)

bool
_Z16ecETCTextureLoadPKcRiS1_Rj(const char *name, int *w, int *h, unsigned int *handler) {
    if (Attempt >= 4) {
        Attempt = 0;
        return false;
    }
    Unexpected = true;
    if (easytech(_Z16ecETCTextureLoadPKcRiS1_Rj)(name, w, h, handler)) {
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
    return _Z16ecPVRTextureLoadPKcRiS1_Rj(s, w, h, handler);
}

def_easytech(_Z17ecWEBPTextureLoadPKcRiS1_Rj)

bool
_Z17ecWEBPTextureLoadPKcRiS1_Rj(const char *name, int *w, int *h, unsigned int *handler) {
    if (Attempt >= 4) {
        Attempt = 0;
        return false;
    }
    if (easytech(_Z17ecWEBPTextureLoadPKcRiS1_Rj)(name, w, h, handler)) {
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
    return _Z16ecETCTextureLoadPKcRiS1_Rj(s, w, h, handler);
}
