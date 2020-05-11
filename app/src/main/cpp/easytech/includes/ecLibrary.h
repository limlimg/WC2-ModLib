#ifndef EASYTECH_ECLIBRARY_H
#define EASYTECH_ECLIBRARY_H

#include "cxx.h"
#include "cxxvector.h"
#include "cxxlist.h"
#include "cxxmap.h"
#include "cxxstring.h"

#if defined(__LP64__)
typedef unsigned int color_t;
#else
typedef unsigned long color_t;
#endif

#ifdef __cplusplus
template<class T>
struct TFreeList {
    void *StorageSpace;
    void **PointerList;
    int TotalSize;
    int RemainingSize;
};
#define TFreeList(type) TFreeList<type>
#else
struct TFreeList {
    void *StorageSpace;
    void **PointerList;
    int TotalSize;
    int RemainingSize;
};
#define TFreeList(type) struct TFreeList
#endif

#ifdef __cplusplus

void ecGameUpdate(float time);

const char *GetPath(const char *FileName, const char *);

bool ecTextureLoad(const char *name, int &w, int &h, unsigned int &handler);

bool ecPVRTextureLoad(const char *name, int &w, int &h, unsigned int &handler);

bool ecETCTextureLoad(const char *name, int &w, int &h, unsigned int &handler);

bool ecWEBPTextureLoad(const char *name, int &w, int &h, unsigned int &handler);

#endif

__BEGIN_DECLS
void _Z12ecGameUpdatef(float time);

const char *_Z7GetPathPKcS0_(const char *FileName, const char *);

bool _Z13ecTextureLoadPKcRiS1_Rj(const char *name, int *w, int *h, unsigned int *handler);

bool _Z16ecPVRTextureLoadPKcRiS1_Rj(const char *name, int *w, int *h, unsigned int *handler);

bool _Z16ecETCTextureLoadPKcRiS1_Rj(const char *name, int *w, int *h, unsigned int *handler);

bool _Z17ecWEBPTextureLoadPKcRiS1_Rj(const char *name, int *w, int *h, unsigned int *handler);

__END_DECLS

struct ecTexture;

struct ecImageAttr {
    struct ecTexture *Texture;
    float x;
    float y;
    float w;
    float h;
    float refx;
    float refy;
};

struct ecTextureRes {
    map(string, ecTexture *) Texture;
    map(string, ecImageAttr *) Image;
#ifdef __cplusplus

    ecImageAttr *
    CreateImage(const char *name, const char *TextureName, float x, float y, float w, float h,
                float refx, float refy);

    void CreateImage(const char *name, ecTexture *, float x, float y, float w, float h, float refx,
                     float refy);

    ecTexture *CreateTexture(const char *name, bool pvr, bool pkm, bool webp);

    ecImageAttr *GetImage(const char *name);

    ecTexture *GetTexture(const char *name);

    bool LoadRes(const char *name, bool shrink);

    void Release();

    void ReleaseTexture(ecTexture *);

    void UnloadRes(const char *name);

#endif
};

__BEGIN_DECLS
void _ZN12ecTextureResC1Ev(struct ecTextureRes *self);

void _ZN12ecTextureResD1Ev(struct ecTextureRes *self);

struct ecImageAttr *
_ZN12ecTextureRes11CreateImageEPKcS1_ffffff(struct ecTextureRes *self, const char *name,
                                            const char *TextureName, float x, float y, float w,
                                            float h, float refx, float refy);

void
_ZN12ecTextureRes11CreateImageEPKcP9ecTextureffffff(struct ecTextureRes *self, const char *name,
                                                    struct ecTexture *, float x, float y, float w,
                                                    float h, float refx, float refy);

struct ecTexture *
_ZN12ecTextureRes13CreateTextureEPKcbbb(struct ecTextureRes *self, const char *name, bool pvr,
                                        bool pkm, bool webp);

struct ecImageAttr *_ZN12ecTextureRes8GetImageEPKc(struct ecTextureRes *self, const char *name);

struct ecTexture *_ZN12ecTextureRes10GetTextureEPKc(struct ecTextureRes *self, const char *name);

bool _ZN12ecTextureRes7LoadResEPKcb(struct ecTextureRes *self, const char *name, bool shrink);

void _ZN12ecTextureRes7ReleaseEv(struct ecTextureRes *self);

void _ZN12ecTextureRes14ReleaseTextureEP9ecTexture(struct ecTextureRes *self, struct ecTexture *);

void _ZN12ecTextureRes9UnloadResEPKc(struct ecTextureRes *self, const char *name);

__END_DECLS

struct ecTextureRect {
    float x;
    float y;
    float w;
    float h;
    float refx;
    float refy;
};

struct ecImage {
    struct ecTexture *Texture;
    struct ecTextureRect TextureRect;
    float x1CfTextureW;
    float x20fTextureH;
    float x24fRealRenderX;
    float x28fRealRenderY;
    unsigned long x2Cuicolor;
    float x30fxdivTextureW;
    float x34fydivTextureH;
    float x38fRealRenderXaddW;
    float x3CfRealRenderY;
    unsigned long x40uicolor;
    float x44f_xaddw_divTextureW;
    float x48fydivTextureH;
    float x4CfRealRenderXaddW;
    float x50fRealRenderYaddH;
    unsigned long x54uicolor;
    float x58f_xaddw_divTextureW;
    float x5Cf_yaddh_divTextureH;
    float x60fRealRenderX;
    float x64fRealRenderYaddH;
    unsigned long x68uicolor;
    float x6CfxdivTextureW;
    float x70f_yaddh_divTextureH;
    int x74iBlendMode;
    bool x78b3Filp[3];
#ifdef __cplusplus

    void Init(ecImageAttr *);

    void Init(ecTexture *, float x, float y, float w, float h);

    void Render(float x, float y);

    void Render(float x, float y, float w, float h);

    void Render4V(float, float, float, float, float, float, float, float);

    void Render4VC(float, float, float, float, float, float, float, float, int, float);

    void RenderEx(float x, float y, float angle, float xFactor, float yFactor);

    void RenderStretch(float, float, float, float);

    void SetAlpha(float Alpha, int type);

    void SetColor(unsigned long color, int type);

    void SetFlip(bool, bool, bool);

    void SetTexture(ecTexture *);

    void SetTextureRect(const ecTextureRect &);

    void SetTextureRect(float x, float y, float w, float h);

#endif
};

__BEGIN_DECLS
void _ZN7ecImageC1EP11ecImageAttr(struct ecImage *self, struct ecImageAttr *);

void
_ZN7ecImageC1EP9ecTextureffff(struct ecImage *self, struct ecTexture *, float x, float y, float w,
                              float h);

void _ZN7ecImageC1EP9ecTextureRK13ecTextureRect(struct ecImage *self, struct ecTexture *,
                                                const struct ecTextureRect *);

void _ZN7ecImageD1Ev(struct ecImage *self);

void _ZN7ecImage4InitEP11ecImageAttr(struct ecImage *self, struct ecImageAttr *);

void _ZN7ecImage4InitEP9ecTextureffff(struct ecImage *self, struct ecTexture *, float x, float y,
                                      float w, float h);

void _ZN7ecImage6RenderEff(struct ecImage *self, float x, float y);

void _ZN7ecImage6RenderEffff(struct ecImage *self, float x, float y, float w, float h);

void
_ZN7ecImage8Render4VEffffffff(struct ecImage *self, float, float, float, float, float, float, float,
                              float);

void
_ZN7ecImage9Render4VCEffffffffif(struct ecImage *self, float, float, float, float, float, float,
                                 float, float, int, float);

void _ZN7ecImage8RenderExEfffff(struct ecImage *self, float x, float y, float angle, float xFactor,
                                float yFactor);

void _ZN7ecImage13RenderStretchEffff(struct ecImage *self, float, float, float, float);

void _ZN7ecImage8SetAlphaEfi(struct ecImage *self, float Alpha, int type);

void _ZN7ecImage8SetColorEmi(struct ecImage *self, unsigned long color, int type);

void _ZN7ecImage7SetFlipEbbb(struct ecImage *self, bool, bool, bool);

void _ZN7ecImage10SetTextureEP9ecTexture(struct ecImage *self, struct ecTexture *);

void
_ZN7ecImage14SetTextureRectERK13ecTextureRect(struct ecImage *self, const struct ecTextureRect *);

void _ZN7ecImage14SetTextureRectEffff(struct ecImage *self, float x, float y, float w, float h);

__END_DECLS

struct ecCharImage;

struct ecUniFont {
    map(const long, ecCharImage*) Encoding;
    struct ecCharImage *CharImage;
    struct ecImage *FontImage;
    struct ecTexture *FontTexture;
    int FontHeight;
#ifdef __cplusplus

    void Init(const char *name, bool);

    void Release();

    ecCharImage *GetCharImage(wchar_t);

#endif
};

__BEGIN_DECLS
void _ZN9ecUniFontC1Ev(struct ecUniFont *self);

void _ZN9ecUniFontD1Ev(struct ecUniFont *self);

void _ZN9ecUniFont4InitEPKcb(struct ecUniFont *self, const char *name);

void _ZN9ecUniFont7ReleaseEv(struct ecUniFont *self);

struct ecCharImage *_ZN9ecUniFont12GetCharImageEt(struct ecUniFont *self, wchar_t);

__END_DECLS

struct ecText {
    vector(ecCharImage*) TextWithFont;
    struct ecUniFont *Font;
    float FontSize[2];
    color_t AlphaColor;
#ifdef __cplusplus

    void Init(ecUniFont *);

    void DrawText(float x, float y, int line);

    float GetHeight();

    int GetNumLines();

    float GetStringWidth(int line, bool SingleLine);

    void SetAlpha(float alpha);

    void SetColor(color_t);

    void SetText(const char *text);

    void SetText(const wchar_t *text);

#endif
};

__BEGIN_DECLS
void _ZN6ecTextC1Ev(struct ecText *self);

void _ZN6ecTextD1Ev(struct ecText *self);

void _ZN6ecText4InitEP9ecUniFont(struct ecText *self, struct ecUniFont *);

void _ZN6ecText8DrawTextEffi(struct ecText *self, float x, float y, int line);

float _ZN6ecText9GetHeightEv(struct ecText *self);

int _ZN6ecText11GetNumLinesEv(struct ecText *self);

float _ZN6ecText14GetStringWidthEib(struct ecText *self, int line, bool SingleLine);

void _ZN6ecText8SetAlphaEf(struct ecText *self, float alpha);

void _ZN6ecText8SetColorEm(struct ecText *self, color_t);

void _ZN6ecText7SetTextEPKc(struct ecText *self, const char *text);

void _ZN6ecText7SetTextEPKt(struct ecText *self, const wchar_t *text);

__END_DECLS

struct ecLabelText {
    string TextString;
    int FontW;
    int FontH;
    color_t AlphaColor;
    int SpaceW;
    int SpaceH;
    struct ecTexture *TextTexture;
    struct ecImage *TextImage;
#ifdef __cplusplus

    void Init(const char *, int, int, int, int);

    void DrawText(float x, float y);

    void SetAlpha(float alpha);

    void SetColor(color_t color);

    void SetText(const char *text);

#endif
};

__BEGIN_DECLS
void _ZN11ecLabelTextC1Ev(struct ecLabelText *self);

void _ZN11ecLabelTextD1Ev(struct ecLabelText *self);

void _ZN11ecLabelText4InitEPKciiii(struct ecLabelText *self, const char *, int, int, int, int);

void _ZN11ecLabelText8DrawTextEff(struct ecLabelText *self, float x, float y);

void _ZN11ecLabelText8SetAlphaEf(struct ecLabelText *self, float alpha);

void _ZN11ecLabelText8SetColorEm(struct ecLabelText *self, color_t color);

void _ZN11ecLabelText7SetTextEPKc(struct ecLabelText *self, const char *text);

__END_DECLS

struct ecEffect;

struct ecParticleSystem;

struct ecEffectManager {
    list(ecEffect*) Effect;
    TFreeList(ecParticleSystem) ParticleSystem;
#ifdef __cplusplus

    static ecEffectManager *Instance();

    ecEffect *AddEffect(const char *name, bool);

    ecEffect *CreateEffect(const char *name);

    void RemoveAll();

    void Render();

    void Update(float time);

#endif
};

__BEGIN_DECLS
struct ecEffectManager *_ZN15ecEffectManager8InstanceEv();

void _ZN15ecEffectManagerC1Ev(struct ecEffectManager *self);

void _ZN15ecEffectManagerD1Ev(struct ecEffectManager *self);

struct ecEffect *
_ZN15ecEffectManager9AddEffectEPKcb(struct ecEffectManager *self, const char *name, bool);

struct ecEffect *
_ZN15ecEffectManager12CreateEffectEPKc(struct ecEffectManager *self, const char *name);

void _ZN15ecEffectManager9RemoveAllEv(struct ecEffectManager *self);

void _ZN15ecEffectManager6RenderEv(struct ecEffectManager *self);

void _ZN15ecEffectManager6UpdateEf(struct ecEffectManager *self, float time);

__END_DECLS

struct ecLine;
struct ecTriple;
struct ecQuad;

struct ecGraphics {
    float TouchMutiplier[2];
    int TouchSize[2];
    int DisplaySize[2];
    int eq0;
    int WidthMode;
    //Member Variables is incomplete
#ifdef __cplusplus

    static ecGraphics *Instance();

    void Init(int, int, int, int, int);

    void BindTexture(ecTexture *);

    ecTexture *CreateTextureWithString(const char *, const char *, int, int, int, int);

    void Fade(float);

    void Flush();

    void FreeTexture(ecTexture *);

    ecTexture *LoadTexture(const char *name);

    ecTexture *LoadPVRTexture(const char *name);

    ecTexture *LoadETCTexture(const char *name);

    ecTexture *LoadWEBPTexture(const char *name);

    void RenderBegin();

    void RenderCircle(float x, float y, float r, color_t color);

    void RenderEndEv();

    void RenderLine(const ecLine *);

    void RenderQuad(const ecQuad *);

    void RenderRect(float x, float y, float w, float h, unsigned long color);

    void RenderTriple(const ecTriple *);

    void SetBlendMode(int);

    void SetOrientation(int);

    void SetViewPoint(float x, float y, float scale);

    void Shutdown();

#endif
};

__BEGIN_DECLS
struct ecGraphics *_ZN10ecGraphics8InstanceEv();

void _ZN10ecGraphicsC1Ev(struct ecGraphics *self);

void _ZN10ecGraphicsD1Ev(struct ecGraphics *self);

void _ZN10ecGraphics4InitEiiiii(struct ecGraphics *self, int, int, int, int, int);

void _ZN10ecGraphics11BindTextureEP9ecTexture(struct ecGraphics *self, struct ecTexture *);

struct ecTexture *
_ZN10ecGraphics23CreateTextureWithStringEPKcS1_iiii(struct ecGraphics *self, const char *,
                                                    const char *, int, int, int, int);

void _ZN10ecGraphics4FadeEf(struct ecGraphics *self, float);

void _ZN10ecGraphics5FlushEv(struct ecGraphics *self);

void _ZN10ecGraphics11FreeTextureEP9ecTexture(struct ecGraphics *self, struct ecTexture *);

struct ecTexture *_ZN10ecGraphics11LoadTextureEPKc(struct ecGraphics *self, const char *name);

struct ecTexture *_ZN10ecGraphics14LoadPVRTextureEPKc(struct ecGraphics *self, const char *name);

struct ecTexture *_ZN10ecGraphics14LoadETCTextureEPKc(struct ecGraphics *self, const char *name);

struct ecTexture *_ZN10ecGraphics15LoadWEBPTextureEPKc(struct ecGraphics *self, const char *name);

void _ZN10ecGraphics11RenderBeginEv(struct ecGraphics *self);

void _ZN10ecGraphics12RenderCircleEfffm(struct ecGraphics *self, float x, float y, float r,
                                        color_t color);

void _ZN10ecGraphics9RenderEndEv(struct ecGraphics *self);

void _ZN10ecGraphics10RenderLineEPK6ecLine(struct ecGraphics *self, const struct ecLine *);

void _ZN10ecGraphics10RenderQuadEPK6ecQuad(struct ecGraphics *self, const struct ecQuad *);

void _ZN10ecGraphics10RenderRectEffffm(struct ecGraphics *self, float x, float y, float w, float h,
                                       unsigned long color);

void _ZN10ecGraphics12RenderTripleEPK8ecTriple(struct ecGraphics *self, const struct ecTriple *);

void _ZN10ecGraphics12SetBlendModeEi(struct ecGraphics *self, int);

void _ZN10ecGraphics14SetOrientationEi(struct ecGraphics *self, int);

void _ZN10ecGraphics12SetViewPointEfff(struct ecGraphics *self, float x, float y, float scale);

void _ZN10ecGraphics8ShutdownEv(struct ecGraphics *self);

__END_DECLS

#endif //EASYTECH_ECLIBRARY_H
