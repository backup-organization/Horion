#pragma once
#include "Module.h"
class Zoom : public IModule {
public:
	Zoom();
	~Zoom();

	bool zooming = false;
	float strength = 20.f;
	float target = 20.f;
	float modifier = 20.f;

	// Inherited via IModule
	virtual bool isFlashMode() override;
	virtual const char* getModuleName() override;
	virtual void onEnable() override;
	virtual void onPostRender(C_MinecraftUIRenderContext* ctx) override;
	virtual void onDisable() override;
};
