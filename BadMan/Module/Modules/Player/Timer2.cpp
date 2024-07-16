#include "Timer2.h"
#include "../pch.h"

Timer2::Timer2() : IModule(0, Category::PLAYER, "Modifies the games speed") {
	registerIntSetting("TPS", &timer3, timer3, 1, 500);
}

const char* Timer2::getModuleName() {
	return ("Timer3");
}

void Timer2::onTick(C_GameMode* gm) {
	g_Data.getClientInstance()->minecraft->setTimerSpeed(timer3);
}

void Timer2::onDisable() {
	g_Data.getClientInstance()->minecraft->setTimerSpeed(20.f);
}