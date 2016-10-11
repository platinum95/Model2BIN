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

BufferObject::BufferObject(unsigned int _dimension, std::size_t _unitSize, unsigned int _size, void * _data) {
	dimension = _dimension;
	unitSize = _unitSize;
	size = _size;
	data = _data;
}



BufferObject::BufferObject() {
}

#pragma endregion


