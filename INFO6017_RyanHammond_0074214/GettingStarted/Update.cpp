#include "Update.h"

void Update()
{
	static double lastTime = glfwGetTime();
	double currentTime = glfwGetTime();
	float deltaTime = float(currentTime - lastTime);
	if (deltaTime == 0.f)
	{
		lastTime = currentTime;
		return;
	}

	for (int index = 0; index != gEntities.size(); index++)	//loop through all entities and run their updates
	{
		gEntities[index]->Update(deltaTime);
	}
	//refocus camera
	glm::mat4 cameraTargetTransform;
	gPlayer->GetTransform(cameraTargetTransform);
	gCamera->SetTargetTransform(cameraTargetTransform);
	gCamera->Update(deltaTime);

	lastTime = currentTime;	//update for deltaTime
}