#pragma once
#include "field.h"
class renderer
{
private:
	field* fieldmodel;
public:
	renderer(){};
	renderer(field* f);
	void renderField();

};
