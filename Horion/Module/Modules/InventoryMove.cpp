#include "InventoryMove.h"



InventoryMove::InventoryMove() : IModule(0x0, MOVEMENT)
{
}


InventoryMove::~InventoryMove()
{
}

const char* InventoryMove::getModuleName()
{
	return ("InventoryMove");
}

void InventoryMove::onTick(C_GameMode* gm)
{
	if (g_Data.getLocalPlayer()->isInventoryClosed() == 1)
		return;

	float speed = 0.25f;
	static C_GameSettingsInput* input = g_Data.getGameSettingsInput();
	float yaw = gm->player->yaw;

	if (GameData::isKeyDown(*input->forwardKey) && GameData::isKeyDown(*input->rightKey))
	{
		yaw += 45.f;
		keyPressed = true;
	}
	else if (GameData::isKeyDown(*input->forwardKey) && GameData::isKeyDown(*input->leftKey))
	{
		yaw -= 45.f;
		keyPressed = true;
	}
	else if (GameData::isKeyDown(*input->backKey) && GameData::isKeyDown(*input->rightKey))
	{
		yaw += 135.f;
		keyPressed = true;
	}
	else if (GameData::isKeyDown(*input->backKey) && GameData::isKeyDown(*input->leftKey))
	{
		yaw -= 135.f;
		keyPressed = true;
	}
	else if (GameData::isKeyDown(*input->forwardKey))
	{
		keyPressed = true;
	}
	else if (GameData::isKeyDown(*input->backKey))
	{
		yaw += 180.f;
		keyPressed = true;
	}
	else if (GameData::isKeyDown(*input->rightKey))
	{
		yaw += 90.f;
		keyPressed = true;
	}
	else if (GameData::isKeyDown(*input->leftKey))
	{
		yaw -= 90.f;
		keyPressed = true;
	}
	if (yaw >= 180)
		yaw -= 360.f;

	float calcYaw = (yaw + 90) *  (PI / 180);
	float calcPitch = (gm->player->pitch)  * -(PI / 180);
	vec3_t moveVec;
	moveVec.x = cos(calcYaw) * cos(calcPitch) * speed;
	moveVec.y = gm->player->velocity.y;
	moveVec.z = sin(calcYaw) * cos(calcPitch) * speed;
	if (keyPressed)
	{
		gm->player->lerpMotion(moveVec);
		keyPressed = false;
	}
}