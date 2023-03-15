#pragma once

enum class eSceneType
{
	Title,
	Main,
	SelectChar,
	//PetSelect,
	SelectStage,
	Play, //Stage00,
	ResultS,
	ResultF,
	Max,
};

enum class eLayerType // layer 그리는 순서
{
	BG,
	Obstacle,
	Item,
	Player,
	Pet,
	Ground,
	Effect,
	UIfirst,
	UI,
	End = 16,
};

enum class eComponentType
{
	Transform,
	SpriteRenderer,
	Animator,
	Collider,
	Rigidbody,
	Audio,
	End,
};