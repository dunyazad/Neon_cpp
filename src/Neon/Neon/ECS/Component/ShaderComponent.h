#pragma once

#include <Neon/NeonCommon.h>
#include <Neon/ECS/Component/ComponentBase.h>

class NeShaderComponent : public NeComponentBase
{
public:
	NeShaderComponent();
	~NeShaderComponent();

	bool Build();

	void Use();

	bool SetUniformMatrix4(const string& name, const glm::mat4& m);

	inline void SetVertexShaderCode(const string& code) { this->vertexShaderCode = code; }
	inline void SetGeometryShaderCode(const string& code) { this->geometryShaderCode = code; }
	inline void SetFragmentShaderCode(const string& code) { this->fragmentShaderCode = code; }

	inline void SetVertexShaderFile(const string& file) { this->vertexShaderFile = file; }
	inline void SetGeometryShaderFile(const string& file) { this->geometryShaderFile = file; }
	inline void SetFragmentShaderFile(const string& file) { this->fragmentShaderFile = file; }

	inline unsigned int GetShaderProgramID() const { return this->shaderProgramID; }

private:
	string vertexShaderCode;
	string geometryShaderCode;
	string fragmentShaderCode;

	string vertexShaderFile;
	string geometryShaderFile;
	string fragmentShaderFile;

	unsigned int shaderProgramID = UINT_MAX;
	unsigned int vertexShaderID = UINT_MAX;
	unsigned int geometryShaderID = UINT_MAX;
	unsigned int fragmentShaderID = UINT_MAX;

	map<int, string> attributeIndexNameTable;
	map<string, int> attributeNameIndexTable;

	map<int, string> uniformIndexNameTable;
	map<string, int> uniformNameIndexTable;
};
