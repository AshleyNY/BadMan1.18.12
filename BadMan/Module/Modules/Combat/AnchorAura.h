#pragma once
#pragma once
#pragma once
#pragma once
#include "../../Utils/TargetUtil.h"
#include "../../ModuleManager.h"
#include "../Module.h"
#include "../../../../Utils/HMath.h"

class AnchorAura : public IModule {
private:
	int anchordelay = 1;
	int gsdelay = 3;
	int breakdelay = 2;
	bool airplace = true;
	bool spoof = false;
	int odelays = 100;
	bool hasDetonated = false;
	bool hasPlacedAnchor = false;
	bool hasCharged = false;
	bool DhasPlacedAnchor = false;
	bool DhasCharged = false;
	int tickTimer = 0;
	bool takenAnchor = false;
	bool takenGS = false;
	int Option = 99;
	bool appleA = false;
	bool BackForWhat = false;
	int SlotSpoof = false;
	// ground level  ~~~ funni initializations
	vec3_t bottom1;
	vec3_t bottom2;
	vec3_t bottom3;
	vec3_t bottom4;
	// top level
	vec3_t neckBreaker;
	// middle level  ~ last priority because it is the least effective
	vec3_t mid1;
	vec3_ti pos3;
	vec3_ti pos2;
	vec3_ti pos1;
	vec3_ti pos;
	vec3_ti pos4;

public:
	AnchorAura();
	~AnchorAura();

	int range = 10;
	// Inherited via IModule
	virtual const char* getModuleName() override;
	bool Tryplace(vec3_t AutoFallBlock);
	//void charge2(C_GameMode* gm, vec3_t* pos);
	virtual void onTick(C_GameMode* gm) override;
	virtual void onPreRender(C_MinecraftUIRenderContext* renderCtx) override;
	virtual void onEnable() override;
	//bool anchorspoof();
	//bool gsspoof();
	virtual void onDisable() override;
};