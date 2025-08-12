#pragma once
#include "tool.h"
#include "shapeTool.h"
#include "slider.h"

class LineTool : public ShapeTool
{
private:
	float thickness = 0.1f;
	Slider slider;

	void MakeNewShape();
	void ResizeShape(sf::Vector2f newSize);

public:
	LineTool(std::string displayName, std::string descriptionAndTutorial)
	: ShapeTool(displayName, descriptionAndTutorial) { }

	void Start() override;
	void Update() override;
	void Draw() override;
};