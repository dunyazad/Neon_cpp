#pragma once

#include <Neon/NeonCommon.h>

class NeShader
{
public:
	NeShader();
	~NeShader();

	bool Build();

	void Use();

	bool SetUniformMatrix4(const string& name, const glm::mat4& m);

	inline void SetVertexShaderCode(const string& code) { this->vertexShaderCode = code; }
	inline void SetGeometryShaderCode(const string& code) { this->geometryShaderCode = code; }
	inline void SetFragmentShaderCode(const string& code) { this->fragmentShaderCode = code; }

	inline void SetVertexShaderFileName(const string& fileName) { this->vertexShaderFileName = fileName; }
	inline void SetGeometryShaderFileName(const string& fileName) { this->geometryShaderFileName = fileName; }
	inline void SetFragmentShaderFileName(const string& fileName) { this->fragmentShaderFileName = fileName; }

	inline unsigned int GetShaderProgramID() const { return this->shaderProgramID; }

private:
	string vertexShaderCode;
	string vertexShaderFileName;

	string geometryShaderCode;
	string geometryShaderFileName;

	string fragmentShaderCode;
	string fragmentShaderFileName;

	unsigned int shaderProgramID = UINT_MAX;
	unsigned int vertexShaderID = UINT_MAX;
	unsigned int geometryShaderID = UINT_MAX;
	unsigned int fragmentShaderID = UINT_MAX;

	map<int, string> attributeIndexNameTable;
	map<string, int> attributeNameIndexTable;

	map<int, string> uniformIndexNameTable;
	map<string, int> uniformNameIndexTable;
};
