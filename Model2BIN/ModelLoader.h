#pragma once

#include "assimp\Importer.hpp"
#include <vector>
#include "Entity.h"

#include <assimp/cimport.h>
#include <assimp/scene.h>
#include <assimp/postprocess.h>


class ModelLoader {
public:
	ModelLoader();
	static std::vector<Entity*>* readModel(const char* filePath);
	static void freeData(Entity*);
	~ModelLoader();
private:
	
	static Entity* processMesh(aiMesh inMesh, const aiScene *inScene);
//	static std::vector<Texture*> loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName);
	static void processNode(aiNode* node, const aiScene* scene, std::vector<Entity*> * propList);
	

};

