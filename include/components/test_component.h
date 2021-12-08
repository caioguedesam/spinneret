#pragma once

#include "components/component.h"

class TestComponent : public Component
{
public:
	void update(double dt) override;
};
