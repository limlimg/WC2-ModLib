#include <stddef.h>
#include <dlfcn.h>
#include "easytech.h"

#define got(name) __attribute__((visibility("hidden"))) size_t easytech(name) = (size_t)lazybind;
#define bss(name, size) __attribute__((weak)) __attribute__((visibility("protected"))) char name[size];

#define plt(name) __attribute__((weak)) __attribute__((visibility("protected"))) void name() {asm(\
        "call .+5\n\t"\
        "pop %eax\n\t"\
        "lea 8(%eax), %eax\n\t"\
        "addl (%eax), %eax\n\t"\
        "jmp *(%eax)\n\t"\
        ".long "__easytech(name)" - .");}

#define Thn(name, offset) __attribute__((weak)) __attribute__((visibility("protected"))) void _ZThn##offset##_##name() {asm(\
        "sub $"#offset", 4(%esp)\n\t"\
        "jmp _Z"#name"\n\t");}

#define off(name, offset) easytech(name) = BaseAddress + offset;

static const char GameLib[] = "libeasytech.so";

void __attribute__((visibility("hidden"))) lazybind() {
    asm(
    "push %eax\n\t"
    "call resolvesymbol\n\t"
    "pop %eax\n\t"
    "jmp *(%eax)\n\t");
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

got(_ZN10ecGraphics12RenderCircleEfffm)

got(_ZN10ecGraphics4FadeEf)

got(_ZN10ecGraphicsD2Ev)

got(_ZN10ecGraphicsD1Ev)

got(_ZN10ecGraphics11LoadTextureEPKc)

got(_Z13ecTextureLoadPKcRiS1_Rj)

got(_ZN10ecGraphics15LoadWEBPTextureEPKc)

got(_Z17ecWEBPTextureLoadPKcRiS1_Rj)

got(_ZN10ecGraphics14LoadETCTextureEPKc)

got(_Z16ecETCTextureLoadPKcRiS1_Rj)

got(_ZN10ecGraphics14LoadPVRTextureEPKc)

got(_Z16ecPVRTextureLoadPKcRiS1_Rj)

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
bss(g_PlayerManager, 144)

got(_ZN14CPlayerManager7ReleaseEv)
bss(g_Font1, 40)

got(_ZN9ecUniFont7ReleaseEv)
bss(g_Font2, 40)
bss(g_Font3, 40)
bss(g_Font6, 40)
bss(g_Font7, 40)
bss(g_Num1, 40)
bss(g_Num3, 40)
bss(g_Num4, 40)
bss(g_Num5, 40)
bss(g_Num8, 40)

got(_ZN10CCSoundBox8UnloadSEEPKc)

got(_ZN13CStateManager4TermEv)

got(_ZN10GUIManager8InstanceEv)

got(_ZN10GUIElement12FreeAllChildEv)

got(_ZN10GUIManager16ReleaseTexureResEv)

got(_ZN10CCSoundBox7DestroyEv)

got(_ZN10CObjectDef8InstanceEv)

got(_ZN10CObjectDef7DestroyEv)
bss(g_StringTable, 24)

got(_ZN13ecStringTable5ClearEv)
bss(g_LocalizableStrings, 24)
bss(g_Num4b, 40)

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
bss(g_Scene, 232)

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
bss(g_GameManager, 212)

got(_ZN12CGameManager7NewGameEiiii)
bss(g_SoundRes, 92)

got(_ZN9CSoundRes4LoadEv)
bss(g_GameRes, 712)

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
bss(g_FightTextMgr, 64)

got(_ZN13CFightTextMgr7AddTextEffPKcm)

got(_ZN9CSoundRes10PlayCharSEE10SND_EFFECT)

got(_ZN5CArmy6AddExpEi)
bss(_ZN9CActionAI9_instanceE, 4)

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

got(_ZN10CFightText8SetColorEm)

got(_ZN6ecText8SetColorEm)

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
bss(_ZN11TiXmlString8nullrep_E, 12)

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
bss(_ZN13CActionAssist9_instanceE, 4)

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

got(_ZN16GUIMotionManager12ActiveMotionEmh)

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

got(_ZN11GUICardListC1Ev)

got(_ZN11GUICardList4InitERK7GUIRecti)

got(_ZN7ecImageC1EP9ecTextureRK13ecTextureRect)

got(_ZN10GUIBuyCard15SetSelCardIntroEv)

got(_ZN10CObjectDef10GetCardDefE7CARD_ID)

got(_ZN8CCountry10CanBuyCardEP7CardDef)

got(_ZN7GUICard13SetPriceColorEm)

got(_ZN8CCountry16IsEnoughIndustryEP7CardDef)

got(_ZN7GUICard16SetIndustryColorEm)

got(_ZN8CCountry12GetCardPriceEP7CardDef)

got(_ZN8CCountry15GetCardIndustryEP7CardDef)

got(_ZN11GUICardList7GetCardEi)

got(_ZN8CCountry13IsEnoughMoneyEP7CardDef)

got(_ZN10GUIElement9SetEnableEb)

got(_ZN8CCountry13GetCardRoundsE7CARD_ID)

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

got(_ZN10GUIServiceC1Ev)

got(_ZN10GUIService4InitERK7GUIRect)

got(_ZN12GUICommanderC1Ev)

got(_ZN12GUICommander4InitERK7GUIRect)

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
bss(_ZN10CObjectDef10m_InstanceE, 4)

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

got(_ZN7CPlayer9SendFirstEv)

got(_ZN14CPlayerManager14onReceivedDataEPKviPKcb)

got(_ZN7CPlayer7SendAckEi)

got(_ZN7CPlayer7RecvAckEi)

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

got(_ZN11TiXmlString7reserveEj)

got(_ZN11TiXmlString6assignEPKcj)

got(_ZN11TiXmlString6appendEPKcj)

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

got(_ZN16ecParticleSystemC2Ev)

got(_ZN16ecParticleSystemD2Ev)

got(_ZN9ecLibraryC2Ev)

got(_ZN9ecLibrary11GetItemDataEi)

got(_ZN9ecLibrary12FindItemDataEPKc)

got(_ZN9ecLibrary14GetElementDataEi)

got(_ZN9ecLibrary12GetFrameDataEi)

got(_ZN9ecLibrary12GetLayerDataEi)

got(_ZN9ecLibrary11GetItemNameEm)

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

got(_ZN7ecShape8SetColorEm)

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
    size_t BaseAddress = (size_t) dlsym(dlopen(GameLib, RTLD_NOLOAD), "SetLangDir") - 236528;
    off(_ZN7_JNIEnv16CallObjectMethodEP8_jobjectP10_jmethodIDz, 236976)
    off(_ZN7_JNIEnv23CallStaticBooleanMethodEP7_jclassP10_jmethodIDz, 237024)
    off(_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz, 237072)
    off(_ZN7_JNIEnv21CallStaticFloatMethodEP7_jclassP10_jmethodIDz, 237120)
    off(_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz, 237168)
    off(_Z24ecGameDidEnterBackgroundv, 306352)
    off(_Z14ecGameShutdownv, 305904)
    off(_Z7GetPathPKcS0_, 245152)
    off(_Z18ecPurchasedProducti, 307936)
    off(_Z10ecGameInitiiiii, 308768)
    off(_Z18ecSetInAppPurchasePFviE, 308000)
    off(_Z11ecGamePausev, 306256)
    off(_Z25ecGameWillEnterForegroundv, 306416)
    off(_Z12ecGameResumev, 306288)
    off(_Z13ecBackPressedv, 307472)
    off(_ZN13CStateManager8InstanceEv, 559872)
    off(_ZN13CStateManager11GetStatePtrE6EState, 560640)
    off(_ZN10CMenuState8ShowExitEv, 485792)
    off(_Z12ecGameUpdatef, 306528)
    off(_Z12ecGameRenderv, 306688)
    off(_ZN10ecGraphics8InstanceEv, 245744)
    off(_ZN15ecMultipleTouch8InstanceEv, 256752)
    off(_ZN15ecMultipleTouch10TouchBeganEff, 256864)
    off(_Z12ecTouchBeginffi, 306848)
    off(_ZN15ecMultipleTouch5ResetEv, 256800)
    off(_ZN15ecMultipleTouch10TouchMovedEff, 256992)
    off(_Z11ecTouchMoveffi, 307056)
    off(_ZN15ecMultipleTouch10TouchEndedEff, 257120)
    off(_Z10ecTouchEndffi, 307264)
    off(_ZN10CCommander8BuyMedalEi, 305072)
    off(_ZN10CCommander4SaveEv, 304256)
    off(_Z17ecSetProductPriceiPKc, 307856)
    off(_ZN6ecFileC1Ev, 257296)
    off(_ZN6ecFile11IsFlieExistEPKc, 257680)
    off(_ZN6ecFileD1Ev, 257488)
    off(_Z9Get2XPathPKcS0_, 245360)
    off(_Z15GetDocumentPathPKc, 245520)
    off(_Z16GetEditorResPathPKc, 245600)
    off(_ZN10ecGraphicsC2Ev, 245632)
    off(_ZN10ecGraphicsC1Ev, 245632)
    off(_ZN10ecGraphics4InitEiiiii, 245776)
    off(_ZN10ecGraphics8ShutdownEv, 246384)
    off(_ZN10ecGraphics14SetOrientationEi, 246400)
    off(_ZN10ecGraphics11RenderBeginEv, 246448)
    off(_ZN10ecGraphics13CreateTextureEii, 246512)
    off(_ZN10ecGraphics11FreeTextureEP9ecTexture, 246528)
    off(_ZN10ecGraphics5FlushEv, 246944)
    off(_ZN10ecGraphics9RenderEndEv, 247184)
    off(_ZN10ecGraphics12SetViewPointEfff, 247232)
    off(_ZN10ecGraphics12SetBlendModeEi, 247600)
    off(_ZN10ecGraphics11BindTextureEP9ecTexture, 247728)
    off(_ZN10ecGraphics23CreateTextureWithStringEPKcS1_iiii, 247856)
    off(_Z19ecTextureWithStringPKcS0_iiRiS1_Rj, 295456)
    off(_ZN10ecGraphics10RenderLineEPK6ecLine, 248048)
    off(_ZN10ecGraphics12RenderTripleEPK8ecTriple, 248208)
    off(_ZN10ecGraphics10RenderQuadEPK6ecQuad, 248416)
    off(_ZN10ecGraphics10RenderRectEffffm, 248752)
    off(_ZN10ecGraphics12RenderCircleEfffm, 249184)
    off(_ZN10ecGraphics4FadeEf, 249648)
    off(_ZN10ecGraphicsD2Ev, 250208)
    off(_ZN10ecGraphicsD1Ev, 250208)
    off(_ZN10ecGraphics11LoadTextureEPKc, 251008)
    off(_Z13ecTextureLoadPKcRiS1_Rj, 287296)
    off(_ZN10ecGraphics15LoadWEBPTextureEPKc, 252416)
    off(_Z17ecWEBPTextureLoadPKcRiS1_Rj, 294304)
    off(_ZN10ecGraphics14LoadETCTextureEPKc, 253824)
    off(_Z16ecETCTextureLoadPKcRiS1_Rj, 293328)
    off(_ZN10ecGraphics14LoadPVRTextureEPKc, 255232)
    off(_Z16ecPVRTextureLoadPKcRiS1_Rj, 292480)
    off(_ZN15ecMultipleTouchD2Ev, 256672)
    off(_ZN15ecMultipleTouchD1Ev, 256672)
    off(_ZN15ecMultipleTouchC2Ev, 256736)
    off(_ZN15ecMultipleTouchC1Ev, 256736)
    off(_ZN6ecFileC2Ev, 257296)
    off(_ZN3MD5C1Ev, 260000)
    off(_ZN6ecFile5CloseEv, 257392)
    off(_ZN6ecFileD2Ev, 257488)
    off(_ZN6ecFile4OpenEPKcS1_, 257536)
    off(_ZN6ecFile4ReadEPvm, 257840)
    off(_ZN6ecFile5WriteEPKvm, 257984)
    off(_ZN6ecFile4SeekEli, 258080)
    off(_ZN6ecFile9GetCurPosEv, 258208)
    off(_ZN6ecFile7GetSizeEv, 258320)
    off(_ZN6ecFile12CheckJavaDexEv, 258480)
    off(_ZN6ecFile18GetFileDataFromZipEPKcS1_Pm, 258496)
    off(_ZN3MD55resetEv, 259936)
    off(_ZN3MD56updateEPKvj, 262768)
    off(_ZN3MD58toStringEv, 263936)
    off(_ZN8CheckMD5C1Ev, 264016)
    off(_ZN8CheckMD56INfileEPKcS1_, 264032)
    off(_ZN6ecFile21CheckFileExistFromZipEPKcS1_, 259648)
    off(_ZN3MD5C2Ev, 260000)
    off(_ZN3MD56encodeEPKmPhj, 260064)
    off(_ZN3MD56decodeEPKhPmj, 260160)
    off(_ZN3MD59transformEPKh, 260256)
    off(_ZN3MD56updateEPKhj, 262240)
    off(_ZN3MD5C2EPKvj, 262832)
    off(_ZN3MD5C1EPKvj, 262832)
    off(_ZN3MD56updateERSt14basic_ifstreamIcSt11char_traitsIcEE, 262896)
    off(_ZN3MD5C2ERSt14basic_ifstreamIcSt11char_traitsIcEE, 263104)
    off(_ZN3MD5C1ERSt14basic_ifstreamIcSt11char_traitsIcEE, 263104)
    off(_ZN3MD56updateERKSs, 263168)
    off(_ZN3MD5C2ERKSs, 263232)
    off(_ZN3MD5C1ERKSs, 263232)
    off(_ZN3MD55finalEv, 263296)
    off(_ZN3MD56digestEv, 263584)
    off(_ZN3MD516bytesToHexStringEPKhj, 263648)
    off(_ZN8CheckMD5C2Ev, 264016)
    off(_ZN10CCommanderD2Ev, 303296)
    off(_ZN10CCommanderD1Ev, 303296)
    off(_Z19GetCommanderAbilityi, 303312)
    off(_ZN10CCommanderC2Ev, 303360)
    off(_ZN10CCommanderC1Ev, 303360)
    off(_ZN10CCommander4LoadEv, 303616)
    off(_ZN10CCommander15GetUpgradeMedalEv, 304880)
    off(_ZN10CCommander12CheckUpgardeEv, 304928)
    off(_ZN10CCommander7UpgradeEv, 304992)
    off(_ZN10CCommander10IsMaxLevelEv, 305056)
    off(_ZN10CCSoundBox11GetInstanceEv, 934144)
    off(_ZN10CCSoundBox6PlaySEEPKc, 934768)
    off(_ZN10CCommander16GetWarMedalLevelE11WARMEDAL_ID, 305136)
    off(_ZN10CCommander19GetNeedUpgradeMedalE11WARMEDAL_ID, 305152)
    off(_ZN10CCommander20CheckUpgradeWarMedalE11WARMEDAL_ID, 305184)
    off(_ZN10CCommander15UpgradeWarMedalE11WARMEDAL_ID, 305248)
    off(_ZN10CCommander20SetNumPlayedBatttlesEii, 305328)
    off(_ZN10CCommander20GetNumPlayedBatttlesEi, 305360)
    off(_ZN10CCommander15SetBattlePlayedEii, 305376)
    off(_ZN10CCommander17GetNumBattleStarsEii, 305456)
    off(_ZN10CCommander17SetNumBattleStarsEiii, 305504)
    off(_ZN10CCommander16GetCommanderDataER13CommanderData, 305552)
    off(_ZN14CPlayerManager7ReleaseEv, 522736)
    off(_ZN9ecUniFont7ReleaseEv, 930368)
    off(_ZN10CCSoundBox8UnloadSEEPKc, 934720)
    off(_ZN13CStateManager4TermEv, 559968)
    off(_ZN10GUIManager8InstanceEv, 735584)
    off(_ZN10GUIElement12FreeAllChildEv, 732224)
    off(_ZN10GUIManager16ReleaseTexureResEv, 735760)
    off(_ZN10CCSoundBox7DestroyEv, 934288)
    off(_ZN10CObjectDef8InstanceEv, 486496)
    off(_ZN10CObjectDef7DestroyEv, 496672)
    off(_ZN13ecStringTable5ClearEv, 935616)
    off(_Z13ecGameWaitingb, 306320)
    off(_ZN13CStateManager15EnterBackgroundEv, 560528)
    off(_ZN10CCSoundBox14SetMusicVolumeEi, 934544)
    off(_ZN10CCSoundBox11SetSEVolumeEi, 934608)
    off(_ZN10CCSoundBox11ResumeMusicEv, 934512)
    off(_ZN13CStateManager15EnterForegroundEv, 560560)
    off(_ZN14CPlayerManager6UpdateEf, 534704)
    off(_ZN13CStateManager6UpdateEf, 560064)
    off(_ZN10GUIManager6UpdateEf, 736096)
    off(_ZN16GUIMotionManager8InstanceEv, 737712)
    off(_ZN16GUIMotionManager10ProcMotionEv, 739504)
    off(_ZN10CCSoundBox11UpdateSoundEv, 934848)
    off(_ZN13CStateManager6RenderEv, 560160)
    off(_ZN10GUIManager6RenderEv, 735968)
    off(_ZN10GUIManager9PostEventERK5Event, 735904)
    off(_ZN13CStateManager10TouchBeginEffi, 560192)
    off(_ZN13CStateManager9TouchMoveEffi, 560256)
    off(_ZN13CStateManager8TouchEndEffi, 560320)
    off(_ZN13CStateManager11BackPressedEv, 560384)
    off(_Z15ecAccelerometerfff, 307584)
    off(_Z13ecScrollWheelfff, 307600)
    off(_ZN13CStateManager11ScrollWheelEfff, 560464)
    off(_Z9ecKeyDowni, 307680)
    off(_ZN13CStateManager7KeyDownEi, 560416)
    off(_Z18ecSetShowReviewFucPFvvE, 307728)
    off(_Z12ecShowReviewv, 307760)
    off(_Z17ecGetProductPricei, 307808)
    off(_Z15ecInAppPurchasei, 308032)
    off(_Z18ecAppWillTerminatev, 308096)
    off(_Z22ecApplicationTerminatev, 308128)
    off(_Z14ecLoadSettingsv, 308160)
    off(_ZN13CGameSettings12LoadSettingsEv, 369376)
    off(_Z14ecIsFullScreenv, 308208)
    off(_Z15ecSetFullScreenb, 308240)
    off(_ZN13CGameSettings12SaveSettingsEv, 369744)
    off(_Z13SetAIRandSeedi, 569248)
    off(_Z11SetRandSeedi, 314256)
    off(_ZN10GUIManager4InitERK7GUIRect, 735616)
    off(_ZN13CStateManager4InitEv, 559904)
    off(_ZN10CLogoStateC1Ev, 477776)
    off(_ZN10CMenuStateC1Ev, 480032)
    off(_ZN11CMatchStateC1Ev, 478368)
    off(_ZN10CLoadStateC1Ev, 475856)
    off(_ZN10CGameStateC1Ev, 372832)
    off(_ZN10CEditStateC1Ev, 313184)
    off(_ZN13CStateManager13RegisterStateEP10CBaseState, 560592)
    off(_ZN13CStateManager11SetCurStateE6EState, 560608)
    off(_ZN13ecStringTable4LoadEPKc, 937248)
    off(_ZN13ecStringTable9GetStringEPKc, 934912)
    off(_ZN10CObjectDef4InitEv, 517472)
    off(_ZN10CCSoundBox6LoadSEEPKc, 934672)
    off(_ZN9ecUniFont4InitEPKcb, 930912)
    off(_ZN10CBaseState7OnEnterEv, 311856)
    off(_ZN10CBaseState6OnExitEv, 311872)
    off(_ZN10CBaseState10TouchBeginEffi, 311888)
    off(_ZN10CBaseState9TouchMoveEffi, 311904)
    off(_ZN10CBaseState8TouchEndEffi, 311920)
    off(_ZN10CBaseState11BackPressedEv, 311936)
    off(_ZN10CBaseState7KeyDownEi, 311952)
    off(_ZN10CBaseState11ScrollWheelEfff, 311968)
    off(_ZN10CBaseState15EnterBackgroundEv, 311984)
    off(_ZN10CBaseState15EnterForegroundEv, 312000)
    off(_ZN10CEditState7KeyDownEi, 312016)
    off(_ZN10CEditState7OnEventERK5Event, 312032)
    off(_ZN10CEditStateD2Ev, 312064)
    off(_ZN13CTouchInertiaD1Ev, 560672)
    off(_ZN10CEditStateD1Ev, 312064)
    off(_ZN10CEditStateD0Ev, 312144)
    off(_ZN10CEditState6UpdateEf, 312208)
    off(_ZN13CTouchInertia6UpdateEf, 560784)
    off(_ZN13CTouchInertia8GetSpeedERfS0_, 560864)
    off(_ZN15ecEffectManager8InstanceEv, 929184)
    off(_ZN15ecEffectManager6UpdateEf, 929856)
    off(_ZN6CScene6UpdateEf, 546272)
    off(_ZN6CScene4MoveEii, 547664)
    off(_ZN13CTouchInertia4StopEv, 560768)
    off(_ZN7CCamera13SetAutoFixPosEb, 619008)
    off(_ZN10CEditState6RenderEv, 312528)
    off(_ZN6CScene6RenderEv, 549216)
    off(_ZN6CScene14RenderAreasTaxEv, 541872)
    off(_ZN6CScene15RenderAreasTypeEv, 541856)
    off(_ZN10CEditState10TouchBeginEffi, 312624)
    off(_ZN13CTouchInertia10TouchBeginEffi, 561024)
    off(_ZN10CEditState9TouchMoveEffi, 312768)
    off(_ZN13CTouchInertia9TouchMoveEffi, 561136)
    off(_ZN10CEditState8TouchEndEffi, 312928)
    off(_ZN13CTouchInertia8TouchEndEffi, 561520)
    off(_ZN6CScene12ScreenToAreaEff, 547872)
    off(_ZN6CScene15GetSelectedAreaEv, 548944)
    off(_ZN6CScene12UnselectAreaEv, 549024)
    off(_ZN6CScene10SelectAreaEP5CArea, 553616)
    off(_ZN10CEditStateC2Ev, 313184)
    off(_ZN13CTouchInertiaC1Ev, 560720)
    off(_ZN10CEditState8InitGameEv, 313264)
    off(_ZN12CGameManager7NewGameEiiii, 325664)
    off(_ZN9CSoundRes4LoadEv, 559520)
    off(_ZN8CGameRes4LoadEv, 355040)
    off(_ZN6CScene4InitEPKci, 558880)
    off(_ZN13CTouchInertia4InitEv, 560688)
    off(_ZN10CEditState7OnEnterEv, 313968)
    off(_ZN10GUIManager6FadeInEi, 735808)
    off(_ZN10CEditState11ReleaseGameEv, 314080)
    off(_ZN6CScene7ReleaseEv, 542016)
    off(_ZN8CGameRes7ReleaseEv, 346912)
    off(_ZN9CSoundRes6UnloadEv, 559680)
    off(_ZN10CEditState6OnExitEv, 314144)
    off(_ZN16GUIMotionManager11ClearMotionEv, 737856)
    off(_ZN9CActionAID2Ev, 314208)
    off(_ZN9CActionAI18setActionNodeClearEv, 563312)
    off(_ZN9CActionAID1Ev, 314208)
    off(_Z11GetRandSeedv, 314288)
    off(_Z7GetRandv, 314320)
    off(_ZN6CFightC2Ev, 314368)
    off(_ZN6CFightC1Ev, 314368)
    off(_ZN6CFightD2Ev, 314416)
    off(_ZN6CFightD1Ev, 314416)
    off(_ZN6CFight16AirStrikesAttackEP8CCountryii, 314496)
    off(_ZN6CScene7GetAreaEi, 547856)
    off(_ZN8CCountry16GetWarMedalLevelE11WARMEDAL_ID, 626992)
    off(_ZN10CObjectDef10GetArmyDefEiPKc, 496992)
    off(_ZN6CFight16AirStrikesAttackEii, 314896)
    off(_ZN6CFight17GetAttackerResultEi, 315024)
    off(_ZN6CFight17GetDefenderResultEi, 315040)
    off(_ZN6CFight12GetAttackAddEi, 315056)
    off(_ZN6CFight12GetDefendAddEi, 315072)
    off(_ZN6CFight11ApplyResultEv, 315104)
    off(_ZN5CArea7GetArmyEi, 593616)
    off(_ZN5CArea16LostArmyStrengthEii, 595872)
    off(_ZN6CScene25AdjacentAreasEncirclementEi, 553888)
    off(_ZN8CCountry10AddDestroyEi, 624912)
    off(_ZN5CArea23ReduceConstructionLevelEv, 593200)
    off(_ZN5CArmy6IsNavyEv, 600960)
    off(_ZN15ecEffectManager9AddEffectEPKcb, 929344)
    off(_ZN8ecEffect6FireAtEfff, 928144)
    off(_ZN13CFightTextMgr7AddTextEffPKcm, 323040)
    off(_ZN9CSoundRes10PlayCharSEE10SND_EFFECT, 559760)
    off(_ZN5CArmy6AddExpEi, 601776)
    off(_Z9GetAIRandv, 569312)
    off(_ZN8CCountry13IsLocalPlayerEv, 633296)
    off(_ZN6CScene9GainMedalEff, 554272)
    off(_ZN5CArea19DestroyConstructionEv, 593376)
    off(_ZN5CArea12ClearAllArmyEv, 595440)
    off(_ZN5CArmy12BreakthroughEv, 601952)
    off(_ZN5CArea10OccupyAreaEPS_, 595152)
    off(_ZN6CFight12NormalAttackEii, 319296)
    off(_ZN5CArmy11GetNumDicesEv, 601472)
    off(_ZN8CCountry17GetCommanderLevelEv, 625856)
    off(_Z14GetArmyAbilityi, 600880)
    off(_ZN5CArmy25GetNumDicesIfLostStrengthEi, 601568)
    off(_ZN6CFight11FirstAttackEii, 321088)
    off(_ZN6CFight12SecondAttackEv, 321168)
    off(_ZN10CFightTextC2Ev, 321264)
    off(_ZN6ecTextC1Ev, 938752)
    off(_ZN10CFightTextC1Ev, 321264)
    off(_ZN10CFightTextD2Ev, 321312)
    off(_ZN6ecTextD1Ev, 938784)
    off(_ZN10CFightTextD1Ev, 321312)
    off(_ZN13CFightTextMgrD2Ev, 321376)
    off(_ZN9ecUniFontD1Ev, 930592)
    off(_ZN13CFightTextMgrD1Ev, 321376)
    off(_ZN10CFightText4InitEffP9ecUniFont, 321568)
    off(_ZN6ecText4InitEP9ecUniFont, 938832)
    off(_ZN10CFightText7SetTextEPKc, 321648)
    off(_ZN6ecText7SetTextEPKc, 940144)
    off(_ZN10CFightText8SetColorEm, 321696)
    off(_ZN6ecText8SetColorEm, 938864)
    off(_ZN10CFightText6UpdateEf, 321744)
    off(_ZN6ecText8SetAlphaEf, 938880)
    off(_ZN10CFightText6RenderEv, 321904)
    off(_ZN6ecText8DrawTextEffi, 939136)
    off(_ZN13CFightTextMgrC2Ev, 321984)
    off(_ZN9ecUniFontC1Ev, 930096)
    off(_ZN13CFightTextMgrC1Ev, 321984)
    off(_ZN13CFightTextMgr4InitEv, 322176)
    off(_ZN13CFightTextMgr7ReleaseEv, 322656)
    off(_ZN13CFightTextMgr6UpdateEf, 322848)
    off(_ZN13CFightTextMgr6RenderEv, 322976)
    off(_ZN13CActionAssistD2Ev, 323232)
    off(_ZN13CActionAssistD1Ev, 323232)
    off(_ZN12CGameManagerD2Ev, 323280)
    off(_ZN12CGameManagerD1Ev, 323280)
    off(_Z13GetNumBattlesi, 323360)
    off(_Z16GetBattleKeyNameiiPc, 323456)
    off(_Z18GetConquestKeyNameiPc, 323728)
    off(_Z17GetBattleFileNameiiiiPc, 323792)
    off(_Z24GetNumMultiPlayerBattlesi, 324176)
    off(_Z24GetBattleBelligerentListPKcRSt4listI11BelligerentSaIS2_EEb, 324256)
    off(_ZN13TiXmlDocumentC1EPKc, 843216)
    off(_ZN13TiXmlDocument8LoadFileE13TiXmlEncoding, 844384)
    off(_ZN9TiXmlNodeD2Ev, 839648)
    off(_ZN9TiXmlNode10FirstChildEPKc, 841184)
    off(_ZNK12TiXmlElement9AttributeEPKc, 850272)
    off(_ZNK12TiXmlElement17QueryIntAttributeEPKcPi, 850880)
    off(_ZN12CGameManagerC2Ev, 325200)
    off(_ZN12CGameManagerC1Ev, 325200)
    off(_ZN12CGameManager4InitEv, 325296)
    off(_ZN12CGameManager20SetPlayercountrynameEiPKc, 325312)
    off(_ZN12CGameManager11GetPlayerNoEPKc, 325376)
    off(_ZN12CGameManager20GetPlayerCountryNameEi, 325584)
    off(_ZN12CGameManager26SetConquestPlayerCountryIDEPKc, 325616)
    off(_ZN10CObjectDef12GetBattleDefEPKc, 488832)
    off(_ZN12CGameManager8LoadGameEPKc, 326000)
    off(_ZN12CGameManager9RetryGameEv, 326400)
    off(_ZN12CGameManager8SaveGameEPKc, 326432)
    off(_ZN8CCountry11SaveCountryEP15SaveCountryInfo, 624192)
    off(_ZN5CArea8SaveAeraEP12SaveAreaInfo, 599568)
    off(_ZN12CGameManager13GetSaveHeaderEPKcR10SaveHeader, 327600)
    off(_ZN12CGameManager11ClearBattleEv, 327808)
    off(_ZN8CCountryD1Ev, 620736)
    off(_ZN12CGameManager7ReleaseEv, 328080)
    off(_ZN12CGameManager10NextBattleEv, 328128)
    off(_ZN12CGameManager12IsLastBattleEv, 328144)
    off(_ZN12CGameManager15GetNumCountriesEv, 328224)
    off(_ZN12CGameManager17GetCountryByIndexEi, 328240)
    off(_ZN12CGameManager11FindCountryEPKc, 328256)
    off(_ZN12CGameManager13GetCurCountryEv, 328368)
    off(_ZN12CGameManager13InitCameraPosEv, 328432)
    off(_ZN8CCountry19GetHighestValueAreaEv, 621952)
    off(_ZN6CScene15SetCameraToAreaEi, 547968)
    off(_ZN12CGameManager16GetPlayerCountryEv, 328512)
    off(_ZN12CGameManager21GetLocalPlayerCountryEv, 328592)
    off(_ZN12CGameManager15GetNumDialoguesEv, 328752)
    off(_ZN12CGameManager18GetDialogueByIndexEi, 328768)
    off(_ZN12CGameManager10SaveBattleEPKc, 328800)
    off(_ZN12TiXmlElementC1EPKc, 849664)
    off(_ZN12TiXmlElement12SetAttributeEPKci, 853104)
    off(_ZN12TiXmlElement12SetAttributeEPKcS1_, 852192)
    off(_ZN12TiXmlElement18SetDoubleAttributeEPKcd, 853248)
    off(_ZN9TiXmlNode12LinkEndChildEPS_, 840560)
    off(_ZN8CCountry16GetCommanderNameEv, 625824)
    off(_ZN6CScene11GetNumAreasEv, 547840)
    off(_ZNK13TiXmlDocument8SaveFileEv, 844768)
    off(_ZN12CGameManager14GetCurDialogueEv, 331328)
    off(_ZN12CGameManager20GetCurDialogueStringEPc, 331392)
    off(_ZN12CGameManager12NextDialogueEv, 331712)
    off(_ZN12CGameManager18GetNumVictoryStarsEv, 331728)
    off(_ZN12CGameManager17CheckAndSetResultEv, 331824)
    off(_ZN8CCountry12IsConquestedEv, 622544)
    off(_ZN12CGameManager13BattleVictoryEv, 332592)
    off(_ZN12CGameManager21GetNewDefeatedCountryEv, 332880)
    off(_ZN12CGameManager12IsManipulateEv, 332944)
    off(_ZN8CCountry14IsActionFinishEv, 624160)
    off(_ZN12CGameManager9TurnBeginEv, 333072)
    off(_ZN8CCountry9TurnBeginEv, 629248)
    off(_ZN10CGameState16UpdateActionInfoEv, 380112)
    off(_ZN10CGameState18PlayerCountryBeginEv, 378144)
    off(_ZN8CCountry6ActionERK13CountryAction, 633376)
    off(_ZN12CGameManager7TurnEndEv, 333296)
    off(_ZN8CCountry7TurnEndEv, 623904)
    off(_ZN12CGameManager7EndTurnEv, 333344)
    off(_ZN10CGameState12ShowDialogueEPKcS1_b, 378480)
    off(_ZN10CGameState14HideAIProgressEv, 378048)
    off(_ZN12CGameManager4NextEv, 334512)
    off(_ZN9CActionAI16setCpuDriverbyIdEii, 568288)
    off(_ZN14CPlayerManager13DoFrontActionEv, 534336)
    off(_ZN5CArea13SetArmyActiveEib, 596448)
    off(_ZN12CGameManager10GameUpdateEf, 335648)
    off(_ZN8CCountry6UpdateEf, 633024)
    off(_ZN10CGameState12ShowDefeatedEP8CCountry, 373440)
    off(_ZN10CGameState16UpdateAIProgressEv, 373520)
    off(_ZN12CGameManager24MovePlayerCountryToFrontEv, 336368)
    off(_ZN12CGameManager12RealLoadGameEPKc, 336832)
    off(_ZN8CCountryC1Ev, 620656)
    off(_ZN8CCountry4InitEPKcS1_, 620896)
    off(_ZN8CCountry11LoadCountryEPK15SaveCountryInfo, 625248)
    off(_ZN7CCamera6SetPosEffb, 618256)
    off(_ZN5CArea8LoadAreaEPK12SaveAreaInfo, 600032)
    off(_ZN8CCountry7AddAreaEi, 621760)
    off(_ZN12CGameManager10LoadBattleEPKc, 337888)
    off(_ZNK12TiXmlElement20QueryDoubleAttributeEPKcPd, 851280)
    off(_ZN8CCountry12SetCommanderEPKc, 624960)
    off(_ZN14CPlayerManager21FindPlayerByCountryIDEPKc, 532784)
    off(_ZN6CScene14SetAreaCountryEiP8CCountry, 548912)
    off(_ZN5CArea15SetConstructionEii, 593104)
    off(_ZN5CArmyC1Ev, 600928)
    off(_ZN5CArmy4InitEP7ArmyDefP8CCountry, 601232)
    off(_ZN5CArea7AddArmyEP5CArmyb, 593744)
    off(_ZN5CArmy16ResetMaxStrengthEb, 601040)
    off(_ZN12CGameManager10InitBattleEv, 341632)
    off(_ZN6CScene20AllAreasEncirclementEv, 553808)
    off(_ZN14CPlayerManager18SetPlayerOfCountryEv, 533392)
    off(_ZN8CGameRes14RenderArmyInfoEiffiiiii, 343152)
    off(_ZN7ecImage6RenderEff, 906336)
    off(_ZN7ecImage8SetColorEmi, 909136)
    off(_ZN7ecImage8RenderExEfffff, 906784)
    off(_ZN8CGameRes20RenderCommanderMedalEiffi, 343792)
    off(_ZN8CGameRes12RenderArmyHPEffii, 343904)
    off(_ZN8CGameRes15RenderArmyLevelEffi, 344176)
    off(_ZN8CGameRes21RenderArmyMovementNumEffi, 344256)
    off(_ZN8CGameRes18RenderConstructionEiiff, 344336)
    off(_ZN8CGameRes10RenderPortEff, 344560)
    off(_ZN8CGameRes18RenderInstallationEiff, 344624)
    off(_ZN8CGameRes11GetBattleBGEPKc, 344704)
    off(_ZN12ecTextureRes8GetImageEPKc, 912656)
    off(_ZN8CGameRes12GetFlagImageEPKc, 344752)
    off(_ZN8CGameResC2Ev, 345008)
    off(_ZN12ecTextureResC1Ev, 910144)
    off(_ZN12ecTextureResD1Ev, 910896)
    off(_ZN8CGameResC1Ev, 345008)
    off(_ZN8CGameResD2Ev, 346272)
    off(_ZN8CGameResD1Ev, 346272)
    off(_ZN15ecEffectManager9RemoveAllEv, 929536)
    off(_ZN18ecEffectResManager8InstanceEv, 923696)
    off(_ZN18ecEffectResManager19ReleaseAllEffectResEv, 924768)
    off(_ZN18ecEffectResManager17ReleaseTextureResEv, 923792)
    off(_ZN7ecImageD1Ev, 905600)
    off(_ZN12ecTextureRes7ReleaseEv, 911296)
    off(_ZN8CGameRes12GetArmyImageEPKcib, 349440)
    off(_ZN8CGameRes10RenderArmyEPKciiffimbf, 349728)
    off(_ZN8CGameRes12RenderUIArmyEPKcffibiiiii, 350080)
    off(_ZN8CGameRes22RenderAICommanderMedalEiffPKci, 350928)
    off(_ZN8CGameRes18RenderUIAttackArmyEPKcffiiiiiiib, 351440)
    off(_ZN8CGameRes18RenderUIDefendArmyEPKcffiiiiiiib, 352368)
    off(_ZN8CGameRes10RenderFlagEPKcff, 353296)
    off(_ZN12ecTextureRes7LoadResEPKcb, 916288)
    off(_ZN7ecImageC1EP11ecImageAttr, 906096)
    off(_ZN7ecImageC1EP9ecTextureffff, 905872)
    off(_ZN18ecEffectResManager14LoadTextureResEPKc, 923728)
    off(_ZN18ecEffectResManager13LoadEffectResEPKc, 926640)
    off(_ZN13CGameSettingsD2Ev, 369312)
    off(_ZN13CGameSettingsD1Ev, 369312)
    off(_ZN13CGameSettingsC2Ev, 369328)
    off(_ZN13CGameSettingsC1Ev, 369328)
    off(_ZN10CGameStateD2Ev, 370016)
    off(_ZN10CGameStateD1Ev, 370016)
    off(_ZN10CGameStateD0Ev, 370096)
    off(_ZN10CGameState6RenderEv, 370160)
    off(_ZN15ecEffectManager6RenderEv, 930016)
    off(_ZN10CGameState8TouchEndEffi, 370336)
    off(_ZN10GUIBuyCard10GetSelCardEv, 415888)
    off(_ZN8CCountry19CheckCardTargetAreaEP7CardDefi, 627104)
    off(_ZN6GUITax7SetAreaEi, 462176)
    off(_ZN5CArea8IsActiveEv, 596336)
    off(_ZN10GUIElement4HideEv, 733152)
    off(_ZN10GUIElement4ShowEv, 733136)
    off(_ZN6CScene13CheckMoveableEiii, 551904)
    off(_ZN14CPlayerManager22SendPacketToAllPlayersE9PACKET_IDPKvi, 525776)
    off(_ZN10GUISelArmy7SetAreaEi, 458560)
    off(_ZN6CScene15CheckAttackableEiii, 552416)
    off(_ZN12GUIAttackBox9SetAttackEii, 390192)
    off(_ZN10CGameState9TouchMoveEffi, 371552)
    off(_ZN6CScene13ScreenToSceneERfS0_, 547424)
    off(_ZN7CCamera14SetPosAndScaleEfff, 618448)
    off(_ZN10CGameState11ScrollWheelEfff, 372496)
    off(_ZN10CGameState15EnterBackgroundEv, 372736)
    off(_ZN10CGameStateC2Ev, 372832)
    off(_ZN10CGameState8InitGameEv, 372912)
    off(_ZN10GUIManager14LoadTextureResEPKcb, 735648)
    off(_ZN10CGameState11ReleaseGameEv, 373104)
    off(_ZN10GUIManager16UnloadTextureResEPKc, 735712)
    off(_ZN10CGameState6OnExitEv, 373264)
    off(_ZN10CCSoundBox11UnloadMusicEv, 934416)
    off(_ZN14CPlayerManager4StopEv, 523312)
    off(_ZN10GUIElement11MoveToFrontEPS_, 732400)
    off(_ZN11GUIDefeated12ShowDefeatedEP8CCountry, 427600)
    off(_ZN13GUIAIProgress17SetCurCountryNameEPKc, 388432)
    off(_ZN10CGameState7OnEnterEv, 373808)
    off(_ZN10GUIManager9AddButtonEPKcS1_RK7GUIRectP10GUIElementP9ecUniFont, 737136)
    off(_ZN9GUIButton13SetBackgroundEPKc, 730656)
    off(_ZN7GUIGoldC1Ev, 434544)
    off(_ZN7GUIGold4InitERK7GUIRect, 434928)
    off(_ZN10GUIElement8AddChildEPS_b, 731840)
    off(_ZN6GUITaxC1Ev, 461152)
    off(_ZN6GUITax4InitERK7GUIRect, 461600)
    off(_ZN12GUISmallCardC1Ev, 460112)
    off(_ZN12GUISmallCard4InitERK7GUIRect, 460176)
    off(_ZN12GUIAttackBoxC1Ev, 389488)
    off(_ZN12GUIAttackBox4InitERK7GUIRect, 389584)
    off(_ZN10GUIElement6CenterEv, 732656)
    off(_ZN11GUIPauseBoxC1Ev, 444208)
    off(_ZN11GUIPauseBox4InitERK7GUIRect, 444304)
    off(_ZN10GUIBuyCardC1Ev, 412288)
    off(_ZN10GUIBuyCard4InitERK7GUIRect, 412496)
    off(_ZN13GUIAIProgressC1Ev, 388000)
    off(_ZN13GUIAIProgress4InitERK7GUIRect, 388080)
    off(_ZN10GUISelArmyC1Ev, 458064)
    off(_ZN10GUISelArmy4InitERK7GUIRect, 458128)
    off(_ZN8GUIBeginC1Ev, 405936)
    off(_ZN8GUIBegin4InitERK7GUIRect, 406208)
    off(_ZN11GUIDefeatedC1Ev, 427008)
    off(_ZN11GUIDefeated4InitERK7GUIRect, 427152)
    off(_ZN9GUIBattleC1Ev, 396992)
    off(_ZN9GUIBattle4InitERK7GUIRect, 397344)
    off(_ZN11GUIDialogueC1Ev, 430032)
    off(_ZN11GUIDialogue4InitERK7GUIRect, 430176)
    off(_ZN16GUIMotionManager9AddMotionEP10GUIElementffft, 738768)
    off(_ZN10CCSoundBox9LoadMusicEPKcS1_, 934368)
    off(_ZN10CCSoundBox9PlayMusicEb, 934432)
    off(_ZN12GUITutorailsC1Ev, 464928)
    off(_ZN12GUITutorails4InitERK7GUIRect, 466880)
    off(_ZN13GUIActionInfoC1Ev, 387184)
    off(_ZN13GUIActionInfo4InitERK7GUIRect, 387280)
    off(_ZN10CGameState15EnableIdleTimerEf, 377648)
    off(_ZN10CGameState12StartBattaleEiiib, 377680)
    off(_ZN9GUIBattle11BattleStartEiii, 399136)
    off(_ZN8GUIBegin9ResetDataEv, 407408)
    off(_ZN10CGameState10SelectAreaEi, 378224)
    off(_ZN6CScene10SelectAreaEi, 553680)
    off(_ZN10CGameState12UnselectAreaEv, 378400)
    off(_ZN11GUIDialogue7ShowDlgEPKcS1_b, 430576)
    off(_ZN10CGameState11ShowWarningEi, 378560)
    off(_ZN10GUIWarningC1Ev, 472752)
    off(_ZN10GUIWarning4InitERK7GUIRecti, 472880)
    off(_ZN10CGameState6UpdateEf, 378800)
    off(_ZN6CScene9IsBombingEv, 554224)
    off(_ZN10GUIBuyCard13CanBuySelCardEv, 415952)
    off(_ZN10GUIBuyCard13ReleaseTargetEv, 417408)
    off(_ZN10GUIBuyCard15ResetCardTargetEv, 417280)
    off(_ZN14CPlayerManager13GetNumActionsEv, 534640)
    off(_ZN14CPlayerManager22IsDisconnectedFromHostEv, 525232)
    off(_ZN13GUIActionInfo7SetInfoEPKc, 387424)
    off(_ZN10CGameState15ResetTouchStateEv, 380656)
    off(_ZN10CGameState11BackPressedEv, 380720)
    off(_ZN10GUIManager7FadeOutEiP10GUIElement, 735840)
    off(_ZN10CGameState10TouchBeginEffi, 380928)
    off(_ZN10CGameState7OnEventERK5Event, 381200)
    off(_ZN10GUIVictoryC1Ev, 471056)
    off(_ZN10GUIVictory4InitERK7GUIRectb, 471136)
    off(_ZN10GUIVictory4PlayEv, 472048)
    off(_ZN16GUIMotionManager12ActiveMotionEmh, 739376)
    off(_ZN14CPlayerManager18SendPacketToServerE9PACKET_IDPKvi, 525648)
    off(_ZN10GUIManager13SafeFreeChildEP10GUIElement, 736560)
    off(_ZN6GUIEndC1Ev, 431792)
    off(_ZN6GUIEnd4InitERK7GUIRect, 431936)
    off(_ZN10GUIBuyCard14ResetCardStateEv, 416064)
    off(_ZN10GUIOptionsC1Ev, 440256)
    off(_ZN10GUIOptions4InitERK7GUIRect, 440384)
    off(_ZN7GUISaveC1Ev, 453680)
    off(_ZN7GUISave4InitERK7GUIRectib, 453792)
    off(_ZN12GUISmallCard7SetCardEP7CardDef, 460256)
    off(_ZN14GUIBattleIntroC1Ev, 401792)
    off(_ZN14GUIBattleIntro4InitERK7GUIRectii, 403136)
    off(_ZN11GUIDefeated12HideDefeatedEv, 428592)
    off(_ZN9GUIResultC1Ev, 446480)
    off(_ZN9GUIResult4InitERK7GUIRecti, 446704)
    off(_ZN14CPlayerManager16PlayerLoadFinishEP7CPlayer, 533968)
    off(_ZN7GUIBankC1Ev, 391136)
    off(_ZN7GUIBank4InitERK7GUIRect, 391232)
    off(_ZN6GUIIapC1Ev, 436816)
    off(_ZN6GUIIap4InitERK7GUIRect, 436944)
    off(_ZN13ecStringTableC1Ev, 934864)
    off(_ZN13ecStringTableD1Ev, 935968)
    off(_ZN13GUIActionInfo8OnUpdateEf, 386768)
    off(_ZN13GUIActionInfoD2Ev, 386784)
    off(_ZN11ecLabelTextD1Ev, 933152)
    off(_ZN10GUIElementD2Ev, 732304)
    off(_ZN13GUIActionInfoD1Ev, 386784)
    off(_ZN13GUIActionInfoD0Ev, 386880)
    off(_ZN13GUIActionInfo8OnRenderEv, 386928)
    off(_ZN10GUIElement10GetAbsRectER7GUIRect, 732768)
    off(_ZN11ecLabelText8DrawTextEff, 933840)
    off(_ZN13GUIActionInfoC2Ev, 387184)
    off(_ZN10GUIElementC2Ev, 731712)
    off(_ZN11ecLabelTextC1Ev, 933104)
    off(_ZN11ecLabelText4InitEPKciiii, 933360)
    off(_ZN11ecLabelText7SetTextEPKc, 933456)
    off(_ZN10GUIElement7OnEventERK5Event, 731664)
    off(_ZN13GUIAIProgressD2Ev, 387472)
    off(_ZN13GUIAIProgressD1Ev, 387472)
    off(_ZN13GUIAIProgressD0Ev, 387648)
    off(_ZN13GUIAIProgress8OnRenderEv, 387712)
    off(_ZN13GUIAIProgressC2Ev, 388000)
    off(_ZN7ecImage4InitEP11ecImageAttr, 906224)
    off(_ZN10GUIElement8OnUpdateEf, 731648)
    off(_ZN12GUIAttackBoxD2Ev, 388560)
    off(_ZN12GUIAttackBoxD1Ev, 388560)
    off(_ZN12GUIAttackBoxD0Ev, 388736)
    off(_ZN12GUIAttackBox8OnRenderEv, 388784)
    off(_ZN5CArmy14GetMaxStrengthEv, 601392)
    off(_ZN12GUIAttackBoxC2Ev, 389488)
    off(_ZN11GUIButtonExC1Ev, 408176)
    off(_ZN9GUIButton4InitEPKcS1_RK7GUIRectP9ecUniFont, 730128)
    off(_ZN11GUIButtonEx12SetImageTextEPKcS1_, 408256)
    off(_ZN12GUIAttackBox7OnEventERK5Event, 390432)
    off(_ZN7GUIBank8OnUpdateEf, 390640)
    off(_ZN7GUIBankD2Ev, 390656)
    off(_ZN7GUIBankD1Ev, 390656)
    off(_ZN7GUIBankD0Ev, 390784)
    off(_ZN7GUIBank8OnRenderEv, 390832)
    off(_ZN7ecImage6RenderEffff, 906560)
    off(_ZN7GUIBankC2Ev, 391136)
    off(_ZN9GUIButtonC1Ev, 730000)
    off(_ZN8GUIMedalC1Ev, 439136)
    off(_ZN8GUIMedal4InitERK7GUIRect, 439360)
    off(_ZN10GUIManager8AddImageEPKcRK7GUIRectP10GUIElement, 736944)
    off(_ZN7GUIBank7OnEventERK5Event, 393440)
    off(_ZN9GUIBattleD2Ev, 393888)
    off(_ZN12CBattleSceneD1Ev, 613088)
    off(_ZN9GUIBattleD1Ev, 393888)
    off(_ZN9GUIBattleD0Ev, 394256)
    off(_ZN9GUIBattle8OnRenderEv, 394304)
    off(_ZN12CBattleScene6RenderEv, 605216)
    off(_ZN9GUIBattleC2Ev, 396992)
    off(_ZN12CBattleSceneC1Ev, 604864)
    off(_ZN12CBattleScene4InitEiPS_, 605088)
    off(_ZN9GUIBattle11ResetBattleEv, 398096)
    off(_ZN12CBattleScene13SetBattleAreaEi, 608704)
    off(_ZN9GUIBattle12BattleFinishEv, 399472)
    off(_ZN9GUIBattle13UpateFightingEf, 399504)
    off(_ZN12CBattleScene6AttackEv, 610720)
    off(_ZN12CBattleScene11IsAttackingEv, 610768)
    off(_ZN12CBattleScene12DestroyUnitsEi, 610880)
    off(_ZN9GUIBattle8OnUpdateEf, 399936)
    off(_ZN12CBattleScene6UpdateEf, 611616)
    off(_ZN12CBattleScene12ClearCratersEv, 611232)
    off(_ZN12CBattleScene12ClearEffectsEv, 612896)
    off(_ZN9GUIBattle7OnEventERK5Event, 400416)
    off(_ZN14GUIBattleIntroD2Ev, 400480)
    off(_ZN14GUIBattleIntroD1Ev, 400480)
    off(_ZN14GUIBattleIntroD0Ev, 400752)
    off(_ZN14GUIBattleIntro8OnRenderEv, 400800)
    off(_ZN14GUIBattleIntroC2Ev, 401792)
    off(_ZN14GUIBattleIntro9SetBattleEii, 402160)
    off(_ZN14GUIBattleIntro7OnEventERK5Event, 404624)
    off(_ZN8GUIBeginD2Ev, 404864)
    off(_ZN8GUIBeginD1Ev, 404864)
    off(_ZN8GUIBeginD0Ev, 405216)
    off(_ZN8GUIBegin8OnRenderEv, 405280)
    off(_ZN8GUIBeginC2Ev, 405936)
    off(_ZN7GUITechC1Ev, 463344)
    off(_ZN7GUITech4InitERK7GUIRect, 463440)
    off(_ZN8CCountry8GetTaxesEv, 628736)
    off(_ZN8CCountry12GetIndustrysEv, 628992)
    off(_ZN8GUIBegin7OnEventERK5Event, 407808)
    off(_ZN11GUIButtonExD2Ev, 408016)
    off(_ZN9GUIButtonD2Ev, 728624)
    off(_ZN11GUIButtonExD1Ev, 408016)
    off(_ZN11GUIButtonExD0Ev, 408128)
    off(_ZN11GUIButtonExC2Ev, 408176)
    off(_ZN9GUIButtonC2Ev, 730000)
    off(_ZN11GUIButtonEx8OnRenderEv, 408480)
    off(_ZN9GUIButton8OnRenderEv, 728928)
    off(_ZN9GUIButton7OnEventERK5Event, 731248)
    off(_ZN10GUICardTabD2Ev, 408896)
    off(_ZN10GUICardTabD1Ev, 408896)
    off(_ZN10GUICardTabD0Ev, 408944)
    off(_ZN10GUIBuyCardD2Ev, 408992)
    off(_ZN10GUIBuyCardD1Ev, 408992)
    off(_ZN10GUIBuyCardD0Ev, 409264)
    off(_ZN10GUIBuyCard8OnRenderEv, 409312)
    off(_ZN10GUICardTabC2Ev, 409888)
    off(_ZN10GUICardTabC1Ev, 409888)
    off(_ZN10GUICardTab19GetCardTabButtonIdxEPK10GUIElement, 409936)
    off(_ZN10GUICardTab9SelectTabEi, 410016)
    off(_ZN10GUIElement6GetPosERfS0_, 732544)
    off(_ZN10GUIElement6SetPosEff, 732576)
    off(_ZN10GUICardTab4InitERK7GUIRect, 410336)
    off(_ZN14GUIRadioButtonC1Ev, 740960)
    off(_ZN10GUIManager8AddImageEPKcRK13ecTextureRectRK7GUIRectP10GUIElementb, 736640)
    off(_ZN10GUIBuyCardC2Ev, 412288)
    off(_ZN11GUICardListC1Ev, 423152)
    off(_ZN11GUICardList4InitERK7GUIRecti, 423712)
    off(_ZN7ecImageC1EP9ecTextureRK13ecTextureRect, 905968)
    off(_ZN10GUIBuyCard15SetSelCardIntroEv, 415744)
    off(_ZN10CObjectDef10GetCardDefE7CARD_ID, 487648)
    off(_ZN8CCountry10CanBuyCardEP7CardDef, 626544)
    off(_ZN7GUICard13SetPriceColorEm, 423056)
    off(_ZN8CCountry16IsEnoughIndustryEP7CardDef, 623840)
    off(_ZN7GUICard16SetIndustryColorEm, 423104)
    off(_ZN8CCountry12GetCardPriceEP7CardDef, 625952)
    off(_ZN8CCountry15GetCardIndustryEP7CardDef, 623808)
    off(_ZN11GUICardList7GetCardEi, 423312)
    off(_ZN8CCountry13IsEnoughMoneyEP7CardDef, 626064)
    off(_ZN10GUIElement9SetEnableEb, 733168)
    off(_ZN8CCountry13GetCardRoundsE7CARD_ID, 623792)
    off(_ZN7GUICard8SetPriceEi, 422832)
    off(_ZN7GUICard11SetIndustryEi, 422944)
    off(_ZN8CCountry15CanUseCommanderEv, 626512)
    off(_ZN10GUIBuyCard7SelCardEii, 416960)
    off(_ZN6CScene12ClearTargetsEv, 548960)
    off(_ZN8CCountry14SetCardTargetsEP7CardDef, 628288)
    off(_ZN6CScene11ResetTargetEv, 553744)
    off(_ZN10GUICardTab7OnEventERK5Event, 417472)
    off(_ZN10GUIBuyCard7OnEventERK5Event, 417632)
    off(_ZN10CObjectDef17GetCardTargetTypeEP7CardDef, 487680)
    off(_ZN10GUIElement8OnRenderEv, 731632)
    off(_ZN7GUICardD2Ev, 418368)
    off(_ZN7GUICardD1Ev, 418368)
    off(_ZN7GUICardD0Ev, 418688)
    off(_ZN7GUICard8OnRenderEv, 418736)
    off(_ZN11GUICardListD2Ev, 420256)
    off(_ZN11GUICardListD1Ev, 420256)
    off(_ZN11GUICardListD0Ev, 420336)
    off(_ZN11GUICardList8OnUpdateEf, 420384)
    off(_ZN7GUICardC2Ev, 420960)
    off(_ZN7GUICardC1Ev, 420960)
    off(_ZN7GUICard4InitEP7CardDefRK7GUIRect, 421296)
    off(_ZN11GUICardListC2Ev, 423152)
    off(_ZN11GUICardList11ResetSelectEv, 423280)
    off(_ZN11GUICardList10GelSelItemEff, 423360)
    off(_ZN10GUIElement11CheckInRectEff, 732864)
    off(_ZN7GUICard7OnEventERK5Event, 425200)
    off(_ZN11GUICardList9SetSelectEi, 425600)
    off(_ZN11GUICardList8ReSelectEv, 425728)
    off(_ZN11GUICardList7OnEventERK5Event, 425792)
    off(_ZN11GUIDefeated8OnRenderEv, 426544)
    off(_ZN11GUIDefeatedC2Ev, 427008)
    off(_ZN10CObjectDef15GetGeneralPhotoEPKc, 488464)
    off(_ZN11GUIDefeatedD2Ev, 428784)
    off(_ZN11GUIDefeatedD1Ev, 428784)
    off(_ZN11GUIDefeatedD0Ev, 428864)
    off(_ZN11GUIDefeated8OnUpdateEf, 428912)
    off(_ZN11GUIDefeated7OnEventERK5Event, 429088)
    off(_ZN11GUIDialogue8OnUpdateEf, 429248)
    off(_ZN11GUIDialogueD2Ev, 429264)
    off(_ZN11GUIDialogueD1Ev, 429264)
    off(_ZN11GUIDialogueD0Ev, 429472)
    off(_ZN11GUIDialogue8OnRenderEv, 429520)
    off(_ZN11GUIDialogueC2Ev, 430032)
    off(_ZN11GUIDialogue7HideDlgEv, 430896)
    off(_ZN11GUIDialogue7OnEventERK5Event, 430944)
    off(_ZN6GUIEndD2Ev, 431104)
    off(_ZN6GUIEndD1Ev, 431104)
    off(_ZN6GUIEndD0Ev, 431312)
    off(_ZN6GUIEnd8OnRenderEv, 431360)
    off(_ZN6GUIEndC2Ev, 431792)
    off(_ZN6GUIEnd7OnEventERK5Event, 433984)
    off(_ZN7GUIGoldD2Ev, 434144)
    off(_ZN7GUIGoldD1Ev, 434144)
    off(_ZN7GUIGoldD0Ev, 434256)
    off(_ZN7GUIGold8OnRenderEv, 434304)
    off(_ZN7GUIGoldC2Ev, 434544)
    off(_ZN7GUIGold8SetMoneyEi, 434672)
    off(_ZN7GUIGold11SetIndustryEi, 434800)
    off(_ZN7GUIGold8OnUpdateEf, 435200)
    off(_ZN15GUIProductPrice8OnRenderEv, 435296)
    off(_ZN6GUIIapD2Ev, 435488)
    off(_ZN6GUIIapD1Ev, 435488)
    off(_ZN6GUIIapD0Ev, 435696)
    off(_ZN6GUIIap7OnEventERK5Event, 435744)
    off(_ZN15GUIProductPriceD2Ev, 436080)
    off(_ZN15GUIProductPriceD1Ev, 436080)
    off(_ZN15GUIProductPriceD0Ev, 436256)
    off(_ZN6GUIIap8OnRenderEv, 436304)
    off(_ZN15GUIProductPriceC2Ev, 436448)
    off(_ZN15GUIProductPriceC1Ev, 436448)
    off(_ZN15GUIProductPrice4InitERK7GUIRect, 436544)
    off(_ZN11ecLabelText8SetColorEm, 933728)
    off(_ZN15GUIProductPrice14SetLocalePirceEPKc, 436736)
    off(_ZN6GUIIapC2Ev, 436816)
    off(_ZN9GUIButton7SetTextEPKc, 730944)
    off(_ZN9GUIButton12SetTextColorEm, 731104)
    off(_ZN6GUIIap14SetLocalePirceEiPKc, 438704)
    off(_ZN6GUIIap14OnListCompleteEPv, 438768)
    off(_ZN6GUIIap15SetProductPriceEv, 438784)
    off(_ZN8GUIMedalD2Ev, 438800)
    off(_ZN8GUIMedalD1Ev, 438800)
    off(_ZN8GUIMedalD0Ev, 438896)
    off(_ZN8GUIMedal8OnRenderEv, 438944)
    off(_ZN8GUIMedalC2Ev, 439136)
    off(_ZN8GUIMedal8SetMedalEi, 439232)
    off(_ZN8GUIMedal8OnUpdateEf, 439728)
    off(_ZN8GUIMedal7OnEventERK5Event, 439776)
    off(_ZN10GUIOptionsD2Ev, 439936)
    off(_ZN10GUIOptionsD1Ev, 439936)
    off(_ZN10GUIOptionsD0Ev, 440112)
    off(_ZN10GUIOptions8OnRenderEv, 440160)
    off(_ZN10GUIOptionsC2Ev, 440256)
    off(_ZN10GUIManager12AddScrollBarERK7GUIRectP10GUIElementPKcS6_iiiii, 737296)
    off(_ZN11GUILevelSelC1Ev, 654560)
    off(_ZN11GUILevelSel4InitERK7GUIRecti, 654624)
    off(_ZN12GUIScrollBar12SetScrollPosEi, 741456)
    off(_ZN10GUIOptions7OnEventERK5Event, 443520)
    off(_ZN12GUIScrollBar12GetScrollPosEv, 741392)
    off(_ZN11GUIPauseBoxD2Ev, 443904)
    off(_ZN11GUIPauseBoxD1Ev, 443904)
    off(_ZN11GUIPauseBoxD0Ev, 444016)
    off(_ZN11GUIPauseBox8OnRenderEv, 444064)
    off(_ZN11GUIPauseBoxC2Ev, 444208)
    off(_ZN11GUIPauseBox7OnEventERK5Event, 445024)
    off(_ZN9GUIResult8OnUpdateEf, 445152)
    off(_ZN9GUIResultD2Ev, 445168)
    off(_ZN9GUIResultD1Ev, 445168)
    off(_ZN9GUIResultD0Ev, 445584)
    off(_ZN9GUIResult8OnRenderEv, 445632)
    off(_ZN9GUIResultC2Ev, 446480)
    off(_ZN13GUIAdornMedalC1Ev, 639200)
    off(_ZN13GUIAdornMedal4InitER7GUIRect, 639632)
    off(_ZN9GUIResult7OnEventERK5Event, 449936)
    off(_ZN11GUISaveItemD2Ev, 450096)
    off(_ZN14GUIRadioButtonD2Ev, 740208)
    off(_ZN11GUISaveItemD1Ev, 450096)
    off(_ZN11GUISaveItemD0Ev, 450224)
    off(_ZN7GUISave8OnRenderEv, 450272)
    off(_ZN11GUISaveItem8OnRenderEv, 450336)
    off(_ZN7GUISaveD2Ev, 452096)
    off(_ZN12ecTextureRes9UnloadResEPKc, 912096)
    off(_ZN7GUISaveD1Ev, 452096)
    off(_ZN7GUISaveD0Ev, 452304)
    off(_ZN11GUISaveItem8OnUpdateEf, 452352)
    off(_ZN11GUISaveItemC2Ev, 452480)
    off(_ZN14GUIRadioButtonC2Ev, 740960)
    off(_ZN11GUISaveItemC1Ev, 452480)
    off(_ZN11GUISaveItem4InitERK7GUIRectPKc, 452640)
    off(_ZN11GUISaveItem7SetInfoEPKciiiiiiiib, 453008)
    off(_ZN7GUISaveC2Ev, 453680)
    off(_ZN7GUISave7SelItemEi, 456400)
    off(_ZN7GUISave7OnEventERK5Event, 456736)
    off(_ZN11GUIArmyItemD2Ev, 457360)
    off(_ZN11GUIArmyItemD1Ev, 457360)
    off(_ZN11GUIArmyItemD0Ev, 457408)
    off(_ZN11GUIArmyItem8OnRenderEv, 457456)
    off(_ZN10GUISelArmyD2Ev, 457760)
    off(_ZN10GUISelArmyD1Ev, 457760)
    off(_ZN10GUISelArmyD0Ev, 457840)
    off(_ZN10GUISelArmy8OnRenderEv, 457888)
    off(_ZN11GUIArmyItemC2Ev, 458000)
    off(_ZN11GUIArmyItemC1Ev, 458000)
    off(_ZN10GUISelArmyC2Ev, 458064)
    off(_ZN7ecImage8SetAlphaEfi, 909184)
    off(_ZN10GUISelArmy15MoveArmyToFrontEi, 458720)
    off(_ZN5CArea15MoveArmyToFrontEib, 594000)
    off(_ZN10GUISelArmy10TargetArmyEi, 459072)
    off(_ZN10GUISelArmy7OnEventERK5Event, 459184)
    off(_ZN12GUISmallCardD2Ev, 459408)
    off(_ZN12GUISmallCardD1Ev, 459408)
    off(_ZN12GUISmallCardD0Ev, 459488)
    off(_ZN12GUISmallCard8OnRenderEv, 459536)
    off(_ZN12GUISmallCardC2Ev, 460112)
    off(_ZN6GUITaxD2Ev, 460336)
    off(_ZN6GUITaxD1Ev, 460336)
    off(_ZN6GUITaxD0Ev, 460560)
    off(_ZN6GUITax8OnRenderEv, 460608)
    off(_ZN6GUITaxC2Ev, 461152)
    off(_ZN6GUITax8SetMoneyEi, 461344)
    off(_ZN6GUITax11SetIndustryEi, 461472)
    off(_ZN5CArea10GetRealTaxEv, 593472)
    off(_ZN5CArea11GetIndustryEv, 593568)
    off(_ZN5CArea11HasArmyCardEi, 595712)
    off(_ZN7GUITechD2Ev, 462896)
    off(_ZN7GUITechD1Ev, 462896)
    off(_ZN7GUITechD0Ev, 463024)
    off(_ZN7GUITech8OnRenderEv, 463072)
    off(_ZN7GUITech8OnUpdateEf, 463280)
    off(_ZN7GUITechC2Ev, 463344)
    off(_ZN12GUITutorails8OnRenderEv, 463888)
    off(_ZN12GUITutorailsC2Ev, 464928)
    off(_ZN12GUITutorails10LoadScriptEv, 465136)
    off(_ZN12GUITutorails13ReleaseScriptEv, 467552)
    off(_ZN12GUITutorailsD2Ev, 467760)
    off(_ZN12GUITutorailsD1Ev, 467760)
    off(_ZN12GUITutorailsD0Ev, 468128)
    off(_ZN12GUITutorails7ShowDlgEi, 468176)
    off(_ZN12GUITutorails7ShowDlgEPKc, 468352)
    off(_ZN12GUITutorails7HideDlgEv, 468464)
    off(_ZN12GUITutorails6ExeCmdEi, 468512)
    off(_ZN6CScene22MoveCameraCenterToAreaEi, 548240)
    off(_ZN6CScene16MoveCameraToAreaEi, 548064)
    off(_ZN12GUITutorails8OnUpdateEf, 469616)
    off(_ZN6CScene8IsMovingEv, 547824)
    off(_ZN12GUITutorails7OnEventERK5Event, 470112)
    off(_ZN10GUIVictoryD2Ev, 470256)
    off(_ZN10GUIVictoryD1Ev, 470256)
    off(_ZN10GUIVictoryD0Ev, 470432)
    off(_ZN10GUIVictory8OnRenderEv, 470480)
    off(_ZN10GUIVictory8OnUpdateEf, 470736)
    off(_ZN10GUIVictoryC2Ev, 471056)
    off(_ZN10GUIVictory7OnEventERK5Event, 472224)
    off(_ZN10GUIWarning8OnUpdateEf, 472320)
    off(_ZN10GUIWarningD2Ev, 472336)
    off(_ZN10GUIWarningD1Ev, 472336)
    off(_ZN10GUIWarningD0Ev, 472480)
    off(_ZN10GUIWarning8OnRenderEv, 472528)
    off(_ZN10GUIWarningC2Ev, 472752)
    off(_ZN10GUIWarning7OnEventERK5Event, 473760)
    off(_ZN10CLoadState10TouchBeginEffi, 473968)
    off(_ZN10CLoadState9TouchMoveEffi, 473984)
    off(_ZN10CLoadState8TouchEndEffi, 474000)
    off(_ZN10CLoadState11BackPressedEv, 474016)
    off(_ZN10CLoadStateD2Ev, 474032)
    off(_ZN10CLoadStateD1Ev, 474032)
    off(_ZN10CLoadStateD0Ev, 474112)
    off(_ZN10CLoadState7OnEnterEv, 474176)
    off(_ZN10CLoadState6OnExitEv, 475088)
    off(_ZN10CLoadState6RenderEv, 475248)
    off(_ZN10CLoadState6UpdateEf, 475584)
    off(_ZN10CLoadState7OnEventERK5Event, 475696)
    off(_ZN10CLoadStateC2Ev, 475856)
    off(_ZN10CLogoStateD2Ev, 475952)
    off(_ZN10CLogoStateD1Ev, 475952)
    off(_ZN10CLogoState15EnterForegroundEv, 475984)
    off(_ZN10CLogoStateD0Ev, 476000)
    off(_ZN10CLogoState7OnEnterEv, 476064)
    off(_ZN10CLogoState6OnExitEv, 477296)
    off(_ZN10CLogoState6RenderEv, 477344)
    off(_ZN10CLogoState7OnEventERK5Event, 477504)
    off(_ZN10CLogoState6UpdateEf, 477584)
    off(_ZN14CPlayerManager4InitEv, 517968)
    off(_ZN10CLogoStateC2Ev, 477776)
    off(_ZN11CMatchStateD2Ev, 477824)
    off(_ZN11CMatchStateD1Ev, 477824)
    off(_ZN11CMatchState6UpdateEf, 477856)
    off(_ZN11CMatchState6RenderEv, 477872)
    off(_ZN11CMatchState10TouchBeginEffi, 477888)
    off(_ZN11CMatchState9TouchMoveEffi, 477904)
    off(_ZN11CMatchState8TouchEndEffi, 477920)
    off(_ZN11CMatchStateD0Ev, 477936)
    off(_ZN11CMatchState7OnEnterEv, 478000)
    off(_ZN13GUIMatchSetupC1Ev, 675824)
    off(_ZN13GUIMatchSetup4InitERK7GUIRect, 678096)
    off(_ZN11CMatchState6OnExitEv, 478304)
    off(_ZN11CMatchStateC2Ev, 478368)
    off(_ZN11CMatchState18StartMultiplayGameEi, 478416)
    off(_ZN11CMatchState7OnEventERK5Event, 478528)
    off(_ZN14CPlayerManager17SendStartLoadGameEv, 533520)
    off(_ZN11CMatchState11ShowWarningEi, 478928)
    off(_ZN10CMenuStateD2Ev, 479152)
    off(_ZN10CMenuStateD1Ev, 479152)
    off(_ZN10CMenuState6UpdateEf, 479184)
    off(_ZN10CMenuState6RenderEv, 479200)
    off(_ZN10CMenuState10TouchBeginEffi, 479216)
    off(_ZN10CMenuState9TouchMoveEffi, 479232)
    off(_ZN10CMenuState8TouchEndEffi, 479248)
    off(_ZN10CMenuStateD0Ev, 479264)
    off(_ZN10CMenuState7OnEnterEv, 479328)
    off(_ZN11GUIMainMenuC1Ev, 658192)
    off(_ZN11GUIMainMenu4InitERK7GUIRect, 658560)
    off(_ZN12GUISelBattleC1Ev, 696336)
    off(_ZN12GUISelBattle4InitERK7GUIRectii, 696640)
    off(_ZN10CMenuState6OnExitEv, 479968)
    off(_ZN10CMenuStateC2Ev, 480032)
    off(_ZN10CMenuState13PeerConnectedEv, 480080)
    off(_ZN10CMenuState18StartMultiplayGameEi, 480160)
    off(_ZN10CMenuState7OnEventERK5Event, 480272)
    off(_ZN11GUIMainMenu13RefreshNewTipEv, 658480)
    off(_ZN10GUILoadingC1Ev, 655456)
    off(_ZN10GUILoading4InitERK7GUIRect, 655520)
    off(_ZN11GUIMainMenu6ShowADEv, 670288)
    off(_ZN14CPlayerManager12SetupSessionEb, 522048)
    off(_ZN16GUILockedWarningC1Ev, 656448)
    off(_ZN16GUILockedWarning4InitERK7GUIRect, 656576)
    off(_ZN10GUIServiceC1Ev, 711072)
    off(_ZN10GUIService4InitERK7GUIRect, 711264)
    off(_ZN12GUICommanderC1Ev, 640288)
    off(_ZN12GUICommander4InitERK7GUIRect, 641280)
    off(_ZN10GUIElement9FreeChildEPS_, 732144)
    off(_ZN11GUIHostList17ResetConnectStateEv, 650288)
    off(_ZN13GUISelCountryC1Ev, 706096)
    off(_ZN13GUISelCountry4InitERK7GUIRecti, 707584)
    off(_ZN14CPlayerManager9InitCorpsEi, 526112)
    off(_ZN14CPlayerManager14DestroySessionEv, 522656)
    off(_ZN11GUIHostListC1Ev, 649072)
    off(_ZN11GUIHostList4InitERK7GUIRect, 651232)
    off(_ZN10GUINewGameC1Ev, 680832)
    off(_ZN10GUINewGame4InitERK7GUIRect, 684400)
    off(_ZN14CPlayerManager10StartMatchEv, 521520)
    off(_ZN14CPlayerManager9StopMatchEv, 523248)
    off(_ZN10CMenuState11ShowWarningEi, 485568)
    off(_ZN14GUIExitWarningC1Ev, 645888)
    off(_ZN14GUIExitWarning4InitERK7GUIRect, 646016)
    off(_ZN10CObjectDefC2Ev, 486112)
    off(_ZN10CObjectDefC1Ev, 486112)
    off(_ZN10CObjectDef11LoadCardDefEv, 486592)
    off(_ZN10CObjectDef16GetUnitPositionsEPKc, 487728)
    off(_ZN10CObjectDef15GetCommanderDefEPKc, 488096)
    off(_ZN10CObjectDef14GetConquestDefEPKc, 489200)
    off(_ZN10CObjectDef14ReleaseArmyDefEv, 489792)
    off(_ZN10CObjectDef18ReleaseUnitMotionsEv, 490432)
    off(_ZN10CObjectDef20ReleaseUnitPositionsEv, 491392)
    off(_ZN10CObjectDef19ReleaseCommanderDefEv, 491904)
    off(_ZN10CObjectDef20ReleaseGeneralPhotosEv, 492640)
    off(_ZN10CObjectDef17ReleaseBattleListEv, 493280)
    off(_ZN10CObjectDefD2Ev, 494368)
    off(_ZN10CObjectDefD1Ev, 494368)
    off(_ZN10CObjectDef19ReleaseConquestListEv, 496000)
    off(_ZN10CObjectDef7ReleaseEv, 496576)
    off(_ZN10CObjectDef14GetUnitMotionsEPKcS1_, 497632)
    off(_ZN10CObjectDef11LoadArmyDefEv, 498720)
    off(_ZN10CObjectDef15LoadUnitMotionsEv, 501760)
    off(_ZN10CObjectDef16LoadUnitPositonsEv, 504672)
    off(_ZN10CObjectDef16LoadCommanderDefEv, 506912)
    off(_ZN10CObjectDef17LoadGeneralPhotosEv, 509216)
    off(_ZN10CObjectDef14LoadBattleListEv, 511328)
    off(_ZN10CObjectDef16LoadConquestListEv, 515072)
    off(_ZN14CPlayerManager14WillDisconnectEv, 517568)
    off(_ZN14CPlayerManager34onLocalPlayerAuthenticationChangedEv, 517584)
    off(_ZN14CPlayerManager20onFriendListReceivedEv, 517616)
    off(_ZN14CPlayerManager14onMatchRequestEv, 517648)
    off(_ZN14CPlayerManager17onPlayerConnectedEPKc, 517680)
    off(_ZN14CPlayerManager17InvitationDidFailEPKc, 517728)
    off(_ZN11GUIHostList13ConnectFailedEv, 650304)
    off(_ZN14CPlayerManager16SessionNoNetworkEv, 517872)
    off(_Z9ecGetUUIDRSs, 835344)
    off(_Z13ecGetUUIDHashv, 835360)
    off(_ZN9ecGameKitC1Ev, 834928)
    off(_ZN9ecGameKit4InitEP17ecGameKitDelegateb, 834960)
    off(_ZN14CPlayerManager15AnalyzePeerNameERKSsRSsRiS3_, 518160)
    off(_ZN14CPlayerManager7ConnectEPKci, 518848)
    off(_ZN18ecSessionInterface7ConnectEPKc, 835200)
    off(_ZN14CPlayerManager9ReconnectEv, 518960)
    off(_ZN18ecSessionInterface15GetPeerNameListERSt4listISsSaISsEES3_, 835184)
    off(_ZN14CPlayerManager13CancelConnectEv, 520432)
    off(_ZN18ecSessionInterface13CancelConnectEv, 835216)
    off(_ZN14CPlayerManager19onPeerListDidChangeEv, 520480)
    off(_ZN11GUIHostList15RefreshHostListEv, 650320)
    off(_ZN9ecGameKit25ShowMatchmakerWithRequestEiii, 835024)
    off(_ZN14CPlayerManager9AddPlayerEbPKc, 521584)
    off(_ZN7CPlayerC1Ev, 714208)
    off(_ZN7CPlayer4InitEbPKc, 714272)
    off(_ZN18ecSessionInterfaceC1Ev, 835104)
    off(_ZN18ecSessionInterface4InitEP17ecSessionDelegate, 835136)
    off(_ZN18ecSessionInterface12SetupSessionEb, 835168)
    off(_ZN18ecSessionInterface13GetDeviceNameERSs, 835328)
    off(_ZN14CPlayerManager18ClearRemotePlayersEv, 522432)
    off(_ZN7CPlayerD1Ev, 715456)
    off(_ZN14CPlayerManager12ClearPlayersEv, 522576)
    off(_ZN18ecSessionInterfaceD1Ev, 835120)
    off(_ZN9ecGameKitD1Ev, 834944)
    off(_ZN14CPlayerManagerD2Ev, 522912)
    off(_ZN14CPlayerManagerD1Ev, 522912)
    off(_ZN9ecGameKit22DisconnectCurrentMatchEv, 835040)
    off(_ZN14CPlayerManager16onAcceptedInviteEv, 523376)
    off(_ZN14CPlayerManager10FindPlayerEPKc, 523488)
    off(_ZN14CPlayerManager20onPlayerInfoReceivedERSt4listIP12ecPlayerInfoSaIS2_EE, 523648)
    off(_ZN14CPlayerManager12onMatchFoundEv, 524048)
    off(_ZN9ecGameKit18GetMatchPlayerListERSt4listISsSaISsEE, 835056)
    off(_ZN14CPlayerManager16FindPlayerByUUIDEi, 524448)
    off(_ZN14CPlayerManager17DidRecvInvitationEPKc, 524544)
    off(_ZN18ecSessionInterface11GetPeerNameEPKcRSs, 835312)
    off(_ZN18ecSessionInterface17DeclineInvitationEPKc, 835264)
    off(_ZN18ecSessionInterface16AcceptInvitationEPKc, 835248)
    off(_ZN14CPlayerManager21GetDisconnectedPlayerEv, 525152)
    off(_ZN14CPlayerManager18SendPacketToPlayerE12PacketHeaderPKviPKc, 525280)
    off(_ZN18ecSessionInterface10SendPacketEPKviPKc, 835280)
    off(_ZN9ecGameKit10SendPacketEPKviPKc, 834992)
    off(_ZN14CPlayerManager18SendPacketToPlayerE9PACKET_IDPKviP7CPlayer, 525488)
    off(_ZN14CPlayerManager28SendPacketToAllPlayersExceptE9PACKET_IDPKviP7CPlayer, 525504)
    off(_ZN7CPlayer10PushPacketE9PACKET_IDPKvi, 714896)
    off(_ZN7CPlayer10SendPacketE9PACKET_IDPKvi, 714496)
    off(_ZN14CPlayerManager10ClearCorpsEv, 525984)
    off(_ZN14CPlayerManager13WillTerminateEv, 527040)
    off(_ZN13GUIMatchSetup18RefreshCorsButtonsEv, 677088)
    off(_ZN11GUIHostList13ClearHostListEv, 649184)
    off(_ZN14CPlayerManager12GetLeftCorpsEi, 527328)
    off(_ZN14CPlayerManager13GetRightCorpsEi, 527344)
    off(_ZN14CPlayerManager15GetNumLeftCorpsEv, 527360)
    off(_ZN14CPlayerManager16GetNumRightCorpsEv, 527392)
    off(_ZN14CPlayerManager8SelCorpsEiiP7CPlayer, 527424)
    off(_ZN14CPlayerManager17RemoveCorpsPlayerEii, 527744)
    off(_ZN14CPlayerManager17RemoveCorpsPlayerEP7CPlayer, 527824)
    off(_ZN14CPlayerManager12RemovePlayerEP7CPlayer, 527984)
    off(_ZN14CPlayerManager20onPlayerDisconnectedEPKc, 528112)
    off(_ZN14CPlayerManager12GetCorpsDataERi, 528288)
    off(_ZN14CPlayerManager15onPeerConnectedEPKc, 529776)
    off(_ZN14CPlayerManager12onStartMatchEv, 530624)
    off(_ZN9ecGameKit18GetLocalPlayerInfoER12ecPlayerInfo, 835088)
    off(_ZN9ecGameKit19GetMatchPlayersInfoEv, 835072)
    off(_ZN14CPlayerManager14SetCorpsByDataEPviP7CPlayer, 531712)
    off(_ZN14CPlayerManager17IsAllPlayersReadyEv, 532704)
    off(_ZN14CPlayerManager23RefreshAndSendCorpsDataEv, 532976)
    off(_ZN14CPlayerManager18onPeerDisconnectedEPKc, 533184)
    off(_ZN14CPlayerManager14SendRoundBeginEv, 533856)
    off(_ZN14CPlayerManager16ClearActionQueueEv, 534128)
    off(_ZN7CPlayer9SendFirstEv, 715232)
    off(_ZN14CPlayerManager14onReceivedDataEPKviPKcb, 535568)
    off(_ZN7CPlayer7SendAckEi, 715712)
    off(_ZN7CPlayer7RecvAckEi, 715792)
    off(_ZN13GUIMatchSetup16CreatCorsButtonsEv, 675936)
    off(_ZN14CPlayerManager22onReveivedDataFromPeerEPKviPKc, 537408)
    off(_ZN14CPlayerManager24onReceivedDataFromPlayerEPKviPKc, 537488)
    off(_ZN14CPlayerManagerC2Ev, 537920)
    off(_ZN14CPlayerManagerC1Ev, 537920)
    off(_ZN6CSceneD2Ev, 538720)
    off(_ZN9CAreaMarkD1Ev, 600400)
    off(_ZN6CSceneD1Ev, 538720)
    off(_ZN6CSceneC2Ev, 538896)
    off(_ZN9CAreaMarkC1Ev, 600320)
    off(_ZN7CCameraC1Ev, 618000)
    off(_ZN6CSceneC1Ev, 538896)
    off(_ZN6CScene17CheckAdjacentDataEv, 539184)
    off(_ZN6CScene9NewAdjoinEv, 539200)
    off(_ZN6CScene10LoadAdjoinEi, 539456)
    off(_ZN6CScene10SaveAdjoinEi, 539792)
    off(_ZN6CScene10MakeAdjoinEii, 540064)
    off(_ZN6CScene9DelAdjoinEii, 540416)
    off(_ZN6CScene8IsAdjoinEii, 540704)
    off(_ZN6CScene12RenderAdjoinEv, 540800)
    off(_ZN6CScene17RenderAreasCenterEv, 540816)
    off(_ZN6CScene15RenderAreasArmyEv, 540832)
    off(_ZN6CScene16RenderAreasPointEv, 540848)
    off(_ZN6CScene12LoadAreaDataEi, 540864)
    off(_ZN6CScene12SaveAreaDataEi, 541184)
    off(_ZN6CScene14RenderSeaAreasEv, 541536)
    off(_ZN7CCamera14IsRectInCameraEffff, 620272)
    off(_ZN6CScene13RenderAreasIDEv, 541888)
    off(_ZN6CScene10ClearAreasEv, 541920)
    off(_ZN5CAreaD1Ev, 592448)
    off(_ZN7CBomberD1Ev, 615728)
    off(_ZN11CBackgroundD1Ev, 602464)
    off(_ZN9CAreaMark7ReleaseEv, 600336)
    off(_ZN6CScene11SaveAreaTaxEi, 542384)
    off(_ZN6CScene14LoadAreaEnableEPKc, 543040)
    off(_ZN6CScene14SaveAreaEnableEPKc, 543376)
    off(_ZN6CScene20AreaDisableOutofRectEiiii, 543392)
    off(_ZN6CScene13InitAreaImageEi, 543552)
    off(_ZN6CScene12CalSceneRectERfS0_S0_S0_, 545312)
    off(_ZN6CScene13IsRectInSecenEffff, 546176)
    off(_ZN7CCamera5UpateEf, 619888)
    off(_ZN7CBomber6UpdateEf, 616752)
    off(_ZN5CArea6UpdateEf, 596928)
    off(_ZN6CMedal5UpateEf, 713904)
    off(_ZN6CScene11CreateArrowEii, 546832)
    off(_Z7InvSqrtf, 905040)
    off(_ZN9hgeVector6RotateEf, 905424)
    off(_ZN6CScene14ScreenToAreaIDEff, 547568)
    off(_ZN9CAreaMark7GetMarkEii, 600768)
    off(_ZN7CCamera4MoveEffb, 618784)
    off(_ZN6CScene6MoveToEii, 547744)
    off(_ZN7CCamera6MoveToEffb, 619472)
    off(_ZN7CCamera21IsRectInVisibleRegionEffff, 620400)
    off(_ZN6CScene21MoveCameraBetweenAreaEii, 548336)
    off(_ZN6CScene25GetTwoAreasDistanceSquareEii, 548656)
    off(_ZN6CScene19GetTwoAreasDistanceEii, 548784)
    off(_ZN6CScene19GetNumAdjacentAreasEi, 549088)
    off(_ZN6CScene17GetAdjacentAreaIDEii, 549120)
    off(_ZN6CScene15GetAdjacentAreaEii, 549152)
    off(_ZN7CCamera5ApplyEv, 620128)
    off(_ZN11CBackground6RenderEP7CCamera, 603808)
    off(_ZN11CBackground9RenderBoxEP7CCameraffff, 604000)
    off(_ZN5CArea14RenderBuildingEv, 598272)
    off(_ZN5CArea6RenderEv, 598464)
    off(_ZN7ecImage9Render4VCEffffffffif, 907888)
    off(_ZN6CMedal6RenderEv, 714016)
    off(_ZN7CBomber6RenderEv, 617888)
    off(_ZN8CCountry15AirstrikeRadiusEv, 627008)
    off(_ZN6CScene13CheckAdjacentEii, 551824)
    off(_ZN5CArea11HasArmyCardEii, 595664)
    off(_ZN6CScene17SetSelAreaTargetsEP5CArea, 552864)
    off(_ZN5CArea12EncirclementEv, 596672)
    off(_ZN6CScene8AirborneEi, 554032)
    off(_ZN7CBomber8AirborneEi, 616432)
    off(_ZN6CScene19AircraftCarrierBombEii, 554096)
    off(_ZN7CBomber19AircraftCarrierBombEii, 616368)
    off(_ZN6CScene8BombAreaEii, 554160)
    off(_ZN7CBomber8BombAreaEii, 616080)
    off(_ZN7CBomber9IsBombingEv, 616720)
    off(_ZN6CMedalC1Ev, 713840)
    off(_ZN6CMedal4InitEff, 713856)
    off(_ZN6CScene11LoadAreaTaxEi, 555008)
    off(_ZN5CAreaC1Ev, 592320)
    off(_ZN5CArea4InitEiRK8AreaInfo, 592640)
    off(_ZN6CScene9InitAreasEiPKc, 556064)
    off(_ZN6CScene20CreateRenderAreaListEv, 558144)
    off(_ZN9CAreaMark4InitEi, 600448)
    off(_ZN11CBackgroundC1Ev, 602304)
    off(_ZN11CBackground4InitEiiiiiffff, 602752)
    off(_ZN7CCamera4InitEffff, 618016)
    off(_ZN7CBomberC1Ev, 615696)
    off(_ZN7CBomber4InitEv, 615872)
    off(_ZN9CSoundResD2Ev, 559440)
    off(_ZN9CSoundResD1Ev, 559440)
    off(_ZN9CSoundResC2Ev, 559456)
    off(_ZN9CSoundResC1Ev, 559456)
    off(_ZN13CStateManagerD2Ev, 559840)
    off(_ZN13CStateManagerD1Ev, 559840)
    off(_ZN13CStateManagerC2Ev, 559856)
    off(_ZN13CStateManagerC1Ev, 559856)
    off(_ZN13CTouchInertiaD2Ev, 560672)
    off(_ZN13CTouchInertiaC2Ev, 560720)
    off(_ZN13CTouchInertia13AddTrackPointEff, 560944)
    off(_ZN13CTouchInertia13GetStartPointEv, 561232)
    off(_ZN9CActionAI11detectCardsE7CARD_ID, 561952)
    off(_ZN8CCountry12IsCardUnlockEP7CardDef, 623760)
    off(_ZN9CActionAI21analyseCompositePowerEv, 562240)
    off(_ZN9CActionAI12getAiPercentEi, 562800)
    off(_ZN9CActionAI14getNumArmyMoveEii, 563248)
    off(_ZN9CActionAI12purChaseCardE7CARD_ID, 563536)
    off(_ZN13CActionAssist17purChaseCardsCardEv, 579648)
    off(_ZN13CActionAssist16purChaseFortCardEv, 582656)
    off(_ZN13CActionAssist21purChaseConstructCardEv, 571872)
    off(_ZN13CActionAssist21purChaseAirStrikeCardEv, 584288)
    off(_ZN13CActionAssist17purChaseDraftCardEb, 577952)
    off(_ZN9CActionAI15sortArmyToFrontEv, 564736)
    off(_ZN5CArea12IsArmyActiveEi, 596480)
    off(_ZN9CActionAI8getMaxIdEv, 565520)
    off(_ZN9CActionAI13setArmyActionEP5CArea, 565792)
    off(_ZN13CActionAssist16actionToNextAreaEiiii, 587328)
    off(_ZN9CActionAI13moveAndAttackEv, 566640)
    off(_Z13GetAIRandSeedv, 569280)
    off(_ZN13CActionAssist13calcDraftTypeEbiP8CCountry, 569360)
    off(_ZN5CArea12GetCityLevelEv, 593408)
    off(_ZN13CActionAssist19purChaseSpecialCardEv, 573264)
    off(_ZN13CActionAssist11getAllianceEiii, 573280)
    off(_ZN13CActionAssist10searchNodeEii, 573568)
    off(_ZN13CActionAssist14searchNodeByIDEii, 575168)
    off(_ZN13CActionAssist11getNeighborEiiic, 575520)
    off(_ZN8CCountry19CheckCardTargetArmyEP7CardDefii, 626720)
    off(_ZN5CArea16GetIndustryLevelEv, 593520)
    off(_ZN13CActionAssist4isAIEi, 587248)
    off(_ZN5CAreaC2Ev, 592320)
    off(_ZN5CAreaD2Ev, 592448)
    off(_ZN5CArmyD1Ev, 600944)
    off(_ZN5CArea12CanConstructEi, 592864)
    off(_ZN5CArea9ConstructEi, 592960)
    off(_ZN5CArea10GetArmyIdxEP5CArmy, 593648)
    off(_ZN5CArea10RemoveArmyEP5CArmy, 593856)
    off(_ZN5CArea15MoveArmyToFrontEP5CArmyb, 594208)
    off(_ZN5CArea9DraftArmyEi, 594288)
    off(_ZN5CArea13SetMoveInArmyEPS_P5CArmybbPKc, 594496)
    off(_ZN5CArea10MoveArmyToEPS_, 594656)
    off(_ZN8CCountry10RemoveAreaEi, 621376)
    off(_ZN8CCountry14BeConquestedByEPS_, 622688)
    off(_ZN5CArea10SetArmyDirEif, 595536)
    off(_ZN5CArea11AddArmyCardEii, 595568)
    off(_ZN5CArea11DelArmyCardEii, 595616)
    off(_ZN5CArea18RevertArmyStrengthEi, 595808)
    off(_ZN5CArmy12LostStrengthEi, 600992)
    off(_ZN8CCountry12CommanderDieEv, 626128)
    off(_ZN5CArea15AddArmyStrengthEii, 596080)
    off(_ZN5CArmy11AddStrengthEi, 601408)
    off(_ZN5CArea16AllArmyPoisoningEv, 596144)
    off(_ZN5CArmy9PoisoningEv, 601360)
    off(_ZN5CArea11UpgradeArmyEi, 596208)
    off(_ZN5CArmy7UpgradeEv, 601680)
    off(_ZN5CArea18SetAllArmyMovementEi, 596272)
    off(_ZN5CArea17CheckEncirclementEv, 596512)
    off(_ZN5CArmy9SetMoraleEi, 601920)
    off(_ZN5CArea10RenderArmyEffiP5CArmy, 597664)
    off(_ZN5CArea9TurnBeginEv, 599024)
    off(_ZN5CArmy9TurnBeginEv, 602208)
    off(_ZN5CArea7TurnEndEv, 599184)
    off(_ZN5CArmy7TurnEndEv, 602240)
    off(_ZN5CArmy8SaveArmyEP12SaveArmyInfo, 601984)
    off(_ZN5CArmy8LoadArmyEPK12SaveArmyInfo, 602080)
    off(_ZN9CAreaMarkC2Ev, 600320)
    off(_ZN9CAreaMarkD2Ev, 600400)
    off(_ZN5CArmyC2Ev, 600928)
    off(_ZN5CArmyD2Ev, 600944)
    off(_ZN11CBackgroundC2Ev, 602304)
    off(_ZN11CBackgroundD2Ev, 602464)
    off(_ZN12CBattleSceneC2Ev, 604864)
    off(_ZN12CBattleScene7ReleaseEv, 605200)
    off(_ZN11CBattleUnit6RenderEv, 614976)
    off(_ZN8ecEffect6RenderEv, 928560)
    off(_Z13HasUnitMotionPKci, 606080)
    off(_ZN12CBattleScene11CreateUnitsEv, 606688)
    off(_ZN9ecLibraryC1Ev, 1257216)
    off(_ZN9ecLibrary4LoadEPKcR12ecTextureRes, 1258720)
    off(_ZN11CBattleUnitC1Ev, 613424)
    off(_ZN11CBattleUnit4InitEiiP9ecLibraryP11UnitMotions, 613488)
    off(_ZN11CBattleUnit12SetDestroyedEv, 615536)
    off(_ZN12CBattleScene12ReleaseUnitsEv, 607840)
    off(_ZN11CBattleUnitD1Ev, 614016)
    off(_ZN12CBattleScene10CreateFortEv, 607968)
    off(_ZN12CBattleScene11ReleaseFortEv, 608592)
    off(_ZN11CBattleUnit11IsAttackingEv, 615504)
    off(_ZN11CBattleUnit7DestroyEv, 615552)
    off(_ZN12CBattleScene9AddCraterEPKcfff, 611008)
    off(_ZN12CBattleScene10StarEffectEi, 611408)
    off(_ZN12CBattleScene9AddEffectEPKcff, 611456)
    off(_ZN15ecEffectManager12CreateEffectEPKc, 929216)
    off(_ZN11CBattleUnit6AttackEv, 615328)
    off(_ZN11CBattleUnit6UpdateEf, 614128)
    off(_ZN8ecEffect6UpdateEf, 928480)
    off(_ZN8ecEffect6IsLiveEv, 928624)
    off(_ZN8ecEffectD1Ev, 927776)
    off(_ZN12CBattleSceneD2Ev, 613088)
    off(_ZN11CBattleUnitC2Ev, 613424)
    off(_ZN9ecElementC1Ev, 1262496)
    off(_ZN9ecElement4InitEPKcP9ecLibrary, 1263648)
    off(_ZN9ecElement4PlayEv, 1263936)
    off(_ZN11CBattleUnit7ReleaseEv, 613936)
    off(_ZN9ecElementD1Ev, 1262560)
    off(_ZN11CBattleUnitD2Ev, 614016)
    off(_ZN9ecElement6UpdateEf, 1265888)
    off(_ZN9ecElement6RenderERK7ecMtx32, 1265024)
    off(_ZN9ecElement11SetCurFrameEi, 1263728)
    off(_ZN9ecElement7SetLoopEi, 1264192)
    off(_ZN9ecElement11GetPlayTimeEv, 1263888)
    off(_ZN7CBomberC2Ev, 615696)
    off(_ZN7CBomberD2Ev, 615728)
    off(_ZN8CCountry7UseCardEP7CardDefii, 629392)
    off(_ZN7CCameraC2Ev, 618000)
    off(_ZN7CCamera12SetSceneRectEffff, 618192)
    off(_ZN8CCountryC2Ev, 620656)
    off(_ZN8CCountryD2Ev, 620736)
    off(_ZN8CCountry8FindAreaEi, 621696)
    off(_ZN8CCountry15GetFirstCapitalEv, 622512)
    off(_ZN8CCountry18FindAdjacentAreaIDEib, 622928)
    off(_ZN8CCountry22FindAdjacentLandAreaIDEib, 623088)
    off(_ZN8CCountry13GetNumAirportEv, 623264)
    off(_ZN8CCountry18GetMinDstToAirportEi, 623392)
    off(_ZN8CCountry17GenCardTargetListE7CARD_ID, 623680)
    off(_ZN8CCountry16GetCurCardTargetEv, 623696)
    off(_ZN8CCountry14NextCardTargetEv, 623728)
    off(_ZN8CCountry12FinishActionEv, 624096)
    off(_ZN8CCountry16SetWarMedalLevelE11WARMEDAL_IDi, 626960)
    off(_ZN8CCountry12CollectTaxesEv, 628912)
    off(_ZN8CCountry16CollectIndustrysEv, 629168)
    off(_ZN8CCountry8DoActionEv, 632064)
    off(_ZN17GUICommanderMedalD2Ev, 633728)
    off(_ZN17GUICommanderMedalD1Ev, 633728)
    off(_ZN17GUICommanderMedalD0Ev, 633872)
    off(_ZN11GUIWarMedalD2Ev, 633920)
    off(_ZN11GUIWarMedalD1Ev, 633920)
    off(_ZN11GUIWarMedalD0Ev, 634016)
    off(_ZN17GUICommanderMedal8OnUpdateEf, 634064)
    off(_ZN11GUIWarMedal8OnUpdateEf, 634224)
    off(_ZN17GUICommanderMedal8OnRenderEv, 634384)
    off(_ZN11GUIWarMedal8OnRenderEv, 634672)
    off(_ZN13GUIAdornMedalD2Ev, 635072)
    off(_ZN13GUIAdornMedalD1Ev, 635072)
    off(_ZN13GUIAdornMedalD0Ev, 635264)
    off(_ZN13GUIAdornMedal8OnRenderEv, 635328)
    off(_ZN16GUIUpgradeButtonD2Ev, 635904)
    off(_ZN16GUIUpgradeButtonD1Ev, 635904)
    off(_ZN16GUIUpgradeButtonD0Ev, 636000)
    off(_ZN16GUIUpgradeButton8OnRenderEv, 636048)
    off(_ZN6ecText14GetStringWidthEib, 938976)
    off(_ZN12GUICommanderD2Ev, 636816)
    off(_ZN12GUICommanderD1Ev, 636816)
    off(_ZN12GUICommanderD0Ev, 637200)
    off(_ZN12GUICommander8OnRenderEv, 637248)
    off(_ZN12GUICommander8OnUpdateEf, 637744)
    off(_ZN17GUICommanderMedalC2Ev, 637872)
    off(_ZN17GUICommanderMedalC1Ev, 637872)
    off(_ZN17GUICommanderMedal4InitERK7GUIRecti, 638000)
    off(_ZN17GUICommanderMedal13SetArrowColorEm, 638528)
    off(_ZN11GUIWarMedalC2Ev, 638592)
    off(_ZN11GUIWarMedalC1Ev, 638592)
    off(_ZN11GUIWarMedal8SetLevelEi, 638656)
    off(_ZN11GUIWarMedal4InitERK7GUIRect11WARMEDAL_IDi, 638880)
    off(_ZN11GUIWarMedal13SetArrowColorEm, 639136)
    off(_ZN13GUIAdornMedalC2Ev, 639200)
    off(_ZN13GUIAdornMedal7RefreshEv, 639360)
    off(_ZN16GUIUpgradeButtonC2Ev, 639968)
    off(_ZN16GUIUpgradeButtonC1Ev, 639968)
    off(_ZN16GUIUpgradeButton12SetNeedMedalEi, 640064)
    off(_ZN12GUICommanderC2Ev, 640288)
    off(_ZN12GUICommander16SetCommanderInfoEv, 640480)
    off(_ZN12GUICommander13SelectedMedalEi, 644368)
    off(_ZN12GUICommander7OnEventERK5Event, 644576)
    off(_ZN14GUIExitWarningD2Ev, 645552)
    off(_ZN14GUIExitWarningD1Ev, 645552)
    off(_ZN14GUIExitWarningD0Ev, 645696)
    off(_ZN14GUIExitWarning8OnRenderEv, 645744)
    off(_ZN14GUIExitWarningC2Ev, 645888)
    off(_ZN14GUIExitWarning7OnEventERK5Event, 647200)
    off(_ZN19GUIConnectHostStateD2Ev, 647392)
    off(_ZN19GUIConnectHostStateD1Ev, 647392)
    off(_ZN19GUIConnectHostStateD0Ev, 647456)
    off(_ZN11GUIHostListD2Ev, 647504)
    off(_ZN11GUIHostListD1Ev, 647504)
    off(_ZN11GUIHostListD0Ev, 647632)
    off(_ZN11GUIHostList8OnRenderEv, 647680)
    off(_ZN19GUIConnectHostState8OnRenderEv, 647856)
    off(_ZN11GUIHostItemD2Ev, 648144)
    off(_ZN11GUIHostItemD1Ev, 648144)
    off(_ZN11GUIHostItemD0Ev, 648400)
    off(_ZN19GUIConnectHostStateC2Ev, 648448)
    off(_ZN19GUIConnectHostStateC1Ev, 648448)
    off(_ZN19GUIConnectHostState4InitER7GUIRect, 648528)
    off(_ZN11GUIHostItemC2Ev, 648720)
    off(_ZN11GUIHostItemC1Ev, 648720)
    off(_ZN11GUIHostItem7SetNameEPKc, 648896)
    off(_ZN11GUIHostListC2Ev, 649072)
    off(_ZN11GUIHostList8FindHostEPKc, 649264)
    off(_ZN11GUIHostList14FindHostByUUIDEi, 649376)
    off(_ZN11GUIHostList7AddHostEPKcS1_ii, 649440)
    off(_ZN19GUIConnectHostState7OnEventERK5Event, 653776)
    off(_ZN11GUIHostList7OnEventERK5Event, 653856)
    off(_ZN11GUIHostItem8OnRenderEv, 654032)
    off(_ZN11GUILevelSelD2Ev, 654160)
    off(_ZN11GUILevelSelD1Ev, 654160)
    off(_ZN11GUILevelSelD0Ev, 654240)
    off(_ZN11GUILevelSel8OnRenderEv, 654304)
    off(_ZN11GUILevelSelC2Ev, 654560)
    off(_ZN11GUILevelSel7OnEventERK5Event, 654784)
    off(_ZN10GUILoadingD2Ev, 655040)
    off(_ZN10GUILoadingD1Ev, 655040)
    off(_ZN10GUILoadingD0Ev, 655152)
    off(_ZN10GUILoading8OnRenderEv, 655200)
    off(_ZN10GUILoadingC2Ev, 655456)
    off(_ZN10GUILoading7OnEventERK5Event, 655936)
    off(_ZN16GUILockedWarningD2Ev, 656016)
    off(_ZN16GUILockedWarningD1Ev, 656016)
    off(_ZN16GUILockedWarningD0Ev, 656160)
    off(_ZN16GUILockedWarning8OnRenderEv, 656208)
    off(_ZN16GUILockedWarningC2Ev, 656448)
    off(_ZN16GUILockedWarning7OnEventERK5Event, 657216)
    off(_ZN11GUIMainMenuD2Ev, 657504)
    off(_ZN11GUIMainMenuD1Ev, 657504)
    off(_ZN11GUIMainMenuD0Ev, 658000)
    off(_ZN11GUIMainMenu8OnRenderEv, 658048)
    off(_ZN11GUIMainMenuC2Ev, 658192)
    off(_ZN11GUIMainMenu12IsShowNewTipEv, 658320)
    off(_ZN9GUIButton12SetTextImageEPKc, 730800)
    off(_ZN8GUIImageC1Ev, 734048)
    off(_ZN8GUIImage4InitEPKcRK7GUIRect, 734432)
    off(_ZN11GUIMainMenu8OnUpdateEf, 668400)
    off(_ZN11GUIMainMenu7OnEventERK5Event, 670320)
    off(_ZN12GUICorpsInfoD2Ev, 671136)
    off(_ZN12GUICorpsInfoD1Ev, 671136)
    off(_ZN12GUICorpsInfoD0Ev, 671264)
    off(_ZN13GUIMatchSetup8OnRenderEv, 671312)
    off(_ZN14GUICorpsButton8OnRenderEv, 671408)
    off(_ZN12GUICorpsInfo8OnRenderEv, 671600)
    off(_ZN14GUICorpsButtonD2Ev, 672000)
    off(_ZN14GUICorpsButtonD1Ev, 672000)
    off(_ZN14GUICorpsButtonD0Ev, 672096)
    off(_ZN13GUIMatchSetupD2Ev, 672144)
    off(_ZN13GUIMatchSetupD1Ev, 672144)
    off(_ZN13GUIMatchSetupD0Ev, 672464)
    off(_ZN12GUICorpsInfoC2Ev, 672592)
    off(_ZN12GUICorpsInfoC1Ev, 672592)
    off(_ZN12GUICorpsInfo4InitERK7GUIRect, 672688)
    off(_ZN12GUICorpsInfo13SetPlayerNameEPKcbS1_iib, 672832)
    off(_ZN14GUICorpsButtonC2Ev, 674144)
    off(_ZN14GUICorpsButtonC1Ev, 674144)
    off(_ZN14GUICorpsButton4InitERK7GUIRectPKcb, 674208)
    off(_ZN14GUICorpsButton13SetPlayerNameEPKcbS1_iib, 675648)
    off(_ZN13GUIMatchSetupC2Ev, 675824)
    off(_ZN13GUIMatchSetup7OnEventERK5Event, 679872)
    off(_ZN10GUINewGameD2Ev, 680480)
    off(_ZN10GUINewGameD1Ev, 680480)
    off(_ZN10GUINewGameD0Ev, 680640)
    off(_ZN10GUINewGame8OnRenderEv, 680688)
    off(_ZN7_JNIEnv22CallStaticObjectMethodEP7_jclassP10_jmethodIDz, 680784)
    off(_ZN10GUINewGameC2Ev, 680832)
    off(_ZN10GUINewGame12IsShowSurveyEv, 681024)
    off(_ZN10GUINewGame12IsImageReadyEv, 681200)
    off(_ZN10GUINewGame18IsIabEventImgReadyEv, 681376)
    off(_ZN10GUINewGame15IsShowSurveyTipEv, 681552)
    off(_ZN10GUINewGame17IsShowIabEventTipEv, 681728)
    off(_ZN10GUINewGame14IsShowIabEventEv, 681904)
    off(_Z12JString2CStrP7_JNIEnvP8_jstring, 682080)
    off(_ZN10GUINewGame17GetPromotionImageEv, 682496)
    off(_ZN10GUINewGame16GetIabEventImageEv, 682848)
    off(_ZN10GUINewGame15GetPromotionUrlEv, 683200)
    off(_ZN10GUINewGame14BtnSurveyClickEv, 683408)
    off(_ZN10GUINewGame14GetIabEventUrlEv, 683568)
    off(_ZN10GUINewGame21OnRadioBtnSurveyClickEv, 683776)
    off(_ZN10GUINewGame23OnRadioBtnIabEventClickEv, 683968)
    off(_ZN10GUINewGame14GetSelectGroupEP14GUIRadioButton, 684160)
    off(_ZN10GUINewGame18OnCheckButtonClickEP14GUIRadioButton, 684224)
    off(_ZN10GUINewGame13GetAppVersionEv, 684368)
    off(_ZN9GUIButton13SetTextOffsetEff, 731168)
    off(_ZN9GUIButton12SetTextAlignEi, 731216)
    off(_ZN8GUIImage4InitEPKcRK13ecTextureRectRK7GUIRectbbb, 734128)
    off(_ZN7GUITextC1Ev, 742848)
    off(_ZN7GUIText4InitERK7GUIRectP9ecUniFont, 742896)
    off(_ZN7GUIText7SetTextEPKc, 743040)
    off(_ZN8GUIImage8SetImageEPKcRK13ecTextureRectb, 734672)
    off(_ZN10GUINewGame7OnEventERK5Event, 694768)
    off(_Z16ecLaunchAppStorePKc, 940624)
    off(_ZN12GUISelBattle8OnRenderEv, 695392)
    off(_ZN12GUISelBattleC2Ev, 696336)
    off(_ZN13GUIBattleListC1Ev, 719808)
    off(_ZN13GUIBattleList4InitERK7GUIRecti, 719936)
    off(_ZN13GUIBattleList18SelectLastUnlockedEv, 721984)
    off(_ZN13GUIBattleList9SetSelectEi, 721744)
    off(_ZN12GUISelBattle16ReleaseImageListEv, 700064)
    off(_ZN12GUISelBattleD2Ev, 700384)
    off(_ZN12GUISelBattleD1Ev, 700384)
    off(_ZN12GUISelBattleD0Ev, 700832)
    off(_ZN12GUISelBattle13LoadImageListEii, 701072)
    off(_ZN12GUISelBattle9SelBattleEii, 703072)
    off(_ZN12GUISelBattle8OnUpdateEf, 703136)
    off(_ZN12GUISelBattle7OnEventERK5Event, 703920)
    off(_ZN13GUISelCountry8OnRenderEv, 704672)
    off(_ZN13GUISelCountry8OnUpdateEf, 705216)
    off(_ZN13GUISelCountryC2Ev, 706096)
    off(_ZN13GUISelCountry9SelBattleEii, 706224)
    off(_ZN13GUISelCountry13LoadImageListEi, 706240)
    off(_ZN14GUICountryListC1Ev, 725824)
    off(_ZN14GUICountryList4InitERK7GUIRecti, 726912)
    off(_ZN13GUISelCountry16ReleaseImageListEv, 709920)
    off(_ZN13GUISelCountryD2Ev, 710112)
    off(_ZN13GUISelCountryD1Ev, 710112)
    off(_ZN13GUISelCountryD0Ev, 710448)
    off(_ZN13GUISelCountry7OnEventERK5Event, 710496)
    off(_ZN14GUICountryList15GetSelCountryIDEv, 726128)
    off(_ZN10GUIServiceD2Ev, 710768)
    off(_ZN10GUIServiceD1Ev, 710768)
    off(_ZN10GUIServiceD0Ev, 710928)
    off(_ZN10GUIService8OnRenderEv, 710976)
    off(_ZN10GUIServiceC2Ev, 711072)
    off(_ZN7GUIText8SetAlignEi, 743168)
    off(_ZN10GUIService7OnEventERK5Event, 713520)
    off(_ZN6CMedalC2Ev, 713840)
    off(_ZN7CPlayerC2Ev, 714208)
    off(_ZN7CPlayer10RecvPacketEPKvi, 715216)
    off(_ZN7CPlayer15ClearPacketListEv, 715328)
    off(_ZN7CPlayerD2Ev, 715456)
    off(_ZN13GUIBattleItem8OnUpdateEf, 715920)
    off(_ZN13GUIBattleItemD2Ev, 715936)
    off(_ZN13GUIBattleItemD1Ev, 715936)
    off(_ZN13GUIBattleItemD0Ev, 716128)
    off(_ZN13GUIBattleItem8OnRenderEv, 716176)
    off(_ZN13GUIBattleListD2Ev, 718192)
    off(_ZN13GUIBattleListD1Ev, 718192)
    off(_ZN13GUIBattleListD0Ev, 718272)
    off(_ZN13GUIBattleList8OnUpdateEf, 718336)
    off(_ZN13GUIBattleItemC2Ev, 718944)
    off(_ZN13GUIBattleItemC1Ev, 718944)
    off(_ZN13GUIBattleItem4InitEiiRK7GUIRect, 719024)
    off(_ZN13GUIBattleItem11SetSelectedEb, 719792)
    off(_ZN13GUIBattleListC2Ev, 719808)
    off(_ZN13GUIBattleList11ResetSelectEv, 721024)
    off(_ZN13GUIBattleList15ResetTouchStateEv, 721200)
    off(_ZN13GUIBattleList10GelSelItemEff, 721248)
    off(_ZN13GUIBattleItem7OnEventERK5Event, 721408)
    off(_ZN13GUIBattleList7OnEventERK5Event, 722080)
    off(_ZN14GUICountryItem8OnUpdateEf, 722832)
    off(_ZN14GUICountryItemD2Ev, 722848)
    off(_ZN14GUICountryItemD1Ev, 722848)
    off(_ZN14GUICountryItemD0Ev, 722960)
    off(_ZN14GUICountryItem8OnRenderEv, 723008)
    off(_ZN14GUICountryListD2Ev, 724704)
    off(_ZN14GUICountryListD1Ev, 724704)
    off(_ZN14GUICountryListD0Ev, 724784)
    off(_ZN14GUICountryList8OnUpdateEf, 724832)
    off(_ZN14GUICountryItemC2Ev, 725440)
    off(_ZN14GUICountryItemC1Ev, 725440)
    off(_ZN14GUICountryItem4InitEPKcS1_RK7GUIRect, 725504)
    off(_ZN14GUICountryItem11SetSelectedEb, 725808)
    off(_ZN14GUICountryListC2Ev, 725824)
    off(_ZN14GUICountryList11ResetSelectEv, 725952)
    off(_ZN14GUICountryList15ResetTouchStateEv, 726160)
    off(_ZN14GUICountryList10GelSelItemEff, 726208)
    off(_ZN14GUICountryItem7OnEventERK5Event, 726336)
    off(_ZN14GUICountryList9SetSelectEi, 726672)
    off(_ZN14GUICountryList7OnEventERK5Event, 727872)
    off(_ZN9GUIButtonD1Ev, 728624)
    off(_ZN9GUIButtonD0Ev, 728880)
    off(_ZN9GUIButton7SetGlowEPKc, 730512)
    off(_ZN6ecText9GetHeightEv, 939696)
    off(_ZN9GUIButton7SetTextEPKt, 731024)
    off(_ZN6ecText7SetTextEPKt, 940432)
    off(_ZN9GUIButton8SetAlphaEf, 731232)
    off(_ZN10GUIElementC1Ev, 731712)
    off(_ZN10GUIElement11RemoveChildEPS_, 731952)
    off(_ZN10GUIElementD1Ev, 732304)
    off(_ZN10GUIElementD0Ev, 732352)
    off(_ZN10GUIElement4MoveEff, 732608)
    off(_ZN10GUIElement11CheckInRectEffRK7GUIRect, 733008)
    off(_ZN10GUIElement10SetVisibleEb, 733088)
    off(_ZN10GUIElement12FindByHandleEm, 733216)
    off(_ZN10GUIElement9PostEventERK5Event, 733312)
    off(_ZN10GUIElement6RenderEv, 733440)
    off(_ZN10GUIElement6UpdateEf, 733568)
    off(_ZN8GUIImageD2Ev, 733680)
    off(_ZN8GUIImageD1Ev, 733680)
    off(_ZN8GUIImageD0Ev, 733792)
    off(_ZN8GUIImage8OnRenderEv, 733840)
    off(_ZN8GUIImageC2Ev, 734048)
    off(_ZN8GUIImage8SetAlphaEf, 734608)
    off(_ZN10GUIManager7OnEventERK5Event, 735232)
    off(_ZN10GUIManagerD2Ev, 735296)
    off(_ZN10GUIManagerD1Ev, 735296)
    off(_ZN10GUIManagerD0Ev, 735440)
    off(_ZN10GUIManagerC2Ev, 735488)
    off(_ZN10GUIManagerC1Ev, 735488)
    off(_ZN12GUIScrollBarC1Ev, 741312)
    off(_ZN12GUIScrollBar4InitERK7GUIRectPKcS4_iiiii, 741584)
    off(_ZN16GUIMotionManagerD2Ev, 737504)
    off(_ZN16GUIMotionManagerD1Ev, 737504)
    off(_ZN16GUIMotionManagerC2Ev, 737520)
    off(_ZN16GUIMotionManagerC1Ev, 737520)
    off(_ZN16GUIMotionManager9SetMotionEmffffft, 738240)
    off(_ZN16GUIMotionManager9AddMotionEP10GUIElementffffft, 738592)
    off(_ZN16GUIMotionManager10AddMotionXEP10GUIElementfft, 738960)
    off(_ZN16GUIMotionManager10AddMotionYEP10GUIElementfft, 739152)
    off(_ZN16GUIMotionManager8SetSpeedEmff, 739344)
    off(_ZN16GUIMotionManager15GetMotionActiveEm, 740176)
    off(_ZN14GUIRadioButtonD1Ev, 740208)
    off(_ZN14GUIRadioButtonD0Ev, 740256)
    off(_ZN14GUIRadioButton8OnRenderEv, 740304)
    off(_ZN12GUIScrollBarD2Ev, 741024)
    off(_ZN12GUIScrollBarD1Ev, 741024)
    off(_ZN12GUIScrollBarD0Ev, 741136)
    off(_ZN12GUIScrollBar8OnRenderEv, 741184)
    off(_ZN12GUIScrollBarC2Ev, 741312)
    off(_ZN12GUIScrollBar7OnEventERK5Event, 741904)
    off(_ZN7GUITextD2Ev, 742592)
    off(_ZN7GUITextD1Ev, 742592)
    off(_ZN7GUITextD0Ev, 742672)
    off(_ZN7GUIText8OnRenderEv, 742720)
    off(_ZN7GUITextC2Ev, 742848)
    off(_ZN7GUIText12SetTextColorEm, 743104)
    off(_ZN9ecGameKitC2Ev, 834928)
    off(_ZN9ecGameKitD2Ev, 834944)
    off(_ZN9ecGameKit7ReleaseEv, 834976)
    off(_ZN9ecGameKit22SendPacketToAllPlayersEPKvi, 835008)
    off(_ZN18ecSessionInterfaceC2Ev, 835104)
    off(_ZN18ecSessionInterfaceD2Ev, 835120)
    off(_ZN18ecSessionInterface7ReleaseEv, 835152)
    off(_ZN18ecSessionInterface10DisconnectEPKc, 835232)
    off(_ZN18ecSessionInterface20SendPacketToAllPeersEPKvi, 835296)
    off(_ZN11TiXmlString7reserveEj, 835376)
    off(_ZN11TiXmlString6assignEPKcj, 835680)
    off(_ZN11TiXmlString6appendEPKcj, 836032)
    off(_ZNK9TiXmlNode10ToDocumentEv, 836624)
    off(_ZNK9TiXmlNode9ToElementEv, 836640)
    off(_ZNK9TiXmlNode9ToCommentEv, 836656)
    off(_ZNK9TiXmlNode9ToUnknownEv, 836672)
    off(_ZNK9TiXmlNode6ToTextEv, 836688)
    off(_ZNK9TiXmlNode13ToDeclarationEv, 836704)
    off(_ZN9TiXmlNode10ToDocumentEv, 836720)
    off(_ZN9TiXmlNode9ToElementEv, 836736)
    off(_ZN9TiXmlNode9ToCommentEv, 836752)
    off(_ZN9TiXmlNode9ToUnknownEv, 836768)
    off(_ZN9TiXmlNode6ToTextEv, 836784)
    off(_ZN9TiXmlNode13ToDeclarationEv, 836800)
    off(_ZNK12TiXmlElement9ToElementEv, 836816)
    off(_ZN12TiXmlElement9ToElementEv, 836832)
    off(_ZNK12TiXmlComment9ToCommentEv, 836848)
    off(_ZN12TiXmlComment9ToCommentEv, 836864)
    off(_ZNK9TiXmlText6ToTextEv, 836880)
    off(_ZN9TiXmlText6ToTextEv, 836896)
    off(_ZNK16TiXmlDeclaration13ToDeclarationEv, 836912)
    off(_ZN16TiXmlDeclaration13ToDeclarationEv, 836928)
    off(_ZNK12TiXmlUnknown9ToUnknownEv, 836944)
    off(_ZN12TiXmlUnknown9ToUnknownEv, 836960)
    off(_ZNK12TiXmlComment9StreamOutEP14TiXmlOutStream, 836976)
    off(_ZNK12TiXmlUnknown9StreamOutEP14TiXmlOutStream, 837088)
    off(_ZNK12TiXmlComment5PrintEP7__sFILEi, 837216)
    off(_ZNK12TiXmlUnknown5PrintEP7__sFILEi, 837376)
    off(_ZNK16TiXmlDeclaration5PrintEP7__sFILEi, 837520)
    off(_ZN9TiXmlBase9PutStringERK11TiXmlStringPS0_, 837760)
    off(_ZN9TiXmlBase9PutStringERK11TiXmlStringP14TiXmlOutStream, 838368)
    off(_ZNK9TiXmlText9StreamOutEP14TiXmlOutStream, 838544)
    off(_ZNK16TiXmlDeclaration9StreamOutEP14TiXmlOutStream, 838688)
    off(_ZNK9TiXmlText5PrintEP7__sFILEi, 839040)
    off(_ZN9TiXmlBase14StringToBufferC2ERK11TiXmlString, 839408)
    off(_ZN9TiXmlBase14StringToBufferC1ERK11TiXmlString, 839408)
    off(_ZN9TiXmlBase14StringToBufferD2Ev, 839488)
    off(_ZN9TiXmlBase14StringToBufferD1Ev, 839488)
    off(_ZN9TiXmlNodeC2ENS_8NodeTypeE, 839536)
    off(_ZN9TiXmlNodeC1ENS_8NodeTypeE, 839536)
    off(_ZN9TiXmlNodeD1Ev, 839648)
    off(_ZN12TiXmlUnknownD2Ev, 839760)
    off(_ZN12TiXmlUnknownD1Ev, 839760)
    off(_ZN12TiXmlUnknownD0Ev, 839808)
    off(_ZN16TiXmlDeclarationD2Ev, 839872)
    off(_ZN16TiXmlDeclarationD1Ev, 839872)
    off(_ZN9TiXmlTextD2Ev, 839984)
    off(_ZN9TiXmlTextD1Ev, 839984)
    off(_ZN9TiXmlTextD0Ev, 840032)
    off(_ZN12TiXmlCommentD2Ev, 840096)
    off(_ZN12TiXmlCommentD1Ev, 840096)
    off(_ZN12TiXmlCommentD0Ev, 840144)
    off(_ZN16TiXmlDeclarationD0Ev, 840208)
    off(_ZN9TiXmlNodeD0Ev, 840336)
    off(_ZNK9TiXmlNode6CopyToEPS_, 840384)
    off(_ZN9TiXmlNode5ClearEv, 840480)
    off(_ZN9TiXmlNode14InsertEndChildERKS_, 840608)
    off(_ZN9TiXmlNode17InsertBeforeChildEPS_RKS_, 840672)
    off(_ZN9TiXmlNode16InsertAfterChildEPS_RKS_, 840768)
    off(_ZN9TiXmlNode12ReplaceChildEPS_RKS_, 840864)
    off(_ZN9TiXmlNode11RemoveChildEPS_, 840992)
    off(_ZNK9TiXmlNode10FirstChildEPKc, 841088)
    off(_ZNK9TiXmlNode9LastChildEPKc, 841280)
    off(_ZN9TiXmlNode9LastChildEPKc, 841376)
    off(_ZNK9TiXmlNode15IterateChildrenEPKS_, 841472)
    off(_ZN9TiXmlNode15IterateChildrenEPS_, 841504)
    off(_ZNK9TiXmlNode11NextSiblingEPKc, 841536)
    off(_ZNK9TiXmlNode15IterateChildrenEPKcPKS_, 841632)
    off(_ZN9TiXmlNode11NextSiblingEPKc, 841712)
    off(_ZN9TiXmlNode15IterateChildrenEPKcPS_, 841808)
    off(_ZNK9TiXmlNode15PreviousSiblingEPKc, 841888)
    off(_ZN9TiXmlNode15PreviousSiblingEPKc, 841984)
    off(_ZNK9TiXmlNode17FirstChildElementEv, 842080)
    off(_ZN9TiXmlNode17FirstChildElementEv, 842160)
    off(_ZNK9TiXmlNode17FirstChildElementEPKc, 842240)
    off(_ZN9TiXmlNode17FirstChildElementEPKc, 842352)
    off(_ZNK9TiXmlNode18NextSiblingElementEv, 842464)
    off(_ZN9TiXmlNode18NextSiblingElementEv, 842544)
    off(_ZNK9TiXmlNode18NextSiblingElementEPKc, 842624)
    off(_ZN9TiXmlNode18NextSiblingElementEPKc, 842736)
    off(_ZNK9TiXmlNode11GetDocumentEv, 842848)
    off(_ZN9TiXmlNode11GetDocumentEv, 842912)
    off(_ZNK12TiXmlElement7GetTextEv, 842976)
    off(_ZN13TiXmlDocumentC2Ev, 843024)
    off(_ZN13TiXmlDocumentC1Ev, 843024)
    off(_ZN13TiXmlDocumentC2EPKc, 843216)
    off(_ZN13TiXmlDocument8LoadFileEP7__sFILE13TiXmlEncoding, 843456)
    off(_ZN13TiXmlDocument8SetErrorEiPKcP16TiXmlParsingData13TiXmlEncoding, 858192)
    off(_ZN13TiXmlDocument8LoadFileEPKc13TiXmlEncoding, 844160)
    off(_ZNK13TiXmlDocument8SaveFileEP7__sFILE, 844544)
    off(_ZNK13TiXmlDocument8SaveFileEPKc, 844672)
    off(_ZNK13TiXmlDocument6CopyToEPS_, 844928)
    off(_ZN13TiXmlDocumentC2ERKS_, 845072)
    off(_ZN13TiXmlDocumentC1ERKS_, 845072)
    off(_ZN13TiXmlDocumentaSERKS_, 845216)
    off(_ZNK13TiXmlDocument5CloneEv, 845280)
    off(_ZNK13TiXmlDocument5PrintEP7__sFILEi, 845376)
    off(_ZNK13TiXmlDocument9StreamOutEP14TiXmlOutStream, 845488)
    off(_ZNK14TiXmlAttribute4NextEv, 845552)
    off(_ZNK12TiXmlElement5PrintEP7__sFILEi, 845600)
    off(_ZNK12TiXmlElement9StreamOutEP14TiXmlOutStream, 846208)
    off(_ZN14TiXmlAttribute4NextEv, 846608)
    off(_ZNK14TiXmlAttribute8PreviousEv, 846640)
    off(_ZN14TiXmlAttribute8PreviousEv, 846672)
    off(_ZNK14TiXmlAttribute5PrintEP7__sFILEi, 846720)
    off(_ZNK14TiXmlAttribute9StreamOutEP14TiXmlOutStream, 847104)
    off(_ZNK14TiXmlAttribute13QueryIntValueEPi, 847408)
    off(_ZNK14TiXmlAttribute16QueryDoubleValueEPd, 847488)
    off(_ZN14TiXmlAttribute11SetIntValueEi, 847568)
    off(_ZN14TiXmlAttribute14SetDoubleValueEd, 847744)
    off(_ZNK14TiXmlAttribute8IntValueEv, 847936)
    off(_ZNK14TiXmlAttribute11DoubleValueEv, 847984)
    off(_ZNK12TiXmlComment6CopyToEPS_, 848032)
    off(_ZN12TiXmlCommentC2ERKS_, 848080)
    off(_ZN12TiXmlCommentC1ERKS_, 848080)
    off(_ZN12TiXmlCommentaSERKS_, 848176)
    off(_ZNK12TiXmlComment5CloneEv, 848240)
    off(_ZNK9TiXmlText6CopyToEPS_, 848352)
    off(_ZNK9TiXmlText5CloneEv, 848416)
    off(_ZN16TiXmlDeclarationC2EPKcS1_S1_, 848576)
    off(_ZN16TiXmlDeclarationC1EPKcS1_S1_, 848576)
    off(_ZNK16TiXmlDeclaration6CopyToEPS_, 848832)
    off(_ZN16TiXmlDeclarationC2ERKS_, 848960)
    off(_ZN16TiXmlDeclarationC1ERKS_, 848960)
    off(_ZN16TiXmlDeclarationaSERKS_, 849136)
    off(_ZNK16TiXmlDeclaration5CloneEv, 849200)
    off(_ZNK12TiXmlUnknown6CopyToEPS_, 849328)
    off(_ZNK12TiXmlUnknown5CloneEv, 849376)
    off(_ZN17TiXmlAttributeSetC2Ev, 849488)
    off(_ZN17TiXmlAttributeSetC1Ev, 849488)
    off(_ZN17TiXmlAttributeSetD2Ev, 849568)
    off(_ZN17TiXmlAttributeSetD1Ev, 849568)
    off(_ZN12TiXmlElementC2EPKc, 849664)
    off(_ZN17TiXmlAttributeSet3AddEP14TiXmlAttribute, 849824)
    off(_ZN17TiXmlAttributeSet6RemoveEP14TiXmlAttribute, 849856)
    off(_ZN12TiXmlElement9ClearThisEv, 849936)
    off(_ZN12TiXmlElementD2Ev, 850016)
    off(_ZN12TiXmlElementD1Ev, 850016)
    off(_ZN12TiXmlElementD0Ev, 850096)
    off(_ZNK17TiXmlAttributeSet4FindERK11TiXmlString, 850144)
    off(_ZNK12TiXmlElement9AttributeEPKcPi, 850672)
    off(_ZNK12TiXmlElement9AttributeEPKcPd, 850768)
    off(_ZN17TiXmlAttributeSet4FindERK11TiXmlString, 851680)
    off(_ZN12TiXmlElement15RemoveAttributeEPKc, 851808)
    off(_ZNK12TiXmlElement6CopyToEPS_, 853408)
    off(_ZN12TiXmlElementC2ERKS_, 853584)
    off(_ZN12TiXmlElementC1ERKS_, 853584)
    off(_ZN12TiXmlElementaSERKS_, 853728)
    off(_ZNK12TiXmlElement5CloneEv, 853792)
    off(_ZNK11TiXmlHandle10FirstChildEv, 853936)
    off(_ZNK11TiXmlHandle10FirstChildEPKc, 853968)
    off(_ZNK11TiXmlHandle17FirstChildElementEv, 854048)
    off(_ZNK11TiXmlHandle17FirstChildElementEPKc, 854128)
    off(_ZNK11TiXmlHandle5ChildEi, 854208)
    off(_ZNK11TiXmlHandle5ChildEPKci, 854272)
    off(_ZNK11TiXmlHandle12ChildElementEi, 854400)
    off(_ZNK11TiXmlHandle12ChildElementEPKci, 854528)
    off(_ZN12TiXmlElement5ParseEPKcP16TiXmlParsingData13TiXmlEncoding, 863696)
    off(_ZN12TiXmlComment5ParseEPKcP16TiXmlParsingData13TiXmlEncoding, 860768)
    off(_ZN9TiXmlText5ParseEPKcP16TiXmlParsingData13TiXmlEncoding, 861056)
    off(_ZN16TiXmlDeclaration5ParseEPKcP16TiXmlParsingData13TiXmlEncoding, 861744)
    off(_ZN12TiXmlUnknown5ParseEPKcP16TiXmlParsingData13TiXmlEncoding, 860384)
    off(_ZNK13TiXmlDocument10ToDocumentEv, 854656)
    off(_ZN13TiXmlDocument10ToDocumentEv, 854672)
    off(_ZN14TiXmlAttributeD2Ev, 854688)
    off(_ZN14TiXmlAttributeD1Ev, 854688)
    off(_ZN13TiXmlDocumentD2Ev, 854784)
    off(_ZN13TiXmlDocumentD1Ev, 854784)
    off(_ZN13TiXmlDocumentD0Ev, 854864)
    off(_ZN14TiXmlAttributeD0Ev, 854944)
    off(_ZN9TiXmlBase18ConvertUTF32ToUTF8EmPcPi, 855040)
    off(_ZN9TiXmlBase7IsAlphaEh13TiXmlEncoding, 855312)
    off(_ZN9TiXmlBase10IsAlphaNumEh13TiXmlEncoding, 855360)
    off(_ZN16TiXmlParsingData5StampEPKc13TiXmlEncoding, 855408)
    off(_ZN9TiXmlBase14SkipWhiteSpaceEPKc13TiXmlEncoding, 855728)
    off(_ZN9TiXmlBase8ReadNameEPKcP11TiXmlString13TiXmlEncoding, 855968)
    off(_ZN9TiXmlBase9GetEntityEPKcPcPi13TiXmlEncoding, 856224)
    off(_ZN9TiXmlBase11StringEqualEPKcS1_b13TiXmlEncoding, 856960)
    off(_ZN9TiXmlBase8ReadTextEPKcP11TiXmlStringbS1_b13TiXmlEncoding, 857216)
    off(_ZN14TiXmlAttribute5ParseEPKcP16TiXmlParsingData13TiXmlEncoding, 858368)
    off(_ZN9TiXmlNode8IdentifyEPKc13TiXmlEncoding, 859040)
    off(_ZN13TiXmlDocument5ParseEPKcP16TiXmlParsingData13TiXmlEncoding, 859696)
    off(_ZNK9TiXmlText5BlankEv, 863008)
    off(_ZN12TiXmlElement9ReadValueEPKcP16TiXmlParsingData13TiXmlEncoding, 863168)
    off(_ZNK9hgeVector5AngleEPKS_, 905136)
    off(_ZN7ecImageD2Ev, 905600)
    off(_ZN7ecImage4InitEP9ecTextureffff, 905616)
    off(_ZN7ecImageC2EP9ecTextureffff, 905872)
    off(_ZN7ecImageC2EP9ecTextureRK13ecTextureRect, 905968)
    off(_ZN7ecImageC2EP11ecImageAttr, 906096)
    off(_ZN7ecImage13RenderStretchEffff, 907456)
    off(_ZN7ecImage8Render4VEffffffff, 907648)
    off(_ZN7ecImage10SetTextureEP9ecTexture, 908944)
    off(_ZN7ecImage7SetFlipEbbb, 909376)
    off(_ZN7ecImage14SetTextureRectEffff, 909744)
    off(_ZN7ecImage14SetTextureRectERK13ecTextureRect, 909952)
    off(_ZN12ecTextureResC2Ev, 910144)
    off(_ZN12ecTextureRes14ReleaseTextureEP9ecTexture, 910224)
    off(_ZN12ecTextureResD2Ev, 910896)
    off(_ZN12ecTextureRes10GetTextureEPKc, 911872)
    off(_ZN12ecTextureRes13CreateTextureEPKcbbb, 912880)
    off(_ZN12ecTextureRes11CreateImageEPKcP9ecTextureffffff, 914800)
    off(_ZN12ecTextureRes11CreateImageEPKcS1_ffffff, 917632)
    off(_ZN11ecEffectResC2Ev, 919136)
    off(_ZN11ecEffectResC1Ev, 919136)
    off(_ZN11ecEffectRes7ReleaseEv, 919184)
    off(_ZN11ecEffectResD2Ev, 919296)
    off(_ZN11ecEffectResD1Ev, 919296)
    off(_ZN11ecEffectRes10LoadEffectEPKcP12ecTextureRes, 919360)
    off(_ZN18ecEffectResManager16ReleaseEffectResEP11ecEffectRes, 923840)
    off(_ZN18ecEffectResManagerC2Ev, 924304)
    off(_ZN18ecEffectResManagerC1Ev, 924304)
    off(_ZN18ecEffectResManagerD2Ev, 924544)
    off(_ZN18ecEffectResManagerD1Ev, 924544)
    off(_ZN18ecEffectResManager16ReleaseEffectResEPKc, 925312)
    off(_ZN8ecEffectC2Ev, 927728)
    off(_ZN8ecEffectC1Ev, 927728)
    off(_ZN8ecEffectD2Ev, 927776)
    off(_ZN8ecEffect4InitEPKcP9TFreeListI16ecParticleSystemE, 927920)
    off(_ZN16ecParticleSystem4InitEP13ecEmitterAttr, 940832)
    off(_ZN16ecParticleSystem6FireAtEfff, 941232)
    off(_ZN8ecEffect4FireEv, 928240)
    off(_ZN16ecParticleSystem4FireEv, 940960)
    off(_ZN8ecEffect4StopEb, 928304)
    off(_ZN16ecParticleSystem4StopEb, 940976)
    off(_ZN8ecEffect6MoveToEffb, 928384)
    off(_ZN16ecParticleSystem6MoveToEffb, 941024)
    off(_ZN16ecParticleSystem6UpdateEf, 941792)
    off(_ZN16ecParticleSystem6RenderEv, 941344)
    off(_ZN16ecParticleSystem6IsLiveEv, 945312)
    off(_ZN15ecEffectManagerC2Ev, 928736)
    off(_ZN16ecParticleSystemC1Ev, 940704)
    off(_ZN16ecParticleSystemD1Ev, 940816)
    off(_ZN15ecEffectManagerC1Ev, 928736)
    off(_ZN15ecEffectManagerD2Ev, 929664)
    off(_ZN15ecEffectManagerD1Ev, 929664)
    off(_ZN9ecUniFontC2Ev, 930096)
    off(_ZN9ecUniFont12GetCharImageEt, 930160)
    off(_ZN9ecUniFontD2Ev, 930592)
    off(_ZN11ecLabelTextC2Ev, 933104)
    off(_ZN11ecLabelTextD2Ev, 933152)
    off(_ZN11ecLabelText8SetAlphaEf, 933744)
    off(_ZN10CCSoundBoxC2Ev, 933936)
    off(_ZN10CCSoundBoxC1Ev, 933936)
    off(_ZN10CCSoundBoxD2Ev, 933984)
    off(_ZN10CCSoundBoxD1Ev, 933984)
    off(_ZN10CCSoundBox15InitSoundSystemEv, 934128)
    off(_ZN10CCSoundBox18DestroySoundSystemEv, 934256)
    off(_ZN10CCSoundBox9StopMusicEv, 934480)
    off(_ZN10CCSoundBox9StopAllSEEv, 934816)
    off(_ZN13ecStringTableC2Ev, 934864)
    off(_ZN13ecStringTableD2Ev, 935968)
    off(_ZN6ecTextC2Ev, 938752)
    off(_ZN6ecTextD2Ev, 938784)
    off(_ZN6ecText11GetNumLinesEv, 939840)
    off(_Z22ecSetIdleTimerDisabledb, 940672)
    off(_ZN16ecParticleSystemC2Ev, 940704)
    off(_ZN16ecParticleSystemD2Ev, 940816)
    off(_ZN9ecLibraryC2Ev, 1257216)
    off(_ZN9ecLibrary11GetItemDataEi, 1257296)
    off(_ZN9ecLibrary12FindItemDataEPKc, 1257328)
    off(_ZN9ecLibrary14GetElementDataEi, 1257696)
    off(_ZN9ecLibrary12GetFrameDataEi, 1257744)
    off(_ZN9ecLibrary12GetLayerDataEi, 1257776)
    off(_ZN9ecLibrary11GetItemNameEm, 1257792)
    off(_ZN9ecLibraryD2Ev, 1258016)
    off(_ZN7ecShapeD1Ev, 1266064)
    off(_ZN9ecLibraryD1Ev, 1258016)
    off(_ZN9ecLibraryD0Ev, 1258336)
    off(_Z13ecLoadLibraryPKcR13ecLibraryData, 1260832)
    off(_ZN7ecShapeC1Ev, 1266048)
    off(_ZN7ecShape4InitEP9ecTextureffff, 1266080)
    off(_Z14ecSaveLibrarayPKcR13ecLibraryDataS0_i, 1261840)
    off(_ZN9ecElementC2Ev, 1262496)
    off(_ZN9ecElementD2Ev, 1262560)
    off(_ZN9ecElement4InitEP10ecItemDataP9ecLibrary, 1262816)
    off(_ZN7ecLayerC1Ev, 1266784)
    off(_ZN7ecFrameC1Ev, 1267792)
    off(_ZN7ecLayer4InitEiP11ecLayerDataP7ecFrameP9ecElementP9ecLibrary, 1267104)
    off(_ZN7ecLayer11SetCurFrameEi, 1267312)
    off(_ZN9ecElement5ResetEv, 1263840)
    off(_ZN7ecLayer4PlayEv, 1266944)
    off(_ZN9ecElement4StopEv, 1264064)
    off(_ZN7ecLayer4StopEv, 1267008)
    off(_ZN7ecLayer7SetLoopEi, 1267072)
    off(_ZN9ecElement4InitEP13ecElementDataP9ecLibrary, 1264304)
    off(_ZN9ecElement9ResetItemEP10ecItemDataP9ecLibrary, 1264416)
    off(_ZN9ecElement10ChangeItemEP10ecItemDataS1_P9ecLibrary, 1264768)
    off(_ZN7ecLayer10ChangeItemEP10ecItemDataS1_P9ecLibrary, 1266816)
    off(_ZN9ecElement10ChangeItemEPKcS1_P9ecLibrary, 1264928)
    off(_ZN7ecShape8SetColorEm, 1266688)
    off(_ZN7ecShape6RenderERK7ecMtx32, 1266304)
    off(_ZN7ecLayer6RenderERK7ecMtx32, 1267440)
    off(_ZN9ecElement9NextFrameEv, 1265728)
    off(_ZN7ecLayer9NextFrameEv, 1267504)
    off(_ZN7ecShapeC2Ev, 1266048)
    off(_ZN7ecShapeD2Ev, 1266064)
    off(_ZN7ecLayerD2Ev, 1266720)
    off(_ZN7ecLayerD1Ev, 1266720)
    off(_ZN7ecLayerD0Ev, 1266736)
    off(_ZN7ecLayerC2Ev, 1266784)
    off(_ZN7ecFrame10ChangeItemEP10ecItemDataS1_P9ecLibrary, 1268096)
    off(_ZN7ecFrame4PlayEv, 1268480)
    off(_ZN7ecFrame4StopEv, 1268608)
    off(_ZN7ecFrame4InitEP11ecFrameDataP9ecElementP9ecLibrary, 1267840)
    off(_ZN7ecFrame6RenderERK7ecMtx32, 1268224)
    off(_ZN7ecFrame9NextFrameEv, 1268352)
    off(_ZN7ecFrame5ResetEv, 1267968)
    off(_ZN7ecFrameD2Ev, 1267728)
    off(_ZN7ecFrameD1Ev, 1267728)
    off(_ZN7ecFrameD0Ev, 1267744)
    off(_ZN7ecFrameC2Ev, 1267792)
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

plt(_ZN10ecGraphics12RenderCircleEfffm)

plt(_ZN10ecGraphics4FadeEf)

plt(_ZN10ecGraphicsD2Ev)

plt(_ZN10ecGraphicsD1Ev)

plt(_ZN10ecGraphics11LoadTextureEPKc)

plt(_Z13ecTextureLoadPKcRiS1_Rj)

plt(_ZN10ecGraphics15LoadWEBPTextureEPKc)

plt(_Z17ecWEBPTextureLoadPKcRiS1_Rj)

plt(_ZN10ecGraphics14LoadETCTextureEPKc)

plt(_Z16ecETCTextureLoadPKcRiS1_Rj)

plt(_ZN10ecGraphics14LoadPVRTextureEPKc)

plt(_Z16ecPVRTextureLoadPKcRiS1_Rj)

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

plt(_ZN13CFightTextMgr7AddTextEffPKcm)

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

plt(_ZN10CFightText8SetColorEm)

plt(_ZN6ecText8SetColorEm)

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

Thn(N10CGameStateD1Ev, 12)

plt(_ZN10CGameStateD0Ev)

Thn(N10CGameStateD0Ev, 12)

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

plt(_ZN16GUIMotionManager12ActiveMotionEmh)

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

plt(_ZN11GUICardListC1Ev)

plt(_ZN11GUICardList4InitERK7GUIRecti)

plt(_ZN7ecImageC1EP9ecTextureRK13ecTextureRect)

plt(_ZN10GUIBuyCard15SetSelCardIntroEv)

plt(_ZN10CObjectDef10GetCardDefE7CARD_ID)

plt(_ZN8CCountry10CanBuyCardEP7CardDef)

plt(_ZN7GUICard13SetPriceColorEm)

plt(_ZN8CCountry16IsEnoughIndustryEP7CardDef)

plt(_ZN7GUICard16SetIndustryColorEm)

plt(_ZN8CCountry12GetCardPriceEP7CardDef)

plt(_ZN8CCountry15GetCardIndustryEP7CardDef)

plt(_ZN11GUICardList7GetCardEi)

plt(_ZN8CCountry13IsEnoughMoneyEP7CardDef)

plt(_ZN10GUIElement9SetEnableEb)

plt(_ZN8CCountry13GetCardRoundsE7CARD_ID)

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

plt(_ZN11GUIMainMenu13RefreshNewTipEv)

plt(_ZN10GUILoadingC1Ev)

plt(_ZN10GUILoading4InitERK7GUIRect)

plt(_ZN11GUIMainMenu6ShowADEv)

plt(_ZN14CPlayerManager12SetupSessionEb)

plt(_ZN16GUILockedWarningC1Ev)

plt(_ZN16GUILockedWarning4InitERK7GUIRect)

plt(_ZN10GUIServiceC1Ev)

plt(_ZN10GUIService4InitERK7GUIRect)

plt(_ZN12GUICommanderC1Ev)

plt(_ZN12GUICommander4InitERK7GUIRect)

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

Thn(N10CMenuState7OnEventERK5Event, 12)

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

Thn(N14CPlayerManager16onAcceptedInviteEv, 4)

plt(_ZN14CPlayerManager10FindPlayerEPKc)

plt(_ZN14CPlayerManager20onPlayerInfoReceivedERSt4listIP12ecPlayerInfoSaIS2_EE)

Thn(N14CPlayerManager20onPlayerInfoReceivedERSt4listIP12ecPlayerInfoSaIS2_EE, 4)

plt(_ZN14CPlayerManager12onMatchFoundEv)

plt(_ZN9ecGameKit18GetMatchPlayerListERSt4listISsSaISsEE)

Thn(N14CPlayerManager12onMatchFoundEv, 4)

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

Thn(N14CPlayerManager20onPlayerDisconnectedEPKc, 4)

plt(_ZN14CPlayerManager12GetCorpsDataERi)

plt(_ZN14CPlayerManager15onPeerConnectedEPKc)

plt(_ZN14CPlayerManager12onStartMatchEv)

plt(_ZN9ecGameKit18GetLocalPlayerInfoER12ecPlayerInfo)

plt(_ZN9ecGameKit19GetMatchPlayersInfoEv)

Thn(N14CPlayerManager12onStartMatchEv, 4)

plt(_ZN14CPlayerManager14SetCorpsByDataEPviP7CPlayer)

plt(_ZN14CPlayerManager17IsAllPlayersReadyEv)

plt(_ZN14CPlayerManager23RefreshAndSendCorpsDataEv)

plt(_ZN14CPlayerManager18onPeerDisconnectedEPKc)

plt(_ZN14CPlayerManager14SendRoundBeginEv)

plt(_ZN14CPlayerManager16ClearActionQueueEv)

plt(_ZN7CPlayer9SendFirstEv)

plt(_ZN14CPlayerManager14onReceivedDataEPKviPKcb)

plt(_ZN7CPlayer7SendAckEi)

plt(_ZN7CPlayer7RecvAckEi)

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

plt(_ZN11TiXmlString7reserveEj)

plt(_ZN11TiXmlString6assignEPKcj)

plt(_ZN11TiXmlString6appendEPKcj)

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

plt(_ZN9ecLibrary11GetItemNameEm)

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

plt(_ZN7ecShape8SetColorEm)

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
