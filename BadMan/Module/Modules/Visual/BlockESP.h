#pragma once
#include "../../ModuleManager.h"
#include "../../Utils/DrawUtils.h"
#include "../Module.h"

class BlockESP : public IModule {
private:
	bool spawner = false;
	bool dOre = false;
	bool eOre = false;
	bool rOre = false;
	bool gOre = false;
	bool iOre = false;
	bool cOre = false;
	bool tracer = true;
	float width = 0.5;
	int range = 5;
public:
	virtual void onPreRender(C_MinecraftUIRenderContext* renderCtx);
	virtual void onLevelRender();
	virtual const char* getModuleName();
	BlockESP();
};