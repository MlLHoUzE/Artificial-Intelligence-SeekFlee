#ifndef _cEntity_HG_
#define _cEntity_HG_

#include "LoadMesh.h"

struct sPhysicsInfo
{
	glm::mat4 Transform;
};

class cEntity
{
public:
	virtual ~cEntity() {}

	virtual void GetTransform(glm::mat4& transform) = 0;
	virtual void SetPosition(glm::vec3& position) = 0;
	virtual void GetMeshEntry(sMeshEntry& meshEntry) = 0;

	virtual void SetMeshEntry(int NumIndices, int BaseIndex, int BaseVertex) = 0;
	virtual void SetColor(glm::vec4& colorIn) = 0;
	virtual void GetColor(glm::vec4& color) = 0;
	virtual void Scale(float scale) = 0;

	virtual void Update(float dt) = 0;


};

class cEnemy : public cEntity
{
public:
	enum cEnemyState
	{
		//STATE_WANDER,
		//STATE_APPROACH,
		//STATE
		STATE_FLEE,
		STATE_SEEK
	};
	cEnemy();
	virtual ~cEnemy() {}

	virtual void GetTransform(glm::mat4& transform);
	virtual void SetPosition(glm::vec3& position);
	virtual void GetMeshEntry(sMeshEntry& meshEntry);
	virtual void SetMeshEntry(int NumIndices, int BaseIndex, int BaseVertex);
	virtual void GetColor(glm::vec4& color);
	virtual void SetColor(glm::vec4& colorIn);
	virtual void Scale(float scale);
	virtual void Update(float dt);
	void checkState(glm::mat4 targetTransform, glm::vec3 direction);
	
private:
private:
	glm::mat4 m_eTransform;
	float m_eLinearSpeed;
	float m_eAngularSpeed;
	sMeshEntry m_eMeshEntry;
	glm::vec4 m_eColor;
	//void SeekStep(float dt);
	//void FleeStep(float dt);
	//void MakeADecision();
	cEnemyState mState;
	//float mDecisionTime;
	//float mDecisionCountDown;

};

class cPlayer : public cEntity
{
public:
	cPlayer();
	virtual ~cPlayer() {}

	virtual void GetTransform(glm::mat4& transform);
	virtual void SetPosition(glm::vec3& position);
	virtual void GetMeshEntry(sMeshEntry& meshEntry);
	virtual void SetMeshEntry(int NumIndices, int BaseIndex, int BaseVertex);
	virtual void GetColor(glm::vec4& color);
	virtual void SetColor(glm::vec4& colorIn);

	virtual void Scale(float scale);
	virtual void Update(float dt);
private:
	glm::mat4 m_transform;
	float m_linearSpeed;
	float m_angularSpeed;
	sMeshEntry m_meshEntry;
	glm::vec4 m_color;
};

#endif