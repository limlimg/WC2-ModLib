#include <stddef.h>
#include <dlfcn.h>
#include "easytech.h"

#define got(name) __attribute__((visibility("hidden"))) size_t easytech(name) = (size_t)lazybind;
#define bss(name, size) __attribute__((weak)) __attribute__((visibility("protected"))) char name[size];

#define plt(name) __attribute__((weak)) __attribute__((visibility("protected"))) void name() {asm(\
        "lea 5(%rip), %rax\n\t"\
        "addq (%rax), %rax\n\t"\
        "jmp *(%rax)\n\t"\
        ".quad "__easytech(name)" - .");}

#define Thn(name, offset) __attribute__((weak)) __attribute__((visibility("protected"))) void _ZThn##offset##_##name() {asm(\
        "sub $"#offset", %rdi\n\t"\
        "jmp _Z"#name"\n\t");}

#define off(name, offset) easytech(name) = BaseAddress + offset;

static const char GameLib[] = "libeasytech.so";

void __attribute__((visibility("hidden"))) lazybind() {
    asm(
    "push %rax\n\t"
    "push %rdi\n\t"
    "push %rsi\n\t"
    "push %rdx\n\t"
    "push %rcx\n\t"
    "push %r8\n\t"
    "push %r9\n\t"
    "subq $0x48, %rsp\n\t"
    "movsd %xmm7, 0x40(%rsp)\n\t"
    "movsd %xmm6, 0x38(%rsp)\n\t"
    "movsd %xmm5, 0x30(%rsp)\n\t"
    "movsd %xmm4, 0x28(%rsp)\n\t"
    "movsd %xmm3, 0x20(%rsp)\n\t"
    "movsd %xmm2, 0x18(%rsp)\n\t"
    "movsd %xmm1, 0x10(%rsp)\n\t"
    "movsd %xmm0, 0x8(%rsp)\n\t"
    "call resolvesymbol\n\t"
    "movsd 0x8(%rsp), %xmm0\n\t"
    "movsd 0x10(%rsp), %xmm1\n\t"
    "movsd 0x18(%rsp), %xmm2\n\t"
    "movsd 0x20(%rsp), %xmm3\n\t"
    "movsd 0x28(%rsp), %xmm4\n\t"
    "movsd 0x30(%rsp), %xmm5\n\t"
    "movsd 0x38(%rsp), %xmm6\n\t"
    "movsd 0x40(%rsp), %xmm7\n\t"
    "addq $0x48, %rsp\n\t"
    "pop %r9\n\t"
    "pop %r8\n\t"
    "pop %rcx\n\t"
    "pop %rdx\n\t"
    "pop %rsi\n\t"
    "pop %rdi\n\t"
    "pop %rax\n\t"
    "jmp *(%rax)\n\t");
}

got(_ZN7_JNIEnv16CallObjectMethodEP8_jobjectP10_jmethodIDz)

got(_ZN7_JNIEnv23CallStaticBooleanMethodEP7_jclassP10_jmethodIDz)

got(_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz)

got(_ZN7_JNIEnv21CallStaticFloatMethodEP7_jclassP10_jmethodIDz)

got(_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz)

got(_Z24ecGameDidEnterBackgroundv)

got(_Z14ecGameShutdownv)

got(_Z7GetPathPKcS0_)

got(_Z18ecPurchasedProducti)

got(_Z10ecGameInitiiiii)

got(_Z18ecSetInAppPurchasePFviE)

got(_Z11ecGamePausev)

got(_Z25ecGameWillEnterForegroundv)

got(_Z12ecGameResumev)

got(_Z13ecBackPressedv)

got(_ZN13CStateManager8InstanceEv)

got(_ZN13CStateManager11GetStatePtrE6EState)

got(_ZN10CMenuState8ShowExitEv)

got(_Z12ecGameUpdatef)

got(_Z12ecGameRenderv)

got(_ZN10ecGraphics8InstanceEv)

got(_ZN15ecMultipleTouch8InstanceEv)

got(_ZN15ecMultipleTouch10TouchBeganEff)

got(_Z12ecTouchBeginffi)

got(_ZN15ecMultipleTouch5ResetEv)

got(_ZN15ecMultipleTouch10TouchMovedEff)

got(_Z11ecTouchMoveffi)

got(_ZN15ecMultipleTouch10TouchEndedEff)

got(_Z10ecTouchEndffi)
bss(g_Commander, 376)

got(_ZN10CCommander8BuyMedalEi)

got(_ZN10CCommander4SaveEv)

got(_Z17ecSetProductPriceiPKc)

got(_ZN6ecFileC1Ev)

got(_ZN6ecFile11IsFlieExistEPKc)

got(_ZN6ecFileD1Ev)

got(_Z9Get2XPathPKcS0_)

got(_Z15GetDocumentPathPKc)

got(_Z16GetEditorResPathPKc)

got(_ZN10ecGraphicsC2Ev)

got(_ZN10ecGraphicsC1Ev)

got(_ZN10ecGraphics4InitEiiiii)

got(_ZN10ecGraphics8ShutdownEv)

got(_ZN10ecGraphics14SetOrientationEi)

got(_ZN10ecGraphics11RenderBeginEv)

got(_ZN10ecGraphics13CreateTextureEii)

got(_ZN10ecGraphics11FreeTextureEP9ecTexture)

got(_ZN10ecGraphics5FlushEv)

got(_ZN10ecGraphics9RenderEndEv)

got(_ZN10ecGraphics12SetViewPointEfff)

got(_ZN10ecGraphics12SetBlendModeEi)

got(_ZN10ecGraphics11BindTextureEP9ecTexture)

got(_ZN10ecGraphics23CreateTextureWithStringEPKcS1_iiii)

got(_Z19ecTextureWithStringPKcS0_iiRiS1_Rj)

got(_ZN10ecGraphics10RenderLineEPK6ecLine)

got(_ZN10ecGraphics12RenderTripleEPK8ecTriple)

got(_ZN10ecGraphics10RenderQuadEPK6ecQuad)

got(_ZN10ecGraphics10RenderRectEffffm)

got(_ZN10ecGraphics12RenderCircleEfffj)

got(_ZN10ecGraphics4FadeEf)

got(_ZN10ecGraphicsD2Ev)

got(_ZN10ecGraphicsD1Ev)

got(_ZN10ecGraphics11LoadTextureEPKc)

got(_Z13ecTextureLoadPKcRiS1_Rj)

got(_ZN10ecGraphics15LoadWEBPTextureEPKc)

got(_Z17ecWEBPTextureLoadPKcRiS1_Rj)

got(_ZN10ecGraphics14LoadPVRTextureEPKc)

got(_Z16ecPVRTextureLoadPKcRiS1_Rj)

got(_ZN10ecGraphics14LoadETCTextureEPKc)

got(_Z16ecETCTextureLoadPKcRiS1_Rj)

got(_ZN15ecMultipleTouchD2Ev)

got(_ZN15ecMultipleTouchD1Ev)

got(_ZN15ecMultipleTouchC2Ev)

got(_ZN15ecMultipleTouchC1Ev)

got(_ZN6ecFileC2Ev)

got(_ZN3MD5C1Ev)

got(_ZN6ecFile5CloseEv)

got(_ZN6ecFileD2Ev)

got(_ZN6ecFile4OpenEPKcS1_)

got(_ZN6ecFile4ReadEPvj)

got(_ZN6ecFile5WriteEPKvj)

got(_ZN6ecFile4SeekEli)

got(_ZN6ecFile9GetCurPosEv)

got(_ZN6ecFile7GetSizeEv)

got(_ZN6ecFile12CheckJavaDexEv)

got(_ZN6ecFile18GetFileDataFromZipEPKcS1_Pm)

got(_ZN3MD55resetEv)

got(_ZN3MD56updateEPKvm)

got(_ZN3MD58toStringEv)

got(_ZN8CheckMD5C1Ev)

got(_ZN8CheckMD56INfileEPKcS1_)

got(_ZN6ecFile21CheckFileExistFromZipEPKcS1_)

got(_ZN3MD5C2Ev)

got(_ZN3MD56encodeEPKmPhm)

got(_ZN3MD56decodeEPKhPmm)

got(_ZN3MD59transformEPKh)

got(_ZN3MD56updateEPKhm)

got(_ZN3MD5C2EPKvm)

got(_ZN3MD5C1EPKvm)

got(_ZN3MD56updateERSt14basic_ifstreamIcSt11char_traitsIcEE)

got(_ZN3MD5C2ERSt14basic_ifstreamIcSt11char_traitsIcEE)

got(_ZN3MD5C1ERSt14basic_ifstreamIcSt11char_traitsIcEE)

got(_ZN3MD56updateERKSs)

got(_ZN3MD5C2ERKSs)

got(_ZN3MD5C1ERKSs)

got(_ZN3MD55finalEv)

got(_ZN3MD56digestEv)

got(_ZN3MD516bytesToHexStringEPKhm)

got(_ZN8CheckMD5C2Ev)

got(_ZN10CCommanderD2Ev)

got(_ZN10CCommanderD1Ev)

got(_Z19GetCommanderAbilityi)

got(_ZN10CCommanderC2Ev)

got(_ZN10CCommanderC1Ev)

got(_ZN10CCommander4LoadEv)

got(_ZN10CCommander15GetUpgradeMedalEv)

got(_ZN10CCommander12CheckUpgardeEv)

got(_ZN10CCommander7UpgradeEv)

got(_ZN10CCommander10IsMaxLevelEv)

got(_ZN10CCSoundBox11GetInstanceEv)

got(_ZN10CCSoundBox6PlaySEEPKc)

got(_ZN10CCommander16GetWarMedalLevelE11WARMEDAL_ID)

got(_ZN10CCommander19GetNeedUpgradeMedalE11WARMEDAL_ID)

got(_ZN10CCommander20CheckUpgradeWarMedalE11WARMEDAL_ID)

got(_ZN10CCommander15UpgradeWarMedalE11WARMEDAL_ID)

got(_ZN10CCommander20SetNumPlayedBatttlesEii)

got(_ZN10CCommander20GetNumPlayedBatttlesEi)

got(_ZN10CCommander15SetBattlePlayedEii)

got(_ZN10CCommander17GetNumBattleStarsEii)

got(_ZN10CCommander17SetNumBattleStarsEiii)

got(_ZN10CCommander16GetCommanderDataER13CommanderData)
bss(g_PlayerManager, 248)

got(_ZN14CPlayerManager7ReleaseEv)
bss(g_Font1, 80)

got(_ZN9ecUniFont7ReleaseEv)
bss(g_Font2, 80)
bss(g_Font3, 80)
bss(g_Font6, 80)
bss(g_Font7, 80)
bss(g_Num1, 80)
bss(g_Num3, 80)
bss(g_Num4, 80)
bss(g_Num5, 80)
bss(g_Num8, 80)

got(_ZN10CCSoundBox8UnloadSEEPKc)

got(_ZN13CStateManager4TermEv)

got(_ZN10GUIManager8InstanceEv)

got(_ZN10GUIElement12FreeAllChildEv)

got(_ZN10GUIManager16ReleaseTexureResEv)

got(_ZN10CCSoundBox7DestroyEv)

got(_ZN10CObjectDef8InstanceEv)

got(_ZN10CObjectDef7DestroyEv)
bss(g_StringTable, 48)

got(_ZN13ecStringTable5ClearEv)
bss(g_LocalizableStrings, 48)
bss(g_Num4b, 80)

got(_Z13ecGameWaitingb)

got(_ZN13CStateManager15EnterBackgroundEv)
bss(g_GameSettings, 24)

got(_ZN10CCSoundBox14SetMusicVolumeEi)

got(_ZN10CCSoundBox11SetSEVolumeEi)

got(_ZN10CCSoundBox11ResumeMusicEv)

got(_ZN13CStateManager15EnterForegroundEv)

got(_ZN14CPlayerManager6UpdateEf)

got(_ZN13CStateManager6UpdateEf)

got(_ZN10GUIManager6UpdateEf)

got(_ZN16GUIMotionManager8InstanceEv)

got(_ZN16GUIMotionManager10ProcMotionEv)

got(_ZN10CCSoundBox11UpdateSoundEv)

got(_ZN13CStateManager6RenderEv)

got(_ZN10GUIManager6RenderEv)

got(_ZN10GUIManager9PostEventERK5Event)

got(_ZN13CStateManager10TouchBeginEffi)

got(_ZN13CStateManager9TouchMoveEffi)

got(_ZN13CStateManager8TouchEndEffi)

got(_ZN13CStateManager11BackPressedEv)

got(_Z15ecAccelerometerfff)

got(_Z13ecScrollWheelfff)

got(_ZN13CStateManager11ScrollWheelEfff)

got(_Z9ecKeyDowni)

got(_ZN13CStateManager7KeyDownEi)

got(_Z18ecSetShowReviewFucPFvvE)

got(_Z12ecShowReviewv)

got(_Z17ecGetProductPricei)

got(_Z15ecInAppPurchasei)

got(_Z18ecAppWillTerminatev)

got(_Z22ecApplicationTerminatev)

got(_Z14ecLoadSettingsv)

got(_ZN13CGameSettings12LoadSettingsEv)

got(_Z14ecIsFullScreenv)

got(_Z15ecSetFullScreenb)

got(_ZN13CGameSettings12SaveSettingsEv)

got(_Z13SetAIRandSeedi)

got(_Z11SetRandSeedi)

got(_ZN10GUIManager4InitERK7GUIRect)

got(_ZN13CStateManager4InitEv)

got(_ZN10CLogoStateC1Ev)

got(_ZN10CMenuStateC1Ev)

got(_ZN11CMatchStateC1Ev)

got(_ZN10CLoadStateC1Ev)

got(_ZN10CGameStateC1Ev)

got(_ZN10CEditStateC1Ev)

got(_ZN13CStateManager13RegisterStateEP10CBaseState)

got(_ZN13CStateManager11SetCurStateE6EState)

got(_ZN13ecStringTable4LoadEPKc)

got(_ZN13ecStringTable9GetStringEPKc)

got(_ZN10CObjectDef4InitEv)

got(_ZN10CCSoundBox6LoadSEEPKc)

got(_ZN9ecUniFont4InitEPKcb)

got(_ZN10CBaseState7OnEnterEv)

got(_ZN10CBaseState6OnExitEv)

got(_ZN10CBaseState10TouchBeginEffi)

got(_ZN10CBaseState9TouchMoveEffi)

got(_ZN10CBaseState8TouchEndEffi)

got(_ZN10CBaseState11BackPressedEv)

got(_ZN10CBaseState7KeyDownEi)

got(_ZN10CBaseState11ScrollWheelEfff)

got(_ZN10CBaseState15EnterBackgroundEv)

got(_ZN10CBaseState15EnterForegroundEv)

got(_ZN10CEditState7KeyDownEi)

got(_ZN10CEditState7OnEventERK5Event)

got(_ZN10CEditStateD2Ev)

got(_ZN13CTouchInertiaD1Ev)

got(_ZN10CEditStateD1Ev)

got(_ZN10CEditStateD0Ev)

got(_ZN10CEditState6UpdateEf)

got(_ZN13CTouchInertia6UpdateEf)

got(_ZN13CTouchInertia8GetSpeedERfS0_)
bss(g_Scene, 352)

got(_ZN15ecEffectManager8InstanceEv)

got(_ZN15ecEffectManager6UpdateEf)

got(_ZN6CScene6UpdateEf)

got(_ZN6CScene4MoveEii)

got(_ZN13CTouchInertia4StopEv)

got(_ZN7CCamera13SetAutoFixPosEb)

got(_ZN10CEditState6RenderEv)

got(_ZN6CScene6RenderEv)

got(_ZN6CScene14RenderAreasTaxEv)

got(_ZN6CScene15RenderAreasTypeEv)

got(_ZN10CEditState10TouchBeginEffi)

got(_ZN13CTouchInertia10TouchBeginEffi)

got(_ZN10CEditState9TouchMoveEffi)

got(_ZN13CTouchInertia9TouchMoveEffi)

got(_ZN10CEditState8TouchEndEffi)

got(_ZN13CTouchInertia8TouchEndEffi)

got(_ZN6CScene12ScreenToAreaEff)

got(_ZN6CScene15GetSelectedAreaEv)

got(_ZN6CScene12UnselectAreaEv)

got(_ZN6CScene10SelectAreaEP5CArea)

got(_ZN10CEditStateC2Ev)

got(_ZN13CTouchInertiaC1Ev)

got(_ZN10CEditState8InitGameEv)
bss(g_GameManager, 248)

got(_ZN12CGameManager7NewGameEiiii)
bss(g_SoundRes, 92)

got(_ZN9CSoundRes4LoadEv)
bss(g_GameRes, 1424)

got(_ZN8CGameRes4LoadEv)

got(_ZN6CScene4InitEPKci)

got(_ZN13CTouchInertia4InitEv)

got(_ZN10CEditState7OnEnterEv)

got(_ZN10GUIManager6FadeInEi)

got(_ZN10CEditState11ReleaseGameEv)

got(_ZN6CScene7ReleaseEv)

got(_ZN8CGameRes7ReleaseEv)

got(_ZN9CSoundRes6UnloadEv)

got(_ZN10CEditState6OnExitEv)

got(_ZN16GUIMotionManager11ClearMotionEv)

got(_ZN9CActionAID2Ev)

got(_ZN9CActionAI18setActionNodeClearEv)

got(_ZN9CActionAID1Ev)

got(_Z11GetRandSeedv)

got(_Z7GetRandv)

got(_ZN6CFightC2Ev)

got(_ZN6CFightC1Ev)

got(_ZN6CFightD2Ev)

got(_ZN6CFightD1Ev)

got(_ZN6CFight16AirStrikesAttackEP8CCountryii)

got(_ZN6CScene7GetAreaEi)

got(_ZN8CCountry16GetWarMedalLevelE11WARMEDAL_ID)

got(_ZN10CObjectDef10GetArmyDefEiPKc)

got(_ZN6CFight16AirStrikesAttackEii)

got(_ZN6CFight17GetAttackerResultEi)

got(_ZN6CFight17GetDefenderResultEi)

got(_ZN6CFight12GetAttackAddEi)

got(_ZN6CFight12GetDefendAddEi)

got(_ZN6CFight11ApplyResultEv)

got(_ZN5CArea7GetArmyEi)

got(_ZN5CArea16LostArmyStrengthEii)

got(_ZN6CScene25AdjacentAreasEncirclementEi)

got(_ZN8CCountry10AddDestroyEi)

got(_ZN5CArea23ReduceConstructionLevelEv)

got(_ZN5CArmy6IsNavyEv)

got(_ZN15ecEffectManager9AddEffectEPKcb)

got(_ZN8ecEffect6FireAtEfff)
bss(g_FightTextMgr, 120)

got(_ZN13CFightTextMgr7AddTextEffPKcj)

got(_ZN9CSoundRes10PlayCharSEE10SND_EFFECT)

got(_ZN5CArmy6AddExpEi)
bss(_ZN9CActionAI9_instanceE, 8)

got(_Z9GetAIRandv)

got(_ZN8CCountry13IsLocalPlayerEv)

got(_ZN6CScene9GainMedalEff)

got(_ZN5CArea19DestroyConstructionEv)

got(_ZN5CArea12ClearAllArmyEv)

got(_ZN5CArmy12BreakthroughEv)

got(_ZN5CArea10OccupyAreaEPS_)

got(_ZN6CFight12NormalAttackEii)

got(_ZN5CArmy11GetNumDicesEv)

got(_ZN8CCountry17GetCommanderLevelEv)

got(_Z14GetArmyAbilityi)

got(_ZN5CArmy25GetNumDicesIfLostStrengthEi)

got(_ZN6CFight11FirstAttackEii)

got(_ZN6CFight12SecondAttackEv)

got(_ZN10CFightTextC2Ev)

got(_ZN6ecTextC1Ev)

got(_ZN10CFightTextC1Ev)

got(_ZN10CFightTextD2Ev)

got(_ZN6ecTextD1Ev)

got(_ZN10CFightTextD1Ev)

got(_ZN13CFightTextMgrD2Ev)

got(_ZN9ecUniFontD1Ev)

got(_ZN13CFightTextMgrD1Ev)

got(_ZN10CFightText4InitEffP9ecUniFont)

got(_ZN6ecText4InitEP9ecUniFont)

got(_ZN10CFightText7SetTextEPKc)

got(_ZN6ecText7SetTextEPKc)

got(_ZN10CFightText8SetColorEj)

got(_ZN6ecText8SetColorEj)

got(_ZN10CFightText6UpdateEf)

got(_ZN6ecText8SetAlphaEf)

got(_ZN10CFightText6RenderEv)

got(_ZN6ecText8DrawTextEffi)

got(_ZN13CFightTextMgrC2Ev)

got(_ZN9ecUniFontC1Ev)

got(_ZN13CFightTextMgrC1Ev)

got(_ZN13CFightTextMgr4InitEv)

got(_ZN13CFightTextMgr7ReleaseEv)

got(_ZN13CFightTextMgr6UpdateEf)

got(_ZN13CFightTextMgr6RenderEv)

got(_ZN13CActionAssistD2Ev)

got(_ZN13CActionAssistD1Ev)

got(_ZN12CGameManagerD2Ev)

got(_ZN12CGameManagerD1Ev)

got(_Z13GetNumBattlesi)

got(_Z16GetBattleKeyNameiiPc)

got(_Z18GetConquestKeyNameiPc)

got(_Z17GetBattleFileNameiiiiPc)

got(_Z24GetNumMultiPlayerBattlesi)

got(_Z24GetBattleBelligerentListPKcRSt4listI11BelligerentSaIS2_EEb)

got(_ZN13TiXmlDocumentC1EPKc)

got(_ZN13TiXmlDocument8LoadFileE13TiXmlEncoding)
bss(_ZN11TiXmlString8nullrep_E, 24)

got(_ZN9TiXmlNodeD2Ev)

got(_ZN9TiXmlNode10FirstChildEPKc)

got(_ZNK12TiXmlElement9AttributeEPKc)

got(_ZNK12TiXmlElement17QueryIntAttributeEPKcPi)

got(_ZN12CGameManagerC2Ev)

got(_ZN12CGameManagerC1Ev)

got(_ZN12CGameManager4InitEv)

got(_ZN12CGameManager20SetPlayercountrynameEiPKc)

got(_ZN12CGameManager11GetPlayerNoEPKc)

got(_ZN12CGameManager20GetPlayerCountryNameEi)

got(_ZN12CGameManager26SetConquestPlayerCountryIDEPKc)

got(_ZN10CObjectDef12GetBattleDefEPKc)

got(_ZN12CGameManager8LoadGameEPKc)

got(_ZN12CGameManager9RetryGameEv)

got(_ZN12CGameManager8SaveGameEPKc)

got(_ZN8CCountry11SaveCountryEP15SaveCountryInfo)

got(_ZN5CArea8SaveAeraEP12SaveAreaInfo)

got(_ZN12CGameManager13GetSaveHeaderEPKcR10SaveHeader)

got(_ZN12CGameManager11ClearBattleEv)

got(_ZN8CCountryD1Ev)

got(_ZN12CGameManager7ReleaseEv)

got(_ZN12CGameManager10NextBattleEv)

got(_ZN12CGameManager12IsLastBattleEv)

got(_ZN12CGameManager15GetNumCountriesEv)

got(_ZN12CGameManager17GetCountryByIndexEi)

got(_ZN12CGameManager11FindCountryEPKc)

got(_ZN12CGameManager13GetCurCountryEv)

got(_ZN12CGameManager13InitCameraPosEv)

got(_ZN8CCountry19GetHighestValueAreaEv)

got(_ZN6CScene15SetCameraToAreaEi)

got(_ZN12CGameManager16GetPlayerCountryEv)

got(_ZN12CGameManager21GetLocalPlayerCountryEv)

got(_ZN12CGameManager15GetNumDialoguesEv)

got(_ZN12CGameManager18GetDialogueByIndexEi)

got(_ZN12CGameManager10SaveBattleEPKc)

got(_ZN12TiXmlElementC1EPKc)

got(_ZN12TiXmlElement12SetAttributeEPKci)

got(_ZN12TiXmlElement12SetAttributeEPKcS1_)

got(_ZN12TiXmlElement18SetDoubleAttributeEPKcd)

got(_ZN9TiXmlNode12LinkEndChildEPS_)

got(_ZN8CCountry16GetCommanderNameEv)

got(_ZN6CScene11GetNumAreasEv)

got(_ZNK13TiXmlDocument8SaveFileEv)

got(_ZN12CGameManager14GetCurDialogueEv)

got(_ZN12CGameManager20GetCurDialogueStringEPc)

got(_ZN12CGameManager12NextDialogueEv)

got(_ZN12CGameManager18GetNumVictoryStarsEv)

got(_ZN12CGameManager17CheckAndSetResultEv)

got(_ZN8CCountry12IsConquestedEv)

got(_ZN12CGameManager13BattleVictoryEv)

got(_ZN12CGameManager21GetNewDefeatedCountryEv)

got(_ZN12CGameManager12IsManipulateEv)

got(_ZN8CCountry14IsActionFinishEv)

got(_ZN12CGameManager9TurnBeginEv)

got(_ZN8CCountry9TurnBeginEv)

got(_ZN10CGameState16UpdateActionInfoEv)

got(_ZN10CGameState18PlayerCountryBeginEv)

got(_ZN8CCountry6ActionERK13CountryAction)

got(_ZN12CGameManager7TurnEndEv)

got(_ZN8CCountry7TurnEndEv)

got(_ZN12CGameManager7EndTurnEv)

got(_ZN10CGameState12ShowDialogueEPKcS1_b)
bss(_ZN13CActionAssist9_instanceE, 8)

got(_ZN10CGameState14HideAIProgressEv)

got(_ZN12CGameManager4NextEv)

got(_ZN9CActionAI16setCpuDriverbyIdEii)

got(_ZN14CPlayerManager13DoFrontActionEv)

got(_ZN5CArea13SetArmyActiveEib)

got(_ZN12CGameManager10GameUpdateEf)

got(_ZN8CCountry6UpdateEf)

got(_ZN10CGameState12ShowDefeatedEP8CCountry)

got(_ZN10CGameState16UpdateAIProgressEv)

got(_ZN12CGameManager24MovePlayerCountryToFrontEv)

got(_ZN12CGameManager12RealLoadGameEPKc)

got(_ZN8CCountryC1Ev)

got(_ZN8CCountry4InitEPKcS1_)

got(_ZN8CCountry11LoadCountryEPK15SaveCountryInfo)

got(_ZN7CCamera6SetPosEffb)

got(_ZN5CArea8LoadAreaEPK12SaveAreaInfo)

got(_ZN8CCountry7AddAreaEi)

got(_ZN12CGameManager10LoadBattleEPKc)

got(_ZNK12TiXmlElement20QueryDoubleAttributeEPKcPd)

got(_ZN8CCountry12SetCommanderEPKc)

got(_ZN14CPlayerManager21FindPlayerByCountryIDEPKc)

got(_ZN6CScene14SetAreaCountryEiP8CCountry)

got(_ZN5CArea15SetConstructionEii)

got(_ZN5CArmyC1Ev)

got(_ZN5CArmy4InitEP7ArmyDefP8CCountry)

got(_ZN5CArea7AddArmyEP5CArmyb)

got(_ZN5CArmy16ResetMaxStrengthEb)

got(_ZN12CGameManager10InitBattleEv)

got(_ZN6CScene20AllAreasEncirclementEv)

got(_ZN14CPlayerManager18SetPlayerOfCountryEv)

got(_ZN8CGameRes14RenderArmyInfoEiffiiiii)

got(_ZN7ecImage6RenderEff)

got(_ZN7ecImage8SetColorEmi)

got(_ZN7ecImage8RenderExEfffff)

got(_ZN8CGameRes20RenderCommanderMedalEiffi)

got(_ZN8CGameRes12RenderArmyHPEffii)

got(_ZN8CGameRes15RenderArmyLevelEffi)

got(_ZN8CGameRes21RenderArmyMovementNumEffi)

got(_ZN8CGameRes18RenderConstructionEiiff)

got(_ZN8CGameRes10RenderPortEff)

got(_ZN8CGameRes18RenderInstallationEiff)

got(_ZN8CGameRes11GetBattleBGEPKc)

got(_ZN12ecTextureRes8GetImageEPKc)

got(_ZN8CGameRes12GetFlagImageEPKc)

got(_ZN8CGameResC2Ev)

got(_ZN12ecTextureResC1Ev)

got(_ZN12ecTextureResD1Ev)

got(_ZN8CGameResC1Ev)

got(_ZN8CGameResD2Ev)

got(_ZN8CGameResD1Ev)

got(_ZN15ecEffectManager9RemoveAllEv)

got(_ZN18ecEffectResManager8InstanceEv)

got(_ZN18ecEffectResManager19ReleaseAllEffectResEv)

got(_ZN18ecEffectResManager17ReleaseTextureResEv)

got(_ZN7ecImageD1Ev)

got(_ZN12ecTextureRes7ReleaseEv)

got(_ZN8CGameRes12GetArmyImageEPKcib)

got(_ZN8CGameRes10RenderArmyEPKciiffimbf)

got(_ZN8CGameRes12RenderUIArmyEPKcffibiiiii)

got(_ZN8CGameRes22RenderAICommanderMedalEiffPKci)

got(_ZN8CGameRes18RenderUIAttackArmyEPKcffiiiiiiib)

got(_ZN8CGameRes18RenderUIDefendArmyEPKcffiiiiiiib)

got(_ZN8CGameRes10RenderFlagEPKcff)

got(_ZN12ecTextureRes7LoadResEPKcb)

got(_ZN7ecImageC1EP11ecImageAttr)

got(_ZN7ecImageC1EP9ecTextureffff)

got(_ZN18ecEffectResManager14LoadTextureResEPKc)

got(_ZN18ecEffectResManager13LoadEffectResEPKc)

got(_ZN13CGameSettingsD2Ev)

got(_ZN13CGameSettingsD1Ev)

got(_ZN13CGameSettingsC2Ev)

got(_ZN13CGameSettingsC1Ev)

got(_ZN10CGameStateD2Ev)

got(_ZN10CGameStateD1Ev)

got(_ZN10CGameStateD0Ev)

got(_ZN10CGameState6RenderEv)

got(_ZN15ecEffectManager6RenderEv)

got(_ZN10CGameState8TouchEndEffi)

got(_ZN10GUIBuyCard10GetSelCardEv)

got(_ZN8CCountry19CheckCardTargetAreaEP7CardDefi)

got(_ZN6GUITax7SetAreaEi)

got(_ZN5CArea8IsActiveEv)

got(_ZN10GUIElement4HideEv)

got(_ZN10GUIElement4ShowEv)

got(_ZN6CScene13CheckMoveableEiii)

got(_ZN14CPlayerManager22SendPacketToAllPlayersE9PACKET_IDPKvi)

got(_ZN10GUISelArmy7SetAreaEi)

got(_ZN6CScene15CheckAttackableEiii)

got(_ZN12GUIAttackBox9SetAttackEii)

got(_ZN10CGameState9TouchMoveEffi)

got(_ZN6CScene13ScreenToSceneERfS0_)

got(_ZN7CCamera14SetPosAndScaleEfff)

got(_ZN10CGameState11ScrollWheelEfff)

got(_ZN10CGameState15EnterBackgroundEv)

got(_ZN10CGameStateC2Ev)

got(_ZN10CGameState8InitGameEv)

got(_ZN10GUIManager14LoadTextureResEPKcb)

got(_ZN10CGameState11ReleaseGameEv)

got(_ZN10GUIManager16UnloadTextureResEPKc)

got(_ZN10CGameState6OnExitEv)

got(_ZN10CCSoundBox11UnloadMusicEv)

got(_ZN14CPlayerManager4StopEv)

got(_ZN10GUIElement11MoveToFrontEPS_)

got(_ZN11GUIDefeated12ShowDefeatedEP8CCountry)

got(_ZN13GUIAIProgress17SetCurCountryNameEPKc)

got(_ZN10CGameState7OnEnterEv)

got(_ZN10GUIManager9AddButtonEPKcS1_RK7GUIRectP10GUIElementP9ecUniFont)

got(_ZN9GUIButton13SetBackgroundEPKc)

got(_ZN7GUIGoldC1Ev)

got(_ZN7GUIGold4InitERK7GUIRect)

got(_ZN10GUIElement8AddChildEPS_b)

got(_ZN6GUITaxC1Ev)

got(_ZN6GUITax4InitERK7GUIRect)

got(_ZN12GUISmallCardC1Ev)

got(_ZN12GUISmallCard4InitERK7GUIRect)

got(_ZN12GUIAttackBoxC1Ev)

got(_ZN12GUIAttackBox4InitERK7GUIRect)

got(_ZN10GUIElement6CenterEv)

got(_ZN11GUIPauseBoxC1Ev)

got(_ZN11GUIPauseBox4InitERK7GUIRect)

got(_ZN10GUIBuyCardC1Ev)

got(_ZN10GUIBuyCard4InitERK7GUIRect)

got(_ZN13GUIAIProgressC1Ev)

got(_ZN13GUIAIProgress4InitERK7GUIRect)

got(_ZN10GUISelArmyC1Ev)

got(_ZN10GUISelArmy4InitERK7GUIRect)

got(_ZN8GUIBeginC1Ev)

got(_ZN8GUIBegin4InitERK7GUIRect)

got(_ZN11GUIDefeatedC1Ev)

got(_ZN11GUIDefeated4InitERK7GUIRect)

got(_ZN9GUIBattleC1Ev)

got(_ZN9GUIBattle4InitERK7GUIRect)

got(_ZN11GUIDialogueC1Ev)

got(_ZN11GUIDialogue4InitERK7GUIRect)

got(_ZN16GUIMotionManager9AddMotionEP10GUIElementffft)

got(_ZN10CCSoundBox9LoadMusicEPKcS1_)

got(_ZN10CCSoundBox9PlayMusicEb)

got(_ZN12GUITutorailsC1Ev)

got(_ZN12GUITutorails4InitERK7GUIRect)

got(_ZN13GUIActionInfoC1Ev)

got(_ZN13GUIActionInfo4InitERK7GUIRect)

got(_ZN10CGameState15EnableIdleTimerEf)

got(_ZN10CGameState12StartBattaleEiiib)

got(_ZN9GUIBattle11BattleStartEiii)

got(_ZN8GUIBegin9ResetDataEv)

got(_ZN10CGameState10SelectAreaEi)

got(_ZN6CScene10SelectAreaEi)

got(_ZN10CGameState12UnselectAreaEv)

got(_ZN11GUIDialogue7ShowDlgEPKcS1_b)

got(_ZN10CGameState11ShowWarningEi)

got(_ZN10GUIWarningC1Ev)

got(_ZN10GUIWarning4InitERK7GUIRecti)

got(_ZN10CGameState6UpdateEf)

got(_ZN6CScene9IsBombingEv)

got(_ZN10GUIBuyCard13CanBuySelCardEv)

got(_ZN10GUIBuyCard13ReleaseTargetEv)

got(_ZN10GUIBuyCard15ResetCardTargetEv)

got(_ZN14CPlayerManager13GetNumActionsEv)

got(_ZN14CPlayerManager22IsDisconnectedFromHostEv)

got(_ZN13GUIActionInfo7SetInfoEPKc)

got(_ZN10CGameState15ResetTouchStateEv)

got(_ZN10CGameState11BackPressedEv)

got(_ZN10GUIManager7FadeOutEiP10GUIElement)

got(_ZN10CGameState10TouchBeginEffi)

got(_ZN10CGameState7OnEventERK5Event)

got(_ZN10GUIVictoryC1Ev)

got(_ZN10GUIVictory4InitERK7GUIRectb)

got(_ZN10GUIVictory4PlayEv)

got(_ZN16GUIMotionManager12ActiveMotionEjh)

got(_ZN14CPlayerManager18SendPacketToServerE9PACKET_IDPKvi)

got(_ZN10GUIManager13SafeFreeChildEP10GUIElement)

got(_ZN6GUIEndC1Ev)

got(_ZN6GUIEnd4InitERK7GUIRect)

got(_ZN10GUIBuyCard14ResetCardStateEv)

got(_ZN10GUIOptionsC1Ev)

got(_ZN10GUIOptions4InitERK7GUIRect)

got(_ZN7GUISaveC1Ev)

got(_ZN7GUISave4InitERK7GUIRectib)

got(_ZN12GUISmallCard7SetCardEP7CardDef)

got(_ZN14GUIBattleIntroC1Ev)

got(_ZN14GUIBattleIntro4InitERK7GUIRectii)

got(_ZN11GUIDefeated12HideDefeatedEv)

got(_ZN9GUIResultC1Ev)

got(_ZN9GUIResult4InitERK7GUIRecti)

got(_ZN14CPlayerManager16PlayerLoadFinishEP7CPlayer)

got(_ZN7GUIBankC1Ev)

got(_ZN7GUIBank4InitERK7GUIRect)

got(_ZN6GUIIapC1Ev)

got(_ZN6GUIIap4InitERK7GUIRect)

got(_ZN13ecStringTableC1Ev)

got(_ZN13ecStringTableD1Ev)

got(_ZN13GUIActionInfo8OnUpdateEf)

got(_ZN13GUIActionInfoD2Ev)

got(_ZN11ecLabelTextD1Ev)

got(_ZN10GUIElementD2Ev)

got(_ZN13GUIActionInfoD1Ev)

got(_ZN13GUIActionInfoD0Ev)

got(_ZN13GUIActionInfo8OnRenderEv)

got(_ZN10GUIElement10GetAbsRectER7GUIRect)

got(_ZN11ecLabelText8DrawTextEff)

got(_ZN13GUIActionInfoC2Ev)

got(_ZN10GUIElementC2Ev)

got(_ZN11ecLabelTextC1Ev)

got(_ZN11ecLabelText4InitEPKciiii)

got(_ZN11ecLabelText7SetTextEPKc)

got(_ZN10GUIElement7OnEventERK5Event)

got(_ZN13GUIAIProgressD2Ev)

got(_ZN13GUIAIProgressD1Ev)

got(_ZN13GUIAIProgressD0Ev)

got(_ZN13GUIAIProgress8OnRenderEv)

got(_ZN13GUIAIProgressC2Ev)
bss(_ZN10GUIElement12s_TextureResE, 96)

got(_ZN7ecImage4InitEP11ecImageAttr)

got(_ZN10GUIElement8OnUpdateEf)

got(_ZN12GUIAttackBoxD2Ev)

got(_ZN12GUIAttackBoxD1Ev)

got(_ZN12GUIAttackBoxD0Ev)

got(_ZN12GUIAttackBox8OnRenderEv)

got(_ZN5CArmy14GetMaxStrengthEv)

got(_ZN12GUIAttackBoxC2Ev)

got(_ZN11GUIButtonExC1Ev)

got(_ZN9GUIButton4InitEPKcS1_RK7GUIRectP9ecUniFont)

got(_ZN11GUIButtonEx12SetImageTextEPKcS1_)

got(_ZN12GUIAttackBox7OnEventERK5Event)

got(_ZN7GUIBank8OnUpdateEf)

got(_ZN7GUIBankD2Ev)

got(_ZN7GUIBankD1Ev)

got(_ZN7GUIBankD0Ev)

got(_ZN7GUIBank8OnRenderEv)

got(_ZN7ecImage6RenderEffff)

got(_ZN7GUIBankC2Ev)

got(_ZN9GUIButtonC1Ev)

got(_ZN8GUIMedalC1Ev)

got(_ZN8GUIMedal4InitERK7GUIRect)

got(_ZN10GUIManager8AddImageEPKcRK7GUIRectP10GUIElement)

got(_ZN7GUIBank7OnEventERK5Event)

got(_ZN9GUIBattleD2Ev)

got(_ZN12CBattleSceneD1Ev)

got(_ZN9GUIBattleD1Ev)

got(_ZN9GUIBattleD0Ev)

got(_ZN9GUIBattle8OnRenderEv)

got(_ZN12CBattleScene6RenderEv)

got(_ZN9GUIBattleC2Ev)

got(_ZN12CBattleSceneC1Ev)

got(_ZN12CBattleScene4InitEiPS_)

got(_ZN9GUIBattle11ResetBattleEv)

got(_ZN12CBattleScene13SetBattleAreaEi)

got(_ZN9GUIBattle12BattleFinishEv)

got(_ZN9GUIBattle13UpateFightingEf)

got(_ZN12CBattleScene6AttackEv)

got(_ZN12CBattleScene11IsAttackingEv)

got(_ZN12CBattleScene12DestroyUnitsEi)

got(_ZN9GUIBattle8OnUpdateEf)

got(_ZN12CBattleScene6UpdateEf)

got(_ZN12CBattleScene12ClearCratersEv)

got(_ZN12CBattleScene12ClearEffectsEv)

got(_ZN9GUIBattle7OnEventERK5Event)

got(_ZN14GUIBattleIntroD2Ev)

got(_ZN14GUIBattleIntroD1Ev)

got(_ZN14GUIBattleIntroD0Ev)

got(_ZN14GUIBattleIntro8OnRenderEv)

got(_ZN14GUIBattleIntroC2Ev)

got(_ZN14GUIBattleIntro9SetBattleEii)

got(_ZN14GUIBattleIntro7OnEventERK5Event)

got(_ZN8GUIBeginD2Ev)

got(_ZN8GUIBeginD1Ev)

got(_ZN8GUIBeginD0Ev)

got(_ZN8GUIBegin8OnRenderEv)

got(_ZN8GUIBeginC2Ev)

got(_ZN7GUITechC1Ev)

got(_ZN7GUITech4InitERK7GUIRect)

got(_ZN8CCountry8GetTaxesEv)

got(_ZN8CCountry12GetIndustrysEv)

got(_ZN8GUIBegin7OnEventERK5Event)

got(_ZN11GUIButtonExD2Ev)

got(_ZN9GUIButtonD2Ev)

got(_ZN11GUIButtonExD1Ev)

got(_ZN11GUIButtonExD0Ev)

got(_ZN11GUIButtonExC2Ev)

got(_ZN9GUIButtonC2Ev)

got(_ZN11GUIButtonEx8OnRenderEv)

got(_ZN9GUIButton8OnRenderEv)

got(_ZN9GUIButton7OnEventERK5Event)

got(_ZN10GUICardTabD2Ev)

got(_ZN10GUICardTabD1Ev)

got(_ZN10GUICardTabD0Ev)

got(_ZN10GUIBuyCardD2Ev)

got(_ZN10GUIBuyCardD1Ev)

got(_ZN10GUIBuyCardD0Ev)

got(_ZN10GUIBuyCard8OnRenderEv)

got(_ZN10GUICardTabC2Ev)

got(_ZN10GUICardTabC1Ev)

got(_ZN10GUICardTab19GetCardTabButtonIdxEPK10GUIElement)

got(_ZN10GUICardTab9SelectTabEi)

got(_ZN10GUIElement6GetPosERfS0_)

got(_ZN10GUIElement6SetPosEff)

got(_ZN10GUICardTab4InitERK7GUIRect)

got(_ZN14GUIRadioButtonC1Ev)

got(_ZN10GUIManager8AddImageEPKcRK13ecTextureRectRK7GUIRectP10GUIElementb)

got(_ZN10GUIBuyCardC2Ev)

got(_ZN11GUICardListC1Ev)

got(_ZN11GUICardList4InitERK7GUIRecti)

got(_ZN7ecImageC1EP9ecTextureRK13ecTextureRect)

got(_ZN10GUIBuyCard15SetSelCardIntroEv)

got(_ZN10CObjectDef10GetCardDefE7CARD_ID)

got(_ZN8CCountry10CanBuyCardEP7CardDef)

got(_ZN7GUICard13SetPriceColorEj)

got(_ZN8CCountry16IsEnoughIndustryEP7CardDef)

got(_ZN7GUICard16SetIndustryColorEj)

got(_ZN8CCountry12GetCardPriceEP7CardDef)

got(_ZN8CCountry15GetCardIndustryEP7CardDef)

got(_ZN11GUICardList7GetCardEi)

got(_ZN8CCountry13IsEnoughMoneyEP7CardDef)

got(_ZN8CCountry13GetCardRoundsE7CARD_ID)

got(_ZN10GUIElement9SetEnableEb)

got(_ZN7GUICard8SetPriceEi)

got(_ZN7GUICard11SetIndustryEi)

got(_ZN8CCountry15CanUseCommanderEv)

got(_ZN10GUIBuyCard7SelCardEii)

got(_ZN6CScene12ClearTargetsEv)

got(_ZN8CCountry14SetCardTargetsEP7CardDef)

got(_ZN6CScene11ResetTargetEv)

got(_ZN10GUICardTab7OnEventERK5Event)

got(_ZN10GUIBuyCard7OnEventERK5Event)

got(_ZN10CObjectDef17GetCardTargetTypeEP7CardDef)

got(_ZN10GUIElement8OnRenderEv)

got(_ZN7GUICardD2Ev)

got(_ZN7GUICardD1Ev)

got(_ZN7GUICardD0Ev)

got(_ZN7GUICard8OnRenderEv)

got(_ZN11GUICardListD2Ev)

got(_ZN11GUICardListD1Ev)

got(_ZN11GUICardListD0Ev)

got(_ZN11GUICardList8OnUpdateEf)

got(_ZN7GUICardC2Ev)

got(_ZN7GUICardC1Ev)

got(_ZN7GUICard4InitEP7CardDefRK7GUIRect)

got(_ZN11GUICardListC2Ev)

got(_ZN11GUICardList11ResetSelectEv)

got(_ZN11GUICardList10GelSelItemEff)

got(_ZN10GUIElement11CheckInRectEff)

got(_ZN7GUICard7OnEventERK5Event)

got(_ZN11GUICardList9SetSelectEi)

got(_ZN11GUICardList8ReSelectEv)

got(_ZN11GUICardList7OnEventERK5Event)

got(_ZN11GUIDefeated8OnRenderEv)

got(_ZN11GUIDefeatedC2Ev)

got(_ZN10CObjectDef15GetGeneralPhotoEPKc)

got(_ZN11GUIDefeatedD2Ev)

got(_ZN11GUIDefeatedD1Ev)

got(_ZN11GUIDefeatedD0Ev)

got(_ZN11GUIDefeated8OnUpdateEf)

got(_ZN11GUIDefeated7OnEventERK5Event)

got(_ZN11GUIDialogue8OnUpdateEf)

got(_ZN11GUIDialogueD2Ev)

got(_ZN11GUIDialogueD1Ev)

got(_ZN11GUIDialogueD0Ev)

got(_ZN11GUIDialogue8OnRenderEv)

got(_ZN11GUIDialogueC2Ev)

got(_ZN11GUIDialogue7HideDlgEv)

got(_ZN11GUIDialogue7OnEventERK5Event)

got(_ZN6GUIEndD2Ev)

got(_ZN6GUIEndD1Ev)

got(_ZN6GUIEndD0Ev)

got(_ZN6GUIEnd8OnRenderEv)

got(_ZN6GUIEndC2Ev)

got(_ZN6GUIEnd7OnEventERK5Event)

got(_ZN7GUIGoldD2Ev)

got(_ZN7GUIGoldD1Ev)

got(_ZN7GUIGoldD0Ev)

got(_ZN7GUIGold8OnRenderEv)

got(_ZN7GUIGoldC2Ev)

got(_ZN7GUIGold8SetMoneyEi)

got(_ZN7GUIGold11SetIndustryEi)

got(_ZN7GUIGold8OnUpdateEf)

got(_ZN15GUIProductPrice8OnRenderEv)

got(_ZN6GUIIapD2Ev)

got(_ZN6GUIIapD1Ev)

got(_ZN6GUIIapD0Ev)

got(_ZN6GUIIap7OnEventERK5Event)

got(_ZN15GUIProductPriceD2Ev)

got(_ZN15GUIProductPriceD1Ev)

got(_ZN15GUIProductPriceD0Ev)

got(_ZN6GUIIap8OnRenderEv)

got(_ZN15GUIProductPriceC2Ev)

got(_ZN15GUIProductPriceC1Ev)

got(_ZN15GUIProductPrice4InitERK7GUIRect)

got(_ZN11ecLabelText8SetColorEj)

got(_ZN15GUIProductPrice14SetLocalePirceEPKc)

got(_ZN6GUIIapC2Ev)

got(_ZN9GUIButton7SetTextEPKc)

got(_ZN9GUIButton12SetTextColorEj)

got(_ZN6GUIIap14SetLocalePirceEiPKc)

got(_ZN6GUIIap14OnListCompleteEPv)

got(_ZN6GUIIap15SetProductPriceEv)

got(_ZN8GUIMedalD2Ev)

got(_ZN8GUIMedalD1Ev)

got(_ZN8GUIMedalD0Ev)

got(_ZN8GUIMedal8OnRenderEv)

got(_ZN8GUIMedalC2Ev)

got(_ZN8GUIMedal8SetMedalEi)

got(_ZN8GUIMedal8OnUpdateEf)

got(_ZN8GUIMedal7OnEventERK5Event)

got(_ZN10GUIOptionsD2Ev)

got(_ZN10GUIOptionsD1Ev)

got(_ZN10GUIOptionsD0Ev)

got(_ZN10GUIOptions8OnRenderEv)

got(_ZN10GUIOptionsC2Ev)

got(_ZN10GUIManager12AddScrollBarERK7GUIRectP10GUIElementPKcS6_iiiii)

got(_ZN11GUILevelSelC1Ev)

got(_ZN11GUILevelSel4InitERK7GUIRecti)

got(_ZN12GUIScrollBar12SetScrollPosEi)

got(_ZN10GUIOptions7OnEventERK5Event)

got(_ZN12GUIScrollBar12GetScrollPosEv)

got(_ZN11GUIPauseBoxD2Ev)

got(_ZN11GUIPauseBoxD1Ev)

got(_ZN11GUIPauseBoxD0Ev)

got(_ZN11GUIPauseBox8OnRenderEv)

got(_ZN11GUIPauseBoxC2Ev)

got(_ZN11GUIPauseBox7OnEventERK5Event)

got(_ZN9GUIResult8OnUpdateEf)

got(_ZN9GUIResultD2Ev)

got(_ZN9GUIResultD1Ev)

got(_ZN9GUIResultD0Ev)

got(_ZN9GUIResult8OnRenderEv)

got(_ZN9GUIResultC2Ev)

got(_ZN13GUIAdornMedalC1Ev)

got(_ZN13GUIAdornMedal4InitER7GUIRect)

got(_ZN9GUIResult7OnEventERK5Event)

got(_ZN11GUISaveItemD2Ev)

got(_ZN14GUIRadioButtonD2Ev)

got(_ZN11GUISaveItemD1Ev)

got(_ZN11GUISaveItemD0Ev)

got(_ZN7GUISave8OnRenderEv)

got(_ZN11GUISaveItem8OnRenderEv)

got(_ZN7GUISaveD2Ev)

got(_ZN12ecTextureRes9UnloadResEPKc)

got(_ZN7GUISaveD1Ev)

got(_ZN7GUISaveD0Ev)

got(_ZN11GUISaveItem8OnUpdateEf)

got(_ZN11GUISaveItemC2Ev)

got(_ZN14GUIRadioButtonC2Ev)

got(_ZN11GUISaveItemC1Ev)

got(_ZN11GUISaveItem4InitERK7GUIRectPKc)

got(_ZN11GUISaveItem7SetInfoEPKciiiiiiiib)

got(_ZN7GUISaveC2Ev)

got(_ZN7GUISave7SelItemEi)

got(_ZN7GUISave7OnEventERK5Event)

got(_ZN11GUIArmyItemD2Ev)

got(_ZN11GUIArmyItemD1Ev)

got(_ZN11GUIArmyItemD0Ev)

got(_ZN11GUIArmyItem8OnRenderEv)

got(_ZN10GUISelArmyD2Ev)

got(_ZN10GUISelArmyD1Ev)

got(_ZN10GUISelArmyD0Ev)

got(_ZN10GUISelArmy8OnRenderEv)

got(_ZN11GUIArmyItemC2Ev)

got(_ZN11GUIArmyItemC1Ev)

got(_ZN10GUISelArmyC2Ev)

got(_ZN7ecImage8SetAlphaEfi)

got(_ZN10GUISelArmy15MoveArmyToFrontEi)

got(_ZN5CArea15MoveArmyToFrontEib)

got(_ZN10GUISelArmy10TargetArmyEi)

got(_ZN10GUISelArmy7OnEventERK5Event)

got(_ZN12GUISmallCardD2Ev)

got(_ZN12GUISmallCardD1Ev)

got(_ZN12GUISmallCardD0Ev)

got(_ZN12GUISmallCard8OnRenderEv)

got(_ZN12GUISmallCardC2Ev)

got(_ZN6GUITaxD2Ev)

got(_ZN6GUITaxD1Ev)

got(_ZN6GUITaxD0Ev)

got(_ZN6GUITax8OnRenderEv)

got(_ZN6GUITaxC2Ev)

got(_ZN6GUITax8SetMoneyEi)

got(_ZN6GUITax11SetIndustryEi)

got(_ZN5CArea10GetRealTaxEv)

got(_ZN5CArea11GetIndustryEv)

got(_ZN5CArea11HasArmyCardEi)

got(_ZN7GUITechD2Ev)

got(_ZN7GUITechD1Ev)

got(_ZN7GUITechD0Ev)

got(_ZN7GUITech8OnRenderEv)

got(_ZN7GUITech8OnUpdateEf)

got(_ZN7GUITechC2Ev)

got(_ZN12GUITutorails8OnRenderEv)

got(_ZN12GUITutorailsC2Ev)

got(_ZN12GUITutorails10LoadScriptEv)

got(_ZN12GUITutorails13ReleaseScriptEv)

got(_ZN12GUITutorailsD2Ev)

got(_ZN12GUITutorailsD1Ev)

got(_ZN12GUITutorailsD0Ev)

got(_ZN12GUITutorails7ShowDlgEi)

got(_ZN12GUITutorails7ShowDlgEPKc)

got(_ZN12GUITutorails7HideDlgEv)

got(_ZN12GUITutorails6ExeCmdEi)

got(_ZN6CScene22MoveCameraCenterToAreaEi)

got(_ZN6CScene16MoveCameraToAreaEi)

got(_ZN12GUITutorails8OnUpdateEf)

got(_ZN6CScene8IsMovingEv)

got(_ZN12GUITutorails7OnEventERK5Event)

got(_ZN10GUIVictoryD2Ev)

got(_ZN10GUIVictoryD1Ev)

got(_ZN10GUIVictoryD0Ev)

got(_ZN10GUIVictory8OnRenderEv)

got(_ZN10GUIVictory8OnUpdateEf)

got(_ZN10GUIVictoryC2Ev)

got(_ZN10GUIVictory7OnEventERK5Event)

got(_ZN10GUIWarning8OnUpdateEf)

got(_ZN10GUIWarningD2Ev)

got(_ZN10GUIWarningD1Ev)

got(_ZN10GUIWarningD0Ev)

got(_ZN10GUIWarning8OnRenderEv)

got(_ZN10GUIWarningC2Ev)

got(_ZN10GUIWarning7OnEventERK5Event)

got(_ZN10CLoadState10TouchBeginEffi)

got(_ZN10CLoadState9TouchMoveEffi)

got(_ZN10CLoadState8TouchEndEffi)

got(_ZN10CLoadState11BackPressedEv)

got(_ZN10CLoadStateD2Ev)

got(_ZN10CLoadStateD1Ev)

got(_ZN10CLoadStateD0Ev)

got(_ZN10CLoadState7OnEnterEv)

got(_ZN10CLoadState6OnExitEv)

got(_ZN10CLoadState6RenderEv)

got(_ZN10CLoadState6UpdateEf)

got(_ZN10CLoadState7OnEventERK5Event)

got(_ZN10CLoadStateC2Ev)

got(_ZN10CLogoStateD2Ev)

got(_ZN10CLogoStateD1Ev)

got(_ZN10CLogoState15EnterForegroundEv)

got(_ZN10CLogoStateD0Ev)

got(_ZN10CLogoState7OnEnterEv)

got(_ZN10CLogoState6OnExitEv)

got(_ZN10CLogoState6RenderEv)

got(_ZN10CLogoState7OnEventERK5Event)

got(_ZN10CLogoState6UpdateEf)

got(_ZN14CPlayerManager4InitEv)

got(_ZN10CLogoStateC2Ev)

got(_ZN11CMatchStateD2Ev)

got(_ZN11CMatchStateD1Ev)

got(_ZN11CMatchState6UpdateEf)

got(_ZN11CMatchState6RenderEv)

got(_ZN11CMatchState10TouchBeginEffi)

got(_ZN11CMatchState9TouchMoveEffi)

got(_ZN11CMatchState8TouchEndEffi)

got(_ZN11CMatchStateD0Ev)

got(_ZN11CMatchState7OnEnterEv)

got(_ZN13GUIMatchSetupC1Ev)

got(_ZN13GUIMatchSetup4InitERK7GUIRect)

got(_ZN11CMatchState6OnExitEv)

got(_ZN11CMatchStateC2Ev)

got(_ZN11CMatchState18StartMultiplayGameEi)

got(_ZN11CMatchState7OnEventERK5Event)

got(_ZN14CPlayerManager17SendStartLoadGameEv)

got(_ZN11CMatchState11ShowWarningEi)

got(_ZN10CMenuStateD2Ev)

got(_ZN10CMenuStateD1Ev)

got(_ZN10CMenuState6UpdateEf)

got(_ZN10CMenuState6RenderEv)

got(_ZN10CMenuState10TouchBeginEffi)

got(_ZN10CMenuState9TouchMoveEffi)

got(_ZN10CMenuState8TouchEndEffi)

got(_ZN10CMenuStateD0Ev)

got(_ZN10CMenuState7OnEnterEv)

got(_ZN11GUIMainMenuC1Ev)

got(_ZN11GUIMainMenu4InitERK7GUIRect)

got(_ZN12GUISelBattleC1Ev)

got(_ZN12GUISelBattle4InitERK7GUIRectii)

got(_ZN10CMenuState6OnExitEv)

got(_ZN10CMenuStateC2Ev)

got(_ZN10CMenuState13PeerConnectedEv)

got(_ZN10CMenuState18StartMultiplayGameEi)

got(_ZN10CMenuState7OnEventERK5Event)

got(_ZN11GUIMainMenu13RefreshNewTipEv)

got(_ZN10GUILoadingC1Ev)

got(_ZN10GUILoading4InitERK7GUIRect)

got(_ZN11GUIMainMenu6ShowADEv)

got(_ZN14CPlayerManager12SetupSessionEb)

got(_ZN16GUILockedWarningC1Ev)

got(_ZN16GUILockedWarning4InitERK7GUIRect)

got(_ZN12GUICommanderC1Ev)

got(_ZN12GUICommander4InitERK7GUIRect)

got(_ZN10GUIServiceC1Ev)

got(_ZN10GUIService4InitERK7GUIRect)

got(_ZN10GUIElement9FreeChildEPS_)

got(_ZN11GUIHostList17ResetConnectStateEv)

got(_ZN13GUISelCountryC1Ev)

got(_ZN13GUISelCountry4InitERK7GUIRecti)

got(_ZN14CPlayerManager9InitCorpsEi)

got(_ZN14CPlayerManager14DestroySessionEv)

got(_ZN11GUIHostListC1Ev)

got(_ZN11GUIHostList4InitERK7GUIRect)

got(_ZN10GUINewGameC1Ev)

got(_ZN10GUINewGame4InitERK7GUIRect)

got(_ZN14CPlayerManager10StartMatchEv)

got(_ZN14CPlayerManager9StopMatchEv)

got(_ZN10CMenuState11ShowWarningEi)

got(_ZN14GUIExitWarningC1Ev)

got(_ZN14GUIExitWarning4InitERK7GUIRect)

got(_ZN10CObjectDefC2Ev)

got(_ZN10CObjectDefC1Ev)
bss(_ZN10CObjectDef10m_InstanceE, 8)

got(_ZN10CObjectDef11LoadCardDefEv)

got(_ZN10CObjectDef16GetUnitPositionsEPKc)

got(_ZN10CObjectDef15GetCommanderDefEPKc)

got(_ZN10CObjectDef14GetConquestDefEPKc)

got(_ZN10CObjectDef14ReleaseArmyDefEv)

got(_ZN10CObjectDef18ReleaseUnitMotionsEv)

got(_ZN10CObjectDef20ReleaseUnitPositionsEv)

got(_ZN10CObjectDef19ReleaseCommanderDefEv)

got(_ZN10CObjectDef20ReleaseGeneralPhotosEv)

got(_ZN10CObjectDef17ReleaseBattleListEv)

got(_ZN10CObjectDefD2Ev)

got(_ZN10CObjectDefD1Ev)

got(_ZN10CObjectDef19ReleaseConquestListEv)

got(_ZN10CObjectDef7ReleaseEv)

got(_ZN10CObjectDef14GetUnitMotionsEPKcS1_)

got(_ZN10CObjectDef11LoadArmyDefEv)

got(_ZN10CObjectDef15LoadUnitMotionsEv)

got(_ZN10CObjectDef16LoadUnitPositonsEv)

got(_ZN10CObjectDef16LoadCommanderDefEv)

got(_ZN10CObjectDef17LoadGeneralPhotosEv)

got(_ZN10CObjectDef14LoadBattleListEv)

got(_ZN10CObjectDef16LoadConquestListEv)

got(_ZN14CPlayerManager14WillDisconnectEv)

got(_ZN14CPlayerManager34onLocalPlayerAuthenticationChangedEv)

got(_ZN14CPlayerManager20onFriendListReceivedEv)

got(_ZN14CPlayerManager14onMatchRequestEv)

got(_ZN14CPlayerManager17onPlayerConnectedEPKc)

got(_ZN14CPlayerManager17InvitationDidFailEPKc)

got(_ZN11GUIHostList13ConnectFailedEv)

got(_ZN14CPlayerManager16SessionNoNetworkEv)

got(_Z9ecGetUUIDRSs)

got(_Z13ecGetUUIDHashv)

got(_ZN9ecGameKitC1Ev)

got(_ZN9ecGameKit4InitEP17ecGameKitDelegateb)

got(_ZN14CPlayerManager15AnalyzePeerNameERKSsRSsRiS3_)

got(_ZN14CPlayerManager7ConnectEPKci)

got(_ZN18ecSessionInterface7ConnectEPKc)

got(_ZN14CPlayerManager9ReconnectEv)

got(_ZN18ecSessionInterface15GetPeerNameListERSt4listISsSaISsEES3_)

got(_ZN14CPlayerManager13CancelConnectEv)

got(_ZN18ecSessionInterface13CancelConnectEv)

got(_ZN14CPlayerManager19onPeerListDidChangeEv)

got(_ZN11GUIHostList15RefreshHostListEv)

got(_ZN9ecGameKit25ShowMatchmakerWithRequestEiii)

got(_ZN14CPlayerManager9AddPlayerEbPKc)

got(_ZN7CPlayerC1Ev)

got(_ZN7CPlayer4InitEbPKc)

got(_ZN18ecSessionInterfaceC1Ev)

got(_ZN18ecSessionInterface4InitEP17ecSessionDelegate)

got(_ZN18ecSessionInterface12SetupSessionEb)

got(_ZN18ecSessionInterface13GetDeviceNameERSs)

got(_ZN14CPlayerManager18ClearRemotePlayersEv)

got(_ZN7CPlayerD1Ev)

got(_ZN14CPlayerManager12ClearPlayersEv)

got(_ZN18ecSessionInterfaceD1Ev)

got(_ZN9ecGameKitD1Ev)

got(_ZN14CPlayerManagerD2Ev)

got(_ZN14CPlayerManagerD1Ev)

got(_ZN9ecGameKit22DisconnectCurrentMatchEv)

got(_ZN14CPlayerManager16onAcceptedInviteEv)

got(_ZN14CPlayerManager10FindPlayerEPKc)

got(_ZN14CPlayerManager20onPlayerInfoReceivedERSt4listIP12ecPlayerInfoSaIS2_EE)

got(_ZN14CPlayerManager12onMatchFoundEv)

got(_ZN9ecGameKit18GetMatchPlayerListERSt4listISsSaISsEE)

got(_ZN14CPlayerManager16FindPlayerByUUIDEi)

got(_ZN14CPlayerManager17DidRecvInvitationEPKc)

got(_ZN18ecSessionInterface11GetPeerNameEPKcRSs)

got(_ZN18ecSessionInterface17DeclineInvitationEPKc)

got(_ZN18ecSessionInterface16AcceptInvitationEPKc)

got(_ZN14CPlayerManager21GetDisconnectedPlayerEv)

got(_ZN14CPlayerManager18SendPacketToPlayerE12PacketHeaderPKviPKc)

got(_ZN18ecSessionInterface10SendPacketEPKviPKc)

got(_ZN9ecGameKit10SendPacketEPKviPKc)

got(_ZN14CPlayerManager18SendPacketToPlayerE9PACKET_IDPKviP7CPlayer)

got(_ZN14CPlayerManager28SendPacketToAllPlayersExceptE9PACKET_IDPKviP7CPlayer)

got(_ZN7CPlayer10PushPacketE9PACKET_IDPKvi)

got(_ZN7CPlayer10SendPacketE9PACKET_IDPKvi)

got(_ZN14CPlayerManager10ClearCorpsEv)

got(_ZN14CPlayerManager13WillTerminateEv)

got(_ZN13GUIMatchSetup18RefreshCorsButtonsEv)

got(_ZN11GUIHostList13ClearHostListEv)

got(_ZN14CPlayerManager12GetLeftCorpsEi)

got(_ZN14CPlayerManager13GetRightCorpsEi)

got(_ZN14CPlayerManager15GetNumLeftCorpsEv)

got(_ZN14CPlayerManager16GetNumRightCorpsEv)

got(_ZN14CPlayerManager8SelCorpsEiiP7CPlayer)

got(_ZN14CPlayerManager17RemoveCorpsPlayerEii)

got(_ZN14CPlayerManager17RemoveCorpsPlayerEP7CPlayer)

got(_ZN14CPlayerManager12RemovePlayerEP7CPlayer)

got(_ZN14CPlayerManager20onPlayerDisconnectedEPKc)

got(_ZN14CPlayerManager12GetCorpsDataERi)

got(_ZN14CPlayerManager15onPeerConnectedEPKc)

got(_ZN14CPlayerManager12onStartMatchEv)

got(_ZN9ecGameKit18GetLocalPlayerInfoER12ecPlayerInfo)

got(_ZN9ecGameKit19GetMatchPlayersInfoEv)

got(_ZN14CPlayerManager14SetCorpsByDataEPviP7CPlayer)

got(_ZN14CPlayerManager17IsAllPlayersReadyEv)

got(_ZN14CPlayerManager23RefreshAndSendCorpsDataEv)

got(_ZN14CPlayerManager18onPeerDisconnectedEPKc)

got(_ZN14CPlayerManager14SendRoundBeginEv)

got(_ZN14CPlayerManager16ClearActionQueueEv)

got(_ZN14CPlayerManager14onReceivedDataEPKviPKcb)

got(_ZN7CPlayer7SendAckEi)

got(_ZN7CPlayer7RecvAckEi)

got(_ZN13GUIMatchSetup16CreatCorsButtonsEv)

got(_ZN14CPlayerManager22onReveivedDataFromPeerEPKviPKc)

got(_ZN14CPlayerManager24onReceivedDataFromPlayerEPKviPKc)

got(_ZN7CPlayer9SendFirstEv)

got(_ZN14CPlayerManagerC2Ev)

got(_ZN14CPlayerManagerC1Ev)

got(_ZN6CSceneD2Ev)

got(_ZN9CAreaMarkD1Ev)

got(_ZN6CSceneD1Ev)

got(_ZN6CSceneC2Ev)

got(_ZN9CAreaMarkC1Ev)

got(_ZN7CCameraC1Ev)

got(_ZN6CSceneC1Ev)

got(_ZN6CScene17CheckAdjacentDataEv)

got(_ZN6CScene9NewAdjoinEv)

got(_ZN6CScene10LoadAdjoinEi)

got(_ZN6CScene10SaveAdjoinEi)

got(_ZN6CScene10MakeAdjoinEii)

got(_ZN6CScene9DelAdjoinEii)

got(_ZN6CScene8IsAdjoinEii)

got(_ZN6CScene12RenderAdjoinEv)

got(_ZN6CScene17RenderAreasCenterEv)

got(_ZN6CScene15RenderAreasArmyEv)

got(_ZN6CScene16RenderAreasPointEv)

got(_ZN6CScene12LoadAreaDataEi)

got(_ZN6CScene12SaveAreaDataEi)

got(_ZN6CScene14RenderSeaAreasEv)

got(_ZN7CCamera14IsRectInCameraEffff)

got(_ZN6CScene13RenderAreasIDEv)

got(_ZN6CScene10ClearAreasEv)

got(_ZN5CAreaD1Ev)

got(_ZN7CBomberD1Ev)

got(_ZN11CBackgroundD1Ev)

got(_ZN9CAreaMark7ReleaseEv)

got(_ZN6CScene11SaveAreaTaxEi)

got(_ZN6CScene14LoadAreaEnableEPKc)

got(_ZN6CScene14SaveAreaEnableEPKc)

got(_ZN6CScene20AreaDisableOutofRectEiiii)

got(_ZN6CScene13InitAreaImageEi)

got(_ZN6CScene12CalSceneRectERfS0_S0_S0_)

got(_ZN6CScene13IsRectInSecenEffff)

got(_ZN7CCamera5UpateEf)

got(_ZN7CBomber6UpdateEf)

got(_ZN5CArea6UpdateEf)

got(_ZN6CMedal5UpateEf)

got(_ZN6CScene11CreateArrowEii)

got(_Z7InvSqrtf)

got(_ZN9hgeVector6RotateEf)

got(_ZN6CScene14ScreenToAreaIDEff)

got(_ZN9CAreaMark7GetMarkEii)

got(_ZN7CCamera4MoveEffb)

got(_ZN6CScene6MoveToEii)

got(_ZN7CCamera6MoveToEffb)

got(_ZN7CCamera21IsRectInVisibleRegionEffff)

got(_ZN6CScene21MoveCameraBetweenAreaEii)

got(_ZN6CScene25GetTwoAreasDistanceSquareEii)

got(_ZN6CScene19GetTwoAreasDistanceEii)

got(_ZN6CScene19GetNumAdjacentAreasEi)

got(_ZN6CScene17GetAdjacentAreaIDEii)

got(_ZN6CScene15GetAdjacentAreaEii)

got(_ZN7CCamera5ApplyEv)

got(_ZN11CBackground6RenderEP7CCamera)

got(_ZN11CBackground9RenderBoxEP7CCameraffff)

got(_ZN5CArea14RenderBuildingEv)

got(_ZN5CArea6RenderEv)

got(_ZN7ecImage9Render4VCEffffffffif)

got(_ZN6CMedal6RenderEv)

got(_ZN7CBomber6RenderEv)

got(_ZN8CCountry15AirstrikeRadiusEv)

got(_ZN6CScene13CheckAdjacentEii)

got(_ZN5CArea11HasArmyCardEii)

got(_ZN6CScene17SetSelAreaTargetsEP5CArea)

got(_ZN5CArea12EncirclementEv)

got(_ZN6CScene8AirborneEi)

got(_ZN7CBomber8AirborneEi)

got(_ZN6CScene19AircraftCarrierBombEii)

got(_ZN7CBomber19AircraftCarrierBombEii)

got(_ZN6CScene8BombAreaEii)

got(_ZN7CBomber8BombAreaEii)

got(_ZN7CBomber9IsBombingEv)

got(_ZN6CMedalC1Ev)

got(_ZN6CMedal4InitEff)

got(_ZN6CScene11LoadAreaTaxEi)

got(_ZN5CAreaC1Ev)

got(_ZN5CArea4InitEiRK8AreaInfo)

got(_ZN6CScene9InitAreasEiPKc)

got(_ZN6CScene20CreateRenderAreaListEv)

got(_ZN9CAreaMark4InitEi)

got(_ZN11CBackgroundC1Ev)

got(_ZN11CBackground4InitEiiiiiffff)

got(_ZN7CCamera4InitEffff)

got(_ZN7CBomberC1Ev)

got(_ZN7CBomber4InitEv)

got(_ZN9CSoundResD2Ev)

got(_ZN9CSoundResD1Ev)

got(_ZN9CSoundResC2Ev)

got(_ZN9CSoundResC1Ev)

got(_ZN13CStateManagerD2Ev)

got(_ZN13CStateManagerD1Ev)

got(_ZN13CStateManagerC2Ev)

got(_ZN13CStateManagerC1Ev)

got(_ZN13CTouchInertiaD2Ev)

got(_ZN13CTouchInertiaC2Ev)

got(_ZN13CTouchInertia13AddTrackPointEff)

got(_ZN13CTouchInertia13GetStartPointEv)

got(_ZN9CActionAI11detectCardsE7CARD_ID)

got(_ZN8CCountry12IsCardUnlockEP7CardDef)

got(_ZN9CActionAI21analyseCompositePowerEv)
bss(g_NationInfo, 40)

got(_ZN9CActionAI12getAiPercentEi)

got(_ZN9CActionAI14getNumArmyMoveEii)

got(_ZN9CActionAI12purChaseCardE7CARD_ID)

got(_ZN13CActionAssist17purChaseCardsCardEv)

got(_ZN13CActionAssist16purChaseFortCardEv)

got(_ZN13CActionAssist21purChaseConstructCardEv)

got(_ZN13CActionAssist21purChaseAirStrikeCardEv)

got(_ZN13CActionAssist17purChaseDraftCardEb)

got(_ZN9CActionAI15sortArmyToFrontEv)

got(_ZN5CArea12IsArmyActiveEi)

got(_ZN9CActionAI8getMaxIdEv)

got(_ZN9CActionAI13setArmyActionEP5CArea)

got(_ZN13CActionAssist16actionToNextAreaEiiii)

got(_ZN9CActionAI13moveAndAttackEv)

got(_Z13GetAIRandSeedv)

got(_ZN13CActionAssist13calcDraftTypeEbiP8CCountry)

got(_ZN5CArea12GetCityLevelEv)

got(_ZN13CActionAssist19purChaseSpecialCardEv)

got(_ZN13CActionAssist11getAllianceEiii)

got(_ZN13CActionAssist10searchNodeEii)

got(_ZN13CActionAssist14searchNodeByIDEii)

got(_ZN13CActionAssist11getNeighborEiiic)

got(_ZN8CCountry19CheckCardTargetArmyEP7CardDefii)

got(_ZN5CArea16GetIndustryLevelEv)

got(_ZN13CActionAssist4isAIEi)

got(_ZN5CAreaC2Ev)

got(_ZN5CAreaD2Ev)

got(_ZN5CArmyD1Ev)

got(_ZN5CArea12CanConstructEi)

got(_ZN5CArea9ConstructEi)

got(_ZN5CArea10GetArmyIdxEP5CArmy)

got(_ZN5CArea10RemoveArmyEP5CArmy)

got(_ZN5CArea15MoveArmyToFrontEP5CArmyb)

got(_ZN5CArea9DraftArmyEi)

got(_ZN5CArea13SetMoveInArmyEPS_P5CArmybbPKc)

got(_ZN5CArea10MoveArmyToEPS_)

got(_ZN8CCountry10RemoveAreaEi)

got(_ZN8CCountry14BeConquestedByEPS_)

got(_ZN5CArea10SetArmyDirEif)

got(_ZN5CArea11AddArmyCardEii)

got(_ZN5CArea11DelArmyCardEii)

got(_ZN5CArea18RevertArmyStrengthEi)

got(_ZN5CArmy12LostStrengthEi)

got(_ZN8CCountry12CommanderDieEv)

got(_ZN5CArea15AddArmyStrengthEii)

got(_ZN5CArmy11AddStrengthEi)

got(_ZN5CArea16AllArmyPoisoningEv)

got(_ZN5CArmy9PoisoningEv)

got(_ZN5CArea11UpgradeArmyEi)

got(_ZN5CArmy7UpgradeEv)

got(_ZN5CArea18SetAllArmyMovementEi)

got(_ZN5CArea17CheckEncirclementEv)

got(_ZN5CArmy9SetMoraleEi)

got(_ZN5CArea10RenderArmyEffiP5CArmy)

got(_ZN5CArea9TurnBeginEv)

got(_ZN5CArmy9TurnBeginEv)

got(_ZN5CArea7TurnEndEv)

got(_ZN5CArmy7TurnEndEv)

got(_ZN5CArmy8SaveArmyEP12SaveArmyInfo)

got(_ZN5CArmy8LoadArmyEPK12SaveArmyInfo)

got(_ZN9CAreaMarkC2Ev)

got(_ZN9CAreaMarkD2Ev)

got(_ZN5CArmyC2Ev)

got(_ZN5CArmyD2Ev)

got(_ZN11CBackgroundC2Ev)

got(_ZN11CBackgroundD2Ev)

got(_ZN12CBattleSceneC2Ev)

got(_ZN12CBattleScene7ReleaseEv)

got(_ZN11CBattleUnit6RenderEv)

got(_ZN8ecEffect6RenderEv)

got(_Z13HasUnitMotionPKci)

got(_ZN12CBattleScene11CreateUnitsEv)

got(_ZN9ecLibraryC1Ev)

got(_ZN9ecLibrary4LoadEPKcR12ecTextureRes)

got(_ZN11CBattleUnitC1Ev)

got(_ZN11CBattleUnit4InitEiiP9ecLibraryP11UnitMotions)

got(_ZN11CBattleUnit12SetDestroyedEv)

got(_ZN12CBattleScene12ReleaseUnitsEv)

got(_ZN11CBattleUnitD1Ev)

got(_ZN12CBattleScene10CreateFortEv)

got(_ZN12CBattleScene11ReleaseFortEv)

got(_ZN11CBattleUnit11IsAttackingEv)

got(_ZN11CBattleUnit7DestroyEv)

got(_ZN12CBattleScene9AddCraterEPKcfff)

got(_ZN12CBattleScene10StarEffectEi)

got(_ZN12CBattleScene9AddEffectEPKcff)

got(_ZN15ecEffectManager12CreateEffectEPKc)

got(_ZN11CBattleUnit6AttackEv)

got(_ZN11CBattleUnit6UpdateEf)

got(_ZN8ecEffect6UpdateEf)

got(_ZN8ecEffect6IsLiveEv)

got(_ZN8ecEffectD1Ev)

got(_ZN12CBattleSceneD2Ev)

got(_ZN11CBattleUnitC2Ev)

got(_ZN9ecElementC1Ev)

got(_ZN9ecElement4InitEPKcP9ecLibrary)

got(_ZN9ecElement4PlayEv)

got(_ZN11CBattleUnit7ReleaseEv)

got(_ZN9ecElementD1Ev)

got(_ZN11CBattleUnitD2Ev)

got(_ZN9ecElement6UpdateEf)

got(_ZN9ecElement6RenderERK7ecMtx32)

got(_ZN9ecElement11SetCurFrameEi)

got(_ZN9ecElement7SetLoopEi)

got(_ZN9ecElement11GetPlayTimeEv)

got(_ZN7CBomberC2Ev)

got(_ZN7CBomberD2Ev)

got(_ZN8CCountry7UseCardEP7CardDefii)

got(_ZN7CCameraC2Ev)

got(_ZN7CCamera12SetSceneRectEffff)

got(_ZN8CCountryC2Ev)

got(_ZN8CCountryD2Ev)

got(_ZN8CCountry8FindAreaEi)

got(_ZN8CCountry15GetFirstCapitalEv)

got(_ZN8CCountry18FindAdjacentAreaIDEib)

got(_ZN8CCountry22FindAdjacentLandAreaIDEib)

got(_ZN8CCountry13GetNumAirportEv)

got(_ZN8CCountry18GetMinDstToAirportEi)

got(_ZN8CCountry17GenCardTargetListE7CARD_ID)

got(_ZN8CCountry16GetCurCardTargetEv)

got(_ZN8CCountry14NextCardTargetEv)

got(_ZN8CCountry12FinishActionEv)

got(_ZN8CCountry16SetWarMedalLevelE11WARMEDAL_IDi)

got(_ZN8CCountry12CollectTaxesEv)

got(_ZN8CCountry16CollectIndustrysEv)

got(_ZN8CCountry8DoActionEv)

got(_ZN17GUICommanderMedalD2Ev)

got(_ZN17GUICommanderMedalD1Ev)

got(_ZN17GUICommanderMedalD0Ev)

got(_ZN11GUIWarMedalD2Ev)

got(_ZN11GUIWarMedalD1Ev)

got(_ZN11GUIWarMedalD0Ev)

got(_ZN17GUICommanderMedal8OnUpdateEf)

got(_ZN11GUIWarMedal8OnUpdateEf)

got(_ZN17GUICommanderMedal8OnRenderEv)

got(_ZN11GUIWarMedal8OnRenderEv)

got(_ZN13GUIAdornMedalD2Ev)

got(_ZN13GUIAdornMedalD1Ev)

got(_ZN13GUIAdornMedalD0Ev)

got(_ZN13GUIAdornMedal8OnRenderEv)

got(_ZN16GUIUpgradeButtonD2Ev)

got(_ZN16GUIUpgradeButtonD1Ev)

got(_ZN16GUIUpgradeButtonD0Ev)

got(_ZN16GUIUpgradeButton8OnRenderEv)

got(_ZN6ecText14GetStringWidthEib)

got(_ZN12GUICommanderD2Ev)

got(_ZN12GUICommanderD1Ev)

got(_ZN12GUICommanderD0Ev)

got(_ZN12GUICommander8OnRenderEv)

got(_ZN12GUICommander8OnUpdateEf)

got(_ZN17GUICommanderMedalC2Ev)

got(_ZN17GUICommanderMedalC1Ev)

got(_ZN17GUICommanderMedal4InitERK7GUIRecti)

got(_ZN17GUICommanderMedal13SetArrowColorEj)

got(_ZN11GUIWarMedalC2Ev)

got(_ZN11GUIWarMedalC1Ev)

got(_ZN11GUIWarMedal8SetLevelEi)

got(_ZN11GUIWarMedal4InitERK7GUIRect11WARMEDAL_IDi)

got(_ZN11GUIWarMedal13SetArrowColorEj)

got(_ZN13GUIAdornMedalC2Ev)

got(_ZN13GUIAdornMedal7RefreshEv)

got(_ZN16GUIUpgradeButtonC2Ev)

got(_ZN16GUIUpgradeButtonC1Ev)

got(_ZN16GUIUpgradeButton12SetNeedMedalEi)

got(_ZN12GUICommanderC2Ev)

got(_ZN12GUICommander16SetCommanderInfoEv)

got(_ZN12GUICommander13SelectedMedalEi)

got(_ZN12GUICommander7OnEventERK5Event)

got(_ZN14GUIExitWarningD2Ev)

got(_ZN14GUIExitWarningD1Ev)

got(_ZN14GUIExitWarningD0Ev)

got(_ZN14GUIExitWarning8OnRenderEv)

got(_ZN14GUIExitWarningC2Ev)

got(_ZN14GUIExitWarning7OnEventERK5Event)

got(_ZN19GUIConnectHostStateD2Ev)

got(_ZN19GUIConnectHostStateD1Ev)

got(_ZN19GUIConnectHostStateD0Ev)

got(_ZN11GUIHostListD2Ev)

got(_ZN11GUIHostListD1Ev)

got(_ZN11GUIHostListD0Ev)

got(_ZN11GUIHostList8OnRenderEv)

got(_ZN19GUIConnectHostState8OnRenderEv)

got(_ZN11GUIHostItemD2Ev)

got(_ZN11GUIHostItemD1Ev)

got(_ZN11GUIHostItemD0Ev)

got(_ZN19GUIConnectHostStateC2Ev)

got(_ZN19GUIConnectHostStateC1Ev)

got(_ZN19GUIConnectHostState4InitER7GUIRect)

got(_ZN11GUIHostItemC2Ev)

got(_ZN11GUIHostItemC1Ev)

got(_ZN11GUIHostItem7SetNameEPKc)

got(_ZN11GUIHostListC2Ev)

got(_ZN11GUIHostList8FindHostEPKc)

got(_ZN11GUIHostList14FindHostByUUIDEi)

got(_ZN11GUIHostList7AddHostEPKcS1_ii)

got(_ZN19GUIConnectHostState7OnEventERK5Event)

got(_ZN11GUIHostList7OnEventERK5Event)

got(_ZN11GUIHostItem8OnRenderEv)

got(_ZN11GUILevelSelD2Ev)

got(_ZN11GUILevelSelD1Ev)

got(_ZN11GUILevelSelD0Ev)

got(_ZN11GUILevelSel8OnRenderEv)

got(_ZN11GUILevelSelC2Ev)

got(_ZN11GUILevelSel7OnEventERK5Event)

got(_ZN10GUILoadingD2Ev)

got(_ZN10GUILoadingD1Ev)

got(_ZN10GUILoadingD0Ev)

got(_ZN10GUILoading8OnRenderEv)

got(_ZN10GUILoadingC2Ev)

got(_ZN10GUILoading7OnEventERK5Event)

got(_ZN16GUILockedWarningD2Ev)

got(_ZN16GUILockedWarningD1Ev)

got(_ZN16GUILockedWarningD0Ev)

got(_ZN16GUILockedWarning8OnRenderEv)

got(_ZN16GUILockedWarningC2Ev)

got(_ZN16GUILockedWarning7OnEventERK5Event)

got(_ZN11GUIMainMenuD2Ev)

got(_ZN11GUIMainMenuD1Ev)

got(_ZN11GUIMainMenuD0Ev)

got(_ZN11GUIMainMenu8OnRenderEv)

got(_ZN11GUIMainMenuC2Ev)

got(_ZN11GUIMainMenu12IsShowNewTipEv)

got(_ZN9GUIButton12SetTextImageEPKc)

got(_ZN8GUIImageC1Ev)

got(_ZN8GUIImage4InitEPKcRK7GUIRect)

got(_ZN11GUIMainMenu8OnUpdateEf)

got(_ZN11GUIMainMenu7OnEventERK5Event)

got(_ZN12GUICorpsInfoD2Ev)

got(_ZN12GUICorpsInfoD1Ev)

got(_ZN12GUICorpsInfoD0Ev)

got(_ZN13GUIMatchSetup8OnRenderEv)

got(_ZN14GUICorpsButton8OnRenderEv)

got(_ZN12GUICorpsInfo8OnRenderEv)

got(_ZN14GUICorpsButtonD2Ev)

got(_ZN14GUICorpsButtonD1Ev)

got(_ZN14GUICorpsButtonD0Ev)

got(_ZN13GUIMatchSetupD2Ev)

got(_ZN13GUIMatchSetupD1Ev)

got(_ZN13GUIMatchSetupD0Ev)

got(_ZN12GUICorpsInfoC2Ev)

got(_ZN12GUICorpsInfoC1Ev)

got(_ZN12GUICorpsInfo4InitERK7GUIRect)

got(_ZN12GUICorpsInfo13SetPlayerNameEPKcbS1_iib)

got(_ZN14GUICorpsButtonC2Ev)

got(_ZN14GUICorpsButtonC1Ev)

got(_ZN14GUICorpsButton4InitERK7GUIRectPKcb)

got(_ZN14GUICorpsButton13SetPlayerNameEPKcbS1_iib)

got(_ZN13GUIMatchSetupC2Ev)

got(_ZN13GUIMatchSetup7OnEventERK5Event)

got(_ZN10GUINewGameD2Ev)

got(_ZN10GUINewGameD1Ev)

got(_ZN10GUINewGameD0Ev)

got(_ZN10GUINewGame8OnRenderEv)

got(_ZN7_JNIEnv22CallStaticObjectMethodEP7_jclassP10_jmethodIDz)

got(_ZN10GUINewGameC2Ev)

got(_ZN10GUINewGame12IsShowSurveyEv)

got(_ZN10GUINewGame12IsImageReadyEv)

got(_ZN10GUINewGame18IsIabEventImgReadyEv)

got(_ZN10GUINewGame15IsShowSurveyTipEv)

got(_ZN10GUINewGame17IsShowIabEventTipEv)

got(_ZN10GUINewGame14IsShowIabEventEv)

got(_Z12JString2CStrP7_JNIEnvP8_jstring)

got(_ZN10GUINewGame17GetPromotionImageEv)

got(_ZN10GUINewGame16GetIabEventImageEv)

got(_ZN10GUINewGame15GetPromotionUrlEv)

got(_ZN10GUINewGame14BtnSurveyClickEv)

got(_ZN10GUINewGame14GetIabEventUrlEv)

got(_ZN10GUINewGame21OnRadioBtnSurveyClickEv)

got(_ZN10GUINewGame23OnRadioBtnIabEventClickEv)

got(_ZN10GUINewGame14GetSelectGroupEP14GUIRadioButton)

got(_ZN10GUINewGame18OnCheckButtonClickEP14GUIRadioButton)

got(_ZN10GUINewGame13GetAppVersionEv)

got(_ZN9GUIButton13SetTextOffsetEff)

got(_ZN9GUIButton12SetTextAlignEi)

got(_ZN8GUIImage4InitEPKcRK13ecTextureRectRK7GUIRectbbb)

got(_ZN7GUITextC1Ev)

got(_ZN7GUIText4InitERK7GUIRectP9ecUniFont)

got(_ZN7GUIText7SetTextEPKc)

got(_ZN8GUIImage8SetImageEPKcRK13ecTextureRectb)

got(_ZN10GUINewGame7OnEventERK5Event)

got(_Z16ecLaunchAppStorePKc)

got(_ZN12GUISelBattle8OnRenderEv)

got(_ZN12GUISelBattleC2Ev)

got(_ZN13GUIBattleListC1Ev)

got(_ZN13GUIBattleList4InitERK7GUIRecti)

got(_ZN13GUIBattleList18SelectLastUnlockedEv)

got(_ZN13GUIBattleList9SetSelectEi)

got(_ZN12GUISelBattle16ReleaseImageListEv)

got(_ZN12GUISelBattleD2Ev)

got(_ZN12GUISelBattleD1Ev)

got(_ZN12GUISelBattleD0Ev)

got(_ZN12GUISelBattle13LoadImageListEii)

got(_ZN12GUISelBattle9SelBattleEii)

got(_ZN12GUISelBattle8OnUpdateEf)

got(_ZN12GUISelBattle7OnEventERK5Event)

got(_ZN13GUISelCountry8OnRenderEv)

got(_ZN13GUISelCountry8OnUpdateEf)

got(_ZN13GUISelCountryC2Ev)

got(_ZN13GUISelCountry9SelBattleEii)

got(_ZN13GUISelCountry13LoadImageListEi)

got(_ZN14GUICountryListC1Ev)

got(_ZN14GUICountryList4InitERK7GUIRecti)

got(_ZN13GUISelCountry16ReleaseImageListEv)

got(_ZN13GUISelCountryD2Ev)

got(_ZN13GUISelCountryD1Ev)

got(_ZN13GUISelCountryD0Ev)

got(_ZN13GUISelCountry7OnEventERK5Event)

got(_ZN14GUICountryList15GetSelCountryIDEv)

got(_ZN10GUIServiceD2Ev)

got(_ZN10GUIServiceD1Ev)

got(_ZN10GUIServiceD0Ev)

got(_ZN10GUIService8OnRenderEv)

got(_ZN10GUIServiceC2Ev)

got(_ZN7GUIText8SetAlignEi)

got(_ZN10GUIService7OnEventERK5Event)

got(_ZN6CMedalC2Ev)

got(_ZN7CPlayerC2Ev)

got(_ZN7CPlayer10RecvPacketEPKvi)

got(_ZN7CPlayer15ClearPacketListEv)

got(_ZN7CPlayerD2Ev)

got(_ZN13GUIBattleItem8OnUpdateEf)

got(_ZN13GUIBattleItemD2Ev)

got(_ZN13GUIBattleItemD1Ev)

got(_ZN13GUIBattleItemD0Ev)

got(_ZN13GUIBattleItem8OnRenderEv)

got(_ZN13GUIBattleListD2Ev)

got(_ZN13GUIBattleListD1Ev)

got(_ZN13GUIBattleListD0Ev)

got(_ZN13GUIBattleList8OnUpdateEf)

got(_ZN13GUIBattleItemC2Ev)

got(_ZN13GUIBattleItemC1Ev)

got(_ZN13GUIBattleItem4InitEiiRK7GUIRect)

got(_ZN13GUIBattleItem11SetSelectedEb)

got(_ZN13GUIBattleListC2Ev)

got(_ZN13GUIBattleList11ResetSelectEv)

got(_ZN13GUIBattleList15ResetTouchStateEv)

got(_ZN13GUIBattleList10GelSelItemEff)

got(_ZN13GUIBattleItem7OnEventERK5Event)

got(_ZN13GUIBattleList7OnEventERK5Event)

got(_ZN14GUICountryItem8OnUpdateEf)

got(_ZN14GUICountryItemD2Ev)

got(_ZN14GUICountryItemD1Ev)

got(_ZN14GUICountryItemD0Ev)

got(_ZN14GUICountryItem8OnRenderEv)

got(_ZN14GUICountryListD2Ev)

got(_ZN14GUICountryListD1Ev)

got(_ZN14GUICountryListD0Ev)

got(_ZN14GUICountryList8OnUpdateEf)

got(_ZN14GUICountryItemC2Ev)

got(_ZN14GUICountryItemC1Ev)

got(_ZN14GUICountryItem4InitEPKcS1_RK7GUIRect)

got(_ZN14GUICountryItem11SetSelectedEb)

got(_ZN14GUICountryListC2Ev)

got(_ZN14GUICountryList11ResetSelectEv)

got(_ZN14GUICountryList15ResetTouchStateEv)

got(_ZN14GUICountryList10GelSelItemEff)

got(_ZN14GUICountryItem7OnEventERK5Event)

got(_ZN14GUICountryList9SetSelectEi)

got(_ZN14GUICountryList7OnEventERK5Event)

got(_ZN9GUIButtonD1Ev)

got(_ZN9GUIButtonD0Ev)

got(_ZN9GUIButton7SetGlowEPKc)

got(_ZN6ecText9GetHeightEv)

got(_ZN9GUIButton7SetTextEPKt)

got(_ZN6ecText7SetTextEPKt)

got(_ZN9GUIButton8SetAlphaEf)

got(_ZN10GUIElementC1Ev)

got(_ZN10GUIElement11RemoveChildEPS_)

got(_ZN10GUIElementD1Ev)

got(_ZN10GUIElementD0Ev)

got(_ZN10GUIElement4MoveEff)

got(_ZN10GUIElement11CheckInRectEffRK7GUIRect)

got(_ZN10GUIElement10SetVisibleEb)

got(_ZN10GUIElement12FindByHandleEj)

got(_ZN10GUIElement9PostEventERK5Event)

got(_ZN10GUIElement6RenderEv)

got(_ZN10GUIElement6UpdateEf)

got(_ZN8GUIImageD2Ev)

got(_ZN8GUIImageD1Ev)

got(_ZN8GUIImageD0Ev)

got(_ZN8GUIImage8OnRenderEv)

got(_ZN8GUIImageC2Ev)

got(_ZN8GUIImage8SetAlphaEf)

got(_ZN10GUIManager7OnEventERK5Event)

got(_ZN10GUIManagerD2Ev)

got(_ZN10GUIManagerD1Ev)

got(_ZN10GUIManagerD0Ev)

got(_ZN10GUIManagerC2Ev)

got(_ZN10GUIManagerC1Ev)

got(_ZN12GUIScrollBarC1Ev)

got(_ZN12GUIScrollBar4InitERK7GUIRectPKcS4_iiiii)

got(_ZN16GUIMotionManagerD2Ev)

got(_ZN16GUIMotionManagerD1Ev)

got(_ZN16GUIMotionManagerC2Ev)

got(_ZN16GUIMotionManagerC1Ev)

got(_ZN16GUIMotionManager9SetMotionEjffffft)

got(_ZN16GUIMotionManager9AddMotionEP10GUIElementffffft)

got(_ZN16GUIMotionManager10AddMotionXEP10GUIElementfft)

got(_ZN16GUIMotionManager10AddMotionYEP10GUIElementfft)

got(_ZN16GUIMotionManager8SetSpeedEjff)

got(_ZN16GUIMotionManager15GetMotionActiveEj)

got(_ZN14GUIRadioButtonD1Ev)

got(_ZN14GUIRadioButtonD0Ev)

got(_ZN14GUIRadioButton8OnRenderEv)

got(_ZN12GUIScrollBarD2Ev)

got(_ZN12GUIScrollBarD1Ev)

got(_ZN12GUIScrollBarD0Ev)

got(_ZN12GUIScrollBar8OnRenderEv)

got(_ZN12GUIScrollBarC2Ev)

got(_ZN12GUIScrollBar7OnEventERK5Event)

got(_ZN7GUITextD2Ev)

got(_ZN7GUITextD1Ev)

got(_ZN7GUITextD0Ev)

got(_ZN7GUIText8OnRenderEv)

got(_ZN7GUITextC2Ev)

got(_ZN7GUIText12SetTextColorEj)

got(_ZN9ecGameKitC2Ev)

got(_ZN9ecGameKitD2Ev)

got(_ZN9ecGameKit7ReleaseEv)

got(_ZN9ecGameKit22SendPacketToAllPlayersEPKvi)

got(_ZN18ecSessionInterfaceC2Ev)

got(_ZN18ecSessionInterfaceD2Ev)

got(_ZN18ecSessionInterface7ReleaseEv)

got(_ZN18ecSessionInterface10DisconnectEPKc)

got(_ZN18ecSessionInterface20SendPacketToAllPeersEPKvi)

got(_ZN11TiXmlString7reserveEm)

got(_ZN11TiXmlString6assignEPKcm)

got(_ZN11TiXmlString6appendEPKcm)

got(_ZNK9TiXmlNode10ToDocumentEv)

got(_ZNK9TiXmlNode9ToElementEv)

got(_ZNK9TiXmlNode9ToCommentEv)

got(_ZNK9TiXmlNode9ToUnknownEv)

got(_ZNK9TiXmlNode6ToTextEv)

got(_ZNK9TiXmlNode13ToDeclarationEv)

got(_ZN9TiXmlNode10ToDocumentEv)

got(_ZN9TiXmlNode9ToElementEv)

got(_ZN9TiXmlNode9ToCommentEv)

got(_ZN9TiXmlNode9ToUnknownEv)

got(_ZN9TiXmlNode6ToTextEv)

got(_ZN9TiXmlNode13ToDeclarationEv)

got(_ZNK12TiXmlElement9ToElementEv)

got(_ZN12TiXmlElement9ToElementEv)

got(_ZNK12TiXmlComment9ToCommentEv)

got(_ZN12TiXmlComment9ToCommentEv)

got(_ZNK9TiXmlText6ToTextEv)

got(_ZN9TiXmlText6ToTextEv)

got(_ZNK16TiXmlDeclaration13ToDeclarationEv)

got(_ZN16TiXmlDeclaration13ToDeclarationEv)

got(_ZNK12TiXmlUnknown9ToUnknownEv)

got(_ZN12TiXmlUnknown9ToUnknownEv)

got(_ZNK12TiXmlComment9StreamOutEP14TiXmlOutStream)

got(_ZNK12TiXmlUnknown9StreamOutEP14TiXmlOutStream)

got(_ZNK12TiXmlComment5PrintEP7__sFILEi)

got(_ZNK12TiXmlUnknown5PrintEP7__sFILEi)

got(_ZNK16TiXmlDeclaration5PrintEP7__sFILEi)

got(_ZN9TiXmlBase9PutStringERK11TiXmlStringPS0_)

got(_ZN9TiXmlBase9PutStringERK11TiXmlStringP14TiXmlOutStream)

got(_ZNK9TiXmlText9StreamOutEP14TiXmlOutStream)

got(_ZNK16TiXmlDeclaration9StreamOutEP14TiXmlOutStream)

got(_ZNK9TiXmlText5PrintEP7__sFILEi)

got(_ZN9TiXmlBase14StringToBufferC2ERK11TiXmlString)

got(_ZN9TiXmlBase14StringToBufferC1ERK11TiXmlString)

got(_ZN9TiXmlBase14StringToBufferD2Ev)

got(_ZN9TiXmlBase14StringToBufferD1Ev)

got(_ZN9TiXmlNodeC2ENS_8NodeTypeE)

got(_ZN9TiXmlNodeC1ENS_8NodeTypeE)

got(_ZN9TiXmlNodeD1Ev)

got(_ZN12TiXmlUnknownD2Ev)

got(_ZN12TiXmlUnknownD1Ev)

got(_ZN12TiXmlUnknownD0Ev)

got(_ZN16TiXmlDeclarationD2Ev)

got(_ZN16TiXmlDeclarationD1Ev)

got(_ZN9TiXmlTextD2Ev)

got(_ZN9TiXmlTextD1Ev)

got(_ZN9TiXmlTextD0Ev)

got(_ZN12TiXmlCommentD2Ev)

got(_ZN12TiXmlCommentD1Ev)

got(_ZN12TiXmlCommentD0Ev)

got(_ZN16TiXmlDeclarationD0Ev)

got(_ZN9TiXmlNodeD0Ev)

got(_ZNK9TiXmlNode6CopyToEPS_)

got(_ZN9TiXmlNode5ClearEv)

got(_ZN9TiXmlNode14InsertEndChildERKS_)

got(_ZN9TiXmlNode17InsertBeforeChildEPS_RKS_)

got(_ZN9TiXmlNode16InsertAfterChildEPS_RKS_)

got(_ZN9TiXmlNode12ReplaceChildEPS_RKS_)

got(_ZN9TiXmlNode11RemoveChildEPS_)

got(_ZNK9TiXmlNode10FirstChildEPKc)

got(_ZNK9TiXmlNode9LastChildEPKc)

got(_ZN9TiXmlNode9LastChildEPKc)

got(_ZNK9TiXmlNode15IterateChildrenEPKS_)

got(_ZN9TiXmlNode15IterateChildrenEPS_)

got(_ZNK9TiXmlNode11NextSiblingEPKc)

got(_ZNK9TiXmlNode15IterateChildrenEPKcPKS_)

got(_ZN9TiXmlNode11NextSiblingEPKc)

got(_ZN9TiXmlNode15IterateChildrenEPKcPS_)

got(_ZNK9TiXmlNode15PreviousSiblingEPKc)

got(_ZN9TiXmlNode15PreviousSiblingEPKc)

got(_ZNK9TiXmlNode17FirstChildElementEv)

got(_ZN9TiXmlNode17FirstChildElementEv)

got(_ZNK9TiXmlNode17FirstChildElementEPKc)

got(_ZN9TiXmlNode17FirstChildElementEPKc)

got(_ZNK9TiXmlNode18NextSiblingElementEv)

got(_ZN9TiXmlNode18NextSiblingElementEv)

got(_ZNK9TiXmlNode18NextSiblingElementEPKc)

got(_ZN9TiXmlNode18NextSiblingElementEPKc)

got(_ZNK9TiXmlNode11GetDocumentEv)

got(_ZN9TiXmlNode11GetDocumentEv)

got(_ZNK12TiXmlElement7GetTextEv)

got(_ZN13TiXmlDocumentC2Ev)

got(_ZN13TiXmlDocumentC1Ev)

got(_ZN13TiXmlDocumentC2EPKc)

got(_ZN13TiXmlDocument8LoadFileEP7__sFILE13TiXmlEncoding)

got(_ZN13TiXmlDocument8SetErrorEiPKcP16TiXmlParsingData13TiXmlEncoding)

got(_ZN13TiXmlDocument8LoadFileEPKc13TiXmlEncoding)

got(_ZNK13TiXmlDocument8SaveFileEP7__sFILE)

got(_ZNK13TiXmlDocument8SaveFileEPKc)

got(_ZNK13TiXmlDocument6CopyToEPS_)

got(_ZN13TiXmlDocumentC2ERKS_)

got(_ZN13TiXmlDocumentC1ERKS_)

got(_ZN13TiXmlDocumentaSERKS_)

got(_ZNK13TiXmlDocument5CloneEv)

got(_ZNK13TiXmlDocument5PrintEP7__sFILEi)

got(_ZNK13TiXmlDocument9StreamOutEP14TiXmlOutStream)

got(_ZNK14TiXmlAttribute4NextEv)

got(_ZNK12TiXmlElement5PrintEP7__sFILEi)

got(_ZNK12TiXmlElement9StreamOutEP14TiXmlOutStream)

got(_ZN14TiXmlAttribute4NextEv)

got(_ZNK14TiXmlAttribute8PreviousEv)

got(_ZN14TiXmlAttribute8PreviousEv)

got(_ZNK14TiXmlAttribute5PrintEP7__sFILEi)

got(_ZNK14TiXmlAttribute9StreamOutEP14TiXmlOutStream)

got(_ZNK14TiXmlAttribute13QueryIntValueEPi)

got(_ZNK14TiXmlAttribute16QueryDoubleValueEPd)

got(_ZN14TiXmlAttribute11SetIntValueEi)

got(_ZN14TiXmlAttribute14SetDoubleValueEd)

got(_ZNK14TiXmlAttribute8IntValueEv)

got(_ZNK14TiXmlAttribute11DoubleValueEv)

got(_ZNK12TiXmlComment6CopyToEPS_)

got(_ZN12TiXmlCommentC2ERKS_)

got(_ZN12TiXmlCommentC1ERKS_)

got(_ZN12TiXmlCommentaSERKS_)

got(_ZNK12TiXmlComment5CloneEv)

got(_ZNK9TiXmlText6CopyToEPS_)

got(_ZNK9TiXmlText5CloneEv)

got(_ZN16TiXmlDeclarationC2EPKcS1_S1_)

got(_ZN16TiXmlDeclarationC1EPKcS1_S1_)

got(_ZNK16TiXmlDeclaration6CopyToEPS_)

got(_ZN16TiXmlDeclarationC2ERKS_)

got(_ZN16TiXmlDeclarationC1ERKS_)

got(_ZN16TiXmlDeclarationaSERKS_)

got(_ZNK16TiXmlDeclaration5CloneEv)

got(_ZNK12TiXmlUnknown6CopyToEPS_)

got(_ZNK12TiXmlUnknown5CloneEv)

got(_ZN17TiXmlAttributeSetC2Ev)

got(_ZN17TiXmlAttributeSetC1Ev)

got(_ZN17TiXmlAttributeSetD2Ev)

got(_ZN17TiXmlAttributeSetD1Ev)

got(_ZN12TiXmlElementC2EPKc)

got(_ZN17TiXmlAttributeSet3AddEP14TiXmlAttribute)

got(_ZN17TiXmlAttributeSet6RemoveEP14TiXmlAttribute)

got(_ZN12TiXmlElement9ClearThisEv)

got(_ZN12TiXmlElementD2Ev)

got(_ZN12TiXmlElementD1Ev)

got(_ZN12TiXmlElementD0Ev)

got(_ZNK17TiXmlAttributeSet4FindERK11TiXmlString)

got(_ZNK12TiXmlElement9AttributeEPKcPi)

got(_ZNK12TiXmlElement9AttributeEPKcPd)

got(_ZN17TiXmlAttributeSet4FindERK11TiXmlString)

got(_ZN12TiXmlElement15RemoveAttributeEPKc)

got(_ZNK12TiXmlElement6CopyToEPS_)

got(_ZN12TiXmlElementC2ERKS_)

got(_ZN12TiXmlElementC1ERKS_)

got(_ZN12TiXmlElementaSERKS_)

got(_ZNK12TiXmlElement5CloneEv)

got(_ZNK11TiXmlHandle10FirstChildEv)

got(_ZNK11TiXmlHandle10FirstChildEPKc)

got(_ZNK11TiXmlHandle17FirstChildElementEv)

got(_ZNK11TiXmlHandle17FirstChildElementEPKc)

got(_ZNK11TiXmlHandle5ChildEi)

got(_ZNK11TiXmlHandle5ChildEPKci)

got(_ZNK11TiXmlHandle12ChildElementEi)

got(_ZNK11TiXmlHandle12ChildElementEPKci)

got(_ZN12TiXmlElement5ParseEPKcP16TiXmlParsingData13TiXmlEncoding)

got(_ZN12TiXmlComment5ParseEPKcP16TiXmlParsingData13TiXmlEncoding)

got(_ZN9TiXmlText5ParseEPKcP16TiXmlParsingData13TiXmlEncoding)

got(_ZN16TiXmlDeclaration5ParseEPKcP16TiXmlParsingData13TiXmlEncoding)

got(_ZN12TiXmlUnknown5ParseEPKcP16TiXmlParsingData13TiXmlEncoding)

got(_ZNK13TiXmlDocument10ToDocumentEv)

got(_ZN13TiXmlDocument10ToDocumentEv)

got(_ZN14TiXmlAttributeD2Ev)

got(_ZN14TiXmlAttributeD1Ev)

got(_ZN13TiXmlDocumentD2Ev)

got(_ZN13TiXmlDocumentD1Ev)

got(_ZN13TiXmlDocumentD0Ev)

got(_ZN14TiXmlAttributeD0Ev)

got(_ZN9TiXmlBase18ConvertUTF32ToUTF8EmPcPi)

got(_ZN9TiXmlBase7IsAlphaEh13TiXmlEncoding)

got(_ZN9TiXmlBase10IsAlphaNumEh13TiXmlEncoding)

got(_ZN16TiXmlParsingData5StampEPKc13TiXmlEncoding)

got(_ZN9TiXmlBase14SkipWhiteSpaceEPKc13TiXmlEncoding)

got(_ZN9TiXmlBase8ReadNameEPKcP11TiXmlString13TiXmlEncoding)

got(_ZN9TiXmlBase9GetEntityEPKcPcPi13TiXmlEncoding)

got(_ZN9TiXmlBase11StringEqualEPKcS1_b13TiXmlEncoding)

got(_ZN9TiXmlBase8ReadTextEPKcP11TiXmlStringbS1_b13TiXmlEncoding)

got(_ZN14TiXmlAttribute5ParseEPKcP16TiXmlParsingData13TiXmlEncoding)

got(_ZN9TiXmlNode8IdentifyEPKc13TiXmlEncoding)

got(_ZN13TiXmlDocument5ParseEPKcP16TiXmlParsingData13TiXmlEncoding)

got(_ZNK9TiXmlText5BlankEv)

got(_ZN12TiXmlElement9ReadValueEPKcP16TiXmlParsingData13TiXmlEncoding)

got(_ZNK9hgeVector5AngleEPKS_)

got(_ZN7ecImageD2Ev)

got(_ZN7ecImage4InitEP9ecTextureffff)

got(_ZN7ecImageC2EP9ecTextureffff)

got(_ZN7ecImageC2EP9ecTextureRK13ecTextureRect)

got(_ZN7ecImageC2EP11ecImageAttr)

got(_ZN7ecImage13RenderStretchEffff)

got(_ZN7ecImage8Render4VEffffffff)

got(_ZN7ecImage10SetTextureEP9ecTexture)

got(_ZN7ecImage7SetFlipEbbb)

got(_ZN7ecImage14SetTextureRectEffff)

got(_ZN7ecImage14SetTextureRectERK13ecTextureRect)

got(_ZN12ecTextureResC2Ev)

got(_ZN12ecTextureRes14ReleaseTextureEP9ecTexture)

got(_ZN12ecTextureResD2Ev)

got(_ZN12ecTextureRes10GetTextureEPKc)

got(_ZN12ecTextureRes13CreateTextureEPKcbbb)

got(_ZN12ecTextureRes11CreateImageEPKcP9ecTextureffffff)

got(_ZN12ecTextureRes11CreateImageEPKcS1_ffffff)

got(_ZN11ecEffectResC2Ev)

got(_ZN11ecEffectResC1Ev)

got(_ZN11ecEffectRes7ReleaseEv)

got(_ZN11ecEffectResD2Ev)

got(_ZN11ecEffectResD1Ev)

got(_ZN11ecEffectRes10LoadEffectEPKcP12ecTextureRes)

got(_ZN18ecEffectResManager16ReleaseEffectResEP11ecEffectRes)

got(_ZN18ecEffectResManagerC2Ev)

got(_ZN18ecEffectResManagerC1Ev)

got(_ZN18ecEffectResManagerD2Ev)

got(_ZN18ecEffectResManagerD1Ev)

got(_ZN18ecEffectResManager16ReleaseEffectResEPKc)

got(_ZN8ecEffectC2Ev)

got(_ZN8ecEffectC1Ev)

got(_ZN8ecEffectD2Ev)

got(_ZN8ecEffect4InitEPKcP9TFreeListI16ecParticleSystemE)

got(_ZN16ecParticleSystem4InitEP13ecEmitterAttr)

got(_ZN16ecParticleSystem6FireAtEfff)

got(_ZN8ecEffect4FireEv)

got(_ZN16ecParticleSystem4FireEv)

got(_ZN8ecEffect4StopEb)

got(_ZN16ecParticleSystem4StopEb)

got(_ZN8ecEffect6MoveToEffb)

got(_ZN16ecParticleSystem6MoveToEffb)

got(_ZN16ecParticleSystem6UpdateEf)

got(_ZN16ecParticleSystem6RenderEv)

got(_ZN16ecParticleSystem6IsLiveEv)

got(_ZN15ecEffectManagerC2Ev)

got(_ZN16ecParticleSystemC1Ev)

got(_ZN16ecParticleSystemD1Ev)

got(_ZN15ecEffectManagerC1Ev)

got(_ZN15ecEffectManagerD2Ev)

got(_ZN15ecEffectManagerD1Ev)

got(_ZN9ecUniFontC2Ev)

got(_ZN9ecUniFont12GetCharImageEt)

got(_ZN9ecUniFontD2Ev)

got(_ZN11ecLabelTextC2Ev)

got(_ZN11ecLabelTextD2Ev)

got(_ZN11ecLabelText8SetAlphaEf)

got(_ZN10CCSoundBoxC2Ev)

got(_ZN10CCSoundBoxC1Ev)

got(_ZN10CCSoundBoxD2Ev)

got(_ZN10CCSoundBoxD1Ev)

got(_ZN10CCSoundBox15InitSoundSystemEv)
bss(_ZN10CCSoundBox9mInstanceE, 8)

got(_ZN10CCSoundBox18DestroySoundSystemEv)

got(_ZN10CCSoundBox9StopMusicEv)

got(_ZN10CCSoundBox9StopAllSEEv)

got(_ZN13ecStringTableC2Ev)

got(_ZN13ecStringTableD2Ev)

got(_ZN6ecTextC2Ev)

got(_ZN6ecTextD2Ev)

got(_ZN6ecText11GetNumLinesEv)

got(_Z22ecSetIdleTimerDisabledb)

got(_ZN16ecParticleSystemC2Ev)

got(_ZN16ecParticleSystemD2Ev)

got(_ZN9ecLibraryC2Ev)

got(_ZN9ecLibrary11GetItemDataEi)

got(_ZN9ecLibrary12FindItemDataEPKc)

got(_ZN9ecLibrary14GetElementDataEi)

got(_ZN9ecLibrary12GetFrameDataEi)

got(_ZN9ecLibrary12GetLayerDataEi)

got(_ZN9ecLibrary11GetItemNameEj)

got(_ZN9ecLibraryD2Ev)

got(_ZN7ecShapeD1Ev)

got(_ZN9ecLibraryD1Ev)

got(_ZN9ecLibraryD0Ev)

got(_Z13ecLoadLibraryPKcR13ecLibraryData)

got(_ZN7ecShapeC1Ev)

got(_ZN7ecShape4InitEP9ecTextureffff)

got(_Z14ecSaveLibrarayPKcR13ecLibraryDataS0_i)

got(_ZN9ecElementC2Ev)

got(_ZN9ecElementD2Ev)

got(_ZN9ecElement4InitEP10ecItemDataP9ecLibrary)

got(_ZN7ecLayerC1Ev)

got(_ZN7ecFrameC1Ev)

got(_ZN7ecLayer4InitEiP11ecLayerDataP7ecFrameP9ecElementP9ecLibrary)

got(_ZN7ecLayer11SetCurFrameEi)

got(_ZN9ecElement5ResetEv)

got(_ZN7ecLayer4PlayEv)

got(_ZN9ecElement4StopEv)

got(_ZN7ecLayer4StopEv)

got(_ZN7ecLayer7SetLoopEi)

got(_ZN9ecElement4InitEP13ecElementDataP9ecLibrary)

got(_ZN9ecElement9ResetItemEP10ecItemDataP9ecLibrary)

got(_ZN9ecElement10ChangeItemEP10ecItemDataS1_P9ecLibrary)

got(_ZN7ecLayer10ChangeItemEP10ecItemDataS1_P9ecLibrary)

got(_ZN9ecElement10ChangeItemEPKcS1_P9ecLibrary)

got(_ZN7ecShape8SetColorEj)

got(_ZN7ecShape6RenderERK7ecMtx32)

got(_ZN7ecLayer6RenderERK7ecMtx32)

got(_ZN9ecElement9NextFrameEv)

got(_ZN7ecLayer9NextFrameEv)

got(_ZN7ecShapeC2Ev)

got(_ZN7ecShapeD2Ev)

got(_ZN7ecLayerD2Ev)

got(_ZN7ecLayerD1Ev)

got(_ZN7ecLayerD0Ev)

got(_ZN7ecLayerC2Ev)

got(_ZN7ecFrame10ChangeItemEP10ecItemDataS1_P9ecLibrary)

got(_ZN7ecFrame4PlayEv)

got(_ZN7ecFrame4StopEv)

got(_ZN7ecFrame4InitEP11ecFrameDataP9ecElementP9ecLibrary)

got(_ZN7ecFrame6RenderERK7ecMtx32)

got(_ZN7ecFrame9NextFrameEv)

got(_ZN7ecFrame5ResetEv)

got(_ZN7ecFrameD2Ev)

got(_ZN7ecFrameD1Ev)

got(_ZN7ecFrameD0Ev)

got(_ZN7ecFrameC2Ev)

void __attribute__((visibility("hidden"))) resolvesymbol() {
    size_t BaseAddress = (size_t) dlsym(dlopen(GameLib, RTLD_NOLOAD), "SetLangDir") - 343392;
    off(_ZN7_JNIEnv16CallObjectMethodEP8_jobjectP10_jmethodIDz, 343504)
    off(_ZN7_JNIEnv23CallStaticBooleanMethodEP7_jclassP10_jmethodIDz, 343696)
    off(_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz, 343888)
    off(_ZN7_JNIEnv21CallStaticFloatMethodEP7_jclassP10_jmethodIDz, 344080)
    off(_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz, 344272)
    off(_Z24ecGameDidEnterBackgroundv, 404816)
    off(_Z14ecGameShutdownv, 404464)
    off(_Z7GetPathPKcS0_, 351184)
    off(_Z18ecPurchasedProducti, 406208)
    off(_Z10ecGameInitiiiii, 406896)
    off(_Z18ecSetInAppPurchasePFviE, 406256)
    off(_Z11ecGamePausev, 404768)
    off(_Z25ecGameWillEnterForegroundv, 404864)
    off(_Z12ecGameResumev, 404784)
    off(_Z13ecBackPressedv, 405856)
    off(_ZN13CStateManager8InstanceEv, 638464)
    off(_ZN13CStateManager11GetStatePtrE6EState, 639088)
    off(_ZN10CMenuState8ShowExitEv, 567184)
    off(_Z12ecGameUpdatef, 404960)
    off(_Z12ecGameRenderv, 405088)
    off(_ZN10ecGraphics8InstanceEv, 351792)
    off(_ZN15ecMultipleTouch8InstanceEv, 361104)
    off(_ZN15ecMultipleTouch10TouchBeganEff, 361184)
    off(_Z12ecTouchBeginffi, 405232)
    off(_ZN15ecMultipleTouch5ResetEv, 361120)
    off(_ZN15ecMultipleTouch10TouchMovedEff, 361312)
    off(_Z11ecTouchMoveffi, 405440)
    off(_ZN15ecMultipleTouch10TouchEndedEff, 361440)
    off(_Z10ecTouchEndffi, 405648)
    off(_ZN10CCommander8BuyMedalEi, 403776)
    off(_ZN10CCommander4SaveEv, 403040)
    off(_Z17ecSetProductPriceiPKc, 406144)
    off(_ZN6ecFileC1Ev, 361568)
    off(_ZN6ecFile11IsFlieExistEPKc, 361808)
    off(_ZN6ecFileD1Ev, 361696)
    off(_Z9Get2XPathPKcS0_, 351408)
    off(_Z15GetDocumentPathPKc, 351584)
    off(_Z16GetEditorResPathPKc, 351648)
    off(_ZN10ecGraphicsC2Ev, 351664)
    off(_ZN10ecGraphicsC1Ev, 351664)
    off(_ZN10ecGraphics4InitEiiiii, 351808)
    off(_ZN10ecGraphics8ShutdownEv, 352288)
    off(_ZN10ecGraphics14SetOrientationEi, 352304)
    off(_ZN10ecGraphics11RenderBeginEv, 352352)
    off(_ZN10ecGraphics13CreateTextureEii, 352400)
    off(_ZN10ecGraphics11FreeTextureEP9ecTexture, 352416)
    off(_ZN10ecGraphics5FlushEv, 352816)
    off(_ZN10ecGraphics9RenderEndEv, 352976)
    off(_ZN10ecGraphics12SetViewPointEfff, 352992)
    off(_ZN10ecGraphics12SetBlendModeEi, 353328)
    off(_ZN10ecGraphics11BindTextureEP9ecTexture, 353440)
    off(_ZN10ecGraphics23CreateTextureWithStringEPKcS1_iiii, 353536)
    off(_Z19ecTextureWithStringPKcS0_iiRiS1_Rj, 394880)
    off(_ZN10ecGraphics10RenderLineEPK6ecLine, 353712)
    off(_ZN10ecGraphics12RenderTripleEPK8ecTriple, 353840)
    off(_ZN10ecGraphics10RenderQuadEPK6ecQuad, 354000)
    off(_ZN10ecGraphics10RenderRectEffffm, 354352)
    off(_ZN10ecGraphics12RenderCircleEfffj, 354688)
    off(_ZN10ecGraphics4FadeEf, 355088)
    off(_ZN10ecGraphicsD2Ev, 355568)
    off(_ZN10ecGraphicsD1Ev, 355568)
    off(_ZN10ecGraphics11LoadTextureEPKc, 356960)
    off(_Z13ecTextureLoadPKcRiS1_Rj, 387872)
    off(_ZN10ecGraphics15LoadWEBPTextureEPKc, 357968)
    off(_Z17ecWEBPTextureLoadPKcRiS1_Rj, 393856)
    off(_ZN10ecGraphics14LoadPVRTextureEPKc, 358976)
    off(_Z16ecPVRTextureLoadPKcRiS1_Rj, 392224)
    off(_ZN10ecGraphics14LoadETCTextureEPKc, 359984)
    off(_Z16ecETCTextureLoadPKcRiS1_Rj, 392992)
    off(_ZN15ecMultipleTouchD2Ev, 361024)
    off(_ZN15ecMultipleTouchD1Ev, 361024)
    off(_ZN15ecMultipleTouchC2Ev, 361088)
    off(_ZN15ecMultipleTouchC1Ev, 361088)
    off(_ZN6ecFileC2Ev, 361568)
    off(_ZN3MD5C1Ev, 363792)
    off(_ZN6ecFile5CloseEv, 361632)
    off(_ZN6ecFileD2Ev, 361696)
    off(_ZN6ecFile4OpenEPKcS1_, 361712)
    off(_ZN6ecFile4ReadEPvj, 361904)
    off(_ZN6ecFile5WriteEPKvj, 362000)
    off(_ZN6ecFile4SeekEli, 362048)
    off(_ZN6ecFile9GetCurPosEv, 362128)
    off(_ZN6ecFile7GetSizeEv, 362224)
    off(_ZN6ecFile12CheckJavaDexEv, 362352)
    off(_ZN6ecFile18GetFileDataFromZipEPKcS1_Pm, 362400)
    off(_ZN3MD55resetEv, 363728)
    off(_ZN3MD56updateEPKvm, 367664)
    off(_ZN3MD58toStringEv, 368608)
    off(_ZN8CheckMD5C1Ev, 368672)
    off(_ZN8CheckMD56INfileEPKcS1_, 368688)
    off(_ZN6ecFile21CheckFileExistFromZipEPKcS1_, 363504)
    off(_ZN3MD5C2Ev, 363792)
    off(_ZN3MD56encodeEPKmPhm, 363840)
    off(_ZN3MD56decodeEPKhPmm, 363936)
    off(_ZN3MD59transformEPKh, 364032)
    off(_ZN3MD56updateEPKhm, 367200)
    off(_ZN3MD5C2EPKvm, 367680)
    off(_ZN3MD5C1EPKvm, 367680)
    off(_ZN3MD56updateERSt14basic_ifstreamIcSt11char_traitsIcEE, 367728)
    off(_ZN3MD5C2ERSt14basic_ifstreamIcSt11char_traitsIcEE, 367936)
    off(_ZN3MD5C1ERSt14basic_ifstreamIcSt11char_traitsIcEE, 367936)
    off(_ZN3MD56updateERKSs, 367984)
    off(_ZN3MD5C2ERKSs, 368000)
    off(_ZN3MD5C1ERKSs, 368000)
    off(_ZN3MD55finalEv, 368048)
    off(_ZN3MD56digestEv, 368272)
    off(_ZN3MD516bytesToHexStringEPKhm, 368320)
    off(_ZN8CheckMD5C2Ev, 368672)
    off(_ZN10CCommanderD2Ev, 402112)
    off(_ZN10CCommanderD1Ev, 402112)
    off(_Z19GetCommanderAbilityi, 402128)
    off(_ZN10CCommanderC2Ev, 402160)
    off(_ZN10CCommanderC1Ev, 402160)
    off(_ZN10CCommander4LoadEv, 402416)
    off(_ZN10CCommander15GetUpgradeMedalEv, 403648)
    off(_ZN10CCommander12CheckUpgardeEv, 403680)
    off(_ZN10CCommander7UpgradeEv, 403712)
    off(_ZN10CCommander10IsMaxLevelEv, 403760)
    off(_ZN10CCSoundBox11GetInstanceEv, 971712)
    off(_ZN10CCSoundBox6PlaySEEPKc, 972080)
    off(_ZN10CCommander16GetWarMedalLevelE11WARMEDAL_ID, 403824)
    off(_ZN10CCommander19GetNeedUpgradeMedalE11WARMEDAL_ID, 403840)
    off(_ZN10CCommander20CheckUpgradeWarMedalE11WARMEDAL_ID, 403872)
    off(_ZN10CCommander15UpgradeWarMedalE11WARMEDAL_ID, 403904)
    off(_ZN10CCommander20SetNumPlayedBatttlesEii, 403968)
    off(_ZN10CCommander20GetNumPlayedBatttlesEi, 403984)
    off(_ZN10CCommander15SetBattlePlayedEii, 404000)
    off(_ZN10CCommander17GetNumBattleStarsEii, 404064)
    off(_ZN10CCommander17SetNumBattleStarsEiii, 404112)
    off(_ZN10CCommander16GetCommanderDataER13CommanderData, 404144)
    off(_ZN14CPlayerManager7ReleaseEv, 604000)
    off(_ZN9ecUniFont7ReleaseEv, 968320)
    off(_ZN10CCSoundBox8UnloadSEEPKc, 972064)
    off(_ZN13CStateManager4TermEv, 638560)
    off(_ZN10GUIManager8InstanceEv, 797168)
    off(_ZN10GUIElement12FreeAllChildEv, 794272)
    off(_ZN10GUIManager16ReleaseTexureResEv, 797232)
    off(_ZN10CCSoundBox7DestroyEv, 971824)
    off(_ZN10CObjectDef8InstanceEv, 567872)
    off(_ZN10CObjectDef7DestroyEv, 577872)
    off(_ZN13ecStringTable5ClearEv, 972928)
    off(_Z13ecGameWaitingb, 404800)
    off(_ZN13CStateManager15EnterBackgroundEv, 638992)
    off(_ZN10CCSoundBox14SetMusicVolumeEi, 971984)
    off(_ZN10CCSoundBox11SetSEVolumeEi, 972016)
    off(_ZN10CCSoundBox11ResumeMusicEv, 971968)
    off(_ZN13CStateManager15EnterForegroundEv, 639024)
    off(_ZN14CPlayerManager6UpdateEf, 616800)
    off(_ZN13CStateManager6UpdateEf, 638656)
    off(_ZN10GUIManager6UpdateEf, 797472)
    off(_ZN16GUIMotionManager8InstanceEv, 799024)
    off(_ZN16GUIMotionManager10ProcMotionEv, 800768)
    off(_ZN10CCSoundBox11UpdateSoundEv, 972112)
    off(_ZN13CStateManager6RenderEv, 638768)
    off(_ZN10GUIManager6RenderEv, 797376)
    off(_ZN10GUIManager9PostEventERK5Event, 797344)
    off(_ZN13CStateManager10TouchBeginEffi, 638800)
    off(_ZN13CStateManager9TouchMoveEffi, 638832)
    off(_ZN13CStateManager8TouchEndEffi, 638864)
    off(_ZN13CStateManager11BackPressedEv, 638896)
    off(_Z15ecAccelerometerfff, 405952)
    off(_Z13ecScrollWheelfff, 405968)
    off(_ZN13CStateManager11ScrollWheelEfff, 638960)
    off(_Z9ecKeyDowni, 406032)
    off(_ZN13CStateManager7KeyDownEi, 638928)
    off(_Z18ecSetShowReviewFucPFvvE, 406064)
    off(_Z12ecShowReviewv, 406080)
    off(_Z17ecGetProductPricei, 406112)
    off(_Z15ecInAppPurchasei, 406272)
    off(_Z18ecAppWillTerminatev, 406304)
    off(_Z22ecApplicationTerminatev, 406320)
    off(_Z14ecLoadSettingsv, 406336)
    off(_ZN13CGameSettings12LoadSettingsEv, 462176)
    off(_Z14ecIsFullScreenv, 406352)
    off(_Z15ecSetFullScreenb, 406368)
    off(_ZN13CGameSettings12SaveSettingsEv, 462512)
    off(_Z13SetAIRandSeedi, 647040)
    off(_Z11SetRandSeedi, 411808)
    off(_ZN10GUIManager4InitERK7GUIRect, 797184)
    off(_ZN13CStateManager4InitEv, 638480)
    off(_ZN10CLogoStateC1Ev, 559472)
    off(_ZN10CMenuStateC1Ev, 561552)
    off(_ZN11CMatchStateC1Ev, 560032)
    off(_ZN10CLoadStateC1Ev, 557808)
    off(_ZN10CGameStateC1Ev, 465248)
    off(_ZN10CEditStateC1Ev, 410752)
    off(_ZN13CStateManager13RegisterStateEP10CBaseState, 639056)
    off(_ZN13CStateManager11SetCurStateE6EState, 639072)
    off(_ZN13ecStringTable4LoadEPKc, 974592)
    off(_ZN13ecStringTable9GetStringEPKc, 972176)
    off(_ZN10CObjectDef4InitEv, 598992)
    off(_ZN10CCSoundBox6LoadSEEPKc, 972048)
    off(_ZN9ecUniFont4InitEPKcb, 968832)
    off(_ZN10CBaseState7OnEnterEv, 409616)
    off(_ZN10CBaseState6OnExitEv, 409632)
    off(_ZN10CBaseState10TouchBeginEffi, 409648)
    off(_ZN10CBaseState9TouchMoveEffi, 409664)
    off(_ZN10CBaseState8TouchEndEffi, 409680)
    off(_ZN10CBaseState11BackPressedEv, 409696)
    off(_ZN10CBaseState7KeyDownEi, 409712)
    off(_ZN10CBaseState11ScrollWheelEfff, 409728)
    off(_ZN10CBaseState15EnterBackgroundEv, 409744)
    off(_ZN10CBaseState15EnterForegroundEv, 409760)
    off(_ZN10CEditState7KeyDownEi, 409776)
    off(_ZN10CEditState7OnEventERK5Event, 409792)
    off(_ZN10CEditStateD2Ev, 409824)
    off(_ZN13CTouchInertiaD1Ev, 639104)
    off(_ZN10CEditStateD1Ev, 409824)
    off(_ZN10CEditStateD0Ev, 409888)
    off(_ZN10CEditState6UpdateEf, 409936)
    off(_ZN13CTouchInertia6UpdateEf, 639184)
    off(_ZN13CTouchInertia8GetSpeedERfS0_, 639264)
    off(_ZN15ecEffectManager8InstanceEv, 967216)
    off(_ZN15ecEffectManager6UpdateEf, 967840)
    off(_ZN6CScene6UpdateEf, 626336)
    off(_ZN6CScene4MoveEii, 627760)
    off(_ZN13CTouchInertia4StopEv, 639168)
    off(_ZN7CCamera13SetAutoFixPosEb, 691712)
    off(_ZN10CEditState6RenderEv, 410224)
    off(_ZN6CScene6RenderEv, 628896)
    off(_ZN6CScene14RenderAreasTaxEv, 621648)
    off(_ZN6CScene15RenderAreasTypeEv, 621632)
    off(_ZN10CEditState10TouchBeginEffi, 410320)
    off(_ZN13CTouchInertia10TouchBeginEffi, 639392)
    off(_ZN10CEditState9TouchMoveEffi, 410400)
    off(_ZN13CTouchInertia9TouchMoveEffi, 639472)
    off(_ZN10CEditState8TouchEndEffi, 410512)
    off(_ZN13CTouchInertia8TouchEndEffi, 639840)
    off(_ZN6CScene12ScreenToAreaEff, 627872)
    off(_ZN6CScene15GetSelectedAreaEv, 628640)
    off(_ZN6CScene12UnselectAreaEv, 628736)
    off(_ZN6CScene10SelectAreaEP5CArea, 632640)
    off(_ZN10CEditStateC2Ev, 410752)
    off(_ZN13CTouchInertiaC1Ev, 639152)
    off(_ZN10CEditState8InitGameEv, 410816)
    off(_ZN12CGameManager7NewGameEiiii, 421744)
    off(_ZN9CSoundRes4LoadEv, 638144)
    off(_ZN8CGameRes4LoadEv, 448992)
    off(_ZN6CScene4InitEPKci, 637632)
    off(_ZN13CTouchInertia4InitEv, 639120)
    off(_ZN10CEditState7OnEnterEv, 411600)
    off(_ZN10GUIManager6FadeInEi, 797248)
    off(_ZN10CEditState11ReleaseGameEv, 411696)
    off(_ZN6CScene7ReleaseEv, 621792)
    off(_ZN8CGameRes7ReleaseEv, 441696)
    off(_ZN9CSoundRes6UnloadEv, 638304)
    off(_ZN10CEditState6OnExitEv, 411744)
    off(_ZN16GUIMotionManager11ClearMotionEv, 799168)
    off(_ZN9CActionAID2Ev, 411792)
    off(_ZN9CActionAI18setActionNodeClearEv, 641376)
    off(_ZN9CActionAID1Ev, 411792)
    off(_Z11GetRandSeedv, 411824)
    off(_Z7GetRandv, 411840)
    off(_ZN6CFightC2Ev, 411888)
    off(_ZN6CFightC1Ev, 411888)
    off(_ZN6CFightD2Ev, 411936)
    off(_ZN6CFightD1Ev, 411936)
    off(_ZN6CFight16AirStrikesAttackEP8CCountryii, 412000)
    off(_ZN6CScene7GetAreaEi, 627856)
    off(_ZN8CCountry16GetWarMedalLevelE11WARMEDAL_ID, 698960)
    off(_ZN10CObjectDef10GetArmyDefEiPKc, 578192)
    off(_ZN6CFight16AirStrikesAttackEii, 412368)
    off(_ZN6CFight17GetAttackerResultEi, 412464)
    off(_ZN6CFight17GetDefenderResultEi, 412480)
    off(_ZN6CFight12GetAttackAddEi, 412496)
    off(_ZN6CFight12GetDefendAddEi, 412512)
    off(_ZN6CFight11ApplyResultEv, 412544)
    off(_ZN5CArea7GetArmyEi, 668752)
    off(_ZN5CArea16LostArmyStrengthEii, 670752)
    off(_ZN6CScene25AdjacentAreasEncirclementEi, 632832)
    off(_ZN8CCountry10AddDestroyEi, 697120)
    off(_ZN5CArea23ReduceConstructionLevelEv, 668432)
    off(_ZN5CArmy6IsNavyEv, 675184)
    off(_ZN15ecEffectManager9AddEffectEPKcb, 967328)
    off(_ZN8ecEffect6FireAtEfff, 966224)
    off(_ZN13CFightTextMgr7AddTextEffPKcj, 419584)
    off(_ZN9CSoundRes10PlayCharSEE10SND_EFFECT, 638384)
    off(_ZN5CArmy6AddExpEi, 675792)
    off(_Z9GetAIRandv, 647072)
    off(_ZN8CCountry13IsLocalPlayerEv, 704640)
    off(_ZN6CScene9GainMedalEff, 633072)
    off(_ZN5CArea19DestroyConstructionEv, 668576)
    off(_ZN5CArea12ClearAllArmyEv, 670384)
    off(_ZN5CArmy12BreakthroughEv, 675936)
    off(_ZN5CArea10OccupyAreaEPS_, 670144)
    off(_ZN6CFight12NormalAttackEii, 416320)
    off(_ZN5CArmy11GetNumDicesEv, 675552)
    off(_ZN8CCountry17GetCommanderLevelEv, 698016)
    off(_Z14GetArmyAbilityi, 675120)
    off(_ZN5CArmy25GetNumDicesIfLostStrengthEi, 675632)
    off(_ZN6CFight11FirstAttackEii, 418000)
    off(_ZN6CFight12SecondAttackEv, 418048)
    off(_ZN10CFightTextC2Ev, 418112)
    off(_ZN6ecTextC1Ev, 976144)
    off(_ZN10CFightTextC1Ev, 418112)
    off(_ZN10CFightTextD2Ev, 418128)
    off(_ZN6ecTextD1Ev, 976176)
    off(_ZN10CFightTextD1Ev, 418128)
    off(_ZN13CFightTextMgrD2Ev, 418144)
    off(_ZN9ecUniFontD1Ev, 968576)
    off(_ZN13CFightTextMgrD1Ev, 418144)
    off(_ZN10CFightText4InitEffP9ecUniFont, 418336)
    off(_ZN6ecText4InitEP9ecUniFont, 976208)
    off(_ZN10CFightText7SetTextEPKc, 418384)
    off(_ZN6ecText7SetTextEPKc, 977392)
    off(_ZN10CFightText8SetColorEj, 418400)
    off(_ZN6ecText8SetColorEj, 976240)
    off(_ZN10CFightText6UpdateEf, 418416)
    off(_ZN6ecText8SetAlphaEf, 976256)
    off(_ZN10CFightText6RenderEv, 418544)
    off(_ZN6ecText8DrawTextEffi, 976464)
    off(_ZN13CFightTextMgrC2Ev, 418576)
    off(_ZN9ecUniFontC1Ev, 968064)
    off(_ZN13CFightTextMgrC1Ev, 418576)
    off(_ZN13CFightTextMgr4InitEv, 418752)
    off(_ZN13CFightTextMgr7ReleaseEv, 419232)
    off(_ZN13CFightTextMgr6UpdateEf, 419392)
    off(_ZN13CFightTextMgr6RenderEv, 419520)
    off(_ZN13CActionAssistD2Ev, 419760)
    off(_ZN13CActionAssistD1Ev, 419760)
    off(_ZN12CGameManagerD2Ev, 419792)
    off(_ZN12CGameManagerD1Ev, 419792)
    off(_Z13GetNumBattlesi, 419856)
    off(_Z16GetBattleKeyNameiiPc, 419952)
    off(_Z18GetConquestKeyNameiPc, 420112)
    off(_Z17GetBattleFileNameiiiiPc, 420144)
    off(_Z24GetNumMultiPlayerBattlesi, 420384)
    off(_Z24GetBattleBelligerentListPKcRSt4listI11BelligerentSaIS2_EEb, 420480)
    off(_ZN13TiXmlDocumentC1EPKc, 893184)
    off(_ZN13TiXmlDocument8LoadFileE13TiXmlEncoding, 894176)
    off(_ZN9TiXmlNodeD2Ev, 890112)
    off(_ZN9TiXmlNode10FirstChildEPKc, 891440)
    off(_ZNK12TiXmlElement9AttributeEPKc, 899072)
    off(_ZNK12TiXmlElement17QueryIntAttributeEPKcPi, 899536)
    off(_ZN12CGameManagerC2Ev, 421376)
    off(_ZN12CGameManagerC1Ev, 421376)
    off(_ZN12CGameManager4InitEv, 421472)
    off(_ZN12CGameManager20SetPlayercountrynameEiPKc, 421488)
    off(_ZN12CGameManager11GetPlayerNoEPKc, 421520)
    off(_ZN12CGameManager20GetPlayerCountryNameEi, 421696)
    off(_ZN12CGameManager26SetConquestPlayerCountryIDEPKc, 421728)
    off(_ZN10CObjectDef12GetBattleDefEPKc, 570144)
    off(_ZN12CGameManager8LoadGameEPKc, 422016)
    off(_ZN12CGameManager9RetryGameEv, 422352)
    off(_ZN12CGameManager8SaveGameEPKc, 422368)
    off(_ZN8CCountry11SaveCountryEP15SaveCountryInfo, 696512)
    off(_ZN5CArea8SaveAeraEP12SaveAreaInfo, 673952)
    off(_ZN12CGameManager13GetSaveHeaderEPKcR10SaveHeader, 423584)
    off(_ZN12CGameManager11ClearBattleEv, 423776)
    off(_ZN8CCountryD1Ev, 693344)
    off(_ZN12CGameManager7ReleaseEv, 424080)
    off(_ZN12CGameManager10NextBattleEv, 424096)
    off(_ZN12CGameManager12IsLastBattleEv, 424112)
    off(_ZN12CGameManager15GetNumCountriesEv, 424160)
    off(_ZN12CGameManager17GetCountryByIndexEi, 424176)
    off(_ZN12CGameManager11FindCountryEPKc, 424192)
    off(_ZN12CGameManager13GetCurCountryEv, 424304)
    off(_ZN12CGameManager13InitCameraPosEv, 424336)
    off(_ZN8CCountry19GetHighestValueAreaEv, 694464)
    off(_ZN6CScene15SetCameraToAreaEi, 627920)
    off(_ZN12CGameManager16GetPlayerCountryEv, 424400)
    off(_ZN12CGameManager21GetLocalPlayerCountryEv, 424480)
    off(_ZN12CGameManager15GetNumDialoguesEv, 424640)
    off(_ZN12CGameManager18GetDialogueByIndexEi, 424656)
    off(_ZN12CGameManager10SaveBattleEPKc, 424672)
    off(_ZN12TiXmlElementC1EPKc, 898560)
    off(_ZN12TiXmlElement12SetAttributeEPKci, 901248)
    off(_ZN12TiXmlElement12SetAttributeEPKcS1_, 900560)
    off(_ZN12TiXmlElement18SetDoubleAttributeEPKcd, 901360)
    off(_ZN9TiXmlNode12LinkEndChildEPS_, 890800)
    off(_ZN8CCountry16GetCommanderNameEv, 697984)
    off(_ZN6CScene11GetNumAreasEv, 627840)
    off(_ZNK13TiXmlDocument8SaveFileEv, 894496)
    off(_ZN12CGameManager14GetCurDialogueEv, 427184)
    off(_ZN12CGameManager20GetCurDialogueStringEPc, 427248)
    off(_ZN12CGameManager12NextDialogueEv, 427520)
    off(_ZN12CGameManager18GetNumVictoryStarsEv, 427536)
    off(_ZN12CGameManager17CheckAndSetResultEv, 427632)
    off(_ZN8CCountry12IsConquestedEv, 695040)
    off(_ZN12CGameManager13BattleVictoryEv, 428384)
    off(_ZN12CGameManager21GetNewDefeatedCountryEv, 428608)
    off(_ZN12CGameManager12IsManipulateEv, 428720)
    off(_ZN8CCountry14IsActionFinishEv, 696496)
    off(_ZN12CGameManager9TurnBeginEv, 428832)
    off(_ZN8CCountry9TurnBeginEv, 700832)
    off(_ZN10CGameState16UpdateActionInfoEv, 471696)
    off(_ZN10CGameState18PlayerCountryBeginEv, 470016)
    off(_ZN8CCountry6ActionERK13CountryAction, 704704)
    off(_ZN12CGameManager7TurnEndEv, 429040)
    off(_ZN8CCountry7TurnEndEv, 696256)
    off(_ZN12CGameManager7EndTurnEv, 429088)
    off(_ZN10CGameState12ShowDialogueEPKcS1_b, 470256)
    off(_ZN10CGameState14HideAIProgressEv, 469952)
    off(_ZN12CGameManager4NextEv, 430144)
    off(_ZN9CActionAI16setCpuDriverbyIdEii, 646160)
    off(_ZN14CPlayerManager13DoFrontActionEv, 616352)
    off(_ZN5CArea13SetArmyActiveEib, 671216)
    off(_ZN12CGameManager10GameUpdateEf, 431248)
    off(_ZN8CCountry6UpdateEf, 704416)
    off(_ZN10CGameState12ShowDefeatedEP8CCountry, 465760)
    off(_ZN10CGameState16UpdateAIProgressEv, 465824)
    off(_ZN12CGameManager24MovePlayerCountryToFrontEv, 431888)
    off(_ZN12CGameManager12RealLoadGameEPKc, 432320)
    off(_ZN8CCountryC1Ev, 693280)
    off(_ZN8CCountry4InitEPKcS1_, 693472)
    off(_ZN8CCountry11LoadCountryEPK15SaveCountryInfo, 697440)
    off(_ZN7CCamera6SetPosEffb, 691056)
    off(_ZN5CArea8LoadAreaEPK12SaveAreaInfo, 674448)
    off(_ZN8CCountry7AddAreaEi, 694304)
    off(_ZN12CGameManager10LoadBattleEPKc, 433376)
    off(_ZNK12TiXmlElement20QueryDoubleAttributeEPKcPd, 899840)
    off(_ZN8CCountry12SetCommanderEPKc, 697152)
    off(_ZN14CPlayerManager21FindPlayerByCountryIDEPKc, 612656)
    off(_ZN6CScene14SetAreaCountryEiP8CCountry, 628624)
    off(_ZN5CArea15SetConstructionEii, 668336)
    off(_ZN5CArmyC1Ev, 675152)
    off(_ZN5CArmy4InitEP7ArmyDefP8CCountry, 675392)
    off(_ZN5CArea7AddArmyEP5CArmyb, 668880)
    off(_ZN5CArmy16ResetMaxStrengthEb, 675232)
    off(_ZN12CGameManager10InitBattleEv, 436864)
    off(_ZN6CScene20AllAreasEncirclementEv, 632768)
    off(_ZN14CPlayerManager18SetPlayerOfCountryEv, 613216)
    off(_ZN8CGameRes14RenderArmyInfoEiffiiiii, 438240)
    off(_ZN7ecImage6RenderEff, 946096)
    off(_ZN7ecImage8SetColorEmi, 948880)
    off(_ZN7ecImage8RenderExEfffff, 946512)
    off(_ZN8CGameRes20RenderCommanderMedalEiffi, 438800)
    off(_ZN8CGameRes12RenderArmyHPEffii, 438880)
    off(_ZN8CGameRes15RenderArmyLevelEffi, 439104)
    off(_ZN8CGameRes21RenderArmyMovementNumEffi, 439136)
    off(_ZN8CGameRes18RenderConstructionEiiff, 439168)
    off(_ZN8CGameRes10RenderPortEff, 439264)
    off(_ZN8CGameRes18RenderInstallationEiff, 439280)
    off(_ZN8CGameRes11GetBattleBGEPKc, 439312)
    off(_ZN12ecTextureRes8GetImageEPKc, 952128)
    off(_ZN8CGameRes12GetFlagImageEPKc, 439328)
    off(_ZN8CGameResC2Ev, 439552)
    off(_ZN12ecTextureResC1Ev, 949744)
    off(_ZN12ecTextureResD1Ev, 950464)
    off(_ZN8CGameResC1Ev, 439552)
    off(_ZN8CGameResD2Ev, 441056)
    off(_ZN8CGameResD1Ev, 441056)
    off(_ZN15ecEffectManager9RemoveAllEv, 967520)
    off(_ZN18ecEffectResManager8InstanceEv, 962032)
    off(_ZN18ecEffectResManager19ReleaseAllEffectResEv, 963008)
    off(_ZN18ecEffectResManager17ReleaseTextureResEv, 962064)
    off(_ZN7ecImageD1Ev, 945600)
    off(_ZN12ecTextureRes7ReleaseEv, 950848)
    off(_ZN8CGameRes12GetArmyImageEPKcib, 444160)
    off(_ZN8CGameRes10RenderArmyEPKciiffimbf, 444448)
    off(_ZN8CGameRes12RenderUIArmyEPKcffibiiiii, 444752)
    off(_ZN8CGameRes22RenderAICommanderMedalEiffPKci, 445472)
    off(_ZN8CGameRes18RenderUIAttackArmyEPKcffiiiiiiib, 446144)
    off(_ZN8CGameRes18RenderUIDefendArmyEPKcffiiiiiiib, 446976)
    off(_ZN8CGameRes10RenderFlagEPKcff, 447808)
    off(_ZN12ecTextureRes7LoadResEPKcb, 955520)
    off(_ZN7ecImageC1EP11ecImageAttr, 945936)
    off(_ZN7ecImageC1EP9ecTextureffff, 945840)
    off(_ZN18ecEffectResManager14LoadTextureResEPKc, 962048)
    off(_ZN18ecEffectResManager13LoadEffectResEPKc, 964848)
    off(_ZN13CGameSettingsD2Ev, 462112)
    off(_ZN13CGameSettingsD1Ev, 462112)
    off(_ZN13CGameSettingsC2Ev, 462128)
    off(_ZN13CGameSettingsC1Ev, 462128)
    off(_ZN10CGameStateD2Ev, 462752)
    off(_ZN10CGameStateD1Ev, 462752)
    off(_ZN10CGameStateD0Ev, 462816)
    off(_ZN10CGameState6RenderEv, 462864)
    off(_ZN15ecEffectManager6RenderEv, 968000)
    off(_ZN10CGameState8TouchEndEffi, 463008)
    off(_ZN10GUIBuyCard10GetSelCardEv, 503728)
    off(_ZN8CCountry19CheckCardTargetAreaEP7CardDefi, 699040)
    off(_ZN6GUITax7SetAreaEi, 545440)
    off(_ZN5CArea8IsActiveEv, 671104)
    off(_ZN10GUIElement4HideEv, 795104)
    off(_ZN10GUIElement4ShowEv, 795088)
    off(_ZN6CScene13CheckMoveableEiii, 631184)
    off(_ZN14CPlayerManager22SendPacketToAllPlayersE9PACKET_IDPKvi, 606816)
    off(_ZN10GUISelArmy7SetAreaEi, 542272)
    off(_ZN6CScene15CheckAttackableEiii, 631584)
    off(_ZN12GUIAttackBox9SetAttackEii, 480784)
    off(_ZN10CGameState9TouchMoveEffi, 464128)
    off(_ZN6CScene13ScreenToSceneERfS0_, 627536)
    off(_ZN7CCamera14SetPosAndScaleEfff, 691232)
    off(_ZN10CGameState11ScrollWheelEfff, 464960)
    off(_ZN10CGameState15EnterBackgroundEv, 465184)
    off(_ZN10CGameStateC2Ev, 465248)
    off(_ZN10CGameState8InitGameEv, 465312)
    off(_ZN10GUIManager14LoadTextureResEPKcb, 797200)
    off(_ZN10CGameState11ReleaseGameEv, 465456)
    off(_ZN10GUIManager16UnloadTextureResEPKc, 797216)
    off(_ZN10CGameState6OnExitEv, 465584)
    off(_ZN10CCSoundBox11UnloadMusicEv, 971920)
    off(_ZN14CPlayerManager4StopEv, 604608)
    off(_ZN10GUIElement11MoveToFrontEPS_, 794432)
    off(_ZN11GUIDefeated12ShowDefeatedEP8CCountry, 514368)
    off(_ZN13GUIAIProgress17SetCurCountryNameEPKc, 479264)
    off(_ZN10CGameState7OnEnterEv, 466080)
    off(_ZN10GUIManager9AddButtonEPKcS1_RK7GUIRectP10GUIElementP9ecUniFont, 798448)
    off(_ZN9GUIButton13SetBackgroundEPKc, 792848)
    off(_ZN7GUIGoldC1Ev, 520432)
    off(_ZN7GUIGold4InitERK7GUIRect, 520784)
    off(_ZN10GUIElement8AddChildEPS_b, 793904)
    off(_ZN6GUITaxC1Ev, 544512)
    off(_ZN6GUITax4InitERK7GUIRect, 544928)
    off(_ZN12GUISmallCardC1Ev, 543664)
    off(_ZN12GUISmallCard4InitERK7GUIRect, 543712)
    off(_ZN12GUIAttackBoxC1Ev, 480160)
    off(_ZN12GUIAttackBox4InitERK7GUIRect, 480240)
    off(_ZN10GUIElement6CenterEv, 794624)
    off(_ZN11GUIPauseBoxC1Ev, 529184)
    off(_ZN11GUIPauseBox4InitERK7GUIRect, 529280)
    off(_ZN10GUIBuyCardC1Ev, 500448)
    off(_ZN10GUIBuyCard4InitERK7GUIRect, 500672)
    off(_ZN13GUIAIProgressC1Ev, 478912)
    off(_ZN13GUIAIProgress4InitERK7GUIRect, 478976)
    off(_ZN10GUISelArmyC1Ev, 541840)
    off(_ZN10GUISelArmy4InitERK7GUIRect, 541888)
    off(_ZN8GUIBeginC1Ev, 494624)
    off(_ZN8GUIBegin4InitERK7GUIRect, 495008)
    off(_ZN11GUIDefeatedC1Ev, 513840)
    off(_ZN11GUIDefeated4InitERK7GUIRect, 513968)
    off(_ZN9GUIBattleC1Ev, 486832)
    off(_ZN9GUIBattle4InitERK7GUIRect, 487184)
    off(_ZN11GUIDialogueC1Ev, 516544)
    off(_ZN11GUIDialogue4InitERK7GUIRect, 516672)
    off(_ZN16GUIMotionManager9AddMotionEP10GUIElementffft, 800112)
    off(_ZN10CCSoundBox9LoadMusicEPKcS1_, 971904)
    off(_ZN10CCSoundBox9PlayMusicEb, 971936)
    off(_ZN12GUITutorailsC1Ev, 547872)
    off(_ZN12GUITutorails4InitERK7GUIRect, 549760)
    off(_ZN13GUIActionInfoC1Ev, 478256)
    off(_ZN13GUIActionInfo4InitERK7GUIRect, 478336)
    off(_ZN10CGameState15EnableIdleTimerEf, 469600)
    off(_ZN10CGameState12StartBattaleEiiib, 469616)
    off(_ZN9GUIBattle11BattleStartEiii, 488752)
    off(_ZN8GUIBegin9ResetDataEv, 496048)
    off(_ZN10CGameState10SelectAreaEi, 470064)
    off(_ZN6CScene10SelectAreaEi, 632688)
    off(_ZN10CGameState12UnselectAreaEv, 470208)
    off(_ZN11GUIDialogue7ShowDlgEPKcS1_b, 517024)
    off(_ZN10CGameState11ShowWarningEi, 470288)
    off(_ZN10GUIWarningC1Ev, 555056)
    off(_ZN10GUIWarning4InitERK7GUIRecti, 555168)
    off(_ZN10CGameState6UpdateEf, 470496)
    off(_ZN6CScene9IsBombingEv, 633040)
    off(_ZN10GUIBuyCard13CanBuySelCardEv, 503776)
    off(_ZN10GUIBuyCard13ReleaseTargetEv, 505088)
    off(_ZN10GUIBuyCard15ResetCardTargetEv, 504976)
    off(_ZN14CPlayerManager13GetNumActionsEv, 616704)
    off(_ZN14CPlayerManager22IsDisconnectedFromHostEv, 606400)
    off(_ZN13GUIActionInfo7SetInfoEPKc, 478432)
    off(_ZN10CGameState15ResetTouchStateEv, 472192)
    off(_ZN10CGameState11BackPressedEv, 472224)
    off(_ZN10GUIManager7FadeOutEiP10GUIElement, 797280)
    off(_ZN10CGameState10TouchBeginEffi, 472416)
    off(_ZN10CGameState7OnEventERK5Event, 472720)
    off(_ZN10GUIVictoryC1Ev, 553568)
    off(_ZN10GUIVictory4InitERK7GUIRectb, 553632)
    off(_ZN10GUIVictory4PlayEv, 554512)
    off(_ZN16GUIMotionManager12ActiveMotionEjh, 800640)
    off(_ZN14CPlayerManager18SendPacketToServerE9PACKET_IDPKvi, 606752)
    off(_ZN10GUIManager13SafeFreeChildEP10GUIElement, 797936)
    off(_ZN6GUIEndC1Ev, 518048)
    off(_ZN6GUIEnd4InitERK7GUIRect, 518176)
    off(_ZN10GUIBuyCard14ResetCardStateEv, 503904)
    off(_ZN10GUIOptionsC1Ev, 525600)
    off(_ZN10GUIOptions4InitERK7GUIRect, 525728)
    off(_ZN7GUISaveC1Ev, 537776)
    off(_ZN7GUISave4InitERK7GUIRectib, 537920)
    off(_ZN12GUISmallCard7SetCardEP7CardDef, 543760)
    off(_ZN14GUIBattleIntroC1Ev, 491040)
    off(_ZN14GUIBattleIntro4InitERK7GUIRectii, 492176)
    off(_ZN11GUIDefeated12HideDefeatedEv, 515280)
    off(_ZN9GUIResultC1Ev, 531280)
    off(_ZN9GUIResult4InitERK7GUIRecti, 531520)
    off(_ZN14CPlayerManager16PlayerLoadFinishEP7CPlayer, 613744)
    off(_ZN7GUIBankC1Ev, 481632)
    off(_ZN7GUIBank4InitERK7GUIRect, 481728)
    off(_ZN6GUIIapC1Ev, 522496)
    off(_ZN6GUIIap4InitERK7GUIRect, 522624)
    off(_ZN13ecStringTableC1Ev, 972128)
    off(_ZN13ecStringTableD1Ev, 973312)
    off(_ZN13GUIActionInfo8OnUpdateEf, 477920)
    off(_ZN13GUIActionInfoD2Ev, 477936)
    off(_ZN11ecLabelTextD1Ev, 970816)
    off(_ZN10GUIElementD2Ev, 794368)
    off(_ZN13GUIActionInfoD1Ev, 477936)
    off(_ZN13GUIActionInfoD0Ev, 478032)
    off(_ZN13GUIActionInfo8OnRenderEv, 478064)
    off(_ZN10GUIElement10GetAbsRectER7GUIRect, 794752)
    off(_ZN11ecLabelText8DrawTextEff, 971440)
    off(_ZN13GUIActionInfoC2Ev, 478256)
    off(_ZN10GUIElementC2Ev, 793776)
    off(_ZN11ecLabelTextC1Ev, 970784)
    off(_ZN11ecLabelText4InitEPKciiii, 971008)
    off(_ZN11ecLabelText7SetTextEPKc, 971104)
    off(_ZN10GUIElement7OnEventERK5Event, 793744)
    off(_ZN13GUIAIProgressD2Ev, 478448)
    off(_ZN13GUIAIProgressD1Ev, 478448)
    off(_ZN13GUIAIProgressD0Ev, 478624)
    off(_ZN13GUIAIProgress8OnRenderEv, 478656)
    off(_ZN13GUIAIProgressC2Ev, 478912)
    off(_ZN7ecImage4InitEP11ecImageAttr, 946016)
    off(_ZN10GUIElement8OnUpdateEf, 793728)
    off(_ZN12GUIAttackBoxD2Ev, 479376)
    off(_ZN12GUIAttackBoxD1Ev, 479376)
    off(_ZN12GUIAttackBoxD0Ev, 479552)
    off(_ZN12GUIAttackBox8OnRenderEv, 479584)
    off(_ZN5CArmy14GetMaxStrengthEv, 675488)
    off(_ZN12GUIAttackBoxC2Ev, 480160)
    off(_ZN11GUIButtonExC1Ev, 496736)
    off(_ZN9GUIButton4InitEPKcS1_RK7GUIRectP9ecUniFont, 792336)
    off(_ZN11GUIButtonEx12SetImageTextEPKcS1_, 496816)
    off(_ZN12GUIAttackBox7OnEventERK5Event, 480992)
    off(_ZN7GUIBank8OnUpdateEf, 481200)
    off(_ZN7GUIBankD2Ev, 481216)
    off(_ZN7GUIBankD1Ev, 481216)
    off(_ZN7GUIBankD0Ev, 481344)
    off(_ZN7GUIBank8OnRenderEv, 481376)
    off(_ZN7ecImage6RenderEffff, 946304)
    off(_ZN7GUIBankC2Ev, 481632)
    off(_ZN9GUIButtonC1Ev, 792208)
    off(_ZN8GUIMedalC1Ev, 524608)
    off(_ZN8GUIMedal4InitERK7GUIRect, 524816)
    off(_ZN10GUIManager8AddImageEPKcRK7GUIRectP10GUIElement, 798288)
    off(_ZN7GUIBank7OnEventERK5Event, 483712)
    off(_ZN9GUIBattleD2Ev, 484176)
    off(_ZN12CBattleSceneD1Ev, 686368)
    off(_ZN9GUIBattleD1Ev, 484176)
    off(_ZN9GUIBattleD0Ev, 484528)
    off(_ZN9GUIBattle8OnRenderEv, 484560)
    off(_ZN12CBattleScene6RenderEv, 678912)
    off(_ZN9GUIBattleC2Ev, 486832)
    off(_ZN12CBattleSceneC1Ev, 678560)
    off(_ZN12CBattleScene4InitEiPS_, 678800)
    off(_ZN9GUIBattle11ResetBattleEv, 487856)
    off(_ZN12CBattleScene13SetBattleAreaEi, 682096)
    off(_ZN9GUIBattle12BattleFinishEv, 489072)
    off(_ZN9GUIBattle13UpateFightingEf, 489104)
    off(_ZN12CBattleScene6AttackEv, 684112)
    off(_ZN12CBattleScene11IsAttackingEv, 684160)
    off(_ZN12CBattleScene12DestroyUnitsEi, 684256)
    off(_ZN9GUIBattle8OnUpdateEf, 489568)
    off(_ZN12CBattleScene6UpdateEf, 684928)
    off(_ZN12CBattleScene12ClearCratersEv, 684608)
    off(_ZN12CBattleScene12ClearEffectsEv, 686208)
    off(_ZN9GUIBattle7OnEventERK5Event, 490016)
    off(_ZN14GUIBattleIntroD2Ev, 490048)
    off(_ZN14GUIBattleIntroD1Ev, 490048)
    off(_ZN14GUIBattleIntroD0Ev, 490288)
    off(_ZN14GUIBattleIntro8OnRenderEv, 490320)
    off(_ZN14GUIBattleIntroC2Ev, 491040)
    off(_ZN14GUIBattleIntro9SetBattleEii, 491408)
    off(_ZN14GUIBattleIntro7OnEventERK5Event, 493488)
    off(_ZN8GUIBeginD2Ev, 493728)
    off(_ZN8GUIBeginD1Ev, 493728)
    off(_ZN8GUIBeginD0Ev, 494080)
    off(_ZN8GUIBegin8OnRenderEv, 494112)
    off(_ZN8GUIBeginC2Ev, 494624)
    off(_ZN7GUITechC1Ev, 546512)
    off(_ZN7GUITech4InitERK7GUIRect, 546608)
    off(_ZN8CCountry8GetTaxesEv, 700448)
    off(_ZN8CCountry12GetIndustrysEv, 700640)
    off(_ZN8GUIBegin7OnEventERK5Event, 496400)
    off(_ZN11GUIButtonExD2Ev, 496592)
    off(_ZN9GUIButtonD2Ev, 790832)
    off(_ZN11GUIButtonExD1Ev, 496592)
    off(_ZN11GUIButtonExD0Ev, 496704)
    off(_ZN11GUIButtonExC2Ev, 496736)
    off(_ZN9GUIButtonC2Ev, 792208)
    off(_ZN11GUIButtonEx8OnRenderEv, 497072)
    off(_ZN9GUIButton8OnRenderEv, 791152)
    off(_ZN9GUIButton7OnEventERK5Event, 793328)
    off(_ZN10GUICardTabD2Ev, 497488)
    off(_ZN10GUICardTabD1Ev, 497488)
    off(_ZN10GUICardTabD0Ev, 497520)
    off(_ZN10GUIBuyCardD2Ev, 497552)
    off(_ZN10GUIBuyCardD1Ev, 497552)
    off(_ZN10GUIBuyCardD0Ev, 497872)
    off(_ZN10GUIBuyCard8OnRenderEv, 497904)
    off(_ZN10GUICardTabC2Ev, 498320)
    off(_ZN10GUICardTabC1Ev, 498320)
    off(_ZN10GUICardTab19GetCardTabButtonIdxEPK10GUIElement, 498352)
    off(_ZN10GUICardTab9SelectTabEi, 498432)
    off(_ZN10GUIElement6GetPosERfS0_, 794544)
    off(_ZN10GUIElement6SetPosEff, 794576)
    off(_ZN10GUICardTab4InitERK7GUIRect, 498736)
    off(_ZN14GUIRadioButtonC1Ev, 802176)
    off(_ZN10GUIManager8AddImageEPKcRK13ecTextureRectRK7GUIRectP10GUIElementb, 798000)
    off(_ZN10GUIBuyCardC2Ev, 500448)
    off(_ZN11GUICardListC1Ev, 510192)
    off(_ZN11GUICardList4InitERK7GUIRecti, 510752)
    off(_ZN7ecImageC1EP9ecTextureRK13ecTextureRect, 945856)
    off(_ZN10GUIBuyCard15SetSelCardIntroEv, 503616)
    off(_ZN10CObjectDef10GetCardDefE7CARD_ID, 568928)
    off(_ZN8CCountry10CanBuyCardEP7CardDef, 698544)
    off(_ZN7GUICard13SetPriceColorEj, 510160)
    off(_ZN8CCountry16IsEnoughIndustryEP7CardDef, 696224)
    off(_ZN7GUICard16SetIndustryColorEj, 510176)
    off(_ZN8CCountry12GetCardPriceEP7CardDef, 698096)
    off(_ZN8CCountry15GetCardIndustryEP7CardDef, 696192)
    off(_ZN11GUICardList7GetCardEi, 510336)
    off(_ZN8CCountry13IsEnoughMoneyEP7CardDef, 698144)
    off(_ZN8CCountry13GetCardRoundsE7CARD_ID, 696176)
    off(_ZN10GUIElement9SetEnableEb, 795120)
    off(_ZN7GUICard8SetPriceEi, 509968)
    off(_ZN7GUICard11SetIndustryEi, 510064)
    off(_ZN8CCountry15CanUseCommanderEv, 698512)
    off(_ZN10GUIBuyCard7SelCardEii, 504720)
    off(_ZN6CScene12ClearTargetsEv, 628672)
    off(_ZN8CCountry14SetCardTargetsEP7CardDef, 700064)
    off(_ZN6CScene11ResetTargetEv, 632720)
    off(_ZN10GUICardTab7OnEventERK5Event, 505120)
    off(_ZN10GUIBuyCard7OnEventERK5Event, 505264)
    off(_ZN10CObjectDef17GetCardTargetTypeEP7CardDef, 568960)
    off(_ZN10GUIElement8OnRenderEv, 793712)
    off(_ZN7GUICardD2Ev, 505920)
    off(_ZN7GUICardD1Ev, 505920)
    off(_ZN7GUICardD0Ev, 506256)
    off(_ZN7GUICard8OnRenderEv, 506288)
    off(_ZN11GUICardListD2Ev, 507536)
    off(_ZN11GUICardListD1Ev, 507536)
    off(_ZN11GUICardListD0Ev, 507600)
    off(_ZN11GUICardList8OnUpdateEf, 507648)
    off(_ZN7GUICardC2Ev, 508240)
    off(_ZN7GUICardC1Ev, 508240)
    off(_ZN7GUICard4InitEP7CardDefRK7GUIRect, 508592)
    off(_ZN11GUICardListC2Ev, 510192)
    off(_ZN11GUICardList11ResetSelectEv, 510304)
    off(_ZN11GUICardList10GelSelItemEff, 510384)
    off(_ZN10GUIElement11CheckInRectEff, 794832)
    off(_ZN7GUICard7OnEventERK5Event, 512208)
    off(_ZN11GUICardList9SetSelectEi, 512576)
    off(_ZN11GUICardList8ReSelectEv, 512688)
    off(_ZN11GUICardList7OnEventERK5Event, 512736)
    off(_ZN11GUIDefeated8OnRenderEv, 513488)
    off(_ZN11GUIDefeatedC2Ev, 513840)
    off(_ZN10CObjectDef15GetGeneralPhotoEPKc, 569760)
    off(_ZN11GUIDefeatedD2Ev, 515488)
    off(_ZN11GUIDefeatedD1Ev, 515488)
    off(_ZN11GUIDefeatedD0Ev, 515552)
    off(_ZN11GUIDefeated8OnUpdateEf, 515584)
    off(_ZN11GUIDefeated7OnEventERK5Event, 515744)
    off(_ZN11GUIDialogue8OnUpdateEf, 515872)
    off(_ZN11GUIDialogueD2Ev, 515888)
    off(_ZN11GUIDialogueD1Ev, 515888)
    off(_ZN11GUIDialogueD0Ev, 516096)
    off(_ZN11GUIDialogue8OnRenderEv, 516128)
    off(_ZN11GUIDialogueC2Ev, 516544)
    off(_ZN11GUIDialogue7HideDlgEv, 517328)
    off(_ZN11GUIDialogue7OnEventERK5Event, 517344)
    off(_ZN6GUIEndD2Ev, 517472)
    off(_ZN6GUIEndD1Ev, 517472)
    off(_ZN6GUIEndD0Ev, 517664)
    off(_ZN6GUIEnd8OnRenderEv, 517696)
    off(_ZN6GUIEndC2Ev, 518048)
    off(_ZN6GUIEnd7OnEventERK5Event, 520016)
    off(_ZN7GUIGoldD2Ev, 520144)
    off(_ZN7GUIGoldD1Ev, 520144)
    off(_ZN7GUIGoldD0Ev, 520240)
    off(_ZN7GUIGold8OnRenderEv, 520272)
    off(_ZN7GUIGoldC2Ev, 520432)
    off(_ZN7GUIGold8SetMoneyEi, 520560)
    off(_ZN7GUIGold11SetIndustryEi, 520672)
    off(_ZN7GUIGold8OnUpdateEf, 521008)
    off(_ZN15GUIProductPrice8OnRenderEv, 521104)
    off(_ZN6GUIIapD2Ev, 521296)
    off(_ZN6GUIIapD1Ev, 521296)
    off(_ZN6GUIIapD0Ev, 521520)
    off(_ZN6GUIIap7OnEventERK5Event, 521552)
    off(_ZN15GUIProductPriceD2Ev, 521872)
    off(_ZN15GUIProductPriceD1Ev, 521872)
    off(_ZN15GUIProductPriceD0Ev, 522032)
    off(_ZN6GUIIap8OnRenderEv, 522064)
    off(_ZN15GUIProductPriceC2Ev, 522176)
    off(_ZN15GUIProductPriceC1Ev, 522176)
    off(_ZN15GUIProductPrice4InitERK7GUIRect, 522272)
    off(_ZN11ecLabelText8SetColorEj, 971344)
    off(_ZN15GUIProductPrice14SetLocalePirceEPKc, 522416)
    off(_ZN6GUIIapC2Ev, 522496)
    off(_ZN9GUIButton7SetTextEPKc, 793136)
    off(_ZN9GUIButton12SetTextColorEj, 793232)
    off(_ZN6GUIIap14SetLocalePirceEiPKc, 524256)
    off(_ZN6GUIIap14OnListCompleteEPv, 524304)
    off(_ZN6GUIIap15SetProductPriceEv, 524320)
    off(_ZN8GUIMedalD2Ev, 524336)
    off(_ZN8GUIMedalD1Ev, 524336)
    off(_ZN8GUIMedalD0Ev, 524432)
    off(_ZN8GUIMedal8OnRenderEv, 524464)
    off(_ZN8GUIMedalC2Ev, 524608)
    off(_ZN8GUIMedal8SetMedalEi, 524704)
    off(_ZN8GUIMedal8OnUpdateEf, 525136)
    off(_ZN8GUIMedal7OnEventERK5Event, 525152)
    off(_ZN10GUIOptionsD2Ev, 525296)
    off(_ZN10GUIOptionsD1Ev, 525296)
    off(_ZN10GUIOptionsD0Ev, 525504)
    off(_ZN10GUIOptions8OnRenderEv, 525536)
    off(_ZN10GUIOptionsC2Ev, 525600)
    off(_ZN10GUIManager12AddScrollBarERK7GUIRectP10GUIElementPKcS6_iiiii, 798608)
    off(_ZN11GUILevelSelC1Ev, 724064)
    off(_ZN11GUILevelSel4InitERK7GUIRecti, 724112)
    off(_ZN12GUIScrollBar12SetScrollPosEi, 802576)
    off(_ZN10GUIOptions7OnEventERK5Event, 528560)
    off(_ZN12GUIScrollBar12GetScrollPosEv, 802512)
    off(_ZN11GUIPauseBoxD2Ev, 528928)
    off(_ZN11GUIPauseBoxD1Ev, 528928)
    off(_ZN11GUIPauseBoxD0Ev, 529040)
    off(_ZN11GUIPauseBox8OnRenderEv, 529072)
    off(_ZN11GUIPauseBoxC2Ev, 529184)
    off(_ZN11GUIPauseBox7OnEventERK5Event, 529904)
    off(_ZN9GUIResult8OnUpdateEf, 530016)
    off(_ZN9GUIResultD2Ev, 530032)
    off(_ZN9GUIResultD1Ev, 530032)
    off(_ZN9GUIResultD0Ev, 530480)
    off(_ZN9GUIResult8OnRenderEv, 530528)
    off(_ZN9GUIResultC2Ev, 531280)
    off(_ZN13GUIAdornMedalC1Ev, 709936)
    off(_ZN13GUIAdornMedal4InitER7GUIRect, 710384)
    off(_ZN9GUIResult7OnEventERK5Event, 534400)
    off(_ZN11GUISaveItemD2Ev, 534544)
    off(_ZN14GUIRadioButtonD2Ev, 801504)
    off(_ZN11GUISaveItemD1Ev, 534544)
    off(_ZN11GUISaveItemD0Ev, 534672)
    off(_ZN7GUISave8OnRenderEv, 534704)
    off(_ZN11GUISaveItem8OnRenderEv, 534736)
    off(_ZN7GUISaveD2Ev, 536304)
    off(_ZN12ecTextureRes9UnloadResEPKc, 951600)
    off(_ZN7GUISaveD1Ev, 536304)
    off(_ZN7GUISaveD0Ev, 536528)
    off(_ZN11GUISaveItem8OnUpdateEf, 536560)
    off(_ZN11GUISaveItemC2Ev, 536672)
    off(_ZN14GUIRadioButtonC2Ev, 802176)
    off(_ZN11GUISaveItemC1Ev, 536672)
    off(_ZN11GUISaveItem4InitERK7GUIRectPKc, 536832)
    off(_ZN11GUISaveItem7SetInfoEPKciiiiiiiib, 537168)
    off(_ZN7GUISaveC2Ev, 537776)
    off(_ZN7GUISave7SelItemEi, 540256)
    off(_ZN7GUISave7OnEventERK5Event, 540672)
    off(_ZN11GUIArmyItemD2Ev, 541248)
    off(_ZN11GUIArmyItemD1Ev, 541248)
    off(_ZN11GUIArmyItemD0Ev, 541280)
    off(_ZN11GUIArmyItem8OnRenderEv, 541312)
    off(_ZN10GUISelArmyD2Ev, 541584)
    off(_ZN10GUISelArmyD1Ev, 541584)
    off(_ZN10GUISelArmyD0Ev, 541664)
    off(_ZN10GUISelArmy8OnRenderEv, 541696)
    off(_ZN11GUIArmyItemC2Ev, 541792)
    off(_ZN11GUIArmyItemC1Ev, 541792)
    off(_ZN10GUISelArmyC2Ev, 541840)
    off(_ZN7ecImage8SetAlphaEfi, 948928)
    off(_ZN10GUISelArmy15MoveArmyToFrontEi, 542400)
    off(_ZN5CArea15MoveArmyToFrontEib, 669120)
    off(_ZN10GUISelArmy10TargetArmyEi, 542752)
    off(_ZN10GUISelArmy7OnEventERK5Event, 542848)
    off(_ZN12GUISmallCardD2Ev, 543056)
    off(_ZN12GUISmallCardD1Ev, 543056)
    off(_ZN12GUISmallCardD0Ev, 543136)
    off(_ZN12GUISmallCard8OnRenderEv, 543168)
    off(_ZN12GUISmallCardC2Ev, 543664)
    off(_ZN6GUITaxD2Ev, 543808)
    off(_ZN6GUITaxD1Ev, 543808)
    off(_ZN6GUITaxD0Ev, 544048)
    off(_ZN6GUITax8OnRenderEv, 544080)
    off(_ZN6GUITaxC2Ev, 544512)
    off(_ZN6GUITax8SetMoneyEi, 544704)
    off(_ZN6GUITax11SetIndustryEi, 544816)
    off(_ZN5CArea10GetRealTaxEv, 668656)
    off(_ZN5CArea11GetIndustryEv, 668720)
    off(_ZN5CArea11HasArmyCardEi, 670608)
    off(_ZN7GUITechD2Ev, 546096)
    off(_ZN7GUITechD1Ev, 546096)
    off(_ZN7GUITechD0Ev, 546240)
    off(_ZN7GUITech8OnRenderEv, 546272)
    off(_ZN7GUITech8OnUpdateEf, 546448)
    off(_ZN7GUITechC2Ev, 546512)
    off(_ZN12GUITutorails8OnRenderEv, 547008)
    off(_ZN12GUITutorailsC2Ev, 547872)
    off(_ZN12GUITutorails10LoadScriptEv, 548080)
    off(_ZN12GUITutorails13ReleaseScriptEv, 550368)
    off(_ZN12GUITutorailsD2Ev, 550592)
    off(_ZN12GUITutorailsD1Ev, 550592)
    off(_ZN12GUITutorailsD0Ev, 550976)
    off(_ZN12GUITutorails7ShowDlgEi, 551008)
    off(_ZN12GUITutorails7ShowDlgEPKc, 551152)
    off(_ZN12GUITutorails7HideDlgEv, 551232)
    off(_ZN12GUITutorails6ExeCmdEi, 551248)
    off(_ZN6CScene22MoveCameraCenterToAreaEi, 628144)
    off(_ZN6CScene16MoveCameraToAreaEi, 627984)
    off(_ZN12GUITutorails8OnUpdateEf, 552288)
    off(_ZN6CScene8IsMovingEv, 627824)
    off(_ZN12GUITutorails7OnEventERK5Event, 552736)
    off(_ZN10GUIVictoryD2Ev, 552864)
    off(_ZN10GUIVictoryD1Ev, 552864)
    off(_ZN10GUIVictoryD0Ev, 553040)
    off(_ZN10GUIVictory8OnRenderEv, 553072)
    off(_ZN10GUIVictory8OnUpdateEf, 553264)
    off(_ZN10GUIVictoryC2Ev, 553568)
    off(_ZN10GUIVictory7OnEventERK5Event, 554656)
    off(_ZN10GUIWarning8OnUpdateEf, 554704)
    off(_ZN10GUIWarningD2Ev, 554720)
    off(_ZN10GUIWarningD1Ev, 554720)
    off(_ZN10GUIWarningD0Ev, 554848)
    off(_ZN10GUIWarning8OnRenderEv, 554880)
    off(_ZN10GUIWarningC2Ev, 555056)
    off(_ZN10GUIWarning7OnEventERK5Event, 555952)
    off(_ZN10CLoadState10TouchBeginEffi, 556176)
    off(_ZN10CLoadState9TouchMoveEffi, 556192)
    off(_ZN10CLoadState8TouchEndEffi, 556208)
    off(_ZN10CLoadState11BackPressedEv, 556224)
    off(_ZN10CLoadStateD2Ev, 556240)
    off(_ZN10CLoadStateD1Ev, 556240)
    off(_ZN10CLoadStateD0Ev, 556304)
    off(_ZN10CLoadState7OnEnterEv, 556352)
    off(_ZN10CLoadState6OnExitEv, 557184)
    off(_ZN10CLoadState6RenderEv, 557344)
    off(_ZN10CLoadState6UpdateEf, 557584)
    off(_ZN10CLoadState7OnEventERK5Event, 557664)
    off(_ZN10CLoadStateC2Ev, 557808)
    off(_ZN10CLogoStateD2Ev, 557904)
    off(_ZN10CLogoStateD1Ev, 557904)
    off(_ZN10CLogoState15EnterForegroundEv, 557936)
    off(_ZN10CLogoStateD0Ev, 557952)
    off(_ZN10CLogoState7OnEnterEv, 558000)
    off(_ZN10CLogoState6OnExitEv, 559072)
    off(_ZN10CLogoState6RenderEv, 559104)
    off(_ZN10CLogoState7OnEventERK5Event, 559216)
    off(_ZN10CLogoState6UpdateEf, 559296)
    off(_ZN14CPlayerManager4InitEv, 599440)
    off(_ZN10CLogoStateC2Ev, 559472)
    off(_ZN11CMatchStateD2Ev, 559520)
    off(_ZN11CMatchStateD1Ev, 559520)
    off(_ZN11CMatchState6UpdateEf, 559552)
    off(_ZN11CMatchState6RenderEv, 559568)
    off(_ZN11CMatchState10TouchBeginEffi, 559584)
    off(_ZN11CMatchState9TouchMoveEffi, 559600)
    off(_ZN11CMatchState8TouchEndEffi, 559616)
    off(_ZN11CMatchStateD0Ev, 559632)
    off(_ZN11CMatchState7OnEnterEv, 559680)
    off(_ZN13GUIMatchSetupC1Ev, 743184)
    off(_ZN13GUIMatchSetup4InitERK7GUIRect, 745152)
    off(_ZN11CMatchState6OnExitEv, 559968)
    off(_ZN11CMatchStateC2Ev, 560032)
    off(_ZN11CMatchState18StartMultiplayGameEi, 560080)
    off(_ZN11CMatchState7OnEventERK5Event, 560144)
    off(_ZN14CPlayerManager17SendStartLoadGameEv, 613360)
    off(_ZN11CMatchState11ShowWarningEi, 560496)
    off(_ZN10CMenuStateD2Ev, 560704)
    off(_ZN10CMenuStateD1Ev, 560704)
    off(_ZN10CMenuState6UpdateEf, 560736)
    off(_ZN10CMenuState6RenderEv, 560752)
    off(_ZN10CMenuState10TouchBeginEffi, 560768)
    off(_ZN10CMenuState9TouchMoveEffi, 560784)
    off(_ZN10CMenuState8TouchEndEffi, 560800)
    off(_ZN10CMenuStateD0Ev, 560816)
    off(_ZN10CMenuState7OnEnterEv, 560864)
    off(_ZN11GUIMainMenuC1Ev, 727216)
    off(_ZN11GUIMainMenu4InitERK7GUIRect, 727520)
    off(_ZN12GUISelBattleC1Ev, 761808)
    off(_ZN12GUISelBattle4InitERK7GUIRectii, 762240)
    off(_ZN10CMenuState6OnExitEv, 561488)
    off(_ZN10CMenuStateC2Ev, 561552)
    off(_ZN10CMenuState13PeerConnectedEv, 561600)
    off(_ZN10CMenuState18StartMultiplayGameEi, 561664)
    off(_ZN10CMenuState7OnEventERK5Event, 561728)
    off(_ZN11GUIMainMenu13RefreshNewTipEv, 727472)
    off(_ZN10GUILoadingC1Ev, 724800)
    off(_ZN10GUILoading4InitERK7GUIRect, 724848)
    off(_ZN11GUIMainMenu6ShowADEv, 738016)
    off(_ZN14CPlayerManager12SetupSessionEb, 603344)
    off(_ZN16GUILockedWarningC1Ev, 725632)
    off(_ZN16GUILockedWarning4InitERK7GUIRect, 725744)
    off(_ZN12GUICommanderC1Ev, 710992)
    off(_ZN12GUICommander4InitERK7GUIRect, 711872)
    off(_ZN10GUIServiceC1Ev, 775552)
    off(_ZN10GUIService4InitERK7GUIRect, 775728)
    off(_ZN10GUIElement9FreeChildEPS_, 794224)
    off(_ZN11GUIHostList17ResetConnectStateEv, 720096)
    off(_ZN13GUISelCountryC1Ev, 770864)
    off(_ZN13GUISelCountry4InitERK7GUIRecti, 772480)
    off(_ZN14CPlayerManager9InitCorpsEi, 607072)
    off(_ZN14CPlayerManager14DestroySessionEv, 603920)
    off(_ZN11GUIHostListC1Ev, 718960)
    off(_ZN11GUIHostList4InitERK7GUIRect, 720992)
    off(_ZN10GUINewGameC1Ev, 747728)
    off(_ZN10GUINewGame4InitERK7GUIRect, 750704)
    off(_ZN14CPlayerManager10StartMatchEv, 602912)
    off(_ZN14CPlayerManager9StopMatchEv, 604576)
    off(_ZN10CMenuState11ShowWarningEi, 566976)
    off(_ZN14GUIExitWarningC1Ev, 716128)
    off(_ZN14GUIExitWarning4InitERK7GUIRect, 716240)
    off(_ZN10CObjectDefC2Ev, 567456)
    off(_ZN10CObjectDefC1Ev, 567456)
    off(_ZN10CObjectDef11LoadCardDefEv, 567968)
    off(_ZN10CObjectDef16GetUnitPositionsEPKc, 568992)
    off(_ZN10CObjectDef15GetCommanderDefEPKc, 569376)
    off(_ZN10CObjectDef14GetConquestDefEPKc, 570528)
    off(_ZN10CObjectDef14ReleaseArmyDefEv, 571136)
    off(_ZN10CObjectDef18ReleaseUnitMotionsEv, 571744)
    off(_ZN10CObjectDef20ReleaseUnitPositionsEv, 572704)
    off(_ZN10CObjectDef19ReleaseCommanderDefEv, 573248)
    off(_ZN10CObjectDef20ReleaseGeneralPhotosEv, 573984)
    off(_ZN10CObjectDef17ReleaseBattleListEv, 574624)
    off(_ZN10CObjectDefD2Ev, 575680)
    off(_ZN10CObjectDefD1Ev, 575680)
    off(_ZN10CObjectDef19ReleaseConquestListEv, 577216)
    off(_ZN10CObjectDef7ReleaseEv, 577808)
    off(_ZN10CObjectDef14GetUnitMotionsEPKcS1_, 578768)
    off(_ZN10CObjectDef11LoadArmyDefEv, 580352)
    off(_ZN10CObjectDef15LoadUnitMotionsEv, 583360)
    off(_ZN10CObjectDef16LoadUnitPositonsEv, 586496)
    off(_ZN10CObjectDef16LoadCommanderDefEv, 588896)
    off(_ZN10CObjectDef17LoadGeneralPhotosEv, 591264)
    off(_ZN10CObjectDef14LoadBattleListEv, 593536)
    off(_ZN10CObjectDef16LoadConquestListEv, 597216)
    off(_ZN14CPlayerManager14WillDisconnectEv, 599072)
    off(_ZN14CPlayerManager34onLocalPlayerAuthenticationChangedEv, 599088)
    off(_ZN14CPlayerManager20onFriendListReceivedEv, 599120)
    off(_ZN14CPlayerManager14onMatchRequestEv, 599152)
    off(_ZN14CPlayerManager17onPlayerConnectedEPKc, 599184)
    off(_ZN14CPlayerManager17InvitationDidFailEPKc, 599232)
    off(_ZN11GUIHostList13ConnectFailedEv, 720112)
    off(_ZN14CPlayerManager16SessionNoNetworkEv, 599344)
    off(_Z9ecGetUUIDRSs, 886544)
    off(_Z13ecGetUUIDHashv, 886560)
    off(_ZN9ecGameKitC1Ev, 886128)
    off(_ZN9ecGameKit4InitEP17ecGameKitDelegateb, 886160)
    off(_ZN14CPlayerManager15AnalyzePeerNameERKSsRSsRiS3_, 599616)
    off(_ZN14CPlayerManager7ConnectEPKci, 600256)
    off(_ZN18ecSessionInterface7ConnectEPKc, 886400)
    off(_ZN14CPlayerManager9ReconnectEv, 600336)
    off(_ZN18ecSessionInterface15GetPeerNameListERSt4listISsSaISsEES3_, 886384)
    off(_ZN14CPlayerManager13CancelConnectEv, 601824)
    off(_ZN18ecSessionInterface13CancelConnectEv, 886416)
    off(_ZN14CPlayerManager19onPeerListDidChangeEv, 601856)
    off(_ZN11GUIHostList15RefreshHostListEv, 720128)
    off(_ZN9ecGameKit25ShowMatchmakerWithRequestEiii, 886224)
    off(_ZN14CPlayerManager9AddPlayerEbPKc, 602944)
    off(_ZN7CPlayerC1Ev, 778224)
    off(_ZN7CPlayer4InitEbPKc, 778288)
    off(_ZN18ecSessionInterfaceC1Ev, 886304)
    off(_ZN18ecSessionInterface4InitEP17ecSessionDelegate, 886336)
    off(_ZN18ecSessionInterface12SetupSessionEb, 886368)
    off(_ZN18ecSessionInterface13GetDeviceNameERSs, 886528)
    off(_ZN14CPlayerManager18ClearRemotePlayersEv, 603712)
    off(_ZN7CPlayerD1Ev, 779008)
    off(_ZN14CPlayerManager12ClearPlayersEv, 603856)
    off(_ZN18ecSessionInterfaceD1Ev, 886320)
    off(_ZN9ecGameKitD1Ev, 886144)
    off(_ZN14CPlayerManagerD2Ev, 604192)
    off(_ZN14CPlayerManagerD1Ev, 604192)
    off(_ZN9ecGameKit22DisconnectCurrentMatchEv, 886240)
    off(_ZN14CPlayerManager16onAcceptedInviteEv, 604640)
    off(_ZN14CPlayerManager10FindPlayerEPKc, 604720)
    off(_ZN14CPlayerManager20onPlayerInfoReceivedERSt4listIP12ecPlayerInfoSaIS2_EE, 604864)
    off(_ZN14CPlayerManager12onMatchFoundEv, 605264)
    off(_ZN9ecGameKit18GetMatchPlayerListERSt4listISsSaISsEE, 886256)
    off(_ZN14CPlayerManager16FindPlayerByUUIDEi, 605664)
    off(_ZN14CPlayerManager17DidRecvInvitationEPKc, 605728)
    off(_ZN18ecSessionInterface11GetPeerNameEPKcRSs, 886512)
    off(_ZN18ecSessionInterface17DeclineInvitationEPKc, 886464)
    off(_ZN18ecSessionInterface16AcceptInvitationEPKc, 886448)
    off(_ZN14CPlayerManager21GetDisconnectedPlayerEv, 606320)
    off(_ZN14CPlayerManager18SendPacketToPlayerE12PacketHeaderPKviPKc, 606448)
    off(_ZN18ecSessionInterface10SendPacketEPKviPKc, 886480)
    off(_ZN9ecGameKit10SendPacketEPKviPKc, 886192)
    off(_ZN14CPlayerManager18SendPacketToPlayerE9PACKET_IDPKviP7CPlayer, 606608)
    off(_ZN14CPlayerManager28SendPacketToAllPlayersExceptE9PACKET_IDPKviP7CPlayer, 606624)
    off(_ZN7CPlayer10PushPacketE9PACKET_IDPKvi, 778640)
    off(_ZN7CPlayer10SendPacketE9PACKET_IDPKvi, 778432)
    off(_ZN14CPlayerManager10ClearCorpsEv, 606960)
    off(_ZN14CPlayerManager13WillTerminateEv, 607920)
    off(_ZN13GUIMatchSetup18RefreshCorsButtonsEv, 744304)
    off(_ZN11GUIHostList13ClearHostListEv, 719040)
    off(_ZN14CPlayerManager12GetLeftCorpsEi, 608224)
    off(_ZN14CPlayerManager13GetRightCorpsEi, 608240)
    off(_ZN14CPlayerManager15GetNumLeftCorpsEv, 608256)
    off(_ZN14CPlayerManager16GetNumRightCorpsEv, 608288)
    off(_ZN14CPlayerManager8SelCorpsEiiP7CPlayer, 608320)
    off(_ZN14CPlayerManager17RemoveCorpsPlayerEii, 608608)
    off(_ZN14CPlayerManager17RemoveCorpsPlayerEP7CPlayer, 608672)
    off(_ZN14CPlayerManager12RemovePlayerEP7CPlayer, 608848)
    off(_ZN14CPlayerManager20onPlayerDisconnectedEPKc, 608976)
    off(_ZN14CPlayerManager12GetCorpsDataERi, 609120)
    off(_ZN14CPlayerManager15onPeerConnectedEPKc, 610032)
    off(_ZN14CPlayerManager12onStartMatchEv, 610816)
    off(_ZN9ecGameKit18GetLocalPlayerInfoER12ecPlayerInfo, 886288)
    off(_ZN9ecGameKit19GetMatchPlayersInfoEv, 886272)
    off(_ZN14CPlayerManager14SetCorpsByDataEPviP7CPlayer, 611856)
    off(_ZN14CPlayerManager17IsAllPlayersReadyEv, 612576)
    off(_ZN14CPlayerManager23RefreshAndSendCorpsDataEv, 612832)
    off(_ZN14CPlayerManager18onPeerDisconnectedEPKc, 613024)
    off(_ZN14CPlayerManager14SendRoundBeginEv, 613648)
    off(_ZN14CPlayerManager16ClearActionQueueEv, 613904)
    off(_ZN14CPlayerManager14onReceivedDataEPKviPKcb, 614160)
    off(_ZN7CPlayer7SendAckEi, 779296)
    off(_ZN7CPlayer7RecvAckEi, 779344)
    off(_ZN13GUIMatchSetup16CreatCorsButtonsEv, 743296)
    off(_ZN14CPlayerManager22onReveivedDataFromPeerEPKviPKc, 616304)
    off(_ZN14CPlayerManager24onReceivedDataFromPlayerEPKviPKc, 616320)
    off(_ZN7CPlayer9SendFirstEv, 778816)
    off(_ZN14CPlayerManagerC2Ev, 617472)
    off(_ZN14CPlayerManagerC1Ev, 617472)
    off(_ZN6CSceneD2Ev, 618432)
    off(_ZN9CAreaMarkD1Ev, 674720)
    off(_ZN6CSceneD1Ev, 618432)
    off(_ZN6CSceneC2Ev, 618608)
    off(_ZN9CAreaMarkC1Ev, 674672)
    off(_ZN7CCameraC1Ev, 690880)
    off(_ZN6CSceneC1Ev, 618608)
    off(_ZN6CScene17CheckAdjacentDataEv, 618912)
    off(_ZN6CScene9NewAdjoinEv, 618944)
    off(_ZN6CScene10LoadAdjoinEi, 619232)
    off(_ZN6CScene10SaveAdjoinEi, 619552)
    off(_ZN6CScene10MakeAdjoinEii, 619792)
    off(_ZN6CScene9DelAdjoinEii, 620160)
    off(_ZN6CScene8IsAdjoinEii, 620544)
    off(_ZN6CScene12RenderAdjoinEv, 620672)
    off(_ZN6CScene17RenderAreasCenterEv, 620688)
    off(_ZN6CScene15RenderAreasArmyEv, 620704)
    off(_ZN6CScene16RenderAreasPointEv, 620720)
    off(_ZN6CScene12LoadAreaDataEi, 620736)
    off(_ZN6CScene12SaveAreaDataEi, 621024)
    off(_ZN6CScene14RenderSeaAreasEv, 621376)
    off(_ZN7CCamera14IsRectInCameraEffff, 692944)
    off(_ZN6CScene13RenderAreasIDEv, 621664)
    off(_ZN6CScene10ClearAreasEv, 621696)
    off(_ZN5CAreaD1Ev, 667696)
    off(_ZN7CBomberD1Ev, 688816)
    off(_ZN11CBackgroundD1Ev, 676352)
    off(_ZN9CAreaMark7ReleaseEv, 674688)
    off(_ZN6CScene11SaveAreaTaxEi, 622208)
    off(_ZN6CScene14LoadAreaEnableEPKc, 622880)
    off(_ZN6CScene14SaveAreaEnableEPKc, 623184)
    off(_ZN6CScene20AreaDisableOutofRectEiiii, 623200)
    off(_ZN6CScene13InitAreaImageEi, 623360)
    off(_ZN6CScene12CalSceneRectERfS0_S0_S0_, 625408)
    off(_ZN6CScene13IsRectInSecenEffff, 626272)
    off(_ZN7CCamera5UpateEf, 692576)
    off(_ZN7CBomber6UpdateEf, 689760)
    off(_ZN5CArea6UpdateEf, 671648)
    off(_ZN6CMedal5UpateEf, 778000)
    off(_ZN6CScene11CreateArrowEii, 626928)
    off(_Z7InvSqrtf, 945168)
    off(_ZN9hgeVector6RotateEf, 945456)
    off(_ZN6CScene14ScreenToAreaIDEff, 627680)
    off(_ZN9CAreaMark7GetMarkEii, 675024)
    off(_ZN7CCamera4MoveEffb, 691504)
    off(_ZN6CScene6MoveToEii, 627792)
    off(_ZN7CCamera6MoveToEffb, 692160)
    off(_ZN7CCamera21IsRectInVisibleRegionEffff, 693040)
    off(_ZN6CScene21MoveCameraBetweenAreaEii, 628208)
    off(_ZN6CScene25GetTwoAreasDistanceSquareEii, 628464)
    off(_ZN6CScene19GetTwoAreasDistanceEii, 628560)
    off(_ZN6CScene19GetNumAdjacentAreasEi, 628784)
    off(_ZN6CScene17GetAdjacentAreaIDEii, 628816)
    off(_ZN6CScene15GetAdjacentAreaEii, 628848)
    off(_ZN7CCamera5ApplyEv, 692832)
    off(_ZN11CBackground6RenderEP7CCamera, 677600)
    off(_ZN11CBackground9RenderBoxEP7CCameraffff, 677792)
    off(_ZN5CArea14RenderBuildingEv, 672832)
    off(_ZN5CArea6RenderEv, 672960)
    off(_ZN7ecImage9Render4VCEffffffffif, 947504)
    off(_ZN6CMedal6RenderEv, 778080)
    off(_ZN7CBomber6RenderEv, 690800)
    off(_ZN8CCountry15AirstrikeRadiusEv, 698976)
    off(_ZN6CScene13CheckAdjacentEii, 631104)
    off(_ZN5CArea11HasArmyCardEii, 670576)
    off(_ZN6CScene17SetSelAreaTargetsEP5CArea, 631968)
    off(_ZN5CArea12EncirclementEv, 671440)
    off(_ZN6CScene8AirborneEi, 632944)
    off(_ZN7CBomber8AirborneEi, 689472)
    off(_ZN6CScene19AircraftCarrierBombEii, 632976)
    off(_ZN7CBomber19AircraftCarrierBombEii, 689424)
    off(_ZN6CScene8BombAreaEii, 633008)
    off(_ZN7CBomber8BombAreaEii, 689152)
    off(_ZN7CBomber9IsBombingEv, 689744)
    off(_ZN6CMedalC1Ev, 777952)
    off(_ZN6CMedal4InitEff, 777968)
    off(_ZN6CScene11LoadAreaTaxEi, 633600)
    off(_ZN5CAreaC1Ev, 667552)
    off(_ZN5CArea4InitEiRK8AreaInfo, 667904)
    off(_ZN6CScene9InitAreasEiPKc, 634624)
    off(_ZN6CScene20CreateRenderAreaListEv, 636992)
    off(_ZN9CAreaMark4InitEi, 674736)
    off(_ZN11CBackgroundC1Ev, 676192)
    off(_ZN11CBackground4InitEiiiiiffff, 676608)
    off(_ZN7CCamera4InitEffff, 690896)
    off(_ZN7CBomberC1Ev, 688784)
    off(_ZN7CBomber4InitEv, 688960)
    off(_ZN9CSoundResD2Ev, 638080)
    off(_ZN9CSoundResD1Ev, 638080)
    off(_ZN9CSoundResC2Ev, 638096)
    off(_ZN9CSoundResC1Ev, 638096)
    off(_ZN13CStateManagerD2Ev, 638432)
    off(_ZN13CStateManagerD1Ev, 638432)
    off(_ZN13CStateManagerC2Ev, 638448)
    off(_ZN13CStateManagerC1Ev, 638448)
    off(_ZN13CTouchInertiaD2Ev, 639104)
    off(_ZN13CTouchInertiaC2Ev, 639152)
    off(_ZN13CTouchInertia13AddTrackPointEff, 639328)
    off(_ZN13CTouchInertia13GetStartPointEv, 639520)
    off(_ZN9CActionAI11detectCardsE7CARD_ID, 640208)
    off(_ZN8CCountry12IsCardUnlockEP7CardDef, 696160)
    off(_ZN9CActionAI21analyseCompositePowerEv, 640448)
    off(_ZN9CActionAI12getAiPercentEi, 640912)
    off(_ZN9CActionAI14getNumArmyMoveEii, 641328)
    off(_ZN9CActionAI12purChaseCardE7CARD_ID, 641584)
    off(_ZN13CActionAssist17purChaseCardsCardEv, 656784)
    off(_ZN13CActionAssist16purChaseFortCardEv, 659488)
    off(_ZN13CActionAssist21purChaseConstructCardEv, 649568)
    off(_ZN13CActionAssist21purChaseAirStrikeCardEv, 660832)
    off(_ZN13CActionAssist17purChaseDraftCardEb, 655136)
    off(_ZN9CActionAI15sortArmyToFrontEv, 642784)
    off(_ZN5CArea12IsArmyActiveEi, 671248)
    off(_ZN9CActionAI8getMaxIdEv, 643552)
    off(_ZN9CActionAI13setArmyActionEP5CArea, 643808)
    off(_ZN13CActionAssist16actionToNextAreaEiiii, 663840)
    off(_ZN9CActionAI13moveAndAttackEv, 644576)
    off(_Z13GetAIRandSeedv, 647056)
    off(_ZN13CActionAssist13calcDraftTypeEbiP8CCountry, 647120)
    off(_ZN5CArea12GetCityLevelEv, 668592)
    off(_ZN13CActionAssist19purChaseSpecialCardEv, 650928)
    off(_ZN13CActionAssist11getAllianceEiii, 650944)
    off(_ZN13CActionAssist10searchNodeEii, 651232)
    off(_ZN13CActionAssist14searchNodeByIDEii, 652544)
    off(_ZN13CActionAssist11getNeighborEiiic, 652864)
    off(_ZN8CCountry19CheckCardTargetArmyEP7CardDefii, 698704)
    off(_ZN5CArea16GetIndustryLevelEv, 668672)
    off(_ZN13CActionAssist4isAIEi, 663552)
    off(_ZN5CAreaC2Ev, 667552)
    off(_ZN5CAreaD2Ev, 667696)
    off(_ZN5CArmyD1Ev, 675168)
    off(_ZN5CArea12CanConstructEi, 668112)
    off(_ZN5CArea9ConstructEi, 668208)
    off(_ZN5CArea10GetArmyIdxEP5CArmy, 668784)
    off(_ZN5CArea10RemoveArmyEP5CArmy, 668992)
    off(_ZN5CArea15MoveArmyToFrontEP5CArmyb, 669344)
    off(_ZN5CArea9DraftArmyEi, 669408)
    off(_ZN5CArea13SetMoveInArmyEPS_P5CArmybbPKc, 669584)
    off(_ZN5CArea10MoveArmyToEPS_, 669728)
    off(_ZN8CCountry10RemoveAreaEi, 693920)
    off(_ZN8CCountry14BeConquestedByEPS_, 695168)
    off(_ZN5CArea10SetArmyDirEif, 670480)
    off(_ZN5CArea11AddArmyCardEii, 670512)
    off(_ZN5CArea11DelArmyCardEii, 670544)
    off(_ZN5CArea18RevertArmyStrengthEi, 670720)
    off(_ZN5CArmy12LostStrengthEi, 675200)
    off(_ZN8CCountry12CommanderDieEv, 698176)
    off(_ZN5CArea15AddArmyStrengthEii, 670912)
    off(_ZN5CArmy11AddStrengthEi, 675504)
    off(_ZN5CArea16AllArmyPoisoningEv, 670960)
    off(_ZN5CArmy9PoisoningEv, 675472)
    off(_ZN5CArea11UpgradeArmyEi, 671008)
    off(_ZN5CArmy7UpgradeEv, 675728)
    off(_ZN5CArea18SetAllArmyMovementEi, 671040)
    off(_ZN5CArea17CheckEncirclementEv, 671280)
    off(_ZN5CArmy9SetMoraleEi, 675920)
    off(_ZN5CArea10RenderArmyEffiP5CArmy, 672352)
    off(_ZN5CArea9TurnBeginEv, 673408)
    off(_ZN5CArmy9TurnBeginEv, 676128)
    off(_ZN5CArea7TurnEndEv, 673584)
    off(_ZN5CArmy7TurnEndEv, 676144)
    off(_ZN5CArmy8SaveArmyEP12SaveArmyInfo, 675952)
    off(_ZN5CArmy8LoadArmyEPK12SaveArmyInfo, 676032)
    off(_ZN9CAreaMarkC2Ev, 674672)
    off(_ZN9CAreaMarkD2Ev, 674720)
    off(_ZN5CArmyC2Ev, 675152)
    off(_ZN5CArmyD2Ev, 675168)
    off(_ZN11CBackgroundC2Ev, 676192)
    off(_ZN11CBackgroundD2Ev, 676352)
    off(_ZN12CBattleSceneC2Ev, 678560)
    off(_ZN12CBattleScene7ReleaseEv, 678896)
    off(_ZN11CBattleUnit6RenderEv, 688160)
    off(_ZN8ecEffect6RenderEv, 966624)
    off(_Z13HasUnitMotionPKci, 679680)
    off(_ZN12CBattleScene11CreateUnitsEv, 680288)
    off(_ZN9ecLibraryC1Ev, 1279504)
    off(_ZN9ecLibrary4LoadEPKcR12ecTextureRes, 1281664)
    off(_ZN11CBattleUnitC1Ev, 686736)
    off(_ZN11CBattleUnit4InitEiiP9ecLibraryP11UnitMotions, 686800)
    off(_ZN11CBattleUnit12SetDestroyedEv, 688656)
    off(_ZN12CBattleScene12ReleaseUnitsEv, 681296)
    off(_ZN11CBattleUnitD1Ev, 687296)
    off(_ZN12CBattleScene10CreateFortEv, 681440)
    off(_ZN12CBattleScene11ReleaseFortEv, 681984)
    off(_ZN11CBattleUnit11IsAttackingEv, 688624)
    off(_ZN11CBattleUnit7DestroyEv, 688672)
    off(_ZN12CBattleScene9AddCraterEPKcfff, 684384)
    off(_ZN12CBattleScene10StarEffectEi, 684768)
    off(_ZN12CBattleScene9AddEffectEPKcff, 684800)
    off(_ZN15ecEffectManager12CreateEffectEPKc, 967232)
    off(_ZN11CBattleUnit6AttackEv, 688480)
    off(_ZN11CBattleUnit6UpdateEf, 687392)
    off(_ZN8ecEffect6UpdateEf, 966544)
    off(_ZN8ecEffect6IsLiveEv, 966672)
    off(_ZN8ecEffectD1Ev, 965920)
    off(_ZN12CBattleSceneD2Ev, 686368)
    off(_ZN11CBattleUnitC2Ev, 686736)
    off(_ZN9ecElementC1Ev, 1284416)
    off(_ZN9ecElement4InitEPKcP9ecLibrary, 1285600)
    off(_ZN9ecElement4PlayEv, 1285824)
    off(_ZN11CBattleUnit7ReleaseEv, 687232)
    off(_ZN9ecElementD1Ev, 1284480)
    off(_ZN11CBattleUnitD2Ev, 687296)
    off(_ZN9ecElement6UpdateEf, 1287808)
    off(_ZN9ecElement6RenderERK7ecMtx32, 1286976)
    off(_ZN9ecElement11SetCurFrameEi, 1285664)
    off(_ZN9ecElement7SetLoopEi, 1286080)
    off(_ZN9ecElement11GetPlayTimeEv, 1285776)
    off(_ZN7CBomberC2Ev, 688784)
    off(_ZN7CBomberD2Ev, 688816)
    off(_ZN8CCountry7UseCardEP7CardDefii, 700976)
    off(_ZN7CCameraC2Ev, 690880)
    off(_ZN7CCamera12SetSceneRectEffff, 691024)
    off(_ZN8CCountryC2Ev, 693280)
    off(_ZN8CCountryD2Ev, 693344)
    off(_ZN8CCountry8FindAreaEi, 694256)
    off(_ZN8CCountry15GetFirstCapitalEv, 695008)
    off(_ZN8CCountry18FindAdjacentAreaIDEib, 695408)
    off(_ZN8CCountry22FindAdjacentLandAreaIDEib, 695552)
    off(_ZN8CCountry13GetNumAirportEv, 695712)
    off(_ZN8CCountry18GetMinDstToAirportEi, 695808)
    off(_ZN8CCountry17GenCardTargetListE7CARD_ID, 696080)
    off(_ZN8CCountry16GetCurCardTargetEv, 696096)
    off(_ZN8CCountry14NextCardTargetEv, 696128)
    off(_ZN8CCountry12FinishActionEv, 696448)
    off(_ZN8CCountry16SetWarMedalLevelE11WARMEDAL_IDi, 698944)
    off(_ZN8CCountry12CollectTaxesEv, 700592)
    off(_ZN8CCountry16CollectIndustrysEv, 700784)
    off(_ZN8CCountry8DoActionEv, 703600)
    off(_ZN17GUICommanderMedalD2Ev, 704976)
    off(_ZN17GUICommanderMedalD1Ev, 704976)
    off(_ZN17GUICommanderMedalD0Ev, 705136)
    off(_ZN11GUIWarMedalD2Ev, 705168)
    off(_ZN11GUIWarMedalD1Ev, 705168)
    off(_ZN11GUIWarMedalD0Ev, 705248)
    off(_ZN17GUICommanderMedal8OnUpdateEf, 705280)
    off(_ZN11GUIWarMedal8OnUpdateEf, 705424)
    off(_ZN17GUICommanderMedal8OnRenderEv, 705568)
    off(_ZN11GUIWarMedal8OnRenderEv, 705840)
    off(_ZN13GUIAdornMedalD2Ev, 706208)
    off(_ZN13GUIAdornMedalD1Ev, 706208)
    off(_ZN13GUIAdornMedalD0Ev, 706432)
    off(_ZN13GUIAdornMedal8OnRenderEv, 706464)
    off(_ZN16GUIUpgradeButtonD2Ev, 706992)
    off(_ZN16GUIUpgradeButtonD1Ev, 706992)
    off(_ZN16GUIUpgradeButtonD0Ev, 707088)
    off(_ZN16GUIUpgradeButton8OnRenderEv, 707120)
    off(_ZN6ecText14GetStringWidthEib, 976336)
    off(_ZN12GUICommanderD2Ev, 707808)
    off(_ZN12GUICommanderD1Ev, 707808)
    off(_ZN12GUICommanderD0Ev, 708256)
    off(_ZN12GUICommander8OnRenderEv, 708288)
    off(_ZN12GUICommander8OnUpdateEf, 708704)
    off(_ZN17GUICommanderMedalC2Ev, 708800)
    off(_ZN17GUICommanderMedalC1Ev, 708800)
    off(_ZN17GUICommanderMedal4InitERK7GUIRecti, 708928)
    off(_ZN17GUICommanderMedal13SetArrowColorEj, 709376)
    off(_ZN11GUIWarMedalC2Ev, 709408)
    off(_ZN11GUIWarMedalC1Ev, 709408)
    off(_ZN11GUIWarMedal8SetLevelEi, 709456)
    off(_ZN11GUIWarMedal4InitERK7GUIRect11WARMEDAL_IDi, 709680)
    off(_ZN11GUIWarMedal13SetArrowColorEj, 709904)
    off(_ZN13GUIAdornMedalC2Ev, 709936)
    off(_ZN13GUIAdornMedal7RefreshEv, 710112)
    off(_ZN16GUIUpgradeButtonC2Ev, 710688)
    off(_ZN16GUIUpgradeButtonC1Ev, 710688)
    off(_ZN16GUIUpgradeButton12SetNeedMedalEi, 710768)
    off(_ZN12GUICommanderC2Ev, 710992)
    off(_ZN12GUICommander16SetCommanderInfoEv, 711200)
    off(_ZN12GUICommander13SelectedMedalEi, 714720)
    off(_ZN12GUICommander7OnEventERK5Event, 714912)
    off(_ZN14GUIExitWarningD2Ev, 715840)
    off(_ZN14GUIExitWarningD1Ev, 715840)
    off(_ZN14GUIExitWarningD0Ev, 715984)
    off(_ZN14GUIExitWarning8OnRenderEv, 716016)
    off(_ZN14GUIExitWarningC2Ev, 716128)
    off(_ZN14GUIExitWarning7OnEventERK5Event, 717312)
    off(_ZN19GUIConnectHostStateD2Ev, 717504)
    off(_ZN19GUIConnectHostStateD1Ev, 717504)
    off(_ZN19GUIConnectHostStateD0Ev, 717552)
    off(_ZN11GUIHostListD2Ev, 717584)
    off(_ZN11GUIHostListD1Ev, 717584)
    off(_ZN11GUIHostListD0Ev, 717712)
    off(_ZN11GUIHostList8OnRenderEv, 717744)
    off(_ZN19GUIConnectHostState8OnRenderEv, 717856)
    off(_ZN11GUIHostItemD2Ev, 718112)
    off(_ZN11GUIHostItemD1Ev, 718112)
    off(_ZN11GUIHostItemD0Ev, 718352)
    off(_ZN19GUIConnectHostStateC2Ev, 718384)
    off(_ZN19GUIConnectHostStateC1Ev, 718384)
    off(_ZN19GUIConnectHostState4InitER7GUIRect, 718464)
    off(_ZN11GUIHostItemC2Ev, 718608)
    off(_ZN11GUIHostItemC1Ev, 718608)
    off(_ZN11GUIHostItem7SetNameEPKc, 718800)
    off(_ZN11GUIHostListC2Ev, 718960)
    off(_ZN11GUIHostList8FindHostEPKc, 719120)
    off(_ZN11GUIHostList14FindHostByUUIDEi, 719232)
    off(_ZN11GUIHostList7AddHostEPKcS1_ii, 719296)
    off(_ZN19GUIConnectHostState7OnEventERK5Event, 723376)
    off(_ZN11GUIHostList7OnEventERK5Event, 723424)
    off(_ZN11GUIHostItem8OnRenderEv, 723584)
    off(_ZN11GUILevelSelD2Ev, 723680)
    off(_ZN11GUILevelSelD1Ev, 723680)
    off(_ZN11GUILevelSelD0Ev, 723760)
    off(_ZN11GUILevelSel8OnRenderEv, 723808)
    off(_ZN11GUILevelSelC2Ev, 724064)
    off(_ZN11GUILevelSel7OnEventERK5Event, 724224)
    off(_ZN10GUILoadingD2Ev, 724448)
    off(_ZN10GUILoadingD1Ev, 724448)
    off(_ZN10GUILoadingD0Ev, 724560)
    off(_ZN10GUILoading8OnRenderEv, 724592)
    off(_ZN10GUILoadingC2Ev, 724800)
    off(_ZN10GUILoading7OnEventERK5Event, 725216)
    off(_ZN16GUILockedWarningD2Ev, 725248)
    off(_ZN16GUILockedWarningD1Ev, 725248)
    off(_ZN16GUILockedWarningD0Ev, 725392)
    off(_ZN16GUILockedWarning8OnRenderEv, 725424)
    off(_ZN16GUILockedWarningC2Ev, 725632)
    off(_ZN16GUILockedWarning7OnEventERK5Event, 726352)
    off(_ZN11GUIMainMenuD2Ev, 726592)
    off(_ZN11GUIMainMenuD1Ev, 726592)
    off(_ZN11GUIMainMenuD0Ev, 727088)
    off(_ZN11GUIMainMenu8OnRenderEv, 727120)
    off(_ZN11GUIMainMenuC2Ev, 727216)
    off(_ZN11GUIMainMenu12IsShowNewTipEv, 727328)
    off(_ZN9GUIButton12SetTextImageEPKc, 792992)
    off(_ZN8GUIImageC1Ev, 795904)
    off(_ZN8GUIImage4InitEPKcRK7GUIRect, 796240)
    off(_ZN11GUIMainMenu8OnUpdateEf, 736000)
    off(_ZN11GUIMainMenu7OnEventERK5Event, 738048)
    off(_ZN12GUICorpsInfoD2Ev, 738928)
    off(_ZN12GUICorpsInfoD1Ev, 738928)
    off(_ZN12GUICorpsInfoD0Ev, 739056)
    off(_ZN13GUIMatchSetup8OnRenderEv, 739088)
    off(_ZN14GUICorpsButton8OnRenderEv, 739136)
    off(_ZN12GUICorpsInfo8OnRenderEv, 739312)
    off(_ZN14GUICorpsButtonD2Ev, 739632)
    off(_ZN14GUICorpsButtonD1Ev, 739632)
    off(_ZN14GUICorpsButtonD0Ev, 739712)
    off(_ZN13GUIMatchSetupD2Ev, 739744)
    off(_ZN13GUIMatchSetupD1Ev, 739744)
    off(_ZN13GUIMatchSetupD0Ev, 740080)
    off(_ZN12GUICorpsInfoC2Ev, 740176)
    off(_ZN12GUICorpsInfoC1Ev, 740176)
    off(_ZN12GUICorpsInfo4InitERK7GUIRect, 740272)
    off(_ZN12GUICorpsInfo13SetPlayerNameEPKcbS1_iib, 740368)
    off(_ZN14GUICorpsButtonC2Ev, 741664)
    off(_ZN14GUICorpsButtonC1Ev, 741664)
    off(_ZN14GUICorpsButton4InitERK7GUIRectPKcb, 741712)
    off(_ZN14GUICorpsButton13SetPlayerNameEPKcbS1_iib, 743008)
    off(_ZN13GUIMatchSetupC2Ev, 743184)
    off(_ZN13GUIMatchSetup7OnEventERK5Event, 746752)
    off(_ZN10GUINewGameD2Ev, 747280)
    off(_ZN10GUINewGameD1Ev, 747280)
    off(_ZN10GUINewGameD0Ev, 747424)
    off(_ZN10GUINewGame8OnRenderEv, 747456)
    off(_ZN7_JNIEnv22CallStaticObjectMethodEP7_jclassP10_jmethodIDz, 747536)
    off(_ZN10GUINewGameC2Ev, 747728)
    off(_ZN10GUINewGame12IsShowSurveyEv, 747904)
    off(_ZN10GUINewGame12IsImageReadyEv, 748048)
    off(_ZN10GUINewGame18IsIabEventImgReadyEv, 748192)
    off(_ZN10GUINewGame15IsShowSurveyTipEv, 748336)
    off(_ZN10GUINewGame17IsShowIabEventTipEv, 748480)
    off(_ZN10GUINewGame14IsShowIabEventEv, 748624)
    off(_Z12JString2CStrP7_JNIEnvP8_jstring, 748768)
    off(_ZN10GUINewGame17GetPromotionImageEv, 749040)
    off(_ZN10GUINewGame16GetIabEventImageEv, 749360)
    off(_ZN10GUINewGame15GetPromotionUrlEv, 749680)
    off(_ZN10GUINewGame14BtnSurveyClickEv, 749856)
    off(_ZN10GUINewGame14GetIabEventUrlEv, 749984)
    off(_ZN10GUINewGame21OnRadioBtnSurveyClickEv, 750160)
    off(_ZN10GUINewGame23OnRadioBtnIabEventClickEv, 750320)
    off(_ZN10GUINewGame14GetSelectGroupEP14GUIRadioButton, 750480)
    off(_ZN10GUINewGame18OnCheckButtonClickEP14GUIRadioButton, 750544)
    off(_ZN10GUINewGame13GetAppVersionEv, 750688)
    off(_ZN9GUIButton13SetTextOffsetEff, 793264)
    off(_ZN9GUIButton12SetTextAlignEi, 793296)
    off(_ZN8GUIImage4InitEPKcRK13ecTextureRectRK7GUIRectbbb, 795968)
    off(_ZN7GUITextC1Ev, 803936)
    off(_ZN7GUIText4InitERK7GUIRectP9ecUniFont, 803968)
    off(_ZN7GUIText7SetTextEPKc, 804096)
    off(_ZN8GUIImage8SetImageEPKcRK13ecTextureRectb, 796400)
    off(_ZN10GUINewGame7OnEventERK5Event, 760400)
    off(_Z16ecLaunchAppStorePKc, 977872)
    off(_ZN12GUISelBattle8OnRenderEv, 761024)
    off(_ZN12GUISelBattleC2Ev, 761808)
    off(_ZN13GUIBattleListC1Ev, 782832)
    off(_ZN13GUIBattleList4InitERK7GUIRecti, 782944)
    off(_ZN13GUIBattleList18SelectLastUnlockedEv, 784784)
    off(_ZN13GUIBattleList9SetSelectEi, 784576)
    off(_ZN12GUISelBattle16ReleaseImageListEv, 765184)
    off(_ZN12GUISelBattleD2Ev, 765472)
    off(_ZN12GUISelBattleD1Ev, 765472)
    off(_ZN12GUISelBattleD0Ev, 765952)
    off(_ZN12GUISelBattle13LoadImageListEii, 766176)
    off(_ZN12GUISelBattle9SelBattleEii, 768096)
    off(_ZN12GUISelBattle8OnUpdateEf, 768144)
    off(_ZN12GUISelBattle7OnEventERK5Event, 768864)
    off(_ZN13GUISelCountry8OnRenderEv, 769600)
    off(_ZN13GUISelCountry8OnUpdateEf, 770048)
    off(_ZN13GUISelCountryC2Ev, 770864)
    off(_ZN13GUISelCountry9SelBattleEii, 771120)
    off(_ZN13GUISelCountry13LoadImageListEi, 771136)
    off(_ZN14GUICountryListC1Ev, 788240)
    off(_ZN14GUICountryList4InitERK7GUIRecti, 789216)
    off(_ZN13GUISelCountry16ReleaseImageListEv, 774528)
    off(_ZN13GUISelCountryD2Ev, 774688)
    off(_ZN13GUISelCountryD1Ev, 774688)
    off(_ZN13GUISelCountryD0Ev, 775008)
    off(_ZN13GUISelCountry7OnEventERK5Event, 775040)
    off(_ZN14GUICountryList15GetSelCountryIDEv, 788496)
    off(_ZN10GUIServiceD2Ev, 775296)
    off(_ZN10GUIServiceD1Ev, 775296)
    off(_ZN10GUIServiceD0Ev, 775440)
    off(_ZN10GUIService8OnRenderEv, 775472)
    off(_ZN10GUIServiceC2Ev, 775552)
    off(_ZN7GUIText8SetAlignEi, 804176)
    off(_ZN10GUIService7OnEventERK5Event, 777648)
    off(_ZN6CMedalC2Ev, 777952)
    off(_ZN7CPlayerC2Ev, 778224)
    off(_ZN7CPlayer10RecvPacketEPKvi, 778800)
    off(_ZN7CPlayer15ClearPacketListEv, 778880)
    off(_ZN7CPlayerD2Ev, 779008)
    off(_ZN13GUIBattleItem8OnUpdateEf, 779472)
    off(_ZN13GUIBattleItemD2Ev, 779488)
    off(_ZN13GUIBattleItemD1Ev, 779488)
    off(_ZN13GUIBattleItemD0Ev, 779680)
    off(_ZN13GUIBattleItem8OnRenderEv, 779712)
    off(_ZN13GUIBattleListD2Ev, 781360)
    off(_ZN13GUIBattleListD1Ev, 781360)
    off(_ZN13GUIBattleListD0Ev, 781424)
    off(_ZN13GUIBattleList8OnUpdateEf, 781472)
    off(_ZN13GUIBattleItemC2Ev, 782080)
    off(_ZN13GUIBattleItemC1Ev, 782080)
    off(_ZN13GUIBattleItem4InitEiiRK7GUIRect, 782144)
    off(_ZN13GUIBattleItem11SetSelectedEb, 782816)
    off(_ZN13GUIBattleListC2Ev, 782832)
    off(_ZN13GUIBattleList11ResetSelectEv, 783952)
    off(_ZN13GUIBattleList15ResetTouchStateEv, 784096)
    off(_ZN13GUIBattleList10GelSelItemEff, 784128)
    off(_ZN13GUIBattleItem7OnEventERK5Event, 784288)
    off(_ZN13GUIBattleList7OnEventERK5Event, 784864)
    off(_ZN14GUICountryItem8OnUpdateEf, 785616)
    off(_ZN14GUICountryItemD2Ev, 785632)
    off(_ZN14GUICountryItemD1Ev, 785632)
    off(_ZN14GUICountryItemD0Ev, 785744)
    off(_ZN14GUICountryItem8OnRenderEv, 785776)
    off(_ZN14GUICountryListD2Ev, 787200)
    off(_ZN14GUICountryListD1Ev, 787200)
    off(_ZN14GUICountryListD0Ev, 787264)
    off(_ZN14GUICountryList8OnUpdateEf, 787296)
    off(_ZN14GUICountryItemC2Ev, 787904)
    off(_ZN14GUICountryItemC1Ev, 787904)
    off(_ZN14GUICountryItem4InitEPKcS1_RK7GUIRect, 787952)
    off(_ZN14GUICountryItem11SetSelectedEb, 788224)
    off(_ZN14GUICountryListC2Ev, 788240)
    off(_ZN14GUICountryList11ResetSelectEv, 788352)
    off(_ZN14GUICountryList15ResetTouchStateEv, 788528)
    off(_ZN14GUICountryList10GelSelItemEff, 788560)
    off(_ZN14GUICountryItem7OnEventERK5Event, 788704)
    off(_ZN14GUICountryList9SetSelectEi, 789008)
    off(_ZN14GUICountryList7OnEventERK5Event, 790080)
    off(_ZN9GUIButtonD1Ev, 790832)
    off(_ZN9GUIButtonD0Ev, 791120)
    off(_ZN9GUIButton7SetGlowEPKc, 792720)
    off(_ZN6ecText9GetHeightEv, 976928)
    off(_ZN9GUIButton7SetTextEPKt, 793184)
    off(_ZN6ecText7SetTextEPKt, 977680)
    off(_ZN9GUIButton8SetAlphaEf, 793312)
    off(_ZN10GUIElementC1Ev, 793776)
    off(_ZN10GUIElement11RemoveChildEPS_, 794016)
    off(_ZN10GUIElementD1Ev, 794368)
    off(_ZN10GUIElementD0Ev, 794400)
    off(_ZN10GUIElement4MoveEff, 794592)
    off(_ZN10GUIElement11CheckInRectEffRK7GUIRect, 794976)
    off(_ZN10GUIElement10SetVisibleEb, 795040)
    off(_ZN10GUIElement12FindByHandleEj, 795168)
    off(_ZN10GUIElement9PostEventERK5Event, 795264)
    off(_ZN10GUIElement6RenderEv, 795392)
    off(_ZN10GUIElement6UpdateEf, 795488)
    off(_ZN8GUIImageD2Ev, 795600)
    off(_ZN8GUIImageD1Ev, 795600)
    off(_ZN8GUIImageD0Ev, 795712)
    off(_ZN8GUIImage8OnRenderEv, 795744)
    off(_ZN8GUIImageC2Ev, 795904)
    off(_ZN8GUIImage8SetAlphaEf, 796368)
    off(_ZN10GUIManager7OnEventERK5Event, 796912)
    off(_ZN10GUIManagerD2Ev, 796960)
    off(_ZN10GUIManagerD1Ev, 796960)
    off(_ZN10GUIManagerD0Ev, 797056)
    off(_ZN10GUIManagerC2Ev, 797088)
    off(_ZN10GUIManagerC1Ev, 797088)
    off(_ZN12GUIScrollBarC1Ev, 802464)
    off(_ZN12GUIScrollBar4InitERK7GUIRectPKcS4_iiiii, 802688)
    off(_ZN16GUIMotionManagerD2Ev, 798800)
    off(_ZN16GUIMotionManagerD1Ev, 798800)
    off(_ZN16GUIMotionManagerC2Ev, 798816)
    off(_ZN16GUIMotionManagerC1Ev, 798816)
    off(_ZN16GUIMotionManager9SetMotionEjffffft, 799696)
    off(_ZN16GUIMotionManager9AddMotionEP10GUIElementffffft, 800000)
    off(_ZN16GUIMotionManager10AddMotionXEP10GUIElementfft, 800288)
    off(_ZN16GUIMotionManager10AddMotionYEP10GUIElementfft, 800448)
    off(_ZN16GUIMotionManager8SetSpeedEjff, 800608)
    off(_ZN16GUIMotionManager15GetMotionActiveEj, 801472)
    off(_ZN14GUIRadioButtonD1Ev, 801504)
    off(_ZN14GUIRadioButtonD0Ev, 801536)
    off(_ZN14GUIRadioButton8OnRenderEv, 801568)
    off(_ZN12GUIScrollBarD2Ev, 802208)
    off(_ZN12GUIScrollBarD1Ev, 802208)
    off(_ZN12GUIScrollBarD0Ev, 802320)
    off(_ZN12GUIScrollBar8OnRenderEv, 802352)
    off(_ZN12GUIScrollBarC2Ev, 802464)
    off(_ZN12GUIScrollBar7OnEventERK5Event, 803040)
    off(_ZN7GUITextD2Ev, 803728)
    off(_ZN7GUITextD1Ev, 803728)
    off(_ZN7GUITextD0Ev, 803808)
    off(_ZN7GUIText8OnRenderEv, 803840)
    off(_ZN7GUITextC2Ev, 803936)
    off(_ZN7GUIText12SetTextColorEj, 804144)
    off(_ZN9ecGameKitC2Ev, 886128)
    off(_ZN9ecGameKitD2Ev, 886144)
    off(_ZN9ecGameKit7ReleaseEv, 886176)
    off(_ZN9ecGameKit22SendPacketToAllPlayersEPKvi, 886208)
    off(_ZN18ecSessionInterfaceC2Ev, 886304)
    off(_ZN18ecSessionInterfaceD2Ev, 886320)
    off(_ZN18ecSessionInterface7ReleaseEv, 886352)
    off(_ZN18ecSessionInterface10DisconnectEPKc, 886432)
    off(_ZN18ecSessionInterface20SendPacketToAllPeersEPKvi, 886496)
    off(_ZN11TiXmlString7reserveEm, 886576)
    off(_ZN11TiXmlString6assignEPKcm, 886784)
    off(_ZN11TiXmlString6appendEPKcm, 887024)
    off(_ZNK9TiXmlNode10ToDocumentEv, 887552)
    off(_ZNK9TiXmlNode9ToElementEv, 887568)
    off(_ZNK9TiXmlNode9ToCommentEv, 887584)
    off(_ZNK9TiXmlNode9ToUnknownEv, 887600)
    off(_ZNK9TiXmlNode6ToTextEv, 887616)
    off(_ZNK9TiXmlNode13ToDeclarationEv, 887632)
    off(_ZN9TiXmlNode10ToDocumentEv, 887648)
    off(_ZN9TiXmlNode9ToElementEv, 887664)
    off(_ZN9TiXmlNode9ToCommentEv, 887680)
    off(_ZN9TiXmlNode9ToUnknownEv, 887696)
    off(_ZN9TiXmlNode6ToTextEv, 887712)
    off(_ZN9TiXmlNode13ToDeclarationEv, 887728)
    off(_ZNK12TiXmlElement9ToElementEv, 887744)
    off(_ZN12TiXmlElement9ToElementEv, 887760)
    off(_ZNK12TiXmlComment9ToCommentEv, 887776)
    off(_ZN12TiXmlComment9ToCommentEv, 887792)
    off(_ZNK9TiXmlText6ToTextEv, 887808)
    off(_ZN9TiXmlText6ToTextEv, 887824)
    off(_ZNK16TiXmlDeclaration13ToDeclarationEv, 887840)
    off(_ZN16TiXmlDeclaration13ToDeclarationEv, 887856)
    off(_ZNK12TiXmlUnknown9ToUnknownEv, 887872)
    off(_ZN12TiXmlUnknown9ToUnknownEv, 887888)
    off(_ZNK12TiXmlComment9StreamOutEP14TiXmlOutStream, 887904)
    off(_ZNK12TiXmlUnknown9StreamOutEP14TiXmlOutStream, 887984)
    off(_ZNK12TiXmlComment5PrintEP7__sFILEi, 888064)
    off(_ZNK12TiXmlUnknown5PrintEP7__sFILEi, 888192)
    off(_ZNK16TiXmlDeclaration5PrintEP7__sFILEi, 888304)
    off(_ZN9TiXmlBase9PutStringERK11TiXmlStringPS0_, 888480)
    off(_ZN9TiXmlBase9PutStringERK11TiXmlStringP14TiXmlOutStream, 889056)
    off(_ZNK9TiXmlText9StreamOutEP14TiXmlOutStream, 889200)
    off(_ZNK16TiXmlDeclaration9StreamOutEP14TiXmlOutStream, 889296)
    off(_ZNK9TiXmlText5PrintEP7__sFILEi, 889600)
    off(_ZN9TiXmlBase14StringToBufferC2ERK11TiXmlString, 889904)
    off(_ZN9TiXmlBase14StringToBufferC1ERK11TiXmlString, 889904)
    off(_ZN9TiXmlBase14StringToBufferD2Ev, 889968)
    off(_ZN9TiXmlBase14StringToBufferD1Ev, 889968)
    off(_ZN9TiXmlNodeC2ENS_8NodeTypeE, 890000)
    off(_ZN9TiXmlNodeC1ENS_8NodeTypeE, 890000)
    off(_ZN9TiXmlNodeD1Ev, 890112)
    off(_ZN12TiXmlUnknownD2Ev, 890208)
    off(_ZN12TiXmlUnknownD1Ev, 890208)
    off(_ZN12TiXmlUnknownD0Ev, 890240)
    off(_ZN16TiXmlDeclarationD2Ev, 890272)
    off(_ZN16TiXmlDeclarationD1Ev, 890272)
    off(_ZN9TiXmlTextD2Ev, 890384)
    off(_ZN9TiXmlTextD1Ev, 890384)
    off(_ZN9TiXmlTextD0Ev, 890416)
    off(_ZN12TiXmlCommentD2Ev, 890448)
    off(_ZN12TiXmlCommentD1Ev, 890448)
    off(_ZN12TiXmlCommentD0Ev, 890480)
    off(_ZN16TiXmlDeclarationD0Ev, 890512)
    off(_ZN9TiXmlNodeD0Ev, 890624)
    off(_ZNK9TiXmlNode6CopyToEPS_, 890656)
    off(_ZN9TiXmlNode5ClearEv, 890720)
    off(_ZN9TiXmlNode14InsertEndChildERKS_, 890864)
    off(_ZN9TiXmlNode17InsertBeforeChildEPS_RKS_, 890912)
    off(_ZN9TiXmlNode16InsertAfterChildEPS_RKS_, 891024)
    off(_ZN9TiXmlNode12ReplaceChildEPS_RKS_, 891136)
    off(_ZN9TiXmlNode11RemoveChildEPS_, 891264)
    off(_ZNK9TiXmlNode10FirstChildEPKc, 891360)
    off(_ZNK9TiXmlNode9LastChildEPKc, 891520)
    off(_ZN9TiXmlNode9LastChildEPKc, 891600)
    off(_ZNK9TiXmlNode15IterateChildrenEPKS_, 891680)
    off(_ZN9TiXmlNode15IterateChildrenEPS_, 891712)
    off(_ZNK9TiXmlNode11NextSiblingEPKc, 891744)
    off(_ZNK9TiXmlNode15IterateChildrenEPKcPKS_, 891824)
    off(_ZN9TiXmlNode11NextSiblingEPKc, 891856)
    off(_ZN9TiXmlNode15IterateChildrenEPKcPS_, 891936)
    off(_ZNK9TiXmlNode15PreviousSiblingEPKc, 891968)
    off(_ZN9TiXmlNode15PreviousSiblingEPKc, 892048)
    off(_ZNK9TiXmlNode17FirstChildElementEv, 892128)
    off(_ZN9TiXmlNode17FirstChildElementEv, 892192)
    off(_ZNK9TiXmlNode17FirstChildElementEPKc, 892256)
    off(_ZN9TiXmlNode17FirstChildElementEPKc, 892368)
    off(_ZNK9TiXmlNode18NextSiblingElementEv, 892480)
    off(_ZN9TiXmlNode18NextSiblingElementEv, 892544)
    off(_ZNK9TiXmlNode18NextSiblingElementEPKc, 892608)
    off(_ZN9TiXmlNode18NextSiblingElementEPKc, 892720)
    off(_ZNK9TiXmlNode11GetDocumentEv, 892832)
    off(_ZN9TiXmlNode11GetDocumentEv, 892896)
    off(_ZNK12TiXmlElement7GetTextEv, 892960)
    off(_ZN13TiXmlDocumentC2Ev, 893024)
    off(_ZN13TiXmlDocumentC1Ev, 893024)
    off(_ZN13TiXmlDocumentC2EPKc, 893184)
    off(_ZN13TiXmlDocument8LoadFileEP7__sFILE13TiXmlEncoding, 893376)
    off(_ZN13TiXmlDocument8SetErrorEiPKcP16TiXmlParsingData13TiXmlEncoding, 905872)
    off(_ZN13TiXmlDocument8LoadFileEPKc13TiXmlEncoding, 893968)
    off(_ZNK13TiXmlDocument8SaveFileEP7__sFILE, 894320)
    off(_ZNK13TiXmlDocument8SaveFileEPKc, 894416)
    off(_ZNK13TiXmlDocument6CopyToEPS_, 894624)
    off(_ZN13TiXmlDocumentC2ERKS_, 894736)
    off(_ZN13TiXmlDocumentC1ERKS_, 894736)
    off(_ZN13TiXmlDocumentaSERKS_, 894848)
    off(_ZNK13TiXmlDocument5CloneEv, 894896)
    off(_ZNK13TiXmlDocument5PrintEP7__sFILEi, 894976)
    off(_ZNK13TiXmlDocument9StreamOutEP14TiXmlOutStream, 895056)
    off(_ZNK14TiXmlAttribute4NextEv, 895136)
    off(_ZNK12TiXmlElement5PrintEP7__sFILEi, 895168)
    off(_ZNK12TiXmlElement9StreamOutEP14TiXmlOutStream, 895648)
    off(_ZN14TiXmlAttribute4NextEv, 895952)
    off(_ZNK14TiXmlAttribute8PreviousEv, 895984)
    off(_ZN14TiXmlAttribute8PreviousEv, 896016)
    off(_ZNK14TiXmlAttribute5PrintEP7__sFILEi, 896064)
    off(_ZNK14TiXmlAttribute9StreamOutEP14TiXmlOutStream, 896448)
    off(_ZNK14TiXmlAttribute13QueryIntValueEPi, 896752)
    off(_ZNK14TiXmlAttribute16QueryDoubleValueEPd, 896800)
    off(_ZN14TiXmlAttribute11SetIntValueEi, 896848)
    off(_ZN14TiXmlAttribute14SetDoubleValueEd, 897008)
    off(_ZNK14TiXmlAttribute8IntValueEv, 897184)
    off(_ZNK14TiXmlAttribute11DoubleValueEv, 897200)
    off(_ZNK12TiXmlComment6CopyToEPS_, 897216)
    off(_ZN12TiXmlCommentC2ERKS_, 897232)
    off(_ZN12TiXmlCommentC1ERKS_, 897232)
    off(_ZN12TiXmlCommentaSERKS_, 897312)
    off(_ZNK12TiXmlComment5CloneEv, 897360)
    off(_ZNK9TiXmlText6CopyToEPS_, 897456)
    off(_ZNK9TiXmlText5CloneEv, 897504)
    off(_ZN16TiXmlDeclarationC2EPKcS1_S1_, 897632)
    off(_ZN16TiXmlDeclarationC1EPKcS1_S1_, 897632)
    off(_ZNK16TiXmlDeclaration6CopyToEPS_, 897856)
    off(_ZN16TiXmlDeclarationC2ERKS_, 897952)
    off(_ZN16TiXmlDeclarationC1ERKS_, 897952)
    off(_ZN16TiXmlDeclarationaSERKS_, 898112)
    off(_ZNK16TiXmlDeclaration5CloneEv, 898160)
    off(_ZNK12TiXmlUnknown6CopyToEPS_, 898272)
    off(_ZNK12TiXmlUnknown5CloneEv, 898288)
    off(_ZN17TiXmlAttributeSetC2Ev, 898384)
    off(_ZN17TiXmlAttributeSetC1Ev, 898384)
    off(_ZN17TiXmlAttributeSetD2Ev, 898464)
    off(_ZN17TiXmlAttributeSetD1Ev, 898464)
    off(_ZN12TiXmlElementC2EPKc, 898560)
    off(_ZN17TiXmlAttributeSet3AddEP14TiXmlAttribute, 898688)
    off(_ZN17TiXmlAttributeSet6RemoveEP14TiXmlAttribute, 898720)
    off(_ZN12TiXmlElement9ClearThisEv, 898800)
    off(_ZN12TiXmlElementD2Ev, 898880)
    off(_ZN12TiXmlElementD1Ev, 898880)
    off(_ZN12TiXmlElementD0Ev, 898928)
    off(_ZNK17TiXmlAttributeSet4FindERK11TiXmlString, 898960)
    off(_ZNK12TiXmlElement9AttributeEPKcPi, 899376)
    off(_ZNK12TiXmlElement9AttributeEPKcPd, 899456)
    off(_ZN17TiXmlAttributeSet4FindERK11TiXmlString, 900144)
    off(_ZN12TiXmlElement15RemoveAttributeEPKc, 900256)
    off(_ZNK12TiXmlElement6CopyToEPS_, 901504)
    off(_ZN12TiXmlElementC2ERKS_, 901680)
    off(_ZN12TiXmlElementC1ERKS_, 901680)
    off(_ZN12TiXmlElementaSERKS_, 901792)
    off(_ZNK12TiXmlElement5CloneEv, 901840)
    off(_ZNK11TiXmlHandle10FirstChildEv, 901952)
    off(_ZNK11TiXmlHandle10FirstChildEPKc, 901984)
    off(_ZNK11TiXmlHandle17FirstChildElementEv, 902048)
    off(_ZNK11TiXmlHandle17FirstChildElementEPKc, 902096)
    off(_ZNK11TiXmlHandle5ChildEi, 902160)
    off(_ZNK11TiXmlHandle5ChildEPKci, 902224)
    off(_ZNK11TiXmlHandle12ChildElementEi, 902336)
    off(_ZNK11TiXmlHandle12ChildElementEPKci, 902432)
    off(_ZN12TiXmlElement5ParseEPKcP16TiXmlParsingData13TiXmlEncoding, 910384)
    off(_ZN12TiXmlComment5ParseEPKcP16TiXmlParsingData13TiXmlEncoding, 907952)
    off(_ZN9TiXmlText5ParseEPKcP16TiXmlParsingData13TiXmlEncoding, 908160)
    off(_ZN16TiXmlDeclaration5ParseEPKcP16TiXmlParsingData13TiXmlEncoding, 908672)
    off(_ZN12TiXmlUnknown5ParseEPKcP16TiXmlParsingData13TiXmlEncoding, 907616)
    off(_ZNK13TiXmlDocument10ToDocumentEv, 902544)
    off(_ZN13TiXmlDocument10ToDocumentEv, 902560)
    off(_ZN14TiXmlAttributeD2Ev, 902576)
    off(_ZN14TiXmlAttributeD1Ev, 902576)
    off(_ZN13TiXmlDocumentD2Ev, 902672)
    off(_ZN13TiXmlDocumentD1Ev, 902672)
    off(_ZN13TiXmlDocumentD0Ev, 902736)
    off(_ZN14TiXmlAttributeD0Ev, 902800)
    off(_ZN9TiXmlBase18ConvertUTF32ToUTF8EmPcPi, 902896)
    off(_ZN9TiXmlBase7IsAlphaEh13TiXmlEncoding, 903184)
    off(_ZN9TiXmlBase10IsAlphaNumEh13TiXmlEncoding, 903216)
    off(_ZN16TiXmlParsingData5StampEPKc13TiXmlEncoding, 903248)
    off(_ZN9TiXmlBase14SkipWhiteSpaceEPKc13TiXmlEncoding, 903568)
    off(_ZN9TiXmlBase8ReadNameEPKcP11TiXmlString13TiXmlEncoding, 903792)
    off(_ZN9TiXmlBase9GetEntityEPKcPcPi13TiXmlEncoding, 904016)
    off(_ZN9TiXmlBase11StringEqualEPKcS1_b13TiXmlEncoding, 904672)
    off(_ZN9TiXmlBase8ReadTextEPKcP11TiXmlStringbS1_b13TiXmlEncoding, 904896)
    off(_ZN14TiXmlAttribute5ParseEPKcP16TiXmlParsingData13TiXmlEncoding, 906000)
    off(_ZN9TiXmlNode8IdentifyEPKc13TiXmlEncoding, 906496)
    off(_ZN13TiXmlDocument5ParseEPKcP16TiXmlParsingData13TiXmlEncoding, 907056)
    off(_ZNK9TiXmlText5BlankEv, 909792)
    off(_ZN12TiXmlElement9ReadValueEPKcP16TiXmlParsingData13TiXmlEncoding, 909920)
    off(_ZNK9hgeVector5AngleEPKS_, 945232)
    off(_ZN7ecImageD2Ev, 945600)
    off(_ZN7ecImage4InitEP9ecTextureffff, 945616)
    off(_ZN7ecImageC2EP9ecTextureffff, 945840)
    off(_ZN7ecImageC2EP9ecTextureRK13ecTextureRect, 945856)
    off(_ZN7ecImageC2EP11ecImageAttr, 945936)
    off(_ZN7ecImage13RenderStretchEffff, 947152)
    off(_ZN7ecImage8Render4VEffffffff, 947312)
    off(_ZN7ecImage10SetTextureEP9ecTexture, 948688)
    off(_ZN7ecImage7SetFlipEbbb, 949072)
    off(_ZN7ecImage14SetTextureRectEffff, 949440)
    off(_ZN7ecImage14SetTextureRectERK13ecTextureRect, 949600)
    off(_ZN12ecTextureResC2Ev, 949744)
    off(_ZN12ecTextureRes14ReleaseTextureEP9ecTexture, 949824)
    off(_ZN12ecTextureResD2Ev, 950464)
    off(_ZN12ecTextureRes10GetTextureEPKc, 951408)
    off(_ZN12ecTextureRes13CreateTextureEPKcbbb, 952320)
    off(_ZN12ecTextureRes11CreateImageEPKcP9ecTextureffffff, 954320)
    off(_ZN12ecTextureRes11CreateImageEPKcS1_ffffff, 956656)
    off(_ZN11ecEffectResC2Ev, 958032)
    off(_ZN11ecEffectResC1Ev, 958032)
    off(_ZN11ecEffectRes7ReleaseEv, 958080)
    off(_ZN11ecEffectResD2Ev, 958192)
    off(_ZN11ecEffectResD1Ev, 958192)
    off(_ZN11ecEffectRes10LoadEffectEPKcP12ecTextureRes, 958208)
    off(_ZN18ecEffectResManager16ReleaseEffectResEP11ecEffectRes, 962080)
    off(_ZN18ecEffectResManagerC2Ev, 962544)
    off(_ZN18ecEffectResManagerC1Ev, 962544)
    off(_ZN18ecEffectResManagerD2Ev, 962784)
    off(_ZN18ecEffectResManagerD1Ev, 962784)
    off(_ZN18ecEffectResManager16ReleaseEffectResEPKc, 963568)
    off(_ZN8ecEffectC2Ev, 965872)
    off(_ZN8ecEffectC1Ev, 965872)
    off(_ZN8ecEffectD2Ev, 965920)
    off(_ZN8ecEffect4InitEPKcP9TFreeListI16ecParticleSystemE, 966048)
    off(_ZN16ecParticleSystem4InitEP13ecEmitterAttr, 978048)
    off(_ZN16ecParticleSystem6FireAtEfff, 978480)
    off(_ZN8ecEffect4FireEv, 966320)
    off(_ZN16ecParticleSystem4FireEv, 978176)
    off(_ZN8ecEffect4StopEb, 966368)
    off(_ZN16ecParticleSystem4StopEb, 978192)
    off(_ZN8ecEffect6MoveToEffb, 966448)
    off(_ZN16ecParticleSystem6MoveToEffb, 978240)
    off(_ZN16ecParticleSystem6UpdateEf, 978976)
    off(_ZN16ecParticleSystem6RenderEv, 978560)
    off(_ZN16ecParticleSystem6IsLiveEv, 982592)
    off(_ZN15ecEffectManagerC2Ev, 966784)
    off(_ZN16ecParticleSystemC1Ev, 977920)
    off(_ZN16ecParticleSystemD1Ev, 978032)
    off(_ZN15ecEffectManagerC1Ev, 966784)
    off(_ZN15ecEffectManagerD2Ev, 967648)
    off(_ZN15ecEffectManagerD1Ev, 967648)
    off(_ZN9ecUniFontC2Ev, 968064)
    off(_ZN9ecUniFont12GetCharImageEt, 968128)
    off(_ZN9ecUniFontD2Ev, 968576)
    off(_ZN11ecLabelTextC2Ev, 970784)
    off(_ZN11ecLabelTextD2Ev, 970816)
    off(_ZN11ecLabelText8SetAlphaEf, 971360)
    off(_ZN10CCSoundBoxC2Ev, 971536)
    off(_ZN10CCSoundBoxC1Ev, 971536)
    off(_ZN10CCSoundBoxD2Ev, 971568)
    off(_ZN10CCSoundBoxD1Ev, 971568)
    off(_ZN10CCSoundBox15InitSoundSystemEv, 971696)
    off(_ZN10CCSoundBox18DestroySoundSystemEv, 971808)
    off(_ZN10CCSoundBox9StopMusicEv, 971952)
    off(_ZN10CCSoundBox9StopAllSEEv, 972096)
    off(_ZN13ecStringTableC2Ev, 972128)
    off(_ZN13ecStringTableD2Ev, 973312)
    off(_ZN6ecTextC2Ev, 976144)
    off(_ZN6ecTextD2Ev, 976176)
    off(_ZN6ecText11GetNumLinesEv, 977072)
    off(_Z22ecSetIdleTimerDisabledb, 977888)
    off(_ZN16ecParticleSystemC2Ev, 977920)
    off(_ZN16ecParticleSystemD2Ev, 978032)
    off(_ZN9ecLibraryC2Ev, 1279504)
    off(_ZN9ecLibrary11GetItemDataEi, 1279584)
    off(_ZN9ecLibrary12FindItemDataEPKc, 1279632)
    off(_ZN9ecLibrary14GetElementDataEi, 1280016)
    off(_ZN9ecLibrary12GetFrameDataEi, 1280064)
    off(_ZN9ecLibrary12GetLayerDataEi, 1280080)
    off(_ZN9ecLibrary11GetItemNameEj, 1280096)
    off(_ZN9ecLibraryD2Ev, 1280320)
    off(_ZN7ecShapeD1Ev, 1287952)
    off(_ZN9ecLibraryD1Ev, 1280320)
    off(_ZN9ecLibraryD0Ev, 1280688)
    off(_Z13ecLoadLibraryPKcR13ecLibraryData, 1283040)
    off(_ZN7ecShapeC1Ev, 1287936)
    off(_ZN7ecShape4InitEP9ecTextureffff, 1287968)
    off(_Z14ecSaveLibrarayPKcR13ecLibraryDataS0_i, 1283856)
    off(_ZN9ecElementC2Ev, 1284416)
    off(_ZN9ecElementD2Ev, 1284480)
    off(_ZN9ecElement4InitEP10ecItemDataP9ecLibrary, 1284800)
    off(_ZN7ecLayerC1Ev, 1288592)
    off(_ZN7ecFrameC1Ev, 1289520)
    off(_ZN7ecLayer4InitEiP11ecLayerDataP7ecFrameP9ecElementP9ecLibrary, 1288896)
    off(_ZN7ecLayer11SetCurFrameEi, 1289104)
    off(_ZN9ecElement5ResetEv, 1285744)
    off(_ZN7ecLayer4PlayEv, 1288736)
    off(_ZN9ecElement4StopEv, 1285952)
    off(_ZN7ecLayer4StopEv, 1288800)
    off(_ZN7ecLayer7SetLoopEi, 1288864)
    off(_ZN9ecElement4InitEP13ecElementDataP9ecLibrary, 1286192)
    off(_ZN9ecElement9ResetItemEP10ecItemDataP9ecLibrary, 1286304)
    off(_ZN9ecElement10ChangeItemEP10ecItemDataS1_P9ecLibrary, 1286720)
    off(_ZN7ecLayer10ChangeItemEP10ecItemDataS1_P9ecLibrary, 1288608)
    off(_ZN9ecElement10ChangeItemEPKcS1_P9ecLibrary, 1286864)
    off(_ZN7ecShape8SetColorEj, 1288512)
    off(_ZN7ecShape6RenderERK7ecMtx32, 1288144)
    off(_ZN7ecLayer6RenderERK7ecMtx32, 1289216)
    off(_ZN9ecElement9NextFrameEv, 1287616)
    off(_ZN7ecLayer9NextFrameEv, 1289264)
    off(_ZN7ecShapeC2Ev, 1287936)
    off(_ZN7ecShapeD2Ev, 1287952)
    off(_ZN7ecLayerD2Ev, 1288544)
    off(_ZN7ecLayerD1Ev, 1288544)
    off(_ZN7ecLayerD0Ev, 1288560)
    off(_ZN7ecLayerC2Ev, 1288592)
    off(_ZN7ecFrame10ChangeItemEP10ecItemDataS1_P9ecLibrary, 1289728)
    off(_ZN7ecFrame4PlayEv, 1290016)
    off(_ZN7ecFrame4StopEv, 1290080)
    off(_ZN7ecFrame4InitEP11ecFrameDataP9ecElementP9ecLibrary, 1289536)
    off(_ZN7ecFrame6RenderERK7ecMtx32, 1289856)
    off(_ZN7ecFrame9NextFrameEv, 1289952)
    off(_ZN7ecFrame5ResetEv, 1289664)
    off(_ZN7ecFrameD2Ev, 1289472)
    off(_ZN7ecFrameD1Ev, 1289472)
    off(_ZN7ecFrameD0Ev, 1289488)
    off(_ZN7ecFrameC2Ev, 1289520)
}

plt(_ZN7_JNIEnv16CallObjectMethodEP8_jobjectP10_jmethodIDz)

plt(_ZN7_JNIEnv23CallStaticBooleanMethodEP7_jclassP10_jmethodIDz)

plt(_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz)

plt(_ZN7_JNIEnv21CallStaticFloatMethodEP7_jclassP10_jmethodIDz)

plt(_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz)

plt(_Z24ecGameDidEnterBackgroundv)

plt(_Z14ecGameShutdownv)

plt(_Z7GetPathPKcS0_)

plt(_Z18ecPurchasedProducti)

plt(_Z10ecGameInitiiiii)

plt(_Z18ecSetInAppPurchasePFviE)

plt(_Z11ecGamePausev)

plt(_Z25ecGameWillEnterForegroundv)

plt(_Z12ecGameResumev)

plt(_Z13ecBackPressedv)

plt(_ZN13CStateManager8InstanceEv)

plt(_ZN13CStateManager11GetStatePtrE6EState)

plt(_ZN10CMenuState8ShowExitEv)

plt(_Z12ecGameUpdatef)

plt(_Z12ecGameRenderv)

plt(_ZN10ecGraphics8InstanceEv)

plt(_ZN15ecMultipleTouch8InstanceEv)

plt(_ZN15ecMultipleTouch10TouchBeganEff)

plt(_Z12ecTouchBeginffi)

plt(_ZN15ecMultipleTouch5ResetEv)

plt(_ZN15ecMultipleTouch10TouchMovedEff)

plt(_Z11ecTouchMoveffi)

plt(_ZN15ecMultipleTouch10TouchEndedEff)

plt(_Z10ecTouchEndffi)

plt(_ZN10CCommander8BuyMedalEi)

plt(_ZN10CCommander4SaveEv)

plt(_Z17ecSetProductPriceiPKc)

plt(_ZN6ecFileC1Ev)

plt(_ZN6ecFile11IsFlieExistEPKc)

plt(_ZN6ecFileD1Ev)

plt(_Z9Get2XPathPKcS0_)

plt(_Z15GetDocumentPathPKc)

plt(_Z16GetEditorResPathPKc)

plt(_ZN10ecGraphicsC2Ev)

plt(_ZN10ecGraphicsC1Ev)

plt(_ZN10ecGraphics4InitEiiiii)

plt(_ZN10ecGraphics8ShutdownEv)

plt(_ZN10ecGraphics14SetOrientationEi)

plt(_ZN10ecGraphics11RenderBeginEv)

plt(_ZN10ecGraphics13CreateTextureEii)

plt(_ZN10ecGraphics11FreeTextureEP9ecTexture)

plt(_ZN10ecGraphics5FlushEv)

plt(_ZN10ecGraphics9RenderEndEv)

plt(_ZN10ecGraphics12SetViewPointEfff)

plt(_ZN10ecGraphics12SetBlendModeEi)

plt(_ZN10ecGraphics11BindTextureEP9ecTexture)

plt(_ZN10ecGraphics23CreateTextureWithStringEPKcS1_iiii)

plt(_Z19ecTextureWithStringPKcS0_iiRiS1_Rj)

plt(_ZN10ecGraphics10RenderLineEPK6ecLine)

plt(_ZN10ecGraphics12RenderTripleEPK8ecTriple)

plt(_ZN10ecGraphics10RenderQuadEPK6ecQuad)

plt(_ZN10ecGraphics10RenderRectEffffm)

plt(_ZN10ecGraphics12RenderCircleEfffj)

plt(_ZN10ecGraphics4FadeEf)

plt(_ZN10ecGraphicsD2Ev)

plt(_ZN10ecGraphicsD1Ev)

plt(_ZN10ecGraphics11LoadTextureEPKc)

plt(_Z13ecTextureLoadPKcRiS1_Rj)

plt(_ZN10ecGraphics15LoadWEBPTextureEPKc)

plt(_Z17ecWEBPTextureLoadPKcRiS1_Rj)

plt(_ZN10ecGraphics14LoadPVRTextureEPKc)

plt(_Z16ecPVRTextureLoadPKcRiS1_Rj)

plt(_ZN10ecGraphics14LoadETCTextureEPKc)

plt(_Z16ecETCTextureLoadPKcRiS1_Rj)

plt(_ZN15ecMultipleTouchD2Ev)

plt(_ZN15ecMultipleTouchD1Ev)

plt(_ZN15ecMultipleTouchC2Ev)

plt(_ZN15ecMultipleTouchC1Ev)

plt(_ZN6ecFileC2Ev)

plt(_ZN3MD5C1Ev)

plt(_ZN6ecFile5CloseEv)

plt(_ZN6ecFileD2Ev)

plt(_ZN6ecFile4OpenEPKcS1_)

plt(_ZN6ecFile4ReadEPvj)

plt(_ZN6ecFile5WriteEPKvj)

plt(_ZN6ecFile4SeekEli)

plt(_ZN6ecFile9GetCurPosEv)

plt(_ZN6ecFile7GetSizeEv)

plt(_ZN6ecFile12CheckJavaDexEv)

plt(_ZN6ecFile18GetFileDataFromZipEPKcS1_Pm)

plt(_ZN3MD55resetEv)

plt(_ZN3MD56updateEPKvm)

plt(_ZN3MD58toStringEv)

plt(_ZN8CheckMD5C1Ev)

plt(_ZN8CheckMD56INfileEPKcS1_)

plt(_ZN6ecFile21CheckFileExistFromZipEPKcS1_)

plt(_ZN3MD5C2Ev)

plt(_ZN3MD56encodeEPKmPhm)

plt(_ZN3MD56decodeEPKhPmm)

plt(_ZN3MD59transformEPKh)

plt(_ZN3MD56updateEPKhm)

plt(_ZN3MD5C2EPKvm)

plt(_ZN3MD5C1EPKvm)

plt(_ZN3MD56updateERSt14basic_ifstreamIcSt11char_traitsIcEE)

plt(_ZN3MD5C2ERSt14basic_ifstreamIcSt11char_traitsIcEE)

plt(_ZN3MD5C1ERSt14basic_ifstreamIcSt11char_traitsIcEE)

plt(_ZN3MD56updateERKSs)

plt(_ZN3MD5C2ERKSs)

plt(_ZN3MD5C1ERKSs)

plt(_ZN3MD55finalEv)

plt(_ZN3MD56digestEv)

plt(_ZN3MD516bytesToHexStringEPKhm)

plt(_ZN8CheckMD5C2Ev)

plt(_ZN10CCommanderD2Ev)

plt(_ZN10CCommanderD1Ev)

plt(_Z19GetCommanderAbilityi)

plt(_ZN10CCommanderC2Ev)

plt(_ZN10CCommanderC1Ev)

plt(_ZN10CCommander4LoadEv)

plt(_ZN10CCommander15GetUpgradeMedalEv)

plt(_ZN10CCommander12CheckUpgardeEv)

plt(_ZN10CCommander7UpgradeEv)

plt(_ZN10CCommander10IsMaxLevelEv)

plt(_ZN10CCSoundBox11GetInstanceEv)

plt(_ZN10CCSoundBox6PlaySEEPKc)

plt(_ZN10CCommander16GetWarMedalLevelE11WARMEDAL_ID)

plt(_ZN10CCommander19GetNeedUpgradeMedalE11WARMEDAL_ID)

plt(_ZN10CCommander20CheckUpgradeWarMedalE11WARMEDAL_ID)

plt(_ZN10CCommander15UpgradeWarMedalE11WARMEDAL_ID)

plt(_ZN10CCommander20SetNumPlayedBatttlesEii)

plt(_ZN10CCommander20GetNumPlayedBatttlesEi)

plt(_ZN10CCommander15SetBattlePlayedEii)

plt(_ZN10CCommander17GetNumBattleStarsEii)

plt(_ZN10CCommander17SetNumBattleStarsEiii)

plt(_ZN10CCommander16GetCommanderDataER13CommanderData)

plt(_ZN14CPlayerManager7ReleaseEv)

plt(_ZN9ecUniFont7ReleaseEv)

plt(_ZN10CCSoundBox8UnloadSEEPKc)

plt(_ZN13CStateManager4TermEv)

plt(_ZN10GUIManager8InstanceEv)

plt(_ZN10GUIElement12FreeAllChildEv)

plt(_ZN10GUIManager16ReleaseTexureResEv)

plt(_ZN10CCSoundBox7DestroyEv)

plt(_ZN10CObjectDef8InstanceEv)

plt(_ZN10CObjectDef7DestroyEv)

plt(_ZN13ecStringTable5ClearEv)

plt(_Z13ecGameWaitingb)

plt(_ZN13CStateManager15EnterBackgroundEv)

plt(_ZN10CCSoundBox14SetMusicVolumeEi)

plt(_ZN10CCSoundBox11SetSEVolumeEi)

plt(_ZN10CCSoundBox11ResumeMusicEv)

plt(_ZN13CStateManager15EnterForegroundEv)

plt(_ZN14CPlayerManager6UpdateEf)

plt(_ZN13CStateManager6UpdateEf)

plt(_ZN10GUIManager6UpdateEf)

plt(_ZN16GUIMotionManager8InstanceEv)

plt(_ZN16GUIMotionManager10ProcMotionEv)

plt(_ZN10CCSoundBox11UpdateSoundEv)

plt(_ZN13CStateManager6RenderEv)

plt(_ZN10GUIManager6RenderEv)

plt(_ZN10GUIManager9PostEventERK5Event)

plt(_ZN13CStateManager10TouchBeginEffi)

plt(_ZN13CStateManager9TouchMoveEffi)

plt(_ZN13CStateManager8TouchEndEffi)

plt(_ZN13CStateManager11BackPressedEv)

plt(_Z15ecAccelerometerfff)

plt(_Z13ecScrollWheelfff)

plt(_ZN13CStateManager11ScrollWheelEfff)

plt(_Z9ecKeyDowni)

plt(_ZN13CStateManager7KeyDownEi)

plt(_Z18ecSetShowReviewFucPFvvE)

plt(_Z12ecShowReviewv)

plt(_Z17ecGetProductPricei)

plt(_Z15ecInAppPurchasei)

plt(_Z18ecAppWillTerminatev)

plt(_Z22ecApplicationTerminatev)

plt(_Z14ecLoadSettingsv)

plt(_ZN13CGameSettings12LoadSettingsEv)

plt(_Z14ecIsFullScreenv)

plt(_Z15ecSetFullScreenb)

plt(_ZN13CGameSettings12SaveSettingsEv)

plt(_Z13SetAIRandSeedi)

plt(_Z11SetRandSeedi)

plt(_ZN10GUIManager4InitERK7GUIRect)

plt(_ZN13CStateManager4InitEv)

plt(_ZN10CLogoStateC1Ev)

plt(_ZN10CMenuStateC1Ev)

plt(_ZN11CMatchStateC1Ev)

plt(_ZN10CLoadStateC1Ev)

plt(_ZN10CGameStateC1Ev)

plt(_ZN10CEditStateC1Ev)

plt(_ZN13CStateManager13RegisterStateEP10CBaseState)

plt(_ZN13CStateManager11SetCurStateE6EState)

plt(_ZN13ecStringTable4LoadEPKc)

plt(_ZN13ecStringTable9GetStringEPKc)

plt(_ZN10CObjectDef4InitEv)

plt(_ZN10CCSoundBox6LoadSEEPKc)

plt(_ZN9ecUniFont4InitEPKcb)

plt(_ZN10CBaseState7OnEnterEv)

plt(_ZN10CBaseState6OnExitEv)

plt(_ZN10CBaseState10TouchBeginEffi)

plt(_ZN10CBaseState9TouchMoveEffi)

plt(_ZN10CBaseState8TouchEndEffi)

plt(_ZN10CBaseState11BackPressedEv)

plt(_ZN10CBaseState7KeyDownEi)

plt(_ZN10CBaseState11ScrollWheelEfff)

plt(_ZN10CBaseState15EnterBackgroundEv)

plt(_ZN10CBaseState15EnterForegroundEv)

plt(_ZN10CEditState7KeyDownEi)

plt(_ZN10CEditState7OnEventERK5Event)

Thn(N10CEditState7OnEventERK5Event, 16)

plt(_ZN10CEditStateD2Ev)

plt(_ZN13CTouchInertiaD1Ev)

plt(_ZN10CEditStateD1Ev)

Thn(N10CEditStateD1Ev, 16)

plt(_ZN10CEditStateD0Ev)

Thn(N10CEditStateD0Ev, 16)

plt(_ZN10CEditState6UpdateEf)

plt(_ZN13CTouchInertia6UpdateEf)

plt(_ZN13CTouchInertia8GetSpeedERfS0_)

plt(_ZN15ecEffectManager8InstanceEv)

plt(_ZN15ecEffectManager6UpdateEf)

plt(_ZN6CScene6UpdateEf)

plt(_ZN6CScene4MoveEii)

plt(_ZN13CTouchInertia4StopEv)

plt(_ZN7CCamera13SetAutoFixPosEb)

plt(_ZN10CEditState6RenderEv)

plt(_ZN6CScene6RenderEv)

plt(_ZN6CScene14RenderAreasTaxEv)

plt(_ZN6CScene15RenderAreasTypeEv)

plt(_ZN10CEditState10TouchBeginEffi)

plt(_ZN13CTouchInertia10TouchBeginEffi)

plt(_ZN10CEditState9TouchMoveEffi)

plt(_ZN13CTouchInertia9TouchMoveEffi)

plt(_ZN10CEditState8TouchEndEffi)

plt(_ZN13CTouchInertia8TouchEndEffi)

plt(_ZN6CScene12ScreenToAreaEff)

plt(_ZN6CScene15GetSelectedAreaEv)

plt(_ZN6CScene12UnselectAreaEv)

plt(_ZN6CScene10SelectAreaEP5CArea)

plt(_ZN10CEditStateC2Ev)

plt(_ZN13CTouchInertiaC1Ev)

plt(_ZN10CEditState8InitGameEv)

plt(_ZN12CGameManager7NewGameEiiii)

plt(_ZN9CSoundRes4LoadEv)

plt(_ZN8CGameRes4LoadEv)

plt(_ZN6CScene4InitEPKci)

plt(_ZN13CTouchInertia4InitEv)

plt(_ZN10CEditState7OnEnterEv)

plt(_ZN10GUIManager6FadeInEi)

plt(_ZN10CEditState11ReleaseGameEv)

plt(_ZN6CScene7ReleaseEv)

plt(_ZN8CGameRes7ReleaseEv)

plt(_ZN9CSoundRes6UnloadEv)

plt(_ZN10CEditState6OnExitEv)

plt(_ZN16GUIMotionManager11ClearMotionEv)

plt(_ZN9CActionAID2Ev)

plt(_ZN9CActionAI18setActionNodeClearEv)

plt(_ZN9CActionAID1Ev)

plt(_Z11GetRandSeedv)

plt(_Z7GetRandv)

plt(_ZN6CFightC2Ev)

plt(_ZN6CFightC1Ev)

plt(_ZN6CFightD2Ev)

plt(_ZN6CFightD1Ev)

plt(_ZN6CFight16AirStrikesAttackEP8CCountryii)

plt(_ZN6CScene7GetAreaEi)

plt(_ZN8CCountry16GetWarMedalLevelE11WARMEDAL_ID)

plt(_ZN10CObjectDef10GetArmyDefEiPKc)

plt(_ZN6CFight16AirStrikesAttackEii)

plt(_ZN6CFight17GetAttackerResultEi)

plt(_ZN6CFight17GetDefenderResultEi)

plt(_ZN6CFight12GetAttackAddEi)

plt(_ZN6CFight12GetDefendAddEi)

plt(_ZN6CFight11ApplyResultEv)

plt(_ZN5CArea7GetArmyEi)

plt(_ZN5CArea16LostArmyStrengthEii)

plt(_ZN6CScene25AdjacentAreasEncirclementEi)

plt(_ZN8CCountry10AddDestroyEi)

plt(_ZN5CArea23ReduceConstructionLevelEv)

plt(_ZN5CArmy6IsNavyEv)

plt(_ZN15ecEffectManager9AddEffectEPKcb)

plt(_ZN8ecEffect6FireAtEfff)

plt(_ZN13CFightTextMgr7AddTextEffPKcj)

plt(_ZN9CSoundRes10PlayCharSEE10SND_EFFECT)

plt(_ZN5CArmy6AddExpEi)

plt(_Z9GetAIRandv)

plt(_ZN8CCountry13IsLocalPlayerEv)

plt(_ZN6CScene9GainMedalEff)

plt(_ZN5CArea19DestroyConstructionEv)

plt(_ZN5CArea12ClearAllArmyEv)

plt(_ZN5CArmy12BreakthroughEv)

plt(_ZN5CArea10OccupyAreaEPS_)

plt(_ZN6CFight12NormalAttackEii)

plt(_ZN5CArmy11GetNumDicesEv)

plt(_ZN8CCountry17GetCommanderLevelEv)

plt(_Z14GetArmyAbilityi)

plt(_ZN5CArmy25GetNumDicesIfLostStrengthEi)

plt(_ZN6CFight11FirstAttackEii)

plt(_ZN6CFight12SecondAttackEv)

plt(_ZN10CFightTextC2Ev)

plt(_ZN6ecTextC1Ev)

plt(_ZN10CFightTextC1Ev)

plt(_ZN10CFightTextD2Ev)

plt(_ZN6ecTextD1Ev)

plt(_ZN10CFightTextD1Ev)

plt(_ZN13CFightTextMgrD2Ev)

plt(_ZN9ecUniFontD1Ev)

plt(_ZN13CFightTextMgrD1Ev)

plt(_ZN10CFightText4InitEffP9ecUniFont)

plt(_ZN6ecText4InitEP9ecUniFont)

plt(_ZN10CFightText7SetTextEPKc)

plt(_ZN6ecText7SetTextEPKc)

plt(_ZN10CFightText8SetColorEj)

plt(_ZN6ecText8SetColorEj)

plt(_ZN10CFightText6UpdateEf)

plt(_ZN6ecText8SetAlphaEf)

plt(_ZN10CFightText6RenderEv)

plt(_ZN6ecText8DrawTextEffi)

plt(_ZN13CFightTextMgrC2Ev)

plt(_ZN9ecUniFontC1Ev)

plt(_ZN13CFightTextMgrC1Ev)

plt(_ZN13CFightTextMgr4InitEv)

plt(_ZN13CFightTextMgr7ReleaseEv)

plt(_ZN13CFightTextMgr6UpdateEf)

plt(_ZN13CFightTextMgr6RenderEv)

plt(_ZN13CActionAssistD2Ev)

plt(_ZN13CActionAssistD1Ev)

plt(_ZN12CGameManagerD2Ev)

plt(_ZN12CGameManagerD1Ev)

plt(_Z13GetNumBattlesi)

plt(_Z16GetBattleKeyNameiiPc)

plt(_Z18GetConquestKeyNameiPc)

plt(_Z17GetBattleFileNameiiiiPc)

plt(_Z24GetNumMultiPlayerBattlesi)

plt(_Z24GetBattleBelligerentListPKcRSt4listI11BelligerentSaIS2_EEb)

plt(_ZN13TiXmlDocumentC1EPKc)

plt(_ZN13TiXmlDocument8LoadFileE13TiXmlEncoding)

plt(_ZN9TiXmlNodeD2Ev)

plt(_ZN9TiXmlNode10FirstChildEPKc)

plt(_ZNK12TiXmlElement9AttributeEPKc)

plt(_ZNK12TiXmlElement17QueryIntAttributeEPKcPi)

plt(_ZN12CGameManagerC2Ev)

plt(_ZN12CGameManagerC1Ev)

plt(_ZN12CGameManager4InitEv)

plt(_ZN12CGameManager20SetPlayercountrynameEiPKc)

plt(_ZN12CGameManager11GetPlayerNoEPKc)

plt(_ZN12CGameManager20GetPlayerCountryNameEi)

plt(_ZN12CGameManager26SetConquestPlayerCountryIDEPKc)

plt(_ZN10CObjectDef12GetBattleDefEPKc)

plt(_ZN12CGameManager8LoadGameEPKc)

plt(_ZN12CGameManager9RetryGameEv)

plt(_ZN12CGameManager8SaveGameEPKc)

plt(_ZN8CCountry11SaveCountryEP15SaveCountryInfo)

plt(_ZN5CArea8SaveAeraEP12SaveAreaInfo)

plt(_ZN12CGameManager13GetSaveHeaderEPKcR10SaveHeader)

plt(_ZN12CGameManager11ClearBattleEv)

plt(_ZN8CCountryD1Ev)

plt(_ZN12CGameManager7ReleaseEv)

plt(_ZN12CGameManager10NextBattleEv)

plt(_ZN12CGameManager12IsLastBattleEv)

plt(_ZN12CGameManager15GetNumCountriesEv)

plt(_ZN12CGameManager17GetCountryByIndexEi)

plt(_ZN12CGameManager11FindCountryEPKc)

plt(_ZN12CGameManager13GetCurCountryEv)

plt(_ZN12CGameManager13InitCameraPosEv)

plt(_ZN8CCountry19GetHighestValueAreaEv)

plt(_ZN6CScene15SetCameraToAreaEi)

plt(_ZN12CGameManager16GetPlayerCountryEv)

plt(_ZN12CGameManager21GetLocalPlayerCountryEv)

plt(_ZN12CGameManager15GetNumDialoguesEv)

plt(_ZN12CGameManager18GetDialogueByIndexEi)

plt(_ZN12CGameManager10SaveBattleEPKc)

plt(_ZN12TiXmlElementC1EPKc)

plt(_ZN12TiXmlElement12SetAttributeEPKci)

plt(_ZN12TiXmlElement12SetAttributeEPKcS1_)

plt(_ZN12TiXmlElement18SetDoubleAttributeEPKcd)

plt(_ZN9TiXmlNode12LinkEndChildEPS_)

plt(_ZN8CCountry16GetCommanderNameEv)

plt(_ZN6CScene11GetNumAreasEv)

plt(_ZNK13TiXmlDocument8SaveFileEv)

plt(_ZN12CGameManager14GetCurDialogueEv)

plt(_ZN12CGameManager20GetCurDialogueStringEPc)

plt(_ZN12CGameManager12NextDialogueEv)

plt(_ZN12CGameManager18GetNumVictoryStarsEv)

plt(_ZN12CGameManager17CheckAndSetResultEv)

plt(_ZN8CCountry12IsConquestedEv)

plt(_ZN12CGameManager13BattleVictoryEv)

plt(_ZN12CGameManager21GetNewDefeatedCountryEv)

plt(_ZN12CGameManager12IsManipulateEv)

plt(_ZN8CCountry14IsActionFinishEv)

plt(_ZN12CGameManager9TurnBeginEv)

plt(_ZN8CCountry9TurnBeginEv)

plt(_ZN10CGameState16UpdateActionInfoEv)

plt(_ZN10CGameState18PlayerCountryBeginEv)

plt(_ZN8CCountry6ActionERK13CountryAction)

plt(_ZN12CGameManager7TurnEndEv)

plt(_ZN8CCountry7TurnEndEv)

plt(_ZN12CGameManager7EndTurnEv)

plt(_ZN10CGameState12ShowDialogueEPKcS1_b)

plt(_ZN10CGameState14HideAIProgressEv)

plt(_ZN12CGameManager4NextEv)

plt(_ZN9CActionAI16setCpuDriverbyIdEii)

plt(_ZN14CPlayerManager13DoFrontActionEv)

plt(_ZN5CArea13SetArmyActiveEib)

plt(_ZN12CGameManager10GameUpdateEf)

plt(_ZN8CCountry6UpdateEf)

plt(_ZN10CGameState12ShowDefeatedEP8CCountry)

plt(_ZN10CGameState16UpdateAIProgressEv)

plt(_ZN12CGameManager24MovePlayerCountryToFrontEv)

plt(_ZN12CGameManager12RealLoadGameEPKc)

plt(_ZN8CCountryC1Ev)

plt(_ZN8CCountry4InitEPKcS1_)

plt(_ZN8CCountry11LoadCountryEPK15SaveCountryInfo)

plt(_ZN7CCamera6SetPosEffb)

plt(_ZN5CArea8LoadAreaEPK12SaveAreaInfo)

plt(_ZN8CCountry7AddAreaEi)

plt(_ZN12CGameManager10LoadBattleEPKc)

plt(_ZNK12TiXmlElement20QueryDoubleAttributeEPKcPd)

plt(_ZN8CCountry12SetCommanderEPKc)

plt(_ZN14CPlayerManager21FindPlayerByCountryIDEPKc)

plt(_ZN6CScene14SetAreaCountryEiP8CCountry)

plt(_ZN5CArea15SetConstructionEii)

plt(_ZN5CArmyC1Ev)

plt(_ZN5CArmy4InitEP7ArmyDefP8CCountry)

plt(_ZN5CArea7AddArmyEP5CArmyb)

plt(_ZN5CArmy16ResetMaxStrengthEb)

plt(_ZN12CGameManager10InitBattleEv)

plt(_ZN6CScene20AllAreasEncirclementEv)

plt(_ZN14CPlayerManager18SetPlayerOfCountryEv)

plt(_ZN8CGameRes14RenderArmyInfoEiffiiiii)

plt(_ZN7ecImage6RenderEff)

plt(_ZN7ecImage8SetColorEmi)

plt(_ZN7ecImage8RenderExEfffff)

plt(_ZN8CGameRes20RenderCommanderMedalEiffi)

plt(_ZN8CGameRes12RenderArmyHPEffii)

plt(_ZN8CGameRes15RenderArmyLevelEffi)

plt(_ZN8CGameRes21RenderArmyMovementNumEffi)

plt(_ZN8CGameRes18RenderConstructionEiiff)

plt(_ZN8CGameRes10RenderPortEff)

plt(_ZN8CGameRes18RenderInstallationEiff)

plt(_ZN8CGameRes11GetBattleBGEPKc)

plt(_ZN12ecTextureRes8GetImageEPKc)

plt(_ZN8CGameRes12GetFlagImageEPKc)

plt(_ZN8CGameResC2Ev)

plt(_ZN12ecTextureResC1Ev)

plt(_ZN12ecTextureResD1Ev)

plt(_ZN8CGameResC1Ev)

plt(_ZN8CGameResD2Ev)

plt(_ZN8CGameResD1Ev)

plt(_ZN15ecEffectManager9RemoveAllEv)

plt(_ZN18ecEffectResManager8InstanceEv)

plt(_ZN18ecEffectResManager19ReleaseAllEffectResEv)

plt(_ZN18ecEffectResManager17ReleaseTextureResEv)

plt(_ZN7ecImageD1Ev)

plt(_ZN12ecTextureRes7ReleaseEv)

plt(_ZN8CGameRes12GetArmyImageEPKcib)

plt(_ZN8CGameRes10RenderArmyEPKciiffimbf)

plt(_ZN8CGameRes12RenderUIArmyEPKcffibiiiii)

plt(_ZN8CGameRes22RenderAICommanderMedalEiffPKci)

plt(_ZN8CGameRes18RenderUIAttackArmyEPKcffiiiiiiib)

plt(_ZN8CGameRes18RenderUIDefendArmyEPKcffiiiiiiib)

plt(_ZN8CGameRes10RenderFlagEPKcff)

plt(_ZN12ecTextureRes7LoadResEPKcb)

plt(_ZN7ecImageC1EP11ecImageAttr)

plt(_ZN7ecImageC1EP9ecTextureffff)

plt(_ZN18ecEffectResManager14LoadTextureResEPKc)

plt(_ZN18ecEffectResManager13LoadEffectResEPKc)

plt(_ZN13CGameSettingsD2Ev)

plt(_ZN13CGameSettingsD1Ev)

plt(_ZN13CGameSettingsC2Ev)

plt(_ZN13CGameSettingsC1Ev)

plt(_ZN10CGameStateD2Ev)

plt(_ZN10CGameStateD1Ev)

Thn(N10CGameStateD1Ev, 16)

plt(_ZN10CGameStateD0Ev)

Thn(N10CGameStateD0Ev, 16)

plt(_ZN10CGameState6RenderEv)

plt(_ZN15ecEffectManager6RenderEv)

plt(_ZN10CGameState8TouchEndEffi)

plt(_ZN10GUIBuyCard10GetSelCardEv)

plt(_ZN8CCountry19CheckCardTargetAreaEP7CardDefi)

plt(_ZN6GUITax7SetAreaEi)

plt(_ZN5CArea8IsActiveEv)

plt(_ZN10GUIElement4HideEv)

plt(_ZN10GUIElement4ShowEv)

plt(_ZN6CScene13CheckMoveableEiii)

plt(_ZN14CPlayerManager22SendPacketToAllPlayersE9PACKET_IDPKvi)

plt(_ZN10GUISelArmy7SetAreaEi)

plt(_ZN6CScene15CheckAttackableEiii)

plt(_ZN12GUIAttackBox9SetAttackEii)

plt(_ZN10CGameState9TouchMoveEffi)

plt(_ZN6CScene13ScreenToSceneERfS0_)

plt(_ZN7CCamera14SetPosAndScaleEfff)

plt(_ZN10CGameState11ScrollWheelEfff)

plt(_ZN10CGameState15EnterBackgroundEv)

plt(_ZN10CGameStateC2Ev)

plt(_ZN10CGameState8InitGameEv)

plt(_ZN10GUIManager14LoadTextureResEPKcb)

plt(_ZN10CGameState11ReleaseGameEv)

plt(_ZN10GUIManager16UnloadTextureResEPKc)

plt(_ZN10CGameState6OnExitEv)

plt(_ZN10CCSoundBox11UnloadMusicEv)

plt(_ZN14CPlayerManager4StopEv)

plt(_ZN10GUIElement11MoveToFrontEPS_)

plt(_ZN11GUIDefeated12ShowDefeatedEP8CCountry)

plt(_ZN13GUIAIProgress17SetCurCountryNameEPKc)

plt(_ZN10CGameState7OnEnterEv)

plt(_ZN10GUIManager9AddButtonEPKcS1_RK7GUIRectP10GUIElementP9ecUniFont)

plt(_ZN9GUIButton13SetBackgroundEPKc)

plt(_ZN7GUIGoldC1Ev)

plt(_ZN7GUIGold4InitERK7GUIRect)

plt(_ZN10GUIElement8AddChildEPS_b)

plt(_ZN6GUITaxC1Ev)

plt(_ZN6GUITax4InitERK7GUIRect)

plt(_ZN12GUISmallCardC1Ev)

plt(_ZN12GUISmallCard4InitERK7GUIRect)

plt(_ZN12GUIAttackBoxC1Ev)

plt(_ZN12GUIAttackBox4InitERK7GUIRect)

plt(_ZN10GUIElement6CenterEv)

plt(_ZN11GUIPauseBoxC1Ev)

plt(_ZN11GUIPauseBox4InitERK7GUIRect)

plt(_ZN10GUIBuyCardC1Ev)

plt(_ZN10GUIBuyCard4InitERK7GUIRect)

plt(_ZN13GUIAIProgressC1Ev)

plt(_ZN13GUIAIProgress4InitERK7GUIRect)

plt(_ZN10GUISelArmyC1Ev)

plt(_ZN10GUISelArmy4InitERK7GUIRect)

plt(_ZN8GUIBeginC1Ev)

plt(_ZN8GUIBegin4InitERK7GUIRect)

plt(_ZN11GUIDefeatedC1Ev)

plt(_ZN11GUIDefeated4InitERK7GUIRect)

plt(_ZN9GUIBattleC1Ev)

plt(_ZN9GUIBattle4InitERK7GUIRect)

plt(_ZN11GUIDialogueC1Ev)

plt(_ZN11GUIDialogue4InitERK7GUIRect)

plt(_ZN16GUIMotionManager9AddMotionEP10GUIElementffft)

plt(_ZN10CCSoundBox9LoadMusicEPKcS1_)

plt(_ZN10CCSoundBox9PlayMusicEb)

plt(_ZN12GUITutorailsC1Ev)

plt(_ZN12GUITutorails4InitERK7GUIRect)

plt(_ZN13GUIActionInfoC1Ev)

plt(_ZN13GUIActionInfo4InitERK7GUIRect)

plt(_ZN10CGameState15EnableIdleTimerEf)

plt(_ZN10CGameState12StartBattaleEiiib)

plt(_ZN9GUIBattle11BattleStartEiii)

plt(_ZN8GUIBegin9ResetDataEv)

plt(_ZN10CGameState10SelectAreaEi)

plt(_ZN6CScene10SelectAreaEi)

plt(_ZN10CGameState12UnselectAreaEv)

plt(_ZN11GUIDialogue7ShowDlgEPKcS1_b)

plt(_ZN10CGameState11ShowWarningEi)

plt(_ZN10GUIWarningC1Ev)

plt(_ZN10GUIWarning4InitERK7GUIRecti)

plt(_ZN10CGameState6UpdateEf)

plt(_ZN6CScene9IsBombingEv)

plt(_ZN10GUIBuyCard13CanBuySelCardEv)

plt(_ZN10GUIBuyCard13ReleaseTargetEv)

plt(_ZN10GUIBuyCard15ResetCardTargetEv)

plt(_ZN14CPlayerManager13GetNumActionsEv)

plt(_ZN14CPlayerManager22IsDisconnectedFromHostEv)

plt(_ZN13GUIActionInfo7SetInfoEPKc)

plt(_ZN10CGameState15ResetTouchStateEv)

plt(_ZN10CGameState11BackPressedEv)

plt(_ZN10GUIManager7FadeOutEiP10GUIElement)

plt(_ZN10CGameState10TouchBeginEffi)

plt(_ZN10CGameState7OnEventERK5Event)

plt(_ZN10GUIVictoryC1Ev)

plt(_ZN10GUIVictory4InitERK7GUIRectb)

plt(_ZN10GUIVictory4PlayEv)

plt(_ZN16GUIMotionManager12ActiveMotionEjh)

plt(_ZN14CPlayerManager18SendPacketToServerE9PACKET_IDPKvi)

plt(_ZN10GUIManager13SafeFreeChildEP10GUIElement)

plt(_ZN6GUIEndC1Ev)

plt(_ZN6GUIEnd4InitERK7GUIRect)

plt(_ZN10GUIBuyCard14ResetCardStateEv)

plt(_ZN10GUIOptionsC1Ev)

plt(_ZN10GUIOptions4InitERK7GUIRect)

plt(_ZN7GUISaveC1Ev)

plt(_ZN7GUISave4InitERK7GUIRectib)

plt(_ZN12GUISmallCard7SetCardEP7CardDef)

plt(_ZN14GUIBattleIntroC1Ev)

plt(_ZN14GUIBattleIntro4InitERK7GUIRectii)

plt(_ZN11GUIDefeated12HideDefeatedEv)

plt(_ZN9GUIResultC1Ev)

plt(_ZN9GUIResult4InitERK7GUIRecti)

plt(_ZN14CPlayerManager16PlayerLoadFinishEP7CPlayer)

plt(_ZN7GUIBankC1Ev)

plt(_ZN7GUIBank4InitERK7GUIRect)

plt(_ZN6GUIIapC1Ev)

plt(_ZN6GUIIap4InitERK7GUIRect)

Thn(N10CGameState7OnEventERK5Event, 16)

plt(_ZN13ecStringTableC1Ev)

plt(_ZN13ecStringTableD1Ev)

plt(_ZN13GUIActionInfo8OnUpdateEf)

plt(_ZN13GUIActionInfoD2Ev)

plt(_ZN11ecLabelTextD1Ev)

plt(_ZN10GUIElementD2Ev)

plt(_ZN13GUIActionInfoD1Ev)

plt(_ZN13GUIActionInfoD0Ev)

plt(_ZN13GUIActionInfo8OnRenderEv)

plt(_ZN10GUIElement10GetAbsRectER7GUIRect)

plt(_ZN11ecLabelText8DrawTextEff)

plt(_ZN13GUIActionInfoC2Ev)

plt(_ZN10GUIElementC2Ev)

plt(_ZN11ecLabelTextC1Ev)

plt(_ZN11ecLabelText4InitEPKciiii)

plt(_ZN11ecLabelText7SetTextEPKc)

plt(_ZN10GUIElement7OnEventERK5Event)

plt(_ZN13GUIAIProgressD2Ev)

plt(_ZN13GUIAIProgressD1Ev)

plt(_ZN13GUIAIProgressD0Ev)

plt(_ZN13GUIAIProgress8OnRenderEv)

plt(_ZN13GUIAIProgressC2Ev)

plt(_ZN7ecImage4InitEP11ecImageAttr)

plt(_ZN10GUIElement8OnUpdateEf)

plt(_ZN12GUIAttackBoxD2Ev)

plt(_ZN12GUIAttackBoxD1Ev)

plt(_ZN12GUIAttackBoxD0Ev)

plt(_ZN12GUIAttackBox8OnRenderEv)

plt(_ZN5CArmy14GetMaxStrengthEv)

plt(_ZN12GUIAttackBoxC2Ev)

plt(_ZN11GUIButtonExC1Ev)

plt(_ZN9GUIButton4InitEPKcS1_RK7GUIRectP9ecUniFont)

plt(_ZN11GUIButtonEx12SetImageTextEPKcS1_)

plt(_ZN12GUIAttackBox7OnEventERK5Event)

plt(_ZN7GUIBank8OnUpdateEf)

plt(_ZN7GUIBankD2Ev)

plt(_ZN7GUIBankD1Ev)

plt(_ZN7GUIBankD0Ev)

plt(_ZN7GUIBank8OnRenderEv)

plt(_ZN7ecImage6RenderEffff)

plt(_ZN7GUIBankC2Ev)

plt(_ZN9GUIButtonC1Ev)

plt(_ZN8GUIMedalC1Ev)

plt(_ZN8GUIMedal4InitERK7GUIRect)

plt(_ZN10GUIManager8AddImageEPKcRK7GUIRectP10GUIElement)

plt(_ZN7GUIBank7OnEventERK5Event)

plt(_ZN9GUIBattleD2Ev)

plt(_ZN12CBattleSceneD1Ev)

plt(_ZN9GUIBattleD1Ev)

plt(_ZN9GUIBattleD0Ev)

plt(_ZN9GUIBattle8OnRenderEv)

plt(_ZN12CBattleScene6RenderEv)

plt(_ZN9GUIBattleC2Ev)

plt(_ZN12CBattleSceneC1Ev)

plt(_ZN12CBattleScene4InitEiPS_)

plt(_ZN9GUIBattle11ResetBattleEv)

plt(_ZN12CBattleScene13SetBattleAreaEi)

plt(_ZN9GUIBattle12BattleFinishEv)

plt(_ZN9GUIBattle13UpateFightingEf)

plt(_ZN12CBattleScene6AttackEv)

plt(_ZN12CBattleScene11IsAttackingEv)

plt(_ZN12CBattleScene12DestroyUnitsEi)

plt(_ZN9GUIBattle8OnUpdateEf)

plt(_ZN12CBattleScene6UpdateEf)

plt(_ZN12CBattleScene12ClearCratersEv)

plt(_ZN12CBattleScene12ClearEffectsEv)

plt(_ZN9GUIBattle7OnEventERK5Event)

plt(_ZN14GUIBattleIntroD2Ev)

plt(_ZN14GUIBattleIntroD1Ev)

plt(_ZN14GUIBattleIntroD0Ev)

plt(_ZN14GUIBattleIntro8OnRenderEv)

plt(_ZN14GUIBattleIntroC2Ev)

plt(_ZN14GUIBattleIntro9SetBattleEii)

plt(_ZN14GUIBattleIntro7OnEventERK5Event)

plt(_ZN8GUIBeginD2Ev)

plt(_ZN8GUIBeginD1Ev)

plt(_ZN8GUIBeginD0Ev)

plt(_ZN8GUIBegin8OnRenderEv)

plt(_ZN8GUIBeginC2Ev)

plt(_ZN7GUITechC1Ev)

plt(_ZN7GUITech4InitERK7GUIRect)

plt(_ZN8CCountry8GetTaxesEv)

plt(_ZN8CCountry12GetIndustrysEv)

plt(_ZN8GUIBegin7OnEventERK5Event)

plt(_ZN11GUIButtonExD2Ev)

plt(_ZN9GUIButtonD2Ev)

plt(_ZN11GUIButtonExD1Ev)

plt(_ZN11GUIButtonExD0Ev)

plt(_ZN11GUIButtonExC2Ev)

plt(_ZN9GUIButtonC2Ev)

plt(_ZN11GUIButtonEx8OnRenderEv)

plt(_ZN9GUIButton8OnRenderEv)

plt(_ZN9GUIButton7OnEventERK5Event)

plt(_ZN10GUICardTabD2Ev)

plt(_ZN10GUICardTabD1Ev)

plt(_ZN10GUICardTabD0Ev)

plt(_ZN10GUIBuyCardD2Ev)

plt(_ZN10GUIBuyCardD1Ev)

plt(_ZN10GUIBuyCardD0Ev)

plt(_ZN10GUIBuyCard8OnRenderEv)

plt(_ZN10GUICardTabC2Ev)

plt(_ZN10GUICardTabC1Ev)

plt(_ZN10GUICardTab19GetCardTabButtonIdxEPK10GUIElement)

plt(_ZN10GUICardTab9SelectTabEi)

plt(_ZN10GUIElement6GetPosERfS0_)

plt(_ZN10GUIElement6SetPosEff)

plt(_ZN10GUICardTab4InitERK7GUIRect)

plt(_ZN14GUIRadioButtonC1Ev)

plt(_ZN10GUIManager8AddImageEPKcRK13ecTextureRectRK7GUIRectP10GUIElementb)

plt(_ZN10GUIBuyCardC2Ev)

plt(_ZN11GUICardListC1Ev)

plt(_ZN11GUICardList4InitERK7GUIRecti)

plt(_ZN7ecImageC1EP9ecTextureRK13ecTextureRect)

plt(_ZN10GUIBuyCard15SetSelCardIntroEv)

plt(_ZN10CObjectDef10GetCardDefE7CARD_ID)

plt(_ZN8CCountry10CanBuyCardEP7CardDef)

plt(_ZN7GUICard13SetPriceColorEj)

plt(_ZN8CCountry16IsEnoughIndustryEP7CardDef)

plt(_ZN7GUICard16SetIndustryColorEj)

plt(_ZN8CCountry12GetCardPriceEP7CardDef)

plt(_ZN8CCountry15GetCardIndustryEP7CardDef)

plt(_ZN11GUICardList7GetCardEi)

plt(_ZN8CCountry13IsEnoughMoneyEP7CardDef)

plt(_ZN8CCountry13GetCardRoundsE7CARD_ID)

plt(_ZN10GUIElement9SetEnableEb)

plt(_ZN7GUICard8SetPriceEi)

plt(_ZN7GUICard11SetIndustryEi)

plt(_ZN8CCountry15CanUseCommanderEv)

plt(_ZN10GUIBuyCard7SelCardEii)

plt(_ZN6CScene12ClearTargetsEv)

plt(_ZN8CCountry14SetCardTargetsEP7CardDef)

plt(_ZN6CScene11ResetTargetEv)

plt(_ZN10GUICardTab7OnEventERK5Event)

plt(_ZN10GUIBuyCard7OnEventERK5Event)

plt(_ZN10CObjectDef17GetCardTargetTypeEP7CardDef)

plt(_ZN10GUIElement8OnRenderEv)

plt(_ZN7GUICardD2Ev)

plt(_ZN7GUICardD1Ev)

plt(_ZN7GUICardD0Ev)

plt(_ZN7GUICard8OnRenderEv)

plt(_ZN11GUICardListD2Ev)

plt(_ZN11GUICardListD1Ev)

plt(_ZN11GUICardListD0Ev)

plt(_ZN11GUICardList8OnUpdateEf)

plt(_ZN7GUICardC2Ev)

plt(_ZN7GUICardC1Ev)

plt(_ZN7GUICard4InitEP7CardDefRK7GUIRect)

plt(_ZN11GUICardListC2Ev)

plt(_ZN11GUICardList11ResetSelectEv)

plt(_ZN11GUICardList10GelSelItemEff)

plt(_ZN10GUIElement11CheckInRectEff)

plt(_ZN7GUICard7OnEventERK5Event)

plt(_ZN11GUICardList9SetSelectEi)

plt(_ZN11GUICardList8ReSelectEv)

plt(_ZN11GUICardList7OnEventERK5Event)

plt(_ZN11GUIDefeated8OnRenderEv)

plt(_ZN11GUIDefeatedC2Ev)

plt(_ZN10CObjectDef15GetGeneralPhotoEPKc)

plt(_ZN11GUIDefeatedD2Ev)

plt(_ZN11GUIDefeatedD1Ev)

plt(_ZN11GUIDefeatedD0Ev)

plt(_ZN11GUIDefeated8OnUpdateEf)

plt(_ZN11GUIDefeated7OnEventERK5Event)

plt(_ZN11GUIDialogue8OnUpdateEf)

plt(_ZN11GUIDialogueD2Ev)

plt(_ZN11GUIDialogueD1Ev)

plt(_ZN11GUIDialogueD0Ev)

plt(_ZN11GUIDialogue8OnRenderEv)

plt(_ZN11GUIDialogueC2Ev)

plt(_ZN11GUIDialogue7HideDlgEv)

plt(_ZN11GUIDialogue7OnEventERK5Event)

plt(_ZN6GUIEndD2Ev)

plt(_ZN6GUIEndD1Ev)

plt(_ZN6GUIEndD0Ev)

plt(_ZN6GUIEnd8OnRenderEv)

plt(_ZN6GUIEndC2Ev)

plt(_ZN6GUIEnd7OnEventERK5Event)

plt(_ZN7GUIGoldD2Ev)

plt(_ZN7GUIGoldD1Ev)

plt(_ZN7GUIGoldD0Ev)

plt(_ZN7GUIGold8OnRenderEv)

plt(_ZN7GUIGoldC2Ev)

plt(_ZN7GUIGold8SetMoneyEi)

plt(_ZN7GUIGold11SetIndustryEi)

plt(_ZN7GUIGold8OnUpdateEf)

plt(_ZN15GUIProductPrice8OnRenderEv)

plt(_ZN6GUIIapD2Ev)

plt(_ZN6GUIIapD1Ev)

plt(_ZN6GUIIapD0Ev)

plt(_ZN6GUIIap7OnEventERK5Event)

plt(_ZN15GUIProductPriceD2Ev)

plt(_ZN15GUIProductPriceD1Ev)

plt(_ZN15GUIProductPriceD0Ev)

plt(_ZN6GUIIap8OnRenderEv)

plt(_ZN15GUIProductPriceC2Ev)

plt(_ZN15GUIProductPriceC1Ev)

plt(_ZN15GUIProductPrice4InitERK7GUIRect)

plt(_ZN11ecLabelText8SetColorEj)

plt(_ZN15GUIProductPrice14SetLocalePirceEPKc)

plt(_ZN6GUIIapC2Ev)

plt(_ZN9GUIButton7SetTextEPKc)

plt(_ZN9GUIButton12SetTextColorEj)

plt(_ZN6GUIIap14SetLocalePirceEiPKc)

plt(_ZN6GUIIap14OnListCompleteEPv)

plt(_ZN6GUIIap15SetProductPriceEv)

plt(_ZN8GUIMedalD2Ev)

plt(_ZN8GUIMedalD1Ev)

plt(_ZN8GUIMedalD0Ev)

plt(_ZN8GUIMedal8OnRenderEv)

plt(_ZN8GUIMedalC2Ev)

plt(_ZN8GUIMedal8SetMedalEi)

plt(_ZN8GUIMedal8OnUpdateEf)

plt(_ZN8GUIMedal7OnEventERK5Event)

plt(_ZN10GUIOptionsD2Ev)

plt(_ZN10GUIOptionsD1Ev)

plt(_ZN10GUIOptionsD0Ev)

plt(_ZN10GUIOptions8OnRenderEv)

plt(_ZN10GUIOptionsC2Ev)

plt(_ZN10GUIManager12AddScrollBarERK7GUIRectP10GUIElementPKcS6_iiiii)

plt(_ZN11GUILevelSelC1Ev)

plt(_ZN11GUILevelSel4InitERK7GUIRecti)

plt(_ZN12GUIScrollBar12SetScrollPosEi)

plt(_ZN10GUIOptions7OnEventERK5Event)

plt(_ZN12GUIScrollBar12GetScrollPosEv)

plt(_ZN11GUIPauseBoxD2Ev)

plt(_ZN11GUIPauseBoxD1Ev)

plt(_ZN11GUIPauseBoxD0Ev)

plt(_ZN11GUIPauseBox8OnRenderEv)

plt(_ZN11GUIPauseBoxC2Ev)

plt(_ZN11GUIPauseBox7OnEventERK5Event)

plt(_ZN9GUIResult8OnUpdateEf)

plt(_ZN9GUIResultD2Ev)

plt(_ZN9GUIResultD1Ev)

plt(_ZN9GUIResultD0Ev)

plt(_ZN9GUIResult8OnRenderEv)

plt(_ZN9GUIResultC2Ev)

plt(_ZN13GUIAdornMedalC1Ev)

plt(_ZN13GUIAdornMedal4InitER7GUIRect)

plt(_ZN9GUIResult7OnEventERK5Event)

plt(_ZN11GUISaveItemD2Ev)

plt(_ZN14GUIRadioButtonD2Ev)

plt(_ZN11GUISaveItemD1Ev)

plt(_ZN11GUISaveItemD0Ev)

plt(_ZN7GUISave8OnRenderEv)

plt(_ZN11GUISaveItem8OnRenderEv)

plt(_ZN7GUISaveD2Ev)

plt(_ZN12ecTextureRes9UnloadResEPKc)

plt(_ZN7GUISaveD1Ev)

plt(_ZN7GUISaveD0Ev)

plt(_ZN11GUISaveItem8OnUpdateEf)

plt(_ZN11GUISaveItemC2Ev)

plt(_ZN14GUIRadioButtonC2Ev)

plt(_ZN11GUISaveItemC1Ev)

plt(_ZN11GUISaveItem4InitERK7GUIRectPKc)

plt(_ZN11GUISaveItem7SetInfoEPKciiiiiiiib)

plt(_ZN7GUISaveC2Ev)

plt(_ZN7GUISave7SelItemEi)

plt(_ZN7GUISave7OnEventERK5Event)

plt(_ZN11GUIArmyItemD2Ev)

plt(_ZN11GUIArmyItemD1Ev)

plt(_ZN11GUIArmyItemD0Ev)

plt(_ZN11GUIArmyItem8OnRenderEv)

plt(_ZN10GUISelArmyD2Ev)

plt(_ZN10GUISelArmyD1Ev)

plt(_ZN10GUISelArmyD0Ev)

plt(_ZN10GUISelArmy8OnRenderEv)

plt(_ZN11GUIArmyItemC2Ev)

plt(_ZN11GUIArmyItemC1Ev)

plt(_ZN10GUISelArmyC2Ev)

plt(_ZN7ecImage8SetAlphaEfi)

plt(_ZN10GUISelArmy15MoveArmyToFrontEi)

plt(_ZN5CArea15MoveArmyToFrontEib)

plt(_ZN10GUISelArmy10TargetArmyEi)

plt(_ZN10GUISelArmy7OnEventERK5Event)

plt(_ZN12GUISmallCardD2Ev)

plt(_ZN12GUISmallCardD1Ev)

plt(_ZN12GUISmallCardD0Ev)

plt(_ZN12GUISmallCard8OnRenderEv)

plt(_ZN12GUISmallCardC2Ev)

plt(_ZN6GUITaxD2Ev)

plt(_ZN6GUITaxD1Ev)

plt(_ZN6GUITaxD0Ev)

plt(_ZN6GUITax8OnRenderEv)

plt(_ZN6GUITaxC2Ev)

plt(_ZN6GUITax8SetMoneyEi)

plt(_ZN6GUITax11SetIndustryEi)

plt(_ZN5CArea10GetRealTaxEv)

plt(_ZN5CArea11GetIndustryEv)

plt(_ZN5CArea11HasArmyCardEi)

plt(_ZN7GUITechD2Ev)

plt(_ZN7GUITechD1Ev)

plt(_ZN7GUITechD0Ev)

plt(_ZN7GUITech8OnRenderEv)

plt(_ZN7GUITech8OnUpdateEf)

plt(_ZN7GUITechC2Ev)

plt(_ZN12GUITutorails8OnRenderEv)

plt(_ZN12GUITutorailsC2Ev)

plt(_ZN12GUITutorails10LoadScriptEv)

plt(_ZN12GUITutorails13ReleaseScriptEv)

plt(_ZN12GUITutorailsD2Ev)

plt(_ZN12GUITutorailsD1Ev)

plt(_ZN12GUITutorailsD0Ev)

plt(_ZN12GUITutorails7ShowDlgEi)

plt(_ZN12GUITutorails7ShowDlgEPKc)

plt(_ZN12GUITutorails7HideDlgEv)

plt(_ZN12GUITutorails6ExeCmdEi)

plt(_ZN6CScene22MoveCameraCenterToAreaEi)

plt(_ZN6CScene16MoveCameraToAreaEi)

plt(_ZN12GUITutorails8OnUpdateEf)

plt(_ZN6CScene8IsMovingEv)

plt(_ZN12GUITutorails7OnEventERK5Event)

plt(_ZN10GUIVictoryD2Ev)

plt(_ZN10GUIVictoryD1Ev)

plt(_ZN10GUIVictoryD0Ev)

plt(_ZN10GUIVictory8OnRenderEv)

plt(_ZN10GUIVictory8OnUpdateEf)

plt(_ZN10GUIVictoryC2Ev)

plt(_ZN10GUIVictory7OnEventERK5Event)

plt(_ZN10GUIWarning8OnUpdateEf)

plt(_ZN10GUIWarningD2Ev)

plt(_ZN10GUIWarningD1Ev)

plt(_ZN10GUIWarningD0Ev)

plt(_ZN10GUIWarning8OnRenderEv)

plt(_ZN10GUIWarningC2Ev)

plt(_ZN10GUIWarning7OnEventERK5Event)

plt(_ZN10CLoadState10TouchBeginEffi)

plt(_ZN10CLoadState9TouchMoveEffi)

plt(_ZN10CLoadState8TouchEndEffi)

plt(_ZN10CLoadState11BackPressedEv)

plt(_ZN10CLoadStateD2Ev)

plt(_ZN10CLoadStateD1Ev)

Thn(N10CLoadStateD1Ev, 16)

plt(_ZN10CLoadStateD0Ev)

Thn(N10CLoadStateD0Ev, 16)

plt(_ZN10CLoadState7OnEnterEv)

plt(_ZN10CLoadState6OnExitEv)

plt(_ZN10CLoadState6RenderEv)

plt(_ZN10CLoadState6UpdateEf)

plt(_ZN10CLoadState7OnEventERK5Event)

Thn(N10CLoadState7OnEventERK5Event, 16)

plt(_ZN10CLoadStateC2Ev)

plt(_ZN10CLogoStateD2Ev)

plt(_ZN10CLogoStateD1Ev)

Thn(N10CLogoStateD1Ev, 16)

plt(_ZN10CLogoState15EnterForegroundEv)

plt(_ZN10CLogoStateD0Ev)

Thn(N10CLogoStateD0Ev, 16)

plt(_ZN10CLogoState7OnEnterEv)

plt(_ZN10CLogoState6OnExitEv)

plt(_ZN10CLogoState6RenderEv)

plt(_ZN10CLogoState7OnEventERK5Event)

Thn(N10CLogoState7OnEventERK5Event, 16)

plt(_ZN10CLogoState6UpdateEf)

plt(_ZN14CPlayerManager4InitEv)

plt(_ZN10CLogoStateC2Ev)

plt(_ZN11CMatchStateD2Ev)

plt(_ZN11CMatchStateD1Ev)

Thn(N11CMatchStateD1Ev, 16)

plt(_ZN11CMatchState6UpdateEf)

plt(_ZN11CMatchState6RenderEv)

plt(_ZN11CMatchState10TouchBeginEffi)

plt(_ZN11CMatchState9TouchMoveEffi)

plt(_ZN11CMatchState8TouchEndEffi)

plt(_ZN11CMatchStateD0Ev)

Thn(N11CMatchStateD0Ev, 16)

plt(_ZN11CMatchState7OnEnterEv)

plt(_ZN13GUIMatchSetupC1Ev)

plt(_ZN13GUIMatchSetup4InitERK7GUIRect)

plt(_ZN11CMatchState6OnExitEv)

plt(_ZN11CMatchStateC2Ev)

plt(_ZN11CMatchState18StartMultiplayGameEi)

plt(_ZN11CMatchState7OnEventERK5Event)

plt(_ZN14CPlayerManager17SendStartLoadGameEv)

Thn(N11CMatchState7OnEventERK5Event, 16)

plt(_ZN11CMatchState11ShowWarningEi)

plt(_ZN10CMenuStateD2Ev)

plt(_ZN10CMenuStateD1Ev)

Thn(N10CMenuStateD1Ev, 16)

plt(_ZN10CMenuState6UpdateEf)

plt(_ZN10CMenuState6RenderEv)

plt(_ZN10CMenuState10TouchBeginEffi)

plt(_ZN10CMenuState9TouchMoveEffi)

plt(_ZN10CMenuState8TouchEndEffi)

plt(_ZN10CMenuStateD0Ev)

Thn(N10CMenuStateD0Ev, 16)

plt(_ZN10CMenuState7OnEnterEv)

plt(_ZN11GUIMainMenuC1Ev)

plt(_ZN11GUIMainMenu4InitERK7GUIRect)

plt(_ZN12GUISelBattleC1Ev)

plt(_ZN12GUISelBattle4InitERK7GUIRectii)

plt(_ZN10CMenuState6OnExitEv)

plt(_ZN10CMenuStateC2Ev)

plt(_ZN10CMenuState13PeerConnectedEv)

plt(_ZN10CMenuState18StartMultiplayGameEi)

plt(_ZN10CMenuState7OnEventERK5Event)

plt(_ZN11GUIMainMenu13RefreshNewTipEv)

plt(_ZN10GUILoadingC1Ev)

plt(_ZN10GUILoading4InitERK7GUIRect)

plt(_ZN11GUIMainMenu6ShowADEv)

plt(_ZN14CPlayerManager12SetupSessionEb)

plt(_ZN16GUILockedWarningC1Ev)

plt(_ZN16GUILockedWarning4InitERK7GUIRect)

plt(_ZN12GUICommanderC1Ev)

plt(_ZN12GUICommander4InitERK7GUIRect)

plt(_ZN10GUIServiceC1Ev)

plt(_ZN10GUIService4InitERK7GUIRect)

plt(_ZN10GUIElement9FreeChildEPS_)

plt(_ZN11GUIHostList17ResetConnectStateEv)

plt(_ZN13GUISelCountryC1Ev)

plt(_ZN13GUISelCountry4InitERK7GUIRecti)

plt(_ZN14CPlayerManager9InitCorpsEi)

plt(_ZN14CPlayerManager14DestroySessionEv)

plt(_ZN11GUIHostListC1Ev)

plt(_ZN11GUIHostList4InitERK7GUIRect)

plt(_ZN10GUINewGameC1Ev)

plt(_ZN10GUINewGame4InitERK7GUIRect)

plt(_ZN14CPlayerManager10StartMatchEv)

plt(_ZN14CPlayerManager9StopMatchEv)

Thn(N10CMenuState7OnEventERK5Event, 16)

plt(_ZN10CMenuState11ShowWarningEi)

plt(_ZN14GUIExitWarningC1Ev)

plt(_ZN14GUIExitWarning4InitERK7GUIRect)

plt(_ZN10CObjectDefC2Ev)

plt(_ZN10CObjectDefC1Ev)

plt(_ZN10CObjectDef11LoadCardDefEv)

plt(_ZN10CObjectDef16GetUnitPositionsEPKc)

plt(_ZN10CObjectDef15GetCommanderDefEPKc)

plt(_ZN10CObjectDef14GetConquestDefEPKc)

plt(_ZN10CObjectDef14ReleaseArmyDefEv)

plt(_ZN10CObjectDef18ReleaseUnitMotionsEv)

plt(_ZN10CObjectDef20ReleaseUnitPositionsEv)

plt(_ZN10CObjectDef19ReleaseCommanderDefEv)

plt(_ZN10CObjectDef20ReleaseGeneralPhotosEv)

plt(_ZN10CObjectDef17ReleaseBattleListEv)

plt(_ZN10CObjectDefD2Ev)

plt(_ZN10CObjectDefD1Ev)

plt(_ZN10CObjectDef19ReleaseConquestListEv)

plt(_ZN10CObjectDef7ReleaseEv)

plt(_ZN10CObjectDef14GetUnitMotionsEPKcS1_)

plt(_ZN10CObjectDef11LoadArmyDefEv)

plt(_ZN10CObjectDef15LoadUnitMotionsEv)

plt(_ZN10CObjectDef16LoadUnitPositonsEv)

plt(_ZN10CObjectDef16LoadCommanderDefEv)

plt(_ZN10CObjectDef17LoadGeneralPhotosEv)

plt(_ZN10CObjectDef14LoadBattleListEv)

plt(_ZN10CObjectDef16LoadConquestListEv)

plt(_ZN14CPlayerManager14WillDisconnectEv)

plt(_ZN14CPlayerManager34onLocalPlayerAuthenticationChangedEv)

Thn(N14CPlayerManager34onLocalPlayerAuthenticationChangedEv, 8)

plt(_ZN14CPlayerManager20onFriendListReceivedEv)

Thn(N14CPlayerManager20onFriendListReceivedEv, 8)

plt(_ZN14CPlayerManager14onMatchRequestEv)

Thn(N14CPlayerManager14onMatchRequestEv, 8)

plt(_ZN14CPlayerManager17onPlayerConnectedEPKc)

Thn(N14CPlayerManager17onPlayerConnectedEPKc, 8)

plt(_ZN14CPlayerManager17InvitationDidFailEPKc)

plt(_ZN11GUIHostList13ConnectFailedEv)

plt(_ZN14CPlayerManager16SessionNoNetworkEv)

plt(_Z9ecGetUUIDRSs)

plt(_Z13ecGetUUIDHashv)

plt(_ZN9ecGameKitC1Ev)

plt(_ZN9ecGameKit4InitEP17ecGameKitDelegateb)

plt(_ZN14CPlayerManager15AnalyzePeerNameERKSsRSsRiS3_)

plt(_ZN14CPlayerManager7ConnectEPKci)

plt(_ZN18ecSessionInterface7ConnectEPKc)

plt(_ZN14CPlayerManager9ReconnectEv)

plt(_ZN18ecSessionInterface15GetPeerNameListERSt4listISsSaISsEES3_)

plt(_ZN14CPlayerManager13CancelConnectEv)

plt(_ZN18ecSessionInterface13CancelConnectEv)

plt(_ZN14CPlayerManager19onPeerListDidChangeEv)

plt(_ZN11GUIHostList15RefreshHostListEv)

plt(_ZN9ecGameKit25ShowMatchmakerWithRequestEiii)

plt(_ZN14CPlayerManager9AddPlayerEbPKc)

plt(_ZN7CPlayerC1Ev)

plt(_ZN7CPlayer4InitEbPKc)

plt(_ZN18ecSessionInterfaceC1Ev)

plt(_ZN18ecSessionInterface4InitEP17ecSessionDelegate)

plt(_ZN18ecSessionInterface12SetupSessionEb)

plt(_ZN18ecSessionInterface13GetDeviceNameERSs)

plt(_ZN14CPlayerManager18ClearRemotePlayersEv)

plt(_ZN7CPlayerD1Ev)

plt(_ZN14CPlayerManager12ClearPlayersEv)

plt(_ZN18ecSessionInterfaceD1Ev)

plt(_ZN9ecGameKitD1Ev)

plt(_ZN14CPlayerManagerD2Ev)

plt(_ZN14CPlayerManagerD1Ev)

plt(_ZN9ecGameKit22DisconnectCurrentMatchEv)

plt(_ZN14CPlayerManager16onAcceptedInviteEv)

Thn(N14CPlayerManager16onAcceptedInviteEv, 8)

plt(_ZN14CPlayerManager10FindPlayerEPKc)

plt(_ZN14CPlayerManager20onPlayerInfoReceivedERSt4listIP12ecPlayerInfoSaIS2_EE)

Thn(N14CPlayerManager20onPlayerInfoReceivedERSt4listIP12ecPlayerInfoSaIS2_EE, 8)

plt(_ZN14CPlayerManager12onMatchFoundEv)

plt(_ZN9ecGameKit18GetMatchPlayerListERSt4listISsSaISsEE)

Thn(N14CPlayerManager12onMatchFoundEv, 8)

plt(_ZN14CPlayerManager16FindPlayerByUUIDEi)

plt(_ZN14CPlayerManager17DidRecvInvitationEPKc)

plt(_ZN18ecSessionInterface11GetPeerNameEPKcRSs)

plt(_ZN18ecSessionInterface17DeclineInvitationEPKc)

plt(_ZN18ecSessionInterface16AcceptInvitationEPKc)

plt(_ZN14CPlayerManager21GetDisconnectedPlayerEv)

plt(_ZN14CPlayerManager18SendPacketToPlayerE12PacketHeaderPKviPKc)

plt(_ZN18ecSessionInterface10SendPacketEPKviPKc)

plt(_ZN9ecGameKit10SendPacketEPKviPKc)

plt(_ZN14CPlayerManager18SendPacketToPlayerE9PACKET_IDPKviP7CPlayer)

plt(_ZN14CPlayerManager28SendPacketToAllPlayersExceptE9PACKET_IDPKviP7CPlayer)

plt(_ZN7CPlayer10PushPacketE9PACKET_IDPKvi)

plt(_ZN7CPlayer10SendPacketE9PACKET_IDPKvi)

plt(_ZN14CPlayerManager10ClearCorpsEv)

plt(_ZN14CPlayerManager13WillTerminateEv)

plt(_ZN13GUIMatchSetup18RefreshCorsButtonsEv)

plt(_ZN11GUIHostList13ClearHostListEv)

plt(_ZN14CPlayerManager12GetLeftCorpsEi)

plt(_ZN14CPlayerManager13GetRightCorpsEi)

plt(_ZN14CPlayerManager15GetNumLeftCorpsEv)

plt(_ZN14CPlayerManager16GetNumRightCorpsEv)

plt(_ZN14CPlayerManager8SelCorpsEiiP7CPlayer)

plt(_ZN14CPlayerManager17RemoveCorpsPlayerEii)

plt(_ZN14CPlayerManager17RemoveCorpsPlayerEP7CPlayer)

plt(_ZN14CPlayerManager12RemovePlayerEP7CPlayer)

plt(_ZN14CPlayerManager20onPlayerDisconnectedEPKc)

Thn(N14CPlayerManager20onPlayerDisconnectedEPKc, 8)

plt(_ZN14CPlayerManager12GetCorpsDataERi)

plt(_ZN14CPlayerManager15onPeerConnectedEPKc)

plt(_ZN14CPlayerManager12onStartMatchEv)

plt(_ZN9ecGameKit18GetLocalPlayerInfoER12ecPlayerInfo)

plt(_ZN9ecGameKit19GetMatchPlayersInfoEv)

Thn(N14CPlayerManager12onStartMatchEv, 8)

plt(_ZN14CPlayerManager14SetCorpsByDataEPviP7CPlayer)

plt(_ZN14CPlayerManager17IsAllPlayersReadyEv)

plt(_ZN14CPlayerManager23RefreshAndSendCorpsDataEv)

plt(_ZN14CPlayerManager18onPeerDisconnectedEPKc)

plt(_ZN14CPlayerManager14SendRoundBeginEv)

plt(_ZN14CPlayerManager16ClearActionQueueEv)

plt(_ZN14CPlayerManager14onReceivedDataEPKviPKcb)

plt(_ZN7CPlayer7SendAckEi)

plt(_ZN7CPlayer7RecvAckEi)

plt(_ZN13GUIMatchSetup16CreatCorsButtonsEv)

plt(_ZN14CPlayerManager22onReveivedDataFromPeerEPKviPKc)

plt(_ZN14CPlayerManager24onReceivedDataFromPlayerEPKviPKc)

Thn(N14CPlayerManager24onReceivedDataFromPlayerEPKviPKc, 8)

plt(_ZN7CPlayer9SendFirstEv)

plt(_ZN14CPlayerManagerC2Ev)

plt(_ZN14CPlayerManagerC1Ev)

plt(_ZN6CSceneD2Ev)

plt(_ZN9CAreaMarkD1Ev)

plt(_ZN6CSceneD1Ev)

plt(_ZN6CSceneC2Ev)

plt(_ZN9CAreaMarkC1Ev)

plt(_ZN7CCameraC1Ev)

plt(_ZN6CSceneC1Ev)

plt(_ZN6CScene17CheckAdjacentDataEv)

plt(_ZN6CScene9NewAdjoinEv)

plt(_ZN6CScene10LoadAdjoinEi)

plt(_ZN6CScene10SaveAdjoinEi)

plt(_ZN6CScene10MakeAdjoinEii)

plt(_ZN6CScene9DelAdjoinEii)

plt(_ZN6CScene8IsAdjoinEii)

plt(_ZN6CScene12RenderAdjoinEv)

plt(_ZN6CScene17RenderAreasCenterEv)

plt(_ZN6CScene15RenderAreasArmyEv)

plt(_ZN6CScene16RenderAreasPointEv)

plt(_ZN6CScene12LoadAreaDataEi)

plt(_ZN6CScene12SaveAreaDataEi)

plt(_ZN6CScene14RenderSeaAreasEv)

plt(_ZN7CCamera14IsRectInCameraEffff)

plt(_ZN6CScene13RenderAreasIDEv)

plt(_ZN6CScene10ClearAreasEv)

plt(_ZN5CAreaD1Ev)

plt(_ZN7CBomberD1Ev)

plt(_ZN11CBackgroundD1Ev)

plt(_ZN9CAreaMark7ReleaseEv)

plt(_ZN6CScene11SaveAreaTaxEi)

plt(_ZN6CScene14LoadAreaEnableEPKc)

plt(_ZN6CScene14SaveAreaEnableEPKc)

plt(_ZN6CScene20AreaDisableOutofRectEiiii)

plt(_ZN6CScene13InitAreaImageEi)

plt(_ZN6CScene12CalSceneRectERfS0_S0_S0_)

plt(_ZN6CScene13IsRectInSecenEffff)

plt(_ZN7CCamera5UpateEf)

plt(_ZN7CBomber6UpdateEf)

plt(_ZN5CArea6UpdateEf)

plt(_ZN6CMedal5UpateEf)

plt(_ZN6CScene11CreateArrowEii)

plt(_Z7InvSqrtf)

plt(_ZN9hgeVector6RotateEf)

plt(_ZN6CScene14ScreenToAreaIDEff)

plt(_ZN9CAreaMark7GetMarkEii)

plt(_ZN7CCamera4MoveEffb)

plt(_ZN6CScene6MoveToEii)

plt(_ZN7CCamera6MoveToEffb)

plt(_ZN7CCamera21IsRectInVisibleRegionEffff)

plt(_ZN6CScene21MoveCameraBetweenAreaEii)

plt(_ZN6CScene25GetTwoAreasDistanceSquareEii)

plt(_ZN6CScene19GetTwoAreasDistanceEii)

plt(_ZN6CScene19GetNumAdjacentAreasEi)

plt(_ZN6CScene17GetAdjacentAreaIDEii)

plt(_ZN6CScene15GetAdjacentAreaEii)

plt(_ZN7CCamera5ApplyEv)

plt(_ZN11CBackground6RenderEP7CCamera)

plt(_ZN11CBackground9RenderBoxEP7CCameraffff)

plt(_ZN5CArea14RenderBuildingEv)

plt(_ZN5CArea6RenderEv)

plt(_ZN7ecImage9Render4VCEffffffffif)

plt(_ZN6CMedal6RenderEv)

plt(_ZN7CBomber6RenderEv)

plt(_ZN8CCountry15AirstrikeRadiusEv)

plt(_ZN6CScene13CheckAdjacentEii)

plt(_ZN5CArea11HasArmyCardEii)

plt(_ZN6CScene17SetSelAreaTargetsEP5CArea)

plt(_ZN5CArea12EncirclementEv)

plt(_ZN6CScene8AirborneEi)

plt(_ZN7CBomber8AirborneEi)

plt(_ZN6CScene19AircraftCarrierBombEii)

plt(_ZN7CBomber19AircraftCarrierBombEii)

plt(_ZN6CScene8BombAreaEii)

plt(_ZN7CBomber8BombAreaEii)

plt(_ZN7CBomber9IsBombingEv)

plt(_ZN6CMedalC1Ev)

plt(_ZN6CMedal4InitEff)

plt(_ZN6CScene11LoadAreaTaxEi)

plt(_ZN5CAreaC1Ev)

plt(_ZN5CArea4InitEiRK8AreaInfo)

plt(_ZN6CScene9InitAreasEiPKc)

plt(_ZN6CScene20CreateRenderAreaListEv)

plt(_ZN9CAreaMark4InitEi)

plt(_ZN11CBackgroundC1Ev)

plt(_ZN11CBackground4InitEiiiiiffff)

plt(_ZN7CCamera4InitEffff)

plt(_ZN7CBomberC1Ev)

plt(_ZN7CBomber4InitEv)

plt(_ZN9CSoundResD2Ev)

plt(_ZN9CSoundResD1Ev)

plt(_ZN9CSoundResC2Ev)

plt(_ZN9CSoundResC1Ev)

plt(_ZN13CStateManagerD2Ev)

plt(_ZN13CStateManagerD1Ev)

plt(_ZN13CStateManagerC2Ev)

plt(_ZN13CStateManagerC1Ev)

plt(_ZN13CTouchInertiaD2Ev)

plt(_ZN13CTouchInertiaC2Ev)

plt(_ZN13CTouchInertia13AddTrackPointEff)

plt(_ZN13CTouchInertia13GetStartPointEv)

plt(_ZN9CActionAI11detectCardsE7CARD_ID)

plt(_ZN8CCountry12IsCardUnlockEP7CardDef)

plt(_ZN9CActionAI21analyseCompositePowerEv)

plt(_ZN9CActionAI12getAiPercentEi)

plt(_ZN9CActionAI14getNumArmyMoveEii)

plt(_ZN9CActionAI12purChaseCardE7CARD_ID)

plt(_ZN13CActionAssist17purChaseCardsCardEv)

plt(_ZN13CActionAssist16purChaseFortCardEv)

plt(_ZN13CActionAssist21purChaseConstructCardEv)

plt(_ZN13CActionAssist21purChaseAirStrikeCardEv)

plt(_ZN13CActionAssist17purChaseDraftCardEb)

plt(_ZN9CActionAI15sortArmyToFrontEv)

plt(_ZN5CArea12IsArmyActiveEi)

plt(_ZN9CActionAI8getMaxIdEv)

plt(_ZN9CActionAI13setArmyActionEP5CArea)

plt(_ZN13CActionAssist16actionToNextAreaEiiii)

plt(_ZN9CActionAI13moveAndAttackEv)

plt(_Z13GetAIRandSeedv)

plt(_ZN13CActionAssist13calcDraftTypeEbiP8CCountry)

plt(_ZN5CArea12GetCityLevelEv)

plt(_ZN13CActionAssist19purChaseSpecialCardEv)

plt(_ZN13CActionAssist11getAllianceEiii)

plt(_ZN13CActionAssist10searchNodeEii)

plt(_ZN13CActionAssist14searchNodeByIDEii)

plt(_ZN13CActionAssist11getNeighborEiiic)

plt(_ZN8CCountry19CheckCardTargetArmyEP7CardDefii)

plt(_ZN5CArea16GetIndustryLevelEv)

plt(_ZN13CActionAssist4isAIEi)

plt(_ZN5CAreaC2Ev)

plt(_ZN5CAreaD2Ev)

plt(_ZN5CArmyD1Ev)

plt(_ZN5CArea12CanConstructEi)

plt(_ZN5CArea9ConstructEi)

plt(_ZN5CArea10GetArmyIdxEP5CArmy)

plt(_ZN5CArea10RemoveArmyEP5CArmy)

plt(_ZN5CArea15MoveArmyToFrontEP5CArmyb)

plt(_ZN5CArea9DraftArmyEi)

plt(_ZN5CArea13SetMoveInArmyEPS_P5CArmybbPKc)

plt(_ZN5CArea10MoveArmyToEPS_)

plt(_ZN8CCountry10RemoveAreaEi)

plt(_ZN8CCountry14BeConquestedByEPS_)

plt(_ZN5CArea10SetArmyDirEif)

plt(_ZN5CArea11AddArmyCardEii)

plt(_ZN5CArea11DelArmyCardEii)

plt(_ZN5CArea18RevertArmyStrengthEi)

plt(_ZN5CArmy12LostStrengthEi)

plt(_ZN8CCountry12CommanderDieEv)

plt(_ZN5CArea15AddArmyStrengthEii)

plt(_ZN5CArmy11AddStrengthEi)

plt(_ZN5CArea16AllArmyPoisoningEv)

plt(_ZN5CArmy9PoisoningEv)

plt(_ZN5CArea11UpgradeArmyEi)

plt(_ZN5CArmy7UpgradeEv)

plt(_ZN5CArea18SetAllArmyMovementEi)

plt(_ZN5CArea17CheckEncirclementEv)

plt(_ZN5CArmy9SetMoraleEi)

plt(_ZN5CArea10RenderArmyEffiP5CArmy)

plt(_ZN5CArea9TurnBeginEv)

plt(_ZN5CArmy9TurnBeginEv)

plt(_ZN5CArea7TurnEndEv)

plt(_ZN5CArmy7TurnEndEv)

plt(_ZN5CArmy8SaveArmyEP12SaveArmyInfo)

plt(_ZN5CArmy8LoadArmyEPK12SaveArmyInfo)

plt(_ZN9CAreaMarkC2Ev)

plt(_ZN9CAreaMarkD2Ev)

plt(_ZN5CArmyC2Ev)

plt(_ZN5CArmyD2Ev)

plt(_ZN11CBackgroundC2Ev)

plt(_ZN11CBackgroundD2Ev)

plt(_ZN12CBattleSceneC2Ev)

plt(_ZN12CBattleScene7ReleaseEv)

plt(_ZN11CBattleUnit6RenderEv)

plt(_ZN8ecEffect6RenderEv)

plt(_Z13HasUnitMotionPKci)

plt(_ZN12CBattleScene11CreateUnitsEv)

plt(_ZN9ecLibraryC1Ev)

plt(_ZN9ecLibrary4LoadEPKcR12ecTextureRes)

plt(_ZN11CBattleUnitC1Ev)

plt(_ZN11CBattleUnit4InitEiiP9ecLibraryP11UnitMotions)

plt(_ZN11CBattleUnit12SetDestroyedEv)

plt(_ZN12CBattleScene12ReleaseUnitsEv)

plt(_ZN11CBattleUnitD1Ev)

plt(_ZN12CBattleScene10CreateFortEv)

plt(_ZN12CBattleScene11ReleaseFortEv)

plt(_ZN11CBattleUnit11IsAttackingEv)

plt(_ZN11CBattleUnit7DestroyEv)

plt(_ZN12CBattleScene9AddCraterEPKcfff)

plt(_ZN12CBattleScene10StarEffectEi)

plt(_ZN12CBattleScene9AddEffectEPKcff)

plt(_ZN15ecEffectManager12CreateEffectEPKc)

plt(_ZN11CBattleUnit6AttackEv)

plt(_ZN11CBattleUnit6UpdateEf)

plt(_ZN8ecEffect6UpdateEf)

plt(_ZN8ecEffect6IsLiveEv)

plt(_ZN8ecEffectD1Ev)

plt(_ZN12CBattleSceneD2Ev)

plt(_ZN11CBattleUnitC2Ev)

plt(_ZN9ecElementC1Ev)

plt(_ZN9ecElement4InitEPKcP9ecLibrary)

plt(_ZN9ecElement4PlayEv)

plt(_ZN11CBattleUnit7ReleaseEv)

plt(_ZN9ecElementD1Ev)

plt(_ZN11CBattleUnitD2Ev)

plt(_ZN9ecElement6UpdateEf)

plt(_ZN9ecElement6RenderERK7ecMtx32)

plt(_ZN9ecElement11SetCurFrameEi)

plt(_ZN9ecElement7SetLoopEi)

plt(_ZN9ecElement11GetPlayTimeEv)

plt(_ZN7CBomberC2Ev)

plt(_ZN7CBomberD2Ev)

plt(_ZN8CCountry7UseCardEP7CardDefii)

plt(_ZN7CCameraC2Ev)

plt(_ZN7CCamera12SetSceneRectEffff)

plt(_ZN8CCountryC2Ev)

plt(_ZN8CCountryD2Ev)

plt(_ZN8CCountry8FindAreaEi)

plt(_ZN8CCountry15GetFirstCapitalEv)

plt(_ZN8CCountry18FindAdjacentAreaIDEib)

plt(_ZN8CCountry22FindAdjacentLandAreaIDEib)

plt(_ZN8CCountry13GetNumAirportEv)

plt(_ZN8CCountry18GetMinDstToAirportEi)

plt(_ZN8CCountry17GenCardTargetListE7CARD_ID)

plt(_ZN8CCountry16GetCurCardTargetEv)

plt(_ZN8CCountry14NextCardTargetEv)

plt(_ZN8CCountry12FinishActionEv)

plt(_ZN8CCountry16SetWarMedalLevelE11WARMEDAL_IDi)

plt(_ZN8CCountry12CollectTaxesEv)

plt(_ZN8CCountry16CollectIndustrysEv)

plt(_ZN8CCountry8DoActionEv)

plt(_ZN17GUICommanderMedalD2Ev)

plt(_ZN17GUICommanderMedalD1Ev)

plt(_ZN17GUICommanderMedalD0Ev)

plt(_ZN11GUIWarMedalD2Ev)

plt(_ZN11GUIWarMedalD1Ev)

plt(_ZN11GUIWarMedalD0Ev)

plt(_ZN17GUICommanderMedal8OnUpdateEf)

plt(_ZN11GUIWarMedal8OnUpdateEf)

plt(_ZN17GUICommanderMedal8OnRenderEv)

plt(_ZN11GUIWarMedal8OnRenderEv)

plt(_ZN13GUIAdornMedalD2Ev)

plt(_ZN13GUIAdornMedalD1Ev)

plt(_ZN13GUIAdornMedalD0Ev)

plt(_ZN13GUIAdornMedal8OnRenderEv)

plt(_ZN16GUIUpgradeButtonD2Ev)

plt(_ZN16GUIUpgradeButtonD1Ev)

plt(_ZN16GUIUpgradeButtonD0Ev)

plt(_ZN16GUIUpgradeButton8OnRenderEv)

plt(_ZN6ecText14GetStringWidthEib)

plt(_ZN12GUICommanderD2Ev)

plt(_ZN12GUICommanderD1Ev)

plt(_ZN12GUICommanderD0Ev)

plt(_ZN12GUICommander8OnRenderEv)

plt(_ZN12GUICommander8OnUpdateEf)

plt(_ZN17GUICommanderMedalC2Ev)

plt(_ZN17GUICommanderMedalC1Ev)

plt(_ZN17GUICommanderMedal4InitERK7GUIRecti)

plt(_ZN17GUICommanderMedal13SetArrowColorEj)

plt(_ZN11GUIWarMedalC2Ev)

plt(_ZN11GUIWarMedalC1Ev)

plt(_ZN11GUIWarMedal8SetLevelEi)

plt(_ZN11GUIWarMedal4InitERK7GUIRect11WARMEDAL_IDi)

plt(_ZN11GUIWarMedal13SetArrowColorEj)

plt(_ZN13GUIAdornMedalC2Ev)

plt(_ZN13GUIAdornMedal7RefreshEv)

plt(_ZN16GUIUpgradeButtonC2Ev)

plt(_ZN16GUIUpgradeButtonC1Ev)

plt(_ZN16GUIUpgradeButton12SetNeedMedalEi)

plt(_ZN12GUICommanderC2Ev)

plt(_ZN12GUICommander16SetCommanderInfoEv)

plt(_ZN12GUICommander13SelectedMedalEi)

plt(_ZN12GUICommander7OnEventERK5Event)

plt(_ZN14GUIExitWarningD2Ev)

plt(_ZN14GUIExitWarningD1Ev)

plt(_ZN14GUIExitWarningD0Ev)

plt(_ZN14GUIExitWarning8OnRenderEv)

plt(_ZN14GUIExitWarningC2Ev)

plt(_ZN14GUIExitWarning7OnEventERK5Event)

plt(_ZN19GUIConnectHostStateD2Ev)

plt(_ZN19GUIConnectHostStateD1Ev)

plt(_ZN19GUIConnectHostStateD0Ev)

plt(_ZN11GUIHostListD2Ev)

plt(_ZN11GUIHostListD1Ev)

plt(_ZN11GUIHostListD0Ev)

plt(_ZN11GUIHostList8OnRenderEv)

plt(_ZN19GUIConnectHostState8OnRenderEv)

plt(_ZN11GUIHostItemD2Ev)

plt(_ZN11GUIHostItemD1Ev)

plt(_ZN11GUIHostItemD0Ev)

plt(_ZN19GUIConnectHostStateC2Ev)

plt(_ZN19GUIConnectHostStateC1Ev)

plt(_ZN19GUIConnectHostState4InitER7GUIRect)

plt(_ZN11GUIHostItemC2Ev)

plt(_ZN11GUIHostItemC1Ev)

plt(_ZN11GUIHostItem7SetNameEPKc)

plt(_ZN11GUIHostListC2Ev)

plt(_ZN11GUIHostList8FindHostEPKc)

plt(_ZN11GUIHostList14FindHostByUUIDEi)

plt(_ZN11GUIHostList7AddHostEPKcS1_ii)

plt(_ZN19GUIConnectHostState7OnEventERK5Event)

plt(_ZN11GUIHostList7OnEventERK5Event)

plt(_ZN11GUIHostItem8OnRenderEv)

plt(_ZN11GUILevelSelD2Ev)

plt(_ZN11GUILevelSelD1Ev)

plt(_ZN11GUILevelSelD0Ev)

plt(_ZN11GUILevelSel8OnRenderEv)

plt(_ZN11GUILevelSelC2Ev)

plt(_ZN11GUILevelSel7OnEventERK5Event)

plt(_ZN10GUILoadingD2Ev)

plt(_ZN10GUILoadingD1Ev)

plt(_ZN10GUILoadingD0Ev)

plt(_ZN10GUILoading8OnRenderEv)

plt(_ZN10GUILoadingC2Ev)

plt(_ZN10GUILoading7OnEventERK5Event)

plt(_ZN16GUILockedWarningD2Ev)

plt(_ZN16GUILockedWarningD1Ev)

plt(_ZN16GUILockedWarningD0Ev)

plt(_ZN16GUILockedWarning8OnRenderEv)

plt(_ZN16GUILockedWarningC2Ev)

plt(_ZN16GUILockedWarning7OnEventERK5Event)

plt(_ZN11GUIMainMenuD2Ev)

plt(_ZN11GUIMainMenuD1Ev)

plt(_ZN11GUIMainMenuD0Ev)

plt(_ZN11GUIMainMenu8OnRenderEv)

plt(_ZN11GUIMainMenuC2Ev)

plt(_ZN11GUIMainMenu12IsShowNewTipEv)

plt(_ZN9GUIButton12SetTextImageEPKc)

plt(_ZN8GUIImageC1Ev)

plt(_ZN8GUIImage4InitEPKcRK7GUIRect)

plt(_ZN11GUIMainMenu8OnUpdateEf)

plt(_ZN11GUIMainMenu7OnEventERK5Event)

plt(_ZN12GUICorpsInfoD2Ev)

plt(_ZN12GUICorpsInfoD1Ev)

plt(_ZN12GUICorpsInfoD0Ev)

plt(_ZN13GUIMatchSetup8OnRenderEv)

plt(_ZN14GUICorpsButton8OnRenderEv)

plt(_ZN12GUICorpsInfo8OnRenderEv)

plt(_ZN14GUICorpsButtonD2Ev)

plt(_ZN14GUICorpsButtonD1Ev)

plt(_ZN14GUICorpsButtonD0Ev)

plt(_ZN13GUIMatchSetupD2Ev)

plt(_ZN13GUIMatchSetupD1Ev)

plt(_ZN13GUIMatchSetupD0Ev)

plt(_ZN12GUICorpsInfoC2Ev)

plt(_ZN12GUICorpsInfoC1Ev)

plt(_ZN12GUICorpsInfo4InitERK7GUIRect)

plt(_ZN12GUICorpsInfo13SetPlayerNameEPKcbS1_iib)

plt(_ZN14GUICorpsButtonC2Ev)

plt(_ZN14GUICorpsButtonC1Ev)

plt(_ZN14GUICorpsButton4InitERK7GUIRectPKcb)

plt(_ZN14GUICorpsButton13SetPlayerNameEPKcbS1_iib)

plt(_ZN13GUIMatchSetupC2Ev)

plt(_ZN13GUIMatchSetup7OnEventERK5Event)

plt(_ZN10GUINewGameD2Ev)

plt(_ZN10GUINewGameD1Ev)

plt(_ZN10GUINewGameD0Ev)

plt(_ZN10GUINewGame8OnRenderEv)

plt(_ZN7_JNIEnv22CallStaticObjectMethodEP7_jclassP10_jmethodIDz)

plt(_ZN10GUINewGameC2Ev)

plt(_ZN10GUINewGame12IsShowSurveyEv)

plt(_ZN10GUINewGame12IsImageReadyEv)

plt(_ZN10GUINewGame18IsIabEventImgReadyEv)

plt(_ZN10GUINewGame15IsShowSurveyTipEv)

plt(_ZN10GUINewGame17IsShowIabEventTipEv)

plt(_ZN10GUINewGame14IsShowIabEventEv)

plt(_Z12JString2CStrP7_JNIEnvP8_jstring)

plt(_ZN10GUINewGame17GetPromotionImageEv)

plt(_ZN10GUINewGame16GetIabEventImageEv)

plt(_ZN10GUINewGame15GetPromotionUrlEv)

plt(_ZN10GUINewGame14BtnSurveyClickEv)

plt(_ZN10GUINewGame14GetIabEventUrlEv)

plt(_ZN10GUINewGame21OnRadioBtnSurveyClickEv)

plt(_ZN10GUINewGame23OnRadioBtnIabEventClickEv)

plt(_ZN10GUINewGame14GetSelectGroupEP14GUIRadioButton)

plt(_ZN10GUINewGame18OnCheckButtonClickEP14GUIRadioButton)

plt(_ZN10GUINewGame13GetAppVersionEv)

plt(_ZN9GUIButton13SetTextOffsetEff)

plt(_ZN9GUIButton12SetTextAlignEi)

plt(_ZN8GUIImage4InitEPKcRK13ecTextureRectRK7GUIRectbbb)

plt(_ZN7GUITextC1Ev)

plt(_ZN7GUIText4InitERK7GUIRectP9ecUniFont)

plt(_ZN7GUIText7SetTextEPKc)

plt(_ZN8GUIImage8SetImageEPKcRK13ecTextureRectb)

plt(_ZN10GUINewGame7OnEventERK5Event)

plt(_Z16ecLaunchAppStorePKc)

plt(_ZN12GUISelBattle8OnRenderEv)

plt(_ZN12GUISelBattleC2Ev)

plt(_ZN13GUIBattleListC1Ev)

plt(_ZN13GUIBattleList4InitERK7GUIRecti)

plt(_ZN13GUIBattleList18SelectLastUnlockedEv)

plt(_ZN13GUIBattleList9SetSelectEi)

plt(_ZN12GUISelBattle16ReleaseImageListEv)

plt(_ZN12GUISelBattleD2Ev)

plt(_ZN12GUISelBattleD1Ev)

plt(_ZN12GUISelBattleD0Ev)

plt(_ZN12GUISelBattle13LoadImageListEii)

plt(_ZN12GUISelBattle9SelBattleEii)

plt(_ZN12GUISelBattle8OnUpdateEf)

plt(_ZN12GUISelBattle7OnEventERK5Event)

plt(_ZN13GUISelCountry8OnRenderEv)

plt(_ZN13GUISelCountry8OnUpdateEf)

plt(_ZN13GUISelCountryC2Ev)

plt(_ZN13GUISelCountry9SelBattleEii)

plt(_ZN13GUISelCountry13LoadImageListEi)

plt(_ZN14GUICountryListC1Ev)

plt(_ZN14GUICountryList4InitERK7GUIRecti)

plt(_ZN13GUISelCountry16ReleaseImageListEv)

plt(_ZN13GUISelCountryD2Ev)

plt(_ZN13GUISelCountryD1Ev)

plt(_ZN13GUISelCountryD0Ev)

plt(_ZN13GUISelCountry7OnEventERK5Event)

plt(_ZN14GUICountryList15GetSelCountryIDEv)

plt(_ZN10GUIServiceD2Ev)

plt(_ZN10GUIServiceD1Ev)

plt(_ZN10GUIServiceD0Ev)

plt(_ZN10GUIService8OnRenderEv)

plt(_ZN10GUIServiceC2Ev)

plt(_ZN7GUIText8SetAlignEi)

plt(_ZN10GUIService7OnEventERK5Event)

plt(_ZN6CMedalC2Ev)

plt(_ZN7CPlayerC2Ev)

plt(_ZN7CPlayer10RecvPacketEPKvi)

plt(_ZN7CPlayer15ClearPacketListEv)

plt(_ZN7CPlayerD2Ev)

plt(_ZN13GUIBattleItem8OnUpdateEf)

plt(_ZN13GUIBattleItemD2Ev)

plt(_ZN13GUIBattleItemD1Ev)

plt(_ZN13GUIBattleItemD0Ev)

plt(_ZN13GUIBattleItem8OnRenderEv)

plt(_ZN13GUIBattleListD2Ev)

plt(_ZN13GUIBattleListD1Ev)

plt(_ZN13GUIBattleListD0Ev)

plt(_ZN13GUIBattleList8OnUpdateEf)

plt(_ZN13GUIBattleItemC2Ev)

plt(_ZN13GUIBattleItemC1Ev)

plt(_ZN13GUIBattleItem4InitEiiRK7GUIRect)

plt(_ZN13GUIBattleItem11SetSelectedEb)

plt(_ZN13GUIBattleListC2Ev)

plt(_ZN13GUIBattleList11ResetSelectEv)

plt(_ZN13GUIBattleList15ResetTouchStateEv)

plt(_ZN13GUIBattleList10GelSelItemEff)

plt(_ZN13GUIBattleItem7OnEventERK5Event)

plt(_ZN13GUIBattleList7OnEventERK5Event)

plt(_ZN14GUICountryItem8OnUpdateEf)

plt(_ZN14GUICountryItemD2Ev)

plt(_ZN14GUICountryItemD1Ev)

plt(_ZN14GUICountryItemD0Ev)

plt(_ZN14GUICountryItem8OnRenderEv)

plt(_ZN14GUICountryListD2Ev)

plt(_ZN14GUICountryListD1Ev)

plt(_ZN14GUICountryListD0Ev)

plt(_ZN14GUICountryList8OnUpdateEf)

plt(_ZN14GUICountryItemC2Ev)

plt(_ZN14GUICountryItemC1Ev)

plt(_ZN14GUICountryItem4InitEPKcS1_RK7GUIRect)

plt(_ZN14GUICountryItem11SetSelectedEb)

plt(_ZN14GUICountryListC2Ev)

plt(_ZN14GUICountryList11ResetSelectEv)

plt(_ZN14GUICountryList15ResetTouchStateEv)

plt(_ZN14GUICountryList10GelSelItemEff)

plt(_ZN14GUICountryItem7OnEventERK5Event)

plt(_ZN14GUICountryList9SetSelectEi)

plt(_ZN14GUICountryList7OnEventERK5Event)

plt(_ZN9GUIButtonD1Ev)

plt(_ZN9GUIButtonD0Ev)

plt(_ZN9GUIButton7SetGlowEPKc)

plt(_ZN6ecText9GetHeightEv)

plt(_ZN9GUIButton7SetTextEPKt)

plt(_ZN6ecText7SetTextEPKt)

plt(_ZN9GUIButton8SetAlphaEf)

plt(_ZN10GUIElementC1Ev)

plt(_ZN10GUIElement11RemoveChildEPS_)

plt(_ZN10GUIElementD1Ev)

plt(_ZN10GUIElementD0Ev)

plt(_ZN10GUIElement4MoveEff)

plt(_ZN10GUIElement11CheckInRectEffRK7GUIRect)

plt(_ZN10GUIElement10SetVisibleEb)

plt(_ZN10GUIElement12FindByHandleEj)

plt(_ZN10GUIElement9PostEventERK5Event)

plt(_ZN10GUIElement6RenderEv)

plt(_ZN10GUIElement6UpdateEf)

plt(_ZN8GUIImageD2Ev)

plt(_ZN8GUIImageD1Ev)

plt(_ZN8GUIImageD0Ev)

plt(_ZN8GUIImage8OnRenderEv)

plt(_ZN8GUIImageC2Ev)

plt(_ZN8GUIImage8SetAlphaEf)

plt(_ZN10GUIManager7OnEventERK5Event)

plt(_ZN10GUIManagerD2Ev)

plt(_ZN10GUIManagerD1Ev)

plt(_ZN10GUIManagerD0Ev)

plt(_ZN10GUIManagerC2Ev)

plt(_ZN10GUIManagerC1Ev)

plt(_ZN12GUIScrollBarC1Ev)

plt(_ZN12GUIScrollBar4InitERK7GUIRectPKcS4_iiiii)

plt(_ZN16GUIMotionManagerD2Ev)

plt(_ZN16GUIMotionManagerD1Ev)

plt(_ZN16GUIMotionManagerC2Ev)

plt(_ZN16GUIMotionManagerC1Ev)

plt(_ZN16GUIMotionManager9SetMotionEjffffft)

plt(_ZN16GUIMotionManager9AddMotionEP10GUIElementffffft)

plt(_ZN16GUIMotionManager10AddMotionXEP10GUIElementfft)

plt(_ZN16GUIMotionManager10AddMotionYEP10GUIElementfft)

plt(_ZN16GUIMotionManager8SetSpeedEjff)

plt(_ZN16GUIMotionManager15GetMotionActiveEj)

plt(_ZN14GUIRadioButtonD1Ev)

plt(_ZN14GUIRadioButtonD0Ev)

plt(_ZN14GUIRadioButton8OnRenderEv)

plt(_ZN12GUIScrollBarD2Ev)

plt(_ZN12GUIScrollBarD1Ev)

plt(_ZN12GUIScrollBarD0Ev)

plt(_ZN12GUIScrollBar8OnRenderEv)

plt(_ZN12GUIScrollBarC2Ev)

plt(_ZN12GUIScrollBar7OnEventERK5Event)

plt(_ZN7GUITextD2Ev)

plt(_ZN7GUITextD1Ev)

plt(_ZN7GUITextD0Ev)

plt(_ZN7GUIText8OnRenderEv)

plt(_ZN7GUITextC2Ev)

plt(_ZN7GUIText12SetTextColorEj)

plt(_ZN9ecGameKitC2Ev)

plt(_ZN9ecGameKitD2Ev)

plt(_ZN9ecGameKit7ReleaseEv)

plt(_ZN9ecGameKit22SendPacketToAllPlayersEPKvi)

plt(_ZN18ecSessionInterfaceC2Ev)

plt(_ZN18ecSessionInterfaceD2Ev)

plt(_ZN18ecSessionInterface7ReleaseEv)

plt(_ZN18ecSessionInterface10DisconnectEPKc)

plt(_ZN18ecSessionInterface20SendPacketToAllPeersEPKvi)

plt(_ZN11TiXmlString7reserveEm)

plt(_ZN11TiXmlString6assignEPKcm)

plt(_ZN11TiXmlString6appendEPKcm)

plt(_ZNK9TiXmlNode10ToDocumentEv)

plt(_ZNK9TiXmlNode9ToElementEv)

plt(_ZNK9TiXmlNode9ToCommentEv)

plt(_ZNK9TiXmlNode9ToUnknownEv)

plt(_ZNK9TiXmlNode6ToTextEv)

plt(_ZNK9TiXmlNode13ToDeclarationEv)

plt(_ZN9TiXmlNode10ToDocumentEv)

plt(_ZN9TiXmlNode9ToElementEv)

plt(_ZN9TiXmlNode9ToCommentEv)

plt(_ZN9TiXmlNode9ToUnknownEv)

plt(_ZN9TiXmlNode6ToTextEv)

plt(_ZN9TiXmlNode13ToDeclarationEv)

plt(_ZNK12TiXmlElement9ToElementEv)

plt(_ZN12TiXmlElement9ToElementEv)

plt(_ZNK12TiXmlComment9ToCommentEv)

plt(_ZN12TiXmlComment9ToCommentEv)

plt(_ZNK9TiXmlText6ToTextEv)

plt(_ZN9TiXmlText6ToTextEv)

plt(_ZNK16TiXmlDeclaration13ToDeclarationEv)

plt(_ZN16TiXmlDeclaration13ToDeclarationEv)

plt(_ZNK12TiXmlUnknown9ToUnknownEv)

plt(_ZN12TiXmlUnknown9ToUnknownEv)

plt(_ZNK12TiXmlComment9StreamOutEP14TiXmlOutStream)

plt(_ZNK12TiXmlUnknown9StreamOutEP14TiXmlOutStream)

plt(_ZNK12TiXmlComment5PrintEP7__sFILEi)

plt(_ZNK12TiXmlUnknown5PrintEP7__sFILEi)

plt(_ZNK16TiXmlDeclaration5PrintEP7__sFILEi)

plt(_ZN9TiXmlBase9PutStringERK11TiXmlStringPS0_)

plt(_ZN9TiXmlBase9PutStringERK11TiXmlStringP14TiXmlOutStream)

plt(_ZNK9TiXmlText9StreamOutEP14TiXmlOutStream)

plt(_ZNK16TiXmlDeclaration9StreamOutEP14TiXmlOutStream)

plt(_ZNK9TiXmlText5PrintEP7__sFILEi)

plt(_ZN9TiXmlBase14StringToBufferC2ERK11TiXmlString)

plt(_ZN9TiXmlBase14StringToBufferC1ERK11TiXmlString)

plt(_ZN9TiXmlBase14StringToBufferD2Ev)

plt(_ZN9TiXmlBase14StringToBufferD1Ev)

plt(_ZN9TiXmlNodeC2ENS_8NodeTypeE)

plt(_ZN9TiXmlNodeC1ENS_8NodeTypeE)

plt(_ZN9TiXmlNodeD1Ev)

plt(_ZN12TiXmlUnknownD2Ev)

plt(_ZN12TiXmlUnknownD1Ev)

plt(_ZN12TiXmlUnknownD0Ev)

plt(_ZN16TiXmlDeclarationD2Ev)

plt(_ZN16TiXmlDeclarationD1Ev)

plt(_ZN9TiXmlTextD2Ev)

plt(_ZN9TiXmlTextD1Ev)

plt(_ZN9TiXmlTextD0Ev)

plt(_ZN12TiXmlCommentD2Ev)

plt(_ZN12TiXmlCommentD1Ev)

plt(_ZN12TiXmlCommentD0Ev)

plt(_ZN16TiXmlDeclarationD0Ev)

plt(_ZN9TiXmlNodeD0Ev)

plt(_ZNK9TiXmlNode6CopyToEPS_)

plt(_ZN9TiXmlNode5ClearEv)

plt(_ZN9TiXmlNode14InsertEndChildERKS_)

plt(_ZN9TiXmlNode17InsertBeforeChildEPS_RKS_)

plt(_ZN9TiXmlNode16InsertAfterChildEPS_RKS_)

plt(_ZN9TiXmlNode12ReplaceChildEPS_RKS_)

plt(_ZN9TiXmlNode11RemoveChildEPS_)

plt(_ZNK9TiXmlNode10FirstChildEPKc)

plt(_ZNK9TiXmlNode9LastChildEPKc)

plt(_ZN9TiXmlNode9LastChildEPKc)

plt(_ZNK9TiXmlNode15IterateChildrenEPKS_)

plt(_ZN9TiXmlNode15IterateChildrenEPS_)

plt(_ZNK9TiXmlNode11NextSiblingEPKc)

plt(_ZNK9TiXmlNode15IterateChildrenEPKcPKS_)

plt(_ZN9TiXmlNode11NextSiblingEPKc)

plt(_ZN9TiXmlNode15IterateChildrenEPKcPS_)

plt(_ZNK9TiXmlNode15PreviousSiblingEPKc)

plt(_ZN9TiXmlNode15PreviousSiblingEPKc)

plt(_ZNK9TiXmlNode17FirstChildElementEv)

plt(_ZN9TiXmlNode17FirstChildElementEv)

plt(_ZNK9TiXmlNode17FirstChildElementEPKc)

plt(_ZN9TiXmlNode17FirstChildElementEPKc)

plt(_ZNK9TiXmlNode18NextSiblingElementEv)

plt(_ZN9TiXmlNode18NextSiblingElementEv)

plt(_ZNK9TiXmlNode18NextSiblingElementEPKc)

plt(_ZN9TiXmlNode18NextSiblingElementEPKc)

plt(_ZNK9TiXmlNode11GetDocumentEv)

plt(_ZN9TiXmlNode11GetDocumentEv)

plt(_ZNK12TiXmlElement7GetTextEv)

plt(_ZN13TiXmlDocumentC2Ev)

plt(_ZN13TiXmlDocumentC1Ev)

plt(_ZN13TiXmlDocumentC2EPKc)

plt(_ZN13TiXmlDocument8LoadFileEP7__sFILE13TiXmlEncoding)

plt(_ZN13TiXmlDocument8SetErrorEiPKcP16TiXmlParsingData13TiXmlEncoding)

plt(_ZN13TiXmlDocument8LoadFileEPKc13TiXmlEncoding)

plt(_ZNK13TiXmlDocument8SaveFileEP7__sFILE)

plt(_ZNK13TiXmlDocument8SaveFileEPKc)

plt(_ZNK13TiXmlDocument6CopyToEPS_)

plt(_ZN13TiXmlDocumentC2ERKS_)

plt(_ZN13TiXmlDocumentC1ERKS_)

plt(_ZN13TiXmlDocumentaSERKS_)

plt(_ZNK13TiXmlDocument5CloneEv)

plt(_ZNK13TiXmlDocument5PrintEP7__sFILEi)

plt(_ZNK13TiXmlDocument9StreamOutEP14TiXmlOutStream)

plt(_ZNK14TiXmlAttribute4NextEv)

plt(_ZNK12TiXmlElement5PrintEP7__sFILEi)

plt(_ZNK12TiXmlElement9StreamOutEP14TiXmlOutStream)

plt(_ZN14TiXmlAttribute4NextEv)

plt(_ZNK14TiXmlAttribute8PreviousEv)

plt(_ZN14TiXmlAttribute8PreviousEv)

plt(_ZNK14TiXmlAttribute5PrintEP7__sFILEi)

plt(_ZNK14TiXmlAttribute9StreamOutEP14TiXmlOutStream)

plt(_ZNK14TiXmlAttribute13QueryIntValueEPi)

plt(_ZNK14TiXmlAttribute16QueryDoubleValueEPd)

plt(_ZN14TiXmlAttribute11SetIntValueEi)

plt(_ZN14TiXmlAttribute14SetDoubleValueEd)

plt(_ZNK14TiXmlAttribute8IntValueEv)

plt(_ZNK14TiXmlAttribute11DoubleValueEv)

plt(_ZNK12TiXmlComment6CopyToEPS_)

plt(_ZN12TiXmlCommentC2ERKS_)

plt(_ZN12TiXmlCommentC1ERKS_)

plt(_ZN12TiXmlCommentaSERKS_)

plt(_ZNK12TiXmlComment5CloneEv)

plt(_ZNK9TiXmlText6CopyToEPS_)

plt(_ZNK9TiXmlText5CloneEv)

plt(_ZN16TiXmlDeclarationC2EPKcS1_S1_)

plt(_ZN16TiXmlDeclarationC1EPKcS1_S1_)

plt(_ZNK16TiXmlDeclaration6CopyToEPS_)

plt(_ZN16TiXmlDeclarationC2ERKS_)

plt(_ZN16TiXmlDeclarationC1ERKS_)

plt(_ZN16TiXmlDeclarationaSERKS_)

plt(_ZNK16TiXmlDeclaration5CloneEv)

plt(_ZNK12TiXmlUnknown6CopyToEPS_)

plt(_ZNK12TiXmlUnknown5CloneEv)

plt(_ZN17TiXmlAttributeSetC2Ev)

plt(_ZN17TiXmlAttributeSetC1Ev)

plt(_ZN17TiXmlAttributeSetD2Ev)

plt(_ZN17TiXmlAttributeSetD1Ev)

plt(_ZN12TiXmlElementC2EPKc)

plt(_ZN17TiXmlAttributeSet3AddEP14TiXmlAttribute)

plt(_ZN17TiXmlAttributeSet6RemoveEP14TiXmlAttribute)

plt(_ZN12TiXmlElement9ClearThisEv)

plt(_ZN12TiXmlElementD2Ev)

plt(_ZN12TiXmlElementD1Ev)

plt(_ZN12TiXmlElementD0Ev)

plt(_ZNK17TiXmlAttributeSet4FindERK11TiXmlString)

plt(_ZNK12TiXmlElement9AttributeEPKcPi)

plt(_ZNK12TiXmlElement9AttributeEPKcPd)

plt(_ZN17TiXmlAttributeSet4FindERK11TiXmlString)

plt(_ZN12TiXmlElement15RemoveAttributeEPKc)

plt(_ZNK12TiXmlElement6CopyToEPS_)

plt(_ZN12TiXmlElementC2ERKS_)

plt(_ZN12TiXmlElementC1ERKS_)

plt(_ZN12TiXmlElementaSERKS_)

plt(_ZNK12TiXmlElement5CloneEv)

plt(_ZNK11TiXmlHandle10FirstChildEv)

plt(_ZNK11TiXmlHandle10FirstChildEPKc)

plt(_ZNK11TiXmlHandle17FirstChildElementEv)

plt(_ZNK11TiXmlHandle17FirstChildElementEPKc)

plt(_ZNK11TiXmlHandle5ChildEi)

plt(_ZNK11TiXmlHandle5ChildEPKci)

plt(_ZNK11TiXmlHandle12ChildElementEi)

plt(_ZNK11TiXmlHandle12ChildElementEPKci)

plt(_ZN12TiXmlElement5ParseEPKcP16TiXmlParsingData13TiXmlEncoding)

plt(_ZN12TiXmlComment5ParseEPKcP16TiXmlParsingData13TiXmlEncoding)

plt(_ZN9TiXmlText5ParseEPKcP16TiXmlParsingData13TiXmlEncoding)

plt(_ZN16TiXmlDeclaration5ParseEPKcP16TiXmlParsingData13TiXmlEncoding)

plt(_ZN12TiXmlUnknown5ParseEPKcP16TiXmlParsingData13TiXmlEncoding)

plt(_ZNK13TiXmlDocument10ToDocumentEv)

plt(_ZN13TiXmlDocument10ToDocumentEv)

plt(_ZN14TiXmlAttributeD2Ev)

plt(_ZN14TiXmlAttributeD1Ev)

plt(_ZN13TiXmlDocumentD2Ev)

plt(_ZN13TiXmlDocumentD1Ev)

plt(_ZN13TiXmlDocumentD0Ev)

plt(_ZN14TiXmlAttributeD0Ev)

plt(_ZN9TiXmlBase18ConvertUTF32ToUTF8EmPcPi)

plt(_ZN9TiXmlBase7IsAlphaEh13TiXmlEncoding)

plt(_ZN9TiXmlBase10IsAlphaNumEh13TiXmlEncoding)

plt(_ZN16TiXmlParsingData5StampEPKc13TiXmlEncoding)

plt(_ZN9TiXmlBase14SkipWhiteSpaceEPKc13TiXmlEncoding)

plt(_ZN9TiXmlBase8ReadNameEPKcP11TiXmlString13TiXmlEncoding)

plt(_ZN9TiXmlBase9GetEntityEPKcPcPi13TiXmlEncoding)

plt(_ZN9TiXmlBase11StringEqualEPKcS1_b13TiXmlEncoding)

plt(_ZN9TiXmlBase8ReadTextEPKcP11TiXmlStringbS1_b13TiXmlEncoding)

plt(_ZN14TiXmlAttribute5ParseEPKcP16TiXmlParsingData13TiXmlEncoding)

plt(_ZN9TiXmlNode8IdentifyEPKc13TiXmlEncoding)

plt(_ZN13TiXmlDocument5ParseEPKcP16TiXmlParsingData13TiXmlEncoding)

plt(_ZNK9TiXmlText5BlankEv)

plt(_ZN12TiXmlElement9ReadValueEPKcP16TiXmlParsingData13TiXmlEncoding)

plt(_ZNK9hgeVector5AngleEPKS_)

plt(_ZN7ecImageD2Ev)

plt(_ZN7ecImage4InitEP9ecTextureffff)

plt(_ZN7ecImageC2EP9ecTextureffff)

plt(_ZN7ecImageC2EP9ecTextureRK13ecTextureRect)

plt(_ZN7ecImageC2EP11ecImageAttr)

plt(_ZN7ecImage13RenderStretchEffff)

plt(_ZN7ecImage8Render4VEffffffff)

plt(_ZN7ecImage10SetTextureEP9ecTexture)

plt(_ZN7ecImage7SetFlipEbbb)

plt(_ZN7ecImage14SetTextureRectEffff)

plt(_ZN7ecImage14SetTextureRectERK13ecTextureRect)

plt(_ZN12ecTextureResC2Ev)

plt(_ZN12ecTextureRes14ReleaseTextureEP9ecTexture)

plt(_ZN12ecTextureResD2Ev)

plt(_ZN12ecTextureRes10GetTextureEPKc)

plt(_ZN12ecTextureRes13CreateTextureEPKcbbb)

plt(_ZN12ecTextureRes11CreateImageEPKcP9ecTextureffffff)

plt(_ZN12ecTextureRes11CreateImageEPKcS1_ffffff)

plt(_ZN11ecEffectResC2Ev)

plt(_ZN11ecEffectResC1Ev)

plt(_ZN11ecEffectRes7ReleaseEv)

plt(_ZN11ecEffectResD2Ev)

plt(_ZN11ecEffectResD1Ev)

plt(_ZN11ecEffectRes10LoadEffectEPKcP12ecTextureRes)

plt(_ZN18ecEffectResManager16ReleaseEffectResEP11ecEffectRes)

plt(_ZN18ecEffectResManagerC2Ev)

plt(_ZN18ecEffectResManagerC1Ev)

plt(_ZN18ecEffectResManagerD2Ev)

plt(_ZN18ecEffectResManagerD1Ev)

plt(_ZN18ecEffectResManager16ReleaseEffectResEPKc)

plt(_ZN8ecEffectC2Ev)

plt(_ZN8ecEffectC1Ev)

plt(_ZN8ecEffectD2Ev)

plt(_ZN8ecEffect4InitEPKcP9TFreeListI16ecParticleSystemE)

plt(_ZN16ecParticleSystem4InitEP13ecEmitterAttr)

plt(_ZN16ecParticleSystem6FireAtEfff)

plt(_ZN8ecEffect4FireEv)

plt(_ZN16ecParticleSystem4FireEv)

plt(_ZN8ecEffect4StopEb)

plt(_ZN16ecParticleSystem4StopEb)

plt(_ZN8ecEffect6MoveToEffb)

plt(_ZN16ecParticleSystem6MoveToEffb)

plt(_ZN16ecParticleSystem6UpdateEf)

plt(_ZN16ecParticleSystem6RenderEv)

plt(_ZN16ecParticleSystem6IsLiveEv)

plt(_ZN15ecEffectManagerC2Ev)

plt(_ZN16ecParticleSystemC1Ev)

plt(_ZN16ecParticleSystemD1Ev)

plt(_ZN15ecEffectManagerC1Ev)

plt(_ZN15ecEffectManagerD2Ev)

plt(_ZN15ecEffectManagerD1Ev)

plt(_ZN9ecUniFontC2Ev)

plt(_ZN9ecUniFont12GetCharImageEt)

plt(_ZN9ecUniFontD2Ev)

plt(_ZN11ecLabelTextC2Ev)

plt(_ZN11ecLabelTextD2Ev)

plt(_ZN11ecLabelText8SetAlphaEf)

plt(_ZN10CCSoundBoxC2Ev)

plt(_ZN10CCSoundBoxC1Ev)

plt(_ZN10CCSoundBoxD2Ev)

plt(_ZN10CCSoundBoxD1Ev)

plt(_ZN10CCSoundBox15InitSoundSystemEv)

plt(_ZN10CCSoundBox18DestroySoundSystemEv)

plt(_ZN10CCSoundBox9StopMusicEv)

plt(_ZN10CCSoundBox9StopAllSEEv)

plt(_ZN13ecStringTableC2Ev)

plt(_ZN13ecStringTableD2Ev)

plt(_ZN6ecTextC2Ev)

plt(_ZN6ecTextD2Ev)

plt(_ZN6ecText11GetNumLinesEv)

plt(_Z22ecSetIdleTimerDisabledb)

plt(_ZN16ecParticleSystemC2Ev)

plt(_ZN16ecParticleSystemD2Ev)

plt(_ZN9ecLibraryC2Ev)

plt(_ZN9ecLibrary11GetItemDataEi)

plt(_ZN9ecLibrary12FindItemDataEPKc)

plt(_ZN9ecLibrary14GetElementDataEi)

plt(_ZN9ecLibrary12GetFrameDataEi)

plt(_ZN9ecLibrary12GetLayerDataEi)

plt(_ZN9ecLibrary11GetItemNameEj)

plt(_ZN9ecLibraryD2Ev)

plt(_ZN7ecShapeD1Ev)

plt(_ZN9ecLibraryD1Ev)

plt(_ZN9ecLibraryD0Ev)

plt(_Z13ecLoadLibraryPKcR13ecLibraryData)

plt(_ZN7ecShapeC1Ev)

plt(_ZN7ecShape4InitEP9ecTextureffff)

plt(_Z14ecSaveLibrarayPKcR13ecLibraryDataS0_i)

plt(_ZN9ecElementC2Ev)

plt(_ZN9ecElementD2Ev)

plt(_ZN9ecElement4InitEP10ecItemDataP9ecLibrary)

plt(_ZN7ecLayerC1Ev)

plt(_ZN7ecFrameC1Ev)

plt(_ZN7ecLayer4InitEiP11ecLayerDataP7ecFrameP9ecElementP9ecLibrary)

plt(_ZN7ecLayer11SetCurFrameEi)

plt(_ZN9ecElement5ResetEv)

plt(_ZN7ecLayer4PlayEv)

plt(_ZN9ecElement4StopEv)

plt(_ZN7ecLayer4StopEv)

plt(_ZN7ecLayer7SetLoopEi)

plt(_ZN9ecElement4InitEP13ecElementDataP9ecLibrary)

plt(_ZN9ecElement9ResetItemEP10ecItemDataP9ecLibrary)

plt(_ZN9ecElement10ChangeItemEP10ecItemDataS1_P9ecLibrary)

plt(_ZN7ecLayer10ChangeItemEP10ecItemDataS1_P9ecLibrary)

plt(_ZN9ecElement10ChangeItemEPKcS1_P9ecLibrary)

plt(_ZN7ecShape8SetColorEj)

plt(_ZN7ecShape6RenderERK7ecMtx32)

plt(_ZN7ecLayer6RenderERK7ecMtx32)

plt(_ZN9ecElement9NextFrameEv)

plt(_ZN7ecLayer9NextFrameEv)

plt(_ZN7ecShapeC2Ev)

plt(_ZN7ecShapeD2Ev)

plt(_ZN7ecLayerD2Ev)

plt(_ZN7ecLayerD1Ev)

plt(_ZN7ecLayerD0Ev)

plt(_ZN7ecLayerC2Ev)

plt(_ZN7ecFrame10ChangeItemEP10ecItemDataS1_P9ecLibrary)

plt(_ZN7ecFrame4PlayEv)

plt(_ZN7ecFrame4StopEv)

plt(_ZN7ecFrame4InitEP11ecFrameDataP9ecElementP9ecLibrary)

plt(_ZN7ecFrame6RenderERK7ecMtx32)

plt(_ZN7ecFrame9NextFrameEv)

plt(_ZN7ecFrame5ResetEv)

plt(_ZN7ecFrameD2Ev)

plt(_ZN7ecFrameD1Ev)

plt(_ZN7ecFrameD0Ev)

plt(_ZN7ecFrameC2Ev)
