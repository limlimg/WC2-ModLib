#include <stddef.h>
#include <dlfcn.h>
#include "easytech.h"

#define got(name) __attribute__((visibility("hidden"))) size_t easytech(name) = (size_t)lazybind;
#define bss(name, size) __attribute__((weak)) __attribute__((visibility("protected"))) char name[size];

#define plt(name) __attribute__((weak)) __attribute__((visibility("protected"))) void name() {asm(\
        "adr x16, #16\n\t"\
        "ldr x17, [x16]\n\t"\
        "ldr x8, [x16, x17]\n\t"\
        "br x8\n\t"\
        ".quad "__easytech(name)" - .");}

#define Thn(name, offset) __attribute__((weak)) __attribute__((visibility("protected"))) void _ZThn##offset##_##name() {asm(\
        "sub x0, x0, #"#offset"\n\t"\
        "b _Z"#name"\n\t");}

#define off(name, offset) easytech(name) = BaseAddress + offset;

const char GameLib[] = "libeasytech.so";

void __attribute__((visibility("hidden"))) lazybind() {
    asm(
    "SUB SP, SP, #0xA0\n\t"
    "STP D7, D6, [SP, #0x0]\n\t"
    "STP D5, D4, [SP, #0x10]\n\t"
    "STP D3, D2, [SP, #0x20]\n\t"
    "STP D1, D0, [SP, #0x30]\n\t"
    "STP X7, X6, [SP, #0x40]\n\t"
    "STP X5, X4, [SP, #0x50]\n\t"
    "STP X3, X2, [SP, #0x60]\n\t"
    "STP X1, X0, [SP, #0x70]\n\t"
    "STP X16, X17, [SP, #0x80]\n\t"
    "STP X29, X30, [SP, #0x90]\n\t"
    "ADD x29, SP, #0x90\n\t"
    "bl resolvesymbol\n\t"
    "LDP X29, X30, [SP, #0x90]\n\t"
    "LDP X16, X17, [SP, #0x80]\n\t"
    "LDP X1, X0, [SP, #0x70]\n\t"
    "LDP X3, X2, [SP, #0x60]\n\t"
    "LDP X5, X4, [SP, #0x50]\n\t"
    "LDP X7, X6, [SP, #0x40]\n\t"
    "LDP D1, D0, [SP, #0x30]\n\t"
    "LDP D3, D2, [SP, #0x20]\n\t"
    "LDP D5, D4, [SP, #0x10]\n\t"
    "LDP D7, D6, [SP, #0x0]\n\t"
    "ADD SP, SP, #0xA0\n\t"
    "ldr x8, [x16, x17]\n\t"
    "br x8\n\t");
}

got(_ZN11GUISaveItemC2Ev)

got(_ZN7ecLayer9NextFrameEv)

got(_ZN11GUIWarMedal8OnUpdateEf)

got(_ZN7ecImageC2EP9ecTextureffff)

got(_ZN7GUITechC1Ev)

got(_ZN14GUICorpsButton4InitERK7GUIRectPKcb)

got(_ZN6ecFile5CloseEv)

got(_ZN10GUILoading4InitERK7GUIRect)

got(_ZN12GUIScrollBarC2Ev)

got(_ZN13CActionAssist4isAIEi)

got(_ZN14GUICountryList8OnUpdateEf)

got(_ZN6CScene9IsBombingEv)

got(_ZN10CObjectDef16LoadUnitPositonsEv)

got(_ZN5CArea10GetRealTaxEv)

got(_ZN13TiXmlDocument10ToDocumentEv)

got(_ZN15ecMultipleTouchC2Ev)

got(_ZN14GUICountryList4InitERK7GUIRecti)

got(_ZN10CCSoundBox15InitSoundSystemEv)

got(_ZN14GUIRadioButtonD0Ev)

got(_ZN14GUICorpsButton13SetPlayerNameEPKcbS1_iib)
bss(g_GameRes, 1424)
bss(_psJavaVM, 8)

got(_ZN13CStateManager6UpdateEf)

got(_ZN13ecStringTableD1Ev)

got(_ZN7GUITechD0Ev)

got(_ZN12GUITutorails8OnUpdateEf)

got(_ZN8CCountry8DoActionEv)

got(_ZN16GUIUpgradeButtonD2Ev)

got(_ZN8GUIImageD0Ev)

got(_ZN11CBattleUnit6UpdateEf)

got(_ZN12GUIScrollBarD1Ev)

got(_ZN19GUIConnectHostStateD1Ev)

got(_ZN14CPlayerManager9ReconnectEv)

got(_ZN9CAreaMark7ReleaseEv)

got(_ZN16ecParticleSystemD2Ev)

got(_ZN14CPlayerManager16FindPlayerByUUIDEi)

got(_ZN11GUIHostListD1Ev)

got(_ZN14TiXmlAttribute8PreviousEv)

got(_ZN9TiXmlBase14StringToBufferC2ERK11TiXmlString)

got(_ZN15ecMultipleTouchD1Ev)

got(_ZN14CPlayerManager12RemovePlayerEP7CPlayer)

got(_Z16ecLaunchAppStorePKc)

got(_ZN11CBattleUnitD2Ev)

got(_ZN18ecSessionInterface11GetPeerNameEPKcRSs)

got(_ZN14GUIBattleIntroD2Ev)

got(_ZN6CScene15SetCameraToAreaEi)
bss(g_Scene, 352)

got(_ZN8GUIImageC1Ev)

got(_ZN10CObjectDef14ReleaseArmyDefEv)

got(_ZN14GUIExitWarningD1Ev)

got(_ZN11GUIButtonExC1Ev)

got(_ZN14CPlayerManager16PlayerLoadFinishEP7CPlayer)

got(_ZN12GUISmallCardD2Ev)

got(_ZN12TiXmlElementC2EPKc)

got(_ZN13GUISelCountryC2Ev)

got(_ZN7ecFrameC2Ev)

got(_ZN14CPlayerManager20onPlayerInfoReceivedERSt4listIP12ecPlayerInfoSaIS2_EE)

got(_ZN6ecFile18GetFileDataFromZipEPKcS1_Pm)

got(_ZN12CGameManager24MovePlayerCountryToFrontEv)

got(_ZN7ecLayerC1Ev)

got(_ZN11TiXmlString7reserveEm)

got(_ZN11GUIDefeated12ShowDefeatedEP8CCountry)

got(_ZN12GUISmallCard4InitERK7GUIRect)

got(_ZN9ecElement11GetPlayTimeEv)

got(_ZN6CScene17SetSelAreaTargetsEP5CArea)

got(_ZN11GUISaveItem7SetInfoEPKciiiiiiiib)

got(_ZN16TiXmlDeclarationD2Ev)

got(_ZN11GUICardListD0Ev)

got(_ZN14GUICountryListD1Ev)

got(_ZNK12TiXmlElement5PrintEP7__sFILEi)

got(_ZN6CFightC1Ev)

got(_ZN5CArmy4InitEP7ArmyDefP8CCountry)

got(_ZN7ecLayerD0Ev)

got(_ZN10ecGraphics4InitEiiiii)

got(_ZN17TiXmlAttributeSetC1Ev)

got(_ZN15GUIProductPriceC1Ev)

got(_ZN14CPlayerManager15onPeerConnectedEPKc)

got(_ZN10CCommander17SetNumBattleStarsEiii)

got(_ZN6ecFileC1Ev)

got(_ZN10GUIVictoryC2Ev)

got(_ZN14CPlayerManager17SendStartLoadGameEv)

got(_ZN12ecTextureResC1Ev)

got(_ZN14GUICorpsButtonD2Ev)

got(_ZN16ecParticleSystem6MoveToEffb)

got(_ZN9GUIBattleD1Ev)

got(_ZN8CCountry11SaveCountryEP15SaveCountryInfo)

got(_ZN7CPlayer15ClearPacketListEv)

got(_ZN7GUIGold4InitERK7GUIRect)

got(_ZN9TiXmlNode14InsertEndChildERKS_)

got(_ZN11GUIArmyItemD0Ev)

got(_ZN12ecTextureResD2Ev)

got(_ZN8CCountry15GetCardIndustryEP7CardDef)

got(_ZN9CAreaMark4InitEi)

got(_ZN5CArea18RevertArmyStrengthEi)

got(_ZN10GUIVictoryD1Ev)

got(_ZN12CGameManager15GetNumDialoguesEv)

got(_ZN6CScene8BombAreaEii)

got(_ZN9ecGameKit22DisconnectCurrentMatchEv)

got(_ZN14GUICountryItem4InitEPKcS1_RK7GUIRect)

got(_ZN18ecSessionInterface10SendPacketEPKviPKc)

got(_ZNK9TiXmlNode6CopyToEPS_)

got(_ZN8CGameRes18RenderUIDefendArmyEPKcffiiiiiiib)

got(_ZN10GUIElement9FreeChildEPS_)

got(_ZN11GUIHostList7OnEventERK5Event)

got(_Z19ecTextureWithStringPKcS0_iiRiS1_Rj)

got(_ZN10CBaseState8TouchEndEffi)

got(_ZN13TiXmlDocumentD0Ev)

got(_ZN9CActionAI15sortArmyToFrontEv)

got(_ZN6CScene12UnselectAreaEv)

got(_ZN12CGameManager7TurnEndEv)

got(_ZN10CLoadState6RenderEv)

got(_ZN10ecGraphics12RenderCircleEfffj)

got(_ZN12CGameManager12IsLastBattleEv)

got(_ZN9CActionAI13moveAndAttackEv)

got(_ZN12CBattleScene10StarEffectEi)

got(_ZN10GUIManager16UnloadTextureResEPKc)

got(_ZN13CTouchInertia13GetStartPointEv)

got(_ZN8CCountry12CollectTaxesEv)

got(_ZN6CScene19GetNumAdjacentAreasEi)

got(_ZN10GUIElement10GetAbsRectER7GUIRect)

got(_ZN9TiXmlBase8ReadNameEPKcP11TiXmlString13TiXmlEncoding)

got(_ZN14GUICountryList15ResetTouchStateEv)

got(_ZN9GUIButton7SetTextEPKc)

got(_ZN10GUINewGame8OnRenderEv)

got(_ZN10GUIService8OnRenderEv)

got(_ZN10ecGraphics11FreeTextureEP9ecTexture)

got(_ZNK12TiXmlElement5CloneEv)

got(_ZN10CGameStateD0Ev)

got(_ZN16ecParticleSystem4InitEP13ecEmitterAttr)

got(_ZN7GUICardC2Ev)

got(_ZN10GUIBuyCard8OnRenderEv)

got(_ZN11GUIHostItemC2Ev)

got(_ZN11GUILevelSelD0Ev)

got(_ZN10CObjectDef14GetUnitMotionsEPKcS1_)

got(_ZN5CArmy9SetMoraleEi)

got(_ZN11GUIHostList17ResetConnectStateEv)

got(_ZN11GUIHostList7AddHostEPKcS1_ii)

got(_ZN14CPlayerManager12GetLeftCorpsEi)

got(_ZN10ecGraphics8ShutdownEv)

got(_ZN10CCSoundBox6LoadSEEPKc)

got(_ZN16ecParticleSystem4StopEb)

got(_ZN11GUILevelSelC1Ev)

got(_ZN12CBattleScene9AddCraterEPKcfff)

got(_ZN11GUIWarMedal8SetLevelEi)

got(_ZNK9TiXmlNode10ToDocumentEv)

got(_ZN11GUIPauseBox4InitERK7GUIRect)

got(_ZN10CGameStateC1Ev)

got(_ZN10CObjectDef17GetCardTargetTypeEP7CardDef)

got(_ZN11GUIHostItemD1Ev)

got(_ZN13GUIBattleList10GelSelItemEff)

got(_ZN12CBattleScene12ClearEffectsEv)

got(_ZN14CPlayerManager10ClearCorpsEv)

got(_ZN12TiXmlCommentD0Ev)

got(_Z16GetBattleKeyNameiiPc)

got(_ZN8GUIMedal8SetMedalEi)

got(_ZN9CSoundResD1Ev)

got(_ZN10CCSoundBoxC1Ev)

got(_ZN7GUITechD2Ev)

got(_ZN9TiXmlNode17FirstChildElementEPKc)

got(_ZN6CScene25AdjacentAreasEncirclementEi)

got(_ZN11GUIHostListC2Ev)

got(_ZN7CCamera21IsRectInVisibleRegionEffff)

got(_ZN11GUIDialogue4InitERK7GUIRect)

got(_ZN18ecSessionInterface16AcceptInvitationEPKc)

got(_ZN14GUICountryItem8OnRenderEv)

got(_ZN10CGameState7OnEventERK5Event)

got(_ZNK9TiXmlText6CopyToEPS_)

got(_ZN14CPlayerManagerC2Ev)

got(_ZdlPv)

got(_ZN10GUIService4InitERK7GUIRect)

got(_ZN9GUIResult4InitERK7GUIRecti)

got(_ZN8CCountry19GetHighestValueAreaEv)

got(_ZN13CFightTextMgr6UpdateEf)

got(_ZN10CCommanderD2Ev)

got(_ZN13TiXmlDocumentC2ERKS_)

got(_ZN6CFight12SecondAttackEv)

got(_ZN11GUIDialogueC2Ev)

got(_ZN14GUICountryItemD0Ev)

got(_ZN12GUISelBattleD2Ev)

got(_ZN7ecShape8SetColorEj)

got(_ZN11GUIPauseBoxC1Ev)

got(_ZN9ecGameKitC1Ev)

got(_ZN11GUIHostList15RefreshHostListEv)

got(_ZN6CScene14ScreenToAreaIDEff)

got(_ZN5CArea10RemoveArmyEP5CArmy)

got(_ZN11ecLabelTextD1Ev)

got(_ZN6ecText7SetTextEPKc)

got(_ZN12TiXmlElement12SetAttributeEPKci)

got(_ZN6ecFile12CheckJavaDexEv)

got(_ZN5CArea11GetIndustryEv)

got(_ZN11CBattleUnit11IsAttackingEv)

got(_ZN11GUIWarMedal4InitERK7GUIRect11WARMEDAL_IDi)

got(_ZN11GUIDialogueD1Ev)

got(_ZN6CMedal5UpateEf)

got(_ZN3MD59transformEPKh)
bss(_ZN9CActionAI9_instanceE, 8)

got(_ZN10GUINewGameD2Ev)

got(_ZN12TiXmlElementD0Ev)

got(_ZN10CCSoundBox11ResumeMusicEv)

got(_ZN11GUICardList8ReSelectEv)

got(_ZN7GUIBank4InitERK7GUIRect)

got(_Z18ecAppWillTerminatev)

got(_ZN7GUIText7SetTextEPKc)

got(_ZN3MD5C2Ev)

got(_ZN15ecEffectManagerC1Ev)

got(_ZN11CMatchStateD0Ev)

got(_ZN6GUIEndD2Ev)

got(_ZN14GUIBattleIntroD0Ev)

got(_Znam)

got(_ZN10CLoadState9TouchMoveEffi)

got(_ZN10GUIOptionsD1Ev)

got(_ZN11GUICardListD2Ev)
bss(m_pTexture, 8)

got(_ZN13CTouchInertia8TouchEndEffi)

got(_ZN11GUIMainMenuD0Ev)

got(_ZN10GUIElement4ShowEv)

got(_ZN11GUIHostList4InitERK7GUIRect)

got(_ZN11GUIMainMenu4InitERK7GUIRect)

got(_ZN12GUISmallCardD0Ev)

got(_ZN12GUIAttackBox4InitERK7GUIRect)

got(_ZN9ecUniFontC2Ev)

got(_ZN13GUIMatchSetupD0Ev)

got(_ZN7ecImage8SetColorEmi)

got(_ZN10CObjectDef11LoadCardDefEv)

got(_ZN12GUISelBattleD0Ev)

got(_ZN18ecSessionInterfaceC1Ev)

got(_ZN8CCountry9TurnBeginEv)

got(_ZN12GUISelBattle4InitERK7GUIRectii)

got(_ZN10CCommander15GetUpgradeMedalEv)

got(_ZN12TiXmlElementC1ERKS_)

got(_ZN13CActionAssistD2Ev)

got(_ZN10GUIManager13SafeFreeChildEP10GUIElement)

got(_ZN13ecStringTableC1Ev)

got(_ZN9ecGameKit22SendPacketToAllPlayersEPKvi)

got(_ZN12GUIScrollBar12GetScrollPosEv)

got(_ZN10CObjectDef18ReleaseUnitMotionsEv)

got(_ZN13GUISelCountry8OnRenderEv)

got(_ZN11GUIMainMenuC1Ev)

got(_ZN10CFightTextD2Ev)

got(_ZN10CObjectDef4InitEv)

got(_ZN9TiXmlNode9ToElementEv)

got(_ZN9ecLibraryD2Ev)

got(_ZN10GUISelArmy7SetAreaEi)

got(_ZN6CScene8AirborneEi)

got(_ZN18ecEffectResManager13LoadEffectResEPKc)

got(_ZN10GUIBuyCard7OnEventERK5Event)

got(_ZN8CCountry15CanUseCommanderEv)

got(_ZN10GUISelArmy15MoveArmyToFrontEi)

got(_ZN14CPlayerManager13WillTerminateEv)

got(_ZN10GUIElement12FreeAllChildEv)

got(_Z13ecBackPressedv)

got(_ZN6GUITax8OnRenderEv)

got(_ZN6CScene8IsAdjoinEii)

got(_ZN13TiXmlDocumentC1ERKS_)

got(_ZN9ecLibraryC1Ev)

got(_ZN12CGameManager10InitBattleEv)

got(_ZN12CBattleScene6UpdateEf)

got(_ZN7CBomber4InitEv)

got(_ZNK12TiXmlComment5CloneEv)

got(_ZN13GUIAIProgress8OnRenderEv)

got(_ZN8GUIMedalC1Ev)

got(_ZN10GUIBuyCard15ResetCardTargetEv)

got(_ZN10CFightTextC1Ev)

got(_ZN5CArea7GetArmyEi)

got(_ZN5CArea8IsActiveEv)

got(_ZNK12TiXmlUnknown9StreamOutEP14TiXmlOutStream)

got(_ZN13GUIActionInfo7SetInfoEPKc)

got(_ZNK11TiXmlHandle12ChildElementEPKci)

got(_ZN12CGameManager12RealLoadGameEPKc)

got(_ZN16GUIUpgradeButton12SetNeedMedalEi)

got(_ZN10CCSoundBoxD2Ev)

got(_ZN12CGameManager16GetPlayerCountryEv)

got(_ZN13GUIMatchSetupC2Ev)

got(_ZN6ecText14GetStringWidthEib)

got(_ZN5CArea15MoveArmyToFrontEib)

got(_ZN11GUICardListC1Ev)

got(_ZN6CScene7GetAreaEi)

got(_ZN9TiXmlNode18NextSiblingElementEv)

got(_ZN7CCamera4MoveEffb)

got(_ZN10GUIElement4HideEv)

got(_ZN3MD56updateEPKvm)

got(_ZN12CGameManager8LoadGameEPKc)

got(_ZN7CBomber19AircraftCarrierBombEii)

got(_ZN10CGameState8InitGameEv)

got(_ZN12GUIScrollBar4InitERK7GUIRectPKcS4_iiiii)

got(_ZN8GUIMedal8OnRenderEv)

got(_ZN10CCommander8BuyMedalEi)

got(_ZN15ecMultipleTouch10TouchMovedEff)

got(_ZN14CPlayerManager21FindPlayerByCountryIDEPKc)

got(_ZN6GUITaxD2Ev)

got(_ZN6ecText8SetAlphaEf)

got(_ZN12TiXmlElementD2Ev)

got(_ZN10GUIElement8AddChildEPS_b)

got(_ZN11GUILevelSelD1Ev)

got(_ZN11GUILevelSelC2Ev)

got(_ZN12CBattleScene11IsAttackingEv)

got(_ZNK14TiXmlAttribute16QueryDoubleValueEPd)

got(_ZN12TiXmlUnknown9ToUnknownEv)

got(_ZlsR14TiXmlOutStreamRK9TiXmlNode)

got(_ZN12CBattleScene13SetBattleAreaEi)

got(_ZN8CGameRes12RenderArmyHPEffii)

got(_ZN6CScene13ScreenToSceneERfS0_)

got(_ZN16ecParticleSystem4FireEv)

got(_Z13HasUnitMotionPKci)

got(_ZN7ecImage4InitEP9ecTextureffff)

got(_ZN9TiXmlNode13ToDeclarationEv)

got(_ZN8CCountryD2Ev)

got(_ZN9GUIBattle4InitERK7GUIRect)

got(_ZN10CGameState12UnselectAreaEv)

got(_ZN11GUIButtonExD0Ev)

got(_Z7InvSqrtf)

got(_ZN13GUISelCountryD2Ev)

got(_ZN7ecShapeD2Ev)
bss(g_FightTextMgr, 120)

got(_ZN16TiXmlDeclarationC2ERKS_)

got(_ZN10GUINewGame17IsShowIabEventTipEv)

got(_ZN13GUIBattleItem8OnUpdateEf)

got(_ZN10GUIServiceD1Ev)

got(_ZN10GUIWarningC1Ev)

got(_ZN9hgeVector6RotateEf)

got(_ZN7ecShape6RenderERK7ecMtx32)

got(_ZN13GUIMatchSetupD2Ev)

got(_ZN7ecImage14SetTextureRectEffff)

got(_ZN9ecElement5ResetEv)

got(_ZN13CTouchInertia4InitEv)

got(_ZN11GUIWarMedalC1Ev)

got(_ZN10GUILoadingC2Ev)

got(_ZN10CObjectDef12GetBattleDefEPKc)

got(_ZN6CScene9GainMedalEff)

got(_ZN10ecGraphics11LoadTextureEPKc)

got(_ZN10GUIWarningD0Ev)

got(_ZN18ecEffectResManager8InstanceEv)

got(_ZN11CMatchState11ShowWarningEi)

got(_ZN12GUICommanderC1Ev)

got(_ZN9TiXmlNode12ReplaceChildEPS_RKS_)

got(_ZN14GUIRadioButtonC1Ev)

got(_ZN6CScene4MoveEii)

got(_ZN6GUIIapC1Ev)

got(_ZN10ecGraphics14LoadPVRTextureEPKc)

got(_ZN7GUIText8SetAlignEi)

got(_ZN14CPlayerManager15GetNumLeftCorpsEv)

got(_ZN12GUICommanderD0Ev)

got(_ZN12TiXmlComment5ParseEPKcP16TiXmlParsingData13TiXmlEncoding)

got(_ZN14TiXmlAttribute4NextEv)

got(_ZN5CArmy12BreakthroughEv)

got(_ZN10CMenuStateC2Ev)

got(_ZN11GUIHostList14FindHostByUUIDEi)

got(_ZN8ecEffect6RenderEv)

got(_ZN8ecEffect4StopEb)

got(_ZN11ecEffectRes10LoadEffectEPKcP12ecTextureRes)

got(_ZN10CObjectDef17LoadGeneralPhotosEv)

got(_ZN7ecLayerD2Ev)

got(_ZN13CGameSettings12SaveSettingsEv)

got(_ZN6CSceneC2Ev)

got(_ZNK16TiXmlDeclaration5CloneEv)

got(_ZN10CLogoStateD0Ev)

got(_ZN11GUISaveItem4InitERK7GUIRectPKc)

got(_ZN9ecLibraryD0Ev)

got(_ZN6CScene13CheckMoveableEiii)

got(_ZN6GUIIap8OnRenderEv)

got(_ZNK12TiXmlElement6CopyToEPS_)

got(_ZN14GUIRadioButtonD2Ev)

got(_ZN11ecEffectResC1Ev)

got(_ZN13GUIBattleList15ResetTouchStateEv)

got(_ZN10CMenuStateD1Ev)

got(_ZN6CSceneD1Ev)

got(_ZN6CScene12LoadAreaDataEi)

got(_ZN14CPlayerManager14SendRoundBeginEv)

got(_ZN11GUIWarMedalD1Ev)

got(_ZN11ecLabelText4InitEPKciiii)

got(_ZN6CScene14LoadAreaEnableEPKc)

got(_ZN11CBattleUnitC1Ev)

got(_ZN12CBattleScene7ReleaseEv)

got(_ZN14GUIBattleIntroC1Ev)

got(_ZNK9TiXmlNode18NextSiblingElementEv)

got(_ZN12TiXmlUnknownD1Ev)

got(_ZN12ecTextureRes8GetImageEPKc)

got(_ZN7GUIGold8SetMoneyEi)

got(_ZN11GUIDialogue7ShowDlgEPKcS1_b)
bss(_ZZN9CActionAI8InstanceEvE10S_ActionAi, 64)

got(_ZN6CScene19AircraftCarrierBombEii)

got(_ZN10CLoadState7OnEventERK5Event)

got(_ZN10GUINewGame18OnCheckButtonClickEP14GUIRadioButton)

got(_ZN16GUIMotionManagerC1Ev)

got(_ZN10CCommanderC1Ev)

got(_ZN10ecGraphics8InstanceEv)

got(_ZN9GUIButton8OnRenderEv)

got(_ZN11GUIPauseBoxD0Ev)

got(_Z14GetArmyAbilityi)

got(_Z18ecSetInAppPurchasePFviE)

got(_ZNK16TiXmlDeclaration6CopyToEPS_)

got(_ZN8CCountry12FinishActionEv)

got(_ZN13CStateManagerC1Ev)

got(_ZN15ecMultipleTouch10TouchEndedEff)

got(_ZN10CBaseState7KeyDownEi)

got(_ZN9TiXmlBase10IsAlphaNumEh13TiXmlEncoding)

got(_ZNK14TiXmlAttribute8IntValueEv)

got(_ZN13TiXmlDocumentC1EPKc)

got(_ZN7CPlayerD1Ev)

got(_ZN5CArea8SaveAeraEP12SaveAreaInfo)

got(_ZN10ecGraphics4FadeEf)

got(_ZN9TiXmlNodeD1Ev)

got(_ZN5CArea10RenderArmyEffiP5CArmy)

got(_ZN9TiXmlBase9PutStringERK11TiXmlStringP14TiXmlOutStream)

got(_ZN17TiXmlAttributeSet6RemoveEP14TiXmlAttribute)

got(_ZN7ecImageC1EP9ecTextureffff)

got(_Z16GetEditorResPathPKc)

got(_ZN13GUIBattleList18SelectLastUnlockedEv)

got(_ZN9CActionAID2Ev)

got(_ZN9TiXmlBase14StringToBufferD2Ev)

got(_ZN11GUIHostListD0Ev)

got(_ZN12GUICommander16SetCommanderInfoEv)

got(_ZN6CScene12CalSceneRectERfS0_S0_S0_)

got(_ZN13CActionAssist19purChaseSpecialCardEv)

got(_ZN8CCountry12GetIndustrysEv)

got(_ZN6ecFileD1Ev)

got(_ZN9TiXmlTextD2Ev)

got(_ZN13GUIBattleItem8OnRenderEv)

got(_ZN18ecEffectResManager16ReleaseEffectResEPKc)

got(_ZN5CArmy9TurnBeginEv)

got(_ZplRK11TiXmlStringPKc)

got(_ZN7ecLayer4PlayEv)

got(_ZN12CGameManager26SetConquestPlayerCountryIDEPKc)

got(_ZN13CStateManagerD2Ev)

got(_ZN14GUICountryList10GelSelItemEff)

got(_ZN8CCountry7TurnEndEv)

got(_ZN6CScene11ResetTargetEv)

got(_ZN9GUIBattle11BattleStartEiii)

got(_ZN14GUICountryList11ResetSelectEv)

got(_ZN12CBattleSceneD2Ev)

got(_ZNK16TiXmlDeclaration9StreamOutEP14TiXmlOutStream)

got(_ZN10CCommander12CheckUpgardeEv)

got(_ZN6CScene6MoveToEii)

got(_ZN6CScene10SaveAdjoinEi)

got(_ZN10GUIManager14LoadTextureResEPKcb)

got(_ZN7ecImageC1EP9ecTextureRK13ecTextureRect)

got(_ZN14GUICountryItem8OnUpdateEf)

got(_ZN6CScene7ReleaseEv)
bss(mOldTime, 8)

got(_ZN19GUIConnectHostStateC2Ev)

got(_ZN9CAreaMarkD1Ev)

got(_ZN5CArea15AddArmyStrengthEii)
bss(_ZN10CCSoundBox9mInstanceE, 8)

got(_ZN9TiXmlNode9ToCommentEv)

got(_ZN11GUIMainMenu7OnEventERK5Event)

got(_ZN9GUIButton12SetTextImageEPKc)

got(_ZN12CGameManager11FindCountryEPKc)

got(_ZN7GUIGoldC1Ev)

got(_ZNK14TiXmlAttribute5PrintEP7__sFILEi)

got(_ZN10GUILoadingD1Ev)

got(_ZN11GUIMainMenu12IsShowNewTipEv)

got(_Z13GetAIRandSeedv)

got(_ZN11ecLabelText8SetColorEj)

got(_ZN8GUIImage8OnRenderEv)

got(_ZN10CObjectDef20ReleaseUnitPositionsEv)

got(_ZN13GUIAIProgressC2Ev)

got(_ZN10CCommander20SetNumPlayedBatttlesEii)

got(_ZN12GUICorpsInfoD2Ev)

got(_ZN9TiXmlNode10ToDocumentEv)

got(_ZN7CPlayerC1Ev)

got(_ZN8CCountry16SetWarMedalLevelE11WARMEDAL_IDi)
bss(g_PlayerManager, 248)

got(_ZN10GUIBuyCard7SelCardEii)

got(_ZN9TiXmlNode11GetDocumentEv)

got(_ZN5CArmy7TurnEndEv)

got(_ZN5CArea16AllArmyPoisoningEv)

got(_ZN14CPlayerManager18onPeerDisconnectedEPKc)
bss(g_SoundRes, 92)

got(_ZN13CFightTextMgrD2Ev)

got(_ZN14CPlayerManager15AnalyzePeerNameERKSsRSsRiS3_)

got(_ZN18ecSessionInterface7ReleaseEv)

got(_ZN10CEditState11ReleaseGameEv)

got(_ZN7GUISaveC2Ev)

got(_ZN14GUIExitWarningD2Ev)

got(_ZN13GUIAdornMedalD1Ev)

got(_ZN6GUIIap14OnListCompleteEPv)

got(_ZN7ecFrame4InitEP11ecFrameDataP9ecElementP9ecLibrary)

got(_ZN10GUIManager6RenderEv)

got(_ZNK13TiXmlDocument9StreamOutEP14TiXmlOutStream)

got(_ZN6CScene13RenderAreasIDEv)

got(_ZN12GUICorpsInfo8OnRenderEv)

got(_ZN12CGameManager21GetLocalPlayerCountryEv)

got(_ZN6GUITax11SetIndustryEi)

got(_ZN7ecImageD1Ev)

got(_ZN5CArea6UpdateEf)

got(_ZN10CCommander10IsMaxLevelEv)

got(_ZN10CMenuState8TouchEndEffi)

got(_ZN13GUIMatchSetup4InitERK7GUIRect)

got(_ZN10GUIServiceD0Ev)

got(_ZN5CArea10OccupyAreaEPS_)

got(_Z18GetConquestKeyNameiPc)

got(_ZN7ecImageD2Ev)

got(_ZN7GUIGoldD0Ev)

got(_ZN13CGameSettingsC2Ev)
bss(g_Font6, 80)

got(_ZN13GUIAdornMedalC2Ev)

got(_ZN13TiXmlDocumentaSERKS_)

got(_ZN5CArea11HasArmyCardEii)

got(_ZN10GUIBuyCardD0Ev)

got(_ZN7CCameraC1Ev)

got(_ZN10CGameStateD2Ev)

got(_ZN12ecTextureResC2Ev)

got(_ZN10CObjectDef16LoadConquestListEv)

got(_ZN7ecLayer10ChangeItemEP10ecItemDataS1_P9ecLibrary)

got(_ZN6ecFileC2Ev)

got(_ZN7GUICardD0Ev)

got(_ZN7ecLayer4StopEv)

got(_ZN11CMatchStateD1Ev)

got(_ZN9ecLibrary12GetLayerDataEi)

got(_ZN5CArmy6AddExpEi)

got(_ZN10GUIVictory8OnRenderEv)

got(_ZN9ecGameKitD1Ev)

got(_ZN11GUIArmyItemD1Ev)

got(_ZN12TiXmlElement18SetDoubleAttributeEPKcd)

got(_ZN11GUIDefeatedD1Ev)

got(_ZN5CArea11AddArmyCardEii)

got(_ZN11GUIDefeated12HideDefeatedEv)

got(_ZN9ecGameKit7ReleaseEv)

got(_ZN9ecUniFont12GetCharImageEt)

got(_ZN17TiXmlAttributeSetC2Ev)

got(_ZN11GUICardList10GelSelItemEff)

got(_ZN7CBomberC1Ev)

got(_ZN11CBackgroundD1Ev)

got(_ZN11GUIPauseBoxD2Ev)

got(_ZN8ecEffect4InitEPKcP9TFreeListI16ecParticleSystemE)
bss(g_Font2, 80)

got(_ZN14GUIExitWarningC1Ev)

got(_ZNK13TiXmlDocument8SaveFileEv)

got(_ZN14CPlayerManager6UpdateEf)

got(_ZN7GUIText8OnRenderEv)

got(_ZN14CPlayerManager18SendPacketToPlayerE9PACKET_IDPKviP7CPlayer)

got(_ZN6CScene20AreaDisableOutofRectEiiii)

got(_ZN15ecEffectManager9AddEffectEPKcb)

got(_ZN12GUICorpsInfoC2Ev)

got(_ZN7GUIBankD2Ev)

got(_ZN8GUIImage8SetAlphaEf)

got(_ZN14CPlayerManager17DidRecvInvitationEPKc)

got(_ZN3MD5C1EPKvm)

got(_ZN10GUIElement11CheckInRectEff)

got(_ZN16GUILockedWarning4InitERK7GUIRect)

got(_ZN7CBomberD2Ev)

got(_ZNK11TiXmlHandle10FirstChildEv)

got(_ZN9GUIButton7SetTextEPKt)

got(_ZN10CObjectDef7ReleaseEv)

got(_ZN16GUILockedWarningC2Ev)

got(_ZN10CLoadStateC2Ev)

got(_ZN11GUIWarMedal13SetArrowColorEj)

got(_ZN10GUIElement10SetVisibleEb)

got(_Z17ecGetProductPricei)

got(_ZN12GUIScrollBar12SetScrollPosEi)

got(_Z24GetBattleBelligerentListPKcRSt4listI11BelligerentSaIS2_EEb)

got(_ZN10CBaseState7OnEnterEv)

got(_ZN10CMenuState18StartMultiplayGameEi)

got(_ZN5CArmyD2Ev)

got(_ZNK9TiXmlNode11GetDocumentEv)

got(_ZN8GUIBegin4InitERK7GUIRect)

got(_ZN6ecText8SetColorEj)

got(_ZN10CGameState14HideAIProgressEv)

got(_ZN8CCountry11LoadCountryEPK15SaveCountryInfo)

got(_ZN9CActionAI18setActionNodeClearEv)

got(_ZNK13TiXmlDocument8SaveFileEPKc)

got(_ZN11GUISaveItem8OnRenderEv)

got(_ZN10CMenuState7OnEventERK5Event)

got(_ZN11GUIHostList8OnRenderEv)

got(_ZN14CPlayerManager12onMatchFoundEv)

got(_ZN13GUIMatchSetup7OnEventERK5Event)

got(_ZN13TiXmlDocumentD1Ev)

got(_ZN10CGameState11ScrollWheelEfff)

got(_ZN5CArea9ConstructEi)

got(_ZN6ecFile11IsFlieExistEPKc)

got(_ZN8CCountry13IsLocalPlayerEv)

got(_ZN9CSoundRes10PlayCharSEE10SND_EFFECT)

got(_ZN8CGameRes15RenderArmyLevelEffi)

got(_ZN10CMenuState11ShowWarningEi)

got(_ZNK12TiXmlElement9AttributeEPKc)

got(_ZN13CFightTextMgr7ReleaseEv)

got(_ZN13GUIAdornMedal7RefreshEv)

got(_ZN10CObjectDef14GetConquestDefEPKc)

got(_Z16ecETCTextureLoadPKcRiS1_Rj)

got(_ZN10GUIElement9SetEnableEb)

got(_ZN12CBattleScene10CreateFortEv)

got(_ZN10CGameState12ShowDialogueEPKcS1_b)

got(_ZN13TiXmlDocumentC2Ev)

got(_ZN7GUITechC2Ev)

got(_ZN5CArmy8LoadArmyEPK12SaveArmyInfo)

got(_ZN14CPlayerManager14DestroySessionEv)

got(_ZN11GUIDefeated7OnEventERK5Event)

got(_ZN9TiXmlBase18ConvertUTF32ToUTF8EmPcPi)

got(_ZN12CBattleSceneC1Ev)

got(_ZN6GUITax4InitERK7GUIRect)

got(_ZN3MD56digestEv)

got(_ZN9GUIResultD0Ev)

got(_ZN10GUINewGame15GetPromotionUrlEv)

got(_ZN6GUITax8SetMoneyEi)

got(_ZN8ecEffect6MoveToEffb)

got(_ZN10GUIBuyCard4InitERK7GUIRect)

got(_ZN8CCountry7UseCardEP7CardDefii)

got(_ZNK14TiXmlAttribute11DoubleValueEv)

got(_ZN13CFightTextMgrC2Ev)

got(_ZN13CStateManager8TouchEndEffi)

got(_ZN9GUIBattle7OnEventERK5Event)

got(_ZN5CArea9DraftArmyEi)

got(_ZN12GUIAttackBoxD1Ev)

got(_ZN10CEditState6RenderEv)

got(_ZN9GUIBattle12BattleFinishEv)

got(_ZN8CCountry17GenCardTargetListE7CARD_ID)

got(_ZN7GUITechD1Ev)

got(_ZN19GUIConnectHostStateD0Ev)

got(_ZN14CPlayerManager10FindPlayerEPKc)

got(_ZN10CLogoState7OnEnterEv)

got(_ZN5CArea10GetArmyIdxEP5CArmy)

got(_ZN10CFightText8SetColorEj)

got(_ZN12CGameManager17CheckAndSetResultEv)

got(_ZN9TiXmlBase9PutStringERK11TiXmlStringPS0_)

got(_ZN13CTouchInertiaC1Ev)

got(_ZN10CCommander20GetNumPlayedBatttlesEi)

got(_ZN10GUICardTabC2Ev)

got(_ZN13CActionAssist10searchNodeEii)

got(_ZN13TiXmlDocument8SetErrorEiPKcP16TiXmlParsingData13TiXmlEncoding)

got(_Z18ecSetShowReviewFucPFvvE)

got(_ZN10ecGraphics15LoadWEBPTextureEPKc)

got(_ZN7GUIBank8OnRenderEv)

got(_ZN12GUITutorails10LoadScriptEv)

got(_ZN12GUITutorailsD0Ev)

got(_ZN8GUIBeginD2Ev)

got(_ZN11GUICardListD1Ev)

got(_ZN9CActionAI8getMaxIdEv)

got(_ZN14GUIExitWarningD0Ev)

got(_ZN9GUIButton12SetTextAlignEi)

got(_ZN13GUIAIProgressD0Ev)

got(_ZN15ecMultipleTouchD2Ev)

got(_ZNK12TiXmlUnknown5PrintEP7__sFILEi)

got(_ZN10GUICardTabD1Ev)

got(_ZN10CObjectDefD1Ev)

got(_ZN11ecLabelTextC1Ev)

got(_ZN5CArmy12LostStrengthEi)

got(_ZN13CStateManager11BackPressedEv)

got(_ZN11GUICardList7GetCardEi)

got(_ZN18ecEffectResManager14LoadTextureResEPKc)

got(_ZN7ecFrameD1Ev)

got(_ZN7GUIBankD0Ev)

got(_ZN7ecImage6RenderEffff)

got(_ZN9ecGameKitC2Ev)

got(_ZN7ecImage14SetTextureRectERK13ecTextureRect)

got(_ZN16ecParticleSystem6IsLiveEv)

got(_ZN6ecTextC1Ev)

got(_ZNK9TiXmlText5PrintEP7__sFILEi)

got(_ZN15ecEffectManagerC2Ev)

got(_ZN13GUIAIProgressD2Ev)

got(_ZN8GUIImage4InitEPKcRK7GUIRect)

got(_ZN7CCamera14IsRectInCameraEffff)

got(_ZN11ecLabelTextD2Ev)

got(_ZN10CMenuState7OnEnterEv)

got(_ZN10GUIElement11CheckInRectEffRK7GUIRect)

got(_ZN12TiXmlElement12SetAttributeEPKcS1_)

got(_ZN10CLogoStateC2Ev)

got(_ZN6CScene8IsMovingEv)

got(_ZN9GUIBattleD0Ev)

got(_ZN7GUIBankC1Ev)

got(_ZN10ecGraphics5FlushEv)

got(_ZN12GUITutorails7ShowDlgEPKc)

got(_ZN6GUITaxD1Ev)

got(_ZN6GUIIapC2Ev)

got(_ZN5CArea16GetIndustryLevelEv)

got(_ZN3MD56decodeEPKhPmm)

got(_ZN7GUITextC2Ev)

got(_ZN12CBattleSceneC2Ev)

got(_ZN11GUIDialogue7HideDlgEv)

got(_ZN8GUIMedal8OnUpdateEf)

got(_ZN6CFight12GetAttackAddEi)

got(_ZN11GUIHostItemC1Ev)

got(_ZN12GUITutorails7OnEventERK5Event)

got(_ZN6CScene11CreateArrowEii)

got(_ZN12CGameManager10NextBattleEv)

got(_ZN10GUIVictoryD2Ev)

got(_ZN12GUIAttackBox7OnEventERK5Event)

got(_ZN12GUICorpsInfo13SetPlayerNameEPKcbS1_iib)

got(_ZN11GUIMainMenu8OnRenderEv)

got(_ZN12GUITutorails7ShowDlgEi)

got(_ZN10GUIBuyCard10GetSelCardEv)

got(_ZN10GUIWarningD2Ev)

got(_ZN7ecLayer7SetLoopEi)

got(_ZN13GUIAdornMedal8OnRenderEv)

got(_ZN11GUIHostItemD0Ev)

got(_ZN8ecEffect6FireAtEfff)

got(_ZN10GUIBuyCard13CanBuySelCardEv)

got(_ZN11GUIHostList8FindHostEPKc)

got(_ZN14CPlayerManager12SetupSessionEb)

got(_ZNK9TiXmlText5CloneEv)

got(_ZN14CPlayerManagerC1Ev)

got(_ZN13GUISelCountry13LoadImageListEi)

got(_ZN9CActionAI12getAiPercentEi)

got(_ZN12GUICommanderC2Ev)

got(_ZN7CBomber8AirborneEi)

got(_ZN13GUISelCountryD1Ev)

got(_ZN8CCountry12SetCommanderEPKc)

got(_ZN12CBattleScene12DestroyUnitsEi)

got(_ZN10CEditStateD2Ev)

got(_ZN9GUIButtonC1Ev)

got(_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz)

got(_ZN11GUISaveItemD0Ev)

got(_ZN18ecEffectResManager17ReleaseTextureResEv)

got(_ZN13CGameSettings12LoadSettingsEv)

got(_ZN10GUIVictory4InitERK7GUIRectb)

got(_ZN14CPlayerManager13GetRightCorpsEi)

got(_ZN14CPlayerManagerD2Ev)

got(_ZNK13TiXmlDocument10ToDocumentEv)

got(_ZN9TiXmlText6ToTextEv)

got(_ZN12GUICommanderD1Ev)

got(_ZN16GUIMotionManager9AddMotionEP10GUIElementffft)

got(_ZN7GUICardD2Ev)

got(_ZN12GUICommander13SelectedMedalEi)

got(_ZN11ecEffectRes7ReleaseEv)

got(_ZN6GUIEndD1Ev)

got(_ZN11CMatchState6UpdateEf)

got(_ZN14GUICountryItem7OnEventERK5Event)

got(_ZN10GUILoadingD0Ev)

got(_ZN9TiXmlNode15IterateChildrenEPS_)

got(_ZN10CObjectDef19ReleaseCommanderDefEv)

got(_ZN5CArea12GetCityLevelEv)

got(_ZN8CCountry12GetCardPriceEP7CardDef)

got(_ZN10CCommanderC2Ev)

got(_ZN9GUIButton13SetBackgroundEPKc)

got(_ZN10GUIManager6FadeInEi)

got(_ZN14CPlayerManager12ClearPlayersEv)

got(_ZN10CObjectDefC1Ev)

got(_ZNK12TiXmlElement9AttributeEPKcPi)

got(_ZN7GUISave7OnEventERK5Event)

got(_ZN7GUICardC1Ev)

got(_ZN10CBaseState15EnterForegroundEv)

got(_ZN6GUIIapD2Ev)

got(_ZN8CheckMD5C2Ev)

got(_ZN12CGameManager9RetryGameEv)

got(_ZN7CCamera5UpateEf)

got(_ZN9TiXmlNode17InsertBeforeChildEPS_RKS_)

got(_ZN17GUICommanderMedalC2Ev)

got(_ZN5CArmy25GetNumDicesIfLostStrengthEi)

got(_ZNK9TiXmlNode10FirstChildEPKc)

got(_ZN6CScene10LoadAdjoinEi)

got(_ZN13GUIBattleItem7OnEventERK5Event)

got(_ZN13CActionAssist13calcDraftTypeEbiP8CCountry)

got(_ZN17TiXmlAttributeSet4FindERK11TiXmlString)

got(_ZN17GUICommanderMedalD1Ev)

got(_ZN14GUIBattleIntroD1Ev)

got(_ZN9TiXmlNodeC2ENS_8NodeTypeE)

got(_ZN13GUIBattleItemC2Ev)

got(_ZN12GUIAttackBox8OnRenderEv)

got(_ZN12GUIScrollBarC1Ev)

got(_ZN6CScene16RenderAreasPointEv)

got(_ZN13GUIBattleListC2Ev)

got(_ZN13TiXmlDocument5ParseEPKcP16TiXmlParsingData13TiXmlEncoding)

got(_ZN13TiXmlDocumentC2EPKc)

got(_ZN15GUIProductPrice14SetLocalePirceEPKc)

got(_ZN12GUITutorailsC2Ev)

got(_ZN9ecGameKit18GetMatchPlayerListERSt4listISsSaISsEE)

got(_ZN5CArea12ClearAllArmyEv)

got(_ZN15ecEffectManager6UpdateEf)

got(_ZN10GUIWarning8OnRenderEv)

got(_ZN8CCountry12CommanderDieEv)

got(_ZN8GUIImageD2Ev)

got(_ZN14GUICountryItemD1Ev)

got(_ZN5CArea11UpgradeArmyEi)

got(_ZN6ecTextD1Ev)

got(_ZN12GUITutorailsD2Ev)

got(_ZN12GUISelBattle8OnUpdateEf)

got(_ZN10CObjectDef10GetCardDefE7CARD_ID)

got(_ZN12TiXmlCommentD2Ev)

got(_ZN9TiXmlNode8IdentifyEPKc13TiXmlEncoding)

got(_ZN12CGameManager13GetSaveHeaderEPKcR10SaveHeader)

got(_ZN3MD56updateERKSs)

got(_ZN12GUICorpsInfo4InitERK7GUIRect)

got(_ZN10CLoadState6OnExitEv)

got(_ZN6GUIIap15SetProductPriceEv)

got(_ZN11GUIButtonExD2Ev)

got(_ZN10GUIManagerC1Ev)

got(_ZN8GUIBegin8OnRenderEv)

got(_ZN13CTouchInertia9TouchMoveEffi)

got(_ZN11CMatchState7OnEnterEv)

got(_ZN12ecTextureRes9UnloadResEPKc)

got(_Z17ecSetProductPriceiPKc)

got(_ZN10CGameStateD1Ev)

got(_ZN7ecImage4InitEP11ecImageAttr)

got(_ZN10CCSoundBox11SetSEVolumeEi)

got(_ZN12CGameManagerD1Ev)

got(_ZN3MD56updateEPKhm)

got(_ZN6CScene11SaveAreaTaxEi)

got(_ZNK13TiXmlDocument5CloneEv)

got(_ZN10CGameState12StartBattaleEiiib)

got(_ZN10ecGraphicsC2Ev)

got(_ZN8CCountry18GetMinDstToAirportEi)

got(_ZN6CScene14RenderAreasTaxEv)

got(_ZN10GUIManagerD0Ev)

got(_ZN13GUIActionInfo8OnRenderEv)

got(_ZN11GUIMainMenuD2Ev)

got(_ZN7GUIBank8OnUpdateEf)

got(_ZN10CCSoundBox7DestroyEv)

got(_ZN12CBattleScene11ReleaseFortEv)

got(_ZN10CLoadState10TouchBeginEffi)

got(_ZNK12TiXmlComment9ToCommentEv)

got(_ZN13GUIActionInfo8OnUpdateEf)

got(_Z14ecLoadSettingsv)

got(_ZN12TiXmlUnknownD0Ev)

got(_ZNK13TiXmlDocument6CopyToEPS_)

got(_ZN10GUIManager4InitERK7GUIRect)

got(_ZN3MD5C2ERSt14basic_ifstreamIcSt11char_traitsIcEE)

got(_ZN7GUISaveC1Ev)

got(_ZN10CGameStateC2Ev)

got(_ZN6CMedal6RenderEv)

got(_ZN5CArea10SetArmyDirEif)

got(_ZN8CCountry14NextCardTargetEv)

got(_ZN14TiXmlAttributeD0Ev)

got(_ZN10CCSoundBox11UnloadMusicEv)
bss(_ZZN13CActionAssist8InstanceEvE14S_ActionAssist, 6328)

got(_ZN8CGameRes12GetFlagImageEPKc)

got(_ZN10ecGraphics12SetViewPointEfff)

got(_ZN12CGameManager13BattleVictoryEv)

got(_ZN11CMatchState7OnEventERK5Event)

got(_ZN5CArea14RenderBuildingEv)

got(_ZN8ecEffectC2Ev)

got(_ZN9ecLibraryD1Ev)

got(_ZN10CGameState12ShowDefeatedEP8CCountry)

got(_ZN3MD55finalEv)

got(_ZN8GUIBegin7OnEventERK5Event)

got(_ZN5CArea23ReduceConstructionLevelEv)

got(_ZN6CScene22MoveCameraCenterToAreaEi)

got(_ZN13CActionAssist11getAllianceEiii)

got(_ZN7GUICard8OnRenderEv)

got(_ZN10GUINewGameD0Ev)

got(_ZN5CArea4InitEiRK8AreaInfo)

got(_ZN15ecEffectManagerD2Ev)

got(_ZN10ecGraphics11RenderBeginEv)

got(_ZN11ecEffectResD1Ev)

got(_ZN8GUIMedal7OnEventERK5Event)

got(_ZN10CObjectDef14LoadBattleListEv)

got(_ZN7GUIGold11SetIndustryEi)

got(_ZN9GUIButton4InitEPKcS1_RK7GUIRectP9ecUniFont)

got(_ZN10GUINewGameC1Ev)

got(_ZN6CFight17GetAttackerResultEi)

got(_ZN9TiXmlNode18NextSiblingElementEPKc)

got(_ZN15GUIProductPrice4InitERK7GUIRect)

got(_ZN6GUIIap4InitERK7GUIRect)

got(_ZNK13TiXmlDocument8SaveFileEP7__sFILE)

got(_ZN7GUISaveD2Ev)

got(_ZN6CScene10MakeAdjoinEii)

got(_ZN18ecSessionInterface17DeclineInvitationEPKc)

got(_ZN14CPlayerManager13GetNumActionsEv)

got(_Z9ecKeyDowni)

got(_ZN16GUILockedWarning7OnEventERK5Event)

got(_ZN11GUIWarMedalC2Ev)

got(_ZN14GUICountryList15GetSelCountryIDEv)

got(_ZNK12TiXmlUnknown6CopyToEPS_)

got(_Z15GetDocumentPathPKc)

got(_ZN12GUIScrollBarD0Ev)

got(_ZN6CScene14RenderSeaAreasEv)

got(_ZN13GUIMatchSetupD1Ev)

got(_ZN16TiXmlDeclarationC2EPKcS1_S1_)

got(_ZN13CStateManager13RegisterStateEP10CBaseState)

got(_ZN11GUIDefeatedC1Ev)

got(_ZN10GUISelArmyD1Ev)

got(_ZN10GUIOptions7OnEventERK5Event)

got(_ZN9TiXmlBase9GetEntityEPKcPcPi13TiXmlEncoding)

got(_ZN10CObjectDefC2Ev)

got(_ZN7CCamera5ApplyEv)

got(_ZN10CLogoState7OnEventERK5Event)
bss(APKFilePath, 256)

got(_ZN16TiXmlDeclarationD0Ev)

got(_ZN10CGameState15EnableIdleTimerEf)

got(_ZN10CMenuState10TouchBeginEffi)

got(_ZN16GUILockedWarning8OnRenderEv)

got(_ZN3MD55resetEv)

got(_ZN12TiXmlElementaSERKS_)

got(_ZN10GUISelArmyC2Ev)

got(_ZN9GUIButton7OnEventERK5Event)

got(_ZN13CActionAssist11getNeighborEiiic)

got(_ZN8GUIMedalD1Ev)

got(_ZN7CPlayer10PushPacketE9PACKET_IDPKvi)

got(_ZN10ecGraphics10RenderLineEPK6ecLine)

got(_ZN10CEditState7OnEventERK5Event)

got(_ZN7ecImage7SetFlipEbbb)

got(_ZN7ecShape4InitEP9ecTextureffff)

got(_ZNK12TiXmlComment6CopyToEPS_)

got(_ZN10CMenuState8ShowExitEv)

got(_ZN13CStateManager8InstanceEv)

got(_ZN6CScene10SelectAreaEP5CArea)

got(_ZN9CActionAI14getNumArmyMoveEii)

got(_ZN3MD5C2ERKSs)

got(_ZN11CMatchState6OnExitEv)

got(_ZN12CGameManagerC2Ev)

got(_ZN10CCommander15UpgradeWarMedalE11WARMEDAL_ID)

got(_ZN9ecElementD1Ev)
bss(classLoader, 8)

got(_ZN11CBattleUnit6AttackEv)

got(_ZN9GUIResult7OnEventERK5Event)

got(_ZN13GUIMatchSetup8OnRenderEv)

got(_ZN9ecElement4InitEP13ecElementDataP9ecLibrary)

got(_ZN10CMenuStateD0Ev)

got(_ZN6CFight11ApplyResultEv)

got(_ZN15GUIProductPriceD1Ev)

got(_ZN13CTouchInertiaD2Ev)

got(_ZN11GUIDefeatedD2Ev)

got(_Z11ecTouchMoveffi)

got(_ZN11CMatchState18StartMultiplayGameEi)

got(_ZN14TiXmlAttribute14SetDoubleValueEd)

got(_ZN5CArmy9PoisoningEv)

got(_ZN12GUITutorails6ExeCmdEi)

got(_ZN9GUIBattle8OnUpdateEf)

got(_ZN6GUIEnd8OnRenderEv)

got(_ZN8CCountry16GetWarMedalLevelE11WARMEDAL_ID)

got(_ZN9ecElementC2Ev)
bss(g_Num4b, 80)

got(_ZN10CMenuStateC1Ev)

got(_ZN12GUISmallCard8OnRenderEv)

got(_ZN16GUIUpgradeButtonD0Ev)

got(_ZN13TiXmlDocument8LoadFileEP7__sFILE13TiXmlEncoding)

got(_ZN14GUICountryListC2Ev)

got(_ZN14CPlayerManager14WillDisconnectEv)

got(_ZN16GUIUpgradeButtonC1Ev)

got(_ZN10CEditState7OnEnterEv)

got(_ZNK9TiXmlNode9ToUnknownEv)

got(_ZN6CScene21MoveCameraBetweenAreaEii)
bss(_ZN13CActionAssist9_instanceE, 8)

got(_ZN11GUIWarMedal8OnRenderEv)

got(_ZN12ecTextureRes13CreateTextureEPKcbbb)

got(_ZN6CScene13InitAreaImageEi)

got(_ZN3MD58toStringEv)

got(_ZN10ecGraphics11BindTextureEP9ecTexture)

got(_ZN7GUISave8OnRenderEv)

got(_ZN6GUITax7SetAreaEi)

got(_ZN11GUIButtonExC2Ev)

got(_ZN8CCountry13GetNumAirportEv)

got(_ZN10CBaseState10TouchBeginEffi)

got(_ZN10CObjectDef20ReleaseGeneralPhotosEv)

got(_Z16ecPVRTextureLoadPKcRiS1_Rj)

got(_ZN8CCountry16CollectIndustrysEv)

got(_ZN10GUINewGame14GetIabEventUrlEv)

got(_ZN11CBattleUnitD1Ev)

got(_ZN14CPlayerManager16onAcceptedInviteEv)

got(_ZN6CScene10ClearAreasEv)

got(_ZN12GUISmallCard7SetCardEP7CardDef)

got(_ZN10GUISelArmy8OnRenderEv)

got(_ZN9ecGameKitD2Ev)

got(_ZN13GUIBattleList7OnEventERK5Event)

got(_ZN7GUISaveD1Ev)

got(_ZN6ecFile7GetSizeEv)

got(_ZN7CPlayer10SendPacketE9PACKET_IDPKvi)

got(_ZN13CStateManager6RenderEv)

got(_ZN13CStateManager4InitEv)

got(_ZN9GUIButtonD1Ev)

got(_ZN6CSceneD2Ev)

got(_ZN7ecImage6RenderEff)

got(_ZN8GUIBegin9ResetDataEv)

got(_ZN12CBattleScene11CreateUnitsEv)

got(_Z13ecLoadLibraryPKcR13ecLibraryData)

got(_ZN10CCSoundBox8UnloadSEEPKc)

got(_ZN8CGameRes18RenderUIAttackArmyEPKcffiiiiiiib)

got(_ZN9TiXmlTextD1Ev)
bss(g_Num4, 80)

got(_ZN12GUICommander4InitERK7GUIRect)

got(_ZN16ecParticleSystem6FireAtEfff)

got(_ZN7GUIGoldD2Ev)

got(_ZN12TiXmlElement9ClearThisEv)
bss(g_Num8, 80)

got(_Z12ecGameUpdatef)

got(_ZN8CGameRes10RenderFlagEPKcff)

got(_ZN6CSceneC1Ev)

got(_ZNK9TiXmlNode13ToDeclarationEv)

got(_Z19GetCommanderAbilityi)

got(_ZN10CMenuState6UpdateEf)

got(_ZN9TiXmlBase8ReadTextEPKcP11TiXmlStringbS1_b13TiXmlEncoding)

got(_ZN13GUIActionInfoC2Ev)

got(_ZN9GUIBattleC2Ev)

got(_ZN14CPlayerManager17InvitationDidFailEPKc)

got(_ZN7ecLayer6RenderERK7ecMtx32)

got(_ZN10GUINewGame18IsIabEventImgReadyEv)

got(_ZN5CArea19DestroyConstructionEv)

got(_ZN11GUIArmyItemC1Ev)

got(_ZN10CObjectDef15GetGeneralPhotoEPKc)

got(_ZN10CLoadState11BackPressedEv)

got(_ZN16GUIMotionManager8InstanceEv)

got(_ZN7ecImageC1EP11ecImageAttr)

got(_ZN10CBaseState11ScrollWheelEfff)

got(_ZN11GUIMainMenu8OnUpdateEf)

got(_ZN7GUICard7OnEventERK5Event)

got(_ZN14CPlayerManager13CancelConnectEv)

got(_ZN13CTouchInertia13AddTrackPointEff)

got(_ZN10GUIElement8OnRenderEv)

got(_ZN9ecElement9ResetItemEP10ecItemDataP9ecLibrary)

got(_ZN9TiXmlNodeC1ENS_8NodeTypeE)

got(_ZN18ecSessionInterface7ConnectEPKc)

got(_ZN10CGameState9TouchMoveEffi)

got(_ZN7CCamera6SetPosEffb)

got(_ZN10CFightTextC2Ev)

got(_ZN9CActionAID1Ev)

got(_ZN9ecLibrary11GetItemDataEi)

got(_ZN12CGameManager13GetCurCountryEv)

got(_ZNK12TiXmlUnknown5CloneEv)

got(_ZN11ecLabelTextC2Ev)

got(_ZN12CGameManager20SetPlayercountrynameEiPKc)

got(_ZN10GUIElement8OnUpdateEf)

got(_ZN18ecEffectResManagerC1Ev)

got(_ZN6CScene15GetAdjacentAreaEii)

got(_ZN10CCSoundBox11GetInstanceEv)

got(_ZN12CGameManager9TurnBeginEv)

got(_ZN14CPlayerManager17RemoveCorpsPlayerEii)

got(_Z13ecGameWaitingb)

got(_ZN14CPlayerManager23RefreshAndSendCorpsDataEv)

got(_ZN11ecLabelText8SetAlphaEf)

got(_ZN8CCountry12IsCardUnlockEP7CardDef)

got(_ZN13GUIBattleList4InitERK7GUIRecti)

got(_ZN5CArmy11GetNumDicesEv)

got(_ZN6ecText9GetHeightEv)

got(_ZN13GUIBattleItemD0Ev)

got(_ZN10GUIManager7FadeOutEiP10GUIElement)

got(_ZN11GUICardListC2Ev)

got(_ZN13GUIAdornMedalD2Ev)

got(_ZN12ecTextureRes11CreateImageEPKcP9ecTextureffffff)

got(_ZN10GUIBuyCardD1Ev)

got(_ZN10GUIManager7OnEventERK5Event)

got(_ZN8CGameRes4LoadEv)

got(_ZN12GUITutorails13ReleaseScriptEv)

got(_ZN12ecTextureRes14ReleaseTextureEP9ecTexture)

got(_ZN6ecText11GetNumLinesEv)

got(_ZN10GUIElementD0Ev)

got(_Z10ecGameInitiiiii)

got(_ZN13CTouchInertiaC2Ev)

got(_ZN6CScene6RenderEv)

got(_ZN10CGameState11BackPressedEv)

got(_ZN10GUIManager16ReleaseTexureResEv)

got(_ZN13GUIAIProgress4InitERK7GUIRect)

got(_ZN7GUITextD0Ev)

got(_ZNK12TiXmlElement9ToElementEv)

got(_ZN10GUICardTabD2Ev)

got(_ZN10GUIElement6SetPosEff)

got(_ZN14GUIBattleIntro9SetBattleEii)

got(_ZN6CFightD1Ev)

got(_ZN14CPlayerManager20onFriendListReceivedEv)

got(_ZN9CActionAI16setCpuDriverbyIdEii)

got(_Z9GetAIRandv)

got(_ZN8GUIBeginD0Ev)

got(_ZN12CGameManager7ReleaseEv)

got(_ZN10CBaseState15EnterBackgroundEv)

got(_ZN10CObjectDef16LoadCommanderDefEv)

got(_ZN14CPlayerManager18SetPlayerOfCountryEv)

got(_ZN7ecLayer4InitEiP11ecLayerDataP7ecFrameP9ecElementP9ecLibrary)

got(_ZN10GUIBuyCard14ResetCardStateEv)

got(_ZN17GUICommanderMedalC1Ev)

got(_ZN10CFightText6RenderEv)

got(_ZN10GUIManagerD2Ev)

got(_ZN9CActionAI13setArmyActionEP5CArea)

got(_ZN6CScene17CheckAdjacentDataEv)

got(_ZN7ecFrame9NextFrameEv)

got(_ZN13GUIBattleItem11SetSelectedEb)

got(_ZN17GUICommanderMedalD0Ev)

got(_ZN6CFightC2Ev)

got(_ZN7ecImage10SetTextureEP9ecTexture)

got(_ZN7GUICard4InitEP7CardDefRK7GUIRect)

got(_ZN8GUIBeginC1Ev)

got(_ZN10CCommander4LoadEv)

got(_ZN14CPlayerManager22IsDisconnectedFromHostEv)

got(_ZN10GUIManager9PostEventERK5Event)

got(_ZN8CCountry14BeConquestedByEPS_)

got(_ZN8CheckMD5C1Ev)

got(_ZN19GUIConnectHostState7OnEventERK5Event)

got(_ZN16GUIUpgradeButton8OnRenderEv)

got(_ZN12GUITutorailsD1Ev)

got(_ZN14GUIBattleIntro7OnEventERK5Event)

got(_ZN8CGameResD1Ev)

got(_ZN9GUIButton12SetTextColorEj)

got(_ZN10GUIManager8InstanceEv)

got(_ZN14CPlayerManager18ClearRemotePlayersEv)

got(_ZN9GUIResultD1Ev)

got(_ZN7ecFrameD2Ev)

got(_ZN14TiXmlAttributeD2Ev)

got(_ZN8CGameResD2Ev)

got(_ZN13CFightTextMgrC1Ev)

got(_ZN13GUIBattleItemD2Ev)

got(_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz)

got(_ZN13CFightTextMgr4InitEv)

got(_ZN14CPlayerManager28SendPacketToAllPlayersExceptE9PACKET_IDPKviP7CPlayer)

got(_ZN3MD5C1Ev)

got(_ZN14CPlayerManagerD1Ev)

got(_ZN8GUIImage8SetImageEPKcRK13ecTextureRectb)

got(_ZN7ecFrame6RenderERK7ecMtx32)

got(_ZN8CGameRes22RenderAICommanderMedalEiffPKci)

got(_Z14ecGameShutdownv)

got(_ZN17GUICommanderMedalD2Ev)

got(_ZN10CCommander20CheckUpgradeWarMedalE11WARMEDAL_ID)

got(_ZN6CScene25GetTwoAreasDistanceSquareEii)

got(_ZN10CLoadStateD0Ev)

got(_ZN11CBattleUnit7DestroyEv)

got(_ZN18ecEffectResManagerD1Ev)

got(_ZN6CFight16AirStrikesAttackEii)

got(_ZN6CScene11GetNumAreasEv)

got(_ZN6CScene9InitAreasEiPKc)

got(_ZN6ecFileD2Ev)
bss(gJavaVM, 8)

got(_ZN6CScene12ClearTargetsEv)

got(_ZN14CPlayerManager7ReleaseEv)

got(_ZN12GUICommanderD2Ev)

got(_ZN9CAreaMarkC1Ev)

got(_ZN9CSoundRes6UnloadEv)

got(_ZN13GUIAIProgressC1Ev)

got(_ZN10GUIOptionsC1Ev)

got(_ZN12GUITutorails7HideDlgEv)

got(_ZN13GUIBattleList8OnUpdateEf)

got(_ZN14CPlayerManager16ClearActionQueueEv)

got(_ZN6CScene17RenderAreasCenterEv)

got(_ZN6CScene9NewAdjoinEv)

got(_ZN10GUINewGame14IsShowIabEventEv)

got(_ZN6CScene6UpdateEf)

got(_ZN10CCommander4SaveEv)

got(_ZN13ecStringTable5ClearEv)

got(_ZN12CGameManager10GameUpdateEf)

got(_Z13SetAIRandSeedi)

got(_ZN9CAreaMarkD2Ev)

got(_ZN13CActionAssist16purChaseFortCardEv)

got(_ZN10CGameState8TouchEndEffi)

got(_ZN8CCountryC1Ev)

got(_ZN7_JNIEnv16CallObjectMethodEP8_jobjectP10_jmethodIDz)

got(_ZN9TiXmlNode5ClearEv)

got(_Z13ecGetUUIDHashv)

got(_ZN9CActionAI21analyseCompositePowerEv)

got(_ZN10GUIOptionsD2Ev)

got(_ZN7CPlayer9SendFirstEv)

got(_ZN5CArea6RenderEv)

got(_ZN11GUICardList9SetSelectEi)

got(_ZN13CActionAssistD1Ev)

got(_ZN6ecText7SetTextEPKt)

got(_ZN9GUIBattle8OnRenderEv)

got(_ZN13GUIActionInfo4InitERK7GUIRect)

got(_ZN10GUIServiceC2Ev)

got(_ZN16GUIMotionManager15GetMotionActiveEj)

got(_ZN13GUISelCountry8OnUpdateEf)

got(_ZN7ecFrame4PlayEv)

got(_ZN12CGameManager18GetNumVictoryStarsEv)

got(_ZN5CArmy6IsNavyEv)

got(_ZN11CMatchStateC1Ev)

got(_ZN10CObjectDef10GetArmyDefEiPKc)

got(_ZN10GUIManager8AddImageEPKcRK7GUIRectP10GUIElement)

got(_ZN16GUIMotionManager9SetMotionEjffffft)

got(_ZN10CLoadStateC1Ev)

got(_ZN7GUITextD2Ev)

got(_ZN6CScene12SaveAreaDataEi)

got(_ZN7GUITech8OnRenderEv)

got(_ZN9CActionAI12purChaseCardE7CARD_ID)

got(_ZN10CGameState7OnEnterEv)

got(_ZN10GUISelArmyD0Ev)

got(_ZN18ecSessionInterfaceC2Ev)

got(_ZN7CPlayerC2Ev)

got(_ZN6GUIIapD1Ev)
bss(g_GameSettings, 24)

got(_ZN11ecLabelText8DrawTextEff)

got(_ZN10ecGraphics14LoadETCTextureEPKc)

got(_ZN7GUIBankC2Ev)

got(_ZdaPv)

got(_ZN10GUIElementD1Ev)

got(_ZN13CGameSettingsD2Ev)

got(_ZN10GUINewGameD1Ev)

got(_ZN12CGameManagerD2Ev)

got(_ZN11CMatchStateD2Ev)

got(_ZN18ecSessionInterface13CancelConnectEv)

got(_ZN17TiXmlAttributeSetD1Ev)

got(_ZN13GUIAdornMedalD0Ev)

got(_ZN6ecText8DrawTextEffi)

got(_ZN18ecSessionInterfaceD1Ev)

got(_ZN10GUINewGameC2Ev)

got(_ZN7GUIBankD1Ev)

got(_ZN8CGameRes10RenderPortEff)

got(_Z9ecGetUUIDRSs)

got(_ZN10CObjectDef19ReleaseConquestListEv)

got(_ZN10GUISelArmyC1Ev)

got(_ZN16TiXmlDeclarationD1Ev)

got(_ZN14CPlayerManager17onPlayerConnectedEPKc)

got(_ZN13CActionAssist17purChaseCardsCardEv)

got(_ZN12TiXmlCommentD1Ev)

got(_ZN15ecEffectManager12CreateEffectEPKc)
bss(_ZN10CObjectDef10m_InstanceE, 8)

got(_ZN13GUIAdornMedalC1Ev)

got(_ZN8CCountry8FindAreaEi)

got(_ZN11GUICardList8OnUpdateEf)

got(_ZN17GUICommanderMedal8OnUpdateEf)

got(_ZN10CCSoundBox9PlayMusicEb)

got(_ZN18ecSessionInterface4InitEP17ecSessionDelegate)

got(_ZN9TiXmlText5ParseEPKcP16TiXmlParsingData13TiXmlEncoding)

got(_ZN7ecImage9Render4VCEffffffffif)

got(_ZN10GUIService7OnEventERK5Event)

got(_ZN11GUIButtonExD1Ev)

got(_ZN11GUILevelSelD2Ev)

got(_ZN12CGameManagerC1Ev)

got(_ZN13GUIMatchSetup16CreatCorsButtonsEv)

got(_ZN6CMedalC1Ev)

got(_ZN18ecSessionInterface13GetDeviceNameERSs)

got(_ZN12TiXmlComment9ToCommentEv)

got(_ZN6CScene4InitEPKci)

got(_ZN18ecSessionInterface10DisconnectEPKc)

got(_ZN8CCountry19CheckCardTargetAreaEP7CardDefi)

got(_ZN14CPlayerManager18SendPacketToServerE9PACKET_IDPKvi)

got(_ZN5CArea12IsArmyActiveEi)

got(_Z13GetNumBattlesi)

got(_ZN14GUICorpsButtonC2Ev)

got(_ZN9ecElement11SetCurFrameEi)

got(_ZNK16TiXmlDeclaration13ToDeclarationEv)

got(_ZN9ecElement4StopEv)

got(_ZN11ecEffectResD2Ev)

got(_ZN10CLogoState15EnterForegroundEv)

got(_ZN13CGameSettingsC1Ev)

got(_ZN9CSoundRes4LoadEv)

got(_ZN10GUISelArmyD2Ev)

got(_ZN6CScene15GetSelectedAreaEv)

got(_ZN14GUICorpsButtonD1Ev)

got(_ZN5CArea12EncirclementEv)

got(_ZN12CGameManager10LoadBattleEPKc)

got(_Z12JString2CStrP7_JNIEnvP8_jstring)

got(_ZN6ecTextD2Ev)

got(_ZNK12TiXmlElement7GetTextEv)

got(_ZN10CLogoStateD2Ev)

got(_ZN10CObjectDef15LoadUnitMotionsEv)
bss(LangDir, 256)

got(_ZN5CArmyC2Ev)

got(_ZN14CPlayerManager22onReveivedDataFromPeerEPKviPKc)

got(_ZN5CArea11HasArmyCardEi)

got(_ZN12CGameManager12NextDialogueEv)

got(_ZN3MD516bytesToHexStringEPKhm)

got(_ZN14GUICorpsButton8OnRenderEv)

got(_ZN6CMedal4InitEff)

got(_ZN18ecSessionInterface20SendPacketToAllPeersEPKvi)

got(_ZN10CEditStateD1Ev)

got(_ZNK9TiXmlNode6ToTextEv)

got(_ZN9GUIButtonC2Ev)

got(_ZN11CBackground6RenderEP7CCamera)

got(_ZN12CGameManager18GetDialogueByIndexEi)

got(_ZN14CPlayerManager17IsAllPlayersReadyEv)

got(_ZN7CCamera14SetPosAndScaleEfff)

got(_ZN10GUIManagerC2Ev)

got(_ZN3MD56updateERSt14basic_ifstreamIcSt11char_traitsIcEE)

got(_ZN11GUISaveItemD1Ev)

got(_ZN10CLogoState6OnExitEv)

got(_ZN11GUILevelSel7OnEventERK5Event)

got(_ZN10GUINewGame12IsShowSurveyEv)

got(_ZN10CEditStateC2Ev)

got(_ZN14GUIRadioButton8OnRenderEv)

got(_ZN16GUIMotionManager8SetSpeedEjff)

got(_ZN9TiXmlTextD0Ev)

got(_ZN10CGameState16UpdateActionInfoEv)

got(_ZN16GUIMotionManager9AddMotionEP10GUIElementffffft)

got(_ZN11GUIMainMenuD1Ev)

got(_ZN10GUIManagerD1Ev)

got(_ZN5CAreaD1Ev)

got(_ZN10GUIVictoryC1Ev)

got(_ZN13GUISelCountry7OnEventERK5Event)

got(_ZNK9TiXmlNode15PreviousSiblingEPKc)

got(_ZN10CMenuState6RenderEv)

got(_ZN5CArea13SetMoveInArmyEPS_P5CArmybbPKc)

got(_ZNK9TiXmlNode15IterateChildrenEPKcPKS_)

got(_ZN9GUIResultC2Ev)

got(_ZN11GUIMainMenuC2Ev)

got(_ZN9ecElement10ChangeItemEP10ecItemDataS1_P9ecLibrary)

got(_ZN10GUIServiceC1Ev)

got(_ZN10GUIVictoryD0Ev)

got(_ZN10CEditState10TouchBeginEffi)

got(_ZN10CLogoState6UpdateEf)

got(_ZN8CCountry16IsEnoughIndustryEP7CardDef)

got(_ZN11GUILevelSel4InitERK7GUIRecti)

got(_ZN14GUICountryListC1Ev)

got(_ZN5CArea9TurnBeginEv)

got(_ZN12TiXmlElementC1EPKc)

got(_ZN6GUIEnd7OnEventERK5Event)

got(_ZN13GUIBattleItem4InitEiiRK7GUIRect)

got(_ZN12CBattleScene9AddEffectEPKcff)

got(_ZN7CCamera13SetAutoFixPosEb)

got(_ZN12CGameManager21GetNewDefeatedCountryEv)

got(_ZN8ecEffect6IsLiveEv)

got(_ZN11GUIDefeated4InitERK7GUIRect)

got(_ZN12CBattleScene12ReleaseUnitsEv)

got(_ZN11GUIButtonEx8OnRenderEv)

got(_ZN14TiXmlAttribute11SetIntValueEi)

got(_ZN6ecFile4SeekEli)

got(_ZN8CCountry16GetCurCardTargetEv)

got(_ZN12CBattleScene12ClearCratersEv)

got(_ZN18ecEffectResManagerD2Ev)

got(_ZN10CCommander15SetBattlePlayedEii)

got(_ZN10GUIServiceD2Ev)

got(_ZN9GUIBattleD2Ev)

got(_ZN10GUINewGame4InitERK7GUIRect)

got(_ZN11CMatchState6RenderEv)

got(_ZN10CCSoundBox9StopAllSEEv)

got(_ZN10CBaseState11BackPressedEv)

got(_ZN13GUIBattleItemC1Ev)

got(_Z7GetRandv)

got(_ZN9ecLibrary11GetItemNameEj)

got(_ZN10GUIManager6UpdateEf)

got(_ZN10CGameState15EnterBackgroundEv)

got(_ZN8CCountry12IsConquestedEv)

got(_ZN9GUIBattleC1Ev)

got(_ZN6GUITaxC1Ev)

got(_ZN13CStateManager7KeyDownEi)

got(_ZN9ecElementC1Ev)

got(_ZN8ecEffectD2Ev)

got(_ZN12GUITutorails8OnRenderEv)

got(_ZN3MD56encodeEPKmPhm)

got(_ZN14GUICountryListD2Ev)

got(_ZN7GUITextC1Ev)

got(_ZN10GUICardTab7OnEventERK5Event)

got(_ZN10CCSoundBox9StopMusicEv)

got(_Z22ecSetIdleTimerDisabledb)

got(_ZN9TiXmlNode10FirstChildEPKc)

got(_ZN16GUIMotionManagerD2Ev)

got(_ZN6ecText4InitEP9ecUniFont)

got(_ZN7CPlayerD2Ev)

got(_ZN7CPlayer7SendAckEi)

got(_ZN8CCountry15GetFirstCapitalEv)

got(_ZN10CCSoundBox9LoadMusicEPKcS1_)

got(_ZN10ecGraphicsC1Ev)

got(_ZN13ecStringTableC2Ev)

got(_ZN12GUIAttackBox9SetAttackEii)
bss(g_Commander, 376)

got(_ZNK11TiXmlHandle17FirstChildElementEPKc)

got(_ZN15GUIProductPrice8OnRenderEv)

got(_ZN8CCountry15AirstrikeRadiusEv)

got(_ZNK12TiXmlElement9StreamOutEP14TiXmlOutStream)

got(_ZN9ecGameKit19GetMatchPlayersInfoEv)

got(_ZN11GUIDialogue7OnEventERK5Event)

got(_ZN9TiXmlBase14SkipWhiteSpaceEPKc13TiXmlEncoding)

got(_ZN12GUICorpsInfoD0Ev)

got(_ZN13CStateManager9TouchMoveEffi)

got(_ZN10CCSoundBox11UpdateSoundEv)

got(_ZN15ecEffectManagerD1Ev)

got(_ZN8GUIMedalD2Ev)

got(_ZN10CFightText4InitEffP9ecUniFont)

got(_ZN13CActionAssist14searchNodeByIDEii)

got(_ZN14GUIExitWarning8OnRenderEv)

got(_ZN10GUIWarningC2Ev)

got(_ZN8ecEffectC1Ev)

got(_ZNK9TiXmlText9StreamOutEP14TiXmlOutStream)

got(_ZN14CPlayerManager16GetNumRightCorpsEv)

got(_ZN7CBomber8BombAreaEii)

got(_ZN9GUIButtonD0Ev)

got(_ZN11CMatchState9TouchMoveEffi)

got(_ZN7ecShapeC1Ev)

got(_ZN14CPlayerManager14onMatchRequestEv)

got(_ZN10ecGraphics12SetBlendModeEi)

got(_ZN14GUICountryItem11SetSelectedEb)
bss(_ZGVZN9CActionAI8InstanceEvE10S_ActionAi, 8)

got(_ZN16TiXmlDeclaration5ParseEPKcP16TiXmlParsingData13TiXmlEncoding)

got(_ZN12CGameManager14GetCurDialogueEv)

got(_ZN6GUIEndD0Ev)

got(_ZN10GUIWarningD1Ev)

got(_ZN12CBattleSceneD1Ev)

got(_ZN17GUICommanderMedal8OnRenderEv)

got(_ZN5CArea17CheckEncirclementEv)

got(_ZN6ecFile4OpenEPKcS1_)

got(_ZN13GUIAIProgress17SetCurCountryNameEPKc)

got(_ZN6CFight17GetDefenderResultEi)

got(_ZN10CGameState6OnExitEv)

got(_ZN12GUISmallCardC1Ev)

got(_ZN8CGameRes18RenderConstructionEiiff)

got(_ZN10GUICardTab4InitERK7GUIRect)

got(_ZN5CArmy11AddStrengthEi)

got(_ZN7CCamera4InitEffff)
bss(g_StringTable, 48)

got(_ZN9GUIResult8OnUpdateEf)

got(_ZN11GUILevelSel8OnRenderEv)

got(_ZN11CMatchState8TouchEndEffi)

got(_ZN9CAreaMark7GetMarkEii)

got(_ZN10GUIWarning7OnEventERK5Event)

got(_ZN6CScene20CreateRenderAreaListEv)

got(_ZN9GUIButton7SetGlowEPKc)

got(_ZN12GUITutorails4InitERK7GUIRect)

got(_ZN13CActionAssist16actionToNextAreaEiiii)

got(_ZN11CMatchState10TouchBeginEffi)

got(_ZN11GUIArmyItemD2Ev)

got(_Z9Get2XPathPKcS0_)

got(_ZN13GUIBattleItemD1Ev)

got(_ZN10ecGraphicsD1Ev)

got(_ZN5CArea15MoveArmyToFrontEP5CArmyb)

got(_ZN12GUISelBattleC1Ev)

got(_ZN10GUIElementC2Ev)

got(_ZN10CFightTextD1Ev)

got(_ZN6CMedalC2Ev)

got(_ZN5CArea18SetAllArmyMovementEi)

got(_ZN6CScene13IsRectInSecenEffff)

got(_ZN7ecLayer11SetCurFrameEi)

got(_ZN10CMenuState9TouchMoveEffi)

got(_ZN7CBomber6RenderEv)

got(_ZN7GUITech8OnUpdateEf)

got(_ZN11CBackground9RenderBoxEP7CCameraffff)

got(_ZN10GUIElement11MoveToFrontEPS_)

got(_ZN10CGameState10SelectAreaEi)

got(_ZN14CPlayerManager16SessionNoNetworkEv)

got(_ZN6CScene10SelectAreaEi)

got(_ZN16GUIMotionManager12ActiveMotionEjh)

got(_ZN9ecUniFont7ReleaseEv)

got(_ZN10CCSoundBox6PlaySEEPKc)

got(_ZN11GUIButtonEx12SetImageTextEPKcS1_)

got(_ZN10GUIBuyCardC1Ev)

got(_ZN6CScene20AllAreasEncirclementEv)

got(_ZN9TiXmlNode6ToTextEv)

got(_ZN9GUIResult8OnRenderEv)

got(_ZN12CGameManager20GetPlayerCountryNameEi)

got(_ZN16GUILockedWarningD2Ev)

got(_ZN11GUIMainMenu6ShowADEv)

got(_ZN13CTouchInertia10TouchBeginEffi)

got(_ZN8CCountry16GetCommanderNameEv)
bss(_ZN10GUIElement12s_TextureResE, 96)

got(_ZN11GUICardList7OnEventERK5Event)

got(_ZN8CGameRes7ReleaseEv)

got(_ZN13GUIActionInfoD1Ev)

got(_ZN13GUIBattleListD1Ev)

got(_ZN14GUICountryListD0Ev)

got(_ZN6GUIEndC1Ev)

got(_ZN8CCountry14IsActionFinishEv)

got(_ZN13CTouchInertiaD1Ev)

got(_ZN14GUIRadioButtonD1Ev)

got(_ZN12GUIAttackBoxC2Ev)

got(_ZN11GUICardList11ResetSelectEv)

got(_ZNK16TiXmlDeclaration5PrintEP7__sFILEi)

got(_ZN9ecElementD2Ev)

got(_ZN13CTouchInertia6UpdateEf)

got(_ZNK12TiXmlComment5PrintEP7__sFILEi)

got(_ZN10GUIBuyCardD2Ev)

got(_ZN10CEditState7KeyDownEi)

got(_ZN13GUIBattleList9SetSelectEi)

got(_ZN12GUISelBattle13LoadImageListEii)

got(_ZN11GUIPauseBox8OnRenderEv)

got(_ZN16ecParticleSystemC2Ev)

got(_ZN11CBackgroundD2Ev)

got(_ZN19GUIConnectHostStateC1Ev)

got(_ZN10CEditState8TouchEndEffi)

got(_ZN15ecMultipleTouch8InstanceEv)

got(_ZN15GUIProductPriceD2Ev)
bss(strVersionName, 8)

got(_ZN11GUIArmyItem8OnRenderEv)

got(_ZN12GUIScrollBar8OnRenderEv)

got(_ZN10CEditState6OnExitEv)
bss(g_LocalizableStrings, 48)

got(_ZN10GUINewGame7OnEventERK5Event)

got(_ZN6CScene15CheckAttackableEiii)

got(_ZN7GUIGold8OnUpdateEf)

got(_ZNK9TiXmlNode17FirstChildElementEPKc)

got(_ZN8CGameResC2Ev)

got(_ZN10GUIElement9PostEventERK5Event)

got(_ZN5CArea15SetConstructionEii)

got(_ZN10GUINewGame14BtnSurveyClickEv)

got(_ZN9TiXmlNodeD0Ev)

got(_ZN7GUITextD1Ev)

got(_ZN11CBackgroundC1Ev)

got(_ZN10GUIVictory8OnUpdateEf)

got(_ZN5CAreaC1Ev)

got(_ZN11TiXmlString6appendEPKcm)

got(_ZNK12TiXmlComment9StreamOutEP14TiXmlOutStream)

got(_ZN14CPlayerManager34onLocalPlayerAuthenticationChangedEv)

got(_ZN7CCamera12SetSceneRectEffff)

got(_ZN19GUIConnectHostStateD2Ev)

got(_ZN8CCountry13IsEnoughMoneyEP7CardDef)

got(_ZN9TiXmlBase14StringToBufferC1ERK11TiXmlString)

got(_ZN14CPlayerManager9InitCorpsEi)

got(_ZN10CObjectDefD2Ev)

got(_ZN16TiXmlParsingData5StampEPKc13TiXmlEncoding)

got(_ZNK17TiXmlAttributeSet4FindERK11TiXmlString)

got(_ZN9TiXmlNode17FirstChildElementEv)

got(_ZN12TiXmlUnknownD2Ev)

got(_ZN3MD5C1ERSt14basic_ifstreamIcSt11char_traitsIcEE)

got(_ZN6CScene9DelAdjoinEii)

got(_ZN8CCountry19CheckCardTargetArmyEP7CardDefii)

got(_ZN10CMenuState6OnExitEv)

got(_ZN14CPlayerManager22SendPacketToAllPlayersE9PACKET_IDPKvi)

got(_ZN10ecGraphics23CreateTextureWithStringEPKcS1_iiii)

got(_ZplRK11TiXmlStringS1_)

got(_ZN12TiXmlCommentC2ERKS_)

got(_ZplPKcRK11TiXmlString)

got(_ZN10GUIElement7OnEventERK5Event)

got(_Z25ecGameWillEnterForegroundv)

got(_ZN6CScene15RenderAreasArmyEv)

got(_ZN11GUIHostList13ClearHostListEv)

got(_ZN8CGameRes18RenderInstallationEiff)

got(_ZN10GUINewGame16GetIabEventImageEv)

got(_Z10ecTouchEndffi)

got(_ZN16ecParticleSystemD1Ev)

got(_Z17GetBattleFileNameiiiiPc)

got(_ZN15GUIProductPriceC2Ev)

got(_ZN13CStateManager4TermEv)

got(_ZN7CBomber6UpdateEf)

got(_ZN7CBomberD1Ev)

got(_ZN9GUIButtonD2Ev)

got(_ZN14GUICountryItemC1Ev)

got(_ZN14CPlayerManager14onReceivedDataEPKviPKcb)

got(_ZN9ecElement6RenderERK7ecMtx32)

got(_ZN8GUIImage4InitEPKcRK13ecTextureRectRK7GUIRectbbb)

got(_ZN8CGameRes12RenderUIArmyEPKcffibiiiii)

got(_ZN9TiXmlNode15PreviousSiblingEPKc)

got(_ZN12TiXmlCommentaSERKS_)

got(_ZN12CGameManager12IsManipulateEv)

got(_ZN5CArmy14GetMaxStrengthEv)

got(_ZN15ecMultipleTouch10TouchBeganEff)

got(_ZN13GUISelCountry4InitERK7GUIRecti)

got(_ZN10GUIVictory7OnEventERK5Event)

got(_ZN9TiXmlNode12LinkEndChildEPS_)

got(_ZN6GUIIap7OnEventERK5Event)

got(_ZN10GUIOptions4InitERK7GUIRect)

got(_ZN9ecElement4PlayEv)

got(_ZN10GUINewGame17GetPromotionImageEv)

got(_ZN10GUIManager8AddImageEPKcRK13ecTextureRectRK7GUIRectP10GUIElementb)

got(_ZN6ecFile5WriteEPKvj)

got(_ZN14GUICountryItemD2Ev)

got(_ZN16GUIMotionManager10AddMotionYEP10GUIElementfft)

got(_ZN12CGameManager11ClearBattleEv)

got(_ZN13TiXmlDocument8LoadFileEPKc13TiXmlEncoding)

got(_ZN10GUISelArmy7OnEventERK5Event)

got(_ZN13GUISelCountryC1Ev)

got(_ZN10ecGraphics12RenderTripleEPK8ecTriple)

got(_ZN16ecParticleSystem6RenderEv)

got(_ZN8GUIImageD1Ev)

got(_ZN14CPlayerManager18SendPacketToPlayerE12PacketHeaderPKviPKc)

got(_ZNK11TiXmlHandle5ChildEi)
bss(g_Font3, 80)

got(_ZN10GUIBuyCard15SetSelCardIntroEv)

got(_ZN13CActionAssist21purChaseConstructCardEv)

got(_ZN12CBattleScene6AttackEv)

got(_ZN14CPlayerManager4StopEv)

got(_ZN9ecUniFontD2Ev)

got(_ZN11GUIHostListD2Ev)
bss(g_Font1, 80)

got(_ZN9ecElement10ChangeItemEPKcS1_P9ecLibrary)

got(_ZN10CGameState11ShowWarningEi)

got(_Z14ecIsFullScreenv)

got(_ZN7GUISaveD0Ev)

got(_ZN9CActionAI11detectCardsE7CARD_ID)

got(_ZN10CGameState15ResetTouchStateEv)

got(_ZN18ecEffectResManager19ReleaseAllEffectResEv)

got(_ZN14TiXmlAttribute5ParseEPKcP16TiXmlParsingData13TiXmlEncoding)

got(_ZN10CLoadStateD1Ev)

got(_ZN18ecEffectResManager16ReleaseEffectResEP11ecEffectRes)

got(_ZN17GUICommanderMedal13SetArrowColorEj)

got(_ZN12GUISelBattle7OnEventERK5Event)

got(_Z12ecShowReviewv)

got(_ZN10GUIBuyCard13ReleaseTargetEv)

got(_ZN11GUIHostListC1Ev)

got(_ZN9ecUniFontC1Ev)

got(_ZN16GUIMotionManager11ClearMotionEv)

got(_ZN14CPlayerManager17RemoveCorpsPlayerEP7CPlayer)

got(_ZN9ecElement7SetLoopEi)

got(_ZNK9hgeVector5AngleEPKS_)

got(_ZN9ecLibraryC2Ev)

got(_ZN9TiXmlNode15IterateChildrenEPKcPS_)

got(_ZN7GUICard8SetPriceEi)

got(_ZN9ecUniFont4InitEPKcb)

got(_Z13ecTextureLoadPKcRiS1_Rj)

got(_ZN11GUIDialogue8OnUpdateEf)

got(_ZN9TiXmlNode16InsertAfterChildEPS_RKS_)

got(_ZN9ecGameKit25ShowMatchmakerWithRequestEiii)

got(_ZN10GUIElement11RemoveChildEPS_)

got(_ZN10CGameState6RenderEv)

got(_ZN11GUIDefeated8OnUpdateEf)

got(_ZN14GUICountryList7OnEventERK5Event)

got(_ZN11GUISaveItemD2Ev)

got(_ZN13GUIActionInfoC1Ev)

got(_ZN6CScene13CheckAdjacentEii)

got(_ZN5CArea13SetArmyActiveEib)

got(_ZN11GUIHostItem7SetNameEPKc)

got(_ZN8GUIImageC2Ev)

got(_Z11ecGamePausev)

got(_ZN16ecParticleSystem6UpdateEf)

got(_ZN11GUISaveItemC1Ev)

got(_ZN9ecGameKit4InitEP17ecGameKitDelegateb)

got(_ZN14GUICountryList9SetSelectEi)

got(_ZN6ecFile9GetCurPosEv)

got(_ZN6CFight11FirstAttackEii)

got(_ZN7ecFrame4StopEv)

got(_ZN15ecMultipleTouchC1Ev)

got(_ZN8CCountry6ActionERK13CountryAction)

got(_ZN16GUIUpgradeButtonD1Ev)

got(_ZN9GUIBattle13UpateFightingEf)

got(_ZN10GUINewGame15IsShowSurveyTipEv)

got(_ZN12TiXmlElementD1Ev)

got(_ZN6GUITaxD0Ev)

got(_ZN16GUIUpgradeButtonC2Ev)

got(_ZN10CObjectDef16GetUnitPositionsEPKc)
bss(loadClassMethod_methodID, 8)

got(_ZN11GUISaveItem8OnUpdateEf)

got(_ZN10GUIManager12AddScrollBarERK7GUIRectP10GUIElementPKcS6_iiiii)

got(_ZN10CEditState6UpdateEf)

got(_ZN12CBattleScene6RenderEv)

got(_ZN12GUISelBattle9SelBattleEii)

got(_ZN14CPlayerManager20onPlayerDisconnectedEPKc)

got(_ZN12GUICommander7OnEventERK5Event)

got(_ZN12CGameManager20GetCurDialogueStringEPc)

got(_ZN13GUIAdornMedal4InitER7GUIRect)

got(_ZN13GUIMatchSetup18RefreshCorsButtonsEv)

got(_ZN11GUIPauseBoxD1Ev)

got(_ZN7ecLayerC2Ev)

got(_ZN9ecLibrary4LoadEPKcR12ecTextureRes)

got(_Z22ecApplicationTerminatev)

got(_Z15ecAccelerometerfff)

got(_ZNK9TiXmlText5BlankEv)

got(_ZN17TiXmlAttributeSet3AddEP14TiXmlAttribute)

got(_ZN13GUISelCountry16ReleaseImageListEv)

got(_ZN5CArea16LostArmyStrengthEii)

got(_ZN6CScene12ScreenToAreaEff)

got(_ZN11GUIDialogueC1Ev)

got(_ZN13CStateManager15EnterBackgroundEv)

got(_ZN10GUINewGame12IsImageReadyEv)

got(_ZN13ecStringTable9GetStringEPKc)

got(_ZNK12TiXmlElement20QueryDoubleAttributeEPKcPd)

got(_ZN14CPlayerManager13DoFrontActionEv)

got(_ZN6CScene19GetTwoAreasDistanceEii)

got(_ZN10CObjectDef17ReleaseBattleListEv)

got(_ZN7GUICard11SetIndustryEi)

got(_ZN6CFightD2Ev)

got(_ZN12ecTextureResD1Ev)

got(_ZN18ecEffectResManagerC2Ev)

got(_ZN7ecLayerD1Ev)

got(_ZN10GUILoading8OnRenderEv)

got(_ZN13GUISelCountryD0Ev)

got(_ZNK11TiXmlHandle12ChildElementEi)

got(_ZN5CArea11DelArmyCardEii)

got(_ZN7GUIBank7OnEventERK5Event)

got(_ZN7GUIText4InitERK7GUIRectP9ecUniFont)

got(_ZN10GUIOptionsC2Ev)

got(_ZN8GUIBeginD1Ev)

got(_ZN3MD5C1ERKSs)

got(_ZN12GUIAttackBoxD0Ev)

got(_ZN9GUIButton8SetAlphaEf)

got(_ZN11GUIDialogueD0Ev)

got(_Znwm)

got(_ZN8CCountry4InitEPKcS1_)

got(_ZN10CObjectDef7DestroyEv)

got(_ZN12GUISmallCardC2Ev)

got(_ZN12GUIScrollBarD2Ev)

got(_ZN12GUISelBattle16ReleaseImageListEv)

got(_ZN12CGameManager15GetNumCountriesEv)

got(_ZN6CScene15RenderAreasTypeEv)

got(_ZN10GUIOptionsD0Ev)

got(_ZN6CFight12GetDefendAddEi)

got(_ZN14CPlayerManager9AddPlayerEbPKc)

got(_ZN12GUISmallCardD1Ev)

got(_ZN9CSoundResC2Ev)

got(_ZN8GUIBeginC2Ev)

got(_ZN12CGameManager7EndTurnEv)

got(_ZNK11TiXmlHandle17FirstChildElementEv)

got(_ZNK11TiXmlHandle10FirstChildEPKc)

got(_ZN5CArea7AddArmyEP5CArmyb)

got(_ZN14CPlayerManager10StartMatchEv)

got(_ZN8CCountry14SetCardTargetsEP7CardDef)

got(_ZN8ecEffect6UpdateEf)

got(_Z13ecScrollWheelfff)

got(_ZN13CGameSettingsD1Ev)

got(_ZN10GUIElement6CenterEv)

got(_ZN10CLogoState6RenderEv)

got(_ZN11CMatchStateC2Ev)

got(_ZN12GUISelBattleD1Ev)

got(_ZN19GUIConnectHostState4InitER7GUIRect)

got(_ZN5CArea7TurnEndEv)

got(_ZN8GUIMedalD0Ev)

got(_ZN12ecTextureRes7ReleaseEv)

got(_ZN8ecEffect4FireEv)

got(_ZN14TiXmlAttributeD1Ev)

got(_ZN9ecElement4InitEPKcP9ecLibrary)

got(_ZN6CScene14SetAreaCountryEiP8CCountry)
bss(g_Font7, 80)

got(_ZN11CBackground4InitEiiiiiffff)

got(_ZN9ecElement4InitEP10ecItemDataP9ecLibrary)

got(_ZN14GUIBattleIntroC2Ev)

got(_ZN8CCountry18FindAdjacentAreaIDEib)

got(_ZN10CGameState11ReleaseGameEv)

got(_ZN10CGameState10TouchBeginEffi)

got(_Z11SetRandSeedi)

got(_ZN14CPlayerManager12onStartMatchEv)

got(_ZN6CScene14SaveAreaEnableEPKc)

got(_ZN10GUICardTabC1Ev)

got(_ZN13CTouchInertia8GetSpeedERfS0_)

got(_ZN6GUIIap14SetLocalePirceEiPKc)

got(_ZN7CPlayer10RecvPacketEPKvi)

got(_ZN10CGameState6UpdateEf)

got(_ZN11GUIArmyItemC2Ev)

got(_ZN14GUIExitWarningC2Ev)

got(_ZN9ecGameKit18GetLocalPlayerInfoER12ecPlayerInfo)

got(_ZN8CCountry10CanBuyCardEP7CardDef)

got(_ZN6CScene11LoadAreaTaxEi)

got(_ZN5CArea12CanConstructEi)

got(_ZN10CFightText6UpdateEf)

got(_ZN8CCountry8GetTaxesEv)

got(_ZN10GUIElement4MoveEff)

got(_ZN13CStateManager10TouchBeginEffi)
bss(g_GameManager, 248)

got(_ZN12TiXmlElement9ToElementEv)

got(_ZN9GUIResultD2Ev)

got(_ZN10GUICardTabD0Ev)

got(_ZNK12TiXmlElement9AttributeEPKcPd)

got(_ZN10CCSoundBox18DestroySoundSystemEv)

got(_ZN7ecImage13RenderStretchEffff)

got(_ZN15ecEffectManager6RenderEv)

got(_ZN10CLoadState8TouchEndEffi)

got(_ZN12ecTextureRes10GetTextureEPKc)

got(_Z14ecSaveLibrarayPKcR13ecLibraryDataS0_i)

got(_ZNK9TiXmlNode11NextSiblingEPKc)

got(_ZNK9TiXmlNode9ToElementEv)

got(_ZN10ecGraphics9RenderEndEv)

got(_Z17ecWEBPTextureLoadPKcRiS1_Rj)

got(_ZN9GUIResultC1Ev)

got(_ZN10CGameState18PlayerCountryBeginEv)

got(_ZN8GUIMedalC2Ev)

got(_ZN14GUIExitWarning7OnEventERK5Event)

got(_Z15ecInAppPurchasei)

got(_ZNK11TiXmlHandle5ChildEPKci)

got(_Z12ecGameResumev)

got(_ZN13CStateManager15EnterForegroundEv)

got(_ZN11CBattleUnit4InitEiiP9ecLibraryP11UnitMotions)

got(_ZN9CAreaMarkC2Ev)

got(_ZN12CGameManager8SaveGameEPKc)

got(_ZN12GUIAttackBoxD2Ev)

got(_ZN10GUIManager9AddButtonEPKcS1_RK7GUIRectP10GUIElementP9ecUniFont)

got(_ZN9ecLibrary12FindItemDataEPKc)

got(_ZN12GUISelBattleC2Ev)

got(_ZN13TiXmlDocument8LoadFileE13TiXmlEncoding)

got(_ZN6CFight12NormalAttackEii)

got(_ZN12GUIScrollBar7OnEventERK5Event)

got(_ZN14CPlayerManager14SetCorpsByDataEPviP7CPlayer)

got(_ZN17TiXmlAttributeSetD2Ev)

got(_ZN13GUISelCountry9SelBattleEii)

got(_ZN14GUIRadioButtonC2Ev)

got(_ZN10GUIElementD2Ev)

got(_ZN13CFightTextMgr6RenderEv)

got(_ZN16GUIMotionManager10AddMotionXEP10GUIElementfft)

got(_ZN7ecImage8SetAlphaEfi)

got(_ZN5CArea10MoveArmyToEPS_)

got(_ZN18ecSessionInterfaceD2Ev)

got(_ZN10GUIElement6GetPosERfS0_)

got(_ZN14GUICorpsButtonD0Ev)

got(_ZNK9TiXmlNode9ToCommentEv)

got(_ZN10CLogoStateC1Ev)

got(_ZN16GUIMotionManagerD1Ev)

got(_ZN13GUIMatchSetupC1Ev)

got(_ZN14GUICorpsButtonC1Ev)

got(_ZN11ecLabelText7SetTextEPKc)

got(_ZN13CActionAssist17purChaseDraftCardEb)

got(_ZN13CStateManager11ScrollWheelEfff)

got(_ZN11GUIDialogue8OnRenderEv)

got(_ZN11CBattleUnitC2Ev)

got(_ZN10CLogoStateD1Ev)

got(_ZN12TiXmlElement15RemoveAttributeEPKc)

got(_ZN7_JNIEnv22CallStaticObjectMethodEP7_jclassP10_jmethodIDz)

got(_ZN10CGameState16UpdateAIProgressEv)

got(_ZN5CArmyC1Ev)

got(_ZN19GUIConnectHostState8OnRenderEv)
bss(TEXTURE_RAM_OPTIMIZE, 1)

got(_ZN11GUIDialogueD2Ev)

got(_ZN12ecTextureRes11CreateImageEPKcS1_ffffff)

got(_ZN13CStateManager11GetStatePtrE6EState)

got(_ZN16GUIMotionManagerC2Ev)

got(_ZN14CPlayerManager9StopMatchEv)

got(_ZN6CScene17GetAdjacentAreaIDEii)

got(_ZN13CStateManager11SetCurStateE6EState)

got(_ZNK9TiXmlNode17FirstChildElementEv)

got(_ZN17GUICommanderMedal4InitERK7GUIRecti)

got(_ZN11CBattleUnit12SetDestroyedEv)

got(_ZN9GUIBattle11ResetBattleEv)

got(_ZN12TiXmlCommentC1ERKS_)

got(_ZN10CObjectDef11LoadArmyDefEv)
bss(sTimeOffset, 8)

got(_ZN10GUINewGame14GetSelectGroupEP14GUIRadioButton)

got(_ZN7ecFrameC1Ev)

got(_ZN12TiXmlElement9ReadValueEPKcP16TiXmlParsingData13TiXmlEncoding)

got(_Z11GetRandSeedv)

got(_ZN6ecFile4ReadEPvj)

got(_ZN7ecImageC2EP11ecImageAttr)

got(_ZN14CPlayerManager7ConnectEPKci)

got(_ZN12GUITutorailsC1Ev)

got(_ZN10GUIOptions8OnRenderEv)

got(_ZN9ecGameKit10SendPacketEPKviPKc)

got(_ZN3MD5C2EPKvm)

got(_ZN12CGameManager4InitEv)

got(_ZN12CGameManager7NewGameEiiii)

got(_ZN11CBackgroundC2Ev)

got(_ZN16TiXmlDeclarationC1EPKcS1_S1_)

got(_ZN11CBattleUnit6RenderEv)

got(_Z18ecPurchasedProducti)

got(_ZN10CBaseState9TouchMoveEffi)

got(_ZN7GUIGoldC2Ev)

got(_ZN12ecTextureRes7LoadResEPKcb)

got(_ZN8CCountry17GetCommanderLevelEv)

got(_ZN10CMenuStateD2Ev)

got(_ZN14CPlayerManager4InitEv)

got(_Z24GetNumMultiPlayerBattlesi)

got(_ZN7ecShapeD1Ev)

got(_ZNK14TiXmlAttribute13QueryIntValueEPi)

got(_ZN11GUIDefeated8OnRenderEv)

got(_ZN11GUIPauseBox7OnEventERK5Event)

got(_ZN8CGameRes11GetBattleBGEPKc)

got(_ZN8CGameRes20RenderCommanderMedalEiffi)

got(_ZN12TiXmlElementC2ERKS_)

got(_Z15ecSetFullScreenb)

got(_ZN10CCSoundBoxC2Ev)

got(_ZN8CCountry22FindAdjacentLandAreaIDEib)

got(_ZN10CEditState9TouchMoveEffi)

got(_ZN9ecElement6UpdateEf)

got(_ZN10CCSoundBoxD1Ev)
bss(DocumentFilePath, 256)

got(_ZN11GUIHostItemD2Ev)

got(_ZN12TiXmlUnknown5ParseEPKcP16TiXmlParsingData13TiXmlEncoding)
bss(_ZGVZN13CActionAssist8InstanceEvE14S_ActionAssist, 8)

got(_ZN12GUICommander8OnRenderEv)

got(_ZN7ecShapeC2Ev)

got(_ZN5CArmy16ResetMaxStrengthEb)

got(_ZN15ecEffectManager8InstanceEv)

got(_ZN11GUIWarMedalD0Ev)

got(_ZN10GUISelArmy4InitERK7GUIRect)

got(_ZN10ecGraphicsD2Ev)
bss(asset_mgr, 8)

got(_ZNK9TiXmlNode15IterateChildrenEPKS_)

got(_ZN10CCommander7UpgradeEv)

got(_ZN7GUISave7SelItemEi)

got(_ZN16GUILockedWarningC1Ev)

got(_ZN11GUIDefeatedC2Ev)

got(_ZN7ecImage8Render4VEffffffff)

got(_ZNK14TiXmlAttribute8PreviousEv)

got(_ZN16GUILockedWarningD0Ev)

got(_ZN7ecImage8RenderExEfffff)

got(_ZN11GUIHostList13ConnectFailedEv)

got(_ZN8CGameRes21RenderArmyMovementNumEffi)

got(_ZN10ecGraphics10RenderQuadEPK6ecQuad)

got(_ZN10CCommanderD1Ev)

got(_ZN9TiXmlNode11NextSiblingEPKc)

got(_ZN10GUIElementC1Ev)

got(_ZN8CCountryC2Ev)

got(_ZN6GUITaxC2Ev)

got(_ZN6GUIIapD0Ev)

got(_ZN9TiXmlNodeD2Ev)

got(_ZN7GUISave4InitERK7GUIRectib)

got(_ZN13CTouchInertia4StopEv)

got(_ZN10GUINewGame21OnRadioBtnSurveyClickEv)

got(_ZN13CStateManagerD1Ev)

got(_ZN10CEditStateC1Ev)

got(_ZN7GUIGoldD1Ev)

got(_ZN10ecGraphics13CreateTextureEii)

got(_ZN6CScene16MoveCameraToAreaEi)

got(_ZN10GUICardTab9SelectTabEi)

got(_ZN5CAreaD2Ev)

got(_ZN15ecEffectManager9RemoveAllEv)

got(_ZN14CPlayerManager21GetDisconnectedPlayerEv)

got(_ZN9TiXmlBase14StringToBufferD1Ev)

got(_ZN7GUIText12SetTextColorEj)

got(_ZN18ecSessionInterface15GetPeerNameListERSt4listISsSaISsEES3_)

got(_ZN10GUILoadingD2Ev)

got(_ZN7_JNIEnv21CallStaticFloatMethodEP7_jclassP10_jmethodIDz)

got(_ZN13CStateManagerC2Ev)

got(_ZN11ecEffectResC2Ev)

got(_ZN7_JNIEnv23CallStaticBooleanMethodEP7_jclassP10_jmethodIDz)

got(_ZN10CCommander16GetCommanderDataER13CommanderData)

got(_ZN10CEditStateD0Ev)

got(_ZN10GUIElement6UpdateEf)

got(_ZN13GUIBattleListD0Ev)

got(_ZN7CPlayer7RecvAckEi)

got(_ZN13GUIActionInfoD0Ev)

got(_ZN8CCountryD1Ev)

got(_ZN8CCountry6UpdateEf)

got(_ZNK9TiXmlNode18NextSiblingElementEPKc)

got(_ZN11GUIWarMedalD2Ev)

got(_ZNK12TiXmlElement17QueryIntAttributeEPKcPi)

got(_ZN6CFight16AirStrikesAttackEP8CCountryii)

got(_ZNK14TiXmlAttribute9StreamOutEP14TiXmlOutStream)

got(_ZN10CFightText7SetTextEPKc)

got(_ZN18ecSessionInterface12SetupSessionEb)

got(_ZN9GUIButton13SetTextOffsetEff)

got(_ZN16GUILockedWarningD1Ev)

got(_ZNK13TiXmlDocument5PrintEP7__sFILEi)

got(_ZN13CFightTextMgrD1Ev)

got(_ZN7CBomber9IsBombingEv)
bss(_ZN11TiXmlString8nullrep_E, 24)

got(_ZN7GUICard16SetIndustryColorEj)

got(_ZN7GUITech4InitERK7GUIRect)

got(_ZN12GUICommander8OnUpdateEf)

got(_ZN5CArmyD1Ev)

got(_ZN10CObjectDef8InstanceEv)

got(_ZN8ecEffectD1Ev)
bss(g_NationInfo, 40)

got(_ZN10CCommander19GetNeedUpgradeMedalE11WARMEDAL_ID)

got(_ZN13CActionAssist21purChaseAirStrikeCardEv)

got(_ZN12TiXmlElement5ParseEPKcP16TiXmlParsingData13TiXmlEncoding)

got(_ZN9TiXmlNode9LastChildEPKc)

got(_ZN6ecTextC2Ev)

got(_ZN16ecParticleSystemC1Ev)

got(_ZN7CCamera6MoveToEffb)

got(_ZN10CObjectDef15GetCommanderDefEPKc)

got(_ZN15ecMultipleTouch5ResetEv)

got(_ZN10GUILoadingC1Ev)

got(_ZN10CCommander16GetWarMedalLevelE11WARMEDAL_ID)

got(_ZN13GUIAIProgressD1Ev)

got(_ZN12GUICorpsInfoD1Ev)

got(_ZN16GUIMotionManager10ProcMotionEv)

got(_ZN7ecFrame10ChangeItemEP10ecItemDataS1_P9ecLibrary)

got(_ZN10CMenuState13PeerConnectedEv)

got(_ZN7CPlayer4InitEbPKc)

got(_ZN16TiXmlDeclarationaSERKS_)

got(_ZN10GUILoading7OnEventERK5Event)

got(_ZN7CBomberC2Ev)

got(_ZN14GUICountryItemC2Ev)

got(_ZN10CBaseState6OnExitEv)

got(_ZN8CGameRes14RenderArmyInfoEiffiiiii)

got(_ZN14GUIBattleIntro4InitERK7GUIRectii)

got(_ZN6ecFile21CheckFileExistFromZipEPKcS1_)

got(_Z12ecTouchBeginffi)

got(_ZN9TiXmlNode11RemoveChildEPS_)

got(_ZN10GUINewGame23OnRadioBtnIabEventClickEv)

got(_ZN7ecFrame5ResetEv)

got(_ZN7ecImageC2EP9ecTextureRK13ecTextureRect)

got(_ZN14GUIBattleIntro8OnRenderEv)

got(_ZN8CCountry13GetCardRoundsE7CARD_ID)
bss(g_Num5, 80)

got(_ZN9ecLibrary14GetElementDataEi)

got(_ZN9CSoundResD2Ev)

got(_ZN10GUINewGame13GetAppVersionEv)

got(_ZN12CGameManager11GetPlayerNoEPKc)

got(_ZN8CCountry10RemoveAreaEi)

got(_ZN7GUIGold8OnRenderEv)

got(_ZN9ecLibrary12GetFrameDataEi)

got(_ZN10GUIBuyCardC2Ev)

got(_ZN8CheckMD56INfileEPKcS1_)

got(_ZN12CBattleScene4InitEiPS_)

got(_ZN10CLoadState7OnEnterEv)

got(_ZN14GUIExitWarning4InitERK7GUIRect)

got(_ZN7CCameraC2Ev)

got(_ZNK9TiXmlNode9LastChildEPKc)

got(_ZN10CEditState8InitGameEv)

got(_ZN10CLoadState6UpdateEf)
bss(g_Num1, 80)

got(_ZN13ecStringTableD2Ev)

got(_ZNK14TiXmlAttribute4NextEv)

got(_ZN10GUIElement12FindByHandleEj)

got(_ZN11GUIDefeatedD0Ev)

got(_ZN5CArmy7UpgradeEv)

got(_ZN5CArea8LoadAreaEPK12SaveAreaInfo)

got(_ZN9TiXmlNode9ToUnknownEv)

got(_ZN8GUIMedal4InitERK7GUIRect)

got(_ZN10CCSoundBox14SetMusicVolumeEi)

got(_ZN9TiXmlBase11StringEqualEPKcS1_b13TiXmlEncoding)

got(_ZN12GUICorpsInfoC1Ev)

got(_ZN11CBattleUnit7ReleaseEv)

got(_ZN8CCountry10AddDestroyEi)

got(_Z24ecGameDidEnterBackgroundv)

got(_ZN14CPlayerManager12GetCorpsDataERi)

got(_ZN10ecGraphics10RenderRectEffffm)
bss(g_Num3, 80)

got(_ZN7GUICardD1Ev)

got(_ZN16TiXmlDeclarationC1ERKS_)

got(_ZN10GUIElement6RenderEv)

got(_ZN13TiXmlDocumentC1Ev)

got(_ZN13CFightTextMgr7AddTextEffPKcj)

got(_ZN13ecStringTable4LoadEPKc)

got(_ZN15GUIProductPriceD0Ev)

got(_ZN10CCommander17GetNumBattleStarsEii)

got(_ZN14CPlayerManager8SelCorpsEiiP7CPlayer)

got(_ZN12CGameManager13InitCameraPosEv)

got(_ZN7ecFrameD0Ev)

got(_ZN5CAreaC2Ev)

got(_ZN8CCountry7AddAreaEi)

got(_ZNK12TiXmlUnknown9ToUnknownEv)

got(_ZN12GUISelBattle8OnRenderEv)

got(_ZN7GUICard13SetPriceColorEj)

got(_ZN9CSoundResC1Ev)

got(_ZN9ecElement9NextFrameEv)

got(_ZN10ecGraphics14SetOrientationEi)

got(_ZN11GUIMainMenu13RefreshNewTipEv)

got(_ZN13TiXmlDocumentD2Ev)

got(_ZN6GUIEnd4InitERK7GUIRect)

got(_ZN10GUIVictory4PlayEv)

got(_ZN13GUIActionInfoD2Ev)

got(_ZN13GUIBattleListC1Ev)

got(_ZN8CGameRes12GetArmyImageEPKcib)

got(_Z12ecGameRenderv)

got(_ZN10GUIWarning8OnUpdateEf)

got(_ZN10GUISelArmy10TargetArmyEi)

got(_ZNK9TiXmlText6ToTextEv)

got(_ZN8CGameRes10RenderArmyEPKciiffimbf)

got(_ZN11TiXmlString6assignEPKcm)

got(_ZN8CGameResC1Ev)

got(_ZN9ecUniFontD1Ev)

got(_ZN13GUIBattleList11ResetSelectEv)

got(_ZN11GUIPauseBoxC2Ev)

got(_ZN14CPlayerManager19onPeerListDidChangeEv)

got(_ZN13GUIBattleListD2Ev)

got(_ZN10CLoadStateD2Ev)

got(_ZN16TiXmlDeclaration13ToDeclarationEv)

got(_ZN12CGameManager17GetCountryByIndexEi)

got(_Z7GetPathPKcS0_)

got(_ZN11GUICardList4InitERK7GUIRecti)

got(_ZN12GUIAttackBoxC1Ev)

got(_ZN11GUIHostItem8OnRenderEv)

got(_ZN6CScene12RenderAdjoinEv)

got(_ZN5CArmy8SaveArmyEP12SaveArmyInfo)

got(_ZN9TiXmlBase7IsAlphaEh13TiXmlEncoding)

got(_ZN10GUIWarning4InitERK7GUIRecti)

got(_ZN14CPlayerManager24onReceivedDataFromPlayerEPKviPKc)

got(_ZN6GUIEndC2Ev)

got(_ZN10GUICardTab19GetCardTabButtonIdxEPK10GUIElement)

got(_ZN12CGameManager10SaveBattleEPKc)

got(_ZN12CGameManager4NextEv)

void __attribute__((visibility("hidden"))) resolvesymbol() {
    size_t BaseAddress =
            (size_t) dlsym(dlopen(GameLib, RTLD_NOLOAD), "pauseBackgroundMusicJNI") - 336872;
    off(_ZN11GUISaveItemC2Ev, 512636)
    off(_ZN7ecLayer9NextFrameEv, 1130516)
    off(_ZN11GUIWarMedal8OnUpdateEf, 672940)
    off(_ZN7ecImageC2EP9ecTextureffff, 887656)
    off(_ZN7GUITechC1Ev, 522004)
    off(_ZN14GUICorpsButton4InitERK7GUIRectPKcb, 705356)
    off(_ZN6ecFile5CloseEv, 350936)
    off(_ZN10GUILoading4InitERK7GUIRect, 690932)
    off(_ZN12GUIScrollBarC2Ev, 757656)
    off(_ZN13CActionAssist4isAIEi, 632880)
    off(_ZN14GUICountryList8OnUpdateEf, 744216)
    off(_ZN6CScene9IsBombingEv, 603920)
    off(_ZN10CObjectDef16LoadUnitPositonsEv, 559432)
    off(_ZN5CArea10GetRealTaxEv, 637732)
    off(_ZN13TiXmlDocument10ToDocumentEv, 847820)
    off(_ZN15ecMultipleTouchC2Ev, 350396)
    off(_ZN14GUICountryList4InitERK7GUIRecti, 745988)
    off(_ZN10CCSoundBox15InitSoundSystemEv, 911928)
    off(_ZN14GUIRadioButtonD0Ev, 756920)
    off(_ZN14GUICorpsButton13SetPlayerNameEPKcbS1_iib, 706452)
    off(_ZN13CStateManager6UpdateEf, 608792)
    off(_ZN13ecStringTableD1Ev, 913396)
    off(_ZN7GUITechD0Ev, 521752)
    off(_ZN12GUITutorails8OnUpdateEf, 527080)
    off(_ZN8CCountry8DoActionEv, 670960)
    off(_ZN16GUIUpgradeButtonD2Ev, 674276)
    off(_ZN8GUIImageD0Ev, 751416)
    off(_ZN11CBattleUnit6UpdateEf, 655332)
    off(_ZN12GUIScrollBarD1Ev, 757392)
    off(_ZN19GUIConnectHostStateD1Ev, 683824)
    off(_ZN14CPlayerManager9ReconnectEv, 573228)
    off(_ZN9CAreaMark7ReleaseEv, 644040)
    off(_ZN16ecParticleSystemD2Ev, 918096)
    off(_ZN14CPlayerManager16FindPlayerByUUIDEi, 578760)
    off(_ZN11GUIHostListD1Ev, 683912)
    off(_ZN14TiXmlAttribute8PreviousEv, 841184)
    off(_ZN9TiXmlBase14StringToBufferC2ERK11TiXmlString, 834520)
    off(_ZN15ecMultipleTouchD1Ev, 350336)
    off(_ZN14CPlayerManager12RemovePlayerEP7CPlayer, 581940)
    off(_Z16ecLaunchAppStorePKc, 918020)
    off(_ZN11CBattleUnitD2Ev, 655244)
    off(_ZN18ecSessionInterface11GetPeerNameEPKcRSs, 831120)
    off(_ZN14GUIBattleIntroD2Ev, 469780)
    off(_ZN6CScene15SetCameraToAreaEi, 599140)
    off(_ZN8GUIImageC1Ev, 751608)
    off(_ZN10CObjectDef14ReleaseArmyDefEv, 544084)
    off(_ZN14GUIExitWarningD1Ev, 682200)
    off(_ZN11GUIButtonExC1Ev, 476020)
    off(_ZN14CPlayerManager16PlayerLoadFinishEP7CPlayer, 586928)
    off(_ZN12GUISmallCardD2Ev, 518700)
    off(_ZN12TiXmlElementC2EPKc, 843624)
    off(_ZN13GUISelCountryC2Ev, 729972)
    off(_ZN7ecFrameC2Ev, 1130800)
    off(_ZN14CPlayerManager20onPlayerInfoReceivedERSt4listIP12ecPlayerInfoSaIS2_EE, 577916)
    off(_ZN6ecFile18GetFileDataFromZipEPKcS1_Pm, 351932)
    off(_ZN12CGameManager24MovePlayerCountryToFrontEv, 417728)
    off(_ZN7ecLayerC1Ev, 1129800)
    off(_ZN11TiXmlString7reserveEm, 831140)
    off(_ZN11GUIDefeated12ShowDefeatedEP8CCountry, 491624)
    off(_ZN12GUISmallCard4InitERK7GUIRect, 519284)
    off(_ZN9ecElement11GetPlayTimeEv, 1127176)
    off(_ZN6CScene17SetSelAreaTargetsEP5CArea, 602892)
    off(_ZN11GUISaveItem7SetInfoEPKciiiiiiiib, 513112)
    off(_ZN16TiXmlDeclarationD2Ev, 834860)
    off(_ZN11GUICardListD0Ev, 485696)
    off(_ZN14GUICountryListD1Ev, 744116)
    off(_ZNK12TiXmlElement5PrintEP7__sFILEi, 840304)
    off(_ZN6CFightC1Ev, 398732)
    off(_ZN5CArmy4InitEP7ArmyDefP8CCountry, 644784)
    off(_ZN7ecLayerD0Ev, 1129764)
    off(_ZN10ecGraphics4InitEiiiii, 341344)
    off(_ZN17TiXmlAttributeSetC1Ev, 843456)
    off(_ZN15GUIProductPriceC1Ev, 499380)
    off(_ZN14CPlayerManager15onPeerConnectedEPKc, 582992)
    off(_ZN10CCommander17SetNumBattleStarsEiii, 391624)
    off(_ZN6ecFileC1Ev, 350864)
    off(_ZN10GUIVictoryC2Ev, 528188)
    off(_ZN14CPlayerManager17SendStartLoadGameEv, 586492)
    off(_ZN12ecTextureResC1Ev, 890472)
    off(_ZN14GUICorpsButtonD2Ev, 703496)
    off(_ZN16ecParticleSystem6MoveToEffb, 918244)
    off(_ZN9GUIBattleD1Ev, 465000)
    off(_ZN8CCountry11SaveCountryEP15SaveCountryInfo, 663764)
    off(_ZN7CPlayer15ClearPacketListEv, 737052)
    off(_ZN7GUIGold4InitERK7GUIRect, 497960)
    off(_ZN9TiXmlNode14InsertEndChildERKS_, 835496)
    off(_ZN11GUIArmyItemD0Ev, 516824)
    off(_ZN12ecTextureResD2Ev, 891292)
    off(_ZN8CCountry15GetCardIndustryEP7CardDef, 663476)
    off(_ZN9CAreaMark4InitEi, 644092)
    off(_ZN5CArea18RevertArmyStrengthEi, 639964)
    off(_ZN10GUIVictoryD1Ev, 527560)
    off(_ZN12CGameManager15GetNumDialoguesEv, 410584)
    off(_ZN6CScene8BombAreaEii, 603904)
    off(_ZN9ecGameKit22DisconnectCurrentMatchEv, 831048)
    off(_ZN14GUICountryItem4InitEPKcS1_RK7GUIRect, 744744)
    off(_ZN18ecSessionInterface10SendPacketEPKviPKc, 831112)
    off(_ZNK9TiXmlNode6CopyToEPS_, 835296)
    off(_ZN8CGameRes18RenderUIDefendArmyEPKcffiiiiiiib, 430812)
    off(_ZN10GUIElement9FreeChildEPS_, 750016)
    off(_ZN11GUIHostList7OnEventERK5Event, 689484)
    off(_Z19ecTextureWithStringPKcS0_iiRiS1_Rj, 382716)
    off(_ZN10CBaseState8TouchEndEffi, 397008)
    off(_ZN13TiXmlDocumentD0Ev, 848004)
    off(_ZN9CActionAI15sortArmyToFrontEv, 612876)
    off(_ZN6CScene12UnselectAreaEv, 600008)
    off(_ZN12CGameManager7TurnEndEv, 414920)
    off(_ZN10CLoadState6RenderEv, 531688)
    off(_ZN10ecGraphics12RenderCircleEfffj, 344072)
    off(_ZN12CGameManager12IsLastBattleEv, 410016)
    off(_ZN9CActionAI13moveAndAttackEv, 614612)
    off(_ZN12CBattleScene10StarEffectEi, 652904)
    off(_ZN10GUIManager16UnloadTextureResEPKc, 752864)
    off(_ZN13CTouchInertia13GetStartPointEv, 609728)
    off(_ZN8CCountry12CollectTaxesEv, 668256)
    off(_ZN6CScene19GetNumAdjacentAreasEi, 600032)
    off(_ZN10GUIElement10GetAbsRectER7GUIRect, 750532)
    off(_ZN9TiXmlBase8ReadNameEPKcP11TiXmlString13TiXmlEncoding, 849104)
    off(_ZN14GUICountryList15ResetTouchStateEv, 745324)
    off(_ZN9GUIButton7SetTextEPKc, 749008)
    off(_ZN10GUINewGame8OnRenderEv, 710596)
    off(_ZN10GUIService8OnRenderEv, 733964)
    off(_ZN10ecGraphics11FreeTextureEP9ecTexture, 341884)
    off(_ZNK12TiXmlElement5CloneEv, 846960)
    off(_ZN10CGameStateD0Ev, 445512)
    off(_ZN16ecParticleSystem4InitEP13ecEmitterAttr, 918100)
    off(_ZN7GUICardC2Ev, 486236)
    off(_ZN10GUIBuyCard8OnRenderEv, 476892)
    off(_ZN11GUIHostItemC2Ev, 684960)
    off(_ZN11GUILevelSelD0Ev, 689840)
    off(_ZN10CObjectDef14GetUnitMotionsEPKcS1_, 551964)
    off(_ZN5CArmy9SetMoraleEi, 645408)
    off(_ZN11GUIHostList17ResetConnectStateEv, 686488)
    off(_ZN11GUIHostList7AddHostEPKcS1_ii, 685668)
    off(_ZN14CPlayerManager12GetLeftCorpsEi, 581340)
    off(_ZN10ecGraphics8ShutdownEv, 341788)
    off(_ZN10CCSoundBox6LoadSEEPKc, 912192)
    off(_ZN16ecParticleSystem4StopEb, 918224)
    off(_ZN11GUILevelSelC1Ev, 690120)
    off(_ZN12CBattleScene9AddCraterEPKcfff, 652556)
    off(_ZN11GUIWarMedal8SetLevelEi, 676268)
    off(_ZNK9TiXmlNode10ToDocumentEv, 832232)
    off(_ZN11GUIPauseBox4InitERK7GUIRect, 506248)
    off(_ZN10CGameStateC1Ev, 447752)
    off(_ZN10CObjectDef17GetCardTargetTypeEP7CardDef, 541620)
    off(_ZN11GUIHostItemD1Ev, 684428)
    off(_ZN13GUIBattleList10GelSelItemEff, 741672)
    off(_ZN12CBattleScene12ClearEffectsEv, 654284)
    off(_ZN14CPlayerManager10ClearCorpsEv, 580240)
    off(_ZN12TiXmlCommentD0Ev, 835076)
    off(_Z16GetBattleKeyNameiiPc, 406424)
    off(_ZN8GUIMedal8SetMedalEi, 501876)
    off(_ZN9CSoundResD1Ev, 608344)
    off(_ZN10CCSoundBoxC1Ev, 911740)
    off(_ZN7GUITechD2Ev, 521620)
    off(_ZN9TiXmlNode17FirstChildElementEPKc, 837180)
    off(_ZN6CScene25AdjacentAreasEncirclementEi, 603764)
    off(_ZN11GUIHostListC2Ev, 685328)
    off(_ZN7CCamera21IsRectInVisibleRegionEffff, 660524)
    off(_ZN11GUIDialogue4InitERK7GUIRect, 493908)
    off(_ZN18ecSessionInterface16AcceptInvitationEPKc, 831104)
    off(_ZN14GUICountryItem8OnRenderEv, 743116)
    off(_ZN10CGameState7OnEventERK5Event, 454368)
    off(_ZNK9TiXmlText6CopyToEPS_, 842444)
    off(_ZN14CPlayerManagerC2Ev, 590332)
    off(_ZdlPv, 1132240)
    off(_ZN10GUIService4InitERK7GUIRect, 734220)
    off(_ZN9GUIResult4InitERK7GUIRecti, 508300)
    off(_ZN8CCountry19GetHighestValueAreaEv, 661840)
    off(_ZN13CFightTextMgr6UpdateEf, 405888)
    off(_ZN10CCommanderD2Ev, 389488)
    off(_ZN13TiXmlDocumentC2ERKS_, 839808)
    off(_ZN6CFight12SecondAttackEv, 404616)
    off(_ZN11GUIDialogueC2Ev, 493784)
    off(_ZN14GUICountryItemD0Ev, 743080)
    off(_ZN12GUISelBattleD2Ev, 725508)
    off(_ZN7ecShape8SetColorEj, 1129720)
    off(_ZN11GUIPauseBoxC1Ev, 506172)
    off(_ZN9ecGameKitC1Ev, 831020)
    off(_ZN11GUIHostList15RefreshHostListEv, 686516)
    off(_ZN6CScene14ScreenToAreaIDEff, 598916)
    off(_ZN5CArea10RemoveArmyEP5CArmy, 638136)
    off(_ZN11ecLabelTextD1Ev, 911084)
    off(_ZN6ecText7SetTextEPKc, 917524)
    off(_ZN12TiXmlElement12SetAttributeEPKci, 846396)
    off(_ZN6ecFile12CheckJavaDexEv, 351916)
    off(_ZN5CArea11GetIndustryEv, 637832)
    off(_ZN11CBattleUnit11IsAttackingEv, 656480)
    off(_ZN11GUIWarMedal4InitERK7GUIRect11WARMEDAL_IDi, 676488)
    off(_ZN11GUIDialogueD1Ev, 493120)
    off(_ZN6CMedal5UpateEf, 736208)
    off(_ZN3MD59transformEPKh, 353200)
    off(_ZN10GUINewGameD2Ev, 710416)
    off(_ZN12TiXmlElementD0Ev, 844024)
    off(_ZN10CCSoundBox11ResumeMusicEv, 912140)
    off(_ZN11GUICardList8ReSelectEv, 490140)
    off(_ZN7GUIBank4InitERK7GUIRect, 462504)
    off(_Z18ecAppWillTerminatev, 393736)
    off(_ZN7GUIText7SetTextEPKc, 759264)
    off(_ZN3MD5C2Ev, 353056)
    off(_ZN15ecEffectManagerC1Ev, 907288)
    off(_ZN11CMatchStateD0Ev, 533732)
    off(_ZN6GUIEndD2Ev, 494688)
    off(_ZN14GUIBattleIntroD0Ev, 469984)
    off(_Znam, 1136876)
    off(_ZN10CLoadState9TouchMoveEffi, 530692)
    off(_ZN10GUIOptionsD1Ev, 502568)
    off(_ZN11GUICardListD2Ev, 485632)
    off(_ZN13CTouchInertia8TouchEndEffi, 610092)
    off(_ZN11GUIMainMenuD0Ev, 693044)
    off(_ZN10GUIElement4ShowEv, 750860)
    off(_ZN11GUIHostList4InitERK7GUIRect, 687436)
    off(_ZN11GUIMainMenu4InitERK7GUIRect, 693500)
    off(_ZN12GUISmallCardD0Ev, 518776)
    off(_ZN12GUIAttackBox4InitERK7GUIRect, 460988)
    off(_ZN9ecUniFontC2Ev, 908588)
    off(_ZN13GUIMatchSetupD0Ev, 703896)
    off(_ZN7ecImage8SetColorEmi, 889748)
    off(_ZN10CObjectDef11LoadCardDefEv, 540592)
    off(_ZN12GUISelBattleD0Ev, 725872)
    off(_ZN18ecSessionInterfaceC1Ev, 831068)
    off(_ZN8CCountry9TurnBeginEv, 668536)
    off(_ZN12GUISelBattle4InitERK7GUIRectii, 722548)
    off(_ZN10CCommander15GetUpgradeMedalEv, 391020)
    off(_ZN12TiXmlElementC1ERKS_, 846780)
    off(_ZN13CActionAssistD2Ev, 406244)
    off(_ZN10GUIManager13SafeFreeChildEP10GUIElement, 753480)
    off(_ZN13ecStringTableC1Ev, 912224)
    off(_ZN9ecGameKit22SendPacketToAllPlayersEPKvi, 831040)
    off(_ZN12GUIScrollBar12GetScrollPosEv, 757716)
    off(_ZN10CObjectDef18ReleaseUnitMotionsEv, 544780)
    off(_ZN13GUISelCountry8OnRenderEv, 728972)
    off(_ZN11GUIMainMenuC1Ev, 693192)
    off(_ZN10CFightTextD2Ev, 404672)
    off(_ZN10CObjectDef4InitEv, 571840)
    off(_ZN9TiXmlNode9ToElementEv, 832288)
    off(_ZN9ecLibraryD2Ev, 1121620)
    off(_ZN10GUISelArmy7SetAreaEi, 517800)
    off(_ZN6CScene8AirborneEi, 603872)
    off(_ZN18ecEffectResManager13LoadEffectResEPKc, 905068)
    off(_ZN10GUIBuyCard7OnEventERK5Event, 483712)
    off(_ZN8CCountry15CanUseCommanderEv, 666076)
    off(_ZN10GUISelArmy15MoveArmyToFrontEi, 517984)
    off(_ZN14CPlayerManager13WillTerminateEv, 581060)
    off(_ZN10GUIElement12FreeAllChildEv, 750076)
    off(_Z13ecBackPressedv, 393292)
    off(_ZN6GUITax8OnRenderEv, 519644)
    off(_ZN6CScene8IsAdjoinEii, 593152)
    off(_ZN13TiXmlDocumentC1ERKS_, 839808)
    off(_ZN9ecLibraryC1Ev, 1120736)
    off(_ZN12CGameManager10InitBattleEv, 422260)
    off(_ZN12CBattleScene6UpdateEf, 653040)
    off(_ZN7CBomber4InitEv, 656792)
    off(_ZNK12TiXmlComment5CloneEv, 842344)
    off(_ZN13GUIAIProgress8OnRenderEv, 459368)
    off(_ZN8GUIMedalC1Ev, 501788)
    off(_ZN10GUIBuyCard15ResetCardTargetEv, 483416)
    off(_ZN10CFightTextC1Ev, 404664)
    off(_ZN5CArea7GetArmyEi, 637856)
    off(_ZN5CArea8IsActiveEv, 640448)
    off(_ZNK12TiXmlUnknown9StreamOutEP14TiXmlOutStream, 832456)
    off(_ZN13GUIActionInfo7SetInfoEPKc, 459168)
    off(_ZNK11TiXmlHandle12ChildElementEPKci, 847676)
    off(_ZN12CGameManager12RealLoadGameEPKc, 418176)
    off(_ZN16GUIUpgradeButton12SetNeedMedalEi, 677496)
    off(_ZN10CCSoundBoxD2Ev, 911772)
    off(_ZN12CGameManager16GetPlayerCountryEv, 410324)
    off(_ZN13GUIMatchSetupC2Ev, 706600)
    off(_ZN6ecText14GetStringWidthEib, 916472)
    off(_ZN5CArea15MoveArmyToFrontEib, 638284)
    off(_ZN11GUICardListC1Ev, 487884)
    off(_ZN6CScene7GetAreaEi, 599060)
    off(_ZN9TiXmlNode18NextSiblingElementEv, 837392)
    off(_ZN7CCamera4MoveEffb, 659208)
    off(_ZN10GUIElement4HideEv, 750876)
    off(_ZN3MD56updateEPKvm, 356812)
    off(_ZN12CGameManager8LoadGameEPKc, 408224)
    off(_ZN7CBomber19AircraftCarrierBombEii, 657284)
    off(_ZN10CGameState8InitGameEv, 447820)
    off(_ZN12GUIScrollBar4InitERK7GUIRectPKcS4_iiiii, 757940)
    off(_ZN8GUIMedal8OnRenderEv, 501632)
    off(_ZN10CCommander8BuyMedalEi, 391208)
    off(_ZN15ecMultipleTouch10TouchMovedEff, 350596)
    off(_ZN14CPlayerManager21FindPlayerByCountryIDEPKc, 585736)
    off(_ZN6GUITaxD2Ev, 519404)
    off(_ZN6ecText8SetAlphaEf, 916436)
    off(_ZN12TiXmlElementD2Ev, 843960)
    off(_ZN10GUIElement8AddChildEPS_b, 749692)
    off(_ZN11GUILevelSelD1Ev, 689764)
    off(_ZN11GUILevelSelC2Ev, 690120)
    off(_ZN12CBattleScene11IsAttackingEv, 652328)
    off(_ZNK14TiXmlAttribute16QueryDoubleValueEPd, 841884)
    off(_ZN12TiXmlUnknown9ToUnknownEv, 832364)
    off(_ZlsR14TiXmlOutStreamRK9TiXmlNode, 847056)
    off(_ZN12CBattleScene13SetBattleAreaEi, 650628)
    off(_ZN8CGameRes12RenderArmyHPEffii, 424164)
    off(_ZN6CScene13ScreenToSceneERfS0_, 598780)
    off(_ZN16ecParticleSystem4FireEv, 918204)
    off(_Z13HasUnitMotionPKci, 648332)
    off(_ZN7ecImage4InitEP9ecTextureffff, 887484)
    off(_ZN9TiXmlNode13ToDeclarationEv, 832320)
    off(_ZN8CCountryD2Ev, 660804)
    off(_ZN9GUIBattle4InitERK7GUIRect, 467320)
    off(_ZN10CGameState12UnselectAreaEv, 452100)
    off(_ZN11GUIButtonExD0Ev, 475984)
    off(_Z7InvSqrtf, 887204)
    off(_ZN13GUISelCountryD2Ev, 733212)
    off(_ZN7ecShapeD2Ev, 1129256)
    off(_ZN16TiXmlDeclarationC2ERKS_, 842992)
    off(_ZN10GUINewGame17IsShowIabEventTipEv, 711676)
    off(_ZN13GUIBattleItem8OnUpdateEf, 737680)
    off(_ZN10GUIServiceD1Ev, 733784)
    off(_ZN10GUIWarningC1Ev, 529592)
    off(_ZN9hgeVector6RotateEf, 887380)
    off(_ZN7ecShape6RenderERK7ecMtx32, 1129404)
    off(_ZN13GUIMatchSetupD2Ev, 703608)
    off(_ZN7ecImage14SetTextureRectEffff, 890228)
    off(_ZN9ecElement5ResetEv, 1127156)
    off(_ZN13CTouchInertia4InitEv, 609308)
    off(_ZN11GUIWarMedalC1Ev, 676216)
    off(_ZN10GUILoadingC2Ev, 690876)
    off(_ZN10CObjectDef12GetBattleDefEPKc, 542968)
    off(_ZN6CScene9GainMedalEff, 603940)
    off(_ZN10ecGraphics11LoadTextureEPKc, 346416)
    off(_ZN10GUIWarningD0Ev, 529396)
    off(_ZN18ecEffectResManager8InstanceEv, 901992)
    off(_ZN11CMatchState11ShowWarningEi, 534484)
    off(_ZN12GUICommanderC1Ev, 677716)
    off(_ZN9TiXmlNode12ReplaceChildEPS_RKS_, 835812)
    off(_ZN14GUIRadioButtonC1Ev, 757340)
    off(_ZN6CScene4MoveEii, 598992)
    off(_ZN6GUIIapC1Ev, 499716)
    off(_ZN10ecGraphics14LoadPVRTextureEPKc, 348376)
    off(_ZN7GUIText8SetAlignEi, 759336)
    off(_ZN14CPlayerManager15GetNumLeftCorpsEv, 581364)
    off(_ZN12GUICommanderD0Ev, 675176)
    off(_ZN12TiXmlComment5ParseEPKcP16TiXmlParsingData13TiXmlEncoding, 853568)
    off(_ZN14TiXmlAttribute4NextEv, 841108)
    off(_ZN5CArmy12BreakthroughEv, 645428)
    off(_ZN10CMenuStateC2Ev, 535284)
    off(_ZN11GUIHostList14FindHostByUUIDEi, 685596)
    off(_ZN8ecEffect6RenderEv, 907088)
    off(_ZN8ecEffect4StopEb, 906792)
    off(_ZN11ecEffectRes10LoadEffectEPKcP12ecTextureRes, 898792)
    off(_ZN10CObjectDef17LoadGeneralPhotosEv, 564260)
    off(_ZN7ecLayerD2Ev, 1129760)
    off(_ZN13CGameSettings12SaveSettingsEv, 445228)
    off(_ZN6CSceneC2Ev, 591156)
    off(_ZNK16TiXmlDeclaration5CloneEv, 843232)
    off(_ZN10CLogoStateD0Ev, 532304)
    off(_ZN11GUISaveItem4InitERK7GUIRectPKc, 512784)
    off(_ZN9ecLibraryD0Ev, 1121992)
    off(_ZN6CScene13CheckMoveableEiii, 602064)
    off(_ZN6GUIIap8OnRenderEv, 499264)
    off(_ZNK12TiXmlElement6CopyToEPS_, 846632)
    off(_ZN14GUIRadioButtonD2Ev, 756900)
    off(_ZN11ecEffectResC1Ev, 898632)
    off(_ZN13GUIBattleList15ResetTouchStateEv, 741632)
    off(_ZN10CMenuStateD1Ev, 534692)
    off(_ZN6CSceneD1Ev, 591000)
    off(_ZN6CScene12LoadAreaDataEi, 593312)
    off(_ZN14CPlayerManager14SendRoundBeginEv, 586820)
    off(_ZN11GUIWarMedalD1Ev, 672680)
    off(_ZN11ecLabelText4InitEPKciiii, 911304)
    off(_ZN6CScene14LoadAreaEnableEPKc, 595268)
    off(_ZN11CBattleUnitC1Ev, 654696)
    off(_ZN12CBattleScene7ReleaseEv, 647668)
    off(_ZN14GUIBattleIntroC1Ev, 470640)
    off(_ZNK9TiXmlNode18NextSiblingElementEv, 837296)
    off(_ZN12TiXmlUnknownD1Ev, 834788)
    off(_ZN12ecTextureRes8GetImageEPKc, 893056)
    off(_ZN7GUIGold8SetMoneyEi, 497704)
    off(_ZN11GUIDialogue7ShowDlgEPKcS1_b, 494256)
    off(_ZN6CScene19AircraftCarrierBombEii, 603888)
    off(_ZN10CLoadState7OnEventERK5Event, 532052)
    off(_ZN10GUINewGame18OnCheckButtonClickEP14GUIRadioButton, 714036)
    off(_ZN16GUIMotionManagerC1Ev, 754484)
    off(_ZN10CCommanderC1Ev, 389532)
    off(_ZN10ecGraphics8InstanceEv, 341332)
    off(_ZN9GUIButton8OnRenderEv, 747612)
    off(_ZN11GUIPauseBoxD0Ev, 506036)
    off(_Z14GetArmyAbilityi, 644480)
    off(_Z18ecSetInAppPurchasePFviE, 393672)
    off(_ZNK16TiXmlDeclaration6CopyToEPS_, 842900)
    off(_ZN8CCountry12FinishActionEv, 663708)
    off(_ZN13CStateManagerC1Ev, 608628)
    off(_ZN15ecMultipleTouch10TouchEndedEff, 350720)
    off(_ZN10CBaseState7KeyDownEi, 397020)
    off(_ZN9TiXmlBase10IsAlphaNumEh13TiXmlEncoding, 848508)
    off(_ZNK14TiXmlAttribute8IntValueEv, 842180)
    off(_ZN13TiXmlDocumentC1EPKc, 838148)
    off(_ZN7CPlayerD1Ev, 737164)
    off(_ZN5CArea8SaveAeraEP12SaveAreaInfo, 643444)
    off(_ZN10ecGraphics4FadeEf, 344400)
    off(_ZN9TiXmlNodeD1Ev, 834672)
    off(_ZN5CArea10RenderArmyEffiP5CArmy, 641732)
    off(_ZN9TiXmlBase9PutStringERK11TiXmlStringP14TiXmlOutStream, 833608)
    off(_ZN17TiXmlAttributeSet6RemoveEP14TiXmlAttribute, 843796)
    off(_ZN7ecImageC1EP9ecTextureffff, 887656)
    off(_Z16GetEditorResPathPKc, 341244)
    off(_ZN13GUIBattleList18SelectLastUnlockedEv, 742324)
    off(_ZN9CActionAID2Ev, 398660)
    off(_ZN9TiXmlBase14StringToBufferD2Ev, 834584)
    off(_ZN11GUIHostListD0Ev, 684024)
    off(_ZN12GUICommander16SetCommanderInfoEv, 677860)
    off(_ZN6CScene12CalSceneRectERfS0_S0_S0_, 596924)
    off(_ZN13CActionAssist19purChaseSpecialCardEv, 620832)
    off(_ZN8CCountry12GetIndustrysEv, 668312)
    off(_ZN6ecFileD1Ev, 351016)
    off(_ZN9TiXmlTextD2Ev, 834984)
    off(_ZN13GUIBattleItem8OnRenderEv, 737892)
    off(_ZN18ecEffectResManager16ReleaseEffectResEPKc, 903700)
    off(_ZN5CArmy9TurnBeginEv, 645636)
    off(_ZplRK11TiXmlStringPKc, 831884)
    off(_ZN7ecLayer4PlayEv, 1129940)
    off(_ZN12CGameManager26SetConquestPlayerCountryIDEPKc, 407944)
    off(_ZN13CStateManagerD2Ev, 608624)
    off(_ZN14GUICountryList10GelSelItemEff, 745364)
    off(_ZN8CCountry7TurnEndEv, 663556)
    off(_ZN6CScene11ResetTargetEv, 603636)
    off(_ZN9GUIBattle11BattleStartEiii, 468680)
    off(_ZN14GUICountryList11ResetSelectEv, 745136)
    off(_ZN12CBattleSceneD2Ev, 654412)
    off(_ZNK16TiXmlDeclaration9StreamOutEP14TiXmlOutStream, 833900)
    off(_ZN10CCommander12CheckUpgardeEv, 391052)
    off(_ZN6CScene6MoveToEii, 599012)
    off(_ZN6CScene10SaveAdjoinEi, 591844)
    off(_ZN10GUIManager14LoadTextureResEPKcb, 752852)
    off(_ZN7ecImageC1EP9ecTextureRK13ecTextureRect, 887660)
    off(_ZN14GUICountryItem8OnUpdateEf, 742972)
    off(_ZN6CScene7ReleaseEv, 594324)
    off(_ZN19GUIConnectHostStateC2Ev, 684748)
    off(_ZN9CAreaMarkD1Ev, 644088)
    off(_ZN5CArea15AddArmyStrengthEii, 640216)
    off(_ZN9TiXmlNode9ToCommentEv, 832296)
    off(_ZN11GUIMainMenu7OnEventERK5Event, 702104)
    off(_ZN9GUIButton12SetTextImageEPKc, 748876)
    off(_ZN12CGameManager11FindCountryEPKc, 410136)
    off(_ZN7GUIGoldC1Ev, 497580)
    off(_ZNK14TiXmlAttribute5PrintEP7__sFILEi, 841220)
    off(_ZN10GUILoadingD1Ev, 690528)
    off(_ZN11GUIMainMenu12IsShowNewTipEv, 693284)
    off(_Z13GetAIRandSeedv, 616860)
    off(_ZN11ecLabelText8SetColorEj, 911612)
    off(_ZN8GUIImage8OnRenderEv, 751452)
    off(_ZN10CObjectDef20ReleaseUnitPositionsEv, 545716)
    off(_ZN13GUIAIProgressC2Ev, 459652)
    off(_ZN10CCommander20SetNumPlayedBatttlesEii, 391472)
    off(_ZN12GUICorpsInfoD2Ev, 702776)
    off(_ZN9TiXmlNode10ToDocumentEv, 832280)
    off(_ZN7CPlayerC1Ev, 736440)
    off(_ZN8CCountry16SetWarMedalLevelE11WARMEDAL_IDi, 666524)
    off(_ZN10GUIBuyCard7SelCardEii, 483152)
    off(_ZN9TiXmlNode11GetDocumentEv, 837816)
    off(_ZN5CArmy7TurnEndEv, 645660)
    off(_ZN5CArea16AllArmyPoisoningEv, 640252)
    off(_ZN14CPlayerManager18onPeerDisconnectedEPKc, 586124)
    off(_ZN13CFightTextMgrD2Ev, 404680)
    off(_ZN14CPlayerManager15AnalyzePeerNameERKSsRSsRiS3_, 572380)
    off(_ZN18ecSessionInterface7ReleaseEv, 831080)
    off(_ZN10CEditState11ReleaseGameEv, 398564)
    off(_ZN7GUISaveC2Ev, 513644)
    off(_ZN14GUIExitWarningD2Ev, 682200)
    off(_ZN13GUIAdornMedalD1Ev, 673580)
    off(_ZN6GUIIap14OnListCompleteEPv, 501504)
    off(_ZN7ecFrame4InitEP11ecFrameDataP9ecElementP9ecLibrary, 1130820)
    off(_ZN10GUIManager6RenderEv, 753012)
    off(_ZNK13TiXmlDocument9StreamOutEP14TiXmlOutStream, 840176)
    off(_ZN6CScene13RenderAreasIDEv, 594216)
    off(_ZN12GUICorpsInfo8OnRenderEv, 703156)
    off(_ZN12CGameManager21GetLocalPlayerCountryEv, 410420)
    off(_ZN6GUITax11SetIndustryEi, 520328)
    off(_ZN7ecImageD1Ev, 887480)
    off(_ZN5CArea6UpdateEf, 641128)
    off(_ZN10CCommander10IsMaxLevelEv, 391192)
    off(_ZN10CMenuState8TouchEndEffi, 534720)
    off(_ZN13GUIMatchSetup4InitERK7GUIRect, 708336)
    off(_ZN10GUIServiceD0Ev, 733928)
    off(_ZN5CArea10OccupyAreaEPS_, 639304)
    off(_Z18GetConquestKeyNameiPc, 406568)
    off(_ZN7ecImageD2Ev, 887480)
    off(_ZN7GUIGoldD0Ev, 497376)
    off(_ZN13CGameSettingsC2Ev, 444800)
    off(_ZN13GUIAdornMedalC2Ev, 676700)
    off(_ZN13TiXmlDocumentaSERKS_, 839956)
    off(_ZN5CArea11HasArmyCardEii, 639788)
    off(_ZN10GUIBuyCardD0Ev, 476856)
    off(_ZN7CCameraC1Ev, 658644)
    off(_ZN10CGameStateD2Ev, 445468)
    off(_ZN12ecTextureResC2Ev, 890472)
    off(_ZN10CObjectDef16LoadConquestListEv, 570088)
    off(_ZN7ecLayer10ChangeItemEP10ecItemDataS1_P9ecLibrary, 1129820)
    off(_ZN6ecFileC2Ev, 350864)
    off(_ZN7GUICardD0Ev, 484576)
    off(_ZN7ecLayer4StopEv, 1130028)
    off(_ZN11CMatchStateD1Ev, 533700)
    off(_ZN9ecLibrary12GetLayerDataEi, 1121352)
    off(_ZN5CArmy6AddExpEi, 645256)
    off(_ZN10GUIVictory8OnRenderEv, 527748)
    off(_ZN9ecGameKitD1Ev, 831024)
    off(_ZN11GUIArmyItemD1Ev, 516804)
    off(_ZN12TiXmlElement18SetDoubleAttributeEPKcd, 846516)
    off(_ZN11GUIDefeatedD1Ev, 492684)
    off(_ZN5CArea11AddArmyCardEii, 639692)
    off(_ZN11GUIDefeated12HideDefeatedEv, 492504)
    off(_ZN9ecGameKit7ReleaseEv, 831032)
    off(_ZN9ecUniFont12GetCharImageEt, 908628)
    off(_ZN17TiXmlAttributeSetC2Ev, 843456)
    off(_ZN11GUICardList10GelSelItemEff, 488064)
    off(_ZN7CBomberC1Ev, 656652)
    off(_ZN11CBackgroundD1Ev, 645772)
    off(_ZN11GUIPauseBoxD2Ev, 505936)
    off(_ZN8ecEffect4InitEPKcP9TFreeListI16ecParticleSystemE, 906312)
    off(_ZN14GUIExitWarningC1Ev, 682472)
    off(_ZNK13TiXmlDocument8SaveFileEv, 839532)
    off(_ZN14CPlayerManager6UpdateEf, 589684)
    off(_ZN7GUIText8OnRenderEv, 759000)
    off(_ZN14CPlayerManager18SendPacketToPlayerE9PACKET_IDPKviP7CPlayer, 579856)
    off(_ZN6CScene20AreaDisableOutofRectEiiii, 595580)
    off(_ZN15ecEffectManager9AddEffectEPKcb, 907892)
    off(_ZN12GUICorpsInfoC2Ev, 704000)
    off(_ZN7GUIBankD2Ev, 462020)
    off(_ZN8GUIImage8SetAlphaEf, 752080)
    off(_ZN14CPlayerManager17DidRecvInvitationEPKc, 578840)
    off(_ZN3MD5C1EPKvm, 356816)
    off(_ZN10GUIElement11CheckInRectEff, 750596)
    off(_ZN16GUILockedWarning4InitERK7GUIRect, 691776)
    off(_ZN7CBomberD2Ev, 656668)
    off(_ZNK11TiXmlHandle10FirstChildEv, 847112)
    off(_ZN9GUIButton7SetTextEPKt, 749068)
    off(_ZN10CObjectDef7ReleaseEv, 550852)
    off(_ZN16GUILockedWarningC2Ev, 691660)
    off(_ZN10CLoadStateC2Ev, 532196)
    off(_ZN11GUIWarMedal13SetArrowColorEj, 676684)
    off(_ZN10GUIElement10SetVisibleEb, 750820)
    off(_Z17ecGetProductPricei, 393520)
    off(_ZN12GUIScrollBar12SetScrollPosEi, 757804)
    off(_Z24GetBattleBelligerentListPKcRSt4listI11BelligerentSaIS2_EEb, 406896)
    off(_ZN10CBaseState7OnEnterEv, 396980)
    off(_ZN10CMenuState18StartMultiplayGameEi, 535376)
    off(_ZN5CArmyD2Ev, 644524)
    off(_ZNK9TiXmlNode11GetDocumentEv, 837720)
    off(_ZN8GUIBegin4InitERK7GUIRect, 474336)
    off(_ZN6ecText8SetColorEj, 916428)
    off(_ZN10CGameState14HideAIProgressEv, 451816)
    off(_ZN8CCountry11LoadCountryEPK15SaveCountryInfo, 664844)
    off(_ZN9CActionAI18setActionNodeClearEv, 611644)
    off(_ZNK13TiXmlDocument8SaveFileEPKc, 839436)
    off(_ZN11GUISaveItem8OnRenderEv, 511268)
    off(_ZN10CMenuState7OnEventERK5Event, 535432)
    off(_ZN11GUIHostList8OnRenderEv, 684060)
    off(_ZN14CPlayerManager12onMatchFoundEv, 578320)
    off(_ZN13GUIMatchSetup7OnEventERK5Event, 709904)
    off(_ZN13TiXmlDocumentD1Ev, 847928)
    off(_ZN10CGameState11ScrollWheelEfff, 447492)
    off(_ZN5CArea9ConstructEi, 637236)
    off(_ZN6ecFile11IsFlieExistEPKc, 351188)
    off(_ZN8CCountry13IsLocalPlayerEv, 672096)
    off(_ZN9CSoundRes10PlayCharSEE10SND_EFFECT, 608584)
    off(_ZN8CGameRes15RenderArmyLevelEffi, 424380)
    off(_ZN10CMenuState11ShowWarningEi, 539784)
    off(_ZNK12TiXmlElement9AttributeEPKc, 844188)
    off(_ZN13CFightTextMgr7ReleaseEv, 405740)
    off(_ZN13GUIAdornMedal7RefreshEv, 676808)
    off(_ZN10CObjectDef14GetConquestDefEPKc, 543404)
    off(_Z16ecETCTextureLoadPKcRiS1_Rj, 381048)
    off(_ZN10GUIElement9SetEnableEb, 750892)
    off(_ZN12CBattleScene10CreateFortEv, 650028)
    off(_ZN10CGameState12ShowDialogueEPKcS1_b, 452152)
    off(_ZN13TiXmlDocumentC2Ev, 837968)
    off(_ZN7GUITechC2Ev, 522004)
    off(_ZN5CArmy8LoadArmyEPK12SaveArmyInfo, 645540)
    off(_ZN14CPlayerManager14DestroySessionEv, 576988)
    off(_ZN11GUIDefeated7OnEventERK5Event, 492960)
    off(_ZN9TiXmlBase18ConvertUTF32ToUTF8EmPcPi, 848188)
    off(_ZN12CBattleSceneC1Ev, 647464)
    off(_ZN6GUITax4InitERK7GUIRect, 520456)
    off(_ZN3MD56digestEv, 357416)
    off(_ZN9GUIResultD0Ev, 507372)
    off(_ZN10GUINewGame15GetPromotionUrlEv, 713048)
    off(_ZN6GUITax8SetMoneyEi, 520200)
    off(_ZN8ecEffect6MoveToEffb, 906880)
    off(_ZN10GUIBuyCard4InitERK7GUIRect, 479524)
    off(_ZN8CCountry7UseCardEP7CardDefii, 668692)
    off(_ZNK14TiXmlAttribute11DoubleValueEv, 842192)
    off(_ZN13CFightTextMgrC2Ev, 405060)
    off(_ZN13CStateManager8TouchEndEffi, 609032)
    off(_ZN9GUIBattle7OnEventERK5Event, 469756)
    off(_ZN5CArea9DraftArmyEi, 638568)
    off(_ZN12GUIAttackBoxD1Ev, 460136)
    off(_ZN10CEditState6RenderEv, 397392)
    off(_ZN9GUIBattle12BattleFinishEv, 468976)
    off(_ZN8CCountry17GenCardTargetListE7CARD_ID, 663380)
    off(_ZN7GUITechD1Ev, 521620)
    off(_ZN19GUIConnectHostStateD0Ev, 683876)
    off(_ZN14CPlayerManager10FindPlayerEPKc, 577760)
    off(_ZN10CLogoState7OnEnterEv, 532348)
    off(_ZN5CArea10GetArmyIdxEP5CArmy, 637892)
    off(_ZN10CFightText8SetColorEj, 404912)
    off(_ZN12CGameManager17CheckAndSetResultEv, 413472)
    off(_ZN9TiXmlBase9PutStringERK11TiXmlStringPS0_, 832972)
    off(_ZN13CTouchInertiaC1Ev, 609340)
    off(_ZN10CCommander20GetNumPlayedBatttlesEi, 391484)
    off(_ZN10GUICardTabC2Ev, 477336)
    off(_ZN13CActionAssist10searchNodeEii, 621120)
    off(_ZN13TiXmlDocument8SetErrorEiPKcP16TiXmlParsingData13TiXmlEncoding, 851272)
    off(_Z18ecSetShowReviewFucPFvvE, 393476)
    off(_ZN10ecGraphics15LoadWEBPTextureEPKc, 347396)
    off(_ZN7GUIBank8OnRenderEv, 462164)
    off(_ZN12GUITutorails10LoadScriptEv, 523348)
    off(_ZN12GUITutorailsD0Ev, 526008)
    off(_ZN8GUIBeginD2Ev, 473300)
    off(_ZN11GUICardListD1Ev, 485632)
    off(_ZN9CActionAI8getMaxIdEv, 613620)
    off(_ZN14GUIExitWarningD0Ev, 682336)
    off(_ZN9GUIButton12SetTextAlignEi, 749164)
    off(_ZN13GUIAIProgressD0Ev, 459332)
    off(_ZN15ecMultipleTouchD2Ev, 350336)
    off(_ZNK12TiXmlUnknown5PrintEP7__sFILEi, 832668)
    off(_ZN10GUICardTabD1Ev, 476572)
    off(_ZN10CObjectDefD1Ev, 548760)
    off(_ZN11ecLabelTextC1Ev, 911056)
    off(_ZN5CArmy12LostStrengthEi, 644552)
    off(_ZN13CStateManager11BackPressedEv, 609068)
    off(_ZN11GUICardList7GetCardEi, 488024)
    off(_ZN18ecEffectResManager14LoadTextureResEPKc, 902004)
    off(_ZN7ecFrameD1Ev, 1130760)
    off(_ZN7GUIBankD0Ev, 462128)
    off(_ZN7ecImage6RenderEffff, 888052)
    off(_ZN9ecGameKitC2Ev, 831020)
    off(_ZN7ecImage14SetTextureRectERK13ecTextureRect, 890332)
    off(_ZN16ecParticleSystem6IsLiveEv, 921788)
    off(_ZN6ecTextC1Ev, 916356)
    off(_ZNK9TiXmlText5PrintEP7__sFILEi, 834188)
    off(_ZN15ecEffectManagerC2Ev, 907288)
    off(_ZN13GUIAIProgressD2Ev, 459176)
    off(_ZN8GUIImage4InitEPKcRK7GUIRect, 751936)
    off(_ZN7CCamera14IsRectInCameraEffff, 660428)
    off(_ZN11ecLabelTextD2Ev, 911084)
    off(_ZN10CMenuState7OnEnterEv, 534768)
    off(_ZN10GUIElement11CheckInRectEffRK7GUIRect, 750752)
    off(_ZN12TiXmlElement12SetAttributeEPKcS1_, 845704)
    off(_ZN10CLogoStateC2Ev, 533660)
    off(_ZN6CScene8IsMovingEv, 599032)
    off(_ZN9GUIBattleD0Ev, 465252)
    off(_ZN7GUIBankC1Ev, 462420)
    off(_ZN10ecGraphics5FlushEv, 342300)
    off(_ZN12GUITutorails7ShowDlgEPKc, 526200)
    off(_ZN6GUITaxD1Ev, 519404)
    off(_ZN6GUIIapC2Ev, 499716)
    off(_ZN5CArea16GetIndustryLevelEv, 637772)
    off(_ZN3MD56decodeEPKhPmm, 353132)
    off(_ZN7GUITextC2Ev, 759100)
    off(_ZN12CBattleSceneC2Ev, 647464)
    off(_ZN11GUIDialogue7HideDlgEv, 494524)
    off(_ZN8GUIMedal8OnUpdateEf, 502384)
    off(_ZN6CFight12GetAttackAddEi, 399324)
    off(_ZN11GUIHostItemC1Ev, 684960)
    off(_ZN12GUITutorails7OnEventERK5Event, 527444)
    off(_ZN6CScene11CreateArrowEii, 598388)
    off(_ZN12CGameManager10NextBattleEv, 410012)
    off(_ZN10GUIVictoryD2Ev, 527560)
    off(_ZN12GUIAttackBox7OnEventERK5Event, 461804)
    off(_ZN12GUICorpsInfo13SetPlayerNameEPKcbS1_iib, 704184)
    off(_ZN11GUIMainMenu8OnRenderEv, 693080)
    off(_ZN12GUITutorails7ShowDlgEi, 526044)
    off(_ZN10GUIBuyCard10GetSelCardEv, 482192)
    off(_ZN10GUIWarningD2Ev, 529280)
    off(_ZN7ecLayer7SetLoopEi, 1130116)
    off(_ZN13GUIAdornMedal8OnRenderEv, 673808)
    off(_ZN11GUIHostItemD0Ev, 684712)
    off(_ZN8ecEffect6FireAtEfff, 906592)
    off(_ZN10GUIBuyCard13CanBuySelCardEv, 482252)
    off(_ZN11GUIHostList8FindHostEPKc, 685480)
    off(_ZN14CPlayerManager12SetupSessionEb, 576412)
    off(_ZNK9TiXmlText5CloneEv, 842488)
    off(_ZN14CPlayerManagerC1Ev, 590332)
    off(_ZN13GUISelCountry13LoadImageListEi, 730116)
    off(_ZN9CActionAI12getAiPercentEi, 611100)
    off(_ZN12GUICommanderC2Ev, 677716)
    off(_ZN7CBomber8AirborneEi, 657332)
    off(_ZN13GUISelCountryD1Ev, 733212)
    off(_ZN8CCountry12SetCommanderEPKc, 664420)
    off(_ZN12CBattleScene12DestroyUnitsEi, 652448)
    off(_ZN10CEditStateD2Ev, 397056)
    off(_ZN9GUIButtonC1Ev, 748200)
    off(_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz, 333252)
    off(_ZN11GUISaveItemD0Ev, 511216)
    off(_ZN18ecEffectResManager17ReleaseTextureResEv, 902016)
    off(_ZN13CGameSettings12LoadSettingsEv, 444840)
    off(_ZN10GUIVictory4InitERK7GUIRectb, 528252)
    off(_ZN14CPlayerManager13GetRightCorpsEi, 581352)
    off(_ZN14CPlayerManagerD2Ev, 577224)
    off(_ZNK13TiXmlDocument10ToDocumentEv, 847816)
    off(_ZN9TiXmlText6ToTextEv, 832348)
    off(_ZN12GUICommanderD1Ev, 674860)
    off(_ZN16GUIMotionManager9AddMotionEP10GUIElementffft, 755524)
    off(_ZN7GUICardD2Ev, 484328)
    off(_ZN12GUICommander13SelectedMedalEi, 681156)
    off(_ZN11ecEffectRes7ReleaseEv, 898660)
    off(_ZN6GUIEndD1Ev, 494688)
    off(_ZN11CMatchState6UpdateEf, 533712)
    off(_ZN14GUICountryItem7OnEventERK5Event, 745508)
    off(_ZN10GUILoadingD0Ev, 690628)
    off(_ZN9TiXmlNode15IterateChildrenEPS_, 836468)
    off(_ZN10CObjectDef19ReleaseCommanderDefEv, 546276)
    off(_ZN5CArea12GetCityLevelEv, 637656)
    off(_ZN8CCountry12GetCardPriceEP7CardDef, 665572)
    off(_ZN10CCommanderC2Ev, 389532)
    off(_ZN9GUIButton13SetBackgroundEPKc, 748744)
    off(_ZN10GUIManager6FadeInEi, 752888)
    off(_ZN14CPlayerManager12ClearPlayersEv, 576928)
    off(_ZN10CObjectDefC1Ev, 540256)
    off(_ZNK12TiXmlElement9AttributeEPKcPi, 844488)
    off(_ZN7GUISave7OnEventERK5Event, 516268)
    off(_ZN7GUICardC1Ev, 486236)
    off(_ZN10CBaseState15EnterForegroundEv, 397032)
    off(_ZN6GUIIapD2Ev, 498484)
    off(_ZN8CheckMD5C2Ev, 357836)
    off(_ZN12CGameManager9RetryGameEv, 408544)
    off(_ZN7CCamera5UpateEf, 660148)
    off(_ZN9TiXmlNode17InsertBeforeChildEPS_RKS_, 835564)
    off(_ZN17GUICommanderMedalC2Ev, 675664)
    off(_ZN5CArmy25GetNumDicesIfLostStrengthEi, 645052)
    off(_ZNK9TiXmlNode10FirstChildEPKc, 836096)
    off(_ZN6CScene10LoadAdjoinEi, 591552)
    off(_ZN13GUIBattleItem7OnEventERK5Event, 741844)
    off(_ZN13CActionAssist13calcDraftTypeEbiP8CCountry, 616912)
    off(_ZN17TiXmlAttributeSet4FindERK11TiXmlString, 845260)
    off(_ZN17GUICommanderMedalD1Ev, 672496)
    off(_ZN14GUIBattleIntroD1Ev, 469780)
    off(_ZN9TiXmlNodeC2ENS_8NodeTypeE, 834600)
    off(_ZN13GUIBattleItemC2Ev, 739720)
    off(_ZN12GUIAttackBox8OnRenderEv, 460328)
    off(_ZN12GUIScrollBarC1Ev, 757656)
    off(_ZN6CScene16RenderAreasPointEv, 593308)
    off(_ZN13GUIBattleListC2Ev, 740420)
    off(_ZN13TiXmlDocument5ParseEPKcP16TiXmlParsingData13TiXmlEncoding, 852584)
    off(_ZN13TiXmlDocumentC2EPKc, 838148)
    off(_ZN15GUIProductPrice14SetLocalePirceEPKc, 499644)
    off(_ZN12GUITutorailsC2Ev, 523196)
    off(_ZN9ecGameKit18GetMatchPlayerListERSt4listISsSaISsEE, 831052)
    off(_ZN5CArea12ClearAllArmyEv, 639556)
    off(_ZN15ecEffectManager6UpdateEf, 908368)
    off(_ZN10GUIWarning8OnRenderEv, 529432)
    off(_ZN8CCountry12CommanderDieEv, 665720)
    off(_ZN8GUIImageD2Ev, 751316)
    off(_ZN14GUICountryItemD1Ev, 742976)
    off(_ZN5CArea11UpgradeArmyEi, 640332)
    off(_ZN6ecTextD1Ev, 916376)
    off(_ZN12GUITutorailsD2Ev, 525696)
    off(_ZN12GUISelBattle8OnUpdateEf, 727716)
    off(_ZN10CObjectDef10GetCardDefE7CARD_ID, 541580)
    off(_ZN12TiXmlCommentD2Ev, 835056)
    off(_ZN9TiXmlNode8IdentifyEPKc13TiXmlEncoding, 851984)
    off(_ZN12CGameManager13GetSaveHeaderEPKcR10SaveHeader, 409500)
    off(_ZN3MD56updateERKSs, 357144)
    off(_ZN12GUICorpsInfo4InitERK7GUIRect, 704084)
    off(_ZN10CLoadState6OnExitEv, 531556)
    off(_ZN6GUIIap15SetProductPriceEv, 501508)
    off(_ZN11GUIButtonExD2Ev, 475876)
    off(_ZN10GUIManagerC1Ev, 752744)
    off(_ZN8GUIBegin8OnRenderEv, 473612)
    off(_ZN13CTouchInertia9TouchMoveEffi, 609656)
    off(_ZN11CMatchState7OnEnterEv, 533776)
    off(_ZN12ecTextureRes9UnloadResEPKc, 892448)
    off(_Z17ecSetProductPriceiPKc, 393552)
    off(_ZN10CGameStateD1Ev, 445468)
    off(_ZN7ecImage4InitEP11ecImageAttr, 887808)
    off(_ZN10CCSoundBox11SetSEVolumeEi, 912168)
    off(_ZN12CGameManagerD1Ev, 406260)
    off(_ZN3MD56updateEPKhm, 356548)
    off(_ZN6CScene11SaveAreaTaxEi, 594628)
    off(_ZNK13TiXmlDocument5CloneEv, 840004)
    off(_ZN10CGameState12StartBattaleEiiib, 451524)
    off(_ZN10ecGraphicsC2Ev, 341260)
    off(_ZN8CCountry18GetMinDstToAirportEi, 663144)
    off(_ZN6CScene14RenderAreasTaxEv, 594212)
    off(_ZN10GUIManagerD0Ev, 752708)
    off(_ZN13GUIActionInfo8OnRenderEv, 458848)
    off(_ZN11GUIMainMenuD2Ev, 692592)
    off(_ZN7GUIBank8OnUpdateEf, 462016)
    off(_ZN10CCSoundBox7DestroyEv, 912044)
    off(_ZN12CBattleScene11ReleaseFortEv, 650544)
    off(_ZN10CLoadState10TouchBeginEffi, 530688)
    off(_ZNK12TiXmlComment9ToCommentEv, 832336)
    off(_ZN13GUIActionInfo8OnUpdateEf, 458724)
    off(_Z14ecLoadSettingsv, 393764)
    off(_ZN12TiXmlUnknownD0Ev, 834808)
    off(_ZNK13TiXmlDocument6CopyToEPS_, 839684)
    off(_ZN10GUIManager4InitERK7GUIRect, 752836)
    off(_ZN3MD5C2ERSt14basic_ifstreamIcSt11char_traitsIcEE, 357100)
    off(_ZN7GUISaveC1Ev, 513644)
    off(_ZN10CGameStateC2Ev, 447752)
    off(_ZN6CMedal6RenderEv, 736280)
    off(_ZN5CArea10SetArmyDirEif, 639664)
    off(_ZN8CCountry14NextCardTargetEv, 663416)
    off(_ZN14TiXmlAttributeD0Ev, 848088)
    off(_ZN10CCSoundBox11UnloadMusicEv, 912124)
    off(_ZN8CGameRes12GetFlagImageEPKc, 424556)
    off(_ZN10ecGraphics12SetViewPointEfff, 342472)
    off(_ZN12CGameManager13BattleVictoryEv, 414220)
    off(_ZN11CMatchState7OnEventERK5Event, 534176)
    off(_ZN5CArea14RenderBuildingEv, 642184)
    off(_ZN8ecEffectC2Ev, 906120)
    off(_ZN9ecLibraryD1Ev, 1121620)
    off(_ZN10CGameState12ShowDefeatedEP8CCountry, 448280)
    off(_ZN3MD55finalEv, 357200)
    off(_ZN8GUIBegin7OnEventERK5Event, 475676)
    off(_ZN5CArea23ReduceConstructionLevelEv, 637484)
    off(_ZN6CScene22MoveCameraCenterToAreaEi, 599376)
    off(_ZN13CActionAssist11getAllianceEiii, 620840)
    off(_ZN7GUICard8OnRenderEv, 484612)
    off(_ZN10GUINewGameD0Ev, 710560)
    off(_ZN5CArea4InitEiRK8AreaInfo, 636948)
    off(_ZN15ecEffectManagerD2Ev, 908192)
    off(_ZN10ecGraphics11RenderBeginEv, 341848)
    off(_ZN11ecEffectResD1Ev, 898788)
    off(_ZN8GUIMedal7OnEventERK5Event, 502400)
    off(_ZN10CObjectDef14LoadBattleListEv, 566568)
    off(_ZN7GUIGold11SetIndustryEi, 497832)
    off(_ZN9GUIButton4InitEPKcS1_RK7GUIRectP9ecUniFont, 748304)
    off(_ZN10GUINewGameC1Ev, 710864)
    off(_ZN6CFight17GetAttackerResultEi, 399300)
    off(_ZN9TiXmlNode18NextSiblingElementEPKc, 837604)
    off(_ZN15GUIProductPrice4InitERK7GUIRect, 499472)
    off(_ZN6GUIIap4InitERK7GUIRect, 499816)
    off(_ZNK13TiXmlDocument8SaveFileEP7__sFILE, 839336)
    off(_ZN7GUISaveD2Ev, 512332)
    off(_ZN6CScene10MakeAdjoinEii, 592080)
    off(_ZN18ecSessionInterface17DeclineInvitationEPKc, 831108)
    off(_ZN14CPlayerManager13GetNumActionsEv, 589600)
    off(_Z9ecKeyDowni, 393444)
    off(_ZN16GUILockedWarning7OnEventERK5Event, 692360)
    off(_ZN11GUIWarMedalC2Ev, 676216)
    off(_ZN14GUICountryList15GetSelCountryIDEv, 745292)
    off(_ZNK12TiXmlUnknown6CopyToEPS_, 843352)
    off(_Z15GetDocumentPathPKc, 341176)
    off(_ZN12GUIScrollBarD0Ev, 757500)
    off(_ZN6CScene14RenderSeaAreasEv, 593920)
    off(_ZN13GUIMatchSetupD1Ev, 703608)
    off(_ZN16TiXmlDeclarationC2EPKcS1_S1_, 842628)
    off(_ZN13CStateManager13RegisterStateEP10CBaseState, 609264)
    off(_ZN11GUIDefeatedC1Ev, 491108)
    off(_ZN10GUISelArmyD1Ev, 517128)
    off(_ZN10GUIOptions7OnEventERK5Event, 505560)
    off(_ZN9TiXmlBase9GetEntityEPKcPcPi13TiXmlEncoding, 849376)
    off(_ZN10CObjectDefC2Ev, 540256)
    off(_ZN7CCamera5ApplyEv, 660340)
    off(_ZN10CLogoState7OnEventERK5Event, 533408)
    off(_ZN16TiXmlDeclarationD0Ev, 835128)
    off(_ZN10CGameState15EnableIdleTimerEf, 451508)
    off(_ZN10CMenuState10TouchBeginEffi, 534712)
    off(_ZN16GUILockedWarning8OnRenderEv, 691460)
    off(_ZN3MD55resetEv, 352992)
    off(_ZN12TiXmlElementaSERKS_, 846912)
    off(_ZN10GUISelArmyC2Ev, 517380)
    off(_ZN9GUIButton7OnEventERK5Event, 749180)
    off(_ZN13CActionAssist11getNeighborEiiic, 622696)
    off(_ZN8GUIMedalD1Ev, 501512)
    off(_ZN7CPlayer10PushPacketE9PACKET_IDPKvi, 736828)
    off(_ZN10ecGraphics10RenderLineEPK6ecLine, 343172)
    off(_ZN10CEditState7OnEventERK5Event, 397040)
    off(_ZN7ecImage7SetFlipEbbb, 889936)
    off(_ZN7ecShape4InitEP9ecTextureffff, 1129260)
    off(_ZNK12TiXmlComment6CopyToEPS_, 842204)
    off(_ZN10CMenuState8ShowExitEv, 539992)
    off(_ZN13CStateManager8InstanceEv, 608632)
    off(_ZN6CScene10SelectAreaEP5CArea, 603540)
    off(_ZN9CActionAI14getNumArmyMoveEii, 611580)
    off(_ZN3MD5C2ERKSs, 357156)
    off(_ZN11CMatchState6OnExitEv, 534040)
    off(_ZN12CGameManagerC2Ev, 407668)
    off(_ZN10CCommander15UpgradeWarMedalE11WARMEDAL_ID, 391372)
    off(_ZN9ecElementD1Ev, 1125936)
    off(_ZN11CBattleUnit6AttackEv, 656328)
    off(_ZN9GUIResult7OnEventERK5Event, 510960)
    off(_ZN13GUIMatchSetup8OnRenderEv, 702924)
    off(_ZN9ecElement4InitEP13ecElementDataP9ecLibrary, 1127560)
    off(_ZN10CMenuStateD0Ev, 534724)
    off(_ZN6CFight11ApplyResultEv, 399340)
    off(_ZN15GUIProductPriceD1Ev, 499036)
    off(_ZN13CTouchInertiaD2Ev, 609304)
    off(_ZN11GUIDefeatedD2Ev, 492684)
    off(_Z11ecTouchMoveffi, 392920)
    off(_ZN11CMatchState18StartMultiplayGameEi, 534120)
    off(_ZN14TiXmlAttribute14SetDoubleValueEd, 842060)
    off(_ZN5CArmy9PoisoningEv, 644856)
    off(_ZN12GUITutorails6ExeCmdEi, 526284)
    off(_ZN9GUIBattle8OnUpdateEf, 469372)
    off(_ZN6GUIEnd8OnRenderEv, 494892)
    off(_ZN8CCountry16GetWarMedalLevelE11WARMEDAL_ID, 666536)
    off(_ZN9ecElementC2Ev, 1125908)
    off(_ZN10CMenuStateC1Ev, 535284)
    off(_ZN12GUISmallCard8OnRenderEv, 518812)
    off(_ZN16GUIUpgradeButtonD0Ev, 674360)
    off(_ZN13TiXmlDocument8LoadFileEP7__sFILE13TiXmlEncoding, 838356)
    off(_ZN14GUICountryListC2Ev, 745028)
    off(_ZN14CPlayerManager14WillDisconnectEv, 571924)
    off(_ZN16GUIUpgradeButtonC1Ev, 677416)
    off(_ZN10CEditState7OnEnterEv, 398484)
    off(_ZNK9TiXmlNode9ToUnknownEv, 832256)
    off(_ZN6CScene21MoveCameraBetweenAreaEii, 599452)
    off(_ZN11GUIWarMedal8OnRenderEv, 673320)
    off(_ZN12ecTextureRes13CreateTextureEPKcbbb, 893280)
    off(_ZN6CScene13InitAreaImageEi, 595708)
    off(_ZN3MD58toStringEv, 357776)
    off(_ZN10ecGraphics11BindTextureEP9ecTexture, 342872)
    off(_ZN7GUISave8OnRenderEv, 511252)
    off(_ZN6GUITax7SetAreaEi, 520932)
    off(_ZN11GUIButtonExC2Ev, 476020)
    off(_ZN8CCountry13GetNumAirportEv, 663044)
    off(_ZN10CBaseState10TouchBeginEffi, 397000)
    off(_ZN10CObjectDef20ReleaseGeneralPhotosEv, 547024)
    off(_Z16ecPVRTextureLoadPKcRiS1_Rj, 380352)
    off(_ZN8CCountry16CollectIndustrysEv, 668480)
    off(_ZN10GUINewGame14GetIabEventUrlEv, 713408)
    off(_ZN11CBattleUnitD1Ev, 655244)
    off(_ZN14CPlayerManager16onAcceptedInviteEv, 577668)
    off(_ZN6CScene10ClearAreasEv, 594220)
    off(_ZN12GUISmallCard7SetCardEP7CardDef, 519336)
    off(_ZN10GUISelArmy8OnRenderEv, 517240)
    off(_ZN9ecGameKitD2Ev, 831024)
    off(_ZN13GUIBattleList7OnEventERK5Event, 742408)
    off(_ZN7GUISaveD1Ev, 512332)
    off(_ZN6ecFile7GetSizeEv, 351752)
    off(_ZN7CPlayer10SendPacketE9PACKET_IDPKvi, 736612)
    off(_ZN13CStateManager6RenderEv, 608924)
    off(_ZN13CStateManager4InitEv, 608644)
    off(_ZN9GUIButtonD1Ev, 747344)
    off(_ZN6CSceneD2Ev, 591000)
    off(_ZN7ecImage6RenderEff, 887880)
    off(_ZN8GUIBegin9ResetDataEv, 475336)
    off(_ZN12CBattleScene11CreateUnitsEv, 648940)
    off(_Z13ecLoadLibraryPKcR13ecLibraryData, 1124312)
    off(_ZN10CCSoundBox8UnloadSEEPKc, 912200)
    off(_ZN8CGameRes18RenderUIAttackArmyEPKcffiiiiiiib, 430180)
    off(_ZN9TiXmlTextD1Ev, 834984)
    off(_ZN12GUICommander4InitERK7GUIRect, 678500)
    off(_ZN16ecParticleSystem6FireAtEfff, 918452)
    off(_ZN7GUIGoldD2Ev, 497284)
    off(_ZN12TiXmlElement9ClearThisEv, 843876)
    off(_Z12ecGameUpdatef, 392524)
    off(_ZN8CGameRes10RenderFlagEPKcff, 431444)
    off(_ZN6CSceneC1Ev, 591156)
    off(_ZNK9TiXmlNode13ToDeclarationEv, 832272)
    off(_Z19GetCommanderAbilityi, 389492)
    off(_ZN10CMenuState6UpdateEf, 534704)
    off(_ZN9TiXmlBase8ReadTextEPKcP11TiXmlStringbS1_b13TiXmlEncoding, 850356)
    off(_ZN13GUIActionInfoC2Ev, 458976)
    off(_ZN9GUIBattleC2Ev, 467016)
    off(_ZN14CPlayerManager17InvitationDidFailEPKc, 571984)
    off(_ZN7ecLayer6RenderERK7ecMtx32, 1130472)
    off(_ZN10GUINewGame18IsIabEventImgReadyEv, 711356)
    off(_ZN5CArea19DestroyConstructionEv, 637644)
    off(_ZN11GUIArmyItemC1Ev, 517328)
    off(_ZN10CObjectDef15GetGeneralPhotoEPKc, 542532)
    off(_ZN10CLoadState11BackPressedEv, 530700)
    off(_ZN16GUIMotionManager8InstanceEv, 754568)
    off(_ZN7ecImageC1EP11ecImageAttr, 887732)
    off(_ZN10CBaseState11ScrollWheelEfff, 397024)
    off(_ZN11GUIMainMenu8OnUpdateEf, 700596)
    off(_ZN7GUICard7OnEventERK5Event, 489696)
    off(_ZN14CPlayerManager13CancelConnectEv, 574812)
    off(_ZN13CTouchInertia13AddTrackPointEff, 609504)
    off(_ZN10GUIElement8OnRenderEv, 749520)
    off(_ZN9ecElement9ResetItemEP10ecItemDataP9ecLibrary, 1127672)
    off(_ZN9TiXmlNodeC1ENS_8NodeTypeE, 834600)
    off(_ZN18ecSessionInterface7ConnectEPKc, 831092)
    off(_ZN10CGameState9TouchMoveEffi, 446740)
    off(_ZN7CCamera6SetPosEffb, 658808)
    off(_ZN10CFightTextC2Ev, 404664)
    off(_ZN9CActionAID1Ev, 398660)
    off(_ZN9ecLibrary11GetItemDataEi, 1120796)
    off(_ZN12CGameManager13GetCurCountryEv, 410252)
    off(_ZNK12TiXmlUnknown5CloneEv, 843356)
    off(_ZN11ecLabelTextC2Ev, 911056)
    off(_ZN12CGameManager20SetPlayercountrynameEiPKc, 407724)
    off(_ZN10GUIElement8OnUpdateEf, 749524)
    off(_ZN18ecEffectResManagerC1Ev, 902568)
    off(_ZN6CScene15GetAdjacentAreaEii, 600088)
    off(_ZN10CCSoundBox11GetInstanceEv, 911932)
    off(_ZN12CGameManager9TurnBeginEv, 414704)
    off(_ZN14CPlayerManager17RemoveCorpsPlayerEii, 581712)
    off(_Z13ecGameWaitingb, 392400)
    off(_ZN14CPlayerManager23RefreshAndSendCorpsDataEv, 585916)
    off(_ZN11ecLabelText8SetAlphaEf, 911620)
    off(_ZN8CCountry12IsCardUnlockEP7CardDef, 663444)
    off(_ZN13GUIBattleList4InitERK7GUIRecti, 740528)
    off(_ZN5CArmy11GetNumDicesEv, 644952)
    off(_ZN6ecText9GetHeightEv, 917048)
    off(_ZN13GUIBattleItemD0Ev, 737856)
    off(_ZN10GUIManager7FadeOutEiP10GUIElement, 752912)
    off(_ZN11GUICardListC2Ev, 487884)
    off(_ZN13GUIAdornMedalD2Ev, 673580)
    off(_ZN12ecTextureRes11CreateImageEPKcP9ecTextureffffff, 895240)
    off(_ZN10GUIBuyCardD1Ev, 476628)
    off(_ZN10GUIManager7OnEventERK5Event, 752540)
    off(_ZN8CGameRes4LoadEv, 432680)
    off(_ZN12GUITutorails13ReleaseScriptEv, 525448)
    off(_ZN12ecTextureRes14ReleaseTextureEP9ecTexture, 890524)
    off(_ZN6ecText11GetNumLinesEv, 917196)
    off(_ZN10GUIElementD0Ev, 750172)
    off(_Z10ecGameInitiiiii, 394296)
    off(_ZN13CTouchInertiaC2Ev, 609340)
    off(_ZN6CScene6RenderEv, 600128)
    off(_ZN10CGameState11BackPressedEv, 453916)
    off(_ZN10GUIManager16ReleaseTexureResEv, 752876)
    off(_ZN13GUIAIProgress4InitERK7GUIRect, 459712)
    off(_ZN7GUITextD0Ev, 758964)
    off(_ZNK12TiXmlElement9ToElementEv, 832328)
    off(_ZN10GUICardTabD2Ev, 476572)
    off(_ZN10GUIElement6SetPosEff, 750384)
    off(_ZN14GUIBattleIntro9SetBattleEii, 470992)
    off(_ZN6CFightD1Ev, 398760)
    off(_ZN14CPlayerManager20onFriendListReceivedEv, 571940)
    off(_ZN9CActionAI16setCpuDriverbyIdEii, 616040)
    off(_Z9GetAIRandv, 616872)
    off(_ZN8GUIBeginD0Ev, 473576)
    off(_ZN12CGameManager7ReleaseEv, 410008)
    off(_ZN10CBaseState15EnterBackgroundEv, 397028)
    off(_ZN10CObjectDef16LoadCommanderDefEv, 561784)
    off(_ZN14CPlayerManager18SetPlayerOfCountryEv, 586348)
    off(_ZN7ecLayer4InitEiP11ecLayerDataP7ecFrameP9ecElementP9ecLibrary, 1130124)
    off(_ZN10GUIBuyCard14ResetCardStateEv, 482344)
    off(_ZN17GUICommanderMedalC1Ev, 675664)
    off(_ZN10CFightText6RenderEv, 405036)
    off(_ZN10GUIManagerD2Ev, 752592)
    off(_ZN9CActionAI13setArmyActionEP5CArea, 613924)
    off(_ZN6CScene17CheckAdjacentDataEv, 591400)
    off(_ZN7ecFrame9NextFrameEv, 1131268)
    off(_ZN13GUIBattleItem11SetSelectedEb, 740412)
    off(_ZN17GUICommanderMedalD0Ev, 672644)
    off(_ZN6CFightC2Ev, 398732)
    off(_ZN7ecImage10SetTextureEP9ecTexture, 889580)
    off(_ZN7GUICard4InitEP7CardDefRK7GUIRect, 486516)
    off(_ZN8GUIBeginC1Ev, 474104)
    off(_ZN10CCommander4LoadEv, 389752)
    off(_ZN14CPlayerManager22IsDisconnectedFromHostEv, 579656)
    off(_ZN10GUIManager9PostEventERK5Event, 752992)
    off(_ZN8CCountry14BeConquestedByEPS_, 662504)
    off(_ZN8CheckMD5C1Ev, 357836)
    off(_ZN19GUIConnectHostState7OnEventERK5Event, 689444)
    off(_ZN16GUIUpgradeButton8OnRenderEv, 674396)
    off(_ZN12GUITutorailsD1Ev, 525696)
    off(_ZN14GUIBattleIntro7OnEventERK5Event, 473064)
    off(_ZN8CGameResD1Ev, 425572)
    off(_ZN9GUIButton12SetTextColorEj, 749128)
    off(_ZN10GUIManager8InstanceEv, 752824)
    off(_ZN14CPlayerManager18ClearRemotePlayersEv, 576796)
    off(_ZN9GUIResultD1Ev, 507024)
    off(_ZN7ecFrameD2Ev, 1130760)
    off(_ZN14TiXmlAttributeD2Ev, 847824)
    off(_ZN8CGameResD2Ev, 425572)
    off(_ZN13CFightTextMgrC1Ev, 405060)
    off(_ZN13GUIBattleItemD2Ev, 737684)
    off(_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz, 332884)
    off(_ZN13CFightTextMgr4InitEv, 405248)
    off(_ZN14CPlayerManager28SendPacketToAllPlayersExceptE9PACKET_IDPKviP7CPlayer, 579860)
    off(_ZN3MD5C1Ev, 353056)
    off(_ZN14CPlayerManagerD1Ev, 577224)
    off(_ZN8GUIImage8SetImageEPKcRK13ecTextureRectb, 752100)
    off(_ZN7ecFrame6RenderERK7ecMtx32, 1131172)
    off(_ZN8CGameRes22RenderAICommanderMedalEiffPKci, 429480)
    off(_Z14ecGameShutdownv, 392104)
    off(_ZN17GUICommanderMedalD2Ev, 672496)
    off(_ZN10CCommander20CheckUpgradeWarMedalE11WARMEDAL_ID, 391308)
    off(_ZN6CScene25GetTwoAreasDistanceSquareEii, 599756)
    off(_ZN10CLoadStateD0Ev, 530752)
    off(_ZN11CBattleUnit7DestroyEv, 656532)
    off(_ZN18ecEffectResManagerD1Ev, 902840)
    off(_ZN6CFight16AirStrikesAttackEii, 399188)
    off(_ZN6CScene11GetNumAreasEv, 599040)
    off(_ZN6CScene9InitAreasEiPKc, 605552)
    off(_ZN6ecFileD2Ev, 351016)
    off(_ZN6CScene12ClearTargetsEv, 599960)
    off(_ZN14CPlayerManager7ReleaseEv, 577056)
    off(_ZN12GUICommanderD2Ev, 674860)
    off(_ZN9CAreaMarkC1Ev, 644032)
    off(_ZN9CSoundRes6UnloadEv, 608512)
    off(_ZN13GUIAIProgressC1Ev, 459652)
    off(_ZN10GUIOptionsC1Ev, 502820)
    off(_ZN12GUITutorails7HideDlgEv, 526280)
    off(_ZN13GUIBattleList8OnUpdateEf, 739248)
    off(_ZN14CPlayerManager16ClearActionQueueEv, 587104)
    off(_ZN6CScene17RenderAreasCenterEv, 593300)
    off(_ZN6CScene9NewAdjoinEv, 591404)
    off(_ZN10GUINewGame14IsShowIabEventEv, 711836)
    off(_ZN6CScene6UpdateEf, 597928)
    off(_ZN10CCommander4SaveEv, 390396)
    off(_ZN13ecStringTable5ClearEv, 913032)
    off(_ZN12CGameManager10GameUpdateEf, 417060)
    off(_Z13SetAIRandSeedi, 616844)
    off(_ZN9CAreaMarkD2Ev, 644088)
    off(_ZN13CActionAssist16purChaseFortCardEv, 628988)
    off(_ZN10CGameState8TouchEndEffi, 445736)
    off(_ZN8CCountryC1Ev, 660760)
    off(_ZN7_JNIEnv16CallObjectMethodEP8_jobjectP10_jmethodIDz, 332516)
    off(_ZN9TiXmlNode5ClearEv, 835372)
    off(_Z13ecGetUUIDHashv, 831132)
    off(_ZN9CActionAI21analyseCompositePowerEv, 610624)
    off(_ZN10GUIOptionsD2Ev, 502568)
    off(_ZN7CPlayer9SendFirstEv, 737000)
    off(_ZN5CArea6RenderEv, 642352)
    off(_ZN11GUICardList9SetSelectEi, 490028)
    off(_ZN13CActionAssistD1Ev, 406244)
    off(_ZN6ecText7SetTextEPKt, 917832)
    off(_ZN9GUIBattle8OnRenderEv, 465288)
    off(_ZN13GUIActionInfo4InitERK7GUIRect, 459056)
    off(_ZN10GUIServiceC2Ev, 734048)
    off(_ZN16GUIMotionManager15GetMotionActiveEj, 756872)
    off(_ZN13GUISelCountry8OnUpdateEf, 729300)
    off(_ZN7ecFrame4PlayEv, 1131356)
    off(_ZN12CGameManager18GetNumVictoryStarsEv, 413372)
    off(_ZN5CArmy6IsNavyEv, 644528)
    off(_ZN11CMatchStateC1Ev, 534076)
    off(_ZN10CObjectDef10GetArmyDefEiPKc, 551288)
    off(_ZN10GUIManager8AddImageEPKcRK7GUIRectP10GUIElement, 753852)
    off(_ZN16GUIMotionManager9SetMotionEjffffft, 755108)
    off(_ZN10CLoadStateC1Ev, 532196)
    off(_ZN7GUITextD2Ev, 758888)
    off(_ZN6CScene12SaveAreaDataEi, 593592)
    off(_ZN7GUITech8OnRenderEv, 521788)
    off(_ZN9CActionAI12purChaseCardE7CARD_ID, 611832)
    off(_ZN10CGameState7OnEnterEv, 448584)
    off(_ZN10GUISelArmyD0Ev, 517204)
    off(_ZN18ecSessionInterfaceC2Ev, 831068)
    off(_ZN7CPlayerC2Ev, 736440)
    off(_ZN6GUIIapD1Ev, 498484)
    off(_ZN11ecLabelText8DrawTextEff, 911656)
    off(_ZN10ecGraphics14LoadETCTextureEPKc, 349356)
    off(_ZN7GUIBankC2Ev, 462420)
    off(_ZdaPv, 1132244)
    off(_ZN10GUIElementD1Ev, 750152)
    off(_ZN13CGameSettingsD2Ev, 444796)
    off(_ZN10GUINewGameD1Ev, 710416)
    off(_ZN12CGameManagerD2Ev, 406260)
    off(_ZN11CMatchStateD2Ev, 533700)
    off(_ZN18ecSessionInterface13CancelConnectEv, 831096)
    off(_ZN17TiXmlAttributeSetD1Ev, 843520)
    off(_ZN13GUIAdornMedalD0Ev, 673772)
    off(_ZN6ecText8DrawTextEffi, 916628)
    off(_ZN18ecSessionInterfaceD1Ev, 831072)
    off(_ZN10GUINewGameC2Ev, 710864)
    off(_ZN7GUIBankD1Ev, 462020)
    off(_ZN8CGameRes10RenderPortEff, 424516)
    off(_Z9ecGetUUIDRSs, 831128)
    off(_ZN10CObjectDef19ReleaseConquestListEv, 550268)
    off(_ZN10GUISelArmyC1Ev, 517380)
    off(_ZN16TiXmlDeclarationD1Ev, 834860)
    off(_ZN14CPlayerManager17onPlayerConnectedEPKc, 571972)
    off(_ZN13CActionAssist17purChaseCardsCardEv, 626320)
    off(_ZN12TiXmlCommentD1Ev, 835056)
    off(_ZN15ecEffectManager12CreateEffectEPKc, 907768)
    off(_ZN13GUIAdornMedalC1Ev, 676700)
    off(_ZN8CCountry8FindAreaEi, 661648)
    off(_ZN11GUICardList8OnUpdateEf, 485732)
    off(_ZN17GUICommanderMedal8OnUpdateEf, 672792)
    off(_ZN10CCSoundBox9PlayMusicEb, 912128)
    off(_ZN18ecSessionInterface4InitEP17ecSessionDelegate, 831076)
    off(_ZN9TiXmlText5ParseEPKcP16TiXmlParsingData13TiXmlEncoding, 853808)
    off(_ZN7ecImage9Render4VCEffffffffif, 888900)
    off(_ZN10GUIService7OnEventERK5Event, 735880)
    off(_ZN11GUIButtonExD1Ev, 475876)
    off(_ZN11GUILevelSelD2Ev, 689764)
    off(_ZN12CGameManagerC1Ev, 407668)
    off(_ZN13GUIMatchSetup16CreatCorsButtonsEv, 706680)
    off(_ZN6CMedalC1Ev, 736172)
    off(_ZN18ecSessionInterface13GetDeviceNameERSs, 831124)
    off(_ZN12TiXmlComment9ToCommentEv, 832340)
    off(_ZN6CScene4InitEPKci, 607924)
    off(_ZN18ecSessionInterface10DisconnectEPKc, 831100)
    off(_ZN8CCountry19CheckCardTargetAreaEP7CardDefi, 666604)
    off(_ZN14CPlayerManager18SendPacketToServerE9PACKET_IDPKvi, 580016)
    off(_ZN5CArea12IsArmyActiveEi, 640632)
    off(_Z13GetNumBattlesi, 406332)
    off(_ZN14GUICorpsButtonC2Ev, 705304)
    off(_ZN9ecElement11SetCurFrameEi, 1127036)
    off(_ZNK16TiXmlDeclaration13ToDeclarationEv, 832352)
    off(_ZN9ecElement4StopEv, 1127328)
    off(_ZN11ecEffectResD2Ev, 898788)
    off(_ZN10CLogoState15EnterForegroundEv, 532300)
    off(_ZN13CGameSettingsC1Ev, 444800)
    off(_ZN9CSoundRes4LoadEv, 608408)
    off(_ZN10GUISelArmyD2Ev, 517128)
    off(_ZN6CScene15GetSelectedAreaEv, 599952)
    off(_ZN14GUICorpsButtonD1Ev, 703496)
    off(_ZN5CArea12EncirclementEv, 640848)
    off(_ZN12CGameManager10LoadBattleEPKc, 419124)
    off(_Z12JString2CStrP7_JNIEnvP8_jstring, 711996)
    off(_ZN6ecTextD2Ev, 916376)
    off(_ZNK12TiXmlElement7GetTextEv, 837912)
    off(_ZN10CLogoStateD2Ev, 532288)
    off(_ZN10CObjectDef15LoadUnitMotionsEv, 556408)
    off(_ZN5CArmyC2Ev, 644520)
    off(_ZN14CPlayerManager22onReveivedDataFromPeerEPKviPKc, 589204)
    off(_ZN5CArea11HasArmyCardEi, 639836)
    off(_ZN12CGameManager12NextDialogueEv, 413356)
    off(_ZN3MD516bytesToHexStringEPKhm, 357468)
    off(_ZN14GUICorpsButton8OnRenderEv, 702980)
    off(_ZN6CMedal4InitEff, 736176)
    off(_ZN18ecSessionInterface20SendPacketToAllPeersEPKvi, 831116)
    off(_ZN10CEditStateD1Ev, 397056)
    off(_ZNK9TiXmlNode6ToTextEv, 832264)
    off(_ZN9GUIButtonC2Ev, 748200)
    off(_ZN11CBackground6RenderEP7CCamera, 646848)
    off(_ZN12CGameManager18GetDialogueByIndexEi, 410604)
    off(_ZN14CPlayerManager17IsAllPlayersReadyEv, 585644)
    off(_ZN7CCamera14SetPosAndScaleEfff, 658980)
    off(_ZN10GUIManagerC2Ev, 752744)
    off(_ZN3MD56updateERSt14basic_ifstreamIcSt11char_traitsIcEE, 356868)
    off(_ZN11GUISaveItemD1Ev, 511116)
    off(_ZN10CLogoState6OnExitEv, 533288)
    off(_ZN11GUILevelSel7OnEventERK5Event, 690288)
    off(_ZN10GUINewGame12IsShowSurveyEv, 711036)
    off(_ZN10CEditStateC2Ev, 397956)
    off(_ZN14GUIRadioButton8OnRenderEv, 756956)
    off(_ZN16GUIMotionManager8SetSpeedEjff, 756028)
    off(_ZN9TiXmlTextD0Ev, 835004)
    off(_ZN10CGameState16UpdateActionInfoEv, 453360)
    off(_ZN16GUIMotionManager9AddMotionEP10GUIElementffffft, 755412)
    off(_ZN11GUIMainMenuD1Ev, 692592)
    off(_ZN10GUIManagerD1Ev, 752592)
    off(_ZN5CAreaD1Ev, 636764)
    off(_ZN10GUIVictoryC1Ev, 528188)
    off(_ZN13GUISelCountry7OnEventERK5Event, 733528)
    off(_ZNK9TiXmlNode15PreviousSiblingEPKc, 836696)
    off(_ZN10CMenuState6RenderEv, 534708)
    off(_ZN5CArea13SetMoveInArmyEPS_P5CArmybbPKc, 638772)
    off(_ZNK9TiXmlNode15IterateChildrenEPKcPKS_, 836576)
    off(_ZN9GUIResultC2Ev, 508116)
    off(_ZN11GUIMainMenuC2Ev, 693192)
    off(_ZN9ecElement10ChangeItemEP10ecItemDataS1_P9ecLibrary, 1128088)
    off(_ZN10GUIServiceC1Ev, 734048)
    off(_ZN10GUIVictoryD0Ev, 527712)
    off(_ZN10CEditState10TouchBeginEffi, 397500)
    off(_ZN10CLogoState6UpdateEf, 533492)
    off(_ZN8CCountry16IsEnoughIndustryEP7CardDef, 663512)
    off(_ZN11GUILevelSel4InitERK7GUIRecti, 690172)
    off(_ZN14GUICountryListC1Ev, 745028)
    off(_ZN5CArea9TurnBeginEv, 642792)
    off(_ZN12TiXmlElementC1EPKc, 843624)
    off(_ZN6GUIEnd7OnEventERK5Event, 497128)
    off(_ZN13GUIBattleItem4InitEiiRK7GUIRect, 739784)
    off(_ZN12CBattleScene9AddEffectEPKcff, 652932)
    off(_ZN7CCamera13SetAutoFixPosEb, 659420)
    off(_ZN12CGameManager21GetNewDefeatedCountryEv, 414480)
    off(_ZN8ecEffect6IsLiveEv, 907168)
    off(_ZN11GUIDefeated4InitERK7GUIRect, 491232)
    off(_ZN12CBattleScene12ReleaseUnitsEv, 649904)
    off(_ZN11GUIButtonEx8OnRenderEv, 476324)
    off(_ZN14TiXmlAttribute11SetIntValueEi, 841936)
    off(_ZN6ecFile4SeekEli, 351548)
    off(_ZN8CCountry16GetCurCardTargetEv, 663384)
    off(_ZN12CBattleScene12ClearCratersEv, 652760)
    off(_ZN18ecEffectResManagerD2Ev, 902840)
    off(_ZN10CCommander15SetBattlePlayedEii, 391496)
    off(_ZN10GUIServiceD2Ev, 733784)
    off(_ZN9GUIBattleD2Ev, 465000)
    off(_ZN10GUINewGame4InitERK7GUIRect, 714156)
    off(_ZN11CMatchState6RenderEv, 533716)
    off(_ZN10CCSoundBox9StopAllSEEv, 912216)
    off(_ZN10CBaseState11BackPressedEv, 397012)
    off(_ZN13GUIBattleItemC1Ev, 739720)
    off(_Z7GetRandv, 398692)
    off(_ZN9ecLibrary11GetItemNameEj, 1121364)
    off(_ZN10GUIManager6UpdateEf, 753084)
    off(_ZN10CGameState15EnterBackgroundEv, 447696)
    off(_ZN8CCountry12IsConquestedEv, 662356)
    off(_ZN9GUIBattleC1Ev, 467016)
    off(_ZN6GUITaxC1Ev, 520052)
    off(_ZN13CStateManager7KeyDownEi, 609120)
    off(_ZN9ecElementC1Ev, 1125908)
    off(_ZN8ecEffectD2Ev, 906148)
    off(_ZN12GUITutorails8OnRenderEv, 522464)
    off(_ZN3MD56encodeEPKmPhm, 353060)
    off(_ZN14GUICountryListD2Ev, 744116)
    off(_ZN7GUITextC1Ev, 759100)
    off(_ZN10GUICardTab7OnEventERK5Event, 483544)
    off(_ZN10CCSoundBox9StopMusicEv, 912136)
    off(_Z22ecSetIdleTimerDisabledb, 918024)
    off(_ZN9TiXmlNode10FirstChildEPKc, 836184)
    off(_ZN16GUIMotionManagerD2Ev, 754480)
    off(_ZN6ecText4InitEP9ecUniFont, 916400)
    off(_ZN7CPlayerD2Ev, 737164)
    off(_ZN7CPlayer7SendAckEi, 737476)
    off(_ZN8CCountry15GetFirstCapitalEv, 662328)
    off(_ZN10CCSoundBox9LoadMusicEPKcS1_, 912116)
    off(_ZN10ecGraphicsC1Ev, 341260)
    off(_ZN13ecStringTableC2Ev, 912224)
    off(_ZN12GUIAttackBox9SetAttackEii, 461556)
    off(_ZNK11TiXmlHandle17FirstChildElementEPKc, 847272)
    off(_ZN15GUIProductPrice8OnRenderEv, 498296)
    off(_ZN8CCountry15AirstrikeRadiusEv, 666548)
    off(_ZNK12TiXmlElement9StreamOutEP14TiXmlOutStream, 840800)
    off(_ZN9ecGameKit19GetMatchPlayersInfoEv, 831056)
    off(_ZN11GUIDialogue7OnEventERK5Event, 494528)
    off(_ZN9TiXmlBase14SkipWhiteSpaceEPKc13TiXmlEncoding, 848832)
    off(_ZN12GUICorpsInfoD0Ev, 702888)
    off(_ZN13CStateManager9TouchMoveEffi, 608996)
    off(_ZN10CCSoundBox11UpdateSoundEv, 912220)
    off(_ZN15ecEffectManagerD1Ev, 908192)
    off(_ZN8GUIMedalD2Ev, 501512)
    off(_ZN10CFightText4InitEffP9ecUniFont, 404848)
    off(_ZN13CActionAssist14searchNodeByIDEii, 622412)
    off(_ZN14GUIExitWarning8OnRenderEv, 682372)
    off(_ZN10GUIWarningC2Ev, 529592)
    off(_ZN8ecEffectC1Ev, 906120)
    off(_ZNK9TiXmlText9StreamOutEP14TiXmlOutStream, 833788)
    off(_ZN14CPlayerManager16GetNumRightCorpsEv, 581392)
    off(_ZN7CBomber8BombAreaEii, 656988)
    off(_ZN9GUIButtonD0Ev, 747576)
    off(_ZN11CMatchState9TouchMoveEffi, 533724)
    off(_ZN7ecShapeC1Ev, 1129252)
    off(_ZN14CPlayerManager14onMatchRequestEv, 571952)
    off(_ZN10ecGraphics12SetBlendModeEi, 342752)
    off(_ZN14GUICountryItem11SetSelectedEb, 745020)
    off(_ZN16TiXmlDeclaration5ParseEPKcP16TiXmlParsingData13TiXmlEncoding, 854364)
    off(_ZN12CGameManager14GetCurDialogueEv, 413000)
    off(_ZN6GUIEndD0Ev, 494856)
    off(_ZN10GUIWarningD1Ev, 529280)
    off(_ZN12CBattleSceneD1Ev, 654412)
    off(_ZN17GUICommanderMedal8OnRenderEv, 673088)
    off(_ZN5CArea17CheckEncirclementEv, 640672)
    off(_ZN6ecFile4OpenEPKcS1_, 351020)
    off(_ZN13GUIAIProgress17SetCurCountryNameEPKc, 460008)
    off(_ZN6CFight17GetDefenderResultEi, 399312)
    off(_ZN10CGameState6OnExitEv, 448112)
    off(_ZN12GUISmallCardC1Ev, 519232)
    off(_ZN8CGameRes18RenderConstructionEiiff, 424432)
    off(_ZN10GUICardTab4InitERK7GUIRect, 477776)
    off(_ZN5CArmy11AddStrengthEi, 644888)
    off(_ZN7CCamera4InitEffff, 658648)
    off(_ZN9GUIResult8OnUpdateEf, 507020)
    off(_ZN11GUILevelSel8OnRenderEv, 689876)
    off(_ZN11CMatchState8TouchEndEffi, 533728)
    off(_ZN9CAreaMark7GetMarkEii, 644396)
    off(_ZN10GUIWarning7OnEventERK5Event, 530472)
    off(_ZN6CScene20CreateRenderAreaListEv, 607284)
    off(_ZN9GUIButton7SetGlowEPKc, 748612)
    off(_ZN12GUITutorails4InitERK7GUIRect, 524900)
    off(_ZN13CActionAssist16actionToNextAreaEiiii, 633148)
    off(_ZN11CMatchState10TouchBeginEffi, 533720)
    off(_ZN11GUIArmyItemD2Ev, 516804)
    off(_Z9Get2XPathPKcS0_, 340956)
    off(_ZN13GUIBattleItemD1Ev, 737684)
    off(_ZN10ecGraphicsD1Ev, 344896)
    off(_ZN5CArea15MoveArmyToFrontEP5CArmyb, 638504)
    off(_ZN12GUISelBattleC1Ev, 722260)
    off(_ZN10GUIElementC2Ev, 749584)
    off(_ZN10CFightTextD1Ev, 404672)
    off(_ZN6CMedalC2Ev, 736172)
    off(_ZN5CArea18SetAllArmyMovementEi, 640364)
    off(_ZN6CScene13IsRectInSecenEffff, 597848)
    off(_ZN7ecLayer11SetCurFrameEi, 1130336)
    off(_ZN10CMenuState9TouchMoveEffi, 534716)
    off(_ZN7CBomber6RenderEv, 658580)
    off(_ZN7GUITech8OnUpdateEf, 521940)
    off(_ZN11CBackground9RenderBoxEP7CCameraffff, 647008)
    off(_ZN10GUIElement11MoveToFrontEPS_, 750208)
    off(_ZN10CGameState10SelectAreaEi, 451932)
    off(_ZN14CPlayerManager16SessionNoNetworkEv, 572116)
    off(_ZN6CScene10SelectAreaEi, 603596)
    off(_ZN16GUIMotionManager12ActiveMotionEjh, 756056)
    off(_ZN9ecUniFont7ReleaseEv, 908788)
    off(_ZN10CCSoundBox6PlaySEEPKc, 912208)
    off(_ZN11GUIButtonEx12SetImageTextEPKcS1_, 476088)
    off(_ZN10GUIBuyCardC1Ev, 479348)
    off(_ZN6CScene20AllAreasEncirclementEv, 603692)
    off(_ZN9TiXmlNode6ToTextEv, 832312)
    off(_ZN9GUIResult8OnRenderEv, 507408)
    off(_ZN12CGameManager20GetPlayerCountryNameEi, 407916)
    off(_ZN16GUILockedWarningD2Ev, 691288)
    off(_ZN11GUIMainMenu6ShowADEv, 702084)
    off(_ZN13CTouchInertia10TouchBeginEffi, 609584)
    off(_ZN8CCountry16GetCommanderNameEv, 665456)
    off(_ZN11GUICardList7OnEventERK5Event, 490204)
    off(_ZN8CGameRes7ReleaseEv, 426188)
    off(_ZN13GUIActionInfoD1Ev, 458728)
    off(_ZN13GUIBattleListD1Ev, 739148)
    off(_ZN14GUICountryListD0Ev, 744180)
    off(_ZN6GUIEndC1Ev, 495260)
    off(_ZN8CCountry14IsActionFinishEv, 663748)
    off(_ZN13CTouchInertiaD1Ev, 609304)
    off(_ZN14GUIRadioButtonD1Ev, 756900)
    off(_ZN12GUIAttackBoxC2Ev, 460920)
    off(_ZN11GUICardList11ResetSelectEv, 487992)
    off(_ZNK16TiXmlDeclaration5PrintEP7__sFILEi, 832792)
    off(_ZN9ecElementD2Ev, 1125936)
    off(_ZN13CTouchInertia6UpdateEf, 609360)
    off(_ZNK12TiXmlComment5PrintEP7__sFILEi, 832544)
    off(_ZN10GUIBuyCardD2Ev, 476628)
    off(_ZN10CEditState7KeyDownEi, 397036)
    off(_ZN13GUIBattleList9SetSelectEi, 742124)
    off(_ZN12GUISelBattle13LoadImageListEii, 726116)
    off(_ZN11GUIPauseBox8OnRenderEv, 506072)
    off(_ZN16ecParticleSystemC2Ev, 918028)
    off(_ZN11CBackgroundD2Ev, 645772)
    off(_ZN19GUIConnectHostStateC1Ev, 684748)
    off(_ZN10CEditState8TouchEndEffi, 397712)
    off(_ZN15ecMultipleTouch8InstanceEv, 350408)
    off(_ZN15GUIProductPriceD2Ev, 499036)
    off(_ZN11GUIArmyItem8OnRenderEv, 516860)
    off(_ZN12GUIScrollBar8OnRenderEv, 757536)
    off(_ZN10CEditState6OnExitEv, 398612)
    off(_ZN10GUINewGame7OnEventERK5Event, 721060)
    off(_ZN6CScene15CheckAttackableEiii, 602512)
    off(_ZN7GUIGold8OnUpdateEf, 498200)
    off(_ZNK9TiXmlNode17FirstChildElementEPKc, 837064)
    off(_ZN8CGameResC2Ev, 424808)
    off(_ZN10GUIElement9PostEventERK5Event, 751024)
    off(_ZN5CArea15SetConstructionEii, 637380)
    off(_ZN10GUINewGame14BtnSurveyClickEv, 713260)
    off(_ZN9TiXmlNodeD0Ev, 835260)
    off(_ZN7GUITextD1Ev, 758888)
    off(_ZN11CBackgroundC1Ev, 645700)
    off(_ZN10GUIVictory8OnUpdateEf, 527920)
    off(_ZN5CAreaC1Ev, 636692)
    off(_ZN11TiXmlString6appendEPKcm, 831588)
    off(_ZNK12TiXmlComment9StreamOutEP14TiXmlOutStream, 832368)
    off(_ZN14CPlayerManager34onLocalPlayerAuthenticationChangedEv, 571928)
    off(_ZN7CCamera12SetSceneRectEffff, 658788)
    off(_ZN19GUIConnectHostStateD2Ev, 683824)
    off(_ZN8CCountry13IsEnoughMoneyEP7CardDef, 665676)
    off(_ZN9TiXmlBase14StringToBufferC1ERK11TiXmlString, 834520)
    off(_ZN14CPlayerManager9InitCorpsEi, 580344)
    off(_ZN10CObjectDefD2Ev, 548760)
    off(_ZN16TiXmlParsingData5StampEPKc13TiXmlEncoding, 848532)
    off(_ZNK17TiXmlAttributeSet4FindERK11TiXmlString, 844060)
    off(_ZN9TiXmlNode17FirstChildElementEv, 836968)
    off(_ZN12TiXmlUnknownD2Ev, 834788)
    off(_ZN3MD5C1ERSt14basic_ifstreamIcSt11char_traitsIcEE, 357100)
    off(_ZN6CScene9DelAdjoinEii, 592564)
    off(_ZN8CCountry19CheckCardTargetArmyEP7CardDefii, 666284)
    off(_ZN10CMenuState6OnExitEv, 535248)
    off(_ZN14CPlayerManager22SendPacketToAllPlayersE9PACKET_IDPKvi, 580056)
    off(_ZN10ecGraphics23CreateTextureWithStringEPKcS1_iiii, 342968)
    off(_ZplRK11TiXmlStringS1_, 831716)
    off(_ZN12TiXmlCommentC2ERKS_, 842208)
    off(_ZplPKcRK11TiXmlString, 832060)
    off(_ZN10GUIElement7OnEventERK5Event, 749528)
    off(_Z25ecGameWillEnterForegroundv, 392444)
    off(_ZN6CScene15RenderAreasArmyEv, 593304)
    off(_ZN11GUIHostList13ClearHostListEv, 685404)
    off(_ZN8CGameRes18RenderInstallationEiff, 424524)
    off(_ZN10GUINewGame16GetIabEventImageEv, 712700)
    off(_Z10ecTouchEndffi, 393104)
    off(_ZN16ecParticleSystemD1Ev, 918096)
    off(_Z17GetBattleFileNameiiiiPc, 406588)
    off(_ZN15GUIProductPriceC2Ev, 499380)
    off(_ZN13CStateManager4TermEv, 608688)
    off(_ZN7CBomber6UpdateEf, 657640)
    off(_ZN7CBomberD1Ev, 656668)
    off(_ZN9GUIButtonD2Ev, 747344)
    off(_ZN14GUICountryItemC1Ev, 744688)
    off(_ZN14CPlayerManager14onReceivedDataEPKviPKcb, 587336)
    off(_ZN9ecElement6RenderERK7ecMtx32, 1128368)
    off(_ZN8GUIImage4InitEPKcRK13ecTextureRectRK7GUIRectbbb, 751676)
    off(_ZN8CGameRes12RenderUIArmyEPKcffibiiiii, 428952)
    off(_ZN9TiXmlNode15PreviousSiblingEPKc, 836784)
    off(_ZN12TiXmlCommentaSERKS_, 842296)
    off(_ZN12CGameManager12IsManipulateEv, 414584)
    off(_ZN5CArmy14GetMaxStrengthEv, 644880)
    off(_ZN15ecMultipleTouch10TouchBeganEff, 350488)
    off(_ZN13GUISelCountry4InitERK7GUIRecti, 731180)
    off(_ZN10GUIVictory7OnEventERK5Event, 529236)
    off(_ZN9TiXmlNode12LinkEndChildEPS_, 835444)
    off(_ZN6GUIIap7OnEventERK5Event, 498692)
    off(_ZN10GUIOptions4InitERK7GUIRect, 502908)
    off(_ZN9ecElement4PlayEv, 1127212)
    off(_ZN10GUINewGame17GetPromotionImageEv, 712352)
    off(_ZN10GUIManager8AddImageEPKcRK13ecTextureRectRK7GUIRectP10GUIElementb, 753536)
    off(_ZN6ecFile5WriteEPKvj, 351468)
    off(_ZN14GUICountryItemD2Ev, 742976)
    off(_ZN16GUIMotionManager10AddMotionYEP10GUIElementfft, 755864)
    off(_ZN12CGameManager11ClearBattleEv, 409684)
    off(_ZN13TiXmlDocument8LoadFileEPKc13TiXmlEncoding, 838956)
    off(_ZN10GUISelArmy7OnEventERK5Event, 518472)
    off(_ZN13GUISelCountryC1Ev, 729972)
    off(_ZN10ecGraphics12RenderTripleEPK8ecTriple, 343316)
    off(_ZN16ecParticleSystem6RenderEv, 918524)
    off(_ZN8GUIImageD1Ev, 751316)
    off(_ZN14CPlayerManager18SendPacketToPlayerE12PacketHeaderPKviPKc, 579704)
    off(_ZNK11TiXmlHandle5ChildEi, 847340)
    off(_ZN10GUIBuyCard15SetSelCardIntroEv, 482060)
    off(_ZN13CActionAssist21purChaseConstructCardEv, 619540)
    off(_ZN12CBattleScene6AttackEv, 652284)
    off(_ZN14CPlayerManager4StopEv, 577652)
    off(_ZN9ecUniFontD2Ev, 909000)
    off(_ZN11GUIHostListD2Ev, 683912)
    off(_ZN9ecElement10ChangeItemEPKcS1_P9ecLibrary, 1128264)
    off(_ZN10CGameState11ShowWarningEi, 452172)
    off(_Z14ecIsFullScreenv, 393776)
    off(_ZN7GUISaveD0Ev, 512528)
    off(_ZN9CActionAI11detectCardsE7CARD_ID, 610376)
    off(_ZN10CGameState15ResetTouchStateEv, 453888)
    off(_ZN18ecEffectResManager19ReleaseAllEffectResEv, 903092)
    off(_ZN14TiXmlAttribute5ParseEPKcP16TiXmlParsingData13TiXmlEncoding, 851440)
    off(_ZN10CLoadStateD1Ev, 530708)
    off(_ZN18ecEffectResManager16ReleaseEffectResEP11ecEffectRes, 902024)
    off(_ZN17GUICommanderMedal13SetArrowColorEj, 676200)
    off(_ZN12GUISelBattle7OnEventERK5Event, 728320)
    off(_Z12ecShowReviewv, 393488)
    off(_ZN10GUIBuyCard13ReleaseTargetEv, 483524)
    off(_ZN11GUIHostListC1Ev, 685328)
    off(_ZN9ecUniFontC1Ev, 908588)
    off(_ZN16GUIMotionManager11ClearMotionEv, 754708)
    off(_ZN14CPlayerManager17RemoveCorpsPlayerEP7CPlayer, 581776)
    off(_ZN9ecElement7SetLoopEi, 1127440)
    off(_ZNK9hgeVector5AngleEPKS_, 887256)
    off(_ZN9ecLibraryC2Ev, 1120736)
    off(_ZN9TiXmlNode15IterateChildrenEPKcPS_, 836680)
    off(_ZN7GUICard8SetPriceEi, 487652)
    off(_ZN9ecUniFont4InitEPKcb, 909248)
    off(_Z13ecTextureLoadPKcRiS1_Rj, 377056)
    off(_ZN11GUIDialogue8OnUpdateEf, 493116)
    off(_ZN9TiXmlNode16InsertAfterChildEPS_RKS_, 835688)
    off(_ZN9ecGameKit25ShowMatchmakerWithRequestEiii, 831044)
    off(_ZN10GUIElement11RemoveChildEPS_, 749820)
    off(_ZN10CGameState6RenderEv, 445556)
    off(_ZN11GUIDefeated8OnUpdateEf, 492792)
    off(_ZN14GUICountryList7OnEventERK5Event, 746780)
    off(_ZN11GUISaveItemD2Ev, 511116)
    off(_ZN13GUIActionInfoC1Ev, 458976)
    off(_ZN6CScene13CheckAdjacentEii, 601964)
    off(_ZN5CArea13SetArmyActiveEib, 640596)
    off(_ZN11GUIHostItem7SetNameEPKc, 685160)
    off(_ZN8GUIImageC2Ev, 751608)
    off(_Z11ecGamePausev, 392372)
    off(_ZN16ecParticleSystem6UpdateEf, 918756)
    off(_ZN11GUISaveItemC1Ev, 512636)
    off(_ZN9ecGameKit4InitEP17ecGameKitDelegateb, 831028)
    off(_ZN14GUICountryList9SetSelectEi, 745788)
    off(_ZN6ecFile9GetCurPosEv, 351644)
    off(_ZN6CFight11FirstAttackEii, 404564)
    off(_ZN7ecFrame4StopEv, 1131444)
    off(_ZN15ecMultipleTouchC1Ev, 350396)
    off(_ZN8CCountry6ActionERK13CountryAction, 672168)
    off(_ZN16GUIUpgradeButtonD1Ev, 674276)
    off(_ZN9GUIBattle13UpateFightingEf, 468996)
    off(_ZN10GUINewGame15IsShowSurveyTipEv, 711516)
    off(_ZN12TiXmlElementD1Ev, 843960)
    off(_ZN6GUITaxD0Ev, 519608)
    off(_ZN16GUIUpgradeButtonC2Ev, 677416)
    off(_ZN10CObjectDef16GetUnitPositionsEPKc, 541660)
    off(_ZN11GUISaveItem8OnUpdateEf, 512564)
    off(_ZN10GUIManager12AddScrollBarERK7GUIRectP10GUIElementPKcS6_iiiii, 754256)
    off(_ZN10CEditState6UpdateEf, 397144)
    off(_ZN12CBattleScene6RenderEv, 647672)
    off(_ZN12GUISelBattle9SelBattleEii, 727664)
    off(_ZN14CPlayerManager20onPlayerDisconnectedEPKc, 582104)
    off(_ZN12GUICommander7OnEventERK5Event, 681328)
    off(_ZN12CGameManager20GetCurDialogueStringEPc, 413068)
    off(_ZN13GUIAdornMedal4InitER7GUIRect, 677104)
    off(_ZN13GUIMatchSetup18RefreshCorsButtonsEv, 707556)
    off(_ZN11GUIPauseBoxD1Ev, 505936)
    off(_ZN7ecLayerC2Ev, 1129800)
    off(_ZN9ecLibrary4LoadEPKcR12ecTextureRes, 1123012)
    off(_Z22ecApplicationTerminatev, 393748)
    off(_Z15ecAccelerometerfff, 393396)
    off(_ZNK9TiXmlText5BlankEv, 855388)
    off(_ZN17TiXmlAttributeSet3AddEP14TiXmlAttribute, 843768)
    off(_ZN13GUISelCountry16ReleaseImageListEv, 733084)
    off(_ZN5CArea16LostArmyStrengthEii, 640024)
    off(_ZN6CScene12ScreenToAreaEff, 599072)
    off(_ZN11GUIDialogueC1Ev, 493784)
    off(_ZN13CStateManager15EnterBackgroundEv, 609192)
    off(_ZN10GUINewGame12IsImageReadyEv, 711196)
    off(_ZN13ecStringTable9GetStringEPKc, 912252)
    off(_ZNK12TiXmlElement20QueryDoubleAttributeEPKcPd, 844952)
    off(_ZN14CPlayerManager13DoFrontActionEv, 589228)
    off(_ZN6CScene19GetTwoAreasDistanceEii, 599876)
    off(_ZN10CObjectDef17ReleaseBattleListEv, 547688)
    off(_ZN7GUICard11SetIndustryEi, 487760)
    off(_ZN6CFightD2Ev, 398760)
    off(_ZN12ecTextureResD1Ev, 891292)
    off(_ZN18ecEffectResManagerC2Ev, 902568)
    off(_ZN7ecLayerD1Ev, 1129760)
    off(_ZN10GUILoading8OnRenderEv, 690664)
    off(_ZN13GUISelCountryD0Ev, 733492)
    off(_ZNK11TiXmlHandle12ChildElementEi, 847544)
    off(_ZN5CArea11DelArmyCardEii, 639740)
    off(_ZN7GUIBank7OnEventERK5Event, 464456)
    off(_ZN7GUIText4InitERK7GUIRectP9ecUniFont, 759148)
    off(_ZN10GUIOptionsC2Ev, 502820)
    off(_ZN8GUIBeginD1Ev, 473300)
    off(_ZN3MD5C1ERKSs, 357156)
    off(_ZN12GUIAttackBoxD0Ev, 460292)
    off(_ZN9GUIButton8SetAlphaEf, 749172)
    off(_ZN11GUIDialogueD0Ev, 493308)
    off(_Znwm, 1136764)
    off(_ZN8CCountry4InitEPKcS1_, 660948)
    off(_ZN10CObjectDef7DestroyEv, 550928)
    off(_ZN12GUISmallCardC2Ev, 519232)
    off(_ZN12GUIScrollBarD2Ev, 757392)
    off(_ZN12GUISelBattle16ReleaseImageListEv, 725280)
    off(_ZN12CGameManager15GetNumCountriesEv, 410104)
    off(_ZN6CScene15RenderAreasTypeEv, 594208)
    off(_ZN10GUIOptionsD0Ev, 502720)
    off(_ZN6CFight12GetDefendAddEi, 399332)
    off(_ZN14CPlayerManager9AddPlayerEbPKc, 576048)
    off(_ZN12GUISmallCardD1Ev, 518700)
    off(_ZN9CSoundResC2Ev, 608348)
    off(_ZN8GUIBeginC2Ev, 474104)
    off(_ZN12CGameManager7EndTurnEv, 414952)
    off(_ZNK11TiXmlHandle17FirstChildElementEv, 847204)
    off(_ZNK11TiXmlHandle10FirstChildEPKc, 847136)
    off(_ZN5CArea7AddArmyEP5CArmyb, 638016)
    off(_ZN14CPlayerManager10StartMatchEv, 575992)
    off(_ZN8CCountry14SetCardTargetsEP7CardDef, 667680)
    off(_ZN8ecEffect6UpdateEf, 906992)
    off(_Z13ecScrollWheelfff, 393400)
    off(_ZN13CGameSettingsD1Ev, 444796)
    off(_ZN10GUIElement6CenterEv, 750424)
    off(_ZN10CLogoState6RenderEv, 533308)
    off(_ZN11CMatchStateC2Ev, 534076)
    off(_ZN12GUISelBattleD1Ev, 725508)
    off(_ZN19GUIConnectHostState4InitER7GUIRect, 684824)
    off(_ZN5CArea7TurnEndEv, 643020)
    off(_ZN8GUIMedalD0Ev, 501596)
    off(_ZN12ecTextureRes7ReleaseEv, 891692)
    off(_ZN8ecEffect4FireEv, 906712)
    off(_ZN14TiXmlAttributeD1Ev, 847824)
    off(_ZN9ecElement4InitEPKcP9ecLibrary, 1126968)
    off(_ZN6CScene14SetAreaCountryEiP8CCountry, 599936)
    off(_ZN11CBackground4InitEiiiiiffff, 645996)
    off(_ZN9ecElement4InitEP10ecItemDataP9ecLibrary, 1126232)
    off(_ZN14GUIBattleIntroC2Ev, 470640)
    off(_ZN8CCountry18FindAdjacentAreaIDEib, 662700)
    off(_ZN10CGameState11ReleaseGameEv, 447992)
    off(_ZN10CGameState10TouchBeginEffi, 454076)
    off(_Z11SetRandSeedi, 398664)
    off(_ZN14CPlayerManager12onStartMatchEv, 583884)
    off(_ZN6CScene14SaveAreaEnableEPKc, 595576)
    off(_ZN10GUICardTabC1Ev, 477336)
    off(_ZN13CTouchInertia8GetSpeedERfS0_, 609432)
    off(_ZN6GUIIap14SetLocalePirceEiPKc, 501472)
    off(_ZN7CPlayer10RecvPacketEPKvi, 736996)
    off(_ZN10CGameState6UpdateEf, 452380)
    off(_ZN11GUIArmyItemC2Ev, 517328)
    off(_ZN14GUIExitWarningC2Ev, 682472)
    off(_ZN9ecGameKit18GetLocalPlayerInfoER12ecPlayerInfo, 831060)
    off(_ZN8CCountry10CanBuyCardEP7CardDef, 666108)
    off(_ZN6CScene11LoadAreaTaxEi, 604576)
    off(_ZN5CArea12CanConstructEi, 637108)
    off(_ZN10CFightText6UpdateEf, 404920)
    off(_ZN8CCountry8GetTaxesEv, 668088)
    off(_ZN10GUIElement4MoveEff, 750396)
    off(_ZN13CStateManager10TouchBeginEffi, 608960)
    off(_ZN12TiXmlElement9ToElementEv, 832332)
    off(_ZN9GUIResultD2Ev, 507024)
    off(_ZN10GUICardTabD0Ev, 476592)
    off(_ZNK12TiXmlElement9AttributeEPKcPd, 844564)
    off(_ZN10CCSoundBox18DestroySoundSystemEv, 912040)
    off(_ZN7ecImage13RenderStretchEffff, 888620)
    off(_ZN15ecEffectManager6RenderEv, 908528)
    off(_ZN10CLoadState8TouchEndEffi, 530696)
    off(_ZN12ecTextureRes10GetTextureEPKc, 892224)
    off(_Z14ecSaveLibrarayPKcR13ecLibraryDataS0_i, 1125272)
    off(_ZNK9TiXmlNode11NextSiblingEPKc, 836488)
    off(_ZNK9TiXmlNode9ToElementEv, 832240)
    off(_ZN10ecGraphics9RenderEndEv, 342468)
    off(_Z17ecWEBPTextureLoadPKcRiS1_Rj, 381812)
    off(_ZN9GUIResultC1Ev, 508116)
    off(_ZN10CGameState18PlayerCountryBeginEv, 451876)
    off(_ZN8GUIMedalC2Ev, 501788)
    off(_ZN14GUIExitWarning7OnEventERK5Event, 683620)
    off(_Z15ecInAppPurchasei, 393684)
    off(_ZNK11TiXmlHandle5ChildEPKci, 847404)
    off(_Z12ecGameResumev, 392388)
    off(_ZN13CStateManager15EnterForegroundEv, 609228)
    off(_ZN11CBattleUnit4InitEiiP9ecLibraryP11UnitMotions, 654732)
    off(_ZN9CAreaMarkC2Ev, 644032)
    off(_ZN12CGameManager8SaveGameEPKc, 408556)
    off(_ZN12GUIAttackBoxD2Ev, 460136)
    off(_ZN10GUIManager9AddButtonEPKcS1_RK7GUIRectP10GUIElementP9ecUniFont, 754056)
    off(_ZN9ecLibrary12FindItemDataEPKc, 1120844)
    off(_ZN12GUISelBattleC2Ev, 722260)
    off(_ZN13TiXmlDocument8LoadFileE13TiXmlEncoding, 839176)
    off(_ZN6CFight12NormalAttackEii, 402788)
    off(_ZN12GUIScrollBar7OnEventERK5Event, 758248)
    off(_ZN14CPlayerManager14SetCorpsByDataEPviP7CPlayer, 584960)
    off(_ZN17TiXmlAttributeSetD2Ev, 843520)
    off(_ZN13GUISelCountry9SelBattleEii, 730112)
    off(_ZN14GUIRadioButtonC2Ev, 757340)
    off(_ZN10GUIElementD2Ev, 750152)
    off(_ZN13CFightTextMgr6RenderEv, 406036)
    off(_ZN16GUIMotionManager10AddMotionXEP10GUIElementfft, 755700)
    off(_ZN7ecImage8SetAlphaEfi, 889800)
    off(_ZN5CArea10MoveArmyToEPS_, 638884)
    off(_ZN18ecSessionInterfaceD2Ev, 831072)
    off(_ZN10GUIElement6GetPosERfS0_, 750364)
    off(_ZN14GUICorpsButtonD0Ev, 703572)
    off(_ZNK9TiXmlNode9ToCommentEv, 832248)
    off(_ZN10CLogoStateC1Ev, 533660)
    off(_ZN16GUIMotionManagerD1Ev, 754480)
    off(_ZN13GUIMatchSetupC1Ev, 706600)
    off(_ZN14GUICorpsButtonC1Ev, 705304)
    off(_ZN11ecLabelText7SetTextEPKc, 911412)
    off(_ZN13CActionAssist17purChaseDraftCardEb, 624876)
    off(_ZN13CStateManager11ScrollWheelEfff, 609156)
    off(_ZN11GUIDialogue8OnRenderEv, 493344)
    off(_ZN11CBattleUnitC2Ev, 654696)
    off(_ZN10CLogoStateD1Ev, 532288)
    off(_ZN12TiXmlElement15RemoveAttributeEPKc, 845388)
    off(_ZN7_JNIEnv22CallStaticObjectMethodEP7_jclassP10_jmethodIDz, 710680)
    off(_ZN10CGameState16UpdateAIProgressEv, 448332)
    off(_ZN5CArmyC1Ev, 644520)
    off(_ZN19GUIConnectHostState8OnRenderEv, 684184)
    off(_ZN11GUIDialogueD2Ev, 493120)
    off(_ZN12ecTextureRes11CreateImageEPKcS1_ffffff, 897392)
    off(_ZN13CStateManager11GetStatePtrE6EState, 609296)
    off(_ZN16GUIMotionManagerC2Ev, 754484)
    off(_ZN14CPlayerManager9StopMatchEv, 577604)
    off(_ZN6CScene17GetAdjacentAreaIDEii, 600056)
    off(_ZN13CStateManager11SetCurStateE6EState, 609276)
    off(_ZNK9TiXmlNode17FirstChildElementEv, 836872)
    off(_ZN17GUICommanderMedal4InitERK7GUIRecti, 675744)
    off(_ZN11CBattleUnit12SetDestroyedEv, 656520)
    off(_ZN9GUIBattle11ResetBattleEv, 467884)
    off(_ZN12TiXmlCommentC1ERKS_, 842208)
    off(_ZN10CObjectDef11LoadArmyDefEv, 553620)
    off(_ZN10GUINewGame14GetSelectGroupEP14GUIRadioButton, 713956)
    off(_ZN7ecFrameC1Ev, 1130800)
    off(_ZN12TiXmlElement9ReadValueEPKcP16TiXmlParsingData13TiXmlEncoding, 855520)
    off(_Z11GetRandSeedv, 398680)
    off(_ZN6ecFile4ReadEPvj, 351328)
    off(_ZN7ecImageC2EP11ecImageAttr, 887732)
    off(_ZN14CPlayerManager7ConnectEPKci, 573124)
    off(_ZN12GUITutorailsC1Ev, 523196)
    off(_ZN10GUIOptions8OnRenderEv, 502756)
    off(_ZN9ecGameKit10SendPacketEPKviPKc, 831036)
    off(_ZN3MD5C2EPKvm, 356816)
    off(_ZN12CGameManager4InitEv, 407720)
    off(_ZN12CGameManager7NewGameEiiii, 407952)
    off(_ZN11CBackgroundC2Ev, 645700)
    off(_ZN16TiXmlDeclarationC1EPKcS1_S1_, 842628)
    off(_ZN11CBattleUnit6RenderEv, 656052)
    off(_Z18ecPurchasedProducti, 393632)
    off(_ZN10CBaseState9TouchMoveEffi, 397004)
    off(_ZN7GUIGoldC2Ev, 497580)
    off(_ZN12ecTextureRes7LoadResEPKcb, 896344)
    off(_ZN8CCountry17GetCommanderLevelEv, 665480)
    off(_ZN10CMenuStateD2Ev, 534692)
    off(_ZN14CPlayerManager4InitEv, 572228)
    off(_Z24GetNumMultiPlayerBattlesi, 406808)
    off(_ZN7ecShapeD1Ev, 1129256)
    off(_ZNK14TiXmlAttribute13QueryIntValueEPi, 841832)
    off(_ZN11GUIDefeated8OnRenderEv, 490768)
    off(_ZN11GUIPauseBox7OnEventERK5Event, 506880)
    off(_ZN8CGameRes11GetBattleBGEPKc, 424548)
    off(_ZN8CGameRes20RenderCommanderMedalEiffi, 424096)
    off(_ZN12TiXmlElementC2ERKS_, 846780)
    off(_Z15ecSetFullScreenb, 393792)
    off(_ZN10CCSoundBoxC2Ev, 911740)
    off(_ZN8CCountry22FindAdjacentLandAreaIDEib, 662868)
    off(_ZN10CEditState9TouchMoveEffi, 397592)
    off(_ZN9ecElement6UpdateEf, 1129096)
    off(_ZN10CCSoundBoxD1Ev, 911772)
    off(_ZN11GUIHostItemD2Ev, 684428)
    off(_ZN12TiXmlUnknown5ParseEPKcP16TiXmlParsingData13TiXmlEncoding, 853208)
    off(_ZN12GUICommander8OnRenderEv, 675212)
    off(_ZN7ecShapeC2Ev, 1129252)
    off(_ZN5CArmy16ResetMaxStrengthEb, 644592)
    off(_ZN15ecEffectManager8InstanceEv, 907756)
    off(_ZN11GUIWarMedalD0Ev, 672756)
    off(_ZN10GUISelArmy4InitERK7GUIRect, 517432)
    off(_ZN10ecGraphicsD2Ev, 344896)
    off(_ZNK9TiXmlNode15IterateChildrenEPKS_, 836448)
    off(_ZN10CCommander7UpgradeEv, 391112)
    off(_ZN7GUISave7SelItemEi, 515912)
    off(_ZN16GUILockedWarningC1Ev, 691660)
    off(_ZN11GUIDefeatedC2Ev, 491108)
    off(_ZN7ecImage8Render4VEffffffff, 888752)
    off(_ZNK14TiXmlAttribute8PreviousEv, 841144)
    off(_ZN16GUILockedWarningD0Ev, 691424)
    off(_ZN7ecImage8RenderExEfffff, 888216)
    off(_ZN11GUIHostList13ConnectFailedEv, 686500)
    off(_ZN8CGameRes21RenderArmyMovementNumEffi, 424408)
    off(_ZN10ecGraphics10RenderQuadEPK6ecQuad, 343476)
    off(_ZN10CCommanderD1Ev, 389488)
    off(_ZN9TiXmlNode11NextSiblingEPKc, 836592)
    off(_ZN10GUIElementC1Ev, 749584)
    off(_ZN8CCountryC2Ev, 660760)
    off(_ZN6GUITaxC2Ev, 520052)
    off(_ZN6GUIIapD0Ev, 498656)
    off(_ZN9TiXmlNodeD2Ev, 834672)
    off(_ZN7GUISave4InitERK7GUIRectib, 513740)
    off(_ZN13CTouchInertia4StopEv, 609344)
    off(_ZN10GUINewGame21OnRadioBtnSurveyClickEv, 713620)
    off(_ZN13CStateManagerD1Ev, 608624)
    off(_ZN10CEditStateC1Ev, 397956)
    off(_ZN7GUIGoldD1Ev, 497284)
    off(_ZN10ecGraphics13CreateTextureEii, 341876)
    off(_ZN6CScene16MoveCameraToAreaEi, 599216)
    off(_ZN10GUICardTab9SelectTabEi, 477492)
    off(_ZN5CAreaD2Ev, 636764)
    off(_ZN15ecEffectManager9RemoveAllEv, 908068)
    off(_ZN14CPlayerManager21GetDisconnectedPlayerEv, 579584)
    off(_ZN9TiXmlBase14StringToBufferD1Ev, 834584)
    off(_ZN7GUIText12SetTextColorEj, 759320)
    off(_ZN18ecSessionInterface15GetPeerNameListERSt4listISsSaISsEES3_, 831088)
    off(_ZN10GUILoadingD2Ev, 690528)
    off(_ZN7_JNIEnv21CallStaticFloatMethodEP7_jclassP10_jmethodIDz, 333068)
    off(_ZN13CStateManagerC2Ev, 608628)
    off(_ZN11ecEffectResC2Ev, 898632)
    off(_ZN7_JNIEnv23CallStaticBooleanMethodEP7_jclassP10_jmethodIDz, 332700)
    off(_ZN10CCommander16GetCommanderDataER13CommanderData, 391668)
    off(_ZN10CEditStateD0Ev, 397100)
    off(_ZN10GUIElement6UpdateEf, 751228)
    off(_ZN13GUIBattleListD0Ev, 739212)
    off(_ZN7CPlayer7RecvAckEi, 737520)
    off(_ZN13GUIActionInfoD0Ev, 458812)
    off(_ZN8CCountryD1Ev, 660804)
    off(_ZN8CCountry6UpdateEf, 671808)
    off(_ZNK9TiXmlNode18NextSiblingElementEPKc, 837488)
    off(_ZN11GUIWarMedalD2Ev, 672680)
    off(_ZNK12TiXmlElement17QueryIntAttributeEPKcPi, 844644)
    off(_ZN6CFight16AirStrikesAttackEP8CCountryii, 398840)
    off(_ZNK14TiXmlAttribute9StreamOutEP14TiXmlOutStream, 841584)
    off(_ZN10CFightText7SetTextEPKc, 404904)
    off(_ZN18ecSessionInterface12SetupSessionEb, 831084)
    off(_ZN9GUIButton13SetTextOffsetEff, 749144)
    off(_ZN16GUILockedWarningD1Ev, 691288)
    off(_ZNK13TiXmlDocument5PrintEP7__sFILEi, 840084)
    off(_ZN13CFightTextMgrD1Ev, 404680)
    off(_ZN7CBomber9IsBombingEv, 657620)
    off(_ZN7GUICard16SetIndustryColorEj, 487876)
    off(_ZN7GUITech4InitERK7GUIRect, 522084)
    off(_ZN12GUICommander8OnUpdateEf, 675576)
    off(_ZN5CArmyD1Ev, 644524)
    off(_ZN10CObjectDef8InstanceEv, 540492)
    off(_ZN8ecEffectD1Ev, 906148)
    off(_ZN10CCommander19GetNeedUpgradeMedalE11WARMEDAL_ID, 391272)
    off(_ZN13CActionAssist21purChaseAirStrikeCardEv, 630288)
    off(_ZN12TiXmlElement5ParseEPKcP16TiXmlParsingData13TiXmlEncoding, 856048)
    off(_ZN9TiXmlNode9LastChildEPKc, 836360)
    off(_ZN6ecTextC2Ev, 916356)
    off(_ZN16ecParticleSystemC1Ev, 918028)
    off(_ZN7CCamera6MoveToEffb, 659780)
    off(_ZN10CObjectDef15GetCommanderDefEPKc, 542096)
    off(_ZN15ecMultipleTouch5ResetEv, 350420)
    off(_ZN10GUILoadingC1Ev, 690876)
    off(_ZN10CCommander16GetWarMedalLevelE11WARMEDAL_ID, 391260)
    off(_ZN13GUIAIProgressD1Ev, 459176)
    off(_ZN12GUICorpsInfoD1Ev, 702776)
    off(_ZN16GUIMotionManager10ProcMotionEv, 756180)
    off(_ZN7ecFrame10ChangeItemEP10ecItemDataS1_P9ecLibrary, 1131052)
    off(_ZN10CMenuState13PeerConnectedEv, 535324)
    off(_ZN7CPlayer4InitEbPKc, 736488)
    off(_ZN16TiXmlDeclarationaSERKS_, 843184)
    off(_ZN10GUILoading7OnEventERK5Event, 691256)
    off(_ZN7CBomberC2Ev, 656652)
    off(_ZN14GUICountryItemC2Ev, 744688)
    off(_ZN10CBaseState6OnExitEv, 396992)
    off(_ZN8CGameRes14RenderArmyInfoEiffiiiii, 423692)
    off(_ZN14GUIBattleIntro4InitERK7GUIRectii, 471720)
    off(_ZN6ecFile21CheckFileExistFromZipEPKcS1_, 352772)
    off(_Z12ecTouchBeginffi, 392736)
    off(_ZN9TiXmlNode11RemoveChildEPS_, 835984)
    off(_ZN10GUINewGame23OnRadioBtnIabEventClickEv, 713788)
    off(_ZN7ecFrame5ResetEv, 1130964)
    off(_ZN7ecImageC2EP9ecTextureRK13ecTextureRect, 887660)
    off(_ZN14GUIBattleIntro8OnRenderEv, 470020)
    off(_ZN8CCountry13GetCardRoundsE7CARD_ID, 663464)
    off(_ZN9ecLibrary14GetElementDataEi, 1121280)
    off(_ZN9CSoundResD2Ev, 608344)
    off(_ZN10GUINewGame13GetAppVersionEv, 714152)
    off(_ZN12CGameManager11GetPlayerNoEPKc, 407752)
    off(_ZN8CCountry10RemoveAreaEi, 661284)
    off(_ZN7GUIGold8OnRenderEv, 497412)
    off(_ZN9ecLibrary12GetFrameDataEi, 1121328)
    off(_ZN10GUIBuyCardC2Ev, 479348)
    off(_ZN8CheckMD56INfileEPKcS1_, 357840)
    off(_ZN12CBattleScene4InitEiPS_, 647608)
    off(_ZN10CLoadState7OnEnterEv, 530796)
    off(_ZN14GUIExitWarning4InitERK7GUIRect, 682588)
    off(_ZN7CCameraC2Ev, 658644)
    off(_ZNK9TiXmlNode9LastChildEPKc, 836272)
    off(_ZN10CEditState8InitGameEv, 398024)
    off(_ZN10CLoadState6UpdateEf, 531956)
    off(_ZN13ecStringTableD2Ev, 913396)
    off(_ZNK14TiXmlAttribute4NextEv, 840264)
    off(_ZN10GUIElement12FindByHandleEj, 750932)
    off(_ZN11GUIDefeatedD0Ev, 492756)
    off(_ZN5CArmy7UpgradeEv, 645172)
    off(_ZN5CArea8LoadAreaEPK12SaveAreaInfo, 643800)
    off(_ZN9TiXmlNode9ToUnknownEv, 832304)
    off(_ZN8GUIMedal4InitERK7GUIRect, 502004)
    off(_ZN10CCSoundBox14SetMusicVolumeEi, 912144)
    off(_ZN9TiXmlBase11StringEqualEPKcS1_b13TiXmlEncoding, 850028)
    off(_ZN12GUICorpsInfoC1Ev, 704000)
    off(_ZN11CBattleUnit7ReleaseEv, 655164)
    off(_ZN8CCountry10AddDestroyEi, 664392)
    off(_Z24ecGameDidEnterBackgroundv, 392412)
    off(_ZN14CPlayerManager12GetCorpsDataERi, 582288)
    off(_ZN10ecGraphics10RenderRectEffffm, 343804)
    off(_ZN7GUICardD1Ev, 484328)
    off(_ZN16TiXmlDeclarationC1ERKS_, 842992)
    off(_ZN10GUIElement6RenderEv, 751148)
    off(_ZN13TiXmlDocumentC1Ev, 837968)
    off(_ZN13CFightTextMgr7AddTextEffPKcj, 406096)
    off(_ZN13ecStringTable4LoadEPKc, 914728)
    off(_ZN15GUIProductPriceD0Ev, 499228)
    off(_ZN10CCommander17GetNumBattleStarsEii, 391572)
    off(_ZN14CPlayerManager8SelCorpsEiiP7CPlayer, 581420)
    off(_ZN12CGameManager13InitCameraPosEv, 410272)
    off(_ZN7ecFrameD0Ev, 1130764)
    off(_ZN5CAreaC2Ev, 636692)
    off(_ZN8CCountry7AddAreaEi, 661704)
    off(_ZNK12TiXmlUnknown9ToUnknownEv, 832360)
    off(_ZN12GUISelBattle8OnRenderEv, 721612)
    off(_ZN7GUICard13SetPriceColorEj, 487868)
    off(_ZN9CSoundResC1Ev, 608348)
    off(_ZN9ecElement9NextFrameEv, 1128888)
    off(_ZN10ecGraphics14SetOrientationEi, 341792)
    off(_ZN11GUIMainMenu13RefreshNewTipEv, 693440)
    off(_ZN13TiXmlDocumentD2Ev, 847928)
    off(_ZN6GUIEnd4InitERK7GUIRect, 495384)
    off(_ZN10GUIVictory4PlayEv, 529104)
    off(_ZN13GUIActionInfoD2Ev, 458728)
    off(_ZN13GUIBattleListC1Ev, 740420)
    off(_ZN8CGameRes12GetArmyImageEPKcib, 428336)
    off(_Z12ecGameRenderv, 392636)
    off(_ZN10GUIWarning8OnUpdateEf, 529276)
    off(_ZN10GUISelArmy10TargetArmyEi, 518368)
    off(_ZNK9TiXmlText6ToTextEv, 832344)
    off(_ZN8CGameRes10RenderArmyEPKciiffimbf, 428644)
    off(_ZN11TiXmlString6assignEPKcm, 831340)
    off(_ZN8CGameResC1Ev, 424808)
    off(_ZN9ecUniFontD1Ev, 909000)
    off(_ZN13GUIBattleList11ResetSelectEv, 741476)
    off(_ZN11GUIPauseBoxC2Ev, 506172)
    off(_ZN14CPlayerManager19onPeerListDidChangeEv, 574828)
    off(_ZN13GUIBattleListD2Ev, 739148)
    off(_ZN10CLoadStateD2Ev, 530708)
    off(_ZN16TiXmlDeclaration13ToDeclarationEv, 832356)
    off(_ZN12CGameManager17GetCountryByIndexEi, 410124)
    off(_Z7GetPathPKcS0_, 340728)
    off(_ZN11GUICardList4InitERK7GUIRecti, 488436)
    off(_ZN12GUIAttackBoxC1Ev, 460920)
    off(_ZN11GUIHostItem8OnRenderEv, 689668)
    off(_ZN6CScene12RenderAdjoinEv, 593296)
    off(_ZN5CArmy8SaveArmyEP12SaveArmyInfo, 645444)
    off(_ZN9TiXmlBase7IsAlphaEh13TiXmlEncoding, 848484)
    off(_ZN10GUIWarning4InitERK7GUIRecti, 529708)
    off(_ZN14CPlayerManager24onReceivedDataFromPlayerEPKviPKc, 589212)
    off(_ZN6GUIEndC2Ev, 495260)
    off(_ZN10GUICardTab19GetCardTabButtonIdxEPK10GUIElement, 477384)
    off(_ZN12CGameManager10SaveBattleEPKc, 410616)
    off(_ZN12CGameManager4NextEv, 415928)
}

plt(_ZN11GUISaveItemC2Ev)

plt(_ZN7ecLayer9NextFrameEv)

plt(_ZN11GUIWarMedal8OnUpdateEf)

plt(_ZN7ecImageC2EP9ecTextureffff)

plt(_ZN7GUITechC1Ev)

plt(_ZN14GUICorpsButton4InitERK7GUIRectPKcb)

plt(_ZN6ecFile5CloseEv)

plt(_ZN10GUILoading4InitERK7GUIRect)

plt(_ZN12GUIScrollBarC2Ev)

plt(_ZN13CActionAssist4isAIEi)

plt(_ZN14GUICountryList8OnUpdateEf)

plt(_ZN6CScene9IsBombingEv)

plt(_ZN10CObjectDef16LoadUnitPositonsEv)

plt(_ZN5CArea10GetRealTaxEv)

plt(_ZN13TiXmlDocument10ToDocumentEv)

plt(_ZN15ecMultipleTouchC2Ev)

plt(_ZN14GUICountryList4InitERK7GUIRecti)

plt(_ZN10CCSoundBox15InitSoundSystemEv)

Thn(N14CPlayerManager12onStartMatchEv, 8)

plt(_ZN14GUIRadioButtonD0Ev)

plt(_ZN14GUICorpsButton13SetPlayerNameEPKcbS1_iib)

plt(_ZN13CStateManager6UpdateEf)

plt(_ZN13ecStringTableD1Ev)

plt(_ZN7GUITechD0Ev)

plt(_ZN12GUITutorails8OnUpdateEf)

plt(_ZN8CCountry8DoActionEv)

plt(_ZN16GUIUpgradeButtonD2Ev)

plt(_ZN8GUIImageD0Ev)

plt(_ZN11CBattleUnit6UpdateEf)

plt(_ZN12GUIScrollBarD1Ev)

plt(_ZN19GUIConnectHostStateD1Ev)

plt(_ZN14CPlayerManager9ReconnectEv)

plt(_ZN9CAreaMark7ReleaseEv)

plt(_ZN16ecParticleSystemD2Ev)

plt(_ZN14CPlayerManager16FindPlayerByUUIDEi)

plt(_ZN11GUIHostListD1Ev)

plt(_ZN14TiXmlAttribute8PreviousEv)

plt(_ZN9TiXmlBase14StringToBufferC2ERK11TiXmlString)

plt(_ZN15ecMultipleTouchD1Ev)

plt(_ZN14CPlayerManager12RemovePlayerEP7CPlayer)

plt(_Z16ecLaunchAppStorePKc)

plt(_ZN11CBattleUnitD2Ev)

plt(_ZN18ecSessionInterface11GetPeerNameEPKcRSs)

plt(_ZN14GUIBattleIntroD2Ev)

plt(_ZN6CScene15SetCameraToAreaEi)

plt(_ZN8GUIImageC1Ev)

plt(_ZN10CObjectDef14ReleaseArmyDefEv)

plt(_ZN14GUIExitWarningD1Ev)

plt(_ZN11GUIButtonExC1Ev)

plt(_ZN14CPlayerManager16PlayerLoadFinishEP7CPlayer)

plt(_ZN12GUISmallCardD2Ev)

plt(_ZN12TiXmlElementC2EPKc)

plt(_ZN13GUISelCountryC2Ev)

plt(_ZN7ecFrameC2Ev)

plt(_ZN14CPlayerManager20onPlayerInfoReceivedERSt4listIP12ecPlayerInfoSaIS2_EE)

plt(_ZN6ecFile18GetFileDataFromZipEPKcS1_Pm)

plt(_ZN12CGameManager24MovePlayerCountryToFrontEv)

plt(_ZN7ecLayerC1Ev)

plt(_ZN11TiXmlString7reserveEm)

plt(_ZN11GUIDefeated12ShowDefeatedEP8CCountry)

plt(_ZN12GUISmallCard4InitERK7GUIRect)

plt(_ZN9ecElement11GetPlayTimeEv)

plt(_ZN6CScene17SetSelAreaTargetsEP5CArea)

plt(_ZN11GUISaveItem7SetInfoEPKciiiiiiiib)

plt(_ZN16TiXmlDeclarationD2Ev)

plt(_ZN11GUICardListD0Ev)

plt(_ZN14GUICountryListD1Ev)

plt(_ZNK12TiXmlElement5PrintEP7__sFILEi)

plt(_ZN6CFightC1Ev)

plt(_ZN5CArmy4InitEP7ArmyDefP8CCountry)

plt(_ZN7ecLayerD0Ev)

plt(_ZN10ecGraphics4InitEiiiii)

plt(_ZN17TiXmlAttributeSetC1Ev)

plt(_ZN15GUIProductPriceC1Ev)

plt(_ZN14CPlayerManager15onPeerConnectedEPKc)

plt(_ZN10CCommander17SetNumBattleStarsEiii)

plt(_ZN6ecFileC1Ev)

plt(_ZN10GUIVictoryC2Ev)

plt(_ZN14CPlayerManager17SendStartLoadGameEv)

plt(_ZN12ecTextureResC1Ev)

plt(_ZN14GUICorpsButtonD2Ev)

plt(_ZN16ecParticleSystem6MoveToEffb)

plt(_ZN9GUIBattleD1Ev)

plt(_ZN8CCountry11SaveCountryEP15SaveCountryInfo)

plt(_ZN7CPlayer15ClearPacketListEv)

plt(_ZN7GUIGold4InitERK7GUIRect)

plt(_ZN9TiXmlNode14InsertEndChildERKS_)

plt(_ZN11GUIArmyItemD0Ev)

plt(_ZN12ecTextureResD2Ev)

plt(_ZN8CCountry15GetCardIndustryEP7CardDef)

plt(_ZN9CAreaMark4InitEi)

plt(_ZN5CArea18RevertArmyStrengthEi)

plt(_ZN10GUIVictoryD1Ev)

plt(_ZN12CGameManager15GetNumDialoguesEv)

plt(_ZN6CScene8BombAreaEii)

plt(_ZN9ecGameKit22DisconnectCurrentMatchEv)

plt(_ZN14GUICountryItem4InitEPKcS1_RK7GUIRect)

plt(_ZN18ecSessionInterface10SendPacketEPKviPKc)

plt(_ZNK9TiXmlNode6CopyToEPS_)

plt(_ZN8CGameRes18RenderUIDefendArmyEPKcffiiiiiiib)

plt(_ZN10GUIElement9FreeChildEPS_)

plt(_ZN11GUIHostList7OnEventERK5Event)

plt(_Z19ecTextureWithStringPKcS0_iiRiS1_Rj)

plt(_ZN10CBaseState8TouchEndEffi)

plt(_ZN13TiXmlDocumentD0Ev)

plt(_ZN9CActionAI15sortArmyToFrontEv)

plt(_ZN6CScene12UnselectAreaEv)

plt(_ZN12CGameManager7TurnEndEv)

plt(_ZN10CLoadState6RenderEv)

plt(_ZN10ecGraphics12RenderCircleEfffj)

plt(_ZN12CGameManager12IsLastBattleEv)

plt(_ZN9CActionAI13moveAndAttackEv)

plt(_ZN12CBattleScene10StarEffectEi)

plt(_ZN10GUIManager16UnloadTextureResEPKc)

plt(_ZN13CTouchInertia13GetStartPointEv)

plt(_ZN8CCountry12CollectTaxesEv)

plt(_ZN6CScene19GetNumAdjacentAreasEi)

plt(_ZN10GUIElement10GetAbsRectER7GUIRect)

plt(_ZN9TiXmlBase8ReadNameEPKcP11TiXmlString13TiXmlEncoding)

plt(_ZN14GUICountryList15ResetTouchStateEv)

plt(_ZN9GUIButton7SetTextEPKc)

plt(_ZN10GUINewGame8OnRenderEv)

plt(_ZN10GUIService8OnRenderEv)

plt(_ZN10ecGraphics11FreeTextureEP9ecTexture)

plt(_ZNK12TiXmlElement5CloneEv)

plt(_ZN10CGameStateD0Ev)

plt(_ZN16ecParticleSystem4InitEP13ecEmitterAttr)

plt(_ZN7GUICardC2Ev)

plt(_ZN10GUIBuyCard8OnRenderEv)

plt(_ZN11GUIHostItemC2Ev)

plt(_ZN11GUILevelSelD0Ev)

plt(_ZN10CObjectDef14GetUnitMotionsEPKcS1_)

plt(_ZN5CArmy9SetMoraleEi)

plt(_ZN11GUIHostList17ResetConnectStateEv)

Thn(N10CGameState7OnEventERK5Event, 16)

plt(_ZN11GUIHostList7AddHostEPKcS1_ii)

plt(_ZN14CPlayerManager12GetLeftCorpsEi)

plt(_ZN10ecGraphics8ShutdownEv)

plt(_ZN10CCSoundBox6LoadSEEPKc)

plt(_ZN16ecParticleSystem4StopEb)

plt(_ZN11GUILevelSelC1Ev)

plt(_ZN12CBattleScene9AddCraterEPKcfff)

plt(_ZN11GUIWarMedal8SetLevelEi)

plt(_ZNK9TiXmlNode10ToDocumentEv)

plt(_ZN11GUIPauseBox4InitERK7GUIRect)

plt(_ZN10CGameStateC1Ev)

plt(_ZN10CObjectDef17GetCardTargetTypeEP7CardDef)

plt(_ZN11GUIHostItemD1Ev)

plt(_ZN13GUIBattleList10GelSelItemEff)

plt(_ZN12CBattleScene12ClearEffectsEv)

plt(_ZN14CPlayerManager10ClearCorpsEv)

plt(_ZN12TiXmlCommentD0Ev)

plt(_Z16GetBattleKeyNameiiPc)

plt(_ZN8GUIMedal8SetMedalEi)

plt(_ZN9CSoundResD1Ev)

plt(_ZN10CCSoundBoxC1Ev)

plt(_ZN7GUITechD2Ev)

plt(_ZN9TiXmlNode17FirstChildElementEPKc)

plt(_ZN6CScene25AdjacentAreasEncirclementEi)

plt(_ZN11GUIHostListC2Ev)

plt(_ZN7CCamera21IsRectInVisibleRegionEffff)

Thn(N14CPlayerManager24onReceivedDataFromPlayerEPKviPKc, 8)

plt(_ZN11GUIDialogue4InitERK7GUIRect)

plt(_ZN18ecSessionInterface16AcceptInvitationEPKc)

plt(_ZN14GUICountryItem8OnRenderEv)

plt(_ZN10CGameState7OnEventERK5Event)

plt(_ZNK9TiXmlText6CopyToEPS_)

plt(_ZN14CPlayerManagerC2Ev)

plt(_ZdlPv)

plt(_ZN10GUIService4InitERK7GUIRect)

plt(_ZN9GUIResult4InitERK7GUIRecti)

plt(_ZN8CCountry19GetHighestValueAreaEv)

plt(_ZN13CFightTextMgr6UpdateEf)

plt(_ZN10CCommanderD2Ev)

plt(_ZN13TiXmlDocumentC2ERKS_)

plt(_ZN6CFight12SecondAttackEv)

plt(_ZN11GUIDialogueC2Ev)

plt(_ZN14GUICountryItemD0Ev)

plt(_ZN12GUISelBattleD2Ev)

plt(_ZN7ecShape8SetColorEj)

plt(_ZN11GUIPauseBoxC1Ev)

plt(_ZN9ecGameKitC1Ev)

plt(_ZN11GUIHostList15RefreshHostListEv)

plt(_ZN6CScene14ScreenToAreaIDEff)

plt(_ZN5CArea10RemoveArmyEP5CArmy)

plt(_ZN11ecLabelTextD1Ev)

plt(_ZN6ecText7SetTextEPKc)

plt(_ZN12TiXmlElement12SetAttributeEPKci)

plt(_ZN6ecFile12CheckJavaDexEv)

plt(_ZN5CArea11GetIndustryEv)

plt(_ZN11CBattleUnit11IsAttackingEv)

plt(_ZN11GUIWarMedal4InitERK7GUIRect11WARMEDAL_IDi)

plt(_ZN11GUIDialogueD1Ev)

plt(_ZN6CMedal5UpateEf)

plt(_ZN3MD59transformEPKh)

plt(_ZN10GUINewGameD2Ev)

plt(_ZN12TiXmlElementD0Ev)

plt(_ZN10CCSoundBox11ResumeMusicEv)

plt(_ZN11GUICardList8ReSelectEv)

plt(_ZN7GUIBank4InitERK7GUIRect)

plt(_Z18ecAppWillTerminatev)

plt(_ZN7GUIText7SetTextEPKc)

plt(_ZN3MD5C2Ev)

plt(_ZN15ecEffectManagerC1Ev)

plt(_ZN11CMatchStateD0Ev)

plt(_ZN6GUIEndD2Ev)

plt(_ZN14GUIBattleIntroD0Ev)

plt(_Znam)

plt(_ZN10CLoadState9TouchMoveEffi)

plt(_ZN10GUIOptionsD1Ev)

plt(_ZN11GUICardListD2Ev)

plt(_ZN13CTouchInertia8TouchEndEffi)

plt(_ZN11GUIMainMenuD0Ev)

plt(_ZN10GUIElement4ShowEv)

plt(_ZN11GUIHostList4InitERK7GUIRect)

plt(_ZN11GUIMainMenu4InitERK7GUIRect)

plt(_ZN12GUISmallCardD0Ev)

plt(_ZN12GUIAttackBox4InitERK7GUIRect)

plt(_ZN9ecUniFontC2Ev)

plt(_ZN13GUIMatchSetupD0Ev)

plt(_ZN7ecImage8SetColorEmi)

Thn(N14CPlayerManager34onLocalPlayerAuthenticationChangedEv, 8)

plt(_ZN10CObjectDef11LoadCardDefEv)

plt(_ZN12GUISelBattleD0Ev)

plt(_ZN18ecSessionInterfaceC1Ev)

plt(_ZN8CCountry9TurnBeginEv)

plt(_ZN12GUISelBattle4InitERK7GUIRectii)

plt(_ZN10CCommander15GetUpgradeMedalEv)

plt(_ZN12TiXmlElementC1ERKS_)

plt(_ZN13CActionAssistD2Ev)

plt(_ZN10GUIManager13SafeFreeChildEP10GUIElement)

plt(_ZN13ecStringTableC1Ev)

plt(_ZN9ecGameKit22SendPacketToAllPlayersEPKvi)

plt(_ZN12GUIScrollBar12GetScrollPosEv)

plt(_ZN10CObjectDef18ReleaseUnitMotionsEv)

plt(_ZN13GUISelCountry8OnRenderEv)

plt(_ZN11GUIMainMenuC1Ev)

plt(_ZN10CFightTextD2Ev)

plt(_ZN10CObjectDef4InitEv)

plt(_ZN9TiXmlNode9ToElementEv)

plt(_ZN9ecLibraryD2Ev)

plt(_ZN10GUISelArmy7SetAreaEi)

plt(_ZN6CScene8AirborneEi)

plt(_ZN18ecEffectResManager13LoadEffectResEPKc)

plt(_ZN10GUIBuyCard7OnEventERK5Event)

plt(_ZN8CCountry15CanUseCommanderEv)

plt(_ZN10GUISelArmy15MoveArmyToFrontEi)

plt(_ZN14CPlayerManager13WillTerminateEv)

plt(_ZN10GUIElement12FreeAllChildEv)

plt(_Z13ecBackPressedv)

plt(_ZN6GUITax8OnRenderEv)

plt(_ZN6CScene8IsAdjoinEii)

plt(_ZN13TiXmlDocumentC1ERKS_)

plt(_ZN9ecLibraryC1Ev)

plt(_ZN12CGameManager10InitBattleEv)

plt(_ZN12CBattleScene6UpdateEf)

plt(_ZN7CBomber4InitEv)

plt(_ZNK12TiXmlComment5CloneEv)

plt(_ZN13GUIAIProgress8OnRenderEv)

plt(_ZN8GUIMedalC1Ev)

plt(_ZN10GUIBuyCard15ResetCardTargetEv)

plt(_ZN10CFightTextC1Ev)

plt(_ZN5CArea7GetArmyEi)

plt(_ZN5CArea8IsActiveEv)

plt(_ZNK12TiXmlUnknown9StreamOutEP14TiXmlOutStream)

plt(_ZN13GUIActionInfo7SetInfoEPKc)

plt(_ZNK11TiXmlHandle12ChildElementEPKci)

plt(_ZN12CGameManager12RealLoadGameEPKc)

plt(_ZN16GUIUpgradeButton12SetNeedMedalEi)

plt(_ZN10CCSoundBoxD2Ev)

plt(_ZN12CGameManager16GetPlayerCountryEv)

plt(_ZN13GUIMatchSetupC2Ev)

plt(_ZN6ecText14GetStringWidthEib)

plt(_ZN5CArea15MoveArmyToFrontEib)

plt(_ZN11GUICardListC1Ev)

plt(_ZN6CScene7GetAreaEi)

plt(_ZN9TiXmlNode18NextSiblingElementEv)

plt(_ZN7CCamera4MoveEffb)

plt(_ZN10GUIElement4HideEv)

plt(_ZN3MD56updateEPKvm)

plt(_ZN12CGameManager8LoadGameEPKc)

plt(_ZN7CBomber19AircraftCarrierBombEii)

plt(_ZN10CGameState8InitGameEv)

plt(_ZN12GUIScrollBar4InitERK7GUIRectPKcS4_iiiii)

plt(_ZN8GUIMedal8OnRenderEv)

plt(_ZN10CCommander8BuyMedalEi)

plt(_ZN15ecMultipleTouch10TouchMovedEff)

plt(_ZN14CPlayerManager21FindPlayerByCountryIDEPKc)

plt(_ZN6GUITaxD2Ev)

plt(_ZN6ecText8SetAlphaEf)

plt(_ZN12TiXmlElementD2Ev)

plt(_ZN10GUIElement8AddChildEPS_b)

plt(_ZN11GUILevelSelD1Ev)

plt(_ZN11GUILevelSelC2Ev)

plt(_ZN12CBattleScene11IsAttackingEv)

plt(_ZNK14TiXmlAttribute16QueryDoubleValueEPd)

plt(_ZN12TiXmlUnknown9ToUnknownEv)

plt(_ZlsR14TiXmlOutStreamRK9TiXmlNode)

plt(_ZN12CBattleScene13SetBattleAreaEi)

plt(_ZN8CGameRes12RenderArmyHPEffii)

plt(_ZN6CScene13ScreenToSceneERfS0_)

plt(_ZN16ecParticleSystem4FireEv)

plt(_Z13HasUnitMotionPKci)

plt(_ZN7ecImage4InitEP9ecTextureffff)

plt(_ZN9TiXmlNode13ToDeclarationEv)

plt(_ZN8CCountryD2Ev)

plt(_ZN9GUIBattle4InitERK7GUIRect)

plt(_ZN10CGameState12UnselectAreaEv)

plt(_ZN11GUIButtonExD0Ev)

plt(_Z7InvSqrtf)

plt(_ZN13GUISelCountryD2Ev)

plt(_ZN7ecShapeD2Ev)

plt(_ZN16TiXmlDeclarationC2ERKS_)

plt(_ZN10GUINewGame17IsShowIabEventTipEv)

plt(_ZN13GUIBattleItem8OnUpdateEf)

plt(_ZN10GUIServiceD1Ev)

plt(_ZN10GUIWarningC1Ev)

plt(_ZN9hgeVector6RotateEf)

plt(_ZN7ecShape6RenderERK7ecMtx32)

plt(_ZN13GUIMatchSetupD2Ev)

plt(_ZN7ecImage14SetTextureRectEffff)

plt(_ZN9ecElement5ResetEv)

plt(_ZN13CTouchInertia4InitEv)

plt(_ZN11GUIWarMedalC1Ev)

plt(_ZN10GUILoadingC2Ev)

plt(_ZN10CObjectDef12GetBattleDefEPKc)

plt(_ZN6CScene9GainMedalEff)

plt(_ZN10ecGraphics11LoadTextureEPKc)

plt(_ZN10GUIWarningD0Ev)

plt(_ZN18ecEffectResManager8InstanceEv)

plt(_ZN11CMatchState11ShowWarningEi)

plt(_ZN12GUICommanderC1Ev)

plt(_ZN9TiXmlNode12ReplaceChildEPS_RKS_)

plt(_ZN14GUIRadioButtonC1Ev)

plt(_ZN6CScene4MoveEii)

plt(_ZN6GUIIapC1Ev)

Thn(N10CLogoStateD1Ev, 16)

plt(_ZN10ecGraphics14LoadPVRTextureEPKc)

plt(_ZN7GUIText8SetAlignEi)

plt(_ZN14CPlayerManager15GetNumLeftCorpsEv)

plt(_ZN12GUICommanderD0Ev)

plt(_ZN12TiXmlComment5ParseEPKcP16TiXmlParsingData13TiXmlEncoding)

plt(_ZN14TiXmlAttribute4NextEv)

plt(_ZN5CArmy12BreakthroughEv)

plt(_ZN10CMenuStateC2Ev)

plt(_ZN11GUIHostList14FindHostByUUIDEi)

plt(_ZN8ecEffect6RenderEv)

plt(_ZN8ecEffect4StopEb)

plt(_ZN11ecEffectRes10LoadEffectEPKcP12ecTextureRes)

plt(_ZN10CObjectDef17LoadGeneralPhotosEv)

plt(_ZN7ecLayerD2Ev)

plt(_ZN13CGameSettings12SaveSettingsEv)

plt(_ZN6CSceneC2Ev)

plt(_ZNK16TiXmlDeclaration5CloneEv)

plt(_ZN10CLogoStateD0Ev)

plt(_ZN11GUISaveItem4InitERK7GUIRectPKc)

plt(_ZN9ecLibraryD0Ev)

plt(_ZN6CScene13CheckMoveableEiii)

plt(_ZN6GUIIap8OnRenderEv)

plt(_ZNK12TiXmlElement6CopyToEPS_)

plt(_ZN14GUIRadioButtonD2Ev)

plt(_ZN11ecEffectResC1Ev)

plt(_ZN13GUIBattleList15ResetTouchStateEv)

plt(_ZN10CMenuStateD1Ev)

plt(_ZN6CSceneD1Ev)

plt(_ZN6CScene12LoadAreaDataEi)

plt(_ZN14CPlayerManager14SendRoundBeginEv)

plt(_ZN11GUIWarMedalD1Ev)

plt(_ZN11ecLabelText4InitEPKciiii)

plt(_ZN6CScene14LoadAreaEnableEPKc)

plt(_ZN11CBattleUnitC1Ev)

plt(_ZN12CBattleScene7ReleaseEv)

plt(_ZN14GUIBattleIntroC1Ev)

plt(_ZNK9TiXmlNode18NextSiblingElementEv)

plt(_ZN12TiXmlUnknownD1Ev)

plt(_ZN12ecTextureRes8GetImageEPKc)

plt(_ZN7GUIGold8SetMoneyEi)

plt(_ZN11GUIDialogue7ShowDlgEPKcS1_b)

plt(_ZN6CScene19AircraftCarrierBombEii)

plt(_ZN10CLoadState7OnEventERK5Event)

plt(_ZN10GUINewGame18OnCheckButtonClickEP14GUIRadioButton)

plt(_ZN16GUIMotionManagerC1Ev)

plt(_ZN10CCommanderC1Ev)

plt(_ZN10ecGraphics8InstanceEv)

plt(_ZN9GUIButton8OnRenderEv)

plt(_ZN11GUIPauseBoxD0Ev)

plt(_Z14GetArmyAbilityi)

plt(_Z18ecSetInAppPurchasePFviE)

plt(_ZNK16TiXmlDeclaration6CopyToEPS_)

plt(_ZN8CCountry12FinishActionEv)

plt(_ZN13CStateManagerC1Ev)

plt(_ZN15ecMultipleTouch10TouchEndedEff)

plt(_ZN10CBaseState7KeyDownEi)

plt(_ZN9TiXmlBase10IsAlphaNumEh13TiXmlEncoding)

plt(_ZNK14TiXmlAttribute8IntValueEv)

plt(_ZN13TiXmlDocumentC1EPKc)

plt(_ZN7CPlayerD1Ev)

plt(_ZN5CArea8SaveAeraEP12SaveAreaInfo)

plt(_ZN10ecGraphics4FadeEf)

plt(_ZN9TiXmlNodeD1Ev)

plt(_ZN5CArea10RenderArmyEffiP5CArmy)

plt(_ZN9TiXmlBase9PutStringERK11TiXmlStringP14TiXmlOutStream)

plt(_ZN17TiXmlAttributeSet6RemoveEP14TiXmlAttribute)

plt(_ZN7ecImageC1EP9ecTextureffff)

plt(_Z16GetEditorResPathPKc)

plt(_ZN13GUIBattleList18SelectLastUnlockedEv)

plt(_ZN9CActionAID2Ev)

plt(_ZN9TiXmlBase14StringToBufferD2Ev)

plt(_ZN11GUIHostListD0Ev)

plt(_ZN12GUICommander16SetCommanderInfoEv)

plt(_ZN6CScene12CalSceneRectERfS0_S0_S0_)

plt(_ZN13CActionAssist19purChaseSpecialCardEv)

plt(_ZN8CCountry12GetIndustrysEv)

plt(_ZN6ecFileD1Ev)

plt(_ZN9TiXmlTextD2Ev)

plt(_ZN13GUIBattleItem8OnRenderEv)

plt(_ZN18ecEffectResManager16ReleaseEffectResEPKc)

plt(_ZN5CArmy9TurnBeginEv)

plt(_ZplRK11TiXmlStringPKc)

plt(_ZN7ecLayer4PlayEv)

plt(_ZN12CGameManager26SetConquestPlayerCountryIDEPKc)

plt(_ZN13CStateManagerD2Ev)

plt(_ZN14GUICountryList10GelSelItemEff)

plt(_ZN8CCountry7TurnEndEv)

plt(_ZN6CScene11ResetTargetEv)

plt(_ZN9GUIBattle11BattleStartEiii)

plt(_ZN14GUICountryList11ResetSelectEv)

plt(_ZN12CBattleSceneD2Ev)

plt(_ZNK16TiXmlDeclaration9StreamOutEP14TiXmlOutStream)

plt(_ZN10CCommander12CheckUpgardeEv)

plt(_ZN6CScene6MoveToEii)

plt(_ZN6CScene10SaveAdjoinEi)

plt(_ZN10GUIManager14LoadTextureResEPKcb)

plt(_ZN7ecImageC1EP9ecTextureRK13ecTextureRect)

plt(_ZN14GUICountryItem8OnUpdateEf)

plt(_ZN6CScene7ReleaseEv)

plt(_ZN19GUIConnectHostStateC2Ev)

plt(_ZN9CAreaMarkD1Ev)

plt(_ZN5CArea15AddArmyStrengthEii)

plt(_ZN9TiXmlNode9ToCommentEv)

plt(_ZN11GUIMainMenu7OnEventERK5Event)

plt(_ZN9GUIButton12SetTextImageEPKc)

plt(_ZN12CGameManager11FindCountryEPKc)

plt(_ZN7GUIGoldC1Ev)

plt(_ZNK14TiXmlAttribute5PrintEP7__sFILEi)

plt(_ZN10GUILoadingD1Ev)

plt(_ZN11GUIMainMenu12IsShowNewTipEv)

plt(_Z13GetAIRandSeedv)

plt(_ZN11ecLabelText8SetColorEj)

plt(_ZN8GUIImage8OnRenderEv)

plt(_ZN10CObjectDef20ReleaseUnitPositionsEv)

plt(_ZN13GUIAIProgressC2Ev)

plt(_ZN10CCommander20SetNumPlayedBatttlesEii)

plt(_ZN12GUICorpsInfoD2Ev)

plt(_ZN9TiXmlNode10ToDocumentEv)

plt(_ZN7CPlayerC1Ev)

plt(_ZN8CCountry16SetWarMedalLevelE11WARMEDAL_IDi)

plt(_ZN10GUIBuyCard7SelCardEii)

plt(_ZN9TiXmlNode11GetDocumentEv)

plt(_ZN5CArmy7TurnEndEv)

plt(_ZN5CArea16AllArmyPoisoningEv)

plt(_ZN14CPlayerManager18onPeerDisconnectedEPKc)

plt(_ZN13CFightTextMgrD2Ev)

plt(_ZN14CPlayerManager15AnalyzePeerNameERKSsRSsRiS3_)

plt(_ZN18ecSessionInterface7ReleaseEv)

plt(_ZN10CEditState11ReleaseGameEv)

plt(_ZN7GUISaveC2Ev)

plt(_ZN14GUIExitWarningD2Ev)

plt(_ZN13GUIAdornMedalD1Ev)

plt(_ZN6GUIIap14OnListCompleteEPv)

plt(_ZN7ecFrame4InitEP11ecFrameDataP9ecElementP9ecLibrary)

Thn(N10CLoadState7OnEventERK5Event, 16)

plt(_ZN10GUIManager6RenderEv)

plt(_ZNK13TiXmlDocument9StreamOutEP14TiXmlOutStream)

plt(_ZN6CScene13RenderAreasIDEv)

plt(_ZN12GUICorpsInfo8OnRenderEv)

plt(_ZN12CGameManager21GetLocalPlayerCountryEv)

plt(_ZN6GUITax11SetIndustryEi)

plt(_ZN7ecImageD1Ev)

plt(_ZN5CArea6UpdateEf)

plt(_ZN10CCommander10IsMaxLevelEv)

plt(_ZN10CMenuState8TouchEndEffi)

plt(_ZN13GUIMatchSetup4InitERK7GUIRect)

plt(_ZN10GUIServiceD0Ev)

plt(_ZN5CArea10OccupyAreaEPS_)

plt(_Z18GetConquestKeyNameiPc)

plt(_ZN7ecImageD2Ev)

plt(_ZN7GUIGoldD0Ev)

plt(_ZN13CGameSettingsC2Ev)

plt(_ZN13GUIAdornMedalC2Ev)

plt(_ZN13TiXmlDocumentaSERKS_)

plt(_ZN5CArea11HasArmyCardEii)

plt(_ZN10GUIBuyCardD0Ev)

plt(_ZN7CCameraC1Ev)

plt(_ZN10CGameStateD2Ev)

plt(_ZN12ecTextureResC2Ev)

plt(_ZN10CObjectDef16LoadConquestListEv)

plt(_ZN7ecLayer10ChangeItemEP10ecItemDataS1_P9ecLibrary)

plt(_ZN6ecFileC2Ev)

plt(_ZN7GUICardD0Ev)

plt(_ZN7ecLayer4StopEv)

plt(_ZN11CMatchStateD1Ev)

plt(_ZN9ecLibrary12GetLayerDataEi)

plt(_ZN5CArmy6AddExpEi)

plt(_ZN10GUIVictory8OnRenderEv)

plt(_ZN9ecGameKitD1Ev)

plt(_ZN11GUIArmyItemD1Ev)

plt(_ZN12TiXmlElement18SetDoubleAttributeEPKcd)

plt(_ZN11GUIDefeatedD1Ev)

plt(_ZN5CArea11AddArmyCardEii)

plt(_ZN11GUIDefeated12HideDefeatedEv)

plt(_ZN9ecGameKit7ReleaseEv)

plt(_ZN9ecUniFont12GetCharImageEt)

plt(_ZN17TiXmlAttributeSetC2Ev)

plt(_ZN11GUICardList10GelSelItemEff)

plt(_ZN7CBomberC1Ev)

plt(_ZN11CBackgroundD1Ev)

plt(_ZN11GUIPauseBoxD2Ev)

plt(_ZN8ecEffect4InitEPKcP9TFreeListI16ecParticleSystemE)

plt(_ZN14GUIExitWarningC1Ev)

plt(_ZNK13TiXmlDocument8SaveFileEv)

plt(_ZN14CPlayerManager6UpdateEf)

plt(_ZN7GUIText8OnRenderEv)

plt(_ZN14CPlayerManager18SendPacketToPlayerE9PACKET_IDPKviP7CPlayer)

plt(_ZN6CScene20AreaDisableOutofRectEiiii)

plt(_ZN15ecEffectManager9AddEffectEPKcb)

plt(_ZN12GUICorpsInfoC2Ev)

plt(_ZN7GUIBankD2Ev)

plt(_ZN8GUIImage8SetAlphaEf)

plt(_ZN14CPlayerManager17DidRecvInvitationEPKc)

plt(_ZN3MD5C1EPKvm)

plt(_ZN10GUIElement11CheckInRectEff)

plt(_ZN16GUILockedWarning4InitERK7GUIRect)

plt(_ZN7CBomberD2Ev)

plt(_ZNK11TiXmlHandle10FirstChildEv)

plt(_ZN9GUIButton7SetTextEPKt)

plt(_ZN10CObjectDef7ReleaseEv)

plt(_ZN16GUILockedWarningC2Ev)

plt(_ZN10CLoadStateC2Ev)

plt(_ZN11GUIWarMedal13SetArrowColorEj)

plt(_ZN10GUIElement10SetVisibleEb)

plt(_Z17ecGetProductPricei)

plt(_ZN12GUIScrollBar12SetScrollPosEi)

plt(_Z24GetBattleBelligerentListPKcRSt4listI11BelligerentSaIS2_EEb)

plt(_ZN10CBaseState7OnEnterEv)

plt(_ZN10CMenuState18StartMultiplayGameEi)

plt(_ZN5CArmyD2Ev)

plt(_ZNK9TiXmlNode11GetDocumentEv)

plt(_ZN8GUIBegin4InitERK7GUIRect)

plt(_ZN6ecText8SetColorEj)

plt(_ZN10CGameState14HideAIProgressEv)

plt(_ZN8CCountry11LoadCountryEPK15SaveCountryInfo)

plt(_ZN9CActionAI18setActionNodeClearEv)

plt(_ZNK13TiXmlDocument8SaveFileEPKc)

plt(_ZN11GUISaveItem8OnRenderEv)

plt(_ZN10CMenuState7OnEventERK5Event)

plt(_ZN11GUIHostList8OnRenderEv)

plt(_ZN14CPlayerManager12onMatchFoundEv)

plt(_ZN13GUIMatchSetup7OnEventERK5Event)

plt(_ZN13TiXmlDocumentD1Ev)

plt(_ZN10CGameState11ScrollWheelEfff)

plt(_ZN5CArea9ConstructEi)

plt(_ZN6ecFile11IsFlieExistEPKc)

plt(_ZN8CCountry13IsLocalPlayerEv)

plt(_ZN9CSoundRes10PlayCharSEE10SND_EFFECT)

plt(_ZN8CGameRes15RenderArmyLevelEffi)

plt(_ZN10CMenuState11ShowWarningEi)

plt(_ZNK12TiXmlElement9AttributeEPKc)

plt(_ZN13CFightTextMgr7ReleaseEv)

plt(_ZN13GUIAdornMedal7RefreshEv)

plt(_ZN10CObjectDef14GetConquestDefEPKc)

plt(_Z16ecETCTextureLoadPKcRiS1_Rj)

plt(_ZN10GUIElement9SetEnableEb)

plt(_ZN12CBattleScene10CreateFortEv)

plt(_ZN10CGameState12ShowDialogueEPKcS1_b)

plt(_ZN13TiXmlDocumentC2Ev)

plt(_ZN7GUITechC2Ev)

plt(_ZN5CArmy8LoadArmyEPK12SaveArmyInfo)

plt(_ZN14CPlayerManager14DestroySessionEv)

plt(_ZN11GUIDefeated7OnEventERK5Event)

plt(_ZN9TiXmlBase18ConvertUTF32ToUTF8EmPcPi)

plt(_ZN12CBattleSceneC1Ev)

plt(_ZN6GUITax4InitERK7GUIRect)

plt(_ZN3MD56digestEv)

plt(_ZN9GUIResultD0Ev)

plt(_ZN10GUINewGame15GetPromotionUrlEv)

plt(_ZN6GUITax8SetMoneyEi)

plt(_ZN8ecEffect6MoveToEffb)

plt(_ZN10GUIBuyCard4InitERK7GUIRect)

plt(_ZN8CCountry7UseCardEP7CardDefii)

plt(_ZNK14TiXmlAttribute11DoubleValueEv)

plt(_ZN13CFightTextMgrC2Ev)

plt(_ZN13CStateManager8TouchEndEffi)

plt(_ZN9GUIBattle7OnEventERK5Event)

plt(_ZN5CArea9DraftArmyEi)

plt(_ZN12GUIAttackBoxD1Ev)

plt(_ZN10CEditState6RenderEv)

plt(_ZN9GUIBattle12BattleFinishEv)

plt(_ZN8CCountry17GenCardTargetListE7CARD_ID)

plt(_ZN7GUITechD1Ev)

plt(_ZN19GUIConnectHostStateD0Ev)

plt(_ZN14CPlayerManager10FindPlayerEPKc)

plt(_ZN10CLogoState7OnEnterEv)

plt(_ZN5CArea10GetArmyIdxEP5CArmy)

plt(_ZN10CFightText8SetColorEj)

Thn(N11CMatchState7OnEventERK5Event, 16)

plt(_ZN12CGameManager17CheckAndSetResultEv)

plt(_ZN9TiXmlBase9PutStringERK11TiXmlStringPS0_)

plt(_ZN13CTouchInertiaC1Ev)

plt(_ZN10CCommander20GetNumPlayedBatttlesEi)

plt(_ZN10GUICardTabC2Ev)

plt(_ZN13CActionAssist10searchNodeEii)

plt(_ZN13TiXmlDocument8SetErrorEiPKcP16TiXmlParsingData13TiXmlEncoding)

plt(_Z18ecSetShowReviewFucPFvvE)

plt(_ZN10ecGraphics15LoadWEBPTextureEPKc)

plt(_ZN7GUIBank8OnRenderEv)

plt(_ZN12GUITutorails10LoadScriptEv)

plt(_ZN12GUITutorailsD0Ev)

plt(_ZN8GUIBeginD2Ev)

plt(_ZN11GUICardListD1Ev)

plt(_ZN9CActionAI8getMaxIdEv)

plt(_ZN14GUIExitWarningD0Ev)

plt(_ZN9GUIButton12SetTextAlignEi)

plt(_ZN13GUIAIProgressD0Ev)

plt(_ZN15ecMultipleTouchD2Ev)

plt(_ZNK12TiXmlUnknown5PrintEP7__sFILEi)

plt(_ZN10GUICardTabD1Ev)

plt(_ZN10CObjectDefD1Ev)

plt(_ZN11ecLabelTextC1Ev)

plt(_ZN5CArmy12LostStrengthEi)

plt(_ZN13CStateManager11BackPressedEv)

plt(_ZN11GUICardList7GetCardEi)

plt(_ZN18ecEffectResManager14LoadTextureResEPKc)

plt(_ZN7ecFrameD1Ev)

Thn(N11CMatchStateD1Ev, 16)

plt(_ZN7GUIBankD0Ev)

plt(_ZN7ecImage6RenderEffff)

plt(_ZN9ecGameKitC2Ev)

plt(_ZN7ecImage14SetTextureRectERK13ecTextureRect)

plt(_ZN16ecParticleSystem6IsLiveEv)

plt(_ZN6ecTextC1Ev)

plt(_ZNK9TiXmlText5PrintEP7__sFILEi)

plt(_ZN15ecEffectManagerC2Ev)

plt(_ZN13GUIAIProgressD2Ev)

plt(_ZN8GUIImage4InitEPKcRK7GUIRect)

plt(_ZN7CCamera14IsRectInCameraEffff)

plt(_ZN11ecLabelTextD2Ev)

plt(_ZN10CMenuState7OnEnterEv)

plt(_ZN10GUIElement11CheckInRectEffRK7GUIRect)

plt(_ZN12TiXmlElement12SetAttributeEPKcS1_)

plt(_ZN10CLogoStateC2Ev)

plt(_ZN6CScene8IsMovingEv)

plt(_ZN9GUIBattleD0Ev)

plt(_ZN7GUIBankC1Ev)

plt(_ZN10ecGraphics5FlushEv)

plt(_ZN12GUITutorails7ShowDlgEPKc)

plt(_ZN6GUITaxD1Ev)

Thn(N10CLoadStateD0Ev, 16)

plt(_ZN6GUIIapC2Ev)

plt(_ZN5CArea16GetIndustryLevelEv)

plt(_ZN3MD56decodeEPKhPmm)

plt(_ZN7GUITextC2Ev)

plt(_ZN12CBattleSceneC2Ev)

plt(_ZN11GUIDialogue7HideDlgEv)

plt(_ZN8GUIMedal8OnUpdateEf)

plt(_ZN6CFight12GetAttackAddEi)

plt(_ZN11GUIHostItemC1Ev)

plt(_ZN12GUITutorails7OnEventERK5Event)

plt(_ZN6CScene11CreateArrowEii)

plt(_ZN12CGameManager10NextBattleEv)

plt(_ZN10GUIVictoryD2Ev)

plt(_ZN12GUIAttackBox7OnEventERK5Event)

plt(_ZN12GUICorpsInfo13SetPlayerNameEPKcbS1_iib)

plt(_ZN11GUIMainMenu8OnRenderEv)

plt(_ZN12GUITutorails7ShowDlgEi)

plt(_ZN10GUIBuyCard10GetSelCardEv)

plt(_ZN10GUIWarningD2Ev)

plt(_ZN7ecLayer7SetLoopEi)

plt(_ZN13GUIAdornMedal8OnRenderEv)

plt(_ZN11GUIHostItemD0Ev)

plt(_ZN8ecEffect6FireAtEfff)

plt(_ZN10GUIBuyCard13CanBuySelCardEv)

plt(_ZN11GUIHostList8FindHostEPKc)

plt(_ZN14CPlayerManager12SetupSessionEb)

plt(_ZNK9TiXmlText5CloneEv)

plt(_ZN14CPlayerManagerC1Ev)

plt(_ZN13GUISelCountry13LoadImageListEi)

plt(_ZN9CActionAI12getAiPercentEi)

plt(_ZN12GUICommanderC2Ev)

plt(_ZN7CBomber8AirborneEi)

plt(_ZN13GUISelCountryD1Ev)

plt(_ZN8CCountry12SetCommanderEPKc)

plt(_ZN12CBattleScene12DestroyUnitsEi)

plt(_ZN10CEditStateD2Ev)

plt(_ZN9GUIButtonC1Ev)

plt(_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz)

plt(_ZN11GUISaveItemD0Ev)

plt(_ZN18ecEffectResManager17ReleaseTextureResEv)

plt(_ZN13CGameSettings12LoadSettingsEv)

plt(_ZN10GUIVictory4InitERK7GUIRectb)

plt(_ZN14CPlayerManager13GetRightCorpsEi)

plt(_ZN14CPlayerManagerD2Ev)

plt(_ZNK13TiXmlDocument10ToDocumentEv)

plt(_ZN9TiXmlText6ToTextEv)

plt(_ZN12GUICommanderD1Ev)

plt(_ZN16GUIMotionManager9AddMotionEP10GUIElementffft)

plt(_ZN7GUICardD2Ev)

plt(_ZN12GUICommander13SelectedMedalEi)

plt(_ZN11ecEffectRes7ReleaseEv)

plt(_ZN6GUIEndD1Ev)

plt(_ZN11CMatchState6UpdateEf)

plt(_ZN14GUICountryItem7OnEventERK5Event)

plt(_ZN10GUILoadingD0Ev)

plt(_ZN9TiXmlNode15IterateChildrenEPS_)

plt(_ZN10CObjectDef19ReleaseCommanderDefEv)

plt(_ZN5CArea12GetCityLevelEv)

Thn(N10CEditStateD1Ev, 16)

plt(_ZN8CCountry12GetCardPriceEP7CardDef)

plt(_ZN10CCommanderC2Ev)

plt(_ZN9GUIButton13SetBackgroundEPKc)

plt(_ZN10GUIManager6FadeInEi)

plt(_ZN14CPlayerManager12ClearPlayersEv)

plt(_ZN10CObjectDefC1Ev)

plt(_ZNK12TiXmlElement9AttributeEPKcPi)

plt(_ZN7GUISave7OnEventERK5Event)

plt(_ZN7GUICardC1Ev)

plt(_ZN10CBaseState15EnterForegroundEv)

plt(_ZN6GUIIapD2Ev)

plt(_ZN8CheckMD5C2Ev)

plt(_ZN12CGameManager9RetryGameEv)

plt(_ZN7CCamera5UpateEf)

plt(_ZN9TiXmlNode17InsertBeforeChildEPS_RKS_)

plt(_ZN17GUICommanderMedalC2Ev)

plt(_ZN5CArmy25GetNumDicesIfLostStrengthEi)

plt(_ZNK9TiXmlNode10FirstChildEPKc)

plt(_ZN6CScene10LoadAdjoinEi)

plt(_ZN13GUIBattleItem7OnEventERK5Event)

plt(_ZN13CActionAssist13calcDraftTypeEbiP8CCountry)

plt(_ZN17TiXmlAttributeSet4FindERK11TiXmlString)

plt(_ZN17GUICommanderMedalD1Ev)

plt(_ZN14GUIBattleIntroD1Ev)

plt(_ZN9TiXmlNodeC2ENS_8NodeTypeE)

plt(_ZN13GUIBattleItemC2Ev)

plt(_ZN12GUIAttackBox8OnRenderEv)

plt(_ZN12GUIScrollBarC1Ev)

plt(_ZN6CScene16RenderAreasPointEv)

plt(_ZN13GUIBattleListC2Ev)

plt(_ZN13TiXmlDocument5ParseEPKcP16TiXmlParsingData13TiXmlEncoding)

plt(_ZN13TiXmlDocumentC2EPKc)

plt(_ZN15GUIProductPrice14SetLocalePirceEPKc)

plt(_ZN12GUITutorailsC2Ev)

plt(_ZN9ecGameKit18GetMatchPlayerListERSt4listISsSaISsEE)

plt(_ZN5CArea12ClearAllArmyEv)

plt(_ZN15ecEffectManager6UpdateEf)

plt(_ZN10GUIWarning8OnRenderEv)

plt(_ZN8CCountry12CommanderDieEv)

plt(_ZN8GUIImageD2Ev)

plt(_ZN14GUICountryItemD1Ev)

plt(_ZN5CArea11UpgradeArmyEi)

plt(_ZN6ecTextD1Ev)

plt(_ZN12GUITutorailsD2Ev)

plt(_ZN12GUISelBattle8OnUpdateEf)

Thn(N14CPlayerManager20onFriendListReceivedEv, 8)

plt(_ZN10CObjectDef10GetCardDefE7CARD_ID)

plt(_ZN12TiXmlCommentD2Ev)

plt(_ZN9TiXmlNode8IdentifyEPKc13TiXmlEncoding)

plt(_ZN12CGameManager13GetSaveHeaderEPKcR10SaveHeader)

plt(_ZN3MD56updateERKSs)

plt(_ZN12GUICorpsInfo4InitERK7GUIRect)

plt(_ZN10CLoadState6OnExitEv)

plt(_ZN6GUIIap15SetProductPriceEv)

plt(_ZN11GUIButtonExD2Ev)

plt(_ZN10GUIManagerC1Ev)

plt(_ZN8GUIBegin8OnRenderEv)

plt(_ZN13CTouchInertia9TouchMoveEffi)

plt(_ZN11CMatchState7OnEnterEv)

plt(_ZN12ecTextureRes9UnloadResEPKc)

plt(_Z17ecSetProductPriceiPKc)

plt(_ZN10CGameStateD1Ev)

plt(_ZN7ecImage4InitEP11ecImageAttr)

plt(_ZN10CCSoundBox11SetSEVolumeEi)

plt(_ZN12CGameManagerD1Ev)

plt(_ZN3MD56updateEPKhm)

plt(_ZN6CScene11SaveAreaTaxEi)

plt(_ZNK13TiXmlDocument5CloneEv)

plt(_ZN10CGameState12StartBattaleEiiib)

plt(_ZN10ecGraphicsC2Ev)

plt(_ZN8CCountry18GetMinDstToAirportEi)

plt(_ZN6CScene14RenderAreasTaxEv)

plt(_ZN10GUIManagerD0Ev)

plt(_ZN13GUIActionInfo8OnRenderEv)

plt(_ZN11GUIMainMenuD2Ev)

plt(_ZN7GUIBank8OnUpdateEf)

plt(_ZN10CCSoundBox7DestroyEv)

plt(_ZN12CBattleScene11ReleaseFortEv)

plt(_ZN10CLoadState10TouchBeginEffi)

plt(_ZNK12TiXmlComment9ToCommentEv)

plt(_ZN13GUIActionInfo8OnUpdateEf)

plt(_Z14ecLoadSettingsv)

plt(_ZN12TiXmlUnknownD0Ev)

plt(_ZNK13TiXmlDocument6CopyToEPS_)

plt(_ZN10GUIManager4InitERK7GUIRect)

plt(_ZN3MD5C2ERSt14basic_ifstreamIcSt11char_traitsIcEE)

plt(_ZN7GUISaveC1Ev)

plt(_ZN10CGameStateC2Ev)

plt(_ZN6CMedal6RenderEv)

plt(_ZN5CArea10SetArmyDirEif)

plt(_ZN8CCountry14NextCardTargetEv)

plt(_ZN14TiXmlAttributeD0Ev)

plt(_ZN10CCSoundBox11UnloadMusicEv)

plt(_ZN8CGameRes12GetFlagImageEPKc)

plt(_ZN10ecGraphics12SetViewPointEfff)

plt(_ZN12CGameManager13BattleVictoryEv)

plt(_ZN11CMatchState7OnEventERK5Event)

plt(_ZN5CArea14RenderBuildingEv)

plt(_ZN8ecEffectC2Ev)

plt(_ZN9ecLibraryD1Ev)

plt(_ZN10CGameState12ShowDefeatedEP8CCountry)

plt(_ZN3MD55finalEv)

plt(_ZN8GUIBegin7OnEventERK5Event)

plt(_ZN5CArea23ReduceConstructionLevelEv)

plt(_ZN6CScene22MoveCameraCenterToAreaEi)

plt(_ZN13CActionAssist11getAllianceEiii)

plt(_ZN7GUICard8OnRenderEv)

plt(_ZN10GUINewGameD0Ev)

plt(_ZN5CArea4InitEiRK8AreaInfo)

plt(_ZN15ecEffectManagerD2Ev)

plt(_ZN10ecGraphics11RenderBeginEv)

plt(_ZN11ecEffectResD1Ev)

plt(_ZN8GUIMedal7OnEventERK5Event)

plt(_ZN10CObjectDef14LoadBattleListEv)

plt(_ZN7GUIGold11SetIndustryEi)

plt(_ZN9GUIButton4InitEPKcS1_RK7GUIRectP9ecUniFont)

plt(_ZN10GUINewGameC1Ev)

plt(_ZN6CFight17GetAttackerResultEi)

plt(_ZN9TiXmlNode18NextSiblingElementEPKc)

plt(_ZN15GUIProductPrice4InitERK7GUIRect)

plt(_ZN6GUIIap4InitERK7GUIRect)

plt(_ZNK13TiXmlDocument8SaveFileEP7__sFILE)

plt(_ZN7GUISaveD2Ev)

plt(_ZN6CScene10MakeAdjoinEii)

plt(_ZN18ecSessionInterface17DeclineInvitationEPKc)

plt(_ZN14CPlayerManager13GetNumActionsEv)

plt(_Z9ecKeyDowni)

plt(_ZN16GUILockedWarning7OnEventERK5Event)

plt(_ZN11GUIWarMedalC2Ev)

plt(_ZN14GUICountryList15GetSelCountryIDEv)

plt(_ZNK12TiXmlUnknown6CopyToEPS_)

plt(_Z15GetDocumentPathPKc)

plt(_ZN12GUIScrollBarD0Ev)

plt(_ZN6CScene14RenderSeaAreasEv)

plt(_ZN13GUIMatchSetupD1Ev)

plt(_ZN16TiXmlDeclarationC2EPKcS1_S1_)

plt(_ZN13CStateManager13RegisterStateEP10CBaseState)

plt(_ZN11GUIDefeatedC1Ev)

plt(_ZN10GUISelArmyD1Ev)

plt(_ZN10GUIOptions7OnEventERK5Event)

plt(_ZN9TiXmlBase9GetEntityEPKcPcPi13TiXmlEncoding)

plt(_ZN10CObjectDefC2Ev)

plt(_ZN7CCamera5ApplyEv)

plt(_ZN10CLogoState7OnEventERK5Event)

plt(_ZN16TiXmlDeclarationD0Ev)

plt(_ZN10CGameState15EnableIdleTimerEf)

plt(_ZN10CMenuState10TouchBeginEffi)

plt(_ZN16GUILockedWarning8OnRenderEv)

plt(_ZN3MD55resetEv)

plt(_ZN12TiXmlElementaSERKS_)

plt(_ZN10GUISelArmyC2Ev)

plt(_ZN9GUIButton7OnEventERK5Event)

plt(_ZN13CActionAssist11getNeighborEiiic)

plt(_ZN8GUIMedalD1Ev)

plt(_ZN7CPlayer10PushPacketE9PACKET_IDPKvi)

plt(_ZN10ecGraphics10RenderLineEPK6ecLine)

plt(_ZN10CEditState7OnEventERK5Event)

plt(_ZN7ecImage7SetFlipEbbb)

plt(_ZN7ecShape4InitEP9ecTextureffff)

plt(_ZNK12TiXmlComment6CopyToEPS_)

plt(_ZN10CMenuState8ShowExitEv)

plt(_ZN13CStateManager8InstanceEv)

plt(_ZN6CScene10SelectAreaEP5CArea)

plt(_ZN9CActionAI14getNumArmyMoveEii)

plt(_ZN3MD5C2ERKSs)

plt(_ZN11CMatchState6OnExitEv)

plt(_ZN12CGameManagerC2Ev)

plt(_ZN10CCommander15UpgradeWarMedalE11WARMEDAL_ID)

plt(_ZN9ecElementD1Ev)

plt(_ZN11CBattleUnit6AttackEv)

plt(_ZN9GUIResult7OnEventERK5Event)

plt(_ZN13GUIMatchSetup8OnRenderEv)

plt(_ZN9ecElement4InitEP13ecElementDataP9ecLibrary)

plt(_ZN10CMenuStateD0Ev)

plt(_ZN6CFight11ApplyResultEv)

plt(_ZN15GUIProductPriceD1Ev)

plt(_ZN13CTouchInertiaD2Ev)

plt(_ZN11GUIDefeatedD2Ev)

plt(_Z11ecTouchMoveffi)

plt(_ZN11CMatchState18StartMultiplayGameEi)

plt(_ZN14TiXmlAttribute14SetDoubleValueEd)

plt(_ZN5CArmy9PoisoningEv)

plt(_ZN12GUITutorails6ExeCmdEi)

plt(_ZN9GUIBattle8OnUpdateEf)

plt(_ZN6GUIEnd8OnRenderEv)

plt(_ZN8CCountry16GetWarMedalLevelE11WARMEDAL_ID)

plt(_ZN9ecElementC2Ev)

plt(_ZN10CMenuStateC1Ev)

plt(_ZN12GUISmallCard8OnRenderEv)

plt(_ZN16GUIUpgradeButtonD0Ev)

Thn(N10CLogoStateD0Ev, 16)

plt(_ZN13TiXmlDocument8LoadFileEP7__sFILE13TiXmlEncoding)

plt(_ZN14GUICountryListC2Ev)

plt(_ZN14CPlayerManager14WillDisconnectEv)

plt(_ZN16GUIUpgradeButtonC1Ev)

plt(_ZN10CEditState7OnEnterEv)

plt(_ZNK9TiXmlNode9ToUnknownEv)

plt(_ZN6CScene21MoveCameraBetweenAreaEii)

plt(_ZN11GUIWarMedal8OnRenderEv)

plt(_ZN12ecTextureRes13CreateTextureEPKcbbb)

plt(_ZN6CScene13InitAreaImageEi)

plt(_ZN3MD58toStringEv)

plt(_ZN10ecGraphics11BindTextureEP9ecTexture)

plt(_ZN7GUISave8OnRenderEv)

plt(_ZN6GUITax7SetAreaEi)

plt(_ZN11GUIButtonExC2Ev)

plt(_ZN8CCountry13GetNumAirportEv)

plt(_ZN10CBaseState10TouchBeginEffi)

plt(_ZN10CObjectDef20ReleaseGeneralPhotosEv)

plt(_Z16ecPVRTextureLoadPKcRiS1_Rj)

plt(_ZN8CCountry16CollectIndustrysEv)

plt(_ZN10GUINewGame14GetIabEventUrlEv)

plt(_ZN11CBattleUnitD1Ev)

plt(_ZN14CPlayerManager16onAcceptedInviteEv)

plt(_ZN6CScene10ClearAreasEv)

plt(_ZN12GUISmallCard7SetCardEP7CardDef)

plt(_ZN10GUISelArmy8OnRenderEv)

plt(_ZN9ecGameKitD2Ev)

plt(_ZN13GUIBattleList7OnEventERK5Event)

plt(_ZN7GUISaveD1Ev)

plt(_ZN6ecFile7GetSizeEv)

plt(_ZN7CPlayer10SendPacketE9PACKET_IDPKvi)

plt(_ZN13CStateManager6RenderEv)

plt(_ZN13CStateManager4InitEv)

plt(_ZN9GUIButtonD1Ev)

plt(_ZN6CSceneD2Ev)

plt(_ZN7ecImage6RenderEff)

plt(_ZN8GUIBegin9ResetDataEv)

plt(_ZN12CBattleScene11CreateUnitsEv)

plt(_Z13ecLoadLibraryPKcR13ecLibraryData)

plt(_ZN10CCSoundBox8UnloadSEEPKc)

plt(_ZN8CGameRes18RenderUIAttackArmyEPKcffiiiiiiib)

plt(_ZN9TiXmlTextD1Ev)

plt(_ZN12GUICommander4InitERK7GUIRect)

plt(_ZN16ecParticleSystem6FireAtEfff)

plt(_ZN7GUIGoldD2Ev)

plt(_ZN12TiXmlElement9ClearThisEv)

plt(_Z12ecGameUpdatef)

plt(_ZN8CGameRes10RenderFlagEPKcff)

Thn(N10CMenuStateD0Ev, 16)

plt(_ZN6CSceneC1Ev)

Thn(N10CLogoState7OnEventERK5Event, 16)

plt(_ZNK9TiXmlNode13ToDeclarationEv)

plt(_Z19GetCommanderAbilityi)

plt(_ZN10CMenuState6UpdateEf)

plt(_ZN9TiXmlBase8ReadTextEPKcP11TiXmlStringbS1_b13TiXmlEncoding)

plt(_ZN13GUIActionInfoC2Ev)

Thn(N14CPlayerManager16onAcceptedInviteEv, 8)

plt(_ZN9GUIBattleC2Ev)

plt(_ZN14CPlayerManager17InvitationDidFailEPKc)

plt(_ZN7ecLayer6RenderERK7ecMtx32)

plt(_ZN10GUINewGame18IsIabEventImgReadyEv)

plt(_ZN5CArea19DestroyConstructionEv)

plt(_ZN11GUIArmyItemC1Ev)

plt(_ZN10CObjectDef15GetGeneralPhotoEPKc)

plt(_ZN10CLoadState11BackPressedEv)

plt(_ZN16GUIMotionManager8InstanceEv)

plt(_ZN7ecImageC1EP11ecImageAttr)

plt(_ZN10CBaseState11ScrollWheelEfff)

plt(_ZN11GUIMainMenu8OnUpdateEf)

plt(_ZN7GUICard7OnEventERK5Event)

Thn(N14CPlayerManager17onPlayerConnectedEPKc, 8)

plt(_ZN14CPlayerManager13CancelConnectEv)

plt(_ZN13CTouchInertia13AddTrackPointEff)

plt(_ZN10GUIElement8OnRenderEv)

plt(_ZN9ecElement9ResetItemEP10ecItemDataP9ecLibrary)

plt(_ZN9TiXmlNodeC1ENS_8NodeTypeE)

plt(_ZN18ecSessionInterface7ConnectEPKc)

plt(_ZN10CGameState9TouchMoveEffi)

plt(_ZN7CCamera6SetPosEffb)

plt(_ZN10CFightTextC2Ev)

plt(_ZN9CActionAID1Ev)

plt(_ZN9ecLibrary11GetItemDataEi)

plt(_ZN12CGameManager13GetCurCountryEv)

plt(_ZNK12TiXmlUnknown5CloneEv)

plt(_ZN11ecLabelTextC2Ev)

plt(_ZN12CGameManager20SetPlayercountrynameEiPKc)

plt(_ZN10GUIElement8OnUpdateEf)

plt(_ZN18ecEffectResManagerC1Ev)

plt(_ZN6CScene15GetAdjacentAreaEii)

plt(_ZN10CCSoundBox11GetInstanceEv)

plt(_ZN12CGameManager9TurnBeginEv)

plt(_ZN14CPlayerManager17RemoveCorpsPlayerEii)

plt(_Z13ecGameWaitingb)

plt(_ZN14CPlayerManager23RefreshAndSendCorpsDataEv)

plt(_ZN11ecLabelText8SetAlphaEf)

plt(_ZN8CCountry12IsCardUnlockEP7CardDef)

plt(_ZN13GUIBattleList4InitERK7GUIRecti)

plt(_ZN5CArmy11GetNumDicesEv)

plt(_ZN6ecText9GetHeightEv)

plt(_ZN13GUIBattleItemD0Ev)

plt(_ZN10GUIManager7FadeOutEiP10GUIElement)

plt(_ZN11GUICardListC2Ev)

plt(_ZN13GUIAdornMedalD2Ev)

plt(_ZN12ecTextureRes11CreateImageEPKcP9ecTextureffffff)

plt(_ZN10GUIBuyCardD1Ev)

plt(_ZN10GUIManager7OnEventERK5Event)

plt(_ZN8CGameRes4LoadEv)

plt(_ZN12GUITutorails13ReleaseScriptEv)

plt(_ZN12ecTextureRes14ReleaseTextureEP9ecTexture)

plt(_ZN6ecText11GetNumLinesEv)

plt(_ZN10GUIElementD0Ev)

plt(_Z10ecGameInitiiiii)

plt(_ZN13CTouchInertiaC2Ev)

plt(_ZN6CScene6RenderEv)

plt(_ZN10CGameState11BackPressedEv)

plt(_ZN10GUIManager16ReleaseTexureResEv)

plt(_ZN13GUIAIProgress4InitERK7GUIRect)

plt(_ZN7GUITextD0Ev)

Thn(N14CPlayerManager20onPlayerInfoReceivedERSt4listIP12ecPlayerInfoSaIS2_EE, 8)

plt(_ZNK12TiXmlElement9ToElementEv)

plt(_ZN10GUICardTabD2Ev)

plt(_ZN10GUIElement6SetPosEff)

plt(_ZN14GUIBattleIntro9SetBattleEii)

plt(_ZN6CFightD1Ev)

plt(_ZN14CPlayerManager20onFriendListReceivedEv)

plt(_ZN9CActionAI16setCpuDriverbyIdEii)

plt(_Z9GetAIRandv)

plt(_ZN8GUIBeginD0Ev)

plt(_ZN12CGameManager7ReleaseEv)

plt(_ZN10CBaseState15EnterBackgroundEv)

plt(_ZN10CObjectDef16LoadCommanderDefEv)

plt(_ZN14CPlayerManager18SetPlayerOfCountryEv)

plt(_ZN7ecLayer4InitEiP11ecLayerDataP7ecFrameP9ecElementP9ecLibrary)

plt(_ZN10GUIBuyCard14ResetCardStateEv)

plt(_ZN17GUICommanderMedalC1Ev)

plt(_ZN10CFightText6RenderEv)

plt(_ZN10GUIManagerD2Ev)

plt(_ZN9CActionAI13setArmyActionEP5CArea)

plt(_ZN6CScene17CheckAdjacentDataEv)

plt(_ZN7ecFrame9NextFrameEv)

plt(_ZN13GUIBattleItem11SetSelectedEb)

plt(_ZN17GUICommanderMedalD0Ev)

plt(_ZN6CFightC2Ev)

plt(_ZN7ecImage10SetTextureEP9ecTexture)

plt(_ZN7GUICard4InitEP7CardDefRK7GUIRect)

plt(_ZN8GUIBeginC1Ev)

plt(_ZN10CCommander4LoadEv)

plt(_ZN14CPlayerManager22IsDisconnectedFromHostEv)

plt(_ZN10GUIManager9PostEventERK5Event)

plt(_ZN8CCountry14BeConquestedByEPS_)

plt(_ZN8CheckMD5C1Ev)

plt(_ZN19GUIConnectHostState7OnEventERK5Event)

plt(_ZN16GUIUpgradeButton8OnRenderEv)

plt(_ZN12GUITutorailsD1Ev)

plt(_ZN14GUIBattleIntro7OnEventERK5Event)

plt(_ZN8CGameResD1Ev)

plt(_ZN9GUIButton12SetTextColorEj)

plt(_ZN10GUIManager8InstanceEv)

plt(_ZN14CPlayerManager18ClearRemotePlayersEv)

plt(_ZN9GUIResultD1Ev)

plt(_ZN7ecFrameD2Ev)

plt(_ZN14TiXmlAttributeD2Ev)

plt(_ZN8CGameResD2Ev)

plt(_ZN13CFightTextMgrC1Ev)

plt(_ZN13GUIBattleItemD2Ev)

plt(_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz)

plt(_ZN13CFightTextMgr4InitEv)

plt(_ZN14CPlayerManager28SendPacketToAllPlayersExceptE9PACKET_IDPKviP7CPlayer)

plt(_ZN3MD5C1Ev)

plt(_ZN14CPlayerManagerD1Ev)

plt(_ZN8GUIImage8SetImageEPKcRK13ecTextureRectb)

plt(_ZN7ecFrame6RenderERK7ecMtx32)

plt(_ZN8CGameRes22RenderAICommanderMedalEiffPKci)

plt(_Z14ecGameShutdownv)

plt(_ZN17GUICommanderMedalD2Ev)

plt(_ZN10CCommander20CheckUpgradeWarMedalE11WARMEDAL_ID)

plt(_ZN6CScene25GetTwoAreasDistanceSquareEii)

plt(_ZN10CLoadStateD0Ev)

plt(_ZN11CBattleUnit7DestroyEv)

plt(_ZN18ecEffectResManagerD1Ev)

plt(_ZN6CFight16AirStrikesAttackEii)

plt(_ZN6CScene11GetNumAreasEv)

plt(_ZN6CScene9InitAreasEiPKc)

plt(_ZN6ecFileD2Ev)

plt(_ZN6CScene12ClearTargetsEv)

plt(_ZN14CPlayerManager7ReleaseEv)

plt(_ZN12GUICommanderD2Ev)

plt(_ZN9CAreaMarkC1Ev)

plt(_ZN9CSoundRes6UnloadEv)

plt(_ZN13GUIAIProgressC1Ev)

plt(_ZN10GUIOptionsC1Ev)

plt(_ZN12GUITutorails7HideDlgEv)

plt(_ZN13GUIBattleList8OnUpdateEf)

plt(_ZN14CPlayerManager16ClearActionQueueEv)

plt(_ZN6CScene17RenderAreasCenterEv)

plt(_ZN6CScene9NewAdjoinEv)

plt(_ZN10GUINewGame14IsShowIabEventEv)

plt(_ZN6CScene6UpdateEf)

plt(_ZN10CCommander4SaveEv)

plt(_ZN13ecStringTable5ClearEv)

plt(_ZN12CGameManager10GameUpdateEf)

plt(_Z13SetAIRandSeedi)

plt(_ZN9CAreaMarkD2Ev)

plt(_ZN13CActionAssist16purChaseFortCardEv)

plt(_ZN10CGameState8TouchEndEffi)

plt(_ZN8CCountryC1Ev)

plt(_ZN7_JNIEnv16CallObjectMethodEP8_jobjectP10_jmethodIDz)

plt(_ZN9TiXmlNode5ClearEv)

plt(_Z13ecGetUUIDHashv)

plt(_ZN9CActionAI21analyseCompositePowerEv)

plt(_ZN10GUIOptionsD2Ev)

plt(_ZN7CPlayer9SendFirstEv)

plt(_ZN5CArea6RenderEv)

plt(_ZN11GUICardList9SetSelectEi)

plt(_ZN13CActionAssistD1Ev)

plt(_ZN6ecText7SetTextEPKt)

plt(_ZN9GUIBattle8OnRenderEv)

plt(_ZN13GUIActionInfo4InitERK7GUIRect)

plt(_ZN10GUIServiceC2Ev)

plt(_ZN16GUIMotionManager15GetMotionActiveEj)

plt(_ZN13GUISelCountry8OnUpdateEf)

plt(_ZN7ecFrame4PlayEv)

plt(_ZN12CGameManager18GetNumVictoryStarsEv)

plt(_ZN5CArmy6IsNavyEv)

plt(_ZN11CMatchStateC1Ev)

plt(_ZN10CObjectDef10GetArmyDefEiPKc)

plt(_ZN10GUIManager8AddImageEPKcRK7GUIRectP10GUIElement)

plt(_ZN16GUIMotionManager9SetMotionEjffffft)

plt(_ZN10CLoadStateC1Ev)

plt(_ZN7GUITextD2Ev)

plt(_ZN6CScene12SaveAreaDataEi)

plt(_ZN7GUITech8OnRenderEv)

plt(_ZN9CActionAI12purChaseCardE7CARD_ID)

plt(_ZN10CGameState7OnEnterEv)

plt(_ZN10GUISelArmyD0Ev)

plt(_ZN18ecSessionInterfaceC2Ev)

plt(_ZN7CPlayerC2Ev)

plt(_ZN6GUIIapD1Ev)

plt(_ZN11ecLabelText8DrawTextEff)

plt(_ZN10ecGraphics14LoadETCTextureEPKc)

plt(_ZN7GUIBankC2Ev)

plt(_ZdaPv)

plt(_ZN10GUIElementD1Ev)

plt(_ZN13CGameSettingsD2Ev)

plt(_ZN10GUINewGameD1Ev)

plt(_ZN12CGameManagerD2Ev)

plt(_ZN11CMatchStateD2Ev)

plt(_ZN18ecSessionInterface13CancelConnectEv)

plt(_ZN17TiXmlAttributeSetD1Ev)

plt(_ZN13GUIAdornMedalD0Ev)

plt(_ZN6ecText8DrawTextEffi)

plt(_ZN18ecSessionInterfaceD1Ev)

plt(_ZN10GUINewGameC2Ev)

plt(_ZN7GUIBankD1Ev)

plt(_ZN8CGameRes10RenderPortEff)

plt(_Z9ecGetUUIDRSs)

plt(_ZN10CObjectDef19ReleaseConquestListEv)

plt(_ZN10GUISelArmyC1Ev)

plt(_ZN16TiXmlDeclarationD1Ev)

Thn(N10CMenuState7OnEventERK5Event, 16)

plt(_ZN14CPlayerManager17onPlayerConnectedEPKc)

plt(_ZN13CActionAssist17purChaseCardsCardEv)

plt(_ZN12TiXmlCommentD1Ev)

plt(_ZN15ecEffectManager12CreateEffectEPKc)

plt(_ZN13GUIAdornMedalC1Ev)

plt(_ZN8CCountry8FindAreaEi)

plt(_ZN11GUICardList8OnUpdateEf)

plt(_ZN17GUICommanderMedal8OnUpdateEf)

plt(_ZN10CCSoundBox9PlayMusicEb)

plt(_ZN18ecSessionInterface4InitEP17ecSessionDelegate)

plt(_ZN9TiXmlText5ParseEPKcP16TiXmlParsingData13TiXmlEncoding)

plt(_ZN7ecImage9Render4VCEffffffffif)

plt(_ZN10GUIService7OnEventERK5Event)

plt(_ZN11GUIButtonExD1Ev)

plt(_ZN11GUILevelSelD2Ev)

plt(_ZN12CGameManagerC1Ev)

plt(_ZN13GUIMatchSetup16CreatCorsButtonsEv)

plt(_ZN6CMedalC1Ev)

plt(_ZN18ecSessionInterface13GetDeviceNameERSs)

plt(_ZN12TiXmlComment9ToCommentEv)

plt(_ZN6CScene4InitEPKci)

plt(_ZN18ecSessionInterface10DisconnectEPKc)

plt(_ZN8CCountry19CheckCardTargetAreaEP7CardDefi)

plt(_ZN14CPlayerManager18SendPacketToServerE9PACKET_IDPKvi)

plt(_ZN5CArea12IsArmyActiveEi)

plt(_Z13GetNumBattlesi)

plt(_ZN14GUICorpsButtonC2Ev)

plt(_ZN9ecElement11SetCurFrameEi)

plt(_ZNK16TiXmlDeclaration13ToDeclarationEv)

plt(_ZN9ecElement4StopEv)

plt(_ZN11ecEffectResD2Ev)

plt(_ZN10CLogoState15EnterForegroundEv)

plt(_ZN13CGameSettingsC1Ev)

plt(_ZN9CSoundRes4LoadEv)

plt(_ZN10GUISelArmyD2Ev)

plt(_ZN6CScene15GetSelectedAreaEv)

plt(_ZN14GUICorpsButtonD1Ev)

plt(_ZN5CArea12EncirclementEv)

plt(_ZN12CGameManager10LoadBattleEPKc)

plt(_Z12JString2CStrP7_JNIEnvP8_jstring)

plt(_ZN6ecTextD2Ev)

plt(_ZNK12TiXmlElement7GetTextEv)

plt(_ZN10CLogoStateD2Ev)

plt(_ZN10CObjectDef15LoadUnitMotionsEv)

plt(_ZN5CArmyC2Ev)

plt(_ZN14CPlayerManager22onReveivedDataFromPeerEPKviPKc)

plt(_ZN5CArea11HasArmyCardEi)

plt(_ZN12CGameManager12NextDialogueEv)

plt(_ZN3MD516bytesToHexStringEPKhm)

plt(_ZN14GUICorpsButton8OnRenderEv)

plt(_ZN6CMedal4InitEff)

plt(_ZN18ecSessionInterface20SendPacketToAllPeersEPKvi)

plt(_ZN10CEditStateD1Ev)

plt(_ZNK9TiXmlNode6ToTextEv)

plt(_ZN9GUIButtonC2Ev)

plt(_ZN11CBackground6RenderEP7CCamera)

plt(_ZN12CGameManager18GetDialogueByIndexEi)

plt(_ZN14CPlayerManager17IsAllPlayersReadyEv)

plt(_ZN7CCamera14SetPosAndScaleEfff)

plt(_ZN10GUIManagerC2Ev)

plt(_ZN3MD56updateERSt14basic_ifstreamIcSt11char_traitsIcEE)

plt(_ZN11GUISaveItemD1Ev)

plt(_ZN10CLogoState6OnExitEv)

plt(_ZN11GUILevelSel7OnEventERK5Event)

plt(_ZN10GUINewGame12IsShowSurveyEv)

plt(_ZN10CEditStateC2Ev)

plt(_ZN14GUIRadioButton8OnRenderEv)

plt(_ZN16GUIMotionManager8SetSpeedEjff)

plt(_ZN9TiXmlTextD0Ev)

plt(_ZN10CGameState16UpdateActionInfoEv)

plt(_ZN16GUIMotionManager9AddMotionEP10GUIElementffffft)

plt(_ZN11GUIMainMenuD1Ev)

plt(_ZN10GUIManagerD1Ev)

plt(_ZN5CAreaD1Ev)

plt(_ZN10GUIVictoryC1Ev)

plt(_ZN13GUISelCountry7OnEventERK5Event)

plt(_ZNK9TiXmlNode15PreviousSiblingEPKc)

plt(_ZN10CMenuState6RenderEv)

plt(_ZN5CArea13SetMoveInArmyEPS_P5CArmybbPKc)

plt(_ZNK9TiXmlNode15IterateChildrenEPKcPKS_)

plt(_ZN9GUIResultC2Ev)

plt(_ZN11GUIMainMenuC2Ev)

plt(_ZN9ecElement10ChangeItemEP10ecItemDataS1_P9ecLibrary)

plt(_ZN10GUIServiceC1Ev)

plt(_ZN10GUIVictoryD0Ev)

plt(_ZN10CEditState10TouchBeginEffi)

plt(_ZN10CLogoState6UpdateEf)

plt(_ZN8CCountry16IsEnoughIndustryEP7CardDef)

plt(_ZN11GUILevelSel4InitERK7GUIRecti)

plt(_ZN14GUICountryListC1Ev)

plt(_ZN5CArea9TurnBeginEv)

plt(_ZN12TiXmlElementC1EPKc)

plt(_ZN6GUIEnd7OnEventERK5Event)

plt(_ZN13GUIBattleItem4InitEiiRK7GUIRect)

plt(_ZN12CBattleScene9AddEffectEPKcff)

plt(_ZN7CCamera13SetAutoFixPosEb)

plt(_ZN12CGameManager21GetNewDefeatedCountryEv)

Thn(N10CEditState7OnEventERK5Event, 16)

plt(_ZN8ecEffect6IsLiveEv)

plt(_ZN11GUIDefeated4InitERK7GUIRect)

plt(_ZN12CBattleScene12ReleaseUnitsEv)

plt(_ZN11GUIButtonEx8OnRenderEv)

plt(_ZN14TiXmlAttribute11SetIntValueEi)

plt(_ZN6ecFile4SeekEli)

plt(_ZN8CCountry16GetCurCardTargetEv)

plt(_ZN12CBattleScene12ClearCratersEv)

plt(_ZN18ecEffectResManagerD2Ev)

plt(_ZN10CCommander15SetBattlePlayedEii)

plt(_ZN10GUIServiceD2Ev)

plt(_ZN9GUIBattleD2Ev)

Thn(N14CPlayerManager12onMatchFoundEv, 8)

plt(_ZN10GUINewGame4InitERK7GUIRect)

plt(_ZN11CMatchState6RenderEv)

plt(_ZN10CCSoundBox9StopAllSEEv)

plt(_ZN10CBaseState11BackPressedEv)

plt(_ZN13GUIBattleItemC1Ev)

plt(_Z7GetRandv)

plt(_ZN9ecLibrary11GetItemNameEj)

plt(_ZN10GUIManager6UpdateEf)

plt(_ZN10CGameState15EnterBackgroundEv)

plt(_ZN8CCountry12IsConquestedEv)

plt(_ZN9GUIBattleC1Ev)

plt(_ZN6GUITaxC1Ev)

plt(_ZN13CStateManager7KeyDownEi)

plt(_ZN9ecElementC1Ev)

plt(_ZN8ecEffectD2Ev)

plt(_ZN12GUITutorails8OnRenderEv)

plt(_ZN3MD56encodeEPKmPhm)

plt(_ZN14GUICountryListD2Ev)

plt(_ZN7GUITextC1Ev)

plt(_ZN10GUICardTab7OnEventERK5Event)

plt(_ZN10CCSoundBox9StopMusicEv)

plt(_Z22ecSetIdleTimerDisabledb)

plt(_ZN9TiXmlNode10FirstChildEPKc)

plt(_ZN16GUIMotionManagerD2Ev)

plt(_ZN6ecText4InitEP9ecUniFont)

Thn(N10CGameStateD0Ev, 16)

plt(_ZN7CPlayerD2Ev)

plt(_ZN7CPlayer7SendAckEi)

plt(_ZN8CCountry15GetFirstCapitalEv)

plt(_ZN10CCSoundBox9LoadMusicEPKcS1_)

plt(_ZN10ecGraphicsC1Ev)

plt(_ZN13ecStringTableC2Ev)

plt(_ZN12GUIAttackBox9SetAttackEii)

plt(_ZNK11TiXmlHandle17FirstChildElementEPKc)

plt(_ZN15GUIProductPrice8OnRenderEv)

plt(_ZN8CCountry15AirstrikeRadiusEv)

Thn(N10CMenuStateD1Ev, 16)

plt(_ZNK12TiXmlElement9StreamOutEP14TiXmlOutStream)

plt(_ZN9ecGameKit19GetMatchPlayersInfoEv)

plt(_ZN11GUIDialogue7OnEventERK5Event)

plt(_ZN9TiXmlBase14SkipWhiteSpaceEPKc13TiXmlEncoding)

plt(_ZN12GUICorpsInfoD0Ev)

plt(_ZN13CStateManager9TouchMoveEffi)

plt(_ZN10CCSoundBox11UpdateSoundEv)

plt(_ZN15ecEffectManagerD1Ev)

plt(_ZN8GUIMedalD2Ev)

plt(_ZN10CFightText4InitEffP9ecUniFont)

plt(_ZN13CActionAssist14searchNodeByIDEii)

plt(_ZN14GUIExitWarning8OnRenderEv)

plt(_ZN10GUIWarningC2Ev)

plt(_ZN8ecEffectC1Ev)

plt(_ZNK9TiXmlText9StreamOutEP14TiXmlOutStream)

plt(_ZN14CPlayerManager16GetNumRightCorpsEv)

plt(_ZN7CBomber8BombAreaEii)

plt(_ZN9GUIButtonD0Ev)

plt(_ZN11CMatchState9TouchMoveEffi)

plt(_ZN7ecShapeC1Ev)

plt(_ZN14CPlayerManager14onMatchRequestEv)

plt(_ZN10ecGraphics12SetBlendModeEi)

plt(_ZN14GUICountryItem11SetSelectedEb)

plt(_ZN16TiXmlDeclaration5ParseEPKcP16TiXmlParsingData13TiXmlEncoding)

plt(_ZN12CGameManager14GetCurDialogueEv)

plt(_ZN6GUIEndD0Ev)

plt(_ZN10GUIWarningD1Ev)

plt(_ZN12CBattleSceneD1Ev)

plt(_ZN17GUICommanderMedal8OnRenderEv)

plt(_ZN5CArea17CheckEncirclementEv)

plt(_ZN6ecFile4OpenEPKcS1_)

plt(_ZN13GUIAIProgress17SetCurCountryNameEPKc)

plt(_ZN6CFight17GetDefenderResultEi)

plt(_ZN10CGameState6OnExitEv)

plt(_ZN12GUISmallCardC1Ev)

plt(_ZN8CGameRes18RenderConstructionEiiff)

plt(_ZN10GUICardTab4InitERK7GUIRect)

plt(_ZN5CArmy11AddStrengthEi)

plt(_ZN7CCamera4InitEffff)

Thn(N10CEditStateD0Ev, 16)

plt(_ZN9GUIResult8OnUpdateEf)

plt(_ZN11GUILevelSel8OnRenderEv)

plt(_ZN11CMatchState8TouchEndEffi)

plt(_ZN9CAreaMark7GetMarkEii)

plt(_ZN10GUIWarning7OnEventERK5Event)

plt(_ZN6CScene20CreateRenderAreaListEv)

plt(_ZN9GUIButton7SetGlowEPKc)

plt(_ZN12GUITutorails4InitERK7GUIRect)

plt(_ZN13CActionAssist16actionToNextAreaEiiii)

plt(_ZN11CMatchState10TouchBeginEffi)

plt(_ZN11GUIArmyItemD2Ev)

plt(_Z9Get2XPathPKcS0_)

plt(_ZN13GUIBattleItemD1Ev)

plt(_ZN10ecGraphicsD1Ev)

plt(_ZN5CArea15MoveArmyToFrontEP5CArmyb)

plt(_ZN12GUISelBattleC1Ev)

plt(_ZN10GUIElementC2Ev)

plt(_ZN10CFightTextD1Ev)

plt(_ZN6CMedalC2Ev)

plt(_ZN5CArea18SetAllArmyMovementEi)

plt(_ZN6CScene13IsRectInSecenEffff)

plt(_ZN7ecLayer11SetCurFrameEi)

plt(_ZN10CMenuState9TouchMoveEffi)

plt(_ZN7CBomber6RenderEv)

plt(_ZN7GUITech8OnUpdateEf)

plt(_ZN11CBackground9RenderBoxEP7CCameraffff)

plt(_ZN10GUIElement11MoveToFrontEPS_)

plt(_ZN10CGameState10SelectAreaEi)

plt(_ZN14CPlayerManager16SessionNoNetworkEv)

plt(_ZN6CScene10SelectAreaEi)

plt(_ZN16GUIMotionManager12ActiveMotionEjh)

plt(_ZN9ecUniFont7ReleaseEv)

plt(_ZN10CCSoundBox6PlaySEEPKc)

plt(_ZN11GUIButtonEx12SetImageTextEPKcS1_)

plt(_ZN10GUIBuyCardC1Ev)

plt(_ZN6CScene20AllAreasEncirclementEv)

plt(_ZN9TiXmlNode6ToTextEv)

plt(_ZN9GUIResult8OnRenderEv)

plt(_ZN12CGameManager20GetPlayerCountryNameEi)

plt(_ZN16GUILockedWarningD2Ev)

plt(_ZN11GUIMainMenu6ShowADEv)

plt(_ZN13CTouchInertia10TouchBeginEffi)

plt(_ZN8CCountry16GetCommanderNameEv)

plt(_ZN11GUICardList7OnEventERK5Event)

plt(_ZN8CGameRes7ReleaseEv)

plt(_ZN13GUIActionInfoD1Ev)

plt(_ZN13GUIBattleListD1Ev)

plt(_ZN14GUICountryListD0Ev)

plt(_ZN6GUIEndC1Ev)

plt(_ZN8CCountry14IsActionFinishEv)

plt(_ZN13CTouchInertiaD1Ev)

plt(_ZN14GUIRadioButtonD1Ev)

plt(_ZN12GUIAttackBoxC2Ev)

plt(_ZN11GUICardList11ResetSelectEv)

plt(_ZNK16TiXmlDeclaration5PrintEP7__sFILEi)

plt(_ZN9ecElementD2Ev)

plt(_ZN13CTouchInertia6UpdateEf)

plt(_ZNK12TiXmlComment5PrintEP7__sFILEi)

plt(_ZN10GUIBuyCardD2Ev)

plt(_ZN10CEditState7KeyDownEi)

plt(_ZN13GUIBattleList9SetSelectEi)

plt(_ZN12GUISelBattle13LoadImageListEii)

plt(_ZN11GUIPauseBox8OnRenderEv)

plt(_ZN16ecParticleSystemC2Ev)

plt(_ZN11CBackgroundD2Ev)

plt(_ZN19GUIConnectHostStateC1Ev)

plt(_ZN10CEditState8TouchEndEffi)

plt(_ZN15ecMultipleTouch8InstanceEv)

plt(_ZN15GUIProductPriceD2Ev)

plt(_ZN11GUIArmyItem8OnRenderEv)

plt(_ZN12GUIScrollBar8OnRenderEv)

plt(_ZN10CEditState6OnExitEv)

plt(_ZN10GUINewGame7OnEventERK5Event)

plt(_ZN6CScene15CheckAttackableEiii)

plt(_ZN7GUIGold8OnUpdateEf)

plt(_ZNK9TiXmlNode17FirstChildElementEPKc)

plt(_ZN8CGameResC2Ev)

plt(_ZN10GUIElement9PostEventERK5Event)

Thn(N11CMatchStateD0Ev, 16)

plt(_ZN5CArea15SetConstructionEii)

plt(_ZN10GUINewGame14BtnSurveyClickEv)

plt(_ZN9TiXmlNodeD0Ev)

plt(_ZN7GUITextD1Ev)

plt(_ZN11CBackgroundC1Ev)

plt(_ZN10GUIVictory8OnUpdateEf)

plt(_ZN5CAreaC1Ev)

plt(_ZN11TiXmlString6appendEPKcm)

plt(_ZNK12TiXmlComment9StreamOutEP14TiXmlOutStream)

plt(_ZN14CPlayerManager34onLocalPlayerAuthenticationChangedEv)

plt(_ZN7CCamera12SetSceneRectEffff)

plt(_ZN19GUIConnectHostStateD2Ev)

plt(_ZN8CCountry13IsEnoughMoneyEP7CardDef)

plt(_ZN9TiXmlBase14StringToBufferC1ERK11TiXmlString)

plt(_ZN14CPlayerManager9InitCorpsEi)

plt(_ZN10CObjectDefD2Ev)

plt(_ZN16TiXmlParsingData5StampEPKc13TiXmlEncoding)

plt(_ZNK17TiXmlAttributeSet4FindERK11TiXmlString)

plt(_ZN9TiXmlNode17FirstChildElementEv)

plt(_ZN12TiXmlUnknownD2Ev)

plt(_ZN3MD5C1ERSt14basic_ifstreamIcSt11char_traitsIcEE)

plt(_ZN6CScene9DelAdjoinEii)

plt(_ZN8CCountry19CheckCardTargetArmyEP7CardDefii)

plt(_ZN10CMenuState6OnExitEv)

plt(_ZN14CPlayerManager22SendPacketToAllPlayersE9PACKET_IDPKvi)

plt(_ZN10ecGraphics23CreateTextureWithStringEPKcS1_iiii)

plt(_ZplRK11TiXmlStringS1_)

plt(_ZN12TiXmlCommentC2ERKS_)

plt(_ZplPKcRK11TiXmlString)

plt(_ZN10GUIElement7OnEventERK5Event)

plt(_Z25ecGameWillEnterForegroundv)

plt(_ZN6CScene15RenderAreasArmyEv)

plt(_ZN11GUIHostList13ClearHostListEv)

plt(_ZN8CGameRes18RenderInstallationEiff)

plt(_ZN10GUINewGame16GetIabEventImageEv)

plt(_Z10ecTouchEndffi)

plt(_ZN16ecParticleSystemD1Ev)

plt(_Z17GetBattleFileNameiiiiPc)

plt(_ZN15GUIProductPriceC2Ev)

plt(_ZN13CStateManager4TermEv)

plt(_ZN7CBomber6UpdateEf)

plt(_ZN7CBomberD1Ev)

plt(_ZN9GUIButtonD2Ev)

plt(_ZN14GUICountryItemC1Ev)

plt(_ZN14CPlayerManager14onReceivedDataEPKviPKcb)

plt(_ZN9ecElement6RenderERK7ecMtx32)

plt(_ZN8GUIImage4InitEPKcRK13ecTextureRectRK7GUIRectbbb)

plt(_ZN8CGameRes12RenderUIArmyEPKcffibiiiii)

plt(_ZN9TiXmlNode15PreviousSiblingEPKc)

plt(_ZN12TiXmlCommentaSERKS_)

plt(_ZN12CGameManager12IsManipulateEv)

plt(_ZN5CArmy14GetMaxStrengthEv)

plt(_ZN15ecMultipleTouch10TouchBeganEff)

plt(_ZN13GUISelCountry4InitERK7GUIRecti)

plt(_ZN10GUIVictory7OnEventERK5Event)

plt(_ZN9TiXmlNode12LinkEndChildEPS_)

plt(_ZN6GUIIap7OnEventERK5Event)

plt(_ZN10GUIOptions4InitERK7GUIRect)

plt(_ZN9ecElement4PlayEv)

plt(_ZN10GUINewGame17GetPromotionImageEv)

plt(_ZN10GUIManager8AddImageEPKcRK13ecTextureRectRK7GUIRectP10GUIElementb)

plt(_ZN6ecFile5WriteEPKvj)

plt(_ZN14GUICountryItemD2Ev)

plt(_ZN16GUIMotionManager10AddMotionYEP10GUIElementfft)

plt(_ZN12CGameManager11ClearBattleEv)

plt(_ZN13TiXmlDocument8LoadFileEPKc13TiXmlEncoding)

plt(_ZN10GUISelArmy7OnEventERK5Event)

plt(_ZN13GUISelCountryC1Ev)

plt(_ZN10ecGraphics12RenderTripleEPK8ecTriple)

plt(_ZN16ecParticleSystem6RenderEv)

plt(_ZN8GUIImageD1Ev)

plt(_ZN14CPlayerManager18SendPacketToPlayerE12PacketHeaderPKviPKc)

plt(_ZNK11TiXmlHandle5ChildEi)

plt(_ZN10GUIBuyCard15SetSelCardIntroEv)

plt(_ZN13CActionAssist21purChaseConstructCardEv)

plt(_ZN12CBattleScene6AttackEv)

plt(_ZN14CPlayerManager4StopEv)

plt(_ZN9ecUniFontD2Ev)

plt(_ZN11GUIHostListD2Ev)

plt(_ZN9ecElement10ChangeItemEPKcS1_P9ecLibrary)

plt(_ZN10CGameState11ShowWarningEi)

plt(_Z14ecIsFullScreenv)

plt(_ZN7GUISaveD0Ev)

plt(_ZN9CActionAI11detectCardsE7CARD_ID)

plt(_ZN10CGameState15ResetTouchStateEv)

plt(_ZN18ecEffectResManager19ReleaseAllEffectResEv)

plt(_ZN14TiXmlAttribute5ParseEPKcP16TiXmlParsingData13TiXmlEncoding)

plt(_ZN10CLoadStateD1Ev)

plt(_ZN18ecEffectResManager16ReleaseEffectResEP11ecEffectRes)

plt(_ZN17GUICommanderMedal13SetArrowColorEj)

plt(_ZN12GUISelBattle7OnEventERK5Event)

plt(_Z12ecShowReviewv)

plt(_ZN10GUIBuyCard13ReleaseTargetEv)

plt(_ZN11GUIHostListC1Ev)

plt(_ZN9ecUniFontC1Ev)

plt(_ZN16GUIMotionManager11ClearMotionEv)

plt(_ZN14CPlayerManager17RemoveCorpsPlayerEP7CPlayer)

plt(_ZN9ecElement7SetLoopEi)

plt(_ZNK9hgeVector5AngleEPKS_)

plt(_ZN9ecLibraryC2Ev)

plt(_ZN9TiXmlNode15IterateChildrenEPKcPS_)

plt(_ZN7GUICard8SetPriceEi)

plt(_ZN9ecUniFont4InitEPKcb)

plt(_Z13ecTextureLoadPKcRiS1_Rj)

plt(_ZN11GUIDialogue8OnUpdateEf)

plt(_ZN9TiXmlNode16InsertAfterChildEPS_RKS_)

plt(_ZN9ecGameKit25ShowMatchmakerWithRequestEiii)

plt(_ZN10GUIElement11RemoveChildEPS_)

plt(_ZN10CGameState6RenderEv)

plt(_ZN11GUIDefeated8OnUpdateEf)

plt(_ZN14GUICountryList7OnEventERK5Event)

plt(_ZN11GUISaveItemD2Ev)

plt(_ZN13GUIActionInfoC1Ev)

plt(_ZN6CScene13CheckAdjacentEii)

plt(_ZN5CArea13SetArmyActiveEib)

plt(_ZN11GUIHostItem7SetNameEPKc)

plt(_ZN8GUIImageC2Ev)

plt(_Z11ecGamePausev)

plt(_ZN16ecParticleSystem6UpdateEf)

plt(_ZN11GUISaveItemC1Ev)

Thn(N10CLoadStateD1Ev, 16)

plt(_ZN9ecGameKit4InitEP17ecGameKitDelegateb)

plt(_ZN14GUICountryList9SetSelectEi)

plt(_ZN6ecFile9GetCurPosEv)

plt(_ZN6CFight11FirstAttackEii)

plt(_ZN7ecFrame4StopEv)

plt(_ZN15ecMultipleTouchC1Ev)

plt(_ZN8CCountry6ActionERK13CountryAction)

plt(_ZN16GUIUpgradeButtonD1Ev)

plt(_ZN9GUIBattle13UpateFightingEf)

plt(_ZN10GUINewGame15IsShowSurveyTipEv)

plt(_ZN12TiXmlElementD1Ev)

plt(_ZN6GUITaxD0Ev)

plt(_ZN16GUIUpgradeButtonC2Ev)

plt(_ZN10CObjectDef16GetUnitPositionsEPKc)

plt(_ZN11GUISaveItem8OnUpdateEf)

plt(_ZN10GUIManager12AddScrollBarERK7GUIRectP10GUIElementPKcS6_iiiii)

plt(_ZN10CEditState6UpdateEf)

plt(_ZN12CBattleScene6RenderEv)

plt(_ZN12GUISelBattle9SelBattleEii)

plt(_ZN14CPlayerManager20onPlayerDisconnectedEPKc)

plt(_ZN12GUICommander7OnEventERK5Event)

plt(_ZN12CGameManager20GetCurDialogueStringEPc)

plt(_ZN13GUIAdornMedal4InitER7GUIRect)

plt(_ZN13GUIMatchSetup18RefreshCorsButtonsEv)

plt(_ZN11GUIPauseBoxD1Ev)

plt(_ZN7ecLayerC2Ev)

plt(_ZN9ecLibrary4LoadEPKcR12ecTextureRes)

plt(_Z22ecApplicationTerminatev)

plt(_Z15ecAccelerometerfff)

plt(_ZNK9TiXmlText5BlankEv)

plt(_ZN17TiXmlAttributeSet3AddEP14TiXmlAttribute)

plt(_ZN13GUISelCountry16ReleaseImageListEv)

plt(_ZN5CArea16LostArmyStrengthEii)

plt(_ZN6CScene12ScreenToAreaEff)

plt(_ZN11GUIDialogueC1Ev)

plt(_ZN13CStateManager15EnterBackgroundEv)

plt(_ZN10GUINewGame12IsImageReadyEv)

plt(_ZN13ecStringTable9GetStringEPKc)

plt(_ZNK12TiXmlElement20QueryDoubleAttributeEPKcPd)

plt(_ZN14CPlayerManager13DoFrontActionEv)

plt(_ZN6CScene19GetTwoAreasDistanceEii)

plt(_ZN10CObjectDef17ReleaseBattleListEv)

plt(_ZN7GUICard11SetIndustryEi)

plt(_ZN6CFightD2Ev)

plt(_ZN12ecTextureResD1Ev)

plt(_ZN18ecEffectResManagerC2Ev)

plt(_ZN7ecLayerD1Ev)

plt(_ZN10GUILoading8OnRenderEv)

plt(_ZN13GUISelCountryD0Ev)

plt(_ZNK11TiXmlHandle12ChildElementEi)

plt(_ZN5CArea11DelArmyCardEii)

plt(_ZN7GUIBank7OnEventERK5Event)

plt(_ZN7GUIText4InitERK7GUIRectP9ecUniFont)

plt(_ZN10GUIOptionsC2Ev)

plt(_ZN8GUIBeginD1Ev)

plt(_ZN3MD5C1ERKSs)

plt(_ZN12GUIAttackBoxD0Ev)

plt(_ZN9GUIButton8SetAlphaEf)

plt(_ZN11GUIDialogueD0Ev)

plt(_Znwm)

plt(_ZN8CCountry4InitEPKcS1_)

plt(_ZN10CObjectDef7DestroyEv)

plt(_ZN12GUISmallCardC2Ev)

plt(_ZN12GUIScrollBarD2Ev)

plt(_ZN12GUISelBattle16ReleaseImageListEv)

plt(_ZN12CGameManager15GetNumCountriesEv)

plt(_ZN6CScene15RenderAreasTypeEv)

plt(_ZN10GUIOptionsD0Ev)

plt(_ZN6CFight12GetDefendAddEi)

plt(_ZN14CPlayerManager9AddPlayerEbPKc)

plt(_ZN12GUISmallCardD1Ev)

plt(_ZN9CSoundResC2Ev)

plt(_ZN8GUIBeginC2Ev)

plt(_ZN12CGameManager7EndTurnEv)

plt(_ZNK11TiXmlHandle17FirstChildElementEv)

plt(_ZNK11TiXmlHandle10FirstChildEPKc)

plt(_ZN5CArea7AddArmyEP5CArmyb)

plt(_ZN14CPlayerManager10StartMatchEv)

plt(_ZN8CCountry14SetCardTargetsEP7CardDef)

plt(_ZN8ecEffect6UpdateEf)

plt(_Z13ecScrollWheelfff)

plt(_ZN13CGameSettingsD1Ev)

plt(_ZN10GUIElement6CenterEv)

plt(_ZN10CLogoState6RenderEv)

plt(_ZN11CMatchStateC2Ev)

plt(_ZN12GUISelBattleD1Ev)

plt(_ZN19GUIConnectHostState4InitER7GUIRect)

Thn(N14CPlayerManager14onMatchRequestEv, 8)

plt(_ZN5CArea7TurnEndEv)

plt(_ZN8GUIMedalD0Ev)

plt(_ZN12ecTextureRes7ReleaseEv)

plt(_ZN8ecEffect4FireEv)

plt(_ZN14TiXmlAttributeD1Ev)

plt(_ZN9ecElement4InitEPKcP9ecLibrary)

plt(_ZN6CScene14SetAreaCountryEiP8CCountry)

plt(_ZN11CBackground4InitEiiiiiffff)

plt(_ZN9ecElement4InitEP10ecItemDataP9ecLibrary)

plt(_ZN14GUIBattleIntroC2Ev)

plt(_ZN8CCountry18FindAdjacentAreaIDEib)

plt(_ZN10CGameState11ReleaseGameEv)

plt(_ZN10CGameState10TouchBeginEffi)

plt(_Z11SetRandSeedi)

plt(_ZN14CPlayerManager12onStartMatchEv)

plt(_ZN6CScene14SaveAreaEnableEPKc)

plt(_ZN10GUICardTabC1Ev)

plt(_ZN13CTouchInertia8GetSpeedERfS0_)

plt(_ZN6GUIIap14SetLocalePirceEiPKc)

plt(_ZN7CPlayer10RecvPacketEPKvi)

plt(_ZN10CGameState6UpdateEf)

plt(_ZN11GUIArmyItemC2Ev)

plt(_ZN14GUIExitWarningC2Ev)

plt(_ZN9ecGameKit18GetLocalPlayerInfoER12ecPlayerInfo)

plt(_ZN8CCountry10CanBuyCardEP7CardDef)

plt(_ZN6CScene11LoadAreaTaxEi)

plt(_ZN5CArea12CanConstructEi)

plt(_ZN10CFightText6UpdateEf)

plt(_ZN8CCountry8GetTaxesEv)

plt(_ZN10GUIElement4MoveEff)

plt(_ZN13CStateManager10TouchBeginEffi)

plt(_ZN12TiXmlElement9ToElementEv)

plt(_ZN9GUIResultD2Ev)

plt(_ZN10GUICardTabD0Ev)

plt(_ZNK12TiXmlElement9AttributeEPKcPd)

plt(_ZN10CCSoundBox18DestroySoundSystemEv)

plt(_ZN7ecImage13RenderStretchEffff)

plt(_ZN15ecEffectManager6RenderEv)

plt(_ZN10CLoadState8TouchEndEffi)

plt(_ZN12ecTextureRes10GetTextureEPKc)

plt(_Z14ecSaveLibrarayPKcR13ecLibraryDataS0_i)

plt(_ZNK9TiXmlNode11NextSiblingEPKc)

plt(_ZNK9TiXmlNode9ToElementEv)

plt(_ZN10ecGraphics9RenderEndEv)

plt(_Z17ecWEBPTextureLoadPKcRiS1_Rj)

plt(_ZN9GUIResultC1Ev)

plt(_ZN10CGameState18PlayerCountryBeginEv)

plt(_ZN8GUIMedalC2Ev)

plt(_ZN14GUIExitWarning7OnEventERK5Event)

plt(_Z15ecInAppPurchasei)

plt(_ZNK11TiXmlHandle5ChildEPKci)

plt(_Z12ecGameResumev)

plt(_ZN13CStateManager15EnterForegroundEv)

plt(_ZN11CBattleUnit4InitEiiP9ecLibraryP11UnitMotions)

plt(_ZN9CAreaMarkC2Ev)

plt(_ZN12CGameManager8SaveGameEPKc)

plt(_ZN12GUIAttackBoxD2Ev)

plt(_ZN10GUIManager9AddButtonEPKcS1_RK7GUIRectP10GUIElementP9ecUniFont)

plt(_ZN9ecLibrary12FindItemDataEPKc)

plt(_ZN12GUISelBattleC2Ev)

plt(_ZN13TiXmlDocument8LoadFileE13TiXmlEncoding)

plt(_ZN6CFight12NormalAttackEii)

plt(_ZN12GUIScrollBar7OnEventERK5Event)

plt(_ZN14CPlayerManager14SetCorpsByDataEPviP7CPlayer)

plt(_ZN17TiXmlAttributeSetD2Ev)

plt(_ZN13GUISelCountry9SelBattleEii)

plt(_ZN14GUIRadioButtonC2Ev)

plt(_ZN10GUIElementD2Ev)

plt(_ZN13CFightTextMgr6RenderEv)

plt(_ZN16GUIMotionManager10AddMotionXEP10GUIElementfft)

plt(_ZN7ecImage8SetAlphaEfi)

plt(_ZN5CArea10MoveArmyToEPS_)

plt(_ZN18ecSessionInterfaceD2Ev)

plt(_ZN10GUIElement6GetPosERfS0_)

plt(_ZN14GUICorpsButtonD0Ev)

plt(_ZNK9TiXmlNode9ToCommentEv)

plt(_ZN10CLogoStateC1Ev)

plt(_ZN16GUIMotionManagerD1Ev)

plt(_ZN13GUIMatchSetupC1Ev)

plt(_ZN14GUICorpsButtonC1Ev)

plt(_ZN11ecLabelText7SetTextEPKc)

plt(_ZN13CActionAssist17purChaseDraftCardEb)

plt(_ZN13CStateManager11ScrollWheelEfff)

plt(_ZN11GUIDialogue8OnRenderEv)

plt(_ZN11CBattleUnitC2Ev)

plt(_ZN10CLogoStateD1Ev)

plt(_ZN12TiXmlElement15RemoveAttributeEPKc)

plt(_ZN7_JNIEnv22CallStaticObjectMethodEP7_jclassP10_jmethodIDz)

plt(_ZN10CGameState16UpdateAIProgressEv)

plt(_ZN5CArmyC1Ev)

plt(_ZN19GUIConnectHostState8OnRenderEv)

plt(_ZN11GUIDialogueD2Ev)

plt(_ZN12ecTextureRes11CreateImageEPKcS1_ffffff)

plt(_ZN13CStateManager11GetStatePtrE6EState)

plt(_ZN16GUIMotionManagerC2Ev)

plt(_ZN14CPlayerManager9StopMatchEv)

plt(_ZN6CScene17GetAdjacentAreaIDEii)

plt(_ZN13CStateManager11SetCurStateE6EState)

plt(_ZNK9TiXmlNode17FirstChildElementEv)

plt(_ZN17GUICommanderMedal4InitERK7GUIRecti)

Thn(N10CGameStateD1Ev, 16)

plt(_ZN11CBattleUnit12SetDestroyedEv)

plt(_ZN9GUIBattle11ResetBattleEv)

plt(_ZN12TiXmlCommentC1ERKS_)

plt(_ZN10CObjectDef11LoadArmyDefEv)

plt(_ZN10GUINewGame14GetSelectGroupEP14GUIRadioButton)

plt(_ZN7ecFrameC1Ev)

plt(_ZN12TiXmlElement9ReadValueEPKcP16TiXmlParsingData13TiXmlEncoding)

plt(_Z11GetRandSeedv)

plt(_ZN6ecFile4ReadEPvj)

plt(_ZN7ecImageC2EP11ecImageAttr)

plt(_ZN14CPlayerManager7ConnectEPKci)

plt(_ZN12GUITutorailsC1Ev)

plt(_ZN10GUIOptions8OnRenderEv)

plt(_ZN9ecGameKit10SendPacketEPKviPKc)

plt(_ZN3MD5C2EPKvm)

plt(_ZN12CGameManager4InitEv)

plt(_ZN12CGameManager7NewGameEiiii)

plt(_ZN11CBackgroundC2Ev)

plt(_ZN16TiXmlDeclarationC1EPKcS1_S1_)

plt(_ZN11CBattleUnit6RenderEv)

plt(_Z18ecPurchasedProducti)

plt(_ZN10CBaseState9TouchMoveEffi)

plt(_ZN7GUIGoldC2Ev)

plt(_ZN12ecTextureRes7LoadResEPKcb)

plt(_ZN8CCountry17GetCommanderLevelEv)

plt(_ZN10CMenuStateD2Ev)

plt(_ZN14CPlayerManager4InitEv)

plt(_Z24GetNumMultiPlayerBattlesi)

plt(_ZN7ecShapeD1Ev)

plt(_ZNK14TiXmlAttribute13QueryIntValueEPi)

plt(_ZN11GUIDefeated8OnRenderEv)

plt(_ZN11GUIPauseBox7OnEventERK5Event)

plt(_ZN8CGameRes11GetBattleBGEPKc)

plt(_ZN8CGameRes20RenderCommanderMedalEiffi)

plt(_ZN12TiXmlElementC2ERKS_)

plt(_Z15ecSetFullScreenb)

plt(_ZN10CCSoundBoxC2Ev)

plt(_ZN8CCountry22FindAdjacentLandAreaIDEib)

plt(_ZN10CEditState9TouchMoveEffi)

plt(_ZN9ecElement6UpdateEf)

plt(_ZN10CCSoundBoxD1Ev)

plt(_ZN11GUIHostItemD2Ev)

plt(_ZN12TiXmlUnknown5ParseEPKcP16TiXmlParsingData13TiXmlEncoding)

plt(_ZN12GUICommander8OnRenderEv)

plt(_ZN7ecShapeC2Ev)

plt(_ZN5CArmy16ResetMaxStrengthEb)

plt(_ZN15ecEffectManager8InstanceEv)

plt(_ZN11GUIWarMedalD0Ev)

plt(_ZN10GUISelArmy4InitERK7GUIRect)

plt(_ZN10ecGraphicsD2Ev)

plt(_ZNK9TiXmlNode15IterateChildrenEPKS_)

plt(_ZN10CCommander7UpgradeEv)

plt(_ZN7GUISave7SelItemEi)

plt(_ZN16GUILockedWarningC1Ev)

plt(_ZN11GUIDefeatedC2Ev)

plt(_ZN7ecImage8Render4VEffffffff)

plt(_ZNK14TiXmlAttribute8PreviousEv)

plt(_ZN16GUILockedWarningD0Ev)

plt(_ZN7ecImage8RenderExEfffff)

plt(_ZN11GUIHostList13ConnectFailedEv)

plt(_ZN8CGameRes21RenderArmyMovementNumEffi)

plt(_ZN10ecGraphics10RenderQuadEPK6ecQuad)

plt(_ZN10CCommanderD1Ev)

plt(_ZN9TiXmlNode11NextSiblingEPKc)

plt(_ZN10GUIElementC1Ev)

plt(_ZN8CCountryC2Ev)

plt(_ZN6GUITaxC2Ev)

plt(_ZN6GUIIapD0Ev)

plt(_ZN9TiXmlNodeD2Ev)

plt(_ZN7GUISave4InitERK7GUIRectib)

plt(_ZN13CTouchInertia4StopEv)

plt(_ZN10GUINewGame21OnRadioBtnSurveyClickEv)

plt(_ZN13CStateManagerD1Ev)

plt(_ZN10CEditStateC1Ev)

plt(_ZN7GUIGoldD1Ev)

plt(_ZN10ecGraphics13CreateTextureEii)

plt(_ZN6CScene16MoveCameraToAreaEi)

plt(_ZN10GUICardTab9SelectTabEi)

plt(_ZN5CAreaD2Ev)

plt(_ZN15ecEffectManager9RemoveAllEv)

plt(_ZN14CPlayerManager21GetDisconnectedPlayerEv)

plt(_ZN9TiXmlBase14StringToBufferD1Ev)

plt(_ZN7GUIText12SetTextColorEj)

plt(_ZN18ecSessionInterface15GetPeerNameListERSt4listISsSaISsEES3_)

plt(_ZN10GUILoadingD2Ev)

plt(_ZN7_JNIEnv21CallStaticFloatMethodEP7_jclassP10_jmethodIDz)

plt(_ZN13CStateManagerC2Ev)

plt(_ZN11ecEffectResC2Ev)

plt(_ZN7_JNIEnv23CallStaticBooleanMethodEP7_jclassP10_jmethodIDz)

plt(_ZN10CCommander16GetCommanderDataER13CommanderData)

plt(_ZN10CEditStateD0Ev)

plt(_ZN10GUIElement6UpdateEf)

plt(_ZN13GUIBattleListD0Ev)

plt(_ZN7CPlayer7RecvAckEi)

plt(_ZN13GUIActionInfoD0Ev)

plt(_ZN8CCountryD1Ev)

plt(_ZN8CCountry6UpdateEf)

plt(_ZNK9TiXmlNode18NextSiblingElementEPKc)

plt(_ZN11GUIWarMedalD2Ev)

plt(_ZNK12TiXmlElement17QueryIntAttributeEPKcPi)

plt(_ZN6CFight16AirStrikesAttackEP8CCountryii)

Thn(N14CPlayerManager20onPlayerDisconnectedEPKc, 8)

plt(_ZNK14TiXmlAttribute9StreamOutEP14TiXmlOutStream)

plt(_ZN10CFightText7SetTextEPKc)

plt(_ZN18ecSessionInterface12SetupSessionEb)

plt(_ZN9GUIButton13SetTextOffsetEff)

plt(_ZN16GUILockedWarningD1Ev)

plt(_ZNK13TiXmlDocument5PrintEP7__sFILEi)

plt(_ZN13CFightTextMgrD1Ev)

plt(_ZN7CBomber9IsBombingEv)

plt(_ZN7GUICard16SetIndustryColorEj)

plt(_ZN7GUITech4InitERK7GUIRect)

plt(_ZN12GUICommander8OnUpdateEf)

plt(_ZN5CArmyD1Ev)

plt(_ZN10CObjectDef8InstanceEv)

plt(_ZN8ecEffectD1Ev)

plt(_ZN10CCommander19GetNeedUpgradeMedalE11WARMEDAL_ID)

plt(_ZN13CActionAssist21purChaseAirStrikeCardEv)

plt(_ZN12TiXmlElement5ParseEPKcP16TiXmlParsingData13TiXmlEncoding)

plt(_ZN9TiXmlNode9LastChildEPKc)

plt(_ZN6ecTextC2Ev)

plt(_ZN16ecParticleSystemC1Ev)

plt(_ZN7CCamera6MoveToEffb)

plt(_ZN10CObjectDef15GetCommanderDefEPKc)

plt(_ZN15ecMultipleTouch5ResetEv)

plt(_ZN10GUILoadingC1Ev)

plt(_ZN10CCommander16GetWarMedalLevelE11WARMEDAL_ID)

plt(_ZN13GUIAIProgressD1Ev)

plt(_ZN12GUICorpsInfoD1Ev)

plt(_ZN16GUIMotionManager10ProcMotionEv)

plt(_ZN7ecFrame10ChangeItemEP10ecItemDataS1_P9ecLibrary)

plt(_ZN10CMenuState13PeerConnectedEv)

plt(_ZN7CPlayer4InitEbPKc)

plt(_ZN16TiXmlDeclarationaSERKS_)

plt(_ZN10GUILoading7OnEventERK5Event)

plt(_ZN7CBomberC2Ev)

plt(_ZN14GUICountryItemC2Ev)

plt(_ZN10CBaseState6OnExitEv)

plt(_ZN8CGameRes14RenderArmyInfoEiffiiiii)

plt(_ZN14GUIBattleIntro4InitERK7GUIRectii)

plt(_ZN6ecFile21CheckFileExistFromZipEPKcS1_)

plt(_Z12ecTouchBeginffi)

plt(_ZN9TiXmlNode11RemoveChildEPS_)

plt(_ZN10GUINewGame23OnRadioBtnIabEventClickEv)

plt(_ZN7ecFrame5ResetEv)

plt(_ZN7ecImageC2EP9ecTextureRK13ecTextureRect)

plt(_ZN14GUIBattleIntro8OnRenderEv)

plt(_ZN8CCountry13GetCardRoundsE7CARD_ID)

plt(_ZN9ecLibrary14GetElementDataEi)

plt(_ZN9CSoundResD2Ev)

plt(_ZN10GUINewGame13GetAppVersionEv)

plt(_ZN12CGameManager11GetPlayerNoEPKc)

plt(_ZN8CCountry10RemoveAreaEi)

plt(_ZN7GUIGold8OnRenderEv)

plt(_ZN9ecLibrary12GetFrameDataEi)

plt(_ZN10GUIBuyCardC2Ev)

plt(_ZN8CheckMD56INfileEPKcS1_)

plt(_ZN12CBattleScene4InitEiPS_)

plt(_ZN10CLoadState7OnEnterEv)

plt(_ZN14GUIExitWarning4InitERK7GUIRect)

plt(_ZN7CCameraC2Ev)

plt(_ZNK9TiXmlNode9LastChildEPKc)

plt(_ZN10CEditState8InitGameEv)

plt(_ZN10CLoadState6UpdateEf)

plt(_ZN13ecStringTableD2Ev)

plt(_ZNK14TiXmlAttribute4NextEv)

plt(_ZN10GUIElement12FindByHandleEj)

plt(_ZN11GUIDefeatedD0Ev)

plt(_ZN5CArmy7UpgradeEv)

plt(_ZN5CArea8LoadAreaEPK12SaveAreaInfo)

plt(_ZN9TiXmlNode9ToUnknownEv)

plt(_ZN8GUIMedal4InitERK7GUIRect)

plt(_ZN10CCSoundBox14SetMusicVolumeEi)

plt(_ZN9TiXmlBase11StringEqualEPKcS1_b13TiXmlEncoding)

plt(_ZN12GUICorpsInfoC1Ev)

plt(_ZN11CBattleUnit7ReleaseEv)

plt(_ZN8CCountry10AddDestroyEi)

plt(_Z24ecGameDidEnterBackgroundv)

plt(_ZN14CPlayerManager12GetCorpsDataERi)

plt(_ZN10ecGraphics10RenderRectEffffm)

plt(_ZN7GUICardD1Ev)

plt(_ZN16TiXmlDeclarationC1ERKS_)

plt(_ZN10GUIElement6RenderEv)

plt(_ZN13TiXmlDocumentC1Ev)

plt(_ZN13CFightTextMgr7AddTextEffPKcj)

plt(_ZN13ecStringTable4LoadEPKc)

plt(_ZN15GUIProductPriceD0Ev)

plt(_ZN10CCommander17GetNumBattleStarsEii)

plt(_ZN14CPlayerManager8SelCorpsEiiP7CPlayer)

plt(_ZN12CGameManager13InitCameraPosEv)

plt(_ZN7ecFrameD0Ev)

plt(_ZN5CAreaC2Ev)

plt(_ZN8CCountry7AddAreaEi)

plt(_ZNK12TiXmlUnknown9ToUnknownEv)

plt(_ZN12GUISelBattle8OnRenderEv)

plt(_ZN7GUICard13SetPriceColorEj)

plt(_ZN9CSoundResC1Ev)

plt(_ZN9ecElement9NextFrameEv)

plt(_ZN10ecGraphics14SetOrientationEi)

plt(_ZN11GUIMainMenu13RefreshNewTipEv)

plt(_ZN13TiXmlDocumentD2Ev)

plt(_ZN6GUIEnd4InitERK7GUIRect)

plt(_ZN10GUIVictory4PlayEv)

plt(_ZN13GUIActionInfoD2Ev)

plt(_ZN13GUIBattleListC1Ev)

plt(_ZN8CGameRes12GetArmyImageEPKcib)

plt(_Z12ecGameRenderv)

plt(_ZN10GUIWarning8OnUpdateEf)

plt(_ZN10GUISelArmy10TargetArmyEi)

plt(_ZNK9TiXmlText6ToTextEv)

plt(_ZN8CGameRes10RenderArmyEPKciiffimbf)

plt(_ZN11TiXmlString6assignEPKcm)

plt(_ZN8CGameResC1Ev)

plt(_ZN9ecUniFontD1Ev)

plt(_ZN13GUIBattleList11ResetSelectEv)

plt(_ZN11GUIPauseBoxC2Ev)

plt(_ZN14CPlayerManager19onPeerListDidChangeEv)

plt(_ZN13GUIBattleListD2Ev)

plt(_ZN10CLoadStateD2Ev)

plt(_ZN16TiXmlDeclaration13ToDeclarationEv)

plt(_ZN12CGameManager17GetCountryByIndexEi)

plt(_Z7GetPathPKcS0_)

plt(_ZN11GUICardList4InitERK7GUIRecti)

plt(_ZN12GUIAttackBoxC1Ev)

plt(_ZN11GUIHostItem8OnRenderEv)

plt(_ZN6CScene12RenderAdjoinEv)

plt(_ZN5CArmy8SaveArmyEP12SaveArmyInfo)

plt(_ZN9TiXmlBase7IsAlphaEh13TiXmlEncoding)

plt(_ZN10GUIWarning4InitERK7GUIRecti)

plt(_ZN14CPlayerManager24onReceivedDataFromPlayerEPKviPKc)

plt(_ZN6GUIEndC2Ev)

plt(_ZN10GUICardTab19GetCardTabButtonIdxEPK10GUIElement)

plt(_ZN12CGameManager10SaveBattleEPKc)

plt(_ZN12CGameManager4NextEv)
