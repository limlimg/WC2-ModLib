#include <stddef.h>
#include <dlfcn.h>
#include "easytech.h"

#define got(name) __attribute__((visibility("hidden"))) size_t easytech(name) = (size_t)lazybind;
#define bss(name, size) __attribute__((weak)) __attribute__((visibility("protected"))) char name[size];

#define plt(name) __attribute__((naked)) __attribute__((weak)) __attribute__((visibility("protected"))) void name() {asm(\
        "ldr.w r12, [pc, #8]\n\t"\
        "add r12, pc\n\t"\
        "ldr pc, [r12]\n\t"\
        ".align 2\n\t"\
        ".long "__easytech(name)" - (. -4)\n\t");}

#define Thn(name, offset) __attribute__((naked)) __attribute__((weak)) __attribute__((visibility("protected"))) void _ZThn##offset##_##name() {asm(\
        "sub r0, #"#offset"\n\t"\
        "b _Z"#name"\n\t");}

#define off(name, offset) easytech(name) = BaseAddress + offset;

static const char GameLib[] = "libeasytech.so";

void __attribute__((naked)) __attribute__((visibility("hidden"))) lazybind() {
    asm(
    "push {r0-r3,r12,lr}\n\t"
    "bl resolvesymbol\n\t"
    "pop {r0-r3,r12,lr}\n\t"
    "ldr pc, [r12]\n\t");
}

got(_ZN7_JNIEnv14ExceptionClearEv)

got(_ZN7_JNIEnv14DeleteLocalRefEP8_jobject)

got(_ZN7_JNIEnv16CallObjectMethodEP8_jobjectP10_jmethodIDz)

got(_ZN7_JNIEnv23CallStaticBooleanMethodEP7_jclassP10_jmethodIDz)

got(_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz)

got(_ZN7_JNIEnv21CallStaticFloatMethodEP7_jclassP10_jmethodIDz)

got(_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz)

got(_ZN7_JNIEnv12NewStringUTFEPKc)

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

got(_ZN15ecMultipleTouch5ResetEv)

got(_ZN15ecMultipleTouch10TouchBeganEff)

got(_Z12ecTouchBeginffi)

got(_ZN15ecMultipleTouch10TouchEndedEff)

got(_Z10ecTouchEndffi)

got(_ZN15ecMultipleTouch10TouchMovedEff)

got(_Z11ecTouchMoveffi)

got(_ZN10CCommander8BuyMedalEi)

got(_ZN10CCommander4SaveEv)
bss(g_Commander, 376)

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

got(_ZN10ecGraphics12RenderCircleEfffm)

got(_ZN10ecGraphics4FadeEf)

got(_ZN10ecGraphicsD2Ev)

got(_ZN10ecGraphicsD1Ev)

got(_ZN10ecGraphics11LoadTextureEPKc)

got(_Z13ecTextureLoadPKcRiS1_Rj)

got(_ZN10ecGraphics14LoadPVRTextureEPKc)

got(_Z16ecPVRTextureLoadPKcRiS1_Rj)

got(_ZN10ecGraphics14LoadETCTextureEPKc)

got(_Z16ecETCTextureLoadPKcRiS1_Rj)

got(_ZN10ecGraphics15LoadWEBPTextureEPKc)

got(_Z17ecWEBPTextureLoadPKcRiS1_Rj)

got(_ZN15ecMultipleTouchD2Ev)

got(_ZN15ecMultipleTouchD1Ev)

got(_ZN15ecMultipleTouchC2Ev)

got(_ZN15ecMultipleTouchC1Ev)

got(_ZN6ecFileC2Ev)

got(_ZN3MD5C1Ev)

got(_ZN6ecFile5CloseEv)

got(_ZN6ecFileD2Ev)

got(_ZN6ecFile4OpenEPKcS1_)

got(_ZN6ecFile4ReadEPvm)

got(_ZN6ecFile5WriteEPKvm)

got(_ZN6ecFile4SeekEli)

got(_ZN6ecFile9GetCurPosEv)

got(_ZN6ecFile7GetSizeEv)

got(_ZN6ecFile12CheckJavaDexEv)

got(_ZN6ecFile18GetFileDataFromZipEPKcS1_Pm)

got(_ZN3MD55resetEv)

got(_ZN3MD56updateEPKvj)

got(_ZN3MD58toStringEv)

got(_ZN8CheckMD5C1Ev)

got(_ZN8CheckMD56INfileEPKcS1_)

got(_ZN6ecFile21CheckFileExistFromZipEPKcS1_)

got(_ZN3MD5C2Ev)

got(_ZN3MD56encodeEPKmPhj)

got(_ZN3MD56decodeEPKhPmj)

got(_ZN3MD59transformEPKh)

got(_ZN3MD56updateEPKhj)

got(_ZN3MD5C2EPKvj)

got(_ZN3MD5C1EPKvj)

got(_ZN3MD56updateERSt14basic_ifstreamIcSt11char_traitsIcEE)

got(_ZN3MD5C2ERSt14basic_ifstreamIcSt11char_traitsIcEE)

got(_ZN3MD5C1ERSt14basic_ifstreamIcSt11char_traitsIcEE)

got(_ZN3MD56updateERKSs)

got(_ZN3MD5C2ERKSs)

got(_ZN3MD5C1ERKSs)

got(_ZN3MD55finalEv)

got(_ZN3MD56digestEv)

got(_ZN3MD516bytesToHexStringEPKhj)

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

got(_ZN14CPlayerManager7ReleaseEv)

got(_ZN9ecUniFont7ReleaseEv)

got(_ZN10CCSoundBox8UnloadSEEPKc)

got(_ZN13CStateManager4TermEv)

got(_ZN10GUIManager8InstanceEv)

got(_ZN10GUIElement12FreeAllChildEv)

got(_ZN10GUIManager16ReleaseTexureResEv)

got(_ZN10CCSoundBox7DestroyEv)

got(_ZN10CObjectDef8InstanceEv)

got(_ZN10CObjectDef7DestroyEv)

got(_ZN13ecStringTable5ClearEv)
bss(g_PlayerManager, 144)
bss(g_Font1, 40)
bss(g_Font2, 40)
bss(g_Font3, 40)
bss(g_Font6, 40)
bss(g_Font7, 40)
bss(g_Num1, 40)
bss(g_Num3, 40)
bss(g_Num4, 40)
bss(g_Num4b, 40)
bss(g_Num5, 40)
bss(g_Num8, 40)
bss(g_StringTable, 24)
bss(g_LocalizableStrings, 24)

got(_Z13ecGameWaitingb)

got(_ZN13CStateManager15EnterBackgroundEv)

got(_ZN10CCSoundBox14SetMusicVolumeEi)

got(_ZN10CCSoundBox11SetSEVolumeEi)

got(_ZN10CCSoundBox11ResumeMusicEv)

got(_ZN13CStateManager15EnterForegroundEv)
bss(g_GameSettings, 24)

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

got(_ZN6CScene4MoveEii)

got(_ZN13CTouchInertia4StopEv)

got(_ZN7CCamera13SetAutoFixPosEb)

got(_ZN15ecEffectManager8InstanceEv)

got(_ZN15ecEffectManager6UpdateEf)

got(_ZN6CScene6UpdateEf)
bss(g_Scene, 232)

got(_ZN10CEditState6RenderEv)

got(_ZN6CScene6RenderEv)

got(_ZN6CScene15RenderAreasTypeEv)

got(_ZN6CScene14RenderAreasTaxEv)

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

got(_ZN12CGameManager7NewGameEiiii)

got(_ZN9CSoundRes4LoadEv)

got(_ZN8CGameRes4LoadEv)

got(_ZN6CScene4InitEPKci)

got(_ZN13CTouchInertia4InitEv)
bss(g_GameManager, 212)
bss(g_SoundRes, 92)
bss(g_GameRes, 712)

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

got(_ZN9CActionAI8InstanceEv)
bss(_ZN9CActionAI9_instanceE, 4)

got(_ZN9CActionAI8getMedalEiP5CArea)

got(_Z9GetAIRandv)

got(_Z11GetRandSeedv)

got(_Z7GetRandv)

got(_ZN6CFightC2Ev)

got(_ZN6CFightC1Ev)

got(_ZN6CFightD2Ev)

got(_ZN6CFightD1Ev)

got(_ZN6CFight16AirStrikesAttackEP8CCountryii)

got(_ZN6CScene7GetAreaEi)

got(_ZN10CObjectDef10GetArmyDefEiPKc)

got(_ZN8CCountry16GetWarMedalLevelE11WARMEDAL_ID)

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

got(_ZN5CArmy6AddExpEi)

got(_ZN5CArea23ReduceConstructionLevelEv)

got(_ZN5CArea10OccupyAreaEPS_)

got(_ZN5CArmy12BreakthroughEv)

got(_ZN5CArmy6IsNavyEv)

got(_ZN8CCountry13IsLocalPlayerEv)

got(_ZN6CScene9GainMedalEff)

got(_ZN9CSoundRes10PlayCharSEE10SND_EFFECT)

got(_ZN5CArea19DestroyConstructionEv)

got(_ZN5CArea12ClearAllArmyEv)

got(_ZN15ecEffectManager9AddEffectEPKcb)

got(_ZN8ecEffect6FireAtEfff)

got(_ZN13CFightTextMgr7AddTextEffPKcm)
bss(g_FightTextMgr, 64)

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

got(_ZN10CFightText4InitEffP9ecUniFont)

got(_ZN6ecText4InitEP9ecUniFont)

got(_ZN10CFightText7SetTextEPKc)

got(_ZN6ecText7SetTextEPKc)

got(_ZN10CFightText8SetColorEm)

got(_ZN6ecText8SetColorEm)

got(_ZN10CFightText6UpdateEf)

got(_ZN6ecText8SetAlphaEf)

got(_ZN10CFightText6RenderEv)

got(_ZN6ecText8DrawTextEffi)

got(_ZN13CFightTextMgr6UpdateEf)

got(_ZN13CFightTextMgr6RenderEv)

got(_ZN9TFreeListI10CFightTextED2Ev)

got(_ZN9TFreeListI10CFightTextED1Ev)

got(_ZN9TFreeListI10CFightTextE7FreeAllEv)

got(_ZN13CFightTextMgr4InitEv)

got(_ZN13CFightTextMgrD2Ev)

got(_ZN9ecUniFontD1Ev)

got(_ZN13CFightTextMgrD1Ev)

got(_ZN13CFightTextMgr7ReleaseEv)

got(_ZN13CFightTextMgrC2Ev)

got(_ZN9ecUniFontC1Ev)

got(_ZN13CFightTextMgrC1Ev)

got(_ZN13CActionAssistD2Ev)

got(_ZN13CActionAssistD1Ev)

got(_ZN12CGameManagerD2Ev)

got(_ZN12CGameManagerD1Ev)

got(_ZN13TiXmlDocumentD2Ev)

got(_ZN9TiXmlNodeD2Ev)
bss(_ZN11TiXmlString8nullrep_E, 12)

got(_ZN13TiXmlDocumentD1Ev)

got(_ZN13TiXmlDocumentD0Ev)

got(_ZN13CActionAssist8InstanceEv)
bss(_ZN13CActionAssist9_instanceE, 4)

got(_ZN9CActionAI6InitAIEv)

got(_ZN6CScene11GetNumAreasEv)

got(_Z13GetNumBattlesi)

got(_Z16GetBattleKeyNameiiPc)

got(_Z18GetConquestKeyNameiPc)

got(_Z17GetBattleFileNameiiiiPc)

got(_Z24GetNumMultiPlayerBattlesi)

got(_Z24GetBattleBelligerentListPKcRSt4listI11BelligerentSaIS2_EEb)

got(_ZN13TiXmlDocumentC1EPKc)

got(_ZN13TiXmlDocument8LoadFileE13TiXmlEncoding)

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

got(_ZN8CCountry16GetCommanderNameEv)

got(_ZN12TiXmlElement18SetDoubleAttributeEPKcd)

got(_ZN9TiXmlNode12LinkEndChildEPS_)

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

got(_ZN10CGameState14HideAIProgressEv)

got(_ZN12CGameManager4NextEv)

got(_ZN9CActionAI16setCpuDriverbyIdEii)

got(_ZN14CPlayerManager13DoFrontActionEv)

got(_ZN5CArea13SetArmyActiveEib)

got(_ZN12CGameManager10GameUpdateEf)

got(_ZN8CCountry6UpdateEf)

got(_ZN10CGameState12ShowDefeatedEP8CCountry)

got(_ZN10CGameState16UpdateAIProgressEv)

got(_ZN12CGameManager12RealLoadGameEPKc)

got(_ZN8CCountryC1Ev)

got(_ZN8CCountry4InitEPKcS1_)

got(_ZN8CCountry11LoadCountryEPK15SaveCountryInfo)

got(_ZN5CArea8LoadAreaEPK12SaveAreaInfo)

got(_ZN8CCountry7AddAreaEi)

got(_ZN7CCamera6SetPosEffb)

got(_ZN12CGameManager10LoadBattleEPKc)

got(_ZNK12TiXmlElement20QueryDoubleAttributeEPKcPd)

got(_ZN14CPlayerManager21FindPlayerByCountryIDEPKc)

got(_ZN8CCountry12SetCommanderEPKc)

got(_ZN6CScene14SetAreaCountryEiP8CCountry)

got(_ZN5CArea15SetConstructionEii)

got(_ZN5CArmyC1Ev)

got(_ZN5CArmy4InitEP7ArmyDefP8CCountry)

got(_ZN5CArea7AddArmyEP5CArmyb)

got(_ZN5CArmy16ResetMaxStrengthEb)

got(_ZN12CGameManager24MovePlayerCountryToFrontEv)

got(_ZN12CGameManager10InitBattleEv)

got(_ZN14CPlayerManager18SetPlayerOfCountryEv)

got(_ZN6CScene20AllAreasEncirclementEv)

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

got(_ZN14CPlayerManager22SendPacketToAllPlayersE9PACKET_IDPKvi)

got(_ZN6GUITax7SetAreaEi)

got(_ZN5CArea8IsActiveEv)

got(_ZN6CScene13CheckMoveableEiii)

got(_ZN10GUIElement4HideEv)

got(_ZN10GUIElement4ShowEv)

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

got(_ZN13GUIActionInfoC1Ev)

got(_ZN13GUIActionInfo4InitERK7GUIRect)

got(_ZN11GUIDefeatedC1Ev)

got(_ZN11GUIDefeated4InitERK7GUIRect)

got(_ZN9GUIBattleC1Ev)

got(_ZN9GUIBattle4InitERK7GUIRect)

got(_ZN12GUITutorailsC1Ev)

got(_ZN12GUITutorails4InitERK7GUIRect)

got(_ZN11GUIDialogueC1Ev)

got(_ZN11GUIDialogue4InitERK7GUIRect)

got(_ZN16GUIMotionManager9AddMotionEP10GUIElementffft)

got(_ZN10CCSoundBox9LoadMusicEPKcS1_)

got(_ZN10CCSoundBox9PlayMusicEb)

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

got(_ZN10GUIBuyCard13CanBuySelCardEv)

got(_ZN10GUIBuyCard15ResetCardTargetEv)

got(_ZN10GUIBuyCard13ReleaseTargetEv)

got(_ZN6CScene9IsBombingEv)

got(_ZN14CPlayerManager13GetNumActionsEv)

got(_ZN14CPlayerManager22IsDisconnectedFromHostEv)

got(_ZN13GUIActionInfo7SetInfoEPKc)

got(_ZN10CGameState15ResetTouchStateEv)

got(_ZN10CGameState11BackPressedEv)

got(_ZN10GUIManager7FadeOutEiP10GUIElement)

got(_ZN10CGameState10TouchBeginEffi)

got(_ZN10CGameState7OnEventERK5Event)

got(_ZN10GUIBuyCard14ResetCardStateEv)

got(_ZN10GUIOptionsC1Ev)

got(_ZN10GUIOptions4InitERK7GUIRect)

got(_ZN7GUISaveC1Ev)

got(_ZN7GUISave4InitERK7GUIRectib)

got(_ZN10GUIManager13SafeFreeChildEP10GUIElement)

got(_ZN6GUIEndC1Ev)

got(_ZN6GUIEnd4InitERK7GUIRect)

got(_ZN14GUIBattleIntroC1Ev)

got(_ZN14GUIBattleIntro4InitERK7GUIRectii)

got(_ZN16GUIMotionManager12ActiveMotionEmh)

got(_ZN14CPlayerManager18SendPacketToServerE9PACKET_IDPKvi)

got(_ZN14CPlayerManager16PlayerLoadFinishEP7CPlayer)

got(_ZN9GUIResultC1Ev)

got(_ZN9GUIResult4InitERK7GUIRecti)

got(_ZN6GUIIapC1Ev)

got(_ZN6GUIIap4InitERK7GUIRect)

got(_ZN12GUISmallCard7SetCardEP7CardDef)

got(_ZN11GUIDefeated12HideDefeatedEv)

got(_ZN10GUIVictoryC1Ev)

got(_ZN10GUIVictory4InitERK7GUIRectb)

got(_ZN10GUIVictory4PlayEv)

got(_ZN7GUIBankC1Ev)

got(_ZN7GUIBank4InitERK7GUIRect)

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
bss(_ZN10GUIElement12s_TextureResE, 48)

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

got(_ZN7ecImageC1EP9ecTextureRK13ecTextureRect)

got(_ZN11GUICardListC1Ev)

got(_ZN11GUICardList4InitERK7GUIRecti)

got(_ZN10GUIBuyCard15SetSelCardIntroEv)

got(_ZN10CObjectDef10GetCardDefE7CARD_ID)

got(_ZN8CCountry10CanBuyCardEP7CardDef)

got(_ZN8CCountry12GetCardPriceEP7CardDef)

got(_ZN8CCountry15GetCardIndustryEP7CardDef)

got(_ZN11GUICardList7GetCardEi)

got(_ZN8CCountry13IsEnoughMoneyEP7CardDef)

got(_ZN7GUICard13SetPriceColorEm)

got(_ZN8CCountry16IsEnoughIndustryEP7CardDef)

got(_ZN7GUICard16SetIndustryColorEm)

got(_ZN7GUICard8SetPriceEi)

got(_ZN7GUICard11SetIndustryEi)

got(_ZN8CCountry15CanUseCommanderEv)

got(_ZN8CCountry13GetCardRoundsE7CARD_ID)

got(_ZN10GUIElement9SetEnableEb)

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

got(_ZN11GUICardList8OnUpdateEf)

got(_ZN11GUICardListD2Ev)

got(_ZN11GUICardListD1Ev)

got(_ZN11GUICardListD0Ev)

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

got(_ZN15GUIProductPriceD2Ev)

got(_ZN15GUIProductPriceD1Ev)

got(_ZN15GUIProductPriceD0Ev)

got(_ZN15GUIProductPrice8OnRenderEv)

got(_ZN6GUIIapD2Ev)

got(_ZN6GUIIapD1Ev)

got(_ZN6GUIIapD0Ev)

got(_ZN6GUIIap7OnEventERK5Event)

got(_ZN6GUIIap8OnRenderEv)

got(_ZN15GUIProductPriceC2Ev)

got(_ZN15GUIProductPriceC1Ev)

got(_ZN15GUIProductPrice4InitERK7GUIRect)

got(_ZN11ecLabelText8SetColorEm)

got(_ZN15GUIProductPrice14SetLocalePirceEPKc)

got(_ZN6GUIIapC2Ev)

got(_ZN9GUIButton7SetTextEPKc)

got(_ZN9GUIButton12SetTextColorEm)

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

got(_ZNK12TiXmlElement19QueryFloatAttributeEPKcPf)

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

got(_ZN6CScene16MoveCameraToAreaEi)

got(_ZN6CScene22MoveCameraCenterToAreaEi)

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

got(_ZN10GUILoadingC1Ev)

got(_ZN10GUILoading4InitERK7GUIRect)

got(_ZN14CPlayerManager14DestroySessionEv)

got(_ZN14CPlayerManager12SetupSessionEb)

got(_ZN11GUIMainMenu6ShowADEv)

got(_ZN12GUICommanderC1Ev)

got(_ZN12GUICommander4InitERK7GUIRect)

got(_ZN10GUIElement9FreeChildEPS_)

got(_ZN13GUISelCountryC1Ev)

got(_ZN13GUISelCountry4InitERK7GUIRecti)

got(_ZN11GUIHostList17ResetConnectStateEv)

got(_ZN11GUIHostListC1Ev)

got(_ZN11GUIHostList4InitERK7GUIRect)

got(_ZN14CPlayerManager9InitCorpsEi)

got(_ZN10GUIServiceC1Ev)

got(_ZN10GUIService4InitERK7GUIRect)

got(_ZN11GUIMainMenu13RefreshNewTipEv)

got(_ZN10GUINewGameC1Ev)

got(_ZN10GUINewGame4InitERK7GUIRect)

got(_ZN14CPlayerManager10StartMatchEv)

got(_ZN14CPlayerManager9StopMatchEv)

got(_ZN16GUILockedWarningC1Ev)

got(_ZN16GUILockedWarning4InitERK7GUIRect)

got(_ZN10CMenuState11ShowWarningEi)

got(_ZN14GUIExitWarningC1Ev)

got(_ZN14GUIExitWarning4InitERK7GUIRect)

got(_ZN10CObjectDefC2Ev)

got(_ZN10CObjectDefC1Ev)
bss(_ZN10CObjectDef10m_InstanceE, 4)

got(_ZN10CObjectDef11LoadCardDefEv)

got(_ZN10CObjectDef14ReleaseArmyDefEv)

got(_ZN10CObjectDef18ReleaseUnitMotionsEv)

got(_ZN10CObjectDef20ReleaseUnitPositionsEv)

got(_ZN10CObjectDef19ReleaseCommanderDefEv)

got(_ZN10CObjectDef20ReleaseGeneralPhotosEv)

got(_ZN10CObjectDef17ReleaseBattleListEv)

got(_ZN10CObjectDef19ReleaseConquestListEv)

got(_ZN10CObjectDef7ReleaseEv)

got(_ZN10CObjectDefD2Ev)

got(_ZN10CObjectDefD1Ev)

got(_ZN10CObjectDef14GetConquestDefEPKc)

got(_ZN10CObjectDef14GetUnitMotionsEPKcS1_)

got(_ZN10CObjectDef15GetCommanderDefEPKc)

got(_ZN10CObjectDef16GetUnitPositionsEPKc)

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

got(_ZN14CPlayerManager13CancelConnectEv)

got(_ZN18ecSessionInterface13CancelConnectEv)

got(_ZN9ecGameKit25ShowMatchmakerWithRequestEiii)

got(_ZN14CPlayerManager9AddPlayerEbPKc)

got(_ZN7CPlayerC1Ev)

got(_ZN7CPlayer4InitEbPKc)

got(_ZN18ecSessionInterfaceC1Ev)

got(_ZN18ecSessionInterface4InitEP17ecSessionDelegate)

got(_ZN18ecSessionInterface12SetupSessionEb)

got(_ZN18ecSessionInterface13GetDeviceNameERSs)

got(_ZN14CPlayerManager10FindPlayerEPKc)

got(_ZN14CPlayerManager20onPlayerInfoReceivedERSt4listIP12ecPlayerInfoSaIS2_EE)

got(_ZN14CPlayerManager16FindPlayerByUUIDEi)

got(_ZN14CPlayerManager17DidRecvInvitationEPKc)

got(_ZN18ecSessionInterface11GetPeerNameEPKcRSs)

got(_ZN18ecSessionInterface16AcceptInvitationEPKc)

got(_ZN18ecSessionInterface17DeclineInvitationEPKc)

got(_ZN14CPlayerManager21GetDisconnectedPlayerEv)

got(_ZN14CPlayerManager18SendPacketToPlayerE12PacketHeaderPKviPKc)

got(_ZN18ecSessionInterface10SendPacketEPKviPKc)

got(_ZN9ecGameKit10SendPacketEPKviPKc)

got(_ZN14CPlayerManager18SendPacketToPlayerE9PACKET_IDPKviP7CPlayer)

got(_ZN14CPlayerManager28SendPacketToAllPlayersExceptE9PACKET_IDPKviP7CPlayer)

got(_ZN7CPlayer10SendPacketE9PACKET_IDPKvi)

got(_ZN7CPlayer10PushPacketE9PACKET_IDPKvi)

got(_ZN14CPlayerManager10ClearCorpsEv)

got(_ZN14CPlayerManager12GetLeftCorpsEi)

got(_ZN14CPlayerManager13GetRightCorpsEi)

got(_ZN14CPlayerManager15GetNumLeftCorpsEv)

got(_ZN14CPlayerManager16GetNumRightCorpsEv)

got(_ZN14CPlayerManager8SelCorpsEiiP7CPlayer)

got(_ZN14CPlayerManager17RemoveCorpsPlayerEii)

got(_ZN14CPlayerManager17RemoveCorpsPlayerEP7CPlayer)

got(_ZN14CPlayerManager12RemovePlayerEP7CPlayer)

got(_ZN7CPlayerD1Ev)

got(_ZN14CPlayerManager20onPlayerDisconnectedEPKc)

got(_ZN14CPlayerManager12GetCorpsDataERi)

got(_ZN14CPlayerManager15onPeerConnectedEPKc)

got(_ZN13GUIMatchSetup18RefreshCorsButtonsEv)

got(_ZN14CPlayerManager14SetCorpsByDataEPviP7CPlayer)

got(_ZN14CPlayerManager17IsAllPlayersReadyEv)

got(_ZN14CPlayerManager23RefreshAndSendCorpsDataEv)

got(_ZN14CPlayerManager18onPeerDisconnectedEPKc)

got(_ZN14CPlayerManager14SendRoundBeginEv)

got(_ZN14CPlayerManager18ClearRemotePlayersEv)

got(_ZN14CPlayerManager12ClearPlayersEv)

got(_ZN18ecSessionInterfaceD1Ev)

got(_ZN9ecGameKitD1Ev)

got(_ZN9ecGameKit22DisconnectCurrentMatchEv)

got(_ZN14CPlayerManager16onAcceptedInviteEv)

got(_ZN14CPlayerManager13WillTerminateEv)

got(_ZN11GUIHostList13ClearHostListEv)

got(_ZN14CPlayerManagerD2Ev)

got(_ZN14CPlayerManagerD1Ev)

got(_ZN14CPlayerManager19onPeerListDidChangeEv)

got(_ZN18ecSessionInterface15GetPeerNameListERSt4listISsSaISsEES3_)

got(_ZN11GUIHostList15RefreshHostListEv)

got(_ZN14CPlayerManager9ReconnectEv)

got(_ZN7CPlayer9SendFirstEv)

got(_ZN14CPlayerManager12onMatchFoundEv)

got(_ZN9ecGameKit18GetMatchPlayerListERSt4listISsSaISsEE)

got(_ZN14CPlayerManager12onStartMatchEv)

got(_ZN9ecGameKit18GetLocalPlayerInfoER12ecPlayerInfo)

got(_ZN9ecGameKit19GetMatchPlayersInfoEv)

got(_ZN14CPlayerManager16ClearActionQueueEv)

got(_ZN14CPlayerManager14onReceivedDataEPKviPKcb)

got(_ZN7CPlayer7RecvAckEi)

got(_ZN7CPlayer7SendAckEi)

got(_ZN13GUIMatchSetup16CreatCorsButtonsEv)

got(_ZN14CPlayerManager22onReveivedDataFromPeerEPKviPKc)

got(_ZN14CPlayerManager24onReceivedDataFromPlayerEPKviPKc)

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

got(_ZN6CMedal5UpateEf)

got(_ZN5CArea6UpdateEf)

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

got(_ZN8CCountry15AirstrikeRadiusEv)

got(_ZN7ecImage9Render4VCEffffffffif)

got(_ZN6CMedal6RenderEv)

got(_ZN7CBomber6RenderEv)

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

got(_ZN13CActionAssist21purChaseAirStrikeCardEv)

got(_ZN13CActionAssist17purChaseDraftCardEb)

got(_ZN13CActionAssist16purChaseFortCardEv)

got(_ZN13CActionAssist17purChaseCardsCardEv)

got(_ZN13CActionAssist21purChaseConstructCardEv)

got(_ZN9CActionAI15sortArmyToFrontEv)

got(_ZN5CArea12IsArmyActiveEi)

got(_ZN9CActionAI8getMaxIdEv)

got(_ZN9CActionAI13setArmyActionEP5CArea)

got(_ZN13CActionAssist16actionToNextAreaEiiii)

got(_ZN9CActionAI13moveAndAttackEv)

got(_ZN13CActionAssist13calcAreaValueEP5CArea)

got(_ZN13CActionAssist15aiCheckMoveableEiiii)

got(_Z13GetAIRandSeedv)

got(_ZN13CActionAssist9isBuyCardEP7CardDef)

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

got(_ZN8CCountryD2Ev)

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

got(_ZN17GUICommanderMedal13SetArrowColorEm)

got(_ZN11GUIWarMedalC2Ev)

got(_ZN11GUIWarMedalC1Ev)

got(_ZN11GUIWarMedal8SetLevelEi)

got(_ZN11GUIWarMedal4InitERK7GUIRect11WARMEDAL_IDi)

got(_ZN11GUIWarMedal13SetArrowColorEm)

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

got(_ZN11GUIHostItemD2Ev)

got(_ZN11GUIHostItemD1Ev)

got(_ZN11GUIHostItemD0Ev)

got(_ZN11GUIHostList8OnRenderEv)

got(_ZN19GUIConnectHostState8OnRenderEv)

got(_ZN11GUIHostListD2Ev)

got(_ZN11GUIHostListD1Ev)

got(_ZN11GUIHostListD0Ev)

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

got(_ZN13GUIBattleListC1Ev)

got(_ZN13GUIBattleList4InitERK7GUIRecti)

got(_ZN13GUIBattleList18SelectLastUnlockedEv)

got(_ZN13GUIBattleList9SetSelectEi)

got(_ZN12GUISelBattle13LoadImageListEii)

got(_ZN12GUISelBattleC2Ev)

got(_ZN12GUISelBattle16ReleaseImageListEv)

got(_ZN12GUISelBattleD2Ev)

got(_ZN12GUISelBattleD1Ev)

got(_ZN12GUISelBattleD0Ev)

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

got(_ZN13GUIBattleList8OnUpdateEf)

got(_ZN13GUIBattleListD2Ev)

got(_ZN13GUIBattleListD1Ev)

got(_ZN13GUIBattleListD0Ev)

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

got(_ZN14GUICountryList8OnUpdateEf)

got(_ZN14GUICountryListD2Ev)

got(_ZN14GUICountryListD1Ev)

got(_ZN14GUICountryListD0Ev)

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

got(_ZN10GUIElement12FindByHandleEm)

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

got(_ZN16GUIMotionManager9SetMotionEmffffft)

got(_ZN16GUIMotionManager9AddMotionEP10GUIElementffffft)

got(_ZN16GUIMotionManager10AddMotionXEP10GUIElementfft)

got(_ZN16GUIMotionManager10AddMotionYEP10GUIElementfft)

got(_ZN16GUIMotionManager8SetSpeedEmff)

got(_ZN16GUIMotionManager15GetMotionActiveEm)

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

got(_ZN7GUIText12SetTextColorEm)

got(_ZN9ecGameKitC2Ev)

got(_ZN9ecGameKitD2Ev)

got(_ZN9ecGameKit7ReleaseEv)

got(_ZN9ecGameKit22SendPacketToAllPlayersEPKvi)

got(_ZN18ecSessionInterfaceC2Ev)

got(_ZN18ecSessionInterfaceD2Ev)

got(_ZN18ecSessionInterface7ReleaseEv)

got(_ZN18ecSessionInterface10DisconnectEPKc)

got(_ZN18ecSessionInterface20SendPacketToAllPeersEPKvi)

got(_ZN11TiXmlString4quitEv)

got(_ZN11TiXmlString7reserveEj)

got(_ZN11TiXmlString6assignEPKcj)

got(_ZN11TiXmlString6appendEPKcj)

got(_ZN11TiXmlStringpLERKS_)

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

got(_ZNK12TiXmlUnknown5PrintEP7__sFILEi)

got(_ZNK16TiXmlDeclaration5PrintEP7__sFILEi)

got(_ZNK12TiXmlComment5PrintEP7__sFILEi)

got(_ZN11TiXmlStringC2EPKc)

got(_ZN11TiXmlStringC1EPKc)

got(_ZN11TiXmlStringaSEPKc)

got(_ZN11TiXmlStringpLEPKc)

got(_ZNK12TiXmlComment9StreamOutEP14TiXmlOutStream)

got(_ZNK12TiXmlUnknown9StreamOutEP14TiXmlOutStream)

got(_ZNK11TiXmlString4findEc)

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

got(_ZN16TiXmlDeclarationD0Ev)

got(_ZN9TiXmlTextD2Ev)

got(_ZN9TiXmlTextD1Ev)

got(_ZN9TiXmlTextD0Ev)

got(_ZN12TiXmlCommentD2Ev)

got(_ZN12TiXmlCommentD1Ev)

got(_ZN12TiXmlCommentD0Ev)

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

got(_ZN11TiXmlStringpLEc)

got(_ZN14TiXmlAttributeD2Ev)

got(_ZN14TiXmlAttributeD1Ev)

got(_ZN14TiXmlAttributeD0Ev)

got(_ZN9TiXmlBase12IsWhiteSpaceEc)

got(_ZN9TiXmlBase18ConvertUTF32ToUTF8EmPcPi)

got(_ZN9TiXmlBase7IsAlphaEh13TiXmlEncoding)

got(_ZN9TiXmlBase10IsAlphaNumEh13TiXmlEncoding)

got(_ZN16TiXmlParsingData5StampEPKc13TiXmlEncoding)

got(_ZN9TiXmlBase14SkipWhiteSpaceEPKc13TiXmlEncoding)

got(_ZN9TiXmlBase8ReadNameEPKcP11TiXmlString13TiXmlEncoding)

got(_ZN9TiXmlBase9GetEntityEPKcPcPi13TiXmlEncoding)

got(_ZN9TiXmlBase7GetCharEPKcPcPi13TiXmlEncoding)

got(_ZN9TiXmlBase11StringEqualEPKcS1_b13TiXmlEncoding)

got(_ZN9TiXmlBase8ReadTextEPKcP11TiXmlStringbS1_b13TiXmlEncoding)

got(_ZN14TiXmlAttribute5ParseEPKcP16TiXmlParsingData13TiXmlEncoding)

got(_ZN9TiXmlNode8IdentifyEPKc13TiXmlEncoding)

got(_ZN13TiXmlDocument5ParseEPKcP16TiXmlParsingData13TiXmlEncoding)

got(_ZNK9TiXmlText5BlankEv)

got(_ZN12TiXmlElement9ReadValueEPKcP16TiXmlParsingData13TiXmlEncoding)

got(_ZN9hgeVector9NormalizeEv)

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

got(_ZN12ecTextureRes11CreateImageEPKcS1_ffffff)

got(_ZN12ecTextureRes11CreateImageEPKcP9ecTextureffffff)

got(_ZN11ecEffectResC2Ev)

got(_ZN11ecEffectResC1Ev)

got(_ZN11ecEffectRes7ReleaseEv)

got(_ZN11ecEffectResD2Ev)

got(_ZN11ecEffectResD1Ev)

got(_ZN11ecEffectRes10LoadEffectEPKcP12ecTextureRes)

got(_ZN18ecEffectResManager16ReleaseEffectResEP11ecEffectRes)

got(_ZN18ecEffectResManagerD2Ev)

got(_ZN18ecEffectResManagerD1Ev)

got(_ZN18ecEffectResManagerC2Ev)

got(_ZN18ecEffectResManagerC1Ev)

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

got(_ZN9TFreeListI16ecParticleSystemED2Ev)

got(_ZN16ecParticleSystemD1Ev)

got(_ZN9TFreeListI16ecParticleSystemED1Ev)

got(_ZN15ecEffectManagerD2Ev)

got(_ZN15ecEffectManagerD1Ev)

got(_ZN15ecEffectManagerC2Ev)

got(_ZN16ecParticleSystemC1Ev)

got(_ZN15ecEffectManagerC1Ev)

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
bss(_ZN10CCSoundBox9mInstanceE, 4)

got(_ZN10CCSoundBox18DestroySoundSystemEv)

got(_ZN10CCSoundBox9StopMusicEv)

got(_ZN10CCSoundBox9StopAllSEEv)

got(_ZN13ecStringTableC2Ev)

got(_ZN13ecStringTableD2Ev)

got(_ZN6ecTextC2Ev)

got(_ZN6ecTextD2Ev)

got(_ZN6ecText11GetNumLinesEv)

got(_Z22ecSetIdleTimerDisabledb)

got(_Z10ColorClampRf)

got(_ZN16ecParticleSystemC2Ev)

got(_ZN16ecParticleSystemD2Ev)

got(_ZN9ecLibraryC2Ev)

got(_ZN9ecLibrary11GetItemDataEi)

got(_ZN9ecLibrary14GetElementDataEi)

got(_ZN9ecLibrary12GetFrameDataEi)

got(_ZN9ecLibrary12GetLayerDataEi)

got(_ZN9ecLibrary11GetItemNameEm)

got(_ZN9ecLibraryD2Ev)

got(_ZN7ecShapeD1Ev)

got(_ZN9ecLibraryD1Ev)

got(_ZN9ecLibraryD0Ev)

got(_ZN9ecLibrary12FindItemDataEPKc)

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

got(_ZN7ecShape8SetColorEm)

got(_ZN7ecLayer6RenderERK7ecMtx32)

got(_ZN7ecShape6RenderERK7ecMtx32)

got(_ZN9ecElement9NextFrameEv)

got(_ZN7ecLayer9NextFrameEv)

got(_Z10ecMtx32MulRfS_RK7ecMtx32)

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

got(_ZN7ecFrame5ResetEv)

got(_ZN7ecFrame9NextFrameEv)

got(_ZN7ecFrameD2Ev)

got(_ZN7ecFrameD1Ev)

got(_ZN7ecFrameD0Ev)

got(_ZN7ecFrameC2Ev)

void __attribute__((visibility("hidden"))) resolvesymbol() {
    size_t BaseAddress = (size_t) dlsym(dlopen(GameLib, RTLD_NOLOAD), "SetLangDir") - 233237;
    off(_ZN7_JNIEnv14ExceptionClearEv, 233365)
    off(_ZN7_JNIEnv14DeleteLocalRefEP8_jobject, 233371)
    off(_ZN7_JNIEnv16CallObjectMethodEP8_jobjectP10_jmethodIDz, 233377)
    off(_ZN7_JNIEnv23CallStaticBooleanMethodEP7_jclassP10_jmethodIDz, 233433)
    off(_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz, 233489)
    off(_ZN7_JNIEnv21CallStaticFloatMethodEP7_jclassP10_jmethodIDz, 233545)
    off(_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz, 233601)
    off(_ZN7_JNIEnv12NewStringUTFEPKc, 233657)
    off(_Z24ecGameDidEnterBackgroundv, 272009)
    off(_Z14ecGameShutdownv, 271641)
    off(_Z7GetPathPKcS0_, 238053)
    off(_Z18ecPurchasedProducti, 272737)
    off(_Z10ecGameInitiiiii, 273097)
    off(_Z18ecSetInAppPurchasePFviE, 272773)
    off(_Z11ecGamePausev, 271965)
    off(_Z25ecGameWillEnterForegroundv, 272037)
    off(_Z12ecGameResumev, 271981)
    off(_Z13ecBackPressedv, 272549)
    off(_ZN13CStateManager8InstanceEv, 395445)
    off(_ZN13CStateManager11GetStatePtrE6EState, 395747)
    off(_ZN10CMenuState8ShowExitEv, 364981)
    off(_Z12ecGameUpdatef, 272093)
    off(_Z12ecGameRenderv, 272173)
    off(_ZN10ecGraphics8InstanceEv, 238469)
    off(_ZN15ecMultipleTouch8InstanceEv, 242129)
    off(_ZN15ecMultipleTouch5ResetEv, 242141)
    off(_ZN15ecMultipleTouch10TouchBeganEff, 242169)
    off(_Z12ecTouchBeginffi, 272257)
    off(_ZN15ecMultipleTouch10TouchEndedEff, 242321)
    off(_Z10ecTouchEndffi, 272449)
    off(_ZN15ecMultipleTouch10TouchMovedEff, 242229)
    off(_Z11ecTouchMoveffi, 272353)
    off(_ZN10CCommander8BuyMedalEi, 271345)
    off(_ZN10CCommander4SaveEv, 271033)
    off(_Z17ecSetProductPriceiPKc, 272713)
    off(_ZN6ecFileC1Ev, 242413)
    off(_ZN6ecFile11IsFlieExistEPKc, 242573)
    off(_ZN6ecFileD1Ev, 242487)
    off(_Z9Get2XPathPKcS0_, 238209)
    off(_Z15GetDocumentPathPKc, 238341)
    off(_Z16GetEditorResPathPKc, 238385)
    off(_ZN10ecGraphicsC2Ev, 238401)
    off(_ZN10ecGraphicsC1Ev, 238401)
    off(_ZN10ecGraphics4InitEiiiii, 238481)
    off(_ZN10ecGraphics8ShutdownEv, 238817)
    off(_ZN10ecGraphics14SetOrientationEi, 238819)
    off(_ZN10ecGraphics11RenderBeginEv, 238841)
    off(_ZN10ecGraphics13CreateTextureEii, 238863)
    off(_ZN10ecGraphics11FreeTextureEP9ecTexture, 238869)
    off(_ZN10ecGraphics5FlushEv, 239077)
    off(_ZN10ecGraphics9RenderEndEv, 239175)
    off(_ZN10ecGraphics12SetViewPointEfff, 239181)
    off(_ZN10ecGraphics12SetBlendModeEi, 239385)
    off(_ZN10ecGraphics11BindTextureEP9ecTexture, 239439)
    off(_ZN10ecGraphics23CreateTextureWithStringEPKcS1_iiii, 239501)
    off(_Z19ecTextureWithStringPKcS0_iiRiS1_Rj, 267825)
    off(_ZN10ecGraphics10RenderLineEPK6ecLine, 239617)
    off(_ZN10ecGraphics12RenderTripleEPK8ecTriple, 239699)
    off(_ZN10ecGraphics10RenderQuadEPK6ecQuad, 239781)
    off(_ZN10ecGraphics10RenderRectEffffm, 239973)
    off(_ZN10ecGraphics12RenderCircleEfffm, 240201)
    off(_ZN10ecGraphics4FadeEf, 240493)
    off(_ZN10ecGraphicsD2Ev, 240747)
    off(_ZN10ecGraphicsD1Ev, 240747)
    off(_ZN10ecGraphics11LoadTextureEPKc, 241265)
    off(_Z13ecTextureLoadPKcRiS1_Rj, 265025)
    off(_ZN10ecGraphics14LoadPVRTextureEPKc, 241473)
    off(_Z16ecPVRTextureLoadPKcRiS1_Rj, 266253)
    off(_ZN10ecGraphics14LoadETCTextureEPKc, 241681)
    off(_Z16ecETCTextureLoadPKcRiS1_Rj, 266713)
    off(_ZN10ecGraphics15LoadWEBPTextureEPKc, 241889)
    off(_Z17ecWEBPTextureLoadPKcRiS1_Rj, 267221)
    off(_ZN15ecMultipleTouchD2Ev, 242097)
    off(_ZN15ecMultipleTouchD1Ev, 242097)
    off(_ZN15ecMultipleTouchC2Ev, 242119)
    off(_ZN15ecMultipleTouchC1Ev, 242119)
    off(_ZN6ecFileC2Ev, 242413)
    off(_ZN3MD5C1Ev, 243529)
    off(_ZN6ecFile5CloseEv, 242453)
    off(_ZN6ecFileD2Ev, 242487)
    off(_ZN6ecFile4OpenEPKcS1_, 242501)
    off(_ZN6ecFile4ReadEPvm, 242645)
    off(_ZN6ecFile5WriteEPKvm, 242697)
    off(_ZN6ecFile4SeekEli, 242729)
    off(_ZN6ecFile9GetCurPosEv, 242767)
    off(_ZN6ecFile7GetSizeEv, 242809)
    off(_ZN6ecFile12CheckJavaDexEv, 242881)
    off(_ZN6ecFile18GetFileDataFromZipEPKcS1_Pm, 242893)
    off(_ZN3MD55resetEv, 243481)
    off(_ZN3MD56updateEPKvj, 245527)
    off(_ZN3MD58toStringEv, 246041)
    off(_ZN8CheckMD5C1Ev, 246069)
    off(_ZN8CheckMD56INfileEPKcS1_, 246073)
    off(_ZN6ecFile21CheckFileExistFromZipEPKcS1_, 243357)
    off(_ZN3MD5C2Ev, 243529)
    off(_ZN3MD56encodeEPKmPhj, 243541)
    off(_ZN3MD56decodeEPKhPmj, 243591)
    off(_ZN3MD59transformEPKh, 243641)
    off(_ZN3MD56updateEPKhj, 245413)
    off(_ZN3MD5C2EPKvj, 245531)
    off(_ZN3MD5C1EPKvj, 245531)
    off(_ZN3MD56updateERSt14basic_ifstreamIcSt11char_traitsIcEE, 245653)
    off(_ZN3MD5C2ERSt14basic_ifstreamIcSt11char_traitsIcEE, 245675)
    off(_ZN3MD5C1ERSt14basic_ifstreamIcSt11char_traitsIcEE, 245675)
    off(_ZN3MD56updateERKSs, 245697)
    off(_ZN3MD5C2ERKSs, 245707)
    off(_ZN3MD5C1ERKSs, 245707)
    off(_ZN3MD55finalEv, 245729)
    off(_ZN3MD56digestEv, 245917)
    off(_ZN3MD516bytesToHexStringEPKhj, 245945)
    off(_ZN8CheckMD5C2Ev, 246069)
    off(_ZN10CCommanderD2Ev, 270725)
    off(_ZN10CCommanderD1Ev, 270725)
    off(_Z19GetCommanderAbilityi, 270729)
    off(_ZN10CCommanderC2Ev, 270753)
    off(_ZN10CCommanderC1Ev, 270753)
    off(_ZN10CCommander4LoadEv, 270813)
    off(_ZN10CCommander15GetUpgradeMedalEv, 271245)
    off(_ZN10CCommander12CheckUpgardeEv, 271269)
    off(_ZN10CCommander7UpgradeEv, 271297)
    off(_ZN10CCommander10IsMaxLevelEv, 271331)
    off(_ZN10CCSoundBox11GetInstanceEv, 567969)
    off(_ZN10CCSoundBox6PlaySEEPKc, 568173)
    off(_ZN10CCommander16GetWarMedalLevelE11WARMEDAL_ID, 271381)
    off(_ZN10CCommander19GetNeedUpgradeMedalE11WARMEDAL_ID, 271389)
    off(_ZN10CCommander20CheckUpgradeWarMedalE11WARMEDAL_ID, 271409)
    off(_ZN10CCommander15UpgradeWarMedalE11WARMEDAL_ID, 271441)
    off(_ZN10CCommander20SetNumPlayedBatttlesEii, 271483)
    off(_ZN10CCommander20GetNumPlayedBatttlesEi, 271491)
    off(_ZN10CCommander15SetBattlePlayedEii, 271499)
    off(_ZN10CCommander17GetNumBattleStarsEii, 271531)
    off(_ZN10CCommander17SetNumBattleStarsEiii, 271557)
    off(_ZN10CCommander16GetCommanderDataER13CommanderData, 271581)
    off(_ZN14CPlayerManager7ReleaseEv, 380599)
    off(_ZN9ecUniFont7ReleaseEv, 566355)
    off(_ZN10CCSoundBox8UnloadSEEPKc, 568167)
    off(_ZN13CStateManager4TermEv, 395481)
    off(_ZN10GUIManager8InstanceEv, 482957)
    off(_ZN10GUIElement12FreeAllChildEv, 481301)
    off(_ZN10GUIManager16ReleaseTexureResEv, 483017)
    off(_ZN10CCSoundBox7DestroyEv, 568029)
    off(_ZN10CObjectDef8InstanceEv, 365365)
    off(_ZN10CObjectDef7DestroyEv, 367213)
    off(_ZN13ecStringTable5ClearEv, 568261)
    off(_Z13ecGameWaitingb, 271997)
    off(_ZN13CStateManager15EnterBackgroundEv, 395705)
    off(_ZN10CCSoundBox14SetMusicVolumeEi, 568097)
    off(_ZN10CCSoundBox11SetSEVolumeEi, 568129)
    off(_ZN10CCSoundBox11ResumeMusicEv, 568091)
    off(_ZN13CStateManager15EnterForegroundEv, 395717)
    off(_ZN14CPlayerManager6UpdateEf, 381725)
    off(_ZN13CStateManager6UpdateEf, 395531)
    off(_ZN10GUIManager6UpdateEf, 483125)
    off(_ZN16GUIMotionManager8InstanceEv, 483845)
    off(_ZN16GUIMotionManager10ProcMotionEv, 484673)
    off(_ZN10CCSoundBox11UpdateSoundEv, 568183)
    off(_ZN13CStateManager6RenderEv, 395589)
    off(_ZN10GUIManager6RenderEv, 483089)
    off(_ZN10GUIManager9PostEventERK5Event, 483077)
    off(_ZN13CStateManager10TouchBeginEffi, 395601)
    off(_ZN13CStateManager9TouchMoveEffi, 395621)
    off(_ZN13CStateManager8TouchEndEffi, 395641)
    off(_ZN13CStateManager11BackPressedEv, 395661)
    off(_Z15ecAccelerometerfff, 272613)
    off(_Z13ecScrollWheelfff, 272615)
    off(_ZN13CStateManager11ScrollWheelEfff, 395685)
    off(_Z9ecKeyDowni, 272641)
    off(_ZN13CStateManager7KeyDownEi, 395673)
    off(_Z18ecSetShowReviewFucPFvvE, 272661)
    off(_Z12ecShowReviewv, 272673)
    off(_Z17ecGetProductPricei, 272689)
    off(_Z15ecInAppPurchasei, 272785)
    off(_Z18ecAppWillTerminatev, 272817)
    off(_Z22ecApplicationTerminatev, 272829)
    off(_Z14ecLoadSettingsv, 272845)
    off(_ZN13CGameSettings12LoadSettingsEv, 298669)
    off(_Z14ecIsFullScreenv, 272861)
    off(_Z15ecSetFullScreenb, 272877)
    off(_ZN13CGameSettings12SaveSettingsEv, 298893)
    off(_Z13SetAIRandSeedi, 399017)
    off(_Z11SetRandSeedi, 276101)
    off(_ZN10GUIManager4InitERK7GUIRect, 482969)
    off(_ZN13CStateManager4InitEv, 395457)
    off(_ZN10CLogoStateC1Ev, 360729)
    off(_ZN10CMenuStateC1Ev, 361837)
    off(_ZN11CMatchStateC1Ev, 361029)
    off(_ZN10CLoadStateC1Ev, 359641)
    off(_ZN10CGameStateC1Ev, 300861)
    off(_ZN10CEditStateC1Ev, 275377)
    off(_ZN13CStateManager13RegisterStateEP10CBaseState, 395729)
    off(_ZN13CStateManager11SetCurStateE6EState, 395737)
    off(_ZN13ecStringTable4LoadEPKc, 568521)
    off(_ZN13ecStringTable9GetStringEPKc, 568305)
    off(_ZN10CObjectDef4InitEv, 375985)
    off(_ZN10CCSoundBox6LoadSEEPKc, 568161)
    off(_ZN9ecUniFont4InitEPKcb, 566833)
    off(_ZN10CBaseState7OnEnterEv, 274653)
    off(_ZN10CBaseState6OnExitEv, 274659)
    off(_ZN10CBaseState10TouchBeginEffi, 274665)
    off(_ZN10CBaseState9TouchMoveEffi, 274667)
    off(_ZN10CBaseState8TouchEndEffi, 274669)
    off(_ZN10CBaseState11BackPressedEv, 274671)
    off(_ZN10CBaseState7KeyDownEi, 274675)
    off(_ZN10CBaseState11ScrollWheelEfff, 274677)
    off(_ZN10CBaseState15EnterBackgroundEv, 274679)
    off(_ZN10CBaseState15EnterForegroundEv, 274681)
    off(_ZN10CEditState7KeyDownEi, 274683)
    off(_ZN10CEditState7OnEventERK5Event, 274685)
    off(_ZN10CEditStateD2Ev, 274697)
    off(_ZN13CTouchInertiaD1Ev, 395753)
    off(_ZN10CEditStateD1Ev, 274697)
    off(_ZN10CEditStateD0Ev, 274741)
    off(_ZN10CEditState6UpdateEf, 274769)
    off(_ZN13CTouchInertia6UpdateEf, 395801)
    off(_ZN13CTouchInertia8GetSpeedERfS0_, 395877)
    off(_ZN6CScene4MoveEii, 389299)
    off(_ZN13CTouchInertia4StopEv, 395789)
    off(_ZN7CCamera13SetAutoFixPosEb, 420537)
    off(_ZN15ecEffectManager8InstanceEv, 565637)
    off(_ZN15ecEffectManager6UpdateEf, 565799)
    off(_ZN6CScene6UpdateEf, 388481)
    off(_ZN10CEditState6RenderEv, 274945)
    off(_ZN6CScene6RenderEv, 390137)
    off(_ZN6CScene15RenderAreasTypeEv, 385965)
    off(_ZN6CScene14RenderAreasTaxEv, 385967)
    off(_ZN10CEditState10TouchBeginEffi, 275001)
    off(_ZN13CTouchInertia10TouchBeginEffi, 395973)
    off(_ZN10CEditState9TouchMoveEffi, 275073)
    off(_ZN13CTouchInertia9TouchMoveEffi, 396009)
    off(_ZN10CEditState8TouchEndEffi, 275177)
    off(_ZN13CTouchInertia8TouchEndEffi, 396125)
    off(_ZN6CScene12ScreenToAreaEff, 389385)
    off(_ZN6CScene15GetSelectedAreaEv, 390041)
    off(_ZN6CScene12UnselectAreaEv, 390069)
    off(_ZN6CScene10SelectAreaEP5CArea, 392545)
    off(_ZN10CEditStateC2Ev, 275377)
    off(_ZN13CTouchInertiaC1Ev, 395777)
    off(_ZN10CEditState8InitGameEv, 275425)
    off(_ZN12CGameManager7NewGameEiiii, 281533)
    off(_ZN9CSoundRes4LoadEv, 395309)
    off(_ZN8CGameRes4LoadEv, 294589)
    off(_ZN6CScene4InitEPKci, 395005)
    off(_ZN13CTouchInertia4InitEv, 395757)
    off(_ZN10CEditState7OnEnterEv, 275729)
    off(_ZN10GUIManager6FadeInEi, 483033)
    off(_ZN10CEditState11ReleaseGameEv, 275781)
    off(_ZN6CScene7ReleaseEv, 386011)
    off(_ZN8CGameRes7ReleaseEv, 291105)
    off(_ZN9CSoundRes6UnloadEv, 395373)
    off(_ZN10CEditState6OnExitEv, 275829)
    off(_ZN16GUIMotionManager11ClearMotionEv, 483949)
    off(_ZN9CActionAID2Ev, 275859)
    off(_ZN9CActionAI18setActionNodeClearEv, 397085)
    off(_ZN9CActionAID1Ev, 275859)
    off(_ZN9CActionAI8InstanceEv, 275873)
    off(_ZN9CActionAI8getMedalEiP5CArea, 276005)
    off(_Z9GetAIRandv, 399041)
    off(_Z11GetRandSeedv, 276113)
    off(_Z7GetRandv, 276125)
    off(_ZN6CFightC2Ev, 276157)
    off(_ZN6CFightC1Ev, 276157)
    off(_ZN6CFightD2Ev, 276173)
    off(_ZN6CFightD1Ev, 276173)
    off(_ZN6CFight16AirStrikesAttackEP8CCountryii, 276205)
    off(_ZN6CScene7GetAreaEi, 389377)
    off(_ZN10CObjectDef10GetArmyDefEiPKc, 367885)
    off(_ZN8CCountry16GetWarMedalLevelE11WARMEDAL_ID, 424031)
    off(_ZN6CFight16AirStrikesAttackEii, 276437)
    off(_ZN6CFight17GetAttackerResultEi, 276501)
    off(_ZN6CFight17GetDefenderResultEi, 276509)
    off(_ZN6CFight12GetAttackAddEi, 276517)
    off(_ZN6CFight12GetDefendAddEi, 276521)
    off(_ZN6CFight11ApplyResultEv, 276525)
    off(_ZN5CArea7GetArmyEi, 406957)
    off(_ZN5CArea16LostArmyStrengthEii, 408011)
    off(_ZN6CScene25AdjacentAreasEncirclementEi, 392653)
    off(_ZN8CCountry10AddDestroyEi, 423111)
    off(_ZN5CArmy6AddExpEi, 411045)
    off(_ZN5CArea23ReduceConstructionLevelEv, 406775)
    off(_ZN5CArea10OccupyAreaEPS_, 407669)
    off(_ZN5CArmy12BreakthroughEv, 411141)
    off(_ZN5CArmy6IsNavyEv, 410669)
    off(_ZN8CCountry13IsLocalPlayerEv, 425253)
    off(_ZN6CScene9GainMedalEff, 392751)
    off(_ZN9CSoundRes10PlayCharSEE10SND_EFFECT, 395413)
    off(_ZN5CArea19DestroyConstructionEv, 406845)
    off(_ZN5CArea12ClearAllArmyEv, 407797)
    off(_ZN15ecEffectManager9AddEffectEPKcb, 565711)
    off(_ZN8ecEffect6FireAtEfff, 565391)
    off(_ZN13CFightTextMgr7AddTextEffPKcm, 279669)
    off(_ZN6CFight12NormalAttackEii, 278365)
    off(_ZN5CArmy11GetNumDicesEv, 410883)
    off(_ZN8CCountry17GetCommanderLevelEv, 423461)
    off(_Z14GetArmyAbilityi, 410641)
    off(_ZN5CArmy25GetNumDicesIfLostStrengthEi, 410937)
    off(_ZN6CFight11FirstAttackEii, 279361)
    off(_ZN6CFight12SecondAttackEv, 279385)
    off(_ZN10CFightTextC2Ev, 279415)
    off(_ZN6ecTextC1Ev, 569189)
    off(_ZN10CFightTextC1Ev, 279415)
    off(_ZN10CFightTextD2Ev, 279429)
    off(_ZN6ecTextD1Ev, 569201)
    off(_ZN10CFightTextD1Ev, 279429)
    off(_ZN10CFightText4InitEffP9ecUniFont, 279443)
    off(_ZN6ecText4InitEP9ecUniFont, 569219)
    off(_ZN10CFightText7SetTextEPKc, 279469)
    off(_ZN6ecText7SetTextEPKc, 569921)
    off(_ZN10CFightText8SetColorEm, 279475)
    off(_ZN6ecText8SetColorEm, 569235)
    off(_ZN10CFightText6UpdateEf, 279481)
    off(_ZN6ecText8SetAlphaEf, 569241)
    off(_ZN10CFightText6RenderEv, 279573)
    off(_ZN6ecText8DrawTextEffi, 569377)
    off(_ZN13CFightTextMgr6UpdateEf, 279587)
    off(_ZN13CFightTextMgr6RenderEv, 279647)
    off(_ZN9TFreeListI10CFightTextED2Ev, 279745)
    off(_ZN9TFreeListI10CFightTextED1Ev, 279745)
    off(_ZN9TFreeListI10CFightTextE7FreeAllEv, 279803)
    off(_ZN13CFightTextMgr4InitEv, 279841)
    off(_ZN13CFightTextMgrD2Ev, 280103)
    off(_ZN9ecUniFontD1Ev, 566449)
    off(_ZN13CFightTextMgrD1Ev, 280103)
    off(_ZN13CFightTextMgr7ReleaseEv, 280131)
    off(_ZN13CFightTextMgrC2Ev, 280163)
    off(_ZN9ecUniFontC1Ev, 566245)
    off(_ZN13CFightTextMgrC1Ev, 280163)
    off(_ZN13CActionAssistD2Ev, 280217)
    off(_ZN13CActionAssistD1Ev, 280217)
    off(_ZN12CGameManagerD2Ev, 280237)
    off(_ZN12CGameManagerD1Ev, 280237)
    off(_ZN13TiXmlDocumentD2Ev, 280269)
    off(_ZN9TiXmlNodeD2Ev, 530609)
    off(_ZN13TiXmlDocumentD1Ev, 280269)
    off(_ZN13TiXmlDocumentD0Ev, 280321)
    off(_ZN13CActionAssist8InstanceEv, 280341)
    off(_ZN9CActionAI6InitAIEv, 280453)
    off(_ZN6CScene11GetNumAreasEv, 389369)
    off(_Z13GetNumBattlesi, 280601)
    off(_Z16GetBattleKeyNameiiPc, 280665)
    off(_Z18GetConquestKeyNameiPc, 280753)
    off(_Z17GetBattleFileNameiiiiPc, 280769)
    off(_Z24GetNumMultiPlayerBattlesi, 280881)
    off(_Z24GetBattleBelligerentListPKcRSt4listI11BelligerentSaIS2_EEb, 280945)
    off(_ZN13TiXmlDocumentC1EPKc, 531997)
    off(_ZN13TiXmlDocument8LoadFileE13TiXmlEncoding, 532557)
    off(_ZN9TiXmlNode10FirstChildEPKc, 531235)
    off(_ZNK12TiXmlElement9AttributeEPKc, 535145)
    off(_ZNK12TiXmlElement17QueryIntAttributeEPKcPi, 535293)
    off(_ZN12CGameManagerC2Ev, 281417)
    off(_ZN12CGameManagerC1Ev, 281417)
    off(_ZN12CGameManager4InitEv, 281451)
    off(_ZN12CGameManager20SetPlayercountrynameEiPKc, 281453)
    off(_ZN12CGameManager11GetPlayerNoEPKc, 281473)
    off(_ZN12CGameManager20GetPlayerCountryNameEi, 281513)
    off(_ZN12CGameManager26SetConquestPlayerCountryIDEPKc, 281527)
    off(_ZN10CObjectDef12GetBattleDefEPKc, 367365)
    off(_ZN12CGameManager8LoadGameEPKc, 281717)
    off(_ZN12CGameManager9RetryGameEv, 281913)
    off(_ZN12CGameManager8SaveGameEPKc, 281921)
    off(_ZN8CCountry11SaveCountryEP15SaveCountryInfo, 422907)
    off(_ZN5CArea8SaveAeraEP12SaveAreaInfo, 410097)
    off(_ZN12CGameManager13GetSaveHeaderEPKcR10SaveHeader, 282505)
    off(_ZN12CGameManager11ClearBattleEv, 282609)
    off(_ZN8CCountryD1Ev, 425459)
    off(_ZN12CGameManager7ReleaseEv, 282687)
    off(_ZN12CGameManager10NextBattleEv, 282691)
    off(_ZN12CGameManager12IsLastBattleEv, 282693)
    off(_ZN12CGameManager15GetNumCountriesEv, 282729)
    off(_ZN12CGameManager17GetCountryByIndexEi, 282737)
    off(_ZN12CGameManager11FindCountryEPKc, 282745)
    off(_ZN12CGameManager13GetCurCountryEv, 282783)
    off(_ZN12CGameManager13InitCameraPosEv, 282797)
    off(_ZN8CCountry19GetHighestValueAreaEv, 421897)
    off(_ZN6CScene15SetCameraToAreaEi, 389417)
    off(_ZN12CGameManager16GetPlayerCountryEv, 282833)
    off(_ZN12CGameManager21GetLocalPlayerCountryEv, 282877)
    off(_ZN12CGameManager15GetNumDialoguesEv, 282943)
    off(_ZN12CGameManager18GetDialogueByIndexEi, 282953)
    off(_ZN12CGameManager10SaveBattleEPKc, 282961)
    off(_ZN12TiXmlElementC1EPKc, 534873)
    off(_ZN12TiXmlElement12SetAttributeEPKci, 535833)
    off(_ZN12TiXmlElement12SetAttributeEPKcS1_, 535605)
    off(_ZN8CCountry16GetCommanderNameEv, 423449)
    off(_ZN12TiXmlElement18SetDoubleAttributeEPKcd, 535901)
    off(_ZN9TiXmlNode12LinkEndChildEPS_, 530939)
    off(_ZNK13TiXmlDocument8SaveFileEv, 532737)
    off(_ZN12CGameManager14GetCurDialogueEv, 284741)
    off(_ZN12CGameManager20GetCurDialogueStringEPc, 284773)
    off(_ZN12CGameManager12NextDialogueEv, 284901)
    off(_ZN12CGameManager18GetNumVictoryStarsEv, 284909)
    off(_ZN12CGameManager17CheckAndSetResultEv, 284969)
    off(_ZN8CCountry12IsConquestedEv, 422225)
    off(_ZN12CGameManager13BattleVictoryEv, 285325)
    off(_ZN12CGameManager21GetNewDefeatedCountryEv, 285461)
    off(_ZN12CGameManager12IsManipulateEv, 285515)
    off(_ZN8CCountry14IsActionFinishEv, 422897)
    off(_ZN12CGameManager9TurnBeginEv, 285585)
    off(_ZN8CCountry9TurnBeginEv, 425169)
    off(_ZN10CGameState16UpdateActionInfoEv, 305001)
    off(_ZN10CGameState18PlayerCountryBeginEv, 303965)
    off(_ZN8CCountry6ActionERK13CountryAction, 427861)
    off(_ZN12CGameManager7TurnEndEv, 285721)
    off(_ZN8CCountry7TurnEndEv, 422777)
    off(_ZN12CGameManager7EndTurnEv, 285741)
    off(_ZN10CGameState12ShowDialogueEPKcS1_b, 304153)
    off(_ZN10CGameState14HideAIProgressEv, 303921)
    off(_ZN12CGameManager4NextEv, 285917)
    off(_ZN9CActionAI16setCpuDriverbyIdEii, 398349)
    off(_ZN14CPlayerManager13DoFrontActionEv, 383697)
    off(_ZN5CArea13SetArmyActiveEib, 408257)
    off(_ZN12CGameManager10GameUpdateEf, 286333)
    off(_ZN8CCountry6UpdateEf, 427661)
    off(_ZN10CGameState12ShowDefeatedEP8CCountry, 301313)
    off(_ZN10CGameState16UpdateAIProgressEv, 301345)
    off(_ZN12CGameManager12RealLoadGameEPKc, 286649)
    off(_ZN8CCountryC1Ev, 421749)
    off(_ZN8CCountry4InitEPKcS1_, 425489)
    off(_ZN8CCountry11LoadCountryEPK15SaveCountryInfo, 423269)
    off(_ZN5CArea8LoadAreaEPK12SaveAreaInfo, 410255)
    off(_ZN8CCountry7AddAreaEi, 421813)
    off(_ZN7CCamera6SetPosEffb, 419929)
    off(_ZN12CGameManager10LoadBattleEPKc, 287129)
    off(_ZNK12TiXmlElement20QueryDoubleAttributeEPKcPd, 535381)
    off(_ZN14CPlayerManager21FindPlayerByCountryIDEPKc, 379737)
    off(_ZN8CCountry12SetCommanderEPKc, 423133)
    off(_ZN6CScene14SetAreaCountryEiP8CCountry, 390031)
    off(_ZN5CArea15SetConstructionEii, 406727)
    off(_ZN5CArmyC1Ev, 410665)
    off(_ZN5CArmy4InitEP7ArmyDefP8CCountry, 410799)
    off(_ZN5CArea7AddArmyEP5CArmyb, 407011)
    off(_ZN5CArmy16ResetMaxStrengthEb, 410705)
    off(_ZN12CGameManager24MovePlayerCountryToFrontEv, 289377)
    off(_ZN12CGameManager10InitBattleEv, 289589)
    off(_ZN14CPlayerManager18SetPlayerOfCountryEv, 380029)
    off(_ZN6CScene20AllAreasEncirclementEv, 392619)
    off(_ZN8CGameRes14RenderArmyInfoEiffiiiii, 289893)
    off(_ZN7ecImage6RenderEff, 556993)
    off(_ZN7ecImage8SetColorEmi, 558687)
    off(_ZN7ecImage8RenderExEfffff, 557329)
    off(_ZN8CGameRes20RenderCommanderMedalEiffi, 290209)
    off(_ZN8CGameRes12RenderArmyHPEffii, 290293)
    off(_ZN8CGameRes15RenderArmyLevelEffi, 290385)
    off(_ZN8CGameRes21RenderArmyMovementNumEffi, 290403)
    off(_ZN8CGameRes18RenderConstructionEiiff, 290419)
    off(_ZN8CGameRes10RenderPortEff, 290475)
    off(_ZN8CGameRes18RenderInstallationEiff, 290483)
    off(_ZN8CGameRes11GetBattleBGEPKc, 290501)
    off(_ZN12ecTextureRes8GetImageEPKc, 559773)
    off(_ZN8CGameRes12GetFlagImageEPKc, 290509)
    off(_ZN8CGameResC2Ev, 290569)
    off(_ZN12ecTextureResC1Ev, 559147)
    off(_ZN12ecTextureResD1Ev, 559481)
    off(_ZN8CGameResC1Ev, 290569)
    off(_ZN8CGameResD2Ev, 291029)
    off(_ZN8CGameResD1Ev, 291029)
    off(_ZN15ecEffectManager9RemoveAllEv, 565979)
    off(_ZN18ecEffectResManager8InstanceEv, 564185)
    off(_ZN18ecEffectResManager19ReleaseAllEffectResEv, 564331)
    off(_ZN18ecEffectResManager17ReleaseTextureResEv, 564205)
    off(_ZN7ecImageD1Ev, 556691)
    off(_ZN12ecTextureRes7ReleaseEv, 559385)
    off(_ZN8CGameRes12GetArmyImageEPKcib, 292225)
    off(_ZN8CGameRes10RenderArmyEPKciiffimbf, 292349)
    off(_ZN8CGameRes12RenderUIArmyEPKcffibiiiii, 292549)
    off(_ZN8CGameRes22RenderAICommanderMedalEiffPKci, 292957)
    off(_ZN8CGameRes18RenderUIAttackArmyEPKcffiiiiiiib, 293173)
    off(_ZN8CGameRes18RenderUIDefendArmyEPKcffiiiiiiib, 293621)
    off(_ZN8CGameRes10RenderFlagEPKcff, 294077)
    off(_ZN12ecTextureRes7LoadResEPKcb, 561125)
    off(_ZN7ecImageC1EP11ecImageAttr, 556915)
    off(_ZN7ecImageC1EP9ecTextureffff, 556857)
    off(_ZN18ecEffectResManager14LoadTextureResEPKc, 564197)
    off(_ZN18ecEffectResManager13LoadEffectResEPKc, 565065)
    off(_ZN13CGameSettingsD2Ev, 298645)
    off(_ZN13CGameSettingsD1Ev, 298645)
    off(_ZN13CGameSettingsC2Ev, 298647)
    off(_ZN13CGameSettingsC1Ev, 298647)
    off(_ZN10CGameStateD2Ev, 299037)
    off(_ZN10CGameStateD1Ev, 299037)
    off(_ZN10CGameStateD0Ev, 299081)
    off(_ZN10CGameState6RenderEv, 299109)
    off(_ZN15ecEffectManager6RenderEv, 565869)
    off(_ZN10CGameState8TouchEndEffi, 299177)
    off(_ZN10GUIBuyCard10GetSelCardEv, 325357)
    off(_ZN8CCountry19CheckCardTargetAreaEP7CardDefi, 424081)
    off(_ZN14CPlayerManager22SendPacketToAllPlayersE9PACKET_IDPKvi, 377667)
    off(_ZN6GUITax7SetAreaEi, 351945)
    off(_ZN5CArea8IsActiveEv, 408219)
    off(_ZN6CScene13CheckMoveableEiii, 391669)
    off(_ZN10GUIElement4HideEv, 481863)
    off(_ZN10GUIElement4ShowEv, 481853)
    off(_ZN10GUISelArmy7SetAreaEi, 349901)
    off(_ZN6CScene15CheckAttackableEiii, 391937)
    off(_ZN12GUIAttackBox9SetAttackEii, 310213)
    off(_ZN10CGameState9TouchMoveEffi, 300001)
    off(_ZN6CScene13ScreenToSceneERfS0_, 389141)
    off(_ZN7CCamera14SetPosAndScaleEfff, 420109)
    off(_ZN10CGameState11ScrollWheelEfff, 300633)
    off(_ZN10CGameState15EnterBackgroundEv, 300813)
    off(_ZN10CGameStateC2Ev, 300861)
    off(_ZN10CGameState8InitGameEv, 300909)
    off(_ZN10GUIManager14LoadTextureResEPKcb, 482985)
    off(_ZN10CGameState11ReleaseGameEv, 301061)
    off(_ZN10GUIManager16UnloadTextureResEPKc, 483001)
    off(_ZN10CGameState6OnExitEv, 301197)
    off(_ZN10CCSoundBox11UnloadMusicEv, 568079)
    off(_ZN14CPlayerManager4StopEv, 380711)
    off(_ZN10GUIElement11MoveToFrontEPS_, 481375)
    off(_ZN11GUIDefeated12ShowDefeatedEP8CCountry, 331781)
    off(_ZN13GUIAIProgress17SetCurCountryNameEPKc, 309141)
    off(_ZN10CGameState7OnEnterEv, 301413)
    off(_ZN10GUIManager9AddButtonEPKcS1_RK7GUIRectP10GUIElementP9ecUniFont, 483637)
    off(_ZN9GUIButton13SetBackgroundEPKc, 480557)
    off(_ZN7GUIGoldC1Ev, 335849)
    off(_ZN7GUIGold4InitERK7GUIRect, 336077)
    off(_ZN10GUIElement8AddChildEPS_b, 481125)
    off(_ZN6GUITaxC1Ev, 351369)
    off(_ZN6GUITax4InitERK7GUIRect, 351617)
    off(_ZN12GUISmallCardC1Ev, 350757)
    off(_ZN12GUISmallCard4InitERK7GUIRect, 350789)
    off(_ZN12GUIAttackBoxC1Ev, 309777)
    off(_ZN12GUIAttackBox4InitERK7GUIRect, 309817)
    off(_ZN10GUIElement6CenterEv, 481483)
    off(_ZN11GUIPauseBoxC1Ev, 341689)
    off(_ZN11GUIPauseBox4InitERK7GUIRect, 341733)
    off(_ZN10GUIBuyCardC1Ev, 323273)
    off(_ZN10GUIBuyCard4InitERK7GUIRect, 323373)
    off(_ZN13GUIAIProgressC1Ev, 308913)
    off(_ZN13GUIAIProgress4InitERK7GUIRect, 308949)
    off(_ZN10GUISelArmyC1Ev, 349601)
    off(_ZN10GUISelArmy4InitERK7GUIRect, 349633)
    off(_ZN8GUIBeginC1Ev, 319689)
    off(_ZN8GUIBegin4InitERK7GUIRect, 319801)
    off(_ZN13GUIActionInfoC1Ev, 308441)
    off(_ZN13GUIActionInfo4InitERK7GUIRect, 308489)
    off(_ZN11GUIDefeatedC1Ev, 331417)
    off(_ZN11GUIDefeated4InitERK7GUIRect, 331489)
    off(_ZN9GUIBattleC1Ev, 314445)
    off(_ZN9GUIBattle4InitERK7GUIRect, 314633)
    off(_ZN12GUITutorailsC1Ev, 353581)
    off(_ZN12GUITutorails4InitERK7GUIRect, 354649)
    off(_ZN11GUIDialogueC1Ev, 333193)
    off(_ZN11GUIDialogue4InitERK7GUIRect, 333265)
    off(_ZN16GUIMotionManager9AddMotionEP10GUIElementffft, 484305)
    off(_ZN10CCSoundBox9LoadMusicEPKcS1_, 568073)
    off(_ZN10CCSoundBox9PlayMusicEb, 568081)
    off(_ZN10CGameState15EnableIdleTimerEf, 303701)
    off(_ZN10CGameState12StartBattaleEiiib, 303713)
    off(_ZN9GUIBattle11BattleStartEiii, 315669)
    off(_ZN8GUIBegin9ResetDataEv, 320517)
    off(_ZN10CGameState10SelectAreaEi, 304005)
    off(_ZN6CScene10SelectAreaEi, 392575)
    off(_ZN10CGameState12UnselectAreaEv, 304113)
    off(_ZN11GUIDialogue7ShowDlgEPKcS1_b, 333525)
    off(_ZN10CGameState11ShowWarningEi, 304165)
    off(_ZN10GUIWarningC1Ev, 357865)
    off(_ZN10GUIWarning4InitERK7GUIRecti, 357933)
    off(_ZN10CGameState6UpdateEf, 304293)
    off(_ZN10GUIBuyCard13CanBuySelCardEv, 325389)
    off(_ZN10GUIBuyCard15ResetCardTargetEv, 326021)
    off(_ZN10GUIBuyCard13ReleaseTargetEv, 326109)
    off(_ZN6CScene9IsBombingEv, 392739)
    off(_ZN14CPlayerManager13GetNumActionsEv, 382673)
    off(_ZN14CPlayerManager22IsDisconnectedFromHostEv, 377433)
    off(_ZN13GUIActionInfo7SetInfoEPKc, 308573)
    off(_ZN10CGameState15ResetTouchStateEv, 305205)
    off(_ZN10CGameState11BackPressedEv, 305229)
    off(_ZN10GUIManager7FadeOutEiP10GUIElement, 483047)
    off(_ZN10CGameState10TouchBeginEffi, 305321)
    off(_ZN10CGameState7OnEventERK5Event, 305497)
    off(_ZN10GUIBuyCard14ResetCardStateEv, 325449)
    off(_ZN10GUIOptionsC1Ev, 339265)
    off(_ZN10GUIOptions4InitERK7GUIRect, 339313)
    off(_ZN7GUISaveC1Ev, 347385)
    off(_ZN7GUISave4InitERK7GUIRectib, 347437)
    off(_ZN10GUIManager13SafeFreeChildEP10GUIElement, 483377)
    off(_ZN6GUIEndC1Ev, 334205)
    off(_ZN6GUIEnd4InitERK7GUIRect, 334277)
    off(_ZN14GUIBattleIntroC1Ev, 317253)
    off(_ZN14GUIBattleIntro4InitERK7GUIRectii, 317953)
    off(_ZN16GUIMotionManager12ActiveMotionEmh, 484599)
    off(_ZN14CPlayerManager18SendPacketToServerE9PACKET_IDPKvi, 377631)
    off(_ZN14CPlayerManager16PlayerLoadFinishEP7CPlayer, 380337)
    off(_ZN9GUIResultC1Ev, 343097)
    off(_ZN9GUIResult4InitERK7GUIRecti, 343201)
    off(_ZN6GUIIapC1Ev, 337061)
    off(_ZN6GUIIap4InitERK7GUIRect, 337121)
    off(_ZN12GUISmallCard7SetCardEP7CardDef, 350813)
    off(_ZN11GUIDefeated12HideDefeatedEv, 332269)
    off(_ZN10GUIVictoryC1Ev, 356909)
    off(_ZN10GUIVictory4InitERK7GUIRectb, 356945)
    off(_ZN10GUIVictory4PlayEv, 357501)
    off(_ZN7GUIBankC1Ev, 310773)
    off(_ZN7GUIBank4InitERK7GUIRect, 310825)
    off(_ZN13ecStringTableC1Ev, 568185)
    off(_ZN13ecStringTableD1Ev, 568285)
    off(_ZN13GUIActionInfo8OnUpdateEf, 308273)
    off(_ZN13GUIActionInfoD2Ev, 308277)
    off(_ZN11ecLabelTextD1Ev, 567625)
    off(_ZN10GUIElementD2Ev, 481329)
    off(_ZN13GUIActionInfoD1Ev, 308277)
    off(_ZN13GUIActionInfoD0Ev, 308333)
    off(_ZN13GUIActionInfo8OnRenderEv, 308353)
    off(_ZN10GUIElement10GetAbsRectER7GUIRect, 481565)
    off(_ZN11ecLabelText8DrawTextEff, 567889)
    off(_ZN13GUIActionInfoC2Ev, 308441)
    off(_ZN10GUIElementC2Ev, 481049)
    off(_ZN11ecLabelTextC1Ev, 567601)
    off(_ZN11ecLabelText4InitEPKciiii, 567677)
    off(_ZN11ecLabelText7SetTextEPKc, 567709)
    off(_ZN10GUIElement7OnEventERK5Event, 481029)
    off(_ZN13GUIAIProgressD2Ev, 308581)
    off(_ZN13GUIAIProgressD1Ev, 308581)
    off(_ZN13GUIAIProgressD0Ev, 308669)
    off(_ZN13GUIAIProgress8OnRenderEv, 308689)
    off(_ZN13GUIAIProgressC2Ev, 308913)
    off(_ZN7ecImage4InitEP11ecImageAttr, 556955)
    off(_ZN10GUIElement8OnUpdateEf, 481027)
    off(_ZN12GUIAttackBoxD2Ev, 309221)
    off(_ZN12GUIAttackBoxD1Ev, 309221)
    off(_ZN12GUIAttackBoxD0Ev, 309309)
    off(_ZN12GUIAttackBox8OnRenderEv, 309329)
    off(_ZN5CArmy14GetMaxStrengthEv, 410851)
    off(_ZN12GUIAttackBoxC2Ev, 309777)
    off(_ZN11GUIButtonExC1Ev, 320941)
    off(_ZN9GUIButton4InitEPKcS1_RK7GUIRectP9ecUniFont, 480297)
    off(_ZN11GUIButtonEx12SetImageTextEPKcS1_, 320985)
    off(_ZN12GUIAttackBox7OnEventERK5Event, 310373)
    off(_ZN7GUIBank8OnUpdateEf, 310489)
    off(_ZN7GUIBankD2Ev, 310493)
    off(_ZN7GUIBankD1Ev, 310493)
    off(_ZN7GUIBankD0Ev, 310569)
    off(_ZN7GUIBank8OnRenderEv, 310589)
    off(_ZN7ecImage6RenderEffff, 557161)
    off(_ZN7GUIBankC2Ev, 310773)
    off(_ZN9GUIButtonC1Ev, 480237)
    off(_ZN8GUIMedalC1Ev, 338581)
    off(_ZN8GUIMedal4InitERK7GUIRect, 338713)
    off(_ZN10GUIManager8AddImageEPKcRK7GUIRectP10GUIElement, 483553)
    off(_ZN7GUIBank7OnEventERK5Event, 312301)
    off(_ZN9GUIBattleD2Ev, 312689)
    off(_ZN12CBattleSceneD1Ev, 416863)
    off(_ZN9GUIBattleD1Ev, 312689)
    off(_ZN9GUIBattleD0Ev, 312893)
    off(_ZN9GUIBattle8OnRenderEv, 312913)
    off(_ZN12CBattleScene6RenderEv, 412737)
    off(_ZN9GUIBattleC2Ev, 314445)
    off(_ZN12CBattleSceneC1Ev, 412589)
    off(_ZN12CBattleScene4InitEiPS_, 412687)
    off(_ZN9GUIBattle11ResetBattleEv, 315077)
    off(_ZN12CBattleScene13SetBattleAreaEi, 414517)
    off(_ZN9GUIBattle12BattleFinishEv, 315865)
    off(_ZN9GUIBattle13UpateFightingEf, 315881)
    off(_ZN12CBattleScene6AttackEv, 415465)
    off(_ZN12CBattleScene11IsAttackingEv, 415495)
    off(_ZN12CBattleScene12DestroyUnitsEi, 415549)
    off(_ZN9GUIBattle8OnUpdateEf, 316141)
    off(_ZN12CBattleScene6UpdateEf, 415877)
    off(_ZN12CBattleScene12ClearCratersEv, 415721)
    off(_ZN12CBattleScene12ClearEffectsEv, 416801)
    off(_ZN9GUIBattle7OnEventERK5Event, 316429)
    off(_ZN14GUIBattleIntroD2Ev, 316445)
    off(_ZN14GUIBattleIntroD1Ev, 316445)
    off(_ZN14GUIBattleIntroD0Ev, 316601)
    off(_ZN14GUIBattleIntro8OnRenderEv, 316621)
    off(_ZN14GUIBattleIntroC2Ev, 317253)
    off(_ZN14GUIBattleIntro9SetBattleEii, 317457)
    off(_ZN14GUIBattleIntro7OnEventERK5Event, 318929)
    off(_ZN8GUIBeginD2Ev, 319053)
    off(_ZN8GUIBeginD1Ev, 319053)
    off(_ZN8GUIBeginD0Ev, 319241)
    off(_ZN8GUIBegin8OnRenderEv, 319261)
    off(_ZN8GUIBeginC2Ev, 319689)
    off(_ZN7GUITechC1Ev, 352573)
    off(_ZN7GUITech4InitERK7GUIRect, 352617)
    off(_ZN8CCountry8GetTaxesEv, 424929)
    off(_ZN8CCountry12GetIndustrysEv, 425049)
    off(_ZN8GUIBegin7OnEventERK5Event, 320745)
    off(_ZN11GUIButtonExD2Ev, 320853)
    off(_ZN9GUIButtonD2Ev, 479593)
    off(_ZN11GUIButtonExD1Ev, 320853)
    off(_ZN11GUIButtonExD0Ev, 320921)
    off(_ZN11GUIButtonExC2Ev, 320941)
    off(_ZN9GUIButtonC2Ev, 480237)
    off(_ZN11GUIButtonEx8OnRenderEv, 321117)
    off(_ZN9GUIButton8OnRenderEv, 479761)
    off(_ZN9GUIButton7OnEventERK5Event, 480809)
    off(_ZN10GUICardTabD2Ev, 321297)
    off(_ZN10GUICardTabD1Ev, 321297)
    off(_ZN10GUICardTabD0Ev, 321325)
    off(_ZN10GUIBuyCardD2Ev, 321345)
    off(_ZN10GUIBuyCardD1Ev, 321345)
    off(_ZN10GUIBuyCardD0Ev, 321513)
    off(_ZN10GUIBuyCard8OnRenderEv, 321533)
    off(_ZN10GUICardTabC2Ev, 321901)
    off(_ZN10GUICardTabC1Ev, 321901)
    off(_ZN10GUICardTab19GetCardTabButtonIdxEPK10GUIElement, 321929)
    off(_ZN10GUICardTab9SelectTabEi, 321957)
    off(_ZN10GUIElement6GetPosERfS0_, 481433)
    off(_ZN10GUIElement6SetPosEff, 481443)
    off(_ZN10GUICardTab4InitERK7GUIRect, 322145)
    off(_ZN14GUIRadioButtonC1Ev, 485525)
    off(_ZN10GUIManager8AddImageEPKcRK13ecTextureRectRK7GUIRectP10GUIElementb, 483409)
    off(_ZN10GUIBuyCardC2Ev, 323273)
    off(_ZN7ecImageC1EP9ecTextureRK13ecTextureRect, 556879)
    off(_ZN11GUICardListC1Ev, 329297)
    off(_ZN11GUICardList4InitERK7GUIRecti, 329581)
    off(_ZN10GUIBuyCard15SetSelCardIntroEv, 325277)
    off(_ZN10CObjectDef10GetCardDefE7CARD_ID, 365981)
    off(_ZN8CCountry10CanBuyCardEP7CardDef, 423811)
    off(_ZN8CCountry12GetCardPriceEP7CardDef, 423525)
    off(_ZN8CCountry15GetCardIndustryEP7CardDef, 422739)
    off(_ZN11GUICardList7GetCardEi, 329385)
    off(_ZN8CCountry13IsEnoughMoneyEP7CardDef, 423559)
    off(_ZN7GUICard13SetPriceColorEm, 329285)
    off(_ZN8CCountry16IsEnoughIndustryEP7CardDef, 422755)
    off(_ZN7GUICard16SetIndustryColorEm, 329291)
    off(_ZN7GUICard8SetPriceEi, 329157)
    off(_ZN7GUICard11SetIndustryEi, 329221)
    off(_ZN8CCountry15CanUseCommanderEv, 423789)
    off(_ZN8CCountry13GetCardRoundsE7CARD_ID, 422731)
    off(_ZN10GUIElement9SetEnableEb, 481873)
    off(_ZN10GUIBuyCard7SelCardEii, 325889)
    off(_ZN6CScene12ClearTargetsEv, 390045)
    off(_ZN8CCountry14SetCardTargetsEP7CardDef, 424705)
    off(_ZN6CScene11ResetTargetEv, 392595)
    off(_ZN10GUICardTab7OnEventERK5Event, 326133)
    off(_ZN10GUIBuyCard7OnEventERK5Event, 326189)
    off(_ZN10CObjectDef17GetCardTargetTypeEP7CardDef, 365997)
    off(_ZN10GUIElement8OnRenderEv, 481025)
    off(_ZN7GUICardD2Ev, 326585)
    off(_ZN7GUICardD1Ev, 326585)
    off(_ZN7GUICardD0Ev, 326777)
    off(_ZN7GUICard8OnRenderEv, 326797)
    off(_ZN11GUICardList8OnUpdateEf, 327677)
    off(_ZN11GUICardListD2Ev, 328065)
    off(_ZN11GUICardListD1Ev, 328065)
    off(_ZN11GUICardListD0Ev, 328109)
    off(_ZN7GUICardC2Ev, 328129)
    off(_ZN7GUICardC1Ev, 328129)
    off(_ZN7GUICard4InitEP7CardDefRK7GUIRect, 328305)
    off(_ZN11GUICardListC2Ev, 329297)
    off(_ZN11GUICardList11ResetSelectEv, 329357)
    off(_ZN11GUICardList10GelSelItemEff, 329405)
    off(_ZN10GUIElement11CheckInRectEff, 481625)
    off(_ZN7GUICard7OnEventERK5Event, 330353)
    off(_ZN11GUICardList9SetSelectEi, 330569)
    off(_ZN11GUICardList8ReSelectEv, 330637)
    off(_ZN11GUICardList7OnEventERK5Event, 330665)
    off(_ZN11GUIDefeated8OnRenderEv, 331109)
    off(_ZN11GUIDefeatedC2Ev, 331417)
    off(_ZN10CObjectDef15GetGeneralPhotoEPKc, 368017)
    off(_ZN11GUIDefeatedD2Ev, 332369)
    off(_ZN11GUIDefeatedD1Ev, 332369)
    off(_ZN11GUIDefeatedD0Ev, 332421)
    off(_ZN11GUIDefeated8OnUpdateEf, 332441)
    off(_ZN11GUIDefeated7OnEventERK5Event, 332569)
    off(_ZN11GUIDialogue8OnUpdateEf, 332653)
    off(_ZN11GUIDialogueD2Ev, 332657)
    off(_ZN11GUIDialogueD1Ev, 332657)
    off(_ZN11GUIDialogueD0Ev, 332785)
    off(_ZN11GUIDialogue8OnRenderEv, 332805)
    off(_ZN11GUIDialogueC2Ev, 333193)
    off(_ZN11GUIDialogue7HideDlgEv, 333693)
    off(_ZN11GUIDialogue7OnEventERK5Event, 333697)
    off(_ZN6GUIEndD2Ev, 333785)
    off(_ZN6GUIEndD1Ev, 333785)
    off(_ZN6GUIEndD0Ev, 333905)
    off(_ZN6GUIEnd8OnRenderEv, 333925)
    off(_ZN6GUIEndC2Ev, 334205)
    off(_ZN6GUIEnd7OnEventERK5Event, 335537)
    off(_ZN7GUIGoldD2Ev, 335621)
    off(_ZN7GUIGoldD1Ev, 335621)
    off(_ZN7GUIGoldD0Ev, 335685)
    off(_ZN7GUIGold8OnRenderEv, 335705)
    off(_ZN7GUIGoldC2Ev, 335849)
    off(_ZN7GUIGold8SetMoneyEi, 335925)
    off(_ZN7GUIGold11SetIndustryEi, 336001)
    off(_ZN7GUIGold8OnUpdateEf, 336233)
    off(_ZN15GUIProductPriceD2Ev, 336293)
    off(_ZN15GUIProductPriceD1Ev, 336293)
    off(_ZN15GUIProductPriceD0Ev, 336337)
    off(_ZN15GUIProductPrice8OnRenderEv, 336357)
    off(_ZN6GUIIapD2Ev, 336485)
    off(_ZN6GUIIapD1Ev, 336485)
    off(_ZN6GUIIapD0Ev, 336605)
    off(_ZN6GUIIap7OnEventERK5Event, 336625)
    off(_ZN6GUIIap8OnRenderEv, 336785)
    off(_ZN15GUIProductPriceC2Ev, 336861)
    off(_ZN15GUIProductPriceC1Ev, 336861)
    off(_ZN15GUIProductPrice4InitERK7GUIRect, 336921)
    off(_ZN11ecLabelText8SetColorEm, 567843)
    off(_ZN15GUIProductPrice14SetLocalePirceEPKc, 337029)
    off(_ZN6GUIIapC2Ev, 337061)
    off(_ZN9GUIButton7SetTextEPKc, 480717)
    off(_ZN9GUIButton12SetTextColorEm, 480781)
    off(_ZN6GUIIap14SetLocalePirceEiPKc, 338365)
    off(_ZN6GUIIap14OnListCompleteEPv, 338385)
    off(_ZN6GUIIap15SetProductPriceEv, 338387)
    off(_ZN8GUIMedalD2Ev, 338389)
    off(_ZN8GUIMedalD1Ev, 338389)
    off(_ZN8GUIMedalD0Ev, 338445)
    off(_ZN8GUIMedal8OnRenderEv, 338465)
    off(_ZN8GUIMedalC2Ev, 338581)
    off(_ZN8GUIMedal8SetMedalEi, 338637)
    off(_ZN8GUIMedal8OnUpdateEf, 338981)
    off(_ZN8GUIMedal7OnEventERK5Event, 338997)
    off(_ZN10GUIOptionsD2Ev, 339081)
    off(_ZN10GUIOptionsD1Ev, 339081)
    off(_ZN10GUIOptionsD0Ev, 339185)
    off(_ZN10GUIOptions8OnRenderEv, 339205)
    off(_ZN10GUIOptionsC2Ev, 339265)
    off(_ZN10GUIManager12AddScrollBarERK7GUIRectP10GUIElementPKcS6_iiiii, 483713)
    off(_ZN11GUILevelSelC1Ev, 439525)
    off(_ZN11GUILevelSel4InitERK7GUIRecti, 439557)
    off(_ZN12GUIScrollBar12SetScrollPosEi, 485837)
    off(_ZN10GUIOptions7OnEventERK5Event, 341309)
    off(_ZN12GUIScrollBar12GetScrollPosEv, 485769)
    off(_ZN11GUIPauseBoxD2Ev, 341537)
    off(_ZN11GUIPauseBoxD1Ev, 341537)
    off(_ZN11GUIPauseBoxD0Ev, 341605)
    off(_ZN11GUIPauseBox8OnRenderEv, 341625)
    off(_ZN11GUIPauseBoxC2Ev, 341689)
    off(_ZN11GUIPauseBox7OnEventERK5Event, 342201)
    off(_ZN9GUIResult8OnUpdateEf, 342265)
    off(_ZN9GUIResultD2Ev, 342269)
    off(_ZN9GUIResultD1Ev, 342269)
    off(_ZN9GUIResultD0Ev, 342513)
    off(_ZN9GUIResult8OnRenderEv, 342533)
    off(_ZN9GUIResultC2Ev, 343097)
    off(_ZN13GUIAdornMedalC1Ev, 431097)
    off(_ZN13GUIAdornMedal4InitER7GUIRect, 431349)
    off(_ZN9GUIResult7OnEventERK5Event, 345373)
    off(_ZN11GUISaveItemD2Ev, 345457)
    off(_ZN14GUIRadioButtonD2Ev, 485193)
    off(_ZN11GUISaveItemD1Ev, 345457)
    off(_ZN11GUISaveItemD0Ev, 345529)
    off(_ZN7GUISave8OnRenderEv, 345547)
    off(_ZN11GUISaveItem8OnRenderEv, 345557)
    off(_ZN7GUISaveD2Ev, 346489)
    off(_ZN12ecTextureRes9UnloadResEPKc, 559577)
    off(_ZN7GUISaveD1Ev, 346489)
    off(_ZN7GUISaveD0Ev, 346625)
    off(_ZN11GUISaveItem8OnUpdateEf, 346645)
    off(_ZN11GUISaveItemC2Ev, 346721)
    off(_ZN14GUIRadioButtonC2Ev, 485525)
    off(_ZN11GUISaveItemC1Ev, 346721)
    off(_ZN11GUISaveItem4InitERK7GUIRectPKc, 346805)
    off(_ZN11GUISaveItem7SetInfoEPKciiiiiiiib, 347025)
    off(_ZN7GUISaveC2Ev, 347385)
    off(_ZN7GUISave7SelItemEi, 348889)
    off(_ZN7GUISave7OnEventERK5Event, 348953)
    off(_ZN11GUIArmyItemD2Ev, 349225)
    off(_ZN11GUIArmyItemD1Ev, 349225)
    off(_ZN11GUIArmyItemD0Ev, 349253)
    off(_ZN11GUIArmyItem8OnRenderEv, 349273)
    off(_ZN10GUISelArmyD2Ev, 349449)
    off(_ZN10GUISelArmyD1Ev, 349449)
    off(_ZN10GUISelArmyD0Ev, 349497)
    off(_ZN10GUISelArmy8OnRenderEv, 349517)
    off(_ZN11GUIArmyItemC2Ev, 349569)
    off(_ZN11GUIArmyItemC1Ev, 349569)
    off(_ZN10GUISelArmyC2Ev, 349601)
    off(_ZN7ecImage8SetAlphaEfi, 558713)
    off(_ZN10GUISelArmy15MoveArmyToFrontEi, 349993)
    off(_ZN5CArea15MoveArmyToFrontEib, 407119)
    off(_ZN10GUISelArmy10TargetArmyEi, 350221)
    off(_ZN10GUISelArmy7OnEventERK5Event, 350281)
    off(_ZN12GUISmallCardD2Ev, 350377)
    off(_ZN12GUISmallCardD1Ev, 350377)
    off(_ZN12GUISmallCardD0Ev, 350425)
    off(_ZN12GUISmallCard8OnRenderEv, 350445)
    off(_ZN12GUISmallCardC2Ev, 350757)
    off(_ZN6GUITaxD2Ev, 350849)
    off(_ZN6GUITaxD1Ev, 350849)
    off(_ZN6GUITaxD0Ev, 350997)
    off(_ZN6GUITax8OnRenderEv, 351017)
    off(_ZN6GUITaxC2Ev, 351369)
    off(_ZN6GUITax8SetMoneyEi, 351465)
    off(_ZN6GUITax11SetIndustryEi, 351541)
    off(_ZN5CArea10GetRealTaxEv, 406895)
    off(_ZN5CArea11GetIndustryEv, 406945)
    off(_ZN5CArea11HasArmyCardEi, 407949)
    off(_ZN7GUITechD2Ev, 352309)
    off(_ZN7GUITechD1Ev, 352309)
    off(_ZN7GUITechD0Ev, 352401)
    off(_ZN7GUITech8OnRenderEv, 352421)
    off(_ZN7GUITech8OnUpdateEf, 352537)
    off(_ZN7GUITechC2Ev, 352573)
    off(_ZN12GUITutorails8OnRenderEv, 352865)
    off(_ZNK12TiXmlElement19QueryFloatAttributeEPKcPf, 353525)
    off(_ZN12GUITutorailsC2Ev, 353581)
    off(_ZN12GUITutorails10LoadScriptEv, 353673)
    off(_ZN12GUITutorails13ReleaseScriptEv, 355065)
    off(_ZN12GUITutorailsD2Ev, 355117)
    off(_ZN12GUITutorailsD1Ev, 355117)
    off(_ZN12GUITutorailsD0Ev, 355337)
    off(_ZN12GUITutorails7ShowDlgEi, 355357)
    off(_ZN12GUITutorails7ShowDlgEPKc, 355465)
    off(_ZN12GUITutorails7HideDlgEv, 355525)
    off(_ZN12GUITutorails6ExeCmdEi, 355529)
    off(_ZN6CScene16MoveCameraToAreaEi, 389471)
    off(_ZN6CScene22MoveCameraCenterToAreaEi, 389611)
    off(_ZN12GUITutorails8OnUpdateEf, 356065)
    off(_ZN6CScene8IsMovingEv, 389363)
    off(_ZN12GUITutorails7OnEventERK5Event, 356349)
    off(_ZN10GUIVictoryD2Ev, 356429)
    off(_ZN10GUIVictoryD1Ev, 356429)
    off(_ZN10GUIVictoryD0Ev, 356533)
    off(_ZN10GUIVictory8OnRenderEv, 356551)
    off(_ZN10GUIVictory8OnUpdateEf, 356689)
    off(_ZN10GUIVictoryC2Ev, 356909)
    off(_ZN10GUIVictory7OnEventERK5Event, 357597)
    off(_ZN10GUIWarning8OnUpdateEf, 357621)
    off(_ZN10GUIWarningD2Ev, 357625)
    off(_ZN10GUIWarningD1Ev, 357625)
    off(_ZN10GUIWarningD0Ev, 357709)
    off(_ZN10GUIWarning8OnRenderEv, 357729)
    off(_ZN10GUIWarningC2Ev, 357865)
    off(_ZN10GUIWarning7OnEventERK5Event, 358509)
    off(_ZN10CLoadState10TouchBeginEffi, 358621)
    off(_ZN10CLoadState9TouchMoveEffi, 358623)
    off(_ZN10CLoadState8TouchEndEffi, 358625)
    off(_ZN10CLoadState11BackPressedEv, 358627)
    off(_ZN10CLoadStateD2Ev, 358633)
    off(_ZN10CLoadStateD1Ev, 358633)
    off(_ZN10CLoadStateD0Ev, 358677)
    off(_ZN10CLoadState7OnEnterEv, 358705)
    off(_ZN10CLoadState6OnExitEv, 359245)
    off(_ZN10CLoadState6RenderEv, 359329)
    off(_ZN10CLoadState6UpdateEf, 359529)
    off(_ZN10CLoadState7OnEventERK5Event, 359573)
    off(_ZN10CLoadStateC2Ev, 359641)
    off(_ZN10CLogoStateD2Ev, 359697)
    off(_ZN10CLogoStateD1Ev, 359697)
    off(_ZN10CLogoState15EnterForegroundEv, 359707)
    off(_ZN10CLogoStateD0Ev, 359709)
    off(_ZN10CLogoState7OnEnterEv, 359737)
    off(_ZN10CLogoState6OnExitEv, 360437)
    off(_ZN10CLogoState6RenderEv, 360451)
    off(_ZN10CLogoState7OnEventERK5Event, 360539)
    off(_ZN10CLogoState6UpdateEf, 360581)
    off(_ZN14CPlayerManager4InitEv, 376261)
    off(_ZN10CLogoStateC2Ev, 360729)
    off(_ZN11CMatchStateD2Ev, 360761)
    off(_ZN11CMatchStateD1Ev, 360761)
    off(_ZN11CMatchState6UpdateEf, 360771)
    off(_ZN11CMatchState6RenderEv, 360773)
    off(_ZN11CMatchState10TouchBeginEffi, 360775)
    off(_ZN11CMatchState9TouchMoveEffi, 360777)
    off(_ZN11CMatchState8TouchEndEffi, 360779)
    off(_ZN11CMatchStateD0Ev, 360781)
    off(_ZN11CMatchState7OnEnterEv, 360809)
    off(_ZN13GUIMatchSetupC1Ev, 451913)
    off(_ZN13GUIMatchSetup4InitERK7GUIRect, 453145)
    off(_ZN11CMatchState6OnExitEv, 360997)
    off(_ZN11CMatchStateC2Ev, 361029)
    off(_ZN11CMatchState18StartMultiplayGameEi, 361061)
    off(_ZN11CMatchState7OnEventERK5Event, 361105)
    off(_ZN14CPlayerManager17SendStartLoadGameEv, 380105)
    off(_ZN11CMatchState11ShowWarningEi, 361289)
    off(_ZN10CMenuStateD2Ev, 361409)
    off(_ZN10CMenuStateD1Ev, 361409)
    off(_ZN10CMenuState6UpdateEf, 361419)
    off(_ZN10CMenuState6RenderEv, 361421)
    off(_ZN10CMenuState10TouchBeginEffi, 361423)
    off(_ZN10CMenuState9TouchMoveEffi, 361425)
    off(_ZN10CMenuState8TouchEndEffi, 361427)
    off(_ZN10CMenuStateD0Ev, 361429)
    off(_ZN10CMenuState7OnEnterEv, 361457)
    off(_ZN11GUIMainMenuC1Ev, 441657)
    off(_ZN11GUIMainMenu4InitERK7GUIRect, 441849)
    off(_ZN12GUISelBattleC1Ev, 465737)
    off(_ZN12GUISelBattle4InitERK7GUIRectii, 462701)
    off(_ZN10CMenuState6OnExitEv, 361805)
    off(_ZN10CMenuStateC2Ev, 361837)
    off(_ZN10CMenuState13PeerConnectedEv, 361865)
    off(_ZN10CMenuState18StartMultiplayGameEi, 361897)
    off(_ZN10CMenuState7OnEventERK5Event, 361941)
    off(_ZN10GUILoadingC1Ev, 440053)
    off(_ZN10GUILoading4InitERK7GUIRect, 440085)
    off(_ZN14CPlayerManager14DestroySessionEv, 380563)
    off(_ZN14CPlayerManager12SetupSessionEb, 376837)
    off(_ZN11GUIMainMenu6ShowADEv, 448925)
    off(_ZN12GUICommanderC1Ev, 431745)
    off(_ZN12GUICommander4InitERK7GUIRect, 432197)
    off(_ZN10GUIElement9FreeChildEPS_, 481275)
    off(_ZN13GUISelCountryC1Ev, 467853)
    off(_ZN13GUISelCountry4InitERK7GUIRecti, 468529)
    off(_ZN11GUIHostList17ResetConnectStateEv, 437445)
    off(_ZN11GUIHostListC1Ev, 436797)
    off(_ZN11GUIHostList4InitERK7GUIRect, 437709)
    off(_ZN14CPlayerManager9InitCorpsEi, 377789)
    off(_ZN10GUIServiceC1Ev, 470573)
    off(_ZN10GUIService4InitERK7GUIRect, 470673)
    off(_ZN11GUIMainMenu13RefreshNewTipEv, 441813)
    off(_ZN10GUINewGameC1Ev, 454733)
    off(_ZN10GUINewGame4InitERK7GUIRect, 456633)
    off(_ZN14CPlayerManager10StartMatchEv, 376631)
    off(_ZN14CPlayerManager9StopMatchEv, 380689)
    off(_ZN16GUILockedWarningC1Ev, 440605)
    off(_ZN16GUILockedWarning4InitERK7GUIRect, 440673)
    off(_ZN10CMenuState11ShowWarningEi, 364861)
    off(_ZN14GUIExitWarningC1Ev, 435093)
    off(_ZN14GUIExitWarning4InitERK7GUIRect, 435161)
    off(_ZN10CObjectDefC2Ev, 365141)
    off(_ZN10CObjectDefC1Ev, 365141)
    off(_ZN10CObjectDef11LoadCardDefEv, 365417)
    off(_ZN10CObjectDef14ReleaseArmyDefEv, 366057)
    off(_ZN10CObjectDef18ReleaseUnitMotionsEv, 366177)
    off(_ZN10CObjectDef20ReleaseUnitPositionsEv, 366373)
    off(_ZN10CObjectDef19ReleaseCommanderDefEv, 366475)
    off(_ZN10CObjectDef20ReleaseGeneralPhotosEv, 366593)
    off(_ZN10CObjectDef17ReleaseBattleListEv, 366705)
    off(_ZN10CObjectDef19ReleaseConquestListEv, 366919)
    off(_ZN10CObjectDef7ReleaseEv, 367043)
    off(_ZN10CObjectDefD2Ev, 367091)
    off(_ZN10CObjectDefD1Ev, 367091)
    off(_ZN10CObjectDef14GetConquestDefEPKc, 367485)
    off(_ZN10CObjectDef14GetUnitMotionsEPKcS1_, 367669)
    off(_ZN10CObjectDef15GetCommanderDefEPKc, 368137)
    off(_ZN10CObjectDef16GetUnitPositionsEPKc, 368257)
    off(_ZN10CObjectDef11LoadArmyDefEv, 368473)
    off(_ZN10CObjectDef15LoadUnitMotionsEv, 369641)
    off(_ZN10CObjectDef16LoadUnitPositonsEv, 370889)
    off(_ZN10CObjectDef16LoadCommanderDefEv, 371737)
    off(_ZN10CObjectDef17LoadGeneralPhotosEv, 372629)
    off(_ZN10CObjectDef14LoadBattleListEv, 373417)
    off(_ZN10CObjectDef16LoadConquestListEv, 375001)
    off(_ZN14CPlayerManager14WillDisconnectEv, 376039)
    off(_ZN14CPlayerManager34onLocalPlayerAuthenticationChangedEv, 376041)
    off(_ZN14CPlayerManager20onFriendListReceivedEv, 376051)
    off(_ZN14CPlayerManager14onMatchRequestEv, 376061)
    off(_ZN14CPlayerManager17onPlayerConnectedEPKc, 376077)
    off(_ZN14CPlayerManager17InvitationDidFailEPKc, 376127)
    off(_ZN11GUIHostList13ConnectFailedEv, 437453)
    off(_ZN14CPlayerManager16SessionNoNetworkEv, 376203)
    off(_Z9ecGetUUIDRSs, 528531)
    off(_Z13ecGetUUIDHashv, 528533)
    off(_ZN9ecGameKitC1Ev, 528477)
    off(_ZN9ecGameKit4InitEP17ecGameKitDelegateb, 528481)
    off(_ZN14CPlayerManager15AnalyzePeerNameERKSsRSsRiS3_, 376353)
    off(_ZN14CPlayerManager7ConnectEPKci, 376581)
    off(_ZN18ecSessionInterface7ConnectEPKc, 528513)
    off(_ZN14CPlayerManager13CancelConnectEv, 376621)
    off(_ZN18ecSessionInterface13CancelConnectEv, 528515)
    off(_ZN9ecGameKit25ShowMatchmakerWithRequestEiii, 528489)
    off(_ZN14CPlayerManager9AddPlayerEbPKc, 376657)
    off(_ZN7CPlayerC1Ev, 472281)
    off(_ZN7CPlayer4InitEbPKc, 472317)
    off(_ZN18ecSessionInterfaceC1Ev, 528501)
    off(_ZN18ecSessionInterface4InitEP17ecSessionDelegate, 528505)
    off(_ZN18ecSessionInterface12SetupSessionEb, 528509)
    off(_ZN18ecSessionInterface13GetDeviceNameERSs, 528529)
    off(_ZN14CPlayerManager10FindPlayerEPKc, 377001)
    off(_ZN14CPlayerManager20onPlayerInfoReceivedERSt4listIP12ecPlayerInfoSaIS2_EE, 377061)
    off(_ZN14CPlayerManager16FindPlayerByUUIDEi, 377131)
    off(_ZN14CPlayerManager17DidRecvInvitationEPKc, 377173)
    off(_ZN18ecSessionInterface11GetPeerNameEPKcRSs, 528527)
    off(_ZN18ecSessionInterface16AcceptInvitationEPKc, 528519)
    off(_ZN18ecSessionInterface17DeclineInvitationEPKc, 528521)
    off(_ZN14CPlayerManager21GetDisconnectedPlayerEv, 377401)
    off(_ZN14CPlayerManager18SendPacketToPlayerE12PacketHeaderPKviPKc, 377461)
    off(_ZN18ecSessionInterface10SendPacketEPKviPKc, 528523)
    off(_ZN9ecGameKit10SendPacketEPKviPKc, 528485)
    off(_ZN14CPlayerManager18SendPacketToPlayerE9PACKET_IDPKviP7CPlayer, 377565)
    off(_ZN14CPlayerManager28SendPacketToAllPlayersExceptE9PACKET_IDPKviP7CPlayer, 377567)
    off(_ZN7CPlayer10SendPacketE9PACKET_IDPKvi, 472381)
    off(_ZN7CPlayer10PushPacketE9PACKET_IDPKvi, 472509)
    off(_ZN14CPlayerManager10ClearCorpsEv, 377743)
    off(_ZN14CPlayerManager12GetLeftCorpsEi, 378253)
    off(_ZN14CPlayerManager13GetRightCorpsEi, 378261)
    off(_ZN14CPlayerManager15GetNumLeftCorpsEv, 378269)
    off(_ZN14CPlayerManager16GetNumRightCorpsEv, 378287)
    off(_ZN14CPlayerManager8SelCorpsEiiP7CPlayer, 378305)
    off(_ZN14CPlayerManager17RemoveCorpsPlayerEii, 378431)
    off(_ZN14CPlayerManager17RemoveCorpsPlayerEP7CPlayer, 378469)
    off(_ZN14CPlayerManager12RemovePlayerEP7CPlayer, 378523)
    off(_ZN7CPlayerD1Ev, 472701)
    off(_ZN14CPlayerManager20onPlayerDisconnectedEPKc, 378599)
    off(_ZN14CPlayerManager12GetCorpsDataERi, 378689)
    off(_ZN14CPlayerManager15onPeerConnectedEPKc, 378973)
    off(_ZN13GUIMatchSetup18RefreshCorsButtonsEv, 452573)
    off(_ZN14CPlayerManager14SetCorpsByDataEPviP7CPlayer, 379313)
    off(_ZN14CPlayerManager17IsAllPlayersReadyEv, 379689)
    off(_ZN14CPlayerManager23RefreshAndSendCorpsDataEv, 379797)
    off(_ZN14CPlayerManager18onPeerDisconnectedEPKc, 379913)
    off(_ZN14CPlayerManager14SendRoundBeginEv, 380269)
    off(_ZN14CPlayerManager18ClearRemotePlayersEv, 380483)
    off(_ZN14CPlayerManager12ClearPlayersEv, 380533)
    off(_ZN18ecSessionInterfaceD1Ev, 528503)
    off(_ZN9ecGameKitD1Ev, 528479)
    off(_ZN9ecGameKit22DisconnectCurrentMatchEv, 528491)
    off(_ZN14CPlayerManager16onAcceptedInviteEv, 380723)
    off(_ZN14CPlayerManager13WillTerminateEv, 380769)
    off(_ZN11GUIHostList13ClearHostListEv, 436837)
    off(_ZN14CPlayerManagerD2Ev, 380945)
    off(_ZN14CPlayerManagerD1Ev, 380945)
    off(_ZN14CPlayerManager19onPeerListDidChangeEv, 381041)
    off(_ZN18ecSessionInterface15GetPeerNameListERSt4listISsSaISsEES3_, 528511)
    off(_ZN11GUIHostList15RefreshHostListEv, 437461)
    off(_ZN14CPlayerManager9ReconnectEv, 381381)
    off(_ZN7CPlayer9SendFirstEv, 472597)
    off(_ZN14CPlayerManager12onMatchFoundEv, 381889)
    off(_ZN9ecGameKit18GetMatchPlayerListERSt4listISsSaISsEE, 528493)
    off(_ZN14CPlayerManager12onStartMatchEv, 381997)
    off(_ZN9ecGameKit18GetLocalPlayerInfoER12ecPlayerInfo, 528497)
    off(_ZN9ecGameKit19GetMatchPlayersInfoEv, 528495)
    off(_ZN14CPlayerManager16ClearActionQueueEv, 382679)
    off(_ZN14CPlayerManager14onReceivedDataEPKviPKcb, 382737)
    off(_ZN7CPlayer7RecvAckEi, 472801)
    off(_ZN7CPlayer7SendAckEi, 472757)
    off(_ZN13GUIMatchSetup16CreatCorsButtonsEv, 451957)
    off(_ZN14CPlayerManager22onReveivedDataFromPeerEPKviPKc, 383661)
    off(_ZN14CPlayerManager24onReceivedDataFromPlayerEPKviPKc, 383675)
    off(_ZN14CPlayerManagerC2Ev, 384089)
    off(_ZN14CPlayerManagerC1Ev, 384089)
    off(_ZN6CSceneD2Ev, 384395)
    off(_ZN9CAreaMarkD1Ev, 410403)
    off(_ZN6CSceneD1Ev, 384395)
    off(_ZN6CSceneC2Ev, 384489)
    off(_ZN9CAreaMarkC1Ev, 410379)
    off(_ZN7CCameraC1Ev, 419803)
    off(_ZN6CSceneC1Ev, 384489)
    off(_ZN6CScene17CheckAdjacentDataEv, 384645)
    off(_ZN6CScene9NewAdjoinEv, 384647)
    off(_ZN6CScene10LoadAdjoinEi, 384721)
    off(_ZN6CScene10SaveAdjoinEi, 384909)
    off(_ZN6CScene10MakeAdjoinEii, 385053)
    off(_ZN6CScene9DelAdjoinEii, 385167)
    off(_ZN6CScene8IsAdjoinEii, 385319)
    off(_ZN6CScene12RenderAdjoinEv, 385369)
    off(_ZN6CScene17RenderAreasCenterEv, 385371)
    off(_ZN6CScene15RenderAreasArmyEv, 385373)
    off(_ZN6CScene16RenderAreasPointEv, 385375)
    off(_ZN6CScene12LoadAreaDataEi, 385377)
    off(_ZN6CScene12SaveAreaDataEi, 385549)
    off(_ZN6CScene14RenderSeaAreasEv, 385757)
    off(_ZN7CCamera14IsRectInCameraEffff, 421417)
    off(_ZN6CScene13RenderAreasIDEv, 385969)
    off(_ZN6CScene10ClearAreasEv, 385971)
    off(_ZN5CAreaD1Ev, 406393)
    off(_ZN7CBomberD1Ev, 418363)
    off(_ZN11CBackgroundD1Ev, 411365)
    off(_ZN9CAreaMark7ReleaseEv, 410385)
    off(_ZN6CScene11SaveAreaTaxEi, 386197)
    off(_ZN6CScene14LoadAreaEnableEPKc, 386561)
    off(_ZN6CScene14SaveAreaEnableEPKc, 386729)
    off(_ZN6CScene20AreaDisableOutofRectEiiii, 386731)
    off(_ZN6CScene13InitAreaImageEi, 386821)
    off(_ZN6CScene12CalSceneRectERfS0_S0_S0_, 387705)
    off(_ZN6CScene13IsRectInSecenEffff, 388381)
    off(_ZN7CCamera5UpateEf, 421185)
    off(_ZN7CBomber6UpdateEf, 419093)
    off(_ZN6CMedal5UpateEf, 472099)
    off(_ZN5CArea6UpdateEf, 408457)
    off(_ZN6CScene11CreateArrowEii, 388857)
    off(_Z7InvSqrtf, 556393)
    off(_ZN9hgeVector6RotateEf, 556621)
    off(_ZN6CScene14ScreenToAreaIDEff, 389247)
    off(_ZN9CAreaMark7GetMarkEii, 410597)
    off(_ZN7CCamera4MoveEffb, 420317)
    off(_ZN6CScene6MoveToEii, 389331)
    off(_ZN7CCamera6MoveToEffb, 420837)
    off(_ZN7CCamera21IsRectInVisibleRegionEffff, 421537)
    off(_ZN6CScene21MoveCameraBetweenAreaEii, 389665)
    off(_ZN6CScene25GetTwoAreasDistanceSquareEii, 389925)
    off(_ZN6CScene19GetTwoAreasDistanceEii, 390001)
    off(_ZN6CScene19GetNumAdjacentAreasEi, 390087)
    off(_ZN6CScene17GetAdjacentAreaIDEii, 390099)
    off(_ZN6CScene15GetAdjacentAreaEii, 390117)
    off(_ZN7CCamera5ApplyEv, 421347)
    off(_ZN11CBackground6RenderEP7CCamera, 412077)
    off(_ZN11CBackground9RenderBoxEP7CCameraffff, 412177)
    off(_ZN5CArea14RenderBuildingEv, 409237)
    off(_ZN5CArea6RenderEv, 409393)
    off(_ZN8CCountry15AirstrikeRadiusEv, 424041)
    off(_ZN7ecImage9Render4VCEffffffffif, 558013)
    off(_ZN6CMedal6RenderEv, 472161)
    off(_ZN7CBomber6RenderEv, 419769)
    off(_ZN6CScene13CheckAdjacentEii, 391629)
    off(_ZN5CArea11HasArmyCardEii, 407921)
    off(_ZN6CScene17SetSelAreaTargetsEP5CArea, 392149)
    off(_ZN5CArea12EncirclementEv, 408385)
    off(_ZN6CScene8AirborneEi, 392703)
    off(_ZN7CBomber8AirborneEi, 418825)
    off(_ZN6CScene19AircraftCarrierBombEii, 392715)
    off(_ZN7CBomber19AircraftCarrierBombEii, 418805)
    off(_ZN6CScene8BombAreaEii, 392727)
    off(_ZN7CBomber8BombAreaEii, 418549)
    off(_ZN7CBomber9IsBombingEv, 419077)
    off(_ZN6CMedalC1Ev, 472077)
    off(_ZN6CMedal4InitEff, 472079)
    off(_ZN6CScene11LoadAreaTaxEi, 393013)
    off(_ZN5CAreaC1Ev, 406341)
    off(_ZN5CArea4InitEiRK8AreaInfo, 406499)
    off(_ZN6CScene9InitAreasEiPKc, 393541)
    off(_ZN6CScene20CreateRenderAreaListEv, 394625)
    off(_ZN9CAreaMark4InitEi, 410417)
    off(_ZN11CBackgroundC1Ev, 411301)
    off(_ZN11CBackground4InitEiiiiiffff, 411509)
    off(_ZN7CCamera4InitEffff, 419805)
    off(_ZN7CBomberC1Ev, 418353)
    off(_ZN7CBomber4InitEv, 418429)
    off(_ZN9CSoundResD2Ev, 395281)
    off(_ZN9CSoundResD1Ev, 395281)
    off(_ZN9CSoundResC2Ev, 395283)
    off(_ZN9CSoundResC1Ev, 395283)
    off(_ZN13CStateManagerD2Ev, 395441)
    off(_ZN13CStateManagerD1Ev, 395441)
    off(_ZN13CStateManagerC2Ev, 395443)
    off(_ZN13CStateManagerC1Ev, 395443)
    off(_ZN13CTouchInertiaD2Ev, 395753)
    off(_ZN13CTouchInertiaC2Ev, 395777)
    off(_ZN13CTouchInertia13AddTrackPointEff, 395933)
    off(_ZN13CTouchInertia13GetStartPointEv, 396033)
    off(_ZN9CActionAI11detectCardsE7CARD_ID, 396349)
    off(_ZN8CCountry12IsCardUnlockEP7CardDef, 422717)
    off(_ZN9CActionAI21analyseCompositePowerEv, 396457)
    off(_ZN9CActionAI12getAiPercentEi, 396757)
    off(_ZN9CActionAI14getNumArmyMoveEii, 397053)
    off(_ZN9CActionAI12purChaseCardE7CARD_ID, 397161)
    off(_ZN13CActionAssist21purChaseAirStrikeCardEv, 403421)
    off(_ZN13CActionAssist17purChaseDraftCardEb, 401881)
    off(_ZN13CActionAssist16purChaseFortCardEv, 402949)
    off(_ZN13CActionAssist17purChaseCardsCardEv, 402353)
    off(_ZN13CActionAssist21purChaseConstructCardEv, 399713)
    off(_ZN9CActionAI15sortArmyToFrontEv, 397353)
    off(_ZN5CArea12IsArmyActiveEi, 408277)
    off(_ZN9CActionAI8getMaxIdEv, 397777)
    off(_ZN9CActionAI13setArmyActionEP5CArea, 397849)
    off(_ZN13CActionAssist16actionToNextAreaEiiii, 404469)
    off(_ZN9CActionAI13moveAndAttackEv, 397981)
    off(_ZN13CActionAssist13calcAreaValueEP5CArea, 398657)
    off(_ZN13CActionAssist15aiCheckMoveableEiiii, 398753)
    off(_Z13GetAIRandSeedv, 399029)
    off(_ZN13CActionAssist9isBuyCardEP7CardDef, 399077)
    off(_ZN13CActionAssist13calcDraftTypeEbiP8CCountry, 399197)
    off(_ZN5CArea12GetCityLevelEv, 406853)
    off(_ZN13CActionAssist19purChaseSpecialCardEv, 400181)
    off(_ZN13CActionAssist11getAllianceEiii, 400185)
    off(_ZN13CActionAssist10searchNodeEii, 400321)
    off(_ZN13CActionAssist14searchNodeByIDEii, 400761)
    off(_ZN13CActionAssist11getNeighborEiiic, 400897)
    off(_ZN8CCountry19CheckCardTargetArmyEP7CardDefii, 423893)
    off(_ZN5CArea16GetIndustryLevelEv, 406911)
    off(_ZN13CActionAssist4isAIEi, 404293)
    off(_ZN5CAreaC2Ev, 406341)
    off(_ZN5CAreaD2Ev, 406393)
    off(_ZN5CArmyD1Ev, 410667)
    off(_ZN5CArea12CanConstructEi, 406603)
    off(_ZN5CArea9ConstructEi, 406663)
    off(_ZN5CArea10GetArmyIdxEP5CArmy, 406979)
    off(_ZN5CArea10RemoveArmyEP5CArmy, 407067)
    off(_ZN5CArea15MoveArmyToFrontEP5CArmyb, 407203)
    off(_ZN5CArea9DraftArmyEi, 407233)
    off(_ZN5CArea13SetMoveInArmyEPS_P5CArmybbPKc, 407345)
    off(_ZN5CArea10MoveArmyToEPS_, 407445)
    off(_ZN8CCountry10RemoveAreaEi, 425381)
    off(_ZN8CCountry14BeConquestedByEPS_, 425689)
    off(_ZN5CArea10SetArmyDirEif, 407851)
    off(_ZN5CArea11AddArmyCardEii, 407867)
    off(_ZN5CArea11DelArmyCardEii, 407893)
    off(_ZN5CArea18RevertArmyStrengthEi, 407985)
    off(_ZN5CArmy12LostStrengthEi, 410685)
    off(_ZN8CCountry12CommanderDieEv, 423581)
    off(_ZN5CArea15AddArmyStrengthEii, 408119)
    off(_ZN5CArmy11AddStrengthEi, 410855)
    off(_ZN5CArea16AllArmyPoisoningEv, 408143)
    off(_ZN5CArmy9PoisoningEv, 410839)
    off(_ZN5CArea11UpgradeArmyEi, 408173)
    off(_ZN5CArmy7UpgradeEv, 411001)
    off(_ZN5CArea18SetAllArmyMovementEi, 408193)
    off(_ZN5CArea17CheckEncirclementEv, 408301)
    off(_ZN5CArmy9SetMoraleEi, 411129)
    off(_ZN5CArea10RenderArmyEffiP5CArmy, 408929)
    off(_ZN5CArea9TurnBeginEv, 409809)
    off(_ZN5CArmy9TurnBeginEv, 411263)
    off(_ZN5CArea7TurnEndEv, 409875)
    off(_ZN5CArmy7TurnEndEv, 411277)
    off(_ZN5CArmy8SaveArmyEP12SaveArmyInfo, 411149)
    off(_ZN5CArmy8LoadArmyEPK12SaveArmyInfo, 411201)
    off(_ZN9CAreaMarkC2Ev, 410379)
    off(_ZN9CAreaMarkD2Ev, 410403)
    off(_ZN5CArmyC2Ev, 410665)
    off(_ZN5CArmyD2Ev, 410667)
    off(_ZN11CBackgroundC2Ev, 411301)
    off(_ZN11CBackgroundD2Ev, 411365)
    off(_ZN12CBattleSceneC2Ev, 412589)
    off(_ZN12CBattleScene7ReleaseEv, 412733)
    off(_ZN11CBattleUnit6RenderEv, 417913)
    off(_ZN8ecEffect6RenderEv, 565571)
    off(_Z13HasUnitMotionPKci, 413273)
    off(_ZN12CBattleScene11CreateUnitsEv, 413433)
    off(_ZN9ecLibraryC1Ev, 700953)
    off(_ZN9ecLibrary4LoadEPKcR12ecTextureRes, 701445)
    off(_ZN11CBattleUnitC1Ev, 417067)
    off(_ZN11CBattleUnit4InitEiiP9ecLibraryP11UnitMotions, 417087)
    off(_ZN11CBattleUnit12SetDestroyedEv, 418259)
    off(_ZN12CBattleScene12ReleaseUnitsEv, 414013)
    off(_ZN11CBattleUnitD1Ev, 417375)
    off(_ZN12CBattleScene10CreateFortEv, 414089)
    off(_ZN12CBattleScene11ReleaseFortEv, 414461)
    off(_ZN11CBattleUnit11IsAttackingEv, 418241)
    off(_ZN11CBattleUnit7DestroyEv, 418265)
    off(_ZN12CBattleScene9AddCraterEPKcfff, 415601)
    off(_ZN12CBattleScene10StarEffectEi, 415793)
    off(_ZN12CBattleScene9AddEffectEPKcff, 415817)
    off(_ZN15ecEffectManager12CreateEffectEPKc, 565649)
    off(_ZN11CBattleUnit6AttackEv, 418137)
    off(_ZN11CBattleUnit6UpdateEf, 417429)
    off(_ZN8ecEffect6UpdateEf, 565539)
    off(_ZN8ecEffect6IsLiveEv, 565599)
    off(_ZN8ecEffectD1Ev, 565257)
    off(_ZN12CBattleSceneD2Ev, 416863)
    off(_ZN11CBattleUnitC2Ev, 417067)
    off(_ZN9ecElementC1Ev, 702961)
    off(_ZN9ecElement4InitEPKcP9ecLibrary, 703535)
    off(_ZN9ecElement4PlayEv, 703653)
    off(_ZN11CBattleUnit7ReleaseEv, 417337)
    off(_ZN9ecElementD1Ev, 702977)
    off(_ZN11CBattleUnitD2Ev, 417375)
    off(_ZN9ecElement6UpdateEf, 704591)
    off(_ZN9ecElement6RenderERK7ecMtx32, 704133)
    off(_ZN9ecElement11SetCurFrameEi, 703565)
    off(_ZN9ecElement7SetLoopEi, 703737)
    off(_ZN9ecElement11GetPlayTimeEv, 703617)
    off(_ZN7CBomberC2Ev, 418353)
    off(_ZN7CBomberD2Ev, 418363)
    off(_ZN8CCountry7UseCardEP7CardDefii, 425765)
    off(_ZN7CCameraC2Ev, 419803)
    off(_ZN7CCamera12SetSceneRectEffff, 419915)
    off(_ZN8CCountryC2Ev, 421749)
    off(_ZN8CCountry8FindAreaEi, 421785)
    off(_ZN8CCountry15GetFirstCapitalEv, 422193)
    off(_ZN8CCountry18FindAdjacentAreaIDEib, 422305)
    off(_ZN8CCountry22FindAdjacentLandAreaIDEib, 422385)
    off(_ZN8CCountry13GetNumAirportEv, 422469)
    off(_ZN8CCountry18GetMinDstToAirportEi, 422521)
    off(_ZN8CCountry17GenCardTargetListE7CARD_ID, 422677)
    off(_ZN8CCountry16GetCurCardTargetEv, 422679)
    off(_ZN8CCountry14NextCardTargetEv, 422697)
    off(_ZN8CCountry12FinishActionEv, 422865)
    off(_ZN8CCountry16SetWarMedalLevelE11WARMEDAL_IDi, 424021)
    off(_ZN8CCountry12CollectTaxesEv, 425021)
    off(_ZN8CCountry16CollectIndustrysEv, 425141)
    off(_ZN8CCountryD2Ev, 425459)
    off(_ZN8CCountry8DoActionEv, 427161)
    off(_ZN17GUICommanderMedalD2Ev, 428041)
    off(_ZN17GUICommanderMedalD1Ev, 428041)
    off(_ZN17GUICommanderMedalD0Ev, 428145)
    off(_ZN11GUIWarMedalD2Ev, 428165)
    off(_ZN11GUIWarMedalD1Ev, 428165)
    off(_ZN11GUIWarMedalD0Ev, 428217)
    off(_ZN17GUICommanderMedal8OnUpdateEf, 428235)
    off(_ZN11GUIWarMedal8OnUpdateEf, 428333)
    off(_ZN17GUICommanderMedal8OnRenderEv, 428433)
    off(_ZN11GUIWarMedal8OnRenderEv, 428613)
    off(_ZN13GUIAdornMedalD2Ev, 428801)
    off(_ZN13GUIAdornMedalD1Ev, 428801)
    off(_ZN13GUIAdornMedalD0Ev, 428941)
    off(_ZN13GUIAdornMedal8OnRenderEv, 428961)
    off(_ZN16GUIUpgradeButtonD2Ev, 429349)
    off(_ZN16GUIUpgradeButtonD1Ev, 429349)
    off(_ZN16GUIUpgradeButtonD0Ev, 429405)
    off(_ZN16GUIUpgradeButton8OnRenderEv, 429425)
    off(_ZN6ecText14GetStringWidthEib, 569281)
    off(_ZN12GUICommanderD2Ev, 429801)
    off(_ZN12GUICommanderD1Ev, 429801)
    off(_ZN12GUICommanderD0Ev, 430037)
    off(_ZN12GUICommander8OnRenderEv, 430057)
    off(_ZN12GUICommander8OnUpdateEf, 430337)
    off(_ZN17GUICommanderMedalC2Ev, 430389)
    off(_ZN17GUICommanderMedalC1Ev, 430389)
    off(_ZN17GUICommanderMedal4InitERK7GUIRecti, 430445)
    off(_ZN17GUICommanderMedal13SetArrowColorEm, 430753)
    off(_ZN11GUIWarMedalC2Ev, 430765)
    off(_ZN11GUIWarMedalC1Ev, 430765)
    off(_ZN11GUIWarMedal8SetLevelEi, 430797)
    off(_ZN11GUIWarMedal4InitERK7GUIRect11WARMEDAL_IDi, 430941)
    off(_ZN11GUIWarMedal13SetArrowColorEm, 431085)
    off(_ZN13GUIAdornMedalC2Ev, 431097)
    off(_ZN13GUIAdornMedal7RefreshEv, 431153)
    off(_ZN16GUIUpgradeButtonC2Ev, 431553)
    off(_ZN16GUIUpgradeButtonC1Ev, 431553)
    off(_ZN16GUIUpgradeButton12SetNeedMedalEi, 431601)
    off(_ZN12GUICommanderC2Ev, 431745)
    off(_ZN12GUICommander16SetCommanderInfoEv, 431829)
    off(_ZN12GUICommander13SelectedMedalEi, 434265)
    off(_ZN12GUICommander7OnEventERK5Event, 434365)
    off(_ZN14GUIExitWarningD2Ev, 434917)
    off(_ZN14GUIExitWarningD1Ev, 434917)
    off(_ZN14GUIExitWarningD0Ev, 435009)
    off(_ZN14GUIExitWarning8OnRenderEv, 435029)
    off(_ZN14GUIExitWarningC2Ev, 435093)
    off(_ZN14GUIExitWarning7OnEventERK5Event, 435925)
    off(_ZN19GUIConnectHostStateD2Ev, 436033)
    off(_ZN19GUIConnectHostStateD1Ev, 436033)
    off(_ZN19GUIConnectHostStateD0Ev, 436069)
    off(_ZN11GUIHostItemD2Ev, 436089)
    off(_ZN11GUIHostItemD1Ev, 436089)
    off(_ZN11GUIHostItemD0Ev, 436141)
    off(_ZN11GUIHostList8OnRenderEv, 436159)
    off(_ZN19GUIConnectHostState8OnRenderEv, 436189)
    off(_ZN11GUIHostListD2Ev, 436377)
    off(_ZN11GUIHostListD1Ev, 436377)
    off(_ZN11GUIHostListD0Ev, 436453)
    off(_ZN19GUIConnectHostStateC2Ev, 436473)
    off(_ZN19GUIConnectHostStateC1Ev, 436473)
    off(_ZN19GUIConnectHostState4InitER7GUIRect, 436517)
    off(_ZN11GUIHostItemC2Ev, 436625)
    off(_ZN11GUIHostItemC1Ev, 436625)
    off(_ZN11GUIHostItem7SetNameEPKc, 436701)
    off(_ZN11GUIHostListC2Ev, 436797)
    off(_ZN11GUIHostList8FindHostEPKc, 436869)
    off(_ZN11GUIHostList14FindHostByUUIDEi, 436905)
    off(_ZN11GUIHostList7AddHostEPKcS1_ii, 436933)
    off(_ZN19GUIConnectHostState7OnEventERK5Event, 439153)
    off(_ZN11GUIHostList7OnEventERK5Event, 439177)
    off(_ZN11GUIHostItem8OnRenderEv, 439249)
    off(_ZN11GUILevelSelD2Ev, 439309)
    off(_ZN11GUILevelSelD1Ev, 439309)
    off(_ZN11GUILevelSelD0Ev, 439357)
    off(_ZN11GUILevelSel8OnRenderEv, 439377)
    off(_ZN11GUILevelSelC2Ev, 439525)
    off(_ZN11GUILevelSel7OnEventERK5Event, 439633)
    off(_ZN10GUILoadingD2Ev, 439801)
    off(_ZN10GUILoadingD1Ev, 439801)
    off(_ZN10GUILoadingD0Ev, 439869)
    off(_ZN10GUILoading8OnRenderEv, 439889)
    off(_ZN10GUILoadingC2Ev, 440053)
    off(_ZN10GUILoading7OnEventERK5Event, 440325)
    off(_ZN16GUILockedWarningD2Ev, 440345)
    off(_ZN16GUILockedWarningD1Ev, 440345)
    off(_ZN16GUILockedWarningD0Ev, 440437)
    off(_ZN16GUILockedWarning8OnRenderEv, 440457)
    off(_ZN16GUILockedWarningC2Ev, 440605)
    off(_ZN16GUILockedWarning7OnEventERK5Event, 441081)
    off(_ZN11GUIMainMenuD2Ev, 441217)
    off(_ZN11GUIMainMenuD1Ev, 441217)
    off(_ZN11GUIMainMenuD0Ev, 441577)
    off(_ZN11GUIMainMenu8OnRenderEv, 441597)
    off(_ZN11GUIMainMenuC2Ev, 441657)
    off(_ZN11GUIMainMenu12IsShowNewTipEv, 441721)
    off(_ZN9GUIButton12SetTextImageEPKc, 480637)
    off(_ZN8GUIImageC1Ev, 482245)
    off(_ZN8GUIImage4InitEPKcRK7GUIRect, 482409)
    off(_ZN11GUIMainMenu8OnUpdateEf, 447697)
    off(_ZN11GUIMainMenu7OnEventERK5Event, 448941)
    off(_ZN12GUICorpsInfoD2Ev, 449465)
    off(_ZN12GUICorpsInfoD1Ev, 449465)
    off(_ZN12GUICorpsInfoD0Ev, 449541)
    off(_ZN13GUIMatchSetup8OnRenderEv, 449559)
    off(_ZN14GUICorpsButton8OnRenderEv, 449589)
    off(_ZN12GUICorpsInfo8OnRenderEv, 449713)
    off(_ZN14GUICorpsButtonD2Ev, 450009)
    off(_ZN14GUICorpsButtonD1Ev, 450009)
    off(_ZN14GUICorpsButtonD0Ev, 450061)
    off(_ZN13GUIMatchSetupD2Ev, 450081)
    off(_ZN13GUIMatchSetupD1Ev, 450081)
    off(_ZN13GUIMatchSetupD0Ev, 450285)
    off(_ZN12GUICorpsInfoC2Ev, 450305)
    off(_ZN12GUICorpsInfoC1Ev, 450305)
    off(_ZN12GUICorpsInfo4InitERK7GUIRect, 450357)
    off(_ZN12GUICorpsInfo13SetPlayerNameEPKcbS1_iib, 450425)
    off(_ZN14GUICorpsButtonC2Ev, 450989)
    off(_ZN14GUICorpsButtonC1Ev, 450989)
    off(_ZN14GUICorpsButton4InitERK7GUIRectPKcb, 451021)
    off(_ZN14GUICorpsButton13SetPlayerNameEPKcbS1_iib, 451821)
    off(_ZN13GUIMatchSetupC2Ev, 451913)
    off(_ZN13GUIMatchSetup7OnEventERK5Event, 454305)
    off(_ZN10GUINewGameD2Ev, 454505)
    off(_ZN10GUINewGameD1Ev, 454505)
    off(_ZN10GUINewGameD0Ev, 454601)
    off(_ZN10GUINewGame8OnRenderEv, 454621)
    off(_ZN7_JNIEnv22CallStaticObjectMethodEP7_jclassP10_jmethodIDz, 454677)
    off(_ZN10GUINewGameC2Ev, 454733)
    off(_ZN10GUINewGame12IsShowSurveyEv, 454833)
    off(_ZN10GUINewGame12IsImageReadyEv, 454925)
    off(_ZN10GUINewGame18IsIabEventImgReadyEv, 455017)
    off(_ZN10GUINewGame15IsShowSurveyTipEv, 455109)
    off(_ZN10GUINewGame17IsShowIabEventTipEv, 455201)
    off(_ZN10GUINewGame14IsShowIabEventEv, 455293)
    off(_Z12JString2CStrP7_JNIEnvP8_jstring, 455385)
    off(_ZN10GUINewGame17GetPromotionImageEv, 455573)
    off(_ZN10GUINewGame16GetIabEventImageEv, 455785)
    off(_ZN10GUINewGame15GetPromotionUrlEv, 455997)
    off(_ZN10GUINewGame14BtnSurveyClickEv, 456113)
    off(_ZN10GUINewGame14GetIabEventUrlEv, 456193)
    off(_ZN10GUINewGame21OnRadioBtnSurveyClickEv, 456309)
    off(_ZN10GUINewGame23OnRadioBtnIabEventClickEv, 456409)
    off(_ZN10GUINewGame14GetSelectGroupEP14GUIRadioButton, 456509)
    off(_ZN10GUINewGame18OnCheckButtonClickEP14GUIRadioButton, 456549)
    off(_ZN10GUINewGame13GetAppVersionEv, 456627)
    off(_ZN9GUIButton13SetTextOffsetEff, 480791)
    off(_ZN9GUIButton12SetTextAlignEi, 480801)
    off(_ZN8GUIImage4InitEPKcRK13ecTextureRectRK7GUIRectbbb, 482285)
    off(_ZN7GUITextC1Ev, 486761)
    off(_ZN7GUIText4InitERK7GUIRectP9ecUniFont, 486789)
    off(_ZN7GUIText7SetTextEPKc, 486853)
    off(_ZN8GUIImage8SetImageEPKcRK13ecTextureRectb, 482497)
    off(_ZN10GUINewGame7OnEventERK5Event, 461977)
    off(_Z16ecLaunchAppStorePKc, 570185)
    off(_ZN12GUISelBattle8OnRenderEv, 462273)
    off(_ZN13GUIBattleListC1Ev, 474885)
    off(_ZN13GUIBattleList4InitERK7GUIRecti, 474945)
    off(_ZN13GUIBattleList18SelectLastUnlockedEv, 476069)
    off(_ZN13GUIBattleList9SetSelectEi, 475937)
    off(_ZN12GUISelBattle13LoadImageListEii, 464861)
    off(_ZN12GUISelBattleC2Ev, 465737)
    off(_ZN12GUISelBattle16ReleaseImageListEv, 465873)
    off(_ZN12GUISelBattleD2Ev, 465969)
    off(_ZN12GUISelBattleD1Ev, 465969)
    off(_ZN12GUISelBattleD0Ev, 466221)
    off(_ZN12GUISelBattle9SelBattleEii, 466239)
    off(_ZN12GUISelBattle8OnUpdateEf, 466265)
    off(_ZN12GUISelBattle7OnEventERK5Event, 466721)
    off(_ZN13GUISelCountry8OnRenderEv, 467145)
    off(_ZN13GUISelCountry8OnUpdateEf, 467409)
    off(_ZN13GUISelCountryC2Ev, 467853)
    off(_ZN13GUISelCountry9SelBattleEii, 467921)
    off(_ZN13GUISelCountry13LoadImageListEi, 467925)
    off(_ZN14GUICountryListC1Ev, 478101)
    off(_ZN14GUICountryList4InitERK7GUIRecti, 478669)
    off(_ZN13GUISelCountry16ReleaseImageListEv, 469969)
    off(_ZN13GUISelCountryD2Ev, 470033)
    off(_ZN13GUISelCountryD1Ev, 470033)
    off(_ZN13GUISelCountryD0Ev, 470233)
    off(_ZN13GUISelCountry7OnEventERK5Event, 470253)
    off(_ZN14GUICountryList15GetSelCountryIDEv, 478269)
    off(_ZN10GUIServiceD2Ev, 470401)
    off(_ZN10GUIServiceD1Ev, 470401)
    off(_ZN10GUIServiceD0Ev, 470497)
    off(_ZN10GUIService8OnRenderEv, 470517)
    off(_ZN10GUIServiceC2Ev, 470573)
    off(_ZN7GUIText8SetAlignEi, 486883)
    off(_ZN10GUIService7OnEventERK5Event, 471917)
    off(_ZN6CMedalC2Ev, 472077)
    off(_ZN7CPlayerC2Ev, 472281)
    off(_ZN7CPlayer10RecvPacketEPKvi, 472593)
    off(_ZN7CPlayer15ClearPacketListEv, 472653)
    off(_ZN7CPlayerD2Ev, 472701)
    off(_ZN13GUIBattleItem8OnUpdateEf, 472867)
    off(_ZN13GUIBattleItemD2Ev, 472869)
    off(_ZN13GUIBattleItemD1Ev, 472869)
    off(_ZN13GUIBattleItemD0Ev, 472977)
    off(_ZN13GUIBattleItem8OnRenderEv, 472997)
    off(_ZN13GUIBattleList8OnUpdateEf, 473997)
    off(_ZN13GUIBattleListD2Ev, 474373)
    off(_ZN13GUIBattleListD1Ev, 474373)
    off(_ZN13GUIBattleListD0Ev, 474417)
    off(_ZN13GUIBattleItemC2Ev, 474437)
    off(_ZN13GUIBattleItemC1Ev, 474437)
    off(_ZN13GUIBattleItem4InitEiiRK7GUIRect, 474473)
    off(_ZN13GUIBattleItem11SetSelectedEb, 474877)
    off(_ZN13GUIBattleListC2Ev, 474885)
    off(_ZN13GUIBattleList11ResetSelectEv, 475573)
    off(_ZN13GUIBattleList15ResetTouchStateEv, 475681)
    off(_ZN13GUIBattleList10GelSelItemEff, 475699)
    off(_ZN13GUIBattleItem7OnEventERK5Event, 475757)
    off(_ZN13GUIBattleList7OnEventERK5Event, 476101)
    off(_ZN14GUICountryItem8OnUpdateEf, 476545)
    off(_ZN14GUICountryItemD2Ev, 476549)
    off(_ZN14GUICountryItemD1Ev, 476549)
    off(_ZN14GUICountryItemD0Ev, 476617)
    off(_ZN14GUICountryItem8OnRenderEv, 476637)
    off(_ZN14GUICountryList8OnUpdateEf, 477433)
    off(_ZN14GUICountryListD2Ev, 477809)
    off(_ZN14GUICountryListD1Ev, 477809)
    off(_ZN14GUICountryListD0Ev, 477853)
    off(_ZN14GUICountryItemC2Ev, 477873)
    off(_ZN14GUICountryItemC1Ev, 477873)
    off(_ZN14GUICountryItem4InitEPKcS1_RK7GUIRect, 477905)
    off(_ZN14GUICountryItem11SetSelectedEb, 478093)
    off(_ZN14GUICountryListC2Ev, 478101)
    off(_ZN14GUICountryList11ResetSelectEv, 478161)
    off(_ZN14GUICountryList15ResetTouchStateEv, 478287)
    off(_ZN14GUICountryList10GelSelItemEff, 478305)
    off(_ZN14GUICountryItem7OnEventERK5Event, 478357)
    off(_ZN14GUICountryList9SetSelectEi, 478537)
    off(_ZN14GUICountryList7OnEventERK5Event, 479149)
    off(_ZN9GUIButtonD1Ev, 479593)
    off(_ZN9GUIButtonD0Ev, 479741)
    off(_ZN9GUIButton7SetGlowEPKc, 480477)
    off(_ZN6ecText9GetHeightEv, 569661)
    off(_ZN9GUIButton7SetTextEPKt, 480749)
    off(_ZN6ecText7SetTextEPKt, 570093)
    off(_ZN9GUIButton8SetAlphaEf, 480805)
    off(_ZN10GUIElementC1Ev, 481049)
    off(_ZN10GUIElement11RemoveChildEPS_, 481171)
    off(_ZN10GUIElementD1Ev, 481329)
    off(_ZN10GUIElementD0Ev, 481357)
    off(_ZN10GUIElement4MoveEff, 481449)
    off(_ZN10GUIElement11CheckInRectEffRK7GUIRect, 481753)
    off(_ZN10GUIElement10SetVisibleEb, 481835)
    off(_ZN10GUIElement12FindByHandleEm, 481891)
    off(_ZN10GUIElement9PostEventERK5Event, 481921)
    off(_ZN10GUIElement6RenderEv, 481975)
    off(_ZN10GUIElement6UpdateEf, 482011)
    off(_ZN8GUIImageD2Ev, 482049)
    off(_ZN8GUIImageD1Ev, 482049)
    off(_ZN8GUIImageD0Ev, 482117)
    off(_ZN8GUIImage8OnRenderEv, 482137)
    off(_ZN8GUIImageC2Ev, 482245)
    off(_ZN8GUIImage8SetAlphaEf, 482481)
    off(_ZN10GUIManager7OnEventERK5Event, 482813)
    off(_ZN10GUIManagerD2Ev, 482825)
    off(_ZN10GUIManagerD1Ev, 482825)
    off(_ZN10GUIManagerD0Ev, 482889)
    off(_ZN10GUIManagerC2Ev, 482909)
    off(_ZN10GUIManagerC1Ev, 482909)
    off(_ZN12GUIScrollBarC1Ev, 485733)
    off(_ZN12GUIScrollBar4InitERK7GUIRectPKcS4_iiiii, 485937)
    off(_ZN16GUIMotionManagerD2Ev, 483805)
    off(_ZN16GUIMotionManagerD1Ev, 483805)
    off(_ZN16GUIMotionManagerC2Ev, 483807)
    off(_ZN16GUIMotionManagerC1Ev, 483807)
    off(_ZN16GUIMotionManager9SetMotionEmffffft, 483999)
    off(_ZN16GUIMotionManager9AddMotionEP10GUIElementffffft, 484219)
    off(_ZN16GUIMotionManager10AddMotionXEP10GUIElementfft, 484401)
    off(_ZN16GUIMotionManager10AddMotionYEP10GUIElementfft, 484493)
    off(_ZN16GUIMotionManager8SetSpeedEmff, 484585)
    off(_ZN16GUIMotionManager15GetMotionActiveEm, 485177)
    off(_ZN14GUIRadioButtonD1Ev, 485193)
    off(_ZN14GUIRadioButtonD0Ev, 485221)
    off(_ZN14GUIRadioButton8OnRenderEv, 485241)
    off(_ZN12GUIScrollBarD2Ev, 485557)
    off(_ZN12GUIScrollBarD1Ev, 485557)
    off(_ZN12GUIScrollBarD0Ev, 485625)
    off(_ZN12GUIScrollBar8OnRenderEv, 485645)
    off(_ZN12GUIScrollBarC2Ev, 485733)
    off(_ZN12GUIScrollBar7OnEventERK5Event, 486129)
    off(_ZN7GUITextD2Ev, 486637)
    off(_ZN7GUITextD1Ev, 486637)
    off(_ZN7GUITextD0Ev, 486685)
    off(_ZN7GUIText8OnRenderEv, 486705)
    off(_ZN7GUITextC2Ev, 486761)
    off(_ZN7GUIText12SetTextColorEm, 486873)
    off(_ZN9ecGameKitC2Ev, 528477)
    off(_ZN9ecGameKitD2Ev, 528479)
    off(_ZN9ecGameKit7ReleaseEv, 528483)
    off(_ZN9ecGameKit22SendPacketToAllPlayersEPKvi, 528487)
    off(_ZN18ecSessionInterfaceC2Ev, 528501)
    off(_ZN18ecSessionInterfaceD2Ev, 528503)
    off(_ZN18ecSessionInterface7ReleaseEv, 528507)
    off(_ZN18ecSessionInterface10DisconnectEPKc, 528517)
    off(_ZN18ecSessionInterface20SendPacketToAllPeersEPKvi, 528525)
    off(_ZN11TiXmlString4quitEv, 528537)
    off(_ZN11TiXmlString7reserveEj, 528561)
    off(_ZN11TiXmlString6assignEPKcj, 528713)
    off(_ZN11TiXmlString6appendEPKcj, 528885)
    off(_ZN11TiXmlStringpLERKS_, 528941)
    off(_ZNK9TiXmlNode10ToDocumentEv, 529161)
    off(_ZNK9TiXmlNode9ToElementEv, 529165)
    off(_ZNK9TiXmlNode9ToCommentEv, 529169)
    off(_ZNK9TiXmlNode9ToUnknownEv, 529173)
    off(_ZNK9TiXmlNode6ToTextEv, 529177)
    off(_ZNK9TiXmlNode13ToDeclarationEv, 529181)
    off(_ZN9TiXmlNode10ToDocumentEv, 529185)
    off(_ZN9TiXmlNode9ToElementEv, 529189)
    off(_ZN9TiXmlNode9ToCommentEv, 529193)
    off(_ZN9TiXmlNode9ToUnknownEv, 529197)
    off(_ZN9TiXmlNode6ToTextEv, 529201)
    off(_ZN9TiXmlNode13ToDeclarationEv, 529205)
    off(_ZNK12TiXmlElement9ToElementEv, 529209)
    off(_ZN12TiXmlElement9ToElementEv, 529211)
    off(_ZNK12TiXmlComment9ToCommentEv, 529213)
    off(_ZN12TiXmlComment9ToCommentEv, 529215)
    off(_ZNK9TiXmlText6ToTextEv, 529217)
    off(_ZN9TiXmlText6ToTextEv, 529219)
    off(_ZNK16TiXmlDeclaration13ToDeclarationEv, 529221)
    off(_ZN16TiXmlDeclaration13ToDeclarationEv, 529223)
    off(_ZNK12TiXmlUnknown9ToUnknownEv, 529225)
    off(_ZN12TiXmlUnknown9ToUnknownEv, 529227)
    off(_ZNK12TiXmlUnknown5PrintEP7__sFILEi, 529229)
    off(_ZNK16TiXmlDeclaration5PrintEP7__sFILEi, 529289)
    off(_ZNK12TiXmlComment5PrintEP7__sFILEi, 529393)
    off(_ZN11TiXmlStringC2EPKc, 529453)
    off(_ZN11TiXmlStringC1EPKc, 529453)
    off(_ZN11TiXmlStringaSEPKc, 529537)
    off(_ZN11TiXmlStringpLEPKc, 529563)
    off(_ZNK12TiXmlComment9StreamOutEP14TiXmlOutStream, 529589)
    off(_ZNK12TiXmlUnknown9StreamOutEP14TiXmlOutStream, 529637)
    off(_ZNK11TiXmlString4findEc, 529685)
    off(_ZN9TiXmlBase9PutStringERK11TiXmlStringPS0_, 529729)
    off(_ZN9TiXmlBase9PutStringERK11TiXmlStringP14TiXmlOutStream, 530009)
    off(_ZNK9TiXmlText9StreamOutEP14TiXmlOutStream, 530093)
    off(_ZNK16TiXmlDeclaration9StreamOutEP14TiXmlOutStream, 530157)
    off(_ZNK9TiXmlText5PrintEP7__sFILEi, 530329)
    off(_ZN9TiXmlBase14StringToBufferC2ERK11TiXmlString, 530505)
    off(_ZN9TiXmlBase14StringToBufferC1ERK11TiXmlString, 530505)
    off(_ZN9TiXmlBase14StringToBufferD2Ev, 530535)
    off(_ZN9TiXmlBase14StringToBufferD1Ev, 530535)
    off(_ZN9TiXmlNodeC2ENS_8NodeTypeE, 530553)
    off(_ZN9TiXmlNodeC1ENS_8NodeTypeE, 530553)
    off(_ZN9TiXmlNodeD1Ev, 530609)
    off(_ZN12TiXmlUnknownD2Ev, 530657)
    off(_ZN12TiXmlUnknownD1Ev, 530657)
    off(_ZN12TiXmlUnknownD0Ev, 530685)
    off(_ZN16TiXmlDeclarationD2Ev, 530705)
    off(_ZN16TiXmlDeclarationD1Ev, 530705)
    off(_ZN16TiXmlDeclarationD0Ev, 530757)
    off(_ZN9TiXmlTextD2Ev, 530777)
    off(_ZN9TiXmlTextD1Ev, 530777)
    off(_ZN9TiXmlTextD0Ev, 530805)
    off(_ZN12TiXmlCommentD2Ev, 530825)
    off(_ZN12TiXmlCommentD1Ev, 530825)
    off(_ZN12TiXmlCommentD0Ev, 530853)
    off(_ZN9TiXmlNodeD0Ev, 530871)
    off(_ZNK9TiXmlNode6CopyToEPS_, 530889)
    off(_ZN9TiXmlNode5ClearEv, 530913)
    off(_ZN9TiXmlNode14InsertEndChildERKS_, 530963)
    off(_ZN9TiXmlNode17InsertBeforeChildEPS_RKS_, 530991)
    off(_ZN9TiXmlNode16InsertAfterChildEPS_RKS_, 531041)
    off(_ZN9TiXmlNode12ReplaceChildEPS_RKS_, 531091)
    off(_ZN9TiXmlNode11RemoveChildEPS_, 531161)
    off(_ZNK9TiXmlNode10FirstChildEPKc, 531207)
    off(_ZNK9TiXmlNode9LastChildEPKc, 531263)
    off(_ZN9TiXmlNode9LastChildEPKc, 531291)
    off(_ZNK9TiXmlNode15IterateChildrenEPKS_, 531319)
    off(_ZN9TiXmlNode15IterateChildrenEPS_, 531329)
    off(_ZNK9TiXmlNode11NextSiblingEPKc, 531339)
    off(_ZNK9TiXmlNode15IterateChildrenEPKcPKS_, 531367)
    off(_ZN9TiXmlNode11NextSiblingEPKc, 531379)
    off(_ZN9TiXmlNode15IterateChildrenEPKcPS_, 531407)
    off(_ZNK9TiXmlNode15PreviousSiblingEPKc, 531419)
    off(_ZN9TiXmlNode15PreviousSiblingEPKc, 531447)
    off(_ZNK9TiXmlNode17FirstChildElementEv, 531475)
    off(_ZN9TiXmlNode17FirstChildElementEv, 531511)
    off(_ZNK9TiXmlNode17FirstChildElementEPKc, 531547)
    off(_ZN9TiXmlNode17FirstChildElementEPKc, 531593)
    off(_ZNK9TiXmlNode18NextSiblingElementEv, 531639)
    off(_ZN9TiXmlNode18NextSiblingElementEv, 531675)
    off(_ZNK9TiXmlNode18NextSiblingElementEPKc, 531711)
    off(_ZN9TiXmlNode18NextSiblingElementEPKc, 531753)
    off(_ZNK9TiXmlNode11GetDocumentEv, 531795)
    off(_ZN9TiXmlNode11GetDocumentEv, 531831)
    off(_ZNK12TiXmlElement7GetTextEv, 531867)
    off(_ZN13TiXmlDocumentC2Ev, 531893)
    off(_ZN13TiXmlDocumentC1Ev, 531893)
    off(_ZN13TiXmlDocumentC2EPKc, 531997)
    off(_ZN13TiXmlDocument8LoadFileEP7__sFILE13TiXmlEncoding, 532113)
    off(_ZN13TiXmlDocument8SetErrorEiPKcP16TiXmlParsingData13TiXmlEncoding, 538017)
    off(_ZN13TiXmlDocument8LoadFileEPKc13TiXmlEncoding, 532445)
    off(_ZNK13TiXmlDocument8SaveFileEP7__sFILE, 532641)
    off(_ZNK13TiXmlDocument8SaveFileEPKc, 532693)
    off(_ZNK13TiXmlDocument6CopyToEPS_, 532817)
    off(_ZN13TiXmlDocumentC2ERKS_, 532873)
    off(_ZN13TiXmlDocumentC1ERKS_, 532873)
    off(_ZN13TiXmlDocumentaSERKS_, 532949)
    off(_ZNK13TiXmlDocument5CloneEv, 532971)
    off(_ZNK13TiXmlDocument5PrintEP7__sFILEi, 533009)
    off(_ZNK13TiXmlDocument9StreamOutEP14TiXmlOutStream, 533045)
    off(_ZNK14TiXmlAttribute4NextEv, 533079)
    off(_ZNK12TiXmlElement5PrintEP7__sFILEi, 533101)
    off(_ZNK12TiXmlElement9StreamOutEP14TiXmlOutStream, 533377)
    off(_ZN14TiXmlAttribute4NextEv, 533549)
    off(_ZNK14TiXmlAttribute8PreviousEv, 533569)
    off(_ZN14TiXmlAttribute8PreviousEv, 533589)
    off(_ZNK14TiXmlAttribute5PrintEP7__sFILEi, 533609)
    off(_ZNK14TiXmlAttribute9StreamOutEP14TiXmlOutStream, 533773)
    off(_ZNK14TiXmlAttribute13QueryIntValueEPi, 533897)
    off(_ZNK14TiXmlAttribute16QueryDoubleValueEPd, 533929)
    off(_ZN14TiXmlAttribute11SetIntValueEi, 533961)
    off(_ZN14TiXmlAttribute14SetDoubleValueEd, 534029)
    off(_ZNK14TiXmlAttribute8IntValueEv, 534101)
    off(_ZNK14TiXmlAttribute11DoubleValueEv, 534109)
    off(_ZNK12TiXmlComment6CopyToEPS_, 534119)
    off(_ZN12TiXmlCommentC2ERKS_, 534125)
    off(_ZN12TiXmlCommentC1ERKS_, 534125)
    off(_ZN12TiXmlCommentaSERKS_, 534173)
    off(_ZNK12TiXmlComment5CloneEv, 534197)
    off(_ZNK9TiXmlText6CopyToEPS_, 534253)
    off(_ZNK9TiXmlText5CloneEv, 534273)
    off(_ZN16TiXmlDeclarationC2EPKcS1_S1_, 534357)
    off(_ZN16TiXmlDeclarationC1EPKcS1_S1_, 534357)
    off(_ZNK16TiXmlDeclaration6CopyToEPS_, 534477)
    off(_ZN16TiXmlDeclarationC2ERKS_, 534541)
    off(_ZN16TiXmlDeclarationC1ERKS_, 534541)
    off(_ZN16TiXmlDeclarationaSERKS_, 534629)
    off(_ZNK16TiXmlDeclaration5CloneEv, 534653)
    off(_ZNK12TiXmlUnknown6CopyToEPS_, 534725)
    off(_ZNK12TiXmlUnknown5CloneEv, 534729)
    off(_ZN17TiXmlAttributeSetC2Ev, 534785)
    off(_ZN17TiXmlAttributeSetC1Ev, 534785)
    off(_ZN17TiXmlAttributeSetD2Ev, 534837)
    off(_ZN17TiXmlAttributeSetD1Ev, 534837)
    off(_ZN12TiXmlElementC2EPKc, 534873)
    off(_ZN17TiXmlAttributeSet3AddEP14TiXmlAttribute, 534949)
    off(_ZN17TiXmlAttributeSet6RemoveEP14TiXmlAttribute, 534963)
    off(_ZN12TiXmlElement9ClearThisEv, 534997)
    off(_ZN12TiXmlElementD2Ev, 535037)
    off(_ZN12TiXmlElementD1Ev, 535037)
    off(_ZN12TiXmlElementD0Ev, 535081)
    off(_ZNK17TiXmlAttributeSet4FindERK11TiXmlString, 535099)
    off(_ZNK12TiXmlElement9AttributeEPKcPi, 535225)
    off(_ZNK12TiXmlElement9AttributeEPKcPd, 535253)
    off(_ZN17TiXmlAttributeSet4FindERK11TiXmlString, 535469)
    off(_ZN12TiXmlElement15RemoveAttributeEPKc, 535517)
    off(_ZNK12TiXmlElement6CopyToEPS_, 535973)
    off(_ZN12TiXmlElementC2ERKS_, 536049)
    off(_ZN12TiXmlElementC1ERKS_, 536049)
    off(_ZN12TiXmlElementaSERKS_, 536121)
    off(_ZNK12TiXmlElement5CloneEv, 536143)
    off(_ZNK11TiXmlHandle10FirstChildEv, 536207)
    off(_ZNK11TiXmlHandle10FirstChildEPKc, 536217)
    off(_ZNK11TiXmlHandle17FirstChildElementEv, 536245)
    off(_ZNK11TiXmlHandle17FirstChildElementEPKc, 536271)
    off(_ZNK11TiXmlHandle5ChildEi, 536299)
    off(_ZNK11TiXmlHandle5ChildEPKci, 536325)
    off(_ZNK11TiXmlHandle12ChildElementEi, 536373)
    off(_ZNK11TiXmlHandle12ChildElementEPKci, 536415)
    off(_ZN12TiXmlElement5ParseEPKcP16TiXmlParsingData13TiXmlEncoding, 540581)
    off(_ZN12TiXmlComment5ParseEPKcP16TiXmlParsingData13TiXmlEncoding, 539241)
    off(_ZN9TiXmlText5ParseEPKcP16TiXmlParsingData13TiXmlEncoding, 539377)
    off(_ZN16TiXmlDeclaration5ParseEPKcP16TiXmlParsingData13TiXmlEncoding, 539677)
    off(_ZN12TiXmlUnknown5ParseEPKcP16TiXmlParsingData13TiXmlEncoding, 539089)
    off(_ZNK13TiXmlDocument10ToDocumentEv, 536463)
    off(_ZN13TiXmlDocument10ToDocumentEv, 536465)
    off(_ZN11TiXmlStringpLEc, 536467)
    off(_ZN14TiXmlAttributeD2Ev, 536489)
    off(_ZN14TiXmlAttributeD1Ev, 536489)
    off(_ZN14TiXmlAttributeD0Ev, 536525)
    off(_ZN9TiXmlBase12IsWhiteSpaceEc, 536543)
    off(_ZN9TiXmlBase18ConvertUTF32ToUTF8EmPcPi, 536573)
    off(_ZN9TiXmlBase7IsAlphaEh13TiXmlEncoding, 536769)
    off(_ZN9TiXmlBase10IsAlphaNumEh13TiXmlEncoding, 536781)
    off(_ZN16TiXmlParsingData5StampEPKc13TiXmlEncoding, 536793)
    off(_ZN9TiXmlBase14SkipWhiteSpaceEPKc13TiXmlEncoding, 536981)
    off(_ZN9TiXmlBase8ReadNameEPKcP11TiXmlString13TiXmlEncoding, 537093)
    off(_ZN9TiXmlBase9GetEntityEPKcPcPi13TiXmlEncoding, 537193)
    off(_ZN9TiXmlBase7GetCharEPKcPcPi13TiXmlEncoding, 537553)
    off(_ZN9TiXmlBase11StringEqualEPKcS1_b13TiXmlEncoding, 537633)
    off(_ZN9TiXmlBase8ReadTextEPKcP11TiXmlStringbS1_b13TiXmlEncoding, 537749)
    off(_ZN14TiXmlAttribute5ParseEPKcP16TiXmlParsingData13TiXmlEncoding, 538097)
    off(_ZN9TiXmlNode8IdentifyEPKc13TiXmlEncoding, 538353)
    off(_ZN13TiXmlDocument5ParseEPKcP16TiXmlParsingData13TiXmlEncoding, 538721)
    off(_ZNK9TiXmlText5BlankEv, 540261)
    off(_ZN12TiXmlElement9ReadValueEPKcP16TiXmlParsingData13TiXmlEncoding, 540297)
    off(_ZN9hgeVector9NormalizeEv, 556445)
    off(_ZNK9hgeVector5AngleEPKS_, 556505)
    off(_ZN7ecImageD2Ev, 556691)
    off(_ZN7ecImage4InitEP9ecTextureffff, 556693)
    off(_ZN7ecImageC2EP9ecTextureffff, 556857)
    off(_ZN7ecImageC2EP9ecTextureRK13ecTextureRect, 556879)
    off(_ZN7ecImageC2EP11ecImageAttr, 556915)
    off(_ZN7ecImage13RenderStretchEffff, 557713)
    off(_ZN7ecImage8Render4VEffffffff, 557849)
    off(_ZN7ecImage10SetTextureEP9ecTexture, 558533)
    off(_ZN7ecImage7SetFlipEbbb, 558805)
    off(_ZN7ecImage14SetTextureRectEffff, 558991)
    off(_ZN7ecImage14SetTextureRectERK13ecTextureRect, 559115)
    off(_ZN12ecTextureResC2Ev, 559147)
    off(_ZN12ecTextureRes14ReleaseTextureEP9ecTexture, 559197)
    off(_ZN12ecTextureResD2Ev, 559481)
    off(_ZN12ecTextureRes10GetTextureEPKc, 559505)
    off(_ZN12ecTextureRes13CreateTextureEPKcbbb, 559849)
    off(_ZN12ecTextureRes11CreateImageEPKcS1_ffffff, 560769)
    off(_ZN12ecTextureRes11CreateImageEPKcP9ecTextureffffff, 560965)
    off(_ZN11ecEffectResC2Ev, 561809)
    off(_ZN11ecEffectResC1Ev, 561809)
    off(_ZN11ecEffectRes7ReleaseEv, 561825)
    off(_ZN11ecEffectResD2Ev, 561887)
    off(_ZN11ecEffectResD1Ev, 561887)
    off(_ZN11ecEffectRes10LoadEffectEPKcP12ecTextureRes, 561905)
    off(_ZN18ecEffectResManager16ReleaseEffectResEP11ecEffectRes, 564211)
    off(_ZN18ecEffectResManagerD2Ev, 564389)
    off(_ZN18ecEffectResManagerD1Ev, 564389)
    off(_ZN18ecEffectResManagerC2Ev, 564411)
    off(_ZN18ecEffectResManagerC1Ev, 564411)
    off(_ZN18ecEffectResManager16ReleaseEffectResEPKc, 564521)
    off(_ZN8ecEffectC2Ev, 565241)
    off(_ZN8ecEffectC1Ev, 565241)
    off(_ZN8ecEffectD2Ev, 565257)
    off(_ZN8ecEffect4InitEPKcP9TFreeListI16ecParticleSystemE, 565297)
    off(_ZN16ecParticleSystem4InitEP13ecEmitterAttr, 570389)
    off(_ZN16ecParticleSystem6FireAtEfff, 570637)
    off(_ZN8ecEffect4FireEv, 565435)
    off(_ZN16ecParticleSystem4FireEv, 570469)
    off(_ZN8ecEffect4StopEb, 565463)
    off(_ZN16ecParticleSystem4StopEb, 570479)
    off(_ZN8ecEffect6MoveToEffb, 565495)
    off(_ZN16ecParticleSystem6MoveToEffb, 570489)
    off(_ZN16ecParticleSystem6UpdateEf, 570885)
    off(_ZN16ecParticleSystem6RenderEv, 570675)
    off(_ZN16ecParticleSystem6IsLiveEv, 572657)
    off(_ZN9TFreeListI16ecParticleSystemED2Ev, 565891)
    off(_ZN16ecParticleSystemD1Ev, 570387)
    off(_ZN9TFreeListI16ecParticleSystemED1Ev, 565891)
    off(_ZN15ecEffectManagerD2Ev, 566021)
    off(_ZN15ecEffectManagerD1Ev, 566021)
    off(_ZN15ecEffectManagerC2Ev, 566049)
    off(_ZN16ecParticleSystemC1Ev, 570343)
    off(_ZN15ecEffectManagerC1Ev, 566049)
    off(_ZN9ecUniFontC2Ev, 566245)
    off(_ZN9ecUniFont12GetCharImageEt, 566279)
    off(_ZN9ecUniFontD2Ev, 566449)
    off(_ZN11ecLabelTextC2Ev, 567601)
    off(_ZN11ecLabelTextD2Ev, 567625)
    off(_ZN11ecLabelText8SetAlphaEf, 567849)
    off(_ZN10CCSoundBoxC2Ev, 567929)
    off(_ZN10CCSoundBoxC1Ev, 567929)
    off(_ZN10CCSoundBoxD2Ev, 567953)
    off(_ZN10CCSoundBoxD1Ev, 567953)
    off(_ZN10CCSoundBox15InitSoundSystemEv, 567967)
    off(_ZN10CCSoundBox18DestroySoundSystemEv, 568025)
    off(_ZN10CCSoundBox9StopMusicEv, 568087)
    off(_ZN10CCSoundBox9StopAllSEEv, 568179)
    off(_ZN13ecStringTableC2Ev, 568185)
    off(_ZN13ecStringTableD2Ev, 568285)
    off(_ZN6ecTextC2Ev, 569189)
    off(_ZN6ecTextD2Ev, 569201)
    off(_ZN6ecText11GetNumLinesEv, 569769)
    off(_Z22ecSetIdleTimerDisabledb, 570189)
    off(_Z10ColorClampRf, 570301)
    off(_ZN16ecParticleSystemC2Ev, 570343)
    off(_ZN16ecParticleSystemD2Ev, 570387)
    off(_ZN9ecLibraryC2Ev, 700953)
    off(_ZN9ecLibrary11GetItemDataEi, 701005)
    off(_ZN9ecLibrary14GetElementDataEi, 701029)
    off(_ZN9ecLibrary12GetFrameDataEi, 701053)
    off(_ZN9ecLibrary12GetLayerDataEi, 701063)
    off(_ZN9ecLibrary11GetItemNameEm, 701071)
    off(_ZN9ecLibraryD2Ev, 701117)
    off(_ZN7ecShapeD1Ev, 704761)
    off(_ZN9ecLibraryD1Ev, 701117)
    off(_ZN9ecLibraryD0Ev, 701209)
    off(_ZN9ecLibrary12FindItemDataEPKc, 701229)
    off(_Z13ecLoadLibraryPKcR13ecLibraryData, 702161)
    off(_ZN7ecShapeC1Ev, 704759)
    off(_ZN7ecShape4InitEP9ecTextureffff, 704763)
    off(_Z14ecSaveLibrarayPKcR13ecLibraryDataS0_i, 702593)
    off(_ZN9ecElementC2Ev, 702961)
    off(_ZN9ecElementD2Ev, 702977)
    off(_ZN9ecElement4InitEP10ecItemDataP9ecLibrary, 703107)
    off(_ZN7ecLayerC1Ev, 705097)
    off(_ZN7ecFrameC1Ev, 705513)
    off(_ZN7ecLayer4InitEiP11ecLayerDataP7ecFrameP9ecElementP9ecLibrary, 705217)
    off(_ZN7ecLayer11SetCurFrameEi, 705315)
    off(_ZN9ecElement5ResetEv, 703605)
    off(_ZN7ecLayer4PlayEv, 705157)
    off(_ZN9ecElement4StopEv, 703695)
    off(_ZN7ecLayer4StopEv, 705185)
    off(_ZN7ecLayer7SetLoopEi, 705213)
    off(_ZN9ecElement4InitEP13ecElementDataP9ecLibrary, 703779)
    off(_ZN9ecElement9ResetItemEP10ecItemDataP9ecLibrary, 703833)
    off(_ZN9ecElement10ChangeItemEP10ecItemDataS1_P9ecLibrary, 704015)
    off(_ZN7ecLayer10ChangeItemEP10ecItemDataS1_P9ecLibrary, 705113)
    off(_ZN9ecElement10ChangeItemEPKcS1_P9ecLibrary, 704083)
    off(_ZN7ecShape8SetColorEm, 705057)
    off(_ZN7ecLayer6RenderERK7ecMtx32, 705373)
    off(_ZN7ecShape6RenderERK7ecMtx32, 704895)
    off(_ZN9ecElement9NextFrameEv, 704505)
    off(_ZN7ecLayer9NextFrameEv, 705393)
    off(_Z10ecMtx32MulRfS_RK7ecMtx32, 704689)
    off(_ZN7ecShapeC2Ev, 704759)
    off(_ZN7ecShapeD2Ev, 704761)
    off(_ZN7ecLayerD2Ev, 705077)
    off(_ZN7ecLayerD1Ev, 705077)
    off(_ZN7ecLayerD0Ev, 705079)
    off(_ZN7ecLayerC2Ev, 705097)
    off(_ZN7ecFrame10ChangeItemEP10ecItemDataS1_P9ecLibrary, 705623)
    off(_ZN7ecFrame4PlayEv, 705735)
    off(_ZN7ecFrame4StopEv, 705765)
    off(_ZN7ecFrame4InitEP11ecFrameDataP9ecElementP9ecLibrary, 705529)
    off(_ZN7ecFrame6RenderERK7ecMtx32, 705671)
    off(_ZN7ecFrame5ResetEv, 705593)
    off(_ZN7ecFrame9NextFrameEv, 705705)
    off(_ZN7ecFrameD2Ev, 705493)
    off(_ZN7ecFrameD1Ev, 705493)
    off(_ZN7ecFrameD0Ev, 705495)
    off(_ZN7ecFrameC2Ev, 705513)
}

plt(_ZN7_JNIEnv14ExceptionClearEv)

plt(_ZN7_JNIEnv14DeleteLocalRefEP8_jobject)

plt(_ZN7_JNIEnv16CallObjectMethodEP8_jobjectP10_jmethodIDz)

plt(_ZN7_JNIEnv23CallStaticBooleanMethodEP7_jclassP10_jmethodIDz)

plt(_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz)

plt(_ZN7_JNIEnv21CallStaticFloatMethodEP7_jclassP10_jmethodIDz)

plt(_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz)

plt(_ZN7_JNIEnv12NewStringUTFEPKc)

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

plt(_ZN15ecMultipleTouch5ResetEv)

plt(_ZN15ecMultipleTouch10TouchBeganEff)

plt(_Z12ecTouchBeginffi)

plt(_ZN15ecMultipleTouch10TouchEndedEff)

plt(_Z10ecTouchEndffi)

plt(_ZN15ecMultipleTouch10TouchMovedEff)

plt(_Z11ecTouchMoveffi)

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

plt(_ZN10ecGraphics12RenderCircleEfffm)

plt(_ZN10ecGraphics4FadeEf)

plt(_ZN10ecGraphicsD2Ev)

plt(_ZN10ecGraphicsD1Ev)

plt(_ZN10ecGraphics11LoadTextureEPKc)

plt(_Z13ecTextureLoadPKcRiS1_Rj)

plt(_ZN10ecGraphics14LoadPVRTextureEPKc)

plt(_Z16ecPVRTextureLoadPKcRiS1_Rj)

plt(_ZN10ecGraphics14LoadETCTextureEPKc)

plt(_Z16ecETCTextureLoadPKcRiS1_Rj)

plt(_ZN10ecGraphics15LoadWEBPTextureEPKc)

plt(_Z17ecWEBPTextureLoadPKcRiS1_Rj)

plt(_ZN15ecMultipleTouchD2Ev)

plt(_ZN15ecMultipleTouchD1Ev)

plt(_ZN15ecMultipleTouchC2Ev)

plt(_ZN15ecMultipleTouchC1Ev)

plt(_ZN6ecFileC2Ev)

plt(_ZN3MD5C1Ev)

plt(_ZN6ecFile5CloseEv)

plt(_ZN6ecFileD2Ev)

plt(_ZN6ecFile4OpenEPKcS1_)

plt(_ZN6ecFile4ReadEPvm)

plt(_ZN6ecFile5WriteEPKvm)

plt(_ZN6ecFile4SeekEli)

plt(_ZN6ecFile9GetCurPosEv)

plt(_ZN6ecFile7GetSizeEv)

plt(_ZN6ecFile12CheckJavaDexEv)

plt(_ZN6ecFile18GetFileDataFromZipEPKcS1_Pm)

plt(_ZN3MD55resetEv)

plt(_ZN3MD56updateEPKvj)

plt(_ZN3MD58toStringEv)

plt(_ZN8CheckMD5C1Ev)

plt(_ZN8CheckMD56INfileEPKcS1_)

plt(_ZN6ecFile21CheckFileExistFromZipEPKcS1_)

plt(_ZN3MD5C2Ev)

plt(_ZN3MD56encodeEPKmPhj)

plt(_ZN3MD56decodeEPKhPmj)

plt(_ZN3MD59transformEPKh)

plt(_ZN3MD56updateEPKhj)

plt(_ZN3MD5C2EPKvj)

plt(_ZN3MD5C1EPKvj)

plt(_ZN3MD56updateERSt14basic_ifstreamIcSt11char_traitsIcEE)

plt(_ZN3MD5C2ERSt14basic_ifstreamIcSt11char_traitsIcEE)

plt(_ZN3MD5C1ERSt14basic_ifstreamIcSt11char_traitsIcEE)

plt(_ZN3MD56updateERKSs)

plt(_ZN3MD5C2ERKSs)

plt(_ZN3MD5C1ERKSs)

plt(_ZN3MD55finalEv)

plt(_ZN3MD56digestEv)

plt(_ZN3MD516bytesToHexStringEPKhj)

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

Thn(N10CEditState7OnEventERK5Event, 12)

plt(_ZN10CEditStateD2Ev)

plt(_ZN13CTouchInertiaD1Ev)

plt(_ZN10CEditStateD1Ev)

Thn(N10CEditStateD1Ev, 12)

plt(_ZN10CEditStateD0Ev)

Thn(N10CEditStateD0Ev, 12)

plt(_ZN10CEditState6UpdateEf)

plt(_ZN13CTouchInertia6UpdateEf)

plt(_ZN13CTouchInertia8GetSpeedERfS0_)

plt(_ZN6CScene4MoveEii)

plt(_ZN13CTouchInertia4StopEv)

plt(_ZN7CCamera13SetAutoFixPosEb)

plt(_ZN15ecEffectManager8InstanceEv)

plt(_ZN15ecEffectManager6UpdateEf)

plt(_ZN6CScene6UpdateEf)

plt(_ZN10CEditState6RenderEv)

plt(_ZN6CScene6RenderEv)

plt(_ZN6CScene15RenderAreasTypeEv)

plt(_ZN6CScene14RenderAreasTaxEv)

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

plt(_ZN9CActionAI8InstanceEv)

plt(_ZN9CActionAI8getMedalEiP5CArea)

plt(_Z9GetAIRandv)

plt(_Z11GetRandSeedv)

plt(_Z7GetRandv)

plt(_ZN6CFightC2Ev)

plt(_ZN6CFightC1Ev)

plt(_ZN6CFightD2Ev)

plt(_ZN6CFightD1Ev)

plt(_ZN6CFight16AirStrikesAttackEP8CCountryii)

plt(_ZN6CScene7GetAreaEi)

plt(_ZN10CObjectDef10GetArmyDefEiPKc)

plt(_ZN8CCountry16GetWarMedalLevelE11WARMEDAL_ID)

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

plt(_ZN5CArmy6AddExpEi)

plt(_ZN5CArea23ReduceConstructionLevelEv)

plt(_ZN5CArea10OccupyAreaEPS_)

plt(_ZN5CArmy12BreakthroughEv)

plt(_ZN5CArmy6IsNavyEv)

plt(_ZN8CCountry13IsLocalPlayerEv)

plt(_ZN6CScene9GainMedalEff)

plt(_ZN9CSoundRes10PlayCharSEE10SND_EFFECT)

plt(_ZN5CArea19DestroyConstructionEv)

plt(_ZN5CArea12ClearAllArmyEv)

plt(_ZN15ecEffectManager9AddEffectEPKcb)

plt(_ZN8ecEffect6FireAtEfff)

plt(_ZN13CFightTextMgr7AddTextEffPKcm)

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

plt(_ZN10CFightText4InitEffP9ecUniFont)

plt(_ZN6ecText4InitEP9ecUniFont)

plt(_ZN10CFightText7SetTextEPKc)

plt(_ZN6ecText7SetTextEPKc)

plt(_ZN10CFightText8SetColorEm)

plt(_ZN6ecText8SetColorEm)

plt(_ZN10CFightText6UpdateEf)

plt(_ZN6ecText8SetAlphaEf)

plt(_ZN10CFightText6RenderEv)

plt(_ZN6ecText8DrawTextEffi)

plt(_ZN13CFightTextMgr6UpdateEf)

plt(_ZN13CFightTextMgr6RenderEv)

plt(_ZN9TFreeListI10CFightTextED2Ev)

plt(_ZN9TFreeListI10CFightTextED1Ev)

plt(_ZN9TFreeListI10CFightTextE7FreeAllEv)

plt(_ZN13CFightTextMgr4InitEv)

plt(_ZN13CFightTextMgrD2Ev)

plt(_ZN9ecUniFontD1Ev)

plt(_ZN13CFightTextMgrD1Ev)

plt(_ZN13CFightTextMgr7ReleaseEv)

plt(_ZN13CFightTextMgrC2Ev)

plt(_ZN9ecUniFontC1Ev)

plt(_ZN13CFightTextMgrC1Ev)

plt(_ZN13CActionAssistD2Ev)

plt(_ZN13CActionAssistD1Ev)

plt(_ZN12CGameManagerD2Ev)

plt(_ZN12CGameManagerD1Ev)

plt(_ZN13TiXmlDocumentD2Ev)

plt(_ZN9TiXmlNodeD2Ev)

plt(_ZN13TiXmlDocumentD1Ev)

plt(_ZN13TiXmlDocumentD0Ev)

plt(_ZN13CActionAssist8InstanceEv)

plt(_ZN9CActionAI6InitAIEv)

plt(_ZN6CScene11GetNumAreasEv)

plt(_Z13GetNumBattlesi)

plt(_Z16GetBattleKeyNameiiPc)

plt(_Z18GetConquestKeyNameiPc)

plt(_Z17GetBattleFileNameiiiiPc)

plt(_Z24GetNumMultiPlayerBattlesi)

plt(_Z24GetBattleBelligerentListPKcRSt4listI11BelligerentSaIS2_EEb)

plt(_ZN13TiXmlDocumentC1EPKc)

plt(_ZN13TiXmlDocument8LoadFileE13TiXmlEncoding)

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

plt(_ZN8CCountry16GetCommanderNameEv)

plt(_ZN12TiXmlElement18SetDoubleAttributeEPKcd)

plt(_ZN9TiXmlNode12LinkEndChildEPS_)

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

plt(_ZN12CGameManager12RealLoadGameEPKc)

plt(_ZN8CCountryC1Ev)

plt(_ZN8CCountry4InitEPKcS1_)

plt(_ZN8CCountry11LoadCountryEPK15SaveCountryInfo)

plt(_ZN5CArea8LoadAreaEPK12SaveAreaInfo)

plt(_ZN8CCountry7AddAreaEi)

plt(_ZN7CCamera6SetPosEffb)

plt(_ZN12CGameManager10LoadBattleEPKc)

plt(_ZNK12TiXmlElement20QueryDoubleAttributeEPKcPd)

plt(_ZN14CPlayerManager21FindPlayerByCountryIDEPKc)

plt(_ZN8CCountry12SetCommanderEPKc)

plt(_ZN6CScene14SetAreaCountryEiP8CCountry)

plt(_ZN5CArea15SetConstructionEii)

plt(_ZN5CArmyC1Ev)

plt(_ZN5CArmy4InitEP7ArmyDefP8CCountry)

plt(_ZN5CArea7AddArmyEP5CArmyb)

plt(_ZN5CArmy16ResetMaxStrengthEb)

plt(_ZN12CGameManager24MovePlayerCountryToFrontEv)

plt(_ZN12CGameManager10InitBattleEv)

plt(_ZN14CPlayerManager18SetPlayerOfCountryEv)

plt(_ZN6CScene20AllAreasEncirclementEv)

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

Thn(N10CGameStateD1Ev, 12)

plt(_ZN10CGameStateD0Ev)

Thn(N10CGameStateD0Ev, 12)

plt(_ZN10CGameState6RenderEv)

plt(_ZN15ecEffectManager6RenderEv)

plt(_ZN10CGameState8TouchEndEffi)

plt(_ZN10GUIBuyCard10GetSelCardEv)

plt(_ZN8CCountry19CheckCardTargetAreaEP7CardDefi)

plt(_ZN14CPlayerManager22SendPacketToAllPlayersE9PACKET_IDPKvi)

plt(_ZN6GUITax7SetAreaEi)

plt(_ZN5CArea8IsActiveEv)

plt(_ZN6CScene13CheckMoveableEiii)

plt(_ZN10GUIElement4HideEv)

plt(_ZN10GUIElement4ShowEv)

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

plt(_ZN13GUIActionInfoC1Ev)

plt(_ZN13GUIActionInfo4InitERK7GUIRect)

plt(_ZN11GUIDefeatedC1Ev)

plt(_ZN11GUIDefeated4InitERK7GUIRect)

plt(_ZN9GUIBattleC1Ev)

plt(_ZN9GUIBattle4InitERK7GUIRect)

plt(_ZN12GUITutorailsC1Ev)

plt(_ZN12GUITutorails4InitERK7GUIRect)

plt(_ZN11GUIDialogueC1Ev)

plt(_ZN11GUIDialogue4InitERK7GUIRect)

plt(_ZN16GUIMotionManager9AddMotionEP10GUIElementffft)

plt(_ZN10CCSoundBox9LoadMusicEPKcS1_)

plt(_ZN10CCSoundBox9PlayMusicEb)

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

plt(_ZN10GUIBuyCard13CanBuySelCardEv)

plt(_ZN10GUIBuyCard15ResetCardTargetEv)

plt(_ZN10GUIBuyCard13ReleaseTargetEv)

plt(_ZN6CScene9IsBombingEv)

plt(_ZN14CPlayerManager13GetNumActionsEv)

plt(_ZN14CPlayerManager22IsDisconnectedFromHostEv)

plt(_ZN13GUIActionInfo7SetInfoEPKc)

plt(_ZN10CGameState15ResetTouchStateEv)

plt(_ZN10CGameState11BackPressedEv)

plt(_ZN10GUIManager7FadeOutEiP10GUIElement)

plt(_ZN10CGameState10TouchBeginEffi)

plt(_ZN10CGameState7OnEventERK5Event)

plt(_ZN10GUIBuyCard14ResetCardStateEv)

plt(_ZN10GUIOptionsC1Ev)

plt(_ZN10GUIOptions4InitERK7GUIRect)

plt(_ZN7GUISaveC1Ev)

plt(_ZN7GUISave4InitERK7GUIRectib)

plt(_ZN10GUIManager13SafeFreeChildEP10GUIElement)

plt(_ZN6GUIEndC1Ev)

plt(_ZN6GUIEnd4InitERK7GUIRect)

plt(_ZN14GUIBattleIntroC1Ev)

plt(_ZN14GUIBattleIntro4InitERK7GUIRectii)

plt(_ZN16GUIMotionManager12ActiveMotionEmh)

plt(_ZN14CPlayerManager18SendPacketToServerE9PACKET_IDPKvi)

plt(_ZN14CPlayerManager16PlayerLoadFinishEP7CPlayer)

plt(_ZN9GUIResultC1Ev)

plt(_ZN9GUIResult4InitERK7GUIRecti)

plt(_ZN6GUIIapC1Ev)

plt(_ZN6GUIIap4InitERK7GUIRect)

plt(_ZN12GUISmallCard7SetCardEP7CardDef)

plt(_ZN11GUIDefeated12HideDefeatedEv)

plt(_ZN10GUIVictoryC1Ev)

plt(_ZN10GUIVictory4InitERK7GUIRectb)

plt(_ZN10GUIVictory4PlayEv)

plt(_ZN7GUIBankC1Ev)

plt(_ZN7GUIBank4InitERK7GUIRect)

Thn(N10CGameState7OnEventERK5Event, 12)

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

plt(_ZN7ecImageC1EP9ecTextureRK13ecTextureRect)

plt(_ZN11GUICardListC1Ev)

plt(_ZN11GUICardList4InitERK7GUIRecti)

plt(_ZN10GUIBuyCard15SetSelCardIntroEv)

plt(_ZN10CObjectDef10GetCardDefE7CARD_ID)

plt(_ZN8CCountry10CanBuyCardEP7CardDef)

plt(_ZN8CCountry12GetCardPriceEP7CardDef)

plt(_ZN8CCountry15GetCardIndustryEP7CardDef)

plt(_ZN11GUICardList7GetCardEi)

plt(_ZN8CCountry13IsEnoughMoneyEP7CardDef)

plt(_ZN7GUICard13SetPriceColorEm)

plt(_ZN8CCountry16IsEnoughIndustryEP7CardDef)

plt(_ZN7GUICard16SetIndustryColorEm)

plt(_ZN7GUICard8SetPriceEi)

plt(_ZN7GUICard11SetIndustryEi)

plt(_ZN8CCountry15CanUseCommanderEv)

plt(_ZN8CCountry13GetCardRoundsE7CARD_ID)

plt(_ZN10GUIElement9SetEnableEb)

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

plt(_ZN11GUICardList8OnUpdateEf)

plt(_ZN11GUICardListD2Ev)

plt(_ZN11GUICardListD1Ev)

plt(_ZN11GUICardListD0Ev)

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

plt(_ZN15GUIProductPriceD2Ev)

plt(_ZN15GUIProductPriceD1Ev)

plt(_ZN15GUIProductPriceD0Ev)

plt(_ZN15GUIProductPrice8OnRenderEv)

plt(_ZN6GUIIapD2Ev)

plt(_ZN6GUIIapD1Ev)

plt(_ZN6GUIIapD0Ev)

plt(_ZN6GUIIap7OnEventERK5Event)

plt(_ZN6GUIIap8OnRenderEv)

plt(_ZN15GUIProductPriceC2Ev)

plt(_ZN15GUIProductPriceC1Ev)

plt(_ZN15GUIProductPrice4InitERK7GUIRect)

plt(_ZN11ecLabelText8SetColorEm)

plt(_ZN15GUIProductPrice14SetLocalePirceEPKc)

plt(_ZN6GUIIapC2Ev)

plt(_ZN9GUIButton7SetTextEPKc)

plt(_ZN9GUIButton12SetTextColorEm)

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

plt(_ZNK12TiXmlElement19QueryFloatAttributeEPKcPf)

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

plt(_ZN6CScene16MoveCameraToAreaEi)

plt(_ZN6CScene22MoveCameraCenterToAreaEi)

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

Thn(N10CLoadStateD1Ev, 12)

plt(_ZN10CLoadStateD0Ev)

Thn(N10CLoadStateD0Ev, 12)

plt(_ZN10CLoadState7OnEnterEv)

plt(_ZN10CLoadState6OnExitEv)

plt(_ZN10CLoadState6RenderEv)

plt(_ZN10CLoadState6UpdateEf)

plt(_ZN10CLoadState7OnEventERK5Event)

Thn(N10CLoadState7OnEventERK5Event, 12)

plt(_ZN10CLoadStateC2Ev)

plt(_ZN10CLogoStateD2Ev)

plt(_ZN10CLogoStateD1Ev)

Thn(N10CLogoStateD1Ev, 12)

plt(_ZN10CLogoState15EnterForegroundEv)

plt(_ZN10CLogoStateD0Ev)

Thn(N10CLogoStateD0Ev, 12)

plt(_ZN10CLogoState7OnEnterEv)

plt(_ZN10CLogoState6OnExitEv)

plt(_ZN10CLogoState6RenderEv)

plt(_ZN10CLogoState7OnEventERK5Event)

Thn(N10CLogoState7OnEventERK5Event, 12)

plt(_ZN10CLogoState6UpdateEf)

plt(_ZN14CPlayerManager4InitEv)

plt(_ZN10CLogoStateC2Ev)

plt(_ZN11CMatchStateD2Ev)

plt(_ZN11CMatchStateD1Ev)

Thn(N11CMatchStateD1Ev, 12)

plt(_ZN11CMatchState6UpdateEf)

plt(_ZN11CMatchState6RenderEv)

plt(_ZN11CMatchState10TouchBeginEffi)

plt(_ZN11CMatchState9TouchMoveEffi)

plt(_ZN11CMatchState8TouchEndEffi)

plt(_ZN11CMatchStateD0Ev)

Thn(N11CMatchStateD0Ev, 12)

plt(_ZN11CMatchState7OnEnterEv)

plt(_ZN13GUIMatchSetupC1Ev)

plt(_ZN13GUIMatchSetup4InitERK7GUIRect)

plt(_ZN11CMatchState6OnExitEv)

plt(_ZN11CMatchStateC2Ev)

plt(_ZN11CMatchState18StartMultiplayGameEi)

plt(_ZN11CMatchState7OnEventERK5Event)

plt(_ZN14CPlayerManager17SendStartLoadGameEv)

Thn(N11CMatchState7OnEventERK5Event, 12)

plt(_ZN11CMatchState11ShowWarningEi)

plt(_ZN10CMenuStateD2Ev)

plt(_ZN10CMenuStateD1Ev)

Thn(N10CMenuStateD1Ev, 12)

plt(_ZN10CMenuState6UpdateEf)

plt(_ZN10CMenuState6RenderEv)

plt(_ZN10CMenuState10TouchBeginEffi)

plt(_ZN10CMenuState9TouchMoveEffi)

plt(_ZN10CMenuState8TouchEndEffi)

plt(_ZN10CMenuStateD0Ev)

Thn(N10CMenuStateD0Ev, 12)

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

plt(_ZN10GUILoadingC1Ev)

plt(_ZN10GUILoading4InitERK7GUIRect)

plt(_ZN14CPlayerManager14DestroySessionEv)

plt(_ZN14CPlayerManager12SetupSessionEb)

plt(_ZN11GUIMainMenu6ShowADEv)

plt(_ZN12GUICommanderC1Ev)

plt(_ZN12GUICommander4InitERK7GUIRect)

plt(_ZN10GUIElement9FreeChildEPS_)

plt(_ZN13GUISelCountryC1Ev)

plt(_ZN13GUISelCountry4InitERK7GUIRecti)

plt(_ZN11GUIHostList17ResetConnectStateEv)

plt(_ZN11GUIHostListC1Ev)

plt(_ZN11GUIHostList4InitERK7GUIRect)

plt(_ZN14CPlayerManager9InitCorpsEi)

plt(_ZN10GUIServiceC1Ev)

plt(_ZN10GUIService4InitERK7GUIRect)

plt(_ZN11GUIMainMenu13RefreshNewTipEv)

plt(_ZN10GUINewGameC1Ev)

plt(_ZN10GUINewGame4InitERK7GUIRect)

plt(_ZN14CPlayerManager10StartMatchEv)

plt(_ZN14CPlayerManager9StopMatchEv)

plt(_ZN16GUILockedWarningC1Ev)

plt(_ZN16GUILockedWarning4InitERK7GUIRect)

Thn(N10CMenuState7OnEventERK5Event, 12)

plt(_ZN10CMenuState11ShowWarningEi)

plt(_ZN14GUIExitWarningC1Ev)

plt(_ZN14GUIExitWarning4InitERK7GUIRect)

plt(_ZN10CObjectDefC2Ev)

plt(_ZN10CObjectDefC1Ev)

plt(_ZN10CObjectDef11LoadCardDefEv)

plt(_ZN10CObjectDef14ReleaseArmyDefEv)

plt(_ZN10CObjectDef18ReleaseUnitMotionsEv)

plt(_ZN10CObjectDef20ReleaseUnitPositionsEv)

plt(_ZN10CObjectDef19ReleaseCommanderDefEv)

plt(_ZN10CObjectDef20ReleaseGeneralPhotosEv)

plt(_ZN10CObjectDef17ReleaseBattleListEv)

plt(_ZN10CObjectDef19ReleaseConquestListEv)

plt(_ZN10CObjectDef7ReleaseEv)

plt(_ZN10CObjectDefD2Ev)

plt(_ZN10CObjectDefD1Ev)

plt(_ZN10CObjectDef14GetConquestDefEPKc)

plt(_ZN10CObjectDef14GetUnitMotionsEPKcS1_)

plt(_ZN10CObjectDef15GetCommanderDefEPKc)

plt(_ZN10CObjectDef16GetUnitPositionsEPKc)

plt(_ZN10CObjectDef11LoadArmyDefEv)

plt(_ZN10CObjectDef15LoadUnitMotionsEv)

plt(_ZN10CObjectDef16LoadUnitPositonsEv)

plt(_ZN10CObjectDef16LoadCommanderDefEv)

plt(_ZN10CObjectDef17LoadGeneralPhotosEv)

plt(_ZN10CObjectDef14LoadBattleListEv)

plt(_ZN10CObjectDef16LoadConquestListEv)

plt(_ZN14CPlayerManager14WillDisconnectEv)

plt(_ZN14CPlayerManager34onLocalPlayerAuthenticationChangedEv)

Thn(N14CPlayerManager34onLocalPlayerAuthenticationChangedEv, 4)

plt(_ZN14CPlayerManager20onFriendListReceivedEv)

Thn(N14CPlayerManager20onFriendListReceivedEv, 4)

plt(_ZN14CPlayerManager14onMatchRequestEv)

Thn(N14CPlayerManager14onMatchRequestEv, 4)

plt(_ZN14CPlayerManager17onPlayerConnectedEPKc)

Thn(N14CPlayerManager17onPlayerConnectedEPKc, 4)

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

plt(_ZN14CPlayerManager13CancelConnectEv)

plt(_ZN18ecSessionInterface13CancelConnectEv)

plt(_ZN9ecGameKit25ShowMatchmakerWithRequestEiii)

plt(_ZN14CPlayerManager9AddPlayerEbPKc)

plt(_ZN7CPlayerC1Ev)

plt(_ZN7CPlayer4InitEbPKc)

plt(_ZN18ecSessionInterfaceC1Ev)

plt(_ZN18ecSessionInterface4InitEP17ecSessionDelegate)

plt(_ZN18ecSessionInterface12SetupSessionEb)

plt(_ZN18ecSessionInterface13GetDeviceNameERSs)

plt(_ZN14CPlayerManager10FindPlayerEPKc)

plt(_ZN14CPlayerManager20onPlayerInfoReceivedERSt4listIP12ecPlayerInfoSaIS2_EE)

Thn(N14CPlayerManager20onPlayerInfoReceivedERSt4listIP12ecPlayerInfoSaIS2_EE, 4)

plt(_ZN14CPlayerManager16FindPlayerByUUIDEi)

plt(_ZN14CPlayerManager17DidRecvInvitationEPKc)

plt(_ZN18ecSessionInterface11GetPeerNameEPKcRSs)

plt(_ZN18ecSessionInterface16AcceptInvitationEPKc)

plt(_ZN18ecSessionInterface17DeclineInvitationEPKc)

plt(_ZN14CPlayerManager21GetDisconnectedPlayerEv)

plt(_ZN14CPlayerManager18SendPacketToPlayerE12PacketHeaderPKviPKc)

plt(_ZN18ecSessionInterface10SendPacketEPKviPKc)

plt(_ZN9ecGameKit10SendPacketEPKviPKc)

plt(_ZN14CPlayerManager18SendPacketToPlayerE9PACKET_IDPKviP7CPlayer)

plt(_ZN14CPlayerManager28SendPacketToAllPlayersExceptE9PACKET_IDPKviP7CPlayer)

plt(_ZN7CPlayer10SendPacketE9PACKET_IDPKvi)

plt(_ZN7CPlayer10PushPacketE9PACKET_IDPKvi)

plt(_ZN14CPlayerManager10ClearCorpsEv)

plt(_ZN14CPlayerManager12GetLeftCorpsEi)

plt(_ZN14CPlayerManager13GetRightCorpsEi)

plt(_ZN14CPlayerManager15GetNumLeftCorpsEv)

plt(_ZN14CPlayerManager16GetNumRightCorpsEv)

plt(_ZN14CPlayerManager8SelCorpsEiiP7CPlayer)

plt(_ZN14CPlayerManager17RemoveCorpsPlayerEii)

plt(_ZN14CPlayerManager17RemoveCorpsPlayerEP7CPlayer)

plt(_ZN14CPlayerManager12RemovePlayerEP7CPlayer)

plt(_ZN7CPlayerD1Ev)

plt(_ZN14CPlayerManager20onPlayerDisconnectedEPKc)

Thn(N14CPlayerManager20onPlayerDisconnectedEPKc, 4)

plt(_ZN14CPlayerManager12GetCorpsDataERi)

plt(_ZN14CPlayerManager15onPeerConnectedEPKc)

plt(_ZN13GUIMatchSetup18RefreshCorsButtonsEv)

plt(_ZN14CPlayerManager14SetCorpsByDataEPviP7CPlayer)

plt(_ZN14CPlayerManager17IsAllPlayersReadyEv)

plt(_ZN14CPlayerManager23RefreshAndSendCorpsDataEv)

plt(_ZN14CPlayerManager18onPeerDisconnectedEPKc)

plt(_ZN14CPlayerManager14SendRoundBeginEv)

plt(_ZN14CPlayerManager18ClearRemotePlayersEv)

plt(_ZN14CPlayerManager12ClearPlayersEv)

plt(_ZN18ecSessionInterfaceD1Ev)

plt(_ZN9ecGameKitD1Ev)

plt(_ZN9ecGameKit22DisconnectCurrentMatchEv)

plt(_ZN14CPlayerManager16onAcceptedInviteEv)

Thn(N14CPlayerManager16onAcceptedInviteEv, 4)

plt(_ZN14CPlayerManager13WillTerminateEv)

plt(_ZN11GUIHostList13ClearHostListEv)

plt(_ZN14CPlayerManagerD2Ev)

plt(_ZN14CPlayerManagerD1Ev)

plt(_ZN14CPlayerManager19onPeerListDidChangeEv)

plt(_ZN18ecSessionInterface15GetPeerNameListERSt4listISsSaISsEES3_)

plt(_ZN11GUIHostList15RefreshHostListEv)

plt(_ZN14CPlayerManager9ReconnectEv)

plt(_ZN7CPlayer9SendFirstEv)

plt(_ZN14CPlayerManager12onMatchFoundEv)

plt(_ZN9ecGameKit18GetMatchPlayerListERSt4listISsSaISsEE)

Thn(N14CPlayerManager12onMatchFoundEv, 4)

plt(_ZN14CPlayerManager12onStartMatchEv)

plt(_ZN9ecGameKit18GetLocalPlayerInfoER12ecPlayerInfo)

plt(_ZN9ecGameKit19GetMatchPlayersInfoEv)

Thn(N14CPlayerManager12onStartMatchEv, 4)

plt(_ZN14CPlayerManager16ClearActionQueueEv)

plt(_ZN14CPlayerManager14onReceivedDataEPKviPKcb)

plt(_ZN7CPlayer7RecvAckEi)

plt(_ZN7CPlayer7SendAckEi)

plt(_ZN13GUIMatchSetup16CreatCorsButtonsEv)

plt(_ZN14CPlayerManager22onReveivedDataFromPeerEPKviPKc)

plt(_ZN14CPlayerManager24onReceivedDataFromPlayerEPKviPKc)

Thn(N14CPlayerManager24onReceivedDataFromPlayerEPKviPKc, 4)

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

plt(_ZN6CMedal5UpateEf)

plt(_ZN5CArea6UpdateEf)

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

plt(_ZN8CCountry15AirstrikeRadiusEv)

plt(_ZN7ecImage9Render4VCEffffffffif)

plt(_ZN6CMedal6RenderEv)

plt(_ZN7CBomber6RenderEv)

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

plt(_ZN13CActionAssist21purChaseAirStrikeCardEv)

plt(_ZN13CActionAssist17purChaseDraftCardEb)

plt(_ZN13CActionAssist16purChaseFortCardEv)

plt(_ZN13CActionAssist17purChaseCardsCardEv)

plt(_ZN13CActionAssist21purChaseConstructCardEv)

plt(_ZN9CActionAI15sortArmyToFrontEv)

plt(_ZN5CArea12IsArmyActiveEi)

plt(_ZN9CActionAI8getMaxIdEv)

plt(_ZN9CActionAI13setArmyActionEP5CArea)

plt(_ZN13CActionAssist16actionToNextAreaEiiii)

plt(_ZN9CActionAI13moveAndAttackEv)

plt(_ZN13CActionAssist13calcAreaValueEP5CArea)

plt(_ZN13CActionAssist15aiCheckMoveableEiiii)

plt(_Z13GetAIRandSeedv)

plt(_ZN13CActionAssist9isBuyCardEP7CardDef)

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

plt(_ZN8CCountryD2Ev)

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

plt(_ZN17GUICommanderMedal13SetArrowColorEm)

plt(_ZN11GUIWarMedalC2Ev)

plt(_ZN11GUIWarMedalC1Ev)

plt(_ZN11GUIWarMedal8SetLevelEi)

plt(_ZN11GUIWarMedal4InitERK7GUIRect11WARMEDAL_IDi)

plt(_ZN11GUIWarMedal13SetArrowColorEm)

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

plt(_ZN11GUIHostItemD2Ev)

plt(_ZN11GUIHostItemD1Ev)

plt(_ZN11GUIHostItemD0Ev)

plt(_ZN11GUIHostList8OnRenderEv)

plt(_ZN19GUIConnectHostState8OnRenderEv)

plt(_ZN11GUIHostListD2Ev)

plt(_ZN11GUIHostListD1Ev)

plt(_ZN11GUIHostListD0Ev)

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

plt(_ZN13GUIBattleListC1Ev)

plt(_ZN13GUIBattleList4InitERK7GUIRecti)

plt(_ZN13GUIBattleList18SelectLastUnlockedEv)

plt(_ZN13GUIBattleList9SetSelectEi)

plt(_ZN12GUISelBattle13LoadImageListEii)

plt(_ZN12GUISelBattleC2Ev)

plt(_ZN12GUISelBattle16ReleaseImageListEv)

plt(_ZN12GUISelBattleD2Ev)

plt(_ZN12GUISelBattleD1Ev)

plt(_ZN12GUISelBattleD0Ev)

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

plt(_ZN13GUIBattleList8OnUpdateEf)

plt(_ZN13GUIBattleListD2Ev)

plt(_ZN13GUIBattleListD1Ev)

plt(_ZN13GUIBattleListD0Ev)

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

plt(_ZN14GUICountryList8OnUpdateEf)

plt(_ZN14GUICountryListD2Ev)

plt(_ZN14GUICountryListD1Ev)

plt(_ZN14GUICountryListD0Ev)

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

plt(_ZN10GUIElement12FindByHandleEm)

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

plt(_ZN16GUIMotionManager9SetMotionEmffffft)

plt(_ZN16GUIMotionManager9AddMotionEP10GUIElementffffft)

plt(_ZN16GUIMotionManager10AddMotionXEP10GUIElementfft)

plt(_ZN16GUIMotionManager10AddMotionYEP10GUIElementfft)

plt(_ZN16GUIMotionManager8SetSpeedEmff)

plt(_ZN16GUIMotionManager15GetMotionActiveEm)

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

plt(_ZN7GUIText12SetTextColorEm)

plt(_ZN9ecGameKitC2Ev)

plt(_ZN9ecGameKitD2Ev)

plt(_ZN9ecGameKit7ReleaseEv)

plt(_ZN9ecGameKit22SendPacketToAllPlayersEPKvi)

plt(_ZN18ecSessionInterfaceC2Ev)

plt(_ZN18ecSessionInterfaceD2Ev)

plt(_ZN18ecSessionInterface7ReleaseEv)

plt(_ZN18ecSessionInterface10DisconnectEPKc)

plt(_ZN18ecSessionInterface20SendPacketToAllPeersEPKvi)

plt(_ZN11TiXmlString4quitEv)

plt(_ZN11TiXmlString7reserveEj)

plt(_ZN11TiXmlString6assignEPKcj)

plt(_ZN11TiXmlString6appendEPKcj)

plt(_ZN11TiXmlStringpLERKS_)

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

plt(_ZNK12TiXmlUnknown5PrintEP7__sFILEi)

plt(_ZNK16TiXmlDeclaration5PrintEP7__sFILEi)

plt(_ZNK12TiXmlComment5PrintEP7__sFILEi)

plt(_ZN11TiXmlStringC2EPKc)

plt(_ZN11TiXmlStringC1EPKc)

plt(_ZN11TiXmlStringaSEPKc)

plt(_ZN11TiXmlStringpLEPKc)

plt(_ZNK12TiXmlComment9StreamOutEP14TiXmlOutStream)

plt(_ZNK12TiXmlUnknown9StreamOutEP14TiXmlOutStream)

plt(_ZNK11TiXmlString4findEc)

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

plt(_ZN16TiXmlDeclarationD0Ev)

plt(_ZN9TiXmlTextD2Ev)

plt(_ZN9TiXmlTextD1Ev)

plt(_ZN9TiXmlTextD0Ev)

plt(_ZN12TiXmlCommentD2Ev)

plt(_ZN12TiXmlCommentD1Ev)

plt(_ZN12TiXmlCommentD0Ev)

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

plt(_ZN11TiXmlStringpLEc)

plt(_ZN14TiXmlAttributeD2Ev)

plt(_ZN14TiXmlAttributeD1Ev)

plt(_ZN14TiXmlAttributeD0Ev)

plt(_ZN9TiXmlBase12IsWhiteSpaceEc)

plt(_ZN9TiXmlBase18ConvertUTF32ToUTF8EmPcPi)

plt(_ZN9TiXmlBase7IsAlphaEh13TiXmlEncoding)

plt(_ZN9TiXmlBase10IsAlphaNumEh13TiXmlEncoding)

plt(_ZN16TiXmlParsingData5StampEPKc13TiXmlEncoding)

plt(_ZN9TiXmlBase14SkipWhiteSpaceEPKc13TiXmlEncoding)

plt(_ZN9TiXmlBase8ReadNameEPKcP11TiXmlString13TiXmlEncoding)

plt(_ZN9TiXmlBase9GetEntityEPKcPcPi13TiXmlEncoding)

plt(_ZN9TiXmlBase7GetCharEPKcPcPi13TiXmlEncoding)

plt(_ZN9TiXmlBase11StringEqualEPKcS1_b13TiXmlEncoding)

plt(_ZN9TiXmlBase8ReadTextEPKcP11TiXmlStringbS1_b13TiXmlEncoding)

plt(_ZN14TiXmlAttribute5ParseEPKcP16TiXmlParsingData13TiXmlEncoding)

plt(_ZN9TiXmlNode8IdentifyEPKc13TiXmlEncoding)

plt(_ZN13TiXmlDocument5ParseEPKcP16TiXmlParsingData13TiXmlEncoding)

plt(_ZNK9TiXmlText5BlankEv)

plt(_ZN12TiXmlElement9ReadValueEPKcP16TiXmlParsingData13TiXmlEncoding)

plt(_ZN9hgeVector9NormalizeEv)

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

plt(_ZN12ecTextureRes11CreateImageEPKcS1_ffffff)

plt(_ZN12ecTextureRes11CreateImageEPKcP9ecTextureffffff)

plt(_ZN11ecEffectResC2Ev)

plt(_ZN11ecEffectResC1Ev)

plt(_ZN11ecEffectRes7ReleaseEv)

plt(_ZN11ecEffectResD2Ev)

plt(_ZN11ecEffectResD1Ev)

plt(_ZN11ecEffectRes10LoadEffectEPKcP12ecTextureRes)

plt(_ZN18ecEffectResManager16ReleaseEffectResEP11ecEffectRes)

plt(_ZN18ecEffectResManagerD2Ev)

plt(_ZN18ecEffectResManagerD1Ev)

plt(_ZN18ecEffectResManagerC2Ev)

plt(_ZN18ecEffectResManagerC1Ev)

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

plt(_ZN9TFreeListI16ecParticleSystemED2Ev)

plt(_ZN16ecParticleSystemD1Ev)

plt(_ZN9TFreeListI16ecParticleSystemED1Ev)

plt(_ZN15ecEffectManagerD2Ev)

plt(_ZN15ecEffectManagerD1Ev)

plt(_ZN15ecEffectManagerC2Ev)

plt(_ZN16ecParticleSystemC1Ev)

plt(_ZN15ecEffectManagerC1Ev)

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

plt(_Z10ColorClampRf)

plt(_ZN16ecParticleSystemC2Ev)

plt(_ZN16ecParticleSystemD2Ev)

plt(_ZN9ecLibraryC2Ev)

plt(_ZN9ecLibrary11GetItemDataEi)

plt(_ZN9ecLibrary14GetElementDataEi)

plt(_ZN9ecLibrary12GetFrameDataEi)

plt(_ZN9ecLibrary12GetLayerDataEi)

plt(_ZN9ecLibrary11GetItemNameEm)

plt(_ZN9ecLibraryD2Ev)

plt(_ZN7ecShapeD1Ev)

plt(_ZN9ecLibraryD1Ev)

plt(_ZN9ecLibraryD0Ev)

plt(_ZN9ecLibrary12FindItemDataEPKc)

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

plt(_ZN7ecShape8SetColorEm)

plt(_ZN7ecLayer6RenderERK7ecMtx32)

plt(_ZN7ecShape6RenderERK7ecMtx32)

plt(_ZN9ecElement9NextFrameEv)

plt(_ZN7ecLayer9NextFrameEv)

plt(_Z10ecMtx32MulRfS_RK7ecMtx32)

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

plt(_ZN7ecFrame5ResetEv)

plt(_ZN7ecFrame9NextFrameEv)

plt(_ZN7ecFrameD2Ev)

plt(_ZN7ecFrameD1Ev)

plt(_ZN7ecFrameD0Ev)

plt(_ZN7ecFrameC2Ev)
