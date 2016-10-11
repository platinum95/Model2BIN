#include "Entity.h"


Entity::Entity() {
	VBOs = std::vector<BufferObject*>();
//	textures = std::vector<Texture*>();

}

Entity::~Entity() {

}

void Entity::registerBufferObject(BufferObject* toAdd) {
	VBOs.push_back(toAdd);
}


#pragma region BufferObject
BufferObject::BufferObject(BufferObjectProperties boProp, unsigned int _size, void* _data)
	:  dimension(boProp.dimension), size(_size), data(_data), unitSize(boProp.unitSize) {
}



BufferObject::BufferObject() {
}

#pragma endregion


