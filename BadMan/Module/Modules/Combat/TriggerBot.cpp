#include "TriggerBot.h"
#include "../pch.h"

TriggerBot::TriggerBot() : IModule(0, Category::COMBAT, u8"当你瞄准目标时攻击") {
	//registerIntSetting("APS", &APS, APS, 1, 20);
	registerIntSetting("Delay", &delay, delay, 0, 20);
}

const char* TriggerBot::getModuleName() {
	return ("TriggerBot");
}

void TriggerBot::onTick(C_GameMode* gm) {
	/*
	auto player = g_Data.getLocalPlayer();
	auto timerUtil = new TimerUtil();
	if (player == nullptr) return;

	auto target = g_Data.getLocalPlayer()->pointingStruct->getEntity();
	auto pointing = g_Data.getLocalPlayer()->pointingStruct;

	if (g_Data.canUseMoveKeys()) {
		if (target != 0 && TimerUtil::hasTimedElapsed((1000 / APS), true)) {
			if (!TargetUtil::isValidTarget(target))
				return;

			player->swing();
			gm->attack(target);
		}
	}
	*/ // Packet ncc
	auto player = g_Data.getLocalPlayer();
	if (player == nullptr) return;

	//auto target = g_Data.getLocalPlayer()->pointingStruct->getEntity();
	auto pointing = g_Data.getLocalPlayer()->pointingStruct;

	wtfdelay++;
	if (g_Data.canUseMoveKeys()) {
		if (pointing->hasEntity()) {
			auto target = g_Data.getLocalPlayer()->pointingStruct->getEntity();
			if (target != 0 && wtfdelay >= delay) {
				if (TargetUtil::isValidTarget(target)) {
					gm->attack(target);
					if (!moduleMgr->getModule<NoSwing>()->isEnabled()) {
						player->swing();
					}
				}
				wtfdelay = 0;
			}
		}
	}
}