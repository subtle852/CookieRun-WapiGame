#pragma once
#include "yaEntity.h"
#include "yaLayer.h"

namespace ya
{
	class Scene : public Entity
	{
	public:
		Scene();
		virtual ~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Destroy();
		virtual void Release();

		virtual void OnEnter();
		virtual void OnExit();

		virtual void SceneText(HDC hdc);
		virtual void PosText(HDC hdc);

		void AddGameObeject(GameObject* obj, eLayerType layer);
		std::vector<GameObject*>& GetGameObjects(eLayerType layer);

	private:
		std::vector<Layer> mLayers;
	};
}
