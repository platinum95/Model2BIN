#pragma once

#ifndef PROPERTIES_H
#define PROPERTIES_H

#include <typeinfo>


struct BufferObjectProperties {
	unsigned int dimension;
	std::size_t unitSize;
};

struct EntityProperties {
	float * vertices;
	unsigned int *indices;
	unsigned int vertexSize, indexSize;
	float *normals;
};



#include <typeinfo>
#include <vector>
//#include "Texture.h"
#include <glm/gtx/transform.hpp>

#define standardVBO 1
#define InstancedVBO 2

struct BufferObject {
public:
	void* data;
	//size is number of primitives, so byte size is size * unitSize
	unsigned int dimension, size;	
	std::size_t unitSize;
	BufferObject(unsigned int _dimension, std::size_t _unitSize, unsigned int _size, void* _data);
	BufferObject();
	const char* title;
};


class Entity {
public:
	Entity();
	~Entity();
	void registerBufferObject(BufferObject*);

	std::vector<BufferObject*> VBOs;
//	std::vector<Texture*> textures;
	bool active = true;


};

#endif


