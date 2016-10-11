#include "BinaryLoader.h"
#include <fstream>
#include <iostream>
//0 No data
//1 1-D
//2 2-D
//3 3-D
//4 4-D
//5 5-D
//6 
//...
//9 unspecified

volatile long BinaryLoader::fileSize = 0;

void BinaryLoader::createFile(const char* outFile, std::vector<BufferObject*> bos){
	FILE * outFileStream;
	fopen_s(&outFileStream, outFile, "wb");
	header headerBlock;
	uint OffsetCount = 0;
	for (int i = 0; i < bos.size(); i++) {
		headerBlock.headerInfo[i] = informationBlock{
			"Unititled",		//Title
			(short)bos[i]->dimension,	//dimension
			(short)4,					//Data type size
			OffsetCount,	//offset
			bos[i]->size * bos[i]->unitSize		//size
		};
		OffsetCount += headerBlock.headerInfo[i].size;
	}
	for (int i = bos.size(); i < 15; i++) {
		headerBlock.headerInfo[i] = informationBlock{
			"Unititled",//Title
			(short)-1,			//dimension
			(short)-1,			//Data type size
			0,			//offset
			0			//size
		};
	}
	fwrite(&headerBlock, sizeof(header), 1, outFileStream);
	for (int i = 0; i < bos.size(); i++) {
		BufferObject* bo = bos[i];
		std::size_t byteSize = bo->size * bo->unitSize;
		fwrite(bo->data, 1, byteSize, outFileStream);
	}
	fclose(outFileStream);
}

void BinaryLoader::freeData(std::vector<BufferObject*> list) {

	for (BufferObject *BO : list) {
		free(BO->data);
	}
}

void BinaryLoader::freeData(BufferObject* toFree) {
	free(toFree->data);
	//delete toFree;
}

BinaryLoader::~BinaryLoader() {
}
