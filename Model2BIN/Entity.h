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

	void* data;
	unsigned int dimension, size;
	std::size_t unitSize;
	BufferObject(BufferObjectProperties boProp, unsigned int _size, void* _data);
	BufferObject();
	int VBOtype;
	inline bool isActive() {return active;}
	const char* title;
	
private:
	bool active = true;
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


