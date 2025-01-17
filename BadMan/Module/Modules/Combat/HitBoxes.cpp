#include "HitBoxes.h"
#include "../pch.h"

using namespace std;
HitBoxes::HitBoxes() : IModule(0, Category::COMBAT, u8"��ײ���޸�") {
	registerFloatSetting("Height", &height, height, 2.f, 4);
	registerFloatSetting("Width", &width, width, 1.f, 6);

}

const char* HitBoxes::getRawModuleName() {
	return "HitBox";
}

const char* HitBoxes::getModuleName() {
	//name = string("HitBox ") + string(GRAY) + to_string((int)height) + string(".") + to_string((int)(height * 10) - ((int)height * 10)) + " " + to_string((int)width) + string(".") + to_string((int)(width * 10) - ((int)width * 10));
	name = string("HitBox ") + string(GRAY) + string("[") + string(WHITE) + to_string((int)height) + string(".") + to_string((int)(height * 10) - ((int)height * 10)) + " " + to_string((int)width) + string(".") + to_string((int)(width * 10) - ((int)width * 10)) + string(GRAY) + string("]");
	return name.c_str();
}

void findTarget(C_Entity* currentEntity, bool isRegularEntitie) {
	static auto hitBoxes = moduleMgr->getModule<HitBoxes>();
	
	if (currentEntity == g_Data.getLocalPlayer()) return;
	/*
	if (currentEntity == 0) return;
	if (currentEntity->timeSinceDeath > 0 || currentEntity->damageTime >= 1) return;
	*/
	if (!TargetUtil::isValidTarget(currentEntity)) return;

	float dist = (*currentEntity->getPos()).dist(*g_Data.getLocalPlayer()->getPos());
	if (dist < hitBoxes->range) {
		currentEntity->width = hitBoxes->width;
		currentEntity->height = hitBoxes->height;
	}
}

void HitBoxes::onTick(C_GameMode* gm) {
	auto player = g_Data.getLocalPlayer();
	if (player == nullptr) return;

	g_Data.forEachEntity(findTarget);
}
/*
void HitBoxes::onSendPacket(C_Packet* packet) {
	auto player = g_Data.getLocalPlayer();
	if (player == nullptr) return;

	if (g_Data.canUseMoveKeys() && g_Data.isLeftClickDown()) {
		sort(targetList.begin(), targetList.end(), CompareTargetEnArray());
		if (packet->isInstanceOf<C_MovePlayerPacket>() && !targetList.empty()) {
			vec2_t angle = g_Data.getLocalPlayer()->getPos()->CalcAngle(targetList[0]->eyePos0);
			auto* movePacket = reinterpret_cast<C_MovePlayerPacket*>(packet);

			movePacket->pitch = angle.x;
			movePacket->headYaw = angle.y;
			movePacket->yaw = angle.y;
		}
	}
}
*/