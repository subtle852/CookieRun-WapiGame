#include "yaScene.h"
#include "yaSceneManager.h"
#include "yaApplication.h"

extern ya::Application application;

namespace ya
{
	int PosX, PosY; WCHAR Postext[100];
	Scene::Scene()
	{
		mLayers.reserve(5);
		mLayers.resize((UINT)eLayerType::End);
	}
	Scene::~Scene()
	{

	}
	void Scene::Initialize()
	{
		//*(lyaer)
		//for (Layer& layer : mLayers)
		//{
		//	layer.Initialize();
		//}
		SceneManager::SetActiveScene(this);
	}
	void Scene::Update()
	{
		for (Layer& layer : mLayers)
		{
			layer.Update();
		}
	}
	void Scene::Render(HDC hdc)
	{
		for (Layer& layer : mLayers)
		{
			layer.Render(hdc);
		}
	}
	void Scene::Destroy()
	{
		std::vector<GameObject*> deleteGameObjects = {};
		for (Layer& layer : mLayers)
		{
			std::vector<GameObject*>& gameObjects
				= layer.GetGameObjects();

			for (std::vector<GameObject*>::iterator iter = gameObjects.begin()
				; iter != gameObjects.end(); )
			{
				if ((*iter)->GetState() == GameObject::eState::Death)
				{
					deleteGameObjects.push_back((*iter));
					iter = gameObjects.erase(iter);
				}
				else
				{
					iter++;
				}
			}
		}

		for (GameObject* deathObj : deleteGameObjects)
		{
			delete deathObj;
			deathObj = nullptr;
		}
	}
	void Scene::Release()
	{

	}
	void Scene::OnEnter()
	{
	}
	void Scene::OnExit()
	{
	}

	void Scene::SceneText(HDC hdc)
	{
		//std::wstring tmp = Scene::GetName();
		//TextOut(hdc, 0, 0, tmp.c_str(), tmp.size());
	}

	void Scene::PosText(HDC hdc)
	{
		//::POINT mousePos = {};
		//::GetCursorPos(&mousePos);
		//::ScreenToClient(application.GetHwnd(), &mousePos);

		//PosX = mousePos.x;
		//PosY = mousePos.y;
		////if (x >= 1600.0f || x <= 0.0f)
		////	return;
		////if (y >= 900.0f || y <= 0.0f)
		////	return;

		//wsprintf(Postext, L" x : %d  y : %d", PosX, PosY);

		//TextOutW(hdc, 0, 16, Postext, lstrlen(Postext));
	}

	void Scene::AddGameObeject(GameObject* obj, eLayerType layer)
	{
		mLayers[(UINT)layer].AddGameObject(obj);
	}
	std::vector<GameObject*>& Scene::GetGameObjects(eLayerType layer)
	{
		return mLayers[(UINT)layer].GetGameObjects();
	}
}