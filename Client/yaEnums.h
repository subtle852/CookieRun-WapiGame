#pragma once

enum class eSceneType
{
	Title,
	Tutorial,
	Main,// ��, �� ����
	Play,
	Result,
	Max,
};

enum class eLayerType // layer �׸��� ����
{
	BG,
	Opponent,
	Player,
	Effect,
	UI,
	End,
};

enum class eComponentType
{
	Transform,
	Collider,
	SpriteRenderer,
	Animatior,
	Audio,
	End,
};